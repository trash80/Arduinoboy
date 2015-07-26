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
  pinMode(pinGBClock,INPUT); //Set the gb clock as input, we will be reading from the clock
  countSyncTime=0;
  modeLSDJMasterSync();
}

void modeLSDJMasterSync()
{
  while(1){
    readgbClockLine = digitalRead(pinGBClock); //Read gameboy's clock line
    if(readgbClockLine) {                          //If Gb's Clock is On
      while(readgbClockLine) {                     //Loop untill its off
        checkLSDJStopped();                        //Check if LSDJ hit Stop
        readgbClockLine = digitalRead(pinGBClock); //Read the clock again
        bit = digitalRead(pinGBSerialIn);          //Read the serial input for song position
        setMode();
        updateStatusLight();
      }
      countClockPause= 0;                          //Reset our wait timer for detecting a sequencer stop
      
      readGbSerialIn = readGbSerialIn << 1;        //left shift the serial byte by one to append new bit from last loop
      readGbSerialIn = readGbSerialIn + bit;       //and then add the bit that was read

      sendMidiClockSlaveFromLSDJ();                //send the clock & start offset data to midi
    }
    
    if (Serial.available() > 0) {                  //If serial data was send to midi input
      incomingMidiByte = Serial.read();            //Read it
      Serial.print(incomingMidiByte, BYTE);        //Send it to the midi output
    }
  }
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
      countClockPause = 0;                           //reset our clock
      Serial.print(0xFC, BYTE);                      //send the transport stop message
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
      Serial.print(masterNotePositionMidiChannel, BYTE); //Send the midi channel byte
      Serial.print(readGbSerialIn, BYTE);                //Send the row value as a note
      Serial.print(0x7F, BYTE);                          //Send a velocity 127
      
      Serial.print(0xFA, BYTE);     //send MIDI transport start message 
      sequencerStart();             //call the global sequencer start function
    }
    Serial.print(0xF8, BYTE);       //Send the MIDI Clock Tick
    
    countGbClockTicks=0;            //Reset the bit counter
    readGbSerialIn = 0x00;                //Reset our serial read value
    
    updateVisualSync();
  }
  countGbClockTicks++;              //Increment the bit counter
 if(countGbClockTicks==8) countGbClockTicks=0; 
}
