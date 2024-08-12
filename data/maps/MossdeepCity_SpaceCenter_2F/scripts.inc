.set LOCALID_RICH_BOY, 1
.set LOCALID_GENTLEMAN, 2
.set LOCALID_SCIENTIST, 3
.set LOCALID_STEVEN, 4
@ Grunt names numbered like their Trainer values (which are for the full Space Center)
.set LOCALID_GRUNT_6, 5
.set LOCALID_GRUNT_5, 6
.set LOCALID_GRUNT_7, 7
.set LOCALID_TABITHA, 8
.set LOCALID_MAXIE, 9

MossdeepCity_SpaceCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_2F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_SpaceCenter_2F_OnFrame
	.byte 0

MossdeepCity_SpaceCenter_2F_OnTransition:
	call_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_MoveCivilians
	call_if_eq VAR_MOSSDEEP_SPACE_CENTER_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_MoveDefeatedGrunts
	end

MossdeepCity_SpaceCenter_2F_EventScript_MoveCivilians::
	clearflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
	setobjectxyperm LOCALID_SCIENTIST, 5, 3
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_RICH_BOY, 3, 2
	setobjectmovementtype LOCALID_RICH_BOY, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_GENTLEMAN, 1, 3
	setobjectmovementtype LOCALID_GENTLEMAN, MOVEMENT_TYPE_FACE_RIGHT
	return

MossdeepCity_SpaceCenter_2F_EventScript_MoveDefeatedGrunts::
	setobjectxyperm LOCALID_GRUNT_6, 11, 2
	setobjectxyperm LOCALID_GRUNT_7, 15, 2
	setobjectxyperm LOCALID_GRUNT_5, 13, 4
	return

MossdeepCity_SpaceCenter_2F_OnFrame:
	map_script_2 VAR_MOSSDEEP_SPACE_CENTER_STATE, 1, MossdeepCity_SpaceCenter_2F_EventScript_ThreeMagmaGrunts
	.2byte 0

MossdeepCity_SpaceCenter_2F_EventScript_ThreeMagmaGrunts::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_YoureOutnumberedTakeUsOn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts
	msgbox MossdeepCity_SpaceCenter_2F_Text_GoodAnswer, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_2F_Movement_PlayerExit
	waitmovement 0
	warp MAP_MOSSDEEP_CITY_SPACE_CENTER_1F, 13, 1
	waitstate
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_PlayerExit:
	walk_up
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts::
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt5Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_5, MossdeepCity_SpaceCenter_2F_Text_Grunt5Defeat
	applymovement LOCALID_GRUNT_5, MossdeepCity_SpaceCenter_2F_Movement_Grunt5Defeated
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt6Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_6, MossdeepCity_SpaceCenter_2F_Text_Grunt6Defeat
	applymovement LOCALID_GRUNT_6, MossdeepCity_SpaceCenter_2F_Movement_Grunt6Defeated
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt7Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_7, MossdeepCity_SpaceCenter_2F_Text_Grunt7Defeat
	applymovement LOCALID_GRUNT_7, MossdeepCity_SpaceCenter_2F_Movement_Grunt7Defeated
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 2
	copyobjectxytoperm LOCALID_GRUNT_6
	copyobjectxytoperm LOCALID_GRUNT_7
	copyobjectxytoperm LOCALID_GRUNT_5
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_Grunt6Defeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_Movement_Grunt5Defeated:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_Movement_Grunt7Defeated:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_Scientist::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal::
	msgbox MossdeepCity_SpaceCenter_2F_Text_MossdeepIdealForRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma::
	msgbox MossdeepCity_SpaceCenter_2F_Text_WhyWouldMagmaStealRocketFuel, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal::
	msgbox MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma::
	msgbox MossdeepCity_SpaceCenter_2F_Text_MagmaCantGetAwayWithThis, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoy::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal::
	msgbox MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma::
	msgbox MossdeepCity_SpaceCenter_2F_Text_DoesMagmaWantToGoToSpace, MSGBOX_DEFAULT
	release
	end

@ Battle for the below 3 grunts is handled in MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts
MossdeepCity_SpaceCenter_2F_EventScript_Grunt6::
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt6PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Grunt7::
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt7PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Grunt5::
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt5PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Tabitha::
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_2F_Text_WellTakeCareOfYou, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Maxie::
	lockall
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieDontInterfere, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_Steven::
	lockall
	goto_if_set FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER, MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt
	setflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenWhyStealRocketFuel, MSGBOX_DEFAULT
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieUseFuelToEruptVolcano, MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_NOT_EFFECTIVE
	switch VAR_FACING
	case DIR_SOUTH, MossdeepCity_SpaceCenter_2F_EventScript_StevenFightMovementSouth
	applymovement LOCALID_STEVEN, MossdeepCity_SpaceCenter_2F_Movement_StevenFight
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_StevenFightMovementSouth::
	applymovement LOCALID_STEVEN, MossdeepCity_SpaceCenter_2F_Movement_StevenFightSouth
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_StevenFight:
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	delay_16
	delay_16
	walk_slow_down
	walk_slow_down
	step_end

MossdeepCity_SpaceCenter_2F_Movement_StevenFightSouth:
	face_left
	lock_facing_direction
	walk_fast_right
	walk_fast_right
	unlock_facing_direction
	delay_16
	delay_16
	walk_slow_left
	walk_slow_left
	face_down
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenAreYouReadyToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MossdeepCity_SpaceCenter_2F_EventScript_ChoosePartyForMultiBattle
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenHurryGetReadyQuickly, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_ChoosePartyForMultiBattle::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_ne VAR_RESULT, 0, MossdeepCity_SpaceCenter_2F_EventScript_DoStevenMultiBattle
	special LoadPlayerParty
	goto MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt

MossdeepCity_SpaceCenter_2F_EventScript_DoStevenMultiBattle::
	special ReducePlayerPartyToSelectedMons
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_0x8004, SPECIAL_BATTLE_STEVEN
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	frontier_saveparty
	special LoadPlayerParty
	switch VAR_RESULT
	case 1, MossdeepCity_SpaceCenter_2F_EventScript_DefeatedMaxieTabitha
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate

MossdeepCity_SpaceCenter_2F_EventScript_DefeatedMaxieTabitha::
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieWeFailedIsAquaAlsoMisguided, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_TABITHA, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 60
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_TABITHA, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieWeWillGiveUp, MSGBOX_DEFAULT
	closemessage
	setvar VAR_MOSSDEEP_CITY_STATE, 3
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 3
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	removeobject LOCALID_GRUNT_6
	removeobject LOCALID_GRUNT_7
	removeobject LOCALID_GRUNT_5
	removeobject LOCALID_TABITHA
	removeobject LOCALID_MAXIE
	setobjectxy LOCALID_SCIENTIST, 5, 6
	turnobject LOCALID_SCIENTIST, DIR_SOUTH
	setobjectxy LOCALID_GENTLEMAN, 11, 8
	turnobject LOCALID_GENTLEMAN, DIR_NORTH
	setobjectxy LOCALID_RICH_BOY, 6, 2
	turnobject LOCALID_RICH_BOY, DIR_NORTH
	call MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayer
	fadescreen FADE_FROM_BLACK
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenThankYouComeSeeMeAtHome, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	removeobject LOCALID_STEVEN
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_MAGMA_NOTE
	clearflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setvar VAR_STEVENS_HOUSE_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
	removeobject LOCALID_SCIENTIST
	setobjectxyperm LOCALID_SCIENTIST, 5, 6
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_WANDER_AROUND
	addobject LOCALID_SCIENTIST
	fadescreen FADE_FROM_BLACK
#ifdef BUGFIX
	releaseall
#endif
	end

MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayer::
	switch VAR_FACING
	case DIR_SOUTH, MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerSouth
	case DIR_WEST, MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerWest
	return

MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerSouth::
	turnobject LOCALID_STEVEN, DIR_NORTH
	return

MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerWest::
	turnobject LOCALID_STEVEN, DIR_EAST
	return

MossdeepCity_SpaceCenter_2F_EventScript_MaxieTrainer::
	trainerbattle TRAINER_BATTLE_SET_TRAINER_A, TRAINER_MAXIE_MOSSDEEP, 0, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand
	end

MossdeepCity_SpaceCenter_2F_EventScript_TabithaTrainer::
	trainerbattle TRAINER_BATTLE_SET_TRAINER_B, TRAINER_TABITHA_MOSSDEEP, 0, MossdeepCity_SpaceCenter_Text_TabithaDefeat, MossdeepCity_SpaceCenter_Text_TabithaDefeat
	end

MossdeepCity_SpaceCenter_2F_EventScript_RivalRayquazaCall::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, MossdeepCity_SpaceCenter_2F_EventScript_MayRayquazaCall
	call_if_eq VAR_RESULT, FEMALE, MossdeepCity_SpaceCenter_2F_EventScript_BrendanRayquazaCall
	closemessage
	clearflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_MayRayquazaCall::
	pokenavcall MatchCall_Text_MayRayquazaCall
	waitmessage
	return

MossdeepCity_SpaceCenter_2F_EventScript_BrendanRayquazaCall::
	pokenavcall MatchCall_Text_BrendanRayquazaCall
	waitmessage
	return

MossdeepCity_SpaceCenter_2F_Text_MossdeepIdealForRockets:
	.ifdef ENGLISH
	.string "MOSSDEEP has mainly sunny weather,\n"
	.string "and its winds are stable.\p"
	.string "It's an ideal location for launching\n"
	.string "rockets.$"
	.else
	.ifdef GERMAN
	.string "MOOSBACH CITY hat meistens sonniges\n"
	.string "Wetter und einen beständigen Wind.\p"
	.string "Ein idealer Ort, um Raketen ins All zu\n"
	.string "schicken.$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_WhyWouldMagmaStealRocketFuel:
	.ifdef ENGLISH
	.string "Why would TEAM MAGMA want to steal\n"
	.string "our rocket fuel in the first place?$"
	.else
	.ifdef GERMAN
	.string "Warum will TEAM MAGMA unseren Raketen-\n"
	.string "treibstoff überhaupt haben?$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut:
	.ifdef ENGLISH
	.string "If only I was a little younger, I would\n"
	.string "have liked being an astronaut…\p"
	.string "No… It's not too late!\n"
	.string "I can and will try!$"
	.else
	.ifdef GERMAN
	.string "Wenn ich jünger wäre, würde ich mit\n"
	.string "Sicherheit Astronaut…\p"
	.string "Nein… Dazu ist es nie zu spät!\n"
	.string "Ich werde es versuchen!!!$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_MagmaCantGetAwayWithThis:
	.ifdef ENGLISH
	.string "If TEAM MAGMA takes the rocket fuel,\n"
	.string "I won't be able to go to space!\p"
	.string "They can't be allowed to get away\n"
	.string "with such an outrage!$"
	.else
	.ifdef GERMAN
	.string "Wenn TEAM MAGMA den Raketentreibstoff\n"
	.string "nimmt, kann ich nicht ins All fliegen!\p"
	.string "Sie dürfen mit so einer Schandtat\n"
	.string "einfach nicht davonkommen.$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace:
	.ifdef ENGLISH
	.string "I wish ordinary people could go into\n"
	.string "space one day…$"
	.else
	.ifdef GERMAN
	.string "Ich wünschte, auch normale Leute\n"
	.string "könnten eines Tages ins All reisen…$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_DoesMagmaWantToGoToSpace:
	.ifdef ENGLISH
	.string "TEAM MAGMA…\n"
	.string "Do they want to go to space, too?$"
	.else
	.ifdef GERMAN
	.string "TEAM MAGMA…\n"
	.string "Ob sie auch ins Weltall fliegen wollen?!?$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_YoureOutnumberedTakeUsOn:
	.ifdef ENGLISH
	.string "What's wrong with you?\p"
	.string "You're outnumbered three to one,\n"
	.string "but you still want to take us on?$"
	.else
	.ifdef GERMAN
	.string "Was ist los mit dir?\p"
	.string "Wir sind drei und trotzdem willst du\n"
	.string "gegen uns antreten?$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_GoodAnswer:
	.ifdef ENGLISH
	.string "Good answer!\n"
	.string "That's what a smart person'll do!$"
	.else
	.ifdef GERMAN
	.string "Gute Antwort!\n"
	.string "Eine kluge Entscheidung!$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_Grunt5Intro:
	.ifdef ENGLISH
	.string "A reckless go-getter, are you?\n"
	.string "Okay, I'll go first!$"
	.else
	.ifdef GERMAN
	.string "Du bist ein rücksichtsloses Etwas,\n"
	.string "oder? Okay, ich fang an.$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_Grunt5Defeat:
	.ifdef ENGLISH
	.string "I lost!\n"
	.string "But!$"
	.else
	.ifdef GERMAN
	.string "Ich habe verloren!\n"
	.string "Ich Narr!$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_Grunt6Intro:
	.ifdef ENGLISH
	.string "It's too soon to be relieved!\n"
	.string "I'm up next!$"
	.else
	.ifdef GERMAN
	.string "Sei nicht zu erleichtert!\n"
	.string "Jetzt komme ich!$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_Grunt6Defeat:
	.ifdef ENGLISH
	.string "I lost, too!\n"
	.string "But!$"
	.else
	.ifdef GERMAN
	.string "Ich habe auch verloren!\n"
	.string "Argh!$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_Grunt7Intro:
	.ifdef ENGLISH
	.string "I bet you want to take a break.\n"
	.string "But I'm not about to let you do that!$"
	.else
	.ifdef GERMAN
	.string "Ich wette, du sehnst dich nach einer\n"
	.string "Pause! Aber die gönne ich dir nicht.$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_Grunt7Defeat:
	.ifdef ENGLISH
	.string "We should've taken a break…\n"
	.string "That's what we should've done…$"
	.else
	.ifdef GERMAN
	.string "Wir hätten eine Pause einlegen sollen…\n"
	.string "Das hätten wir wirklich machen sollen…$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_Grunt6PostBattle:
	.ifdef ENGLISH
	.string "Three of us here, and look at the sorry\n"
	.string "mess we got ourselves into.$"
	.else
	.ifdef GERMAN
	.string "Drei gegen Einen und schau, was aus uns\n"
	.string "geworden ist…$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_Grunt7PostBattle:
	.ifdef ENGLISH
	.string "We three losing like this…\n"
	.string "We look worse than usual by triple!$"
	.else
	.ifdef GERMAN
	.string "Wir drei haben verloren…\n"
	.string "Wir stehen echt doof da…$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_Grunt5PostBattle:
	.ifdef ENGLISH
	.string "Are we being useful to our leader\n"
	.string "at all?$"
	.else
	.ifdef GERMAN
	.string "Haben wir unserem Boss überhaupt\n"
	.string "helfen können?$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_WellTakeCareOfYou:
	.ifdef ENGLISH
	.string "Hehehe!\p"
	.string "We come all the way here to get some\n"
	.string "fuel, and we're interfered with again!\p"
	.string "If you're going to mess with us too,\n"
	.string "we'll take care of you at the same time!$"
	.else
	.ifdef GERMAN
	.string "Hähähä!\p"
	.string "Wir haben einen weiten Weg hinter uns,\n"
	.string "um an den Treibstoff zu kommen.\p"
	.string "Wir lassen uns davon nicht abbringen.\n"
	.string "Störenfriede lassen wir nicht zu.$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_MaxieDontInterfere:
	.ifdef ENGLISH
	.string "MAXIE: Clear out of the way!\n"
	.string "Don't you dare interfere!$"
	.else
	.ifdef GERMAN
	.string "MARC: Geh aus dem Weg!\n"
	.string "Du wagst es, uns aufhalten zu wollen?!?$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_StevenWhyStealRocketFuel:
	.ifdef ENGLISH
	.string "STEVEN: TEAM MAGMA…\p"
	.string "What's the point of stealing rocket\n"
	.string "fuel?$"
	.else
	.ifdef GERMAN
	.string "TROY: TEAM MAGMA…\p"
	.string "Was wollt ihr mit dem\n"
	.string "Raketentreibstoff?$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_MaxieUseFuelToEruptVolcano:
	.ifdef ENGLISH
	.string "MAXIE: Fufufu… Since you're so\n"
	.string "curious, you deserve an explanation.\p"
	.string "We're going to jettison the entire\n"
	.string "load into MT. CHIMNEY!\p"
	.string "With GROUDON gone, we have no need\n"
	.string "for that slag heap of a mountain!\p"
	.string "So we'll use the fuel's power to make\n"
	.string "the volcano erupt!\p"
	.string "It will be savage!$"
	.else
	.ifdef GERMAN
	.string "MARC: Hähähä… Da du so wissbegierig\n"
	.string "bist, werden wir dich aufklären.\p"
	.string "Wir wollen den Treibstoff über dem\n"
	.string "SCHLOTBERG abwerfen.\p"
	.string "Nun, wo GROUDON weg ist, hat dieser\n"
	.string "Berg keinen Nutzen mehr für uns!\p"
	.string "Daher werden wir den Vulkan mit Hilfe\n"
	.string "des Treibstoffs zum Ausbruch bringen.\p"
	.string "Das wird wild!$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_StevenAreYouReadyToBattle:
	.ifdef ENGLISH
	.string "STEVEN: {PLAYER}{KUN}!\n"
	.string "You're going to help me?\p"
	.string "Let's go into battle together!\n"
	.string "Are you ready?$"
	.else
	.ifdef GERMAN
	.string "TROY: {PLAYER}{KUN}!\n"
	.string "Du hilfst mir?\p"
	.string "Dann lass uns als Team kämpfen.\n"
	.string "Bist du bereit?$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_StevenHurryGetReadyQuickly:
	.ifdef ENGLISH
	.string "STEVEN: Then, hurry!\n"
	.string "Get ready quickly!$"
	.else
	.ifdef GERMAN
	.string "TROY: Dann Beeilung!\n"
	.string "Beeilung, Beeilung!$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand:
	.ifdef ENGLISH
	.string "All I want…\n"
	.string "I just want to expand the land mass…$"
	.else
	.ifdef GERMAN
	.string "Ich wollte doch nur…\n"
	.string "Ich wollte doch nur die Landmassen\l"
	.string "vergrößern…$"
	.endif
	.endif

MossdeepCity_SpaceCenter_Text_TabithaDefeat:
	.ifdef ENGLISH
	.string "I'm with our leader…$"
	.else
	.ifdef GERMAN
	.string "Ich stehe auf der Seite vom Boss…$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_MaxieWeFailedIsAquaAlsoMisguided:
	.ifdef ENGLISH
	.string "MAXIE: We failed to make the volcano\n"
	.string "erupt…\p"
	.string "We failed to control GROUDON after\n"
	.string "we had awoken it…\p"
	.string "Is our goal to expand the land\n"
	.string "misguided?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "If…\n"
	.string "If we, TEAM MAGMA, are wrong…\l"
	.string "… … … … … …\p"
	.string "Then might TEAM AQUA's goal to expand\n"
	.string "the sea also be equally misguided?$"
	.else
	.ifdef GERMAN
	.string "MARC: Wir konnten den Vulkan nicht zum\n"
	.string "Ausbruch bringen…\p"
	.string "Wir konnten GROUDON nicht\n"
	.string "kontrollieren…\p"
	.string "Ist unser Plan, die Landmassen zu\n"
	.string "vergrößern, vielleicht doch falsch?\p"
	.string "… … … … …\n"
	.string "…\l"
	.string "… … … … …\l"
	.string "…\p"
	.string "Wenn…\n"
	.string "Wenn wir, TEAM MAGMA, uns geirrt haben…\l"
	.string "… … … … …\l"
	.string "…\p"
	.string "dann liegt TEAM AQUA mit seinem Plan,\n"
	.string "das Meer auszuweiten, vielleicht\l"
	.string "genauso falsch?$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_MaxieWeWillGiveUp:
	.ifdef ENGLISH
	.string "MAXIE: All right…\n"
	.string "We will give up on the fuel…\p"
	.string "There appear to be more important\n"
	.string "matters that I must examine…$"
	.else
	.ifdef GERMAN
	.string "MARC: Gut…\n"
	.string "Wir werden den Treibstoff hier lassen…\p"
	.string "Es gibt wichtigere Dinge, um die ich mich\n"
	.string "kümmern muss…$"
	.endif
	.endif

MossdeepCity_SpaceCenter_2F_Text_StevenThankYouComeSeeMeAtHome:
	.ifdef ENGLISH
	.string "STEVEN: Whew, that was too tense.\n"
	.string "{PLAYER}{KUN}, thank you.\p"
	.string "I have something to give you as\n"
	.string "thanks for your support.\p"
	.string "Please come see me at home\n"
	.string "after this.\p"
	.string "Oh, yes, I don't live in RUSTBORO CITY.\n"
	.string "I live right here on this island.$"
	.else
	.ifdef GERMAN
	.string "TROY: Huh, war das Nerven zerreißend.\n"
	.string "Danke, {PLAYER}{KUN}.\p"
	.string "Ich habe etwas, das ich dir als\n"
	.string "Dankeschön für deine Hilfe geben\l"
	.string "möchte.\p"
	.string "Komm mich bitte besuchen.\p"
	.string "Ach so: Ich lebe nicht in METAROST CITY.\n"
	.string "Ich lebe hier auf dieser Insel.$"
	.endif
	.endif
