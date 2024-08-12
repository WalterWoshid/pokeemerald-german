.set LOCALID_STEVEN, 1

GraniteCave_StevensRoom_MapScripts::
	.byte 0

GraniteCave_StevensRoom_EventScript_Steven::
	lock
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_STEEL_WING
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_STEVEN_POKENAV
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_StevensRoom_EventScript_StevenExitNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_StevensRoom_EventScript_StevenExitSouth
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	playse SE_EXIT
	removeobject LOCALID_STEVEN
	release
	end

GraniteCave_StevensRoom_EventScript_StevenExitNorth::
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitWestEast::
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitSouth::
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_BagFull::
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Text_ImStevenLetterForMe:
	.ifdef ENGLISH
	.string "My name is STEVEN.\p"
	.string "I'm interested in rare stones,\n"
	.string "so I travel here and there.\p"
	.string "Oh?\n"
	.string "A LETTER for me?$"
	.else
	.ifdef GERMAN
	.string "Mein Name ist TROY.\p"
	.string "Ich sammle seltene Steine, daher gehe\n"
	.string "ich immer mal wieder auf Reisen.\p"
	.string "Oh?\n"
	.string "Ein BRIEF? Für mich?$"
	.endif
	.endif

GraniteCave_StevensRoom_Text_ThankYouTakeThis:
	.ifdef ENGLISH
	.string "STEVEN: Okay, thank you.\p"
	.string "You went through all this trouble to\n"
	.string "deliver that. I need to thank you.\p"
	.string "Let me see…\n"
	.string "I'll give you this TM.\p"
	.string "It contains my favorite move,\n"
	.string "STEEL WING.$"
	.else
	.ifdef GERMAN
	.string "TROY: Okay, danke schön.\p"
	.string "Du hast all die Beschwerlichkeiten auf\n"
	.string "dich genommen, um ihn mir zu bringen.\p"
	.string "Ich muss mich bedanken. Ehrlich.\n"
	.string "Ich werde dir diese TM geben.\p"
	.string "Sie enthält meine Lieblingsattacke,\n"
	.string "STAHLFLÜGEL.$"
	.endif
	.endif

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
	.ifdef ENGLISH
	.string "STEVEN: Your POKéMON appear quite\n"
	.string "capable.\p"
	.string "If you keep training, you could even\n"
	.string "become the CHAMPION of the POKéMON\l"
	.string "LEAGUE one day. That's what I think.\p"
	.string "I know, since we've gotten to know each\n"
	.string "other, let's register one another in\l"
	.string "our POKéNAVS.\p"
	.string "… … … … … …$"
	.else
	.ifdef GERMAN
	.string "TROY: Deine POKéMON sehen recht\n"
	.string "talentiert aus.\p"
	.string "Wenn du fleißig trainierst, wirst du\n"
	.string "vielleicht eines Tages der CHAMP der\l"
	.string "POKéMON LIGA. Das ist meine Meinung.\p"
	.string "Und da wir uns jetzt so gut kennen\n"
	.string "gelernt haben, sollten wir uns in\l"
	.string "unseren POKéNAVs eintragen.\p"
	.string "… … … … …\n"
	.string "…$"
	.endif
	.endif

GraniteCave_StevensRoom_Text_RegisteredSteven:
	.ifdef ENGLISH
	.string "Registered STEVEN\n"
	.string "in the POKéNAV.$"
	.else
	.ifdef GERMAN
	.string "TROY wurde im POKéNAV-Verzeichnis\n"
	.string "eingetragen.$"
	.endif
	.endif

GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
	.ifdef ENGLISH
	.string "Now, I've got to hurry along.$"
	.else
	.ifdef GERMAN
	.string "Nun muss ich mich aber wirklich beeilen.$"
	.endif
	.endif

GraniteCave_StevensRoom_Text_OhBagIsFull:
	.ifdef ENGLISH
	.string "Oh, your BAG is full…\n"
	.string "That's too bad, then.$"
	.else
	.ifdef GERMAN
	.string "Oh, dein BEUTEL ist voll.\n"
	.string "Das ist aber wirklich schade.$"
	.endif
	.endif

