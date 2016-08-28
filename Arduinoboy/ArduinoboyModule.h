/*
 * Arduinoboy
 * http://trash80.com
 * Copyright (c) 2016 Timothy Lamb
 *
 * This file is part of Arduinoboy.
 *
 * Arduinoboy is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Arduinoboy is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef ArduinoboyModuleClass_h
#define ArduinoboyModuleClass_h

#include "GameboySerial.h"
#include "MidiCallback.h"
#include "MidiHandler.h"
#include "LedInterface.h"

class ArduinoboyModuleClass : public MidiCallbackClass {
  public:
    ArduinoboyModuleClass(GameboySerialClass * gb, MidiHandlerClass * midiHandler, LedInterfaceClass * inter)
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
