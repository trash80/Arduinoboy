#include "MidiDeviceSerial.h"

void MidiDeviceSerialClass::begin()
{
    serial->begin(baud);
}


void MidiDeviceSerialClass::update()
{
    if(serial->available()) {
        uint8_t data = serial->read();

        //@TODO checkForProgrammerSysex(data);

        if(data & 0x80) {
            switch (data) {
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
                case 0xFD:
                case 0xFE:
                case 0xFF:
                    break;
                default:
                    command = data;
                    data1 = -1;
                    data2 = -1;
                    channel = (command & 0x0F) + 1;
                    callback->onCommand(this);
            }

        } else if(command && data1 == -1) {
            data1 = data;
            callback->onData1(this);

            if((command & 0x80) == 0xC0) {
                callback->onProgramChange(this);
                data1 = -1;
            } else if((command & 0x80) == 0xD0) {
                callback->onAfterTouch(this);
                data1 = -1;
            }
        } else if(command) {
            data2 = data;
            switch((command & 0xF0)) {
                case 0x90:
                    // Note On
                    if(data2 != 0) {
                        callback->onNoteOn(this);
                        break;
                    }
                    // Fall though to Note Off
                case 0x80:
                    // Note Off
                    callback->onNoteOff(this);
                    break;
                case 0xA0:
                    // After Touch
                    callback->onPolyPressure(this);
                    break;
                case 0xB0:
                    // Control Change
                    callback->onControlChange(this);
                    break;
                case 0xE0:
                    // Pitch Wheel
                    callback->onPitchBend(this);
                    break;
            }
            data1 = -1;
        }
    }
}

void MidiDeviceSerialClass::sendRealTime(uint8_t message)
{
    serial->write(message);
}

void MidiDeviceSerialClass::sendNoteOn(uint8_t c, uint8_t number, uint8_t value)
{
    channel = c;
    data1 = number;
    data2 = value;

    c--;

    uint8_t d[3] = {c, number, value};
    serial->write(d, 3);
}

void MidiDeviceSerialClass::sendNoteOff(uint8_t c, uint8_t number, uint8_t value)
{
    channel = c;
    data1 = number;
    data2 = value;

    c--;

    uint8_t d[3] = {c, number, value};
    serial->write(d, 3);
}

void MidiDeviceSerialClass::sendPolyPressure(uint8_t c, uint8_t number, uint8_t value)
{
    channel = c;
    data1 = number;
    data2 = value;

    c--;
    uint8_t d[3] = {c, number, value};
    serial->write(d, 3);
}

void MidiDeviceSerialClass::sendControlChange(uint8_t c, uint8_t number, uint8_t value)
{
    channel = c;
    data1 = number;
    data2 = value;

    c--;
    uint8_t d[3] = {c, number, value};
    serial->write(d, 3);
}

void MidiDeviceSerialClass::sendProgramChange(uint8_t c, uint8_t value)
{
    channel = c;
    data1 = value;
    data2 = 0;
    c--;
    uint8_t d[2] = {c, value};
    serial->write(d, 2);
}

void MidiDeviceSerialClass::sendAfterTouch(uint8_t c, uint8_t value)
{
    channel = c;
    data1 = value;
    data2 = 0;
    c--;
    uint8_t d[2] = {c, value};
    serial->write(d, 2);
}

void MidiDeviceSerialClass::sendPitchBend(uint8_t c, uint8_t value1, uint8_t value2)
{
    channel = c;
    data1 = value1;
    data2 = value2;
    c--;
    uint8_t d[3] = {c, value1, value2};
    serial->write(d, 3);
}


void MidiDeviceSerialClass::onNoteOn(MidiCallbackClass * midi)
{
    sendNoteOn(midi->getChannel(), midi->getData1(), midi->getData2());
}

void MidiDeviceSerialClass::onNoteOff(MidiCallbackClass * midi)
{
    sendNoteOff(midi->getChannel(), midi->getData1(), midi->getData2());
}

void MidiDeviceSerialClass::onPolyPressure(MidiCallbackClass * midi)
{
    sendPolyPressure(midi->getChannel(), midi->getData1(), midi->getData2());
}

void MidiDeviceSerialClass::onControlChange(MidiCallbackClass * midi)
{
    sendControlChange(midi->getChannel(), midi->getData1(), midi->getData2());
}

void MidiDeviceSerialClass::onProgramChange(MidiCallbackClass * midi)
{
    sendProgramChange(midi->getChannel(), midi->getData1());
}

void MidiDeviceSerialClass::onAfterTouch(MidiCallbackClass * midi)
{
    sendAfterTouch(midi->getChannel(), midi->getData1());
}

void MidiDeviceSerialClass::onPitchBend(MidiCallbackClass * midi)
{
    sendPitchBend(midi->getChannel(), midi->getData1(), midi->getData2());
}
