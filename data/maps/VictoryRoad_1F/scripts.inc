.set LOCALID_WALLY_ENTRANCE, 4

VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition:
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 2, 24
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 3, 24
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1::
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_WALLY_ENTRANCE
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer1
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2::
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_WALLY_ENTRANCE
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer2
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	copyobjectxytoperm LOCALID_WALLY_ENTRANCE
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
VictoryRoad_1F_EventScript_EntranceWally::
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

@ This Wally appears and remains at the exit after the Hall of Fame is entered
VictoryRoad_1F_EventScript_ExitWally::
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_RematchWally::
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert::
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy::
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn::
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
	.ifdef ENGLISH
	.string "WALLY: Hi! {PLAYER}!\p"
	.string "I bet you're surprised to see me here!\p"
	.string "I made it all the way here, and it's\n"
	.string "all thanks to you!\p"
	.string "{PLAYER}, losing to you that time\n"
	.string "made me stronger!\p"
	.string "But I'm not going to lose anymore!\p"
	.string "I'm going to win! For the POKéMON who\n"
	.string "gave me courage and strength!\p"
	.string "Okay… Here I come!$"
	.else
	.ifdef GERMAN
	.string "HEIKO: Hallo, {PLAYER}!\p"
	.string "Du bist bestimmt überrascht, mich hier\n"
	.string "zu treffen!\p"
	.string "Ich habe es bis hierher geschafft und\n"
	.string "das verdanke ich dir!\p"
	.string "{PLAYER}, meine Niederlage gegen dich\n"
	.string "hat mich viel stärker gemacht!\p"
	.string "Ich werde nie wieder verlieren!\p"
	.string "Ich werde gewinnen! Für die POKéMON,\n"
	.string "die mir Mut und Kraft gegeben haben!\p"
	.string "Okay… Jetzt komme ich!$"
	.endif
	.endif

VictoryRoad_1F_Text_WallyEntranceDefeat:
	.ifdef ENGLISH
	.string "Wow!\n"
	.string "{PLAYER}, you are strong, after all!$"
	.else
	.ifdef GERMAN
	.string "Wow!\n"
	.string "{PLAYER}, du wirst immer stärker!$"
	.endif
	.endif

VictoryRoad_1F_Text_WallyPostEntranceBattle:
	.ifdef ENGLISH
	.string "WALLY: I couldn't beat you today,\n"
	.string "{PLAYER}, but one of these days, I'll\l"
	.string "catch up to you!$"
	.else
	.ifdef GERMAN
	.string "HEIKO: Ich konnte dich heute nicht be-\n"
	.string "siegen, aber eines Tages werde ich es\l"
	.string "mit dir aufnehmen!$"
	.endif
	.endif

VictoryRoad_1F_Text_WallyIntro:
	.ifdef ENGLISH
	.string "WALLY: Hi! {PLAYER}!\p"
	.string "I've gotten stronger since that last\n"
	.string "time! I wanted to show you, {PLAYER}!\p"
	.string "Okay… Here I come!$"
	.else
	.ifdef GERMAN
	.string "HEIKO: Hallo, {PLAYER}!\p"
	.string "Ich bin viel stärker geworden! Das\n"
	.string "möchte ich dir zeigen, {PLAYER}!\p"
	.string "Okay… Jetzt komme ich!$"
	.endif
	.endif

VictoryRoad_1F_Text_WallyDefeat:
	.ifdef ENGLISH
	.string "Wow!\n"
	.string "{PLAYER}, you are strong, after all!$"
	.else
	.ifdef GERMAN
	.string "Wow!\n"
	.string "{PLAYER}, du bist immer noch zu stark!$"
	.endif
	.endif

VictoryRoad_1F_Text_WallyPostBattle:
	.ifdef ENGLISH
	.string "WALLY: I couldn't beat you this time,\n"
	.string "too… But one of these days, {PLAYER},\l"
	.string "I'm going to catch up to you…\p"
	.string "And challenge the POKéMON LEAGUE!$"
	.else
	.ifdef GERMAN
	.string "HEIKO: Ich konnte dich wieder nicht\n"
	.string "besiegen… Aber eines Tages, {PLAYER},\l"
	.string "eines Tages…\p"
	.string "Da werde ich sogar die POKéMON LIGA\n"
	.string "herausfordern!$"
	.endif
	.endif

VictoryRoad_1F_Text_EdgarIntro:
	.ifdef ENGLISH
	.string "I've made it this far a couple times,\n"
	.string "but the last stretch is so long…$"
	.else
	.ifdef GERMAN
	.string "Ich habe es innerhalb kürzester Zeit\n"
	.string "bis hierher geschafft, aber das letzte\l"
	.string "Stück zieht sich wie Kaugummi…$"
	.endif
	.endif

VictoryRoad_1F_Text_EdgarDefeat:
	.ifdef ENGLISH
	.string "My dream ends here again…$"
	.else
	.ifdef GERMAN
	.string "Hier enden meine Träume…$"
	.endif
	.endif

VictoryRoad_1F_Text_EdgarPostBattle:
	.ifdef ENGLISH
	.string "You've made it this far. Keep the\n"
	.string "momentum going and become the\l"
	.string "CHAMPION! If anyone can, it's you!$"
	.else
	.ifdef GERMAN
	.string "Du bist weit gekommen. Lasse nicht nach\n"
	.string "und versuche, der CHAMP zu werden!\l"
	.string "Wenn einer das kann, dann du!$"
	.endif
	.endif

VictoryRoad_1F_Text_AlbertIntro:
	.ifdef ENGLISH
	.string "I didn't come all this way to lose now.\n"
	.string "That possibility doesn't exist!$"
	.else
	.ifdef GERMAN
	.string "Ich bin nicht hierher gekommen, um zu\n"
	.string "verlieren. Diese Option existiert nicht!$"
	.endif
	.endif

VictoryRoad_1F_Text_AlbertDefeat:
	.ifdef ENGLISH
	.string "Impossible…\n"
	.string "I lost?$"
	.else
	.ifdef GERMAN
	.string "Unmöglich…\n"
	.string "Ich habe verloren???$"
	.endif
	.endif

VictoryRoad_1F_Text_AlbertPostBattle:
	.ifdef ENGLISH
	.string "I lost here…\p"
	.string "That means I lack the qualifications\n"
	.string "to become the CHAMPION…$"
	.else
	.ifdef GERMAN
	.string "Ich habe hier verloren…\p"
	.string "Das heißt, mir fehlt noch eine Menge,\n"
	.string "um CHAMP werden zu können.$"
	.endif
	.endif

VictoryRoad_1F_Text_HopeIntro:
	.ifdef ENGLISH
	.string "This seemingly infinite and harsh road\n"
	.string "lives up to its name of VICTORY.$"
	.else
	.ifdef GERMAN
	.string "Diese unendliche, raue Straße wird\n"
	.string "ihrem Namen - SIEG - gerecht.$"
	.endif
	.endif

VictoryRoad_1F_Text_HopeDefeat:
	.ifdef ENGLISH
	.string "Your battle style is fantastic…$"
	.else
	.ifdef GERMAN
	.string "Dein Kampfstil ist fantastisch…$"
	.endif
	.endif

VictoryRoad_1F_Text_HopePostBattle:
	.ifdef ENGLISH
	.string "You seem to have the potential for\n"
	.string "becoming the CHAMPION.$"
	.else
	.ifdef GERMAN
	.string "Du hast wirklich das Potenzial, der\n"
	.string "CHAMP zu werden.$"
	.endif
	.endif

VictoryRoad_1F_Text_QuincyIntro:
	.ifdef ENGLISH
	.string "What is the VICTORY ROAD?\n"
	.string "I'll tell you if you win!$"
	.else
	.ifdef GERMAN
	.string "Was ist das? Die SIEGESSTRASSE?\n"
	.string "Wenn du gewinnst, verrat ich es dir.$"
	.endif
	.endif

VictoryRoad_1F_Text_QuincyDefeat:
	.ifdef ENGLISH
	.string "Okay!\n"
	.string "Well done!$"
	.else
	.ifdef GERMAN
	.string "Okay!\n"
	.string "Gut gemacht!$"
	.endif
	.endif

VictoryRoad_1F_Text_QuincyPostBattle:
	.ifdef ENGLISH
	.string "Getting through here safely--that's\n"
	.string "the final test for any TRAINER aiming\l"
	.string "to become the POKéMON CHAMPION.\p"
	.string "That's why it's called the VICTORY\n"
	.string "ROAD.$"
	.else
	.ifdef GERMAN
	.string "Hier sicher durchzukommen, das ist der\n"
	.string "letzte Test für einen TRAINER, der\l"
	.string "CHAMP werden will.\p"
	.string "Daher nennt man sie SIEGESSTRASSE.$"
	.endif
	.endif

VictoryRoad_1F_Text_KatelynnIntro:
	.ifdef ENGLISH
	.string "I have nothing to say to anyone\n"
	.string "that's come this far. Come on!$"
	.else
	.ifdef GERMAN
	.string "Ich habe jemandem, der so weit\n"
	.string "gekommen ist, nichts zu sagen. Los!$"
	.endif
	.endif

VictoryRoad_1F_Text_KatelynnDefeat:
	.ifdef ENGLISH
	.string "This is a disgrace…$"
	.else
	.ifdef GERMAN
	.string "Was für eine Blamage…$"
	.endif
	.endif

VictoryRoad_1F_Text_KatelynnPostBattle:
	.ifdef ENGLISH
	.string "Humph, go right on ahead.\n"
	.string "See if I care.$"
	.else
	.ifdef GERMAN
	.string "Hmpf, geh einfach geradeaus weiter.\n"
	.string "Mir doch egal…$"
	.endif
	.endif
