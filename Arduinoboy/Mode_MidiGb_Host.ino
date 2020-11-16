/**************************************************************************
 * Name:    Dave Vondle                                                 *
 * Email:   dave@vondle.com                                             *
 ***************************************************************************/
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

void modeMidiGbHostSetup()
{
  myusb.begin();
  midi1.setHandleNoteOff(OnNoteOff);
  midi1.setHandleNoteOn(OnNoteOn);
  midi1.setHandleControlChange(OnControlChange);
  midi1.setHandlePitchChange(OnPitchBend);

  modeMidiGbHost();
}


void modeMidiGbHost()
{
  while(1){    
    myusb.Task();
    midi1.read();
  }
}

void OnNoteOn(byte ch, byte note, byte velocity)
{
  ch = ch+midiChannelOffset;
  uint8_t s;
  s = 0x90 + ch;
  sendByteToGameboy(s);
  delayMicroseconds(GB_MIDI_DELAY);
  sendByteToGameboy(note);
  delayMicroseconds(GB_MIDI_DELAY);
  sendByteToGameboy(velocity);
  delayMicroseconds(GB_MIDI_DELAY);
  blinkLight(s, velocity);
}

void OnNoteOff(byte ch, byte note, byte velocity)
{
  ch = ch+midiChannelOffset;
  uint8_t s;
  s = 0x80 + ch;
  sendByteToGameboy(s);
  delayMicroseconds(GB_MIDI_DELAY);
  sendByteToGameboy(note);
  delayMicroseconds(GB_MIDI_DELAY);
  sendByteToGameboy(velocity);
  delayMicroseconds(GB_MIDI_DELAY);
  blinkLight(s, velocity);
}

void OnControlChange(byte ch, byte control, byte value)
{
  ch = ch+midiChannelOffset;
  uint8_t s;
  s = 0xB0 + ch;
  sendByteToGameboy(s);
  delayMicroseconds(GB_MIDI_DELAY);
  sendByteToGameboy(control);
  delayMicroseconds(GB_MIDI_DELAY);
  sendByteToGameboy(value);
  delayMicroseconds(GB_MIDI_DELAY);
  blinkLight(s, value);
}

void OnPitchBend(byte ch, int value)
{
  ch = ch+midiChannelOffset;
  uint8_t s;
  s = 0xE0 + ch;
  sendByteToGameboy(s);
  delayMicroseconds(GB_MIDI_DELAY);
  sendByteToGameboy(value);
  delayMicroseconds(GB_MIDI_DELAY);
  sendByteToGameboy(value);
  delayMicroseconds(GB_MIDI_DELAY);
  blinkLight(s, value);
}
