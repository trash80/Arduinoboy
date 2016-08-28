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

 #include "ArduinoboyController.h"

void ArduinoboyControllerClass::begin()
{
    setMode(0);
}

void ArduinoboyControllerClass::update()
{
    int i = currentModule->numberHandlers;
    while(i--) {
        currentModule->module[i]->update();
    }
    interface->update();
}

void ArduinoboyControllerClass::attachMode(uint8_t moduleNumber, ArduinoboyModuleClass * module)
{
    modules[moduleNumber].module[modules[moduleNumber].numberHandlers] = module;
    modules[moduleNumber].numberHandlers++;
}

void ArduinoboyControllerClass::setMode(uint8_t moduleNumber) {
    currentModule = &modules[moduleNumber];
    int i = currentModule->numberHandlers;
    while(i--) currentModule->module[i]->begin();
}

void ArduinoboyControllerClass::onCommand()
{
    int i = currentModule->numberHandlers;
    while(i--) currentModule->module[i]->onCommand();
}

void ArduinoboyControllerClass::onData1()
{
    int i = currentModule->numberHandlers;
    while(i--) currentModule->module[i]->onData1();
}

void ArduinoboyControllerClass::onNoteOn()
{
    int i = currentModule->numberHandlers;
    while(i--) currentModule->module[i]->onNoteOn();
}

void ArduinoboyControllerClass::onNoteOff()
{
    int i = currentModule->numberHandlers;
    while(i--) currentModule->module[i]->onNoteOff();
}

void ArduinoboyControllerClass::onPolyPressure()
{
    int i = currentModule->numberHandlers;
    while(i--) currentModule->module[i]->onPolyPressure();
}

void ArduinoboyControllerClass::onControlChange()
{
    int i = currentModule->numberHandlers;
    while(i--) currentModule->module[i]->onControlChange();
}

void ArduinoboyControllerClass::onProgramChange()
{
    int i = currentModule->numberHandlers;
    while(i--) currentModule->module[i]->onProgramChange();
}

void ArduinoboyControllerClass::onAfterTouch()
{
    int i = currentModule->numberHandlers;
    while(i--) currentModule->module[i]->onAfterTouch();
}

void ArduinoboyControllerClass::onPitchBend()
{
    int i = currentModule->numberHandlers;
    while(i--) currentModule->module[i]->onPitchBend();
}

void ArduinoboyControllerClass::onTransportClock()
{
    int i = currentModule->numberHandlers;
    while(i--) currentModule->module[i]->onTransportClock();
}

void ArduinoboyControllerClass::onTransportStart()
{
    int i = currentModule->numberHandlers;
    while(i--) currentModule->module[i]->onTransportStart();
}

void ArduinoboyControllerClass::onTransportContinue()
{
    int i = currentModule->numberHandlers;
    while(i--) currentModule->module[i]->onTransportContinue();
}

void ArduinoboyControllerClass::onTransportStop()
{
    int i = currentModule->numberHandlers;
    while(i--) currentModule->module[i]->onTransportStop();
}
