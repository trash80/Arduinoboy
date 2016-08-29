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

#ifndef SYNTHCONTROLLER_h
#define SYNTHCONTROLLER_h

#include "ArduinoboyModule.h"

#include "YM2149.h"
#include "SynthPatchStorage.h"
#include "SynthVoice.h"

class SynthControllerClass : public ArduinoboyModuleClass {
  public:
    void setChannels(uint8_t c1, int8_t c2, int8_t c3);
    void updateSoftSynths();
    void updateEvents();
    void begin();
    void update();
    
    void onNoteOn(MidiCallbackClass * midi);
    void onNoteOff(MidiCallbackClass * midi);
    void onControlChange(MidiCallbackClass * midi);
    void onProgramChange(MidiCallbackClass * midi);
    void onAfterTouch(MidiCallbackClass * midi);
    void onPitchBend(MidiCallbackClass * midi);

    SynthVoice Synth[3];
    SynthPatchStorage Patch[3];
    YM2149 Ym;
    uint8_t channels[3];

  private:
      int8_t keyTrig[3];
};

typedef SynthControllerClass SynthController;



#endif
