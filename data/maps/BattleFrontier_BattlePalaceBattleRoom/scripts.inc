.set LOCALID_PLAYER, 1
.set LOCALID_OPPONENT, 2
.set LOCALID_ATTENDANT, 3
.set LOCALID_DUSCLOPS, 4
.set LOCALID_AZURILL, 5

BattleFrontier_BattlePalaceBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePalaceBattleRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceBattleRoom_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceBattleRoom_OnWarp
	.byte 0

	@ On this map the player (OBJ_EVENT_ID_PLAYER) is hidden
	@ The player is represented instead by LOCALID_PLAYER, which has the gfx id VAR_OBJ_GFX_ID_0
	@ The opponent is represented by LOCALID_OPPONENT, which has the gfx id VAR_OBJ_GFX_ID_1

BattleFrontier_BattlePalaceBattleRoom_OnTransition:
	frontier_settrainers
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxMale
	goto_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxFemale
	return

@ The opponent's gfx are set to the players by default
BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxMale::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxFemale::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return

BattleFrontier_BattlePalaceBattleRoom_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattlePalaceBattleRoom_EventScript_EnterRoom::
	showobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
	frontier_get FRONTIER_DATA_BATTLE_NUM
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_BeginChallenge
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerReturnToChallenge
	waitmovement 0
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
	setvar VAR_TEMP_2, 1
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_BeginChallenge::
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerEnterRoom
	waitmovement 0
BattleFrontier_BattlePalaceBattleRoom_EventScript_NextOpponentEnter::
	tower_setopponent
	addobject LOCALID_OPPONENT
	applymovement LOCALID_OPPONENT, BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentEnter
	waitmovement 0
	palace_getopponentintro
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedOpponent
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedOpponent::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	switch VAR_RESULT
	case 7, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
	applymovement LOCALID_OPPONENT, BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentExit
	waitmovement 0
	removeobject LOCALID_OPPONENT
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
	waitmovement 0
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_LetMeRestoreYourMons, MSGBOX_DEFAULT
	special LoadPlayerParty
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent::
	frontier_getbrainstatus
	copyvar VAR_TEMP_F, VAR_RESULT
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattlePalaceBattleRoom_EventScript_MavenUpNext
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor3rdOpponent
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor4thOpponent
	call_if_eq VAR_RESULT, 4, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor5thOpponent
	call_if_eq VAR_RESULT, 5, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor6thOpponent
	call_if_eq VAR_RESULT, 6, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor7thOpponent
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponentNoRecord
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
	case 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponentNoRecord::
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle::
	message BattleFrontier_BattlePalaceBattleRoom_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
	case YES, BattleFrontier_BattlePalaceBattleRoom_EventScript_PauseChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge::
	message BattleFrontier_BattlePalaceBattleRoom_Text_WishToQuitChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge::
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
	closemessage
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_NextOpponentEnter

BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattlePalaceBattleRoom_EventScript_PauseChallenge::
	message BattleFrontier_BattlePalaceBattleRoom_Text_SavingData
	waitmessage
	palace_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_MavenUpNext::
	goto_if_eq VAR_TEMP_2, 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_ChallengingPalaceMaven, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven::
	message BattleFrontier_BattlePalaceBattleRoom_Text_ReadyForPalaceMaven
	waitmessage
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMavenNoRecord
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
	case 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven

BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMavenNoRecord::
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven

BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser::
	call BattleFrontier_EventScript_SetBrainObjectGfx
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_AnnounceArrivalOfSpenser, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
	setobjectxyperm LOCALID_OPPONENT, 15, 1
	addobject LOCALID_OPPONENT
	hideobjectat LOCALID_OPPONENT, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
	setobjectxy LOCALID_OPPONENT, 13, 1
	setobjectxyperm LOCALID_OPPONENT, 13, 1
	applymovement LOCALID_DUSCLOPS, BattleFrontier_BattlePalaceBattleRoom_Movement_DusclopsEnter
	applymovement LOCALID_AZURILL, BattleFrontier_BattlePalaceBattleRoom_Movement_AzurillEnter
	applymovement LOCALID_OPPONENT, BattleFrontier_BattlePalaceBattleRoom_Movement_SpenserEnter
	waitmovement 0
	switch VAR_TEMP_F
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePalaceBattleRoom_EventScript_IntroSpenserGold
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserSilver
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserGold
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserSilver
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserFirstIntro, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserSilver::
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_ProveYourBondWithMons, MSGBOX_DEFAULT
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserSilver
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost

BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserSilver::
	palace_incrementstreak
	frontier_getsymbols
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserPostSilverBattle, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_LetsSeeFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePalaceBattleRoom_Text_ReceivedSpiritsSymbol
	waitmessage
	waitfanfare
	frontier_givesymbol
	applymovement LOCALID_OPPONENT, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserAwaitNextTime, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon

BattleFrontier_BattlePalaceBattleRoom_EventScript_IntroSpenserGold::
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserGold
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserThisTimeWontHoldBack, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserGold::
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_Kaaah, MSGBOX_DEFAULT
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserGold
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost

BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserGold::
	palace_incrementstreak
	frontier_getsymbols
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserYourTeamIsAdmirable, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_HurryWithFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePalaceBattleRoom_Text_SpiritsSymbolTookGoldenShine
	waitmessage
	waitfanfare
	frontier_givesymbol
	applymovement LOCALID_OPPONENT, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserComeSeeMeAgain, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon

BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle::
	closemessage
	setvar VAR_TEMP_2, 0
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_BATTLE_PALACE
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	frontier_restorehelditems
	special HealPlayerParty
	frontier_resetsketch
	return

BattleFrontier_BattlePalaceBattleRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_SetUpRoomObjects
	.2byte 0

BattleFrontier_BattlePalaceBattleRoom_EventScript_SetUpRoomObjects::
	hideobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx
	setvar VAR_TEMP_1, 1
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
	removeobject LOCALID_OPPONENT
	applymovement LOCALID_DUSCLOPS, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
	applymovement LOCALID_AZURILL, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor2ndOpponent
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor3rdOpponent
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor4thOpponent::
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor4thOpponent
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor5thOpponent::
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor5thOpponent
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor6thOpponent::
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor6thOpponent
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor7thOpponent::
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor7thOpponent
	waitmessage
	return

BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible:
	set_invisible
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerEnterRoom:
	set_visible
	walk_up
	walk_up
	walk_up
	walk_up
BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight:
	face_right
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp:
	face_up
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerReturnToChallenge:
	set_visible
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentExit:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown:
	face_down
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter1:
	set_visible
	walk_slow_down
	walk_slow_down
	face_left
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter2:
	set_visible
	walk_slow_down
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter3:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	face_left
	step_end

BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby::
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
	goto_if_eq VAR_RESULT, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyDoubles
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 5, 7
	waitstate
	end

BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyDoubles::
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 19, 7
	waitstate
	end

BattleFrontier_BattlePalaceBattleRoom_Movement_DusclopsEnter:
	delay_16
	delay_16
	set_visible
	walk_down
	walk_right
	walk_down
	walk_in_place_faster_left
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_AzurillEnter:
	set_visible
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_in_place_faster_left
	delay_16
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_SpenserEnter:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	set_visible
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	face_left
	step_end

BattleFrontier_BattlePalaceBattleRoom_Text_LetMeRestoreYourMons:
	.ifdef ENGLISH
	.string "Excellent…\n"
	.string "Let me restore your POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Ausgezeichnet! … Deine\n"
	.string "POKéMON sind gleich wieder topfit.$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor2ndOpponent:
	.ifdef ENGLISH
	.string "The 2nd opponent is next.\n"
	.string "Are you prepared?$"
	.else
	.ifdef GERMAN
	.string "Der zweite Gegner wartet schon.\n"
	.string "Bist du bereit?$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor3rdOpponent:
	.ifdef ENGLISH
	.string "The 3rd opponent is next.\n"
	.string "Are you prepared?$"
	.else
	.ifdef GERMAN
	.string "Der dritte Gegner wartet schon.\n"
	.string "Bist du bereit?$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor4thOpponent:
	.ifdef ENGLISH
	.string "The 4th opponent is next.\n"
	.string "Are you prepared?$"
	.else
	.ifdef GERMAN
	.string "Der vierte Gegner wartet schon.\n"
	.string "Bist du bereit?$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor5thOpponent:
	.ifdef ENGLISH
	.string "The 5th opponent is next.\n"
	.string "Are you prepared?$"
	.else
	.ifdef GERMAN
	.string "Der fünfte Gegner wartet schon.\n"
	.string "Bist du bereit?$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor6thOpponent:
	.ifdef ENGLISH
	.string "The 6th opponent is next.\n"
	.string "Are you prepared?$"
	.else
	.ifdef GERMAN
	.string "Der sechste Gegner wartet schon.\n"
	.string "Bist du bereit?$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor7thOpponent:
	.ifdef ENGLISH
	.string "The 7th opponent is next.\n"
	.string "Are you prepared?$"
	.else
	.ifdef GERMAN
	.string "Der siebte Gegner wartet schon.\n"
	.string "Bist du bereit?$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_SaveAndQuitGame:
	.ifdef ENGLISH
	.string "Would you like to save and quit\n"
	.string "the game?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du das Spiel speichern und\n"
	.string "beenden?$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_WishToQuitChallenge:
	.ifdef ENGLISH
	.string "Do you wish to quit your challenge?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du die Herausforderung\n"
	.string "abbrechen?$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_SavingData:
	.ifdef ENGLISH
	.string "Saving the data.\n"
	.string "Have patience…$"
	.else
	.ifdef GERMAN
	.string "Daten werden gespeichert.\n"
	.string "Einen Moment bitte…$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_RecordLastMatch:
	.ifdef ENGLISH
	.string "Do you wish to record your latest\n"
	.string "match on your FRONTIER PASS?$"
	.else
	.ifdef GERMAN
	.string "Soll der letzte Kampf in deinen\n"
	.string "KAMPFZONENPASS eingetragen werden?$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_ChallengingPalaceMaven:
	.ifdef ENGLISH
	.string "And now…\p"
	.string "By winning consistently, you have\n"
	.string "earned the privilege of challenging\l"
	.string "our master, the PALACE MAVEN…$"
	.else
	.ifdef GERMAN
	.string "Und nun…\p"
	.string "Durch deine vielen Siege in Folge hast\n"
	.string "du nun die Ehre, gegen unseren Meister,\l"
	.string "PALASTREGENT, antreten zu dürfen…$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_ReadyForPalaceMaven:
	.ifdef ENGLISH
	.string "I shall send for the PALACE MAVEN.\n"
	.string "Are you ready?$"
	.else
	.ifdef GERMAN
	.string "Ich werde den PALASTREGENTen rufen.\n"
	.string "Bist du bereit?$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_AnnounceArrivalOfSpenser:
	.ifdef ENGLISH
	.string "Let great fanfare announce the arrival\n"
	.string "of the PALACE MAVEN, SPENSER!$"
	.else
	.ifdef GERMAN
	.string "Begrüßen wir ihn mit Fanfarenklängen.\n"
	.string "Den PALASTREGENTen SERENUS!$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_SpenserFirstIntro:
	.ifdef ENGLISH
	.string "SPENSER: My physical being is with\n"
	.string "POKéMON always!\p"
	.string "My heart beats as one with\n"
	.string "POKéMON always!\p"
	.string "Young one of a TRAINER!\n"
	.string "Do you believe in your POKéMON?\p"
	.string "Can you believe them through\n"
	.string "and through?\p"
	.string "If your bonds of trust are frail,\n"
	.string "you will never beat my brethren!$"
	.else
	.ifdef GERMAN
	.string "SERENUS: Mein Leben dreht sich um meine\n"
	.string "POKéMON. Immer und ausschließlich!\p"
	.string "Unsere Herzen schlagen im gleichen\n"
	.string "Takt!\p"
	.string "Junger TRAINER!\n"
	.string "Glaubst du an deine POKéMON?\p"
	.string "Kannst du aus tiefstem Herzen und\n"
	.string "voller Überzeugung an sie glauben?\p"
	.string "Ist euer Band schwach, wirst du mich\n"
	.string "und meine Gefährten niemals besiegen!$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_ProveYourBondWithMons:
	.ifdef ENGLISH
	.string "The bond you share with your POKéMON!\n"
	.string "Prove it to me here!$"
	.else
	.ifdef GERMAN
	.string "Zeig mir, wie stark euer Band ist!\n"
	.string "Zeig es mir hier und jetzt!$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_SpenserPostSilverBattle:
	.ifdef ENGLISH
	.string "SPENSER: Gwahahah!\p"
	.string "Hah, you never fell for my bluster!\n"
	.string "Sorry for trying that stunt!\p"
	.string "Here!\n"
	.string "Bring me the thing!$"
	.else
	.ifdef GERMAN
	.string "SERENUS: Uahahahaha!\p"
	.string "Du hast dich von meinen Worten niemals\n"
	.string "einschüchtern lassen! Tut mir Leid,\p"
	.string "dass ich das versucht habe! Komm!\n"
	.string "Ich zeichne dich aus!$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_LetsSeeFrontierPass:
	.ifdef ENGLISH
	.string "My, my, if only you could maintain that\n"
	.string "facade of distinguished authority…\p"
	.string "Here!\n"
	.string "Let's see your FRONTIER PASS!$"
	.else
	.ifdef GERMAN
	.string "Ach je, wenn es mir nur gelänge, den\n"
	.string "Anschein von Autorität zu wahren…\p"
	.string "Komm!\n"
	.string "Zeig mir deinen KAMPFZONENPASS!$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_ReceivedSpiritsSymbol:
	.ifdef ENGLISH
	.string "The Spirits Symbol was embossed on\n"
	.string "the FRONTIER PASS!$"
	.else
	.ifdef GERMAN
	.string "Das SEELENSYMBOL wurde dem\n"
	.string "KAMPFZONENPASS hinzugefügt!$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_SpenserAwaitNextTime:
	.ifdef ENGLISH
	.string "SPENSER: Your POKéMON's eyes are \n"
	.string "truly clear and unclouded.\p"
	.string "I will eagerly await the next\n"
	.string "opportunity to see you.$"
	.else
	.ifdef GERMAN
	.string "SERENUS: Die Augen deiner POKéMON sind\n"
	.string "klar und offen!\p"
	.string "Ich freue mich schon auf unsere\n"
	.string "nächste Begegnung!$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_SpenserThisTimeWontHoldBack:
	.ifdef ENGLISH
	.string "SPENSER: Gwahahah!\n"
	.string "You've battled your way up again?\p"
	.string "You must have developed a truly\n"
	.string "formidable bond with your POKéMON.\p"
	.string "So be it!\p"
	.string "This time, I won't bluster or hold back.\n"
	.string "This time, there's no fooling around.\p"
	.string "Ready now?\n"
	.string "Prepare to lose!$"
	.else
	.ifdef GERMAN
	.string "SERENUS: Uahahahaha! Du hast\n"
	.string "dich bis hierher durchgekämpft?\p"
	.string "Dich muss ein wahrhaft starkes Band\n"
	.string "mit deinen POKéMON verbinden!\p"
	.string "Also gut!\p"
	.string "Dieses Mal werde ich dich nicht ein-\n"
	.string "schüchtern, mich aber auch nicht\p"
	.string "zurückhalten! Kein Spielchen, sondern\n"
	.string "ein wahrer Kampf erwartet dich!\p"
	.string "Bist du bereit?\n"
	.string "Deine Niederlage wartet auf dich!$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_Kaaah:
	.ifdef ENGLISH
	.string "… … …Kaaah!$"
	.else
	.ifdef GERMAN
	.string "… … … … Kyaaaiii!$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_SpenserYourTeamIsAdmirable:
	.ifdef ENGLISH
	.string "SPENSER: Well, that was some display!\n"
	.string "Even fully unleashed, my brethren\l"
	.string "could not overpower you.\p"
	.string "Your team spirit is truly admirable!\p"
	.string "Here!\n"
	.string "Bring me that thing, will you?$"
	.else
	.ifdef GERMAN
	.string "SERENUS: Nun, das war doch mal eine\n"
	.string "gelungene Vorstellung! Meine Gefährten\l"
	.string "konnten dich nicht unterbuttern.\p"
	.string "Euer Teamgeist ist wirklich\n"
	.string "anbetungswürdig!\p"
	.string "Komm!\n"
	.string "Gib schon her!$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_HurryWithFrontierPass:
	.ifdef ENGLISH
	.string "My, my, if only you could maintain\n"
	.string "a certain level of decorum…\p"
	.string "Gaaah, here!\n"
	.string "Hurry with that FRONTIER PASS, you!$"
	.else
	.ifdef GERMAN
	.string "Ach je, hätte ich doch nur ein bisschen\n"
	.string "Anstand…\p"
	.string "Uahahaha! Komm!\n"
	.string "Gib mir den KAMPFZONENPASS!$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_SpiritsSymbolTookGoldenShine:
	.ifdef ENGLISH
	.string "The Spirits Symbol took on\n"
	.string "a golden shine!$"
	.else
	.ifdef GERMAN
	.string "Das SEELENSYMBOL erscheint\n"
	.string "in einem goldenen Glanz!$"
	.endif
	.endif

BattleFrontier_BattlePalaceBattleRoom_Text_SpenserComeSeeMeAgain:
	.ifdef ENGLISH
	.string "SPENSER: Gwahahah!\p"
	.string "Come see me time and again!\n"
	.string "My brethren and I will be waiting!$"
	.else
	.ifdef GERMAN
	.string "SERENUS: Uahahahaha!\p"
	.string "Komm ruhig mal wieder her! Meine\n"
	.string "Gefährten und ich warten auf dich.$"
	.endif
	.endif
