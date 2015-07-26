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
 
void setMode()
{
  if(digitalRead(pinButtonMode)) {
    mode++;
    if(mode >= 5) mode = 0;
    if(!forceMode) EEPROM.write(eepromMemoryByte, mode);
    showSelectedMode();
    switchMode();
  }
}

void showSelectedMode()
{
  for(int led=0;led<=5;led++) digitalWrite(pinLeds[led],LOW);
  digitalWrite(pinLeds[mode],HIGH);
  delay(300);
}

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
      modePushpinSetup();
      break;
  }
}

void sequencerStart()
{
  sequencerStarted = true;
  countSyncPulse = 0;
  countSyncTime = 0;
}

void sequencerStop()
{
  midiSyncEffectsTime = false;
  sequencerStarted = false;
  countSyncPulse = 0;
  countSyncTime = 0;
}

void updateStatusLed()
{
  if(statusLedIsOn) {
    countStatusLedOn++;
    if(countStatusLedOn > 3000) {
      countStatusLedOn = 0;
       digitalWrite(pinStatusLed,LOW);
       statusLedIsOn  = false;
    } else if (statusLedBlink && countStatusLedOn == 1) {
       digitalWrite(pinStatusLed,LOW);
    } else if (statusLedBlink && countStatusLedOn > 1000) {
       statusLedBlink = false;
       digitalWrite(pinStatusLed,HIGH);
    }
  }
}

void statusLedOn()
{
  if(statusLedIsOn) {
    statusLedBlink = true;
  }
  statusLedIsOn  = true;
  countStatusLedOn = 0;
  digitalWrite(pinStatusLed,HIGH);
}
