{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 5.0, 44.0, 708.0, 615.0 ],
		"bglocked" : 0,
		"defrect" : [ 5.0, 44.0, 708.0, 615.0 ],
		"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
		"openinpresentation" : 1,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 0,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 0,
		"toolbarvisible" : 1,
		"boxanimatetime" : 200,
		"imprint" : 0,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"boxes" : [ 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Select MIDI IN & OUT Port below and plug Arduinoboy 1.2 into the corresponding ports. Wait a few seconds, if the status doesnt change, check your cables.",
					"linecount" : 3,
					"presentation_linecount" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 877.0, 1231.0, 422.0, 48.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontsize" : 12.0,
					"presentation_rect" : [ 15.0, 10.0, 448.0, 34.0 ],
					"numinlets" : 1,
					"id" : "obj-4"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Arduinoboy Midi Out",
					"numoutlets" : 0,
					"patching_rect" : [ 613.0, 256.0, 168.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 12.0,
					"presentation_rect" : [ 192.0, 58.0, 132.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-216"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Arduinoboy Midi In",
					"numoutlets" : 0,
					"patching_rect" : [ 598.0, 241.0, 168.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 12.0,
					"presentation_rect" : [ 30.0, 59.0, 168.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-215"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "button",
					"numoutlets" : 1,
					"patching_rect" : [ 67.0, 97.0, 20.0, 20.0 ],
					"outlettype" : [ "bang" ],
					"numinlets" : 1,
					"id" : "obj-108"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 184.0, 144.0, 115.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ "AU DLS Synth 1", ",", "Loopback Bus 1", ",", "Loopback Bus 2", ",", "from MaxMSP 1", ",", "from MaxMSP 2" ],
					"fontsize" : 11.595187,
					"presentation_rect" : [ 192.0, 78.0, 142.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-111"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "midiinfo",
					"numoutlets" : 1,
					"patching_rect" : [ 184.0, 121.0, 50.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 11.595187,
					"numinlets" : 2,
					"id" : "obj-116"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "midiinfo",
					"numoutlets" : 1,
					"patching_rect" : [ 68.0, 121.0, 50.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 11.595187,
					"numinlets" : 2,
					"id" : "obj-134"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 70.0, 145.0, 115.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ "Loopback Bus 1", ",", "Loopback Bus 2", ",", "to MaxMSP 1", ",", "to MaxMSP 2" ],
					"fontsize" : 11.595187,
					"presentation_rect" : [ 30.0, 78.0, 141.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-135"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadbang",
					"numoutlets" : 1,
					"patching_rect" : [ 68.0, 73.0, 58.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "bang" ],
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"id" : "obj-136"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "midiout",
					"numoutlets" : 0,
					"patching_rect" : [ 231.0, 196.0, 49.0, 20.0 ],
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-8"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "midiin",
					"numoutlets" : 1,
					"patching_rect" : [ 118.0, 187.0, 42.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "int" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-6"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Mode",
					"numoutlets" : 0,
					"patching_rect" : [ 284.0, 777.0, 251.0, 25.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontsize" : 16.0,
					"presentation_rect" : [ 376.0, 68.0, 53.0, 25.0 ],
					"numinlets" : 1,
					"id" : "obj-180"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "prepend 70 0",
					"numoutlets" : 1,
					"patching_rect" : [ 206.0, 1052.0, 81.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-115"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r mode",
					"numoutlets" : 1,
					"patching_rect" : [ 1134.0, 1008.0, 48.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-107"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 1134.0, 1033.0, 145.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ "1:", "LSDJ", "Slave", "Mode", ",", "2:", "LSDJ", "Master", "Mode", ",", "3:", "LSDJ", "Keyboard", "Mode", ",", "4:", "Nanoloop", "Sync", ",", "5:", "mGB", "Mode", ",", "6:", "LSDJ", "Live/Sync", "Map", ",", "7:", "LSDJ", "MIDI", "Out" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 435.0, 70.0, 195.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-78"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Delay between each time aBoy checks the Gameboy for\nnew incomming messages. Lower numbers tend to freeze\nLSDJ. Default is 40us with a multiplier of 1",
					"linecount" : 3,
					"presentation_linecount" : 3,
					"numoutlets" : 0,
					"patching_rect" : [ 573.0, 1216.0, 374.0, 41.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"frgb" : [ 1.0, 1.0, 1.0, 1.0 ],
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 17.0, 556.0, 374.0, 41.0 ],
					"numinlets" : 1,
					"id" : "obj-10"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "MULTIPLIER",
					"numoutlets" : 0,
					"patching_rect" : [ 730.0, 1196.0, 81.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 174.0, 536.0, 81.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-106"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "BIT CHECK DELAY",
					"numoutlets" : 0,
					"patching_rect" : [ 574.0, 1196.0, 128.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 16.0, 536.0, 99.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-105"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "LSDJ MIDI OUT Mode Advanced Settings",
					"numoutlets" : 0,
					"patching_rect" : [ 574.0, 1165.0, 317.0, 25.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"frgb" : [ 1.0, 1.0, 1.0, 1.0 ],
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"fontsize" : 16.0,
					"presentation_rect" : [ 18.0, 505.0, 317.0, 25.0 ],
					"numinlets" : 1,
					"id" : "obj-77"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 798.0, 1195.0, 50.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 242.0, 535.0, 50.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-46"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 674.0, 1195.0, 50.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 118.0, 535.0, 50.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-45"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_bytedelaymulti",
					"numoutlets" : 1,
					"patching_rect" : [ 1115.0, 1124.0, 140.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-51"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_bytedelay",
					"numoutlets" : 1,
					"patching_rect" : [ 990.0, 1126.0, 115.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-12"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_bitdelaymulti",
					"numoutlets" : 1,
					"patching_rect" : [ 798.0, 1125.0, 130.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-14"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_bitdelay",
					"numoutlets" : 1,
					"patching_rect" : [ 674.0, 1126.0, 105.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-44"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "240 105 71 127 247",
					"numoutlets" : 1,
					"patching_rect" : [ 372.0, 1124.0, 117.0, 18.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 2,
					"id" : "obj-2"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "Restore Defaults",
					"numoutlets" : 1,
					"patching_rect" : [ 376.0, 1084.0, 138.0, 23.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"outlettype" : [ "" ],
					"bgcolor" : [ 0.72549, 0.72549, 0.72549, 1.0 ],
					"bgcolor2" : [ 0.34902, 0.34902, 0.34902, 1.0 ],
					"fontface" : 1,
					"fontsize" : 16.0,
					"presentation_rect" : [ 377.0, 466.0, 138.0, 23.0 ],
					"gradient" : 1,
					"numinlets" : 2,
					"id" : "obj-3"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "s sout",
					"numoutlets" : 0,
					"patching_rect" : [ 86.0, 1178.0, 43.0, 20.0 ],
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-43"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "prepend 240 105",
					"numoutlets" : 1,
					"patching_rect" : [ 93.0, 1115.0, 101.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-18"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "append 127 247",
					"numoutlets" : 1,
					"patching_rect" : [ 87.0, 1070.0, 97.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-17"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "6",
					"numoutlets" : 1,
					"patching_rect" : [ 925.0, 1119.0, 64.0, 18.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 2,
					"id" : "obj-7"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "trash80.loves.you.only.sometimes.love. 2010",
					"linecount" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 628.0, 271.0, 221.0, 34.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"frgb" : [ 0.682353, 0.682353, 0.682353, 1.0 ],
					"textcolor" : [ 0.682353, 0.682353, 0.682353, 1.0 ],
					"fontface" : 1,
					"fontsize" : 12.0,
					"presentation_rect" : [ 11.0, 469.0, 355.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-237"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "Send & Save Changes",
					"linecount" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 928.0, 1042.0, 161.0, 41.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"outlettype" : [ "" ],
					"bgcolor" : [ 0.529412, 0.690196, 0.545098, 1.0 ],
					"bgcolor2" : [ 0.188235, 0.431373, 0.211765, 1.0 ],
					"fontface" : 1,
					"fontsize" : 16.0,
					"presentation_rect" : [ 518.0, 466.0, 180.0, 23.0 ],
					"gradient" : 1,
					"numinlets" : 2,
					"id" : "obj-235"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "button",
					"numoutlets" : 1,
					"patching_rect" : [ 360.0, 269.0, 20.0, 20.0 ],
					"outlettype" : [ "bang" ],
					"numinlets" : 1,
					"id" : "obj-234"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "s reset",
					"numoutlets" : 0,
					"patching_rect" : [ 360.0, 313.0, 47.0, 20.0 ],
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-233"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "prepend bgcolor 0.5 0 0",
					"numoutlets" : 1,
					"patching_rect" : [ 834.0, 92.0, 133.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"id" : "obj-214"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r statusint",
					"numoutlets" : 1,
					"patching_rect" : [ 833.0, 54.0, 63.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-211"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p automove",
					"numoutlets" : 1,
					"patching_rect" : [ 1048.0, 117.0, 71.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 11.595187,
					"numinlets" : 0,
					"id" : "obj-209",
					"patcher" : 					{
						"fileversion" : 1,
						"rect" : [ 25.0, 47.0, 152.0, 172.0 ],
						"bglocked" : 0,
						"defrect" : [ 25.0, 47.0, 152.0, 172.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 10.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "loadmess 1",
									"numoutlets" : 1,
									"patching_rect" : [ 32.0, 31.0, 68.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 11.595187,
									"numinlets" : 1,
									"id" : "obj-47"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "metro 20",
									"numoutlets" : 1,
									"patching_rect" : [ 32.0, 55.75, 54.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "bang" ],
									"fontsize" : 11.595187,
									"numinlets" : 2,
									"id" : "obj-45"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "prepend angle",
									"numoutlets" : 1,
									"patching_rect" : [ 32.0, 103.75, 83.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 11.595187,
									"numinlets" : 1,
									"id" : "obj-44"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "counter 0 359",
									"numoutlets" : 4,
									"patching_rect" : [ 32.0, 79.75, 79.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "int", "", "", "int" ],
									"fontsize" : 11.595187,
									"numinlets" : 5,
									"id" : "obj-43"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"numoutlets" : 0,
									"patching_rect" : [ 32.0, 127.75, 25.0, 25.0 ],
									"numinlets" : 1,
									"id" : "obj-51",
									"comment" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-43", 0 ],
									"destination" : [ "obj-44", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-47", 0 ],
									"destination" : [ "obj-45", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-45", 0 ],
									"destination" : [ "obj-43", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-44", 0 ],
									"destination" : [ "obj-51", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontface" : 0,
						"fontname" : "Arial",
						"globalpatchername" : "",
						"default_fontname" : "Arial",
						"fontface" : 0,
						"default_fontsize" : 10.0,
						"fontsize" : 10.0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "prepend set",
					"numoutlets" : 1,
					"patching_rect" : [ 823.0, 199.0, 74.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-207"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Disconnected",
					"numoutlets" : 0,
					"patching_rect" : [ 1072.0, 243.0, 216.0, 25.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"frgb" : [ 1.0, 1.0, 1.0, 1.0 ],
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"fontface" : 1,
					"fontsize" : 16.0,
					"presentation_rect" : [ 548.0, 14.0, 137.0, 25.0 ],
					"numinlets" : 1,
					"id" : "obj-206"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r status",
					"numoutlets" : 1,
					"patching_rect" : [ 823.0, 165.0, 50.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-205"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Status",
					"numoutlets" : 0,
					"patching_rect" : [ 583.0, 226.0, 216.0, 25.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 16.0,
					"presentation_rect" : [ 475.0, 14.0, 216.0, 25.0 ],
					"numinlets" : 1,
					"id" : "obj-203"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r livemap_ch",
					"numoutlets" : 1,
					"patching_rect" : [ 1188.0, 805.0, 79.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-202"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Midi Channel",
					"numoutlets" : 0,
					"patching_rect" : [ 1146.0, 915.0, 139.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 422.0, 251.0, 139.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-198"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 1146.0, 932.0, 72.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, ",", 2, ",", 3, ",", 4, ",", 5, ",", 6, ",", 7, ",", 8, ",", 9, ",", 10, ",", 11, ",", 12, ",", 13, ",", 14, ",", 15, ",", 16 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 422.0, 268.0, 72.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-199"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "LSDJ LIVEMAP/SYNCMAP Settings",
					"linecount" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 1144.0, 881.0, 225.0, 43.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"frgb" : [ 1.0, 1.0, 1.0, 1.0 ],
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"fontsize" : 16.0,
					"presentation_rect" : [ 419.0, 220.0, 281.0, 25.0 ],
					"numinlets" : 1,
					"id" : "obj-200"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"numoutlets" : 0,
					"patching_rect" : [ 1132.0, 870.0, 279.0, 95.0 ],
					"grad1" : [ 0.047059, 0.611765, 0.913725, 1.0 ],
					"presentation" : 1,
					"mode" : 1,
					"grad2" : [ 0.047059, 0.698039, 0.913725, 1.0 ],
					"angle" : 74.590027,
					"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"presentation_rect" : [ 412.0, 210.0, 285.0, 94.0 ],
					"numinlets" : 1,
					"id" : "obj-201"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r mgb_ch5",
					"numoutlets" : 1,
					"patching_rect" : [ 1298.0, 499.0, 67.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-72"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r mgb_ch4",
					"numoutlets" : 1,
					"patching_rect" : [ 1284.0, 478.0, 67.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-194"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r mgb_ch3",
					"numoutlets" : 1,
					"patching_rect" : [ 1271.0, 457.0, 67.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-195"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r mgb_ch2",
					"numoutlets" : 1,
					"patching_rect" : [ 1257.0, 436.0, 67.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-196"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r mgb_ch1",
					"numoutlets" : 1,
					"patching_rect" : [ 1244.0, 415.0, 67.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-197"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "POLY Channel",
					"numoutlets" : 0,
					"patching_rect" : [ 1324.0, 674.0, 79.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 321.0, 251.0, 79.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-192"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 1324.0, 691.0, 72.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, ",", 2, ",", 3, ",", 4, ",", 5, ",", 6, ",", 7, ",", 8, ",", 9, ",", 10, ",", 11, ",", 12, ",", 13, ",", 14, ",", 15, ",", 16 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 321.0, 268.0, 72.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-193"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "NOI Channel",
					"numoutlets" : 0,
					"patching_rect" : [ 1247.0, 674.0, 79.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 244.0, 251.0, 79.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-190"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 1247.0, 691.0, 72.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, ",", 2, ",", 3, ",", 4, ",", 5, ",", 6, ",", 7, ",", 8, ",", 9, ",", 10, ",", 11, ",", 12, ",", 13, ",", 14, ",", 15, ",", 16 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 244.0, 268.0, 72.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-191"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "WAV Channel",
					"numoutlets" : 0,
					"patching_rect" : [ 1172.0, 674.0, 79.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 169.0, 251.0, 79.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-188"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 1172.0, 691.0, 72.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, ",", 2, ",", 3, ",", 4, ",", 5, ",", 6, ",", 7, ",", 8, ",", 9, ",", 10, ",", 11, ",", 12, ",", 13, ",", 14, ",", 15, ",", 16 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 169.0, 268.0, 72.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-189"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "PU2 Channel",
					"numoutlets" : 0,
					"patching_rect" : [ 1098.0, 675.0, 79.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 95.0, 252.0, 79.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-186"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 1098.0, 692.0, 72.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, ",", 2, ",", 3, ",", 4, ",", 5, ",", 6, ",", 7, ",", 8, ",", 9, ",", 10, ",", 11, ",", 12, ",", 13, ",", 14, ",", 15, ",", 16 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 95.0, 269.0, 72.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-187"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "PU1 Channel",
					"numoutlets" : 0,
					"patching_rect" : [ 1024.0, 675.0, 79.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 21.0, 252.0, 79.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-182"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 1024.0, 692.0, 72.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, ",", 2, ",", 3, ",", 4, ",", 5, ",", 6, ",", 7, ",", 8, ",", 9, ",", 10, ",", 11, ",", 12, ",", 13, ",", 14, ",", 15, ",", 16 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 21.0, 269.0, 72.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-183"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "mGB Midi Settings",
					"numoutlets" : 0,
					"patching_rect" : [ 1022.0, 641.0, 225.0, 25.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"frgb" : [ 1.0, 1.0, 1.0, 1.0 ],
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"fontsize" : 16.0,
					"presentation_rect" : [ 19.0, 221.0, 225.0, 25.0 ],
					"numinlets" : 1,
					"id" : "obj-184"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"numoutlets" : 0,
					"patching_rect" : [ 1010.0, 630.0, 402.0, 94.0 ],
					"grad1" : [ 0.047059, 0.611765, 0.913725, 1.0 ],
					"presentation" : 1,
					"mode" : 1,
					"grad2" : [ 0.047059, 0.698039, 0.913725, 1.0 ],
					"angle" : 74.590027,
					"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"presentation_rect" : [ 7.0, 210.0, 402.0, 94.0 ],
					"numinlets" : 1,
					"id" : "obj-185"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn47",
					"numoutlets" : 1,
					"patching_rect" : [ 1035.0, 493.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-172"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn46",
					"numoutlets" : 1,
					"patching_rect" : [ 1021.0, 471.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-173"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn45",
					"numoutlets" : 1,
					"patching_rect" : [ 1007.0, 450.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-174"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn44",
					"numoutlets" : 1,
					"patching_rect" : [ 992.0, 429.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-175"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn43",
					"numoutlets" : 1,
					"patching_rect" : [ 980.0, 408.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-176"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn42",
					"numoutlets" : 1,
					"patching_rect" : [ 966.0, 387.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-177"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn41",
					"numoutlets" : 1,
					"patching_rect" : [ 953.0, 366.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-178"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn37",
					"numoutlets" : 1,
					"patching_rect" : [ 884.0, 493.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-165"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn36",
					"numoutlets" : 1,
					"patching_rect" : [ 869.0, 471.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-166"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn35",
					"numoutlets" : 1,
					"patching_rect" : [ 856.0, 450.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-167"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn34",
					"numoutlets" : 1,
					"patching_rect" : [ 842.0, 429.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-168"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn33",
					"numoutlets" : 1,
					"patching_rect" : [ 829.0, 408.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-169"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn32",
					"numoutlets" : 1,
					"patching_rect" : [ 815.0, 387.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-170"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn31",
					"numoutlets" : 1,
					"patching_rect" : [ 802.0, 366.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-171"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn27",
					"numoutlets" : 1,
					"patching_rect" : [ 740.0, 493.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-158"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn26",
					"numoutlets" : 1,
					"patching_rect" : [ 725.0, 471.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-159"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn25",
					"numoutlets" : 1,
					"patching_rect" : [ 712.0, 450.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-160"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn24",
					"numoutlets" : 1,
					"patching_rect" : [ 698.0, 429.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-161"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn23",
					"numoutlets" : 1,
					"patching_rect" : [ 685.0, 408.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-162"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn22",
					"numoutlets" : 1,
					"patching_rect" : [ 671.0, 387.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-163"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn21",
					"numoutlets" : 1,
					"patching_rect" : [ 658.0, 366.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-164"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn17",
					"numoutlets" : 1,
					"patching_rect" : [ 616.0, 494.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-157"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn16",
					"numoutlets" : 1,
					"patching_rect" : [ 601.0, 472.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-141"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn15",
					"numoutlets" : 1,
					"patching_rect" : [ 588.0, 451.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-142"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn14",
					"numoutlets" : 1,
					"patching_rect" : [ 574.0, 430.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-143"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn13",
					"numoutlets" : 1,
					"patching_rect" : [ 561.0, 409.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-144"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn12",
					"numoutlets" : 1,
					"patching_rect" : [ 547.0, 388.0, 95.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-145"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccn11",
					"numoutlets" : 1,
					"patching_rect" : [ 534.0, 367.0, 94.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-42"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccs4",
					"numoutlets" : 1,
					"patching_rect" : [ 1002.0, 852.0, 88.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-146"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccs3",
					"numoutlets" : 1,
					"patching_rect" : [ 989.0, 831.0, 88.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-147"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccs2",
					"numoutlets" : 1,
					"patching_rect" : [ 975.0, 810.0, 88.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-148"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccs1",
					"numoutlets" : 1,
					"patching_rect" : [ 962.0, 789.0, 88.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-149"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccm4",
					"numoutlets" : 1,
					"patching_rect" : [ 549.0, 704.0, 92.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-150"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccm3",
					"numoutlets" : 1,
					"patching_rect" : [ 536.0, 683.0, 92.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-30"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccm2",
					"numoutlets" : 1,
					"patching_rect" : [ 522.0, 662.0, 92.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-31"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_ccm1",
					"numoutlets" : 1,
					"patching_rect" : [ 509.0, 641.0, 92.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-151"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_cch4",
					"numoutlets" : 1,
					"patching_rect" : [ 117.0, 817.0, 89.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-152"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_cch3",
					"numoutlets" : 1,
					"patching_rect" : [ 105.0, 796.0, 89.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-153"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_cch2",
					"numoutlets" : 1,
					"patching_rect" : [ 90.0, 775.0, 89.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-27"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_cch1",
					"numoutlets" : 1,
					"patching_rect" : [ 77.0, 754.0, 89.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-28"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_nch4",
					"numoutlets" : 1,
					"patching_rect" : [ 76.0, 732.0, 89.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-24"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_nch3",
					"numoutlets" : 1,
					"patching_rect" : [ 63.0, 710.0, 89.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-154"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_nch2",
					"numoutlets" : 1,
					"patching_rect" : [ 49.0, 688.0, 89.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-155"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r midiout_nch1",
					"numoutlets" : 1,
					"patching_rect" : [ 36.0, 666.0, 89.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-156"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 495.0, 871.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, "CC", "with", "range", "0-6F", ",", 7, "CCs", "with", "range", "0-F" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 237.0, 427.0, 69.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-117"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 761.0, 871.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 519.0, 427.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-118"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 719.0, 871.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 477.0, 427.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-119"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 677.0, 871.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 435.0, 427.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-120"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 635.0, 871.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 393.0, 427.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-121"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 593.0, 871.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 351.0, 427.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-122"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 551.0, 871.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 309.0, 427.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-123"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 449.0, 871.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 194.0, 427.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-124"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 814.0, 871.0, 119.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ "Use", "Exact", "Value", ",", "Spread", "value", "from", 0, "to", 127 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 563.0, 427.0, 119.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-125"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 374.0, 871.0, 72.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, ",", 2, ",", 3, ",", 4, ",", 5, ",", 6, ",", 7, ",", 8, ",", 9, ",", 10, ",", 11, ",", 12, ",", 13, ",", 14, ",", 15, ",", 16 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 121.0, 427.0, 72.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-126"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "NOI",
					"numoutlets" : 0,
					"patching_rect" : [ 268.0, 872.0, 31.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 15.0, 428.0, 31.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-127"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 300.0, 871.0, 72.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, ",", 2, ",", 3, ",", 4, ",", 5, ",", 6, ",", 7, ",", 8, ",", 9, ",", 10, ",", 11, ",", 12, ",", 13, ",", 14, ",", 15, ",", 16 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 48.0, 427.0, 72.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-128"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 496.0, 850.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, "CC", "with", "range", "0-6F", ",", 7, "CCs", "with", "range", "0-F" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 237.0, 406.0, 69.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-92"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 762.0, 850.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 519.0, 406.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-93"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 720.0, 850.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 477.0, 406.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-94"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 678.0, 850.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 435.0, 406.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-95"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 636.0, 850.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 393.0, 406.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-96"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 594.0, 850.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 351.0, 406.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-97"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 552.0, 850.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 309.0, 406.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-98"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 450.0, 850.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 194.0, 406.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-99"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 815.0, 850.0, 119.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ "Use", "Exact", "Value", ",", "Spread", "value", "from", 0, "to", 127 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 563.0, 406.0, 119.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-100"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 375.0, 850.0, 72.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, ",", 2, ",", 3, ",", 4, ",", 5, ",", 6, ",", 7, ",", 8, ",", 9, ",", 10, ",", 11, ",", 12, ",", 13, ",", 14, ",", 15, ",", 16 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 121.0, 406.0, 72.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-101"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "WAV",
					"numoutlets" : 0,
					"patching_rect" : [ 269.0, 851.0, 31.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 16.0, 407.0, 31.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-102"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 301.0, 850.0, 72.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, ",", 2, ",", 3, ",", 4, ",", 5, ",", 6, ",", 7, ",", 8, ",", 9, ",", 10, ",", 11, ",", 12, ",", 13, ",", 14, ",", 15, ",", 16 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 48.0, 406.0, 72.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-103"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 496.0, 829.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, "CC", "with", "range", "0-6F", ",", 7, "CCs", "with", "range", "0-F" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 237.0, 385.0, 69.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-79"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 762.0, 829.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 519.0, 385.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-80"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 720.0, 829.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 477.0, 385.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-81"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 678.0, 829.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 435.0, 385.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-82"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 636.0, 829.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 393.0, 385.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-84"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 594.0, 829.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 351.0, 385.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-85"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 552.0, 829.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 309.0, 385.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-86"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 450.0, 829.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 194.0, 385.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-87"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 815.0, 829.0, 119.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ "Use", "Exact", "Value", ",", "Spread", "value", "from", 0, "to", 127 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 563.0, 385.0, 119.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-88"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 375.0, 829.0, 72.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, ",", 2, ",", 3, ",", 4, ",", 5, ",", 6, ",", 7, ",", 8, ",", 9, ",", 10, ",", 11, ",", 12, ",", 13, ",", 14, ",", 15, ",", 16 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 121.0, 385.0, 72.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-89"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "PU2",
					"numoutlets" : 0,
					"patching_rect" : [ 269.0, 830.0, 31.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 16.0, 386.0, 31.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-90"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 301.0, 829.0, 72.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, ",", 2, ",", 3, ",", 4, ",", 5, ",", 6, ",", 7, ",", 8, ",", 9, ",", 10, ",", 11, ",", 12, ",", 13, ",", 14, ",", 15, ",", 16 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 48.0, 385.0, 72.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-91"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 491.0, 776.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, "CC", "with", "range", "0-6F", ",", 7, "CCs", "with", "range", "0-F" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 237.0, 364.0, 69.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-76"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "CC Mode",
					"numoutlets" : 0,
					"patching_rect" : [ 495.0, 789.0, 53.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 242.0, 345.0, 53.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-75"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "CC SCALING",
					"numoutlets" : 0,
					"patching_rect" : [ 817.0, 789.0, 73.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 565.0, 345.0, 73.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-74"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 762.0, 808.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 519.0, 364.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-70"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "CC#6",
					"numoutlets" : 0,
					"patching_rect" : [ 763.0, 789.0, 36.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 520.0, 345.0, 36.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-71"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 720.0, 808.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 477.0, 364.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-68"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "CC#5",
					"numoutlets" : 0,
					"patching_rect" : [ 721.0, 789.0, 36.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 478.0, 345.0, 36.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-69"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 678.0, 808.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 435.0, 364.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-64"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "CC#4",
					"numoutlets" : 0,
					"patching_rect" : [ 679.0, 789.0, 36.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 436.0, 345.0, 36.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-65"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 636.0, 808.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 393.0, 364.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-66"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "CC#3",
					"numoutlets" : 0,
					"patching_rect" : [ 637.0, 789.0, 36.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 394.0, 345.0, 36.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-67"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 594.0, 808.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 351.0, 364.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-62"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "CC#2",
					"numoutlets" : 0,
					"patching_rect" : [ 595.0, 789.0, 36.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 352.0, 345.0, 36.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-63"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 458.0, 725.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 309.0, 364.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-60"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "CC#1",
					"numoutlets" : 0,
					"patching_rect" : [ 553.0, 789.0, 36.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 310.0, 345.0, 36.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-61"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"maximum" : 127,
					"numoutlets" : 2,
					"patching_rect" : [ 417.0, 725.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 194.0, 364.0, 41.0, 20.0 ],
					"minimum" : 1,
					"numinlets" : 1,
					"id" : "obj-59"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "CC#0",
					"numoutlets" : 0,
					"patching_rect" : [ 451.0, 789.0, 36.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 198.0, 345.0, 36.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-55"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 815.0, 808.0, 119.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ "Use", "Exact", "Value", ",", "Spread", "value", "from", 0, "to", 127 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 563.0, 364.0, 119.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-56"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "CC MIDI CH",
					"numoutlets" : 0,
					"patching_rect" : [ 373.0, 789.0, 71.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 120.0, 345.0, 71.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-54"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 375.0, 808.0, 72.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, ",", 2, ",", 3, ",", 4, ",", 5, ",", 6, ",", 7, ",", 8, ",", 9, ",", 10, ",", 11, ",", 12, ",", 13, ",", 14, ",", 15, ",", 16 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 121.0, 364.0, 72.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-53"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Note MIDI CH",
					"numoutlets" : 0,
					"patching_rect" : [ 298.0, 789.0, 74.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 45.0, 345.0, 74.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-52"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "PU1",
					"numoutlets" : 0,
					"patching_rect" : [ 269.0, 809.0, 31.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 16.0, 365.0, 31.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-49"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 301.0, 808.0, 72.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, ",", 2, ",", 3, ",", 4, ",", 5, ",", 6, ",", 7, ",", 8, ",", 9, ",", 10, ",", 11, ",", 12, ",", 13, ",", 14, ",", 15, ",", 16 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 48.0, 364.0, 72.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-50"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "LSDJ MIDI OUT Mode Settings",
					"numoutlets" : 0,
					"patching_rect" : [ 269.0, 762.0, 251.0, 25.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"frgb" : [ 1.0, 1.0, 1.0, 1.0 ],
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"fontsize" : 16.0,
					"presentation_rect" : [ 19.0, 318.0, 251.0, 25.0 ],
					"numinlets" : 1,
					"id" : "obj-47"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"numoutlets" : 0,
					"patching_rect" : [ 257.0, 751.0, 692.0, 153.0 ],
					"grad1" : [ 0.047059, 0.611765, 0.913725, 1.0 ],
					"presentation" : 1,
					"mode" : 1,
					"grad2" : [ 0.047059, 0.698039, 0.913725, 1.0 ],
					"angle" : 74.590027,
					"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"presentation_rect" : [ 8.0, 307.0, 690.0, 156.0 ],
					"numinlets" : 1,
					"id" : "obj-48"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r sync_midich",
					"numoutlets" : 1,
					"patching_rect" : [ 239.0, 562.0, 84.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-41"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r master_midich",
					"numoutlets" : 1,
					"patching_rect" : [ 146.0, 439.0, 96.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-40"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Midi Channel",
					"numoutlets" : 0,
					"patching_rect" : [ 239.0, 653.0, 139.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 23.0, 155.0, 139.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-36"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 239.0, 670.0, 72.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, ",", 2, ",", 3, ",", 4, ",", 5, ",", 6, ",", 7, ",", 8, ",", 9, ",", 10, ",", 11, ",", 12, ",", 13, ",", 14, ",", 15, ",", 16 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 97.0, 155.0, 72.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-37"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "LSDJ Slave Mode Settings",
					"numoutlets" : 0,
					"patching_rect" : [ 237.0, 619.0, 225.0, 25.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"frgb" : [ 1.0, 1.0, 1.0, 1.0 ],
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"fontsize" : 16.0,
					"presentation_rect" : [ 19.0, 123.0, 206.0, 25.0 ],
					"numinlets" : 1,
					"id" : "obj-38"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"numoutlets" : 0,
					"patching_rect" : [ 225.0, 608.0, 279.0, 95.0 ],
					"grad1" : [ 0.047059, 0.611765, 0.913725, 1.0 ],
					"presentation" : 1,
					"mode" : 1,
					"grad2" : [ 0.047059, 0.698039, 0.913725, 1.0 ],
					"angle" : 74.590027,
					"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"presentation_rect" : [ 7.0, 111.0, 228.0, 96.0 ],
					"numinlets" : 1,
					"id" : "obj-39"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Midi Channel",
					"numoutlets" : 0,
					"patching_rect" : [ 147.0, 502.0, 139.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 254.0, 155.0, 139.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-32"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 147.0, 519.0, 72.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, ",", 2, ",", 3, ",", 4, ",", 5, ",", 6, ",", 7, ",", 8, ",", 9, ",", 10, ",", 11, ",", 12, ",", 13, ",", 14, ",", 15, ",", 16 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 328.0, 155.0, 72.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-33"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "LSDJ Master Mode Settings",
					"numoutlets" : 0,
					"patching_rect" : [ 145.0, 468.0, 225.0, 25.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"frgb" : [ 1.0, 1.0, 1.0, 1.0 ],
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"fontsize" : 16.0,
					"presentation_rect" : [ 250.0, 123.0, 212.0, 25.0 ],
					"numinlets" : 1,
					"id" : "obj-34"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"numoutlets" : 0,
					"patching_rect" : [ 133.0, 457.0, 279.0, 95.0 ],
					"grad1" : [ 0.047059, 0.611765, 0.913725, 1.0 ],
					"presentation" : 1,
					"mode" : 1,
					"grad2" : [ 0.047059, 0.698039, 0.913725, 1.0 ],
					"angle" : 74.590027,
					"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"presentation_rect" : [ 238.0, 111.0, 228.0, 96.0 ],
					"numinlets" : 1,
					"id" : "obj-35"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "pack 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
					"numoutlets" : 1,
					"patching_rect" : [ 82.0, 1003.0, 815.5, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 60,
					"id" : "obj-29"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r kb_compatmode",
					"numoutlets" : 1,
					"patching_rect" : [ 100.0, 312.0, 107.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-26"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r kb_midich",
					"numoutlets" : 1,
					"patching_rect" : [ 86.0, 291.0, 72.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-20"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "toggle",
					"numoutlets" : 1,
					"patching_rect" : [ 188.0, 404.0, 20.0, 20.0 ],
					"presentation" : 1,
					"outlettype" : [ "int" ],
					"presentation_rect" : [ 610.0, 176.0, 20.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-25"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Compatability Mode",
					"numoutlets" : 0,
					"patching_rect" : [ 208.0, 405.0, 139.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 485.0, 178.0, 139.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-23"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Midi Channel",
					"numoutlets" : 0,
					"patching_rect" : [ 97.0, 387.0, 139.0, 18.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"fontface" : 1,
					"fontsize" : 10.0,
					"presentation_rect" : [ 485.0, 154.0, 139.0, 18.0 ],
					"numinlets" : 1,
					"id" : "obj-22"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"types" : [  ],
					"numoutlets" : 3,
					"patching_rect" : [ 97.0, 404.0, 72.0, 20.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"outlettype" : [ "int", "", "" ],
					"items" : [ 1, ",", 2, ",", 3, ",", 4, ",", 5, ",", 6, ",", 7, ",", 8, ",", 9, ",", 10, ",", 11, ",", 12, ",", 13, ",", 14, ",", 15, ",", 16 ],
					"fontsize" : 12.0,
					"presentation_rect" : [ 559.0, 154.0, 72.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-21"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Keyboard Mode Settings",
					"numoutlets" : 0,
					"patching_rect" : [ 95.0, 353.0, 198.0, 25.0 ],
					"fontname" : "Arial",
					"presentation" : 1,
					"frgb" : [ 1.0, 1.0, 1.0, 1.0 ],
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"fontsize" : 16.0,
					"presentation_rect" : [ 481.0, 122.0, 198.0, 25.0 ],
					"numinlets" : 1,
					"id" : "obj-19"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p sysex",
					"numoutlets" : 0,
					"patching_rect" : [ 92.0, 245.0, 51.0, 20.0 ],
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-15",
					"patcher" : 					{
						"fileversion" : 1,
						"rect" : [ 547.0, 493.0, 1903.0, 1042.0 ],
						"bglocked" : 0,
						"defrect" : [ 547.0, 493.0, 1903.0, 1042.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "240 105 72 127 247",
									"numoutlets" : 1,
									"patching_rect" : [ 985.0, 531.0, 117.0, 18.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 2,
									"id" : "obj-50"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"numoutlets" : 1,
									"patching_rect" : [ 985.0, 497.0, 20.0, 20.0 ],
									"outlettype" : [ "bang" ],
									"numinlets" : 1,
									"id" : "obj-43"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "r statusint",
									"numoutlets" : 1,
									"patching_rect" : [ 1011.0, 368.0, 63.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 0,
									"id" : "obj-8"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "gate 1",
									"numoutlets" : 1,
									"patching_rect" : [ 1011.0, 411.0, 44.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 2,
									"id" : "obj-2"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_bytedelaymulti",
									"numoutlets" : 0,
									"patching_rect" : [ 1465.0, 803.0, 142.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-51"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_bytedelay",
									"numoutlets" : 0,
									"patching_rect" : [ 1452.0, 782.0, 117.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-52"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_bitdelaymulti",
									"numoutlets" : 0,
									"patching_rect" : [ 1438.0, 761.0, 132.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-53"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_bitdelay",
									"numoutlets" : 0,
									"patching_rect" : [ 1425.0, 740.0, 107.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-54"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "number",
									"numoutlets" : 2,
									"patching_rect" : [ 675.0, 908.0, 50.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "int", "bang" ],
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-49"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "number",
									"numoutlets" : 2,
									"patching_rect" : [ 635.0, 936.0, 50.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "int", "bang" ],
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-45"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "number",
									"numoutlets" : 2,
									"patching_rect" : [ 621.0, 854.0, 50.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "int", "bang" ],
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-46"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "number",
									"numoutlets" : 2,
									"patching_rect" : [ 607.0, 879.0, 50.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "int", "bang" ],
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-47"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "r reset",
									"numoutlets" : 1,
									"patching_rect" : [ 227.0, 486.0, 45.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 0,
									"id" : "obj-233"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "240 105 66 1 2 69 247",
									"numoutlets" : 1,
									"patching_rect" : [ 760.0, 515.0, 131.0, 18.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 2,
									"id" : "obj-126"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s sout",
									"numoutlets" : 0,
									"patching_rect" : [ 760.0, 569.0, 43.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-121"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "if $i3 == 105 && $i4==65 then bang",
									"numoutlets" : 1,
									"patching_rect" : [ 761.0, 483.0, 199.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 4,
									"id" : "obj-123"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "1",
									"numoutlets" : 1,
									"patching_rect" : [ 270.0, 717.0, 32.5, 18.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 2,
									"id" : "obj-120"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "0",
									"numoutlets" : 1,
									"patching_rect" : [ 347.0, 717.0, 32.5, 18.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 2,
									"id" : "obj-119"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s statusint",
									"numoutlets" : 0,
									"patching_rect" : [ 400.0, 754.0, 65.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-118"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s status",
									"numoutlets" : 0,
									"patching_rect" : [ 296.0, 759.0, 52.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-117"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "Disconnected",
									"numoutlets" : 1,
									"patching_rect" : [ 238.0, 696.0, 83.0, 18.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 2,
									"id" : "obj-116"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "Connected",
									"numoutlets" : 1,
									"patching_rect" : [ 335.0, 695.0, 69.0, 18.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 2,
									"id" : "obj-115"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "if $i1>5 then bang",
									"numoutlets" : 1,
									"patching_rect" : [ 335.0, 655.0, 106.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-114"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "number",
									"numoutlets" : 2,
									"patching_rect" : [ 335.0, 620.0, 50.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "int", "bang" ],
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-113"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"numoutlets" : 1,
									"patching_rect" : [ 334.0, 549.0, 20.0, 20.0 ],
									"outlettype" : [ "bang" ],
									"numinlets" : 1,
									"id" : "obj-112"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "toggle",
									"numoutlets" : 1,
									"patching_rect" : [ 305.0, 482.0, 20.0, 20.0 ],
									"outlettype" : [ "int" ],
									"numinlets" : 1,
									"id" : "obj-111"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "loadbang",
									"numoutlets" : 1,
									"patching_rect" : [ 305.0, 456.0, 60.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "bang" ],
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-110"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "metro 1000",
									"numoutlets" : 1,
									"patching_rect" : [ 334.0, 521.0, 71.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "bang" ],
									"fontsize" : 12.0,
									"numinlets" : 2,
									"id" : "obj-109"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "counter 0 1 100000",
									"numoutlets" : 4,
									"patching_rect" : [ 334.0, 577.0, 114.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "int", "", "", "int" ],
									"fontsize" : 12.0,
									"numinlets" : 5,
									"id" : "obj-108"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s livemap_ch",
									"numoutlets" : 0,
									"patching_rect" : [ 1404.0, 858.0, 81.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-202"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn47",
									"numoutlets" : 0,
									"patching_rect" : [ 1329.0, 983.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-93"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn46",
									"numoutlets" : 0,
									"patching_rect" : [ 1313.0, 961.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-94"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn45",
									"numoutlets" : 0,
									"patching_rect" : [ 1300.0, 940.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-95"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn44",
									"numoutlets" : 0,
									"patching_rect" : [ 1286.0, 919.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-96"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn43",
									"numoutlets" : 0,
									"patching_rect" : [ 1273.0, 898.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-97"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn42",
									"numoutlets" : 0,
									"patching_rect" : [ 1259.0, 877.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-98"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn41",
									"numoutlets" : 0,
									"patching_rect" : [ 1246.0, 856.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-99"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn37",
									"numoutlets" : 0,
									"patching_rect" : [ 1229.0, 834.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-100"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn36",
									"numoutlets" : 0,
									"patching_rect" : [ 1215.0, 812.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-101"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn35",
									"numoutlets" : 0,
									"patching_rect" : [ 1202.0, 791.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-102"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn34",
									"numoutlets" : 0,
									"patching_rect" : [ 1188.0, 770.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-103"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn33",
									"numoutlets" : 0,
									"patching_rect" : [ 1175.0, 749.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-104"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn32",
									"numoutlets" : 0,
									"patching_rect" : [ 1161.0, 728.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-105"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn31",
									"numoutlets" : 0,
									"patching_rect" : [ 1148.0, 707.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-106"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn27",
									"numoutlets" : 0,
									"patching_rect" : [ 1134.0, 984.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-86"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn26",
									"numoutlets" : 0,
									"patching_rect" : [ 1121.0, 962.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-87"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn25",
									"numoutlets" : 0,
									"patching_rect" : [ 1107.0, 941.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-88"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn24",
									"numoutlets" : 0,
									"patching_rect" : [ 1094.0, 920.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-89"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn23",
									"numoutlets" : 0,
									"patching_rect" : [ 1080.0, 899.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-90"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn22",
									"numoutlets" : 0,
									"patching_rect" : [ 1067.0, 878.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-91"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn21",
									"numoutlets" : 0,
									"patching_rect" : [ 1053.0, 857.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-92"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn17",
									"numoutlets" : 0,
									"patching_rect" : [ 1040.0, 835.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-85"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s mgb_ch5",
									"numoutlets" : 0,
									"patching_rect" : [ 1391.0, 832.0, 69.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-72"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s mgb_ch4",
									"numoutlets" : 0,
									"patching_rect" : [ 1377.0, 811.0, 69.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-74"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s mgb_ch3",
									"numoutlets" : 0,
									"patching_rect" : [ 1364.0, 790.0, 69.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-77"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s mgb_ch2",
									"numoutlets" : 0,
									"patching_rect" : [ 1350.0, 769.0, 69.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-83"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s mgb_ch1",
									"numoutlets" : 0,
									"patching_rect" : [ 1337.0, 748.0, 69.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-84"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn16",
									"numoutlets" : 0,
									"patching_rect" : [ 1026.0, 813.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-37"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn15",
									"numoutlets" : 0,
									"patching_rect" : [ 1013.0, 792.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-38"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn14",
									"numoutlets" : 0,
									"patching_rect" : [ 999.0, 771.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-39"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn13",
									"numoutlets" : 0,
									"patching_rect" : [ 986.0, 750.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-40"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn12",
									"numoutlets" : 0,
									"patching_rect" : [ 972.0, 729.0, 97.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-41"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccn11",
									"numoutlets" : 0,
									"patching_rect" : [ 959.0, 708.0, 96.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-42"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccs4",
									"numoutlets" : 0,
									"patching_rect" : [ 945.0, 947.0, 90.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-33"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccs3",
									"numoutlets" : 0,
									"patching_rect" : [ 932.0, 926.0, 90.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-34"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccs2",
									"numoutlets" : 0,
									"patching_rect" : [ 918.0, 905.0, 90.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-35"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccs1",
									"numoutlets" : 0,
									"patching_rect" : [ 905.0, 884.0, 90.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-36"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccm4",
									"numoutlets" : 0,
									"patching_rect" : [ 891.0, 863.0, 94.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-29"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccm3",
									"numoutlets" : 0,
									"patching_rect" : [ 878.0, 842.0, 94.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-30"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccm2",
									"numoutlets" : 0,
									"patching_rect" : [ 864.0, 821.0, 94.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-31"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_ccm1",
									"numoutlets" : 0,
									"patching_rect" : [ 851.0, 800.0, 94.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-32"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_cch4",
									"numoutlets" : 0,
									"patching_rect" : [ 837.0, 773.0, 91.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-25"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_cch3",
									"numoutlets" : 0,
									"patching_rect" : [ 824.0, 752.0, 91.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-26"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_cch2",
									"numoutlets" : 0,
									"patching_rect" : [ 810.0, 731.0, 91.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-27"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_cch1",
									"numoutlets" : 0,
									"patching_rect" : [ 797.0, 710.0, 91.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-28"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_nch4",
									"numoutlets" : 0,
									"patching_rect" : [ 783.0, 923.0, 91.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-24"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_nch3",
									"numoutlets" : 0,
									"patching_rect" : [ 770.0, 901.0, 91.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-23"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_nch2",
									"numoutlets" : 0,
									"patching_rect" : [ 756.0, 879.0, 91.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-22"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s midiout_nch1",
									"numoutlets" : 0,
									"patching_rect" : [ 743.0, 857.0, 91.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-21"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s mnull",
									"numoutlets" : 0,
									"patching_rect" : [ 542.0, 793.0, 49.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-16"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s kb_midich2ins",
									"numoutlets" : 0,
									"patching_rect" : [ 730.0, 832.0, 96.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-17"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s kb_compatmode",
									"numoutlets" : 0,
									"patching_rect" : [ 716.0, 810.0, 109.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-19"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s kb_midich",
									"numoutlets" : 0,
									"patching_rect" : [ 702.0, 789.0, 74.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-20"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s master_midich",
									"numoutlets" : 0,
									"patching_rect" : [ 689.0, 768.0, 98.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-13"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s sync_midich",
									"numoutlets" : 0,
									"patching_rect" : [ 675.0, 747.0, 86.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-15"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s force_mode",
									"numoutlets" : 0,
									"patching_rect" : [ 648.0, 726.0, 83.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-10"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s mode",
									"numoutlets" : 0,
									"patching_rect" : [ 662.0, 705.0, 50.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-11"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s version2",
									"numoutlets" : 0,
									"patching_rect" : [ 621.0, 833.0, 65.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-9"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s version1",
									"numoutlets" : 0,
									"patching_rect" : [ 608.0, 812.0, 65.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-4"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "r syspack",
									"numoutlets" : 1,
									"patching_rect" : [ 435.0, 590.0, 61.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 0,
									"id" : "obj-7"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "0 240 105 127 1 2",
									"numoutlets" : 1,
									"patching_rect" : [ 540.0, 643.0, 1372.0, 18.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 2,
									"id" : "obj-5"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "if $i3 == 105 && $i4==64 then bang",
									"numoutlets" : 1,
									"patching_rect" : [ 498.0, 615.0, 199.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 4,
									"id" : "obj-3"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "unpack 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
									"numoutlets" : 69,
									"patching_rect" : [ 540.0, 680.0, 937.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int" ],
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-1"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s sout",
									"numoutlets" : 0,
									"patching_rect" : [ 432.0, 550.0, 43.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-82"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "240 105 64 1 2 67 247",
									"numoutlets" : 1,
									"patching_rect" : [ 432.0, 523.0, 131.0, 18.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 2,
									"id" : "obj-81"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "r syspack",
									"numoutlets" : 1,
									"patching_rect" : [ 432.0, 447.0, 61.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 0,
									"id" : "obj-80"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "if $i3 == 105 && $i4==127 && $i5==1 && $i6==2 then bang",
									"numoutlets" : 1,
									"patching_rect" : [ 432.0, 483.0, 325.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 6,
									"id" : "obj-79"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "gate",
									"numoutlets" : 1,
									"patching_rect" : [ 239.0, 337.0, 34.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 2,
									"id" : "obj-78"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s syspack",
									"numoutlets" : 0,
									"patching_rect" : [ 240.0, 415.0, 63.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-76"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "r sin",
									"numoutlets" : 1,
									"patching_rect" : [ 260.0, 214.0, 33.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 0,
									"id" : "obj-75"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "if $i1==0 then bang",
									"numoutlets" : 1,
									"patching_rect" : [ 124.0, 302.0, 113.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-73"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "0",
									"numoutlets" : 1,
									"patching_rect" : [ 371.0, 368.0, 32.5, 18.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 2,
									"id" : "obj-71"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"numoutlets" : 1,
									"patching_rect" : [ 205.0, 335.0, 20.0, 20.0 ],
									"outlettype" : [ "bang" ],
									"numinlets" : 1,
									"id" : "obj-69"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "r sysexstatus",
									"numoutlets" : 1,
									"patching_rect" : [ 124.0, 264.0, 81.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 0,
									"id" : "obj-67"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "prepend append",
									"numoutlets" : 1,
									"patching_rect" : [ 340.0, 259.0, 98.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-65"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "0",
									"numoutlets" : 1,
									"patching_rect" : [ 240.0, 369.0, 32.5, 18.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 2,
									"id" : "obj-63"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "append 127",
									"linecount" : 2,
									"numoutlets" : 1,
									"patching_rect" : [ 260.0, 292.0, 55.0, 32.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 2,
									"id" : "obj-58"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s sysexstatus",
									"numoutlets" : 0,
									"patching_rect" : [ 51.0, 206.0, 83.0, 20.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-18"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "if $i1 == 247 then 0",
									"numoutlets" : 1,
									"patching_rect" : [ 76.0, 170.0, 113.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-14"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "r sin",
									"numoutlets" : 1,
									"patching_rect" : [ 50.0, 100.0, 33.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 0,
									"id" : "obj-12"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "if $i1 == 240 then 1",
									"numoutlets" : 1,
									"patching_rect" : [ 51.0, 149.0, 113.0, 20.0 ],
									"fontname" : "Arial",
									"outlettype" : [ "" ],
									"fontsize" : 12.0,
									"numinlets" : 1,
									"id" : "obj-6"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-50", 0 ],
									"destination" : [ "obj-121", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-43", 0 ],
									"destination" : [ "obj-50", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-112", 0 ],
									"destination" : [ "obj-2", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-2", 0 ],
									"destination" : [ "obj-43", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 68 ],
									"destination" : [ "obj-51", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 67 ],
									"destination" : [ "obj-52", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 66 ],
									"destination" : [ "obj-53", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 65 ],
									"destination" : [ "obj-54", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 58 ],
									"destination" : [ "obj-93", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 57 ],
									"destination" : [ "obj-94", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 56 ],
									"destination" : [ "obj-95", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 55 ],
									"destination" : [ "obj-96", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 54 ],
									"destination" : [ "obj-97", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 53 ],
									"destination" : [ "obj-98", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 52 ],
									"destination" : [ "obj-99", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 51 ],
									"destination" : [ "obj-100", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 50 ],
									"destination" : [ "obj-101", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 49 ],
									"destination" : [ "obj-102", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 48 ],
									"destination" : [ "obj-103", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 47 ],
									"destination" : [ "obj-104", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 46 ],
									"destination" : [ "obj-105", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 45 ],
									"destination" : [ "obj-106", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 44 ],
									"destination" : [ "obj-86", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 43 ],
									"destination" : [ "obj-87", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 42 ],
									"destination" : [ "obj-88", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 41 ],
									"destination" : [ "obj-89", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 40 ],
									"destination" : [ "obj-90", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 39 ],
									"destination" : [ "obj-91", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 38 ],
									"destination" : [ "obj-92", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 37 ],
									"destination" : [ "obj-85", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 59 ],
									"destination" : [ "obj-84", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 60 ],
									"destination" : [ "obj-83", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 61 ],
									"destination" : [ "obj-77", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 62 ],
									"destination" : [ "obj-74", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 63 ],
									"destination" : [ "obj-72", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 32 ],
									"destination" : [ "obj-41", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 36 ],
									"destination" : [ "obj-37", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 35 ],
									"destination" : [ "obj-38", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 34 ],
									"destination" : [ "obj-39", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 33 ],
									"destination" : [ "obj-40", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 31 ],
									"destination" : [ "obj-42", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 30 ],
									"destination" : [ "obj-33", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 29 ],
									"destination" : [ "obj-34", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 28 ],
									"destination" : [ "obj-35", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 27 ],
									"destination" : [ "obj-36", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 26 ],
									"destination" : [ "obj-29", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 25 ],
									"destination" : [ "obj-30", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 24 ],
									"destination" : [ "obj-31", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 23 ],
									"destination" : [ "obj-32", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 22 ],
									"destination" : [ "obj-25", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 21 ],
									"destination" : [ "obj-26", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 20 ],
									"destination" : [ "obj-27", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 19 ],
									"destination" : [ "obj-28", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 18 ],
									"destination" : [ "obj-24", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 17 ],
									"destination" : [ "obj-23", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 16 ],
									"destination" : [ "obj-22", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 15 ],
									"destination" : [ "obj-21", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 7 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 4 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 3 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 2 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 1 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 14 ],
									"destination" : [ "obj-17", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 13 ],
									"destination" : [ "obj-19", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 12 ],
									"destination" : [ "obj-20", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 11 ],
									"destination" : [ "obj-13", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 10 ],
									"destination" : [ "obj-15", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 5 ],
									"destination" : [ "obj-4", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 6 ],
									"destination" : [ "obj-9", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 64 ],
									"destination" : [ "obj-202", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 5 ],
									"destination" : [ "obj-47", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 6 ],
									"destination" : [ "obj-46", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 7 ],
									"destination" : [ "obj-45", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 10 ],
									"destination" : [ "obj-49", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-233", 0 ],
									"destination" : [ "obj-120", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-233", 0 ],
									"destination" : [ "obj-116", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-126", 0 ],
									"destination" : [ "obj-119", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-126", 0 ],
									"destination" : [ "obj-115", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-126", 0 ],
									"destination" : [ "obj-121", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-123", 0 ],
									"destination" : [ "obj-126", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-81", 0 ],
									"destination" : [ "obj-82", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-79", 0 ],
									"destination" : [ "obj-81", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-80", 0 ],
									"destination" : [ "obj-123", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-119", 0 ],
									"destination" : [ "obj-118", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-114", 0 ],
									"destination" : [ "obj-120", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-110", 0 ],
									"destination" : [ "obj-120", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-120", 0 ],
									"destination" : [ "obj-118", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-115", 0 ],
									"destination" : [ "obj-117", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-116", 0 ],
									"destination" : [ "obj-117", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-114", 0 ],
									"destination" : [ "obj-116", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-110", 0 ],
									"destination" : [ "obj-116", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-113", 0 ],
									"destination" : [ "obj-114", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-108", 0 ],
									"destination" : [ "obj-113", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-112", 0 ],
									"destination" : [ "obj-108", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-79", 0 ],
									"destination" : [ "obj-108", 3 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-109", 0 ],
									"destination" : [ "obj-112", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-111", 0 ],
									"destination" : [ "obj-109", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-110", 0 ],
									"destination" : [ "obj-111", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-80", 0 ],
									"destination" : [ "obj-79", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-67", 0 ],
									"destination" : [ "obj-73", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-73", 0 ],
									"destination" : [ "obj-69", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-69", 0 ],
									"destination" : [ "obj-63", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-63", 0 ],
									"destination" : [ "obj-71", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-71", 0 ],
									"destination" : [ "obj-63", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-65", 0 ],
									"destination" : [ "obj-58", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-75", 0 ],
									"destination" : [ "obj-58", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-75", 0 ],
									"destination" : [ "obj-65", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-67", 0 ],
									"destination" : [ "obj-78", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-58", 0 ],
									"destination" : [ "obj-78", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-78", 0 ],
									"destination" : [ "obj-63", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-63", 0 ],
									"destination" : [ "obj-76", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-14", 0 ],
									"destination" : [ "obj-18", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-18", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-12", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-12", 0 ],
									"destination" : [ "obj-6", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-5", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
									"destination" : [ "obj-3", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
									"destination" : [ "obj-5", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 8 ],
									"destination" : [ "obj-10", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 9 ],
									"destination" : [ "obj-11", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontface" : 0,
						"fontname" : "Arial",
						"globalpatchername" : "",
						"default_fontname" : "Arial",
						"fontface" : 0,
						"default_fontsize" : 12.0,
						"fontsize" : 12.0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r sout",
					"numoutlets" : 1,
					"patching_rect" : [ 305.0, 151.0, 41.0, 20.0 ],
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0,
					"id" : "obj-83"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "s sin",
					"numoutlets" : 0,
					"patching_rect" : [ 116.0, 217.0, 35.0, 20.0 ],
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"id" : "obj-11"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"numoutlets" : 0,
					"patching_rect" : [ 83.0, 342.0, 279.0, 95.0 ],
					"grad1" : [ 0.047059, 0.611765, 0.913725, 1.0 ],
					"presentation" : 1,
					"mode" : 1,
					"grad2" : [ 0.047059, 0.698039, 0.913725, 1.0 ],
					"angle" : 74.590027,
					"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"presentation_rect" : [ 469.0, 111.0, 228.0, 96.0 ],
					"numinlets" : 1,
					"id" : "obj-16"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"numoutlets" : 0,
					"patching_rect" : [ 1012.0, 228.0, 187.0, 107.0 ],
					"grad1" : [ 0.403922, 0.701961, 0.109804, 1.0 ],
					"presentation" : 1,
					"border" : 2,
					"grad2" : [ 0.521569, 0.866667, 0.0, 1.0 ],
					"angle" : 270.0,
					"bgcolor" : [ 0.5, 0.0, 0.0, 1.0 ],
					"bordercolor" : [ 0.501961, 0.501961, 0.501961, 0.0 ],
					"presentation_rect" : [ 532.0, 10.0, 166.0, 31.0 ],
					"numinlets" : 1,
					"id" : "obj-213"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"numoutlets" : 0,
					"patching_rect" : [ 1060.0, 232.0, 187.0, 107.0 ],
					"grad1" : [ 0.403922, 0.701961, 0.109804, 1.0 ],
					"presentation" : 1,
					"mode" : 1,
					"border" : 2,
					"grad2" : [ 0.521569, 0.866667, 0.0, 1.0 ],
					"angle" : 187.0,
					"bordercolor" : [ 0.501961, 0.501961, 0.501961, 0.0 ],
					"presentation_rect" : [ 532.0, 10.0, 166.0, 31.0 ],
					"numinlets" : 1,
					"id" : "obj-210"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"numoutlets" : 0,
					"patching_rect" : [ 558.0, 1152.0, 695.0, 152.0 ],
					"grad1" : [ 0.517647, 0.517647, 0.517647, 1.0 ],
					"presentation" : 1,
					"mode" : 1,
					"grad2" : [ 0.376471, 0.376471, 0.376471, 1.0 ],
					"angle" : 74.590027,
					"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"presentation_rect" : [ 8.0, 492.0, 689.0, 117.0 ],
					"numinlets" : 1,
					"id" : "obj-104"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"numoutlets" : 0,
					"patching_rect" : [ 272.0, 766.0, 692.0, 153.0 ],
					"grad1" : [ 1.0, 0.8, 0.0, 1.0 ],
					"presentation" : 1,
					"mode" : 1,
					"grad2" : [ 1.0, 0.701961, 0.0, 1.0 ],
					"angle" : 74.590027,
					"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"presentation_rect" : [ 357.0, 50.0, 340.0, 58.0 ],
					"numinlets" : 1,
					"id" : "obj-179"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"numoutlets" : 0,
					"patching_rect" : [ 287.0, 781.0, 692.0, 153.0 ],
					"grad1" : [ 1.0, 0.8, 0.0, 1.0 ],
					"presentation" : 1,
					"mode" : 1,
					"grad2" : [ 1.0, 0.701961, 0.0, 1.0 ],
					"angle" : 74.590027,
					"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"presentation_rect" : [ 8.0, 50.0, 346.0, 58.0 ],
					"numinlets" : 1,
					"id" : "obj-217"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-111", 1 ],
					"destination" : [ "obj-8", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-135", 1 ],
					"destination" : [ "obj-6", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-134", 0 ],
					"destination" : [ "obj-135", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-116", 0 ],
					"destination" : [ "obj-111", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-136", 0 ],
					"destination" : [ "obj-108", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-108", 0 ],
					"destination" : [ "obj-134", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-108", 0 ],
					"destination" : [ "obj-116", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-46", 0 ],
					"destination" : [ "obj-29", 57 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-45", 0 ],
					"destination" : [ "obj-29", 56 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-125", 0 ],
					"destination" : [ "obj-29", 21 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-118", 0 ],
					"destination" : [ "obj-29", 49 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-119", 0 ],
					"destination" : [ "obj-29", 48 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-120", 0 ],
					"destination" : [ "obj-29", 47 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-121", 0 ],
					"destination" : [ "obj-29", 46 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-122", 0 ],
					"destination" : [ "obj-29", 45 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-123", 0 ],
					"destination" : [ "obj-29", 44 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-124", 0 ],
					"destination" : [ "obj-29", 43 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-117", 0 ],
					"destination" : [ "obj-29", 17 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-93", 0 ],
					"destination" : [ "obj-29", 42 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-94", 0 ],
					"destination" : [ "obj-29", 41 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-95", 0 ],
					"destination" : [ "obj-29", 40 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-96", 0 ],
					"destination" : [ "obj-29", 39 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-97", 0 ],
					"destination" : [ "obj-29", 38 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-98", 0 ],
					"destination" : [ "obj-29", 37 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-99", 0 ],
					"destination" : [ "obj-29", 36 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-92", 0 ],
					"destination" : [ "obj-29", 16 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-100", 0 ],
					"destination" : [ "obj-29", 20 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-88", 0 ],
					"destination" : [ "obj-29", 19 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-80", 0 ],
					"destination" : [ "obj-29", 35 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-81", 0 ],
					"destination" : [ "obj-29", 34 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-82", 0 ],
					"destination" : [ "obj-29", 33 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-84", 0 ],
					"destination" : [ "obj-29", 32 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-85", 0 ],
					"destination" : [ "obj-29", 31 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-86", 0 ],
					"destination" : [ "obj-29", 30 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-87", 0 ],
					"destination" : [ "obj-29", 29 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-70", 0 ],
					"destination" : [ "obj-29", 28 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-68", 0 ],
					"destination" : [ "obj-29", 27 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-64", 0 ],
					"destination" : [ "obj-29", 26 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-66", 0 ],
					"destination" : [ "obj-29", 25 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-62", 0 ],
					"destination" : [ "obj-29", 24 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-60", 0 ],
					"destination" : [ "obj-29", 23 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-59", 0 ],
					"destination" : [ "obj-29", 22 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-56", 0 ],
					"destination" : [ "obj-29", 18 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 0 ],
					"destination" : [ "obj-29", 4 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-7", 0 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-21", 0 ],
					"destination" : [ "obj-29", 3 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-33", 0 ],
					"destination" : [ "obj-29", 2 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 0 ],
					"destination" : [ "obj-29", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-50", 0 ],
					"destination" : [ "obj-29", 6 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-91", 0 ],
					"destination" : [ "obj-29", 7 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-103", 0 ],
					"destination" : [ "obj-29", 8 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-128", 0 ],
					"destination" : [ "obj-29", 9 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-53", 0 ],
					"destination" : [ "obj-29", 10 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-89", 0 ],
					"destination" : [ "obj-29", 11 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-101", 0 ],
					"destination" : [ "obj-29", 12 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-126", 0 ],
					"destination" : [ "obj-29", 13 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-79", 0 ],
					"destination" : [ "obj-29", 15 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-76", 0 ],
					"destination" : [ "obj-29", 14 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-183", 0 ],
					"destination" : [ "obj-29", 50 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-187", 0 ],
					"destination" : [ "obj-29", 51 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-189", 0 ],
					"destination" : [ "obj-29", 52 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-191", 0 ],
					"destination" : [ "obj-29", 53 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-193", 0 ],
					"destination" : [ "obj-29", 54 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-199", 0 ],
					"destination" : [ "obj-29", 55 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-14", 0 ],
					"destination" : [ "obj-46", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-44", 0 ],
					"destination" : [ "obj-45", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-2", 0 ],
					"destination" : [ "obj-43", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 0 ],
					"destination" : [ "obj-2", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 0 ],
					"destination" : [ "obj-37", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-234", 0 ],
					"destination" : [ "obj-233", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-211", 0 ],
					"destination" : [ "obj-214", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-214", 0 ],
					"destination" : [ "obj-213", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-209", 0 ],
					"destination" : [ "obj-210", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-207", 0 ],
					"destination" : [ "obj-206", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-205", 0 ],
					"destination" : [ "obj-207", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-202", 0 ],
					"destination" : [ "obj-199", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-197", 0 ],
					"destination" : [ "obj-183", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-196", 0 ],
					"destination" : [ "obj-187", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-195", 0 ],
					"destination" : [ "obj-189", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-194", 0 ],
					"destination" : [ "obj-191", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-72", 0 ],
					"destination" : [ "obj-193", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-172", 0 ],
					"destination" : [ "obj-118", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-173", 0 ],
					"destination" : [ "obj-119", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-174", 0 ],
					"destination" : [ "obj-120", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-175", 0 ],
					"destination" : [ "obj-121", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-176", 0 ],
					"destination" : [ "obj-122", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-177", 0 ],
					"destination" : [ "obj-123", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-165", 0 ],
					"destination" : [ "obj-93", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-166", 0 ],
					"destination" : [ "obj-94", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-167", 0 ],
					"destination" : [ "obj-95", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-168", 0 ],
					"destination" : [ "obj-96", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-169", 0 ],
					"destination" : [ "obj-97", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-170", 0 ],
					"destination" : [ "obj-98", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-178", 0 ],
					"destination" : [ "obj-124", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-171", 0 ],
					"destination" : [ "obj-99", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-158", 0 ],
					"destination" : [ "obj-80", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-159", 0 ],
					"destination" : [ "obj-81", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-160", 0 ],
					"destination" : [ "obj-82", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-161", 0 ],
					"destination" : [ "obj-84", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-162", 0 ],
					"destination" : [ "obj-85", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-163", 0 ],
					"destination" : [ "obj-86", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-164", 0 ],
					"destination" : [ "obj-87", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-42", 0 ],
					"destination" : [ "obj-59", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-145", 0 ],
					"destination" : [ "obj-60", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-144", 0 ],
					"destination" : [ "obj-62", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-143", 0 ],
					"destination" : [ "obj-66", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-142", 0 ],
					"destination" : [ "obj-64", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-141", 0 ],
					"destination" : [ "obj-68", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-157", 0 ],
					"destination" : [ "obj-70", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-150", 0 ],
					"destination" : [ "obj-117", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-30", 0 ],
					"destination" : [ "obj-92", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-31", 0 ],
					"destination" : [ "obj-79", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-151", 0 ],
					"destination" : [ "obj-76", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-149", 0 ],
					"destination" : [ "obj-56", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-148", 0 ],
					"destination" : [ "obj-88", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-147", 0 ],
					"destination" : [ "obj-100", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-146", 0 ],
					"destination" : [ "obj-125", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-152", 0 ],
					"destination" : [ "obj-126", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-153", 0 ],
					"destination" : [ "obj-101", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-27", 0 ],
					"destination" : [ "obj-89", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-28", 0 ],
					"destination" : [ "obj-53", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-156", 0 ],
					"destination" : [ "obj-50", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-155", 0 ],
					"destination" : [ "obj-91", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-154", 0 ],
					"destination" : [ "obj-103", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-24", 0 ],
					"destination" : [ "obj-128", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-40", 0 ],
					"destination" : [ "obj-33", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-26", 0 ],
					"destination" : [ "obj-25", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-20", 0 ],
					"destination" : [ "obj-21", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-235", 0 ],
					"destination" : [ "obj-7", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-17", 0 ],
					"destination" : [ "obj-18", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-107", 0 ],
					"destination" : [ "obj-78", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-78", 0 ],
					"destination" : [ "obj-7", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 0 ],
					"destination" : [ "obj-115", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-115", 0 ],
					"destination" : [ "obj-17", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-18", 0 ],
					"destination" : [ "obj-43", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-111", 1 ],
					"destination" : [ "obj-234", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-135", 1 ],
					"destination" : [ "obj-234", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 0 ],
					"destination" : [ "obj-11", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-83", 0 ],
					"destination" : [ "obj-8", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
