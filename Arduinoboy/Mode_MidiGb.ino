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
  digitalWrite(pinMidiInputPower,HIGH); // turn on the optoisolator
  digitalWrite(pinStatusLed,LOW);
  DDRC = B00111111; //Set analog in pins as outputs
  
  modeMidiGb();
}

void modeMidiGb()
{
  while(1){                                //Loop foreverrrr
    if (Serial.available() > 0) {          //If MIDI is sending
      incomingMidiByte = Serial.read();    //Get the byte sent from MIDI
      sendByteToGameboy(incomingMidiByte);
      if(!usbMode) Serial.print(incomingMidiByte, BYTE); //Echo the Byte to MIDI Output
      if(incomingMidiByte > 0x7F) {    
        switch (incomingMidiByte & 0xF0) {
          case 0xF0:
            midiValueMode = false;
            break;
          default:
            incomingMidiData[0] = incomingMidiByte;
            midiValueMode  =false;
            midiAddressMode=true;
           break;
        }
      } else if (midiAddressMode){
        midiAddressMode = false;
        midiValueMode = true;
        incomingMidiData[1] = incomingMidiByte;
        if((incomingMidiData[0] >> 0x04) == 0x0C) {
          midiAddressMode = false;
        }
      } else if (midiValueMode) {
        incomingMidiData[2] = incomingMidiByte;
        midiAddressMode = true;
        midiValueMode = false;
        blinkLight(incomingMidiData[0],incomingMidiData[2]);
      }
      
    } else {
      setMode();                // Check if mode button was depressed
      updateBlinkLights();
    }
  }
}

void updateBlinkLights()
{
  updateBlinkLight(0);
  updateBlinkLight(1);
  updateBlinkLight(2);
  updateBlinkLight(3);
  updateStatusLight();
}

void updateBlinkLight(int light)
{
  if(blinkSwitch[light]) {
    blinkSwitchTime[light]++;
    if(blinkSwitchTime[light] > 2000) {
      blinkSwitch[light]=0;
      blinkSwitchTime[light]=0;
      digitalWrite(pinLeds[light],LOW);
    }
  }
}

void updateStatusLight()
{
  if(blinkSwitch[4]) {
    blinkSwitchTime[4]++;
    if(blinkSwitchTime[4] > 2000) {
      blinkSwitch[4]=0;
      blinkSwitchTime[4]=0;
      digitalWrite(pinStatusLed,LOW);
    }
  }
}

void blinkLight(byte midiMessage, byte midiValue)
{
  if(midiValue) {
  switch(midiMessage) {
    case 0x90:
      if(!blinkSwitch[0]) digitalWrite(pinLeds[0],HIGH);
      blinkSwitch[0]=1;
      blinkSwitchTime[0]=0;
      break;
    case 0x91:
      if(!blinkSwitch[1]) digitalWrite(pinLeds[1],HIGH);
      blinkSwitch[1]=1;
      blinkSwitchTime[1]=0;
      break;
    case 0x92:
      if(!blinkSwitch[2]) digitalWrite(pinLeds[2],HIGH);
      blinkSwitch[2]=1;
      blinkSwitchTime[2]=0;
      break;
    case 0x93:
      if(!blinkSwitch[3]) digitalWrite(pinLeds[3],HIGH);
      blinkSwitch[3]=1;
      blinkSwitchTime[3]=0;
      break;
    case 0x94:
      if(!blinkSwitch[0])  digitalWrite(pinLeds[0],HIGH);
      blinkSwitch[0]=1;
      blinkSwitchTime[0]=0;
      if(!blinkSwitch[1]) digitalWrite(pinLeds[1],HIGH);
      blinkSwitch[1]=1;
      blinkSwitchTime[1]=0;
      if(!blinkSwitch[2]) digitalWrite(pinLeds[2],HIGH);
      blinkSwitch[2]=1;
      blinkSwitchTime[2]=0;
      break;
  }
  }
  switch(midiMessage) {
    case 0xE0:
    case 0xE1:
    case 0xE2:
    case 0xE3:
    case 0xE4:
    case 0xB0:
    case 0xB1:
    case 0xB2:
    case 0xB3:
    case 0xB4:
      if(!blinkSwitch[4]) digitalWrite(pinStatusLed,HIGH);
      blinkSwitch[4]=1;
      blinkSwitchTime[4]=0;
      break;
    default:
      break;
  }
}

void updateVisualSync()
{
    if(!countSyncTime) {
      if(!blinkSwitch[4]) digitalWrite(pinStatusLed,HIGH);
      digitalWrite(pinLeds[0],LOW);
      digitalWrite(pinLeds[1],LOW);
      digitalWrite(pinLeds[2],LOW);
      digitalWrite(pinLeds[3],LOW);
      digitalWrite(pinLeds[switchLight],HIGH);
      blinkSwitch[4]=1;
      blinkSwitchTime[4]=0;
      countSyncLightTime = 0;
      switchLight++;
      if(switchLight==4) switchLight=0;
    }
    countSyncTime++;
    if(countSyncTime == 24) countSyncTime=0; 
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
