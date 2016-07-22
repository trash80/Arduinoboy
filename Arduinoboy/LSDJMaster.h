
#ifndef LSDJMaster_h
#define LSDJMaster_h

#include "Mode.h"

class LSDJMasterClass : public ModeClass {
  public:
    LSDJMasterClass(GameboySerialClass * gameboy, MidiHandlerClass * midi, LedInterfaceClass * interface)
    : ModeClass(gameboy, midi, interface) {};

    void begin();
    void update();

  private:
      bool sequencerStarted;
      unsigned long wait;
};

typedef LSDJMasterClass ModeLSDJMaster;

#endif
