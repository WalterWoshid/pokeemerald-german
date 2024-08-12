SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.ifdef ENGLISH
	.string "We don't need a kid around!\n"
	.string "Go on home already!$"
	.else
	.ifdef GERMAN
	.string "Wir können hier keine Kinder\n"
	.string "gebrauchen! Geh nach Hause! Sofort!$"
	.endif
	.endif

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.ifdef ENGLISH
	.string "I want to go home…$"
	.else
	.ifdef GERMAN
	.string "Ich will nach Hause zu meiner Mami…$"
	.endif
	.endif

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.ifdef ENGLISH
	.string "I want to get a promotion so I can\n"
	.string "boss around the GRUNTS…$"
	.else
	.ifdef GERMAN
	.string "Ich möchte befördert werden, dann kann\n"
	.string "ich all die RÜPEL herumkommandieren!$"
	.endif
	.endif

SeafloorCavern_Room1_Text_Grunt2Intro:
	.ifdef ENGLISH
	.string "That submarine… It's tiny inside.\n"
	.string "I'm sore all over!$"
	.else
	.ifdef GERMAN
	.string "Dieses U-Boot… Es ist sehr eng.\n"
	.string "Ich habe deshalb überall blaue Flecken.$"
	.endif
	.endif

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.ifdef ENGLISH
	.string "Losing makes me sore!$"
	.else
	.ifdef GERMAN
	.string "Verlieren verursacht bei mir\n"
	.string "Muskelkater!$"
	.endif
	.endif

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.ifdef ENGLISH
	.string "That submarine we jacked, man,\n"
	.string "it's brutal as a ride.\l"
	.string "It's way too tight in there!$"
	.else
	.ifdef GERMAN
	.string "Das U-Boot, das wir aufgetrieben haben,\n"
	.string "ist fürchterlich eng. Brutal eng, sage\l"
	.string "ich. Man stößt sich überall den Kopf.$"
	.endif
	.endif

