.set LOCALID_NURSE, 1

PacifidlogTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PacifidlogTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Girl::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Woman::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_OldMan::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard:
	.ifdef ENGLISH
	.string "What color is your TRAINER CARD?\n"
	.string "Mine's copper!$"
	.else
	.ifdef GERMAN
	.string "Welche Farbe hat dein TRAINERPASS?\n"
	.string "Meiner ist kupferrot.$"
	.endif
	.endif

PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola:
	.ifdef ENGLISH
	.string "PACIFIDLOG TOWN floats on top of\n"
	.string "a colony of CORSOLA.\p"
	.string "If I told you that, would you believe\n"
	.string "me?$"
	.else
	.ifdef GERMAN
	.string "FLOSSBRUNN schwimmt auf einer\n"
	.string "Kolonie von CORASONN.\p"
	.string "Glaubst du mir das?$"
	.endif
	.endif

PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats:
	.ifdef ENGLISH
	.string "The ancestors of the people in\n"
	.string "PACIFIDLOG were said to have been\l"
	.string "born on boats and then lived and died \l"
	.string "aboard them.\p"
	.string "I understand that they lived that way\n"
	.string "because they were searching for\l"
	.string "something.$"
	.else
	.ifdef GERMAN
	.string "Man sagt, die Vorfahren der Menschen in\n"
	.string "FLOSSBRUNN wurden an Bord von\l"
	.string "Schiffen geboren, lebten und starben\l"
	.string "auch dort.\p"
	.string "Diese Lebensart ist verständlich, denn\n"
	.string "sie waren auf der Suche nach etwas.$"
	.endif
	.endif

