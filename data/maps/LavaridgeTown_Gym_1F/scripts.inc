.set LOCALID_COLE, 2
.set LOCALID_GERALD, 3
.set LOCALID_AXLE, 4
.set LOCALID_DANIELLE, 5

LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.ifdef ENGLISH
	.string "Hey, how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "LAVARIDGE's GYM LEADER FLANNERY\n"
	.string "uses FIRE-type POKéMON.\p"
	.string "Her passion for POKéMON burns stronger\n"
	.string "and hotter than a volcano.\p"
	.string "Don't get too close to her--you'll burn!\n"
	.string "Hose her down with water and then\l"
	.string "go for it!$"
	.else
	.ifdef GERMAN
	.string "Na, wie sieht es aus, auf dem Weg zum\n"
	.string "CHAMP, {PLAYER}?\p"
	.string "Die ARENALEITERIN von BAD LAVA-\n"
	.string "STADT, FLAVIA, setzt FEUER-POKéMON\l"
	.string "ein.\p"
	.string "Ihre Leidenschaft für POKéMON brennt\n"
	.string "heißer und stärker als ein Vulkan.\p"
	.string "Komm ihr nicht zu nahe - du verbrennst\n"
	.string "dich! Lösche die Glut mit Wasser und\l"
	.string "dann besiege sie!$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.ifdef ENGLISH
	.string "Yow! That was a scorching-hot battle!$"
	.else
	.ifdef GERMAN
	.string "Hui! Das war ein glühend heißer Kampf!$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.ifdef ENGLISH
	.string "Owowowowow!\n"
	.string "Yikes, it's hot!$"
	.else
	.ifdef GERMAN
	.string "Auauauauau!\n"
	.string "Hach, ist das heiß!$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.ifdef ENGLISH
	.string "I'm blinded by sweat in my eyes…$"
	.else
	.ifdef GERMAN
	.string "Der Schweiß lief mir in die Augen…$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.ifdef ENGLISH
	.string "Being buried in hot sand promotes\n"
	.string "circulation.\p"
	.string "It's effective for healing pain in\n"
	.string "your joints.$"
	.else
	.ifdef GERMAN
	.string "Ein Bad im heißen Sand regt den\n"
	.string "Kreislauf an.\p"
	.string "Auch Gelenkschmerzen lassen sich damit\n"
	.string "kurieren.$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.ifdef ENGLISH
	.string "I'm trying to relieve my stress.\n"
	.string "Don't come along and stress me out!$"
	.else
	.ifdef GERMAN
	.string "Ich versuche, Stress abzubauen.\n"
	.string "Komm her. Ich will mich abreagieren.$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.ifdef ENGLISH
	.string "I hope FLANNERY flames you good!$"
	.else
	.ifdef GERMAN
	.string "Ich hoffe, FLAVIA wird dich rösten!$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.ifdef ENGLISH
	.string "Haaah… Whew…\p"
	.string "If you spend too much time buried in\n"
	.string "hot sand, it tuckers you out…$"
	.else
	.ifdef GERMAN
	.string "Haaah… Huuuuh…\p"
	.string "Bleibt man zu lange im heißen Sand,\n"
	.string "macht einen das ganz schön fertig.$"
	.endif
	.endif

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.ifdef ENGLISH
	.string "You must be getting tired by now.\n"
	.string "You'd like to rest in the hot sand,\l"
	.string "wouldn't you?\p"
	.string "But you should know that maintaining\n"
	.string "your willpower is an important ability\l"
	.string "for all TRAINERS.$"
	.else
	.ifdef GERMAN
	.string "Du musst ganz schön müde sein.\n"
	.string "Willst du dich nicht hier im heißen\l"
	.string "Sand ausruhen?\p"
	.string "Aber du solltest wissen, dass\n"
	.string "Willenskraft ganz wichtig für einen\l"
	.string "TRAINER ist.$"
	.endif
	.endif

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.ifdef ENGLISH
	.string "Play with fire, and be burned…$"
	.else
	.ifdef GERMAN
	.string "Spiele mit Feuer und du verbrennst dich.$"
	.endif
	.endif

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.ifdef ENGLISH
	.string "Your skill is real…\n"
	.string "But our LEADER FLANNERY is strong.\p"
	.string "If you don't watch yourself, you'll be\n"
	.string "burned seriously.$"
	.else
	.ifdef GERMAN
	.string "Dein Können ist gut… Aber unsere\n"
	.string "LEITERIN FLAVIA ist stark.\p"
	.string "Wenn du nicht aufpasst, verbrennst\n"
	.string "du dich ernsthaft.$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.ifdef ENGLISH
	.string "Can your POKéMON withstand\n"
	.string "392-degree heat?$"
	.else
	.ifdef GERMAN
	.string "Kann dein POKéMON 200 Grad aushalten?$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.ifdef ENGLISH
	.string "It didn't burn hotly enough…$"
	.else
	.ifdef GERMAN
	.string "Die Hitze war nicht stark genug…$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.ifdef ENGLISH
	.string "The temperature of magma is\n"
	.string "392 degrees.\p"
	.string "Your POKéMON beat me, so they should\n"
	.string "easily survive in magma.$"
	.else
	.ifdef GERMAN
	.string "Die Temperatur von Magma beträgt\n"
	.string "über 200 Grad.\p"
	.string "Deine POKéMON haben mich besiegt, sie\n"
	.string "sollten auch in Magma überleben können.$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.ifdef ENGLISH
	.string "Um…\n"
	.string "Okay, I'll battle with you.$"
	.else
	.ifdef GERMAN
	.string "Ähm…\n"
	.string "Okay, ich kämpfe mit dir.$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.ifdef ENGLISH
	.string "Oh, but you're too strong.$"
	.else
	.ifdef GERMAN
	.string "Oh, du bist zu stark.$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.ifdef ENGLISH
	.string "I'm going to be a pretty and strong\n"
	.string "TRAINER just like FLANNERY.$"
	.else
	.ifdef GERMAN
	.string "Ich will einmal so eine starke\n"
	.string "TRAINERIN werden wie FLAVIA.$"
	.endif
	.endif

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.ifdef ENGLISH
	.string "Come on, get with it!\n"
	.string "Let's go before my feelings cool!$"
	.else
	.ifdef GERMAN
	.string "Komm schon! Los geht’s!\n"
	.string "Bevor ich abkühle.$"
	.endif
	.endif

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.ifdef ENGLISH
	.string "It's so hot, and yet my heart is\n"
	.string "clutched by ice…$"
	.else
	.ifdef GERMAN
	.string "Es ist so heiß und doch ist mein Herz\n"
	.string "von Eis umgeben…$"
	.endif
	.endif

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.ifdef ENGLISH
	.string "The way the battling spirit burns\n"
	.string "within you, you may stand a chance\l"
	.string "against our LEADER.$"
	.else
	.ifdef GERMAN
	.string "Dein Kampfstil ist feurig, ich denke, du\n"
	.string "hast eine gute Chance gegen unsere\l"
	.string "ARENALEITERIN.$"
	.endif
	.endif

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.ifdef ENGLISH
	.string "See how the flames blaze wildly?\n"
	.string "They flare in anticipation of my win!$"
	.else
	.ifdef GERMAN
	.string "Siehst du, wie wild die Flammen züngeln?\n"
	.string "Sie bejubeln meinen Sieg!$"
	.endif
	.endif

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.ifdef ENGLISH
	.string "Something didn't go right.$"
	.else
	.ifdef GERMAN
	.string "Irgendwas ist da schief gelaufen.$"
	.endif
	.endif

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.ifdef ENGLISH
	.string "Well, so what? I say so what?\n"
	.string "I can walk on hot coals barefoot!\p"
	.string "…Don't even think about trying it!$"
	.else
	.ifdef GERMAN
	.string "Ach, was soll’s?!? Mir doch egal. Dafür\n"
	.string "kann ich barfuß über glühende Kohlen\l"
	.string "laufen. … Versuch das bloß nicht!$"
	.endif
	.endif

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.ifdef ENGLISH
	.string "As much as I love mountains,\n"
	.string "I especially love volcanoes.$"
	.else
	.ifdef GERMAN
	.string "So sehr ich die Berge auch liebe, meine\n"
	.string "Leidenschaft gehört den Vulkanen.$"
	.endif
	.endif

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.ifdef ENGLISH
	.string "Well, it seems to me I lost without\n"
	.string "ever being in control.$"
	.else
	.ifdef GERMAN
	.string "Ich habe verloren. Ich hatte nicht\n"
	.string "einmal den Kampf unter Kontrolle.$"
	.endif
	.endif

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.ifdef ENGLISH
	.string "I stay here because I became a fan\n"
	.string "of FLANNERY's power.\p"
	.string "Hehehehe.$"
	.else
	.ifdef GERMAN
	.string "Ich bleibe hier, weil ich FLAVIAs Kraft\n"
	.string "bewundere.\p"
	.string "Hähähähä…$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.ifdef ENGLISH
	.string "Welcome… No, wait.\p"
	.string "Puny TRAINER, how good to see you've\n"
	.string "made it here!\p"
	.string "I have been entrusted with the…\n"
	.string "No, wait.\p"
	.string "I am FLANNERY, and I'm the GYM\n"
	.string "LEADER here!\p"
	.string "Uh…\n"
	.string "Dare not underestimate me, though\l"
	.string "I have been LEADER only a short time!\p"
	.string "With skills inherited from my grand-\n"
	.string "father, I shall, uh…demonstrate the\l"
	.string "hot moves we have honed on this land!$"
	.else
	.ifdef GERMAN
	.string "Willkommen… Halt, warte!\p"
	.string "Hallo, du Winzling von TRAINER, wie\n"
	.string "schön, dich hier zu sehen!\p"
	.string "Ich bin verantwortlich für, äh…\n"
	.string "Nein, warte.\p"
	.string "Ich bin FLAVIA und ich bin die ARENA-\n"
	.string "LEITERIN hier!\p"
	.string "Äh… Du solltest mich nicht\n"
	.string "unterschätzen, nur weil ich noch nicht\l"
	.string "so lange LEITERIN bin!\p"
	.string "Ich habe das Talent meines Großvaters\n"
	.string "geerbt und daher… äh… kann ich dir die\l"
	.string "heißen Attacken zeigen, die wir hier\l"
	.string "entwickelt haben!$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.ifdef ENGLISH
	.string "Oh…\n"
	.string "I guess I was trying too hard…\p"
	.string "I… I've only recently become\n"
	.string "a GYM LEADER.\p"
	.string "I tried too hard to be someone\n"
	.string "I'm not.\p"
	.string "I have to do things my natural way. If\n"
	.string "I don't, my POKéMON will be confused.\p"
	.string "Thanks for teaching me that.\n"
	.string "For that, you deserve this.$"
	.else
	.ifdef GERMAN
	.string "Äh…\n"
	.string "Ich glaube, ich habe es übertrieben…\p"
	.string "Ich… Ich bin ja auch noch nicht lange\n"
	.string "ARENALEITERIN!\p"
	.string "Ich habe zu sehr versucht, jemand zu\n"
	.string "sein, der ich gar nicht bin.\p"
	.string "Ich muss die Dinge auf meine eigene Art\n"
	.string "angehen. Sonst verwirre ich nur meine\l"
	.string "POKéMON.\p"
	.string "Danke, dass du mich das gelehrt hast!\n"
	.string "Du hast dir das hier wohl verdient!$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.ifdef ENGLISH
	.string "{PLAYER} received the HEAT BADGE\n"
	.string "from FLANNERY.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} erhält den HITZEORDEN\n"
	.string "von FLAVIA.$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.ifdef ENGLISH
	.string "If you have a HEAT BADGE, all POKéMON\n"
	.string "up to Level 50, even those you get in\l"
	.string "trades from other people, will obey\l"
	.string "you completely.\p"
	.string "And, it lets POKéMON use the HM move\n"
	.string "STRENGTH outside of battle.\p"
	.string "This is a token of my appreciation.\n"
	.string "Don't be shy about taking it!$"
	.else
	.ifdef GERMAN
	.string "Mit dem HITZEORDEN gehorchen dir alle\n"
	.string "POKéMON bis Level 50, auch die, die du\l"
	.string "durch Tausch erhalten hast.\p"
	.string "Und du kannst ab sofort STÄRKE auch\n"
	.string "außerhalb eines Kampfes einsetzen.\p"
	.string "Dies ist das Zeichen meiner\n"
	.string "Anerkennung. Nimm es ruhig an!$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.ifdef ENGLISH
	.string "That TM50 contains OVERHEAT.\p"
	.string "That move inflicts serious damage on\n"
	.string "the opponent.\p"
	.string "But it also sharply cuts the SP. ATK\n"
	.string "of the POKéMON using it. It might not\l"
	.string "be suitable for longer battles.$"
	.else
	.ifdef GERMAN
	.string "Die TM50 enthält HITZEKOLLER.\p"
	.string "Diese Attacke richtet beim Gegner\n"
	.string "großen Schaden an.\p"
	.string "Aber gleichzeitig wird der SP. ANG.\n"
	.string "des POKéMON, das die Attacke\p"
	.string "anwendet, herabgesetzt. Für längere\n"
	.string "Kämpfe ist sie daher nicht geeignet.$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.ifdef ENGLISH
	.string "Registered GYM LEADER FLANNERY\n"
	.string "in the POKéNAV.$"
	.else
	.ifdef GERMAN
	.string "ARENALEITERIN FLAVIA wurde\n"
	.string "im POKéNAV eingetragen.$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.ifdef ENGLISH
	.string "Your power reminds me of someone…\p"
	.string "Oh! I know! You battle like NORMAN,\n"
	.string "the GYM LEADER of PETALBURG.$"
	.else
	.ifdef GERMAN
	.string "Deine Stärke erinnert mich an\n"
	.string "jemanden…\p"
	.string "Jetzt weiß ich’s! Du kämpfst wie NORMAN,\n"
	.string "der ARENALEITER von BLÜTENBURG CITY.$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_GymStatue:
	.ifdef ENGLISH
	.string "LAVARIDGE TOWN POKéMON GYM$"
	.else
	.ifdef GERMAN
	.string "POKéMON ARENA von BAD LAVASTADT$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.ifdef ENGLISH
	.string "LAVARIDGE TOWN POKéMON GYM\p"
	.string "FLANNERY'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
	.else
	.ifdef GERMAN
	.string "POKéMON ARENA von BAD LAVASTADT\p"
	.string "FLAVIAs ANERKANNTE TRAINER:\n"
	.string "{PLAYER}$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.ifdef ENGLISH
	.string "FLANNERY: Losing a battle isn't going\n"
	.string "to deflate me.\p"
	.string "I love POKéMON.\n"
	.string "I love to battle.\l"
	.string "And… I love this GYM!\p"
	.string "Let's exchange superhot moves\n"
	.string "in another battle!$"
	.else
	.ifdef GERMAN
	.string "FLAVIA: Eine Niederlage wird mein\n"
	.string "Feuer nicht löschen.\p"
	.string "Ich liebe POKéMON.\n"
	.string "Ich liebe Kämpfe.\l"
	.string "Und… Ich liebe diese ARENA!\p"
	.string "Lass uns einen ultraheißen Kampf\n"
	.string "austragen! Die Funken sollen fliegen.$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.ifdef ENGLISH
	.string "Whew!\n"
	.string "On the verge of eruption!$"
	.else
	.ifdef GERMAN
	.string "Wow!\n"
	.string "Da stand einer kurz vor dem Ausbruch!$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.ifdef ENGLISH
	.string "FLANNERY: I lost the match,\n"
	.string "but I'm completely satisfied.\p"
	.string "It's not often I get to enjoy a battle\n"
	.string "this heated.\p"
	.string "Let's have another one like this\n"
	.string "again sometime!$"
	.else
	.ifdef GERMAN
	.string "FLAVIA: Ich habe den Kampf zwar\n"
	.string "verloren, bin aber dennoch zufrieden.\p"
	.string "Ich habe nicht oft die Gelegenheit,\n"
	.string "einen so heißen Kampf zu genießen.\p"
	.string "Das müssen wir unbedingt wiederholen!\n"
	.string "Komm bald wieder!$"
	.endif
	.endif

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.ifdef ENGLISH
	.string "FLANNERY: Losing a battle isn't going\n"
	.string "to deflate me.\p"
	.string "I love POKéMON.\n"
	.string "I love to battle.\l"
	.string "And… I love this GYM!\p"
	.string "Let's exchange superhot moves\n"
	.string "in another battle!\p"
	.string "Oh, wait. Do you only have one POKéMON\n"
	.string "that can battle?\p"
	.string "I hate to say this, but when you come\n"
	.string "see me, bring at least two POKéMON.$"
	.else
	.ifdef GERMAN
	.string "FLAVIA: Eine Niederlage wird mein\n"
	.string "Feuer nicht löschen.\p"
	.string "Ich liebe POKéMON.\n"
	.string "Ich liebe Kämpfe.\l"
	.string "Und… Ich liebe diese ARENA!\p"
	.string "Lass uns einen ultraheißen Kampf\n"
	.string "austragen! Die Funken sollen fliegen.\p"
	.string "Moment! Warte mal! Du hast ja nur ein\n"
	.string "POKéMON, das kämpfen kann, dabei!\p"
	.string "Bring das nächste Mal mindestens\n"
	.string "zwei POKéMON mit, sonst wird das nichts.$"
	.endif
	.endif
