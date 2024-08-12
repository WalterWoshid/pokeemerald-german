AquaHideout_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AquaHideout_B1F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B1F_OnTransition
	.byte 0

AquaHideout_B1F_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AquaHideout_B1F_EventScript_TryRemoveElectrode
	end

AquaHideout_B1F_EventScript_TryRemoveElectrode::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AquaHideout_B1F_OnTransition:
	call_if_unset FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_ShowElectrode1
	call_if_unset FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_ShowElectrode2
	end

AquaHideout_B1F_EventScript_ShowElectrode1::
	clearflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_1
	return

AquaHideout_B1F_EventScript_ShowElectrode2::
	clearflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_2
	return

AquaHideout_B1F_EventScript_Electrode1::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 30
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_B1F_EventScript_DefeatedElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_B1F_EventScript_DefeatedElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_B1F_EventScript_DefeatedElectrode1
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	release
	end

AquaHideout_B1F_EventScript_DefeatedElectrode1::
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

AquaHideout_B1F_EventScript_Electrode2::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 30
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_B1F_EventScript_DefeatedElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_B1F_EventScript_DefeatedElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_B1F_EventScript_DefeatedElectrode2
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	release
	end

AquaHideout_B1F_EventScript_DefeatedElectrode2::
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

AquaHideout_B1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_2, AquaHideout_B1F_Text_Grunt2Intro, AquaHideout_B1F_Text_Grunt2Defeat, AquaHideout_B1F_EventScript_Grunt2Defeated
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt2Defeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_3, AquaHideout_B1F_Text_Grunt3Intro, AquaHideout_B1F_Text_Grunt3Defeat, AquaHideout_B1F_EventScript_Grunt3Defeated
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt3Defeated::
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_5, AquaHideout_B1F_Text_Grunt5Intro, AquaHideout_B1F_Text_Grunt5Defeat
	msgbox AquaHideout_B1F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_7, AquaHideout_B1F_Text_Grunt7Intro, AquaHideout_B1F_Text_Grunt7Defeat
	msgbox AquaHideout_B1F_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_Text_Grunt2Intro:
	.ifdef ENGLISH
	.string "If you want to know the secret about\n"
	.string "our HIDEOUT, you have me to beat!$"
	.else
	.ifdef GERMAN
	.string "Wenn du das Geheimnis unseres\n"
	.string "VERSTECKs erfahren willst, musst du\l"
	.string "mich besiegen!$"
	.endif
	.endif

AquaHideout_B1F_Text_Grunt2Defeat:
	.ifdef ENGLISH
	.string "I can't win at all…$"
	.else
	.ifdef GERMAN
	.string "Ich kann anscheinend nicht gewinnen…$"
	.endif
	.endif

AquaHideout_B1F_Text_Grunt2PostBattle:
	.ifdef ENGLISH
	.string "Our HIDEOUT's secret?\p"
	.string "Well, let's just say…\n"
	.string "There's a submarine at the far end!\p"
	.string "But, by now…\n"
	.string "Kekekeke…$"
	.else
	.ifdef GERMAN
	.string "Das Geheimnis unseres VERSTECKs?\p"
	.string "Nun, sagen wir mal soooo…\n"
	.string "Am Ende befindet sich ein U-Boot!\p"
	.string "Aber, im Moment…\n"
	.string "Hehehehe…$"
	.endif
	.endif

AquaHideout_B1F_Text_Grunt3Intro:
	.ifdef ENGLISH
	.string "Fuel supply loaded A-OK!\n"
	.string "In-cruise snacks loaded A-OK!\p"
	.string "Nothing left to do but KO a pesky\n"
	.string "meddler!$"
	.else
	.ifdef GERMAN
	.string "Tankbefüllung… OKAY!\n"
	.string "Proviant… OKAY!\p"
	.string "Nichts anderes mehr zu tun, als eine\n"
	.string "Nervensäge aus dem Weg zu räumen.$"
	.endif
	.endif

AquaHideout_B1F_Text_Grunt3Defeat:
	.ifdef ENGLISH
	.string "I took a serious licking!$"
	.else
	.ifdef GERMAN
	.string "Das war ein Schuss vor den Bug.$"
	.endif
	.endif

AquaHideout_B1F_Text_Grunt3PostBattle:
	.ifdef ENGLISH
	.string "Humph!\n"
	.string "This was supposed to happen!\p"
	.string "My mission was to just hold you up!$"
	.else
	.ifdef GERMAN
	.string "Pah!\n"
	.string "Meine Niederlage war geplant.\p"
	.string "Ich sollte dich eh nur aufhalten!$"
	.endif
	.endif

AquaHideout_B1F_Text_Grunt5Intro:
	.ifdef ENGLISH
	.string "Yawn… Keeping watch over the\n"
	.string "HIDEOUT bores me. I'll take you on.$"
	.else
	.ifdef GERMAN
	.string "Gääähn… Hier im VERSTECK Wache zu\n"
	.string "stehen, ist ermüdend. Ich muss kämpfen.$"
	.endif
	.endif

AquaHideout_B1F_Text_Grunt5Defeat:
	.ifdef ENGLISH
	.string "Yawn…\n"
	.string "Oh, I lost…$"
	.else
	.ifdef GERMAN
	.string "Gähn…\n"
	.string "Oh, da habe ich wohl verloren…$"
	.endif
	.endif

AquaHideout_B1F_Text_Grunt5PostBattle:
	.ifdef ENGLISH
	.string "If you scurry too much, other TEAM\n"
	.string "AQUA members might get you.$"
	.else
	.ifdef GERMAN
	.string "Wenn du weiter hier herumschleichst, \n"
	.string "schnappt dich TEAM AQUA.$"
	.endif
	.endif

AquaHideout_B1F_Text_Grunt7Intro:
	.ifdef ENGLISH
	.string "Hey!\n"
	.string "You there!\p"
	.string "Which do you think is cooler?\n"
	.string "TEAM AQUA's uniform or TEAM MAGMA's?$"
	.else
	.ifdef GERMAN
	.string "Hey!\n"
	.string "Du da!\p"
	.string "Was ist cooler?\n"
	.string "Die Uniform von TEAM AQUA oder\l"
	.string "die von TEAM MAGMA?$"
	.endif
	.endif

AquaHideout_B1F_Text_Grunt7Defeat:
	.ifdef ENGLISH
	.string "I lost in a cool way…$"
	.else
	.ifdef GERMAN
	.string "Ich habe ganz cool verloren…$"
	.endif
	.endif

AquaHideout_B1F_Text_Grunt7PostBattle:
	.ifdef ENGLISH
	.string "If you have a cool uniform, you look\n"
	.string "good even in a loss, don't you think?$"
	.else
	.ifdef GERMAN
	.string "Hat man eine coole Uniform, sieht man\n"
	.string "auch noch klasse aus, wenn man verliert,\l"
	.string "findest du nicht?$"
	.endif
	.endif
