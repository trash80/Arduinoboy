
#ifndef LSDJSlave_h
#define LSDJSlave_h

#include "Mode.h"

class LSDJSlaveClass : public ModeClass {
  public:
    LSDJSlaveClass(GameboySerialClass * gameboy, MidiHandlerClass * midi, LedInterfaceClass * interface)
    : ModeClass(gameboy, midi, interface) {};

    void begin();
    void update();
    void onTransportClock();
    void onTransportStart();
    void onTransportContinue();
    void onTransportStop();

  private:
      bool sequencerStarted;
};

typedef LSDJSlaveClass ModeLSDJSlave;

#endif
