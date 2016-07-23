#include "LSDJSlave.h"

void LSDJSlaveClass::begin()
{
    gameboy->setOutputMode();
    sequencerStarted = false;
}

void LSDJSlaveClass::update()
{
    midi->update();
}

void LSDJSlaveClass::onTransportClock()
{
    if(sequencerStarted) {
        gameboy->sendByte(0x00);
        interface->blinkEvery(24);
    }
}

void LSDJSlaveClass::onTransportStart()
{
    sequencerStarted = true;
    interface->reset();
}

void LSDJSlaveClass::onTransportContinue()
{
    sequencerStarted = true;
    interface->reset();
}

void LSDJSlaveClass::onTransportStop()
{
    sequencerStarted = false;
}
