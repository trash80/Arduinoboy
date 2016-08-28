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
 
#ifndef ModeController_h
#define ModeController_h

#include "MidiCallback.h"
#include "Mode.h"
#define MAX_HANDLERS 4
#define MAX_MODES 8

class ModeControllerClass : public MidiCallbackClass {
  public:

    ModeControllerClass(LedInterface * inter) : interface(inter) {};

    void begin();
    void update();
    void attachMode(uint8_t modeNumber, ModeClass * mode);
    void setMode(uint8_t modeNumber);
    void onCommand();
    void onData1();
    void onNoteOn();
    void onNoteOff();
    void onPolyPressure();
    void onControlChange();
    void onProgramChange();
    void onAfterTouch();
    void onPitchBend();
    void onTransportClock();
    void onTransportStart();
    void onTransportStop();
    void onTransportContinue();

  protected:
     struct mode {
         ModeClass * mode[MAX_HANDLERS];
         uint8_t numberHandlers;
     } modes[MAX_MODES];
     mode * currentMode;
     LedInterface * interface;
};

typedef ModeControllerClass ModeController;

#endif
