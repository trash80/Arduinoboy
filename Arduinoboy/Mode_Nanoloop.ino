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

void modeNanoloopSetup()
{
  pinMode(pinGBClock,OUTPUT);
  digitalWrite(pinGBClock,LOW);
  modeNanoloopSync();
}

void modeNanoloopSync()
{
  while(1){
  if (Serial.available() > 0) {
    incomingMidiByte = Serial.read();
    Serial.print(incomingMidiByte, BYTE);
    if(incomingMidiByte > 0x7F) {
    switch (incomingMidiByte) {
      case 0xF8: // Clock Message Recieved
        //send a clock tick out if the sequencer is runn
        if(sequencerStarted) {
          nanoSkipSync = !nanoSkipSync;
          if(countSyncTime) {
            nanoState = sendTickToNanoloop(nanoState, false);
          } else {
            nanoState = sendTickToNanoloop(true, true);
          }
          nanoState = sendTickToNanoloop(nanoState, nanoSkipSync);
          
          if(!countSyncPulse) statusLedOn();
          countSyncPulse++;
          countSyncPulse = countSyncPulse % 24;
          break;
        }
        break;
      case 0xFA: // Transport Start Message
      case 0xFB: // Transport Continue Message
        sequencerStart();
        break;
      case 0xFC: // Transport Stop Message
        sequencerStop();
        break;
      default:
        break;
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

boolean sendTickToNanoloop(boolean state, boolean last_state)
{
  if(!state) {
    if(last_state) {
      digitalWrite(pinGBSerialOut,HIGH);
    } else {
      digitalWrite(pinGBSerialOut,LOW);
    }
    return true;
  } else {
    digitalWrite(pinGBSerialOut,HIGH);
    return false;
  }
}
