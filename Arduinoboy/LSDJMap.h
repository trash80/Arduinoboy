
#ifndef ModeLSDJMap_h
#define ModeLSDJMap_h

#include "Mode.h"

class LSDJMapClass : public ModeClass {
  public:
    LSDJMapClass(GameboySerialClass * gameboy, MidiHandlerClass * midi, LedInterfaceClass * interface)
    : ModeClass(gameboy, midi, interface) {};

    void setChannels(uint8_t c1, uint8_t c2) {
        channel1 = c1;
        channel2 = c2;
    };

    void begin();
    void update();
    void onCommand();
    void onData1();
    void onNoteOn();
    void onNoteOff();
    void onTransportClock();
    void onTransportStart();
    void onTransportContinue();
    void onTransportStop();

  private:
      uint8_t channel1;
      uint8_t channel2;
      bool sequencerStarted;
      int  currentRow;
      int  queueMessage;
      unsigned long queueTime;
      void clearQueue();
      void setQueueMessage(uint8_t message);
};

typedef LSDJMapClass ModeLSDJMap;

#endif
