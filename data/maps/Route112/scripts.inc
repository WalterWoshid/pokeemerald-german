.set LOCALID_GRUNT_1, 1
.set LOCALID_GRUNT_2, 6

Route112_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_OnTransition
	.byte 0

Route112_OnTransition:
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

Route112_EventScript_MagmaGrunts::
	lockall
	delay 40
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	msgbox Route112_Text_LeaderGoingToAwakenThing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	msgbox Route112_Text_YeahWeNeedMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	msgbox Route112_Text_OhThatsWhyCrewWentToFallarbor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	msgbox Route112_Text_CantLetAnyonePassUntilTheyreBack, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

Route112_EventScript_MtChimneyCableCarSign::
	msgbox Route112_Text_MtChimneyCableCarSign, MSGBOX_SIGN
	end

Route112_EventScript_MtChimneySign::
	msgbox Route112_Text_MtChimneySign, MSGBOX_SIGN
	end

Route112_EventScript_RouteSignLavaridge::
	msgbox Route112_Text_RouteSignLavaridge, MSGBOX_SIGN
	end

Route112_EventScript_Hiker::
	msgbox Route112_Text_NotEasyToGetBackToLavaridge, MSGBOX_NPC
	end

Route112_EventScript_Brice::
	trainerbattle_single TRAINER_BRICE, Route112_Text_BriceIntro, Route112_Text_BriceDefeat
	msgbox Route112_Text_BricePostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Trent::
	trainerbattle_single TRAINER_TRENT_1, Route112_Text_TrentIntro, Route112_Text_TrentDefeat, Route112_EventScript_RegisterTrent
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route112_EventScript_RematchTrent
	msgbox Route112_Text_TrentPostBattle, MSGBOX_DEFAULT
	release
	end

Route112_EventScript_RegisterTrent::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route112_Text_TrentRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TRENT_1
	release
	end

Route112_EventScript_RematchTrent::
	trainerbattle_rematch TRAINER_TRENT_1, Route112_Text_TrentRematchIntro, Route112_Text_TrentRematchDefeat
	msgbox Route112_Text_TrentRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Larry::
	trainerbattle_single TRAINER_LARRY, Route112_Text_LarryIntro, Route112_Text_LarryDefeat
	msgbox Route112_Text_LarryPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL, Route112_Text_CarolIntro, Route112_Text_CarolDefeat
	msgbox Route112_Text_CarolPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Bryant::
	trainerbattle_single TRAINER_BRYANT, Route112_Text_BryantIntro, Route112_Text_BryantDefeat
	msgbox Route112_Text_BryantPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Shayla::
	trainerbattle_single TRAINER_SHAYLA, Route112_Text_ShaylaIntro, Route112_Text_ShaylaDefeat
	msgbox Route112_Text_ShaylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_Text_LeaderGoingToAwakenThing:
	.ifdef ENGLISH
	.string "Hey, man, is our leader really going\n"
	.string "to awaken that thing?$"
	.else
	.ifdef GERMAN
	.string "Hey, ob unser Anführer dieses Ding\n"
	.string "wirklich aufwecken wird?$"
	.endif
	.endif

Route112_Text_YeahWeNeedMeteorite:
	.ifdef ENGLISH
	.string "Sounds like it, yeah. But I heard\n"
	.string "we need a METEORITE to do it.$"
	.else
	.ifdef GERMAN
	.string "Hört sich so an, ja. Aber wir brauchen\n"
	.string "einen METEORITen dafür.$"
	.endif
	.endif

Route112_Text_OhThatsWhyCrewWentToFallarbor:
	.ifdef ENGLISH
	.string "Oh, I get it now. That's why the rest\n"
	.string "of the crew went out to FALLARBOR.$"
	.else
	.ifdef GERMAN
	.string "Ach, jetzt verstehe ich! Deshalb sind\n"
	.string "die anderen nach LAUBWECHSELFELD\l"
	.string "gegangen.$"
	.endif
	.endif

Route112_Text_CantLetAnyonePassUntilTheyreBack:
	.ifdef ENGLISH
	.string "You got it. And until they come back,\n"
	.string "we're not to let anyone pass, right.$"
	.else
	.ifdef GERMAN
	.string "Genau! Und solange sie weg sind, darf\n"
	.string "hier niemand durch.$"
	.endif
	.endif

Route112_Text_NotEasyToGetBackToLavaridge:
	.ifdef ENGLISH
	.string "Eh, I'd like to get to MAUVILLE, but if\n"
	.string "I went down these ledges, it'd be no\l"
	.string "easy matter to get back to LAVARIDGE.$"
	.else
	.ifdef GERMAN
	.string "Ich würde gerne nach MALVENFROH CITY,\n"
	.string "aber wenn ich diese Stufen hinunter-\p"
	.string "gehe, komme ich kaum wieder nach\n"
	.string "BAD LAVASTADT.$"
	.endif
	.endif

Route112_Text_MtChimneyCableCarSign:
	.ifdef ENGLISH
	.string "MT. CHIMNEY CABLE CAR\n"
	.string "“A short walk {UP_ARROW} way!”$"
	.else
	.ifdef GERMAN
	.string "SEILBAHN ZUM SCHLOTBERG\n"
	.string "“Ein kurzer Weg nach {UP_ARROW}!”$"
	.endif
	.endif

Route112_Text_MtChimneySign:
	.ifdef ENGLISH
	.string "MT. CHIMNEY\p"
	.string "“For LAVARIDGE TOWN or the summit,\n"
	.string "please take the CABLE CAR.”$"
	.else
	.ifdef GERMAN
	.string "SCHLOTBERG\p"
	.string "“BAD LAVASTADT oder den Gipfel\n"
	.string "erreichen Sie mit der SEILBAHN.”$"
	.endif
	.endif

Route112_Text_RouteSignLavaridge:
	.ifdef ENGLISH
	.string "ROUTE 112\n"
	.string "{LEFT_ARROW} LAVARIDGE TOWN$"
	.else
	.ifdef GERMAN
	.string "ROUTE 112\n"
	.string "{LEFT_ARROW} BAD LAVASTADT$"
	.endif
	.endif

