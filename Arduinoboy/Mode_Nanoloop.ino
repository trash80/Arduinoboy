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
  pinMode(pinGBClock,OUTPUT);
  digitalWrite(pinGBClock,HIGH);

#ifdef USE_TEENSY
  usbMIDI.setHandleRealTimeSystem(usbMidiNanoloopRealtimeMessage);
#endif

  blinkMaxCount=1000;
  modeNanoloopSync();
}

void modeNanoloopSync()
{
  while(1){  //Loop forever
  modeNanoloopUsbMidiReceive();
  if (serial->available()) {                 //If MIDI Byte Availaibleleleiel
    incomingMidiByte = serial->read();           //Read it
    if(!checkForProgrammerSysex(incomingMidiByte) && !usbMode) serial->write(incomingMidiByte);       //Send it back to the Midi out


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
       GB_SET(0,1,0);
       GB_SET(1,1,0);
    } else {
       GB_SET(0,0,0);
       GB_SET(1,0,0);
    }
    return true;
  } else {
    GB_SET(0,1,0);
    GB_SET(1,1,0);
    return false;
  }
}

void usbMidiNanoloopRealtimeMessage(uint8_t message)
{
    switch(message) {
      case 0xF8:
          if(sequencerStarted) {
            nanoSkipSync = !nanoSkipSync;
            if(countSyncTime) {
              nanoState = sendTickToNanoloop(nanoState, false);
            } else {
              nanoState = sendTickToNanoloop(true, true);
            }
            nanoState = sendTickToNanoloop(nanoState, nanoSkipSync);
            updateVisualSync();
          }
      break;
      case 0xFA:                                // Case: Transport Start Message
      case 0xFB:                                // and Case: Transport Continue Message
          sequencerStart();                       // Start the sequencer
      break;
      case 0xFC:                                // Case: Transport Stop Message
          sequencerStop();
      break;
    }
}


void modeNanoloopUsbMidiReceive()
{
#ifdef USE_TEENSY
    while(usbMIDI.read(memory[MEM_LSDJSLAVE_MIDI_CH]+1)) {
        switch(usbMIDI.getType()) {
            case 0x90: // note on
                getSlaveSyncEffect(usbMIDI.getData1());
            break;
            /*
            case 0: // note on
            break;
            case 3: // CC
            break;
            case 4: // PG
            break;
            case 5: // AT
            break;
            case 6: // PB
            break;
            */
        }
    }
#endif

#ifdef USE_LEONARDO
  midiEventPacket_t rx;
  do
  {
    rx = MidiUSB.read();
    usbMidiNanoloopRealtimeMessage(rx.byte1);
  } while (rx.header != 0);
#endif

}
