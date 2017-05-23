## Changelog

### 07/10/16
* New Version 1.3.0a, please download from the [Releases] (https://github.com/trash80/Arduinoboy/releases) if you want the most recent stable version.
* Added Teensy 3.x & LC support. Check the main file for the pin configuration.
* Added USB MIDI support for Teensy
* Updated LSDJ LIVEMAP / SYNCMAP mode. This only works with LSDJ Arduinoboy version 4.8.7 and above. Licensed users can [download it here](http://littlesounddj.com/lsd/latest/full_version/lsdj4_8_7-arduinoboy.zip) Livemap has been removed in favor of stable sync slave mode.

### 06/26/15 
* Project has been moved to GitHub. mGB has been moved to it's own project [Available here](https://github.com/trash80/mGB)

### 12/23/11
* Arduinoboy to version 1.2.3
* Fixed code to work in Arduino 1.0 Software.

### 09/14/11
   * Arduinoboy to version 1.2.2
   * Fixed bug in mGB mode causing the Arduinoboy to respond to other MIDI channels besides the ones assigned to mGB.

### 04/03/11
   * Arduinoboy to version 1.2.0
   * Added EEPROM based settings to all modes which include reassigning MIDI channels in mGB
   * Created software editor for Arduinoboy settings. The file is in the zip and requires the free Max Runtime: http://cycling74.com/downloads/
   * Added 2 new Modes that require a new version of LSDJ. There is a unofficial release of LSDJ which supports these new modes, available here: http://littlesounddj.com/lsd/latest/full_version
      * LIVEMAP / SYNCMAP
       * LIVEMAP - Lsdj will use its own clock, but a incoming midi note will cue midi note # to song row # in live mode.
       * SYNCMAP - Lsdj will sync to incoming MIDI sync, and notes immediately change the song row #.
      * MIDIOUT - LSDJ to MIDIOUT. Each of the 4 gameboy channels send MIDI data on 4 midi channels by the use of effects commands:
       * N - Sends a MIDI Note - Absolute to the value placed in the effect. N00 sends note off, N01-N6F send notes 1 to 112.
       * Q - Sends a MIDI Note relative to the current channel's pitch. The effect value is a offset. so Q0C in PU1 would send a note 1 octave higher than what Pu1 is currently playing. This is useful as a table command to track midi notes as normal notes in the sequencer.
       * X - Sends a MIDI CC - By default in Arduinoboy the high nibble selects a CC#, and the low nibble sends a value [0-F] to [0-127]. This can be changed to allow just 1 midi CC with a range of 00-6F, or 7 CCs with scaled or unscaled values.
       * Y - Sends a program/patch/preset change.

### 02/07/09
* Arduinoboy to version 1.1.0
* Changed Gameboy Pins to the Arduino's "Analog In" pins. From  the old version's 5,6,7 to A0,A1,A2. This allows better more stable behavior. View the source file for changes. And the new "schematic" at the bottom of the page.

### 02/02/09
   * mGB to version 1.3.0
     * Rewrote 90% of code into assembly for much faster performance- especially noticeable on DMG.
     * Changed note behavior. Removed Monophonic note memory to increase performance. 
     * Envelope does not retrigger if the notes overlap and have the same velocity- Good for arpeggios / broken chords. 
     * Note off has a slight delay so immediate retrigged notes don't cause "clicking" effect due to turning off the synth. 
     * Added screen off mode for great signal-to-noise ratio, longer battery life, and better performance on DMG. (To toggle the screen mode hold Select and press A.)
     * Created back-end routine that prioritizes processes for better performance. 
     * Added 8 "noise" shapes to the Wav synth for more interesting effects.
     * Made Wav pitch sweep stable and changed it so it glitches out at values above 8. :D

### 11/05/08
   * New Google group created for Arduinoboy and mGB. http://groups.google.com/group/arduinoboy
   * New Flickr Group. Share your Arduinoboy pics. :) http://flickr.com/groups/arduinoboy
   * mGB to version 1.2.4
    * Fixed small bug with the indicator arrow, it was offset vertically a bit.
    * Fixed bug with unexpected behavior with large PB Ranges
    * PB Range Max is now 48 notes. (hehe)
    * Octave Shift max is now -2/+3 
    * Added some Octave shift logic. If the current note is greater than what the GB can play due to octave shifting, it will select the lower octave note, so no off key notes will play.
    * Added Gameboy Color fast-cpu mode- better performance with newer Gameboys.

### 10/28/08
* mGB to version 1.2.3
    * Added Note markers above synth number, so you can tell if the synth is on. ;)
    * Added PB wheel reset to MIDI panic (Start button)
    * Code more efficient (I'm sure there is still more to do here)
    * nitro2k01 @ http://gameboygenius.8bitcollective.com rewrote my gamejack serial function to make it as fast as possible. THANKS!!
   * Arduinoboy 1.0.5 yet again its just a release to work with mGB 1.2.3 - Everytime the code is sped up on mGB, I remove some delay in Arduinoboy to make the communication faster. This is why you always see a update of Arduinoboy with mGB


### 10/25/08
   * Added Program Change messages to mGB
   * Rewrote MIDI data input for mGB. (Rewrote the function in ASM to make it faster)
   * Added Controller Priority. While changing parameters on the gameboy itself, MIDI messages will not overwrite your changes while your editing them. This is a good live mode feature 
   * Arduinoboy code updated yet again for mGB behavior. Arduinoboy release will now always be included in a zip file inside the mGB zip so you know that the version of Arduinoboy thats included with the mGB archive is the one to use.

### 10/23/08
   * Found & Fixed various bugs in 1.2.0 
   * Changed help text. Made it more clear.

### 10/23/08
   * Added preset load/save memory to mGB. 16 Storage slots for each synth. Recalled via interface or by Midi CC 5 for now, I want to add program change message but would require further rewrites. Check the information below for mGB usage.
   * mGB is now rock solid stable *(It needs Arduinoboy 1.0.3 to work properly)*
   * Changed mGB interface to use less sprites, as a result the look has changed.
   * Arduinoboy 1.0.3 has better behavior for mGB 1.2.0 but should also work better for old mGB versions as well.

### 10/20/08
   * Added interface to mGB. 
   * Changed WAV CC Parameters
   * Arduinoboy 1.0.2 has better behavior for mGB 1.1.0
