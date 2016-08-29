#include <Arduino.h>
#line 1 "/Users/trash80/Programming/Projects/Trash80/Arduinoboy/Arduinoboy/Arduinoboy.ino"
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
#include "GameboySerial.h"
#include "MidiDeviceSerial.h"
#include "MidiDeviceUsb.h"

#include "LedInterface.h"

#include "LSDJSlave.h"
#include "LSDJMaster.h"
#include "LSDJMap.h"
#include "NanoloopSlave.h"
#include "LSDJKeyboard.h"
#include "LSDJMidiout.h"
#include "MidiGameboy.h"


const uint8_t ledPins[2] = {13,13};
const uint8_t numLeds = 2;

LedInterface Interface(ledPins, numLeds);

GameboySerial Gameboy(16,17,18);

ArduinoboyController Controller;

MidiDeviceSerial Midi(&Serial1);
MidiDeviceUsb MidiUsb;

ModeLSDJMap LSDJMap;
ModeLSDJSlave LSDJSlave;
ModeLSDJMaster LSDJMaster;
ModeNanoloopSlave NanoloopSlave;
ModeLSDJKeyboard LSDJKeyboard;
ModeLSDJMidiout LSDJMidiout;
ModeMidiGameboy MidiGameboy;

void setup();

void loop();
#line 59 "/Users/trash80/Programming/Projects/Trash80/Arduinoboy/Arduinoboy/Arduinoboy.ino"
void setup()
{
    LSDJKeyboard.setGameboy(&Gameboy);
    LSDJMaster.setGameboy(&Gameboy);
    LSDJSlave.setGameboy(&Gameboy);
    LSDJMap.setGameboy(&Gameboy);
    NanoloopSlave.setGameboy(&Gameboy);
    LSDJMidiout.setGameboy(&Gameboy);
    MidiGameboy.setGameboy(&Gameboy);

    LSDJKeyboard.setChannels(1);
    LSDJMap.setChannels(1,2);
    MidiGameboy.setChannels(1,2,3,4,5);
    LSDJMidiout.setChannels(1,2,3,4);

    Controller.attachMode(0, &Midi);
    Controller.attachMode(0, &MidiUsb);
    Controller.attachMode(0, &LSDJMap);
    Controller.attachMode(0, &Interface);

    Controller.begin();
}

void loop()
{
    Controller.update();
}