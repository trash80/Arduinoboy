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

#include "SynthPatchStorage.h"

//@TODO document this class

uint8_t SynthPatchStorageClass::bank[16][16] = {
    {1,0,0,0,0,64,0,0,0,0,64,0,0,0,0,0},
    {0,0,1,0,0,64,0,0,0,80,64,0,0,0,0,0},
    {0,0,2,0,0,64,0,0,0,0,0,0,0,0,0,0},
    {0,0,3,0,0,64,0,0,0,0,0,0,0,0,0,0},
    {0,0,4,0,0,64,0,0,0,0,0,0,0,0,0,0},
    {1,0,5,0,0,64,0,0,0,0,0,0,0,0,0,0},
    {92,0,6,0,0,64,0,0,0,0,0,0,0,0,0,0},
    {0,7,5,0,0,64,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,94,0,0,0,0,33,83,52,0,0,0,0,0},
    {2,0,0,90,8,0,0,58,14,77,70,0,0,0,0,0},
    {0,0,7,79,0,0,0,0,0,0,127,0,0,0,0,0},
    {0,0,0,84,0,0,0,0,11,77,71,0,0,0,0,0},
    {27,0,5,0,0,0,0,0,56,102,51,0,0,0,0,0},
    {0,0,3,0,0,0,0,0,66,88,64,0,0,0,0,0},
    {0,0,0,98,0,106,8,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

void SynthPatchStorageClass::begin()
{

}

void SynthPatchStorageClass::init()
{
    if(EEPROM.read(numberPatches*patchSize) != 0xF1) return;
    for(uint8_t p=0;p<numberPatches;p++) {
        for(uint8_t v=0;v<patchSize;v++) {
            SynthPatchStorageClass::bank[p][v] = EEPROM.read((p*patchSize)+v);
        }
    }
}

void SynthPatchStorageClass::load(SynthVoice * synth, int patch)
{
    if(patch >= numberPatches) return;
    uint8_t * pp;
    selectedPatch = patch;
    if(patch < 0) {
        //load from temp
        pp = &patchTemp[0];
    } else {
        pp = &SynthPatchStorageClass::bank[patch][0];
    }

    synth->setPwmFreq(*(pp++));
    synth->setSoftDetune(*(pp++));
    synth->setSynthType(*(pp++));
    synth->setVolumeEnvShape(*(pp++));
    synth->setGlide(*(pp++));
    synth->setVibratoAmount(*(pp++));
    synth->setVibratoFreq(*(pp++));
    synth->setNoiseDelay(*(pp++));
    synth->setPitchEnvAmount(*(pp++));
    synth->setPitchEnvShape(*(pp++));
    synth->setTranspose(*(pp));
}

void SynthPatchStorageClass::getPatch(uint8_t * buffer, int patch)
{
    if(patch >= numberPatches) return;
    uint8_t * pp;

    if(patch < 0) {
        //load from temp
        pp = &patchTemp[0];
    } else {
        pp = &SynthPatchStorageClass::bank[patch][0];
    }

    for(uint8_t v=0;v<patchSize;v++) {
        *(buffer++) = *(pp++);
    }
}

void SynthPatchStorageClass::save()
{
    if(EEPROM.read(numberPatches*patchSize) != 0xF1)
        EEPROM.write(numberPatches*patchSize, 0xF1);

    for(uint8_t p=0;p<numberPatches;p++) {
        for(uint8_t v=0;v<patchSize;v++) {
            EEPROM.write((p*patchSize)+v,SynthPatchStorageClass::bank[p][v]);
        }
    }
}

void SynthPatchStorageClass::flush()
{
    memcpy(&bank[selectedPatch][0], &patchTemp[0], patchSize);
}

void SynthPatchStorageClass::recall()
{
    memcpy(&patchTemp[0], &bank[selectedPatch][0], patchSize);
}

void SynthPatchStorageClass::setValue(uint8_t address,uint8_t value)
{
    if(address >= patchSize) return;
    patchTemp[address] = value;
}

void SynthPatchStorageClass::writeValue(uint8_t address,uint8_t value)
{
    if(address >= patchSize) return;
    SynthPatchStorageClass::bank[selectedPatch][address] = value;
}
