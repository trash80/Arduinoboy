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
  digitalWrite(pinStatusLed,LOW);
  blinkMaxCount=1000;
  modeNanoloopSync();
}

void modeNanoloopSync()
{
  while(1){  //Loop forever
  if (Serial.available()) {                 //If MIDI Byte Availaibleleleiel
    incomingMidiByte = Serial.read();           //Read it
    if(!checkForProgrammerSysex(incomingMidiByte) && !usbMode) Serial.print(incomingMidiByte, BYTE);       //Send it back to the Midi out
    
    
    if(incomingMidiByte & 0x80) { 
    switch (incomingMidiByte) { 
      case 0xF8:                                 // Clock Message Recieved
                                                 // Send a clock tick out if the sequencer is running
        if(sequencerStarted) {
          nanoSkipSync = !nanoSkipSync;
          if(countSyncTime) {
            nanoState = sendTickToNanoloop(nanoState, false);
          } else {
            nanoState = sendTickToNanoloop(true, true);
          }
          nanoState = sendTickToNanoloop(nanoState, nanoSkipSync);
          updateVisualSync();
          break;
        }
        break;
      case 0xFA:                                 // Transport Start Message
      case 0xFB:                                 // Transport Continue Message
        sequencerStart();
        break;
      case 0xFC:                                 // Transport Stop Message
        sequencerStop();
        break;
      default:
        break;
      }
    }
  }
  setMode();         //Check if the mode button was depressed
  updateStatusLight();
  }
}

boolean sendTickToNanoloop(boolean state, boolean last_state)
{
  if(!state) {
    if(last_state) {
       PORTC = B00000010;
       PORTC = B00000011;
    } else {
       PORTC = B00000000;
       PORTC = B00000001;
    }
    return true;
  } else {
    PORTC = B00000010;
    PORTC = B00000011;
    return false;
  }
}
