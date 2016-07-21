#include "ModeController.h"

void ModeControllerClass::begin()
{
    setMode(0);
}

void ModeControllerClass::update()
{
    int i = currentMode->numberHandlers;
    while(i--) {
        currentMode->mode[i]->update();
    }
    interface->update();
}

void ModeControllerClass::attachMode(uint8_t modeNumber, ModeClass * mode)
{
    modes[modeNumber].mode[modes[modeNumber].numberHandlers] = mode;
    modes[modeNumber].numberHandlers++;
}

void ModeControllerClass::setMode(uint8_t modeNumber) {
    currentMode = &modes[modeNumber];
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->begin();
}

void ModeControllerClass::onCommand()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onCommand();
}

void ModeControllerClass::onData1()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onData1();
}

void ModeControllerClass::onNoteOn()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onNoteOn();
}

void ModeControllerClass::onNoteOff()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onNoteOff();
}

void ModeControllerClass::onPolyPressure()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onPolyPressure();
}

void ModeControllerClass::onControlChange()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onControlChange();
}

void ModeControllerClass::onProgramChange()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onProgramChange();
}

void ModeControllerClass::onAfterTouch()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onAfterTouch();
}

void ModeControllerClass::onPitchBend()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onPitchBend();
}

void ModeControllerClass::onTransportClock()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onTransportClock();
}

void ModeControllerClass::onTransportStart()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onTransportStart();
}

void ModeControllerClass::onTransportContinue()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onTransportContinue();
}

void ModeControllerClass::onTransportStop()
{
    int i = currentMode->numberHandlers;
    while(i--) currentMode->mode[i]->onTransportStop();
}
