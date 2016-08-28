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

#ifndef MidiHandler_h
#define MidiHandler_h

#include "Arduino.h"
#include "usb_midi.h"
#include "MidiCallback.h"

class MidiHandlerClass {
  public:
    MidiHandlerClass(HardwareSerial * s, MidiCallback * c) {
        usbMidi = false;
        relayMidi = false;
        serial = s;
        baudRate = 31250;
        setCallback(c);
    };
    void enableUsbMidi() {
        usbMidi = true;
    };
    void enableMidiRelay() {
        relayMidi = true;
    };
    void begin();
    void begin(unsigned long baud) {
        baudRate = baud;
        begin();
    }
    void update();
    int getChannel();
    int getCommand();
    int getCommandMask();
    int getData1();
    int getData2();
    bool fromUsb() {
        return fromUsbMidi;
    }
    void setCallback(MidiCallback * m);
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
    void onUsbRealTime(uint8_t message);
  private:
    unsigned long baudRate;
    boolean relayMidi;
    boolean fromUsbMidi;
    boolean usbMidi;
    int channel;
    int command;
    int data1;
    int data2;
    MidiCallback * callback;
    int numberConnected;
    HardwareSerial * serial;
};


typedef MidiHandlerClass MidiHandler;

#endif
