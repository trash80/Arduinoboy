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
  sendByteToGameboy(0);
  for(int rst=0;rst<5;rst++) sendByteToGameboy(keyboardOctDn);
  for(int rst=0;rst<41;rst++) sendByteToGameboy(keyboardInsDn);
  for(int rst=0;rst<41;rst++) sendByteToGameboy(keyboardTblDn);
  keyboardCurrentOct = 0;
  keyboardCurrentIns = 0;
  keyboardCurrentTbl = 0;
  
  modeLSDJKeyboard();
}

void modeLSDJKeyboard()
{
  while(1){
  setMode();
  updateStatusLed();
  if (Serial.available() > 0) {
    incomingMidiByte = Serial.read();
    Serial.print(incomingMidiByte, BYTE);
    if(incomingMidiByte > 0x7F) {
      switch (incomingMidiByte & 0xF0) {
        case 0x90:
          midiNoteOnMode = true;
          incomingMidiData[0] = incomingMidiByte;
          break;
        case 0xC0:
          midiProgramChange = true;
          incomingMidiData[0] = incomingMidiByte - 48;
          break;
      }
    } else if(midiNoteOnMode) {
      if(!incomingMidiData[1]) {
         incomingMidiData[1] = incomingMidiByte;
      } else {
         incomingMidiData[2] = incomingMidiByte;
         playLSDJKeyboard();
         midiNoteOnMode=false;
         incomingMidiData[0] = false;
         incomingMidiData[1] = false;
         incomingMidiData[2] = false;
      }
    } else if (midiProgramChange) {
        incomingMidiData[1] = incomingMidiByte;
        playLSDJProgramChange();
        midiProgramChange = false;
        incomingMidiData[0] = false;
        incomingMidiData[1] = false;
    }
    updateStatusLed();
  }
  }
}
void playLSDJKeyboard()
{
  if(incomingMidiData[0] == keyboardInstrumentMidiChannel) {
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
        sendByteToGameboy(keyboardInsUp);
      }
    } else {
      keyboardDiff = keyboardLastIns - keyboardCurrentIns;
      for(keyboardCount=0;keyboardCount<keyboardDiff;keyboardCount++) {
        sendByteToGameboy(keyboardInsDn);
      }
    }
    keyboardLastIns = keyboardCurrentIns;
  }
}

void playLSDJKeyboardNote()
{
  if(incomingMidiData[1] >= 0x3C 
      && incomingMidiData[2] > 0x00
      ) {
    incomingMidiData[1] = incomingMidiData[1] - 0x3C;
    if(incomingMidiData[1] >= 0x30) {
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
        sendByteToGameboy(keyboardOctUp);
      }
    } else {
      keyboardDiff = keyboardLastOct - keyboardCurrentOct;
      for(keyboardCount=0;keyboardCount<keyboardDiff;keyboardCount++)
      {
        sendByteToGameboy(keyboardOctDn);
      }
    }
  }
  
  incomingMidiData[1] = incomingMidiData[1] % 12;
  sendByteToGameboy(keyboardNotes[incomingMidiData[1]]);
  keyboardLastOct = keyboardCurrentOct;
  keyboardLastIns = keyboardCurrentIns;
  } else {
    switch(incomingMidiData[1]) {
      case 0x30:
        sendByteToGameboy(keyboardMut1);
        break;
      case 0x31:
        sendByteToGameboy(keyboardMut2);
        break;
      case 0x32:
        sendByteToGameboy(keyboardMut3);
        break;
      case 0x33:
        sendByteToGameboy(keyboardMut4);
        break;
      case 0x34:
        sendByteToGameboy(keyboardEntr);
        break;
      case 0x35:
        sendByteToGameboy(0xE0);
        sendByteToGameboy(keyboardCurL);
        break;
      case 0x36:
        sendByteToGameboy(0xE0);
        sendByteToGameboy(keyboardCurR);
        break;
      case 0x37:
        sendByteToGameboy(0xE0);
        sendByteToGameboy(keyboardCurD);
        break;
      case 0x38:
        sendByteToGameboy(0xE0);
        sendByteToGameboy(keyboardCurU);
        break;
      case 0x39:
        sendByteToGameboy(keyboardTblDn);
        break;
      case 0x3A:
        sendByteToGameboy(keyboardTblUp);
        break;
      case 0x3B:
        sendByteToGameboy(keyboardTblCue);
        break;
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
  delayMicroseconds(1600);
  statusLedOn();
}

