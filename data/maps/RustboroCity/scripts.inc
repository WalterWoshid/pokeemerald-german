.set LOCALID_LITTLE_BOY, 7
.set LOCALID_LITTLE_GIRL, 8
.set LOCALID_DEVON_EMPLOYEE, 9
.set LOCALID_GRUNT, 10
.set LOCALID_RIVAL, 14
.set LOCALID_SCIENTIST, 15

RustboroCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_OnFrame
	.byte 0

RustboroCity_OnTransition:
	setflag FLAG_VISITED_RUSTBORO_CITY
	call Common_EventScript_SetupRivalGfxId
	call_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_HideMapNamePopup
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_PositionScientistForExit
	end

RustboroCity_EventScript_PositionScientistForExit::
	goto_if_eq VAR_TEMP_0, 11, RustboroCity_EventScript_PositionScientistLeftExit
	setobjectxyperm LOCALID_SCIENTIST, 12, 15
	end

RustboroCity_EventScript_PositionScientistLeftExit::
	setobjectxyperm LOCALID_SCIENTIST, 11, 15
	end

RustboroCity_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

RustboroCity_OnFrame:
	map_script_2 VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_ScientistAddMatchCall
	.2byte 0

RustboroCity_EventScript_ScientistAddMatchCall::
	lockall
	setvar VAR_ROUTE104_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_PlayerWalkDown
	waitmovement 0
	playse SE_EXIT
	delay 10
	addobject LOCALID_SCIENTIST
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistApproachPlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistWalkInPlaceDown
	waitmovement 0
	msgbox RustboroCity_Text_DevelopedNewPokenavFeature, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HAS_MATCH_CALL
	applymovement LOCALID_SCIENTIST, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 20
	applymovement LOCALID_SCIENTIST, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox RustboroCity_Text_AddedMatchCallPleaseCallMrStone, MSGBOX_DEFAULT
	closemessage
	delay 20
	goto RustboroCity_EventScript_MatchCallTutorial

RustboroCity_EventScript_PleaseSelectPokenav::
	msgbox RustboroCity_Text_PleaseSelectPokenav, MSGBOX_DEFAULT
	closemessage
	delay 10
	goto RustboroCity_EventScript_MatchCallTutorial

RustboroCity_EventScript_MatchCallTutorial::
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	special ScriptMenu_CreateStartMenuForPokenavTutorial
	waitstate
	switch VAR_RESULT
	case 0, RustboroCity_EventScript_PleaseSelectPokenav
	case 1, RustboroCity_EventScript_PleaseSelectPokenav
	case 2, RustboroCity_EventScript_PleaseSelectPokenav
	case 4, RustboroCity_EventScript_PleaseSelectPokenav
	case 5, RustboroCity_EventScript_PleaseSelectPokenav
	case 6, RustboroCity_EventScript_PleaseSelectPokenav
	case 7, RustboroCity_EventScript_PleaseSelectPokenav
	case MULTI_B_PRESSED, RustboroCity_EventScript_PleaseSelectPokenav
	special OpenPokenavForTutorial
	waitstate
	delay 20
	msgbox RustboroCity_Text_IdBetterGetBackToWork, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_SCIENTIST
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
	setvar VAR_RUSTBORO_CITY_STATE, 7
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

RustboroCity_Movement_ScientistWalkInPlaceDown:
	walk_in_place_down
	step_end

RustboroCity_Movement_PlayerWalkDown:
	walk_down
	step_end

RustboroCity_Movement_ScientistApproachPlayer:
	walk_down
	delay_16
	step_end

@ Unused
RustboroCity_Movement_ScientistWalkAroundPlayer:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_up
	delay_16
	step_end

RustboroCity_Movement_ScientistLeave:
	walk_up
	step_end

RustboroCity_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_FatManSawGrunt::
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_DevonEmployee2::
	lock
	faceplayer
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Woman::
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
	end

RustboroCity_EventScript_Man1::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Man1HaveBadge::
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Boy2::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_Boy2BrineyLeftTunnel
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Boy2BrineyLeftTunnel::
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Twin::
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
	end

RustboroCity_EventScript_NinjaBoy::
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
	end

RustboroCity_EventScript_TunnelSign::
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
	end

RustboroCity_EventScript_DevonCorpSign::
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_GymSign::
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
	end

@ Unused
RustboroCity_EventScript_DevonCorpBranchOfficeSign::
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_CitySign::
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
	end

RustboroCity_EventScript_TrainersSchoolSign::
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_CuttersHouseSign::
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
	end

RustboroCity_EventScript_LittleBoy::
	lock
	faceplayer
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
	applymovement LOCALID_LITTLE_BOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
	applymovement LOCALID_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_EventScript_Man2::
	lock
	faceplayer
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_StolenGoodsTrigger0::
	lockall
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 0
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger1::
	lockall
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 1
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger2::
	lockall
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 2
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger3::
	lockall
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 3
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger4::
	lockall
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 4
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsScene::
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	addobject LOCALID_GRUNT
	addobject LOCALID_DEVON_EMPLOYEE
	applymovement LOCALID_GRUNT, RustboroCity_Movement_GruntEscape
	waitmovement 0
	removeobject LOCALID_GRUNT
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
	waitmovement 0
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_DEVON_EMPLOYEE
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 30, 10
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setflag FLAG_DEVON_GOODS_STOLEN
	setvar VAR_RUSTBORO_CITY_STATE, 2
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
	setvar VAR_ROUTE116_STATE, 1
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	releaseall
	end

@ Unused
RustboroCity_EventScript_ShadyCharacterTookOff::
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
	return

@ Unused
RustboroCity_EventScript_YouGotItThankYou::
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
	return

@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
RustboroCity_EventScript_EmployeeApproachUp::
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
	waitmovement 0
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachLeft::
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
	waitmovement 0
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachRight::
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
	waitmovement 0
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachDown::
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
	waitmovement 0
	return

@ Unused, similar movement to the above scripts
RustboroCity_EventScript_EmployeeApproachPlayerFar::
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

@ Unused
RustboroCity_Movement_GruntEscapeExtended:
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RustboroCity_Movement_GruntEscape:
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RustboroCity_Movement_EmployeeChaseGrunt1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

RustboroCity_Movement_EmployeeChaseGrunt2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachUp:
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachLeft:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachRight:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachDown:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachPlayerFar:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

RustboroCity_EventScript_DevonEmployee1::
	lock
	faceplayer
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_ReturnGoodsSpokeToEmployee::
	waitse
	setvar VAR_TEMP_1, 4
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger0::
	lockall
	setvar VAR_TEMP_1, 0
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger1::
	lockall
	setvar VAR_TEMP_1, 1
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger2::
	lockall
	setvar VAR_TEMP_1, 2
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger3::
	lockall
	setvar VAR_TEMP_1, 3
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_EmployeeAskToGetGoods::
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp1
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft1
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown1
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown1
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
	setvar VAR_RUSTBORO_CITY_STATE, 3
	copyobjectxytoperm LOCALID_DEVON_EMPLOYEE
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
	releaseall
	end

@ The below movement scripts are either partially or fully duplicated by the movement scripts when the player returns the goods
RustboroCity_EventScript_EmployeeFacePlayerUp1::
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerLeft1::
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerDown1::
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeApproachPlayerDown1::
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

RustboroCity_Movement_EmployeeApproachPlayerDown:
	walk_down
	step_end

RustboroCity_EventScript_ReturnGoodsTrigger0::
	lockall
	setvar VAR_TEMP_1, 0
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger1::
	lockall
	setvar VAR_TEMP_1, 1
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger2::
	lockall
	setvar VAR_TEMP_1, 2
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger3::
	lockall
	setvar VAR_TEMP_1, 3
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoods::
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp2
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft2
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown2
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown2
	call_if_eq VAR_TEMP_1, 4, RustboroCity_EventScript_EmployeeFacePlayerRight
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	call_if_eq VAR_RESULT, FALSE, RustboroCity_EventScript_BagFull
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RETURNED_DEVON_GOODS
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setvar VAR_RUSTBORO_CITY_STATE, 5
	delay 30
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
	waitstate
	releaseall
	end

RustboroCity_EventScript_BagFull::
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	return

RustboroCity_EventScript_EmployeeFacePlayerUp2::
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerLeft2::
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerDown2::
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeApproachPlayerDown2::
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerRight::
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	return

RustboroCity_EventScript_Rival::
	lockall
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_PlayRivalMusic::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_PlayMayMusic
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_PlayBrendanMusic
	return

RustboroCity_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

RustboroCity_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

RustboroCity_EventScript_RivalTrigger0::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger1::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger2::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger3::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger4::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger5::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger6::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger7::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalEncounter::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_MayEncounter
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_BrendanEncounter
	end

RustboroCity_EventScript_MayEncounter::
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setvar VAR_0x8008, 0
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_MayAskToBattle::
	setvar VAR_0x8008, 1
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_BattleMay::
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleMayTreecko
	case 1, RustboroCity_EventScript_BattleMayTorchic
	case 2, RustboroCity_EventScript_BattleMayMudkip
	end

RustboroCity_EventScript_MayBrineyHint::
	msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_RestoreBgm::
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

RustboroCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BrendanEncounter::
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_BrendanAskToBattle::
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_BattleBrendan::
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleBrendanTreecko
	case 1, RustboroCity_EventScript_BattleBrendanTorchic
	case 2, RustboroCity_EventScript_BattleBrendanMudkip
	end

RustboroCity_EventScript_BrendanBrineyHint::
	msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_Movement_RivalApproachPlayer0:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer1:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer2:
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer3:
	walk_down
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer4:
	walk_down
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer5:
	walk_down
	walk_right
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer6:
	walk_down
	walk_right
	walk_right
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer7:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

RustboroCity_EventScript_Boy1::
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
	end

RustboroCity_Text_WeShortenItToDevon:
	.ifdef ENGLISH
	.string "The DEVON CORPORATION…\n"
	.string "We all just shorten it to DEVON.\p"
	.string "That company makes all sorts of\n"
	.string "convenient products.$"
	.else
	.ifdef GERMAN
	.string "Die DEVON CORPORATION…\n"
	.string "Wir nennen sie kurz DEVON.\p"
	.string "Die Firma stellt viele praktische\n"
	.string "Dinge her.$"
	.endif
	.endif

RustboroCity_Text_SneakyLookingManWentAroundCorner:
	.ifdef ENGLISH
	.string "Hm? A sneaky-looking man?\p"
	.string "Come to think of it, yes, a shady-\n"
	.string "looking guy went around the corner.$"
	.else
	.ifdef GERMAN
	.string "Hm? Ein verschlagen wirkender Mann?\p"
	.string "Wenn ich so darüber nachdenke, fällt mir\n"
	.string "ein, dass ich einen zwielichtigen Typen\l"
	.string "eben hier an der Ecke gesehen habe.$"
	.endif
	.endif

RustboroCity_Text_HaveYouChallengedGym:
	.ifdef ENGLISH
	.string "Have you taken the POKéMON GYM\n"
	.string "challenge?\p"
	.string "When you get that shiny GYM BADGE\n"
	.string "in hand, I guess TRAINERS begin to\l"
	.string "realize what is required of them.$"
	.else
	.ifdef GERMAN
	.string "Hast du schon die Herausforderung der\n"
	.string "POKéMON ARENA angenommen?\p"
	.string "Ich glaube, wenn sie den glänzenden\n"
	.string "ORDEN der ARENA in der Hand halten, wird\l"
	.string "den TRAINERn klar, was von ihnen\l"
	.string "verlangt wird.$"
	.endif
	.endif

RustboroCity_Text_HeyThatsRustborosGymBadge:
	.ifdef ENGLISH
	.string "Hey, that's RUSTBORO's GYM BADGE!\p"
	.string "Out of all the POKéMON GYM BADGES,\n"
	.string "RUSTBORO's is the coolest, I'd say.$"
	.else
	.ifdef GERMAN
	.string "Hey, das ist der ORDEN der ARENA von\n"
	.string "METAROST CITY!\p"
	.string "Von allen ARENA-ORDEN ist der von\n"
	.string "METAROST CITY der coolste, sage ich dir.$"
	.endif
	.endif

RustboroCity_Text_YoureNewAroundHere:
	.ifdef ENGLISH
	.string "Oh? Who might you be?\n"
	.string "You're a new face around these parts.\p"
	.string "Have you just transferred into the\n"
	.string "POKéMON TRAINER'S SCHOOL?$"
	.else
	.ifdef GERMAN
	.string "Oh? Wer magst du wohl sein?\n"
	.string "Ein neues Gesicht in dieser Gegend.\p"
	.string "Bist du gerade in die POKéMON TRAINER-\n"
	.string "SCHULE gekommen?$"
	.endif
	.endif

RustboroCity_Text_GymLeaderIsntEasyWithFire:
	.ifdef ENGLISH
	.string "I challenged the GYM LEADER, but…\p"
	.string "It's not going to be easy winning with\n"
	.string "my FIRE-type POKéMON…\p"
	.string "FIRE-type POKéMON don't match up\n"
	.string "well against ROCK-type POKéMON…$"
	.else
	.ifdef GERMAN
	.string "Ich habe den ARENALEITER heraus-\n"
	.string "gefordert, aber…\p"
	.string "Es ist nicht einfach, mit meinen FEUER-\n"
	.string "POKéMON zu gewinnen…\p"
	.string "FEUER-POKéMON haben keinen guten\n"
	.string "Stand gegenüber GESTEIN-POKéMON.$"
	.endif
	.endif

RustboroCity_Text_MrBrineyWalksInTheTunnel:
	.ifdef ENGLISH
	.string "The old sailor MR. BRINEY lives in\n"
	.string "a cottage by the sea.\p"
	.string "He goes for walks in the tunnel every\n"
	.string "so often.$"
	.else
	.ifdef GERMAN
	.string "Der alte Seebär MR. BRACK lebt in einer\n"
	.string "Hütte am Meer.\p"
	.string "Er geht sehr oft in dem Tunnel\n"
	.string "spazieren.$"
	.endif
	.endif

RustboroCity_Text_MrBrineyLovesPeeko:
	.ifdef ENGLISH
	.string "The old sailor MR. BRINEY lives in\n"
	.string "a cottage by the sea.\p"
	.string "He said he was going shopping in\n"
	.string "SLATEPORT for his pet, PEEKO.\p"
	.string "That old sea dog, he must really love\n"
	.string "that PEEKO.$"
	.else
	.ifdef GERMAN
	.string "Der alte Seebär MR. BRACK lebt in einer\n"
	.string "Hütte am Meer.\p"
	.string "Er sagt, er wäre in GRAPHITPORT CITY\n"
	.string "gewesen, um etwas für sein Haustier,\l"
	.string "PECKO, zu kaufen.\p"
	.string "Der alte Seebär muss sein PECKO\n"
	.string "wirklich sehr lieben.$"
	.endif
	.endif

RustboroCity_Text_WowYouHavePokemon:
	.ifdef ENGLISH
	.string "Wow, you have POKéMON with you, too.\p"
	.string "When I get bigger, I'm going to go\n"
	.string "places with POKéMON, too.$"
	.else
	.ifdef GERMAN
	.string "Wow, du hast ja auch POKéMON dabei.\p"
	.string "Wenn ich größer bin, werde ich auch\n"
	.string "immer POKéMON dabeihaben.$"
	.endif
	.endif

RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
	.ifdef ENGLISH
	.string "POKéMON TRAINER'S SCHOOL!\p"
	.string "If I go to this school, will I be able\n"
	.string "to catch rare POKéMON easily?$"
	.else
	.ifdef GERMAN
	.string "POKéMON TRAINERSCHULE!\p"
	.string "Wenn ich in diese Schule gehe, werde ich\n"
	.string "später seltene POKéMON fangen können?$"
	.endif
	.endif

RustboroCity_Text_PokemonCanChangeLookFromExp:
	.ifdef ENGLISH
	.string "If a POKéMON gains experience in\n"
	.string "battles, it can sometimes change in\l"
	.string "the way it looks.$"
	.else
	.ifdef GERMAN
	.string "Wenn ein POKéMON Erfahrungen im Kampf\n"
	.string "sammelt, kann es vorkommen, dass es\l"
	.string "irgendwann sein Aussehen verändert.$"
	.endif
	.endif

RustboroCity_Text_PokemonChangeShape:
	.ifdef ENGLISH
	.string "A POKéMON changes shape?\n"
	.string "If one did that, I would be shocked!$"
	.else
	.ifdef GERMAN
	.string "Ein POKéMON verändert sein Aussehen?!?\n"
	.string "Wenn es das tun würde, wäre ich zu Tode\l"
	.string "erschrocken!$"
	.endif
	.endif

RustboroCity_Text_TradePokemonGrowFast:
	.ifdef ENGLISH
	.string "A POKéMON you get in a trade from\n"
	.string "someone grows fast.\p"
	.string "But if you don't have certain GYM\n"
	.string "BADGES, it may not obey you…$"
	.else
	.ifdef GERMAN
	.string "Ein POKéMON, das du durch Tausch\n"
	.string "erhältst, wächst schnell.\p"
	.string "Aber wenn dir ORDEN von bestimmten\n"
	.string "ARENen fehlen, wird es dir eventuell\l"
	.string "nicht gehorchen.$"
	.endif
	.endif

RustboroCity_Text_OutOfTheWay:
	.ifdef ENGLISH
	.string "Get out!\n"
	.string "Out of the way!$"
	.else
	.ifdef GERMAN
	.string "Geh weg! Aus dem Weg!!!$"
	.endif
	.endif

RustboroCity_Text_WaitDontTakeMyGoods:
	.ifdef ENGLISH
	.string "Wait! Pleeeaaase!\p"
	.string "Don't take my GOODS!$"
	.else
	.ifdef GERMAN
	.string "Warte! Waaaaarte doch! Bitte!\p"
	.string "Du kannst doch nicht einfach meine\n"
	.string "WAREN stehlen!!!$"
	.endif
	.endif

RustboroCity_Text_HelpMeIWasRobbed:
	.ifdef ENGLISH
	.string "Oh, it's you!\p"
	.string "You're that fantastic TRAINER who\n"
	.string "helped me in PETALBURG WOODS!\p"
	.string "Help me! I was robbed by TEAM AQUA!\n"
	.string "I have to get the DEVON GOODS back!\p"
	.string "If I don't…\n"
	.string "I'm going to be in serious trouble.$"
	.else
	.ifdef GERMAN
	.string "Oh, du bist das!\p"
	.string "Du bist dieser großartige TRAINER, der\n"
	.string "mir im BLÜTENBURGWALD geholfen hat.\p"
	.string "Hilf mir! TEAM AQUA hat mich aus-\n"
	.string "geraubt! Ich muss die DEVON-WAREN\l"
	.string "zurückbekommen.\p"
	.string "Wenn ich sie nicht bekomme…\n"
	.string "dann habe ich ein riesiges Problem.$"
	.endif
	.endif

RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel:
	.ifdef ENGLISH
	.string "That shady character, I think he took\n"
	.string "off towards the tunnel over there.$"
	.else
	.ifdef GERMAN
	.string "Ich glaube, dieser zwielichtige Typ ist\n"
	.string "in Richtung Tunnel gelaufen.$"
	.endif
	.endif

RustboroCity_Text_YouGotItThankYou:
	.ifdef ENGLISH
	.string "Oh! How did it go?\n"
	.string "The DEVON GOODS?\p"
	.string "You did!\n"
	.string "You got them back!\p"
	.string "You really are a great TRAINER!\p"
	.string "I know! As my thanks, I'll give you\n"
	.string "another GREAT BALL!$"
	.else
	.ifdef GERMAN
	.string "Oh! Und? Wie sieht es aus?\n"
	.string "Die DEVON-WAREN?\p"
	.string "Du hast es geschafft!\n"
	.string "Du hast sie zurückbekommen!\p"
	.string "Du bist wirklich ein großer TRAINER!\n"
	.string "Ich weiß! Ich werde dir zum Dank einen\l"
	.string "weiteren SUPERBALL schenken!$"
	.endif
	.endif

RustboroCity_Text_YoureLoadedWithItems:
	.ifdef ENGLISH
	.string "You're loaded with items.\n"
	.string "I can't give you this GREAT BALL.$"
	.else
	.ifdef GERMAN
	.string "Du bist mit Items überfrachtet.\n"
	.string "Ich kann dir den SUPERBALL nicht geben.$"
	.endif
	.endif

RustboroCity_Text_PleaseComeWithMe:
	.ifdef ENGLISH
	.string "Excuse me, please!\n"
	.string "Please come with me!$"
	.else
	.ifdef GERMAN
	.string "Bitte entschuldige!\n"
	.string "Würdest du mir bitte folgen?$"
	.endif
	.endif

RustboroCity_Text_MayHiLetsRegister:
	.ifdef ENGLISH
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
	.string "You had a MATCH CALL feature put\n"
	.string "on your POKéNAV!\p"
	.string "Let's register each other so we can\n"
	.string "contact one another anytime!\p"
	.string "… … … … … …$"
	.else
	.ifdef GERMAN
	.string "MAIKE: Oh, hi, {PLAYER}{KUN}!\p"
	.string "Dein POKéNAV besitzt die TRAINER/RUF-\n"
	.string "Funktion!\p"
	.string "Wir tragen uns gegenseitig ein, so\n"
	.string "bleiben wir in Kontakt.\p"
	.string "… … … … …\n"
	.string "…$"
	.endif
	.endif

RustboroCity_Text_RegisteredMay:
	.ifdef ENGLISH
	.string "Registered MAY\n"
	.string "in the POKéNAV.$"
	.else
	.ifdef GERMAN
	.string "MAIKE wurde im POKéNAV-Verzeichnis\n"
	.string "eingetragen.$"
	.endif
	.endif

RustboroCity_Text_MayPassedBrineyWantToBattle:
	.ifdef ENGLISH
	.string "MAY: Oh, by the way, I passed\n"
	.string "MR. BRINEY in PETALBURG WOODS.\p"
	.string "I guess he's on his way home to his\n"
	.string "cottage by the sea.\p"
	.string "How's your POKéDEX coming along,\n"
	.string "{PLAYER}{KUN}? Mine's looking pretty decent!\p"
	.string "So…\n"
	.string "How about a little battle?$"
	.else
	.ifdef GERMAN
	.string "MAIKE: Ach, übrigens. Ich habe MR.\n"
	.string "BRACK im BLÜTENBURGWALD gesehen.\p"
	.string "Ich glaube, er ist auf dem Weg zu seiner\n"
	.string "Hütte am Meer.\p"
	.string "Wie geht es mit deinem POKéDEX voran?\n"
	.string "Meiner sieht schon ganz anständig aus.\p"
	.string "Daher…\n"
	.string "Wie wäre es mit einem kleinen Kampf?$"
	.endif
	.endif

RustboroCity_Text_MayOhHaventRaisedPokemonEnough:
	.ifdef ENGLISH
	.string "MAY: Oh, what's the matter?\p"
	.string "Haven't you caught or raised your\n"
	.string "POKéMON very much?\p"
	.string "That's not very good for a TRAINER!$"
	.else
	.ifdef GERMAN
	.string "MAIKE: Oh, was ist das?\p"
	.string "Du hast dich aber nicht um deine\n"
	.string "POKéMON gekümmert? Und auch\l"
	.string "nicht viele gefangen?\p"
	.string "Als Trainer machst du wirklich keinen\n"
	.string "guten Eindruck!$"
	.endif
	.endif

RustboroCity_Text_MayWantToBattle:
	.ifdef ENGLISH
	.string "MAY: So, what do you think?\n"
	.string "How about a little battle here?$"
	.else
	.ifdef GERMAN
	.string "MAIKE: Was hältst du von einem Kampf?$"
	.endif
	.endif

RustboroCity_Text_MayImNotGoingToLose:
	.ifdef ENGLISH
	.string "MAY: You just became a TRAINER,\n"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"
	.else
	.ifdef GERMAN
	.string "MAIKE: Du bist gerade erst TRAINER\n"
	.string "geworden, {PLAYER}{KUN}. Ich werde nicht\l"
	.string "verlieren.$"
	.endif
	.endif

RustboroCity_Text_MayDefeat:
	.ifdef ENGLISH
	.string "Yikes!\n"
	.string "You're better than I expected!$"
	.else
	.ifdef GERMAN
	.string "AchDuSchande!\n"
	.string "Du bist besser, als ich gedacht habe.$"
	.endif
	.endif

RustboroCity_Text_MayMrBrineyHint:
	.ifdef ENGLISH
	.string "MAY: Oh, by the way, MR. BRINEY, who\n"
	.string "I just passed…\p"
	.string "{PLAYER}{KUN}, you just moved here so you\n"
	.string "might not know this, but MR. BRINEY\l"
	.string "was once a revered seafarer.$"
	.else
	.ifdef GERMAN
	.string "MAIKE: Ach, übrigens. Ich habe MR.\n"
	.string "BRACK im BLÜTENBURGWALD gesehen.\p"
	.string "{PLAYER}{KUN}, du bist gerade hierher\n"
	.string "gezogen, daher kannst du das nicht\l"
	.string "wissen, aber MR. BRACK war Seefahrer.$"
	.endif
	.endif

RustboroCity_Text_BrendanHiLetsRegister:
	.ifdef ENGLISH
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
	.string "You had a MATCH CALL feature put\n"
	.string "on your POKéNAV! Cool!\p"
	.string "Let's register each other so we can\n"
	.string "get in touch anytime!\p"
	.string "… … … … … …$"
	.else
	.ifdef GERMAN
	.string "BRIX: Oh, hey, {PLAYER}!\p"
	.string "Dein POKéNAV besitzt die TRAINER/RUF-\n"
	.string "Funktion! Cool!\p"
	.string "Wir tragen uns gegenseitig ein, dann\n"
	.string "können wir jederzeit miteinander reden!\p"
	.string "… … … … …\n"
	.string "…$"
	.endif
	.endif

RustboroCity_Text_RegisteredBrendan:
	.ifdef ENGLISH
	.string "Registered BRENDAN\n"
	.string "in the POKéNAV.$"
	.else
	.ifdef GERMAN
	.string "BRIX wurde im POKéNAV-Verzeichnis\n"
	.string "eingetragen.$"
	.endif
	.endif

RustboroCity_Text_BrendanPassedBrineyWantToBattle:
	.ifdef ENGLISH
	.string "BRENDAN: By the way, {PLAYER}, I walked\n"
	.string "by MR. BRINEY in PETALBURG WOODS.\p"
	.string "I bet he was on his way home to his\n"
	.string "cottage by the sea.\p"
	.string "{PLAYER}, how's your POKéDEX?\n"
	.string "Have you filled in any pages yet?\p"
	.string "Mine rules.\p"
	.string "Want to have a battle to test how\n"
	.string "far you've progressed?$"
	.else
	.ifdef GERMAN
	.string "BRIX: Ich habe MR. BRACK im\n"
	.string "BLÜTENBURGWALD gesehen, {PLAYER}.\p"
	.string "Ich wette, er ist auf dem Weg zu seiner\n"
	.string "Hütte am Meer.\p"
	.string "{PLAYER}, wie sieht es mit\n"
	.string "deinem POKéDEX aus?\p"
	.string "Meiner ist eine Wucht.\p"
	.string "Zeig mir, wie gut du geworden bist.\n"
	.string "Ich werde dich jetzt testen!$"
	.endif
	.endif

RustboroCity_Text_BrendanNoConfidenceInPokemon:
	.ifdef ENGLISH
	.string "BRENDAN: What's the matter? Don't have\n"
	.string "any confidence in your POKéMON?$"
	.else
	.ifdef GERMAN
	.string "BRIX: Oh, hast du ein Problem? Nicht\n"
	.string "genügend Selbstbewusstsein und\l"
	.string "Vertrauen in deine POKéMON, was?$"
	.endif
	.endif

RustboroCity_Text_BrendanWantToBattle:
	.ifdef ENGLISH
	.string "BRENDAN: What's up?\n"
	.string "Want to have a battle with me?$"
	.else
	.ifdef GERMAN
	.string "BRIX: Wie geht’s? Lust auf einen Kampf?$"
	.endif
	.endif

RustboroCity_Text_BrendanIWontGoEasy:
	.ifdef ENGLISH
	.string "BRENDAN: I know you just became\n"
	.string "a TRAINER, but I won't go easy!$"
	.else
	.ifdef GERMAN
	.string "BRIX: Ich weiß, du bist gerade erst ein\n"
	.string "TRAINER geworden, aber ich werde mich\l"
	.string "nicht zurückhalten.$"
	.endif
	.endif

RustboroCity_Text_BrendanDefeat:
	.ifdef ENGLISH
	.string "Hmm…\n"
	.string "You're pretty good.$"
	.else
	.ifdef GERMAN
	.string "Hmm…\n"
	.string "Du bist sehr gut.$"
	.endif
	.endif

RustboroCity_Text_BrendanMrBrineyHint:
	.ifdef ENGLISH
	.string "BRENDAN: By the way, you know\n"
	.string "MR. BRINEY? The guy I just passed?\p"
	.string "I bet you didn't know this, since you\n"
	.string "just moved here, {PLAYER}, but\l"
	.string "MR. BRINEY was once a great sailor.$"
	.else
	.ifdef GERMAN
	.string "BRIX: Kennst du eigentlich MR. BRACK?\n"
	.string "Den Typ, den ich getroffen habe?\p"
	.string "Du bist gerade erst hierher gezogen,\n"
	.string "daher weißt du das vielleicht noch\l"
	.string "nicht, aber MR. BRACK war mal Seefahrer.$"
	.endif
	.endif

RustboroCity_Text_TunnelNearingCompletion:
	.ifdef ENGLISH
	.string "“Timesaving tunnel nearing\n"
	.string "completion!”\p"
	.string "…Is what it says on the sign, but\n"
	.string "there's also a big “X” splashed\l"
	.string "across it in red paint…$"
	.else
	.ifdef GERMAN
	.string "“Tunnel zur Abkürzung steht vor\n"
	.string "Fertigstellung!”\p"
	.string "… Das steht auf dem Schild, aber\n"
	.string "darüber wurde ein “X”\l"
	.string "in roter Farbe gemalt…$"
	.endif
	.endif

RustboroCity_Text_DevonCorpSign:
	.ifdef ENGLISH
	.string "DEVON CORPORATION\p"
	.string "“For all your living needs, we make\n"
	.string "it all.”$"
	.else
	.ifdef GERMAN
	.string "DEVON CORPORATION\p"
	.string "“Alles, was man im Leben braucht - \n"
	.string "wir stellen es her.”$"
	.endif
	.endif

RustboroCity_Text_GymSign:
	.ifdef ENGLISH
	.string "RUSTBORO CITY POKéMON GYM\n"
	.string "LEADER: ROXANNE\p"
	.string "“The ROCK-loving honors student!”$"
	.else
	.ifdef GERMAN
	.string "POKéMON ARENA von METAROST CITY\n"
	.string "LEITERIN: FELIZIA\p"
	.string "“GESTEIN-Liebhaberin und\n"
	.string "ihre Schüler!”$"
	.endif
	.endif

RustboroCity_Text_DevonCorpBranchOfficeSign:
	.ifdef ENGLISH
	.string "DEVON CORP. BRANCH OFFICE\p"
	.string "“Access limited to DEVON employees\n"
	.string "and authorized personnel.”$"
	.else
	.ifdef GERMAN
	.string "DEVON CORP. FILIALE\p"
	.string "“Zutritt nur für Angestellte von DEVON\n"
	.string "und autorisierte Personen.”$"
	.endif
	.endif

RustboroCity_Text_CitySign:
	.ifdef ENGLISH
	.string "RUSTBORO CITY\p"
	.string "“The city probing the integration of\n"
	.string "nature and science.”$"
	.else
	.ifdef GERMAN
	.string "METAROST CITY\p"
	.string "“Diese Stadt steht im Zeichen der\n"
	.string "Integration von Natur und\l"
	.string "Wissenschaften.”$"
	.endif
	.endif

RustboroCity_Text_TrainersSchoolSign:
	.ifdef ENGLISH
	.string "POKéMON TRAINER'S SCHOOL\p"
	.string "“We'll teach you anything about\n"
	.string "POKéMON!”$"
	.else
	.ifdef GERMAN
	.string "POKéMON TRAINERSCHULE\p"
	.string "“Wir bringen dir alles über die\n"
	.string "POKéMON bei!”$"
	.endif
	.endif

RustboroCity_Text_CuttersHouse:
	.ifdef ENGLISH
	.string "CUTTER'S HOUSE$"
	.else
	.ifdef GERMAN
	.string "HAUS DES ZERSCHNEIDERS$"
	.endif
	.endif

RustboroCity_Text_DevelopedNewPokenavFeature:
	.ifdef ENGLISH
	.string "I've been developing an added feature\n"
	.string "for the POKéNAV…\p"
	.string "And it turned out great!\p"
	.string "{PLAYER}, may I see that POKéNAV?\n"
	.string "The one our PRESIDENT gave you?$"
	.else
	.ifdef GERMAN
	.string "Ich habe neues Zubehör für den POKéNAV\n"
	.string "entwickelt…\p"
	.string "Und es funktioniert großartig!\p"
	.string "Zeigst du mir mal deinen POKéNAV,\n"
	.string "{PLAYER}? Den du von unserem\l"
	.string "PRÄSIDENTen bekommen hast.$"
	.endif
	.endif

RustboroCity_Text_AddedMatchCallPleaseCallMrStone:
	.ifdef ENGLISH
	.string "There you go, {PLAYER}!\p"
	.string "I added a new feature named\n"
	.string "MATCH CALL to your POKéNAV.\p"
	.string "Using the MATCH CALL feature,\n"
	.string "you can chat with people who have\l"
	.string "been registered in your POKéNAV.\p"
	.string "{PLAYER}, our PRESIDENT STONE should\n"
	.string "be registered in your POKéNAV.\p"
	.string "Test it out.\n"
	.string "Please give our PRESIDENT a call.$"
	.else
	.ifdef GERMAN
	.string "Hier, bitte schön, {PLAYER}.\p"
	.string "Ich habe deinen POKéNAV mit dem\n"
	.string "so genannten TRAINER/RUF\l"
	.string "ausgestattet.\p"
	.string "Trage deine Freunde und andere\n"
	.string "Personen in das Verzeichnis ein. Dann\l"
	.string "kannst du mit ihnen reden.\p"
	.string "Du solltest auch unseren PRÄSIDENTen\n"
	.string "TRUMM eintragen, {PLAYER}.\p"
	.string "Probier es mal aus.\n"
	.string "Ruf unseren PRÄSIDENTen an.$"
	.endif
	.endif

RustboroCity_Text_PleaseSelectPokenav:
	.ifdef ENGLISH
	.string "Please select the POKéNAV.$"
	.else
	.ifdef GERMAN
	.string "Wähle POKéNAV.$"
	.endif
	.endif

RustboroCity_Text_IdBetterGetBackToWork:
	.ifdef ENGLISH
	.string "Okay, I'd better get back to work.\n"
	.string "Please take care, {PLAYER}!$"
	.else
	.ifdef GERMAN
	.string "So, jetzt muss ich aber weiterarbeiten.\n"
	.string "Pass auf dich auf, {PLAYER}.$"
	.endif
	.endif

RustboroCity_Text_YouCanHave2On2Battle:
	.ifdef ENGLISH
	.string "Did you know this?\p"
	.string "You can have a 2-on-2 battle even\n"
	.string "if you're not with another TRAINER.\p"
	.string "If you catch the eyes of two TRAINERS\n"
	.string "when you have two or more POKéMON,\l"
	.string "they'll both challenge you.\p"
	.string "Don't you think it'd be cool if you\n"
	.string "could beat two TRAINERS by yourself?$"
	.else
	.ifdef GERMAN
	.string "Weißt du das schon?\p"
	.string "Du kannst auch an 2-gegen-2-Kämpfen\n"
	.string "teilnehmen, wenn du allein unterwegs\l"
	.string "bist.\p"
	.string "Triffst du auf zwei TRAINER und hast\n"
	.string "mindestens zwei POKéMON dabei, werden\l"
	.string "sie dich beide herausfordern.\p"
	.string "Ich finde es total cool, wenn man allein\n"
	.string "zwei TRAINER besiegt. Meinst du nicht?$"
	.endif
	.endif
