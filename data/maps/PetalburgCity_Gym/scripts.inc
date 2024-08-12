.set LOCALID_NORMAN, 1
.set LOCALID_WALLY, 10
.set LOCALID_WALLYS_DAD, 11

PetalburgCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PetalburgCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_Gym_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_Gym_OnFrame
	.byte 0

PetalburgCity_Gym_OnLoad:
	goto_if_eq VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_OpenUnlockedDoors
	call_if_ge VAR_PETALBURG_GYM_STATE, 7, PetalburgCity_Gym_EventScript_UnlockAllDoors
	end

@ NOTE: Strength and OHKO rooms are misleading. Both are more accurately Critical-Hit
PetalburgCity_Gym_EventScript_OpenUnlockedDoors::
	setvar VAR_0x8005, 1
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
	call_if_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	call_if_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	call_if_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	call_if_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	call_if_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	call_if_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	call_if_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	end

PetalburgCity_Gym_EventScript_UnlockAllDoors::
	setvar VAR_0x8005, 1
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	return

PetalburgCity_Gym_OnTransition:
	call_if_eq VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_MoveWallyToEntrance
	call_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_MoveNormanToEntrance
	call_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_CheckNormanForRematch
	end

PetalburgCity_Gym_EventScript_MoveWallyToEntrance::
	setobjectxyperm LOCALID_WALLY, 5, 108
	return

PetalburgCity_Gym_EventScript_MoveNormanToEntrance::
	setobjectxyperm LOCALID_NORMAN, 4, 107
	return

PetalburgCity_Gym_EventScript_CheckNormanForRematch::
	setorcopyvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_NORMAN_1
	specialvar VAR_RESULT, IsTrainerReadyForRematch
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontMoveNormanToFront
	goto_if_eq VAR_PETALBURG_GYM_STATE, 8, PetalburgCity_Gym_EventScript_DontMoveNormanToFront
	setobjectxyperm LOCALID_NORMAN, 4, 107
	return

PetalburgCity_Gym_EventScript_DontMoveNormanToFront::
	setvar VAR_PETALBURG_GYM_STATE, 8
	end

PetalburgCity_Gym_OnWarp:
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_TurnPlayerNorth
	.2byte 0

PetalburgCity_Gym_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PetalburgCity_Gym_OnFrame:
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial
	.2byte 0

PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial::
	lockall
	msgbox PetalburgCity_Gym_Text_DadSoDidItWorkOut, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyThankYouBye, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitGym
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_WALLY
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_DadGoCollectBadges, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_GYM_STATE, 2
	releaseall
	end

PetalburgCity_Gym_Movement_WallyExitGym:
	walk_down
	walk_down
	walk_down
	delay_16
	step_end

PetalburgCity_Gym_EventScript_Norman::
	lock
	faceplayer
	switch VAR_PETALBURG_GYM_STATE
	case 2, PetalburgCity_Gym_EventScript_NormanNoBadges
	case 3, PetalburgCity_Gym_EventScript_NormanOneBadge
	case 4, PetalburgCity_Gym_EventScript_NormanTwoBadges
	case 5, PetalburgCity_Gym_EventScript_NormanThreeBadges
	case 6, PetalburgCity_Gym_EventScript_NormanBattle
	case 7, PetalburgCity_Gym_EventScript_NormanPostBattle
	case 8, PetalburgCity_Gym_EventScript_NormanRematch
	msgbox PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth
	case DIR_NORTH, PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth
	case DIR_WEST, PetalburgCity_Gym_EventScript_BeginWallyTutorialWest
	case DIR_EAST, PetalburgCity_Gym_EventScript_BeginWallyTutorialEast
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth::
	setvar VAR_0x8008, 0
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth::
	setvar VAR_0x8008, 1
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialWest::
	setvar VAR_0x8008, 2
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialEast::
	setvar VAR_0x8008, 3
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorial::
	addobject LOCALID_WALLY
	playse SE_DOOR
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyArriveSouth
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyArriveNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyArriveWestEast
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyArriveWestEast
	msgbox PetalburgCity_Gym_Text_WallyIdLikeAPokemon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_DadOhYoureWallyRight, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_DadHmISee, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanAddressPlayerWest
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanAddressPlayerEast
	msgbox PetalburgCity_Gym_Text_DadPlayerGoWithWally, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanAddressWallySouth
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanAddressWallyNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanAddressWallyWest
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanAddressWallyEast
	msgbox PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyOhWowThankYou, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanFaceDoorSouth
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanFaceDoorNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanFaceDoorWest
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanFaceDoorEast
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyFacePlayer
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyFaceDown
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyFacePlayer
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyFacePlayer
	msgbox PetalburgCity_Gym_Text_WouldYouReallyComeWithMe, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_FOLLOW_ME, FALSE
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_ExitGymWithWallySouth
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_ExitGymWithWallyWest
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_ExitGymWithWallyEast
	removeobject LOCALID_WALLY
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM
	setvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_PETALBURG_CITY_STATE, 2
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	special InitBirchState
	warp MAP_PETALBURG_CITY, 15, 8
	waitstate
	release
	end

PetalburgCity_Gym_EventScript_WallyArriveSouth::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyArrive
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyArriveNorth::
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyArriveNorth
	waitmovement 0
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyArriveWestEast::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyArrive
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallySouth::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallySouth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth::
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitNorth
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyWest::
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyWest
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyEast::
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitEast
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyEast
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerWest::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerEast::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallySouth::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyNorth::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyWest::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyEast::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyFacePlayer::
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyFaceDown::
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanNoBadges::
	msgbox PetalburgCity_Gym_Text_NormanGoToRustboro, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanOneBadge::
	msgbox PetalburgCity_Gym_Text_NormanGoToDewford, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanTwoBadges::
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanThreeBadges::
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanFaceDoorSouth::
	return

@ For all other NormanFaceDoorX, Norman is already facing the door from NormanAddressWallyX
PetalburgCity_Gym_EventScript_NormanFaceDoorNorth::
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanFaceDoorWest::
	return

PetalburgCity_Gym_EventScript_NormanFaceDoorEast::
	return

PetalburgCity_Gym_EventScript_NormanPostBattle::
	call PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_GiveEnigmaBerry
	goto_if_unset FLAG_RECEIVED_TM_FACADE, PetalburgCity_Gym_EventScript_GiveFacade2
	goto_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough
	msgbox PetalburgCity_Gym_Text_DadGoingToKeepTraining, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_GiveFacade2::
	call PetalburgCity_Gym_EventScript_GiveFacade
	release
	end

PetalburgCity_Gym_EventScript_NormanRematch::
	trainerbattle_rematch_double TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanPreRematch, PetalburgCity_Gym_Text_NormanRematchDefeat, PetalburgCity_Gym_Text_NormanRematchNeedTwoMons
	msgbox PetalburgCity_Gym_Text_NormanPostRematch, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry::
	specialvar VAR_RESULT, IsEnigmaBerryValid
	goto_if_eq VAR_RESULT, FALSE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	checkitem ITEM_ENIGMA_BERRY
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	checkpcitem ITEM_ENIGMA_BERRY
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	goto_if_eq VAR_ENIGMA_BERRY_AVAILABLE, 0, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	msgbox PetalburgCity_Gym_Text_GiveEnigmaBerry, MSGBOX_DEFAULT
	setvar VAR_RESULT, TRUE
	return

PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry::
	setvar VAR_RESULT, FALSE
	return

PetalburgCity_Gym_EventScript_GiveEnigmaBerry::
	giveitem ITEM_ENIGMA_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_ENIGMA_BERRY_AVAILABLE, 0
	release
	end

PetalburgCity_Gym_EventScript_NormanBattle::
	msgbox PetalburgCity_Gym_Text_NormanIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanDefeat
	message PetalburgCity_Gym_Text_ReceivedBalanceBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_PETALBURG_GYM
	setvar VAR_PETALBURG_GYM_STATE, 7
	setflag FLAG_BADGE05_GET
	special ResetHealLocationFromDewford
	call EventScript_HideMrBriney
	setflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	clearflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setvar VAR_0x8008, 5
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
	call PetalburgCity_Gym_EventScript_UnlockAllDoors
	special DrawWholeMapView
	call PetalburgCity_Gym_EventScript_GiveFacade
	delay 30
	msgbox PetalburgCity_Gym_Text_DadHappyAndSad, MSGBOX_DEFAULT
	closemessage
	delay 40
	playse SE_DOOR
	delay 10
	addobject LOCALID_WALLYS_DAD
	switch VAR_FACING
	case DIR_NORTH, PetalburgCity_Gym_EventScript_WallysDadArrivesNorth
	case DIR_WEST, PetalburgCity_Gym_EventScript_WallysDadArrivesWest
	case DIR_EAST, PetalburgCity_Gym_EventScript_WallysDadArrivesEast
	end

PetalburgCity_Gym_EventScript_GiveFacade::
	giveitem ITEM_TM_FACADE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_RECEIVED_TM_FACADE
	msgbox PetalburgCity_Gym_Text_ExplainFacade, MSGBOX_DEFAULT
	return

PetalburgCity_Gym_EventScript_WallysDadArrivesNorth::
	setvar VAR_0x8008, 1
	goto PetalburgCity_Gym_EventScript_WallysDadArrives

PetalburgCity_Gym_EventScript_WallysDadArrivesEast::
	setvar VAR_0x8008, 2
	goto PetalburgCity_Gym_EventScript_WallysDadArrives

PetalburgCity_Gym_EventScript_WallysDadArrivesWest::
	setvar VAR_0x8008, 3
	goto PetalburgCity_Gym_EventScript_WallysDadArrives

PetalburgCity_Gym_EventScript_WallysDadArrives::
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadEnterGym
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_WALLYS_DAD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLYS_DAD, Common_Movement_Delay48
	waitmovement 0
	delay 10
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest
	msgbox PetalburgCity_Gym_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 20
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest
	msgbox PetalburgCity_Gym_Text_LetMeBorrowPlayer, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_FOLLOW_ME, FALSE
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest
	removeobject LOCALID_WALLYS_DAD
	setvar VAR_PETALBURG_CITY_STATE, 4
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
	warp MAP_PETALBURG_CITY, 15, 8
	waitstate
	release
	end

PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth::
	applymovement LOCALID_WALLYS_DAD, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast::
	applymovement LOCALID_WALLYS_DAD, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest::
	applymovement LOCALID_WALLYS_DAD, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth::
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast::
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest::
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth::
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitNorth
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast::
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitEast
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest::
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitWest
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest
	waitmovement 0
	return

PetalburgCity_Gym_Movement_WallysDadExitNorth:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_faster_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_WallysDadExitEast:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_faster_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_WallysDadExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_faster_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth:
	delay_16
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast:
	delay_16
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_WallysDadEnterGym:
	walk_up
	delay_8
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end

PetalburgCity_Gym_Movement_Unused:
	walk_in_place_faster_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_down
	step_end

PetalburgCity_Gym_Movement_WallyArriveNorth:
	delay_16
	walk_up
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

PetalburgCity_Gym_Movement_WallyArrive:
	delay_16
	walk_up
	delay_16
	delay_8
	walk_up
	walk_up
	step_end

PetalburgCity_Gym_Movement_WallyExitNorth:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_WallyExitEast:
	walk_down
	walk_down
	walk_right
	walk_down
	walk_in_place_faster_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_WallyExitSouthWest:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallySouth:
	delay_16
	delay_16
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallyWest:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallyEast:
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough::
	msgbox PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_SpeedRoomDoor::
	lockall
	goto_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 85
	msgbox PetalburgCity_Gym_Text_EnterSpeedRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_EnterRoom::
	closemessage
	delay 30
	warpdoor MAP_PETALBURG_CITY_GYM, VAR_0x8008, VAR_0x8009
	waitstate
	releaseall
	end

PetalburgCity_Gym_EventScript_DontEnterRoom::
	releaseall
	end

PetalburgCity_Gym_EventScript_DoorLocked::
	msgbox PetalburgCity_Gym_Text_DoorAppearsLocked, MSGBOX_DEFAULT
	releaseall
	end

@ VAR_0x8008 and VAR_0x8009 below are the x and y coordinates of the warp
PetalburgCity_Gym_EventScript_AccuracyRoomDoor::
	lockall
	goto_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 98
	msgbox PetalburgCity_Gym_Text_EnterAccuracyRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_ConfusionRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 46
	msgbox PetalburgCity_Gym_Text_EnterConfusionRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftDefenseRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 59
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightDefenseRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 59
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RecoveryRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 72
	msgbox PetalburgCity_Gym_Text_EnterRecoveryRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftStrengthRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 20
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightStrengthRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 20
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftOHKORoomDoor::
	lockall
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 33
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightOHKORoomDoor::
	lockall
	goto_if_not_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 33
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftGymLeadersRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 7
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightGymLeadersRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 7
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_Randall::
	trainerbattle_single TRAINER_RANDALL, PetalburgCity_Gym_Text_RandallIntro, PetalburgCity_Gym_Text_RandallDefeat, PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_RandallPostBadge
	msgbox PetalburgCity_Gym_Text_RandallPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_RandallPostBadge::
	msgbox PetalburgCity_Gym_Text_RandallPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Parker::
	trainerbattle_single TRAINER_PARKER, PetalburgCity_Gym_Text_ParkerIntro, PetalburgCity_Gym_Text_ParkerDefeat, PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_ParkerPostBadge
	msgbox PetalburgCity_Gym_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_ParkerPostBadge::
	msgbox PetalburgCity_Gym_Text_ParkerPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_George::
	trainerbattle_single TRAINER_GEORGE, PetalburgCity_Gym_Text_GeorgeIntro, PetalburgCity_Gym_Text_GeorgeDefeat, PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GeorgePostBadge
	msgbox PetalburgCity_Gym_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_GeorgePostBadge::
	msgbox PetalburgCity_Gym_Text_GeorgePostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Berke::
	trainerbattle_single TRAINER_BERKE, PetalburgCity_Gym_Text_BerkeIntro, PetalburgCity_Gym_Text_BerkeDefeat, PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_BerkePostBadge
	msgbox PetalburgCity_Gym_Text_BerkePostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_BerkePostBadge::
	msgbox PetalburgCity_Gym_Text_BerkePostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Mary::
	trainerbattle_single TRAINER_MARY, PetalburgCity_Gym_Text_MaryIntro, PetalburgCity_Gym_Text_MaryDefeat, PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_MaryPostBadge
	msgbox PetalburgCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_MaryPostBadge::
	msgbox PetalburgCity_Gym_Text_MaryPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Alexia::
	trainerbattle_single TRAINER_ALEXIA, PetalburgCity_Gym_Text_AlexiaIntro, PetalburgCity_Gym_Text_AlexiaDefeat, PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_AlexiaPostBadge
	msgbox PetalburgCity_Gym_Text_AlexiaPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_AlexiaPostBadge::
	msgbox PetalburgCity_Gym_Text_AlexiaPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Jody::
	trainerbattle_single TRAINER_JODY, PetalburgCity_Gym_Text_JodyIntro, PetalburgCity_Gym_Text_JodyDefeat, PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_JodyPostBadge
	msgbox PetalburgCity_Gym_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_JodyPostBadge::
	msgbox PetalburgCity_Gym_Text_JodyPostBadge, MSGBOX_NPC
	end

@ VAR_0x8004 below is the room number
@ VAR_0x8005 below is 0 when the door should be slid open and 1 when it should be unlocked immediately
PetalburgCity_Gym_EventScript_OpenGymEntranceDoors::
	setvar VAR_0x8004, 1
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors::
	setvar VAR_0x8004, 2
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors::
	setvar VAR_0x8004, 3
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors::
	setvar VAR_0x8004, 4
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors::
	setvar VAR_0x8004, 5
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors::
	setvar VAR_0x8004, 6
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors::
	setvar VAR_0x8004, 7
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenOHKORoomDoors::
	setvar VAR_0x8004, 8
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles::
	setmetatile 6, 85, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 7, 85, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	setmetatile 1, 98, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 2, 98, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles::
	setmetatile 6, 46, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 7, 46, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	setmetatile 1, 59, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 2, 59, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles::
	setmetatile 6, 59, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 7, 59, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	setmetatile 1, 72, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 2, 72, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles::
	setmetatile 1, 20, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 2, 20, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles::
	setmetatile 6, 20, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 7, 20, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	setmetatile 1, 33, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 2, 33, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles::
	setmetatile 6, 33, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 7, 33, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles::
	setmetatile 1, 7, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 2, 7, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles::
	setmetatile 6, 7, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 7, 7, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SlideOpenRoomDoors::
	special PetalburgGymSlideOpenRoomDoors
	waitstate
	return

PetalburgCity_Gym_EventScript_UnlockRoomDoors::
	special PetalburgGymUnlockRoomDoors
	return

PetalburgCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GymGuidePostVictory
	msgbox PetalburgCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_GymGuidePostVictory::
	msgbox PetalburgCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
	goto PetalburgCity_Gym_EventScript_GymStatue
	end

PetalburgCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
	goto PetalburgCity_Gym_EventScript_GymStatue
	end

PetalburgCity_Gym_EventScript_GymStatueCertified::
	msgbox PetalburgCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_Gym_EventScript_GymStatue::
	msgbox PetalburgCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon:
	.ifdef ENGLISH
	.string "DAD: Hm?\p"
	.string "Well, if it isn't {PLAYER}!\n"
	.string "So you're all finished moving in?\p"
	.string "I'm surprised that you managed to\n"
	.string "get here by yourself.\p"
	.string "Oh, I see.\n"
	.string "You're with your POKéMON.\p"
	.string "Hm… Then I guess you're going to\n"
	.string "become a TRAINER like me, {PLAYER}.\p"
	.string "That's great news!\n"
	.string "I'll be looking forward to it!$"
	.else
	.ifdef GERMAN
	.string "VATER: Hm?\p"
	.string "Na, wenn das nicht {PLAYER} ist!\n"
	.string "Dann habt ihr also den Umzug beendet?\p"
	.string "Ich bin überrascht, dass du ganz\n"
	.string "alleine hierher gefunden hast.\p"
	.string "Oh, so ist das.\n"
	.string "Du bist in POKéMON-Begleitung.\p"
	.string "Ich glaube, du wirst einmal in meine\n"
	.string "Fußstapfen als TRAINER treten,\l"
	.string "{PLAYER}.\p"
	.string "Das sind großartige Aussichten!\n"
	.string "Ich kann es kaum erwarten!$"
	.endif
	.endif

PetalburgCity_Gym_Text_WallyIdLikeAPokemon:
	.ifdef ENGLISH
	.string "Um… I…\n"
	.string "I'd like to get a POKéMON, please…$"
	.else
	.ifdef GERMAN
	.string "Äh… Ich… Ich hätte so gerne ein\n"
	.string "POKéMON. Bitte…$"
	.endif
	.endif

PetalburgCity_Gym_Text_DadOhYoureWallyRight:
	.ifdef ENGLISH
	.string "DAD: Hm? You're… Uh… Oh, right.\n"
	.string "You're WALLY, right?$"
	.else
	.ifdef GERMAN
	.string "VATER: Wie? Du… Ach… Gut.\n"
	.string "Du bist HEIKO, nicht wahr?$"
	.endif
	.endif

PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon:
	.ifdef ENGLISH
	.string "WALLY: I'm going to go stay with my\n"
	.string "relatives in VERDANTURF TOWN.\p"
	.string "I thought I would be lonely by myself,\n"
	.string "so I wanted to take a POKéMON along.\p"
	.string "But I've never caught a POKéMON before.\n"
	.string "I don't know how…$"
	.else
	.ifdef GERMAN
	.string "HEIKO: Ich werde meine Verwandten\n"
	.string "in WIESENFLUR besuchen.\p"
	.string "Ich glaube, ich werde mich da doch\n"
	.string "einsam fühlen, daher würde ich gerne ein\l"
	.string "POKéMON mitnehmen.\p"
	.string "Aber ich habe noch nie eines gefangen.\n"
	.string "Ich weiß nicht, wie das geht…$"
	.endif
	.endif

PetalburgCity_Gym_Text_DadHmISee:
	.ifdef ENGLISH
	.string "DAD: Hm. I see.$"
	.else
	.ifdef GERMAN
	.string "VATER: Oh, ich verstehe…$"
	.endif
	.endif

PetalburgCity_Gym_Text_DadPlayerGoWithWally:
	.ifdef ENGLISH
	.string "DAD: {PLAYER}, you heard that,\n"
	.string "right?\p"
	.string "Go with WALLY and make sure that he\n"
	.string "safely catches a POKéMON.$"
	.else
	.ifdef GERMAN
	.string "VATER: {PLAYER}, hast du das gehört?\p"
	.string "Hilf doch bitte HEIKO dabei,\n"
	.string "ein POKéMON zu fangen.$"
	.endif
	.endif

PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon:
	.ifdef ENGLISH
	.string "WALLY, here, I'll loan you my POKéMON.\p"
	.string "WALLY received a ZIGZAGOON!$"
	.else
	.ifdef GERMAN
	.string "HEIKO, hier, ich leihe dir mein\n"
	.string "POKéMON.\p"
	.string "HEIKO hat ein ZIGZACHS erhalten.$"
	.endif
	.endif

PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall:
	.ifdef ENGLISH
	.string "WALLY: Oh, wow!\n"
	.string "A POKéMON!\p"
	.string "DAD: Hm. I'll give you a POKé BALL, too.\n"
	.string "Go for it!\p"
	.string "WALLY received a POKé BALL!$"
	.else
	.ifdef GERMAN
	.string "HEIKO: Oh, wow!!!\n"
	.string "Ein POKéMON!\p"
	.string "VATER: Hm. Ich gebe dir auch diesen\n"
	.string "POKéBALL. Dann leg los!\p"
	.string "HEIKO erhält einen POKéBALL!$"
	.endif
	.endif

PetalburgCity_Gym_Text_WallyOhWowThankYou:
	.ifdef ENGLISH
	.string "WALLY: Oh, wow!\n"
	.string "Thank you!$"
	.else
	.ifdef GERMAN
	.string "HEIKO: Oh, wow!!!\n"
	.string "Danke schön!$"
	.endif
	.endif

PetalburgCity_Gym_Text_WouldYouReallyComeWithMe:
	.ifdef ENGLISH
	.string "{PLAYER}… Would you really come\n"
	.string "with me?$"
	.else
	.ifdef GERMAN
	.string "{PLAYER}… Kommst du wirklich mit mir???$"
	.endif
	.endif

PetalburgCity_Gym_Text_DadSoDidItWorkOut:
	.ifdef ENGLISH
	.string "DAD: So, did it work out?$"
	.else
	.ifdef GERMAN
	.string "VATER: Und? Hat es geklappt?$"
	.endif
	.endif

PetalburgCity_Gym_Text_WallyThankYouBye:
	.ifdef ENGLISH
	.string "WALLY: Thank you, yes, it did.\n"
	.string "Here's your POKéMON back.\p"
	.string "{PLAYER}, thank you for coming along\n"
	.string "with me.\p"
	.string "You two are why I was able to catch\n"
	.string "my POKéMON.\p"
	.string "I promise I'll take really good\n"
	.string "care of it.\p"
	.string "Oh! My mom's waiting for me,\n"
	.string "so I have to go!\p"
	.string "Bye, {PLAYER}!$"
	.else
	.ifdef GERMAN
	.string "HEIKO: Danke. Ja, wunderbar.\n"
	.string "Hier haben Sie Ihr POKéMON zurück.\p"
	.string "Danke, {PLAYER}, dass du mit mir\n"
	.string "gegangen bist.\p"
	.string "Euch beiden habe ich es zu verdanken,\n"
	.string "dass ich mein erstes POKéMON fangen\l"
	.string "konnte.\p"
	.string "Ich verspreche, ich werde mich gut\n"
	.string "darum kümmern!\p"
	.string "Oh! Meine Mama wartet sicher schon auf\n"
	.string "mich! Ich muss nach Hause!\p"
	.string "Bis bald, {PLAYER}!$"
	.endif
	.endif

PetalburgCity_Gym_Text_DadGoCollectBadges:
	.ifdef ENGLISH
	.string "DAD: Now…\p"
	.string "{PLAYER}, if you want to become a\n"
	.string "strong TRAINER, here's my advice.\p"
	.string "Head for RUSTBORO CITY beyond this\n"
	.string "town.\p"
	.string "There, you should challenge\n"
	.string "the GYM LEADER, ROXANNE.\p"
	.string "After her, go on to other POKéMON\n"
	.string "GYMS and defeat their LEADERS.\p"
	.string "Collect BADGES from them,\n"
	.string "understood?\p"
	.string "Of course, I'm a GYM LEADER, too.\n"
	.string "We'll battle one day, {PLAYER}.\p"
	.string "But that's only after you become\n"
	.string "stronger.$"
	.else
	.ifdef GERMAN
	.string "VATER: Nun…\p"
	.string "{PLAYER}, wenn du ein guter TRAINER\n"
	.string "werden willst - hier ist mein Rat.\p"
	.string "Gehe nach METAROST CITY, gleich hinter\n"
	.string "diesem Ort.\p"
	.string "Dort solltest du die ARENALEITERIN\n"
	.string "FELIZIA herausfordern.\p"
	.string "Suche danach die anderen POKéMON\n"
	.string "ARENen auf und besiege die LEITER.\p"
	.string "Sammle die ORDEN der verschiedenen\n"
	.string "ARENen, verstehst du?\p"
	.string "Ich bin natürlich auch ein ARENALEITER.\n"
	.string "Auch wir werden eines Tages\l"
	.string "gegeneinander antreten.\p"
	.string "Aber erst, wenn du stärker geworden\n"
	.string "bist, {PLAYER}.$"
	.endif
	.endif

PetalburgCity_Gym_Text_NormanGoToRustboro:
	.ifdef ENGLISH
	.string "DAD: Hm? Aren't you going to the\n"
	.string "POKéMON GYM in RUSTBORO CITY?\p"
	.string "There's no challenge for me to\n"
	.string "battle a greenhorn TRAINER.\p"
	.string "{PLAYER}, I want you to challenge me\n"
	.string "when you become a lot stronger.\p"
	.string "I'll battle you, {PLAYER}, when you\n"
	.string "can show me four GYM BADGES, okay?$"
	.else
	.ifdef GERMAN
	.string "VATER: Hm? Wolltest du nicht zur\n"
	.string "POKéMON ARENA in METAROST CITY?\p"
	.string "Für mich ist es keine Herausforderung,\n"
	.string "gegen einen Grünschnabel anzutreten.\p"
	.string "{PLAYER}, ich möchte, dass du mich he-\n"
	.string "rausforderst, sobald du stärker bist.\p"
	.string "Ich werde gegen dich kämpfen, {PLAYER},\n"
	.string "sobald du vier ORDEN erhalten hast, ja?$"
	.endif
	.endif

PetalburgCity_Gym_Text_NormanGoToDewford:
	.ifdef ENGLISH
	.string "DAD: I see… So, you've beaten\n"
	.string "the GYM LEADER in RUSTBORO CITY.\p"
	.string "But there are many more TRAINERS\n"
	.string "who are stronger than you, {PLAYER}.\p"
	.string "Across the sea in DEWFORD TOWN is a\n"
	.string "GYM LEADER named BRAWLY.\p"
	.string "You should go challenge him.$"
	.else
	.ifdef GERMAN
	.string "VATER: Oh, ich sehe schon… Du hast die\n"
	.string "ARENALEITERIN in METAROST CITY\l"
	.string "besiegt.\p"
	.string "Aber es gibt weitere TRAINER, die\n"
	.string "stärker sind als du, {PLAYER}.\p"
	.string "Wenn du das Meer überquerst, kommst du\n"
	.string "nach FAUSTAUHAVEN. Dort triffst du auf\l"
	.string "den ARENALEITER KAMILLO.\p"
	.string "Du solltest ihn wirklich herausfordern…$"
	.endif
	.endif

PetalburgCity_Gym_Text_YouHaveGottenStronger:
	.ifdef ENGLISH
	.string "DAD: Hm… {PLAYER}, you have gotten\n"
	.string "stronger.\p"
	.string "I can tell by the number of BADGES\n"
	.string "that you've earned.$"
	.else
	.ifdef GERMAN
	.string "VATER: Hm… {PLAYER}, du bist stärker\n"
	.string "geworden.\p"
	.string "Das sehe ich an der Anzahl der ORDEN,\n"
	.string "die du dir verdient hast.$"
	.endif
	.endif

PetalburgCity_Gym_Text_NormanIntro:
	.ifdef ENGLISH
	.string "DAD: Hm…\n"
	.string "So, you did get four GYM BADGES.\p"
	.string "Fine, as I promised, we will have\n"
	.string "a POKéMON battle.\p"
	.string "{PLAYER}…\p"
	.string "I'm so happy that I can have\n"
	.string "a real battle with my own child.\p"
	.string "But, a battle is a battle!\p"
	.string "I will do everything in my power as\n"
	.string "a GYM LEADER to win.\p"
	.string "{PLAYER}, you'd better give it your\n"
	.string "best shot, too!$"
	.else
	.ifdef GERMAN
	.string "VATER: Hm…\n"
	.string "Du besitzt vier ORDEN.\p"
	.string "Fein. Wie versprochen werden wir nun\n"
	.string "einen POKéMON-Kampf ausfechten.\p"
	.string "{PLAYER}…\p"
	.string "Ich bin so glücklich, dass mein eigenes\n"
	.string "Kind stark genug ist, gegen\l"
	.string "mich zu kämpfen!\p"
	.string "Aber: Kampf ist Kampf!\p"
	.string "Ich werde als ARENALEITER alles tun, um\n"
	.string "diesen Kampf zu gewinnen!\p"
	.string "{PLAYER}, du solltest ebenfalls dein\n"
	.string "Bestes geben!$"
	.endif
	.endif

PetalburgCity_Gym_Text_NormanDefeat:
	.ifdef ENGLISH
	.string "…\p"
	.string "I… I can't…\p"
	.string "I can't believe it. {PLAYER}…\p"
	.string "I lost to {PLAYER}?\p"
	.string "But, rules are rules!\n"
	.string "Here, take this.$"
	.else
	.ifdef GERMAN
	.string "…\p"
	.string "Ich… Ich kann es nicht…\p"
	.string "Ich kann es nicht glauben, {PLAYER}…\p"
	.string "Ich habe gegen {PLAYER} verloren?\p"
	.string "Nun, Regeln sind Regeln!\n"
	.string "Hier, das ist für dich.$"
	.endif
	.endif

PetalburgCity_Gym_Text_ReceivedBalanceBadge:
	.ifdef ENGLISH
	.string "{PLAYER} received the BALANCE BADGE\n"
	.string "from DAD!$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} hat den BALANCEORDEN vom\n"
	.string "VATER erhalten!$"
	.endif
	.endif

PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis:
	.ifdef ENGLISH
	.string "DAD: With that BADGE, the DEFENSE\n"
	.string "of all your POKéMON will increase.\p"
	.string "POKéMON that know the HM move SURF\n"
	.string "will be able to travel over water.\p"
	.string "This is my gift to you. {PLAYER}, I'm\n"
	.string "sure you can use it correctly.$"
	.else
	.ifdef GERMAN
	.string "VATER: Mit diesem ORDEN erhöht sich die\n"
	.string "VERTEIDIGUNG all deiner POKéMON.\p"
	.string "POKéMON, die die VM SURFER erlernt\n"
	.string "haben, können diese auch zum Reisen\l"
	.string "über das Wasser einsetzen.\p"
	.string "{PLAYER}, das ist mein Geschenk für\n"
	.string "dich. Ich bin sicher, du wirst es gut\l"
	.string "nutzen.$"
	.endif
	.endif

PetalburgCity_Gym_Text_ExplainFacade:
	.ifdef ENGLISH
	.string "DAD: TM42 contains FACADE.\p"
	.string "It doubles the power of moves if\n"
	.string "the POKéMON is poisoned, paralyzed,\l"
	.string "or burned.\p"
	.string "It might be able to turn a bad\n"
	.string "situation into an advantage.$"
	.else
	.ifdef GERMAN
	.string "VATER: TM42 enthält FASSADE.\p"
	.string "Sie verdoppelt die Stärke der Attacken,\n"
	.string "wenn das POKéMON vergiftet,\l"
	.string "paralysiert oder verbrannt wurde.\p"
	.string "So kann eine vermeintlich aussichts-\n"
	.string "lose Situation vielleicht gerettet\l"
	.string "werden.$"
	.endif
	.endif

PetalburgCity_Gym_Text_DadHappyAndSad:
	.ifdef ENGLISH
	.string "DAD: As the GYM LEADER, I can't\n"
	.string "express how upset I am…\p"
	.string "But as a father, it makes me both\n"
	.string "happy and a little sad. It's odd…$"
	.else
	.ifdef GERMAN
	.string "VATER: Als ARENALEITER kann ich gar\n"
	.string "nicht sagen, wie bestürzt ich bin…\p"
	.string "Als Vater macht es mich einerseits sehr\n"
	.string "stolz, andererseits aber auch traurig…$"
	.endif
	.endif

PetalburgCity_Gym_Text_PleaseComeWithMe:
	.ifdef ENGLISH
	.string "Ah, there you are, {PLAYER}{KUN}!\p"
	.string "Please come with me.\n"
	.string "I have something I want you to have.$"
	.else
	.ifdef GERMAN
	.string "Ah, da bist du ja, {PLAYER}{KUN}!\p"
	.string "Komm doch bitte mal mit.\n"
	.string "Ich habe hier etwas für dich.$"
	.endif
	.endif

PetalburgCity_Gym_Text_LetMeBorrowPlayer:
	.ifdef ENGLISH
	.string "NORMAN, you don't mind, do you?\p"
	.string "Let me borrow your {PLAYER}{KUN} for\n"
	.string "a minute or two.$"
	.else
	.ifdef GERMAN
	.string "NORMAN, du hast doch nichts dagegen?\p"
	.string "Ich entführe dir {PLAYER}{KUN} mal eben für\n"
	.string "ein paar Minuten.$"
	.endif
	.endif

PetalburgCity_Gym_Text_DadGoingToKeepTraining:
	.ifdef ENGLISH
	.string "DAD: {PLAYER}, you should go visit\n"
	.string "your mother every so often.\p"
	.string "I'm going to stay here and redouble\n"
	.string "my training.\p"
	.string "It would bother me as a TRAINER to\n"
	.string "not avenge my loss to you, {PLAYER}!$"
	.else
	.ifdef GERMAN
	.string "VATER: {PLAYER}, du solltest deine\n"
	.string "Mutter öfter mal besuchen.\p"
	.string "Ich bleibe hier und werde mein Training\n"
	.string "verdoppeln.\p"
	.string "Als TRAINER lässt es mir keine Ruhe. Ich\n"
	.string "möchte irgendwann gegen dich gewinnen.$"
	.endif
	.endif

PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough:
	.ifdef ENGLISH
	.string "DAD: {PLAYER}, how are things going?\p"
	.string "The world of POKéMON is deep.\p"
	.string "I honestly think that no amount of\n"
	.string "training would ever be enough.$"
	.else
	.ifdef GERMAN
	.string "VATER: {PLAYER}! Wie geht es dir?\p"
	.string "Die Welt der POKéMON ist vielfältig.\p"
	.string "Ich bin überzeugt, dass selbst das \n"
	.string "härteste Training dieser Vielfalt nicht\l"
	.string "gerecht wird.$"
	.endif
	.endif

PetalburgCity_Gym_Text_GymGuideAdvice:
	.ifdef ENGLISH
	.string "Hey, how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "The doors in this GYM open when you\n"
	.string "beat the awaiting TRAINERS.\p"
	.string "Whoops! The doors in this room are\n"
	.string "already open, so don't attack me!\p"
	.string "The TRAINERS of PETALBURG GYM\n"
	.string "use all kinds of items.\p"
	.string "The door at the left leads to\n"
	.string "the SPEED ROOM.\p"
	.string "The door at the right leads to\n"
	.string "the ACCURACY ROOM.\p"
	.string "The room's name will be on\n"
	.string "the door, so choose carefully.\p"
	.string "Once you've chosen the door…\n"
	.string "Well, hey, go for it!$"
	.else
	.ifdef GERMAN
	.string "Na, wie sieht es aus, auf dem Weg zum\n"
	.string "CHAMP, {PLAYER}?\p"
	.string "Die Türen dieser ARENA öffnen sich,\n"
	.string "wenn du die einzelnen TRAINER besiegst.\p"
	.string "Huups! Die Türen in diesem Raum sind ja\n"
	.string "schon offen, greif mich bitte nicht an!\p"
	.string "Die TRAINER der ARENA von BLÜTENBURG\n"
	.string "CITY setzen die verschiedensten\l"
	.string "Items ein.\p"
	.string "Die Tür auf der linken Seite führt in\n"
	.string "den INITIATIVE-RAUM.\p"
	.string "Die Tür auf der rechten Seite führt in\n"
	.string "den RAUM der GENAUIGKEIT.\p"
	.string "Die Türen sind beschriftet, lies genau\n"
	.string "und triff eine überlegte Wahl.\p"
	.string "Hast du dich für eine Tür entschieden…\n"
	.string "Nun, ähm, genug der Worte!$"
	.endif
	.endif

PetalburgCity_Gym_Text_GymGuidePostVictory:
	.ifdef ENGLISH
	.string "{PLAYER}! Whoa! You've overcome even\n"
	.string "your own father!\p"
	.string "Like, whoa!\n"
	.string "What a stunning turn of events!$"
	.else
	.ifdef GERMAN
	.string "{PLAYER}! Hui! Du hast sogar deinen\n"
	.string "eigenen Vater besiegt!\p"
	.string "Wie… Unglaublich!\n"
	.string "Die Ereignisse überschlagen sich!$"
	.endif
	.endif

PetalburgCity_Gym_Text_RandallIntro:
	.ifdef ENGLISH
	.string "The ability to attack before the\n"
	.string "opponent…\p"
	.string "Just that alone puts me at a great\n"
	.string "advantage, don't you agree?$"
	.else
	.ifdef GERMAN
	.string "Die Fähigkeit, dem Gegner mit einer\n"
	.string "Attacke zuvorzukommen…\p"
	.string "Das alleine gibt einem doch schon einen\n"
	.string "enormen Vorteil, meinst du nicht auch?$"
	.endif
	.endif

PetalburgCity_Gym_Text_RandallDefeat:
	.ifdef ENGLISH
	.string "That was a magnificent battle!$"
	.else
	.ifdef GERMAN
	.string "Das war ein unglaublicher Kampf!$"
	.endif
	.endif

PetalburgCity_Gym_Text_RandallPostBattle:
	.ifdef ENGLISH
	.string "Go on to the next room where a new\n"
	.string "challenge awaits you.\p"
	.string "At the left is the CONFUSION ROOM.\p"
	.string "The right door leads to the DEFENSE\n"
	.string "ROOM.$"
	.else
	.ifdef GERMAN
	.string "Geh weiter in den nächsten Raum, wo\n"
	.string "eine neue Herausforderung wartet.\p"
	.string "Auf der linken Seite befindet sich der\n"
	.string "RAUM der VERWIRRUNG.\p"
	.string "Auf der rechten Seite findest du den\n"
	.string "RAUM der VERTEIDIGUNG.$"
	.endif
	.endif

PetalburgCity_Gym_Text_RandallPostBadge:
	.ifdef ENGLISH
	.string "Whomever you beat, and whomever you\n"
	.string "may lose to, you never shirk from\l"
	.string "training yourself and your POKéMON.\p"
	.string "That's what I think being a\n"
	.string "GYM LEADER is all about.$"
	.else
	.ifdef GERMAN
	.string "Ob du siegst oder verlierst… Du darfst\n"
	.string "dein Training und das deiner POKéMON\l"
	.string "auf keinen Fall vernachlässigen.\p"
	.string "Das macht für mich einen wahren\n"
	.string "ARENALEITER aus.$"
	.endif
	.endif

PetalburgCity_Gym_Text_ParkerIntro:
	.ifdef ENGLISH
	.string "This is the CONFUSION ROOM.\p"
	.string "Let me see how well bonded you are\n"
	.string "with your POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Dies ist der RAUM der VERWIRRUNG.\p"
	.string "Zeig mir, wie stark das Band zwischen\n"
	.string "dir und deinen POKéMON ist.$"
	.endif
	.endif

PetalburgCity_Gym_Text_ParkerDefeat:
	.ifdef ENGLISH
	.string "I couldn't confuse your team enough…\n"
	.string "You share a strong bond together.$"
	.else
	.ifdef GERMAN
	.string "Ich konnte dein Team nicht genug\n"
	.string "verwirren… Euer Band ist stark.$"
	.endif
	.endif

PetalburgCity_Gym_Text_ParkerPostBattle:
	.ifdef ENGLISH
	.string "The next room is the STRENGTH ROOM.\n"
	.string "Can you withstand brute force?$"
	.else
	.ifdef GERMAN
	.string "Der nächste Raum ist der RAUM der\n"
	.string "STÄRKE. Kommst du gegen pure\l"
	.string "Gewalt an?$"
	.endif
	.endif

PetalburgCity_Gym_Text_ParkerPostBadge:
	.ifdef ENGLISH
	.string "After you beat our LEADER, the\n"
	.string "training has become a lot tougher.$"
	.else
	.ifdef GERMAN
	.string "Nachdem du unseren ARENALEITER be-\n"
	.string "siegt hast, wurde unser Training härter.$"
	.endif
	.endif

PetalburgCity_Gym_Text_GeorgeIntro:
	.ifdef ENGLISH
	.string "Just when you think you're going to\n"
	.string "win, your opponent restores HP…\p"
	.string "Can you just imagine how awful that\n"
	.string "must feel?\p"
	.string "I'll show you exactly how awful it\n"
	.string "feels!$"
	.else
	.ifdef GERMAN
	.string "Immer, wenn du den Sieg in greifbarer\n"
	.string "Nähe siehst, füllt dein Gegner KP auf…\p"
	.string "Kannst du dir vorstellen, wie man sich in\n"
	.string "so einer Situation fühlt?\p"
	.string "Ich werde dir so eine Situation\n"
	.string "demonstrieren!$"
	.endif
	.endif

PetalburgCity_Gym_Text_GeorgeDefeat:
	.ifdef ENGLISH
	.string "I couldn't restore HP enough…\n"
	.string "What ATTACK power…$"
	.else
	.ifdef GERMAN
	.string "Ich konnte nicht genügend KP\n"
	.string "auffüllen… Welch eine ANGRIFFskraft…$"
	.endif
	.endif

PetalburgCity_Gym_Text_GeorgePostBattle:
	.ifdef ENGLISH
	.string "I should have expected no less from\n"
	.string "our LEADER's kid.\p"
	.string "No, wait! A TRAINER's abilities are\n"
	.string "earned only through effort.\p"
	.string "I lost because my own efforts\n"
	.string "weren't enough.\p"
	.string "Go on! The ONE-HIT KO ROOM is next.$"
	.else
	.ifdef GERMAN
	.string "Ich hatte vom Kind unseres ARENA-\n"
	.string "LEITERs nichts anderes erwartet!\p"
	.string "Nein! Die Fähigkeiten eines TRAINERs\n"
	.string "entwickeln sich mit dem Training.\p"
	.string "Ich habe mich offensichtlich nicht\n"
	.string "genug angestrengt.\p"
	.string "Geh! Der nächste Raum ist der K.O.-\n"
	.string "TREFFER-RAUM.$"
	.endif
	.endif

PetalburgCity_Gym_Text_GeorgePostBadge:
	.ifdef ENGLISH
	.string "I'm going to keep training at GYMS.\n"
	.string "One day, I'll become a LEADER.$"
	.else
	.ifdef GERMAN
	.string "Ich werde auch weiterhin in den ARENen\n"
	.string "trainieren. Und ARENALEITER werden!$"
	.endif
	.endif

PetalburgCity_Gym_Text_BerkeIntro:
	.ifdef ENGLISH
	.string "I'm not going to take it easy just\n"
	.string "because you're our LEADER's kid.\p"
	.string "I'll show you how horrid it is for\n"
	.string "a POKéMON to take a critical hit!$"
	.else
	.ifdef GERMAN
	.string "Ich werde es dir nicht leicht machen,\n"
	.string "nur weil du das Kind unseres LEITERs\l"
	.string "bist.\p"
	.string "Ich werde dir beibringen, was es für ein\n"
	.string "POKéMON bedeutet, einen Volltreffer\l"
	.string "zu erhalten.$"
	.endif
	.endif

PetalburgCity_Gym_Text_BerkeDefeat:
	.ifdef ENGLISH
	.string "Your power…\n"
	.string "You're the real deal.$"
	.else
	.ifdef GERMAN
	.string "Deine Stärke…\n"
	.string "Du kämpfst großartig!$"
	.endif
	.endif

PetalburgCity_Gym_Text_BerkePostBattle:
	.ifdef ENGLISH
	.string "Your father really is strong.\n"
	.string "He's a TRAINER worth my respect.\p"
	.string "And, I sense the same glow coming\n"
	.string "from you as your father.\p"
	.string "I hope that you'll stage a terrific\n"
	.string "battle with your father!$"
	.else
	.ifdef GERMAN
	.string "Dein Vater ist stark. Als TRAINER\n"
	.string "erweise ich ihm den größten Respekt.\p"
	.string "Und ich sehe, dass die gleiche Stärke\n"
	.string "auch in dir ruht.\p"
	.string "Ich fühle, dass du dich nun einem\n"
	.string "Kampf mit deinem Vater stellen kannst.$"
	.endif
	.endif

PetalburgCity_Gym_Text_BerkePostBadge:
	.ifdef ENGLISH
	.string "Since your dad became the LEADER,\n"
	.string "the TRAINERS of PETALBURG CITY have\l"
	.string "become a lot tougher.$"
	.else
	.ifdef GERMAN
	.string "Seit dein Vater der LEITER der ARENA\n"
	.string "von BLÜTENBURG CITY ist, sind die\l"
	.string "TRAINER dort viel stärker geworden.$"
	.endif
	.endif

PetalburgCity_Gym_Text_MaryIntro:
	.ifdef ENGLISH
	.string "Giggle…\n"
	.string "This is the ACCURACY ROOM.\p"
	.string "It's pretty nasty when every attack\n"
	.string "lands without fail.$"
	.else
	.ifdef GERMAN
	.string "Kicher…\n"
	.string "Dies ist der RAUM der GENAUIGKEIT.\p"
	.string "Es ist schon ziemlich fies, wenn jede\n"
	.string "Attacke ein Treffer ist.$"
	.endif
	.endif

PetalburgCity_Gym_Text_MaryDefeat:
	.ifdef ENGLISH
	.string "You were a cut above me…$"
	.else
	.ifdef GERMAN
	.string "Du bist ein bisschen stärker als ich…$"
	.endif
	.endif

PetalburgCity_Gym_Text_MaryPostBattle:
	.ifdef ENGLISH
	.string "There are some even stronger\n"
	.string "TRAINERS waiting for you.\p"
	.string "The left is the DEFENSE ROOM, and\n"
	.string "the right is the RECOVERY ROOM.\p"
	.string "Your POKéMON's ATTACK power will be\n"
	.string "on trial either way.$"
	.else
	.ifdef GERMAN
	.string "Es warten noch weitaus stärkere\n"
	.string "TRAINER auf dich.\p"
	.string "Der linke ist der RAUM der VERTEIDIGUNG\n"
	.string "und der rechte der RAUM der ERHOLUNG.\p"
	.string "Die ATTACKEN deiner POKéMON werden\n"
	.string "in beiden Räumen auf die Probe gestellt.$"
	.endif
	.endif

PetalburgCity_Gym_Text_MaryPostBadge:
	.ifdef ENGLISH
	.string "Do you know what we're trying to\n"
	.string "achieve as TRAINERS?\p"
	.string "We're striving to become soul mates\n"
	.string "with our POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Weißt du, wonach wir als TRAINER\n"
	.string "streben?\p"
	.string "Wir streben danach, die Seelenfreunde\n"
	.string "unserer POKéMON zu werden.$"
	.endif
	.endif

PetalburgCity_Gym_Text_AlexiaIntro:
	.ifdef ENGLISH
	.string "The higher the DEFENSE, the more\n"
	.string "reckless I can be in attack.$"
	.else
	.ifdef GERMAN
	.string "Je stärker die VERTEIDIGUNG ist, desto\n"
	.string "rücksichtsloser kann ich angreifen.$"
	.endif
	.endif

PetalburgCity_Gym_Text_AlexiaDefeat:
	.ifdef ENGLISH
	.string "Our defenses weren't enough…$"
	.else
	.ifdef GERMAN
	.string "Unsere Verteidigung reichte nicht aus…$"
	.endif
	.endif

PetalburgCity_Gym_Text_AlexiaPostBattle:
	.ifdef ENGLISH
	.string "I think you've taught me a valuable\n"
	.string "lesson here.\p"
	.string "Now, go on! The left door goes to\n"
	.string "the STRENGTH ROOM.\p"
	.string "The right door opens to\n"
	.string "the ONE-HIT KO ROOM.\p"
	.string "Both of them have TRAINERS who are\n"
	.string "skilled at offense.$"
	.else
	.ifdef GERMAN
	.string "Ich denke, du hast mir eine wertvolle\n"
	.string "Lektion erteilt.\p"
	.string "Nun, geh weiter. Die linke Tür führt in\n"
	.string "den RAUM der STÄRKE.\p"
	.string "Die rechte Tür öffnet den\n"
	.string "K.O.-TREFFER-RAUM.\p"
	.string "In beiden warten äußerst talentierte\n"
	.string "TRAINER.$"
	.endif
	.endif

PetalburgCity_Gym_Text_AlexiaPostBadge:
	.ifdef ENGLISH
	.string "Hi! Have you tried using SURF?$"
	.else
	.ifdef GERMAN
	.string "Hallo! Hast du mal SURFER ausprobiert?$"
	.endif
	.endif

PetalburgCity_Gym_Text_JodyIntro:
	.ifdef ENGLISH
	.string "Our GYM LEADER told us to go all out\n"
	.string "and beat you.\p"
	.string "Even if you happen to be the\n"
	.string "LEADER's kid!$"
	.else
	.ifdef GERMAN
	.string "Unser ARENALEITER hat uns angewiesen,\n"
	.string "alles zu geben und dich zu besiegen.\p"
	.string "Auch wenn du das Kind des LEITERs bist!$"
	.endif
	.endif

PetalburgCity_Gym_Text_JodyDefeat:
	.ifdef ENGLISH
	.string "But… I went all out!$"
	.else
	.ifdef GERMAN
	.string "Aber… Das war wohl nichts!$"
	.endif
	.endif

PetalburgCity_Gym_Text_JodyPostBattle:
	.ifdef ENGLISH
	.string "The way you use your POKéMON…\n"
	.string "It's like your father's style.\p"
	.string "Go on through! The GYM LEADER, your\n"
	.string "father, is waiting!$"
	.else
	.ifdef GERMAN
	.string "Wie du deine POKéMON einsetzt…\n"
	.string "Du bist wie dein Vater.\p"
	.string "Geh weiter! Der ARENALEITER, dein\n"
	.string "Vater, erwartet dich bereits!$"
	.endif
	.endif

PetalburgCity_Gym_Text_JodyPostBadge:
	.ifdef ENGLISH
	.string "Sure, it's fine to make your POKéMON\n"
	.string "stronger.\p"
	.string "But what decides the winner?\p"
	.string "Why, it's the feelings TRAINERS have\n"
	.string "for their POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Sicher, es ist immer von Vorteil, die\n"
	.string "POKéMON stärker werden zu lassen.\p"
	.string "Aber was macht einen Gewinner aus?\p"
	.string "Nun, das sind die Gefühle, die ein\n"
	.string "TRAINER seinen POKéMON entgegen-\l"
	.string "bringt.$"
	.endif
	.endif

PetalburgCity_Gym_Text_DoorAppearsLocked:
	.ifdef ENGLISH
	.string "This door appears to be locked\n"
	.string "right now…$"
	.else
	.ifdef GERMAN
	.string "Die Tür ist noch verschlossen…$"
	.endif
	.endif

PetalburgCity_Gym_Text_EnterSpeedRoom:
	.ifdef ENGLISH
	.string "“SPEED ROOM,” the sign says.\p"
	.string "Do you want to go through?$"
	.else
	.ifdef GERMAN
	.string "“INITIATIVE-RAUM” steht auf\n"
	.string "dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"
	.endif
	.endif

@ Unused
PetalburgCity_Gym_Text_DoorAppearsLocked2:
	.ifdef ENGLISH
	.string "This door appears to be locked\n"
	.string "right now…$"
	.else
	.ifdef GERMAN
	.string "This door appears to be locked\n"
	.string "right now…$"
	.endif
	.endif

PetalburgCity_Gym_Text_EnterAccuracyRoom:
	.ifdef ENGLISH
	.string "“ACCURACY ROOM,” the sign says.\p"
	.string "Do you want to go through?$"
	.else
	.ifdef GERMAN
	.string "“RAUM der GENAUIGKEIT” steht\n"
	.string "auf dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"
	.endif
	.endif

PetalburgCity_Gym_Text_EnterConfusionRoom:
	.ifdef ENGLISH
	.string "“CONFUSION ROOM,” the sign says.\p"
	.string "Do you want to go through?$"
	.else
	.ifdef GERMAN
	.string "“RAUM der VERWIRRUNG”\n"
	.string "steht auf dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"
	.endif
	.endif

PetalburgCity_Gym_Text_EnterDefenseRoom:
	.ifdef ENGLISH
	.string "“DEFENSE ROOM,” the sign says.\p"
	.string "Do you want to go through?$"
	.else
	.ifdef GERMAN
	.string "“RAUM der VERTEIDIGUNG” steht\n"
	.string "auf dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"
	.endif
	.endif

PetalburgCity_Gym_Text_EnterRecoveryRoom:
	.ifdef ENGLISH
	.string "“RECOVERY ROOM,” the sign says.\p"
	.string "Do you want to go through?$"
	.else
	.ifdef GERMAN
	.string "“RAUM der ERHOLUNG” steht auf\n"
	.string "dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"
	.endif
	.endif

PetalburgCity_Gym_Text_EnterStrengthRoom:
	.ifdef ENGLISH
	.string "“STRENGTH ROOM,” the sign says.\p"
	.string "Do you want to go through?$"
	.else
	.ifdef GERMAN
	.string "“RAUM der STÄRKE” steht auf\n"
	.string "dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"
	.endif
	.endif

PetalburgCity_Gym_Text_EnterOHKORoom:
	.ifdef ENGLISH
	.string "“ONE-HIT KO ROOM,” the sign says.\p"
	.string "Do you want to go through?$"
	.else
	.ifdef GERMAN
	.string "“K.O.-TREFFER-RAUM”\n"
	.string "steht auf dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"
	.endif
	.endif

PetalburgCity_Gym_Text_EnterGymLeadersRoom:
	.ifdef ENGLISH
	.string "“GYM LEADER'S ROOM\p"
	.string "“See for yourself what POKéMON await\n"
	.string "you!” the sign says.\p"
	.string "Do you want to go through?$"
	.else
	.ifdef GERMAN
	.string "“ARENALEITER”\p"
	.string "“Sieh selbst, welche POKéMON dich\n"
	.string "erwarten!” steht auf dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"
	.endif
	.endif

PetalburgCity_Gym_Text_GymStatue:
	.ifdef ENGLISH
	.string "PETALBURG CITY POKéMON GYM$"
	.else
	.ifdef GERMAN
	.string "POKéMON ARENA von BLÜTENBURG CITY$"
	.endif
	.endif

PetalburgCity_Gym_Text_GymStatueCertified:
	.ifdef ENGLISH
	.string "PETALBURG CITY POKéMON GYM\p"
	.string "NORMAN'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
	.else
	.ifdef GERMAN
	.string "POKéMON ARENA von BLÜTENBURG CITY\p"
	.string "NORMANs ANERKANNTE TRAINER:\n"
	.string "{PLAYER}$"
	.endif
	.endif

PetalburgCity_Gym_Text_NormanPreRematch:
	.ifdef ENGLISH
	.string "DAD: {PLAYER}…\n"
	.string "I had a feeling that you would come.\p"
	.string "I would never refuse to accept\n"
	.string "a challenge from you.\p"
	.string "You do understand, don't you?\p"
	.string "Inside a GYM, it doesn't matter that\n"
	.string "we are a parent and child.\p"
	.string "…No, because we are parent and child,\n"
	.string "we owe it to each other to do the best\l"
	.string "we can. Isn't that right, {PLAYER}?$"
	.else
	.ifdef GERMAN
	.string "VATER: {PLAYER}…\n"
	.string "Ich wusste, du würdest kommen.\p"
	.string "Niemals würde ich eine Herausforderung\n"
	.string "von dir ablehnen!\p"
	.string "Du verstehst, was ich meine?\p"
	.string "In einer ARENA ist es ohne Bedeutung,\n"
	.string "dass du mein Kind bist.\p"
	.string "Im Gegenteil, da wir Vater und Kind sind,\n"
	.string "müssen wir beide unser Bestes geben.\l"
	.string "Meinst du nicht auch, {PLAYER}?$"
	.endif
	.endif

PetalburgCity_Gym_Text_NormanRematchDefeat:
	.ifdef ENGLISH
	.string "Uh… Haha…\n"
	.string "Maybe that was going too hard…$"
	.else
	.ifdef GERMAN
	.string "Äh… Haha…\n"
	.string "Du bist ein harter Brocken…$"
	.endif
	.endif

PetalburgCity_Gym_Text_NormanPostRematch:
	.ifdef ENGLISH
	.string "DAD: {PLAYER}…\n"
	.string "What is your dream?\p"
	.string "My dream…\n"
	.string "Hahaha…\l"
	.string "It has already come true, actually.$"
	.else
	.ifdef GERMAN
	.string "VATER: {PLAYER}…\n"
	.string "Was ist dein Traum?\p"
	.string "Mein Traum…\n"
	.string "Hahaha…\l"
	.string "Er wurde bereits Wirklichkeit.$"
	.endif
	.endif

PetalburgCity_Gym_Text_NormanRematchNeedTwoMons:
	.ifdef ENGLISH
	.string "DAD: {PLAYER}…\n"
	.string "I had a feeling that you would come.\p"
	.string "I would never refuse to accept\n"
	.string "a challenge from you.\p"
	.string "You do understand, don't you?\p"
	.string "Inside a GYM, it doesn't matter that\n"
	.string "we are a parent and child.\p"
	.string "Hm? Wait a second, {PLAYER}.\p"
	.string "Do you only have one POKéMON that is\n"
	.string "capable of battle?\p"
	.string "Sorry, but you'll have to come back\n"
	.string "with at least two POKéMON.$"
	.else
	.ifdef GERMAN
	.string "VATER: {PLAYER}…\n"
	.string "Ich wusste, du würdest kommen.\p"
	.string "Niemals würde ich eine Herausforderung\n"
	.string "von dir ablehnen!\p"
	.string "Du verstehst, was ich meine?\p"
	.string "In einer ARENA ist es ohne Bedeutung,\n"
	.string "dass du mein Kind bist.\p"
	.string "Hm? Warte mal, {PLAYER}.\p"
	.string "Du hast nur ein POKéMON, das kämpfen\n"
	.string "kann?\p"
	.string "Tut mir Leid, aber du brauchst\n"
	.string "mindestens zwei POKéMON.$"
	.endif
	.endif

