/*
 * Ym2149Synth
 * http://trash80.com
 * Copyright (c) 2016 Timothy Lamb
 *
 * This file is part of Ym2149Synth.
 *
 * Ym2149Synth is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Ym2149Synth is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/*
 * Pin Mapping:
 * @TODO This code only works with Teensy 3.x due to hardcoding the
 * pin/port mapping to allow parallel communcation to the YM2149F
 *
 *           -------_____-------
 *      GND -| 1            40 |- +5v
 *      N/C -| 2            39 |- TEST1
 *      A.A -| 3      Y     38 |- A.C
 *      A.B -| 4      M     37 |- DA0
 *      N/C -| 5      2     36 |- DA1
 *      PB7 -| 6      1     35 |- DA2
 *      PB6 -| 7      4     34 |- DA3
 *      PB5 -| 8      9     33 |- DA4
 *      PB4 -| 9      F     32 |- DA5
 *      PB3 -| 10           31 |- DA6
 *      PB2 -| 11           30 |- DA7
 *      PB1 -| 12           29 |- BC1
 *      PB0 -| 13           28 |- BC2
 *      PA7 -| 14           27 |- BDIR
 *      PA6 -| 15           26 |- SEL
 *      PA5 -| 16           25 |- A8
 *      PA4 -| 17           24 |- A9
 *      PA3 -| 18           23 |- RESET
 *      PA2 -| 19           22 |- CLOCK
 *      PA1 -| 20           21 |- PA0
 *           ```````````````````
 *
 *       Teensy Pin: 2 -> YM 37
 *       Teensy Pin: 14 -> YM 36
 *       Teensy Pin: 7 -> YM 35
 *       Teensy Pin: 8 -> YM 34
 *       Teensy Pin: 6 -> YM 33
 *       Teensy Pin: 20 -> YM 32
 *       Teensy Pin: 21 -> YM 31
 *       Teensy Pin: 5 -> YM 30
 *       Teensy Pin: 15 -> YM 27 (BDIR)
 *       Teensy Pin: 22 -> YM 29 BC1
 *       Teensy Pin: 23 -> YM 25 A8
 *
 *       Audio out Provided by YM pins 3,4 & 38
 *       A 2.000MHZ crystal is required for YM2149 on pin 22
 */

#include "YM2149.h"

//@TODO - Don't hardcode these pins here
static const uint8_t YM2149_PINMAP[11] = {23,22,21,20,15,14,2,5,6,7,8};

/**
    Initializes ports and sets default values
*/
void YM2149Class::begin()
{
    for(int i=0;i<11;i++) pinMode(YM2149_PINMAP[i],OUTPUT);
    // Set YM Chip communcation to Inactive
    GPIOC_PDOR  = (GPIOC_PDOR & B11111000) | B00000100;

    levelValue[0] = 0;
    levelValue[1] = 0;
    levelValue[2] = 0;
    mixerValue = B00111000;

    delay(100);
}

/**
    Send register value to YM

    @param address The register address
    @param value The register's value
*/
void YM2149Class::write(uint8_t address, uint8_t value)
{
    // Set output pins to the register address
    GPIOD_PDOR  = (GPIOD_PDOR & B00000000) | (address & 0x0f);
    // Set YM BDIR & BC1 to Write mode
    GPIOC_PDOR  = (GPIOC_PDOR & B11111100) | B00000011;

    // Wait between address and value modes
    delayMicroseconds(1);

    // Set YM BDIR & BC1 to Inactive mode
    GPIOC_PDOR &= B11111100;
    // Set output pins to the register value
    GPIOD_PDOR  = (GPIOD_PDOR & B00000000) | value;
    // Set YM BDIR & BC1 to Write mode
    GPIOC_PDOR  = (GPIOC_PDOR & B11111100) | B00000001;

    // Wait before going inactive
    delayMicroseconds(1);

    // Set YM BDIR & BC1 to Inactive mode
    GPIOC_PDOR &= B11111100;
}

/**
    Set the YM's GPIO ports A and B to input or output mode

    @param portA 0 = input mode, 1 = output mode for YM pins 14 to 21
    @param portB 0 = input mode, 1 = output mode for YM pins 6 to 13
*/
void YM2149Class::setPortIO(bool portA, bool portB)
{
    uint8_t portSettings = ((uint8_t)portB)<<7 | ((uint8_t)portA)<<6;

    // The register for port mode is the same as the "mixer" for the squarewave outputs
    mixerValue = (mixerValue & B00111111) | portSettings;
    write(REG_MIXER, mixerValue);
}

/**
    Set a YM GPIO pin HIGH or LOW on Ports A and B.

    @param pin The pin to write to, pin number is mapped 0-F as A0 to B7
    @param value 0 = LOW, 1 = HIGH
*/
void YM2149Class::setPin(uint8_t pin, bool value)
{
    uint8_t mask = 1;
    pin &= 0xF;

    if(pin & 0x8) {
        pin -= 8;
        portBValue = (portBValue ^ (mask<<=pin)) | (value<<=pin);
        write(REG_DATAPORT_B, portBValue);
    } else {
        portAValue = (portAValue ^ (mask<<=pin)) | (value<<=pin);
        write(REG_DATAPORT_A, portAValue);
    }
}

/**
    Get a YM GPIO pin's state
    @TODO this is not implemented
    @param pin The pin to write to, pin number is mapped 0-F as A0 to B7
    @return the pin state 0 or 1
*/
uint8_t YM2149Class::getPin(uint8_t pin)
{
    //@TODO get values from port A and port B
    pin &= 0xF;
    if(pin & 0x8) {

    } else {

    }
    return 0;
}

/**
    Set all pins from YM GPIO port A or B
    @param port The port 0=A, 1=B
    @param value The value for all 8 pins
*/
void YM2149Class::setPort(bool port, uint8_t value)
{
    if(port) {
        write(REG_DATAPORT_B,value);
    } else {
        write(REG_DATAPORT_A,value);
    }
}

/**
    Get all pin states from a YM GPIO port
    @TODO this is not implemented
    @param port The port 0=A, 1=B
    @return the port state 0x00 to 0xFF
*/
uint8_t YM2149Class::getPort(bool port)
{
    //@TODO get values from port A and port B
    if(port) {

    } else {

    }
    return 0;
}

/**
    Set a voice frequency (A, B, C, Noi, or Env) in native YM frequency units.
    @param voice The voice to apply the frequency to (0:A, 1:B, 2:C, 3:Noise, 4:Env)
    @param value The value in native YM frequency units. hz = 2000/16 (ABC), hz = 2000/256 (Env), hz = ??? profit in noise
*/
void YM2149Class::setTone(uint8_t voice, uint16_t value)
{
    switch(voice) {
        case 0:
            write(REG_A_FREQ, (value&0xFF));
            write(REG_A_FREQ+1, (value>>8)&0x0F);
        break;
        case 1:
            write(REG_B_FREQ, (value&0xFF));
            write(REG_B_FREQ+1, (value>>8)&0x0F);
        break;
        case 2:
            write(REG_C_FREQ, (value&0xFF));
            write(REG_C_FREQ+1, (value>>8)&0x0F);
        break;
        case 3:
            write(REG_NOISE_FREQ, (value&0x1F));
        break;
        case 4:
            value >>= 4;
            write(REG_ENV_FREQ, (value&0xFF));
            write(REG_ENV_FREQ+1, (value>>8)&0x0F);
        break;
    }
}

/**
    Set a voice frequency by MIDI note number (A, B, C, Noi, or Env)
    @param voice The voice to apply the frequency to (0:A, 1:B, 2:C, 3:Noise, 4:Env)
    @param value Float number representing the note number from 0 to 127
*/
void YM2149Class::setNote(uint8_t voice, float value)
{
    uint16_t f;

    if(voice != 3) {
        f = (uint16_t) ((2000000.0f/((pow(2,((((float)value) - 69)/12)) * 440.0f)))/16);
    } else {
        f = 31 - (value/4);
    }

    setTone(voice, f);
}

/**
    Set a voice frequency by HZ (A, B, C, Noi, or Env)
    @param voice The voice to apply the frequency to (0:A, 1:B, 2:C, 3:Noise, 4:Env)
    @param value Frequency in HZ
*/
void YM2149Class::setFreq(uint8_t voice, uint32_t freq)
{
    uint16_t d = 16;
    if(voice == 4) {
        d = 256;
    }
    uint16_t f = (uint16_t) ((2000000.0f/freq)/d);
    setTone(voice, f);
}

/**
    Set a voice's volume (A, B, C)
    @param voice The voice to apply the volume to (0:A, 1:B, 2:C)
    @param value volume 0 to 15
*/
void YM2149Class::setVolume(uint8_t voice, uint8_t value)
{
    if(voice > 2) return;
    uint8_t * state = &levelValue[voice];

    value &= 0b00001111;
    *(state) = (*(state) & 0b00010000) | value;
    write(REG_A_LEVEL+voice, *(state));
}

/**
    Assign noise to a voice's channel (A, B, C)
    @param voice The voice to apply the volume to (0:A, 1:B, 2:C)
    @param value Noise assignment (0:Voice only, 1:Noise only, 2:Mix both)
*/
void YM2149Class::setNoise(uint8_t voice, uint8_t value)
{
    if(voice > 2) return;

    switch(value) {
        case 1:
            value = 0b00000001;
        break;
        case 2:
            value = 0b00001001;
        break;
        default:
            value = 0b00001000;
        break;
    }

    value <<= voice;

    switch(voice) {
        case 0:
            mixerValue = (mixerValue & 0b11110110)|value;
        break;
        case 1:
            mixerValue = (mixerValue & 0b11101101)|value;
        break;
        default:
            mixerValue = (mixerValue & 0b11011011)|value;
        break;
    }
    write(REG_MIXER, mixerValue);

}

/**
    Assign the envelope to a voice's channel (A, B, C)
    @param voice The voice to apply the volume to (0:A, 1:B, 2:C)
    @param value Boolean value. (0:Off, 1:On)
*/
void YM2149Class::setEnv(uint8_t voice, uint8_t value)
{
    if(voice > 2) return;
    uint8_t * state = &levelValue[voice];

    value &= 0b00000001;
    value <<= 4;
    *(state) = (*(state) & 0b00001111) | value;
    write(REG_A_LEVEL+voice, *(state));
}

/**
    Set the envelope shape:
    0,0,0,0 : \_______
    0,1,0,0 : /_______
    1,0,0,0 : \\\\\\\\
    1,0,0,1 : \_______
    1,0,1,0 : \/\/\/\/
    1,0,1,1 : \```````
    1,1,0,0 : ////////
    1,1,0,1 : /```````
    1,1,1,0 : /\/\/\/\
    1,1,1,1 : /_______
    @param continuous Boolean value. (0:Off, 1:On)
    @param attack Boolean value. Low to High slope.(0:Off, 1:On)
    @param alt Boolean value. (0:Off, 1:On)
    @param hold Boolean value. (0:Off, 1:On)
*/
void YM2149Class::setEnvShape(uint8_t continuous, uint8_t attack, uint8_t alt, uint8_t hold)
{
    continuous &= 0b00000001;
    attack     &= 0b00000001;
    alt        &= 0b00000001;
    hold       &= 0b00000001;
    write(REG_ENV_SHAPE, (continuous<<3)|(attack<<2)|(alt<<1)|(hold));
}

/**
    Mute all channels and reset Mixer
*/
void YM2149Class::mute()
{
    write(REG_A_LEVEL,B00000000); //vol 0
    write(REG_B_LEVEL,B00000000); //vol 0
    write(REG_C_LEVEL,B00000000); //vol 0
    levelValue[0] = 0;
    levelValue[1] = 0;
    levelValue[2] = 0;
    mixerValue = 0b11111000;
}
