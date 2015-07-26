/**************************************************************************
 *         A     R     D     U     I     N     O     B     O     Y        *
 *                                                                        *
 * Version: 0.2.1                                                         *
 * Date:    Feb 24 2008                                                   *
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
 
int syncOut = 12;    // clock out to gameboy
int dataOut = 11;    // serial data to gameboy
int midiEnable = 10; // power opticouplah

int statusLed = 8; // power light
int clockLed = 9;  // start light

int sigCount = 0;   //for loop int (we need to cycle 8 pulses)

boolean seqStart = false;    //Sequencer Started
byte incomingByte;  //incomming midi message

void setup() {
  // Setup our ports as outputs
  pinMode(statusLed,OUTPUT); 
  pinMode(clockLed,OUTPUT); 
  pinMode(syncOut,OUTPUT); 
  pinMode(dataOut,OUTPUT); 
  pinMode(midiEnable,OUTPUT); 
  
  Serial.begin(31250);	  //midi baudrate
  
  digitalWrite(midiEnable, HIGH); // turn on the optoisolator
  digitalWrite(syncOut, HIGH);    // gameboy wants a HIGH line
  digitalWrite(dataOut, LOW);    // no data to send
  
  blinkStatus(5,80);              // blink our status led 5 times
  digitalWrite(statusLed, HIGH);  // then turn it on
}

void loop () {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    switch (incomingByte) {
    case 248: // Clock Message Recieved
      //send a clock tick out if the sequencer is runn
      if(seqStart == true) {
        sendClockTick();
      }
      break;
    case 250: // Transport Start Message
    case 251: // Transport Continue Message
      sequencerStart();
      break;
    case 252: // Transport Stop Message
      sequencerStop();
      break;
    }
  }
}

void sequencerStart()
{
  digitalWrite(clockLed, HIGH);
  digitalWrite(statusLed, LOW);
  seqStart = true;
}

void sequencerStop()
{
  digitalWrite(clockLed, LOW);
  digitalWrite(statusLed, HIGH);
  seqStart = false;
}

void sendClockTick()
{
  for(sigCount=0;sigCount<8;sigCount++) {
    digitalWrite(syncOut,LOW);digitalWrite(syncOut,HIGH);
  }
}

void blinkStatus(int times, int period)
{
  for(int count=0; count < times; count++) {
      digitalWrite(statusLed,HIGH);
      delay(period);
      digitalWrite(statusLed,LOW);
      delay(period);
  }
}
