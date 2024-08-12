.set LOCALID_NURSE, 1

DewfordTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

DewfordTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_DEWFORD_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

DewfordTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

DewfordTown_PokemonCenter_1F_EventScript_PokefanF::
	msgbox DewfordTown_PokemonCenter_1F_Text_StoneCavern, MSGBOX_NPC
	end

DewfordTown_PokemonCenter_1F_EventScript_Man::
	msgbox DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM, MSGBOX_NPC
	end

DewfordTown_PokemonCenter_1F_Text_StoneCavern:
	.ifdef ENGLISH
	.string "There's a stone cavern at the edge\n"
	.string "of town.\p"
	.string "I've heard you can find rare stones\n"
	.string "there.$"
	.else
	.ifdef GERMAN
	.string "Am Rande des Ortes befindet sich eine\n"
	.string "steinerne Höhle.\p"
	.string "Dort soll man seltene Steine finden\n"
	.string "können.$"
	.endif
	.endif

DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM:
	.ifdef ENGLISH
	.string "Even if a POKéMON faints and can't\n"
	.string "battle, it can still use a move learned\l"
	.string "from a HIDDEN MACHINE (HM).$"
	.else
	.ifdef GERMAN
	.string "Auch wenn in deinem Team ein kampf-\n"
	.string "unfähiges POKéMON ist, kann es außer-\p"
	.string "halb des Kampfes eine Versteckte\n"
	.string "Maschine, eine VM, anwenden.$"
	.endif
	.endif

