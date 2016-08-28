/*
 * Ym2149Synth
 * http://trash80.com
 * Copyright (c) 2016 Timothy Lamb
 *
 * This file is part of Ym2149Synth.
 *
 * Ym2149Synth is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Ym2149Synth is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef YM2149_h
#define YM2149_h

#include "Arduino.h"

class YM2149Class {
  public:

    void begin();
    void write(uint8_t address, uint8_t value);

    void setPin(uint8_t pin, bool value);
    uint8_t getPin(uint8_t pin);

    void setPort(bool port, uint8_t value);
    uint8_t getPort(bool port);
    void setPortIO(bool portA, bool portB);

    void setNote(uint8_t synth, float value);
    void setFreq(uint8_t synth, uint32_t value);
    void setTone(uint8_t synth, uint16_t value);
    void setVolume(uint8_t synth, uint8_t value);
    void setNoise(uint8_t synth, uint8_t value);
    void setEnv(uint8_t synth, uint8_t value);
    void setEnvShape(uint8_t continuous, uint8_t attack, uint8_t alt, uint8_t hold);
    void mute();
  private:
    uint8_t mixerValue;
    uint8_t levelValue[3];

    uint8_t portAValue;
    uint8_t portBValue;

    static const uint8_t REG_A_FREQ = 0x00;
    static const uint8_t REG_B_FREQ = 0x02;
    static const uint8_t REG_C_FREQ = 0x04;
    static const uint8_t REG_NOISE_FREQ = 0x06;
    static const uint8_t REG_MIXER = 0x07;
    static const uint8_t REG_A_LEVEL = 0x08;
    static const uint8_t REG_B_LEVEL = 0x09;
    static const uint8_t REG_C_LEVEL = 0x0A;
    static const uint8_t REG_ENV_FREQ = 0x0B;
    static const uint8_t REG_ENV_SHAPE = 0x0D;
    static const uint8_t REG_DATAPORT_A = 0x0E;
    static const uint8_t REG_DATAPORT_B = 0x0F;

};


typedef YM2149Class YM2149;

#endif
