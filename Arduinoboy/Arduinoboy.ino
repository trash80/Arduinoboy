#include "ModeController.h"
#include "GameboySerial.h"
#include "LedInterface.h"
#include "MidiHandler.h"

#include "LSDJSlave.h"
#include "LSDJMaster.h"
#include "LSDJMap.h"
#include "NanoloopSlave.h"
#include "LSDJKeyboard.h"
#include "LSDJMidiout.h"
#include "MidiGameboy.h"


const uint8_t ledPins[2] = {13,13};
LedInterface interface(ledPins, 2);

GameboySerial gameboy1(16,17,18, &interface);
GameboySerial gameboy2(19,20,21, &interface);

ModeController controller(&interface);

MidiHandler midi(&Serial1, &controller);

ModeLSDJMap LSDJMap1(&gameboy1, &midi, &interface);
ModeLSDJMap LSDJMap2(&gameboy2, &midi, &interface);

ModeLSDJSlave LSDJSlave1(&gameboy1, &midi, &interface);
ModeLSDJSlave LSDJSlave2(&gameboy2, &midi, &interface);

ModeLSDJMaster LSDJMaster1(&gameboy1, &midi, &interface);
ModeLSDJMaster LSDJMaster2(&gameboy2, &midi, &interface);

ModeNanoloopSlave NanoloopSlave1(&gameboy1, &midi, &interface);
ModeNanoloopSlave NanoloopSlave2(&gameboy2, &midi, &interface);

ModeLSDJMidiout LSDJKeyboard1(&gameboy1, &midi, &interface);
ModeLSDJMidiout LSDJKeyboard2(&gameboy2, &midi, &interface);

ModeLSDJMidiout LSDJMidiout1(&gameboy1, &midi, &interface);
ModeLSDJMidiout LSDJMidiout2(&gameboy2, &midi, &interface);

ModeMidiGameboy MidiGameboy1(&gameboy1, &midi, &interface);
ModeMidiGameboy MidiGameboy2(&gameboy2, &midi, &interface);

/*


midiSerial has serial device
midiMerger merges midi devices together
midiMapper maps an aggragator to midi channels of arduinoboy ModeLSDJSlave

MidiSerial midi1(&Serial1);
MidiSerial midi2(&Serial2);
MidiSerialUsb midi3(&usbMIDI);

MidiSerialMerger midiAll(&midi1);
midiAll.addDevice(&midi3);

MidiChannelFilter LSDJMapFilter1(channels);
MidiChannelFilter LSDJMapFilter2(channels);

MidiMapper midiMapper;
midiMapper.connectInput(&midiAll, &LSDJMapFilter1, &LSDJMap1);
midiMapper.connectInput(&midiAll, &LSDJMapFilter2, &LSDJMap2);

*/
void setup()
{
    //midi.attachDevice(&usb);
    //midi.attachRelay(&usb);
    midi.enableUsbMidi();
    midi.enableMidiRelay();
    midi.begin();

    LSDJMap1.setChannels(1,2);
    LSDJMap2.setChannels(3,4);

    MidiGameboy1.setChannels(5,4,3,2,1);
    controller.attachMode(0, &MidiGameboy1);
    controller.attachMode(0, &MidiGameboy2);

    controller.attachMode(1, &LSDJSlave1);
    controller.attachMode(1, &LSDJSlave2);

    controller.attachMode(2, &NanoloopSlave1);
    controller.attachMode(2, &NanoloopSlave2);

    controller.begin();
    controller.setMode(0);

}

void loop()
{
    controller.update();
}
