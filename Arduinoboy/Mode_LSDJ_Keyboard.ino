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

void modeLSDJKeyboardSetup()
{
  pinMode(pinGBClock,OUTPUT);
  addGameboyByte(0);
  for(int rst=0;rst<5;rst++) addGameboyByte(keyboardOctDn);
  for(int rst=0;rst<41;rst++) addGameboyByte(keyboardInsDn);
  for(int rst=0;rst<41;rst++) addGameboyByte(keyboardTblDn);
  keyboardCurrentOct = 0;
  keyboardCurrentIns = 0;
  keyboardCurrentTbl = 0;
  modeLSDJKeyboard();
}

void modeLSDJKeyboard()
{
  while(1){
  
  if (Serial.available() > 0) {
    incomingMidiByte = Serial.read();
    Serial.print(incomingMidiByte, BYTE);
    if(incomingMidiByte > 0x7F) {
      switch (incomingMidiByte & 0xF0) {
        case 0x90:
          midiNoteOnMode = true;
          incomingMidiData[0] = incomingMidiByte;
          incomingMidiData[1] = false;
          break;
        case 0xC0:
          midiProgramChange = true;
          midiNoteOnMode = false;
          incomingMidiData[0] = incomingMidiByte - 48;
          break;
        default:
          break;
      }
    } else if(midiNoteOnMode) {
      if(!incomingMidiData[1]) {
         incomingMidiData[1] = incomingMidiByte;
      } else {
         incomingMidiData[2] = incomingMidiByte;
         playLSDJKeyboard();
         incomingMidiData[1] = false;
      }
    } else if (midiProgramChange) {
        incomingMidiData[1] = incomingMidiByte;
        playLSDJProgramChange();
        midiProgramChange = false;
        incomingMidiData[0] = false;
        incomingMidiData[1] = false;
    }
    updateGameboyByteFrame();
    updateStatusLed();
    setMode();
  } else {
    updateGameboyByteFrame();
    updateStatusLed();
    setMode();
  }
  }
}
void playLSDJKeyboard()
{
  if(incomingMidiData[0] == keyboardInstrumentMidiChannel && incomingMidiData[2] > 0x00) {
    playLSDJKeyboardNote();
  }
}

void playLSDJProgramChange()
{
  if(incomingMidiData[0] == keyboardInstrumentMidiChannel) {
    keyboardCurrentIns = incomingMidiData[1];
    if(keyboardCurrentIns > keyboardLastIns) {
      keyboardDiff = keyboardCurrentIns - keyboardLastIns;
      for(keyboardCount=0;keyboardCount<keyboardDiff;keyboardCount++) {
        addGameboyByte(keyboardInsUp);
      }
    } else {
      keyboardDiff = keyboardLastIns - keyboardCurrentIns;
      for(keyboardCount=0;keyboardCount<keyboardDiff;keyboardCount++) {
        addGameboyByte(keyboardInsDn);
      }
    }
    keyboardLastIns = keyboardCurrentIns;
  }
}

void playLSDJKeyboardNote()
{
  if(incomingMidiData[1] >= keyboardNoteStart) {
    keyboardNoteOffset = 0;
    incomingMidiData[1] = incomingMidiData[1] - keyboardNoteStart;
    if(incomingMidiData[1] >= 0x3C) {
      keyboardNoteOffset = 0x0C;
      keyboardCurrentOct = 4;
    } else if(incomingMidiData[1] >= 0x30) {
      keyboardCurrentOct = 4;
    } else if (incomingMidiData[1] >= 0x24) {
      keyboardCurrentOct = 3;
    } else if (incomingMidiData[1] >= 0x18) {
      keyboardCurrentOct = 2;
    } else if (incomingMidiData[1] >= 0x0C) {
      keyboardCurrentOct = 1;
    } else {
      keyboardCurrentOct = 0;
    }
  
    if(keyboardCurrentOct != keyboardLastOct)
    {
      if(keyboardCurrentOct > keyboardLastOct) {
        keyboardDiff = keyboardCurrentOct - keyboardLastOct;
        for(keyboardCount=0;keyboardCount<keyboardDiff;keyboardCount++)
        {
          addGameboyByte(keyboardOctUp);
        }
      } else {
        keyboardDiff = keyboardLastOct - keyboardCurrentOct;
        for(keyboardCount=0;keyboardCount<keyboardDiff;keyboardCount++)
        {
          addGameboyByte(keyboardOctDn);
        }
      }
    }
  
    incomingMidiData[1] = (incomingMidiData[1] % 12) + keyboardNoteOffset;
    addGameboyByte(keyboardNotes[incomingMidiData[1]]);
    keyboardLastOct = keyboardCurrentOct;
    keyboardLastIns = keyboardCurrentIns;
  
  } else if (incomingMidiData[1] >=keyboardStartOctave) {
    addGameboyByte(keyboardCommands[incomingMidiData[1] - keyboardStartOctave]);
  }
}

void addGameboyByte(byte send_byte)
{
  serialWriteBuffer[writePosition] = send_byte;
  writePosition++;
  writePosition = writePosition % 256;
}

void updateGameboyByteFrame()
{
  if(readPosition != writePosition){
    waitClock++;
    if(waitClock > 100) {
      waitClock=0;
      statusLedOn();
      sendByteToGameboy(serialWriteBuffer[readPosition]);
      readPosition++;
      readPosition = readPosition % 256;
    }
  }
}

void sendByteToGameboy(byte send_byte) 
{
  for(countLSDJTicks=0;countLSDJTicks<8;countLSDJTicks++) {
    digitalWrite(pinGBClock,HIGH);
    if(send_byte & 0x01) {
      digitalWrite(pinGBSerialOut,HIGH);
    } else {
      digitalWrite(pinGBSerialOut,LOW);
    }
    send_byte >>= 1;
    digitalWrite(pinGBClock,LOW);
  }
  digitalWrite(pinGBSerialOut,LOW);
}

