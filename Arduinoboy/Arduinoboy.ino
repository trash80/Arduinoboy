/***************************************************************************
 ***************************************************************************
 *                         __      _             __                        *
 *         ____ __________/ /_  __(_)___  ____  / /_  ____  __  __         *
 *        / __ `/ ___/ __  / / / / / __ \/ __ \/ __ \/ __ \/ / / /         *
 *       / /_/ / /  / /_/ / /_/ / / / / / /_/ / /_/ / /_/ / /_/ /          *
 *       \__,_/_/   \__,_/\__,_/_/_/ /_/\____/_.___/\____/\__, /           *
 *                                                       /____/            *
 *                                                                         *
 ***************************************************************************
 ***************************************************************************
 *                                                                         *
 * Version: 1.0.1                                                        *
 * Date:    Oct 12 2008                                                    *
 * Name:    Timothy Lamb                                                   *
 * Email:   trash80@gmail.com                                              *
 *                                                                         *
 ***************************************************************************
 ***************************************************************************
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
int masterNotePositionMidiChannel = 16;   //LSDJ in master mode will send its song position on the start button via midi note.
int keyboardInstrumentMidiChannel = 16;  //midi channel for keyboard instruments in lsdj.

boolean keyboardCompatabilityMode = true; //Set to true if you are using LSDJ version lower then 2.6, not working right now
boolean keyboardMidiChannelToInstrument = true; //Set to true if you want to have midi channel set the instrument number

//Mode 0: Midi Input to LSDJ Sync
//Mode 1: LSDJ MASTER to Midi output
//Mode 2: LSDJ Keyboard
//Mode 3: Midi Input to Nanoloop 
//Mode 4: Midi Input to mGB cart (available at: code.google.com/p/ardunioboy) 

boolean forceMode = false; //Enforces the mode above, without reading from memory, use this to force the mode if you dont have a push button setup. 
int mode          = 0;    //0 to 4 - default mode for force mode
int numberOfModes = 5;    //Right now there are 5 modes, Might be more in the future
boolean usbMode   = false; //to use usb for serial communication as oppose to MIDI - sets baud rate to 38400

int gameboyBitPauseLOW  = 5;    //Bit pause for gbmidi mode    .... 1 to 10 /// tested working value: 5=GBA/SP/DMG01   ---   
int gameboyBitPauseHIGH = 1;    //Bit pause for gbmidi mode    .... 1 to 10 /// tested working value: 1=GBA/SP/DMG01   ---    (note: roughly 4 microseconds off from Low do to code that writes to the serial line)
int gameboyBytePause= 10;       //Byte pause for gbmidi mode   .... 5 to 20 /// tested working value: 5=GBA/SP/GBC and 10=DMG

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
boolean midiAddressMode  =false;
boolean midiValueMode    =false;

boolean statusLedIsOn    =false;
boolean statusLedBlink   =false;

boolean nanoState        =false;
boolean nanoSkipSync     =false;

boolean blinkSwitch[5];
unsigned long int blinkSwitchTime[5];
int switchLight = 0;

/***************************************************************************
* Counter vars
***************************************************************************/
int countLSDJTicks = 0;            //for loop int (we need to cycle 8 pulses)
int countSyncTime  = 0;
int countSyncLightTime=0;
int countSyncSteps = 0;
int countSyncPulse = 0;
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
byte bit;
int incomingMidiData[] = {0, 0, 0};
int lastMidiData[] = {0, 0, 0};

int incomingMidiNote = 0;
int incomingMidiVel = 0;
byte readToggleMode;
byte serialWriteBuffer[256];
byte midiDefaultStartOffset;
int  writePosition=0;
int  readPosition=0;
int lastMode=0; //Stores the last selected mode for leds.
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
byte keyboardStartOctave = 0x24;
byte keyboardNoteStart = 0;
byte keyboardNoteOffset = 0;
byte keyboardCommands[12];

void setup() {
/*
  Init Pins
*/
  for(int led=0;led<=5;led++) pinMode(pinLeds[led],OUTPUT);
  pinMode(pinStatusLed,OUTPUT);
  
  pinMode(pinButtonMode,INPUT); 
  
  pinMode(pinGBClock,OUTPUT); 
  pinMode(pinGBSerialOut,OUTPUT); 
  pinMode(pinGBSerialIn,INPUT);
/*
  Set MIDI Serial Rate
*/
  if(usbMode == true) {
    Serial.begin(38400); //31250
  } else {
    pinMode(pinMidiInputPower,OUTPUT); 
    digitalWrite(pinMidiInputPower,HIGH); // turn on the optoisolator
    Serial.begin(31250); //31250
  }
/*
  Set Pin States
*/
  digitalWrite(pinGBClock,HIGH);    // gameboy wants a HIGH line
  digitalWrite(pinGBSerialOut,LOW);    // no data to send
/*
  Misc Startup
*/
  syncEffectsMidiChannel = 143 + syncEffectsMidiChannel; //set the midi channel to the real note-on number (144 to 159)
  keyboardInstrumentMidiChannel = 143 + keyboardInstrumentMidiChannel; //set the midi channel to the real note-on number (144 to 159)
  masterNotePositionMidiChannel = 143 + masterNotePositionMidiChannel; //set the midi channel to the real note-on number (144 to 159)
  keyboardNoteStart = keyboardStartOctave + 12; // Set the octave where the actual notes start (the octave below is for the mutes, cursor, etc)
/*
  Assign the keyboard mode command array for the first octave
*/
  keyboardCommands[0] = keyboardMut1;
  keyboardCommands[1] = keyboardMut2;
  keyboardCommands[2] = keyboardMut3;
  keyboardCommands[3] = keyboardMut4;
  keyboardCommands[4] = keyboardCurL;
  keyboardCommands[5] = keyboardCurR;
  keyboardCommands[6] = keyboardCurU;
  keyboardCommands[7] = keyboardCurD;
  keyboardCommands[8] = keyboardEntr;
  keyboardCommands[9] = keyboardTblDn;
  keyboardCommands[10] = keyboardTblUp;
  keyboardCommands[11] = keyboardTblCue;
/*
  Load Settings from EEPROM
*/
  if(!forceMode) mode = EEPROM.read(eepromMemoryByte);
  lastMode = mode;
  showSelectedMode(); //Light up the LED that shows which mode we are in.
}

/*
  Main Loop, which we don't use to be able to isolate each mode into its own setup and loop functions
*/
void loop () {
  setMode();
  switchMode();
}
