@ Objects in this room are set dynamically with OBJ_EVENT_GFX_VAR_0 and OBJ_EVENT_GFX_VAR_1
@ Note: LOCALIDs shared with data/scripts/battle_pike.inc
.equ LOCALID_OBJ_0, 1
.equ LOCALID_OBJ_1, 2

BattleFrontier_BattlePikeRoomNormal_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePikeRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePikeRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeRoomNormal_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeRoom_OnWarp
	.byte 0

BattleFrontier_BattlePikeRoomNormal_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterRoom::
	setvar VAR_TEMP_0, 1
	pike_getroomtype
	switch VAR_RESULT
	case PIKE_ROOM_SINGLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterSingleBattleRoom
	case PIKE_ROOM_HEAL_FULL, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterFullHealRoom
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterStatusRoom
	case PIKE_ROOM_HARD_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterHardBattleRoom
	case PIKE_ROOM_DOUBLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterDoubleBattleRoom
	case PIKE_ROOM_BRAIN, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterBrainRoom
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterSingleBattleRoom::
	lockall
	delay 16
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
	waitmovement 0
	pike_gettrainerintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonSingleBattle
BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 5, 6
	waitstate
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WonSingleBattle::
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterHardBattleRoom::
	lockall
	delay 16
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_BattleSomewhatToughTrainer, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
	waitmovement 0
	pike_gettrainerintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonHardBattle
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WonHardBattle::
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
	waitmovement 0
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCApproachPlayer
	waitmovement 0
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_RestoreToFullHealth, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge2, MSGBOX_DEFAULT
	closemessage
	release
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterBrainRoom::
	delay 22
	lockall
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_PreQueenHealNPCApproachPlayer
	waitmovement 0
	pike_prequeenheal
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenNoHeal
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealOneMon
	case 2, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealTwoMons

BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ShallFetchOurMaster, MSGBOX_DEFAULT
	closemessage
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanUp
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExitForLucy
	waitmovement 0
	playse SE_PIKE_CURTAIN_CLOSE
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesClosed
	delay 4
	waitse
	delay 60
	playse SE_PIKE_CURTAIN_OPEN
	delay 65
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed
	showobjectat LOCALID_OBJ_0, MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_NORMAL
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesOpen
	waitse
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_LucyEnter
	waitmovement 0
	pike_getbrainstatus
	switch VAR_RESULT
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePikeRoomNormal_EventScript_IntroLucyGold
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ImThePikeQueen, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_HopeYouDidntUseUpLuck, MSGBOX_DEFAULT
	call BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucySilver
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost

BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucySilver::
	frontier_getsymbols
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyShowMeFrontierPass, MSGBOX_DEFAULT
	waitmessage
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePikeRoomNormal_Text_ReceivedLuckSymbol
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_AllThereIsDisappear, MSGBOX_DEFAULT
	closemessage
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy

BattleFrontier_BattlePikeRoomNormal_EventScript_IntroLucyGold::
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyYouAgain, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_NowComeOn, MSGBOX_DEFAULT
	call BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucyGold
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost

BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucyGold::
	frontier_getsymbols
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyFrontierPass, MSGBOX_DEFAULT
	waitmessage
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePikeRoomNormal_Text_LuckSymbolTookGoldenShine
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_IWontForget, MSGBOX_DEFAULT
	closemessage
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy::
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_LucyMoveAside
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2
	waitmovement 0
	pike_get PIKE_DATA_WIN_STREAK
	addvar VAR_RESULT, 1
	pike_set PIKE_DATA_WIN_STREAK, VAR_RESULT
	call BattleFrontier_BattlePikeRoom_EventScript_WarpToFinalRoom
	waitstate
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenNoHeal::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomNoHeal, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealOneMon::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealOne, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealTwoMons::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealTwo, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterFullHealRoom::
	lockall
	delay 16
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
	waitmovement 0
	message BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreToFullHealth
	waitmessage
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
	waitmovement 0
	releaseall
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterDoubleBattleRoom::
	lockall
	delay 16
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1WalkRight
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2WalkLeft
	waitmovement 0
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown
	waitmovement 0
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1FacePlayer
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2FacePlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer1
	waitmovement 0
	pike_gettrainerintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2
	waitmovement 0
	pike_gettrainerintro 1
	msgbox gStringVar4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_DOUBLE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonDoubleBattle
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WonDoubleBattle::
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2
	waitmovement 0
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1Exit
	waitmovement 0
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2Exit
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceUp
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterStatusRoom::
	lockall
	message BattleFrontier_BattlePikeRoomNormal_Text_WatchOut
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonApproachPlayer
	waitmovement 0
	pike_getstatusmon
	copyvar VAR_0x8004, VAR_RESULT
	call_if_eq VAR_0x8004, PIKE_STATUSMON_KIRLIA, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaAttack
	call_if_eq VAR_0x8004, PIKE_STATUSMON_DUSCLOPS, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsAttack
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_AttacksWhenStartled, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaAttack::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_KirliaStop, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	waitmoncry
	pike_getstatus
	call_if_eq VAR_RESULT, PIKE_STATUS_TOXIC, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedToxic
	call_if_eq VAR_RESULT, PIKE_STATUS_BURN, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedWillOWisp
	call_if_eq VAR_RESULT, PIKE_STATUS_PARALYSIS, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedThunderWave
	call_if_eq VAR_RESULT, PIKE_STATUS_SLEEP, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedHypnosis
	pike_flashscreen
	waitstate
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon
	waitmovement 0
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC
	waitmovement 0
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	waitmoncry
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	waitmoncry
	closemessage
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForKirlia, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsAttack::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_DusclopsStop, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
	waitmoncry
	pike_getstatus
	call_if_eq VAR_RESULT, PIKE_STATUS_FREEZE, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedIceBeam
	call_if_eq VAR_RESULT, PIKE_STATUS_BURN, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedWillOWisp
	pike_flashscreen
	waitstate
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon
	waitmovement 0
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC
	waitmovement 0
	waitse
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
	waitmoncry
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
	waitmoncry
	closemessage
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForDusclops, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedToxic::
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedToxic
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedWillOWisp::
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedWillOWisp
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedThunderWave::
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedThunderWave
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedHypnosis::
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedHypnosis
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedIceBeam::
	message BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedIceBeam
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedWillOWisp::
	message BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedWillOWisp
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2
	waitmovement 0
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	return

BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit:
	walk_up
	walk_up
	walk_up
	set_invisible
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit:
	walk_up
	set_invisible
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon:
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer:
	walk_down
	face_left
	delay_16
	delay_16
	face_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_MonApproachPlayer:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_left
	face_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC:
	face_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside:
	walk_left
BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceRight:
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCApproachPlayer:
	walk_down
	walk_down
	walk_right
	face_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer1:
	face_left
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2:
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceUp:
	face_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1WalkRight:
	walk_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2WalkLeft:
	walk_left
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1FacePlayer:
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2FacePlayer:
	face_left
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1Exit:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	set_invisible
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2Exit:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	set_invisible
	walk_up
	step_end

@ For approaching Lucy and exiting room after defeating Lucy
BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PreQueenHealNPCApproachPlayer:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExitForLucy:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_LucyEnter:
	set_visible
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_LucyMoveAside:
	walk_left
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_EventScript_NPC::
	pike_getroomtype
	switch VAR_RESULT
	case PIKE_ROOM_NPC, BattleFrontier_BattlePikeRoomNormal_EventScript_NormalNPC
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeRoomNormal_EventScript_StatusNPC
	case PIKE_ROOM_HEAL_PART, BattleFrontier_BattlePikeRoomNormal_EventScript_HealNPC
BattleFrontier_BattlePikeRoomNormal_EventScript_NormalNPC::
	lock
	faceplayer
	pike_getnpcmsg
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	release
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_StatusNPC::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeHopeMonsAreFine, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_HealNPC::
	pike_healonetwomons
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreTwoMons
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreOneMon
	playfanfare MUS_HEAL
	waitfanfare
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell, MSGBOX_DEFAULT
	closemessage
	release
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreOneMon::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreOneMon, MSGBOX_DEFAULT
	closemessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreTwoMons::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreTwoMons, MSGBOX_DEFAULT
	closemessage
	return

@ Dusclops or Kirlia
BattleFrontier_BattlePikeRoomNormal_EventScript_StatusMon::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_Silence, MSGBOX_DEFAULT
	closemessage
	release
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceRight
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed::
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage1_Tile0, TRUE
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage1_Tile1, TRUE
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage1_Tile2, TRUE
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage1_Tile3, TRUE
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage1_Tile4, TRUE
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage1_Tile5, FALSE
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage1_Tile6, TRUE
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed::
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage2_Tile0, TRUE
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage2_Tile1, TRUE
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage2_Tile2, TRUE
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage2_Tile3, TRUE
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage2_Tile4, TRUE
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage2_Tile5, FALSE
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage2_Tile6, TRUE
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesOpen::
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage3_Tile0, TRUE
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage3_Tile1, TRUE
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage3_Tile2, TRUE
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage3_Tile3, TRUE
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage3_Tile4, TRUE
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage3_Tile5, FALSE
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage3_Tile6, TRUE
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesClosed::
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage0_Tile0, TRUE
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage0_Tile1, TRUE
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage0_Tile2, TRUE
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage0_Tile3, TRUE
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage0_Tile4, TRUE
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage0_Tile5, FALSE
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage0_Tile6, TRUE
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanUp:
	walk_up
	walk_up
	step_end

@ Unused
BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanDown:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreToFullHealth:
	.ifdef ENGLISH
	.string "Welcome…\n"
	.string "You must be commended for your luck…\p"
	.string "Your POKéMON shall be restored\n"
	.string "to full health…$"
	.else
	.ifdef GERMAN
	.string "Willkommen…\n"
	.string "Du hast wirklich Glück!\p"
	.string "Deine POKéMON sind bald wieder\n"
	.string "topfit…$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge:
	.ifdef ENGLISH
	.string "I urge you to enjoy the rest of your\n"
	.string "Battle Choice challenge…$"
	.else
	.ifdef GERMAN
	.string "Ich wünsche dir für den restlichen Weg\n"
	.string "deiner Kampfbahn-Herausforderung\l"
	.string "alles Gute…$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreOneMon:
	.ifdef ENGLISH
	.string "Ah, you're a lucky one.\n"
	.string "I'm in somewhat-good spirits now.\p"
	.string "I will restore one of your POKéMON\n"
	.string "to full health.$"
	.else
	.ifdef GERMAN
	.string "Na, du bist echt ein Glückspilz.\n"
	.string "Ich bin gerade in guter Stimmung.\p"
	.string "Deine POKéMON sind gleich wieder\n"
	.string "topfit…$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell:
	.ifdef ENGLISH
	.string "The best of luck to you.\n"
	.string "Farewell.$"
	.else
	.ifdef GERMAN
	.string "Ich wünsche dir alles Gute!\n"
	.string "Leb wohl…$"
	.endif
	.endif

@ Seems there was a planned room type where the player could choose to battle and would be healed if they won
@ Possibly replaced/superseded by the hard battle room, which is the same but the battle isnt optional
@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_CareForBattleWillRestoreMons:
	.ifdef ENGLISH
	.string "Excuse me…\p"
	.string "Would you care for a battle?\n"
	.string "I'll restore your POKéMON if you win.$"
	.else
	.ifdef GERMAN
	.string "Excuse me…\p"
	.string "Would you care for a battle?\n"
	.string "I’ll restore your POKéMON if you win.$"
	.endif
	.endif

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_NowShallWe:
	.ifdef ENGLISH
	.string "Very well…\n"
	.string "Now, shall we?$"
	.else
	.ifdef GERMAN
	.string "Very well…\n"
	.string "Now, shall we?$"
	.endif
	.endif

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_HowUnsportingOfYou:
	.ifdef ENGLISH
	.string "I see…\n"
	.string "How unsporting of you…$"
	.else
	.ifdef GERMAN
	.string "I see…\n"
	.string "How unsporting of you…$"
	.endif
	.endif

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreMonsAsPromised:
	.ifdef ENGLISH
	.string "Magnificent…\p"
	.string "As promised, I shall restore your\n"
	.string "POKéMON to full health.$"
	.else
	.ifdef GERMAN
	.string "Magnificent…\p"
	.string "As promised, I shall restore your\n"
	.string "POKéMON to full health.$"
	.endif
	.endif

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell2:
	.ifdef ENGLISH
	.string "The best of luck to you.\n"
	.string "Farewell.$"
	.else
	.ifdef GERMAN
	.string "The best of luck to you.\n"
	.string "Farewell.$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_WatchOut:
	.ifdef ENGLISH
	.string "Oh, my!\p"
	.string "Watch out!$"
	.else
	.ifdef GERMAN
	.string "Oh je!\p"
	.string "Pass auf!!!$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_KirliaStop:
	.ifdef ENGLISH
	.string "Now, now!\n"
	.string "KIRLIA, stop that!$"
	.else
	.ifdef GERMAN
	.string "Aber, aber!\n"
	.string "KIRLIA, hör auf damit!$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_DusclopsStop:
	.ifdef ENGLISH
	.string "Now, now!\n"
	.string "DUSCLOPS, stop that!$"
	.else
	.ifdef GERMAN
	.string "Aber, aber!\n"
	.string "ZWIRRKLOP, hör auf damit!$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedToxic:
	.ifdef ENGLISH
	.string "KIRLIA used TOXIC!$"
	.else
	.ifdef GERMAN
	.string "KIRLIA setzt TOXIN ein!$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedHypnosis:
	.ifdef ENGLISH
	.string "KIRLIA used HYPNOSIS!$"
	.else
	.ifdef GERMAN
	.string "KIRLIA setzt HYPNOSE ein!$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedThunderWave:
	.ifdef ENGLISH
	.string "KIRLIA used THUNDER WAVE!$"
	.else
	.ifdef GERMAN
	.string "KIRLIA setzt DONNERWELLE ein!$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedWillOWisp:
	.ifdef ENGLISH
	.string "KIRLIA used WILL-O-WISP!$"
	.else
	.ifdef GERMAN
	.string "KIRLIA setzt IRRLICHT ein!$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedWillOWisp:
	.ifdef ENGLISH
	.string "DUSCLOPS used WILL-O-WISP!$"
	.else
	.ifdef GERMAN
	.string "ZWIRRKLOP setzt IRRLICHT ein!$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedIceBeam:
	.ifdef ENGLISH
	.string "DUSCLOPS used ICE BEAM!$"
	.else
	.ifdef GERMAN
	.string "ZWIRRKLOP setzt EISSTRAHL ein!$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough:
	.ifdef ENGLISH
	.string "Look here!\n"
	.string "That's quite enough!$"
	.else
	.ifdef GERMAN
	.string "Jetzt reicht es aber!$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForKirlia:
	.ifdef ENGLISH
	.string "I must apologize to you…\p"
	.string "My KIRLIA has a TIMID nature…$"
	.else
	.ifdef GERMAN
	.string "Ich muss mich bei dir entschuldigen…\p"
	.string "Mein KIRLIA ist eigentlich SCHEU…$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForDusclops:
	.ifdef ENGLISH
	.string "I must apologize to you…\p"
	.string "My DUSCLOPS has a TIMID nature…$"
	.else
	.ifdef GERMAN
	.string "Ich muss mich bei dir entschuldigen…\p"
	.string "Mein ZWIRRKLOP ist eigentlich SCHEU…$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_AttacksWhenStartled:
	.ifdef ENGLISH
	.string "It attacks without warning if it is\n"
	.string "startled by another person…\p"
	.string "Are you and your POKéMON all right?$"
	.else
	.ifdef GERMAN
	.string "Es greift nur an, wenn es von jemandem\n"
	.string "erschreckt wird…\p"
	.string "Geht es dir und deinen POKéMON gut?$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_ApologizeHopeMonsAreFine:
	.ifdef ENGLISH
	.string "I do apologize for what happened…\n"
	.string "I do hope your POKéMON are fine.$"
	.else
	.ifdef GERMAN
	.string "Ich entschuldige mich für das, was\n"
	.string "passiert ist… Ich hoffe, deinen\l"
	.string "POKéMON geht es gut.$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_Silence:
	.ifdef ENGLISH
	.string "… … … … … …\n"
	.string "… … … … … …$"
	.else
	.ifdef GERMAN
	.string "… … … … …\n"
	.string "…\l"
	.string "… … … … …\l"
	.string "…$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_BattleSomewhatToughTrainer:
	.ifdef ENGLISH
	.string "Welcome…\p"
	.string "Here, we will have you battle\n"
	.string "a somewhat-tough TRAINER…$"
	.else
	.ifdef GERMAN
	.string "Willkommen…\p"
	.string "Hier musst du gegen einigermaßen\n"
	.string "starke Gegner antreten…$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_RestoreToFullHealth:
	.ifdef ENGLISH
	.string "How wonderful…\p"
	.string "To honor your victory, your POKéMON\n"
	.string "shall be restored to full health…$"
	.else
	.ifdef GERMAN
	.string "Oh, wunderbar!\p"
	.string "Als Belohnung für deinen Sieg sorge ich\n"
	.string "dafür, dass deine POKéMON wieder topfit\l"
	.string "sind.$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge2:
	.ifdef ENGLISH
	.string "I urge you to enjoy the rest of your\n"
	.string "Battle Choice challenge…$"
	.else
	.ifdef GERMAN
	.string "Ich wünsche dir für den restlichen Weg\n"
	.string "deiner Kampfbahn-Herausforderung\l"
	.string "alles Gute…$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_ImThePikeQueen:
	.ifdef ENGLISH
	.string "I am LUCY…\n"
	.string "I am the law here…\l"
	.string "For I am the PIKE QUEEN…\p"
	.string "You already know it, but to advance,\n"
	.string "you must defeat me…\p"
	.string "…I'm not one for idle chatter.\n"
	.string "Hurry. Come on…$"
	.else
	.ifdef GERMAN
	.string "Ich bin LOTTE…\n"
	.string "Ich bin hier das Gesetz…\l"
	.string "Ich bin die PFIPITISTIN…\p"
	.string "Du weißt das bestimmt schon, aber um\n"
	.string "weitergehen zu können, musst du erst\l"
	.string "an mir vorbei…\p"
	.string "Smalltalk liegt mir nicht…\n"
	.string "Los, lass uns kämpfen…$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_HopeYouDidntUseUpLuck:
	.ifdef ENGLISH
	.string "Your luck…\n"
	.string "I hope you didn't use it all up here…$"
	.else
	.ifdef GERMAN
	.string "Dein Glück… Ich hoffe, du hast\n"
	.string "noch etwas davon übrig…$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_LucyShowMeFrontierPass:
	.ifdef ENGLISH
	.string "LUCY: … … … … … …\n"
	.string "Show me your FRONTIER PASS…$"
	.else
	.ifdef GERMAN
	.string "LOTTE: … … … …\n"
	.string "… …\l"
	.string "Gib mir deinen KAMPFZONENPASS!$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_ReceivedLuckSymbol:
	.ifdef ENGLISH
	.string "The Luck Symbol was embossed on\n"
	.string "the FRONTIER PASS!$"
	.else
	.ifdef GERMAN
	.string "Das LOSSYMBOL wurde dem\n"
	.string "KAMPFZONENPASS hinzugefügt!$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_AllThereIsDisappear:
	.ifdef ENGLISH
	.string "…That's all there is…\n"
	.string "Disappear already…$"
	.else
	.ifdef GERMAN
	.string "Das war’s…\n"
	.string "Nun verschwinde endlich…$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_LucyYouAgain:
	.ifdef ENGLISH
	.string "LUCY: …You again…\p"
	.string "… … … … … …\p"
	.string "…I've trampled flowers and braved\n"
	.string "storms to get to where I am…\p"
	.string "I don't feel any compulsion to keep\n"
	.string "losing to the same opponent…\p"
	.string "… … … … … …\n"
	.string "Fine… I'll do it…$"
	.else
	.ifdef GERMAN
	.string "LOTTE: Du schon wieder…\p"
	.string "… … … … …\n"
	.string "…\p"
	.string "Ich habe Berge bezwungen und Stürme\n"
	.string "überstanden, um so weit zu kommen…\p"
	.string "Irgendwie habe ich nicht das Bedürfnis,\n"
	.string "wieder gegen denselben Gegner zu\l"
	.string "verlieren…\p"
	.string "… … … … …\n"
	.string "…\p"
	.string "Also gut… Kämpfen wir…$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_NowComeOn:
	.ifdef ENGLISH
	.string "Now!\n"
	.string "Come on!$"
	.else
	.ifdef GERMAN
	.string "Nun mach schon!$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_LucyFrontierPass:
	.ifdef ENGLISH
	.string "LUCY: … … … … … …\p"
	.string "…FRONTIER PASS…$"
	.else
	.ifdef GERMAN
	.string "LOTTE: … … … …\n"
	.string "… …\l"
	.string "……KAMPFZONENPASS……$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_LuckSymbolTookGoldenShine:
	.ifdef ENGLISH
	.string "The Luck Symbol took on\n"
	.string "a golden shine!$"
	.else
	.ifdef GERMAN
	.string "Das LOSSYMBOL erscheint\n"
	.string "in einem goldenen Glanz!$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_IWontForget:
	.ifdef ENGLISH
	.string "…You, I won't forget…\n"
	.string "…Ever…$"
	.else
	.ifdef GERMAN
	.string "Das werde ich dir nicht verzeihen…\n"
	.string "Niemals…$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomNoHeal:
	.ifdef ENGLISH
	.string "I welcome you…\p"
	.string "Giggle…\n"
	.string "You seem to be bereft of luck…\p"
	.string "If only you hadn't chosen this room,\n"
	.string "your POKéMON could have been healed…$"
	.else
	.ifdef GERMAN
	.string "Ich heiße dich willkommen…\p"
	.string "Kicher… Dein Glück scheint\n"
	.string "dich verlassen zu haben…\p"
	.string "Hättest du dich nicht für diesen Raum\n"
	.string "entschieden, wären deine POKéMON schon\l"
	.string "längst wieder topfit…$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealOne:
	.ifdef ENGLISH
	.string "I welcome you…\p"
	.string "Since you have chosen this room, I will\n"
	.string "restore one POKéMON to full health…$"
	.else
	.ifdef GERMAN
	.string "Ich heiße dich willkommen…\p"
	.string "Da du dich für diesen Raum entschieden\n"
	.string "hast, sorge ich dafür, dass eines deiner\l"
	.string "POKéMON wieder topfit wird.$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealTwo:
	.ifdef ENGLISH
	.string "I welcome you…\p"
	.string "Since you have chosen this room, I will\n"
	.string "restore two POKéMON to full health…$"
	.else
	.ifdef GERMAN
	.string "Ich heiße dich willkommen…\p"
	.string "Da du dich für diesen Raum entschieden\n"
	.string "hast, sorge ich dafür, dass deine\l"
	.string "POKéMON wieder topfit werden.$"
	.endif
	.endif

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreAllMons:
	.ifdef ENGLISH
	.string "I welcome you…\p"
	.string "Giggle…\n"
	.string "You should thank your lucky stars…\p"
	.string "Since you have chosen this room,\n"
	.string "all your POKéMON will be restored…$"
	.else
	.ifdef GERMAN
	.string "I welcome you…\p"
	.string "Giggle…\n"
	.string "You should thank your lucky stars…\p"
	.string "Since you have chosen this room,\n"
	.string "all your POKéMON will be restored…$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_ShallFetchOurMaster:
	.ifdef ENGLISH
	.string "I shall go fetch our master…$"
	.else
	.ifdef GERMAN
	.string "Ich werde unsere Meisterin rufen…$"
	.endif
	.endif

BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreTwoMons:
	.ifdef ENGLISH
	.string "Ah, you're a lucky one!\n"
	.string "I'm in good spirits now.\p"
	.string "I will restore two of your POKéMON\n"
	.string "to full health!$"
	.else
	.ifdef GERMAN
	.string "Du bist ein Glückspilz! Ich habe heute\n"
	.string "ausgesprochen gute Laune.\p"
	.string "Ich werde dafür sorgen, dass zwei\n"
	.string "deiner POKéMON wieder topfit werden.$"
	.endif
	.endif

