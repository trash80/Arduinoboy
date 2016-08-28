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
 
#ifndef LSDJSlave_h
#define LSDJSlave_h

#include "Mode.h"

class LSDJSlaveClass : public ModeClass {
  public:
    LSDJSlaveClass(GameboySerialClass * gameboy, MidiHandlerClass * midi, LedInterfaceClass * interface)
    : ModeClass(gameboy, midi, interface) {};

    void begin();
    void update();
    void onTransportClock();
    void onTransportStart();
    void onTransportContinue();
    void onTransportStop();

  private:
      bool sequencerStarted;
};

typedef LSDJSlaveClass ModeLSDJSlave;

#endif
