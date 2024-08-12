SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.ifdef ENGLISH
	.string "Listen up, and I'll tell you something\n"
	.string "good.\p"
	.string "There's supposed to be an ancient\n"
	.string "ruin in the sea around here.\p"
	.string "There could be treasures just waiting\n"
	.string "to be discovered down there.$"
	.else
	.ifdef GERMAN
	.string "Hör mir zu und ich verrate dir etwas.\p"
	.string "Unter Wasser soll sich eine antike\n"
	.string "Ruine befinden.\p"
	.string "Da gibt es bestimmt Schätze, die nur\n"
	.string "darauf warten, gehoben zu werden.$"
	.endif
	.endif

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.ifdef ENGLISH
	.string "Ancient treasures…\p"
	.string "It would be nice if they existed, but\n"
	.string "even if they didn't, it would be so\l"
	.string "beautiful to take an underwater\l"
	.string "stroll with my POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Antike Schätze…\p"
	.string "Wäre das schön, wenn es die tatsächlich\n"
	.string "gäbe. Aber auch ohne Schätze wäre eine\p"
	.string "Reise unter Wasser zusammen mit\n"
	.string "meinen POKéMON herrlich.$"
	.endif
	.endif

SootopolisCity_House4_Text_Azumarill:
	.ifdef ENGLISH
	.string "AZUMARILL: Marurii.$"
	.else
	.ifdef GERMAN
	.string "AZUMARILL: Marurii.$"
	.endif
	.endif

