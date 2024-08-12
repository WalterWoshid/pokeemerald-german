.set LOCALID_GROUDON, 1
.set LOCALID_GRUNT_1, 2
.set LOCALID_GRUNT_2, 3
.set LOCALID_GRUNT_3, 4
.set LOCALID_TABITHA, 5
.set LOCALID_MAXIE, 6
.set LOCALID_GROUDON_SLEEPING, 7

MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_GROUDON_SLEEPING
	addobject LOCALID_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
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

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.ifdef ENGLISH
	.string "I want to see GROUDON, too, but they\n"
	.string "won't let me see even its tail…\p"
	.string "It's got me feeling really frustrated.\p"
	.string "Oh, no!\n"
	.string "I blabbed about GROUDON!$"
	.else
	.ifdef GERMAN
	.string "Ich würde so gerne einen Blick auf\n"
	.string "GROUDON werfen, aber ich darf nicht mal\l"
	.string "einen Blick auf seinen Schweif werfen.\p"
	.string "Das frustriert mich total.\p"
	.string "Oh, nein!\n"
	.string "Ich klatsche hier über GROUDON!$"
	.endif
	.endif

MagmaHideout_4F_Text_Grunt11Defeat:
	.ifdef ENGLISH
	.string "I guess it's impossible to win if one\n"
	.string "doesn't have a calm mind…$"
	.else
	.ifdef GERMAN
	.string "Wenn der Verstand durch andere Dinge\n"
	.string "abgelenkt ist, ist es unmöglich,\l"
	.string "zu gewinnen…$"
	.endif
	.endif

MagmaHideout_4F_Text_Grunt11PostBattle:
	.ifdef ENGLISH
	.string "I wonder if GROUDON even has a tail?$"
	.else
	.ifdef GERMAN
	.string "Ich frage mich, ob GROUDON überhaupt\n"
	.string "einen Schweif hat?$"
	.endif
	.endif

MagmaHideout_4F_Text_Grunt12Intro:
	.ifdef ENGLISH
	.string "Fuhahaha!\n"
	.string "Soon! Very soon!\l"
	.string "Our grand objective will be achieved!$"
	.else
	.ifdef GERMAN
	.string "Muahahaha!\n"
	.string "Bald! Sehr bald!\l"
	.string "Werden wir unser großes Ziel erreichen!$"
	.endif
	.endif

MagmaHideout_4F_Text_Grunt12Defeat:
	.ifdef ENGLISH
	.string "Grrr…\n"
	.string "I've come so far, but now this?$"
	.else
	.ifdef GERMAN
	.string "Grr…\n"
	.string "Ich bin so weit gekommen und nun das?$"
	.endif
	.endif

MagmaHideout_4F_Text_Grunt12PostBattle:
	.ifdef ENGLISH
	.string "MAXIE, sir!\n"
	.string "An intruder is headed your way!$"
	.else
	.ifdef GERMAN
	.string "MARC, Sir!\n"
	.string "Ein Eindringling ist auf dem Weg!$"
	.endif
	.endif

MagmaHideout_4F_Text_Grunt13Intro:
	.ifdef ENGLISH
	.string "You're not finished yet!\n"
	.string "You're not getting by me easily!$"
	.else
	.ifdef GERMAN
	.string "Du bist noch nicht fertig!\n"
	.string "An mir kommst du nicht so leicht vorbei!$"
	.endif
	.endif

MagmaHideout_4F_Text_Grunt13Defeat:
	.ifdef ENGLISH
	.string "Was I that easy to knock down?$"
	.else
	.ifdef GERMAN
	.string "War ich so leicht zu besiegen?$"
	.endif
	.endif

MagmaHideout_4F_Text_Grunt13PostBattle:
	.ifdef ENGLISH
	.string "C-come on, one more match…$"
	.else
	.ifdef GERMAN
	.string "Ko-Komm schon, noch ein Kampf…$"
	.endif
	.endif

MagmaHideout_4F_Text_TabithaIntro:
	.ifdef ENGLISH
	.string "Hehehe!\n"
	.string "You made it this far, so I'll tell you!\p"
	.string "That's right!\n"
	.string "Up ahead, GROUDON is sleeping!\p"
	.string "MAXIE went to GROUDON just seconds\n"
	.string "ago!\p"
	.string "It's going to awaken real soon!\n"
	.string "Hehe! Hehehe!$"
	.else
	.ifdef GERMAN
	.string "Hähähä!\n"
	.string "Du hast es bis hierher geschafft, daher\l"
	.string "verrate ich dir etwas!\p"
	.string "Es stimmt!\n"
	.string "Dort drüben schläft GROUDON!\p"
	.string "MARC ist vor ein paar Sekunden zu ihm\n"
	.string "gegangen!\p"
	.string "Es wird bald erwachen!\n"
	.string "Hähä! Hähähähä!$"
	.endif
	.endif

MagmaHideout_4F_Text_TabithaDefeat:
	.ifdef ENGLISH
	.string "Taken down again…\n"
	.string "Hehe…$"
	.else
	.ifdef GERMAN
	.string "Schon wieder verloren…\n"
	.string "Hähä…$"
	.endif
	.endif

MagmaHideout_4F_Text_TabithaPostBattle:
	.ifdef ENGLISH
	.string "…And while you wasted time with me,\n"
	.string "MAXIE should have awakened GROUDON…$"
	.else
	.ifdef GERMAN
	.string "Und während du deine Zeit mit mir\n"
	.string "verschwendest… sollte MARC\l"
	.string "GROUDON aufgeweckt haben…$"
	.endif
	.endif

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.ifdef ENGLISH
	.string "MAXIE: GROUDON…\p"
	.string "Nothing could awaken you from your\n"
	.string "sleep bathed in magma…\p"
	.string "This BLUE ORB is what you sought.\n"
	.string "Wasn't it?\p"
	.string "I have brought you the BLUE ORB.\n"
	.string "Let its shine awaken you!\p"
	.string "And show me…\n"
	.string "Show me the full extent of your power!$"
	.else
	.ifdef GERMAN
	.string "MARC: GROUDON…\p"
	.string "Nichts kann deinen Schlummer in\n"
	.string "dem heißen Magma stören…\p"
	.string "Du wolltest diese BLAUE KUGEL haben,\n"
	.string "nicht wahr?\p"
	.string "Ich habe sie dir gebracht.\n"
	.string "Ihr Licht soll dich aufwecken!\p"
	.string "Und nun zeig mir…\n"
	.string "Zeig mir deine ganze Kraft!$"
	.endif
	.endif

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.ifdef ENGLISH
	.string "MAXIE: GROUDON!\n"
	.string "What's wrong?\p"
	.string "Wasn't the BLUE ORB the key?\p"
	.string "GROUDON!\n"
	.string "Where have you gone…$"
	.else
	.ifdef GERMAN
	.string "MARC: GROUDON!\n"
	.string "Was ist los?\p"
	.string "Die BLAUE KUGEL ist doch der Schlüssel,\n"
	.string "oder etwa nicht?\p"
	.string "GROUDON!\n"
	.string "Wo bist du hin…$"
	.endif
	.endif

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.ifdef ENGLISH
	.string "MAXIE: Oh, so it was you?\p"
	.string "I've seen you poking around uninvited\n"
	.string "here and there…\p"
	.string "I get it now!\n"
	.string "You must have pulled a cheap stunt!$"
	.else
	.ifdef GERMAN
	.string "MARC: Du warst das also!\p"
	.string "Ich habe gesehen, wie du unerlaubter-\n"
	.string "weise deine Nase hier und dort\l"
	.string "hineingesteckt hast.\p"
	.string "Ich verstehe es jetzt!\n"
	.string "Du hast eine ganz billige Nummer\l"
	.string "abgezogen!$"
	.endif
	.endif

MagmaHideout_4F_Text_MaxieDefeat:
	.ifdef ENGLISH
	.string "What makes you so adept at handling\n"
	.string "POKéMON?$"
	.else
	.ifdef GERMAN
	.string "Wie kommt es, dass du so gut mit\n"
	.string "POKéMON umgehen kannst?$"
	.endif
	.endif

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.ifdef ENGLISH
	.string "MAXIE: There has to be some reason\n"
	.string "why GROUDON fled…\p"
	.string "That's what you're trying to say,\n"
	.string "aren't you?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Humph…\n"
	.string "You think I didn't know that?\p"
	.string "With GROUDON gone, there is no longer\n"
	.string "any need for this blasted volcano.\p"
	.string "I am going after GROUDON, so this\n"
	.string "is where we part!$"
	.else
	.ifdef GERMAN
	.string "MARC: Es muss einen Grund geben, warum\n"
	.string "GROUDON geflohen ist…\p"
	.string "Das willst du mir doch sagen, oder?\p"
	.string "… … … … …\n"
	.string "…\l"
	.string "… … … … …\l"
	.string "…\p"
	.string "Hmpf…\n"
	.string "Du meinst, das wüsste ich nicht?\p"
	.string "Da GROUDON weg ist, hat dieser Vulkan\n"
	.string "keinen Nutzen mehr.\p"
	.string "Ich werde GROUDON folgen. Hier trennen\n"
	.string "sich unsere Wege.$"
	.endif
	.endif
