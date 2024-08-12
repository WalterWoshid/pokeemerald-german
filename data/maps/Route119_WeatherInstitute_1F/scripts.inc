.set LOCALID_LITTLE_BOY, 5

Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.ifdef ENGLISH
	.string "The BOSS got interested in\n"
	.string "the research they have going here,\l"
	.string "so he sent us out.\p"
	.string "You quit meddling!$"
	.else
	.ifdef GERMAN
	.string "Der BOSS hat Interesse an den \n"
	.string "Forschungen gezeigt, daher hat er uns\l"
	.string "hergeschickt.\p"
	.string "Stör uns gefälligst nicht!$"
	.endif
	.endif

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.ifdef ENGLISH
	.string "Blast it…\n"
	.string "Blasted by a kid…$"
	.else
	.ifdef GERMAN
	.string "So ein Mist…\n"
	.string "Besiegt… von einem Kind!$"
	.endif
	.endif

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.ifdef ENGLISH
	.string "Our BOSS knows everything.\p"
	.string "But I'm just a GRUNT. What would I know\n"
	.string "about what he's thinking?$"
	.else
	.ifdef GERMAN
	.string "Unser BOSS weiß alles.\p"
	.string "Ich bin nur ein RÜPEL. Woher soll ich\n"
	.string "wissen, was er denkt?$"
	.endif
	.endif

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.ifdef ENGLISH
	.string "Huh?\n"
	.string "What's a kid doing here?$"
	.else
	.ifdef GERMAN
	.string "Wie?\n"
	.string "Was macht denn das Kind hier?$"
	.endif
	.endif

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.ifdef ENGLISH
	.string "Huh?\n"
	.string "I lost?!$"
	.else
	.ifdef GERMAN
	.string "Wie?\n"
	.string "Ich habe verloren?!?$"
	.endif
	.endif

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.ifdef ENGLISH
	.string "Oh, no…\n"
	.string "I'll catch an earful for losing to a kid…\p"
	.string "I should just take a nap in the bed…$"
	.else
	.ifdef GERMAN
	.string "Oh. Ich werde mir etwas anhören müssen,\n"
	.string "weil ich gegen ein Kind verloren habe…\p"
	.string "Ich muss mich jetzt dringend hinlegen…$"
	.endif
	.endif

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.ifdef ENGLISH
	.string "While I was sleeping, everyone went\n"
	.string "upstairs!$"
	.else
	.ifdef GERMAN
	.string "Als ich schlief, schlich sich jemand\n"
	.string "nach oben!$"
	.endif
	.endif

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.ifdef ENGLISH
	.string "Wow, you're really strong!\p"
	.string "I wish I could be a POKéMON TRAINER\n"
	.string "like you!$"
	.else
	.ifdef GERMAN
	.string "Wow! Bist du aber stark!\p"
	.string "Ich wäre auch gerne ein POKéMON-\n"
	.string "TRAINER wie du!$"
	.endif
	.endif

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.ifdef ENGLISH
	.string "The PROFESSOR loves rain.\n"
	.string "That's a fact.\p"
	.string "But if it keeps raining, people will be in\n"
	.string "trouble. That's another fact.\p"
	.string "And thus, the PROFESSOR is studying\n"
	.string "if the rain can be put to good use.$"
	.else
	.ifdef GERMAN
	.string "Der PROFESSOR liebt den Regen.\n"
	.string "Das ist eine Tatsache.\p"
	.string "Aber wenn es noch lange so regnet,\n"
	.string "wird das zu Problemen führen. Das ist\l"
	.string "die andere Seite der Medaille.\p"
	.string "Und daher erforscht der PROFESSOR,\n"
	.string "wie man den Regen positiv nutzen kann.$"
	.endif
	.endif

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.ifdef ENGLISH
	.string "On the 2nd floor of the INSTITUTE,\n"
	.string "we study the weather patterns over\l"
	.string "the HOENN region.\p"
	.string "We've been noticing temporary and\n"
	.string "isolated cases of droughts and\l"
	.string "heavy rain lately…$"
	.else
	.ifdef GERMAN
	.string "Im ersten Stock des INSTITUTs\n"
	.string "untersuchen wir die Klimaveränderungen\l"
	.string "in der HOENN-Region.\p"
	.string "Wir haben dort eine temporäre Dürre\n"
	.string "und einzelne Fälle von heftigem\l"
	.string "Niederschlag verzeichnen können.$"
	.endif
	.endif

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.ifdef ENGLISH
	.string "Hello!\n"
	.string "We've been saved by your actions!\p"
	.string "What I don't understand is what on\n"
	.string "earth the AQUAS were up to.$"
	.else
	.ifdef GERMAN
	.string "Hallo! Dein beherztes Eingreifen hat\n"
	.string "uns gerettet!\p"
	.string "Ich verstehe nur nicht, was die AQUAs\n"
	.string "von uns wollten…$"
	.endif
	.endif

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.ifdef ENGLISH
	.string "There's a bed…\n"
	.string "Let's take a rest.$"
	.else
	.ifdef GERMAN
	.string "Da steht ein Bett…\n"
	.string "Eine Pause wäre willkommen.$"
	.endif
	.endif

