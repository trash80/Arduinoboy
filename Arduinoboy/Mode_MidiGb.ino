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

void modeMidiGbSetup()
{
  digitalWrite(pinStatusLed,LOW);
  DDRC = B00111111; //Set analog in pins as outputs
  blinkMaxCount=1000;
  modeMidiGb();
}

void modeMidiGb()
{
  boolean sendByte = false;
  while(1){                                //Loop foreverrrr
    if (Serial.available()) {          //If MIDI is sending
      incomingMidiByte = Serial.read();    //Get the byte sent from MIDI
      
      if(!checkForProgrammerSysex(incomingMidiByte) && !usbMode) Serial.print(incomingMidiByte, BYTE); //Echo the Byte to MIDI Output
      
      if(incomingMidiByte & 0x80) {    
        switch (incomingMidiByte & 0xF0) {
          case 0xF0:
            midiValueMode = false;
            break;
          default:
            sendByte = false;
            midiStatusChannel = incomingMidiByte&0x0F;
            midiStatusType    = incomingMidiByte&0xF0;
            if(midiStatusChannel == memory[MEM_MGB_CH]) {
               incomingMidiData[0] = midiStatusType;
               sendByte = true;
            } else if (midiStatusChannel == memory[MEM_MGB_CH+1]) {
               incomingMidiData[0] = midiStatusType+1;
               sendByte = true;
            } else if (midiStatusChannel == memory[MEM_MGB_CH+2]) {
               incomingMidiData[0] = midiStatusType+2;
               sendByte = true;
            } else if (midiStatusChannel == memory[MEM_MGB_CH+3]) {
               incomingMidiData[0] = midiStatusType+3;
               sendByte = true;
            } else if (midiStatusChannel == memory[MEM_MGB_CH+4]) {
               incomingMidiData[0] = midiStatusType+4;
               sendByte = true;
            } else {
              midiValueMode  =false;
              midiAddressMode=false;
            }
            if(sendByte) {
              sendByteToGameboy(incomingMidiData[0]);
              midiValueMode  =false;
              midiAddressMode=true;
            }
           break;
        }
      } else if (midiAddressMode){
        midiAddressMode = false;
        midiValueMode = true;
        incomingMidiData[1] = incomingMidiByte;
        sendByteToGameboy(incomingMidiData[1]);
      } else if (midiValueMode) {
        incomingMidiData[2] = incomingMidiByte;
        midiAddressMode = true;
        midiValueMode = false;
        
        sendByteToGameboy(incomingMidiData[2]);
        blinkLight(incomingMidiData[0],incomingMidiData[2]);
      }
    } else {
      setMode();                // Check if mode button was depressed
      updateBlinkLights();
    }
  }
}

boolean checkGbSerialStopped()
{
  countClockPause++;                                 //Increment the counter
  if(countClockPause > 16000) {                      //if we've reached our waiting period
      countClockPause = 0;                           //reset our clock
      Serial.print(0xFC, BYTE);                      //send the transport stop message
    return true;
  }
  return false;
}

 /*
 sendByteToGameboy does what it says. yay magic
 */
void sendByteToGameboy(byte send_byte)
{
 for(countLSDJTicks=0;countLSDJTicks!=8;countLSDJTicks++) {  //we are going to send 8 bits, so do a loop 8 times
   if(send_byte & 0x80) {
       PORTC = B00000010;
       PORTC = B00000011;
   } else {
       PORTC = B00000000;
       PORTC = B00000001;
   }
   send_byte <<= 1;
 }
}
