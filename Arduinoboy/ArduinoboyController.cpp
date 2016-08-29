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
    int i = currentMode->numberHandlers;
    while(i--) {
        currentUpdateId = i;
        currentMode->module[i]->update();
    }
}

void ArduinoboyControllerClass::attachMode(uint8_t moduleNumber, ArduinoboyModuleClass * module)
{
    modes[moduleNumber].module[modes[moduleNumber].numberHandlers] = module;
    modes[moduleNumber].numberHandlers++;
}

void ArduinoboyControllerClass::setMode(uint8_t moduleNumber) {
    currentMode = &modes[moduleNumber];
    int i = currentMode->numberHandlers;
    while(i--) {
        currentMode->module[i]->setCallback(this);
        currentMode->module[i]->begin();
    }
}

void ArduinoboyControllerClass::onCommand(MidiCallbackClass * midi)
{
    int i = currentMode->numberHandlers;
    while(i--) if(i != currentUpdateId) currentMode->module[i]->onData1(midi);
}

void ArduinoboyControllerClass::onData1(MidiCallbackClass * midi)
{
    int i = currentMode->numberHandlers;
    while(i--) if(i != currentUpdateId) currentMode->module[i]->onData1(midi);
}

void ArduinoboyControllerClass::onNoteOn(MidiCallbackClass * midi)
{
    int i = currentMode->numberHandlers;
    while(i--) if(i != currentUpdateId) currentMode->module[i]->onNoteOn(midi);
}

void ArduinoboyControllerClass::onNoteOff(MidiCallbackClass * midi)
{
    int i = currentMode->numberHandlers;
    while(i--) if(i != currentUpdateId) currentMode->module[i]->onNoteOff(midi);
}

void ArduinoboyControllerClass::onPolyPressure(MidiCallbackClass * midi)
{
    int i = currentMode->numberHandlers;
    while(i--) if(i != currentUpdateId) currentMode->module[i]->onPolyPressure(midi);
}

void ArduinoboyControllerClass::onControlChange(MidiCallbackClass * midi)
{
    int i = currentMode->numberHandlers;
    while(i--) if(i != currentUpdateId) currentMode->module[i]->onControlChange(midi);
}

void ArduinoboyControllerClass::onProgramChange(MidiCallbackClass * midi)
{
    int i = currentMode->numberHandlers;
    while(i--) if(i != currentUpdateId) currentMode->module[i]->onProgramChange(midi);
}

void ArduinoboyControllerClass::onAfterTouch(MidiCallbackClass * midi)
{
    int i = currentMode->numberHandlers;
    while(i--) if(i != currentUpdateId) currentMode->module[i]->onAfterTouch(midi);
}

void ArduinoboyControllerClass::onPitchBend(MidiCallbackClass * midi)
{
    int i = currentMode->numberHandlers;
    while(i--) if(i != currentUpdateId) currentMode->module[i]->onPitchBend(midi);
}

void ArduinoboyControllerClass::onTransportClock()
{
    int i = currentMode->numberHandlers;
    while(i--) if(i != currentUpdateId) currentMode->module[i]->onTransportClock();
}

void ArduinoboyControllerClass::onTransportStart()
{
    int i = currentMode->numberHandlers;
    while(i--) if(i != currentUpdateId) currentMode->module[i]->onTransportStart();
}

void ArduinoboyControllerClass::onTransportContinue()
{
    int i = currentMode->numberHandlers;
    while(i--) if(i != currentUpdateId) currentMode->module[i]->onTransportContinue();
}

void ArduinoboyControllerClass::onTransportStop()
{
    int i = currentMode->numberHandlers;
    while(i--) if(i != currentUpdateId) currentMode->module[i]->onTransportStop();
}
