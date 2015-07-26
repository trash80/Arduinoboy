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

void modeLSDJMasterSyncSetup()
{
  pinMode(pinGBClock,INPUT);
  modeLSDJMasterSync();
}
void modeLSDJMasterSync()
{
  while(1){
  setMode();
  readgbClockLine = digitalRead(pinGBClock); //Read gameboy's clock line
  if(readgbClockLine) {
    while(readgbClockLine) {
      countClockPause++;
      if(sequencerStarted && countClockPause > 16000) {
          Serial.print(0xFC, BYTE);
          countClockPause = 0;
          sequencerStop();
      }
      readgbClockLine = digitalRead(pinGBClock);
      setMode();
    }
    countClockPause = 0;
    countGbClockTicks++;
    if(countGbClockTicks == 8) {
      countGbClockTicks=0;
      if(!sequencerStarted) {
          Serial.print(0xFA, BYTE);
          sequencerStart();
      }
      Serial.print(0xF8, BYTE);
    }
  }
  if (Serial.available() > 0) {
    incomingMidiByte = Serial.read();
    Serial.print(incomingMidiByte, BYTE);
  }
  }
}
