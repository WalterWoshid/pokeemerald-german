GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.ifdef ENGLISH
	.string "Hey, you.\n"
	.string "It gets awfully dark ahead.\l"
	.string "It'll be tough trying to explore.\p"
	.string "That guy who came by earlier…\n"
	.string "STEVEN, I think it was.\p"
	.string "He knew how to use FLASH, so he ought\n"
	.string "to be all right, but…\p"
	.string "Well, for us HIKERS, helping out those\n"
	.string "that we meet is our motto.\p"
	.string "Here you go, I'll pass this on to you.$"
	.else
	.ifdef GERMAN
	.string "Hey, du!\n"
	.string "Hier ist es schrecklich dunkel.\l"
	.string "Eine Erforschung wird damit schwierig.\p"
	.string "Der Typ, der vorher schon mal hier war…\n"
	.string "TROY heißt er, glaube ich…\p"
	.string "Der weiß, wie man BLITZ einsetzt, daher\n"
	.string "wird es ihm wohl gut gehen, aber…\p"
	.string "Das Motto unter uns WANDERERn heißt:\n"
	.string "Jedem aus der Klemme helfen.\p"
	.string "Deshalb bekommst du dies von mir.$"
	.endif
	.endif

GraniteCave_1F_Text_ExplainFlash:
	.ifdef ENGLISH
	.string "Teach that hidden move FLASH to\n"
	.string "a POKéMON and use it.\p"
	.string "It lights up even the inky darkness\n"
	.string "of caves.\p"
	.string "But, to use it, you need the GYM BADGE\n"
	.string "from DEWFORD's POKéMON GYM.$"
	.else
	.ifdef GERMAN
	.string "Bringe einem POKéMON die VM BLITZ\n"
	.string "bei und setze sie ein.\p"
	.string "Damit wird selbst die dunkelste Höhle\n"
	.string "von Licht erfüllt.\p"
	.string "Aber um das zu können, brauchst du den\n"
	.string "ORDEN der ARENA von FAUSTAUHAVEN.$"
	.endif
	.endif

