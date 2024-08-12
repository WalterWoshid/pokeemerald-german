VerdanturfTown_House_MapScripts::
	.byte 0

VerdanturfTown_House_EventScript_Woman1::
	msgbox VerdanturfTown_House_Text_TrainersGatherAtPokemonLeague, MSGBOX_NPC
	end

VerdanturfTown_House_EventScript_Woman2::
	msgbox VerdanturfTown_House_Text_DefeatEliteFourInARow, MSGBOX_NPC
	end

VerdanturfTown_House_Text_TrainersGatherAtPokemonLeague:
	.ifdef ENGLISH
	.string "Far away, deep in EVER GRANDE CITY,\n"
	.string "is the POKéMON LEAGUE.\p"
	.string "The TRAINERS who gather there are\n"
	.string "all frighteningly well skilled.$"
	.else
	.ifdef GERMAN
	.string "Weit von hier, in PRACHTPOLIS CITY,\n"
	.string "findest du die POKéMON LIGA.\p"
	.string "Die TRAINER dort sind alle geradezu\n"
	.string "Furcht erregend talentiert.$"
	.endif
	.endif

VerdanturfTown_House_Text_DefeatEliteFourInARow:
	.ifdef ENGLISH
	.string "In the POKéMON LEAGUE, I think the\n"
	.string "rules say that you have to battle the\l"
	.string "ELITE FOUR all in a row.\p"
	.string "If you lose to any of them, you have\n"
	.string "to begin your challenge again from the\l"
	.string "first one.$"
	.else
	.ifdef GERMAN
	.string "In der POKéMON LIGA musst du die TOP\n"
	.string "VIER hintereinander besiegen. Das\l"
	.string "sagen die Regeln.\p"
	.string "Wenn du gegen einen dieser TRAINER\n"
	.string "verlierst, musst du die Herausforderung\l"
	.string "von vorne beginnen.$"
	.endif
	.endif

