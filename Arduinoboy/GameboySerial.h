
#ifndef GameboySerial_h
#define GameboySerial_h

#include "Arduino.h"

class GameboySerialClass {
  public:
    GameboySerialClass(uint8_t clockPin, uint8_t dataOutputPin, uint8_t dataInputPin) :
        pinClock(clockPin), pinDataOut(dataOutputPin), pinDataIn(dataInputPin) {};
    void setOutputMode();
    void setInputMode();
    void sendByte(uint8_t data);
    void sendKeyboard(uint8_t data);
    int receiveByte();
    uint8_t readClock();
    uint8_t readData();
  private:
    const uint8_t pinClock;
    const uint8_t pinDataOut;
    const uint8_t pinDataIn;
};

typedef GameboySerialClass GameboySerial;

#endif
