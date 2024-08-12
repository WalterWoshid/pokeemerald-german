.set LOCALID_ARCHIE, 2
.set LOCALID_OLD_LADY, 3
.set LOCALID_GRUNT_1, 4
.set LOCALID_GRUNT_2, 5
.set LOCALID_GRUNT_3, 6
.set LOCALID_GRUNT_4, 7
.set LOCALID_MAXIE, 8

MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MAXIE, 23, 6
	setobjectxyperm LOCALID_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.ifdef ENGLISH
	.string "No! Those TEAM MAGMA goons got\n"
	.string "here ahead of us!\p"
	.string "We can't fall behind!$"
	.else
	.ifdef GERMAN
	.string "Nein! Die Idioten von TEAM MAGMA waren\n"
	.string "vor uns hier!\p"
	.string "Wir müssen sie einholen!$"
	.endif
	.endif

MtPyre_Summit_Text_Grunt1Defeat:
	.ifdef ENGLISH
	.string "I thought you were one of the MAGMAS\n"
	.string "who happened to come back…$"
	.else
	.ifdef GERMAN
	.string "Ich dachte, du würdest zu TEAM MAGMA\n"
	.string "gehören und wärest nochmal\l"
	.string "zurückgekommen.$"
	.endif
	.endif

MtPyre_Summit_Text_Grunt1PostBattle:
	.ifdef ENGLISH
	.string "Yeah, so you are strong…\n"
	.string "But there're a lot of us!$"
	.else
	.ifdef GERMAN
	.string "Ja, du bist ganz schön stark…\n"
	.string "Aber wir sind viele…$"
	.endif
	.endif

MtPyre_Summit_Text_Grunt2Intro:
	.ifdef ENGLISH
	.string "Hah!\n"
	.string "Too bad for you!\p"
	.string "If you came earlier, you only would've\n"
	.string "had to battle the wimpy TEAM MAGMA.\p"
	.string "But since you arrived now, you have\n"
	.string "to take on us toughies!$"
	.else
	.ifdef GERMAN
	.string "Hah!\n"
	.string "Pech für dich!\p"
	.string "Wärest du eher hier gewesen, hättest du\n"
	.string "nur gegen das weinerliche TEAM MAGMA\l"
	.string "antreten müssen.\p"
	.string "Aber jetzt muss du gegen unsere Stärke\n"
	.string "antreten.$"
	.endif
	.endif

MtPyre_Summit_Text_Grunt2Defeat:
	.ifdef ENGLISH
	.string "Urgh… I should've let you take on\n"
	.string "TEAM MAGMA first…$"
	.else
	.ifdef GERMAN
	.string "Argh… Ich hätte dich erst gegen TEAM\n"
	.string "MAGMA kämpfen lassen sollen…$"
	.endif
	.endif

MtPyre_Summit_Text_Grunt2PostBattle:
	.ifdef ENGLISH
	.string "You don't know anything!\n"
	.string "So why are you messing with us?$"
	.else
	.ifdef GERMAN
	.string "Du weißt doch gar nichts! Misch dich\n"
	.string "besser nicht in unsere Sachen ein!$"
	.endif
	.endif

MtPyre_Summit_Text_Grunt3Intro:
	.ifdef ENGLISH
	.string "You…\n"
	.string "We saw you at MT. CHIMNEY.\p"
	.string "You don't belong to either TEAM,\n"
	.string "so why would you be here?$"
	.else
	.ifdef GERMAN
	.string "Hey…\n"
	.string "Ich kenne dich doch vom SCHLOTBERG!\p"
	.string "Du gehörst keinem TEAM an. Warum bist\n"
	.string "du hier?$"
	.endif
	.endif

MtPyre_Summit_Text_Grunt3Defeat:
	.ifdef ENGLISH
	.string "If you're going to mess with anyone,\n"
	.string "let it be TEAM MAGMA…$"
	.else
	.ifdef GERMAN
	.string "Wenn du dich schon in fremde Ange-\n"
	.string "legenheiten einmischen musst, dann\l"
	.string "mach das bei TEAM MAGMA!$"
	.endif
	.endif

MtPyre_Summit_Text_Grunt3PostBattle:
	.ifdef ENGLISH
	.string "Heh, it doesn't matter!\n"
	.string "We bought ourselves some time!\p"
	.string "The BOSS should have snatched what\n"
	.string "he was after!$"
	.else
	.ifdef GERMAN
	.string "Ach, das spielt keine Rolle.\n"
	.string "Wir haben Zeit herausgeschlagen!\p"
	.string "Der BOSS müsste mittlerweile haben, was\n"
	.string "er besorgen wollte!$"
	.endif
	.endif

MtPyre_Summit_Text_Grunt4Intro:
	.ifdef ENGLISH
	.string "Oh, I know!\n"
	.string "You tried to join TEAM MAGMA,\l"
	.string "but they wouldn't have you!\p"
	.string "Well, don't think that we'll let you\n"
	.string "join our TEAM AQUA!$"
	.else
	.ifdef GERMAN
	.string "Ach, ich weiß!\n"
	.string "Du wolltest Mitglied bei TEAM MAGMA\l"
	.string "werden, aber die wollten dich nicht!\p"
	.string "Denk nur nicht, dass du Mitglied bei\n"
	.string "TEAM AQUA werden kannst!$"
	.endif
	.endif

MtPyre_Summit_Text_Grunt4Defeat:
	.ifdef ENGLISH
	.string "If you want to join TEAM AQUA that\n"
	.string "badly, we can consider it…$"
	.else
	.ifdef GERMAN
	.string "Wenn du TEAM AQUA unbedingt\n"
	.string "beitreten willst, können wir darüber\l"
	.string "reden…$"
	.endif
	.endif

MtPyre_Summit_Text_Grunt4PostBattle:
	.ifdef ENGLISH
	.string "We have a great combination going\n"
	.string "with us members and our leader.$"
	.else
	.ifdef GERMAN
	.string "Wir Mitglieder und unser Boss sind\n"
	.string "das perfekte Team.$"
	.endif
	.endif

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.ifdef ENGLISH
	.string "ARCHIE: TEAM MAGMA's MAXIE got ahead\n"
	.string "of us, but we also got what we wanted.\p"
	.string "The RED ORB preserved at MT. PYRE…\n"
	.string "I, ARCHIE, now have it in my possession!\p"
	.string "Fufufu… Now we can bring our ultimate\n"
	.string "objective to fruition!\p"
	.string "Okay, TEAM!\n"
	.string "We're pulling out!$"
	.else
	.ifdef GERMAN
	.string "ADRIAN: MARC von TEAM MAGMA mag uns\n"
	.string "vielleicht einen Schritt voraus sein,\l"
	.string "aber wir haben das, was wir wollten.\p"
	.string "Die ROTE KUGEL vom PYROBERG…\n"
	.string "Ich, ADRIAN, halte sie endlich in meinen\l"
	.string "Händen!\p"
	.string "Hähähä… Nun werden sich unsere\n"
	.string "ultimativen Träume erfüllen!\p"
	.string "Okay, TEAM!\n"
	.string "Los geht’s!$"
	.endif
	.endif

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.ifdef ENGLISH
	.string "Oh, no…\n"
	.string "This cannot happen…\p"
	.string "Not only the BLUE ORB, but even\n"
	.string "the RED ORB has been taken…\p"
	.string "The BLUE ORB and RED ORB must never\n"
	.string "be separated. They belong together.\p"
	.string "What are those men trying to do with\n"
	.string "the two ORBS?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Oh, yes. Was it TEAM MAGMA who came\n"
	.string "and took the BLUE ORB first?\p"
	.string "Well, in their haste, they left this\n"
	.string "behind.\p"
	.string "I couldn't imagine what exactly it\n"
	.string "could be.\p"
	.string "I would like you to have it.\n"
	.string "Perhaps it will be useful in some way.$"
	.else
	.ifdef GERMAN
	.string "Oh, nein…\n"
	.string "Das darf nicht sein…\p"
	.string "Nicht nur die BLAUE, sondern auch die\n"
	.string "ROTE KUGEL wurde gestohlen…\p"
	.string "Die beiden KUGELn dürfen niemals\n"
	.string "voneinander getrennt werden.\l"
	.string "Sie gehören zusammen.\p"
	.string "Was wollen diese Männer nur mit den\n"
	.string "beiden KUGELn?\p"
	.string "… … … … …\n"
	.string "…\l"
	.string "… … … … …\l"
	.string "…\p"
	.string "Ich meine, TEAM MAGMA wäre als Erstes\n"
	.string "hier gewesen und hat die BLAUE KUGEL\l"
	.string "mitgenommen.\p"
	.string "Aber sie hatten es sehr eilig und haben\n"
	.string "dies hier zurückgelassen.\p"
	.string "Ich habe keine Ahnung, was das ist.\p"
	.string "Du kannst es gerne haben.\n"
	.string "Vielleicht kannst du damit was\l"
	.string "anfangen?$"
	.endif
	.endif

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.ifdef ENGLISH
	.string "The BLUE ORB and RED ORB taken by\n"
	.string "those sinister men…\p"
	.string "They must never be apart…\n"
	.string "I fear something terrible will happen…$"
	.else
	.ifdef GERMAN
	.string "Die BLAUE und die ROTE KUGEL wurden von\n"
	.string "diesen gemeinen Männern fortgenommen…\p"
	.string "Sie dürfen niemals getrennt werden…\n"
	.string "Ich habe Angst, dass etwas\l"
	.string "Schreckliches passieren wird…$"
	.endif
	.endif

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.ifdef ENGLISH
	.string "Oh, my goodness…\p"
	.string "You say that both GROUDON and KYOGRE\n"
	.string "have been awakened?\p"
	.string "It is said that the BLUE ORB and\n"
	.string "the RED ORB quelled the rage of\l"
	.string "the two POKéMON…\p"
	.string "It is also said that the true owner\n"
	.string "of the ORBS still exists.\p"
	.string "However, no one knows who, or what\n"
	.string "exactly, the ORBS belong to.\p"
	.string "It could be a human, or perhaps\n"
	.string "a POKéMON, but no one knows.$"
	.else
	.ifdef GERMAN
	.string "Ach, du meine Güte…\p"
	.string "Du sagst, GROUDON und KYOGRE seien\n"
	.string "beide aufgewacht?\p"
	.string "Man sagt, die BLAUE und die ROTE KUGEL\n"
	.string "bezwingen die Wut dieser beiden\l"
	.string "POKéMON…\p"
	.string "Und man sagt auch, dass der wahre\n"
	.string "Besitzer der KUGELn immer noch lebt.\p"
	.string "Aber niemand weiß, zu wem die KUGELn\n"
	.string "gehören.\p"
	.string "Es könnte ein Mensch, aber auch ein\n"
	.string "POKéMON sein. Niemand weiß es.$"
	.endif
	.endif

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.ifdef ENGLISH
	.string "The two men who took the ORBS came\n"
	.string "back to return them on their own.\p"
	.string "Those men…\n"
	.string "Perhaps they are not so evil after all…$"
	.else
	.ifdef GERMAN
	.string "Die beiden Männer, die die KUGELn\n"
	.string "genommen hatten, haben sie freiwillig\l"
	.string "wieder zurückgebracht.\p"
	.string "Diese Männer…\n"
	.string "Vielleicht sind sie doch keine\l"
	.string "schlechten Kerle…$"
	.endif
	.endif

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.ifdef ENGLISH
	.string "The embodiments of the land, sea,\n"
	.string "and the sky…\p"
	.string "That is said to be the identities of\n"
	.string "the super-ancient POKéMON…\p"
	.string "In the same way that we humans and\n"
	.string "POKéMON have life, our world, too,\l"
	.string "is alive…\p"
	.string "The super-ancient POKéMON have\n"
	.string "taught us that…$"
	.else
	.ifdef GERMAN
	.string "Die Gestaltung des Landes, des Meeres\n"
	.string "und des Himmels…\p"
	.string "Man sagt, dass sich hier die Persönlich-\n"
	.string "keiten uralter POKéMON widerspiegeln…\p"
	.string "So, wie Menschen und POKéMON leben,\n"
	.string "lebt auch die Welt…\p"
	.string "Das haben wir von den uralten POKéMON\n"
	.string "gelernt…$"
	.endif
	.endif

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.ifdef ENGLISH
	.string "MT. PYRE is where we calm the spirits\n"
	.string "of POKéMON that have passed on…\p"
	.string "This is a high place where one can\n"
	.string "see all of HOENN…\p"
	.string "The disembodied spirits of POKéMON\n"
	.string "must find solace here…\p"
	.string "Is it coincidence that you are here…\p"
	.string "Will you hear out my tale? A tale long\n"
	.string "told in the HOENN region?$"
	.else
	.ifdef GERMAN
	.string "Am PYROBERG legen wir die Geister der\n"
	.string "POKéMON, die von uns gegangen sind, zur\l"
	.string "Ruhe…\p"
	.string "Von hier aus hat man einen Ausblick\n"
	.string "über die ganze Region von HOENN…\p"
	.string "Die körperlosen Geister der POKéMON\n"
	.string "finden hier ihre Ruhe…\p"
	.string "Es ist Fügung, dass du jetzt hier bist…\p"
	.string "Möchtest du meine Geschichte hören?\n"
	.string "Eine lange, sehr alte Geschichte der\l"
	.string "HOENN-Region?$"
	.endif
	.endif

MtPyre_Summit_Text_GroudonKyogreTale:
	.ifdef ENGLISH
	.string "It happened long, long ago…\p"
	.string "The world was wracked by a ferocious\n"
	.string "clash between the POKéMON of the land\l"
	.string "and the POKéMON of the sea…\p"
	.string "The POKéMON of the land raised\n"
	.string "mountains and created continents…\p"
	.string "The POKéMON of the sea raised huge\n"
	.string "waves and carved out oceans…\p"
	.string "Their fierce duel raged without end.\p"
	.string "The world was engulfed in massive\n"
	.string "infernos and vicious storms.\p"
	.string "The BLUE ORB and the RED ORB brought\n"
	.string "an end to the calamity.\p"
	.string "Light poured from the two ORBS and\n"
	.string "becalmed the enraged adversaries.\p"
	.string "The pair, made docile, dove deep into\n"
	.string "the sea where eventually they\l"
	.string "disappeared…$"
	.else
	.ifdef GERMAN
	.string "Es geschah vor langer, langer Zeit…\p"
	.string "Die Welt erbebte unter der\n"
	.string "Auseinandersetzung der POKéMON des\l"
	.string "Landes mit den POKéMON des Meeres…\p"
	.string "Die POKéMON des Landes erschufen\n"
	.string "Berge und Kontinente…\p"
	.string "Die POKéMON des Meeres erschufen hohe\n"
	.string "Wellen und tiefe Meeresbecken…\p"
	.string "Das Duell wütete ohne absehbares Ende.\p"
	.string "Die Welt wurde von erbarmungslosen\n"
	.string "Stürmen und unglaublichen Infernos\l"
	.string "heimgesucht.\p"
	.string "Die BLAUE und die ROTE KUGEL setzten\n"
	.string "schließlich diesem Kampf ein Ende.\p"
	.string "Licht strahlte von den beiden KUGELn\n"
	.string "und beruhigte die Kontrahenten.\p"
	.string "Die beruhigten POKéMON verbargen sich\n"
	.string "in den Tiefen des Meeres und der Erde,\l"
	.string "und eines Tages verschwanden sie.$"
	.endif
	.endif

MtPyre_Summit_Text_WellThatTooIsFine:
	.ifdef ENGLISH
	.string "I see…\n"
	.string "Well, that, too, is fine…$"
	.else
	.ifdef GERMAN
	.string "Ich verstehe…\n"
	.string "Nun, das ist auch in Ordnung…$"
	.endif
	.endif

MtPyre_Summit_Text_MaxieSilence:
	.ifdef ENGLISH
	.string "MAXIE: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"
	.else
	.ifdef GERMAN
	.string "MARC: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"
	.endif
	.endif

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.ifdef ENGLISH
	.string "It is my role to pass on the legends\n"
	.string "of HOENN to future generations.\p"
	.string "And the crisis that just ended in\n"
	.string "SOOTOPOLIS rewrote a legend…\p"
	.string "Have you the time to hear the new\n"
	.string "legend of HOENN?$"
	.else
	.ifdef GERMAN
	.string "Meine Aufgabe ist es, die Legenden von\n"
	.string "HOENN an die nachfolgenden\l"
	.string "Generationen weiterzugeben.\p"
	.string "Die Krise von XENEROVILLE war die\n"
	.string "Wiederholung der Legende…\p"
	.string "Hast du Zeit, dir die neue Legende von\n"
	.string "HOENN anzuhören?$"
	.endif
	.endif

MtPyre_Summit_Text_HoennTrioTale:
	.ifdef ENGLISH
	.string "It happened long, long ago…\p"
	.string "The world was wracked by a ferocious\n"
	.string "clash between the POKéMON of the land\l"
	.string "and the POKéMON of the sea…\p"
	.string "The POKéMON of the land raised\n"
	.string "mountains and created continents…\p"
	.string "The POKéMON of the sea raised huge\n"
	.string "waves and carved out oceans…\p"
	.string "Their fierce duel raged without end.\p"
	.string "The world was engulfed in massive\n"
	.string "fires and vicious storms.\p"
	.string "It was then that the POKéMON of\n"
	.string "the sky descended from a storm.\p"
	.string "The POKéMON, shining a vivid green,\n"
	.string "becalmed the two enraged POKéMON.\p"
	.string "Then, its duty done, the green POKéMON\n"
	.string "flew off into the wild blue yonder…$"
	.else
	.ifdef GERMAN
	.string "Es geschah vor langer, langer Zeit…\p"
	.string "Die Welt erbebte unter der\n"
	.string "Auseinandersetzung des POKéMON des\l"
	.string "Landes mit dem POKéMON des Meeres…\p"
	.string "Das POKéMON des Landes erschuf\n"
	.string "Berge und Kontinente…\p"
	.string "Das POKéMON des Meeres erschuf hohe\n"
	.string "Wellen und tiefe Meeresbecken…\p"
	.string "Das Duell wütete ohne absehbares Ende.\p"
	.string "Die Welt wurde von erbarmungslosen\n"
	.string "Stürmen und unglaublichen Infernos\l"
	.string "heimgesucht.\p"
	.string "Da stieg ein POKéMON in einem Sturm aus\n"
	.string "den Wolken herab.\p"
	.string "Dieses POKéMON, welches in einem\n"
	.string "lebendigen Grün glänzte, beruhigte die\l"
	.string "beiden POKéMON.\p"
	.string "Und als es seine Aufgabe erfüllt hatte,\n"
	.string "stieg das POKéMON wieder in das Blau\l"
	.string "des Himmels hinauf…$"
	.endif
	.endif

