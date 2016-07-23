
#ifndef GameboySerial_h
#define GameboySerial_h

#include "Arduino.h"
#include "LedInterface.h"

class GameboySerialClass {
  public:
    GameboySerialClass(uint8_t clockPin, uint8_t dataOutputPin, uint8_t dataInputPin, LedInterfaceClass * inter) :
        pinClock(clockPin), pinDataOut(dataOutputPin), pinDataIn(dataInputPin), interface(inter) {};
    void setOutputMode();
    void setInputMode();
    void sendByte(uint8_t data);
    void sendBit(uint8_t data);
    void sendKeyboard(uint8_t data);
    int receiveByte();
    uint8_t readClock();
    uint8_t readData();
  private:
    const uint8_t pinClock;
    const uint8_t pinDataOut;
    const uint8_t pinDataIn;
    bool active;
    LedInterfaceClass * interface;
};

typedef GameboySerialClass GameboySerial;

#endif
