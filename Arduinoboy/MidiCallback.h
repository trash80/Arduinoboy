
#ifndef MidiCallback_h
#define MidiCallback_h

class MidiCallbackClass {
  public:
    MidiCallbackClass() {}

    virtual void begin(){};
    virtual void update(){};
    virtual void onCommand(){};
    virtual void onData1(){};
    virtual void onNoteOn(){};
    virtual void onNoteOff(){};
    virtual void onPolyPressure(){};
    virtual void onControlChange(){};
    virtual void onProgramChange(){};
    virtual void onAfterTouch(){};
    virtual void onPitchBend(){};
    virtual void onTransportClock(){};
    virtual void onTransportStart(){};
    virtual void onTransportStop(){};
    virtual void onTransportContinue(){};

};

typedef MidiCallbackClass MidiCallback;



#endif
