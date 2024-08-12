.set LOCALID_STEVEN, 3
.set LOCALID_ARCHIE, 4
.set LOCALID_MAXIE, 5

Route128_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route128_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route128_OnFrame
	.byte 0

Route128_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

Route128_OnFrame:
	map_script_2 VAR_ROUTE128_STATE, 1, Route128_EventScript_KyogreAwakenedScene
	.2byte 0

Route128_EventScript_KyogreAwakenedScene::
	lockall
	delay 20
	applymovement LOCALID_ARCHIE, Route128_Movement_ArchieLookAround
	waitmovement 0
	msgbox Route128_Text_ArchieWhatHappened, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, Route128_Movement_ArchieBackUp
	waitmovement 0
	msgbox Route128_Text_ArchieIOnlyWanted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAXIE, Route128_Movement_MaxieApproachArchie
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox Route128_Text_MaxieDoYouUnderstandNow, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAXIE, Route128_Movement_MaxieApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox Route128_Text_MaxieResposibilityFallsToArchieAndMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, Route128_Movement_ArchieRunLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAXIE, Route128_Movement_MaxieWalkLeft
	waitmovement 0
	msgbox Route128_Text_MaxieThisDefiesBelief, MSGBOX_DEFAULT
	closemessage
	delay 40
	applymovement LOCALID_MAXIE, Route128_Movement_MaxieExit
	applymovement LOCALID_ARCHIE, Route128_Movement_ArchieExit
	waitmovement 0
	removeobject LOCALID_MAXIE
	removeobject LOCALID_ARCHIE
	delay 100
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	waitfieldeffect FLDEFF_NPCFLY_OUT
	addobject LOCALID_STEVEN
	applymovement LOCALID_STEVEN, Route128_Movement_StevenApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox Route128_Text_StevenWhatIsHappening, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, Route128_Movement_StevenWalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox Route128_Text_StevenWholeWorldWillDrown, MSGBOX_DEFAULT
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route128_Text_StevenImGoingToSootopolis, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject LOCALID_STEVEN
	waitfieldeffect FLDEFF_NPCFLY_OUT
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE128_STATE, 2
	releaseall
	end

Route128_Movement_Unused1:
	walk_fast_left
	step_end

Route128_Movement_Unused2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route128_Movement_StevenWalkUp:
	walk_up
	step_end

Route128_Movement_StevenApproachPlayer:
	walk_fast_left
	step_end

Route128_Movement_ArchieLookAround:
	walk_fast_down
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

Route128_Movement_ArchieBackUp:
	lock_facing_direction
	walk_slow_up
	delay_16
	unlock_facing_direction
	step_end

Route128_Movement_ArchieRunLeft:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_in_place_faster_right
	step_end

Route128_Movement_ArchieExit:
	delay_16
	delay_16
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route128_Movement_MaxieWalkLeft:
	walk_left
	walk_left
	delay_8
	delay_4
	step_end

Route128_Movement_MaxieApproachArchie:
	walk_left
	walk_in_place_faster_down
	step_end

Route128_Movement_MaxieExit:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route128_Movement_MaxieApproachPlayer:
	walk_right
	walk_in_place_faster_down
	step_end

Route128_EventScript_Isaiah::
	trainerbattle_single TRAINER_ISAIAH_1, Route128_Text_IsaiahIntro, Route128_Text_IsaiahDefeat, Route128_EventScript_RegisterIsaiah
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route128_EventScript_RematchIsaiah
	msgbox Route128_Text_IsaiahPostBattle, MSGBOX_DEFAULT
	release
	end

Route128_EventScript_RegisterIsaiah::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route128_Text_IsaiahRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISAIAH_1
	release
	end

Route128_EventScript_RematchIsaiah::
	trainerbattle_rematch TRAINER_ISAIAH_1, Route128_Text_IsaiahRematchIntro, Route128_Text_IsaiahRematchDefeat
	msgbox Route128_Text_IsaiahPostRematch, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Katelyn::
	trainerbattle_single TRAINER_KATELYN_1, Route128_Text_KatelynIntro, Route128_Text_KatelynDefeat, Route128_EventScript_RegisterKatelyn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route128_EventScript_RematchKatelyn
	msgbox Route128_Text_KatelynPostBattle, MSGBOX_DEFAULT
	release
	end

Route128_EventScript_RegisterKatelyn::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route128_Text_KatelynRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KATELYN_1
	release
	end

Route128_EventScript_RematchKatelyn::
	trainerbattle_rematch TRAINER_KATELYN_1, Route128_Text_KatelynRematchIntro, Route128_Text_KatelynRematchDefeat
	msgbox Route128_Text_KatelynPostRematch, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Alexa::
	trainerbattle_single TRAINER_ALEXA, Route128_Text_AlexaIntro, Route128_Text_AlexaDefeat
	msgbox Route128_Text_AlexaPostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Ruben::
	trainerbattle_single TRAINER_RUBEN, Route128_Text_RubenIntro, Route128_Text_RubenDefeat
	msgbox Route128_Text_RubenPostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Wayne::
	trainerbattle_single TRAINER_WAYNE, Route128_Text_WayneIntro, Route128_Text_WayneDefeat
	msgbox Route128_Text_WaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Harrison::
	trainerbattle_single TRAINER_HARRISON, Route128_Text_HarrisonIntro, Route128_Text_HarrisonDefeat
	msgbox Route128_Text_HarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Carlee::
	trainerbattle_single TRAINER_CARLEE, Route128_Text_CarleeIntro, Route128_Text_CarleeDefeat
	msgbox Route128_Text_CarleePostBattle, MSGBOX_AUTOCLOSE
	end

Route128_Text_ArchieWhatHappened:
	.ifdef ENGLISH
	.string "ARCHIE: What happened…\n"
	.string "What is this wretched scene…\p"
	.string "Did I…make a horrible mistake?$"
	.else
	.ifdef GERMAN
	.string "ADRIAN: Was ist passiert… Was für\n"
	.string "ein Furcht erregendes Szenario…\p"
	.string "Habe ich… einen schrecklichen Fehler\n"
	.string "begangen?$"
	.endif
	.endif

Route128_Text_ArchieIOnlyWanted:
	.ifdef ENGLISH
	.string "I…\n"
	.string "I only wanted…$"
	.else
	.ifdef GERMAN
	.string "Ich…\n"
	.string "Ich wollte doch nur…$"
	.endif
	.endif

Route128_Text_MaxieDoYouUnderstandNow:
	.ifdef ENGLISH
	.string "MAXIE: Do you understand now,\n"
	.string "ARCHIE?\p"
	.string "Do you finally see how disastrous\n"
	.string "your dream turned out to be?\p"
	.string "We have to hurry! We have to do\n"
	.string "something before the situation goes\l"
	.string "completely out of control!$"
	.else
	.ifdef GERMAN
	.string "MARC: Begreifst du es nun,\n"
	.string "ADRIAN?\p"
	.string "Begreifst du nun die schrecklichen\n"
	.string "Folgen deines katastrophalen Traums?\p"
	.string "Wir müssen uns beeilen! Wir müssen\n"
	.string "etwas unternehmen, bevor die Situation\l"
	.string "völlig außer Kontrolle gerät!$"
	.endif
	.endif

Route128_Text_MaxieResposibilityFallsToArchieAndMe:
	.ifdef ENGLISH
	.string "MAXIE: {PLAYER}, don't say anything.\p"
	.string "I know that I have no right to be\n"
	.string "critical of ARCHIE…\p"
	.string "But the way things are now, I doubt\n"
	.string "that we humans will be capable of\l"
	.string "doing anything about it.\p"
	.string "But neither can we stand by and\n"
	.string "just watch helplessly.\p"
	.string "The responsibility for putting an end\n"
	.string "to this falls to ARCHIE and me…$"
	.else
	.ifdef GERMAN
	.string "MARC: {PLAYER}, sag jetzt nichts.\p"
	.string "Ich weiß, ich bin nicht der Richtige, um\n"
	.string "ADRIAN zu kritisieren…\p"
	.string "Aber wie die Dinge jetzt liegen, werden\n"
	.string "wir Menschen wohl nicht in der Lage\l"
	.string "sein, etwas zu tun.\p"
	.string "Aber wir dürfen auch nicht einfach\n"
	.string "daneben stehen und zuschauen.\p"
	.string "ADRIAN und ich haben die\n"
	.string "Verantwortung, dies alles zu\l"
	.string "verändern…$"
	.endif
	.endif

Route128_Text_MaxieThisDefiesBelief:
	.ifdef ENGLISH
	.string "MAXIE: This defies belief…\p"
	.string "Those super-ancient POKéMON…\p"
	.string "Their power is unbelievable.\n"
	.string "They've upset the balance of nature…$"
	.else
	.ifdef GERMAN
	.string "MARC: Das ist ja unglaublich…\p"
	.string "Ein super-antikes POKéMON…\p"
	.string "Seine Kraft ist unglaublich. Es hat\n"
	.string "das Gleichgewicht der Natur verändert.$"
	.endif
	.endif

Route128_Text_StevenWhatIsHappening:
	.ifdef ENGLISH
	.string "STEVEN: {PLAYER}{KUN}!\n"
	.string "What is happening?$"
	.else
	.ifdef GERMAN
	.string "TROY: {PLAYER}{KUN}!\n"
	.string "Was geht hier vor?$"
	.endif
	.endif

Route128_Text_StevenWholeWorldWillDrown:
	.ifdef ENGLISH
	.string "This is terrible…\p"
	.string "After the scorching heat wave ended,\n"
	.string "this deluge began.\p"
	.string "If this doesn't stop, all of HOENN…\n"
	.string "No, the whole world will drown.\p"
	.string "This huge rain cloud is spreading\n"
	.string "from above SOOTOPOLIS…\p"
	.string "What in the world is taking place there?\p"
	.string "There's no point arguing here…\n"
	.string "SOOTOPOLIS might provide answers…$"
	.else
	.ifdef GERMAN
	.string "Das ist schrecklich…\p"
	.string "Nach der sengenden Hitze kam die\n"
	.string "Überschwemmung.\p"
	.string "Wenn das nicht aufhört, wird ganz\n"
	.string "HOENN… Nein, die ganze Welt wird\l"
	.string "untergehen.\p"
	.string "Von XENEROVILLE aus breitet sich eine\n"
	.string "gigantische Regenwolke aus…\p"
	.string "Was in aller Welt passiert da nur?\p"
	.string "Aber wir sollten hier nicht die Zeit mit\n"
	.string "Reden vertun…\p"
	.string "In XENEROVILLE bekommen wir\n"
	.string "hoffentlich Antworten…$"
	.endif
	.endif

Route128_Text_StevenImGoingToSootopolis:
	.ifdef ENGLISH
	.string "{PLAYER}{KUN}…\n"
	.string "I don't know what you intend to do,\l"
	.string "but don't do anything reckless.\p"
	.string "Okay.\n"
	.string "I'm going to SOOTOPOLIS.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER}{KUN}…\n"
	.string "Ich weiß nicht, was du vorhast, aber tue\l"
	.string "nichts Unüberlegtes.\p"
	.string "Okay.\n"
	.string "Ich gehe nach XENEROVILLE.$"
	.endif
	.endif

