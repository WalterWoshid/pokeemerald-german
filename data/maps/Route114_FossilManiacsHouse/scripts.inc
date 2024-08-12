Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.ifdef ENGLISH
	.string "My big brother's the FOSSIL MANIAC…\n"
	.string "He's a nice guy who loves FOSSILS…\p"
	.string "He loves digging holes, too…\n"
	.string "He dug this hole by himself…\p"
	.string "You can have this, so you can DIG\n"
	.string "holes just like my big brother…$"
	.else
	.ifdef GERMAN
	.string "Mein großer Bruder ist ein FOSSIL-\n"
	.string "MANIAC… Er ist ein netter Kerl, der\l"
	.string "Fossilien liebt…\p"
	.string "Er liebt es auch, Löcher zu graben…\n"
	.string "Dieses Loch hat er alleine gegraben!\p"
	.string "Hier, das kannst du haben. Damit kannst\n"
	.string "du Löcher graben, wie mein Bruder…$"
	.endif
	.endif

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.ifdef ENGLISH
	.string "If you make a POKéMON DIG inside a\n"
	.string "cave, you're returned to the entrance…$"
	.else
	.ifdef GERMAN
	.string "Wenn ein POKéMON in einer Höhle\n"
	.string "SCHAUFLER einsetzt, kommst du zum\l"
	.string "Eingang zurück.$"
	.endif
	.endif

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.ifdef ENGLISH
	.string "Rocks in peculiar shapes fill\n"
	.string "the display case…$"
	.else
	.ifdef GERMAN
	.string "Steine in den unterschiedlichsten\n"
	.string "Formen liegen im Glasschaukasten.$"
	.endif
	.endif

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.ifdef ENGLISH
	.string "THE COMPOSITION OF STRATA…\n"
	.string "HOW RAIN SHAPES THE LAND…\l"
	.string "STONES, SOIL, AND ROCK…\p"
	.string "It's crammed with books.$"
	.else
	.ifdef GERMAN
	.string "DIE ZUSAMMENSETZUNG DER ERDSCHICHT…\n"
	.string "WIE REGEN DAS LAND FORMT…\l"
	.string "STEINE, BODEN UND FELSEN…\p"
	.string "Gerammelt voll mit Büchern.$"
	.endif
	.endif

