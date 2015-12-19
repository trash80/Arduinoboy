/*
  attiny midi clock to cv clock converter
 - works for gb clock - nanoloop
 - works for korg cv snyc - volca, monotribe

 ************************

PPQN (Pulses Per Quarter Note, also known as PPQ, Pulses Per Quarter) is unit
used by devices to sync. Different devices are using different values

 Korg Volca clock uses 2 ppqn
 midi clock uses 24 ppqn
 gameboy uses  12 ppqn
 din sync uses 24 or 48 ppqn

 ************************

 TODO:
 - din cync 24 / 48
 - cv clock(din sync) to midi clock converter

 */
//#include <SoftwareSerial.h>



//SoftwareSerial Serial(6, 0);
//Serial Serial;

unsigned char divider = 6;

unsigned char multiplier = 2; // use 12 for converting from volca to midi

boolean cvState;

unsigned char cvPin = 1;
// unsigned char speedPin = 4;

int speedPin = A0;
int led = 8;

unsigned char dinCVPin = 3;
unsigned char startPin = 3;

boolean doubleClock;

long clockTime, subTime, lastTime, quarterClockTime;
void setup()
{
    // Open serial communications and wait for port to open:
    // Serial.begin(31250);
    pinMode(cvPin, OUTPUT);
    pinMode(speedPin, INPUT_PULLUP);
    pinMode(led, OUTPUT);

    //  pinMode(startPin,OUTPUT);
}


int counter;
boolean render = false;

boolean lastInClock, inClock;
boolean firstClock;
void loop()
{
    // divider=6; // for volca
    //  multiplier=2; // for midi // for converting from volca to midi use 12


    lastInClock = inClock;
    inClock = digitalRead(speedPin);
    if (inClock && !lastInClock)
    {

        if (!render){
          Serial.write(0xFA); //midi start
          digitalWrite(led, 1);
          delay(100);
          digitalWrite(led, 0);
          delay(100);
        }
        render = true;

        counter++;
        if (counter >= divider) cvState = true, counter = 0;
        else cvState = false;
        // cvState=!cvState;
        if (render) digitalWrite(cvPin, cvState);

        long time = micros();
        clockTime = time - lastTime;
        quarterClockTime = clockTime / multiplier;
        subTime = time;
        lastTime = time;
        // cvState=true;
        // digitalWrite(cvPin,HIGH);
        if (firstClock) Serial.write(0xF8);
        Serial.write(0xF8); //clock
        firstClock = true;
        subTime = time;

    }

    long _time = micros();

    if ((_time - subTime) >= 1000000) // timeout time before sends the stop
    {
        if (render) Serial.write(0xFC); // midi stop
        render = false;
    }
    if (firstClock)
    {
        if ((_time - subTime) >= quarterClockTime) //100 slows the in between pulse a bit (by 1ms) to make sure it wont send more midi clock
        {
            subTime = _time;

            if (render)
            {
                //  cvState=!cvState;
                if (firstClock){
                   Serial.write(0xF8);
                   firstClock = false; //clock
                }



                //if(incomingByte==){
                // digitalWrite(cvPin,cvState);
                // }
            }
        }
    }
}
