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

}

void MidiGameboyClass::onNoteOn(MidiCallbackClass * midi)
{
    int ch = 0;
    if((ch = getChennel(midi->getChannel())) == -1) return;
    gameboy->sendByte(0x90 + ((uint8_t) ch));
    gameboy->sendByte(midi->getData1());
    gameboy->sendByte(midi->getData2());
}

void MidiGameboyClass::onNoteOff(MidiCallbackClass * midi)
{
    int ch = 0;
    if((ch = getChennel(midi->getChannel())) == -1) return;
    gameboy->sendByte(0x80 + ((uint8_t) ch));
    gameboy->sendByte(midi->getData1());
    gameboy->sendByte(midi->getData2());
}

void MidiGameboyClass::onControlChange(MidiCallbackClass * midi)
{
    int ch = 0;
    if((ch = getChennel(midi->getChannel())) == -1) return;
    gameboy->sendByte(0xB0 + ((uint8_t) ch));
    gameboy->sendByte(midi->getData1());
    gameboy->sendByte(midi->getData2());
}

void MidiGameboyClass::onProgramChange(MidiCallbackClass * midi)
{
    int ch = 0;
    if((ch = getChennel(midi->getChannel())) == -1) return;
    gameboy->sendByte(0xC0 + ((uint8_t) ch));
    gameboy->sendByte(midi->getData1());
}

void MidiGameboyClass::onPitchBend(MidiCallbackClass * midi)
{
    int ch = 0;
    if((ch = getChennel(midi->getChannel())) == -1) return;
    gameboy->sendByte(0xE0 + ((uint8_t) ch));
    gameboy->sendByte(((uint8_t)midi->getData1()));
    gameboy->sendByte(((uint8_t)midi->getData2()));
}

int MidiGameboyClass::getChennel(uint8_t ch)
{
    for(int i=0;i<6;i++) {
        if(ch == channel[i]) {
            return i;
        }
    }
    return -1;
}
