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

#include "LedInterface.h"

void LedInterfaceClass::update()
{
    unsigned long currentTime = millis();
    for(int i=0;i<numberLeds;i++) {
        if(state[i] && timer[i] < currentTime) {
            state[i] = 0;
            digitalWriteFast(pins[i],LOW);
        }
    }
}

void LedInterfaceClass::reset()
{
    for(int i=0;i<numberLeds;i++) {
        state[i] = 0;
        digitalWriteFast(pins[i],LOW);
    }

    blinkEveryCountCurrent = 0;
}

void LedInterfaceClass::onNoteOn(MidiCallbackClass * midi)
{
    blink(0,50);
}

void LedInterfaceClass::onControlChange(MidiCallbackClass * midi)
{
    blink(0,50);
}

void LedInterfaceClass::onTransportClock()
{
    blinkEvery(0,24,10);
}

void LedInterfaceClass::onTransportStart()
{
    blink(0,50);
}

void LedInterfaceClass::onTransportStop()
{
    reset();
}

void LedInterfaceClass::onTransportContinue()
{
    reset();
}

void LedInterfaceClass::blink(uint8_t pin, uint16_t milli)
{
    digitalWriteFast(pins[pin],HIGH);
    state[pin] = 255;
    timer[pin] = millis() + milli;
}

void LedInterfaceClass::blinkEvery(uint8_t pin, uint16_t count, uint16_t milli)
{
    if(pin > numberLeds) pin = 0;
    blinkEveryLedNumber = pin;
    blinkEveryCountTo   = count;
    blinkEveryMillis    = milli;

    if(!blinkEveryCountCurrent) {
        blink(blinkEveryLedNumber, blinkEveryMillis);
    }
    blinkEveryCountCurrent++;
    if(blinkEveryCountCurrent >= blinkEveryCountTo) {
        blinkEveryCountCurrent = 0;
    }
}

void LedInterfaceClass::cycle(uint8_t numLeds, uint16_t skipEvery, uint16_t milli)
{

}
