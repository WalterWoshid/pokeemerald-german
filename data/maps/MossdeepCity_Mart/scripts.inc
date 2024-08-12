MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_NONE
	release
	end

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.ifdef ENGLISH
	.string "REVIVE is fantastic!\p"
	.string "Give it to a fainted POKéMON,\n"
	.string "and the POKéMON will arise.\p"
	.string "But be careful, REVIVE doesn't restore\n"
	.string "the used-up PP of moves.$"
	.else
	.ifdef GERMAN
	.string "BELEBER ist einfach fantastisch!\p"
	.string "Gib es einem besiegten POKéMON und\n"
	.string "es ist wieder fit.\p"
	.string "Aber Vorsicht! BELEBER füllt nicht die\n"
	.string "verbrauchten AP neu auf!$"
	.endif
	.endif

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.ifdef ENGLISH
	.string "MAX REPEL keeps all weak POKéMON away.\p"
	.string "Out of all the REPEL sprays, it lasts\n"
	.string "the longest.$"
	.else
	.ifdef GERMAN
	.string "TOP-SCHUTZ hält alle schwachen\n"
	.string "POKéMON auf Distanz.\p"
	.string "Von allen SCHUTZ-Sprays hält dieses am\n"
	.string "längsten an.$"
	.endif
	.endif

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.ifdef ENGLISH
	.string "The NET and DIVE BALLS are rare POKé\n"
	.string "BALLS that are only made in MOSSDEEP.\p"
	.string "A NET BALL is effective against\n"
	.string "BUG-type and WATER-type POKéMON.\p"
	.string "A DIVE BALL works best on POKéMON\n"
	.string "at the bottom of the sea.$"
	.else
	.ifdef GERMAN
	.string "Der NETZ- und der TAUCHBALL sind\n"
	.string "seltene POKéBÄLLe, die in\l"
	.string "MOOSBACH CITY hergestellt werden.\p"
	.string "Ein NETZBALL ist höchst wirkungsvoll\n"
	.string "bei KÄFER- und WASSER-POKéMON.\p"
	.string "Der TAUCHBALL ist wirkungsvoll bei\n"
	.string "POKéMON, die in der Tiefsee leben.$"
	.endif
	.endif

