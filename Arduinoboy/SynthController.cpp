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

#include "SynthController.h"

//@TODO document this class

void SynthControllerClass::begin()
{
    Ym.begin();

    Ym.setPortIO(1,1);

    for(int i=0;i<3;i++) {
        Ym.setPin(8,1);
        digitalWrite(13,HIGH);
        delay(60);
        Ym.setPin(8,0);
        digitalWrite(13,LOW);
        delay(60);
    }

    Ym.setPin(8,1);
    Ym.mute();

    Patch[0].init(); // Init memory / eeprom once.

    for(int x=0;x<3;x++) {
        Synth[x].begin(&Ym,x);
        Patch[x].begin();
    }
}

void SynthControllerClass::update()
{

}

void SynthControllerClass::updateSoftSynths()
{
    Synth[0].updateSoftsynth();
    Synth[1].updateSoftsynth();
    Synth[2].updateSoftsynth();
}

void SynthControllerClass::updateEvents()
{
    Synth[0].updateEvents();
    Synth[1].updateEvents();
    Synth[2].updateEvents();
}

void SynthControllerClass::setChannels(uint8_t c1, int8_t c2, int8_t c3){
    channels[0] = c1;
    channels[1] = c2;
    channels[2] = c3;
}

void SynthControllerClass::onNoteOn(MidiCallbackClass * midi)
{
    uint8_t * m = &channels[2];
    uint8_t synth = 3;
    uint8_t note = midi->getData1();

    while(synth--) {
        if(*m == midi->getChannel()) {

            if(note < 16) {
                keyTrig[synth] = note;
                Patch[synth].load(&Synth[synth],note);
                Synth[synth].playNote(36,midi->getData2());
            } else {
                if(keyTrig[synth] > 0) {
                    Patch[synth].load(&Synth[synth],-1);
                }
                keyTrig[synth] = -1;
                Synth[synth].playNote(note,midi->getData2());
            }
        }
        m--;
    }
}

void SynthControllerClass::onNoteOff(MidiCallbackClass * midi)
{
    uint8_t * m = &channels[2];
    uint8_t synth = 3;
    uint8_t note = midi->getData1();

    while(synth--) {
        if(*m == midi->getChannel()) {
            if(note < 16) {
                Synth[synth].playNote(36,0);
            } else {
                Synth[synth].playNote(midi->getData1(),0);
            }
        }
        m--;
    }
}

void SynthControllerClass::onControlChange(MidiCallbackClass * midi)
{
    uint8_t * m = &channels[2];
    uint8_t synth = 3;
    while(synth--) {
        if(*m != midi->getChannel()) {
            m--;
            continue;
        }
        m--;

        Patch[synth].setValue((uint8_t)(midi->getData1()-1), (uint8_t) midi->getData2());

        switch(midi->getData1()) {
            case 1:
                Synth[synth].setPwmFreq(midi->getData2());
                break;
            case 2:
                Synth[synth].setSoftDetune(midi->getData2());
                break;
            case 3:
                Synth[synth].setSynthType(midi->getData2());
                break;
            case 4:
                Synth[synth].setVolumeEnvShape(midi->getData2());
                break;
            case 5:
                Synth[synth].setGlide(midi->getData2());
                break;
            case 6:
                Synth[synth].setVibratoFreq(midi->getData2());
                break;
            case 7:
                Synth[synth].setVibratoAmount(midi->getData2());
                break;
            case 8:
                Synth[synth].setNoiseDelay(midi->getData2());
                break;
            case 9:
                Synth[synth].setPitchEnvAmount(midi->getData2());
                break;
            case 10:
                Synth[synth].setPitchEnvShape(midi->getData2());
                break;
            case 11:
                Synth[synth].setTranspose(midi->getData2());
                break;
            case 120:
                Patch[synth].load(&Synth[synth],midi->getData2());
                Patch[synth].recall(); // load patch into edit memory
                break;
            case 121:
                Patch[synth].save(midi->getData2());
                break;
            case 122:
                uint8_t buffer[Patch[synth].patchSize];
                Patch[0].getPatch(&buffer[0], midi->getData2());
                for(uint8_t i=0;i!=Patch[synth].patchSize;i++) {
                    midi->sendControlChange(midi->getChannel(), i+1, buffer[i]);
                }
                break;
        }
    }
}

void SynthControllerClass::onProgramChange(MidiCallbackClass * midi)
{
    uint8_t * m = &channels[2];
    uint8_t synth = 3;
    while(synth--) {
        if(*m == midi->getChannel()) {
            Patch[synth].load(&Synth[synth],midi->getData1());
        }
        m--;
    }
}

void SynthControllerClass::onAfterTouch(MidiCallbackClass * midi)
{

}

void SynthControllerClass::onPitchBend(MidiCallbackClass * midi)
{
    uint8_t * m = &channels[2];
    uint8_t synth = 3;
    unsigned short pb;
    int v;

    pb = (unsigned short)midi->getData2();
    pb<<=7;
    pb|= (unsigned short)midi->getData1();
    v = ((int)pb) - 0x2000;

    while(synth--) {
        if(*m == midi->getChannel()) {
            Synth[synth].setPitchbend(v);
        }
        m--;
    }
}
