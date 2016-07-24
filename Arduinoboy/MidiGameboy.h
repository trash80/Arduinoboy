
#ifndef MidiGameboy_h
#define MidiGameboy_h

#include "Mode.h"

class MidiGameboyClass : public ModeClass {
  public:
    MidiGameboyClass(GameboySerialClass * gameboy, MidiHandlerClass * midi, LedInterfaceClass * interface)
    : ModeClass(gameboy, midi, interface) {};

    void setChannels(uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4, uint8_t c5) {
        channel[0] = c1;
        channel[1] = c2;
        channel[2] = c3;
        channel[3] = c4;
        channel[4] = c5;
    };

    void begin();
    void update();
    void onNoteOn();
    void onNoteOff();
    void onControlChange();
    void onProgramChange();
    void onPitchBend();

  private:
    uint8_t channel[5];
    int getChennel();
};

typedef MidiGameboyClass ModeMidiGameboy;

#endif
