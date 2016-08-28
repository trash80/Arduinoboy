#include "LSDJMap.h"


void LSDJMapClass::begin()
{
    gameboy->setOutputMode();
    sequencerStarted = false;
    currentRow = -1;
    clearQueue();
}

void LSDJMapClass::update()
{
    midi->update();

    if(queueMessage >= 0 && millis() > queueTime) {
        if(queueMessage == 0xFF) {
            gameboy->sendByte(queueMessage);
        } else if(queueMessage == 0xFE || currentRow == queueMessage) {
            // Only kill playback if the row is the last one that's been played.
            currentRow = -1;
            gameboy->sendByte(0xFE);
        }
        queueMessage = -1;
    }
}

void LSDJMapClass::onCommand()
{
    if(midi->getChannel() == channel1 || midi->getChannel() == channel2) {
        if(queueMessage == 0xFF) clearQueue();
    }
}

void LSDJMapClass::onData1()
{
    if(midi->getChannel() == channel1 || midi->getChannel() == channel2) {
        if(queueMessage == 0xFF) clearQueue();
    }
}

void LSDJMapClass::onNoteOn()
{
    if(midi->getChannel() == channel1) {
        currentRow = midi->getData1();
        gameboy->sendByte(currentRow);
        clearQueue();
    } else if (midi->getChannel() == channel2) {
        currentRow = midi->getData1();
        gameboy->sendByte(currentRow + 128);
        clearQueue();
    }
    interface->blink(0, 100);
}

void LSDJMapClass::onNoteOff()
{
    uint8_t row = midi->getData1();
    if(midi->getChannel() == channel1
    || midi->getChannel() == (channel2)) {
        if(row == currentRow) {
            if(!sequencerStarted) {
                gameboy->sendByte(0xFE);
                clearQueue();
            } else if (currentRow >= 0) {
                setQueueMessage(currentRow);
            }
        }
    }
}

void LSDJMapClass::onTransportClock()
{
    if(queueMessage == -1) {
        setQueueMessage(0xFF);
    }
    if(sequencerStarted) interface->blinkEvery(48);
}

void LSDJMapClass::onTransportStart()
{
    sequencerStarted = true;
    interface->reset();
}

void LSDJMapClass::onTransportContinue()
{
    sequencerStarted = true;
}

void LSDJMapClass::onTransportStop()
{
    sequencerStarted = false;
}

void LSDJMapClass::clearQueue()
{
    queueMessage = -1;
}

void LSDJMapClass::setQueueMessage(uint8_t message)
{
    queueMessage = message;
    queueTime = millis()+4;
}
