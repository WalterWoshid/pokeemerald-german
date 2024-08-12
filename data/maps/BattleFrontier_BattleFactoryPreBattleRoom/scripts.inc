.set LOCALID_ATTENDANT, 1

BattleFrontier_BattleFactoryPreBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryPreBattleRoom_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryPreBattleRoom_OnWarp
	.byte 0

BattleFrontier_BattleFactoryPreBattleRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SetUpObjects
	.2byte 0

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	goto_if_ne VAR_0x8006, 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_ATTENDANT, 8, 7
	turnobject LOCALID_ATTENDANT, DIR_SOUTH
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryPreBattleRoom_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterRoom::
	goto_if_eq VAR_0x8006, 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantEnterRoom
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerEnterRoom
	waitmovement 0
	goto_if_eq VAR_0x8006, 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ResumeChallenge
	factory_generaterentalmons
	factory_generateopponentmons
	factory_getopponentmontype
	setorcopyvar VAR_0x8005, VAR_RESULT
	factory_getopponentstyle
	setorcopyvar VAR_0x8006, VAR_RESULT
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	factory_setswapped
	factory_rentmons
	waitstate
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_EventScript_GetLvlMode
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLv50
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLvOpen
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM, 6, 11
	waitstate
	end

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReturnToRoomFromBattle::
	factory_setopponentmons
	factory_resethelditems
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	frontier_getbrainstatus
	goto_if_eq VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForRegularOpponent
	playse SE_POKENAV_CALL
	waitse
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_WaitFewMoments, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantMoveToReceiveCall
	waitmovement 0
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_UnderstoodSirWillDo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantReturnToPlayer
	waitmovement 0
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_MessageFromHeadComeRightNow, MSGBOX_DEFAULT
	closemessage
	delay 16
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
	end

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent::
	frontier_getbrainstatus
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForRegularOpponent::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor3rdOpponent
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor4thOpponent
	call_if_eq VAR_RESULT, 4, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor5thOpponent
	call_if_eq VAR_RESULT, 5, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor6thOpponent
	call_if_eq VAR_RESULT, 6, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor7thOpponent
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponentNoRecord
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
	case 3, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponentNoRecord::
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RecordLatestBattle
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
	case YES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_PauseChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
	case 0, BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon::
	factory_generateopponentmons
	factory_getopponentmontype
	setorcopyvar VAR_0x8005, VAR_RESULT
	factory_getopponentstyle
	setorcopyvar VAR_0x8006, VAR_RESULT
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
	case YES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons::
	fadescreen FADE_TO_BLACK
	factory_swapmons
	waitstate
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom  @ Did player keep current pokemon
	factory_setswapped
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor4thOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor4thOpponent
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor5thOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor5thOpponent
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor6thOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor6thOpponent
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor7thOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor7thOpponent
	waitmessage
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_PauseChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	factory_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ResumeChallenge::
	special SavePlayerParty
	factory_setparties 0
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	special CalculatePlayerPartyCount
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_InvestigatedUpcomingOpponent, MSGBOX_DEFAULT
	call_if_eq VAR_0x8005, TYPE_NORMAL, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesNormal
	call_if_eq VAR_0x8005, TYPE_FIGHTING, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFighting
	call_if_eq VAR_0x8005, TYPE_FLYING, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFlying
	call_if_eq VAR_0x8005, TYPE_POISON, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPoison
	call_if_eq VAR_0x8005, TYPE_GROUND, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGround
	call_if_eq VAR_0x8005, TYPE_ROCK, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesRock
	call_if_eq VAR_0x8005, TYPE_BUG, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesBug
	call_if_eq VAR_0x8005, TYPE_GHOST, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGhost
	call_if_eq VAR_0x8005, TYPE_STEEL, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesSteel
	call_if_eq VAR_0x8005, TYPE_FIRE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFire
	call_if_eq VAR_0x8005, TYPE_WATER, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesWater
	call_if_eq VAR_0x8005, TYPE_GRASS, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGrass
	call_if_eq VAR_0x8005, TYPE_ELECTRIC, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesElectric
	call_if_eq VAR_0x8005, TYPE_PSYCHIC, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPsychic
	call_if_eq VAR_0x8005, TYPE_ICE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesIce
	call_if_eq VAR_0x8005, TYPE_DRAGON, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDragon
	call_if_eq VAR_0x8005, TYPE_DARK, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDark
	call_if_eq VAR_0x8005, NUMBER_OF_MON_TYPES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentHasNoMostCommonType
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesNormal::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInNormalType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFighting::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFightingType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFlying::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFlyingType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPoison::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPoisonType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGround::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGroundType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesRock::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInRockType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesBug::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInBugType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGhost::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGhostType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesSteel::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInSteelType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFire::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFireType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesWater::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInWaterType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGrass::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGrassType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesElectric::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInElectricType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPsychic::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPsychicType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesIce::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInIceType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDragon::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDragonType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDark::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDarkType, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentHasNoMostCommonType::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerHasNoClearFavorite, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle::
	call_if_eq VAR_0x8006, FACTORY_STYLE_NONE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleUnrestrained
	call_if_eq VAR_0x8006, FACTORY_STYLE_PREPARATION, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleTotalPreparation
	call_if_eq VAR_0x8006, FACTORY_STYLE_SLOW_STEADY, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleSlowAndSteady
	call_if_eq VAR_0x8006, FACTORY_STYLE_ENDURANCE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleEndurance
	call_if_eq VAR_0x8006, FACTORY_STYLE_HIGH_RISK, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleHighRisk
	call_if_eq VAR_0x8006, FACTORY_STYLE_WEAKENING, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleWeakenFoe
	call_if_eq VAR_0x8006, FACTORY_STYLE_UNPREDICTABLE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleImpossibleToPredict
	call_if_eq VAR_0x8006, FACTORY_STYLE_WEATHER, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleDependsOnFlow
	call_if_eq VAR_0x8006, FACTORY_NUM_STYLES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleFlexible
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleUnrestrained::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleUnrestrained, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleTotalPreparation::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleTotalPreparation, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleSlowAndSteady::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleSlowAndSteady, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleEndurance::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleEndurance, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleHighRisk::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleHighRisk, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleWeakenFoe::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleWeakenFoe, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleImpossibleToPredict::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleImpossibleToPredict, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleDependsOnFlow::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleDependsOnFlow, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleFlexible::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleFlexible, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_PreparedToFaceHead
	waitmessage
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHeadNoRecord
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
	case 3, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHeadNoRecord::
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_CantTellAnythingAboutHead, MSGBOX_DEFAULT
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
	case YES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLv50::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLv50
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLv50
	return

BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLvOpen::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLvOpen
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLvOpen
	return

BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerEnterRoom:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLv50:
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLvOpen:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantEnterRoom:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLv50:
	walk_left
	walk_left
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLvOpen:
	walk_right
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantMoveToReceiveCall:
	walk_left
	walk_left
	walk_left
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantReturnToPlayer:
	walk_right
	walk_right
	walk_right
	face_down
	step_end

BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection:
	.ifdef ENGLISH
	.string "First, we will hold your POKéMON for\n"
	.string "safekeeping.\p"
	.string "You may then choose from our\n"
	.string "selection of POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Wir nehmen deine POKéMON in unsere\n"
	.string "Obhut.\p"
	.string "Dann kannst du dir aus einer Anzahl von\n"
	.string "POKéMON ein paar ausleihen.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons:
	.ifdef ENGLISH
	.string "Thank you for competing!\n"
	.string "Let us restore your POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Vielen Dank für deine Teilnahme! Deine\n"
	.string "POKéMON sind gleich wieder topfit.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent:
	.ifdef ENGLISH
	.string "The 2nd match is next!\n"
	.string "Are you ready?$"
	.else
	.ifdef GERMAN
	.string "Der zweite Kampf steht bevor!\n"
	.string "Bist du bereit?$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent:
	.ifdef ENGLISH
	.string "The 3rd match is next!\n"
	.string "Are you ready?$"
	.else
	.ifdef GERMAN
	.string "Der dritte Kampf steht bevor!\n"
	.string "Bist du bereit?$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor4thOpponent:
	.ifdef ENGLISH
	.string "The 4th match is next!\n"
	.string "Are you ready?$"
	.else
	.ifdef GERMAN
	.string "Der vierte Kampf steht bevor!\n"
	.string "Bist du bereit?$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor5thOpponent:
	.ifdef ENGLISH
	.string "The 5th match is next!\n"
	.string "Are you ready?$"
	.else
	.ifdef GERMAN
	.string "Der fünfte Kampf steht bevor!\n"
	.string "Bist du bereit?$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor6thOpponent:
	.ifdef ENGLISH
	.string "The 6th match is next!\n"
	.string "Are you ready?$"
	.else
	.ifdef GERMAN
	.string "Der sechste Kampf steht bevor!\n"
	.string "Bist du bereit?$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor7thOpponent:
	.ifdef ENGLISH
	.string "Finally, the 7th match is next!\n"
	.string "Are you ready?$"
	.else
	.ifdef GERMAN
	.string "Der siebte Kampf steht endlich bevor!\n"
	.string "Bist du bereit?$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame:
	.ifdef ENGLISH
	.string "Would you like to save and quit\n"
	.string "the game?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du das Spiel speichern und\n"
	.string "beenden?$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge:
	.ifdef ENGLISH
	.string "Would you like to retire from your\n"
	.string "Battle Swap challenge?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du dich aus dem Wechselkampf\n"
	.string "zurückziehen?$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_InvestigatedUpcomingOpponent:
	.ifdef ENGLISH
	.string "I've conducted a little investigation\n"
	.string "about your upcoming opponent.$"
	.else
	.ifdef GERMAN
	.string "Ich habe mich über deinen nächsten\n"
	.string "Gegner erkundigt.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInNormalType:
	.ifdef ENGLISH
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the NORMAL type.$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER ist ein Fachmann für\n"
	.string "POKéMON vom Typ NORMAL.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFireType:
	.ifdef ENGLISH
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the FIRE type.$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER ist ein Fachmann für\n"
	.string "POKéMON vom Typ FEUER.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInWaterType:
	.ifdef ENGLISH
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the WATER type.$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER ist ein Fachmann für\n"
	.string "POKéMON vom Typ WASSER.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInElectricType:
	.ifdef ENGLISH
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the ELECTRIC type.$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER ist ein Fachmann für\n"
	.string "POKéMON vom Typ ELEKTRO.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGrassType:
	.ifdef ENGLISH
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the GRASS type.$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER ist ein Fachmann für\n"
	.string "POKéMON vom Typ PFLANZE.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInIceType:
	.ifdef ENGLISH
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the ICE type.$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER ist ein Fachmann für\n"
	.string "POKéMON vom Typ EIS.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFightingType:
	.ifdef ENGLISH
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the FIGHTING type.$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER ist ein Fachmann für\n"
	.string "POKéMON vom Typ KAMPF.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPoisonType:
	.ifdef ENGLISH
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the POISON type.$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER ist ein Fachmann für\n"
	.string "POKéMON vom Typ GIFT.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGroundType:
	.ifdef ENGLISH
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the GROUND type.$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER ist ein Fachmann für\n"
	.string "POKéMON vom Typ BODEN.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFlyingType:
	.ifdef ENGLISH
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the FLYING type.$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER ist ein Fachmann für\n"
	.string "POKéMON vom Typ FLUG.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPsychicType:
	.ifdef ENGLISH
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the PSYCHIC type.$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER ist ein Fachmann für\n"
	.string "POKéMON vom Typ PSYCHO.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInBugType:
	.ifdef ENGLISH
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the BUG type.$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER ist ein Fachmann für\n"
	.string "POKéMON vom Typ KÄFER.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInRockType:
	.ifdef ENGLISH
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the ROCK type.$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER ist ein Fachmann für\n"
	.string "POKéMON vom Typ GESTEIN.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGhostType:
	.ifdef ENGLISH
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the GHOST type.$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER ist ein Fachmann für\n"
	.string "POKéMON vom Typ GEIST.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDragonType:
	.ifdef ENGLISH
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the DRAGON type.$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER ist ein Fachmann für\n"
	.string "POKéMON vom Typ DRACHE.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDarkType:
	.ifdef ENGLISH
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the DARK type.$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER ist ein Fachmann für\n"
	.string "POKéMON vom Typ UNLICHT.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInSteelType:
	.ifdef ENGLISH
	.string "The TRAINER is apparently skilled\n"
	.string "in the handling of the STEEL type.$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER ist ein Fachmann für\n"
	.string "POKéMON vom Typ STAHL.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerHasNoClearFavorite:
	.ifdef ENGLISH
	.string "The TRAINER appears to have no clear\n"
	.string "favorites when it comes to type.$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER scheint keine Vorlieben\n"
	.string "für einen bestimmten Typ zu haben.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleSlowAndSteady:
	.ifdef ENGLISH
	.string "The favorite battle style appears to\n"
	.string "be slow and steady.$"
	.else
	.ifdef GERMAN
	.string "Sein favorisierter Kampfstil:\n"
	.string "langsam, aber mit Beständigkeit.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleEndurance:
	.ifdef ENGLISH
	.string "The favorite battle style appears to\n"
	.string "be one of endurance.$"
	.else
	.ifdef GERMAN
	.string "Sein favorisierter Kampfstil:\n"
	.string "ausdauernd.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleHighRisk:
	.ifdef ENGLISH
	.string "The favorite battle style appears to\n"
	.string "be high risk, high return.$"
	.else
	.ifdef GERMAN
	.string "Sein favorisierter Kampfstil:\n"
	.string "hohes Risiko und starke Gegenattacken.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleDependsOnFlow:
	.ifdef ENGLISH
	.string "The favorite battle style appears to\n"
	.string "depend on the battle's flow.$"
	.else
	.ifdef GERMAN
	.string "Sein favorisierter Kampfstil:\n"
	.string "hängt vom Kampfverlauf ab.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleTotalPreparation:
	.ifdef ENGLISH
	.string "The favorite battle style appears to\n"
	.string "be one based on total preparation.$"
	.else
	.ifdef GERMAN
	.string "Sein favorisierter Kampfstil: \n"
	.string "gründliche Vorbereitung eines Kampfes.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleWeakenFoe:
	.ifdef ENGLISH
	.string "The favorite battle style appears\n"
	.string "to be weakening the foe to start.$"
	.else
	.ifdef GERMAN
	.string "Sein favorisierter Kampfstil: \n"
	.string "den Gegner gleich zu Anfang schwächen.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleFlexible:
	.ifdef ENGLISH
	.string "The favorite battle style appears to\n"
	.string "be flexibly adaptable to the situation.$"
	.else
	.ifdef GERMAN
	.string "Sein favorisierter Kampfstil: \n"
	.string "flexibel auf jede Situation reagieren.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleImpossibleToPredict:
	.ifdef ENGLISH
	.string "The favorite battle style appears to\n"
	.string "be impossible to predict.$"
	.else
	.ifdef GERMAN
	.string "Sein favorisierter Kampfstil: \n"
	.string "ist nicht vorhersehbar.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleUnrestrained:
	.ifdef ENGLISH
	.string "The favorite battle style appears to\n"
	.string "be free-spirited and unrestrained.$"
	.else
	.ifdef GERMAN
	.string "Sein favorisierter Kampfstil: \n"
	.string "frei und bedenkenlos.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon:
	.ifdef ENGLISH
	.string "Before starting the battle, would you\n"
	.string "like to swap a POKéMON?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du vor dem Kampf ein POKéMON\n"
	.string "tauschen?$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete:
	.ifdef ENGLISH
	.string "Thank you!\n"
	.string "Your POKéMON swap is complete.$"
	.else
	.ifdef GERMAN
	.string "Vielen Dank! Der POKéMON-Tausch\n"
	.string "wurde durchgeführt.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay:
	.ifdef ENGLISH
	.string "Right this way, please!$"
	.else
	.ifdef GERMAN
	.string "Bitte hier entlang!$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait:
	.ifdef ENGLISH
	.string "I am saving your data.\n"
	.string "Please wait.$"
	.else
	.ifdef GERMAN
	.string "Ich speichere deine Daten.\n"
	.string "Einen Moment bitte.$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_RecordLatestBattle:
	.ifdef ENGLISH
	.string "Would you like to record your latest\n"
	.string "battle on your FRONTIER PASS?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du deinen letzten Kampf\n"
	.string "in deinen KAMPFZONENPASS eintragen?$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_WaitFewMoments:
	.ifdef ENGLISH
	.string "Excuse me! Excuse me, please!\n"
	.string "May I get you to wait a few moments?$"
	.else
	.ifdef GERMAN
	.string "Entschuldigung! Hallo, entschuldige!\n"
	.string "Würdest du bitte einen Moment warten?$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_UnderstoodSirWillDo:
	.ifdef ENGLISH
	.string "…Uh-huh? What?! …Whoa!\n"
	.string "Understood, sir! Will do!$"
	.else
	.ifdef GERMAN
	.string "…Oh-oh. Was?!?… Hui!\n"
	.string "Ja, verstanden, Sir! Sofort!$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_MessageFromHeadComeRightNow:
	.ifdef ENGLISH
	.string "Oh, my…\n"
	.string "Sorry to keep you waiting!\p"
	.string "I have a message from this facility's\n"
	.string "boss, the FACTORY HEAD.\p"
	.string "He says, “We're going to do it!\n"
	.string "Come here right now!”$"
	.else
	.ifdef GERMAN
	.string "Oh je…\n"
	.string "Tut mir Leid, dass du warten musstest.\p"
	.string "Ich habe eine Nachricht vom\n"
	.string "FABRIKLEITER.\p"
	.string "Er sagt: “Wir werden es in Angriff\n"
	.string "nehmen! Komm bitte her!”$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_PreparedToFaceHead:
	.ifdef ENGLISH
	.string "The FACTORY HEAD is demanding you.\n"
	.string "Are you prepared to face him?$"
	.else
	.ifdef GERMAN
	.string "Der FABRIKLEITER erwartet dich.\n"
	.string "Bist du bereit?$"
	.endif
	.endif

BattleFrontier_BattleFactoryPreBattleRoom_Text_CantTellAnythingAboutHead:
	.ifdef ENGLISH
	.string "I'm terribly sorry, but I can't tell you\n"
	.string "anything about the FACTORY HEAD.$"
	.else
	.ifdef GERMAN
	.string "Es tut mir Leid, aber ich kann dir über\n"
	.string "den FABRIKLEITER nichts sagen.$"
	.endif
	.endif
