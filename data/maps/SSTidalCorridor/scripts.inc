.set LOCALID_SAILOR, 1
.set LOCALID_SCOTT, 5

SSTidalCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSTidalCorridor_OnFrame
	.byte 0

SSTidalCorridor_OnFrame:
	map_script_2 VAR_SS_TIDAL_SCOTT_STATE, 0, SSTidalCorridor_EventScript_ScottScene
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT, SSTidalCorridor_EventScript_DepartSlateportForLilycove
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE, SSTidalCorridor_EventScript_DepartLilycoveForSlateport
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_EXIT_CURRENTS_RIGHT, SSTidalCorridor_EventScript_HalfwayToLilycove
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_EXIT_CURRENTS_LEFT, SSTidalCorridor_EventScript_ArrivedInSlateport
	.2byte 0

SSTidalCorridor_EventScript_DepartSlateportForLilycove::
	special SetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_SLATEPORT
	lockall
	playse SE_DING_DONG
	msgbox SSTidal_Text_FastCurrentsHopeYouEnjoyVoyage, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_DepartLilycoveForSlateport::
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_LILYCOVE
	lockall
	playse SE_DING_DONG
	msgbox SSTidal_Text_HopeYouEnjoyVoyage, MSGBOX_DEFAULT
	releaseall
	end

SSTidalRooms_EventScript_HalfwayToSlateport::
	special SetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_SLATEPORT
	playse SE_DING_DONG
	msgbox SSTidal_Text_FastCurrentsHopeYouEnjoyVoyage, MSGBOX_DEFAULT
	return

SSTidalRooms_EventScript_ArrivedInLilycove::
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_LILYCOVE
	playse SE_DING_DONG
	msgbox SSTidal_Text_MadeLandInLilycove, MSGBOX_DEFAULT
	return

SSTidalCorridor_EventScript_ReachedStepCount::
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_SLATEPORT, SSTidalCorridor_EventScript_HalfwayToLilycove
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_SLATEPORT, SSTidalCorridor_EventScript_ArrivedInSlateport
	end

SSTidalCorridor_EventScript_HalfwayToLilycove::
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_LILYCOVE
	lockall
	playse SE_DING_DONG
	msgbox SSTidal_Text_HopeYouEnjoyVoyage, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_ArrivedInSlateport::
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_SLATEPORT
	lockall
	playse SE_DING_DONG
	msgbox SSTidal_Text_MadeLandInSlateport, MSGBOX_DEFAULT
	releaseall
	end

SSTidalRooms_EventScript_ArrivedInSlateport::
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_SLATEPORT
	playse SE_DING_DONG
	msgbox SSTidal_Text_MadeLandInSlateport, MSGBOX_DEFAULT
	return

SSTidalRooms_EventScript_ProgessCruiseAfterBed::
	switch VAR_SS_TIDAL_STATE
	case SS_TIDAL_DEPART_SLATEPORT, SSTidalRooms_EventScript_ArrivedInLilycove
	case SS_TIDAL_HALFWAY_LILYCOVE, SSTidalRooms_EventScript_ArrivedInLilycove
	case SS_TIDAL_DEPART_LILYCOVE, SSTidalRooms_EventScript_HalfwayToSlateport
	case SS_TIDAL_HALFWAY_SLATEPORT, SSTidalRooms_EventScript_ArrivedInSlateport
	return

SSTidalCorridor_EventScript_Briney::
	msgbox SSTidalCorridor_Text_BrineyWelcomeAboard, MSGBOX_NPC
	end

SSTidalCorridor_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox SSTidalCorridor_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SSTidalCorridor_EventScript_Cabin1Sign::
	msgbox SSTidalCorridor_Text_Cabin1, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_Cabin2Sign::
	msgbox SSTidalCorridor_Text_Cabin2, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_Cabin3Sign::
	msgbox SSTidalCorridor_Text_Cabin3, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_Cabin4Sign::
	msgbox SSTidalCorridor_Text_Cabin4, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_ExitSailor::
	lock
	faceplayer
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_LILYCOVE, SSTidalCorridor_EventScript_ExitLilycove
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_SLATEPORT, SSTidalCorridor_EventScript_ExitSlateport
	msgbox SSTidalCorridor_Text_CanRestInCabin2, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_ExitLilycove::
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	msgbox SSTidalCorridor_Text_WeveArrived, MSGBOX_DEFAULT
	call_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalCorridor_EventScript_HideSnatchGiver
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

SSTidalCorridor_EventScript_ExitSlateport::
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	msgbox SSTidalCorridor_Text_WeveArrived, MSGBOX_DEFAULT
	call_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalCorridor_EventScript_HideSnatchGiver
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

SSTidalCorridor_EventScript_HideSnatchGiver::
	setflag FLAG_HIDE_SS_TIDAL_ROOMS_SNATCH_GIVER
	return

SSTidalCorridor_EventScript_Porthole::
	lockall
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_SLATEPORT, SSTidalCorridor_EventScript_LookThroughPorthole
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_SLATEPORT, SSTidalCorridor_EventScript_LookThroughPorthole
	msgbox SSTidalCorridor_Text_HorizonSpreadsBeyondPorthole, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_LookThroughPorthole::
	special LookThroughPorthole
	waitstate
	end

SSTidalCorridor_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SS_TIDAL_TRAINERS, SSTidalCorridor_EventScript_EnjoyYourCruise
	call SSTidalCorridor_EventScript_CheckIfTrainersDefeated
	msgbox SSTidalCorridor_Text_VisitOtherCabins, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_EnjoyYourCruise::
	msgbox SSTidalCorridor_Text_EnjoyYourCruise, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_CheckIfTrainersDefeated::
	goto_if_not_defeated TRAINER_PHILLIP, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_LEONARD, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_COLTON, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_MICAH, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_THOMAS, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_LEA_AND_JED, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_GARRET, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_NAOMI, SSTidalCorridor_EventScript_TrainerNotDefeated
	setflag FLAG_DEFEATED_SS_TIDAL_TRAINERS
	goto SSTidalCorridor_EventScript_EnjoyYourCruise
	return

SSTidalCorridor_EventScript_TrainerNotDefeated::
	return

SSTidalCorridor_EventScript_ScottScene::
	lockall
	applymovement LOCALID_SCOTT, SSTidalCorridor_Movement_ScottApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SSTidalCorridor_Text_ScottBattleFrontierInvite, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SSTidalCorridor_Movement_PlayerWatchScottExit
	applymovement LOCALID_SAILOR, SSTidalCorridor_Movement_SailorMoveForScott
	applymovement LOCALID_SCOTT, SSTidalCorridor_Movement_ScottExit
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject LOCALID_SCOTT
	applymovement LOCALID_SAILOR, SSTidalCorridor_Movement_SailorReturn
	waitmovement 0
	delay 30
	setflag FLAG_MET_SCOTT_ON_SS_TIDAL
	setvar VAR_SS_TIDAL_SCOTT_STATE, 1
	releaseall
	end

SSTidalCorridor_Movement_ScottApproachPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SSTidalCorridor_Movement_ScottExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SSTidalCorridor_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_down
	step_end

SSTidalCorridor_Movement_SailorMoveForScott:
	delay_16
	walk_right
	walk_right
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_left
	step_end

SSTidalCorridor_Movement_SailorReturn:
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

SSTidalCorridor_Text_ScottBattleFrontierInvite:
	.ifdef ENGLISH
	.string "SCOTT: Well, hi, hi!\n"
	.string "{PLAYER}{KUN}, {PLAYER}{KUN}!\p"
	.string "Something's come up, so I have to\n"
	.string "disembark, but am I glad to see you!\p"
	.string "Congratulations, LEAGUE CHAMPION!\p"
	.string "There's a place I'd like to invite\n"
	.string "someone like you.\p"
	.string "It's the…\n"
	.string "BATTLE FRONTIER!\p"
	.string "What's the place like?\n"
	.string "You'll understand when you see it!\p"
	.string "I've spoken with the ship's CAPTAIN\n"
	.string "about this.\p"
	.string "The next time you take a ferry,\n"
	.string "you should be able to sail to\l"
	.string "the BATTLE FRONTIER.\p"
	.string "Okay, {PLAYER}{KUN}, I'll be waiting for you\n"
	.string "at the BATTLE FRONTIER!$"
	.else
	.ifdef GERMAN
	.string "SCOTT: Hallo!!!\n"
	.string "{PLAYER}{KUN}, {PLAYER}{KUN}!\p"
	.string "Irgendetwas Großes wird passieren,\n"
	.string "daher habe ich es eilig. Aber ich habe\l"
	.string "mich gefreut, dich zu treffen!\p"
	.string "Herzlichen Glückwunsch, CHAMP der\n"
	.string "POKéMON LIGA!\p"
	.string "Jemanden wie dich würde ich gerne ein-\n"
	.string "laden. Es gibt da einen besonderen Ort…\p"
	.string "Und zwar…\n"
	.string "Die KAMPFZONE!\p"
	.string "Was das für ein Ort ist?\n"
	.string "Schau ihn dir einfach an!\p"
	.string "Ich habe mich bereits mit dem KAPITÄN\n"
	.string "darüber unterhalten.\p"
	.string "Nächstes Mal, wenn du die Fähre nimmst,\n"
	.string "kannst du zur KAMPFZONE fahren.\p"
	.string "Okay, {PLAYER}{KUN}, ich erwarte dich also in\n"
	.string "der KAMPFZONE!$"
	.endif
	.endif

SSTidal_Text_FastCurrentsHopeYouEnjoyVoyage:
	.ifdef ENGLISH
	.string "This ferry is built to plow through\n"
	.string "fast-running currents.\p"
	.string "We hope you enjoy your voyage with us.\n"
	.string "Feel free to explore the ship.$"
	.else
	.ifdef GERMAN
	.string "Diese Fähre ist so konstruiert, dass sie\n"
	.string "auch durch starke Strömungen\l"
	.string "fahren kann.\p"
	.string "Wir hoffen, du genießt die Reise mit\n"
	.string "uns. Schau dich ruhig auf dem Schiff um.$"
	.endif
	.endif

SSTidal_Text_HopeYouEnjoyVoyage:
	.ifdef ENGLISH
	.string "We hope you enjoy your voyage on\n"
	.string "our ferry.$"
	.else
	.ifdef GERMAN
	.string "Wir hoffen, du genießt die Reise mit\n"
	.string "uns. Schau dich ruhig auf dem Schiff um.$"
	.endif
	.endif

SSTidal_Text_MadeLandInSlateport:
	.ifdef ENGLISH
	.string "We have made land in SLATEPORT CITY.\n"
	.string "Thank you for sailing with us.$"
	.else
	.ifdef GERMAN
	.string "Wir gehen in GRAPHITPORT CITY vor\n"
	.string "Anker. Danke, dass du mit uns gefahren\l"
	.string "bist.$"
	.endif
	.endif

SSTidal_Text_MadeLandInLilycove:
	.ifdef ENGLISH
	.string "We have made land in LILYCOVE CITY.\n"
	.string "Thank you for sailing with us.$"
	.else
	.ifdef GERMAN
	.string "Wir gehen in SEEGRASULB CITY vor Anker.\n"
	.string "Danke, dass du mit uns gefahren bist.$"
	.endif
	.endif

SSTidalCorridor_Text_CanRestInCabin2:
	.ifdef ENGLISH
	.string "It'll be some time before we make land,\n"
	.string "I reckon.\p"
	.string "You can rest up in your cabin if you'd\n"
	.string "like. Your cabin's No. 2.\p"
	.string "The bed in there is soft and plushy.\n"
	.string "I can attest to how comfy it is!$"
	.else
	.ifdef GERMAN
	.string "Ich schätze, es wird einige Zeit dauern,\n"
	.string "bis wir an Land gehen.\p"
	.string "Du kannst dich in deiner Kabine aus-\n"
	.string "ruhen. Du hast Kabine 2.\p"
	.string "Das Bett ist weich und gemütlich. Das\n"
	.string "habe ich bereits überprüft!$"
	.endif
	.endif

SSTidalCorridor_Text_WeveArrived:
	.ifdef ENGLISH
	.string "We've arrived!$"
	.else
	.ifdef GERMAN
	.string "Wir sind angekommen!$"
	.endif
	.endif

SSTidalCorridor_Text_VisitOtherCabins:
	.ifdef ENGLISH
	.string "Go visit other cabins.\n"
	.string "TRAINERS bored of the boat trip will\l"
	.string "be itching to battle.$"
	.else
	.ifdef GERMAN
	.string "Schau dir ruhig die anderen Kabinen an.\n"
	.string "TRAINER langweilen sich auf der Über-\l"
	.string "fahrt und werden sicher gerne kämpfen.$"
	.endif
	.endif

SSTidalCorridor_Text_EnjoyYourCruise:
	.ifdef ENGLISH
	.string "Enjoy your cruise!$"
	.else
	.ifdef GERMAN
	.string "Genieße die Überfahrt.$"
	.endif
	.endif

SSTidalCorridor_Text_HorizonSpreadsBeyondPorthole:
	.ifdef ENGLISH
	.string "The horizon spreads beyond\n"
	.string "the porthole.$"
	.else
	.ifdef GERMAN
	.string "Durch das Bullauge sieht man\n"
	.string "den Horizont.$"
	.endif
	.endif

SSTidalCorridor_Text_BrineyWelcomeAboard:
	.ifdef ENGLISH
	.string "MR. BRINEY: Welcome aboard, {PLAYER}{KUN}!\p"
	.string "They made me honorary captain of\n"
	.string "the S.S. TIDAL!\p"
	.string "You can call me CAPTAIN BRINEY now!\p"
	.string "You know, I retired once before,\n"
	.string "but when I saw this majestic ship…\p"
	.string "Let me just say, it stirred my sleeping\n"
	.string "soul as a sailor!$"
	.else
	.ifdef GERMAN
	.string "MR. BRACK: Willkommen an Bord, {PLAYER}{KUN}!\p"
	.string "Ich bin jetzt der Kapitän der\n"
	.string "MS TIDE!\p"
	.string "Du kannst mich ab sofort\n"
	.string "KAPITÄN BRACK nennen.\p"
	.string "Ich war zwar schon in Rente gegangen,\n"
	.string "aber als ich dieses majestätische\l"
	.string "Schiff gesehen habe…\p"
	.string "Lass es mich so sagen: Es weckte die\n"
	.string "schlafende Seele des Seemannes in mir.$"
	.endif
	.endif

SSTidalCorridor_Text_Peeko:
	.ifdef ENGLISH
	.string "PEEKO: Pihyo pihyohyo…$"
	.else
	.ifdef GERMAN
	.string "PECKO: Pihyo pihyohyo…$"
	.endif
	.endif

SSTidalCorridor_Text_Cabin1:
	.ifdef ENGLISH
	.string "Cabin 1$"
	.else
	.ifdef GERMAN
	.string "Kabine 1$"
	.endif
	.endif

SSTidalCorridor_Text_Cabin2:
	.ifdef ENGLISH
	.string "Cabin 2$"
	.else
	.ifdef GERMAN
	.string "Kabine 2$"
	.endif
	.endif

SSTidalCorridor_Text_Cabin3:
	.ifdef ENGLISH
	.string "Cabin 3$"
	.else
	.ifdef GERMAN
	.string "Kabine 3$"
	.endif
	.endif

SSTidalCorridor_Text_Cabin4:
	.ifdef ENGLISH
	.string "Cabin 4$"
	.else
	.ifdef GERMAN
	.string "Kabine 4$"
	.endif
	.endif
