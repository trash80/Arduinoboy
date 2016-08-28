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

#ifndef SYNTHVOICE_h
#define SYNTHVOICE_h

#include "Arduino.h"
#include "YM2149.h"
#include "SynthSoftEnvelope.h"

class SynthVoiceClass {
  public:

    SynthSoftEnvelope volumeEnvelope;
    SynthSoftEnvelope pitchEnvelope;
    bool playing;

    void begin(YM2149 * ym, uint8_t sy);
    void updateSoftsynth();
    void updateEvents();
    void playNote(uint8_t n, uint8_t v);
    void setVolumeEnvShape(uint8_t v);
    void setPitchEnvAmount(uint8_t v);
    void setPitchEnvShape(uint8_t v);
    void setVibratoAttack(uint8_t v);
    void setVibratoAmount(uint8_t v);
    void setVibratoFreq(uint8_t v);
    void setNoiseDelay(uint8_t v);
    void setTranspose(uint8_t v);
    void setPitchbend(int v);
    void setGlide(uint8_t v);
    void setPwmFreq(uint8_t v);
    void setSoftDetune(uint8_t v);
    void setSynthType(uint8_t v);

  private:
    YM2149 * Ym;
    uint8_t synth;

    uint8_t synthType;

    bool enableVoice;
    bool enableSoftsynth;
    bool enableSoftDetune;
    bool enableNoise;
    bool enableEnv;

    uint8_t envType;

    uint8_t softShape;
    float softPhase;
    float softIncrement;
    float softWidth;

    float pitchEnvAmount;

    float currentFreq;
    uint16_t lastNoteFreq;

    uint32_t softCurrentFreq;
    uint16_t softFreqDetune;
    uint16_t pwmFreq;
    uint8_t softWavPos;

    uint16_t note;
    uint8_t velocity;
    uint16_t notePitch;
    int volume;

    float glide;
    float glideIncrement;

    float bendWheel;
    int transpose;

    uint8_t noiseDelay;
    bool noiseDelayTriggered;
    float noiseDelayIncrement;
    float noiseDelayPhase;

    uint8_t vibratoAmount;
    float vibratoPhase;
    float vibratoIncrement;
    float vibratoDelayIncrement;
    float vibratoDelayPhase;


};

typedef SynthVoiceClass SynthVoice;

#endif
