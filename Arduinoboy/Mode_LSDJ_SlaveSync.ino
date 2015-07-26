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

void modeLSDJSlaveSyncSetup()
{
  pinMode(pinGBClock,OUTPUT);
  modeLSDJSlaveSync();
}

void modeLSDJSlaveSync()
{
  while(1){
  if (Serial.available() > 0) {
    incomingMidiByte = Serial.read();
    Serial.print(incomingMidiByte, BYTE);
    if(incomingMidiByte > 0x7F) {
    switch (incomingMidiByte) {
      case 0xF8: // Clock Message Recieved
        //send a clock tick out if the sequencer is runn
        if(sequencerStarted && midiSyncEffectsTime && !countSyncTime
          || sequencerStarted && !midiSyncEffectsTime) {
          sendClockTickToLSDJ();
        }
        if(midiSyncEffectsTime) {
          countSyncTime++;
          countSyncTime = countSyncTime % countSyncSteps;
        }
        if(!countSyncPulse) statusLedOn();
        countSyncPulse++;
        countSyncPulse = countSyncPulse % 24;
        break;
      case 0xFA: // Transport Start Message
      case 0xFB: // Transport Continue Message
        sequencerStart();
        break;
      case 0xFC: // Transport Stop Message
        sequencerStop();
        break;
      default:
        if(incomingMidiByte == syncEffectsMidiChannel) {
           midiNoteOnMode = true;
        } else {
           midiNoteOnMode = false;
        }
    }
    } else if(midiNoteOnMode) {
      if(!incomingMidiData[0]) {
         incomingMidiData[0] = incomingMidiByte;
      } else {
         incomingMidiData[1] = incomingMidiByte;
         getNote();
         incomingMidiData[0] = false;
      }
    }
    setMode();
    updateStatusLed();
  } else {
    setMode();
    updateStatusLed();
  }
  
  }
}

void sendClockTickToLSDJ()
{
  for(countLSDJTicks=0;countLSDJTicks<8;countLSDJTicks++) {
    digitalWrite(pinGBClock,LOW);digitalWrite(pinGBClock,HIGH);
  }
}

void getNote()
{
  if(incomingMidiData[1] > 0) {
    switch(incomingMidiData[0]) {
    case 48:
      statusLedOn();
      sequencerStart();
      break;
    case 49:
      statusLedOn();
      sequencerStop();
      break;
    case 50:
      midiSyncEffectsTime = false;
      statusLedOn();
      break;
    case 51:
      midiSyncEffectsTime = true;
      countSyncTime = 0;
      countSyncSteps = 2;
      statusLedOn();
      break;
    case 52:
      midiSyncEffectsTime = true;
      countSyncTime = 0;
      countSyncSteps = 4;
      statusLedOn();
      break;
    case 53:
      midiSyncEffectsTime = true;
      countSyncTime = 0;
      countSyncSteps = 8;
      statusLedOn();
      break;
    }
  }
}
