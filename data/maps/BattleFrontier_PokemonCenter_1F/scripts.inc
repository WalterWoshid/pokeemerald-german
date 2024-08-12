.set LOCALID_NURSE, 1

BattleFrontier_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BattleFrontier_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST
	end

BattleFrontier_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_SchoolKid::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Man::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Picnicker::
	msgbox BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox BattleFrontier_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon:
	.ifdef ENGLISH
	.string "There was someone here using a \n"
	.string "POKéMON I've never seen before.\p"
	.string "I never learned about it at\n"
	.string "TRAINER'S SCHOOL at least.\p"
	.string "I wonder where you can catch POKéMON\n"
	.string "like that.$"
	.else
	.ifdef GERMAN
	.string "Hier war gerade jemand, der hat ein\n"
	.string "POKéMON gehabt, das ich vorher noch\p"
	.string "nie gesehen habe. Ich habe auch in der\n"
	.string "TRAINERSCHULE nichts darüber gelernt.\p"
	.string "Wo findet man wohl so ein POKéMON?$"
	.endif
	.endif

BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena:
	.ifdef ENGLISH
	.string "Okay! Next stop, the BATTLE ARENA!\n"
	.string "I'd better get the right POKéMON from\l"
	.string "the PC Storage System.$"
	.else
	.ifdef GERMAN
	.string "Okay! Nächster Halt: KAMPFRING!\n"
	.string "Ich sollte mir schnell ein POKéMON aus\l"
	.string "dem POKéMON-Lagerungs-System nehmen.$"
	.endif
	.endif

BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge:
	.ifdef ENGLISH
	.string "Giggle… I'm going to go through every\n"
	.string "challenge with just this baby!$"
	.else
	.ifdef GERMAN
	.string "Kicher… Mit diesem Schatz hier werde\n"
	.string "ich jede Herausforderung bestehen!$"
	.endif
	.endif

BattleFrontier_PokemonCenter_1F_Text_Skitty:
	.ifdef ENGLISH
	.string "SKITTY: Mya myaaah!$"
	.else
	.ifdef GERMAN
	.string "ENECO: Mya myaaah!$"
	.endif
	.endif

