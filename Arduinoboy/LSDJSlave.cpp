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

 #include "LSDJSlave.h"

void LSDJSlaveClass::begin()
{
    gameboy->setOutputMode();
    sequencerStarted = false;
}

void LSDJSlaveClass::update()
{

}

void LSDJSlaveClass::onTransportClock()
{
    if(sequencerStarted) {
        gameboy->sendByte(0x00);
    }
}

void LSDJSlaveClass::onTransportStart()
{
    sequencerStarted = true;
}

void LSDJSlaveClass::onTransportContinue()
{
    sequencerStarted = true;
}

void LSDJSlaveClass::onTransportStop()
{
    sequencerStarted = false;
}
