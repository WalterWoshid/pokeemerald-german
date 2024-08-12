.set LOCALID_ATTENDANT, 1
.set LOCALID_NURSE, 2
.set LOCALID_GIRL, 4
.set LOCALID_MAN, 5

TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy OBJ_EVENT_ID_PLAYER, 9, 6
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_NURSE
	addobject LOCALID_ATTENDANT
	addobject LOCALID_MAN
	addobject LOCALID_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Expanded:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

TrainerHill_Entrance_Text_StillGettingReady:
	.ifdef ENGLISH
	.string "This is the TRAINER HILL where\n"
	.string "you may enjoy tag battles with many\l"
	.string "TRAINERS.\p"
	.string "Unfortunately, we're still getting\n"
	.string "things ready. Please come back later!$"
	.else
	.ifdef GERMAN
	.string "Dies ist der TRAINERBERG. Hier triffst\n"
	.string "du TRAINER, mit denen du viele Kämpfe\l"
	.string "genießen kannst.\p"
	.string "Leider ist hier noch alles im Aufbau\n"
	.string "begriffen. Komm doch später wieder.$"
	.endif
	.endif

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
	.ifdef ENGLISH
	.string "Welcome!\p"
	.string "This is the TRAINER HILL where\n"
	.string "you may enjoy tag battles with many\l"
	.string "TRAINERS!$"
	.else
	.ifdef GERMAN
	.string "Willkommen!\p"
	.string "Dies ist der TRAINERBERG. Hier triffst\n"
	.string "du TRAINER, mit denen du viele Kämpfe\l"
	.string "genießen kannst.$"
	.endif
	.endif

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
	.ifdef ENGLISH
	.string "Is this your first visit here?\p"
	.string "Before you enter, please save\n"
	.string "your game.$"
	.else
	.ifdef GERMAN
	.string "Bist du zum ersten Mal hier?\p"
	.string "Bevor du dich ins Getümmel stürzt,\n"
	.string "speicher bitte dein Spiel!$"
	.endif
	.endif

TrainerHill_Entrance_Text_TrainersUpToFloorX:
	.ifdef ENGLISH
	.string "Let's see…\n"
	.string "The TRAINERS here now are…\p"
	.string "Up to floor no. {STR_VAR_1}.$"
	.else
	.ifdef GERMAN
	.string "Mal sehen…\n"
	.string "Die TRAINER befinden sich…\p"
	.string "In den Etagen bis Etage {STR_VAR_1}.$"
	.endif
	.endif

TrainerHill_Entrance_Text_TrainersInEveryRoom:
	.ifdef ENGLISH
	.string "Let's see…\n"
	.string "The TRAINERS here now are…\p"
	.string "There appear to be TRAINERS gathered\n"
	.string "in every room.$"
	.else
	.ifdef GERMAN
	.string "Mal sehen…\n"
	.string "Die TRAINER befinden sich…\p"
	.string "In jedem Raum scheint sich nun ein\n"
	.string "TRAINER zu befinden.$"
	.endif
	.endif

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
	.ifdef ENGLISH
	.string "Would you like to challenge the\n"
	.string "waiting TRAINERS?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du die wartenden TRAINER\n"
	.string "herausfordern?$"
	.endif
	.endif

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
	.ifdef ENGLISH
	.string "I will time your progress.\n"
	.string "Best of luck!\p"
	.string "On your marks…\p"
	.string "Get set…\p"
	.string "Go!$"
	.else
	.ifdef GERMAN
	.string "O.K.! Ich stelle die Uhr! Gib\n"
	.string "dein Bestes!\p"
	.string "Auf die Plätze…\p"
	.string "Fertig…\p"
	.string "Los!$"
	.endif
	.endif

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
	.ifdef ENGLISH
	.string "Please do visit us again!$"
	.else
	.ifdef GERMAN
	.string "Bitte besuche uns wieder!$"
	.endif
	.endif

TrainerHill_Entrance_Text_TooBadTremendousEffort:
	.ifdef ENGLISH
	.string "That was too bad.\p"
	.string "I think you put in a tremendous\n"
	.string "effort in your battling.\p"
	.string "Please come back and try again!$"
	.else
	.ifdef GERMAN
	.string "Das war nicht gut!\p"
	.string "Ich glaube, du hast dich beim Kampf\n"
	.string "richtig angestrengt.\p"
	.string "Bitte komme wieder und probiere es\n"
	.string "erneut!$"
	.endif
	.endif

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
	.ifdef ENGLISH
	.string "I hope you give it your best.$"
	.else
	.ifdef GERMAN
	.string "Ich hoffe, du strengst dich wirklich an!$"
	.endif
	.endif

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
	.ifdef ENGLISH
	.string "When the TRAINERS switch places,\n"
	.string "the movement can be hectic.\p"
	.string "To avoid the stampede, we moved\n"
	.string "the reception counter here.\p"
	.string "I'm sorry for the inconvenience.$"
	.else
	.ifdef GERMAN
	.string "Tauschen die TRAINER ihre Plätze, kann\n"
	.string "es hektisch werden.\p"
	.string "Um eine Panik zu vermeiden, haben wir\n"
	.string "die Rezeption hierher verlegt.\p"
	.string "Wir bitten um dein Verständnis!$"
	.endif
	.endif

TrainerHill_Entrance_Text_ThankYouForPlaying:
	.ifdef ENGLISH
	.string "Thank you for playing!$"
	.else
	.ifdef GERMAN
	.string "Vielen Dank für die Teilnahme!$"
	.endif
	.endif

TrainerHill_Entrance_Text_ExplainTrainerHill:
	.ifdef ENGLISH
	.string "Here at the TRAINER HILL, we conduct\n"
	.string "an event called the Time Attack.\p"
	.string "It is a race that measures how long\n"
	.string "you take to reach our owner on\l"
	.string "the rooftop from this counter.\p"
	.string "The fastest times are posted on\n"
	.string "the Time Board--try competing with\l"
	.string "your friends.\p"
	.string "In TRAINER battles along the way,\n"
	.string "neither Exp. Points nor money will\l"
	.string "be awarded.$"
	.else
	.ifdef GERMAN
	.string "Hier im TRAINERBERG bieten wir dir an,\n"
	.string "“Gegen die Uhr” anzutreten.\p"
	.string "Wie lange brauchst du von hier bis zum\n"
	.string "Besitzer, der sich oben auf dem Dach\l"
	.string "befindet?\p"
	.string "Die Namen der TRAINER, die es am\n"
	.string "schnellsten schaffen, werden\l"
	.string "öffentlich ausgehängt.\p"
	.string "Fordere deine Freunde heraus!\p"
	.string "Für die Kämpfe, die du auf dem\n"
	.string "Weg zum Dach bestreitest, bekommst du\l"
	.string "keine E-Punkte und auch kein Geld.$"
	.endif
	.endif

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
	.ifdef ENGLISH
	.string "Oh, I'm sorry, but you appear to have\n"
	.string "only one POKéMON with you.\p"
	.string "You will need at least two POKéMON\n"
	.string "to enter this event.$"
	.else
	.ifdef GERMAN
	.string "Oh, I’m sorry, but you appear to have\n"
	.string "only one POKéMON with you.\p"
	.string "You will need at least two POKéMON\n"
	.string "to enter this event.$"
	.endif
	.endif

TrainerHill_Roof_Text_YouFinallyCameBravo:
	.ifdef ENGLISH
	.string "Hm! Hm!\p"
	.string "You finally came!\n"
	.string "Yes, you have arrived!\p"
	.string "Wait! Don't say it!\n"
	.string "I know why you came all the way\l"
	.string "here by yourself!\p"
	.string "You wanted to see me, the owner\n"
	.string "of the TRAINER HILL, because…\p"
	.string "You want to form a tag team with me!\n"
	.string "Wa-hoo!\p"
	.string "…Uh?\n"
	.string "That's not it?\p"
	.string "Anyway, I watched you on your way up.\n"
	.string "Marvelous battling! Bravo, indeed!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Da bist du ja endlich!\n"
	.string "Hast es also geschafft!\p"
	.string "Warte! Sag nichts!\n"
	.string "Ich weiß, warum du gekommen bist!\p"
	.string "Du wolltest mich, den Besitzer des\n"
	.string "TRAINERBERGs, kennen lernen, weil…\p"
	.string "Du willst mit mir in einem Team\n"
	.string "kämpfen! Jahuu!\p"
	.string "Wie?\n"
	.string "Das ist nicht der Grund?\p"
	.string "Na, egal. Ich habe dich auf dem Weg\n"
	.string "hierher beobachtet. Du bist sehr gut!$"
	.endif
	.endif

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
	.ifdef ENGLISH
	.string "For a marvelous someone like you,\n"
	.string "I have the most marvelous gift!$"
	.else
	.ifdef GERMAN
	.string "Ein fantastischer TRAINER wie du\n"
	.string "verdient ein fantastisches Geschenk!$"
	.endif
	.endif

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
	.ifdef ENGLISH
	.string "Oh, no, full up with things!\n"
	.string "You'll be back later for this!$"
	.else
	.ifdef GERMAN
	.string "Oh, du hast keinen Platz mehr! Na, dann\n"
	.string "komm doch einfach später mal vorbei.$"
	.endif
	.endif

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
	.ifdef ENGLISH
	.string "Oh, hold on here! Did you possibly get\n"
	.string "here marvelously quickly?\p"
	.string "How splendid! You needn't have\n"
	.string "hurried so to see me!\p"
	.string "That is so delightful. I'll have the Time\n"
	.string "Board at the reception updated!$"
	.else
	.ifdef GERMAN
	.string "Hey, warte mal! Bist du wirklich so\n"
	.string "fantastisch schnell hierher gekommen?\p"
	.string "Ausgezeichnet! Dabei hättest du dich\n"
	.string "doch nicht so beeilen müssen, nur um\p"
	.string "mich zu treffen! Trotzdem! Ich habe\n"
	.string "deinen Namen bereits verewigt.$"
	.endif
	.endif

TrainerHill_Roof_Text_YouWerentVeryQuick:
	.ifdef ENGLISH
	.string "But, oh…\n"
	.string "You weren't very quick getting here.$"
	.else
	.ifdef GERMAN
	.string "Aber… Du hast dir ja\n"
	.string "mächtig viel Zeit gelassen…$"
	.endif
	.endif

TrainerHill_Roof_Text_ArriveZippierNextTime:
	.ifdef ENGLISH
	.string "Perhaps it would please me more if you\n"
	.string "arrived zippier next time.\p"
	.string "Then, I should be pleased to form\n"
	.string "a tag team with you!\p"
	.string "Until we meet again, amigo!$"
	.else
	.ifdef GERMAN
	.string "Mir würde es gefallen, wenn du das\n"
	.string "nächste Mal mehr Tempo machst!\p"
	.string "Dann bin ich auch bereit, dein\n"
	.string "Teampartner zu werden!\p"
	.string "Bis dann, mein Freund!$"
	.endif
	.endif

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
	.ifdef ENGLISH
	.string "I had the TRAINER HILL built for but\n"
	.string "one reason and one only!\p"
	.string "To find the most suitable partner\n"
	.string "with whom I may form a tag team!$"
	.else
	.ifdef GERMAN
	.string "I had the TRAINER HILL built for but\n"
	.string "one reason and one only!\p"
	.string "To find the most suitable partner\n"
	.string "with whom I may form a tag team!$"
	.endif
	.endif

TrainerHill_Entrance_Text_ChallengeTime:
	.ifdef ENGLISH
	.string "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sec.$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_1} Min. {STR_VAR_2},{STR_VAR_3} Sek.$"
	.endif
	.endif

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
	.ifdef ENGLISH
	.string "Who knows what sort of TRAINERS\n"
	.string "and POKéMON combos are ahead?\p"
	.string "All I know is that I'll knock aside\n"
	.string "anyone that stands in my way!$"
	.else
	.ifdef GERMAN
	.string "Wer weiß schon, welche TRAINER und\n"
	.string "POKéMON auf uns warten?\p"
	.string "Ich weiß nur eines: Ich werde alle, die\n"
	.string "mir im Weg stehen, besiegen!$"
	.endif
	.endif

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
	.ifdef ENGLISH
	.string "I heard tough TRAINERS come to this\n"
	.string "TRAINER HILL from all over.\p"
	.string "I can't wait to test the waters!\p"
	.string "I'll knock aside anyone that stands\n"
	.string "in my way!$"
	.else
	.ifdef GERMAN
	.string "Ich habe gehört, TRAINER kommen\n"
	.string "von überall her zum TRAINERBERG.\p"
	.string "Ich kann es nicht erwarten, ihnen\n"
	.string "Auge in Auge gegenüber zu stehen.\p"
	.string "Ich werde jeden besiegen, der sich mir\n"
	.string "in den Weg stellt.$"
	.endif
	.endif

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.ifdef ENGLISH
	.string "Do you see the Time Board over there?\p"
	.string "My friends and I are trying to see who\n"
	.string "can reach the top in the least time.$"
	.else
	.ifdef GERMAN
	.string "Hast du die Liste mit den Zeiten da\n"
	.string "drüben gesehen?\p"
	.string "Meine Freunde und ich wollen heraus-\n"
	.string "finden, wer von uns der Schnellste ist.$"
	.endif
	.endif

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
	.ifdef ENGLISH
	.string "Do you know when they're opening\n"
	.string "this place up?\p"
	.string "I'm waiting here to be the first\n"
	.string "challenger ever!$"
	.else
	.ifdef GERMAN
	.string "Du weißt nicht zufällig, wann die hier\n"
	.string "eröffnen?\p"
	.string "Ich warte hier, da ich die allererste\n"
	.string "Herausforderin sein will!$"
	.endif
	.endif

TrainerHill_Elevator_Text_ReturnToReception:
	.ifdef ENGLISH
	.string "Would you like to return to\n"
	.string "the reception counter?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du zur\n"
	.string "Rezeption zurückkehren?$"
	.endif
	.endif
