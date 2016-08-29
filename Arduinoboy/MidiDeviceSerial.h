
#ifndef MidiDeviceSerial_h
#define MidiDeviceSerial_h

#include "Arduino.h"
#include "ArduinoboyModule.h"

class MidiDeviceSerialClass : public ArduinoboyModuleClass {
  public:
    MidiDeviceSerialClass(HardwareSerial * s) : serial(s), baud(31250) {};

    void begin();
    void setBaud(unsigned long baudRate) { baud = baudRate; };
    void update();
    void sendRealTime(uint8_t message);
    void sendNoteOn(uint8_t channel, uint8_t note, uint8_t value);
    void sendNoteOff(uint8_t channel, uint8_t note, uint8_t value);
    void sendPolyPressure(uint8_t channel, uint8_t number, uint8_t value);
    void sendControlChange(uint8_t channel, uint8_t number, uint8_t value);
    void sendProgramChange(uint8_t channel, uint8_t patchNumber);
    void sendAfterTouch(uint8_t channel, uint8_t value);
    void sendPitchBend(uint8_t channel, uint8_t value1, uint8_t value2);
    void sendTransportClock() { sendRealTime(0xF8); };
    void sendTransportStart() { sendRealTime(0xFA); };
    void sendTransportContinue() { sendRealTime(0xFB); };
    void sendTransportStop() { sendRealTime(0xFC); };

    void onNoteOn(MidiCallbackClass * midi);
    void onNoteOff(MidiCallbackClass * midi);
    void onPolyPressure(MidiCallbackClass * midi);
    void onControlChange(MidiCallbackClass * midi);
    void onProgramChange(MidiCallbackClass * midi);
    void onAfterTouch(MidiCallbackClass * midi);
    void onPitchBend(MidiCallbackClass * midi);
    void onTransportClock(){ sendTransportClock(); };
    void onTransportStart(){ sendTransportStart(); };
    void onTransportStop(){ sendTransportStop(); };
    void onTransportContinue(){ sendTransportContinue(); };


    int getChannel() { return channel; };
    int getCommand() { return command; };
    int getData1() { return data1; };
    int getData2() { return data2; };

  private:
    HardwareSerial * serial;
    unsigned long baud;
    int channel;
    int command;
    int data1;
    int data2;
};


typedef MidiDeviceSerialClass MidiDeviceSerial;

#endif
