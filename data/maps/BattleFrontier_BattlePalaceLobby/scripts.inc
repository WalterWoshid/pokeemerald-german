.set LOCALID_ATTENDANT_SINGLES, 1
.set LOCALID_ATTENDANT_DOUBLES, 6

BattleFrontier_BattlePalaceLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_OnWarp
	.byte 0

BattleFrontier_BattlePalaceLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePalaceLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge, MSGBOX_DEFAULT
	closemessage
	palace_set PALACE_DATA_WIN_STREAK, 0
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven
	msgbox BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded
	waitmessage
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	palace_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
	waitmessage
	palace_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_Attendant::
	palace_get PALACE_DATA_PRIZE
	goto_if_ne VAR_RESULT, ITEM_NONE, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_WhichChallenge
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	palace_init
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePalaceLobby_Text_FollowMe, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge::
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor
	waitdooranim
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_SINGLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_DOUBLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor::
	opendoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor::
	opendoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor::
	closedoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor::
	closedoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor:
	walk_up
	step_end

BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt::
	msgbox BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Man::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Maniac::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_RulesNature
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesNature::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle:
	.ifdef ENGLISH
	.string "Where the hearts of TRAINERS\n"
	.string "are put to the test.\p"
	.string "I welcome you to the BATTLE PALACE.\p"
	.string "I accept challenges to the SINGLE\n"
	.string "BATTLE HALLS.$"
	.else
	.ifdef GERMAN
	.string "Hier wird das Herz der TRAINER\n"
	.string "auf die Probe gestellt!\p"
	.string "Willkommen im KAMPFPALAST!\p"
	.string "Ich nehme Herausforderungen für die\n"
	.string "EINZELKAMPF-Hallen entgegen!$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge:
	.ifdef ENGLISH
	.string "Do you wish to take\n"
	.string "the SINGLE BATTLE HALL challenge?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du dich der Herausforderung\n"
	.string "der EINZELKAMPF-Hallen stellen?$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge:
	.ifdef ENGLISH
	.string "In the BATTLE PALACE, there are\n"
	.string "several auditoriums for SINGLE BATTLES\l"
	.string "that are named SINGLE BATTLE HALLS.\p"
	.string "The SINGLE BATTLES are conducted in\n"
	.string "the usual way, except with one crucial\l"
	.string "rule that must be obeyed.\p"
	.string "TRAINERS are permitted only to switch\n"
	.string "their POKéMON in and out.\p"
	.string "TRAINERS are otherwise forbidden to\n"
	.string "command their POKéMON.\p"
	.string "The POKéMON are to behave according\n"
	.string "to their nature and battle on their own.\p"
	.string "You must put your trust in your\n"
	.string "POKéMON and watch over them.\p"
	.string "If you achieve the honor of beating\n"
	.string "seven TRAINERS in succession,\l"
	.string "we will present you with Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, you must save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"
	.else
	.ifdef GERMAN
	.string "Im KAMPFPALAST gibt es verschiedene\n"
	.string "EINZELKAMPF-Hallen für\l"
	.string "EINZELKÄMPFE.\p"
	.string "Die EINZELKÄMPFE verlaufen auf die\n"
	.string "übliche Weise. Es gibt eine entschei-\l"
	.string "dende Regel, die es zu beachten gilt!!!\p"
	.string "TRAINER dürfen ihre POKéMON lediglich\n"
	.string "in den Kampf rufen und zurückziehen.\p"
	.string "Ansonsten dürfen sie ihren POKéMON\n"
	.string "keinerlei Anweisungen geben!\p"
	.string "Die POKéMON sollen sich ihrem Wesen\n"
	.string "entsprechend verhalten und eigen-\p"
	.string "ständig kämpfen! Vertrau deinen\n"
	.string "POKéMON und achte auf sie.\p"
	.string "Schaffst du es, sieben TRAINER in Folge\n"
	.string "zu besiegen, erhältst du von uns\l"
	.string "Gewinnpunkte.\p"
	.string "Willst du die Herausforderung ab-\n"
	.string "brechen, musst du dein Spiel speichern.\p"
	.string "Andernfalls wirst du bei Abbruch\n"
	.string "disqualifiziert.$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified:
	.ifdef ENGLISH
	.string "When you have fortified your heart\n"
	.string "and POKéMON, you must return.$"
	.else
	.ifdef GERMAN
	.string "Stärke dein Herz und deine POKéMON und\n"
	.string "komm dann wieder.$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_WhichChallenge:
	.ifdef ENGLISH
	.string "There are two BATTLE HALLS,\n"
	.string "Level 50 and Open Level.\l"
	.string "Which is your choice of a challenge?$"
	.else
	.ifdef GERMAN
	.string "Es gibt zwei KAMPFHALLEN:\n"
	.string "Für Level 50 und Offene Kämpfe.\l"
	.string "Wofür entscheidest du dich?$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50:
	.ifdef ENGLISH
	.string "Sigh…\p"
	.string "You do not have the three POKéMON\n"
	.string "required for the challenge.\p"
	.string "To enter, you must provide three\n"
	.string "different kinds of POKéMON.\p"
	.string "These POKéMON must all be of\n"
	.string "Level 50 or lower.\p"
	.string "They also must not be holding\n"
	.string "the same kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Come back when you have made\n"
	.string "your preparations.$"
	.else
	.ifdef GERMAN
	.string "Entschuldigung!\p"
	.string "Aber deine POKéMON sind nicht\n"
	.string "teilnahmeberechtigt.\p"
	.string "Du brauchst drei verschiedene\n"
	.string "POKéMON von Level 50 oder weniger.\p"
	.string "Jedes muss außerdem ein anderes Item\n"
	.string "halten.\p"
	.string "EIer{STR_VAR_1} nicht zugelassen.\p"
	.string "Bitte komm wieder, wenn du bereit bist.$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen:
	.ifdef ENGLISH
	.string "Sigh…\p"
	.string "You do not have the three POKéMON\n"
	.string "required for the challenge.\p"
	.string "To enter, you must provide three\n"
	.string "different kinds of POKéMON.\p"
	.string "They also must not be holding\n"
	.string "the same kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Come back when you have made\n"
	.string "your preparations.$"
	.else
	.ifdef GERMAN
	.string "Entschuldigung!\p"
	.string "Aber deine POKéMON sind nicht\n"
	.string "teilnahmeberechtigt.\p"
	.string "Du brauchst drei verschiedene\n"
	.string "POKéMON.\p"
	.string "Jedes muss außerdem ein anderes Item\n"
	.string "halten.\p"
	.string "EIer{STR_VAR_1} nicht zugelassen.\p"
	.string "Bitte komm wieder, wenn du bereit bist.$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons:
	.ifdef ENGLISH
	.string "Good. Now, you must select your\n"
	.string "three POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Gut. Nun wähle deine drei POKéMON aus.$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2:
	.ifdef ENGLISH
	.string "I must save before I show you to\n"
	.string "the BATTLE HALL. Is that okay?$"
	.else
	.ifdef GERMAN
	.string "Bevor du die KAMPFHALLE betrittst,\n"
	.string "musst du dein Spiel speichern. Okay?$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_FollowMe:
	.ifdef ENGLISH
	.string "Good.\n"
	.string "Now, follow me.$"
	.else
	.ifdef GERMAN
	.string "Gut. Dann folge mir.$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded:
	.ifdef ENGLISH
	.string "I feel privileged for having seen\n"
	.string "your POKéMON's exploits.\p"
	.string "The results will be recorded.\n"
	.string "I must ask you to briefly wait.$"
	.else
	.ifdef GERMAN
	.string "Ich fühle mich geehrt, dass ich deine\n"
	.string "POKéMON sehen durfte.\p"
	.string "Dein Erfolg wird gespeichert.\n"
	.string "Bitte warte einen Moment.$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak:
	.ifdef ENGLISH
	.string "To achieve a 7-win streak…\p"
	.string "The bonds that bind your heart with\n"
	.string "your POKéMON seem firm and true.$"
	.else
	.ifdef GERMAN
	.string "Sieben Siege in Folge…\p"
	.string "Das Band zwischen deinem Herzen und\n"
	.string "deinen POKéMON scheint stark zu sein.$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded:
	.ifdef ENGLISH
	.string "Your feat will be recorded.\n"
	.string "I must ask you to briefly wait.$"
	.else
	.ifdef GERMAN
	.string "Dein Erfolg wird gespeichert.\n"
	.string "Bitte warte einen Moment.$"
	.endif
	.endif

@ Unused
BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak:
	.ifdef ENGLISH
	.string "For the feat of your 7-win streak,\n"
	.string "we present you with Battle Point(s).$"
	.else
	.ifdef GERMAN
	.string "For the feat of your 7-win streak,\n"
	.string "we present you with Battle Point(s).$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize:
	.ifdef ENGLISH
	.string "You seem to have no space for\n"
	.string "our prize.\p"
	.string "You should return when you have\n"
	.string "organized your BAG.$"
	.else
	.ifdef GERMAN
	.string "Du hast keinen Platz für den Preis?\p"
	.string "Räum deinen BEUTEL auf und komm\n"
	.string "dann wieder.$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting:
	.ifdef ENGLISH
	.string "We have been waiting for you…$"
	.else
	.ifdef GERMAN
	.string "Wir haben auf dich gewartet…$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge:
	.ifdef ENGLISH
	.string "I must save before I show you to\n"
	.string "the BATTLE HALL. Is that okay?$"
	.else
	.ifdef GERMAN
	.string "Bevor du die KAMPFHALLE betrittst,\n"
	.string "musst du dein Spiel speichern.$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge:
	.ifdef ENGLISH
	.string "Sigh…\p"
	.string "You failed to save before you ended\n"
	.string "your challenge the last time.\p"
	.string "As a result, your challenge has been\n"
	.string "disqualified. It is most unfortunate.$"
	.else
	.ifdef GERMAN
	.string "Seufz…\p"
	.string "Du hast, bevor du die Herausforderung\n"
	.string "abgebrochen hast, nicht gespeichert.\p"
	.string "Daher wirst du für diese Herausforde-\n"
	.string "rung disqualifiziert. Schade!$"
	.endif
	.endif

@ Unused
BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize:
	.ifdef ENGLISH
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink:
	.ifdef ENGLISH
	.string "For a hardy fellow like me,\n"
	.string "hardy POKéMON are the best.\p"
	.string "Offense is the best defense!\n"
	.string "A relentless attack is the ultimate!\p"
	.string "But that's not what I wanted to chat\n"
	.string "about.\p"
	.string "Every so often a really cute lady\n"
	.string "swings by here.\p"
	.string "She says that she can tell what\n"
	.string "POKéMON are thinking.\p"
	.string "I don't know about that part,\n"
	.string "but she is really cute.\p"
	.string "Huh?\n"
	.string "Why are you looking at me like that?$"
	.else
	.ifdef GERMAN
	.string "Für so einen kräftigen Burschen wie\n"
	.string "mich sind kräftige POKéMON das Wahre!\p"
	.string "Angriff ist die beste Verteidigung!\n"
	.string "Eine rücksichtslose Attacke das Beste!\p"
	.string "Aber darüber wollte ich jetzt\n"
	.string "eigentlich gar nicht reden.\p"
	.string "Manchmal kommt hier eine niedliche\n"
	.string "Lady vorbei.\p"
	.string "Sie sagt, sie kann erkennen, was\n"
	.string "POKéMON denken.\p"
	.string "Ich kenn mich damit nicht aus, aber ich\n"
	.string "weiß, dass die Lady verdammt süß ist.\p"
	.string "Was?!?\n"
	.string "Warum schaust du mich so komisch an?$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere:
	.ifdef ENGLISH
	.string "Hmm…\p"
	.string "It appears that the nature of POKéMON\n"
	.string "and the moves that they have been\l"
	.string "taught are the keys to battle here.\p"
	.string "To be more precise, it's how well\n"
	.string "the moves match the nature of\l"
	.string "the POKéMON.\p"
	.string "If your POKéMON is in trouble and\n"
	.string "unable to live up to its potential,\l"
	.string "you may need to examine how well\l"
	.string "its moves match its nature.$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Das Wesen der POKéMON und die\n"
	.string "Attacken, die sie gelernt haben,\l"
	.string "scheinen der Schlüssel zu sein.\p"
	.string "Um es deutlicher zu machen: Die\n"
	.string "Attacken sollten zum Wesen der\l"
	.string "POKéMON passen.\p"
	.string "Wenn dein POKéMON Schwierigkeiten\n"
	.string "hat und nicht alles gibt, dann solltest\l"
	.string "du prüfen, wie gut seine Attacken zu\l"
	.string "seinem Wesen passen.$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms:
	.ifdef ENGLISH
	.string "My POKéMON is usually very docile.\p"
	.string "But when it's in a BATTLE HALL,\n"
	.string "it sometimes seems to become\l"
	.string "transformed into something wicked!\p"
	.string "It becomes totally intimidating.\n"
	.string "It's shocking, even.$"
	.else
	.ifdef GERMAN
	.string "Mein POKéMON ist sehr sanftmütig.\p"
	.string "Aber wenn ich es in eine KAMPFHALLE\n"
	.string "mitnehme, scheint es sich manchmal\l"
	.string "ganz merkwürdig zu verändern!\p"
	.string "Es wirkt dann regelrecht\n"
	.string "einschüchternd! Richtig schockierend!$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway:
	.ifdef ENGLISH
	.string "I wonder what sort of nature a POKéMON\n"
	.string "would have if it favored enfeebling its\l"
	.string "opponents and chipping away slowly.\p"
	.string "I'd be surprised if it was a LAX nature.\p"
	.string "But, nah, that can't be right.$"
	.else
	.ifdef GERMAN
	.string "Ich frage mich, welches Wesen ein\n"
	.string "POKéMON hat, das seine Gegner schwächt\l"
	.string "und dann langsam zur Strecke bringt.\p"
	.string "Ich würde mich echt wundern, wenn es\n"
	.string "dann ein LASCHes Wesen hätte.\p"
	.string "Nee, bestimmt nicht!$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle:
	.ifdef ENGLISH
	.string "Where the hearts of TRAINERS\n"
	.string "are put to the test.\p"
	.string "I welcome you to the BATTLE PALACE.\p"
	.string "I accept challenges to the DOUBLE\n"
	.string "BATTLE HALLS.$"
	.else
	.ifdef GERMAN
	.string "Hier wird das Herz der TRAINER\n"
	.string "auf die Probe gestellt!\p"
	.string "Willkommen im KAMPFPALAST!\p"
	.string "Ich nehme Herausforderungen für die\n"
	.string "DOPPELKAMPF-Hallen entgegen!$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge:
	.ifdef ENGLISH
	.string "Do you wish to take\n"
	.string "the DOUBLE BATTLE HALL challenge?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du dich der Herausforderung\n"
	.string "der DOPPELKAMPF-Hallen stellen?$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge:
	.ifdef ENGLISH
	.string "In the BATTLE PALACE, there are\n"
	.string "several auditoriums for DOUBLE BATTLES\l"
	.string "that are named DOUBLE BATTLE HALLS.\p"
	.string "The DOUBLE BATTLES are conducted in\n"
	.string "the usual way, except with one crucial\l"
	.string "rule that must be obeyed.\p"
	.string "TRAINERS are permitted only to switch\n"
	.string "their POKéMON in and out.\p"
	.string "TRAINERS are otherwise forbidden to\n"
	.string "command their POKéMON.\p"
	.string "The POKéMON are to behave according\n"
	.string "to their nature and battle on their own.\p"
	.string "You must put your trust in your\n"
	.string "POKéMON and watch over them.\p"
	.string "If you achieve the honor of beating\n"
	.string "seven TRAINERS in succession,\l"
	.string "we will present you with Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"
	.else
	.ifdef GERMAN
	.string "Im KAMPFPALAST gibt es verschiedene\n"
	.string "DOPPELKAMPF-Hallen für\l"
	.string "DOPPELKÄMPFE.\p"
	.string "Die DOPPELKÄMPFE verlaufen auf die\n"
	.string "übliche Weise. Es gibt eine entschei-\l"
	.string "dende Regel, die es zu beachten gilt!!!\p"
	.string "TRAINER dürfen ihre POKéMON lediglich\n"
	.string "in den Kampf rufen und zurückziehen.\p"
	.string "Ansonsten dürfen sie ihren POKéMON\n"
	.string "keinerlei Anweisungen geben!\p"
	.string "Die POKéMON sollen sich ihrem Wesen\n"
	.string "entsprechend verhalten und eigen-\p"
	.string "ständig kämpfen! Vertrau deinen\n"
	.string "POKéMON und achte auf sie.\p"
	.string "Schaffst du es, sieben TRAINER in Folge\n"
	.string "zu besiegen, erhältst du von uns\l"
	.string "Gewinnpunkte.\p"
	.string "Willst du die Herausforderung ab-\n"
	.string "brechen, musst du dein Spiel speichern.\p"
	.string "Andernfalls wirst du bei Abbruch\n"
	.string "disqualifiziert.$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers:
	.ifdef ENGLISH
	.string "To defeat the PALACE MAVEN\n"
	.string "and seven TRAINERS in a row…$"
	.else
	.ifdef GERMAN
	.string "Um den PALASTREGENTen und sechs\n"
	.string "TRAINER in Folge zu besiegen…$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints:
	.ifdef ENGLISH
	.string "In honor of the bond you share with\n"
	.string "your POKéMON, we present you with\l"
	.string "these Battle Point(s).$"
	.else
	.ifdef GERMAN
	.string "In Anerkennung des Bandes zwischen dir\n"
	.string "und deinen POKéMON geben wir dir\l"
	.string "Gewinnpunkte.$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch:
	.ifdef ENGLISH
	.string "Would you like to record your latest\n"
	.string "BATTLE PALACE match on your\l"
	.string "FRONTIER PASS?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du deinen letzten KAMPF-\n"
	.string "PALAST-Kampf in deinen\l"
	.string "KAMPFZONENPASS eintragen?$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_RulesAreListed:
	.ifdef ENGLISH
	.string "The BATTLE HALL rules are listed.$"
	.else
	.ifdef GERMAN
	.string "Die Regeln der KAMPFHALLE hängen\n"
	.string "öffentlich aus.$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading:
	.ifdef ENGLISH
	.string "Which heading do you want to read?$"
	.else
	.ifdef GERMAN
	.string "Wähle bitte ein Themengebiet aus.$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics:
	.ifdef ENGLISH
	.string "Here, POKéMON are required to think\n"
	.string "and battle by themselves.\p"
	.string "Unlike in the wild, POKéMON that live\n"
	.string "with people behave differently\l"
	.string "depending on their nature.$"
	.else
	.ifdef GERMAN
	.string "Hier müssen die POKéMON selbständig\n"
	.string "handeln und kämpfen.\p"
	.string "Anders als wilde POKéMON reagieren\n"
	.string "POKéMON, die mit Menschen zusammen-\l"
	.string "leben, abhängig von ihrem Wesen.$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature:
	.ifdef ENGLISH
	.string "Depending on its nature, a POKéMON\n"
	.string "may prefer to attack no matter what.\p"
	.string "Another POKéMON may prefer to protect\n"
	.string "itself from any harm.\p"
	.string "Yet another may enjoy vexing or\n"
	.string "confounding its foes.\p"
	.string "Due to its nature, a POKéMON\n"
	.string "will have favorite moves that it is good\l"
	.string "at using.\p"
	.string "It may also dislike certain moves that\n"
	.string "it has trouble using.$"
	.else
	.ifdef GERMAN
	.string "Je nach Wesenheit wird ein POKéMON\n"
	.string "eventuell angreifen, egal, was passiert.\p"
	.string "Ein anderes wird sich vielleicht seinem\n"
	.string "Wesen entsprechend unter allen\p"
	.string "Umständen schützen wollen. Ein anderes\n"
	.string "irritiert oder verwirrt seinen Gegner.\p"
	.string "Abhängig von seinem Wesen wird ein\n"
	.string "POKéMON Lieblingsattacken haben, die\l"
	.string "es hervorragend beherrscht.\p"
	.string "Auf der anderen Seite wird es Attacken\n"
	.string "kennen, die es nicht mag und die ihm\l"
	.string "Schwierigkeiten machen.$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves:
	.ifdef ENGLISH
	.string "There are offensive moves that inflict\n"
	.string "direct damage on the foe.\p"
	.string "There are defensive moves that are\n"
	.string "used to prepare for enemy attacks or\l"
	.string "used to heal HP and so on.\p"
	.string "There are also other somewhat-odd\n"
	.string "moves that may enfeeble the foes with\l"
	.string "stat problems including poison and \l"
	.string "paralysis.\p"
	.string "POKéMON will consider using moves in\n"
	.string "these three categories.$"
	.else
	.ifdef GERMAN
	.string "Es gibt offensive Attacken, die dem\n"
	.string "Gegner Schaden zufügen.\p"
	.string "Es gibt defensive Attacken, die auf\n"
	.string "gegnerische Attacken vorbereiten oder\l"
	.string "aber KP wiederherstellen können.\p"
	.string "Und es gibt Attacken, die den Gegner\n"
	.string "schwächen, indem sie Statusprobleme\l"
	.string "verursachen, wie Vergiftungen oder\l"
	.string "Paralyse.\p"
	.string "POKéMON werden diese 3 Kategorien mit\n"
	.string "Sicherheit im Kampf in Betracht ziehen!$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered:
	.ifdef ENGLISH
	.string "When not under command by its TRAINER,\n"
	.string "a POKéMON may be unable to effectively\l"
	.string "use certain moves.\p"
	.string "A POKéMON is not good at using any\n"
	.string "move that it dislikes.\p"
	.string "If a POKéMON only knows moves that\n"
	.string "do not match its nature, it will often\l"
	.string "be unable to live up to its potential.$"
	.else
	.ifdef GERMAN
	.string "Gibt ein TRAINER seinem POKéMON keine\n"
	.string "Anweisungen, wird es vielleicht nicht in\l"
	.string "der Lage sein, bestimmte Attacken\p"
	.string "einzusetzen. Ein POKéMON hat\n"
	.string "Schwierigkeiten mit Attacken, die es\l"
	.string "nicht mag.\p"
	.string "Kennt ein POKéMON nur Attacken, die\n"
	.string "seinem Wesen widersprechen, so kann es\l"
	.string "nicht immer sein ganzes Können zeigen.$"
	.endif
	.endif

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger:
	.ifdef ENGLISH
	.string "Depending on its nature, a POKéMON may\n"
	.string "start using moves that don't match its\l"
	.string "nature when it is in trouble.\p"
	.string "If a POKéMON begins behaving oddly\n"
	.string "in a pinch, watch it carefully.$"
	.else
	.ifdef GERMAN
	.string "Abhängig von seinem Wesen, wird ein\n"
	.string "POKéMON vielleicht auch Attacken ein-\l"
	.string "setzen, die seinem Wesen widersprechen.\p"
	.string "Benimmt es sich in bestimmten\n"
	.string "Situationen merkwürdig, beobachte es\l"
	.string "genau.$"
	.endif
	.endif

