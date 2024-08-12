.set LOCALID_FAT_MAN, 1
.set LOCALID_MAN_1, 2
.set LOCALID_RICH_BOY, 3
.set LOCALID_GRUNT_1, 5
.set LOCALID_COOK, 6
.set LOCALID_OLD_WOMAN, 7
.set LOCALID_GIRL, 8
.set LOCALID_TY, 9
.set LOCALID_GABBY, 10
.set LOCALID_CAPT_STERN, 11
.set LOCALID_GRUNT_2, 18
.set LOCALID_GRUNT_3, 19
.set LOCALID_GRUNT_4, 26
.set LOCALID_GRUNT_5, 27
.set LOCALID_GRUNT_6, 28
.set LOCALID_GRUNT_7, 29
.set LOCALID_GRUNT_8, 30
.set LOCALID_GRUNT_9, 31
.set LOCALID_GRUNT_11, 33
.set LOCALID_SCOTT, 35

@ Note: LOCALID_SLATEPORT_ENERGY_GURU is a local id for this map used elsewhere. It's defined in event_objects.h

SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_COOK, 27, 16
	setobjectxyperm LOCALID_GIRL, 28, 16
	setobjectxyperm LOCALID_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_MAN_1, 31, 14
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SCOTT
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SCOTT
	setobjectxyperm LOCALID_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	.2byte ITEM_NONE
	release
	end

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_GABBY
	removeobject LOCALID_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SCOTT
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.ifdef ENGLISH
	.string "I'm the ENERGY GURU! I'll go for it and\n"
	.string "sell you what you need!$"
	.else
	.ifdef GERMAN
	.string "Ich bin der STATUSWERTE GURU!\n"
	.string "Ich werde dir verkaufen, was du\l"
	.string "brauchst!$"
	.endif
	.endif

SlateportCity_Text_OhYourPokemon:
	.ifdef ENGLISH
	.string "Oh?\n"
	.string "Your {STR_VAR_1}…$"
	.else
	.ifdef GERMAN
	.string "Oh?\n"
	.string "Dein {STR_VAR_1}…$"
	.endif
	.endif

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.ifdef ENGLISH
	.string "Went for it stupendously!\p"
	.string "As its reward, please give it this\n"
	.string "EFFORT RIBBON.$"
	.else
	.ifdef GERMAN
	.string "Es hat sich enorm angestrengt!\p"
	.string "Gib ihm als Belohnung bitte dieses\n"
	.string "FLEISS-BAND.$"
	.endif
	.endif

SlateportCity_Text_ReceivedEffortRibbon:
	.ifdef ENGLISH
	.string "{PLAYER} received the EFFORT RIBBON.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} erhält das FLEISS-BAND.$"
	.endif
	.endif

SlateportCity_Text_PutEffortRibbonOnMon:
	.ifdef ENGLISH
	.string "{PLAYER} put the EFFORT RIBBON\n"
	.string "on {STR_VAR_1}.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} steckt {STR_VAR_1} das\n"
	.string "FLEISS-BAND an.$"
	.endif
	.endif

SlateportCity_Text_GoForItLittleHarder:
	.ifdef ENGLISH
	.string "You have to go for it a little harder.\p"
	.string "If you do, I'll give your POKéMON\n"
	.string "something nice.$"
	.else
	.ifdef GERMAN
	.string "Du musst dich mehr anstrengen.\p"
	.string "Dann gebe ich dir und deinen POKéMON\n"
	.string "ein schönes Geschenk.$"
	.endif
	.endif

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.ifdef ENGLISH
	.string "Oh! Your {STR_VAR_1}, that EFFORT\n"
	.string "RIBBON looks good on it!$"
	.else
	.ifdef GERMAN
	.string "Oh! Dein {STR_VAR_1} sieht gut mit dem\n"
	.string "FLEISS-BAND aus!$"
	.endif
	.endif

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.ifdef ENGLISH
	.string "The light of the lighthouse reaches\n"
	.string "dozens of miles away.\p"
	.string "I wonder if it doesn't startle POKéMON\n"
	.string "in the sea.$"
	.else
	.ifdef GERMAN
	.string "Das Licht dieses Leuchtturms sieht man\n"
	.string "dutzende von Kilometern weit.\p"
	.string "Ich frage mich, ob es nicht die POKéMON\n"
	.string "im Meer verwirrt.$"
	.endif
	.endif

SlateportCity_Text_SeaweedFullOfLife:
	.ifdef ENGLISH
	.string "Ooh, look at this!\p"
	.string "The seaweed you can get around these\n"
	.string "parts is fresh and full of life.\p"
	.string "Why, it looks like it can even rear up\n"
	.string "and attack!$"
	.else
	.ifdef GERMAN
	.string "Ooh, schau dir das an!\p"
	.string "Das Seegras hier in dieser Gegend sieht\n"
	.string "frisch und fast lebendig aus.\p"
	.string "Es sieht aus, als könne es sich auf-\n"
	.string "richten und angreifen!$"
	.endif
	.endif

SlateportCity_Text_HowTownIsBornAndGrows:
	.ifdef ENGLISH
	.string "Where the water is clean, the fruits\n"
	.string "of bountiful harvest gather.\p"
	.string "And where people gather, a market\n"
	.string "soon starts.\p"
	.string "That is how a town is born and grows.$"
	.else
	.ifdef GERMAN
	.string "Wo das Wasser sauber ist, geben die\n"
	.string "Früchte eine reiche Ernte.\p"
	.string "Und wo es eine reiche Ernte gibt, gibt\n"
	.string "es auch bald einen Markt.\p"
	.string "So entsteht und wächst eine Stadt.$"
	.endif
	.endif

SlateportCity_Text_SlateportWonderfulPlace:
	.ifdef ENGLISH
	.string "Shopping where you can breathe the\n"
	.string "scent of the ocean…\p"
	.string "SLATEPORT is such a wonderful place!$"
	.else
	.ifdef GERMAN
	.string "Einkaufen, wo man die salzige Luft des\n"
	.string "Meeres einatmen kann…\p"
	.string "GRAPHITPORT CITY ist so ein toller Ort!$"
	.endif
	.endif

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.ifdef ENGLISH
	.string "If you put DOLLS or CUSHIONS on\n"
	.string "the floor, they'll get dirty.\p"
	.string "I'm going to buy some BRICKS so my\n"
	.string "DOLLS and CUSHIONS won't get dirty\l"
	.string "when I leave them out.$"
	.else
	.ifdef GERMAN
	.string "Wenn du PUPPEn oder KISSEN einfach auf\n"
	.string "den Boden legst, werden sie schmutzig.\p"
	.string "Ich kaufe mir einige BACKSTEINe, auf\n"
	.string "die ich meine PUPPEn und KISSEN lege.\l"
	.string "So bleiben sie schön sauber.$"
	.endif
	.endif

SlateportCity_Text_GoingToCompeteInBattleTent:
	.ifdef ENGLISH
	.string "Wroooar! I'm going to compete in\n"
	.string "the BATTLE TENT, too!\p"
	.string "But before that, I need to catch\n"
	.string "some POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Wroooaaar! Ich werde auch im KAMPFCAMP\n"
	.string "mein Können unter Beweis stellen! \p"
	.string "Aber vorher muss ich mir einige\n"
	.string "POKéMON fangen!$"
	.endif
	.endif

SlateportCity_Text_BushedHikingFromMauville:
	.ifdef ENGLISH
	.string "Whew… I'm just bushed…\p"
	.string "I hiked over from MAUVILLE CITY.\n"
	.string "But, boy, this city's huge.\p"
	.string "If I'd known this, I would've ridden\n"
	.string "my BIKE here.$"
	.else
	.ifdef GERMAN
	.string "Puuuh… Ich bin fix und fertig…\p"
	.string "Ich komme aus MALVENFROH CITY. Diese\n"
	.string "Stadt ist vielleicht groß! Riesengroß!\p"
	.string "Hätte ich das gewusst, wäre ich mit dem\n"
	.string "RAD gekommen.$"
	.endif
	.endif

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.ifdef ENGLISH
	.string "STERN, the fellow who built the\n"
	.string "MUSEUM, also happens to be the leader\l"
	.string "of an undersea exploration team.\p"
	.string "So, everyone calls him CAPT. STERN.$"
	.else
	.ifdef GERMAN
	.string "Der Typ, der das MUSEUM gebaut\n"
	.string "hat, ist auch der Leiter eines Teams zur\l"
	.string "Erforschung der Tiefsee.\p"
	.string "Daher nennt ihn jeder KAPT. BRIGG.$"
	.endif
	.endif

SlateportCity_Text_WhatsLongLineOverThere:
	.ifdef ENGLISH
	.string "What is that over there?\n"
	.string "That long line…$"
	.else
	.ifdef GERMAN
	.string "Was ist das dort drüben?\n"
	.string "Diese Menschenansammlung…$"
	.endif
	.endif

SlateportCity_Text_VisitedMuseumOften:
	.ifdef ENGLISH
	.string "When I was a child, I visited\n"
	.string "the MUSEUM often.\p"
	.string "I used to dream about the mysteries of\n"
	.string "the sea after seeing the exhibits.$"
	.else
	.ifdef GERMAN
	.string "Als ich noch ein Kind war, war ich oft in\n"
	.string "dem MUSEUM.\p"
	.string "Ich habe danach immer von den\n"
	.string "Mysterien des Meeres geträumt.$"
	.endif
	.endif

SlateportCity_Text_QuitPushing:
	.ifdef ENGLISH
	.string "Hey, there! Quit pushing!\n"
	.string "This is the line, can't you see?$"
	.else
	.ifdef GERMAN
	.string "Hey, du da! Hör auf zu drängeln!\n"
	.string "Wir stehen hier ordentlich an!$"
	.endif
	.endif

SlateportCity_Text_AquaHasPolicy:
	.ifdef ENGLISH
	.string "TEAM AQUA has a policy of\n"
	.string "assembling and dispersing at\l"
	.string "the operation site.$"
	.else
	.ifdef GERMAN
	.string "TEAM AQUA verfolgt die Strategie des\n"
	.string "Versammelns und Verteilens.$"
	.endif
	.endif

SlateportCity_Text_BossIsBrilliant:
	.ifdef ENGLISH
	.string "Our BOSS is brilliant.\p"
	.string "What would he want to do with\n"
	.string "a MUSEUM now?$"
	.else
	.ifdef GERMAN
	.string "Unser BOSS ist brillant.\p"
	.string "Wozu er jetzt wohl Interesse am\n"
	.string "MUSEUM zeigt?$"
	.endif
	.endif

SlateportCity_Text_WhatsNewSchemeIWonder:
	.ifdef ENGLISH
	.string "What's the new scheme, I wonder?\p"
	.string "Our BOSS is scary when he's mad, so\n"
	.string "I'd better not screw things up…$"
	.else
	.ifdef GERMAN
	.string "Was hat diese neue Masche zu bedeuten?\p"
	.string "Unser BOSS ist richtig Furcht ein-\n"
	.string "flößend, wenn er so abgedreht ist. Ich\l"
	.string "halte lieber Abstand und frage nicht…$"
	.endif
	.endif

SlateportCity_Text_ShouldTakeItAll:
	.ifdef ENGLISH
	.string "If there's something we need in\n"
	.string "the MUSEUM, we should take it all!$"
	.else
	.ifdef GERMAN
	.string "Wenn es im MUSEUM etwas Brauchbares\n"
	.string "gibt, dann müssen wir das an uns\l"
	.string "nehmen!$"
	.endif
	.endif

SlateportCity_Text_DontButtIn:
	.ifdef ENGLISH
	.string "Hey, you there!\n"
	.string "Don't butt in!$"
	.else
	.ifdef GERMAN
	.string "Hey, du! Du willst dich doch wohl\n"
	.string "nicht vordrängeln!?!$"
	.endif
	.endif

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.ifdef ENGLISH
	.string "A long line, huh?\p"
	.string "It reminds me of the times I lined up to\n"
	.string "buy smash-hit games…$"
	.else
	.ifdef GERMAN
	.string "Eine lange Schlange, was?\p"
	.string "Erinnert mich an die Zeiten, als ich\n"
	.string "Ewigkeiten anstand, um mir die neuesten\l"
	.string "brandheißen Spiele zu kaufen…$"
	.endif
	.endif

SlateportCity_Text_WhyAreWeLiningUp:
	.ifdef ENGLISH
	.string "Why are we even lining up and paying?\n"
	.string "We should just march in!$"
	.else
	.ifdef GERMAN
	.string "Warum stehen wir hier eigentlich an und\n"
	.string "bezahlen? Wir sollten einfach\lhineingehen.$"
	.endif
	.endif

SlateportCity_Text_WhatDoYouWant:
	.ifdef ENGLISH
	.string "What?\n"
	.string "What do you want?$"
	.else
	.ifdef GERMAN
	.string "Was? Wie?\n"
	.string "Was willst du?!?$"
	.endif
	.endif

SlateportCity_Text_IllReadSignForYou:
	.ifdef ENGLISH
	.string "You want to read this sign?\n"
	.string "I'll read it for you!$"
	.else
	.ifdef GERMAN
	.string "Du willst wissen, was auf dem Schild\n"
	.string "steht? Ich lese es dir vor.$"
	.endif
	.endif

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.ifdef ENGLISH
	.string "Let's see…\p"
	.string "Um… I think it says something like\n"
	.string "“the life in the sea is endless.”\p"
	.string "Yup, I'm pretty sure that's what\n"
	.string "it says.$"
	.else
	.ifdef GERMAN
	.string "Mal sehen…\p"
	.string "Äh… Ich glaube, da steht etwas wie\n"
	.string "“Das Leben im Meer ist unendlich\l"
	.string "vielfältig.”\p"
	.string "Ja, genau. Ich bin sicher, das steht da!$"
	.endif
	.endif

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.ifdef ENGLISH
	.string "Grumble…\p"
	.string "I should've brought my Game Boy\n"
	.string "Advance so I wouldn't get bored in line…\p"
	.string "Grumble…$"
	.else
	.ifdef GERMAN
	.string "Grummel…\p"
	.string "Ich hätte meinen Game Boy Advance\n"
	.string "mitbringen sollen, dann wäre mir jetzt\l"
	.string "nicht so langweilig…\p"
	.string "Das dauert… Grummel…$"
	.endif
	.endif

SlateportCity_Text_HotSpringsAfterOperation:
	.ifdef ENGLISH
	.string "When this operation's over, I'll take\n"
	.string "you to a hot spring spa!\p"
	.string "That's what our leader said.\n"
	.string "I can't wait!$"
	.else
	.ifdef GERMAN
	.string "Wenn diese Operation beendet ist,\n"
	.string "nehme ich dich mit zu den Heißen\l"
	.string "Quellen!\p"
	.string "Das hat unser Boss zu mir gesagt!\n"
	.string "Ich kann es kaum erwarten!$"
	.endif
	.endif

SlateportCity_Text_SeaIsSoWet:
	.ifdef ENGLISH
	.string "The sea is just so vast…\p"
	.string "Could the sea have been made by\n"
	.string "the tears shed by POKéMON?$"
	.else
	.ifdef GERMAN
	.string "Das Meer ist wirklich überwältigend…\p"
	.string "Ob es durch die vergossenen Tränen der\n"
	.string "POKéMON entstanden ist?$"
	.endif
	.endif

SlateportCity_Text_SinkOldBoats:
	.ifdef ENGLISH
	.string "Do you know what they do with old\n"
	.string "ships that become too creaky to sail?\p"
	.string "They sink them in the sea so they\n"
	.string "become habitats for POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Weißt du, was mit alten, nicht mehr\n"
	.string "seetüchtigen Schiffen gemacht wird?\p"
	.string "Sie werden im Meer versenkt und so\n"
	.string "zu Lebensraum für POKéMON.$"
	.endif
	.endif

SlateportCity_Text_BuyTooMuch:
	.ifdef ENGLISH
	.string "Whenever I visit here, I get carried\n"
	.string "away and buy too much.$"
	.else
	.ifdef GERMAN
	.string "Immer wenn ich hierher komme, vergesse\n"
	.string "ich mich und kaufe wie bescheuert ein.$"
	.endif
	.endif

SlateportCity_Text_GetNameRaterToHelpYou:
	.ifdef ENGLISH
	.string "If you want to change your POKéMON's\n"
	.string "nickname, you'll have to get the NAME\l"
	.string "RATER to help you.$"
	.else
	.ifdef GERMAN
	.string "Wenn du die Kosenamen deiner POKéMON\n"
	.string "ändern willst, solltest du den NAMEN-\l"
	.string "BEWERTER um Hilfe bitten.$"
	.endif
	.endif

SlateportCity_Text_CantChangeTradeMonName:
	.ifdef ENGLISH
	.string "Any POKéMON you get in a trade,\n"
	.string "you can't change its nickname.\p"
	.string "The original TRAINER's love for that\n"
	.string "POKéMON is in the nickname.$"
	.else
	.ifdef GERMAN
	.string "Erhältst du ein POKéMON durch Tausch,\n"
	.string "kannst du den Kosenamen nicht ändern.\p"
	.string "Die Liebe des ursprünglichen TRAINERs\n"
	.string "drückt sich in dem Kosenamen aus.$"
	.endif
	.endif

SlateportCity_Text_BattleTentBuiltRecently:
	.ifdef ENGLISH
	.string "Recently, a BATTLE TENT was built\n"
	.string "in SLATEPORT.\p"
	.string "GYMS are fun, but the BATTLE TENT's\n"
	.string "awesome in its own way.\p"
	.string "You should go find tough POKéMON\n"
	.string "for the BATTLE TENT!$"
	.else
	.ifdef GERMAN
	.string "In GRAPHITPORT CITY wurde vor kurzem\n"
	.string "ein KAMPFCAMP aufgebaut.\p"
	.string "ARENen machen Spaß, aber die KAMPF-\n"
	.string "CAMPs sind einfach unglaublich!\p"
	.string "Such dir aber erst ein paar starke\n"
	.string "POKéMON, bevor du in ein KAMPFCAMP\l"
	.string "gehst.$"
	.endif
	.endif

SlateportCity_Text_CaptSternBeingInterviewed:
	.ifdef ENGLISH
	.string "I was hoping that it was a famous star\n"
	.string "so I could get an autograph.\p"
	.string "But who's that being interviewed?\n"
	.string "Isn't that CAPT. STERN?$"
	.else
	.ifdef GERMAN
	.string "Ich habe gehofft, es wäre ein berühmter\n"
	.string "Star. Dann hätte ich mir ein Autogramm\l"
	.string "geben lassen.\p"
	.string "Aber wer wird denn da interviewt?\n"
	.string "Ist das nicht KAPT. BRIGG?$"
	.endif
	.endif

SlateportCity_Text_InterviewerSoCool:
	.ifdef ENGLISH
	.string "That lady interviewer is so cool\n"
	.string "and pretty.\p"
	.string "When I grow up, I'm going to be\n"
	.string "an international journalist!$"
	.else
	.ifdef GERMAN
	.string "Die Interviewerin ist so cool und\n"
	.string "hübsch.\p"
	.string "Wenn ich groß bin, werde ich ein\n"
	.string "weltberühmter Journalist.$"
	.endif
	.endif

SlateportCity_Text_SternSaysDiscoveredSomething:
	.ifdef ENGLISH
	.string "CAPT. STERN says they discovered\n"
	.string "something at the bottom of the sea.\p"
	.string "I wonder what it is?\n"
	.string "What could it be?$"
	.else
	.ifdef GERMAN
	.string "KAPT. BRIGG sagt, sie hätten etwas auf\n"
	.string "dem Meeresgrund entdeckt.\p"
	.string "Ich frage mich, was das wohl ist.\n"
	.string "Was könnte das sein???$"
	.endif
	.endif

SlateportCity_Text_CaptainComeBackWithBigFish:
	.ifdef ENGLISH
	.string "What's going on here?\p"
	.string "Did the good CAPTAIN come back with\n"
	.string "a big fish from the ocean floor?$"
	.else
	.ifdef GERMAN
	.string "Was ist denn hier los?\p"
	.string "Hat KAPT. BRIGG etwa einen Riesen-\n"
	.string "fisch vom Meeresgrund mitgebracht?$"
	.endif
	.endif

SlateportCity_Text_AmIOnTV:
	.ifdef ENGLISH
	.string "Hey! Are you watching?\n"
	.string "Am I on TV?$"
	.else
	.ifdef GERMAN
	.string "Hey! Nimmst du mich auf?\n"
	.string "Komm ich jetzt ins Fernsehen?$"
	.endif
	.endif

SlateportCity_Text_CaptainsACelebrity:
	.ifdef ENGLISH
	.string "A TV interview! Here!\n"
	.string "The CAPTAIN's a celebrity!$"
	.else
	.ifdef GERMAN
	.string "Ein TV-Interview! Hier!!!\n"
	.string "Der KAPITÄN ist ein Star!$"
	.endif
	.endif

SlateportCity_Text_BigSmileForCamera:
	.ifdef ENGLISH
	.string "TY: Okay, CAPT. STERN, a big smile\n"
	.string "for the camera!$"
	.else
	.ifdef GERMAN
	.string "UDO: Okay, KAPT. BRIGG, schenken Sie\n"
	.string "unserer Kamera Ihr schönstes Lächeln!$"
	.endif
	.endif

SlateportCity_Text_MostInvaluableExperience:
	.ifdef ENGLISH
	.string "GABBY: I see, I see. You've had a most\n"
	.string "invaluable experience…$"
	.else
	.ifdef GERMAN
	.string "PIA: Ich verstehe, ich verstehe. Sie\n"
	.string "haben eine unschätzbare Entdeckung\lgemacht…$"
	.endif
	.endif

SlateportCity_Text_SternMoveAheadWithExploration:
	.ifdef ENGLISH
	.string "CAPT. STERN: Yes, indeed. We intend to\n"
	.string "move ahead with our exploration.$"
	.else
	.ifdef GERMAN
	.string "KAPT. BRIGG: Ja, genau. Wir haben vor,\n"
	.string "unsere Expedition weiter fortzuführen.$"
	.endif
	.endif

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.ifdef ENGLISH
	.string "GABBY: That's wonderful, CAPT. STERN!\n"
	.string "Thank you for taking the time from\l"
	.string "your busy schedule to talk to us.\p"
	.string "We hope we can interview you again\n"
	.string "with news of more discoveries!$"
	.else
	.ifdef GERMAN
	.string "PIA: Das ist wunderbar, KAPT. BRIGG!\n"
	.string "Vielen Dank, dass Sie trotz Ihres vollen\l"
	.string "Terminkalenders Zeit für uns gefunden\l"
	.string "haben!\p"
	.string "Wir hoffen, Sie bald wieder zu neuen\n"
	.string "aufregenden Funden interviewen zu\ldürfen!$"
	.endif
	.endif

SlateportCity_Text_SternWhewFirstInterview:
	.ifdef ENGLISH
	.string "CAPT. STERN: Whew…\p"
	.string "That was my first time to be filmed for\n"
	.string "TV. That was nerve-wracking.$"
	.else
	.ifdef GERMAN
	.string "KAPT. BRIGG: Puuh…\p"
	.string "Das war das erste Mal, dass ich für eine\n"
	.string "Fernsehsendung interviewt wurde. Ich\l"
	.string "war vielleicht nervööös!$"
	.endif
	.endif

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.ifdef ENGLISH
	.string "Oh! {PLAYER}{KUN}!\n"
	.string "You're looking great!\p"
	.string "We made a huge discovery on our last\n"
	.string "seafloor exploration.\p"
	.string "We found an underwater cavern on\n"
	.string "ROUTE 128.\p"
	.string "We think it's the habitat of a POKéMON\n"
	.string "that's said to have been long extinct.$"
	.else
	.ifdef GERMAN
	.string "Oh! {PLAYER}{KUN}!\n"
	.string "Gut siehst du aus!\p"
	.string "Wir haben bei unserer letzten Tiefsee-\n"
	.string "Expedition eine großartige Entdeckung\lgemacht.\p"
	.string "Wir haben auf der ROUTE 128 eine Unter-\n"
	.string "wasserhöhle entdeckt.\p"
	.string "Wir glauben, es ist die Höhle eines\n"
	.string "POKéMON, das schon lange ausge-\lstorben ist.$"
	.endif
	.endif

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.ifdef ENGLISH
	.string "Fufufu…\n"
	.string "CAPT. STERN, I presume.\p"
	.string "We of TEAM AQUA will assume\n"
	.string "control of your submarine!\p"
	.string "Your objections are meaningless!\n"
	.string "We expect your total cooperation!\p"
	.string "Fufufu…\n"
	.string "Just watch and learn what TEAM\l"
	.string "AQUA has planned!$"
	.else
	.ifdef GERMAN
	.string "Hähähä…\n"
	.string "KAPT. BRIGG, nehme ich an.\p"
	.string "Wir von TEAM AQUA werden das U-Boot\n"
	.string "in unsere Gewalt nehmen!\p"
	.string "Eure Einwände sind bedeutungslos!\n"
	.string "Wir erwarten absolute Kooperation!\p"
	.string "Hähähä…\n"
	.string "Mal sehen, was ihr zu den Plänen von\l"
	.string "TEAM AQUA sagt!$"
	.endif
	.endif

SlateportCity_Text_SternWhatWasAllThat:
	.ifdef ENGLISH
	.string "CAPT. STERN: What was that all about?\p"
	.string "It sounded like someone using\n"
	.string "a megaphone…\p"
	.string "Where did it come from?$"
	.else
	.ifdef GERMAN
	.string "KAPT. BRIGG: Was soll das Ganze?\p"
	.string "Sieht aus, als benutze jemand ein\n"
	.string "Megaphon…\p"
	.string "Wo kommt das her?$"
	.endif
	.endif

SlateportCity_Text_FromHarborTryingToTakeSub:
	.ifdef ENGLISH
	.string "It's from the HARBOR!\p"
	.string "The submarine!\n"
	.string "They're trying to take it!$"
	.else
	.ifdef GERMAN
	.string "Das kommt von der Anlegestelle!\p"
	.string "Das U-Boot!\n"
	.string "Jemand versucht, es zu stehlen!$"
	.endif
	.endif

SlateportCity_Text_PleaseComeWithMe:
	.ifdef ENGLISH
	.string "{PLAYER}{KUN}!\n"
	.string "Please, come with me!$"
	.else
	.ifdef GERMAN
	.string "{PLAYER}{KUN}!\n"
	.string "Bitte, komm mit mir!$"
	.endif
	.endif

SlateportCity_Text_BattleTentSign:
	.ifdef ENGLISH
	.string "BATTLE TENT SLATEPORT SITE\n"
	.string "“Find it! The ultimate POKéMON!”$"
	.else
	.ifdef GERMAN
	.string "KAMPFCAMP GRAPHITPORT CITY\n"
	.string "“Finde es! Das ultimative POKéMON!”$"
	.endif
	.endif

SlateportCity_Text_SternsShipyardWantedSign:
	.ifdef ENGLISH
	.string "STERN'S SHIPYARD\p"
	.string "“Wanted: A sailor capable of sailing\n"
	.string "in all currents.”$"
	.else
	.ifdef GERMAN
	.string "BRIGGWERFT\p"
	.string "“Gesucht: Ein erfahrener Seemann,\n"
	.string "der die Gefahr nicht scheut.”$"
	.endif
	.endif

SlateportCity_Text_SternsShipyardNearsCompletion:
	.ifdef ENGLISH
	.string "STERN'S SHIPYARD\p"
	.string "“The ferry S.S. TIDAL nears\n"
	.string "completion for serving the ports of\l"
	.string "SLATEPORT and LILYCOVE.”$"
	.else
	.ifdef GERMAN
	.string "BRIGGWERFT\p"
	.string "“Die Fähre MS TIDE wird bald fertig\ngestellt sein und die Häfen von\l"
	.string "GRAPHITPORT CITY und SEEGRASULB CITY\l"
	.string "bedienen.”$"
	.endif
	.endif

SlateportCity_Text_SternsShipyardFerryComplete:
	.ifdef ENGLISH
	.string "STERN'S SHIPYARD\p"
	.string "“Boarding of the SLATEPORT-LILYCOVE\n"
	.string "ferry S.S. TIDAL is handled at the\l"
	.string "HARBOR.”$"
	.else
	.ifdef GERMAN
	.string "BRIGGWERFT\p"
	.string "“Bordkarten für die GRAPHITPORT CITY-\nSEEGRASULB CITY Fähre MS TIDE werden\lam HAFEN ausgegeben.”$"
	.endif
	.endif

SlateportCity_Text_PokemonFanClubSign:
	.ifdef ENGLISH
	.string "POKéMON FAN CLUB\n"
	.string "“Calling all fans of POKéMON!”$"
	.else
	.ifdef GERMAN
	.string "POKéMON-FANCLUB\n"
	.string "“Wir rufen alle Fans der POKéMON!”$"
	.endif
	.endif

SlateportCity_Text_OceanicMuseumSign:
	.ifdef ENGLISH
	.string "“The endless sea sustains\n"
	.string "all life.”\p"
	.string "OCEANIC MUSEUM$"
	.else
	.ifdef GERMAN
	.string "OZEANMUSEUM\p"
	.string "“Das unendliche Meer erhält\nalles Leben.”$"
	.endif
	.endif

SlateportCity_Text_CitySign:
	.ifdef ENGLISH
	.string "SLATEPORT CITY\p"
	.string "“The port where people and POKéMON\n"
	.string "cross paths.”$"
	.else
	.ifdef GERMAN
	.string "GRAPHITPORT CITY\p"
	.string "“Der Hafen, an dem sich Menschen\nund POKéMON begegnen.”$"
	.endif
	.endif

SlateportCity_Text_MarketSign:
	.ifdef ENGLISH
	.string "SLATEPORT MARKET\n"
	.string "“Unique items found nowhere else!”$"
	.else
	.ifdef GERMAN
	.string "GRAPHITPORT CITY MARKT\n"
	.string "“Einzigartige Items, die es\l"
	.string "nirgendwo sonst gibt!”$"
	.endif
	.endif

SlateportCity_Text_HarborFerryUnderConstruction:
	.ifdef ENGLISH
	.string "SLATEPORT HARBOR\p"
	.string "“The ferry S.S. TIDAL is under\n"
	.string "construction in the SHIPYARD.\p"
	.string "“Service is scheduled to begin\n"
	.string "shortly.”$"
	.else
	.ifdef GERMAN
	.string "HAFEN GRAPHITPORT CITY\p"
	.string "“Die Fähre MS TIDE wird momentan\nin der WERFT gebaut.\p"
	.string "Die Fähre wird so bald wie möglich ihren\nDienst aufnehmen.”$"
	.endif
	.endif

SlateportCity_Text_HarborSign:
	.ifdef ENGLISH
	.string "SLATEPORT HARBOR\p"
	.string "“Enjoy a delightful cruise on\n"
	.string "the ferry S.S. TIDAL.”$"
	.else
	.ifdef GERMAN
	.string "HAFEN GRAPHITPORT CITY\p"
	.string "“Genießen Sie die entspannende Fahrt\nmit der Fähre MS TIDE.”$"
	.endif
	.endif

SlateportCity_Text_NameRatersHouseSign:
	.ifdef ENGLISH
	.string "NAME RATER'S HOUSE\n"
	.string "“POKéMON nicknames rated.”$"
	.else
	.ifdef GERMAN
	.string "HAUS DES NAMENBEWERTERS\n"
	.string "“Bewertung von POKéMON-Kosenamen.”$"
	.endif
	.endif

SlateportCity_Text_ExplainBerries:
	.ifdef ENGLISH
	.string "If a wild POKéMON gets hurt, it heals\n"
	.string "itself by chewing on BERRIES.\p"
	.string "Did you know that?\p"
	.string "Somebody saw that and got the idea\n"
	.string "of making medicine from BERRIES.\p"
	.string "Did you know that?\p"
	.string "To turn BERRIES into medicine,\n"
	.string "they must be crushed into powder.\p"
	.string "Did you know that?\p"
	.string "You seem to have an interest\n"
	.string "in BERRIES!\p"
	.string "I've got something good for someone\n"
	.string "like you.$"
	.else
	.ifdef GERMAN
	.string "Verletzt sich ein wildes POKéMON, heilt\n"
	.string "es sich, indem es BEEREn isst.\p"
	.string "Wusstest du das?\p"
	.string "Irgendjemand hat dies beobachtet und\n"
	.string "kam so auf die Idee, aus BEEREn Medizin\l"
	.string "herzustellen.\p"
	.string "Und weißt du noch etwas?\p"
	.string "Um aus BEEREn Medizin herzustellen,\n"
	.string "muss man sie zu Pulver verarbeiten.\p"
	.string "Wusstest du das?\p"
	.string "Du scheinst sehr interessiert an\n"
	.string "BEEREn zu sein!\p"
	.string "Ich habe etwas Gutes für jemanden\n"
	.string "wie dich.$"
	.endif
	.endif

SlateportCity_Text_ExplainBerryPowder:
	.ifdef ENGLISH
	.string "I recently had machines installed at\n"
	.string "POKéMON CENTERS for crushing BERRIES.\p"
	.string "The BERRY CRUSH machines are at\n"
	.string "the DIRECT CORNER upstairs.\p"
	.string "Did you know?\p"
	.string "Could you make BERRY POWDER for\n"
	.string "me using those machines?\p"
	.string "I can make you all sorts of medicine\n"
	.string "if you bring me lots of BERRY POWDER.$"
	.else
	.ifdef GERMAN
	.string "Ich habe vor kurzem in den POKéMON-\nCENTERn Maschinen installiert,\l"
	.string "mit denen man BEEREn mahlen kann.\p"
	.string "Du findest sie im DIREKTKLUB\n"
	.string "im oberen Stockwerk.\p"
	.string "Wusstest du das?\p"
	.string "Kannst du mit dieser Maschine\n"
	.string "BEERENPUDER für mich\lherstellen?\p"
	.string "Ich werde Medizin herstellen,\n"
	.string "wenn du mir BEERENPUDER\lbringst.$"
	.endif
	.endif

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.ifdef ENGLISH
	.string "Have you brought me some\n"
	.string "BERRY POWDER?$"
	.else
	.ifdef GERMAN
	.string "Hast du mir BEERENPUDER\ngebracht?$"
	.endif
	.endif

SlateportCity_Text_ExchangeWhatWithIt:
	.ifdef ENGLISH
	.string "What would you like to exchange\n"
	.string "it with?$"
	.else
	.ifdef GERMAN
	.string "Wogegen möchtest du ihn tauschen?$"
	.endif
	.endif

SlateportCity_Text_ExchangeBerryPowderForItem:
	.ifdef ENGLISH
	.string "Okay, you want to exchange your\n"
	.string "BERRY POWDER for one {STR_VAR_1}?$"
	.else
	.ifdef GERMAN
	.string "Gut, ich gebe dir {STR_VAR_1} im\n"
	.string "Austausch für deinen\lBEERENPUDER!$"
	.endif
	.endif

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.ifdef ENGLISH
	.string "Oh, dear. You don't have enough\n"
	.string "BERRY POWDER.$"
	.else
	.ifdef GERMAN
	.string "Hm? Du hast nicht genügend\nBEERENPUDER!$"
	.endif
	.endif

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.ifdef ENGLISH
	.string "This is fine BERRY POWDER.\n"
	.string "It will make excellent medicine.\p"
	.string "Would you like to trade more of your\n"
	.string "BERRY POWDER for something else?$"
	.else
	.ifdef GERMAN
	.string "Das ist wirklich erstklassiger\nBEERENPUDER! Daraus lässt\lsich gute Medizin herstellen.\p"
	.string "Möchtest du noch mehr BEERENPUDER\ntauschen?$"
	.endif
	.endif

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.ifdef ENGLISH
	.string "Okay! When you get some more\n"
	.string "BERRY POWDER, bring it to me, please!$"
	.else
	.ifdef GERMAN
	.string "Fein! Wenn du mehr BEERENPUDER hast,\nkannst du mir ihn bitte geben?$"
	.endif
	.endif

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.ifdef ENGLISH
	.string "Come back if you'd like to trade your\n"
	.string "BERRY POWDER for some medicine.\p"
	.string "I'm always running a bazaar here.\p"
	.string "Did you know?$"
	.else
	.ifdef GERMAN
	.string "Komm einfach vorbei, wenn du\nBEERENPUDER tauschen möchtest!\p"
	.string "Ich leite hier den Bazar und bin daher\nständig hier.\p"
	.string "Wusstest du das?$"
	.endif
	.endif

SlateportCity_Text_YouDroveTeamAquaAway:
	.ifdef ENGLISH
	.string "SCOTT: Huh?\n"
	.string "I'm sure I met you somewhere before.\p"
	.string "Have I introduced myself to you?\n"
	.string "If not, my name's SCOTT.\p"
	.string "I just saw TEAM AQUA run away from\n"
	.string "here like they were stung.\p"
	.string "Let me guess--you drove them away?$"
	.else
	.ifdef GERMAN
	.string "SCOTT: Wie?\n"
	.string "Ich bin mir sicher, dich irgendwo schon\l"
	.string "mal gesehen zu haben.\p"
	.string "Habe ich mich eigentlich schon\n"
	.string "vorgestellt? Ich bin SCOTT.\p"
	.string "Eben ist TEAM AQUA von hier geflohen,\n"
	.string "als sei eine Horde Hornissen hinter\l"
	.string "ihnen her.\p"
	.string "Lass mich raten - du hast sie verjagt?$"
	.endif
	.endif

SlateportCity_Text_MaybeThisTrainer:
	.ifdef ENGLISH
	.string "SCOTT: Hmm…\n"
	.string "Maybe, just maybe, this TRAINER…$"
	.else
	.ifdef GERMAN
	.string "SCOTT: Hmm…\n"
	.string "Vielleicht, vielleicht dieser TRAINER…$"
	.endif
	.endif

SlateportCity_Text_LetsRegisterEachOther:
	.ifdef ENGLISH
	.string "SCOTT: All right! I think you're going\n"
	.string "to become a good friend.\p"
	.string "So, let's register each other in our\n"
	.string "POKéNAVS.\p"
	.string "… … … … … …$"
	.else
	.ifdef GERMAN
	.string "SCOTT: Sehr gut! Ich denke, wir werden\ngute Freunde werden.\p"
	.string "Wir sollten uns in unseren POKéNAVs\neintragen.\p"
	.string "… … … … …\n…$"
	.endif
	.endif

SlateportCity_Text_RegisteredScott:
	.ifdef ENGLISH
	.string "Registered this SCOTT person\n"
	.string "in the POKéNAV.$"
	.else
	.ifdef GERMAN
	.string "Dieser SCOTT wurde im POKéNAV-\nVerzeichnis eingetragen.$"
	.endif
	.endif

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.ifdef ENGLISH
	.string "SCOTT: What I'd like to do is tag along\n"
	.string "with you, but I do want to keep an eye\l"
	.string "on the talents of other people, too.\p"
	.string "So, I'll be off to roam other towns\n"
	.string "a bit more.\p"
	.string "Be seeing you, {PLAYER}{KUN}!$"
	.else
	.ifdef GERMAN
	.string "SCOTT: Ich würde dich gerne auf deinem\nWeg begleiten, aber natürlich möchte\lich auch andere Talente im Auge\p"
	.string "behalten. Daher werde ich jetzt andere\nOrte besuchen.\p"
	.string "Wir sehen uns, {PLAYER}{KUN}!$"
	.endif
	.endif

SlateportCity_Text_TakingBattleTentChallenge:
	.ifdef ENGLISH
	.string "SCOTT: Oh, hey!\n"
	.string "If it isn't {PLAYER}{KUN}!\p"
	.string "{PLAYER}{KUN}, let me guess--you're going\n"
	.string "to take the BATTLE TENT challenge?\p"
	.string "Yeah! That's a good idea!\n"
	.string "That's a really great idea!\p"
	.string "After all, a tough TRAINER is\n"
	.string "the perfect fit for the BATTLE TENT!\p"
	.string "Give it your best effort!$"
	.else
	.ifdef GERMAN
	.string "SCOTT: Oh, hey!\n"
	.string "Wenn das nicht {PLAYER}{KUN} ist!\p"
	.string "Lass mich raten, {PLAYER}{KUN} - du stellst\ndich der Herausforderung im KAMPFCAMP?\p"
	.string "Yeah! Eine gute Idee!\n"
	.string "Eine wirklich sehr gute Idee!\p"
	.string "Denn ein starker TRAINER ist wie\ngeschaffen für das KAMPFCAMP!\p"
	.string "Gib dein Bestes!$"
	.endif
	.endif
