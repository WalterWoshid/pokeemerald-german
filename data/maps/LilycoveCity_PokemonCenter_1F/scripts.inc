.set LOCALID_NURSE, 1

LilycoveCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LilycoveCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	goto LilycoveCity_PokemonCenter_1F_EventScript_SetLilycoveLadyGfx
	end

@ SetLilycoveLadyGfx returns TRUE if its the Contest Lady
LilycoveCity_PokemonCenter_1F_EventScript_SetLilycoveLadyGfx::
	special SetLilycoveLadyGfx
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_HideContestLadyMon
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_ShowContestLadyMon
	end

LilycoveCity_PokemonCenter_1F_EventScript_HideContestLadyMon::
	setflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON
	end

LilycoveCity_PokemonCenter_1F_EventScript_ShowContestLadyMon::
	clearflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON
	end

LilycoveCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Boy::
	msgbox LilycoveCity_PokemonCenter_1F_Text_HowManyKindsOfPokemon, MSGBOX_NPC
	end

LilycoveCity_PokemonCenter_1F_EventScript_Maniac::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_PokemonCenter_1F_EventScript_ManiacBadTeamGone
	msgbox LilycoveCity_PokemonCenter_1F_Text_HeardAboutRottenScoundrels, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ManiacBadTeamGone::
	msgbox LilycoveCity_PokemonCenter_1F_Text_HaventSeenRottenScoundrels, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_Text_HowManyKindsOfPokemon:
	.ifdef ENGLISH
	.string "I wonder how many kinds of POKéMON\n"
	.string "there are in the world.\p"
	.string "It'd be great to cross seas and\n"
	.string "trade POKéMON with people far away.$"
	.else
	.ifdef GERMAN
	.string "Ich frage mich, wie viele Arten von\n"
	.string "POKéMON es in der Welt wohl gibt?\p"
	.string "Es muss toll sein, die Meere zu über-\n"
	.string "queren und POKéMON mit Leuten zu\l"
	.string "tauschen, die weit weg leben.$"
	.endif
	.endif

LilycoveCity_PokemonCenter_1F_Text_HeardAboutRottenScoundrels:
	.ifdef ENGLISH
	.string "I've been hearing about some rotten\n"
	.string "scoundrels who steal POKéMON and rip\l"
	.string "off METEORITES.$"
	.else
	.ifdef GERMAN
	.string "Ich habe von einigen Schurken gehört,\n"
	.string "die POKéMON stehlen und METEORITen\l"
	.string "klauen.$"
	.endif
	.endif

LilycoveCity_PokemonCenter_1F_Text_HaventSeenRottenScoundrels:
	.ifdef ENGLISH
	.string "Those rotten scoundrels who steal\n"
	.string "POKéMON and rip off METEORITES…\p"
	.string "I haven't seen them around recently.$"
	.else
	.ifdef GERMAN
	.string "Diese verkommenen Schurken, die\n"
	.string "POKéMON stehlen und METEORITen\l"
	.string "klauen…\p"
	.string "Ich habe sie in letzter Zeit nicht\n"
	.string "gesehen.$"
	.endif
	.endif

