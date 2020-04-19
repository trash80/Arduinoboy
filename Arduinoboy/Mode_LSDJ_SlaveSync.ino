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
  digitalWrite(pinStatusLed,LOW);
  pinMode(pinGBClock,OUTPUT);
  digitalWrite(pinGBClock,HIGH);

#ifdef USE_TEENSY
  usbMIDI.setHandleRealTimeSystem(usbMidiLSDJSlaveRealtimeMessage);
#endif

  blinkMaxCount=1000;
  modeLSDJSlaveSync();
}

void modeLSDJSlaveSync()
{
  while(1){  //Loop forever
  modeLSDJSlaveSyncUsbMidiReceive();
  if (serial->available()) {                 //If MIDI Byte Availaibleleleiel
    incomingMidiByte = serial->read();           //Read it

    if(!checkForProgrammerSysex(incomingMidiByte) && !usbMode) serial->write(incomingMidiByte);       //Send it back to the Midi out

    if(incomingMidiByte & 0x80) {               //If we have received a MIDI Status Byte
    switch (incomingMidiByte) {
      case 0xF8:                                //Case: Clock Message Recieved
        if((sequencerStarted && midiSyncEffectsTime && !countSyncTime)   //If the seq has started and our sync effect is on and at zero
          || (sequencerStarted && !midiSyncEffectsTime)) {               //or seq is started and there is no sync effects
              if(!countSyncPulse && midiDefaultStartOffset) {          //if we received a note for start offset
                //sendByteToGameboy(midiDefaultStartOffset);              //send the offset
              }
              sendClockTickToLSDJ();                                   //send the clock tick
              updateVisualSync();
        }
        if(midiSyncEffectsTime) {                                      //If sync effects are turned on
          countSyncTime++;                                             //increment our tick counter
          countSyncTime = countSyncTime % countSyncSteps;              //and mod it by the number of steps we want for the effect
        }
        break;
      case 0xFA:                                // Case: Transport Start Message
      case 0xFB:                                // and Case: Transport Continue Message
        sequencerStart();                       // Start the sequencer
        break;
      case 0xFC:                                // Case: Transport Stop Message
        sequencerStop();                        // Stop the sequencer
        break;
      default:
        if(incomingMidiByte == (0x90+memory[MEM_LSDJSLAVE_MIDI_CH])) { //if a midi note was received and its on the channel of the sync effects channel
           midiNoteOnMode = true;                        //turn on note capture
           midiData[0] = false;                  //and reset the captured note
        } else {
           midiNoteOnMode = false;                       //turn off note capture
        }
      }
    } else if(midiNoteOnMode) {   //if we've received a message thats not a status and our note capture mode is true
      if(!midiData[0]) {                  //if there is no note number yet
         midiData[0] = incomingMidiByte;  //then assume the byte is a note and assign it to a place holder
      } else {                                    //else assumed velocity
         if(incomingMidiByte > 0x00) {
           getSlaveSyncEffect(midiData[0]); //then call our sync effects function
         }
         midiData[0] = false;             //and reset the captured note
      }
    }
  }
  setMode();         //Check if the mode button was depressed
  updateStatusLight();
  }
}

/*
  sendClockTickToLSDJ is a lovely loving simple function I wish they where all this short
  Technicallyly we are sending nothing but a 8bit clock pulse
*/
void sendClockTickToLSDJ()
{
  for(countLSDJTicks=0;countLSDJTicks<8;countLSDJTicks++) {
    GB_SET(0,0,0);
    GB_SET(1,0,0);
  }
}


/*
  getSlaveSyncEffect receives a note, and assigns the propper effect of that note
*/
void getSlaveSyncEffect(byte note)
{
    switch(note) {
    case 48:                        //C-3ish, Transport Start
      sequencerStart();
      break;
    case 49:                        //C#3 Transport Stop
      sequencerStop();
      break;
    case 50:                        //D-3 Turn off sync effects
      midiSyncEffectsTime = false;
      break;
    case 51:                        //D#3 Sync effect, 1/2 time
      midiSyncEffectsTime = true;
      countSyncTime = 0;
      countSyncSteps = 2;
      break;
    case 52:                        //E-3 Sync Effect, 1/4 time
      midiSyncEffectsTime = true;
      countSyncTime = 0;
      countSyncSteps = 4;
      break;
    case 53:                        //F-3 Sync Effect, 1/8 time
      midiSyncEffectsTime = true;
      countSyncTime = 0;
      countSyncSteps = 8;
      break;
    default:                        //All other notes will make LSDJ Start at the row number thats the same as the note number.
      midiDefaultStartOffset = midiData[0];
      break;
    }
}

void usbMidiLSDJSlaveRealtimeMessage(uint8_t message)
{
    switch(message) {
      case 0xF8:
          if((sequencerStarted && midiSyncEffectsTime && !countSyncTime)   //If the seq has started and our sync effect is on and at zero
            || (sequencerStarted && !midiSyncEffectsTime)) {               //or seq is started and there is no sync effects
                if(!countSyncPulse && midiDefaultStartOffset) {          //if we received a note for start offset
                  //sendByteToGameboy(midiDefaultStartOffset);              //send the offset
                }
                sendClockTickToLSDJ();                                   //send the clock tick
                updateVisualSync();
          }
          if(midiSyncEffectsTime) {                                      //If sync effects are turned on
            countSyncTime++;                                             //increment our tick counter
            countSyncTime = countSyncTime % countSyncSteps;              //and mod it by the number of steps we want for the effect
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


void modeLSDJSlaveSyncUsbMidiReceive()
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
      uint8_t ch = rx.byte1 & 0x0F;
      if (ch == memory[MEM_LSDJSLAVE_MIDI_CH] && rx.header == 0x09)
      {
        getSlaveSyncEffect(rx.byte2);
      }
      switch (rx.byte1)
      {
      case 0xF8:
        if ((sequencerStarted && midiSyncEffectsTime && !countSyncTime) //If the seq has started and our sync effect is on and at zero
            || (sequencerStarted && !midiSyncEffectsTime))
        { //or seq is started and there is no sync effects
          if (!countSyncPulse && midiDefaultStartOffset)
          { //if we received a note for start offset
            //sendByteToGameboy(midiDefaultStartOffset);              //send the offset
          }
          sendClockTickToLSDJ(); //send the clock tick
          updateVisualSync();
        }
        if (midiSyncEffectsTime)
        {                                                 //If sync effects are turned on
          countSyncTime++;                                //increment our tick counter
          countSyncTime = countSyncTime % countSyncSteps; //and mod it by the number of steps we want for the effect
        }
        break;
      case 0xFA:          // Case: Transport Start Message
      case 0xFB:          // and Case: Transport Continue Message
        sequencerStart(); // Start the sequencer
        break;
      case 0xFC: // Case: Transport Stop Message
        sequencerStop();
        break;
      }
    } while (rx.header != 0);
#endif
}
