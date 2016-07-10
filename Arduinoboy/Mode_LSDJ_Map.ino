/**************************************************************************
 * Name:    Timothy Lamb                                                  *
 * Email:   trash80@gmail.com                                             *
 ***************************************************************************/
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

void modeLSDJMapSetup()
{
  digitalWrite(pinStatusLed,LOW);
  pinMode(pinGBClock,OUTPUT);
  digitalWrite(pinGBClock, HIGH);
 #ifdef MIDI_INTERFACE
  usbMIDI.setHandleRealTimeSystem(usbMidiLSDJMapRealtimeMessage);
 #endif
  blinkMaxCount=10;
  //modeLSDJMap();
}

void modeLSDJMap()
{
  while(1){  //Loop forever

  modeLSDJMapUsbMidiReceive();
  checkMapQueue();
  if (serial->available()) {                 //If MIDI Byte Availaibleleleiel
    incomingMidiByte = serial->read();           //Read it

    checkForProgrammerSysex(incomingMidiByte);

    if(incomingMidiByte & 0x80) {                //If we have received a MIDI Status Byte
      switch (incomingMidiByte) {
        case 0xF8:
          setMapByte(0xFF);
          usbMidiSendRTMessage(incomingMidiByte);
          break;
        case 0xFA:                                // Case: Transport Start Message
        case 0xFB:                                // and Case: Transport Continue Message
          sequencerStart();                       // Start the sequencer
          usbMidiSendRTMessage(incomingMidiByte);
          break;
        case 0xFC:                                // Case: Transport Stop Message
          lastMidiNote = -1;
          setMapByte(0xFE);
          sequencerStop();
          usbMidiSendRTMessage(incomingMidiByte);
          break;
        default:
          midiData[0] = incomingMidiByte;
          midiNoteOnMode = true;

          if(midiData[0] == (0x90+memory[MEM_LIVEMAP_CH])) resetMidiCue();
        }
    } else if(midiNoteOnMode) {   //if we've received a message thats not a status and our note capture mode is true

      midiNoteOnMode = false;
      midiData[1] = incomingMidiByte;

      usbMidiSendTwoByteMessage(midiData[0],midiData[1]);
      if(midiData[0] == (0x90+memory[MEM_LIVEMAP_CH])) resetMidiCue();

    } else {
      midiNoteOnMode = true;
      if(midiData[0] == (0x90+memory[MEM_LIVEMAP_CH])) {
          if(incomingMidiByte) {
              lastMidiNote = midiData[1];
              if(incomingMidiByte == 0x01) {
                  setMapByte(128+midiData[1]);
              } else {
                  setMapByte(midiData[1]);
              }
          } else if(lastMidiNote == midiData[1]) {
              lastMidiNote = -1;
              setMapByte(0xFE);
          }
      } else if (midiData[0] == (0x80+memory[MEM_LIVEMAP_CH])) {
          if(lastMidiNote == midiData[1]) {
              lastMidiNote = -1;
              setMapByte(0xFE);
          }
      }
      usbMidiSendThreeByteMessage(midiData[0], midiData[1], incomingMidiByte);
      checkMapQueue();
    }
  } else {
    setMode();         //Check if the mode button was depressed
    updateStatusLight();
    checkMapQueue();
    updateBlinkLights();
  }
  }
}

void setMapByte(uint8_t b)
{
    switch(b) {
      case 0xFF:
        setMapQueueMessage(0xFF);
        break;
      case 0xFE:
        setMapQueueMessage(0xFE);
        break;
      default:
        sendByteToGameboy(b);
        resetMidiCue();
    }
}

void setMapQueueMessage(uint8_t m)
{
    if(!mapQueueMessage || mapQueueMessage == 0xFF) {
        mapQueueTime=micros()+mapQueueWait;
        mapQueueMessage=m;
    }
}

void resetMidiCue()
{
    mapQueueMessage=0;
}

void checkMapQueue()
{
  if(mapQueueMessage && micros()>mapQueueTime) {
      sendByteToGameboy(mapQueueMessage);
      updateVisualSync();
      mapQueueMessage=0;
      mapQueueTimeSent=micros()+mapQueueWait;
  }
}


void usbMidiLSDJMapRealtimeMessage(uint8_t message)
{
    switch(message) {
      case 0xF8:
        setMapByte(0xFF);
      break;
      case 0xFA:                                // Case: Transport Start Message
      case 0xFB:                                // and Case: Transport Continue Message
        sequencerStart();                     // Start the sequencer
      break;
      case 0xFC:                                // Case: Transport Stop Message
        lastMidiNote = -1;
        setMapByte(0xFE);
        sequencerStop();                        // Stop the sequencer
      break;
    }
}

void modeLSDJMapUsbMidiReceive()
{
#ifdef MIDI_INTERFACE

    while(usbMIDI.read(memory[MEM_LIVEMAP_CH]+1)) {
        switch(usbMIDI.getType()) {
            case 0: // note off
                if(lastMidiNote == usbMIDI.getData1()) {
                    lastMidiNote = -1;
                    setMapByte(0xFE);
                }
            break;
            case 1: // note on
                lastMidiNote = usbMIDI.getData1();
                uint8_t v = usbMIDI.getData2();
                if(v == 0x01) {
                    setMapByte(128+lastMidiNote);
                } else {
                    setMapByte(lastMidiNote);
                }
            break;
            /*
            case 3: // CC
            break;
            case 4: // PG
            break;
            case 5: // AT
            break;
            case 6: // PB
            break;
            */
        }
    }
#endif
}
