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
  DDRC  = B00000000; //Set analog in pins as inputs
  countSyncTime=0;
  blinkMaxCount=1000;
  modeLSDJMasterSync();
}

void modeLSDJMasterSync()
{
  while(1){
    if (Serial.available()) {                  //If serial data was send to midi input
      incomingMidiByte = Serial.read();            //Read it
      if(!checkForProgrammerSysex(incomingMidiByte) && !usbMode) Serial.write(incomingMidiByte);        //Send it to the midi output
    }
    readgbClockLine = PINC & 0x01; //Read gameboy's clock line
    if(readgbClockLine) {                          //If Gb's Clock is On
      while(readgbClockLine) {                     //Loop untill its off
        readgbClockLine = PINC & 0x01;            //Read the clock again
        bit = (PINC & 0x04)>>2;                   //Read the serial input for song position
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
  countClockPause++;                                 //Increment the counter
  if(countClockPause > 16000) {                      //if we've reached our waiting period
    if(sequencerStarted) {
      readgbClockLine=false;
      countClockPause = 0;                           //reset our clock
      Serial.write(0xFC);                      //send the transport stop message
      sequencerStop();                               //call the global sequencer stop function
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
      Serial.write((0x90+memory[MEM_LSDJMASTER_MIDI_CH])); //Send the midi channel byte
      Serial.write(readGbSerialIn);                //Send the row value as a note
      Serial.write(0x7F);                          //Send a velocity 127
      
      Serial.write(0xFA);     //send MIDI transport start message 
      sequencerStart();             //call the global sequencer start function
    }
    Serial.write(0xF8);       //Send the MIDI Clock Tick
    
    countGbClockTicks=0;            //Reset the bit counter
    readGbSerialIn = 0x00;                //Reset our serial read value
    
    updateVisualSync();
  }
  countGbClockTicks++;              //Increment the bit counter
 if(countGbClockTicks==8) countGbClockTicks=0; 
}
