
#ifndef LSDJMidiout_h
#define LSDJMidiout_h

#define NUM_MIDIOUT 4

#include "Mode.h"

class LSDJMidioutClass : public ModeClass {
  public:
    LSDJMidioutClass(GameboySerialClass * gameboy, MidiHandlerClass * midi, LedInterfaceClass * interface)
    : ModeClass(gameboy, midi, interface) {};

    void begin();
    void update();

  private:
    bool sequencerStarted;
    int lastNote[NUM_MIDIOUT];
    int channel[NUM_MIDIOUT];
    int cc[NUM_MIDIOUT][7];
    bool ccMode[NUM_MIDIOUT];
    bool ccScaling[NUM_MIDIOUT];
    int command;

    void noteMessage(uint8_t chan, uint8_t data);
    void controlChangeMessage(uint8_t chan, uint8_t data);
    void programChangeMessage(uint8_t chan, uint8_t data);
};

typedef LSDJMidioutClass ModeLSDJMidiout;

#endif
