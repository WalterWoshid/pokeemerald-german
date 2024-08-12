RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.ifdef ENGLISH
	.string "Yo, how's it going?\p"
	.string "Listen, my friend!\n"
	.string "Would you like to become the CHAMPION?\p"
	.string "I'm no TRAINER, not me, but I can\n"
	.string "sure give you winning advice.\p"
	.string "That's settled, then! We'll aim for the\n"
	.string "POKéMON CHAMPIONSHIP together!\p"
	.string "It's your job as a TRAINER to collect\n"
	.string "GYM BADGES, am I right?\p"
	.string "But GYM LEADERS aren't pushovers!\p"
	.string "And that's where I come in!\n"
	.string "I'm here to provide expert advice!\p"
	.string "ROXANNE, the GYM LEADER, is a user\n"
	.string "of ROCK-type POKéMON.\p"
	.string "The ROCK type is very durable, but\n"
	.string "it can't stand WATER-type and\l"
	.string "GRASS-type moves.\p"
	.string "Come see me afterwards, if you beat\n"
	.string "the GYM LEADER.\p"
	.string "Well, go for it!$"
	.else
	.ifdef GERMAN
	.string "Hi, wie geht’s?\p"
	.string "Hör zu, mein Freund!\n"
	.string "Würdest du gerne CHAMP werden?\p"
	.string "Ich bin kein TRAINER. Ich nicht. Aber\n"
	.string "ich kann dir trotzdem einen nützlichen\l"
	.string "Rat geben.\p"
	.string "Also, abgemacht! Wir werden zusammen\n"
	.string "nach der POKéMON MEISTERSCHAFT\l"
	.string "streben!\p"
	.string "Als TRAINER musst du die ORDEN der\n"
	.string "ARENen sammeln, habe ich Recht?\p"
	.string "Aber die ARENALEITER sind nicht gerade\n"
	.string "einfach zu besiegen!\p"
	.string "Und hier komme ich ins Spiel!\n"
	.string "Ich werde dir einen Expertentipp geben!\p"
	.string "FELIZIA, die ARENALEITERIN, setzt\n"
	.string "GESTEIN-POKéMON ein.\p"
	.string "Ein GESTEIN-POKéMON ist sehr zäh,\n"
	.string "hat aber gegen WASSER- und PFLANZEN-\l"
	.string "Attacken keine Chance.\p"
	.string "Komm wieder vorbei, wenn du die ARENA-\n"
	.string "LEITERIN besiegt hast.\p"
	.string "Nun zeig, was du drauf hast!$"
	.endif
	.endif

RustboroCity_Gym_Text_GymGuidePostVictory:
	.ifdef ENGLISH
	.string "Whoa! What a breathtaking victory!\n"
	.string "My cheering must've worked!\p"
	.string "Great!\n"
	.string "Check your TRAINER CARD.\p"
	.string "The STONE BADGE you got should be\n"
	.string "properly recorded on it.\p"
	.string "In other words…\p"
	.string "You've climbed the first step on\n"
	.string "the stairs to the CHAMPIONSHIP!\p"
	.string "That's got to feel awesome!$"
	.else
	.ifdef GERMAN
	.string "Hui! Was für ein atemberaubender Sieg!\n"
	.string "Meine Zurufe müssen gewirkt haben!\p"
	.string "Großartig!\n"
	.string "Schau mal auf deinen TRAINERPASS.\p"
	.string "Der STEINORDEN, den du gerade bekommen\n"
	.string "hast, müsste dort schon vermerkt sein.\p"
	.string "Nun hast du den ersten Schritt zur\n"
	.string "MEISTERSCHAFT schon erfolgreich\l"
	.string "hinter dir!\p"
	.string "Ein großartiges Gefühl!$"
	.endif
	.endif

RustboroCity_Gym_Text_JoshIntro:
	.ifdef ENGLISH
	.string "Don't take us GYM TRAINERS lightly!\n"
	.string "I'll show you why we're better!$"
	.else
	.ifdef GERMAN
	.string "Unterschätze die TRAINER einer ARENA\n"
	.string "nicht! Ich zeige dir, warum wir die\l"
	.string "Besten sind!$"
	.endif
	.endif

RustboroCity_Gym_Text_JoshDefeat:
	.ifdef ENGLISH
	.string "You were too good for me…$"
	.else
	.ifdef GERMAN
	.string "Du warst viel zu gut für mich…$"
	.endif
	.endif

RustboroCity_Gym_Text_JoshPostBattle:
	.ifdef ENGLISH
	.string "You haven't seen anything of the ROCK\n"
	.string "type's terrifying power!$"
	.else
	.ifdef GERMAN
	.string "Du hast noch gar nicht gesehen, was\n"
	.string "GESTEIN-POKéMON alles können.$"
	.endif
	.endif

RustboroCity_Gym_Text_TommyIntro:
	.ifdef ENGLISH
	.string "If you can't beat me, you won't stand\n"
	.string "a chance against ROXANNE!$"
	.else
	.ifdef GERMAN
	.string "Wenn du mich nicht besiegen kannst,\n"
	.string "hast du keine Chance gegen FELIZIA.$"
	.endif
	.endif

RustboroCity_Gym_Text_TommyDefeat:
	.ifdef ENGLISH
	.string "Wow! You've got some potential!$"
	.else
	.ifdef GERMAN
	.string "Wow! Du hast wirklich Talent!$"
	.endif
	.endif

RustboroCity_Gym_Text_TommyPostBattle:
	.ifdef ENGLISH
	.string "ROXANNE is stronger than me by\n"
	.string "several times.\p"
	.string "You'd better be on your guard!$"
	.else
	.ifdef GERMAN
	.string "FELIZIA ist um ein Vielfaches stärker\n"
	.string "als ich.\p"
	.string "Du solltest dich besser wappnen!$"
	.endif
	.endif

RustboroCity_Gym_Text_MarcIntro:
	.ifdef ENGLISH
	.string "We might be in the middle of town,\n"
	.string "but so what?\p"
	.string "My ROCK POKéMON need room to\n"
	.string "rampage!$"
	.else
	.ifdef GERMAN
	.string "Wir sind hier mitten in einer Stadt,\n"
	.string "na und?!?\p"
	.string "Meine GESTEIN-POKéMON müssen sich\n"
	.string "einfach austoben!$"
	.endif
	.endif

RustboroCity_Gym_Text_MarcDefeat:
	.ifdef ENGLISH
	.string "Oh, man oh man!\n"
	.string "Our challenger is one feisty customer!$"
	.else
	.ifdef GERMAN
	.string "Mann! Mann! Mann! Unser Herausforderer\n"
	.string "ist aber ein lebhaftes Wesen!$"
	.endif
	.endif

RustboroCity_Gym_Text_MarcPostBattle:
	.ifdef ENGLISH
	.string "I have to hand it to our LEADER.\p"
	.string "It took smarts and sense for her to\n"
	.string "pick the ROCK type at her young age.$"
	.else
	.ifdef GERMAN
	.string "Ich muss es unserer LEITERIN\n"
	.string "überlassen.\p"
	.string "Sie ist clever und geschickt, da sie in\n"
	.string "ihrem zarten Alter schon GESTEIN-\l"
	.string "POKéMON aufzieht.$"
	.endif
	.endif

RustboroCity_Gym_Text_RoxanneIntro:
	.ifdef ENGLISH
	.string "Hello, I am ROXANNE, the RUSTBORO\n"
	.string "POKéMON GYM LEADER.\p"
	.string "I became a GYM LEADER so that I might\n"
	.string "apply what I learned at the POKéMON\l"
	.string "TRAINER'S SCHOOL in battle.\p"
	.string "Would you kindly demonstrate how you\n"
	.string "battle, and with which POKéMON?$"
	.else
	.ifdef GERMAN
	.string "Hallo, ich bin FELIZIA, die LEITERIN der\n"
	.string "ARENA von METAROST CITY.\p"
	.string "Ich wurde ARENALEITERIN, um mein\n"
	.string "Wissen, das ich in der POKéMON TRAINER-\l"
	.string "SCHULE erworben habe, umzusetzen.\p"
	.string "Würdest du mir bitte zeigen, wie du\n"
	.string "kämpfst und mit welchen POKéMON?$"
	.endif
	.endif

RustboroCity_Gym_Text_RoxanneDefeat:
	.ifdef ENGLISH
	.string "So…\n"
	.string "I lost…\p"
	.string "It seems that I still have much more\n"
	.string "to learn…\p"
	.string "I understand.\p"
	.string "The POKéMON LEAGUE's rules state\n"
	.string "that TRAINERS are to be given this\l"
	.string "if they defeat a GYM LEADER.\p"
	.string "Please accept the official POKéMON\n"
	.string "LEAGUE STONE BADGE.$"
	.else
	.ifdef GERMAN
	.string "So…\n"
	.string "Ich habe verloren…\p"
	.string "Es scheint, ich muss noch eine ganze\n"
	.string "Menge lernen…\p"
	.string "Ich verstehe schon.\p"
	.string "Die Regeln der POKéMON LIGA schreiben\n"
	.string "vor, dass TRAINER, die einen ARENA-\l"
	.string "LEITER besiegt haben, dieses erhalten.\p"
	.string "Bitte nimm den offiziellen POKéMON LIGA\n"
	.string "STEINORDEN an!$"
	.endif
	.endif

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.ifdef ENGLISH
	.string "{PLAYER} received the STONE BADGE\n"
	.string "from ROXANNE.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} hat den STEINORDEN von\n"
	.string "FELIZIA erhalten.$"
	.endif
	.endif

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.ifdef ENGLISH
	.string "The STONE BADGE heightens the ATTACK\n"
	.string "power of your POKéMON.\p"
	.string "It also enables them to use the HM move\n"
	.string "CUT outside of battle.\p"
	.string "Please take this with you, too.$"
	.else
	.ifdef GERMAN
	.string "Der STEINORDEN erhöht die Kraft der\n"
	.string "ATTACKEN deiner POKéMON.\p"
	.string "Außerdem sind sie nun in der Lage, die\n"
	.string "VM ZERSCHNEIDER auch außerhalb eines\l"
	.string "Kampfes einzusetzen.\p"
	.string "Dies möchte ich dir auch noch geben.$"
	.endif
	.endif

RustboroCity_Gym_Text_ExplainRockTomb:
	.ifdef ENGLISH
	.string "That TECHNICAL MACHINE, TM39,\n"
	.string "contains ROCK TOMB.\p"
	.string "It not only inflicts damage by dropping\n"
	.string "rocks, it also lowers SPEED.\p"
	.string "If you use a TM, it instantly teaches\n"
	.string "the move to a POKéMON.\p"
	.string "Remember, a TM can be used only once,\n"
	.string "so think before you use it.$"
	.else
	.ifdef GERMAN
	.string "Diese TM39 enthält FELSGRAB.\p"
	.string "Sie richtet nicht nur durch das Fallen\n"
	.string "von Steinen Schaden an, sondern\l"
	.string "reduziert auch die INITIATIVE.\p"
	.string "Sobald du eine TM aktivierst, wird die\n"
	.string "Attacke einem POKéMON beigebracht.\p"
	.string "Aber vergiss nicht, dass eine TM nur\n"
	.string "einmal beigebracht werden kann. Ihr\l"
	.string "Einsatz will also überlegt sein.$"
	.endif
	.endif

RustboroCity_Gym_Text_RoxannePostBattle:
	.ifdef ENGLISH
	.string "Since you are so strong, you should\n"
	.string "challenge other GYM LEADERS.\p"
	.string "By battling many TRAINERS, you should\n"
	.string "learn many things.$"
	.else
	.ifdef GERMAN
	.string "Da du so stark bist, solltest du auch\n"
	.string "die anderen ARENALEITER\l"
	.string "herausfordern.\p"
	.string "Du lernst wertvolle Dinge dazu, wenn du\n"
	.string "gegen viele TRAINER antrittst.$"
	.endif
	.endif

RustboroCity_Gym_Text_GymStatue:
	.ifdef ENGLISH
	.string "RUSTBORO CITY POKéMON GYM$"
	.else
	.ifdef GERMAN
	.string "POKéMON ARENA von METAROST CITY$"
	.endif
	.endif

RustboroCity_Gym_Text_GymStatueCertified:
	.ifdef ENGLISH
	.string "RUSTBORO CITY POKéMON GYM\p"
	.string "ROXANNE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
	.else
	.ifdef GERMAN
	.string "POKéMON ARENA von METAROST CITY\p"
	.string "FELIZIAS ANERKANNTE TRAINER:\n"
	.string "{PLAYER}$"
	.endif
	.endif

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.ifdef ENGLISH
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "ROXANNE: Oh, hello, {PLAYER}?\n"
	.string "This is ROXANNE of RUSTBORO CITY.\p"
	.string "I heard from BRAWLY that you're\n"
	.string "moving up through the ranks of\l"
	.string "TRAINERS at an incredible clip.\p"
	.string "Well, I'd rather not think that\n"
	.string "I can't beat you.\p"
	.string "I promise, I will shape up my GYM\n"
	.string "so that you may challenge us again.\p"
	.string "I hope you'll be looking forward to\n"
	.string "that occasion as much as me!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"
	.else
	.ifdef GERMAN
	.string "… … … … …\n"
	.string "…\l"
	.string "… … … … …\l"
	.string "…\l"
	.string "Piep!\p"
	.string "FELIZIA: Oh, hallo {PLAYER}.\n"
	.string "Hier ist FELIZIA aus METAROST.\p"
	.string "KAMILLO hat mir erzählt, dass du\n"
	.string "die TRAINER in atemberaubender\l"
	.string "Geschwindigkeit aussuchst und\l"
	.string "besiegst.\p"
	.string "Ich denke aber nicht, dass ich\n"
	.string "gegen dich verlieren werde.\p"
	.string "Ich werde meine ARENA wieder\n"
	.string "aufbauen. Dann steht deiner He-\l"
	.string "rausforderung nichts mehr im Weg.\p"
	.string "Du bist doch bestimmt genauso\n"
	.string "ungeduldig wie ich, nicht wahr?\p"
	.string "… … … … …\n"
	.string "…\l"
	.string "… … … … …\l"
	.string "…\l"
	.string "Klick!$"
	.endif
	.endif

RustboroCity_Gym_Text_RegisteredRoxanne:
	.ifdef ENGLISH
	.string "Registered GYM LEADER ROXANNE\n"
	.string "in the POKéNAV.$"
	.else
	.ifdef GERMAN
	.string "ARENALEITERIN FELIZIA wurde im\n"
	.string "POKéNAV-Verzeichnis eingetragen.$"
	.endif
	.endif

RustboroCity_Gym_Text_RoxannePreRematch:
	.ifdef ENGLISH
	.string "ROXANNE: I'm so glad to see you again.\n"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become. Let us battle!$"
	.else
	.ifdef GERMAN
	.string "FELIZIA: Ich freue mich, dich wieder zu\n"
	.string "sehen. Ich bin die ARENALEITERIN\l"
	.string "FELIZIA.\p"
	.string "Ich bin sicher, wir beide haben seit\n"
	.string "unserer letzten Begegnung viele\l"
	.string "Erfahrungen gesammelt.\p"
	.string "Ich würde gerne sehen, um wie vieles\n"
	.string "besser wir beide geworden sind. Los!$"
	.endif
	.endif

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.ifdef ENGLISH
	.string "Grr…\n"
	.string "Again, I have lost…$"
	.else
	.ifdef GERMAN
	.string "Grrrrrr…\n"
	.string "Ich habe schon wieder verloren…$"
	.endif
	.endif

RustboroCity_Gym_Text_RoxannePostRematch:
	.ifdef ENGLISH
	.string "ROXANNE: I still have much to learn\n"
	.string "when it comes to battling POKéMON.\p"
	.string "That awareness makes me love battling\n"
	.string "all that much more!$"
	.else
	.ifdef GERMAN
	.string "FELIZIA: Ich muss anscheindend noch\n"
	.string "viel über POKéMON-Kämpfe lernen.\p"
	.string "Aber genau deshalb liebe ich das\n"
	.string "Kämpfen um so mehr.$"
	.endif
	.endif

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.ifdef ENGLISH
	.string "ROXANNE: I'm so glad to see you again.\n"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become…\p"
	.string "Oh, no…\n"
	.string "You only have one POKéMON with you?\p"
	.string "Please return with at least one more\n"
	.string "POKéMON.$"
	.else
	.ifdef GERMAN
	.string "FELIZIA: Ich freue mich, dich wieder zu\n"
	.string "sehen. Ich bin die ARENALEITERIN\l"
	.string "FELIZIA.\p"
	.string "Ich bin sicher, wir beide haben seit\n"
	.string "unserer letzten Begegnung viele\l"
	.string "Erfahrungen gesammelt.\p"
	.string "Oh… Schade!\n"
	.string "Du hast ja nur ein POKéMON dabei!\p"
	.string "Bitte komm doch wieder, wenn du\n"
	.string "mindestens zwei dabei hast.$"
	.endif
	.endif
