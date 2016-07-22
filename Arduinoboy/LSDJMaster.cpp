#include "LSDJMaster.h"

void LSDJMasterClass::begin()
{
    gameboy->setInputMode();
    sequencerStarted = false;
}

void LSDJMasterClass::update()
{
    midi->update();
    int data = gameboy->receiveByte();
    if(data == 0xFF) {
        wait = millis() + 100;
        midi->sendTransportClock();
    } else if (data >= 0) {
        midi->sendTransportStart();
        sequencerStarted = true;
    } else {
        if(sequencerStarted && wait < millis()) {
            sequencerStarted = false;
            midi->sendTransportStop();
        }
    }
}
