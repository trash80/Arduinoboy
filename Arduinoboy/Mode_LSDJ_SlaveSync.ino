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
  pinMode(pinGBClock,OUTPUT);      //Set the gb clock as output
  digitalWrite(pinGBClock,HIGH);   //Gameboy likes to get high
  digitalWrite(pinGBSerialOut,LOW);//Nothing to send 
  
  modeLSDJSlaveSync();
}

void modeLSDJSlaveSync()
{
  while(1){  //Loop forever
  if (Serial.available() > 0) {                 //If MIDI Byte Availaibleleleiel
    incomingMidiByte = Serial.read();           //Read it
    Serial.print(incomingMidiByte, BYTE);       //Send it back to the Midi out
    
    if(incomingMidiByte > 0x7F) {               //If we have received a MIDI Status Byte
    switch (incomingMidiByte) {                    
      case 0xF8:                                //Case: Clock Message Recieved
        if(sequencerStarted && midiSyncEffectsTime && !countSyncTime   //If the seq has started and our sync effect is on and at zero
          || sequencerStarted && !midiSyncEffectsTime) {               //or seq is started and there is no sync effects
              if(!countSyncPulse && midiDefaultStartOffset) {          //if we received a note for start offset
                sendByteReversed(midiDefaultStartOffset);              //send the offset
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
        if(incomingMidiByte == syncEffectsMidiChannel) { //if a midi note was received and its on the channel of the sync effects channel
           midiNoteOnMode = true;                        //turn on note capture
           incomingMidiData[0] = false;                  //and reset the captured note
        } else {
           midiNoteOnMode = false;                       //turn off note capture
        }
      }
    } else if(midiNoteOnMode) {   //if we've received a message thats not a status and our note capture mode is true
      if(!incomingMidiData[0]) {                  //if there is no note number yet
         incomingMidiData[0] = incomingMidiByte;  //then assume the byte is a note and assign it to a place holder
      } else {                                    //else assumed velocity
         if(incomingMidiByte > 0x00) {            
           getSlaveSyncEffect(incomingMidiData[0]); //then call our sync effects function
         }
         incomingMidiData[0] = false;             //and reset the captured note
      }
    }
  }
  setMode();         //Check if the mode button was depressed
  updateStatusLight();
  }
}

/*
  Again its magic time, but this time its backweirds
  We'll send a byte to the gameboy starting with big endian
  From this point on I'm sick of writing comments
*/
void sendByteReversed(byte send_byte)
{
  for(countLSDJTicks=0;countLSDJTicks<8;countLSDJTicks++) {  //NEWS FLASH: there are 8 bits in a byte
    digitalWrite(pinGBClock,LOW);                            //Set the clock to zero, wes about to send you somethin
    if(send_byte & 0x80) {                                   //Magic
      digitalWrite(pinGBSerialOut,HIGH);                     //1
    } else {
      digitalWrite(pinGBSerialOut,LOW);                      //0
    }
    send_byte <<= 1;                                         //More magic
    digitalWrite(pinGBClock,HIGH);                           //Make the clock 1, so we can make a funky squarewave
  }
  digitalWrite(pinGBSerialOut,LOW);                          //We are done, turn the serial off
}

/*
  sendClockTickToLSDJ is a lovely loving simple function I wish they where all this short
  Technicallyly we are sending nothing but a 8bit clock pulse
*/
void sendClockTickToLSDJ()
{
  for(countLSDJTicks=0;countLSDJTicks<8;countLSDJTicks++) {
    digitalWrite(pinGBClock,LOW);digitalWrite(pinGBClock,HIGH);
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
      midiDefaultStartOffset = incomingMidiData[0];
      break;
    }
}
