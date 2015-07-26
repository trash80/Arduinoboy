/**************************************************************************
 *         A     R     D     U     I     N     O     B     O     Y        *
 *                                                                        *
 * Version: 0.3.1                                                         *
 * Date:    Feb 25 2008                                                   *
 * Name:    Timothy Lamb                                                  *
 * Email:   trash80@gmail.com                                             *
 *                                                                        *
 ***************************************************************************/
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
 
 
/***************************************************************************
* Simple User Settings
***************************************************************************/

int syncEffectsMidiChannel = 8; //midi sync effects, not implemented yet
int mode = 0;  //Mode 0: Midi Input to LSDJ Sync, Mode 1: LSDJ MASTER to Midi output

/***************************************************************************
* Lets Assign our Arduino Pins .....
***************************************************************************/
int gbClockLine = 12;    // clock out to gameboy
int gbSerialOut = 11;    // serial data to gameboy
int gbSerialIn = 10;    // serial data from gameboy

int midiInputPower = 2; // power pin for midi input opto-isolator

int ledSequencerStop = 8; // stopped light pin
int ledSequencerStart = 9;  // start light pin

/***************************************************************************
* Switches and states
***************************************************************************/
boolean sequencerStarted = false;        //Sequencer has Started
boolean midiSyncEffectsHalfTime = false; //Not Implemented yet

/***************************************************************************
* Counter vars
***************************************************************************/
int countLSDJTicks = 0;            //for loop int (we need to cycle 8 pulses)
boolean countSyncHalfTime = true;  //future feature, Not implemented
int countGbClockTicks =0;
int countClockPause =0;
int countIncommingMidiByte =0;


/***************************************************************************
* Inbound Data Placeholders
***************************************************************************/
byte incomingMidiByte;  //incomming midi message
byte readgbClockLine;
byte readGbSerialIn;

int incomingMidiNote = 0;
int incomingMidiVel = 0;


void setup() {
/*
  Init Pins
*/
  pinMode(ledSequencerStop,OUTPUT); 
  pinMode(ledSequencerStart,OUTPUT); 
  
  if(mode==0) {
    pinMode(gbClockLine,OUTPUT); 
    pinMode(gbSerialOut,OUTPUT); 
    pinMode(midiInputPower,OUTPUT); 
  } else if (mode==1) {
    pinMode(gbClockLine,INPUT); 
    pinMode(gbSerialIn,INPUT);
  }
/*
  Set MIDI Serial Rate
*/
  Serial.begin(31250);
  
/*
  Set Pin States
*/
  digitalWrite(midiInputPower, HIGH); // turn on the optoisolator
  digitalWrite(gbClockLine, HIGH);    // gameboy wants a HIGH line
  digitalWrite(gbSerialOut, LOW);    // no data to send
  digitalWrite(ledSequencerStop, HIGH);  // then turn it on
  
/*
  Misc Startup
*/
  syncEffectsMidiChannel = 143 + syncEffectsMidiChannel; //set the midi channel to the real number (144 to 159)
}

void loop () {
  switch(mode) {
    case 0:
     modeGameboySlaveSync();
     break;
    case 1:
     modeGameboyMasterSync();
     break;
  }
}

void modeGameboyMasterSync()
{
  while(1){
  readgbClockLine = digitalRead(gbClockLine); //Read gameboy's clock line
  if(readgbClockLine) {
    while(readgbClockLine) {
      countClockPause++;
      if(sequencerStarted && countClockPause > 8000) {
          Serial.print(0xFC, BYTE);
          countClockPause = 0;
          sequencerStop();
      }
      readgbClockLine = digitalRead(gbClockLine);
    }
    countClockPause = 0;
    countGbClockTicks++;
    if(countGbClockTicks == 8) {
      countGbClockTicks=0;
      if(!sequencerStarted) {
          Serial.print(0xFA, BYTE);
          sequencerStart();
      }
      Serial.print(0xF8, BYTE);
    }
  }
  }
}

void modeGameboySlaveSync()
{
  while(1){
  if (Serial.available() > 0) {
    incomingMidiByte = Serial.read();
    switch (incomingMidiByte) {
      case 248: // Clock Message Recieved
        //send a clock tick out if the sequencer is runn
        if(sequencerStarted && midiSyncEffectsHalfTime && countSyncHalfTime
          || sequencerStarted && !midiSyncEffectsHalfTime) {
          sendClockTickToLSDJ();
        }
        if(midiSyncEffectsHalfTime) countSyncHalfTime = !countSyncHalfTime;
        break;
      case 250: // Transport Start Message
      case 251: // Transport Continue Message
        sequencerStart();
        break;
      case 252: // Transport Stop Message
        sequencerStop();
        break;
      default:
        if(incomingMidiByte == syncEffectsMidiChannel) {
           // This doesnt work yet
           // getNote();
        }
        break;
    }
  } 
  }
}

void sequencerStart()
{
  digitalWrite(ledSequencerStart, HIGH);
  digitalWrite(ledSequencerStop, LOW);
  sequencerStarted = true;
}

void sequencerStop()
{
  digitalWrite(ledSequencerStart, LOW);
  digitalWrite(ledSequencerStop, HIGH);
  midiSyncEffectsHalfTime = false;
  sequencerStarted = false;
}

void sendClockTickToLSDJ()
{
  for(countLSDJTicks=0;countLSDJTicks<8;countLSDJTicks++) {
    digitalWrite(gbClockLine,LOW);digitalWrite(gbClockLine,HIGH);
  }
}

void getNote()
{
  countIncommingMidiByte = 0;
  while(countIncommingMidiByte < 2) {
    if (Serial.available() > 0) {
      countIncommingMidiByte++;
      incomingMidiByte = Serial.read();
      if(countIncommingMidiByte == 1) {
        incomingMidiNote = incomingMidiByte;
      } else if(incomingMidiByte > 0) {
        switch(incomingMidiNote) {
          case 60:
            sequencerStart();
            break;
          case 61:
            sequencerStop();
            break;
          case 62:
            midiSyncEffectsHalfTime = !midiSyncEffectsHalfTime;
            countSyncHalfTime = true;
            break;
         }
      }
    }
  }
}
