/***************************************************************************
 *         A     R     D     U     I     N     O     B     O     Y         *
 *                                                                         *
 * Version: 0.8.6                                                          *
 * Date:    March 07 2008                                                  *
 * Name:    Timothy Lamb                                                   *
 * Email:   trash80@gmail.com                                              *
 *                                                                         *
 * Notes:                                                                  *
 *     Pins have changed from the original diagram, expect build           *
 *     instructions to follow here soon:                                   *
 *     http://code.google.com/p/arduinoboy/                                *
 *                                                                         *
 *   Arduino pin settings:  (Layout is final)                              *
 *     - 6 LEDS on pins 8 to 13                                            *
 *     - Push button on pin 3 (for selecting mode)                         *
 *     - MIDI Opto-isolator power on pin 4                                 *
 *     - Gameboy Clock line on pin 5                                       *
 *     - Gameboy Serial Data input on 6                                    *
 *     - Serial Data from gameboy on pin 7                                 *
 *                                                                         *
 * Program Information:                                                    *
 *    LSDJ Slave Mode Midi Note Effects:                                   *
 *      48 - C-2 Sends a Sequencer Start Command                           *
 *      49 - C#2 Sends a Sequencer Stop Command                            *
 *      50 - D-2 Toggles Normal Tempo                                      *
 *      51 - D#2 Toggles 1/2 Tempo                                         *
 *      52 - E-2 Toggles 1/4 Tempo                                         *
 *      53 - F-2 Toggles 1/8 Tempo                                         *
 *                                                                         *
 *    LSDJ Keyboard Mode:                                                  *
 *      48 - C-2 Mute Pu1 Off/On                                           *
 *      49 - C#2 Mute Pu2 Off/On                                           *
 *      50 - D-2 Mute Wav Off/On                                           *
 *      51 - D#2 Mute Noi Off/On                                           *
 *      52 - E-2 Livemode Cue Sequence                                     *
 *      53 - F-2 Livemode Cursor Up                                        *
 *      54 - F#2 Livemode Cursor Down                                      *
 *      55 - G-2 Livemode Cursor Left                                      *
 *      56 - G#2 Livemode Cursor Right                                     *
 *      57 - A-2 Table Up                                                  *
 *      58 - A#2 Table Down                                                *
 *      59 - B-2 Cue Table                                                 *
 *      60 - C-3 to C-8 Notes!                                             *
 *      Prgram Change to select from instrument table                      *
 *                                                                         *
 *    Special Thanks to firestARTer for help with                          *
 *    keyboard & Midi handling information.                                *
 *                                                                         *
 ***************************************************************************/
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
 #include <EEPROM.h>
 
/***************************************************************************
* Simple User Settings
***************************************************************************/
int syncEffectsMidiChannel = 16;         //midi sync effects for lsdj slave mode
int keyboardInstrumentMidiChannel = 16;  //midi channel for keyboard instruments in lsdj

//Mode 0: Midi Input to LSDJ Sync, Mode 1: LSDJ MASTER to Midi output, Mode 2: LSDJ Keyboard
int mode = 0;

//Enforces the mode above, without reading from memory, use this to force the mode if you dont have a push button setup. 
boolean forceMode = false; 

/***************************************************************************
* Lets Assign our Arduino Pins .....
***************************************************************************/

int pinGBClock = 5;    // clock out to gameboy
int pinGBSerialOut = 6;    // serial data to gameboy
int pinGBSerialIn = 7;    // serial data from gameboy

int pinMidiInputPower = 4; // power pin for midi input opto-isolator

int pinStatusLed = 13; // Status LED
int pinLeds[] = {12,11,10,9,8}; // LED Pins

int pinButtonMode = 3; //toggle button for selecting the mode

/***************************************************************************
* Memory
***************************************************************************/

int eepromMemoryByte = 0; //Location of where to store settings from mem

/***************************************************************************
* Switches and states
***************************************************************************/
boolean sequencerStarted = false;        //Sequencer has Started
boolean midiSyncEffectsTime = false;
boolean midiNoteOnMode   =false;
boolean midiNoteOffMode  =false;
boolean midiProgramChange=false;
boolean statusLedIsOn    =false;
boolean statusLedBlink   =false;
/***************************************************************************
* Counter vars
***************************************************************************/
int countLSDJTicks = 0;            //for loop int (we need to cycle 8 pulses)
int countSyncTime  = 0;
int countSyncSteps = 0;
int countGbClockTicks =0;
int countClockPause =0;
int countIncommingMidiByte =0;
int countStatusLedOn =0;
unsigned int waitClock =0;
/***************************************************************************
* Inbound Data Placeholders
***************************************************************************/
byte incomingMidiByte;  //incomming midi message
byte readgbClockLine;
byte readGbSerialIn;
int incomingMidiData[] = {0, 0, 0};

int incomingMidiNote = 0;
int incomingMidiVel = 0;
byte readToggleMode;
byte serialWriteBuffer[256];
int  writePosition=0;
int  readPosition=0;
/***************************************************************************
* LSDJ Keyboard mode settings
***************************************************************************/      
byte keyboardNotes[] = {0x1A,0x1B,0x22,0x23,0x21,0x2A,0x34,0x32,0x33,0x31,0x3B,0x3A,
                         0x15,0x1E,0x1D,0x26,0x24,0x2D,0x2E,0x2C,0x36,0x35,0x3D,0x3C};
byte keyboardOctDn = 0x05;
byte keyboardOctUp = 0x06;

byte keyboardInsDn = 0x04;
byte keyboardInsUp = 0x0C;

byte keyboardTblDn = 0x03;
byte keyboardTblUp = 0x0B;

byte keyboardTblCue= 0x29;

byte keyboardMut1 = 0x01;
byte keyboardMut2 = 0x09;
byte keyboardMut3 = 0x78;
byte keyboardMut4 = 0x07;

byte keyboardCurL = 0x6B;
byte keyboardCurR = 0x74;
byte keyboardCurU = 0x75;
byte keyboardCurD = 0x72;
byte keyboardPgUp = 0x7D;
byte keyboardPgDn = 0x7A;
byte keyboardEntr = 0x5A;

int keyboardCurrentOct = 0;
int keyboardCurrentIns = 0;
int keyboardCurrentTbl = 0;

int keyboardLastOct = 0;
int keyboardLastIns = 0;
int keyboardLastTbl = 0;

int keyboardDiff = 0;
int keyboardCount = 0;

void setup() {
/*
  Init Pins
*/
  for(int led=0;led<=5;led++) pinMode(pinLeds[led],OUTPUT);
  pinMode(pinStatusLed,OUTPUT);
  
  pinMode(pinButtonMode,INPUT); 
  
  pinMode(pinGBClock,OUTPUT); 
  pinMode(pinGBSerialOut,OUTPUT); 
  pinMode(pinMidiInputPower,OUTPUT); 
  pinMode(pinGBSerialIn,INPUT);
/*
  Set MIDI Serial Rate
*/
  Serial.begin(31250);
  
/*
  Set Pin States
*/
  digitalWrite(pinMidiInputPower,HIGH); // turn on the optoisolator
  digitalWrite(pinGBClock,HIGH);    // gameboy wants a HIGH line
  digitalWrite(pinGBSerialOut,LOW);    // no data to send
  digitalWrite(pinStatusLed,HIGH);
/*
  Misc Startup
*/
  syncEffectsMidiChannel = 143 + syncEffectsMidiChannel; //set the midi channel to the real number (144 to 159)
  keyboardInstrumentMidiChannel = 143 + keyboardInstrumentMidiChannel; //set the midi channel to the real number (144 to 159)
  
/*
  Load Settings from EEPROM
*/
  if(!forceMode) mode = EEPROM.read(eepromMemoryByte);
  showSelectedMode();
}

void loop () {
  setMode();
  switchMode();
}
