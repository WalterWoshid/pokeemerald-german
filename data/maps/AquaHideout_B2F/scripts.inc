.set LOCALID_MATT, 1
.set LOCALID_SUBMARINE, 4

AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_MATT
	setvar VAR_0x8009, LOCALID_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.ifdef ENGLISH
	.string "Hehehe…\p"
	.string "Got here already, did you?\n"
	.string "We underestimated you!\p"
	.string "But this is it!\p"
	.string "I'm a cut above the GRUNTS you've seen\n"
	.string "so far.\p"
	.string "I'm not stalling for time.\n"
	.string "I'm going to pulverize you!$"
	.else
	.ifdef GERMAN
	.string "Hehehehe… Du hast es tatsächlich\n"
	.string "bis hierher geschafft?\p"
	.string "Da haben wir dich wohl etwas\n"
	.string "unterschätzt!\p"
	.string "Aber hier geht es für dich nicht weiter!\p"
	.string "Ich bin besser als die anderen RÜPEL,\n"
	.string "die dir bisher begegnet sind.\p"
	.string "Ich schinde keine Zeit heraus. Ich\n"
	.string "werde dich pulverisieren!$"
	.endif
	.endif

AquaHideout_B2F_Text_MattDefeat:
	.ifdef ENGLISH
	.string "Hehehe…\n"
	.string "So, I lost, too…$"
	.else
	.ifdef GERMAN
	.string "Hehehe…\n"
	.string "Dann habe ich eben auch verloren. Pöh.$"
	.endif
	.endif

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.ifdef ENGLISH
	.string "Hehehe!\p"
	.string "While I was toying with you, our BOSS\n"
	.string "got through his preparations!$"
	.else
	.ifdef GERMAN
	.string "Hehehe!\p"
	.string "Während ich mit dir gespielt habe, hat\n"
	.string "sich unser BOSS vorbereitet!$"
	.endif
	.endif

AquaHideout_B2F_Text_MattPostBattle:
	.ifdef ENGLISH
	.string "Hehehe!\p"
	.string "Our BOSS has already gone on his way to\n"
	.string "some cave under the sea!\p"
	.string "If you're going to give chase, you'd\n"
	.string "better search the big, wide sea beyond\l"
	.string "LILYCOVE.\p"
	.string "But will you find it then?\n"
	.string "Hehehe!$"
	.else
	.ifdef GERMAN
	.string "Hehehe!\p"
	.string "Unser BOSS ist schon unterwegs zu\n"
	.string "einer Unterwasserhöhle!\p"
	.string "Falls du ihn verfolgen willst, suche\n"
	.string "doch mal die Tiefsee in der Region um\l"
	.string "SEEGRASULB CITY ab.\p"
	.string "Aber ob du ihn dort auch finden wirst?\n"
	.string "Hehehehehehe…$"
	.endif
	.endif

AquaHideout_B2F_Text_Grunt4Intro:
	.ifdef ENGLISH
	.string "Wahahah, I grew weary of waiting!\n"
	.string "You owe me a battle, too!$"
	.else
	.ifdef GERMAN
	.string "Wahahahah, ich bin müde vom Warten!\n"
	.string "Du schuldest mir einen Kampf!$"
	.endif
	.endif

AquaHideout_B2F_Text_Grunt4Defeat:
	.ifdef ENGLISH
	.string "Tired of waiting…\n"
	.string "Lost and dazed…$"
	.else
	.ifdef GERMAN
	.string "Des Wartens müde…\n"
	.string "Gedöst und verloren…$"
	.endif
	.endif

AquaHideout_B2F_Text_Grunt4PostBattle:
	.ifdef ENGLISH
	.string "BOSS…\n"
	.string "Is this good enough?$"
	.else
	.ifdef GERMAN
	.string "BOSS…\n"
	.string "Reicht das aus?$"
	.endif
	.endif

AquaHideout_B2F_Text_Grunt6Intro:
	.ifdef ENGLISH
	.string "Warp panels, the HIDEOUT's pride\n"
	.string "and joy!\p"
	.string "You're clueless about where you are,\n"
	.string "aren't you?\p"
	.string "Fluster and tire out the enemy, then\n"
	.string "lower the boom! That's our plan!$"
	.else
	.ifdef GERMAN
	.string "Teleporter… Der ganze Stolz des\n"
	.string "VERSTECKs!\p"
	.string "Du weißt gar nicht mehr, wo du gerade\n"
	.string "bist, stimmt’s? Kicher…\p"
	.string "Den Gegner verwirren, ermüden und dann\n"
	.string "auf ihn mit Gebrüll! Das ist der Plan!$"
	.endif
	.endif

AquaHideout_B2F_Text_Grunt6Defeat:
	.ifdef ENGLISH
	.string "What's wrong with you?\n"
	.string "You're not tired at all!$"
	.else
	.ifdef GERMAN
	.string "Was stimmt nicht mit dir?\n"
	.string "Du bist ja überhaupt nicht müde!$"
	.endif
	.endif

AquaHideout_B2F_Text_Grunt6PostBattle:
	.ifdef ENGLISH
	.string "That reminds me… I can't remember\n"
	.string "where I put the MASTER BALL.\p"
	.string "If I fail to guard it, our BOSS will\n"
	.string "chew me out…$"
	.else
	.ifdef GERMAN
	.string "Da fällt mir ein… Wo habe ich nur den\n"
	.string "MEISTERBALL hingelegt?\p"
	.string "Wenn ich den verloren habe, zieht mir\n"
	.string "der BOSS die Ohren lang…$"
	.endif
	.endif

AquaHideout_B2F_Text_Grunt8Intro:
	.ifdef ENGLISH
	.string "When I joined TEAM AQUA, the first\n"
	.string "thing I had to learn was how these\l"
	.string "warp panels connected.$"
	.else
	.ifdef GERMAN
	.string "Nachdem ich TEAM AQUA beigetreten war,\n"
	.string "musste ich erstmal lernen, wie diese\l"
	.string "Teleporter miteinander verbunden sind.$"
	.endif
	.endif

AquaHideout_B2F_Text_Grunt8Defeat:
	.ifdef ENGLISH
	.string "I was too occupied thinking about\n"
	.string "the warp panels…$"
	.else
	.ifdef GERMAN
	.string "Ich war viel zu sehr damit beschäftigt,\n"
	.string "über die Teleporter nachzudenken…$"
	.endif
	.endif

AquaHideout_B2F_Text_Grunt8PostBattle:
	.ifdef ENGLISH
	.string "I'll have to learn about how I can\n"
	.string "battle more effectively…$"
	.else
	.ifdef GERMAN
	.string "Ich muss lernen, wie ich effektiver\n"
	.string "kämpfen kann…$"
	.endif
	.endif
