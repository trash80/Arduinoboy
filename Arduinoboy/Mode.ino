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
 
/* ***************************************************************************/
/* "Mode" Functions. Deals with changing the setup of arduino.              */
/* ***************************************************************************/

 /*
   setMode will check if the push button is depressed, If it is it will 
   increment the mode number and make sure its in the 
   range 0 to 4 by mod (%). It will then write the mode to memory,
   set the leds to display the mode, and switch the code over to the
   right function.
 */
void setMode()
{
  if(!forceMode && digitalRead(pinButtonMode)) { //if the button is pressed
    mode++;                           //increment the mode number
    if(mode > (numberOfModes - 1)) mode=0;  //if the mode is greater then 4 it will wrap back to 0
    if(!forceMode) EEPROM.write(eepromMemoryByte, mode); //write mode to eeprom if we arnt forcing a mode in the config
    showSelectedMode();            //set the LEDS
    switchMode();                  //switch to the new mode
  }
}

 /*
   showSelectedMode1 turns off the last mode led, turns on the new mode led
   and delays for a period of time to reduce jitter behavior from the mode 
   changing too fast.
 */
void showSelectedMode()
{
  digitalWrite(pinLeds[0],LOW);
  digitalWrite(pinLeds[1],LOW);
  digitalWrite(pinLeds[2],LOW);
  digitalWrite(pinLeds[3],LOW);
  digitalWrite(pinLeds[4],LOW);
  digitalWrite(pinLeds[mode],HIGH);
  lastMode = mode;
  delay(300);
}

 /*
   switchMode is only called from setMode. its responsible for
   linking the mode number to its corrisponding function, 
   and then calling that function. function. function.
 */
void switchMode()
{
  switch(mode)
  {
    case 0:
      modeLSDJSlaveSyncSetup();
      break;
    case 1:
      modeLSDJMasterSyncSetup();
      break;
    case 2:
      modeLSDJKeyboardSetup();
      break;
    case 3:
      modeNanoloopSetup();
      break;
    case 4:
      modeMidiGbSetup();
      break;
  }
}


/* ***************************************************************************/
/* General Global Functions Used in more then one of the modes               */
/* ***************************************************************************/

 /*
   sequencerStart is called when either LSDJ has started to play in master mode, 
   or when a MIDI Start or continue command is received in lsdj slave mode.
   Basically it just resets some counters we use and sets a "start" flag.
 */
 
void sequencerStart()
{
  sequencerStarted = true; //Sequencer has started?
  countSyncPulse = 0;      //Used for status LED, counts 24 ticks (quarter notes)
  countSyncTime = 0;       //Used to count a custom amount of clock ticks (2/4/8) for sync effects
  countSyncLightTime=0;
  switchLight=0;
}

 /*
   sequencerStop is called when either LSDJ has stopped sending sync commands for
   some time in LSDJ Master mode, or when a MIDI Stop command is received in
   lsdj slave mode.
   Basically it just resets some counters we use and sets the "start" flag to false.
 */
void sequencerStop()
{
  midiSyncEffectsTime = false;//Turn off MIDI sync effects in LSDJ slave mode
  sequencerStarted = false;   //Sequencer has started?
  countSyncPulse = 0;         //Used for status LED, counts 24 ticks (quarter notes)
  countSyncTime = 0;          //Used to count a custom amount of clock ticks (2/4/8) for sync effects
  countSyncLightTime=0;
  switchLight=0;
  digitalWrite(pinLeds[0],LOW);
  digitalWrite(pinLeds[1],LOW);
  digitalWrite(pinLeds[2],LOW);
  digitalWrite(pinLeds[3],LOW);
  digitalWrite(pinLeds[mode],HIGH);
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
