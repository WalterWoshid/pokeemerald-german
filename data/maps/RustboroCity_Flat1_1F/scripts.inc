RustboroCity_Flat1_1F_MapScripts::
	.byte 0

RustboroCity_Flat1_1F_EventScript_Man::
	msgbox RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_EventScript_Woman::
	msgbox RustboroCity_Flat1_1F_Text_PokemonStrange, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility:
	.ifdef ENGLISH
	.string "Every POKéMON has a special ability\n"
	.string "that it can use.$"
	.else
	.ifdef GERMAN
	.string "Jedes POKéMON besitzt eine spezielle\n"
	.string "Begabung, die es einsetzen kann.$"
	.endif
	.endif

RustboroCity_Flat1_1F_Text_PokemonStrange:
	.ifdef ENGLISH
	.string "POKéMON are such strange creatures.$"
	.else
	.ifdef GERMAN
	.string "POKéMON sind sehr seltsame Geschöpfe.$"
	.endif
	.endif

