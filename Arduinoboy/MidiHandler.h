
#ifndef MidiHandler_h
#define MidiHandler_h

#include "Arduino.h"
#include "usb_midi.h"
#include "MidiCallback.h"

class MidiHandlerClass {
  public:
    MidiHandlerClass(HardwareSerial * s, MidiCallback * c) {
        usbMidi = false;
        relayMidi = false;
        serial = s;
        setCallback(c);
    };
    void begin(bool usbBaud);
    void begin() {
        begin(false);
    };
    void enableUsbMidi() {
        usbMidi = true;
    };
    void enableMidiRelay() {
        relayMidi = true;
    };
    void update();
    int getChannel();
    int getCommand();
    int getCommandMask();
    int getData1();
    int getData2();
    void setCallback(MidiCallback * m);
    void sendRealTime(uint8_t message);
    void sendNoteOn(uint8_t channel, uint8_t note, uint8_t value);
    void sendNoteOff(uint8_t channel, uint8_t note, uint8_t value);
    void sendPolyPressure(uint8_t channel, uint8_t number, uint8_t value);
    void sendControlChange(uint8_t channel, uint8_t number, uint8_t value);
    void sendProgramChange(uint8_t channel, uint8_t patchNumber);
    void sendAfterTouch(uint8_t channel, uint8_t patchNumber);
    void sendPitchBend(uint8_t channel, uint16_t value);
    void sendTransportClock() { sendRealTime(0xF8); };
    void sendTransportStart() { sendRealTime(0xFA); };
    void sendTransportContinue() { sendRealTime(0xFB); };
    void sendTransportStop() { sendRealTime(0xFC); };
    void onUsbRealTime(uint8_t message);
  private:
    boolean relayMidi;
    boolean fromUsbMidi;
    boolean usbMidi;
    int channel;
    int command;
    int data1;
    int data2;
    MidiCallback * callback;
    int numberConnected;
    HardwareSerial * serial;
};


typedef MidiHandlerClass MidiHandler;

#endif
