#include "LSDJKeyboard.h"

void LSDJKeyboardClass::begin()
{
    gameboy->setOutputMode();

    currentOctave = 0;
    currentInstrument = 0;

    for(int rst=0;rst<5;rst++) gameboy->sendKeyboardByte(keyboardOctDn);
    for(int rst=0;rst<41;rst++) gameboy->sendKeyboardByte(keyboardInsDn);
}

void LSDJKeyboardClass::update()
{
    midi->update();
}

void LSDJKeyboardClass::onNoteOn()
{
    if(midi->getChannel() == channel) {
        playNote(midi->getData1());
    }
}

void LSDJKeyboardClass::onNoteOff()
{

}

void LSDJKeyboardClass::onProgramChange()
{
    if(midi->getChannel() == channel) {
        changeInstrument(midi->getData1());
    }
}

void LSDJKeyboardClass::playNote(uint8_t note)
{
    if(note >= noteStart) {
        note -= noteStart;

        changeOctave(note / 12);

        if(note >= 0x3C) {
            // Use second row of keyboard keys
            note = (note % 12) + 0x0C;
        } else {
            note = (note % 12);
        }

        gameboy->sendKeyboardByte(keyboardNoteMap[note]);

    } else if (note >= startOctave) {
        note -= startOctave;
        uint8_t command = keyboardLowOctaveMap[note];
        if(command == 0x68 || command == 0x72 || command == 0x74 || command == 0x75) {
            //cursor values need an "extended" pc keyboard mode message
            gameboy->sendKeyboardByte(0xE0);
        }
        gameboy->sendKeyboardByte(command);
    }
}

void LSDJKeyboardClass::changeOctave(uint8_t octave)
{
    if(octave != currentOctave) {
        int diff = abs(((int)octave) - ((int)currentOctave));

        if(octave > currentOctave) {
            while(diff--) {
                gameboy->sendKeyboardByte(keyboardOctUp);
            }
        } else {
            while(diff--) {
                gameboy->sendKeyboardByte(keyboardOctUp);
            }
        }
        currentOctave = octave;
    }
}

void LSDJKeyboardClass::changeInstrument(uint8_t instrument)
{
    if(currentInstrument != instrument) {
        int diff = abs(((int)currentInstrument) - ((int)instrument));

        if(instrument > currentInstrument) {
            while(diff--) {
                gameboy->sendKeyboardByte(keyboardInsUp);
            }
        } else {
            while(diff--) {
                gameboy->sendKeyboardByte(keyboardInsDn);
            }
        }
        currentInstrument = instrument;
    }
}
