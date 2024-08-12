.set LOCALID_NURSE, 1

VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon:
	.ifdef ENGLISH
	.string "You can't consider yourself a real\n"
	.string "TRAINER if you don't have faith\l"
	.string "in your POKéMON.\p"
	.string "Only those people who can believe\n"
	.string "in their battling POKéMON can win\l"
	.string "through to the very end.$"
	.else
	.ifdef GERMAN
	.string "Du kannst dich nicht TRAINER nennen,\n"
	.string "wenn du nicht an deine POKéMON glaubst!\p"
	.string "Nur diejenigen, die an ihre POKéMON\n"
	.string "glauben, werden am Ende siegen.$"
	.endif
	.endif

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent:
	.ifdef ENGLISH
	.string "The reason why anyone would visit\n"
	.string "VERDANTURF…\p"
	.string "It's the BATTLE TENT. It goes without\n"
	.string "saying.\p"
	.string "Or is there somebody here that you\n"
	.string "came to see?$"
	.else
	.ifdef GERMAN
	.string "Der Grund, warum jeder WIESENFLUR\n"
	.string "besucht…\p"
	.string "ist das KAMPFCAMP. Das liegt auf der\n"
	.string "Hand.\p"
	.string "Oder bist du aus einem anderen Grund\n"
	.string "hier?$"
	.endif
	.endif

