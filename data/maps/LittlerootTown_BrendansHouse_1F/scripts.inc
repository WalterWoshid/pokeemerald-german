.set LOCALID_MOM, 1
.set LOCALID_RIVAL_MOM, 4
.set LOCALID_RIVAL, 7

LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_MOM, 8, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_MOM, 4, 5
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_MOM, 9, 8
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVAL_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVAL_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVAL
	delay 30
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere:
	.ifdef ENGLISH
	.string "MOM: See, {PLAYER}?\n"
	.string "Isn't it nice in here, too?$"
	.else
	.ifdef GERMAN
	.string "MUTTER: Siehst du, {PLAYER}?\n"
	.string "Hier ist es doch auch schön, oder nicht?$"
	.endif
	.endif

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.ifdef ENGLISH
	.string "The mover's POKéMON do all the work\n"
	.string "of moving us in and cleaning up after.\l"
	.string "This is so convenient!\p"
	.string "{PLAYER}, your room is upstairs.\n"
	.string "Go check it out, dear!\p"
	.string "DAD bought you a new clock to mark\n"
	.string "our move here.\l"
	.string "Don't forget to set it!$"
	.else
	.ifdef GERMAN
	.string "Die POKéMON machen für uns den Umzug,\n"
	.string "räumen alles ein und machen sauber.\l"
	.string "Das ist doch so etwas von praktisch!\p"
	.string "{PLAYER}, dein Zimmer ist oben.\n"
	.string "Schau es dir doch mal an, Spatz!\p"
	.string "VATI hat dir eine neue Uhr zur\n"
	.string "Begrüßung geschenkt.\l"
	.string "Vergiss nicht, sie einzustellen!$"
	.endif
	.endif

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.ifdef ENGLISH
	.string "MOM: Well, {PLAYER}?\p"
	.string "Aren't you interested in seeing your\n"
	.string "very own room?$"
	.else
	.ifdef GERMAN
	.string "MUTTER: Nun, {PLAYER}?\p"
	.string "Bist du nicht neugierig, dein neues\n"
	.string "Zimmer zu sehen?$"
	.endif
	.endif

PlayersHouse_1F_Text_GoSetTheClock:
	.ifdef ENGLISH
	.string "MOM: {PLAYER}.\p"
	.string "Go set the clock in your room, honey.$"
	.else
	.ifdef GERMAN
	.string "MUTTER: {PLAYER}, Schatz!\p"
	.string "Stell bitte die Uhr in deinem Zimmer ein.$"
	.endif
	.endif

PlayersHouse_1F_Text_OhComeQuickly:
	.ifdef ENGLISH
	.string "MOM: Oh! {PLAYER}, {PLAYER}!\n"
	.string "Quick! Come quickly!$"
	.else
	.ifdef GERMAN
	.string "MUTTER: Oh! {PLAYER}! {PLAYER}!\n"
	.string "Schnell! Komm schnell her!$"
	.endif
	.endif

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.ifdef ENGLISH
	.string "MOM: Look! It's PETALBURG GYM!\n"
	.string "Maybe DAD will be on!$"
	.else
	.ifdef GERMAN
	.string "MUTTER: Da! Da ist die ARENA von\n"
	.string "BLÜTENBURG CITY!\l"
	.string "Ich glaube, VATI ist im Fernsehen!$"
	.endif
	.endif

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.ifdef ENGLISH
	.string "MOM: Oh… It's over.\p"
	.string "I think DAD was on, but we missed him.\n"
	.string "Too bad.$"
	.else
	.ifdef GERMAN
	.string "MUTTER: Oh… Schon vorbei.\p"
	.string "Ich glaube, VATI war im Fernsehen und\n"
	.string "wir haben ihn verpasst. Schade!$"
	.endif
	.endif

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.ifdef ENGLISH
	.string "Oh, yes.\n"
	.string "One of DAD's friends lives in town.\p"
	.string "PROF. BIRCH is his name.\p"
	.string "He lives right next door, so you should\n"
	.string "go over and introduce yourself.$"
	.else
	.ifdef GERMAN
	.string "Ach ja.\n"
	.string "Einer von VATIs Freunden lebt hier.\p"
	.string "PROF. BIRK ist sein Name.\p"
	.string "Er lebt gleich nebenan, daher solltest\n"
	.string "du hinübergehen und dich vorstellen.$"
	.endif
	.endif

PlayersHouse_1F_Text_SeeYouHoney:
	.ifdef ENGLISH
	.string "MOM: See you, honey!$"
	.else
	.ifdef GERMAN
	.string "MUTTER: Bis später, Spatz!$"
	.endif
	.endif

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.ifdef ENGLISH
	.string "MOM: Did you introduce yourself to\n"
	.string "PROF. BIRCH?$"
	.else
	.ifdef GERMAN
	.string "MUTTER: Hast du dich bei PROF. BIRK\n"
	.string "vorgestellt?$"
	.endif
	.endif

PlayersHouse_1F_Text_YouShouldRestABit:
	.ifdef ENGLISH
	.string "MOM: How are you doing, {PLAYER}?\n"
	.string "You look a little tired.\p"
	.string "I think you should rest a bit.$"
	.else
	.ifdef GERMAN
	.string "MUTTER: Wie geht es dir, {PLAYER}?\n"
	.string "Du siehst müde aus.\p"
	.string "Ich denke, du solltest dich etwas\n"
	.string "ausruhen.$"
	.endif
	.endif

PlayersHouse_1F_Text_TakeCareHoney:
	.ifdef ENGLISH
	.string "MOM: Take care, honey!$"
	.else
	.ifdef GERMAN
	.string "MUTTER: Pass auf dich auf, Schatz!$"
	.endif
	.endif

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.ifdef ENGLISH
	.string "MOM: Oh? Did DAD give you that BADGE?\p"
	.string "Then here's something from your MOM!$"
	.else
	.ifdef GERMAN
	.string "MUTTER: Oh! Hat VATI dir den ORDEN\n"
	.string "gegeben?\p"
	.string "Dann ist das hier von deiner MUTTI!$"
	.endif
	.endif

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.ifdef ENGLISH
	.string "Don't push yourself too hard, dear.\n"
	.string "You can always come home.\p"
	.string "Go for it, honey!$"
	.else
	.ifdef GERMAN
	.string "Überanstreng dich nicht, Liebes.\n"
	.string "Du kannst jederzeit nach Hause kommen.\p"
	.string "Und jetzt nichts wie los, Schatz!$"
	.endif
	.endif

PlayersHouse_1F_Text_IsThatAPokenav:
	.ifdef ENGLISH
	.string "MOM: What is that, honey? A POKéNAV?\n"
	.string "Someone from DEVON gave it to you?\p"
	.string "Well, honey, how about registering\n"
	.string "your mom?\p"
	.string "… … …$"
	.else
	.ifdef GERMAN
	.string "MUTTER: Was hast du denn da Schönes?\n"
	.string "Einen POKéNAV? Den hat dir jemand von\l"
	.string "DEVON gegeben?\p"
	.string "Und, Liebling? Möchtest du nicht deine\n"
	.string "MUTTER ins Verzeichnis aufnehmen?\p"
	.string "… … …$"
	.endif
	.endif

PlayersHouse_1F_Text_RegisteredMom:
	.ifdef ENGLISH
	.string "Registered MOM\n"
	.string "in the POKéNAV.$"
	.else
	.ifdef GERMAN
	.string "MUTTER wurde im POKéNAV-Verzeichnis\n"
	.string "eingetragen.$"
	.endif
	.endif

PlayersHouse_1F_Text_Vigoroth1:
	.ifdef ENGLISH
	.string "Fugiiiiih!$"
	.else
	.ifdef GERMAN
	.string "Fugiiiiih!$"
	.endif
	.endif

PlayersHouse_1F_Text_Vigoroth2:
	.ifdef ENGLISH
	.string "Huggoh, uggo uggo…$"
	.else
	.ifdef GERMAN
	.string "Huggoh, uggo uggo…$"
	.endif
	.endif

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.ifdef ENGLISH
	.string "INTERVIEWER: …We brought you this\n"
	.string "report from in front of PETALBURG GYM.$"
	.else
	.ifdef GERMAN
	.string "INTERVIEWER: Das war unsere Reportage\n"
	.string "über die ARENA in BLÜTENBURG CITY.$"
	.endif
	.endif

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.ifdef ENGLISH
	.string "There is a movie on TV.\p"
	.string "Two men are dancing on a big piano\n"
	.string "keyboard.\p"
	.string "Better get going!$"
	.else
	.ifdef GERMAN
	.string "Da läuft gerade ein Film.\p"
	.string "Zwei Männer tanzen auf riesengroßen\n"
	.string "Klaviertasten.\p"
	.string "Aber es wird Zeit aufzubrechen!$"
	.endif
	.endif

PlayersHouse_1F_Text_RunningShoesManual:
	.ifdef ENGLISH
	.string "It's the instruction booklet for the\n"
	.string "RUNNING SHOES.\p"
	.string "“Press the B Button to run while\n"
	.string "wearing your RUNNING SHOES.\p"
	.string "“Lace up your RUNNING SHOES and hit\n"
	.string "the road running!”$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Bedienungsanleitung für\n"
	.string "die TURBOTRETER.\p"
	.string "“Halte den B-Knopf gedrückt,\n"
	.string "wenn du diese TURBOTRETER anhast,\l"
	.string "um zu rennen!\p"
	.string "Schlüpf in diese TURBOTRETER und\n"
	.string "erobere die Welt da draußen!”$"
	.endif
	.endif

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.ifdef ENGLISH
	.string "DAD: Hm?\p"
	.string "Hey, it's {PLAYER}!\p"
	.string "It's been a while since I saw you,\n"
	.string "but you look…stronger, somehow.\p"
	.string "That's the impression I get.\n"
	.string "But your old man hasn't given up yet!\p"
	.string "Oh, yes, I have something for you.\n"
	.string "This came to you from someone named\l"
	.string "MR. BRINEY.$"
	.else
	.ifdef GERMAN
	.string "VATER: Hm?\p"
	.string "Hey, das ist ja {PLAYER}!\p"
	.string "Du hast uns ja schon lange nicht mehr\n"
	.string "besucht… Du siehst irgendwie\l"
	.string "stärker aus.\p"
	.string "Das ist zumindest mein Eindruck. Aber\n"
	.string "dein alter Herr gibt noch nicht auf.\p"
	.string "Oh, ich habe hier etwas für dich.\n"
	.string "Das soll ich dir von einem MR. BRACK\l"
	.string "geben.$"
	.endif
	.endif

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.ifdef ENGLISH
	.string "DAD: Hm, a TICKET for a ferry?\p"
	.string "If I recall, there are ferry ports in\n"
	.string "SLATEPORT and LILYCOVE.$"
	.else
	.ifdef GERMAN
	.string "VATER: Hm, ein TICKET für eine Fähre?\p"
	.string "Ich weiß, dass es in GRAPHITPORT CITY\n"
	.string "und SEEGRASULB CITY Anlegestellen für\l"
	.string "Fähren gibt.$"
	.endif
	.endif

PlayersHouse_1F_Text_BetterGetBackToGym:
	.ifdef ENGLISH
	.string "I'd better get back to PETALBURG GYM.\p"
	.string "MOM, thanks for looking after the house\n"
	.string "while I'm away.$"
	.else
	.ifdef GERMAN
	.string "Ich muss jetzt wieder in die ARENA von\n"
	.string "BLÜTENBURG CITY.\p"
	.string "Ich danke dir, dass du dich während\n"
	.string "meiner Abwesenheit um das Haus\l"
	.string "kümmerst.$"
	.endif
	.endif

PlayersHouse_1F_Text_DadShouldStayLonger:
	.ifdef ENGLISH
	.string "MOM: That DAD of yours…\p"
	.string "He comes home for the first time in a\n"
	.string "while, but all he talks about is POKéMON.\p"
	.string "He should relax and stay a little longer.$"
	.else
	.ifdef GERMAN
	.string "MUTTER: Das ist wieder typisch dein\n"
	.string "VATER…\p"
	.string "Da kommt er das erste Mal nach ewigen\n"
	.string "Zeiten nach Hause und spricht nur über\l"
	.string "POKéMON.\p"
	.string "Er sollte sich lieber ausruhen und\n"
	.string "etwas hier bleiben!$"
	.endif
	.endif

PlayersHouse_1F_Text_IsThatABreakingStory:
	.ifdef ENGLISH
	.string "MOM: Is that a breaking news story?$"
	.else
	.ifdef GERMAN
	.string "MUTTER: Sind das Sondernachrichten?$"
	.endif
	.endif

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.ifdef ENGLISH
	.string "We bring you this emergency\n"
	.string "news flash!\p"
	.string "In various HOENN locales, there have\n"
	.string "been reports of a BZZT…colored\l"
	.string "POKéMON in flight.\p"
	.string "The identity of this POKéMON is\n"
	.string "currently unknown.\p"
	.string "We now return you to the regular\n"
	.string "movie program.$"
	.else
	.ifdef GERMAN
	.string "Hier sind die Sondernachrichten.\p"
	.string "Wir haben die Meldung erhalten, dass in\n"
	.string "der HOENN-Region ein GRSSSS…\l"
	.string "farbiges POKéMON gesichtet wurde.\p"
	.string "Die Identität des POKéMON konnte\n"
	.string "bisher nicht festgestellt werden.\p"
	.string "Und damit schalten wir wieder um in\n"
	.string "unser laufendes Programm.$"
	.endif
	.endif

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.ifdef ENGLISH
	.string "MOM: {PLAYER}, did you catch that?\p"
	.string "What color did the announcer say\n"
	.string "that POKéMON was?$"
	.else
	.ifdef GERMAN
	.string "MUTTER: {PLAYER}, hast du das gehört?!?\p"
	.string "Was hat der Sprecher gesagt? Welche\n"
	.string "Farbe hat das POKéMON?$"
	.endif
	.endif

PlayersHouse_1F_Text_StillUnknownPokemon:
	.ifdef ENGLISH
	.string "MOM: Well, isn't that something!\n"
	.string "There are still unknown POKéMON.$"
	.else
	.ifdef GERMAN
	.string "MUTTER: Also, ist das nicht unglaublich?\n"
	.string "Es gibt tatsächlich noch unbekannte\l"
	.string "POKéMON!$"
	.endif
	.endif
