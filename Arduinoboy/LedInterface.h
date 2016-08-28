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
 
#ifndef LedInterface_h
#define LedInterface_h

#include "Arduino.h"

#define MAX_LEDS 8

class LedInterfaceClass {
  public:
    LedInterfaceClass(const uint8_t ledPins[], uint8_t numLeds) : pins(ledPins), numberLeds(numLeds) {
        for(int i=0;i<numberLeds;i++) {
            pinMode(pins[i],OUTPUT);
        }
    };

    void begin();
    void update();
    void reset();
    void blink(uint8_t pin, uint16_t milli);
    void blink(uint16_t milli) {
        blink(0,milli);
    };
    void blink() {
        blink(0,5);
    };
    void blinkEvery(uint8_t pin, uint16_t count, uint16_t milli);
    void blinkEvery(uint16_t count, uint16_t milli) {
        blinkEvery(0, count, milli);
    };
    void blinkEvery(uint16_t count) {
        blinkEvery(0, count, 5);
    };
    void cycle(uint8_t numLeds, uint16_t skipEvery, uint16_t milli);
    void cycle(uint8_t numLeds, uint16_t skipEvery) {
        cycle(numLeds, skipEvery, 0);
    };
    void cycle(uint8_t numLeds) {
        cycle(numLeds, 0, 0);
    };

  private:
    const uint8_t * pins;
    uint8_t numberLeds;
    uint8_t state[MAX_LEDS];
    unsigned long timer[MAX_LEDS];

    uint8_t blinkEveryLedNumber;
    uint16_t blinkEveryCountTo;
    uint16_t blinkEveryCountCurrent;
    uint16_t blinkEveryMillis;

    uint8_t cycleNumberLeds;
    uint16_t cycleSkipTo;
    uint16_t cycleSkipCurrent;
    uint16_t cycleMillis;
};

typedef LedInterfaceClass LedInterface;



#endif
