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
  pinMode(pinGBClock,OUTPUT);
  digitalWrite(pinGBClock,HIGH);

 #ifdef USE_TEENSY
  usbMIDI.setHandleRealTimeSystem(NULL);
 #endif

  countGbClockTicks=0;
  lastMidiData[0] = -1;
  lastMidiData[1] = -1;
  midiValueMode = false;
  blinkMaxCount=60;
  modeLSDJMidiout();
}

void modeLSDJMidiout()
{
#ifdef USE_LEONARDO
  midiEventPacket_t packet;
#endif
  while(1){
     if(getIncommingSlaveByte()) {
        if(incomingMidiByte > 0x6f) {
          switch(incomingMidiByte)
          {
           case 0x7F: //clock tick
             serial->write(0xF8);
#ifdef USE_TEENSY
             usbMIDI.sendRealTime((int)0xF8);
#endif
#ifdef USE_LEONARDO
             packet = {0x0F, 0xF8};
             MidiUSB.sendMIDI(packet);
             MidiUSB.flush();
#endif
                 break;
           case 0x7E: //seq stop
             serial->write(0xFC);
#ifdef USE_TEENSY
             usbMIDI.sendRealTime((int)0xFC);
#endif
#ifdef USE_LEONARDO
             packet = {0x0F, 0xFC};
             MidiUSB.sendMIDI(packet);
             MidiUSB.flush();
#endif
             stopAllNotes();
             break;
           case 0x7D: //seq start
             serial->write(0xFA);
#ifdef USE_TEENSY
             usbMIDI.sendRealTime((int)0xFA);
#endif
#ifdef USE_LEONARDO
             packet = {0x0F, 0xFA};
             MidiUSB.sendMIDI(packet);
             MidiUSB.flush();
#endif
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
#ifdef USE_TEENSY
        while(usbMIDI.read()) ;
#endif
#ifdef USE_LEONARDO
        // while (MidiUSB.read()) ;
#endif
        if (serial->available()) {                  //If serial data was send to midi inp
          checkForProgrammerSysex(serial->read());
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
    serial->write(midiData,3);
#ifdef USE_TEENSY
    usbMIDI.sendNoteOff(midioutNoteHold[m][x], 0, memory[MEM_MIDIOUT_NOTE_CH+m]+1);
#endif
#ifdef USE_LEONARDO
    midiEventPacket_t packet = { 0x08, 0x80 | memory[MEM_MIDIOUT_NOTE_CH + m], midioutNoteHold[m][x], 0 };
    MidiUSB.sendMIDI(packet);
    MidiUSB.flush();
#endif
  }
  midiOutLastNote[m] = -1;
  midioutNoteHoldCounter[m] = 0;
}

void playNote(byte m, byte n)
{
  midiData[0] = (0x90 + (memory[MEM_MIDIOUT_NOTE_CH+m]));
  midiData[1] = n;
  midiData[2] = 0x7F;
  serial->write(midiData,3);
#ifdef USE_TEENSY
  usbMIDI.sendNoteOn(n, 127, memory[MEM_MIDIOUT_NOTE_CH+m]+1);
#endif
#ifdef USE_LEONARDO
  midiEventPacket_t packet = { 0x09, 0x90 | memory[MEM_MIDIOUT_NOTE_CH + m], n, 127 };
  MidiUSB.sendMIDI(packet);
  MidiUSB.flush();
#endif

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
    serial->write(midiData,3);
#ifdef USE_TEENSY
    usbMIDI.sendControlChange((memory[MEM_MIDIOUT_CC_NUMBERS+n]), v, memory[MEM_MIDIOUT_NOTE_CH+m]+1);
#endif
#ifdef USE_LEONARDO
    midiEventPacket_t packet = {0x0B, 0xB0 | (memory[MEM_MIDIOUT_NOTE_CH + m]+1), (memory[MEM_MIDIOUT_CC_NUMBERS + n]), v};
    MidiUSB.sendMIDI(packet);
    MidiUSB.flush();
#endif
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
    serial->write(midiData,3);
#ifdef USE_TEENSY
    usbMIDI.sendControlChange((memory[MEM_MIDIOUT_CC_NUMBERS+n]), v, memory[MEM_MIDIOUT_NOTE_CH+m]+1);
#endif
#ifdef USE_LEONARDO
    midiEventPacket_t packet = {0x0B, 0xB0 | (memory[MEM_MIDIOUT_NOTE_CH + m]+1), (memory[MEM_MIDIOUT_CC_NUMBERS + n]), v};
    MidiUSB.sendMIDI(packet);
    MidiUSB.flush();
#endif
  }
}

void playPC(byte m, byte n)
{
  midiData[0] = (0xC0 + (memory[MEM_MIDIOUT_NOTE_CH+m]));
  midiData[1] = n;
  serial->write(midiData,2);
#ifdef USE_TEENSY
  usbMIDI.sendProgramChange(n, memory[MEM_MIDIOUT_NOTE_CH+m]+1);
#endif
#ifdef USE_LEONARDO
  midiEventPacket_t packet = {0x0C, 0xC0 | (memory[MEM_MIDIOUT_NOTE_CH + m]+1), n};
  MidiUSB.sendMIDI(packet);
  MidiUSB.flush();
#endif
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
    serial->write(midiData,3); //Send midi
#ifdef USE_TEENSY
    usbMIDI.sendControlChange(123, 127, memory[MEM_MIDIOUT_NOTE_CH+m]+1);
#endif
#ifdef USE_LEONARDO
    midiEventPacket_t packet = {0x0B, 0xB0 | memory[MEM_MIDIOUT_NOTE_CH + m], 123, 127};
    MidiUSB.sendMIDI(packet);
    MidiUSB.flush();
#endif
  }
}

boolean getIncommingSlaveByte()
{
  delayMicroseconds(midioutBitDelay);
  GB_SET(0,0,0);
  delayMicroseconds(midioutBitDelay);
  GB_SET(1,0,0);
  delayMicroseconds(2);
  if(digitalRead(pinGBSerialIn)) {
    incomingMidiByte = 0;
    for(countClockPause=0;countClockPause!=7;countClockPause++) {
      GB_SET(0,0,0);
      delayMicroseconds(2);
      GB_SET(1,0,0);
      incomingMidiByte = (incomingMidiByte << 1) + digitalRead(pinGBSerialIn);
    }
    return true;
  }
  return false;
}






















