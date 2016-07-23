
#ifndef NanoloopSlave_h
#define NanoloopSlave_h

#include "Mode.h"

class NanoloopSlaveClass : public ModeClass {
  public:
    NanoloopSlaveClass(GameboySerialClass * gameboy, MidiHandlerClass * midi, LedInterfaceClass * interface)
    : ModeClass(gameboy, midi, interface) {};

    void begin();
    void update();
    void onTransportClock();
    void onTransportStart();
    void onTransportContinue();
    void onTransportStop();

  private:
      bool sequencerStarted;
      bool syncSwitch;
};

typedef NanoloopSlaveClass ModeNanoloopSlave;

#endif
