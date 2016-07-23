#include "LSDJMaster.h"

void LSDJMasterClass::begin()
{
    gameboy->setInputMode();
    sequencerStarted = false;
}

void LSDJMasterClass::update()
{
    midi->update();
    if(sequencerStarted && !gameboy->readClock()) {
        midi->sendTransportClock();
        interface->blinkEvery(24);
        wait = millis() + 100;
        delay(1);
    } else if (sequencerStarted && gameboy->readClock() && wait < millis()) {
        midi->sendTransportStop();
        interface->reset();
        sequencerStarted = false;
    } else if (!sequencerStarted) {
        int data = gameboy->receiveByte();

        if (data >= 0) {
            midi->sendTransportClock();
            midi->sendTransportStart();
            interface->reset();
            interface->blinkEvery(24);
            sequencerStarted = true;
            wait = millis() + 100;
        }
    }
}
