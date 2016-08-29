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

#ifndef MidiCallback_h
#define MidiCallback_h

#include "stdint.h"

class MidiCallbackClass {
  public:
    MidiCallbackClass() {}

    virtual void begin(){};
    virtual void update(){};
    virtual void onCommand(MidiCallbackClass * midi){};
    virtual void onData1(MidiCallbackClass * midi){};
    virtual void onNoteOn(MidiCallbackClass * midi){};
    virtual void onNoteOff(MidiCallbackClass * midi){};
    virtual void onPolyPressure(MidiCallbackClass * midi){};
    virtual void onControlChange(MidiCallbackClass * midi){};
    virtual void onProgramChange(MidiCallbackClass * midi){};
    virtual void onAfterTouch(MidiCallbackClass * midi){};
    virtual void onPitchBend(MidiCallbackClass * midi){};
    virtual void onTransportClock(){};
    virtual void onTransportStart(){};
    virtual void onTransportStop(){};
    virtual void onTransportContinue(){};

    virtual void sendRealTime(uint8_t message){};
    virtual void sendNoteOn(uint8_t channel, uint8_t note, uint8_t value){};
    virtual void sendNoteOff(uint8_t channel, uint8_t note, uint8_t value){};
    virtual void sendPolyPressure(uint8_t channel, uint8_t number, uint8_t value){};
    virtual void sendControlChange(uint8_t channel, uint8_t number, uint8_t value){};
    virtual void sendProgramChange(uint8_t channel, uint8_t patchNumber){};
    virtual void sendAfterTouch(uint8_t channel, uint8_t patchNumber){};
    virtual void sendPitchBend(uint8_t channel, uint16_t value){};
    virtual void sendTransportClock() { sendRealTime(0xF8); };
    virtual void sendTransportStart() { sendRealTime(0xFA); };
    virtual void sendTransportContinue() { sendRealTime(0xFB); };
    virtual void sendTransportStop() { sendRealTime(0xFC); };

    virtual int getChannel() { return 0; };
    virtual int getCommand() { return 0; };
    virtual int getData1() { return 0; };
    virtual int getData2() { return 0; };
};

typedef MidiCallbackClass MidiCallback;



#endif
