#include "MidiHandler.h"

void MidiHandlerClass::begin(bool usbBaud)
{
    if(usbBaud) {
        serial->begin(38400);
        return;
    }
    serial->begin(31250);
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
            if(usbMIDI.getType() == 4 || usbMIDI.getType() == 5) {
                uint8_t m[2] = {((uint8_t) (channel-1)), (uint8_t) data1};
                serial->write(m,2);
            } else if(usbMIDI.getType() == 6){
                uint8_t d1 = (uint8_t) data1;
                uint8_t d2 = (uint8_t) (data1>>7);
                uint8_t m[3] = {((uint8_t) (channel-1)), d1, d2};
                serial->write(m,3);
            } else {
                uint8_t m[3] = {((uint8_t) (channel-1)), (uint8_t) data1, (uint8_t) data2};
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
                    if(relayMidi) usbMIDI.sendRealTime(command);
                    callback->onTransportClock();
                    break;
                case 0xFA:
                    // Transport Start Message
                    if(relayMidi) usbMIDI.sendRealTime(command);
                    callback->onTransportStart();
                    break;
                case 0xFB:
                    // Transport Continue Message
                    if(relayMidi) usbMIDI.sendRealTime(command);
                    callback->onTransportContinue();
                    break;
                case 0xFC:
                    // Case: Transport Stop Message
                    if(relayMidi) usbMIDI.sendRealTime(command);
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

            if((command & 0x80) == 0xC0) {
                if(relayMidi) usbMIDI.sendProgramChange(data1, channel);
                callback->onProgramChange();
                data1 = -1;
            } else if((command & 0x80) == 0xD0) {
                if(relayMidi) usbMIDI.sendAfterTouch(data1, channel);
                callback->onAfterTouch();
                data1 = -1;
            }
        } else if(command) {
            data2 = data;
            switch((command & 0xF0)) {
                case 0x90:
                    // Note On
                    if(data2 != 0) {
                        if(relayMidi) usbMIDI.sendNoteOn(data1, data2, channel);
                        callback->onNoteOn();
                        break;
                    }
                    // Fall though to Note Off
                case 0x80:
                    // Note Off
                    if(relayMidi) usbMIDI.sendNoteOff(data1, data2, channel);
                    callback->onNoteOff();
                    break;
                case 0xA0:
                    // After Touch
                    if(relayMidi) usbMIDI.sendPolyPressure(data1, data2, channel);
                    callback->onPolyPressure();
                    break;
                case 0xB0:
                    // Control Change
                    if(relayMidi) usbMIDI.sendControlChange(data1, data2, channel);
                    callback->onControlChange();
                    break;
                case 0xE0:
                    // Pitch Wheel
                    data1 = ((unsigned short)data2<<7) | (unsigned short)data1;
                    if(relayMidi) usbMIDI.sendPitchBend(data1, channel);
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
}

void MidiHandlerClass::sendNoteOn(uint8_t channel, uint8_t note, uint8_t value)
{
    uint8_t c = channel - 1;
    uint8_t d[3] = {c, note, value};
    serial->write(d, 3);

#ifdef MIDI_INTERFACE
    if(usbMidi) usbMIDI.sendNoteOn(note, value, channel);
#endif
}

void MidiHandlerClass::sendNoteOff(uint8_t channel, uint8_t note, uint8_t value)
{
    uint8_t c = channel - 1;
    uint8_t d[3] = {c, note, value};
    serial->write(d, 3);

#ifdef MIDI_INTERFACE
    if(usbMidi) usbMIDI.sendNoteOff(note, value, channel);
#endif
}

void MidiHandlerClass::sendPolyPressure(uint8_t channel, uint8_t note, uint8_t value)
{
    uint8_t c = channel - 1;
    uint8_t d[3] = {c, note, value};
    serial->write(d, 3);

#ifdef MIDI_INTERFACE
    if(usbMidi) usbMIDI.sendPolyPressure(note, value, channel);
#endif
}

void MidiHandlerClass::sendControlChange(uint8_t channel, uint8_t number, uint8_t value)
{
    uint8_t c = channel - 1;
    uint8_t d[3] = {c, number, value};
    serial->write(d, 3);

#ifdef MIDI_INTERFACE
    if(usbMidi) usbMIDI.sendControlChange(number, value, channel);
#endif
}

void MidiHandlerClass::sendProgramChange(uint8_t channel, uint8_t number)
{
    uint8_t c = channel - 1;
    uint8_t d[2] = {c, number};
    serial->write(d, 2);

#ifdef MIDI_INTERFACE
    if(usbMidi) usbMIDI.sendProgramChange(number,channel);
#endif
}

void MidiHandlerClass::sendPitchBend(uint8_t channel, uint16_t value)
{
    uint8_t c = channel - 1;
    uint8_t d[3] = {c, (uint8_t) (value&0x7f), (uint8_t) ((value>>7)&0x7f)};
    serial->write(d, 3);

#ifdef MIDI_INTERFACE
    if(usbMidi) usbMIDI.sendPitchBend(value, channel);
#endif
}
