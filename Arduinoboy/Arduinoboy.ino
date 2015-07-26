/**************************************************************************
 *         A     R     D     U     I     N     O     B     O     Y        *
 *                                                                        *
 * Version: 0.01A                                                         *
 * Date:    Feb 23 2008                                                   *
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
 
int syncOut = 12;    // gb output
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
  pinMode(midiEnable,OUTPUT); 
  
  Serial.begin(31250);	  //midi baudrate
  
  digitalWrite(midiEnable, HIGH); // turn on the optoisolator
  digitalWrite(syncOut, HIGH);    // gameboy wants a HIGH line
  
  blinkStatus(5,80);              // blink our status led 5 times
  digitalWrite(statusLed, HIGH);  // then turn it on
}

void loop () {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    switch (incomingByte) {
    case 248: // Clock Message Recieved
      if(seqStart == true) {
        for(sigCount=0;sigCount<8;sigCount++) {
          outputDelay(LOW);
          outputDelay(HIGH);
        }
      }
      break;
    case 250: // Transport Start Message
    case 251: // Transport Continue Message
     digitalWrite(clockLed, HIGH);
     digitalWrite(statusLed, LOW);
     seqStart = true;
     break;
    case 252: // Transport Stop Message
     digitalWrite(clockLed, LOW);
     digitalWrite(statusLed, HIGH);
     seqStart = false;
     break;
    }
  }
}

void outputDelay(byte CURRENT)
{
  digitalWrite(syncOut,CURRENT);
  // We want to pause our output for some time because the gameboy's slow. Its usual clock rate is 8khz
  delayMicroseconds(200);
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
