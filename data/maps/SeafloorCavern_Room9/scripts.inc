.set LOCALID_KYOGRE, 1
.set LOCALID_ARCHIE, 2
.set LOCALID_MAXIE, 3
.set LOCALID_GRUNT_1, 4
.set LOCALID_GRUNT_2, 5
.set LOCALID_KYOGRE_SLEEPING, 7

SeafloorCavern_Room9_MapScripts::
	.byte 0

SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre::
	lockall
	setvar VAR_0x8004, LOCALID_ARCHIE
	setvar VAR_0x8005, LOCALID_MAXIE
	setvar VAR_0x8006, LOCALID_GRUNT_1
	setvar VAR_0x8007, LOCALID_GRUNT_2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, SeafloorCavern_Room9_Movement_Delay32
	waitmovement 0
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SeafloorCavern_Room9_Text_ArchieHoldItRightThere, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8004
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieSoItWasYou, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieBeholdKyogre, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieYouMustDisappear, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHIE, SeafloorCavern_Room9_Text_ArchieDefeat
	msgbox SeafloorCavern_Room9_Text_ArchieWithThisRedOrb, MSGBOX_DEFAULT
	setweather WEATHER_NONE
	doweather
	special Script_FadeOutMapMusic
	waitstate
	msgbox SeafloorCavern_Room9_Text_RedOrbShinesByItself, MSGBOX_DEFAULT
	special WaitWeather
	waitstate
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 16, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	closemessage
	setvar VAR_RESULT, 0
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_KYOGRE_SLEEPING
	addobject LOCALID_KYOGRE
	waitstate
	delay 60
	applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
	waitmovement 0
	removeobject LOCALID_KYOGRE
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	setvar VAR_0x8004, LOCALID_ARCHIE
	setvar VAR_0x8005, LOCALID_MAXIE
	setvar VAR_0x8006, LOCALID_GRUNT_1
	setvar VAR_0x8007, LOCALID_GRUNT_2
	msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
	playse SE_PC_LOGIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
	closemessage
	playse SE_PC_OFF
	delay 20
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8005
	addobject VAR_0x8006
	addobject VAR_0x8007
	applymovement VAR_0x8007, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8006, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieArrive
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x8004, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_Delay48
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty, MSGBOX_DEFAULT
	msgbox SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieExit
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieExit
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieComeOnPlayer, MSGBOX_DEFAULT
	setvar VAR_ROUTE128_STATE, 1
	setvar VAR_SOOTOPOLIS_CITY_STATE, 1
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	clearflag FLAG_HIDE_ROUTE_128_ARCHIE
	clearflag FLAG_HIDE_ROUTE_128_MAXIE
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setvar VAR_STEVENS_HOUSE_STATE, 2
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
	setflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_ROUTE128, 38, 22
	waitstate
	releaseall
	end

SeafloorCavern_Room9_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_Unused1:
	walk_left
	walk_left
	step_end

SeafloorCavern_Room9_Movement_ArchieListenMessage:
	walk_left
	delay_16
	step_end

SeafloorCavern_Room9_Movement_Unused2:
	walk_right
	step_end

SeafloorCavern_Room9_Movement_ArchieExit:
	face_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	walk_in_place_faster_right
	step_end

SeafloorCavern_Room9_Movement_KyogreApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Movement_KyogreExit:
	slide_up
	slide_up
	step_end

SeafloorCavern_Room9_Movement_MaxieArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_MaxieExit:
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_MagmaGruntArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_Delay32:
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Text_ArchieHoldItRightThere:
	.ifdef ENGLISH
	.string "ARCHIE: Hold it right there.$"
	.else
	.ifdef GERMAN
	.string "ADRIAN: Bleib sofort stehen!$"
	.endif
	.endif

SeafloorCavern_Room9_Text_ArchieSoItWasYou:
	.ifdef ENGLISH
	.string "ARCHIE: Fufufu…\n"
	.string "So it was you, after all.$"
	.else
	.ifdef GERMAN
	.string "ADRIAN: Hahahaha…\n"
	.string "Du warst das also die ganze Zeit.$"
	.endif
	.endif

SeafloorCavern_Room9_Text_ArchieBeholdKyogre:
	.ifdef ENGLISH
	.string "ARCHIE: Behold!\p"
	.string "See how beautiful it is, the sleeping\n"
	.string "form of the ancient POKéMON KYOGRE!\p"
	.string "I have waited so long for this day to\n"
	.string "come…$"
	.else
	.ifdef GERMAN
	.string "ADRIAN: Schau nur, schau nur!\p"
	.string "Schau, wie schön die schlafende Gestalt\n"
	.string "des antiken POKéMON KYOGRE ist!\p"
	.string "Ich habe so lange auf diesen Tag\n"
	.string "gewartet…$"
	.endif
	.endif

SeafloorCavern_Room9_Text_ArchieYouMustDisappear:
	.ifdef ENGLISH
	.string "ARCHIE: It surprises me, how you've\n"
	.string "managed to chase me here.\p"
	.string "But that's all over now.\p"
	.string "For the realization of my dream,\n"
	.string "you must disappear now!$"
	.else
	.ifdef GERMAN
	.string "ADRIAN: Es überrascht mich, wie du es\n"
	.string "geschafft hast, mir zu folgen.\p"
	.string "Aber das ist nun alles Nebensache.\p"
	.string "Damit meine Träume wahr werden, musst\n"
	.string "du leider verschwinden!$"
	.endif
	.endif

SeafloorCavern_Room9_Text_ArchieDefeat:
	.ifdef ENGLISH
	.string "What?!\n"
	.string "I lost to a mere child like you?!$"
	.else
	.ifdef GERMAN
	.string "Was?!?\n"
	.string "Ich habe gegen ein Kind verloren?!?$"
	.endif
	.endif

SeafloorCavern_Room9_Text_ArchieWithThisRedOrb:
	.ifdef ENGLISH
	.string "ARCHIE: Fufufu…\p"
	.string "I commend you. I must recognize that\n"
	.string "you are truly gifted.\p"
	.string "But!\n"
	.string "I have this in my possession!\p"
	.string "With this RED ORB, I can make KYOGRE…$"
	.else
	.ifdef GERMAN
	.string "ADRIAN: Hahahaha…\p"
	.string "Ich empfehle mich. Ich muss sagen, du\n"
	.string "bist wirklich sehr talentiert.\p"
	.string "Aber!\n"
	.string "Ich habe dieses hier in meinem Besitz!\p"
	.string "Mit dieser ROTEn KUGEL kann ich\n"
	.string "KYOGRE…$"
	.endif
	.endif

SeafloorCavern_Room9_Text_RedOrbShinesByItself:
	.ifdef ENGLISH
	.string "The RED ORB suddenly began shining\n"
	.string "by itself!$"
	.else
	.ifdef GERMAN
	.string "Die ROTE KUGEL beginnt plötzlich von\n"
	.string "innen heraus zu leuchten!$"
	.endif
	.endif

SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo:
	.ifdef ENGLISH
	.string "ARCHIE: What?!\p"
	.string "I didn't do anything.\n"
	.string "Why did the RED ORB…\p"
	.string "Where did KYOGRE go?$"
	.else
	.ifdef GERMAN
	.string "ADRIAN: Was?!?\p"
	.string "Ich habe doch gar nichts gemacht.\n"
	.string "Die ROTE KUGEL… Warum…\p"
	.string "Wo ist KYOGRE geblieben?$"
	.endif
	.endif

SeafloorCavern_Room9_Text_ArchieAMessageFromOutside:
	.ifdef ENGLISH
	.string "ARCHIE: Hm? It's a message from our\n"
	.string "members outside…$"
	.else
	.ifdef GERMAN
	.string "ADRIAN: Hm? Dies ist eine Nachricht\n"
	.string "unserer Mitglieder draußen…$"
	.endif
	.endif

SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard:
	.ifdef ENGLISH
	.string "ARCHIE: Yes, what is it?\p"
	.string "Hm…\n"
	.string "It's raining heavily?\p"
	.string "Good… That should have happened.\n"
	.string "That is why we awakened KYOGRE,\l"
	.string "to realize TEAM AQUA's vision of\l"
	.string "expanding the sea.\p"
	.string "What?!\p"
	.string "It's raining far harder than we\n"
	.string "envisioned? You're in danger?\p"
	.string "That can't be…\n"
	.string "That's just not possible…\p"
	.string "Hold your position and monitor\n"
	.string "the situation!$"
	.else
	.ifdef GERMAN
	.string "ADRIAN: Ja, was ist denn jetzt los?\p"
	.string "Hm…\n"
	.string "Es regnet? So heftig?\p"
	.string "Gut… Genau darauf habe ich gewartet.\n"
	.string "Deshalb haben wir KYOGRE erweckt.\l"
	.string "Um TEAM AQUAs Vision von der Erweite-\l"
	.string "rung der Meere zu realisieren.\p"
	.string "Was?!?\p"
	.string "Es regnet stärker, als wir es voraus-\n"
	.string "gesagt haben? Wir sind in Gefahr?\p"
	.string "Das kann nicht sein…\n"
	.string "Das ist unmöglich…\p"
	.string "Bleib, wo du bist und behalte die\n"
	.string "Situation im Auge!$"
	.endif
	.endif

SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear:
	.ifdef ENGLISH
	.string "ARCHIE: There's something wrong…\p"
	.string "The RED ORB is supposed to awaken\n"
	.string "and control KYOGRE…\p"
	.string "But… Why?\n"
	.string "Why did KYOGRE disappear?\p"
	.string "Why?!$"
	.else
	.ifdef GERMAN
	.string "ADRIAN: Irgendetwas stimmt da ganz und\n"
	.string "gar nicht…\p"
	.string "Die ROTE KUGEL sollte KYOGRE auf-\n"
	.string "wecken und unter Kontrolle halten…\p"
	.string "Aber… Warum?\n"
	.string "Warum ist KYOGRE verschwunden?\p"
	.string "Warum?!?$"
	.endif
	.endif

SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought:
	.ifdef ENGLISH
	.string "MAXIE: What have you wrought?\p"
	.string "ARCHIE… You've finally awoken KYOGRE,\n"
	.string "haven't you?\p"
	.string "What will happen to the world if this\n"
	.string "downpour continues for all eternity?\p"
	.string "The world's landmass will drown in\n"
	.string "the deepening sea…$"
	.else
	.ifdef GERMAN
	.string "MARC: Was hast du da nur herauf-\n"
	.string "beschworen?\p"
	.string "ADRIAN… Du hast KYOGRE aufge-\n"
	.string "weckt, stimmt’s?\p"
	.string "Was wird nur aus der Welt, wenn es\n"
	.string "bis in alle Ewigkeit regnen wird?\p"
	.string "Das Land wird untergehen und im\n"
	.string "Meer verschwinden…$"
	.endif
	.endif

SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty:
	.ifdef ENGLISH
	.string "ARCHIE: W-what?!\n"
	.string "Don't get all high and mighty with me!\p"
	.string "Wasn't it you, TEAM MAGMA, that\n"
	.string "infuriated GROUDON?\p"
	.string "So long as I have this RED ORB,\n"
	.string "I should be able to control KYOGRE…\p"
	.string "I should be able to control it…$"
	.else
	.ifdef GERMAN
	.string "ADRIAN: Was?!?\n"
	.string "Behandle mich nicht so von oben herab!\p"
	.string "Wart ihr es nicht, TEAM MAGMA, die\n"
	.string "GROUDON erzürnt habt?\p"
	.string "Solange ich die ROTE KUGEL habe, habe\n"
	.string "ich auch die Kontrolle über KYOGRE…\p"
	.string "Ich sollte es kontrollieren können…$"
	.endif
	.endif

SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue:
	.ifdef ENGLISH
	.string "MAXIE: We don't have the time to\n"
	.string "argue about it here!\p"
	.string "Get outside and see for yourself!\p"
	.string "See if what you've wrought is the\n"
	.string "world that we desired!$"
	.else
	.ifdef GERMAN
	.string "MARC: Wir haben keine Zeit für\n"
	.string "Diskussionen!\p"
	.string "Geh nach draußen und sieh es dir\n"
	.string "selber an!\p"
	.string "Sieh, ob das, was du heraufbeschworen\n"
	.string "hast, das ist, was du wolltest!$"
	.endif
	.endif

SeafloorCavern_Room9_Text_MaxieComeOnPlayer:
	.ifdef ENGLISH
	.string "MAXIE: {PLAYER}, come on, you have\n"
	.string "to get out of here, too!$"
	.else
	.ifdef GERMAN
	.string "MARC: {PLAYER}, komm, du musst\n"
	.string "ebenfalls von hier verschwinden!$"
	.endif
	.endif
