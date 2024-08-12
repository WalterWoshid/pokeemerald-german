.set LOCALID_OPPONENT, 1
.set LOCALID_ATTENDANT_1, 2
.set LOCALID_ATTENDANT_2, 3

BattleFrontier_BattleTowerBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerBattleRoom_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerBattleRoom_OnWarp
	.byte 0

BattleFrontier_BattleTowerBattleRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_SetUpObjects
	.2byte 0

BattleFrontier_BattleTowerBattleRoom_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	applymovement LOCALID_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SetInvisible
	end

BattleFrontier_BattleTowerBattleRoom_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattleTowerBattleRoom_EventScript_EnterRoom::
	setvar VAR_TEMP_0, 1
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerEnter
	waitmovement 0
	frontier_get FRONTIER_DATA_BATTLE_NUM
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant
	waitmovement 0
	setvar VAR_TEMP_2, 1
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter::
	tower_setopponent
	addobject LOCALID_OPPONENT
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_OpponentEnter
	waitmovement 0
	tower_getopponentintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
	switch VAR_RESULT
	case B_OUTCOME_WON, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedOpponent
BattleFrontier_BattleTower_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	tower_set TOWER_DATA_LVL_MODE
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
	special Script_TryGainNewFanFromCounter
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedOpponent::
	call BattleFrontier_EventScript_IncrementWinStreak
	tower_setbattlewon
	switch VAR_RESULT
	case 7, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_OpponentExit
	waitmovement 0
	removeobject LOCALID_OPPONENT
	frontier_getbrainstatus
	call_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleTowerBattleRoom_EventScript_SecondAttendantEnter
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant
	waitmovement 0
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent::
	frontier_getbrainstatus
	copyvar VAR_TEMP_F, VAR_RESULT
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleTowerBattleRoom_EventScript_MaidenUpNext
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyForOpponent
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponentNoRecord
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponentNoRecord::
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle::
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
	case YES, BattleFrontier_BattleTowerBattleRoom_EventScript_PauseChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_RetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle
	waitmovement 0
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos
	waitmovement 0
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	tower_set TOWER_DATA_LVL_MODE
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
	special Script_TryGainNewFanFromCounter
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattleTowerBattleRoom_EventScript_PauseChallenge::
	message BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait
	waitmessage
	tower_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyForOpponent::
	copyvar VAR_TEMP_F, VAR_RESULT
	switch VAR_TEMP_F
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor2ndOpponent
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor3rdOpponent
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor4thOpponent
	case 4, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor5thOpponent
	case 5, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor6thOpponent
	case 6, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor7thOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor4thOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor4thOpponent
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor5thOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor5thOpponent
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor6thOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor6thOpponent
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor7thOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor7thOpponent
	waitmessage
	return

BattleFrontier_EventScript_IncrementWinStreak::
	frontier_incrementstreak
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_SecondAttendantEnter::
	applymovement LOCALID_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantEnter
	waitmovement 0
	applymovement LOCALID_ATTENDANT_2, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_ATTENDANT_1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ATTENDANT_1, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantDelay
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantFaceSecondAttendant
	waitmovement 0
	applymovement LOCALID_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantExit
	waitmovement 0
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_MaidenUpNext::
	goto_if_eq VAR_TEMP_2, 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SalonMaidenOnHerWay, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyForSalonMaiden
	waitmessage
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaidenNoRecord
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden

BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaidenNoRecord::
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden

BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel::
	call BattleFrontier_EventScript_SetBrainObjectGfx
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle
	waitmovement 0
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos
	waitmovement 0
	addobject LOCALID_OPPONENT
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_AnabelEnter
	waitmovement 0
	switch VAR_TEMP_F
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleTowerBattleRoom_EventScript_AnabelGoldIntro
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_GreetingsImAnabel, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver::
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_LetMeSeeYourTalent, MSGBOX_DEFAULT
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelSilver
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost

BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelSilver::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_getsymbols
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelTalentShallBeRecognized, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattleTowerBattleRoom_Text_ReceivedAbilitySymbol
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_UntilNextTime, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon

BattleFrontier_BattleTowerBattleRoom_EventScript_AnabelGoldIntro::
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelYouCameBack, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold::
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_LetsBeginShallWe, MSGBOX_DEFAULT
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelGold
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost

BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelGold::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_getsymbols
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelCongratsYourPassPlease, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattleTowerBattleRoom_Text_AbilitySymbolTookGoldenShine
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_WishICouldBattleYouAgain, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon

BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle::
	closemessage
	setvar VAR_TEMP_2, 0
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_BATTLE_TOWER
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	copyvar VAR_0x8004, VAR_FRONTIER_BATTLE_MODE
	goto_if_eq VAR_0x8004, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerBattleRoom_EventScript_EndTowerBattle
	frontier_restorehelditems
	special HealPlayerParty
	frontier_resetsketch
BattleFrontier_BattleTowerBattleRoom_EventScript_EndTowerBattle::
	tower_setinterviewdata
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	return

BattleFrontier_EventScript_SetBrainObjectGfx::
	frontier_setbrainobj
	return

BattleFrontier_BattleTowerBattleRoom_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	face_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant:
	face_down
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle:
	face_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_OpponentEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_OpponentExit:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos:
	walk_down
	walk_left
	walk_left
	walk_left
	face_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_SetInvisible:
	set_invisible
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantEnter:
	set_visible
	delay_16
	walk_up
	walk_left
	walk_left
	delay_8
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantExit:
	walk_right
	walk_right
	walk_down
	set_invisible
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantDelay:
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_AttendantFaceSecondAttendant:
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_AnabelEnter:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	face_left
	step_end

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby::
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
	goto_if_eq VAR_RESULT, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyDoubles
	goto_if_eq VAR_RESULT, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyMultis
	goto_if_eq VAR_RESULT, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyLinkMultis
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 6, 6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyDoubles::
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 10, 6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyMultis::
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 14, 6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyLinkMultis::
	tower_closelink
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 18, 6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_RetireChallenge::
	setflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth:
	.ifdef ENGLISH
	.string "We will restore your POKéMON to\n"
	.string "full health.$"
	.else
	.ifdef GERMAN
	.string "Wir heilen deine POKéMON und machen\n"
	.string "sie wieder fit!$"
	.endif
	.endif

@ Unused
BattleFrontier_BattleTowerBattleRoom_Text_ReadyForOpponent:
	.ifdef ENGLISH
	.string "You will be facing opponent no. {STR_VAR_1}.\n"
	.string "Are you ready?$"
	.else
	.ifdef GERMAN
	.string "You will be facing opponent no. {STR_VAR_1}.\n"
	.string "Are you ready?$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor2ndOpponent:
	.ifdef ENGLISH
	.string "You will be facing opponent no. 2.\n"
	.string "Are you ready?$"
	.else
	.ifdef GERMAN
	.string "Gegner Nr. 2 erwartet dich.\n"
	.string "Bist du so weit?$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor3rdOpponent:
	.ifdef ENGLISH
	.string "You will be facing opponent no. 3.\n"
	.string "Are you ready?$"
	.else
	.ifdef GERMAN
	.string "Gegner Nr. 3 erwartet dich.\n"
	.string "Bist du so weit?$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor4thOpponent:
	.ifdef ENGLISH
	.string "You will be facing opponent no. 4.\n"
	.string "Are you ready?$"
	.else
	.ifdef GERMAN
	.string "Gegner Nr. 4 erwartet dich.\n"
	.string "Bist du so weit?$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor5thOpponent:
	.ifdef ENGLISH
	.string "You will be facing opponent no. 5.\n"
	.string "Are you ready?$"
	.else
	.ifdef GERMAN
	.string "Gegner Nr. 5 erwartet dich.\n"
	.string "Bist du so weit?$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor6thOpponent:
	.ifdef ENGLISH
	.string "You will be facing opponent no. 6.\n"
	.string "Are you ready?$"
	.else
	.ifdef GERMAN
	.string "Gegner Nr. 6 erwartet dich.\n"
	.string "Bist du so weit?$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor7thOpponent:
	.ifdef ENGLISH
	.string "You will be facing opponent no. 7.\n"
	.string "Are you ready?$"
	.else
	.ifdef GERMAN
	.string "Gegner Nr. 7 erwartet dich.\n"
	.string "Bist du so weit?$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle:
	.ifdef ENGLISH
	.string "Record your battle on your\n"
	.string "FRONTIER PASS?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du die Resultate in deinen\n"
	.string "KAMPFZONENPASS eintragen?$"
	.endif
	.endif

BattleFrontier_BattleTowerLobby_Text_BattleRecordedOnPass:
	.ifdef ENGLISH
	.string "{PLAYER}'s battle was recorded\n"
	.string "on the FRONTIER PASS.$"
	.else
	.ifdef GERMAN
	.string "Der Kampf von {PLAYER} wurde im\n"
	.string "KAMPFZONENPASS eingetragen.$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame:
	.ifdef ENGLISH
	.string "Would you like to save and\n"
	.string "quit the game?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du das Spiel speichern und\n"
	.string "beenden?$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait:
	.ifdef ENGLISH
	.string "Saving your battle data.\n"
	.string "Please wait.$"
	.else
	.ifdef GERMAN
	.string "Deine Kampfdaten werden gespeichert.\n"
	.string "Bitte warte einen Moment.$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge:
	.ifdef ENGLISH
	.string "Would you like to cancel your BATTLE\n"
	.string "ROOM challenge?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du die Herausforderung im\n"
	.string "KAMPFRAUM abbrechen?$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved::
	.ifdef ENGLISH
	.string "There was an error of some sort.\n"
	.string "Your record could not be saved.$"
	.else
	.ifdef GERMAN
	.string "Es gab einen Fehler. Deine Daten\n"
	.string "konnten nicht gespeichert werden.$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_SalonMaidenOnHerWay:
	.ifdef ENGLISH
	.string "Excuse me, but…\p"
	.string "Our leader, the SALON MAIDEN, is on\n"
	.string "her way here in hopes of battling you.\p"
	.string "She should be arriving very shortly.$"
	.else
	.ifdef GERMAN
	.string "Entschuldige, aber…\p"
	.string "Unser KAMPFKOLOSS ist\n"
	.string "gerade auf dem Weg hierher.\p"
	.string "Sie hofft auf einen Kampf.\n"
	.string "Sie sollte bald hier sein.$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_ReadyForSalonMaiden:
	.ifdef ENGLISH
	.string "You will be facing the SALON MAIDEN.\n"
	.string "Are you prepared?$"
	.else
	.ifdef GERMAN
	.string "Auf dich wartet der KAMPFKOLOSS.\n"
	.string "Bist du so weit?$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_GreetingsImAnabel:
	.ifdef ENGLISH
	.string "Greetings…\n"
	.string "My name is ANABEL.\p"
	.string "I am the SALON MAIDEN, and I am in\n"
	.string "charge of running the BATTLE TOWER…\p"
	.string "I have heard several rumors\n"
	.string "about you…\p"
	.string "In all honesty, what I have heard does\n"
	.string "not seem attractive in any way…\p"
	.string "The reason I've come to see you…\n"
	.string "Well, there is but one reason…$"
	.else
	.ifdef GERMAN
	.string "Hallo…\n"
	.string "Mein Name ist ANABEL.\p"
	.string "Ich bin der KAMPFKOLOSS und\n"
	.string "ich bin hier verantwortlich für den\l"
	.string "DUELLTURM…\p"
	.string "Ich habe schon verschiedene Gerüchte\n"
	.string "über dich gehört…\p"
	.string "Ehrlich gesagt waren das keine schönen\n"
	.string "Geschichten…\p"
	.string "Warum ich überhaupt hier bin…\n"
	.string "Nun, es gibt da einen Grund…$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_LetMeSeeYourTalent:
	.ifdef ENGLISH
	.string "Let me see your talent in\n"
	.string "its entirety…$"
	.else
	.ifdef GERMAN
	.string "Zeig mir dein ganzes Können…$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_AnabelTalentShallBeRecognized:
	.ifdef ENGLISH
	.string "ANABEL: Fufufu, nicely done…\p"
	.string "Your FRONTIER PASS, please…\n"
	.string "Your talent shall be recognized.$"
	.else
	.ifdef GERMAN
	.string "ANABEL: Hahaha, sehr schön…\p"
	.string "Gib mir bitte deinen KAMPFZONENPASS…\n"
	.string "Dein Talent soll jeder sehen.$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_ReceivedAbilitySymbol:
	.ifdef ENGLISH
	.string "The Ability Symbol was embossed on\n"
	.string "the FRONTIER PASS!$"
	.else
	.ifdef GERMAN
	.string "Das ANLAGESYMBOL wurde dem KAMPF-\n"
	.string "ZONENPASS hinzugefügt!$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_UntilNextTime:
	.ifdef ENGLISH
	.string "… … … … … …\p"
	.string "You have confidence in your POKéMON\n"
	.string "battling talent, don't you?\p"
	.string "I urge you to keep battling and\n"
	.string "keep on winning.\p"
	.string "I will be waiting for you.\n"
	.string "Until the next time we meet…$"
	.else
	.ifdef GERMAN
	.string "……………\n"
	.string "…\p"
	.string "Du bist dir deines Talentes als Kämpfer\n"
	.string "ziemlich sicher, nicht wahr?\p"
	.string "Ich verlange von dir, dass du weiter\n"
	.string "kämpfst und gewinnst!\p"
	.string "Ich warte auf dich.\n"
	.string "Bis zum nächsten Mal…$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_AnabelYouCameBack:
	.ifdef ENGLISH
	.string "ANABEL: You really did come back to\n"
	.string "see me…\p"
	.string "… … … … … …\p"
	.string "You've won straight matches to see me…\n"
	.string "I won't have to hold back against you…\p"
	.string "It's been too long now…\p"
	.string "Too long since I've been able to battle\n"
	.string "without thinking about anything…$"
	.else
	.ifdef GERMAN
	.string "ANABEL: Du bist wirklich wieder-\n"
	.string "gekommen…\p"
	.string "……………\n"
	.string "…\p"
	.string "Du hast mehrmals in Folge gesiegt, nur\n"
	.string "um mich wiederzusehen…\p"
	.string "Das heißt, du bist stark und ich brauche\n"
	.string "mich nicht zurückzuhalten…\p"
	.string "Es ist schon sehr lange her…\p"
	.string "Es ist zu lange her, dass ich ohne\n"
	.string "Rücksicht kämpfen konnte…$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_LetsBeginShallWe:
	.ifdef ENGLISH
	.string "Let's begin, shall we?$"
	.else
	.ifdef GERMAN
	.string "Sollen wir anfangen?$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_AnabelCongratsYourPassPlease:
	.ifdef ENGLISH
	.string "ANABEL: Fufu, congratulations…\n"
	.string "Your FRONTIER PASS, please…$"
	.else
	.ifdef GERMAN
	.string "ANABEL: Hähä, Glückwunsch…\n"
	.string "Gib mir deinen KAMPFZONENPASS…$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_AbilitySymbolTookGoldenShine:
	.ifdef ENGLISH
	.string "The Ability Symbol took on\n"
	.string "a golden shine!$"
	.else
	.ifdef GERMAN
	.string "Das ANLAGESYMBOL erscheint in einem\n"
	.string "goldenen Glanz!$"
	.endif
	.endif

BattleFrontier_BattleTowerBattleRoom_Text_WishICouldBattleYouAgain:
	.ifdef ENGLISH
	.string "That was fun…\p"
	.string "I have never had a POKéMON battle\n"
	.string "so enjoyable before…\p"
	.string "I wish I could battle with you again…$"
	.else
	.ifdef GERMAN
	.string "Das hat Spaß gemacht…\p"
	.string "So einen tollen POKéMON-Kampf habe ich\n"
	.string "bisher noch nicht erlebt…\p"
	.string "Ich wünschte, ich könnte öfter gegen\n"
	.string "dich antreten…$"
	.endif
	.endif

