.set LOCALID_ATTENDANT, 1

BattleFrontier_BattlePalaceCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceCorridor_OnFrame
	.byte 0

BattleFrontier_BattlePalaceCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePalaceCorridor_EventScript_WalkThroughCorridor
	.2byte 0

BattleFrontier_BattlePalaceCorridor_EventScript_WalkThroughCorridor::
	delay 16
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor
	waitmovement 0
	lockall
	palace_getcomment
	call_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment1
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment2
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment3
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattlePalaceCorridor_EventScript_StreakComment
	call_if_eq VAR_RESULT, 4, BattleFrontier_BattlePalaceCorridor_EventScript_LongStreakComment
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	goto_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceCorridor_EventScript_WalkToOpenBattleRoom
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkTo50BattleRoom
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkTo50BattleRoom
	waitmovement 0
	opendoor 6, 3
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom
	waitmovement 0
	closedoor 6, 3
	waitdooranim
	goto BattleFrontier_BattlePalaceCorridor_EventScript_WarpToBattleRoom

BattleFrontier_BattlePalaceCorridor_EventScript_WalkToOpenBattleRoom::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkToOpenBattleRoom
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkToOpenBattleRoom
	waitmovement 0
	opendoor 10, 3
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom
	waitmovement 0
	closedoor 10, 3
	waitdooranim
BattleFrontier_BattlePalaceCorridor_EventScript_WarpToBattleRoom::
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM, 7, 4
	waitstate
	end

BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment1::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_PeopleAndMonAreSame, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment2::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_LetMonDoWhatItLikes, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment3::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_MonDifferentWhenCornered, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_StreakComment::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_BeginningToUnderstandNature, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_LongStreakComment::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_HeartfeltBondBetweenYouAndMons, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkTo50BattleRoom:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkTo50BattleRoom:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkToOpenBattleRoom:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkToOpenBattleRoom:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom:
	walk_up
BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceCorridor_Text_PeopleAndMonAreSame:
	.ifdef ENGLISH
	.string "People and POKéMON, they are but\n"
	.string "the same…\p"
	.string "Their individual nature makes them\n"
	.string "good at certain things, and not good\l"
	.string "at others.$"
	.else
	.ifdef GERMAN
	.string "Menschen und POKéMON… sind sich\n"
	.string "manchmal erstaunlich ähnlich…\p"
	.string "Beide sind in manchen Dingen gut, in\n"
	.string "manchen weniger gut - abhängig von\l"
	.string "ihrem Wesen.$"
	.endif
	.endif

BattleFrontier_BattlePalaceCorridor_Text_LetMonDoWhatItLikes:
	.ifdef ENGLISH
	.string "Rather than trying to make a POKéMON\n"
	.string "do what it dislikes, try to let it do\l"
	.string "what it likes and is good at doing.\p"
	.string "Put yourself in the POKéMON's position\n"
	.string "and consider what moves it would like.$"
	.else
	.ifdef GERMAN
	.string "Statt dein POKéMON zu zwingen, etwas\n"
	.string "zu tun, was es nicht mag, lass es das\l"
	.string "machen, was es mag und gut kann.\p"
	.string "Stell dir vor, du wärest das POKéMON.\n"
	.string "Welche Attacken würdest du an seiner\l"
	.string "Stelle einsetzen?$"
	.endif
	.endif

BattleFrontier_BattlePalaceCorridor_Text_MonDifferentWhenCornered:
	.ifdef ENGLISH
	.string "A POKéMON's nature is a remarkable\n"
	.string "thing…\p"
	.string "Some POKéMON behave in a completely\n"
	.string "different way when they are cornered.$"
	.else
	.ifdef GERMAN
	.string "Das Wesen eines POKéMON ist eine\n"
	.string "bemerkenswerte Sache…\p"
	.string "Einige POKéMON verhalten sich\n"
	.string "untypisch, wenn sie in die Ecke\l"
	.string "gedrängt werden.$"
	.endif
	.endif

BattleFrontier_BattlePalaceCorridor_Text_BeginningToUnderstandNature:
	.ifdef ENGLISH
	.string "Are you beginning to understand how\n"
	.string "a POKéMON's nature makes it behave?$"
	.else
	.ifdef GERMAN
	.string "Verstehst du nun, wie sehr das Wesen\n"
	.string "eines POKéMON sein Verhalten bestimmt?$"
	.endif
	.endif

BattleFrontier_BattlePalaceCorridor_Text_HeartfeltBondBetweenYouAndMons:
	.ifdef ENGLISH
	.string "Ah… I see a strong, heartfelt bond\n"
	.string "between you and your POKéMON…$"
	.else
	.ifdef GERMAN
	.string "Ah… Das Band zwischen dir und deinen\n"
	.string "POKéMON ist sehr stark…$"
	.endif
	.endif

