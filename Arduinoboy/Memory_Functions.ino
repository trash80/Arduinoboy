
boolean checkMemory()
{
  byte chk;
  for(int m=0;m<4;m++){
    chk =  EEPROM.read(MEM_CHECK+m);
    if(chk != defaultMemoryMap[MEM_CHECK+m]) {
      return false;
    }
  }
  return true;
}

void initMemory(boolean reinit)
{
  if(!alwaysUseDefaultSettings) {
    if(reinit || !checkMemory()) {
      for(int m=(MEM_MAX);m>=0;m--){
        EEPROM.write(m,defaultMemoryMap[m]);
      }
    }
    loadMemory();
  } else {
    for(int m=0;m<=MEM_MAX;m++){
      memory[m] = defaultMemoryMap[m];
    }
  }
  changeTasks();
}


void loadMemory()
{
  for(int m=(MEM_MAX);m>=0;m--){
     memory[m] = EEPROM.read(m);
  }
  changeTasks();
}

void printMemory()
{
  for(int m=0;m<=MEM_MAX;m++){
    Serial.println(memory[m],HEX);
  }
}

void sendMemory()
{
  for(int m=0;m<=MEM_MAX;m++){
    Serial.write(memory[m]);
  }
}

void saveMemory()
{
  for(int m=(MEM_MAX-1);m>=0;m--){
    EEPROM.write(m,memory[m]);
  }
  changeTasks();
}

void changeTasks()
{
  midioutByteDelay = memory[MEM_MIDIOUT_BYTE_DELAY] * memory[MEM_MIDIOUT_BYTE_DELAY+1];
  midioutBitDelay = memory[MEM_MIDIOUT_BIT_DELAY] * memory[MEM_MIDIOUT_BIT_DELAY+1];
}
