/**************************************************************************
 * Name:    Timothy Lamb                                                  *
 * Email:   trash80@gmail.com                                             *
 ***************************************************************************/
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

void modeLSDJMidioutSetup()
{
  digitalWrite(pinStatusLed,LOW);
  DDRC  = B00000011; //Set analog in pins as inputs
  PORTC = B00000001;
  countGbClockTicks=0;
  lastMidiData[0] = -1;
  lastMidiData[1] = -1;
  midiValueMode = false;
  blinkMaxCount=60;
  modeLSDJMidiout();
}

void modeLSDJMidiout()
{
  while(1){
     if(getIncommingSlaveByte()) {
        if(incomingMidiByte > 0x6f) {
          switch(incomingMidiByte)
          {
           case 0x7F: //clock tick
             Serial.write(0xF8);
             break;
           case 0x7E: //seq stop
             Serial.write(0xFC);
             stopAllNotes();
             break;
           case 0x7D: //seq start
             Serial.write(0xFA);
             break;
           default:
             midiData[0] = (incomingMidiByte - 0x70);
             midiValueMode = true;
             break;
          }
        } else if (midiValueMode == true) {
          midiValueMode = false;
          midioutDoAction(midiData[0],incomingMidiByte);
        }
      
      } else {
        setMode();                // Check if mode button was depressed
        updateBlinkLights();
        
        if (Serial.available()) {                  //If serial data was send to midi inp
          checkForProgrammerSysex(Serial.read());
        }
      }
   }
}

void midioutDoAction(byte m, byte v)
{
  if(m < 4) {
    //note message
    if(v) {
      checkStopNote(m);
      playNote(m,v);
    } else if (midiOutLastNote[m]>=0) {
      stopNote(m);
    }
  } else if (m < 8) {
    m-=4;
    //cc message
    playCC(m,v);
  } else if(m < 0x0C) {
    m-=8;
    playPC(m,v);
  }
  blinkLight(0x90+m,v);
}

void checkStopNote(byte m)
{
  if((midioutNoteTimer[m]+midioutNoteTimerThreshold) < millis()) {
    stopNote(m);
  }
}

void stopNote(byte m)
{
  for(int x=0;x<midioutNoteHoldCounter[m];x++) {
    midiData[0] = (0x80 + (memory[MEM_MIDIOUT_NOTE_CH+m]));
    midiData[1] = midioutNoteHold[m][x];
    midiData[2] = 0x00;
    Serial.write(midiData,3);
  }
  midiOutLastNote[m] = -1;
  midioutNoteHoldCounter[m] = 0;
}

void playNote(byte m, byte n)
{
  midiData[0] = (0x90 + (memory[MEM_MIDIOUT_NOTE_CH+m]));
  midiData[1] = n;
  midiData[2] = 0x7F;
  Serial.write(midiData,3);
  
  midioutNoteHold[m][midioutNoteHoldCounter[m]] =n;
  midioutNoteHoldCounter[m]++;
  midioutNoteTimer[m] = millis();
  midiOutLastNote[m] =n;
}

void playCC(byte m, byte n)
{
  byte v = n;
  
  if(memory[MEM_MIDIOUT_CC_MODE+m]) {
    if(memory[MEM_MIDIOUT_CC_SCALING+m]) {
      v = (v & 0x0F)*8;
      //if(v) v --;
    }
    n=(m*7)+((n>>4) & 0x07);
    midiData[0] = (0xB0 + (memory[MEM_MIDIOUT_CC_CH+m]));
    midiData[1] = (memory[MEM_MIDIOUT_CC_NUMBERS+n]);
    midiData[2] = v;
    Serial.write(midiData,3);
  } else {
    if(memory[MEM_MIDIOUT_CC_SCALING+m]) {
      float s;
      s = n;
      v = ((s / 0x6f) * 0x7f);
    }
    n=(m*7);
    midiData[0] = (0xB0 + (memory[MEM_MIDIOUT_CC_CH+m]));
    midiData[1] = (memory[MEM_MIDIOUT_CC_NUMBERS+n]);
    midiData[2] = v;
    Serial.write(midiData,3);
  }
}

void playPC(byte m, byte n)
{
  midiData[0] = (0xC0 + (memory[MEM_MIDIOUT_NOTE_CH+m]));
  midiData[1] = n;
  Serial.write(midiData,2);
}                                                                    

void stopAllNotes()
{
  for(int m=0;m<4;m++) {
    if(midiOutLastNote[m]>=0) {
      stopNote(m);
    }
    midiData[0] = (0xB0 + (memory[MEM_MIDIOUT_NOTE_CH+m]));
    midiData[1] = 123;
    midiData[2] = 0x7F;
    Serial.write(midiData,3); //Send midi
  }
}

boolean getIncommingSlaveByte()
{
  delayMicroseconds(midioutBitDelay);
  PORTC = B00000000; //rightmost bit is clock line, 2nd bit is data to gb, 3rd is your mom
  delayMicroseconds(midioutBitDelay);
  PORTC = B00000001;
  delayMicroseconds(2);
  if((PINC & B00000100)) {
    incomingMidiByte = 0;
    for(countClockPause=0;countClockPause!=7;countClockPause++) {
      PORTC = B00000000;
      delayMicroseconds(2);
      PORTC = B00000001;
      incomingMidiByte = (incomingMidiByte << 1) + ((PINC & B00000100)>>2);
    }
    return true;
  }
  return false;
}

