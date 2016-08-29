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

#ifndef MidiGameboy_h
#define MidiGameboy_h

#include "ArduinoboyGameboyModule.h"

class MidiGameboyClass : public ArduinoboyGameboyModuleClass {
  public:

    void setChannels(uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4, uint8_t c5) {
        channel[0] = c1;
        channel[1] = c2;
        channel[2] = c3;
        channel[3] = c4;
        channel[4] = c5;
    };

    void begin();
    void update();
    void onNoteOn(MidiCallbackClass * midi);
    void onNoteOff(MidiCallbackClass * midi);
    void onControlChange(MidiCallbackClass * midi);
    void onProgramChange(MidiCallbackClass * midi);
    void onPitchBend(MidiCallbackClass * midi);

  private:
    uint8_t channel[5];
    int getChennel(uint8_t ch);
};

typedef MidiGameboyClass ModeMidiGameboy;

#endif
