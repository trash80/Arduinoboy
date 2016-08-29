#include "MidiDeviceUsb.h"

void MidiDeviceUsbClass::onUsbRealTime(uint8_t message)
{
    switch(message) {
        case 0xF8:
            // Transport Sync Message
            command = message;
            callback->onTransportClock();
            break;
        case 0xFA:
            // Transport Start Message
            command = message;
            callback->onTransportStart();
            break;
        case 0xFB:
            // Transport Continue Message
            command = message;
            callback->onTransportContinue();
            break;
        case 0xFC:
            // Case: Transport Stop Message
            command = message;
            callback->onTransportStop();
            break;
        case 0xFD:
        case 0xFE:
        case 0xFF:
            break;
    }
}

void MidiDeviceUsbClass::update()
{
#ifdef MIDI_INTERFACE
    while(usbMIDI.read()) {
        channel = usbMIDI.getChannel();
        data1   = usbMIDI.getData1();
        data2   = usbMIDI.getData2();

        switch(usbMIDI.getType()) {
            case 0: // note off
                command = 0x80 + channel;
                callback->onNoteOff(this);
                break;
            case 1: // note on
                command = 0x90 + channel;
                callback->onNoteOn(this);
                break;
            case 2: // VC
                command = 0xA0 + channel;
                callback->onPolyPressure(this);
                break;
            case 3: // CC
                command = 0xB0 + channel;
                callback->onControlChange(this);
                break;
            case 4: // PG
                command = 0xC0 + channel;
                callback->onProgramChange(this);
                break;
            case 5: // AT
                command = 0xD0 + channel;
                callback->onAfterTouch(this);
                break;
            case 6: // PB
                command = 0xE0 + channel;
                callback->onPitchBend(this);
                break;
            case 8: // RT
                onUsbRealTime(data1);
                break;
        }
    }
#endif
}


void MidiDeviceUsbClass::sendRealTime(uint8_t message)
{
#ifdef MIDI_INTERFACE
    usbMIDI.sendRealTime(message);
#endif
}

void MidiDeviceUsbClass::sendNoteOn(uint8_t c, uint8_t number, uint8_t value)
{
    channel = c;
    data1 = number;
    data2 = value;
#ifdef MIDI_INTERFACE
    usbMIDI.sendNoteOn(number, value, channel);
#endif
}

void MidiDeviceUsbClass::sendNoteOff(uint8_t c, uint8_t number, uint8_t value)
{
    channel = c;
    data1 = number;
    data2 = value;

#ifdef MIDI_INTERFACE
    usbMIDI.sendNoteOff(number, value, channel);
#endif
}

void MidiDeviceUsbClass::sendPolyPressure(uint8_t c, uint8_t number, uint8_t value)
{
    channel = c;
    data1 = number;
    data2 = value;

#ifdef MIDI_INTERFACE
    usbMIDI.sendPolyPressure(number, value, channel);
#endif
}

void MidiDeviceUsbClass::sendControlChange(uint8_t c, uint8_t number, uint8_t value)
{
    channel = c;
    data1 = number;
    data2 = value;

#ifdef MIDI_INTERFACE
    usbMIDI.sendControlChange(number, value, channel);
#endif
}

void MidiDeviceUsbClass::sendProgramChange(uint8_t c, uint8_t value)
{
    channel = c;
    data1 = value;
    data2 = 0;
#ifdef MIDI_INTERFACE
    usbMIDI.sendProgramChange(value,channel);
#endif
}

void MidiDeviceUsbClass::sendAfterTouch(uint8_t c, uint8_t value)
{
    channel = c;
    data1 = value;
    data2 = 0;
#ifdef MIDI_INTERFACE
    usbMIDI.sendAfterTouch(value,channel);
#endif
}

void MidiDeviceUsbClass::sendPitchBend(uint8_t c, uint8_t value1, uint8_t value2)
{
    channel = c;
    uint16_t value = ((uint16_t)value2<<7)|(value1&0x7F);

#ifdef MIDI_INTERFACE
    usbMIDI.sendPitchBend(value, channel);
#endif
}

void MidiDeviceUsbClass::onNoteOn(MidiCallbackClass * midi)
{
    sendNoteOn(midi->getChannel(), midi->getData1(), midi->getData2());
}

void MidiDeviceUsbClass::onNoteOff(MidiCallbackClass * midi)
{
    sendNoteOff(midi->getChannel(), midi->getData1(), midi->getData2());
}

void MidiDeviceUsbClass::onPolyPressure(MidiCallbackClass * midi)
{
    sendPolyPressure(midi->getChannel(), midi->getData1(), midi->getData2());
}

void MidiDeviceUsbClass::onControlChange(MidiCallbackClass * midi)
{
    sendControlChange(midi->getChannel(), midi->getData1(), midi->getData2());
}

void MidiDeviceUsbClass::onProgramChange(MidiCallbackClass * midi)
{
    sendProgramChange(midi->getChannel(), midi->getData1());
}

void MidiDeviceUsbClass::onAfterTouch(MidiCallbackClass * midi)
{
    sendAfterTouch(midi->getChannel(), midi->getData1());
}

void MidiDeviceUsbClass::onPitchBend(MidiCallbackClass * midi)
{
    sendPitchBend(midi->getChannel(), midi->getData1(), midi->getData2());
}
