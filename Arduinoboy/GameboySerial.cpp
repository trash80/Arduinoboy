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
    for(uint8_t i=0;i<8;i++) {
        digitalWriteFast(pinDataOut, (data & 0x80));
        digitalWriteFast(pinClock, LOW);
        delayMicroseconds(1);
        digitalWriteFast(pinClock, HIGH);
        data <<= 1;
    }
}

void GameboySerialClass::sendKeyboard(uint8_t data)
{

}

uint8_t GameboySerialClass::receiveByte()
{
    return 0;
}

uint8_t GameboySerialClass::readClock()
{
    return digitalRead(pinClock);
}

uint8_t GameboySerialClass::readData()
{
    return digitalRead(pinDataIn);
}
