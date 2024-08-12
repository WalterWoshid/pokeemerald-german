Route119_House_MapScripts::
	.byte 0

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_Text_RumorAboutCaveOfOrigin:
	.ifdef ENGLISH
	.string "I heard about a cave called the CAVE\n"
	.string "OF ORIGIN.\p"
	.string "People rumor that the spirits of\n"
	.string "POKéMON are revived there. Could\l"
	.string "something like that really happen?$"
	.else
	.ifdef GERMAN
	.string "Es soll eine Höhle geben - die\n"
	.string "URZEITHÖHLE.\p"
	.string "Die Menschen erzählen sich, dass dort\n"
	.string "die Geister der POKéMON wieder zum\l"
	.string "Leben erweckt werden.\l"
	.string "Ob das tatsächlich möglich ist?$"
	.endif
	.endif

Route119_House_Text_Wingull:
	.ifdef ENGLISH
	.string "WINGULL: Pihyoh!$"
	.else
	.ifdef GERMAN
	.string "WINGULL: Pihyoh!$"
	.endif
	.endif

