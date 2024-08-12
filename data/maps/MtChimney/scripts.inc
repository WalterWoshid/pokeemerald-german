.set LOCALID_ARCHIE, 1
.set LOCALID_MAXIE, 2
.set LOCALID_TABITHA, 3
.set LOCALID_MAGMA_GRUNT_2, 22
.set LOCALID_MAGMA_GRUNT_1, 29


MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_MAGMA_GRUNT_1
	removeobject LOCALID_TABITHA
	removeobject LOCALID_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreen FADE_FROM_BLACK
	setobjectxyperm LOCALID_ARCHIE, 10, 12
	addobject LOCALID_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
	.ifdef ENGLISH
	.string "The power contained in the METEORITE…\p"
	.string "By amplifying its power with this\n"
	.string "machine, MT. CHIMNEY's volcanic\l"
	.string "activity will instantly intensify…\p"
	.string "Its energy will grow deep inside\n"
	.string "the crater and…\l"
	.string "Fufufu…$"
	.else
	.ifdef GERMAN
	.string "Die Kraft, die in dem METEORITen\n"
	.string "steckt…\p"
	.string "Wenn man die mit dieser Maschine\n"
	.string "verstärkt, würde die Aktivität des\l"
	.string "SCHLOTBERGs enorm verstärkt…\p"
	.string "Die Energie wird tief im Krater\n"
	.string "ansteigen und…\l"
	.string "Hähähähä…$"
	.endif
	.endif

MtChimney_Text_MaxieIntro:
	.ifdef ENGLISH
	.string "MAXIE: Hm?\n"
	.string "Who are you?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "I'd heard ARCHIE bemoaning a child\n"
	.string "who's been meddling in TEAM AQUA's\l"
	.string "affairs.\p"
	.string "It must be you he meant.\p"
	.string "Humph! So you're thinking of\n"
	.string "interfering with us, TEAM MAGMA?\p"
	.string "Now you listen.\n"
	.string "Long ago, living things used the\l"
	.string "land to live and grow.\p"
	.string "That is why land is all important!\n"
	.string "It is the cradle of all!\p"
	.string "That is why TEAM MAGMA is dedicated\n"
	.string "to the expansion of the land mass.\p"
	.string "It is for further advancement of\n"
	.string "humankind and POKéMON!\p"
	.string "And for that, we need the power of\n"
	.string "what sleeps within this mountain…\p"
	.string "Oh! There was no need for you to\n"
	.string "learn that much.\p"
	.string "But, no matter!\n"
	.string "I'll teach you the consequences of\l"
	.string "meddling in our grand design!$"
	.else
	.ifdef GERMAN
	.string "MARC: Hm?\n"
	.string "Wer bist du denn?!?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "ADRIAN hat sich über ein Kind beklagt,\n"
	.string "das sich in die Angelegenheiten von\l"
	.string "TEAM AQUA einmischt.\p"
	.string "Dieses Kind musst du sein.\p"
	.string "Hmpf! Und du glaubst, du kannst dich\n"
	.string "auch in unsere, TEAM MAGMAs\l"
	.string "Angelegenheiten einmischen?\p"
	.string "Hör gut zu. Schon lange Zeit nutzen\n"
	.string "die Lebewesen das Land, um zu\l"
	.string "wachsen und zu gedeihen.\p"
	.string "Daher ist das Land wichtiger als alles\n"
	.string "andere! Es ist die Wiege allen Lebens.\p"
	.string "Daher widmet sich TEAM MAGMA der Auf-\n"
	.string "gabe, die Landmassen zu vergrößern.\p"
	.string "So entsteht mehr Raum für Menschen\n"
	.string "und POKéMON.\p"
	.string "Für unsere Pläne brauchen wir das, was\n"
	.string "im Inneren dieses Berges schläft…\p"
	.string "Nun, mehr brauchst du nicht zu wissen.\p"
	.string "Ich kann einem sturen Kind wie dir nicht\n"
	.string "erlauben, sich uns in den Weg zu stellen.\p"
	.string "Ich werde dir zeigen, was\n"
	.string "passiert, wenn du uns aufhalten willst!$"
	.endif
	.endif

MtChimney_Text_MaxieDefeat:
	.ifdef ENGLISH
	.string "What?!\p"
	.string "I, MAXIE, was caught off guard?!$"
	.else
	.ifdef GERMAN
	.string "Wie bitte?!?\p"
	.string "Ich, MARC, wurde ganz hinterhältig\n"
	.string "besiegt?!?$"
	.endif
	.endif

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.ifdef ENGLISH
	.string "MAXIE: But, enough.\n"
	.string "I will back off this time.\p"
	.string "But don't think that this is the last\n"
	.string "you've seen of TEAM MAGMA.\p"
	.string "Fufufu…\p"
	.string "Even without the METEORITE, if we\n"
	.string "obtain that ORB… Fufufu…$"
	.else
	.ifdef GERMAN
	.string "MARC: Genug.\n"
	.string "Ich ziehe mich für den Moment zurück.\p"
	.string "Aber das ist nicht das letzte Mal, dass\n"
	.string "du TEAM MAGMA zu Gesicht bekommen\l"
	.string "hast.\p"
	.string "Hähähä…\p"
	.string "Auch ohne METEORIT… Wenn wir erst die\n"
	.string "KUGEL haben… Hähähähä…$"
	.endif
	.endif

MtChimney_Text_TabithaIntro:
	.ifdef ENGLISH
	.string "Hehehe!\p"
	.string "So you've come all the way here!\p"
	.string "But you're too late!\n"
	.string "I've already delivered the METEORITE\l"
	.string "from METEOR FALLS to the BOSS!$"
	.else
	.ifdef GERMAN
	.string "Hahahahaha!\p"
	.string "Da bist du also den weiten Weg hier\n"
	.string "hoch gelatscht.\p"
	.string "Tja, du kommst leider zu spät. Ich habe\n"
	.string "den METEORITen aus METEORFÄLLE\l"
	.string "bereits bei meinem BOSS abgeliefert!$"
	.endif
	.endif

MtChimney_Text_TabithaDefeat:
	.ifdef ENGLISH
	.string "Hehehe…\p"
	.string "Even though I've lost, if our leader\n"
	.string "awakens that thing…$"
	.else
	.ifdef GERMAN
	.string "Hähähä…\p"
	.string "Auch wenn ich verloren habe… Sobald\n"
	.string "unser Boss das Ding zum Leben erweckt…$"
	.endif
	.endif

MtChimney_Text_TabithaPostBattle:
	.ifdef ENGLISH
	.string "BOSS, hurry!\n"
	.string "Give it the METEORITE's energy!\p"
	.string "Hehehe…$"
	.else
	.ifdef GERMAN
	.string "BOSS, beeil dich!\n"
	.string "Gib ihm die Energie des METEORITen!\p"
	.string "Hähähä…$"
	.endif
	.endif

MtChimney_Text_Grunt2Intro:
	.ifdef ENGLISH
	.string "We of TEAM MAGMA are working hard for\n"
	.string "everyone's sake.\p"
	.string "Like, if that thing's power made more\n"
	.string "land, there'd be more places to live.\p"
	.string "Everyone'd be happy!$"
	.else
	.ifdef GERMAN
	.string "Wir von TEAM MAGMA setzen alles daran,\n"
	.string "zum Wohle aller zu handeln.\p"
	.string "Und wenn das Ding mehr Land schafft,\n"
	.string "gibt es auch mehr Platz zum Leben.\p"
	.string "Und jeder wäre glücklich!$"
	.endif
	.endif

MtChimney_Text_Grunt2Defeat:
	.ifdef ENGLISH
	.string "Hunh?\n"
	.string "What do you mean I lost?$"
	.else
	.ifdef GERMAN
	.string "Bitte?\n"
	.string "Was sagst du? Ich habe verloren???$"
	.endif
	.endif

MtChimney_Text_Grunt2PostBattle:
	.ifdef ENGLISH
	.string "Our BOSS says, “It will make everyone\n"
	.string "happy.”\p"
	.string "But why does everyone keep getting\n"
	.string "in our way?$"
	.else
	.ifdef GERMAN
	.string "Unser BOSS sagt: “Jeder wird glücklich\n"
	.string "sein.”\p"
	.string "Aber warum will uns dann jeder\n"
	.string "aufhalten?$"
	.endif
	.endif

MtChimney_Text_Grunt1Intro:
	.ifdef ENGLISH
	.string "If there were more land, I'd be able\n"
	.string "to get a big house of my own!\p"
	.string "I'm going to build it on hardened lava!$"
	.else
	.ifdef GERMAN
	.string "Wenn es mehr Land gibt, wäre ich in der\n"
	.string "Lage, mir ein eigenes großes Haus zu\l"
	.string "bauen!\p"
	.string "Das würde ich dann auf der erstarrten\n"
	.string "Lava bauen!$"
	.endif
	.endif

MtChimney_Text_Grunt1Defeat:
	.ifdef ENGLISH
	.string "My dream of a big house…$"
	.else
	.ifdef GERMAN
	.string "Mein Traum von einem großen Haus…$"
	.endif
	.endif

MtChimney_Text_Grunt1PostBattle:
	.ifdef ENGLISH
	.string "A kid like you, you ought to be\n"
	.string "splashing about in the waves!$"
	.else
	.ifdef GERMAN
	.string "Ein Kind wie du sollte sich im Meer\n"
	.string "vergnügen.$"
	.endif
	.endif

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.ifdef ENGLISH
	.string "That annoying TEAM AQUA…\n"
	.string "They always mess with our plans!$"
	.else
	.ifdef GERMAN
	.string "Dieses lästige TEAM AQUA… Sie ver-\n"
	.string "suchen alles, unsere Pläne zu vereiteln.$"
	.endif
	.endif

MtChimney_Text_MeteoritesPackAmazingPower:
	.ifdef ENGLISH
	.string "METEORITES pack amazing power!$"
	.else
	.ifdef GERMAN
	.string "METEORITen stecken voller Energie.$"
	.endif
	.endif

MtChimney_Text_YouBetterNotMessWithUs:
	.ifdef ENGLISH
	.string "You'd better not mess with us!\p"
	.string "We're trying to awaken that thing\n"
	.string "for the benefit of everyone!$"
	.else
	.ifdef GERMAN
	.string "Du gehst uns besser aus dem Weg!\p"
	.string "Wir werden das Ding zum Leben erwecken.\n"
	.string "Zum Wohle aller.$"
	.endif
	.endif

MtChimney_Text_AquasNameSimilar:
	.ifdef ENGLISH
	.string "We're TEAM MAGMA!\p"
	.string "They're TEAM AQUA!\p"
	.string "It totally annoys me that they'd\n"
	.string "use a name like ours!$"
	.else
	.ifdef GERMAN
	.string "Wir sind TEAM MAGMA!\p"
	.string "Sie sind TEAM AQUA!\p"
	.string "Ich finde es total bescheuert, dass sie\n"
	.string "einen Namen haben, der unserem ähnelt.$"
	.endif
	.endif

MtChimney_Text_DouseThemInFire:
	.ifdef ENGLISH
	.string "Yeah!\n"
	.string "Douse them in fire!$"
	.else
	.ifdef GERMAN
	.string "Yeah!\n"
	.string "Taucht sie ins Feuer!$"
	.endif
	.endif

MtChimney_Text_KeepMakingMoreLand:
	.ifdef ENGLISH
	.string "We're going to keep making more land!$"
	.else
	.ifdef GERMAN
	.string "Wir werden weiter für mehr Land sorgen!$"
	.endif
	.endif

MtChimney_Text_Bufoh:
	.ifdef ENGLISH
	.string "Bufoh!$"
	.else
	.ifdef GERMAN
	.string "Hahoh!$"
	.endif
	.endif

MtChimney_Text_ArchieGoStopTeamMagma:
	.ifdef ENGLISH
	.string "ARCHIE: Grr, {PLAYER}!\n"
	.string "I should've guessed you'd show up!\p"
	.string "See for yourself what the fanatics\n"
	.string "of TEAM MAGMA are up to!\p"
	.string "They're trying to inject the stolen\n"
	.string "METEORITE's power into the volcano!\p"
	.string "Doing something like that will cause\n"
	.string "the volcano's eruption!$"
	.else
	.ifdef GERMAN
	.string "ADRIAN: Grrr, {PLAYER}!\n"
	.string "Ich hätte es wissen müssen. War doch\l"
	.string "klar, dass du hier auftauchst.\p"
	.string "Schau dir ruhig an, was die Fanatiker\n"
	.string "von TEAM MAGMA vorhaben!\p"
	.string "Sie wollen die Kraft des gestohlenen\n"
	.string "METEORITen in den Vulkan geben!\p"
	.string "Und das wird den Vulkan zum Ausbruch\n"
	.string "bringen!$"
	.endif
	.endif

MtChimney_Text_ArchieIHaveMyHandsFull:
	.ifdef ENGLISH
	.string "ARCHIE: Grrr…\p"
	.string "I want to stop that MAXIE,\n"
	.string "but I can't!\p"
	.string "Not when I have my hands full battling\n"
	.string "three opponents at once!$"
	.else
	.ifdef GERMAN
	.string "ADRIAN: Grrr…\p"
	.string "Ich möchte MARC aufhalten, aber ich\n"
	.string "kann es nicht!\p"
	.string "Nicht, wenn ich mich drei Gegnern\n"
	.string "gleichzeitig stellen muss.$"
	.endif
	.endif

MtChimney_Text_ArchieThankYou:
	.ifdef ENGLISH
	.string "ARCHIE: {PLAYER}!\n"
	.string "Thank you!\p"
	.string "With your help, we thwarted TEAM\n"
	.string "MAGMA's destructive plan!\p"
	.string "But… You…\n"
	.string "Whose side are you on?\p"
	.string "Ah, it doesn't matter.\p"
	.string "We will remain vigilant and keep up\n"
	.string "our pursuit of TEAM MAGMA.\p"
	.string "{PLAYER}, we shall meet again!$"
	.else
	.ifdef GERMAN
	.string "ADRIAN: {PLAYER}!\n"
	.string "Danke!\p"
	.string "Mit deiner Hilfe haben wir den\n"
	.string "zerstörerischen Plan von TEAM MAGMA\l"
	.string "durchkreuzt!\p"
	.string "Aber… Du…\n"
	.string "Auf welcher Seite stehst du?\p"
	.string "Ach, das ist egal.\p"
	.string "Wir werden weiter unsere Augen\n"
	.string "aufhalten und TEAM MAGMA beobachten.\p"
	.string "{PLAYER}, wir sehen uns bestimmt wieder!$"
	.endif
	.endif

MtChimney_Text_MagmaOutnumbersUs:
	.ifdef ENGLISH
	.string "Darn… TEAM MAGMA outnumbers us!\n"
	.string "We can't keep up with them!$"
	.else
	.ifdef GERMAN
	.string "Mist… TEAM MAGMA ist uns zahlenmäßig\n"
	.string "überlegen! Wir können es nicht mit ihnen\l"
	.string "aufnehmen!$"
	.endif
	.endif

MtChimney_Text_LessHabitatForWaterPokemon:
	.ifdef ENGLISH
	.string "If they expand the land, there'll be\n"
	.string "less habitats for WATER POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Wenn sie die Landmassen vergrößern,\n"
	.string "gibt es weniger Lebensraum für\l"
	.string "WASSER-POKéMON!$"
	.endif
	.endif

MtChimney_Text_MagmasNameSimilar:
	.ifdef ENGLISH
	.string "We're TEAM AQUA!\p"
	.string "They're TEAM MAGMA!\p"
	.string "It burns me up that they'd use such\n"
	.string "a confusing name!$"
	.else
	.ifdef GERMAN
	.string "Wir sind TEAM AQUA!\p"
	.string "Sie sind TEAM MAGMA!\p"
	.string "Ich koche über vor Wut, weil sie so\n"
	.string "einen verwirrenden Namen verwenden.$"
	.endif
	.endif

MtChimney_Text_Bushaa:
	.ifdef ENGLISH
	.string "Bushaa!$"
	.else
	.ifdef GERMAN
	.string "Bushaa!$"
	.endif
	.endif

MtChimney_Text_LavaCookiesJust200:
	.ifdef ENGLISH
	.string "LAVA COOKIES are MT. CHIMNEY's local\n"
	.string "specialty.\p"
	.string "Try one. It's just ¥200.$"
	.else
	.ifdef GERMAN
	.string "LAVAKEKSE sind die Spezialität am\n"
	.string "SCHLOTBERG.\p"
	.string "Nimm einen. Er kostet nur ¥200.$"
	.endif
	.endif

MtChimney_Text_ThankYouDear:
	.ifdef ENGLISH
	.string "Thank you, dear!$"
	.else
	.ifdef GERMAN
	.string "Vielen Dank, Herzchen!$"
	.endif
	.endif

MtChimney_Text_YouveNotGotTheMoney:
	.ifdef ENGLISH
	.string "Oh, dear. You can't buy a thing if\n"
	.string "you've not got the money.$"
	.else
	.ifdef GERMAN
	.string "Oh je. Du kannst nichts kaufen, wenn\n"
	.string "du nicht genug Geld bei dir hast.$"
	.endif
	.endif

MtChimney_Text_OhFineThen:
	.ifdef ENGLISH
	.string "Oh, fine then.$"
	.else
	.ifdef GERMAN
	.string "Oh, ist gut.$"
	.endif
	.endif

MtChimney_Text_MetoriteFittedOnMachine:
	.ifdef ENGLISH
	.string "A METEORITE is fitted on a mysterious\n"
	.string "machine…\p"
	.string "The machine seems to be storing\n"
	.string "energy in the METEORITE.$"
	.else
	.ifdef GERMAN
	.string "Ein METEORIT steckt in dieser\n"
	.string "mysteriösen Vorrichtung…\p"
	.string "Die Maschine scheint den METEORITen\n"
	.string "mit Energie zu versorgen.$"
	.endif
	.endif

MtChimney_Text_RemoveTheMeteorite:
	.ifdef ENGLISH
	.string "A METEORITE is fitted on a mysterious\n"
	.string "machine…\p"
	.string "Do you want to remove the METEORITE?$"
	.else
	.ifdef GERMAN
	.string "Ein METEORIT steckt in dieser\n"
	.string "mysteriösen Vorrichtung…\p"
	.string "Willst du den METEORITen nehmen?$"
	.endif
	.endif

MtChimney_Text_PlayerRemovedMeteorite:
	.ifdef ENGLISH
	.string "{PLAYER} removed the METEORITE from\n"
	.string "the mysterious machine.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} entfernt den METEORITen aus\n"
	.string "der mysteriösen Vorrichtung.$"
	.endif
	.endif

MtChimney_Text_PlayerLeftMeteorite:
	.ifdef ENGLISH
	.string "{PLAYER} left the METEORITE where\n"
	.string "it was.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} fasst den METEORITen nicht an.$"
	.endif
	.endif

MtChimney_Text_MachineMakesNoResponse:
	.ifdef ENGLISH
	.string "This mysterious machine…\n"
	.string "It makes no response whatsoever.$"
	.else
	.ifdef GERMAN
	.string "Diese mysteriöse Vorrichtung…\n"
	.string "Sie reagiert in keiner Weise.$"
	.endif
	.endif

MtChimney_Text_RouteSign:
	.ifdef ENGLISH
	.string "{DOWN_ARROW} JAGGED PATH\n"
	.string "LAVARIDGE TOWN AHEAD$"
	.else
	.ifdef GERMAN
	.string "{DOWN_ARROW} STEILPASS\n"
	.string "BAD LAVASTADT GERADEAUS$"
	.endif
	.endif

MtChimney_Text_ShelbyIntro:
	.ifdef ENGLISH
	.string "I've been to the hot springs and\n"
	.string "refreshed my tired bones.\l"
	.string "Right now I'm feeling strong!$"
	.else
	.ifdef GERMAN
	.string "Ich war bei den Heißen Quellen und habe\n"
	.string "meine müden Knochen erfrischt.\l"
	.string "Jetzt fühle ich mich richtig stark!$"
	.endif
	.endif

MtChimney_Text_ShelbyDefeat:
	.ifdef ENGLISH
	.string "Oh, my goodness.\n"
	.string "Now, aren't you something!$"
	.else
	.ifdef GERMAN
	.string "Oh, du meine Güte!\n"
	.string "Wer bist du denn?!?$"
	.endif
	.endif

MtChimney_Text_ShelbyPostBattle:
	.ifdef ENGLISH
	.string "Well, well, I've lost. I can't call\n"
	.string "myself an EXPERT now, can I?$"
	.else
	.ifdef GERMAN
	.string "Nun, ich habe verloren. Ich darf mich\n"
	.string "nun nicht mehr EXPERTE nennen, oder?$"
	.endif
	.endif

MtChimney_Text_ShelbyRegister:
	.ifdef ENGLISH
	.string "Thank you, child. It was fun, as if\n"
	.string "I were battling my own grandchild.\p"
	.string "Please, come see me again for\n"
	.string "a rematch.$"
	.else
	.ifdef GERMAN
	.string "Danke schön, mein Kind. Das hat Spaß\n"
	.string "gemacht. So, als ob ich gegen mein\l"
	.string "Enkelkind gekämpft hätte.\p"
	.string "Komm doch bitte mal wieder vorbei.$"
	.endif
	.endif

MtChimney_Text_ShelbyRematchIntro:
	.ifdef ENGLISH
	.string "If you can mesh your heart with those\n"
	.string "of your POKéMON, why, you should be\l"
	.string "able to achieve great things.$"
	.else
	.ifdef GERMAN
	.string "Wenn du in deinem Herzen Platz für\n"
	.string "deine POKéMON hast, dann kannst du\l"
	.string "auch große Dinge erreichen.$"
	.endif
	.endif

MtChimney_Text_ShelbyRematchDefeat:
	.ifdef ENGLISH
	.string "Oh, my goodness.\n"
	.string "Now, aren't you something!$"
	.else
	.ifdef GERMAN
	.string "Oh, du meine Güte!\n"
	.string "Wer bist du denn!$"
	.endif
	.endif

MtChimney_Text_ShelbyPostRematch:
	.ifdef ENGLISH
	.string "Perhaps your heart has become one\n"
	.string "with the hearts of your POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Vielleicht schlägt dein Herz im Gleich-\n"
	.string "klang mit den POKéMON.$"
	.endif
	.endif

MtChimney_Text_MelissaIntro:
	.ifdef ENGLISH
	.string "I've got the fire in me, baby.\n"
	.string "I can't stand it! I have to battle!$"
	.else
	.ifdef GERMAN
	.string "Ich habe Feuer in mir, Baby.\n"
	.string "Ich halt’s nicht aus! Ich muss kämpfen!$"
	.endif
	.endif

MtChimney_Text_MelissaDefeat:
	.ifdef ENGLISH
	.string "Ooh, that was a scorching-hot match!$"
	.else
	.ifdef GERMAN
	.string "Oh, was für ein kochend heißer Kampf!$"
	.endif
	.endif

MtChimney_Text_MelissaPostBattle:
	.ifdef ENGLISH
	.string "The heat of MT. CHIMNEY warms\n"
	.string "me up, baby!$"
	.else
	.ifdef GERMAN
	.string "Die Hitze vom SCHLOTBERG bringt mein\n"
	.string "Feuer in Gang.$"
	.endif
	.endif

MtChimney_Text_SheilaIntro:
	.ifdef ENGLISH
	.string "I've finally made it to MT. CHIMNEY.\n"
	.string "I want to make my POKéMON battle!$"
	.else
	.ifdef GERMAN
	.string "Endlich bin ich am SCHLOTBERG ange-\n"
	.string "kommen. Jetzt will ich kämpfen!!!$"
	.endif
	.endif

MtChimney_Text_SheilaDefeat:
	.ifdef ENGLISH
	.string "The way you battle…\n"
	.string "It's like a MT. CHIMNEY eruption!$"
	.else
	.ifdef GERMAN
	.string "Wie du kämpfst…\n"
	.string "Als würde der SCHLOTBERG ausbrechen!$"
	.endif
	.endif

MtChimney_Text_SheilaPostBattle:
	.ifdef ENGLISH
	.string "Like I said, I've finally made it to\n"
	.string "MT. CHIMNEY. It would be a shame if\l"
	.string "I only do a little sightseeing…\p"
	.string "I want to get in some battles and buy\n"
	.string "COOKIES as souvenirs.$"
	.else
	.ifdef GERMAN
	.string "Wie ich schon sagte, endlich bin ich am\n"
	.string "SCHLOTBERG. Wäre doch blödsinnig, wenn\l"
	.string "ich nur zum Sightseeing hier wäre…\p"
	.string "Ich will ein bisschen kämpfen und KEKSe\n"
	.string "als Andenken kaufen.$"
	.endif
	.endif

MtChimney_Text_ShirleyIntro:
	.ifdef ENGLISH
	.string "Since I bathed in the hot springs,\n"
	.string "I've been feeling great!\l"
	.string "I'm sure I'm going to win!$"
	.else
	.ifdef GERMAN
	.string "Seit ich in den Heißen Quellen gebadet\n"
	.string "habe, fühle ich mich großartig!\l"
	.string "Ich bin sicher, ich werde gewinnen!$"
	.endif
	.endif

MtChimney_Text_ShirleyDefeat:
	.ifdef ENGLISH
	.string "Yowch!\n"
	.string "I'm getting a chill out of the water.$"
	.else
	.ifdef GERMAN
	.string "Huaah!\n"
	.string "Außerhalb des Wassers ist es saukalt.$"
	.endif
	.endif

MtChimney_Text_ShirleyPostBattle:
	.ifdef ENGLISH
	.string "I'll have to take another dip in the\n"
	.string "hot springs. Want to join me?\p"
	.string "Just joking!$"
	.else
	.ifdef GERMAN
	.string "Ich werde mich wieder in die Heiße\n"
	.string "Quelle setzen. Kommst du mit?\p"
	.string "Kleiner Scherz am Rande… Hähähä.$"
	.endif
	.endif

MtChimney_Text_SawyerIntro:
	.ifdef ENGLISH
	.string "This is one fine mountain! Plenty of\n"
	.string "hot people around for company!$"
	.else
	.ifdef GERMAN
	.string "Dies ist ein schöner Berg! Hier gibt es\n"
	.string "viele interessante Leute, die einem\l"
	.string "Gesellschaft leisten.$"
	.endif
	.endif

MtChimney_Text_SawyerDefeat:
	.ifdef ENGLISH
	.string "Oh, you're a real firebrand, too!$"
	.else
	.ifdef GERMAN
	.string "Oh, du bist auch ein richtiger\n"
	.string "Heißsporn.$"
	.endif
	.endif

MtChimney_Text_SawyerPostBattle:
	.ifdef ENGLISH
	.string "I think I need a dip in LAVARIDGE\n"
	.string "HOT SPRING with the locals!$"
	.else
	.ifdef GERMAN
	.string "Ich glaube, ich tauche mal in den Heißen\n"
	.string "Quellen von BAD LAVASTADT ab.$"
	.endif
	.endif

MtChimney_Text_SawyerRegister:
	.ifdef ENGLISH
	.string "I like little fireballs like you.\n"
	.string "Let me register you in my POKéNAV.$"
	.else
	.ifdef GERMAN
	.string "Ich mag Hitzköpfe wie dich.\n"
	.string "Ich trage dich in meinen POKéNAV ein.$"
	.endif
	.endif

MtChimney_Text_SawyerRematchIntro:
	.ifdef ENGLISH
	.string "I'm happily surrounded by hot people\n"
	.string "around these parts. I won't lose!$"
	.else
	.ifdef GERMAN
	.string "Ich freue mich, denn hier gibt es viele\n"
	.string "hitzköpfige Menschen.\l"
	.string "Ich verliere mit Sicherheit nicht.$"
	.endif
	.endif

MtChimney_Text_SawyerRematchDefeat:
	.ifdef ENGLISH
	.string "Gosh, you're still the same\n"
	.string "firebrand as before!$"
	.else
	.ifdef GERMAN
	.string "Mist, du hast dich kein bisschen\n"
	.string "abgekühlt. Immer noch ein Heißsporn.$"
	.endif
	.endif

MtChimney_Text_SawyerPostRematch:
	.ifdef ENGLISH
	.string "Actually, it really is hot here.\n"
	.string "I'm overdressed for these parts.$"
	.else
	.ifdef GERMAN
	.string "Hier ist es wirklich sehr heiß. Und ich\n"
	.string "bin absolut zu warm angezogen für\l"
	.string "diese Gegend.$"
	.endif
	.endif

