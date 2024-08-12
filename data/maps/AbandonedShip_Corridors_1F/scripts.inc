AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
	.ifdef ENGLISH
	.string "What's so funny about having my inner\n"
	.string "tube aboard the ship?$"
	.else
	.ifdef GERMAN
	.string "Was ist so lustig daran, dass ich meinen\n"
	.string "Schwimmreifen mit an Bord habe?$"
	.endif
	.endif

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.ifdef ENGLISH
	.string "Whoa, you overwhelmed me!$"
	.else
	.ifdef GERMAN
	.string "Hui, du hast mir die Luft rausgelassen!$"
	.endif
	.endif

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.ifdef ENGLISH
	.string "It's not easy throwing POKé BALLS\n"
	.string "while hanging on to an inner tube!$"
	.else
	.ifdef GERMAN
	.string "Es ist gar nicht so einfach, POKéBÄLLe\n"
	.string "zu werfen, wenn man einen Schwimmreifen\l"
	.string "trägt!$"
	.endif
	.endif

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.ifdef ENGLISH
	.string "Isn't it fun here?\n"
	.string "I get excited just being here!$"
	.else
	.ifdef GERMAN
	.string "Hier ist es doch wirklich lustig, nicht\n"
	.string "wahr? Ich bin total aufgeregt.$"
	.endif
	.endif
