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

 #include "ModeController.h"

void ModeControllerClass::begin()
{
    setMode(0);
}

void ModeControllerClass::update()
{
    int i = currentMode->numberHandlers;
    while(i--) {
        currentMode->mode[i]->update();
    }
    interface->update();
}

void ModeControllerClass::attachMode(uint8_t modeNumber, ModeClass * mode)
{
    modes[modeNumber].mode[modes[modeNumber].numberHandlers] = mode;
    modes[modeNumber].numberHandlers++;
}

void ModeControllerClass::setMode(uint8_t modeNumber) {
    currentMode = &modes[modeNumber];
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->begin();
}

void ModeControllerClass::onCommand()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onCommand();
}

void ModeControllerClass::onData1()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onData1();
}

void ModeControllerClass::onNoteOn()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onNoteOn();
}

void ModeControllerClass::onNoteOff()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onNoteOff();
}

void ModeControllerClass::onPolyPressure()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onPolyPressure();
}

void ModeControllerClass::onControlChange()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onControlChange();
}

void ModeControllerClass::onProgramChange()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onProgramChange();
}

void ModeControllerClass::onAfterTouch()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onAfterTouch();
}

void ModeControllerClass::onPitchBend()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onPitchBend();
}

void ModeControllerClass::onTransportClock()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onTransportClock();
}

void ModeControllerClass::onTransportStart()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onTransportStart();
}

void ModeControllerClass::onTransportContinue()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onTransportContinue();
}

void ModeControllerClass::onTransportStop()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onTransportStop();
}
