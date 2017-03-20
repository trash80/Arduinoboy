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

#ifndef ArduinoboyController_h
#define ArduinoboyController_h

#include "MidiCallback.h"
#include "ArduinoboyModule.h"
#define MAX_HANDLERS 8
#define MAX_MODULES 8

class ArduinoboyControllerClass : public MidiCallbackClass {
  public:

    void begin();
    void update();
    void attachMode(uint8_t modeNumber, ArduinoboyModuleClass * mode);
    void setMode(uint8_t modeNumber);

    void onCommand(MidiCallbackClass * midi);
    void onData1(MidiCallbackClass * midi);
    void onNoteOn(MidiCallbackClass * midi);
    void onNoteOff(MidiCallbackClass * midi);
    void onPolyPressure(MidiCallbackClass * midi);
    void onControlChange(MidiCallbackClass * midi);
    void onProgramChange(MidiCallbackClass * midi);
    void onAfterTouch(MidiCallbackClass * midi);
    void onPitchBend(MidiCallbackClass * midi);
    void onTransportClock();
    void onTransportStart();
    void onTransportStop();
    void onTransportContinue();

    void sendRealTime(uint8_t message);
    void sendNoteOn(uint8_t channel, uint8_t note, uint8_t value);
    void sendNoteOff(uint8_t channel, uint8_t note, uint8_t value);
    void sendPolyPressure(uint8_t channel, uint8_t number, uint8_t value);
    void sendControlChange(uint8_t channel, uint8_t number, uint8_t value);
    void sendProgramChange(uint8_t channel, uint8_t patchNumber);
    void sendAfterTouch(uint8_t channel, uint8_t patchNumber);
    void sendPitchBend(uint8_t channel, uint16_t value);
    void sendTransportClock() { sendRealTime(0xF8); };
    void sendTransportStart() { sendRealTime(0xFA); };
    void sendTransportContinue() { sendRealTime(0xFB); };
    void sendTransportStop() { sendRealTime(0xFC); };

    int getChannel() { return channel; };
    int getCommand() { return command; };
    int getData1() { return data1; };
    int getData2() { return data2; };
  protected:
     struct mode {
         ArduinoboyModuleClass * module[MAX_HANDLERS];
         uint8_t numberHandlers;
     } modes[MAX_MODULES];
     mode * currentMode;
     uint8_t currentUpdateId;

  private:
     int channel;
     int command;
     int data1;
     int data2;
};

typedef ArduinoboyControllerClass ArduinoboyController;

#endif
