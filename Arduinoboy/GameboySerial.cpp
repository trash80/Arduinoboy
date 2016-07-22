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

int GameboySerialClass::receiveByte()
{
    if(!digitalRead(pinClock)) {
        //Clock is low, start read sequence
        unsigned long timeout = millis() + 100;
        uint8_t d = digitalReadFast(pinDataIn);
        uint8_t count = 8;

        while(!digitalReadFast(pinClock) && timeout > millis()) ;

        while((count--) && timeout > millis()) {
            while(digitalReadFast(pinClock) && timeout > millis()) ;
            d<<=1;
            d |= digitalReadFast(pinDataIn);
        }
        if(timeout < millis()) return d;
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
