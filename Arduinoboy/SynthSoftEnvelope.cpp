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

#include "SynthSoftEnvelope.h"

//@TODO document this class

void SynthSoftEnvelopeClass::begin()
{

}

bool SynthSoftEnvelopeClass::update()
{
    //@TODO add slope curve option, add a release state
    uint8_t was = value;

    if(!shape) {
        value = max;
        return value != was;
    }

    if(phase >= 1) {
        if(shape >= 0x80) {
            value = min;
            return value != was;
        } else {
            value = max;
            return value != was;
        }
    }

    phase += increment;

    if(shape >= 0x80) {
        value = (uint8_t) map(255 - ((uint8_t)(phase * 255)),0, 255, min, max);
        return value != was;
    } else {
        value = (uint8_t) map(((uint8_t)(phase * 255)),0, 255, min, max);
        return value != was;
    }
}

uint8_t SynthSoftEnvelopeClass::read()
{
    return value;
}

void SynthSoftEnvelopeClass::rewind()
{
    phase -= increment;
}

void SynthSoftEnvelopeClass::setRange(uint8_t mn, uint8_t mx)
{
    min = mn;
    max = mx;
}

uint8_t SynthSoftEnvelopeClass::getShape()
{
    return shape;
}

void SynthSoftEnvelopeClass::setShape(uint8_t v)
{
    shape = v<<1;
    uint16_t ms = shape&0x7F;

    ms = (pow(4000.0f,0.25f+((float)ms)/127.0f)) + 1;
    //ms = map(ms, 0, 127, 0, 4000);
    increment = 1.0f/ms;
}

void SynthSoftEnvelopeClass::reset()
{
    phase = 0;
    value = -1;
}
