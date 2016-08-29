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

#include "NanoloopSlave.h"

void NanoloopSlaveClass::begin()
{
    gameboy->setOutputMode();
    sequencerStarted = false;
}

void NanoloopSlaveClass::update()
{

}

void NanoloopSlaveClass::onTransportClock()
{
    if(sequencerStarted) {
        if(syncSwitch) {
            gameboy->sendBit(1);
            gameboy->sendBit(1);
        } else {
            gameboy->sendBit(1);
            gameboy->sendBit(0);
        }
        syncSwitch = !syncSwitch;
    }
}

void NanoloopSlaveClass::onTransportStart()
{
    sequencerStarted = true;
    syncSwitch = false;
}

void NanoloopSlaveClass::onTransportContinue()
{
    sequencerStarted = true;
    syncSwitch = false;
}

void NanoloopSlaveClass::onTransportStop()
{
    sequencerStarted = false;
}
