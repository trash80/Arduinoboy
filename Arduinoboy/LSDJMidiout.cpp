#include "LSDJMidiout.h"

void LSDJMidioutClass::begin()
{
    gameboy->setOutputMode();
    sequencerStarted = false;
    for(int i=0;i<NUM_MIDIOUT;i++) lastNote[i] = -1;
}

void LSDJMidioutClass::update()
{
    midi->update();
    int data = gameboy->receiveByteClocked();
    if(data > 0x6f) {
        switch(data){
            case 0x7F:
                //clock tick
                midi->sendTransportClock();
            break;
            case 0x7E:
                //stop
                midi->sendTransportStop();
            break;
            case 0x7D:
                //start
                midi->sendTransportStart();
            break;
            default:
                command = data - 0x70;
        }
    } else if(data != -1 && command != -1) {
        // data contains a value to be performed on the command
        if(command < 4) {
            //Note message
            noteMessage(command, data);
        } else if (command < 8) {
            //Control change message
            command-=4;
            controlChangeMessage(command, data);
        } else if(command< 0x0C) {
            //Program change message
            command -=8;
            programChangeMessage(command, data);
        }
        command = -1;
    }
}

void LSDJMidioutClass::noteMessage(uint8_t chan, uint8_t data)
{
    if(data) {
        if(lastNote[chan] >= 0) {
            midi->sendNoteOff(channel[chan], lastNote[chan], 0x40);
        }
        midi->sendNoteOn(channel[chan], data, 0x7F);
        lastNote[chan] = data;
    } else if (lastNote[chan]>=0) {
        midi->sendNoteOff(channel[chan], lastNote[chan], 0x40);
        lastNote[chan] = -1;
    }
}

void LSDJMidioutClass::controlChangeMessage(uint8_t chan, uint8_t data)
{
    uint8_t value = data;

    if(ccMode[chan]) {
        if(ccScaling[chan]) {
            value = (value & 0x0F)*8;
        }
        data = (data>>4) & 0x07;
        midi->sendControlChange(channel[chan], cc[chan][data], value);
    } else {
        if(ccScaling[chan]) {
            value = (uint8_t) ((((float)data) / 0x6f) * 0x7f);
        }
        midi->sendControlChange(channel[chan], cc[chan][0], value);
    }
}

void LSDJMidioutClass::programChangeMessage(uint8_t chan, uint8_t data)
{
    midi->sendProgramChange(channel[chan], data);
}
