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
#include "LedInterface.h"
#include "MidiHandler.h"

#include "LSDJSlave.h"
#include "LSDJMaster.h"
#include "LSDJMap.h"
#include "NanoloopSlave.h"
#include "LSDJKeyboard.h"
#include "LSDJMidiout.h"
#include "MidiGameboy.h"
#include "SynthController.h"


const uint8_t ledPins[2] = {13,13};
LedInterface interface(ledPins, 2);

GameboySerial gameboy(16,17,18, &interface);

ArduinoboyController controller(&interface);

MidiHandler midi(&Serial1, &controller);

SynthController YmSynth(&gameboy, &midi, &interface);
ModeLSDJMap LSDJMap(&gameboy, &midi, &interface);
ModeLSDJSlave LSDJSlave(&gameboy, &midi, &interface);
ModeLSDJMaster LSDJMaster(&gameboy, &midi, &interface);
ModeNanoloopSlave NanoloopSlave(&gameboy, &midi, &interface);
ModeLSDJKeyboard LSDJKeyboard(&gameboy, &midi, &interface);
ModeLSDJMidiout LSDJMidiout(&gameboy, &midi, &interface);
ModeMidiGameboy MidiGameboy(&gameboy, &midi, &interface);

void setup()
{
    midi.enableUsbMidi();
    midi.enableMidiRelay();
    midi.begin();

    YmSynth.setChannels(3,4,5);
    LSDJMap.setChannels(1,2);
    MidiGameboy.setChannels(1,2,3,4,5);
    LSDJMidiout.setChannels(1,2,3,4);
    LSDJKeyboard.setChannels(1);

    controller.attachMode(0, &LSDJMap);
    controller.attachMode(0, &YmSynth);

    controller.attachMode(1, &LSDJSlave);
    controller.attachMode(2, &NanoloopSlave);

    controller.begin();
    controller.setMode(0);
}

void loop()
{
    controller.update();
}
