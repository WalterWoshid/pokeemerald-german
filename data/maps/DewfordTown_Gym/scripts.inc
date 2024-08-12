DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.ifdef ENGLISH
	.string "Hey, how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "DEWFORD's GYM LEADER BRAWLY commands\n"
	.string "FIGHTING-type POKéMON.\p"
	.string "Going against him with NORMAL-type\n"
	.string "POKéMON is asking for trouble.\p"
	.string "FIGHTING POKéMON will lay a serious\n"
	.string "smack down on NORMAL POKéMON,\l"
	.string "so be careful!\p"
	.string "What's worse, the GYM is as dark as\n"
	.string "the ocean floor.\p"
	.string "But it will get brighter after defeating\n"
	.string "the TRAINERS in your way.\p"
	.string "Hey, okay, go for it!$"
	.else
	.ifdef GERMAN
	.string "Na, wie sieht es aus, auf dem Weg zum\n"
	.string "CHAMP, {PLAYER}?\p"
	.string "FAUSTAUHAVENs ARENALEITER KAMILLO\n"
	.string "besitzt KAMPF-POKéMON.\p"
	.string "Wenn du dort NORMAL-POKéMON antreten\n"
	.string "lässt, sind Probleme vorprogrammiert!\p"
	.string "KAMPF-POKéMON schlagen die NORMALEN\n"
	.string "POKéMON einfach nieder. Pass gut auf!\p"
	.string "Und das Schlimme ist: Die ARENA ist\n"
	.string "dunkel wie die Tiefsee!\p"
	.string "Aber mit jedem TRAINER, den du auf dem\n"
	.string "Weg zum ARENALEITER besiegst, wird sie\l"
	.string "heller!\p"
	.string "Also, dann leg mal los!$"
	.endif
	.endif

DewfordTown_Gym_Text_GymGuidePostVictory:
	.ifdef ENGLISH
	.string "Whoah! It's turned too bright in here!\p"
	.string "Your future is bright, too!$"
	.else
	.ifdef GERMAN
	.string "Huuh!\n"
	.string "Das ist mir hier aber schon zu hell!\p"
	.string "Deine Zukunft wird strahlend hell sein!$"
	.endif
	.endif

DewfordTown_Gym_Text_TakaoIntro:
	.ifdef ENGLISH
	.string "Might is right!\n"
	.string "Come on!$"
	.else
	.ifdef GERMAN
	.string "Die Macht bestimmt alles!\n"
	.string "Komm schon!$"
	.endif
	.endif

DewfordTown_Gym_Text_TakaoDefeat:
	.ifdef ENGLISH
	.string "Not enough power…$"
	.else
	.ifdef GERMAN
	.string "Nicht genug Macht…$"
	.endif
	.endif

DewfordTown_Gym_Text_TakaoPostBattle:
	.ifdef ENGLISH
	.string "Your skill overcame my strength!\n"
	.string "Your technique is commendable!$"
	.else
	.ifdef GERMAN
	.string "Gegen dein Talent ist meine Macht\n"
	.string "machtlos. Deine Technik ist super!$"
	.endif
	.endif

DewfordTown_Gym_Text_JocelynIntro:
	.ifdef ENGLISH
	.string "There's no need for BRAWLY to be\n"
	.string "involved!\p"
	.string "I'll crush you!$"
	.else
	.ifdef GERMAN
	.string "Man muss doch KAMILLO nicht mit so\n"
	.string "etwas Nichtigem belästigen!\p"
	.string "Ich mache dich fertig!$"
	.endif
	.endif

DewfordTown_Gym_Text_JocelynDefeat:
	.ifdef ENGLISH
	.string "But… How?\n"
	.string "How could I lose so easily?$"
	.else
	.ifdef GERMAN
	.string "Aber… Wie…?\n"
	.string "Wie konnte ich nur so schnell verlieren?$"
	.endif
	.endif

DewfordTown_Gym_Text_JocelynPostBattle:
	.ifdef ENGLISH
	.string "I'm not going to waste this loss.\n"
	.string "I'll use it to motivate me to train!\p"
	.string "One day I'll become a GYM LEADER…\p"
	.string "No, I'll become the POKéMON LEAGUE\n"
	.string "CHAMPION!$"
	.else
	.ifdef GERMAN
	.string "Ich werde diese Niederlage nicht ab-\n"
	.string "haken. Sie wird mich beim Training\l"
	.string "motivieren!\p"
	.string "Eines Tages werde ich auch ein\n"
	.string "ARENALEITER sein!\p"
	.string "Nein! Ich werde der CHAMP der\n"
	.string "POKéMON LIGA!$"
	.endif
	.endif

DewfordTown_Gym_Text_LauraIntro:
	.ifdef ENGLISH
	.string "Don't you dare brush me off!\n"
	.string "It's not my fault if you cry!$"
	.else
	.ifdef GERMAN
	.string "Du forderst mich heraus? Dann wundere\n"
	.string "dich nicht, wenn du weinst wie ein Baby!$"
	.endif
	.endif

DewfordTown_Gym_Text_LauraDefeat:
	.ifdef ENGLISH
	.string "Waaaaaaah!\n"
	.string "I lost!$"
	.else
	.ifdef GERMAN
	.string "Waaaaahaaaaaa!\n"
	.string "Schluchz! Schnief! Ich habe verloooren!$"
	.endif
	.endif

DewfordTown_Gym_Text_LauraPostBattle:
	.ifdef ENGLISH
	.string "I battle in the dark to make my heart\n"
	.string "stronger.\p"
	.string "But because it's so dark, I can never\n"
	.string "see BRAWLY's face…$"
	.else
	.ifdef GERMAN
	.string "Ich kämpfe im Dunkeln, das macht mich\n"
	.string "mutiger und trainiert mein Herz.\p"
	.string "Weil es hier so dunkel ist, habe ich noch\n"
	.string "nie das Gesicht von KAMILLO gesehen.$"
	.endif
	.endif

DewfordTown_Gym_Text_LilithIntro:
	.ifdef ENGLISH
	.string "Ufufu…\n"
	.string "Are you stumbling around in the dark?$"
	.else
	.ifdef GERMAN
	.string "Huhuhu…\n"
	.string "Was stolperst du im Dunklen herum?$"
	.endif
	.endif

DewfordTown_Gym_Text_LilithDefeat:
	.ifdef ENGLISH
	.string "Oh, you…\n"
	.string "I don't want to know you!$"
	.else
	.ifdef GERMAN
	.string "Ach, du… Ich habe kein\n"
	.string "Interesse, dich kennen zu lernen.$"
	.endif
	.endif

DewfordTown_Gym_Text_LilithPostBattle:
	.ifdef ENGLISH
	.string "You deserve to stay lost and end up\n"
	.string "back at the entrance again!$"
	.else
	.ifdef GERMAN
	.string "Du verdienst eine Niederlage, damit du\n"
	.string "wieder von vorne anfangen musst.$"
	.endif
	.endif

DewfordTown_Gym_Text_BrendenIntro:
	.ifdef ENGLISH
	.string "I'll show you the gumption of\n"
	.string "a sailing man!$"
	.else
	.ifdef GERMAN
	.string "Ich zeige dir, wie viel Köpfchen ein\n"
	.string "Seemann hat!$"
	.endif
	.endif

DewfordTown_Gym_Text_BrendenDefeat:
	.ifdef ENGLISH
	.string "How'd this happen?\n"
	.string "It's not like me to lose this way!$"
	.else
	.ifdef GERMAN
	.string "Wie konnte das nur passieren? Es ist\n"
	.string "nicht meine Art, einfach zu verlieren.$"
	.endif
	.endif

DewfordTown_Gym_Text_BrendenPostBattle:
	.ifdef ENGLISH
	.string "Oh, aye! You're worthy of seeing\n"
	.string "our GYM LEADER.$"
	.else
	.ifdef GERMAN
	.string "Ahoi! Du bist es wert, unserem\n"
	.string "ARENALEITER vorgestellt zu werden.$"
	.endif
	.endif

DewfordTown_Gym_Text_CristianIntro:
	.ifdef ENGLISH
	.string "If you mean to pass, it has to be\n"
	.string "through me!$"
	.else
	.ifdef GERMAN
	.string "Wenn du hier vorbei willst, musst du\n"
	.string "erst an mir vorbei!$"
	.endif
	.endif

DewfordTown_Gym_Text_CristianDefeat:
	.ifdef ENGLISH
	.string "Grrrrr!\n"
	.string "Vastly overpowered!$"
	.else
	.ifdef GERMAN
	.string "Grrrr!\n"
	.string "Ich wurde einfach überwältigt!$"
	.endif
	.endif

DewfordTown_Gym_Text_CristianPostBattle:
	.ifdef ENGLISH
	.string "You win!\n"
	.string "Go after that BADGE!$"
	.else
	.ifdef GERMAN
	.string "Du hast gewonnen!\n"
	.string "Hol dir den ORDEN!$"
	.endif
	.endif

DewfordTown_Gym_Text_BrawlyIntro:
	.ifdef ENGLISH
	.string "I'm BRAWLY!\n"
	.string "DEWFORD's GYM LEADER!\p"
	.string "I've been churned in the rough waves\n"
	.string "of these parts, and I've grown tough\l"
	.string "in the pitch-black cave!\p"
	.string "So you wanted to challenge me?\n"
	.string "Let me see what you're made of!$"
	.else
	.ifdef GERMAN
	.string "Ich bin KAMILLO!\n"
	.string "Der ARENALEITER von FAUSTAUHAVEN!\p"
	.string "Ich habe die wilden Strudel dieser\n"
	.string "Gegend gemeistert und bin in dieser\l"
	.string "pechschwarzen Höhle stark geworden.\p"
	.string "Du willst mich wirklich herausfordern?\n"
	.string "Dann zeig mir, woraus du gemacht bist!$"
	.endif
	.endif

DewfordTown_Gym_Text_BrawlyDefeat:
	.ifdef ENGLISH
	.string "Whoah, wow! You made a much bigger\n"
	.string "splash than I expected!\p"
	.string "You swamped me!\p"
	.string "Okay, you've got me.\n"
	.string "Take this GYM BADGE!$"
	.else
	.ifdef GERMAN
	.string "Huihuihui! Du hast eine größere Welle\n"
	.string "produziert, als ich dir zugetraut hätte.\p"
	.string "Du hast mich absaufen lassen!\p"
	.string "Okay, du hast mich erwischt!\n"
	.string "Nimm den ORDEN dieser ARENA!$"
	.endif
	.endif

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.ifdef ENGLISH
	.string "{PLAYER} received the KNUCKLE BADGE\n"
	.string "from BRAWLY.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} erhält den KNÖCHELORDEN von\n"
	.string "KAMILLO.$"
	.endif
	.endif

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.ifdef ENGLISH
	.string "The KNUCKLE BADGE makes all POKéMON\n"
	.string "up to Level 30, even those you get in\l"
	.string "trades, obey without question.\p"
	.string "And, you'll be able to use the HM move\n"
	.string "FLASH outside of battle.\p"
	.string "If you'd like, use this TECHNICAL\n"
	.string "MACHINE, too.$"
	.else
	.ifdef GERMAN
	.string "Dank des KNÖCHELORDENs werden dir alle\n"
	.string "POKéMON bis Level 30 gehorchen, auch\l"
	.string "die, die du durch Tausch erhalten hast.\p"
	.string "Und du kannst die VM BLITZ auch\n"
	.string "außerhalb eines Kampfes anwenden.\p"
	.string "Und wenn du magst, kannst du auch diese\n"
	.string "TECHNISCHE MASCHINE anwenden.$"
	.endif
	.endif

DewfordTown_Gym_Text_ExplainBulkUp:
	.ifdef ENGLISH
	.string "That TM08 contains BULK UP.\p"
	.string "It's a move that raises both ATTACK\n"
	.string "and DEFENSE stats.\p"
	.string "… … … … … …$"
	.else
	.ifdef GERMAN
	.string "Die TM08 enthält PROTZER.\p"
	.string "Diese Attacke hebt den Status des\n"
	.string "ANGRIFFs und der VERTEIDIGUNG.\p"
	.string "… … … … … …$"
	.endif
	.endif

DewfordTown_Gym_Text_RegisteredBrawly:
	.ifdef ENGLISH
	.string "Registered GYM LEADER BRAWLY\n"
	.string "in the POKéNAV.$"
	.else
	.ifdef GERMAN
	.string "ARENALEITER KAMILLO wurde\n"
	.string "im POKéNAV eingetragen.$"
	.endif
	.endif

DewfordTown_Gym_Text_BrawlyPostBattle:
	.ifdef ENGLISH
	.string "I can see your talent becoming a giant\n"
	.string "wave to cause a storm of astonishment\l"
	.string "among TRAINERS one day!$"
	.else
	.ifdef GERMAN
	.string "Ich sehe in dir ein Talent, das eines\n"
	.string "Tages zu einer riesigen Welle wird und\l"
	.string "einen Sturm des Erstaunens bei anderen\l"
	.string "TRAINERn entfachen wird!$"
	.endif
	.endif

DewfordTown_Gym_Text_GymStatue:
	.ifdef ENGLISH
	.string "DEWFORD TOWN POKéMON GYM$"
	.else
	.ifdef GERMAN
	.string "POKéMON ARENA von FAUSTAUHAVEN$"
	.endif
	.endif

DewfordTown_Gym_Text_GymStatueCertified:
	.ifdef ENGLISH
	.string "DEWFORD TOWN POKéMON GYM\p"
	.string "BRAWLY'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
	.else
	.ifdef GERMAN
	.string "POKéMON ARENA von FAUSTAUHAVEN\p"
	.string "KAMILLOS ANERKANNTE TRAINER:\n"
	.string "{PLAYER}$"
	.endif
	.endif

DewfordTown_Gym_Text_BrawlyPreRematch:
	.ifdef ENGLISH
	.string "BRAWLY: A wave may draw back, but it\n"
	.string "always returns to the shore.\p"
	.string "A giant wave of a talent like you…\n"
	.string "I knew you would return!\p"
	.string "Show me how much higher\n"
	.string "you've gone!$"
	.else
	.ifdef GERMAN
	.string "KAMILLO: Eine Welle kann sich zurück-\n"
	.string "ziehen, wird aber immer wieder an\l"
	.string "Land zurückkommen.\p"
	.string "Ein riesiges Talent wie du…\n"
	.string "Ich wusste, du würdest wiederkommen.\p"
	.string "Zeig mir, wie gut du geworden bist.$"
	.endif
	.endif

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.ifdef ENGLISH
	.string "Wow!\n"
	.string "Swamped again!$"
	.else
	.ifdef GERMAN
	.string "Und wieder wurde ich fortgespült.$"
	.endif
	.endif

DewfordTown_Gym_Text_BrawlyPostRematch:
	.ifdef ENGLISH
	.string "BRAWLY: Battling is vast and it's deep.\n"
	.string "You can't see the bottom.\l"
	.string "It's just like the sea of HOENN!$"
	.else
	.ifdef GERMAN
	.string "KAMILLO: Kämpfe sind wild und tief wie\n"
	.string "die See. Du siehst kein Land.\l"
	.string "Wie das Meer um HOENN.$"
	.endif
	.endif

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.ifdef ENGLISH
	.string "BRAWLY: A wave may draw back, but it\n"
	.string "always returns to the shore.\p"
	.string "A giant wave of a talent like you…\n"
	.string "I knew you would return!\p"
	.string "Oh? You only have one POKéMON\n"
	.string "that can battle.\p"
	.string "I'm sorry, but I'd like you to come back\n"
	.string "with at least two POKéMON.$"
	.else
	.ifdef GERMAN
	.string "KAMILLO: Eine Welle kann sich zurück-\n"
	.string "ziehen, wird aber immer wieder an\l"
	.string "Land zurückkommen.\p"
	.string "Ein riesiges Talent wie du…\n"
	.string "Ich wusste, du würdest wiederkommen.\p"
	.string "Oh, du hast ja nur ein POKéMON, das\n"
	.string "kämpfen kann.\p"
	.string "Tut mir Leid, aber ich trete nur gegen\n"
	.string "dich an, wenn du mindestens zwei\l"
	.string "POKéMON hast.$"
	.endif
	.endif
