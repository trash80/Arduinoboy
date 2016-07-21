#include "ModeController.h"
#include "GameboySerial.h"
#include "LedInterface.h"
#include "MidiHandler.h"
#include "LSDJMap.h"

GameboySerial gameboy1(16,17,18);
GameboySerial gameboy2(19,20,21);

const uint8_t ledPins[2] = {13,13};
LedInterface interface(ledPins, 2);

ModeController controller(&interface);

MidiHandler midi(&Serial1, &controller);

ModeLSDJMap LSDJMap1(&gameboy1, &midi, &interface);
ModeLSDJMap LSDJMap2(&gameboy2, &midi, &interface);

void setup()
{
    midi.enableUsbMidi();
    midi.enableMidiRelay();
    midi.begin();
    
    LSDJMap1.setChannels(1,2);
    LSDJMap2.setChannels(3,4);

    controller.attachMode(0, &LSDJMap1);
    controller.attachMode(0, &LSDJMap2);

    controller.begin();
}

void loop()
{
    controller.update();
}
