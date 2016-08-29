/*
 * Arduinoboy
 * http://trash80.com
 * Copyright (c) 2016 Timothy Lamb
 *
 * This file is part of Arduinoboy.
 *
 * Arduinoboy is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Arduinoboy is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

 #include "LSDJMaster.h"

void LSDJMasterClass::begin()
{
    gameboy->setInputMode();
    sequencerStarted = false;
}

void LSDJMasterClass::update()
{

    if(sequencerStarted && !gameboy->readClock()) {
        callback->sendTransportClock();
        wait = millis() + 100;
        delay(1);
    } else if (sequencerStarted && gameboy->readClock() && wait < millis()) {
        callback->sendTransportStop();
        sequencerStarted = false;
    } else if (!sequencerStarted) {
        int data = gameboy->receiveByte();

        if (data >= 0) {
            callback->sendTransportClock();
            callback->sendTransportStart();
            sequencerStarted = true;
            wait = millis() + 100;
        }
    }
}
