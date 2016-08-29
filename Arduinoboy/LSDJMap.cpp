/*
 * Arduinoboy
 * http://trash80.com
 * Copyright (c) 2016 Timothy Lamb
 *
 * This file is part of Arduinoboy.
 *
 * Arduinoboy is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Arduinoboy is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

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

void LSDJMapClass::onCommand(MidiCallbackClass * midi)
{
    if(midi->getChannel() == channel1 || midi->getChannel() == channel2) {
        if(queueMessage == 0xFF) clearQueue();
    }
}

void LSDJMapClass::onData1(MidiCallbackClass * midi)
{
    if(midi->getChannel() == channel1 || midi->getChannel() == channel2) {
        if(queueMessage == 0xFF) clearQueue();
    }
}

void LSDJMapClass::onNoteOn(MidiCallbackClass * midi)
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
}

void LSDJMapClass::onNoteOff(MidiCallbackClass * midi)
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
}

void LSDJMapClass::onTransportStart()
{
    sequencerStarted = true;
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
