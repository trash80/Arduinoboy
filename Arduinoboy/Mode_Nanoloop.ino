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
  pinMode(pinGBClock,OUTPUT);      //Set the gb clock as output
  digitalWrite(pinGBClock,LOW);    //Gameboy likes to get low
  
  modeNanoloopSync();
}

void modeNanoloopSync()
{
  while(1){  //Loop forever
  if (Serial.available() > 0) {                 //If MIDI Byte Availaibleleleiel
    incomingMidiByte = Serial.read();           //Read it
    Serial.print(incomingMidiByte, BYTE);       //Send it back to the Midi out
    
    if(incomingMidiByte > 0x7F) {               //If we have received a MIDI Status Byte
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
