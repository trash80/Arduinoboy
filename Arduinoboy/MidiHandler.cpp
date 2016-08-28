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

#include "MidiHandler.h"

void MidiHandlerClass::begin()
{
    serial->begin(baudRate);
}

void MidiHandlerClass::onUsbRealTime(uint8_t message)
{
    switch(message) {
        case 0xF8:
            // Transport Sync Message
            command = message;
            fromUsbMidi = true;
            callback->onTransportClock();
            break;
        case 0xFA:
            // Transport Start Message
            command = message;
            fromUsbMidi = true;
            callback->onTransportStart();
            break;
        case 0xFB:
            // Transport Continue Message
            command = message;
            fromUsbMidi = true;
            callback->onTransportContinue();
            break;
        case 0xFC:
            // Case: Transport Stop Message
            command = message;
            fromUsbMidi = true;
            callback->onTransportStop();
            break;
        case 0xFD:
        case 0xFE:
        case 0xFF:
            break;
    }
    if(relayMidi) serial->write(message);
}

void MidiHandlerClass::update()
{
    if(usbMidi) {
#ifdef MIDI_INTERFACE
    while(usbMIDI.read()) {
        channel = usbMIDI.getChannel();
        data1   = usbMIDI.getData1();
        data2   = usbMIDI.getData2();
        fromUsbMidi = true;


        if(relayMidi) {
            uint8_t status = 0x80 + (usbMIDI.getType()<<4) + ((uint8_t)channel-1);

            if(usbMIDI.getType() == 4 || usbMIDI.getType() == 5) {
                uint8_t m[2] = {status, (uint8_t) data1};
                serial->write(m,2);
            } else if(usbMIDI.getType() == 6){
                uint8_t d1 = (uint8_t) data1;
                uint8_t d2 = (uint8_t) (data1>>7);
                uint8_t m[3] = {status, d1, d2};
                serial->write(m,3);
            } else {
                uint8_t m[3] = {status, (uint8_t) data1, (uint8_t) data2};
                serial->write(m,3);
            }
        }

        switch(usbMIDI.getType()) {
            case 0: // note off
                command = 0x80 + channel;
                callback->onNoteOff();
                break;
            case 1: // note on
                command = 0x90 + channel;
                callback->onNoteOn();
                break;
            case 2: // VC
                command = 0xA0 + channel;
                callback->onPolyPressure();
                break;
            case 3: // CC
                command = 0xB0 + channel;
                callback->onControlChange();
                break;
            case 4: // PG
                command = 0xC0 + channel;
                callback->onProgramChange();
                break;
            case 5: // AT
                command = 0xD0 + channel;
                callback->onAfterTouch();
                break;
            case 6: // PB
                command = 0xE0 + channel;
                callback->onPitchBend();
                break;
            case 8: // RT
                onUsbRealTime(data1);
                break;
        }
    }
#endif
    }

    if(serial->available()) {
        uint8_t data = serial->read();
        fromUsbMidi = false;

        //@TODO checkForProgrammerSysex(data);

        if(data & 0x80) {
            switch (data) {
                case 0xF8:
                    // Transport Sync Message
                    #ifdef MIDI_INTERFACE
                    if(relayMidi) usbMIDI.sendRealTime(data);
                    #endif
                    callback->onTransportClock();
                    break;
                case 0xFA:
                    // Transport Start Message
                    #ifdef MIDI_INTERFACE
                    if(relayMidi) usbMIDI.sendRealTime(data);
                    #endif
                    callback->onTransportStart();
                    break;
                case 0xFB:
                    // Transport Continue Message
                    #ifdef MIDI_INTERFACE
                    if(relayMidi) usbMIDI.sendRealTime(data);
                    #endif
                    callback->onTransportContinue();
                    break;
                case 0xFC:
                    // Case: Transport Stop Message
                    #ifdef MIDI_INTERFACE
                    if(relayMidi) usbMIDI.sendRealTime(data);
                    #endif
                    callback->onTransportStop();
                    break;
                case 0xFD:
                case 0xFE:
                case 0xFF:
                    break;
                default:
                    command = data;
                    data1 = -1;
                    data2 = -1;
                    channel = (command & 0x0F) + 1;
                    callback->onCommand();
            }

        } else if(command && data1 == -1) {
            data1 = data;
            callback->onData1();

            if((command & 0xF0) == 0xC0) {
                #ifdef MIDI_INTERFACE
                if(relayMidi) usbMIDI.sendProgramChange(data1, channel);
                #endif
                callback->onProgramChange();
                data1 = -1;
            } else if((command & 0xF0) == 0xD0) {
                #ifdef MIDI_INTERFACE
                if(relayMidi) usbMIDI.sendAfterTouch(data1, channel);
                #endif
                callback->onAfterTouch();
                data1 = -1;
            }
        } else if(command) {
            data2 = data;
            switch((command & 0xF0)) {
                case 0x90:
                    // Note On
                    if(data2 != 0) {
                        #ifdef MIDI_INTERFACE
                        if(relayMidi) usbMIDI.sendNoteOn(data1, data2, channel);
                        #endif
                        callback->onNoteOn();
                        break;
                    }
                    // Fall though to Note Off
                case 0x80:
                    // Note Off
                    #ifdef MIDI_INTERFACE
                    if(relayMidi) usbMIDI.sendNoteOff(data1, data2, channel);
                    #endif
                    callback->onNoteOff();
                    break;
                case 0xA0:
                    // After Touch
                    #ifdef MIDI_INTERFACE
                    if(relayMidi) usbMIDI.sendPolyPressure(data1, data2, channel);
                    #endif
                    callback->onPolyPressure();
                    break;
                case 0xB0:
                    // Control Change
                    #ifdef MIDI_INTERFACE
                    if(relayMidi) usbMIDI.sendControlChange(data1, data2, channel);
                    #endif
                    callback->onControlChange();
                    break;
                case 0xE0:
                    // Pitch Wheel
                    #ifdef MIDI_INTERFACE
                    if(relayMidi) usbMIDI.sendPitchBend(((unsigned short)data2<<7) | (unsigned short)data1, channel);
                    #endif
                    callback->onPitchBend();
                    break;
            }
            data1 = -1;
        }
    }
}

int MidiHandlerClass::getChannel()
{
    return channel;
}

int MidiHandlerClass::getCommand()
{
    return command;
}

int MidiHandlerClass::getCommandMask()
{
    return command & 0x80;
}

int MidiHandlerClass::getData1()
{
    return data1;
}

int MidiHandlerClass::getData2()
{
    return data2;
}

void MidiHandlerClass::setCallback(MidiCallback *c)
{
    callback = c;
}

void MidiHandlerClass::sendRealTime(uint8_t message)
{
    serial->write(message);

#ifdef MIDI_INTERFACE
    if(usbMidi) usbMIDI.sendRealTime(message);
#endif

    switch (message) {
        case 0xF8:
            // Transport Sync Message
            callback->onTransportClock();
            break;
        case 0xFA:
            // Transport Start Message
            callback->onTransportStart();
            break;
        case 0xFB:
            // Transport Continue Message
            callback->onTransportContinue();
            break;
        case 0xFC:
            // Case: Transport Stop Message
            callback->onTransportStop();
            break;
    }
}

void MidiHandlerClass::sendNoteOn(uint8_t c, uint8_t number, uint8_t value)
{
    channel = c;
    data1 = number;
    data2 = value;

    c--;

    uint8_t d[3] = {c, number, value};
    serial->write(d, 3);

#ifdef MIDI_INTERFACE
    if(usbMidi) usbMIDI.sendNoteOn(number, value, channel);
#endif
    callback->onNoteOn();
}

void MidiHandlerClass::sendNoteOff(uint8_t c, uint8_t number, uint8_t value)
{
    channel = c;
    data1 = number;
    data2 = value;

    c--;

    uint8_t d[3] = {c, number, value};
    serial->write(d, 3);

#ifdef MIDI_INTERFACE
    if(usbMidi) usbMIDI.sendNoteOff(number, value, channel);
#endif
    callback->onNoteOff();
}

void MidiHandlerClass::sendPolyPressure(uint8_t c, uint8_t number, uint8_t value)
{
    channel = c;
    data1 = number;
    data2 = value;

    c--;
    uint8_t d[3] = {c, number, value};
    serial->write(d, 3);

#ifdef MIDI_INTERFACE
    if(usbMidi) usbMIDI.sendPolyPressure(number, value, channel);
#endif
    callback->onPolyPressure();
}

void MidiHandlerClass::sendControlChange(uint8_t c, uint8_t number, uint8_t value)
{
    channel = c;
    data1 = number;
    data2 = value;

    c--;
    uint8_t d[3] = {c, number, value};
    serial->write(d, 3);

#ifdef MIDI_INTERFACE
    if(usbMidi) usbMIDI.sendControlChange(number, value, channel);
#endif
    callback->onControlChange();
}

void MidiHandlerClass::sendProgramChange(uint8_t c, uint8_t value)
{
    channel = c;
    data1 = value;
    data2 = 0;
    c--;
    uint8_t d[2] = {c, value};
    serial->write(d, 2);

#ifdef MIDI_INTERFACE
    if(usbMidi) usbMIDI.sendProgramChange(value,channel);
#endif

    callback->onProgramChange();
}

void MidiHandlerClass::sendPitchBend(uint8_t c, uint16_t value)
{
    channel = c;
    data1 = value;
    data2 = 0;
    c--;
    uint8_t d[3] = {c, (uint8_t) (value&0x7f), (uint8_t) ((value>>7)&0x7f)};
    serial->write(d, 3);

#ifdef MIDI_INTERFACE
    if(usbMidi) usbMIDI.sendPitchBend(value, channel);
#endif

    callback->onPitchBend();
}
