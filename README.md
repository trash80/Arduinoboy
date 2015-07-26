![ScreenShot](http://trash80.net/arduinoboy/aboy1_2_0.jpg)

# Arduinoboy
Official ArduinoBoy Repository for serial MIDI communication to the Nintendo Gameboy.

## About 
Arduinoboy is software for the [http://arduino.cc Arduino hardware platform] that allows serial communication (MIDI) to the Nintendo Gameboy for music applications such as [http://littlesounddj.com LittleSoundDJ], [http://www.nanoloop.com/ Nanoloop.], and mGB (Featured here)

## News
 * 12/21/12
   * mGB to version 1.3.3 : End of the world release. ;)
     * Fixed a bug with the new pitchbend resolution
     * Optimized some of the pitchbend routine
 * 12/20/12
   * mGB to version 1.3.2
     * Increased pitchbend resolution
 * 12/19/12
   * mGB to version 1.3.1
     * Fixed PU1 Envelope retrigger bug. 
 * 12/23/11
   * Arduinoboy to version 1.2.3
     * Fixed code to work in Arduino 1.0 Software.
 * 09/14/11
   * Arduinoboy to version 1.2.2
     * Fixed bug in mGB mode causing the Arduinoboy to respond to other MIDI channels besides the ones assigned to mGB.
 * 04/03/11
   * Arduinoboy to version 1.2.0
     * Added EEPROM based settings to all modes which include reassigning MIDI channels in mGB
     * Created software editor for Arduinoboy settings. The file is in the zip and requires the free Max Runtime: http://cycling74.com/downloads/
     * Added 2 new Modes that require a new version of LSDJ. There is a unofficial release of LSDJ which supports these new modes, available here: http://littlesounddj.com/lsd/latest/full_version/lsdj4_0_8-unofficial-arduinoboy.zip 
      * LIVEMAP / SYNCMAP
       * LIVEMAP - Lsdj will use its own clock, but a incoming midi note will cue midi note # to song row # in live mode.
       * SYNCMAP - Lsdj will sync to incoming MIDI sync, and notes immediately change the song row #.
      * MIDIOUT - LSDJ to MIDIOUT. Each of the 4 gameboy channels send MIDI data on 4 midi channels by the use of effects commands:
       * N - Sends a MIDI Note - Absolute to the value placed in the effect. N00 sends note off, N01-N6F send notes 1 to 112.
       * Q - Sends a MIDI Note relative to the current channel's pitch. The effect value is a offset. so Q0C in PU1 would send a note 1 octave higher than what Pu1 is currently playing. This is useful as a table command to track midi notes as normal notes in the sequencer.
       * X - Sends a MIDI CC - By default in Arduinoboy the high nibble selects a CC#, and the low nibble sends a value [0-F] to [0-127]. This can be changed to allow just 1 midi CC with a range of 00-6F, or 7 CCs with scaled or unscaled values.
       * Y - Sends a program/patch/preset change.

 * 02/07/09
   * Arduinoboy to version 1.1.0
     * Changed Gameboy Pins to the Arduino's "Analog In" pins. From  the old version's 5,6,7 to A0,A1,A2. This allows better more stable behavior. View the source file for changes. And the new "schematic" at the bottom of the page.

 * 02/02/09
   * mGB to version 1.3.0
     * Rewrote 90% of code into assembly for much faster performance- especially noticeable on DMG.
     * Changed note behavior. Removed Monophonic note memory to increase performance. 
     * Envelope does not retrigger if the notes overlap and have the same velocity- Good for arpeggios / broken chords. 
     * Note off has a slight delay so immediate retrigged notes don't cause "clicking" effect due to turning off the synth. 
     * Added screen off mode for great signal-to-noise ratio, longer battery life, and better performance on DMG. (To toggle the screen mode hold Select and press A.)
     * Created back-end routine that prioritizes processes for better performance. 
     * Added 8 "noise" shapes to the Wav synth for more interesting effects.
     * Made Wav pitch sweep stable and changed it so it glitches out at values above 8. :D

 * 11/05/08
   * New Google group created for Arduinoboy and mGB. [http://groups.google.com/group/arduinoboy]
   * New Flickr Group. Share your Arduinoboy pics. :) [http://flickr.com/groups/arduinoboy]
   * mGB to version 1.2.4
    * Fixed small bug with the indicator arrow, it was offset vertically a bit.
    * Fixed bug with unexpected behavior with large PB Ranges
    * PB Range Max is now 48 notes. (hehe)
    * Octave Shift max is now -2/+3 
    * Added some Octave shift logic. If the current note is greater than what the GB can play due to octave shifting, it will select the lower octave note, so no off key notes will play.
    * Added Gameboy Color fast-cpu mode- better performance with newer Gameboys.
 * 10/28/08
   * mGB to version 1.2.3
    * Added Note markers above synth number, so you can tell if the synth is on. ;)
    * Added PB wheel reset to MIDI panic (Start button)
    * Code more efficient (I'm sure there is still more to do here)
    * nitro2k01 @ http://gameboygenius.8bitcollective.com rewrote my gamejack serial function to make it as fast as possible. THANKS!!
   * Arduinoboy 1.0.5 yet again its just a release to work with mGB 1.2.3 - Everytime the code is sped up on mGB, I remove some delay in Arduinoboy to make the communication faster. This is why you always see a update of Arduinoboy with mGB


 * 10/25/08
   * Added Program Change messages to mGB
   * Rewrote MIDI data input for mGB. (Rewrote the function in ASM to make it faster)
   * Added Controller Priority. While changing parameters on the gameboy itself, MIDI messages will not overwrite your changes while your editing them. This is a good live mode feature 
   * Arduinoboy code updated yet again for mGB behavior. Arduinoboy release will now always be included in a zip file inside the mGB zip so you know that the version of Arduinoboy thats included with the mGB archive is the one to use.

 * 10/23/08
   * Found & Fixed various bugs in 1.2.0 
   * Changed help text. Made it more clear.

 * 10/23/08
   * Added preset load/save memory to mGB. 16 Storage slots for each synth. Recalled via interface or by Midi CC 5 for now, I want to add program change message but would require further rewrites. Check the information below for mGB usage.
   * mGB is now rock solid stable *(It needs Arduinoboy 1.0.3 to work properly)*
   * Changed mGB interface to use less sprites, as a result the look has changed.
   * Arduinoboy 1.0.3 has better behavior for mGB 1.2.0 but should also work better for old mGB versions as well.

 * 10/20/08
   * Added interface to mGB. 
   * Changed WAV CC Parameters
   * Arduinoboy 1.0.2 has better behavior for mGB 1.1.0

## Video Demos

  * [http://youtube.com/watch?v=TnLUuvc78XY Keyboard Mode Test]
  * [http://youtube.com/watch?v=iVmhy-Lo7BI Sync Demos]
  * [http://youtube.com/watch?v=VwrMuOA0VnY Arduino inside of Gameboy DMG]
  * [http://vimeo.com/1853931 mGB Example & Arduinoboy build into a DMG]
  * [http://www.youtube.com/watch?v=HAU9MzZ2qeE PDF explores mGB with a MIDI guitar]

## Current Features
  * Affordable and easily accessible parts for assembly.
  * Accurate MIDI Sync, Start and Stop commands.
  * Push Button to select the sync/state mode (7 modes available)
   # LSDJ as MIDI Slave Sync with sync effects and midi note transport control. Also Note value to LSDJ song position row offset on Song Start.
   # LSDJ as MIDI Master Sync. Send Midi sync with LSDJ, LSDJ also sends a Midi Note on message that corresponds to the song row number
   # LSDJ PC Keyboard mode. with the first octave controlling M-U-T-E, Cursor control (LSDJ Live mode only), Table selection and table cue.
   # MIDI to Nanoloop sync
   # Full MIDI with mGB (Details below)
   # LSDJ LIVE MAP ... incoming MIDI notes cue LSDJ row numbers, requires custom LSDJ version on the LSDJ site.
   # LSDJ MIDIOUT ... sends MIDI out from LSDJ, requires custom LSDJ version on the LSDJ site.
  * Midi Out Doubles as a Midi Thru
  * "Filtering" data for only sync messages, no dedicated MIDI line required.
  * Tested and works with DMG (Original), Gameboy Color, and Advance/SP.
  * Can be powered by the gamelink port.
  * USB upgradeable via Arduino.

  * mGB Cartridge Mode: Full MIDI in support across all Gameboy Channels, including a unique "poly" mode. Tested and works with DMG01, GBC, GBA, GB AdvanceSP

## Future Features & wishlist
  * Build instructions, and a Arduino Shield

## Program Information
 * LSDJ Slave Mode Midi Note Effects:
  * 48 - C-2 Sends a Sequencer Start Command
  * 49 - C#2 Sends a Sequencer Stop Command
  * 50 - D-2 Toggles Normal Tempo
  * 51 - D#2 Toggles 1/2 Tempo
  * 52 - E-2 Toggles 1/4 Tempo
  * 53 - F-2 Toggles 1/8 Tempo
 * LSDJ Keyboard Mode:
  * 36 - C-1 Mute Pu1 Off/On
  * 37 - C#1 Mute Pu2 Off/On
  * 38 - D-1 Mute Wav Off/On
  * 39 - D#1 Mute Noi Off/On
  * 40 - E-1 Livemode Cue Sequence
  * 41 - F-1 Livemode Cursor Up
  * 42 - F#1 Livemode Cursor Down
  * 43 - G-1 Livemode Cursor Left
  * 44 - G#1 Livemode Cursor Right
  * 45 - A-1 Table Up
  * 46 - A#1 Table Down
  * 47 - B-1 Cue Table
  * 48 - C-2 to C-8 Notes!
  * Prgram Change to select from instrument table
 * Default Midi channel is 16. You can change in the top of the main source file in the archive. 

## About mGB
![ScreenShot](http://trash80.net/arduinoboy/mGB1_2_0.png)

mGB is a Gameboy cartridge program (You need a Flash Cart and Transfer hardware) That enables the Gameboy to act as a full MIDI supported sound module. It works with the old DMG Gameboy as well as GBC/GBA.

Current Source code available upon request. (Its a bit of a mess without comments. ;)

## mGB Change Log
 * Feb 2 2009 1.3.0
   * Rewrote 90% of code into assembly for much faster performance- especially noticeable on DMG.
   * Changed note behavior. Removed Monophonic note memory to increase performance. 
   * Envelope does not retrigger if the notes overlap and have the same velocity- Good for arpeggios / broken chords. 
   * Note off has a slight delay so immediate retrigged notes don't cause "clicking" effect due to turning off the synth. 
   * Added screen off mode for great signal-to-noise ratio, longer battery life, and better performance on DMG. (To toggle the screen mode hold Select and press A.)
   * Created back-end routine that prioritizes processes for better performance. 
   * Added 8 "noise" shapes to the Wav synth for more interesting effects.
   * Made Wav pitch sweep stable and changed it so it glitches out at values above 8. :D
 * Nov 5 2008 Version: 1.2.4
  * Fixed small bug with the indicator arrow, it was offset vertically a bit.
  * Fixed bug with unexpected behavior with large PB Ranges
  * PB Range Max is now 48 notes. (hehe)
  * Octave Shift max is now -2/+3 
  * Added some Octave shift logic. If the current note is greater than what the GB can play due to octave shifting, it will select the lower octave note, so no off key notes will play.
  * Added Gameboy Color fast-cpu mode- better performance with newer Gameboys.
 * Oct 28 2008 - Version: 1.2.3
  * Added Note markers above synth number, so you can tell if the synth is on. ;)
  * Added PB wheel reset to MIDI panic (Start button)
  * Code more efficient (I'm sure there is still more to do here)
  * nitro2k01 @ http://gameboygenius.8bitcollective.com rewrote my gamejack serial function to make it as fast as possible. THANKS!!
 * Oct 25 2008 - Version: 1.2.2
  * Added Program Change messages to mGB
  * Rewrote MIDI data input for mGB. (Rewrote the function in ASM to make it faster)
  * Added Controller Priority. While changing parameters on the gameboy itself, MIDI messages will not overwrite your changes while your editing them. This is a good live mode feature 
 * Oct 23 2008 - Version: 1.2.1
  * Found & Fixed various bugs in 1.2.0 
  * Changed help text. Made it more clear.
 * Oct 23 2008 - Version: 1.2.0
  * Change interface a bit
  * Added presets
  * Optimized code
 * Oct 20 2008 - Version: 1.1.0
  * Added Interface
  * Changed Wav CCs Around to make more consistent with the Pu Synths.
 * Oct 4 2008 - Version: 0.1.2
  * Fixed bug with Wav Synth hanging after sequencer stop. 
  * Fixed bug with Wav Synth not resetting monophonic keyboard note triggers

## mGB Button shortcuts
 * Start: MIDI Panic
 * Select + Dpad: Select multiple synths for editing.
 * Select + A: Toggles the screen on or off, better battery life, less noise, and faster response.
 * Select + B: Copys all parameters on screen while cursor is not on preset number.
 * B: Pastes all parameters while cursor is not on preset number
 * A + Dpad: Change parameter value 
 * To load/save presets, put the cursor on the "PRESET" number, and hit B for load, Select+B to save

## mGB MIDI Implementation
Note: the name and number at the bottom left of the screen indicates the midi CC of the selected parameter.

 * PU1 - MIDI CH1
  * Program Change: 1 to 15
  * PB: Pitch bend - up to +/- 12
  * cc1: Pulse width - 0,32,64,127
  * cc2: Envelope mode - 0 to 127, 16 possible steps
  * cc3: Pitch sweep
  * cc4: Pitchbend Range
  * cc5: Load Preset
  * cc10: Pan
  * cc64: Sustain- Turns off note off. <64 = off, >63 = on

 * PU2 - MIDI CH2
  * Program Change: 1 to 15
  * PB: Pitch bend - up to +/- 12
  * cc1: Pulse width - 0,32,64,127
  * cc2: Envelope mode - 0 to 127, 16 possible steps
  * cc4: Pitchbend Range
  * cc5: Load Preset
  * cc10: Pan
  * cc64: Sustain- Turns off note off. <64 = off, >63 = on

 * WAV - MIDI CH3
  * Program Change: 1 to 15
  * PB: pitch bend - up to +/- 12
  * cc1: shape select : 16 possible on a 0 to 127 range
  * cc2: shape offset : 32 possible on a 0 to 127 range
  * cc3: Pitch Sweep speed. 0=Off, 1-127 speed.
  * cc4: Pitchbend Range
  * cc5: Load Preset
  * cc10: pan
  * cc64: Sustain- turns off note off. <64 = off, >63 = on

 * NOISE - MIDI CH4
  * Program Change: 1 to 15
  * PB: pitch bend +/-24
  * cc2: envelope mode - 0 to 127, 16 possible steps
  * cc5: Load Preset
  * cc10: pan
  * cc64: (sustain) turns off note off. <64 = off, >63 = on

 * POLY MODE - MIDI CH5 - Plays Pu1/Pu2 and Wav in poly
  * Program Change: 1 to 15
  * PB: pitch bend +/-2
  * cc1: See cc1
  * cc5: Load Preset
  * cc10: pan
  * cc64: (sustain) turns off note off. <64 = off, >63 = on

## How To

(Coming soon)
[http://flickr.com/photos/trash80/2316803175/in/set-72157604068871573/ Check out the flickr set.]

[http://flickr.com/photos/trash80/sets/72157604068871573/ http://farm3.static.flickr.com/2229/2316803721_c22f9c2387.jpg]

http://trash80.net/arduinoboy/arduinoboy_schematic_1_1_0.png

[http://trash80.net/junkfood/arduinoboy/arduinoboy-schem-v.0.9.8-r1.png Old version pre 1.1.0 Here ]


## Thanks To
  * [http://arduino.cc Arduino] (and the [http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1187962258 MIDI IN forum thread])
  * [http://gameboygenius.8bitcollective.com nitro2k01] for ASM help with mGB 
  * GWEM and his [http://www.preromanbritain.com/gwem/lsdj_midi/g33k.html g33k page]
  * [http://wayfar.net Midines] (thanks for the help x|k!)
  * [http://www.firestarter-music.de firestARTer] for help with keyboard & Midi handling information. 
  * [http://gieskes.nl Gijs Gieskes] Found source code that gave insight into Nanoloop sync
  * [http://littlesounddj.com Little Sound DJ]
  * http://devrs.com/gb (Madcatz PC link port for gb serial specs)
  * [http://8bitpeoples.com 8bitpeoples]
