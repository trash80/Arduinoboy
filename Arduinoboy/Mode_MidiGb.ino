void modeMidiGbSetup()
{
  digitalWrite(pinStatusLed,LOW);
  pinMode(pinGBClock,OUTPUT);     //make sure our gameboy Clock is set for OUTPUT mode
  //digitalWrite(pinGBClock,LOW);   //Generally this should be HIGH ie: 1, on, whatever. but since we are emulating a pc keyboard it should be LOW/0/off
  modeMidiGb();
}

void modeMidiGb()
{
  while(1){                                //Loop foreverrrr

    if (Serial.available() > 0) {          //If MIDI is sending
      incomingMidiByte = Serial.read();    //Get the byte sent from MIDI
      //addFSGameboyByte(incomingMidiByte);
      //if(!usbMode) Serial.print(incomingMidiByte, BYTE); //Echo the Byte to MIDI Output
      if(incomingMidiByte > 0x7F) {    
        switch (incomingMidiByte & 0xF0) {
          case 0xF0:
            midiValueMode = false;
            break;
          default:
            incomingMidiData[0] = incomingMidiByte;
            midiValueMode = false;
            midiAddressMode = true;
            break;
        }
      } else if (midiAddressMode){
        midiAddressMode = false;
        midiValueMode = true;
        incomingMidiData[1] = incomingMidiByte;
      } else if (midiValueMode) {
        incomingMidiData[2] = incomingMidiByte;
        midiAddressMode = true;
        midiValueMode = false;
        
        if(lastMidiData[0] != incomingMidiData[0] || 
           lastMidiData[1] != incomingMidiData[1] || 
           lastMidiData[2] != incomingMidiData[2]) {
           if(lastMidiData[0] != incomingMidiData[0]) {
             addFSGameboyByte(incomingMidiData[0]);  
           }
           
           addFSGameboyByte(incomingMidiData[1]);
           addFSGameboyByte(incomingMidiData[2]);
           
           lastMidiData[0] = incomingMidiData[0];
           lastMidiData[1] = incomingMidiData[1];
           lastMidiData[2] = incomingMidiData[2];
        }
      }
    }
    updateFSGameboyByteFrame(); // Send out Bytes to LSDJ
    setMode();                // Check if mode button was depressed
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

void addFSGameboyByte(byte send_byte)
{
  serialWriteBuffer[writePosition] = send_byte; //assign new byte
  writePosition++;                              //increment the write position
  writePosition = writePosition % 256;          //make sure our write position is between 0 to 255 by using a mod of 256
}

 /*
  updateGameboyByteFrame is responcible responsibel resp.... job is to wait a period of time, 
  and then send a byte to the gameboy byte output function.
 */
void updateFSGameboyByteFrame()
{
  if(readPosition != writePosition){ //if we have something to read out
    waitClock++;                     //then increment our counter
    if(waitClock > gameboyBytePause) {             //if we've exceeded our wait time
      waitClock=0;                   //reset the counter
      //statusLedOn();                 //turn on the awesome visuals
      sendFSByteToGameboy(serialWriteBuffer[readPosition]); //send the byte out
      readPosition++;                //increment our read position
      readPosition = readPosition % 256; //wrap our reading range from 0 to 255
    }
  }
}
 /*
 sendByteToGameboy does what it says. yay magic
 */
void sendFSByteToGameboy(byte send_byte)       //changed by firestARTer: send routine changed MST is send out first!!!!!!!
{
 for(countLSDJTicks=0;countLSDJTicks<8;countLSDJTicks++) {  //we are going to send 8 bits, so do a loop 8 times
//    digitalWrite(pinGBClock,HIGH);  //Set our clock output to 1
   if(send_byte & 0x80) {          //if the first bit is equal to 1
     digitalWrite(pinGBSerialOut,HIGH); //then send a 1
   } else {
     digitalWrite(pinGBSerialOut,LOW);  //send a 0
   }
   send_byte <<= 1;                //bitshift right once for the next bit we are going to send
   digitalWrite(pinGBClock,LOW);   //send a 0 to the clock, we finished sending the bit

   delayMicroseconds(gameboyBitPause);        // firestARter : play around with this value, sometimes the gameboy needs more time between messages
   digitalWrite(pinGBClock,HIGH);   //send a 0 to the clock, we finished sending the bit

 }
 digitalWrite(pinGBSerialOut,LOW); //make sure the serial state returns to 0 after its done sending the bits
 delayMicroseconds(gameboyBitPause);        // firestARter : play around with this value, sometimes the gameboy needs more time between messages
 
}
