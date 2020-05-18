
 /*
   showSelectedMode1 turns off the last mode led, turns on the new mode led
   and delays for a period of time to reduce jitter behavior from the mode
   changing too fast.
 */
void showSelectedMode()
{
  digitalWrite(pinStatusLed,LOW);

  for(int m=0;m<3;m++) {
    switch(memory[MEM_MODE]) {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
        digitalWrite(pinLeds[memory[MEM_MODE]],HIGH);
        break;
      case 5:
        digitalWrite(pinStatusLed,HIGH);
        digitalWrite(pinLeds[0],HIGH);
        digitalWrite(pinLeds[1],HIGH);
        break;
      case 6:
        digitalWrite(pinLeds[0],HIGH);
        digitalWrite(pinLeds[1],HIGH);
        digitalWrite(pinLeds[2],HIGH);
        digitalWrite(pinLeds[3],HIGH);
        digitalWrite(pinLeds[4],HIGH);
        digitalWrite(pinLeds[5],HIGH);
        break;

    }
  delay(100);
  digitalWrite(pinLeds[0],LOW);
  digitalWrite(pinLeds[1],LOW);
  digitalWrite(pinLeds[2],LOW);
  digitalWrite(pinLeds[3],LOW);
  digitalWrite(pinLeds[4],LOW);
  digitalWrite(pinLeds[5],LOW);
  delay(100);
  }
  lastMode = memory[MEM_MODE];
  delay(300);
}

void updateVisualSync()
{
    if(!countSyncTime) {
      if(!blinkSwitch[5]) digitalWrite(pinStatusLed,HIGH);
      digitalWrite(pinLeds[0],LOW);
      digitalWrite(pinLeds[1],LOW);
      digitalWrite(pinLeds[2],LOW);
      digitalWrite(pinLeds[3],LOW);
      digitalWrite(pinLeds[switchLight],HIGH);
      blinkSwitch[5]=1;
      blinkSwitchTime[5]=0;
      countSyncLightTime = 0;
      switchLight++;
      if(switchLight==4) switchLight=0;
    }
    countSyncTime++;
    if(countSyncTime == 24) countSyncTime=0;
}



void updateBlinkLights()
{
  updateBlinkLight(0);
  updateBlinkLight(1);
  updateBlinkLight(2);
  updateBlinkLight(3);
  updateBlinkLight(4);
  updateBlinkLight(5);
}

void updateBlinkLight(uint8_t light)
{
  if(blinkSwitch[light]) {
    blinkSwitchTime[light]++;
    if(blinkSwitchTime[light] == blinkMaxCount) {
      blinkSwitch[light]=0;
      blinkSwitchTime[light]=0;
      digitalWrite(pinLeds[light],LOW);
    }
  }
}

void updateStatusLight()
{
  if(blinkSwitch[5]) {
    blinkSwitchTime[5]++;
    if(blinkSwitchTime[5] == blinkMaxCount) {
      blinkSwitch[5]=0;
      blinkSwitchTime[5]=0;
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
    case 0x95:
      if(!blinkSwitch[0]) digitalWrite(pinLeds[0],HIGH);
      blinkSwitch[0]=1;
      blinkSwitchTime[0]=0;
      break;
    case 0x9A:
      if(!blinkSwitch[0]) digitalWrite(pinLeds[0],HIGH);
      blinkSwitch[0]=1;
      blinkSwitchTime[0]=0;
      break;
    case 0x91:
      if(!blinkSwitch[1]) digitalWrite(pinLeds[1],HIGH);
      blinkSwitch[1]=1;
      blinkSwitchTime[1]=0;
      break;
    case 0x96:
      if(!blinkSwitch[1]) digitalWrite(pinLeds[1],HIGH);
      blinkSwitch[1]=1;
      blinkSwitchTime[1]=0;
      break;
    case 0x9B:
      if(!blinkSwitch[1]) digitalWrite(pinLeds[1],HIGH);
      blinkSwitch[1]=1;
      blinkSwitchTime[1]=0;
      break;
    case 0x92:
      if(!blinkSwitch[2]) digitalWrite(pinLeds[2],HIGH);
      blinkSwitch[2]=1;
      blinkSwitchTime[2]=0;
      break;
    case 0x97:
      if(!blinkSwitch[2]) digitalWrite(pinLeds[2],HIGH);
      blinkSwitch[2]=1;
      blinkSwitchTime[2]=0;
      break;
    case 0x9C:
      if(!blinkSwitch[2]) digitalWrite(pinLeds[2],HIGH);
      blinkSwitch[2]=1;
      blinkSwitchTime[2]=0;
      break;
    case 0x93:
      if(!blinkSwitch[3]) digitalWrite(pinLeds[3],HIGH);
      blinkSwitch[3]=1;
      blinkSwitchTime[3]=0;
      break;
    case 0x98:
      if(!blinkSwitch[3]) digitalWrite(pinLeds[3],HIGH);
      blinkSwitch[3]=1;
      blinkSwitchTime[3]=0;
      break;
    case 0x9D:
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
    case 0x99:
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
    case 0x9E:
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
      if(!blinkSwitch[5]) digitalWrite(pinStatusLed,HIGH);
      blinkSwitch[5]=1;
      blinkSwitchTime[5]=0;
      break;
    default:
      break;
  }
}

void updateProgrammerLeds()
{
  if(miscLedTime == miscLedMaxTime) {
    if(sysexProgrammingConnected) {
      miscLedMaxTime = 400;
      blinkSelectedLight(miscLastLed);
      miscLastLed++;
      if(miscLastLed == 5) miscLastLed = 0;
    } else {
      blinkSelectedLight(5);
      miscLedMaxTime = 3000;
    }
    miscLedTime=0;
  }
  miscLedTime++;
  updateBlinkLights();
}
 /*
   updateStatusLed should be placed inside of the main loop cycle of a mode function. It counts to a
   certain number to delay the action of turning off the status led, so the blink is visible to the human eye. ;)>
   I guess this could be called the blinking routine.
 */
void updateStatusLed()
{
  if(statusLedIsOn) {                  //is the led on?
    countStatusLedOn++;                //then increment the counter by 1
    if(countStatusLedOn > 3000) {      //if the counter is pretty high
      countStatusLedOn = 0;            //then reset it to zero.
       digitalWrite(pinStatusLed,LOW); //and turn off the status led
       statusLedIsOn  = false;         //and set our "is it on?" to false, cause its off now. ;p

    } else if (statusLedBlink && countStatusLedOn == 1) {  //someone told me to blink, because i was already on
       digitalWrite(pinStatusLed,LOW);                     //so I'll turn off and turn back on later..

    } else if (statusLedBlink && countStatusLedOn > 1000) {//Now that I've waited long enough I'll finish my blink.
       statusLedBlink = false;                             //Turn off the issued blink
       digitalWrite(pinStatusLed,HIGH);                    //... and finally turn back on.
    }
  }
}

 /*
   statusLedOn is the function to call when we want the status led to blink for us.
   all it does is check if its been already asked to turn on, if it has it will set a flag
   to make it blink. Either way it will reset the blink timer and turn on the LED
 */
void statusLedOn()
{
  if(statusLedIsOn) {
    statusLedBlink = true;   //Make it blink even though its already on
  }
  statusLedIsOn  = true;     //This is the flag the updator function looks for to know if its ok to increment the timer and wait to turn off the led
  countStatusLedOn = 0;      //Reset the timer
  digitalWrite(pinStatusLed,HIGH); //Turn on the led
}

/* cute startup sequence */
void startupSequence()
{
  int ledFxA;
  int ledFxB;

  for(ledFxB=0;ledFxB<2;ledFxB++) {
  for(ledFxA=0;ledFxA<6;ledFxA++) {
    digitalWrite(pinLeds[ledFxA], HIGH);
    delay(25);
    digitalWrite(pinLeds[ledFxA], LOW);
  }
  for(ledFxA=4;ledFxA>=0;ledFxA--) {
    digitalWrite(pinLeds[ledFxA], HIGH);
    delay(25);
    digitalWrite(pinLeds[ledFxA], LOW);
  }
  }
  delay(50);

  for(ledFxA=0;ledFxA<6;ledFxA++) digitalWrite(pinLeds[ledFxA], HIGH);   // sets the LED on
  delay(100);
  for(ledFxA=0;ledFxA<6;ledFxA++) digitalWrite(pinLeds[ledFxA], LOW);      // sets the digital pin as output
  delay(100);
  for(ledFxA=0;ledFxA<6;ledFxA++) digitalWrite(pinLeds[ledFxA], HIGH);   // sets the LED on
  delay(100);
  for(ledFxA=0;ledFxA<6;ledFxA++) digitalWrite(pinLeds[ledFxA], LOW);      // sets the digital pin as output
  delay(500);

}
