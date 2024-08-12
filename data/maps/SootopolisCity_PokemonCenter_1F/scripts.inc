.set LOCALID_NURSE, 1

SootopolisCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SootopolisCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SOOTOPOLIS_CITY
	end

SootopolisCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries::
	msgbox SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries::
	msgbox SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn:
	.ifdef ENGLISH
	.string "WALLACE is rumored to be the toughest\n"
	.string "TRAINER in the whole HOENN region.\p"
	.string "This town's GYM is led by the TRAINER\n"
	.string "who taught WALLACE.\p"
	.string "But the ELITE FOUR… They're said to be\n"
	.string "even stronger than WALLACE's mentor.\p"
	.string "How strong could they be?$"
	.else
	.ifdef GERMAN
	.string "WASSILI, der ehemalige ARENALEITER\n"
	.string "dieses Ortes, ist ein starker TRAINER.\p"
	.string "Man sagt, er sei der beste TRAINER der\n"
	.string "ganzen HOENN-Region.\p"
	.string "Der LEITER dieser ARENA ist der\n"
	.string "Lehrer von WASSILI.\p"
	.string "Aber die TOP VIER…\p"
	.string "Man sagt, sie seien stärker als\n"
	.string "WASSILIs Lehrer.\p"
	.string "Wie stark müssen sie dann erst sein?$"
	.endif
	.endif

SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge:
	.ifdef ENGLISH
	.string "Everyone in town has taken refuge\n"
	.string "and won't come out of their homes.\p"
	.string "Even I would rather not venture\n"
	.string "outside.$"
	.else
	.ifdef GERMAN
	.string "Jeder im Ort hat sich in sein Haus\n"
	.string "zurückgezogen und kommt nicht heraus.\p"
	.string "Ich würde es auch nicht wagen, nach\n"
	.string "draußen zu gehen.$"
	.endif
	.endif

SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon:
	.ifdef ENGLISH
	.string "Whenever, wherever, and whatever\n"
	.string "happens, I will always be friends with\l"
	.string "POKéMON.\p"
	.string "Because it's fun to be with POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Was auch immer wann oder wo passiert,\n"
	.string "meine Freundschaft zu den POKéMON\l"
	.string "leidet darunter bestimmt nicht!\p"
	.string "Ich liebe es, mit POKéMON zusammen\n"
	.string "zu sein.$"
	.endif
	.endif

SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends:
	.ifdef ENGLISH
	.string "Aren't POKéMON our friends?\p"
	.string "Why are they going wild this way?$"
	.else
	.ifdef GERMAN
	.string "Sind POKéMON nicht unsere Freunde?\p"
	.string "Warum sind sie dann auf einmal so wild?$"
	.endif
	.endif

