
#ifndef LSDJKeyboard_h
#define LSDJKeyboard_h

#include "Mode.h"

class LSDJKeyboardClass : public ModeClass {
  public:
    LSDJKeyboardClass(GameboySerialClass * gameboy, MidiHandlerClass * midi, LedInterfaceClass * interface)
    : ModeClass(gameboy, midi, interface) {};

    void begin();
    void update();
    void setChannel(uint8_t ch) { channel = ch; };
    void onNoteOn();
    void onNoteOff();
    void onProgramChange();

  private:
      uint8_t channel;
      uint8_t currentOctave;
      uint8_t currentInstrument;

      const uint8_t startOctave = 36;
      const uint8_t noteStart = 48;

      const uint8_t keyboardNoteMap[24] = {0x1A,0x1B,0x22,0x23,0x21,0x2A,0x34,0x32,0x33,0x31,0x3B,0x3A,
                                         0x15,0x1E,0x1D,0x26,0x24,0x2D,0x2E,0x2C,0x36,0x35,0x3D,0x3C};
      const uint8_t keyboardLowOctaveMap[12] = {
          0x01, //Mute1
          0x09, //Mute2
          0x78, //Mute3
          0x07, //Mute4
          0x68, //Cursor Left
          0x74, //Cursor Right
          0x75, //Cursor Up
          0x72, //Cursor Down
          0x5A, //Enter
          0x7A, //Table Up
          0x7D, //Table Down
          0x29  //Table Cue
      };
      const uint8_t keyboardOctDn = 0x05;
      const uint8_t keyboardOctUp = 0x06;

      const uint8_t keyboardInsDn = 0x04;
      const uint8_t keyboardInsUp = 0x0C;

      const uint8_t keyboardTblDn = 0x03;
      const uint8_t keyboardTblUp = 0x0B;

      const uint8_t keyboardTblCue= 0x29;

      const uint8_t keyboardMut1 = 0x01;
      const uint8_t keyboardMut2 = 0x09;
      const uint8_t keyboardMut3 = 0x78;
      const uint8_t keyboardMut4 = 0x07;

      const uint8_t keyboardCurL = 0x6B;
      const uint8_t keyboardCurR = 0x74;
      const uint8_t keyboardCurU = 0x75;
      const uint8_t keyboardCurD = 0x72;
      const uint8_t keyboardPgUp = 0x7D;
      const uint8_t keyboardPgDn = 0x7A;
      const uint8_t keyboardEntr = 0x5A;

      void playNote(uint8_t note);
      void changeOctave(uint8_t octave);
      void changeInstrument(uint8_t instrument);

};

typedef LSDJKeyboardClass ModeLSDJKeyboard;

#endif
