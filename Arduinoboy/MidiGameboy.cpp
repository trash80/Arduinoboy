#include "MidiGameboy.h"

void MidiGameboyClass::begin()
{
    gameboy->setOutputMode();
}

void MidiGameboyClass::update()
{
    midi->update();
}

void MidiGameboyClass::onNoteOn()
{
    int ch = 0;
    if((ch = getChennel()) == -1) return;
    gameboy->sendByte(0x90 + ((uint8_t) ch));
    gameboy->sendByte(midi->getData1());
    gameboy->sendByte(midi->getData2());
    interface->blink();
}

void MidiGameboyClass::onNoteOff()
{
    int ch = 0;
    if((ch = getChennel()) == -1) return;
    gameboy->sendByte(0x80 + ((uint8_t) ch));
    gameboy->sendByte(midi->getData1());
    gameboy->sendByte(midi->getData2());
}

void MidiGameboyClass::onControlChange()
{
    int ch = 0;
    if((ch = getChennel()) == -1) return;
    gameboy->sendByte(0xB0 + ((uint8_t) ch));
    gameboy->sendByte(midi->getData1());
    gameboy->sendByte(midi->getData2());
}

void MidiGameboyClass::onProgramChange()
{
    int ch = 0;
    if((ch = getChennel()) == -1) return;
    gameboy->sendByte(0xC0 + ((uint8_t) ch));
    gameboy->sendByte(midi->getData1());
}

void MidiGameboyClass::onPitchBend()
{
    int ch = 0;
    if((ch = getChennel()) == -1) return;
    gameboy->sendByte(0xE0 + ((uint8_t) ch));
    gameboy->sendByte(((uint8_t)midi->getData1()));
    gameboy->sendByte(((uint8_t)midi->getData2()));
}

int MidiGameboyClass::getChennel()
{
    uint8_t ch = midi->getChannel();
    for(int i=0;i<6;i++) {
        if(ch == channel[i]) {
            return i;
        }
    }
    return -1;
}
