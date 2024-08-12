.set LOCALID_WINGULL, 3

FortreeCity_House4_MapScripts::
	.byte 0

FortreeCity_House4_EventScript_Woman::
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
	end

FortreeCity_House4_EventScript_Boy::
	lockall
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, FortreeCity_House4_EventScript_WingullReturned
	goto_if_set FLAG_WINGULL_SENT_ON_ERRAND, FortreeCity_House4_EventScript_WingullOnErrand
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_WINGULL_SENT_ON_ERRAND
	clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL
	applymovement LOCALID_WINGULL, FortreeCity_House4_Movement_WingullExit
	waitmovement 0
	removeobject LOCALID_WINGULL
	releaseall
	end

FortreeCity_House4_EventScript_WingullOnErrand::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_AskedWingullToRunErrand, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_EventScript_WingullReturned::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb, MSGBOX_DEFAULT
	giveitem ITEM_MENTAL_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_ReceivedMentalHerb::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToWingull, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_Movement_WingullExit:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	delay_8
	step_end

FortreeCity_House4_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox FortreeCity_House4_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House4_Text_BringsWorldCloserTogether:
	.ifdef ENGLISH
	.string "By being together with POKéMON,\n"
	.string "people make more and more friends.\p"
	.string "And that brings the world closer\n"
	.string "together. I think it's wonderful!$"
	.else
	.ifdef GERMAN
	.string "Wenn sie mit POKéMON zusammen sind,\n"
	.string "finden die Menschen schnell Freunde.\p"
	.string "Und so rücken die Menschen weltweit\n"
	.string "näher zusammen. Wunderbar, nicht wahr?$"
	.endif
	.endif

FortreeCity_House4_Text_GoBirdPokemon:
	.ifdef ENGLISH
	.string "There!\n"
	.string "Go, BIRD POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Fertig!\n"
	.string "Los, VOGEL-POKéMON!$"
	.endif
	.endif

FortreeCity_House4_Text_AskedWingullToRunErrand:
	.ifdef ENGLISH
	.string "Heheh, I asked my WINGULL to run\n"
	.string "an errand for me.$"
	.else
	.ifdef GERMAN
	.string "Hähähä, mein WINGULL macht\n"
	.string "Besorgungen für mich.$"
	.endif
	.endif

FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb:
	.ifdef ENGLISH
	.string "Good!\n"
	.string "Welcome back, WINGULL!\p"
	.string "Huh? What is this?\n"
	.string "What is it holding?\p"
	.string "A MENTAL HERB?\n"
	.string "It must have picked it up somewhere.\p"
	.string "But I'm not a TRAINER, so you can\n"
	.string "have it.$"
	.else
	.ifdef GERMAN
	.string "Gut!\n"
	.string "Komm zurück, WINGULL!\p"
	.string "Huch! Was ist das?\n"
	.string "Was trägt es denn da?\p"
	.string "Ein MENTALKRAUT?\n"
	.string "Das muss es irgendwo gefunden haben.\p"
	.string "Aber, ich bin kein TRAINER, daher kannst\n"
	.string "du es haben.$"
	.endif
	.endif

FortreeCity_House4_Text_FriendsFarAwayThanksToWingull:
	.ifdef ENGLISH
	.string "Thanks to my WINGULL, I have friends\n"
	.string "who live far away.$"
	.else
	.ifdef GERMAN
	.string "Dank meines WINGULL habe ich Freunde,\n"
	.string "die sehr weit weg von hier wohnen.$"
	.endif
	.endif

FortreeCity_House4_Text_Wingull:
	.ifdef ENGLISH
	.string "WINGULL: Pihyoh!$"
	.else
	.ifdef GERMAN
	.string "WINGULL: Pihyoh!$"
	.endif
	.endif

