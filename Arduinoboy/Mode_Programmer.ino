void modeProgrammer()
{
  while(sysexProgrammingConnected || sysexProgrammingMode) {
    checkProgrammerConnected();
    if (Serial.available()) checkForProgrammerSysex(Serial.read());
    updateProgrammerLeds();
    setMode();
  }
  showSelectedMode();
  switchMode();
}

void setProgrammerConnected()
{
  sysexProgrammerLastResponse = millis();
  if(!sysexProgrammingConnected) {
    programmerSendSettings();
  }
  sysexProgrammingConnected = 1;
}

void checkProgrammerConnected()
{
  programmerSendConnectRequest();
  programmerCheckTimeout();
}

void programmerSendSettings()
{
  Serial.write(0xF0);
  Serial.write(sysexManufacturerId);
  Serial.write(0x40);
  sendMemory();
  Serial.write(0xF7);
}

void setProgrammerRequestConnect()
{
  Serial.write(0xF0);
  Serial.write(sysexManufacturerId);
  Serial.write(65);
  Serial.write(0xF7);
}

void setProgrammerMemorySave()
{
  byte offset = 2;
  for(byte m=4;m<=MEM_MAX;m++) {
    memory[m] = sysexData[offset];
    offset++;
  }
  saveMemory();
  loadMemory();
  programmerSendSettings();
}

void setProgrammerRestoreMemory()
{
  initMemory(1);
  programmerSendSettings();
}

void programmerCheckTimeout()
{
  if(sysexProgrammingConnected && millis() > (sysexProgrammerLastResponse+sysexProgrammerWaitTime)) {
    //programmer timeout!
    sysexProgrammingConnected = 0;
    sysexProgrammingMode      = 0;
  }
  if(sysexProgrammingMode && millis() > (sysexProgrammerLastResponse+sysexProgrammerWaitTime)) {
    //programmer timeout!
    sysexProgrammingConnected = 0;
    sysexProgrammingMode      = 0;
  }
}

void programmerSendConnectRequest()
{
  if(millis() > (sysexProgrammerLastSent+sysexProgrammerCallTime)) {
    Serial.write(0xF0);
    Serial.write(sysexManufacturerId);
    Serial.write(0x7F);
    Serial.write(defaultMemoryMap[MEM_VERSION_FIRST]);
    Serial.write(defaultMemoryMap[MEM_VERSION_SECOND]);
    Serial.write(0xF7);
    sysexProgrammerLastSent = millis();
  }
}

boolean checkSysexChecksum()
{
  byte checksum = sysexData[(sysexPosition - 1)];
  byte checkdata= 0;
  if(checksum) {
    for(int x=2;x!=(sysexPosition - 2);x++) {
      checkdata += sysexData[x];
    }
    if(checkdata & 0x80) checkdata -= 0x7F;
    if(checkdata == checksum) {
      return true;
    }
  }
  return true;
}


void clearSysexBuffer()
{
  for(int x=0;x!=sysexPosition;x++) {
    sysexData[x]= 0;
  }
}

void setMode(byte mode)
{
  memory[MEM_MODE] = mode;
  EEPROM.write(MEM_MODE, memory[MEM_MODE]);
  showSelectedMode();
  switchMode();
}

void sendMode()
{
  Serial.write(0xF0);
  Serial.write(sysexManufacturerId);
  Serial.write(memory[MEM_MODE]);
  Serial.write(0xF7);
}

void setMidioutDelay(byte a,byte b,byte c,byte d)
{
  memory[MEM_MIDIOUT_BIT_DELAY] = a;
  memory[MEM_MIDIOUT_BIT_DELAY+1] = b;
  memory[MEM_MIDIOUT_BYTE_DELAY] = c;
  memory[MEM_MIDIOUT_BYTE_DELAY+1] = d;
  saveMemory();
  changeTasks();
}

void getSysexData()
{
  if(sysexData[0] == 0x69 && checkSysexChecksum()) {
    //sysex good, do stuff
    if(sysexProgrammingMode) {
      if(sysexData[1] == 64 
      && sysexData[2] == defaultMemoryMap[MEM_VERSION_FIRST] 
      && sysexData[3] == defaultMemoryMap[MEM_VERSION_SECOND]) {
        //serial connected to programmer
        setProgrammerRequestConnect();
      }
      if(sysexData[1] == 66 
      && sysexData[2] == defaultMemoryMap[MEM_VERSION_FIRST] 
      && sysexData[3] == defaultMemoryMap[MEM_VERSION_SECOND]) {
        //serial connected to programmer
        setProgrammerConnected();
      }
      if(sysexData[1] == 70) {
        //save states 
        setProgrammerMemorySave();
      }
      if(sysexData[1] == 71) {
        //save states 
        setProgrammerRestoreMemory();
      }
    }
    if(sysexData[1] == 72) {
      sysexProgrammingMode = true;
      sysexProgrammerLastResponse = millis();
      modeProgrammer();
    }
    if(sysexData[1] == 73) {
      sendMode();
    }
    if(sysexData[1] == 74) {
      setMode(sysexData[2]);
    }
    if(sysexData[1] == 75) {
      setMidioutDelay(sysexData[2],sysexData[3],sysexData[4],sysexData[5]);
    }
  }
  clearSysexBuffer();
}



boolean checkForProgrammerSysex(byte sin)
{
    if(sin == 0xF0) {
        sysexReceiveMode = true;
        sysexPosition= 0;
        return true;
    } else if (sin == 0xF7 && sysexReceiveMode) {
        sysexReceiveMode = false;
        getSysexData();
        sysexPosition= 0;
        return true;
    } else if (sysexReceiveMode == true) {
        sysexData[sysexPosition] = sin;
        sysexPosition++;
        if(sysexPosition > longestSysexMessage) {
            clearSysexBuffer();
            sysexReceiveMode = false;
        }
        return true;
    }
    return false;
}


void blinkSelectedLight(int led)
{
      if(!blinkSwitch[led]) digitalWrite(pinLeds[led],HIGH);
      blinkSwitch[led]=1;
      blinkSwitchTime[led]=0;
}
