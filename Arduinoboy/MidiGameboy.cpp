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

 #include "MidiGameboy.h"

void MidiGameboyClass::begin()
{
    gameboy->setOutputMode();
}

void MidiGameboyClass::update()
{
    midi->update();
}

void MidiGameboyClass::onNoteOn()
{
    int ch = 0;
    if((ch = getChennel()) == -1) return;
    gameboy->sendByte(0x90 + ((uint8_t) ch));
    gameboy->sendByte(midi->getData1());
    gameboy->sendByte(midi->getData2());
    interface->blink();
}

void MidiGameboyClass::onNoteOff()
{
    int ch = 0;
    if((ch = getChennel()) == -1) return;
    gameboy->sendByte(0x80 + ((uint8_t) ch));
    gameboy->sendByte(midi->getData1());
    gameboy->sendByte(midi->getData2());
}

void MidiGameboyClass::onControlChange()
{
    int ch = 0;
    if((ch = getChennel()) == -1) return;
    gameboy->sendByte(0xB0 + ((uint8_t) ch));
    gameboy->sendByte(midi->getData1());
    gameboy->sendByte(midi->getData2());
}

void MidiGameboyClass::onProgramChange()
{
    int ch = 0;
    if((ch = getChennel()) == -1) return;
    gameboy->sendByte(0xC0 + ((uint8_t) ch));
    gameboy->sendByte(midi->getData1());
}

void MidiGameboyClass::onPitchBend()
{
    int ch = 0;
    if((ch = getChennel()) == -1) return;
    gameboy->sendByte(0xE0 + ((uint8_t) ch));
    gameboy->sendByte(((uint8_t)midi->getData1()));
    gameboy->sendByte(((uint8_t)midi->getData2()));
}

int MidiGameboyClass::getChennel()
{
    uint8_t ch = midi->getChannel();
    for(int i=0;i<6;i++) {
        if(ch == channel[i]) {
            return i;
        }
    }
    return -1;
}
