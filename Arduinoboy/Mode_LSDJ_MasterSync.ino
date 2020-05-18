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


void modeLSDJMasterSyncSetup()
{
  digitalWrite(pinStatusLed,LOW);
  pinMode(pinGBClock,INPUT);

  #ifdef USE_TEENSY
  usbMIDI.setHandleRealTimeSystem(NULL);
  #endif

  countSyncTime=0;
  blinkMaxCount=1000;
  modeLSDJMasterSync();
}

void modeLSDJMasterSync()
{
  while(1){

#ifdef USE_TEENSY
    while(usbMIDI.read()) ;
#endif

    if (serial->available()) {                  //If serial data was send to midi input
      incomingMidiByte = serial->read();            //Read it
      if(!checkForProgrammerSysex(incomingMidiByte) && !usbMode) serial->write(incomingMidiByte);        //Send it to the midi output
    }
    readgbClockLine = digitalRead(pinGBClock);    //Read gameboy's clock line
    if(readgbClockLine) {                         //If Gb's Clock is On
      while(readgbClockLine) {                    //Loop untill its off
        readgbClockLine = digitalRead(pinGBClock);//Read the clock again
        bit = digitalRead(pinGBSerialIn);         //Read the serial input for song position
        checkActions();
      }

      countClockPause= 0;                          //Reset our wait timer for detecting a sequencer stop

      readGbSerialIn = readGbSerialIn << 1;        //left shift the serial byte by one to append new bit from last loop
      readGbSerialIn = readGbSerialIn + bit;       //and then add the bit that was read

      sendMidiClockSlaveFromLSDJ();                //send the clock & start offset data to midi

    }
    setMode();
  }
}

void checkActions()
{
  checkLSDJStopped();                        //Check if LSDJ hit Stop
  setMode();
  updateStatusLight();
}

 /*
  checkLSDJStopped counts how long the clock was on, if its been on too long we assume
  LSDJ has stopped- Send a MIDI transport stop message and return true.
 */
boolean checkLSDJStopped()
{
  countClockPause++;                            //Increment the counter
  if(countClockPause > 16000) {                 //if we've reached our waiting period
    if(sequencerStarted) {
      readgbClockLine=false;
      countClockPause = 0;                      //reset our clock
      serial->write(0xFC);                      //send the transport stop message
#ifdef USE_TEENSY
      usbMIDI.sendRealTime(0xFC);
#endif
#ifdef USE_LEONARDO
      midiEventPacket_t event = {0x0F, 0xFC};
      MidiUSB.sendMIDI(event);
      MidiUSB.flush();
#endif
      sequencerStop();                          //call the global sequencer stop function
    }
    return true;
  }
  return false;
}

 /*
  sendMidiClockSlaveFromLSDJ waits for 8 clock bits from LSDJ,
  sends the transport start command if sequencer hasnt started yet,
  sends the midi clock tick, and sends a note value that corrisponds to
  LSDJ's row number on start (LSDJ only sends this once when it starts)
 */
void sendMidiClockSlaveFromLSDJ()
{
  if(!countGbClockTicks) {      //If we hit 8 bits
    if(!sequencerStarted) {         //If the sequencer hasnt started
      serial->write((0x90+memory[MEM_LSDJMASTER_MIDI_CH])); //Send the midi channel byte
      serial->write(readGbSerialIn);                //Send the row value as a note
      serial->write(0x7F);                          //Send a velocity 127
      serial->write(0xFA);     //send MIDI transport start message

#ifdef USE_TEENSY
      usbMIDI.sendNoteOn(memory[MEM_LSDJMASTER_MIDI_CH]+1,readGbSerialIn,0x7F);
      usbMIDI.sendRealTime(0xFA);
#endif
#ifdef USE_LEONARDO
      midiEventPacket_t event = {0x09, 0x90 | memory[MEM_LSDJMASTER_MIDI_CH] + 1, readGbSerialIn, 0x7F};
      MidiUSB.sendMIDI(event);
      MidiUSB.flush();
      event = {0x0F, 0xFA};
      MidiUSB.sendMIDI(event);
      MidiUSB.flush();
#endif
      sequencerStart();             //call the global sequencer start function
    }
    serial->write(0xF8);       //Send the MIDI Clock Tick

#ifdef USE_TEENSY
    usbMIDI.sendRealTime(0xF8);
#endif
#ifdef USE_LEONARDO
    midiEventPacket_t event = {0x0F, 0xF8};
    MidiUSB.sendMIDI(event);
    MidiUSB.flush();
#endif
    countGbClockTicks=0;            //Reset the bit counter
    readGbSerialIn = 0x00;                //Reset our serial read value

    updateVisualSync();
  }
  countGbClockTicks++;              //Increment the bit counter
 if(countGbClockTicks==8) countGbClockTicks=0;
}
