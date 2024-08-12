.set LOCALID_NURSE, 1

RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.ifdef ENGLISH
	.string "My POKéMON has a NAIVE nature, and my\n"
	.string "friend's has a JOLLY nature.\p"
	.string "It's fascinating how POKéMON have\n"
	.string "personalities!$"
	.else
	.ifdef GERMAN
	.string "Mein POKéMON hat ein NAIVes\n"
	.string "Wesen und das meines Freundes ein\l"
	.string "FRÖHLICHes.\p"
	.string "Es ist faszinierend, dass POKéMON\n"
	.string "unterschiedliche Persönlichkeiten\l"
	.string "haben.$"
	.endif
	.endif

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.ifdef ENGLISH
	.string "Just like people, there are male and\n"
	.string "female POKéMON.\p"
	.string "But no one seems to have any idea how\n"
	.string "they're different.$"
	.else
	.ifdef GERMAN
	.string "Es gibt männliche und weibliche\n"
	.string "POKéMON.\p"
	.string "Aber niemand kann sagen, worin der\n"
	.string "eigentliche Unterschied liegt.$"
	.endif
	.endif

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.ifdef ENGLISH
	.string "The man next door gave me an HM!\p"
	.string "I used it to teach my POKéMON how to\n"
	.string "CUT down skinny trees.$"
	.else
	.ifdef GERMAN
	.string "Der Mann nebenan hat mir eine VM\n"
	.string "gegeben!\p"
	.string "Ich habe meinem POKéMON beigebracht,\n"
	.string "damit kleinere Bäume zu ZERSCHNEIDen.$"
	.endif
	.endif

