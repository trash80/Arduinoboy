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

void modeLSDJKeyboardSetup()
{
  digitalWrite(pinStatusLed,LOW);
  pinMode(pinGBClock,OUTPUT);     //make sure our gameboy Clock is set for OUTPUT mode
  digitalWrite(pinGBClock,LOW);   //Generally this should be HIGH ie: 1, on, whatever. but since we are emulating a pc keyboard it should be LOW/0/off
  addGameboyByte(0);              //Send 8bits of nothing. don't ask I dont know.
  
  /* The stuff below makes sure the code is in the same state as LSDJ on reset / restart, mode switched, etc. */
  
  for(int rst=0;rst<5;rst++) addGameboyByte(keyboardOctDn);   //Return lsdj to the first octave
  for(int rst=0;rst<41;rst++) addGameboyByte(keyboardInsDn);  //Return lsdj to the first instrument
  
  keyboardCurrentOct = 0;  //Set our current octave to 0.
  keyboardLastOct    = 0;  //Set our last octave to 0.
  keyboardCurrentIns = 0;  //Set out current instrument to 0.
  keyboardLastIns    = 0;  //Set out last used instrument to 0.
  
  
  modeLSDJKeyboard();      //.... And start the fun
}


void modeLSDJKeyboard()
{
  while(1){                              //Loop foreverrrr
  if (Serial.available() > 0) {          //If MIDI is sending
    incomingMidiByte = Serial.read();    //Get the byte sent from MIDI
    Serial.print(incomingMidiByte, BYTE);//Echo the Byte to MIDI Output
    

    /***************************************************************************
     * Midi to LSDJ Keyboard Handling                                          *
     ***************************************************************************/
    //If the byte is a Status Message
    if(incomingMidiByte > 0x7F) {    
      /* Status message Information (# = midi channel 0 to F [1-16] )
          0x8# = Note Off
          0x9# = Note On
          0xA# = AfterTouch (ie, key pressure)
          0xB# = Control Change
          0xC# = Program (patch) change
          0xD# = Channel Pressure
          0xE# = Pitch Wheel      
          0xF0 - 0xF7 = System Common Messages
          0xF8 - 0xFF = System Realtime Messages
      */
      
      //Weee hello world bitwise and. ... make the second hex digit zero so we can have a simple case statement
      // - the second digit is usually the midi channel 0 to F (1-16) unless its a 0xF0 message...
      switch (incomingMidiByte & 0xF0) {
        case 0x90:
          //Note-On Status Message (Note: we have to treat this carefully because note status isnt sent on every note-on, damn it)
          //There are 3 bytes total we need: Channel, Note, and velocity, these wil be assigned to a array until we have the velocity,
          //at that point we can then call our note out function to LSDJ
          midiNoteOnMode = true;                    //Set our stupid "Note on mode" on
          incomingMidiData[0] = incomingMidiByte;   //Assign the byte to the first position of a data array. (this is the midi channel)
          incomingMidiData[1] = false;              //Force the second position to false (this will hold the note number)
          break;
        case 0xC0:
          //Program change message
          midiProgramChange = true;                   //Set our silly "Program Change mode" ... we need to get the next byte later
          midiNoteOnMode = false;                     //Turn Note-on mode off
          incomingMidiData[0] = incomingMidiByte - 48;//Set the number to a "note on" message so we can use the same "channel" variable as note on messages
          break;
        case 0xF0:
           //Do nothing, these dont interfear with our note-on mode
          break;
        default:
          //Turn Note-On mode off
          midiNoteOnMode = false;
          break;
      }
    } else if(midiNoteOnMode) {
      //It wasnt a status bit, so lets assume it was a note message if the last status message was note-on.
      if(!incomingMidiData[1]) {
         //If we dont have a note number, we assume this byte is the note number, get it...
         incomingMidiData[1] = incomingMidiByte;
      } else {
         //We have our note and channel, so call our note function...        
         playLSDJNote(incomingMidiData[0], incomingMidiData[1], incomingMidiByte);
         incomingMidiData[1] = false; //Set the note to false, forcing to capture the next note
      }
    } else if (midiProgramChange) {
        changeLSDJInstrument(incomingMidiData[0], incomingMidiByte); 
        midiProgramChange = false;
        incomingMidiData[0] = false;
    }
  }
  
  updateGameboyByteFrame(); // Send out Bytes to LSDJ
  updateStatusLed();        // Update our status blinker
  setMode();                // Check if mode button was depressed
  }
}


 /*
  changeLSDJInstrument does what it does via magic (rtfm, realize the fucking magic)
 */
void changeLSDJInstrument(byte channel,byte message)
{
  keyboardCurrentIns = message; //set the current instrument number 
  
  if(channel == keyboardInstrumentMidiChannel && keyboardCurrentIns != keyboardLastIns) { 
  //if its on our midi channel and the instrument isnt the same as our currrent
    if(!keyboardCompatabilityMode) {
      addGameboyByte(0x80 | message); // <- this is suppose to work but doesn't :/
    } else {
      //We will find out which is greater, the current instrument or the last instrument. then
      //cycle up or down to that instrument
      if(keyboardCurrentIns > keyboardLastIns) {
        keyboardDiff = keyboardCurrentIns - keyboardLastIns;
        for(keyboardCount=0;keyboardCount<keyboardDiff;keyboardCount++) {
          addGameboyByte(keyboardInsUp);  //send the instrument up command to go up to the requested instrument
        }
      } else {
        keyboardDiff = keyboardLastIns - keyboardCurrentIns;
        for(keyboardCount=0;keyboardCount<keyboardDiff;keyboardCount++) {
          addGameboyByte(keyboardInsDn);  //send the instrument down command to down to the requested instrument
        }
      }
    }
    keyboardLastIns = keyboardCurrentIns; //assign our instrument for future reference to this function
  }
}


 /*
  w00t...
 */
void playLSDJNote(byte channel,byte note, byte velocity)
{
  if(channel == keyboardInstrumentMidiChannel
     && velocity > 0x00) { //If midi channel = ours and the velocity is greater then 0
    if(note >= keyboardNoteStart) {
      keyboardNoteOffset = 0;
      note = note - keyboardNoteStart;  //subtract the octave offset to get a value ranging from 0 to 48 for comparison 
      
      keyboardCurrentOct = note / 0x0C;  //get a octave value from 0 to 4 by deviding the current note by 12
      changeLSDJOctave(); 
      
      if(note >= 0x3C) keyboardNoteOffset = 0x0C; //if the note really high we need to use the second row of keyboard keys
      note = (note % 12) + keyboardNoteOffset;    //get a 0 to 11 range of notes and add the offset 
      addGameboyByte(keyboardNotes[note]);        // and finally send the note
    
    } else if (note >= keyboardStartOctave) { //If we are at the octave below notes
      keyboardDiff = note - keyboardStartOctave; //Get a value between 0 and 11
      if(keyboardDiff < 8 && keyboardDiff > 3) addGameboyByte(0xE0); //if we are sending cursor values we have to send a 0xE0 byte for "extended" pc keyboard mode
      addGameboyByte(keyboardCommands[note - keyboardStartOctave]); //send the byte corrisponding to the note number in the keyboard command array
    }
  }
}


 /*
  changeLSDJOctave compares the last octave with the current one and then sends a byte
  to shift the octave to match if need be. its pretty much the same as the changeLSDJInstrument function.
 */
void changeLSDJOctave()
{
  if(keyboardCurrentOct != keyboardLastOct) { 
    if(!keyboardCompatabilityMode) { // This new mode doesnt work yet. :/
      keyboardCurrentOct = 0xB3 + keyboardCurrentOct; 
      addGameboyByte(keyboardCurrentOct);
    } else {
      ///We will find out which is greater, the current octave or the last. then
      //cycle up or down to that octave
      if(keyboardCurrentOct > keyboardLastOct) {
        keyboardDiff = keyboardCurrentOct - keyboardLastOct;
        for(keyboardCount=0;keyboardCount<keyboardDiff;keyboardCount++)
        {
           addGameboyByte(keyboardOctUp);
        }
      } else {
        keyboardDiff = keyboardLastOct - keyboardCurrentOct;
        for(keyboardCount=0;keyboardCount<keyboardDiff;keyboardCount++)
        {
          addGameboyByte(keyboardOctDn);
        }
      }
    }
    keyboardLastOct = keyboardCurrentOct;
  }
}

 /*
  Reguardless how porely optimized my code is the real bottleneck is either LSDJ, gameboy, or the serial line, 
  Therefor a crude "buffer" is setup to capture the bytes we want to send and slowly output them to lsdj...
  
  addGameboyByte put a byte into our output buffer
 */
 
void addGameboyByte(byte send_byte)
{
  serialWriteBuffer[writePosition] = send_byte; //assign new byte
  writePosition++;                              //increment the write position
  writePosition = writePosition % 256;          //make sure our write position is between 0 to 255 by using a mod of 256
}

 /*
  updateGameboyByteFrame is responcible responsibel resp.... job is to wait a period of time, 
  and then send a byte to the gameboy byte output function.
 */
void updateGameboyByteFrame()
{
  if(readPosition != writePosition){ //if we have something to read out
    waitClock++;                     //then increment our counter
    if(waitClock > 40) {             //if we've exceeded our wait time
      waitClock=0;                   //reset the counter
      statusLedOn();                 //turn on the awesome visuals
      sendByteToGameboy(serialWriteBuffer[readPosition]); //send the byte out
      readPosition++;                //increment our read position
      readPosition = readPosition % 256; //wrap our reading range from 0 to 255
    }
  }
}

 /*
  sendByteToGameboy does what it says. yay magic
 */
void sendByteToGameboy(byte send_byte) 
{
  for(countLSDJTicks=0;countLSDJTicks<8;countLSDJTicks++) {  //we are going to send 8 bits, so do a loop 8 times
    digitalWrite(pinGBClock,HIGH);  //Set our clock output to 1
    if(send_byte & 0x01) {          //if the first bit is equal to 1
      digitalWrite(pinGBSerialOut,HIGH); //then send a 1
    } else {
      digitalWrite(pinGBSerialOut,LOW);  //send a 0
    }
    send_byte >>= 1;                //bitshift right once for the next bit we are going to send
   delayMicroseconds(gameboyBitPauseLOW);        // firestARter : play around with this value, sometimes the gameboy needs more time between messages
    digitalWrite(pinGBClock,LOW);   //send a 0 to the clock, we finished sending the bit
   delayMicroseconds(gameboyBitPauseHIGH);        // firestARter : play around with this value, sometimes the gameboy needs more time between messages
  }
  digitalWrite(pinGBSerialOut,LOW); //make sure the serial state returns to 0 after its done sending the bits
  delayMicroseconds(gameboyBitPauseLOW);        // firestARter : play around with this value, sometimes the gameboy needs more time between messages
}

