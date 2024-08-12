MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.ifdef ENGLISH
	.string "I understand everything our leader\n"
	.string "says. But you know what?\p"
	.string "Doing stuff like digging up a super-\n"
	.string "ancient POKéMON and ripping off\l"
	.string "someone's METEORITE…\p"
	.string "I think we're going a little too far.\n"
	.string "What do you think?$"
	.else
	.ifdef GERMAN
	.string "Ich verstehe alles, was unser Boss\n"
	.string "sagt. Aber weißt du, was?\p"
	.string "Nach einem uralten POKéMON zu\n"
	.string "graben und jemandem einen METEORITen\l"
	.string "stehlen…\p"
	.string "Ich glaube, wir sind etwas zu weit\n"
	.string "gegangen. Was meinst du?$"
	.endif
	.endif

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.ifdef ENGLISH
	.string "Yeah, I think we are doing something\n"
	.string "wrong somehow.$"
	.else
	.ifdef GERMAN
	.string "Yeah, ich denke wirklich, was wir\n"
	.string "machen, ist falsch.$"
	.endif
	.endif

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.ifdef ENGLISH
	.string "You know, losing to you cleared my mind.\p"
	.string "The next time I see our leader,\n"
	.string "I'm going to ask him about what we do.$"
	.else
	.ifdef GERMAN
	.string "Die Niederlage gegen dich hat meinen\n"
	.string "Verstand gereinigt.\p"
	.string "Nächstes Mal, wenn ich ihn sehe, werde\n"
	.string "ich meinen Boss fragen, was wir hier\l"
	.string "eigentlich machen.$"
	.endif
	.endif

