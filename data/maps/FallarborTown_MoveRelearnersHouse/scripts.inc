.set LOCALID_MOVE_RELEARNER, 1

FallarborTown_MoveRelearnersHouse_MapScripts::
	.byte 0

FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	end

FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor:
	.ifdef ENGLISH
	.string "I'm the MOVE TUTOR.\p"
	.string "I know all the moves that POKéMON\n"
	.string "learn--every one of them--and I can\l"
	.string "teach POKéMON those moves.\p"
	.string "I can teach a move to a POKéMON\n"
	.string "of yours if you'd like.\p"
	.string "I'll do it for a HEART SCALE.\n"
	.string "I'm collecting those now.$"
	.else
	.ifdef GERMAN
	.string "Ich bin der ATTACKEN-HELFER.\p"
	.string "Ich kenne alle Attacken, die ein\n"
	.string "POKéMON lernen kann - und ich kann sie\l"
	.string "ihnen beibringen.\p"
	.string "Ich kann auch deinen POKéMON neue\n"
	.string "Attacken beibringen, wenn du magst.\p"
	.string "Als Gegenleistung hätte ich gerne eine\n"
	.string "HERZSCHUPPE. Die sammle ich nämlich.$"
	.endif
	.endif

FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
	.ifdef ENGLISH
	.string "Oh! That's it! That's an honest to\n"
	.string "goodness HEART SCALE!\p"
	.string "Let me guess, you want me to teach\n"
	.string "a move?$"
	.else
	.ifdef GERMAN
	.string "Oh! Das ist es! Das ist ehrlich und\n"
	.string "wahrhaftig eine HERZSCHUPPE!\p"
	.string "Lass mich raten… Ich soll einem POKéMON\n"
	.string "eine neue Attacke beibringen?!?$"
	.endif
	.endif

FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon:
	.ifdef ENGLISH
	.string "Which POKéMON needs tutoring?$"
	.else
	.ifdef GERMAN
	.string "Welches POKéMON soll sie lernen?$"
	.endif
	.endif

FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove:
	.ifdef ENGLISH
	.string "Which move should I teach?$"
	.else
	.ifdef GERMAN
	.string "Welche Attacke soll ich es lehren?$"
	.endif
	.endif

FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.ifdef ENGLISH
	.string "Sorry…\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Tut mir Leid…\p"
	.string "Scheinbar gibt es keine Attacke, die ich\n"
	.string "diesem POKéMON beibringen kann.$"
	.endif
	.endif

FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale:
	.ifdef ENGLISH
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} tauscht eine HERZSCHUPPE ein.$"
	.endif
	.endif

FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
	.ifdef ENGLISH
	.string "If your POKéMON need to learn a move,\n"
	.string "come back with a HEART SCALE.$"
	.else
	.ifdef GERMAN
	.string "Falls deine POKéMON neue Attacken\n"
	.string "lernen sollen, komm mit einer\l"
	.string "HERZSCHUPPE wieder.$"
	.endif
	.endif

FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg:
	.ifdef ENGLISH
	.string "Hunh? There isn't a single move that\n"
	.string "I can teach an EGG.$"
	.else
	.ifdef GERMAN
	.string "Bitte? Ich kann einem EI nicht eine\n"
	.string "einzige Attacke beibringen!$"
	.endif
	.endif

