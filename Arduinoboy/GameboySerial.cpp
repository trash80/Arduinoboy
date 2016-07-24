#include "GameboySerial.h"

void GameboySerialClass::setOutputMode()
{
    pinMode(pinClock, OUTPUT);
    pinMode(pinDataOut, OUTPUT);
    pinMode(pinDataIn, INPUT);
    digitalWriteFast(pinClock,HIGH);
}

void GameboySerialClass::setInputMode()
{
    pinMode(pinClock, INPUT);
    pinMode(pinDataOut, OUTPUT);
    pinMode(pinDataIn, INPUT);
}

void GameboySerialClass::sendByte(uint8_t data)
{
    uint8_t count = 8;
    while(count--) {
        digitalWriteFast(pinDataOut, (data & 0x80));
        digitalWriteFast(pinClock, LOW);
        delayMicroseconds(1);
        digitalWriteFast(pinClock, HIGH);
        data <<= 1;
    }
    delayMicroseconds(250);
}

void GameboySerialClass::sendBit(uint8_t data)
{
    digitalWriteFast(pinDataOut, data);
    digitalWriteFast(pinClock, LOW);
    delayMicroseconds(1);
    digitalWriteFast(pinClock, HIGH);
    data <<= 1;
}

void GameboySerialClass::sendKeyboardByte(uint8_t data)
{
    sendBit(0);
    uint8_t count = 8;
    while(count--) {
        sendBit(data&0x01);
        data >>= 1;
    }
    sendBit(0);
    sendBit(1);
}

int GameboySerialClass::receiveByte()
{
    if(digitalReadFast(pinClock)) {
        active = true;
    } else if(active) {
        //Clock is low, start read
        unsigned long timeout = millis() + 2;
        uint8_t d = digitalReadFast(pinDataIn);
        uint8_t count = 7;

        while((count--) && timeout > millis()) {
            while(!digitalReadFast(pinClock) && timeout > millis());
            d<<=1;
            d |= digitalReadFast(pinDataIn);
            while(digitalReadFast(pinClock) && timeout > millis());
        }

        while(!digitalReadFast(pinClock) && timeout > millis());

        if(timeout > millis()) {
            return d;
        } else {
            active = false;
        }
    }
    return -1;
}

int GameboySerialClass::receiveByteClocked()
{
    sendBit(0);
    delayMicroseconds(1);
    if(digitalReadFast(pinDataIn)) {
        uint8_t d = 0;
        uint8_t count = 7;
        while(count--) {
            sendBit(0);
            d = (d<<1) | digitalReadFast(pinDataIn);
        }
        return d;
    }
    return -1;
}

uint8_t GameboySerialClass::readClock()
{
    return digitalReadFast(pinClock);
}

uint8_t GameboySerialClass::readData()
{
    return digitalReadFast(pinDataIn);
}
