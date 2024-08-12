.set LOCALID_ATTENDANT, 1

BattleFrontier_BattleArenaLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge

BattleFrontier_BattleArenaLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 9, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena:
	.ifdef ENGLISH
	.string "Where the battling spirit of TRAINERS\n"
	.string "is put to the test!\p"
	.string "I welcome you to the BATTLE ARENA!\p"
	.string "I am your guide to the Set KO Tourney!$"
	.else
	.ifdef GERMAN
	.string "Hier wird der Kampfgeist der TRAINER\n"
	.string "auf die Probe gestellt!\p"
	.string "Willkommen im KAMPFRING!\p"
	.string "Ich begleite dich beim K.O.-Teamturnier!$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
	.ifdef ENGLISH
	.string "Now, do you wish to take\n"
	.string "the BATTLE ARENA challenge?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du dich der Herausforderung\n"
	.string "des KAMPFRINGs stellen?$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
	.ifdef ENGLISH
	.string "We await your challenge on\n"
	.string "another occasion!$"
	.else
	.ifdef GERMAN
	.string "Wir freuen uns auf deine nächste\n"
	.string "Herausforderung.$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
	.ifdef ENGLISH
	.string "In the BATTLE ARENA, we undertake\n"
	.string "the Set KO Tourney.\p"
	.string "All participants enter with a team of\n"
	.string "three POKéMON.\p"
	.string "The three POKéMON must be lined up in\n"
	.string "the order in which they are to appear.\p"
	.string "During battle, the POKéMON will appear\n"
	.string "one at a time in the preset order.\p"
	.string "Once a POKéMON enters battle, it must\n"
	.string "remain out until the match is decided.\p"
	.string "If a match remains undecided in\n"
	.string "three turns, it goes to judging.\p"
	.string "If you wish to interrupt your challenge,\n"
	.string "please save the game.\p"
	.string "If you don't save, you will not be able\n"
	.string "to continue with your challenge.\p"
	.string "If you pull off the feat of beating\n"
	.string "seven TRAINERS in succession,\l"
	.string "we will present you with Battle Points.$"
	.else
	.ifdef GERMAN
	.string "Im KAMPFRING fechten\n"
	.string "wir K.O.-Teamturniere aus.\p"
	.string "Jeder Teilnehmer nimmt drei POKéMON\n"
	.string "mit in den Wettkampf.\p"
	.string "Die POKéMON müssen in der Reihenfolge\n"
	.string "platziert werden, in der sie kämpfen\p"
	.string "sollen. In dieser Folge kämpfen sie dann\n"
	.string "nacheinander.\p"
	.string "Sobald ein POKéMON in den Kampf\n"
	.string "gerufen wurde, muss es kämpfen, bis der\p"
	.string "Kampf entschieden ist. Sollte ein Kampf\n"
	.string "unentschieden enden, wird der Kampf\p"
	.string "beurteilt und der Sieger bestimmt.\n"
	.string "Möchtest du den Wettkampf unter-\p"
	.string "brechen, speichere bitte dein Spiel.\n"
	.string "Ohne Speichern kannst du den Wett-\p"
	.string "kampf später nicht fortsetzen.\p"
	.string "Besiegst du sieben TRAINER in Folge,\n"
	.string "erhältst du Gewinnpunkte.$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_OkayToSave:
	.ifdef ENGLISH
	.string "Before showing you to the BATTLE\n"
	.string "ARENA, you must save. Is that okay?$"
	.else
	.ifdef GERMAN
	.string "Bevor du den KAMPFRING betrittst,\n"
	.string "musst du dein Spiel speichern. Okay?$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
	.ifdef ENGLISH
	.string "The BATTLE ARENA offers two levels\n"
	.string "of challenge, Level 50 and Open Level.\l"
	.string "Which is your choice?$"
	.else
	.ifdef GERMAN
	.string "Im KAMPFRING wird in zwei\n"
	.string "Kategorien gekämpft: Lv. 50 und Offene\l"
	.string "Kämpfe. Wofür entscheidest du dich?$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
	.ifdef ENGLISH
	.string "Very well, now select your\n"
	.string "three POKéMON, please.$"
	.else
	.ifdef GERMAN
	.string "Bitte wähle drei POKéMON aus, die\n"
	.string "antreten sollen.$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
	.ifdef ENGLISH
	.string "My dear challenger!\p"
	.string "You do not have the three POKéMON\n"
	.string "required for entry.\p"
	.string "To qualify, you must bring three\n"
	.string "different kinds of POKéMON.\p"
	.string "They also must not hold the same\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "When you have made your preparations,\n"
	.string "please do return.$"
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

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
	.ifdef ENGLISH
	.string "My dear challenger!\p"
	.string "You do not have the three POKéMON\n"
	.string "required for entry.\p"
	.string "To qualify, you must bring three\n"
	.string "different kinds of POKéMON.\p"
	.string "The three different POKéMON\n"
	.string "must all be Level 50 or lower.\p"
	.string "They also must not hold the same\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "When you have made your preparations,\n"
	.string "please do return.$"
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

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
	.ifdef ENGLISH
	.string "I shall now guide you to\n"
	.string "the BATTLE ARENA.$"
	.else
	.ifdef GERMAN
	.string "Ich werde dich nun in den KAMPFRING\n"
	.string "begleiten.$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
	.ifdef ENGLISH
	.string "My dear challenger!\p"
	.string "You did not save the game before\n"
	.string "shutting down, did you?\p"
	.string "It is unfortunate, but that has\n"
	.string "resulted in your disqualification\l"
	.string "from your challenge.\p"
	.string "You may, of course, start with a fresh\n"
	.string "challenge.$"
	.else
	.ifdef GERMAN
	.string "Entschuldigung!\p"
	.string "Du hast, bevor du die Herausforderung\n"
	.string "abgebrochen hast, nicht gespeichert.\p"
	.string "Daher wirst du für diese Herausforde-\n"
	.string "rung disqualifiziert. Schade! Du hast\p"
	.string "natürlich die Möglichkeit, dich einer\n"
	.string "neuen Herausforderung zu stellen.$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
	.ifdef ENGLISH
	.string "We congratulate you for your splendid\n"
	.string "string of wins over seven TRAINERS!$"
	.else
	.ifdef GERMAN
	.string "Herzlichen Glückwunsch! Du hast sieben\n"
	.string "TRAINER in Folge besiegt!$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
	.ifdef ENGLISH
	.string "Your achievement will be recorded.\n"
	.string "Please wait while I save the game.$"
	.else
	.ifdef GERMAN
	.string "Dein Erfolg wird gespeichert.\n"
	.string "Bitte warten.$"
	.endif
	.endif

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
	.ifdef ENGLISH
	.string "In commemoration of your 7-win streak,\n"
	.string "we present you with this prize.$"
	.else
	.ifdef GERMAN
	.string "In commemoration of your 7-win streak,\n"
	.string "we present you with this prize.$"
	.endif
	.endif

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
	.ifdef ENGLISH
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"
	.endif
	.endif

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
	.ifdef ENGLISH
	.string "Oh?\n"
	.string "Your BAG seems to be full.\p"
	.string "I urge you to clear space and\n"
	.string "return for your prize.$"
	.else
	.ifdef GERMAN
	.string "Oh?\n"
	.string "Your BAG seems to be full.\p"
	.string "I urge you to clear space and\n"
	.string "return for your prize.$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
	.ifdef ENGLISH
	.string "Thank you so much for participating!\p"
	.string "Please wait while I save the game.$"
	.else
	.ifdef GERMAN
	.string "Vielen Dank für die Teilnahme!\p"
	.string "Das Spiel wird gespeichert.\n"
	.string "Bitte warten.$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
	.ifdef ENGLISH
	.string "We await your challenge on\n"
	.string "another occasion!$"
	.else
	.ifdef GERMAN
	.string "Wir freuen uns auf deine nächste\n"
	.string "Herausforderung.$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
	.ifdef ENGLISH
	.string "We have been looking forward to\n"
	.string "your arrival.\p"
	.string "Before I show you to the BATTLE\n"
	.string "ARENA, I must save the game.\l"
	.string "Please wait.$"
	.else
	.ifdef GERMAN
	.string "Wir haben schon auf dich gewartet!\p"
	.string "Bevor du den KAMPFRING betrittst,\n"
	.string "musst du dein Spiel speichern. Okay?$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
	.ifdef ENGLISH
	.string "Shall I record your last BATTLE ARENA\n"
	.string "match on your FRONTIER PASS?$"
	.else
	.ifdef GERMAN
	.string "Soll ich den KAMPFRING-Kampf\n"
	.string "in deinen KAMPFZONENPASS eintragen?$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
	.ifdef ENGLISH
	.string "I lost on the REFEREE's decision…\p"
	.string "I don't think it was a good idea to only\n"
	.string "use defensive moves and not attack…$"
	.else
	.ifdef GERMAN
	.string "Ich habe aufgrund der REFEREE-\n"
	.string "Entscheidung verloren…\p"
	.string "Ich hätte nicht nur defensive Attacken\n"
	.string "verwenden dürfen, sondern auch\p"
	.string "angreifen müssen.$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
	.ifdef ENGLISH
	.string "I won in judging!\p"
	.string "Landing hits consistently on\n"
	.string "the opponent's POKéMON worked!$"
	.else
	.ifdef GERMAN
	.string "Ich habe durch die richtige\n"
	.string "Entscheidung des REFEREEs gewonnen!\p"
	.string "Kontinuierliche Treffer auf das gegne-\n"
	.string "rische POKéMON haben sich ausgezahlt.$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
	.ifdef ENGLISH
	.string "Our match was declared a draw.\p"
	.string "When we ran out of time, both my\n"
	.string "POKéMON and the opponent's had about\l"
	.string "the same amount of HP left.$"
	.else
	.ifdef GERMAN
	.string "Unser Kampf wurde als Unentschieden\n"
	.string "gewertet.\p"
	.string "Als die Zeit abgelaufen war, hatten\n"
	.string "meine und die gegnerischen POKéMON\l"
	.string "die gleiche Anzahl KP übrig.$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
	.ifdef ENGLISH
	.string "In the BATTLE ARENA, the order of\n"
	.string "POKéMON is totally important.\p"
	.string "For example, if your first POKéMON\n"
	.string "has certain type disadvantages,\l"
	.string "try making your second POKéMON one\l"
	.string "with moves that are super effective\l"
	.string "against the first one.\p"
	.string "I think that will be a good way of\n"
	.string "making an effective team.$"
	.else
	.ifdef GERMAN
	.string "Im KAMPFRING ist die Reihenfolge\n"
	.string "der POKéMON entscheidend.\p"
	.string "Hat dein erstes POKéMON bestimmte\n"
	.string "Nachteile aufgrund seiner Element-\l"
	.string "klasse, sollte dein zweites POKéMON\l"
	.string "diese Nachteile ausgleichen.\p"
	.string "Ich denke, so stellt man ein hervor-\n"
	.string "ragendes Team zusammen.$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
	.ifdef ENGLISH
	.string "The Set KO Tourney's rules are listed.$"
	.else
	.ifdef GERMAN
	.string "Die K.O.-Teamturnier-Regeln sind hier\n"
	.string "aufgeführt.$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
	.ifdef ENGLISH
	.string "Which heading do you want to read?$"
	.else
	.ifdef GERMAN
	.string "Wähle bitte ein Themengebiet aus.$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
	.ifdef ENGLISH
	.string "The Set KO Tourney has special rules,\n"
	.string "unlike standard battles.\p"
	.string "First, one battle lasts only\n"
	.string "three turns.\p"
	.string "If the outcome is not decided after\n"
	.string "three turns, it goes to judging.\p"
	.string "The REFEREE will choose the winner\n"
	.string "based on how the POKéMON battled.\p"
	.string "Also, a POKéMON cannot be switched out\n"
	.string "until its battle's outcome is decided.$"
	.else
	.ifdef GERMAN
	.string "Das K.O.-Teamturnier hat bestimmte\n"
	.string "Regeln, die du beachten musst.\p"
	.string "Erstens: Ein Kampf dauert drei Runden.\n"
	.string "Wenn nach drei Runden kein Sieger\p"
	.string "feststeht, wird eine richterliche\n"
	.string "Entscheidung getroffen. Der REFEREE\p"
	.string "wird den Sieger bestimmen, indem er\n"
	.string "die Art des Kampfes beurteilt. Ein PKMN\p"
	.string "kann nicht ausgetauscht werden, bevor\n"
	.string "der Kampf entschieden ist.$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
	.ifdef ENGLISH
	.string "The first judging factor is “Mind.”\n"
	.string "This factor evaluates how aggressive\l"
	.string "the battlers were.\p"
	.string "The judging is based on how often\n"
	.string "the TRAINERS ordered the use of\l"
	.string "offensive moves.$"
	.else
	.ifdef GERMAN
	.string "Der erste Faktor bei der Beurteilung\n"
	.string "ist der “Verstand”. Hier wird beurteilt,\l"
	.string "wie aggressiv die Kämpfer waren.\p"
	.string "Die Beurteilung richtet sich danach, wie\n"
	.string "oft der TRAINER offensive Attacken\l"
	.string "eingesetzt hat.$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
	.ifdef ENGLISH
	.string "The second judging factor is “Skill.”\n"
	.string "This factor evaluates how effectively\l"
	.string "POKéMON moves were used.\p"
	.string "If a move worked successfully,\n"
	.string "the Skill rating goes up.\p"
	.string "If a move failed, the Skill rating\n"
	.string "is lowered.\p"
	.string "If it was an offensive move, the Skill\n"
	.string "rating goes up if the move was “super\l"
	.string "effective” and goes down if it was\l"
	.string "“not very effective.”\p"
	.string "The Skill rating will not go up for\n"
	.string "moves such as PROTECT and DETECT.\p"
	.string "If the opponent used PROTECT or\n"
	.string "DETECT, and your POKéMON failed to\l"
	.string "hit with a move, its Skill rating will not\l"
	.string "go down.$"
	.else
	.ifdef GERMAN
	.string "Der zweite Faktor ist das\n"
	.string "“Geschick”. Hier wird beurteilt, wie\l"
	.string "effektiv Attacken eingesetzt wurden.\p"
	.string "War eine Attacke erfolgreich, geht die\n"
	.string "Bewertung der Fähigkeiten nach oben.\p"
	.string "Schlug eine Attacke fehl, geht die\n"
	.string "Bewertung nach unten.\p"
	.string "Handelt es sich um eine offensive\n"
	.string "Attacke, geht die Beurteilung nach\l"
	.string "oben, wenn sie “sehr effektiv” war.\l"
	.string "Sie geht nach unten, wenn sie “nicht\p"
	.string "sehr effektiv war”. Für Attacken wie\n"
	.string "SCHUTZSCHILD oder SCANNER gibt es\l"
	.string "keine höhere Bewertung.\p"
	.string "Setzt der Gegner SCHUTZSCHILD oder\n"
	.string "SCANNER ein und die Attacke deines\l"
	.string "PKMN scheitert, wird die Beurteilung\l"
	.string "nicht nach unten gehen.$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
	.ifdef ENGLISH
	.string "The third judging factor is “Body.”\n"
	.string "This factor is based on how much HP\l"
	.string "remained at the end of a battle.\p"
	.string "The rating takes into account how much\n"
	.string "HP a POKéMON had at the start of\l"
	.string "battle, and what remained at the end.$"
	.else
	.ifdef GERMAN
	.string "Der dritte Faktor bei der Beurteilung\n"
	.string "ist der “Körper”. Die am\l"
	.string "Ende verbleibenden KP sind ausschlag-\p"
	.string "gebend. Die Anzahl der KP, mit der ein\n"
	.string "PKMN in den Kampf geht, wird mit der\l"
	.string "am Ende des Kampfes verglichen.$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
	.ifdef ENGLISH
	.string "A victory snatched from the ARENA\n"
	.string "TYCOON, and a seven-TRAINER sweep!\p"
	.string "We congratulate you on your most\n"
	.string "splendid challenge!$"
	.else
	.ifdef GERMAN
	.string "Ein Sieg über den RINGMEISTER und ein\n"
	.string "siebenfacher Sieg über sieben TRAINER!\p"
	.string "Wir gratulieren dir zu deiner\n"
	.string "herausragenden Leistung!$"
	.endif
	.endif

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
	.ifdef ENGLISH
	.string "My dear challenger, in recognition of\n"
	.string "your indefatigable spirit, please\l"
	.string "accept these Battle Point(s).$"
	.else
	.ifdef GERMAN
	.string "Geschätzter Herausforderer! In Aner-\n"
	.string "kennung deines unermüdlichen Geistes\l"
	.string "überreichen wir dir Gewinnpunkte.$"
	.endif
	.endif
