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

#ifndef SYMTHSOFTENVELOPE_h
#define SYNTHSOFTENVELOPE_h

#include "Arduino.h"

class SynthSoftEnvelopeClass {
  public:

    void begin();
    bool update();
    uint8_t read();
    void rewind();
    void setShape(uint8_t v);
    void setRange(uint8_t mn, uint8_t mx);
    uint8_t getShape();
    void reset();

  private:
    uint32_t t;
    float sampleRate;
    float phase;
    float increment;
    uint8_t shape;
    uint8_t min;
    uint8_t max;
    int value;
};

typedef SynthSoftEnvelopeClass SynthSoftEnvelope;

#endif
