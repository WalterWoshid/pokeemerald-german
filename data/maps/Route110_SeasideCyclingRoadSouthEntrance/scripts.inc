Route110_SeasideCyclingRoadSouthEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_SeasideCyclingRoadSouthEntrance_OnTransition
	.byte 0

Route110_SeasideCyclingRoadSouthEntrance_OnTransition:
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 3, Route110_SeasideCyclingRoadSouthEntrance_EventScript_RestartChallenge
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 2, Route110_SeasideCyclingRoadSouthEntrance_EventScript_RestartChallenge
	end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_RestartChallenge::
	setvar VAR_CYCLING_CHALLENGE_STATE, 1
	return

Route110_SeasideCyclingRoadSouthEntrance_EventScript_Clerk::
	lock
	faceplayer
	msgbox Route110_SeasideCyclingRoadSouthEntrance_Text_GoAllOutOnCyclingRoad, MSGBOX_DEFAULT
	release
	end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_BikeCheck::
	lockall
	specialvar VAR_RESULT, GetPlayerAvatarBike
	call_if_eq VAR_RESULT, 2, Route110_SeasideCyclingRoadSouthEntrance_EventScript_OnMachBike
	goto_if_eq VAR_RESULT, 0, Route110_SeasideCyclingRoadSouthEntrance_EventScript_NoBike
	setflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_TEMP_1, 1
	releaseall
	end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_OnMachBike::
	setvar VAR_CYCLING_CHALLENGE_STATE, 1
	return

Route110_SeasideCyclingRoadSouthEntrance_EventScript_NoBike::
	msgbox Route110_SeasideCyclingRoadSouthEntrance_Text_TooDangerousToWalk, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route110_SeasideCyclingRoadSouthEntrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

Route110_SeasideCyclingRoadSouthEntrance_Movement_PushPlayerBackFromCounter:
	walk_left
	step_end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_ClearCyclingRoad::
	lockall
	setvar VAR_CYCLING_CHALLENGE_STATE, 0
	clearflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_TEMP_1, 0
	releaseall
	end

Route110_SeasideCyclingRoadSouthEntrance_Text_GoAllOutOnCyclingRoad:
	.ifdef ENGLISH
	.string "On CYCLING ROAD, you can go all out\n"
	.string "and cycle as fast as you'd like.\p"
	.string "It feels great to go that fast, but try\n"
	.string "not to crash into anyone!$"
	.else
	.ifdef GERMAN
	.string "Auf dem RADWEG kannst du so\n"
	.string "schnell fahren, wie du willst.\p"
	.string "Schnell fahren macht Spaß, pass aber\n"
	.string "auf, dass du mit niemandem\l"
	.string "zusammenstößt.$"
	.endif
	.endif

Route110_SeasideCyclingRoadSouthEntrance_Text_TooDangerousToWalk:
	.ifdef ENGLISH
	.string "Sorry, you can't walk on CYCLING\n"
	.string "ROAD. It's too dangerous.\p"
	.string "Please come back with a BIKE.$"
	.else
	.ifdef GERMAN
	.string "Tut mir Leid, aber auf dem RADWEG\n"
	.string "sind Fußgänger nicht gestattet.\p"
	.string "Das ist gefährlich. Bring dein RAD mit…$"
	.endif
	.endif

