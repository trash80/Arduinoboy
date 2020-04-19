# Arduinoboy
Official ArduinoBoy Repository for serial MIDI communication to the Nintendo Gameboy.

![ScreenShot](http://trash80.net/arduinoboy/aboy1_2_0.jpg)

## About 
Arduinoboy is software for the [Arduino hardware platform](http://arduino.cc) that allows serial communication (MIDI) to the Nintendo Gameboy for music applications such as [LittleSoundDJ](http://littlesounddj.com), [Nanoloop.](http://www.nanoloop.com/), and [mGB](https://github.com/trash80/mGB)


## Current Features
* Affordable and easily accessible parts for assembly.
* Accurate MIDI Sync, Start and Stop commands.
* Push Button selector sets the sync/state modes [(7 modes available)](#modes-details)
* [mGB](https://github.com/trash80/mGB)
 Mode: Full MIDI in support across all Gameboy Channels, including a unique "poly" mode allows you to play your Game Boy like a synthesizer. 
* Midi Out Doubles as a Midi Thru
* "Filtering" data for only sync messages, no dedicated MIDI line required.
* Can be powered by the Game Boy's gamelink port.
* USB upgradeable via Arduino.
* Midi settings configurable using a Mac/PC editor built in Max.
* Tested and works with DMG (Original), Gameboy Color, and Advance/SP.

## Modes Details
#### Mode 1 - LSDJ as MIDI Slave Sync
Slave your Game Boy running [LittleSoundDJ](http://littlesounddj.com) to your midi sequencer or Digital audio workstation.  

You can send the arduinoboy midi notes to change sync resolution and start/stop the LSDJ sequencer.  

_LSDJ Slave Mode Midi Note Effects:_

* 48 - `C-2` Sends a Sequencer Start Command
* 49 - `C#2` Sends a Sequencer Stop Command
* 50 - `D-2` Toggles Normal Tempo 
* 51 - `D#2` Toggles 1/2 Tempo
* 52 - `E-2` Toggles 1/4 Tempo
* 53 - `F-2` Toggles 1/8 Tempo

Higher note values than these map LSDJ song position row offset on a Song Start.

In LSDJ the `sync` mode should be set to `Slave`
 
#### Mode 2 LSDJ as MIDI Master Sync. 

Send Midi sync with LSDJ as a midi clock master, LSDJ also sends a Midi Note on message that corresponds to the song row number on play.

In LSDJ the `sync` mode should be set to `Master`


#### Mode 3 LSDJ PC Keyboard mode.
This mode emulates the [PC Keyboard Mode](http://littlesounddj.wikia.com/wiki/PC_Keyboard_Interface) built into LSDJ, allowing you to control the following aspects of LSDJ: 

Features:

* The first octave controls M-U-T-E, 
* Cursor control (LSDJ Live mode only), 
* Table selection
* Table cue.

_PC Keyboard mode midi note map_

* 36 - `C-1` Mute Pu1 Off/On
* 37 - `C#1` Mute Pu2 Off/On
* 38 - `D-1` Mute Wav Off/On
* 39 - `D#1` Mute Noi Off/On
* 40 - `E-1` Livemode Cue Sequence
* 41 - `F-1` Livemode Cursor Up
* 42 - `F#1` Livemode Cursor Down
* 43 - `G-1` Livemode Cursor Left
* 44 - `G#1` Live mode Cursor Right
* 45 - `A-1` Table Up
* 46 - `A#1` Table Down
* 47 - `B-1` Cue Table
* 48+ - Notes from this note up will accept midi in from an external keyboard or sequencer and allow you to play the notes`C-2 to C-8`.  
* Midi Program Change messages will select from instrument table
* Default Midi channel is 16. You can set this in the top of the main source file in the archive, or via the [Max Pat editor](#max).

In LSDJ the `sync` mode should be set to `Keyboard`

#### Mode 4 MIDI to Nanoloop sync
Sync [Nanoloop.](http://www.nanoloop.com/) to external midi clock signals sent to the midi in.

In Nanoloop, the sync mode should be set to `slave`.

#### Mode 5 Full MIDI with mGB
[mGB](https://github.com/trash80/mGB) is a Gameboy cartridge program (You need a Flash Cart and Transfer hardware) That enables the Gameboy to act as a MIDI supported sound module that allows full control of the Game Boy sound hardware. 

It works with the old DMG Gameboy as well as GBC/GBA.

#### Mode 6 LSDJ MIDIMAP 
Lsdj will sync to incoming MIDI sync, and incoming MIDI notes are mapped to LSDJ's song row #. The currently selected row's MIDI note is displayed on the top right of the LSDJ screen, and incoming MIDI notes will also display the relative song row number in the same location.

In LSDJ the `sync` mode should be set to `MI.MAP`. 

*This requires a special version of LSDJ, which can be found in your account on the [LSDJ website](http://littlesounddj.com/lsd/latest/full_version/).*

#### Mode 7 LSDJ MIDIOUT
Each of the 4 gameboy channels send MIDI data on 4 midi channels by the use of effects commands:

* `Nxx` - Sends a MIDI Note - Absolute to the value placed in the effect. N00 sends note off, `N01`-`N6F` send midi notes 1 to 112.
* `Qxx` - Sends a [MIDI Note](http://www.electronics.dit.ie/staff/tscarff/Music_technology/midi/midi_note_numbers_for_octaves.htm) relative to the current channel's pitch. The effect value is a offset. so `Q0C` in `PU1` would send a note 1 octave higher than what `PU1` is currently playing. This is useful as a table command to track midi notes as normal notes in the sequencer.
* `Xxx` - Sends a MIDI CC - By default in Arduinoboy the high nibble selects a CC#, and the low nibble sends a value `0-F` to `0-127`. This can be changed to allow just 1 midi CC with a range of `00`-`6F`, or 7 CCs with scaled or unscaled values.
* `Yxx` - Sends a program/patch/preset change.

By default each channel of LSDJ is mapped to midi channels 1-4. For example note commands from PU1 will be sent to midi channel 1. 

In LSDJ the `sync` mode should be set to `Midiout`. 

*This requires a special version of LSDJ, which can be found in your account on the [LSDJ website](http://littlesounddj.com/lsd/latest/full_version/).*


## Max Editor
![Editor gui](Editor/editor.png)
[The Arduinoboy Editor for Max](https://github.com/trash80/Arduinoboy/tree/master/Editor) for PC/OSX machines is a gui editor that allows you to edit the various global midi settings of your arduinoboy without editing or flashing code, over midi. It used to required the now deprecated Max Runtime, but you can also run it using a demo of [Cycling '74's Max application](https://cycling74.com/downloads/)

### Maxpat Settings
* `Midi In/Out`
Connect your arduinoboy to these ports on your system. Once it has connected, all the lights on your arduinoboy should flash in order, and the editor will show a green `Connected`.
* `Mode` 
Setting this will tell your arduinoboy what mode to boot into automatically. This is handy if you built your own arduinoboy and decided you wanted to skimp out on LEDs and a button.
* `LSDJ Slave Mode settings` - The midi channel LSDJ slave mode will receive its commands on.
* `LSDJ Master Mode settings` - The midi channel LSDJ Master mode will send its midi notes mapped to row number on.
* `Keyboard Mode settings` - What channel LSDJ will look for its keyboard mode midi commands. No idea what compatibility mode does.
* `mGB midi settings` - Map each incoming midi channel to a specific Gameboy channel in mGB.
* `LSDJ Livesync/Livemap settings` - The midi channel Livesync/Livemap will listen to incoming midi commands from.
* `LSDJ Midiout settings` - Here you can set the following:
	* `Note midi channel` -  The channel each LSDJ channel will send it's midi note commands on.
	* `CC midi channel` -  The channel each LSDJ channel will send it's Continuous Controller commands on.
	* `CC 0` - The initial CC each channel will send. The type of data it will send is based on the next setting.
	* `CC Mode` - Game Boys have limitations! You can either have arduinoboy send one CC with many values, or 7 with limited 8bit values. By default in Arduinoboy the high nibble selects a CC#, and the low nibble sends a value [0-F] to [0-127]. This can be changed to allow just 1 midi CC with a range of 00-6F, or 7 CCs with scaled or unscaled values.
	* `CC Scaling ` - Set wether the 7 CCs are scaled or unscaled.


## Future Features & wishlist
  * Build instructions, and a Arduino Shield

## How To build an Arduinoboy
![ScreenShot](http://farm3.static.flickr.com/2229/2316803721_c22f9c2387.jpg)
![ScreenShot](http://trash80.net/arduinoboy/arduinoboy_schematic_1_1_0.png)

* [Build Photos](http://flickr.com/photos/trash80/2316803175/in/set-72157604068871573/)
* [Old version (Pre 1.1.0)](http://trash80.net/junkfood/arduinoboy/arduinoboy-schem-v.0.9.8-r1.png)

### Video Demos

  * [Keyboard Mode Test](http://youtube.com/watch?v=TnLUuvc78XY)
  * [Sync Demos](http://youtube.com/watch?v=iVmhy-Lo7BI)
  * [Arduino inside of Gameboy DMG](http://youtube.com/watch?v=VwrMuOA0VnY)
  * [mGB Example & Arduinoboy build into a DMG](http://vimeo.com/1853931)
  * [PDF explores mGB with a MIDI guitar](http://www.youtube.com/watch?v=HAU9MzZ2qeE)

## Thanks To
  * [Arduino](http://arduino.cc)
  * [Nitro2k01](http://blog.gg8.se/wordpress/) for ASM help with mGB 
  * [GWEM](http://www.preromanbritain.com/gwem/lsdj_midi/g33k.html) g33k page
  * [Midines](http://wayfar.net) Thanks for the help x|k!
  * [firestARTer](http://www.firestarter-music.de) help with keyboard & Midi handling information. 
  * [Gijs Gieskes](http://gieskes.nl) Found source code that gave insight into Nanoloop sync
  * [Little Sound DJ](http://littlesounddj.com)
  * [http://devrs.com/gb](http://devrs.com/gb) Madcatz PC link port for gb serial specs
  * [http://chipmusic.org](http://chipmusic.org) For all things Chipmusic.
  
