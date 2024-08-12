SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.ifdef ENGLISH
	.string "Who are you?\n"
	.string "Where did you come in from?$"
	.else
	.ifdef GERMAN
	.string "Wer bist du?\n"
	.string "Woher kommst du?$"
	.endif
	.endif

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.ifdef ENGLISH
	.string "Lost it…$"
	.else
	.ifdef GERMAN
	.string "Verloren…$"
	.endif
	.endif

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.ifdef ENGLISH
	.string "I can't find the way out!\p"
	.string "I'm not afraid. Don't get me wrong!$"
	.else
	.ifdef GERMAN
	.string "Ich finde den Ausgang nicht mehr!\p"
	.string "Ich bin nicht verzweifelt. Denk das\n"
	.string "bloß nicht!$"
	.endif
	.endif

SeafloorCavern_Room4_Text_Grunt4Intro:
	.ifdef ENGLISH
	.string "Who are you?\n"
	.string "Where do you think you're going?$"
	.else
	.ifdef GERMAN
	.string "Wer bist du?\n"
	.string "Was meinst du, was du da machst?$"
	.endif
	.endif

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.ifdef ENGLISH
	.string "I failed to win!$"
	.else
	.ifdef GERMAN
	.string "Ich konnte nicht gewinnen!$"
	.endif
	.endif

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.ifdef ENGLISH
	.string "My partner forgot the map in that\n"
	.string "submarine!\p"
	.string "How's that for being useless?$"
	.else
	.ifdef GERMAN
	.string "Mein Partner hat die Karte im U-Boot\n"
	.string "liegen gelassen.\p"
	.string "Wie kann man nur so nutzlos sein?$"
	.endif
	.endif

