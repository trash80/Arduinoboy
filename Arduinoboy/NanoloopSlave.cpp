#include "NanoloopSlave.h"

void NanoloopSlaveClass::begin()
{
    gameboy->setOutputMode();
    sequencerStarted = false;
}

void NanoloopSlaveClass::update()
{
    midi->update();
}

void NanoloopSlaveClass::onTransportClock()
{
    if(sequencerStarted) {
        if(syncSwitch) {
            gameboy->sendBit(1);
            gameboy->sendBit(1);
        } else {
            gameboy->sendBit(1);
            gameboy->sendBit(0);
        }
        syncSwitch = !syncSwitch;
        interface->blinkEvery(24);
    }
}

void NanoloopSlaveClass::onTransportStart()
{
    sequencerStarted = true;
    syncSwitch = false;
    interface->reset();
}

void NanoloopSlaveClass::onTransportContinue()
{
    sequencerStarted = true;
    syncSwitch = false;
    interface->reset();
}

void NanoloopSlaveClass::onTransportStop()
{
    sequencerStarted = false;
}
