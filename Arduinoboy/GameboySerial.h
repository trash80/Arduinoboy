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
 
#ifndef GameboySerial_h
#define GameboySerial_h

#include "Arduino.h"
#include "LedInterface.h"

class GameboySerialClass {
  public:
    GameboySerialClass(uint8_t clockPin, uint8_t dataOutputPin, uint8_t dataInputPin, LedInterfaceClass * inter) :
        pinClock(clockPin), pinDataOut(dataOutputPin), pinDataIn(dataInputPin), interface(inter) {};
    void setOutputMode();
    void setInputMode();
    void sendByte(uint8_t data);
    void sendBit(uint8_t data);
    void sendKeyboardByte(uint8_t data);
    int receiveByte();
    int receiveByteClocked();
    uint8_t readClock();
    uint8_t readData();
  private:
    const uint8_t pinClock;
    const uint8_t pinDataOut;
    const uint8_t pinDataIn;
    bool active;
    LedInterfaceClass * interface;
};

typedef GameboySerialClass GameboySerial;

#endif
