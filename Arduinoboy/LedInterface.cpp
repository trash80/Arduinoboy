#include "LedInterface.h"
/*
void LedInterfaceClass::LedInterfaceClass()
{
    for(int i=0;i<numberLeds;i++) {
        pinMode(pins[i],OUTPUT);
    }
}*/

void LedInterfaceClass::update()
{
    unsigned long currentTime = millis();
    for(int i=0;i<numberLeds;i++) {
        if(state[i] && timer[i] < currentTime) {
            state[i] = 0;
            digitalWriteFast(pins[i],LOW);
        }
    }
}

void LedInterfaceClass::reset()
{
    for(int i=0;i<numberLeds;i++) {
        state[i] = 0;
        digitalWriteFast(pins[i],LOW);
    }

    blinkEveryCountCurrent = 0;
}

void LedInterfaceClass::blink(uint8_t pin, uint16_t milli)
{
    digitalWriteFast(pins[pin],HIGH);
    state[pin] = 255;
    timer[pin] = millis() + milli;
}

void LedInterfaceClass::blinkEvery(uint8_t pin, uint16_t count, uint16_t milli)
{
    if(pin > numberLeds) pin = 0;
    blinkEveryLedNumber = pin;
    blinkEveryCountTo   = count;
    blinkEveryMillis    = milli;

    if(!blinkEveryCountCurrent) {
        blink(blinkEveryLedNumber, blinkEveryMillis);
    }
    blinkEveryCountCurrent++;
    if(blinkEveryCountCurrent >= blinkEveryCountTo) {
        blinkEveryCountCurrent = 0;
    }
}

void LedInterfaceClass::cycle(uint8_t numLeds, uint16_t skipEvery, uint16_t milli)
{

}
