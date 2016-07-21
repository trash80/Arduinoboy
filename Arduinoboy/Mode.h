
#ifndef Mode_h
#define Mode_h

#include "GameboySerial.h"
#include "MidiCallback.h"
#include "MidiHandler.h"
#include "LedInterface.h"

class ModeClass : public MidiCallbackClass {
  public:
    ModeClass(GameboySerialClass * gb, MidiHandlerClass * midiHandler, LedInterfaceClass * inter)
        : gameboy(gb), midi(midiHandler), interface(inter){};

    void init(GameboySerialClass * gb, MidiHandlerClass * midiHandler, LedInterfaceClass * inter)
    {
        gameboy  = gb;
        midi     = midiHandler;
        interface= inter;
    };

    virtual void setChannels(){};

  protected:
      GameboySerialClass * gameboy;
      MidiHandlerClass * midi;
      LedInterfaceClass * interface;

};

#endif
