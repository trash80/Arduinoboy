
#ifndef ModeController_h
#define ModeController_h

#include "MidiCallback.h"
#include "Mode.h"
#define MAX_HANDLERS 4
#define MAX_MODES 8

class ModeControllerClass : public MidiCallbackClass {
  public:

    ModeControllerClass(LedInterface * inter) : interface(inter) {};

    void begin();
    void update();
    void attachMode(uint8_t modeNumber, ModeClass * mode);
    void setMode(uint8_t modeNumber);
    void onCommand();
    void onData1();
    void onNoteOn();
    void onNoteOff();
    void onPolyPressure();
    void onControlChange();
    void onProgramChange();
    void onAfterTouch();
    void onPitchBend();
    void onTransportClock();
    void onTransportStart();
    void onTransportStop();
    void onTransportContinue();

  protected:
     struct mode {
         ModeClass * mode[MAX_HANDLERS];
         uint8_t numberHandlers;
     } modes[MAX_MODES];
     mode * currentMode;
     LedInterface * interface;
};

typedef ModeControllerClass ModeController;

#endif
