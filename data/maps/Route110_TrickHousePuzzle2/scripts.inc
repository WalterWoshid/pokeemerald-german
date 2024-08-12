Route110_TrickHousePuzzle2_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle2_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle2_OnTransition
	.byte 0

Route110_TrickHousePuzzle2_OnResume:
	call_if_eq VAR_TEMP_1, 1, Route110_TrickHousePuzzle2_EventScript_PressButton1
	call_if_eq VAR_TEMP_2, 1, Route110_TrickHousePuzzle2_EventScript_PressButton2
	call_if_eq VAR_TEMP_3, 1, Route110_TrickHousePuzzle2_EventScript_PressButton3
	call_if_eq VAR_TEMP_4, 1, Route110_TrickHousePuzzle2_EventScript_PressButton4
	end

Route110_TrickHousePuzzle2_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	end

Route110_TrickHousePuzzle2_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_2_STATE, 0, Route110_TrickHousePuzzle2_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle2_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_2_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle2_EventScript_Button1::
	lockall
	setvar VAR_TEMP_1, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_PressButton1
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_Button2::
	lockall
	setvar VAR_TEMP_2, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_PressButton2
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_Button3::
	lockall
	setvar VAR_TEMP_3, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_PressButton3
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_Button4::
	lockall
	setvar VAR_TEMP_4, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_PressButton4
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_PressButton1::
	setmetatile 11, 12, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 1, 13, METATILE_TrickHousePuzzle_Door_Shuttered, FALSE
	return

Route110_TrickHousePuzzle2_EventScript_PressButton2::
	setmetatile 0, 4, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 5, 6, METATILE_TrickHousePuzzle_Door_Shuttered, FALSE
	return

Route110_TrickHousePuzzle2_EventScript_PressButton3::
	setmetatile 14, 5, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 7, 15, METATILE_TrickHousePuzzle_Door_Shuttered, FALSE
	return

Route110_TrickHousePuzzle2_EventScript_PressButton4::
	setmetatile 7, 11, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 14, 12, METATILE_TrickHousePuzzle_Door_Shuttered, FALSE
	return

Route110_TrickHousePuzzle2_EventScript_Ted::
	trainerbattle_single TRAINER_TED, Route110_TrickHousePuzzle2_Text_TedIntro, Route110_TrickHousePuzzle2_Text_TedDefeat
	msgbox Route110_TrickHousePuzzle2_Text_TedPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle2_EventScript_Paul::
	trainerbattle_single TRAINER_PAUL, Route110_TrickHousePuzzle2_Text_PaulIntro, Route110_TrickHousePuzzle2_Text_PaulDefeat
	msgbox Route110_TrickHousePuzzle2_Text_PaulPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle2_EventScript_Georgia::
	trainerbattle_single TRAINER_GEORGIA, Route110_TrickHousePuzzle2_Text_GeorgiaIntro, Route110_TrickHousePuzzle2_Text_GeorgiaDefeat
	msgbox Route110_TrickHousePuzzle2_Text_GeorgiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle2_Text_WroteSecretCodeLockOpened:
	.ifdef ENGLISH
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is smart.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} hat den geheimen Code auf die\n"
	.string "Tür geschrieben.\p"
	.string "“RÄTSELMEISTER ist gewieft.”\n"
	.string "… … … … … … … …\p"
	.string "Das Schloss geht klickend auf.$"
	.endif
	.endif

Route110_TrickHousePuzzle2_Text_TedIntro:
	.ifdef ENGLISH
	.string "Which switch closes which hole?$"
	.else
	.ifdef GERMAN
	.string "Welcher Schalter schließt welches\n"
	.string "Loch?$"
	.endif
	.endif

Route110_TrickHousePuzzle2_Text_TedDefeat:
	.ifdef ENGLISH
	.string "After that battle, I'm even more\n"
	.string "confused!$"
	.else
	.ifdef GERMAN
	.string "Nach diesem Kampf bin ich nur noch\n"
	.string "verwirrter!$"
	.endif
	.endif

Route110_TrickHousePuzzle2_Text_TedPostBattle:
	.ifdef ENGLISH
	.string "Can I get you to push all the buttons\n"
	.string "for me?$"
	.else
	.ifdef GERMAN
	.string "Kannst du nicht alle Schalter für mich\n"
	.string "betätigen?$"
	.endif
	.endif

Route110_TrickHousePuzzle2_Text_PaulIntro:
	.ifdef ENGLISH
	.string "Oh! You're on your second TRICK HOUSE\n"
	.string "challenge!$"
	.else
	.ifdef GERMAN
	.string "Oh! Du forderst das RÄTSELHAUS schon\n"
	.string "zum zweiten Mal heraus!?!$"
	.endif
	.endif

Route110_TrickHousePuzzle2_Text_PaulDefeat:
	.ifdef ENGLISH
	.string "You're good at battling too?$"
	.else
	.ifdef GERMAN
	.string "Du bist auch im Kämpfen so gut!?!$"
	.endif
	.endif

Route110_TrickHousePuzzle2_Text_PaulPostBattle:
	.ifdef ENGLISH
	.string "The TRICK MASTER rigged all the tricks\n"
	.string "in this house all by himself.$"
	.else
	.ifdef GERMAN
	.string "Der RÄTSELMEISTER tüftelt alle Tricks\n"
	.string "in diesem Haus selber aus.$"
	.endif
	.endif

Route110_TrickHousePuzzle2_Text_GeorgiaIntro:
	.ifdef ENGLISH
	.string "I want to make my own GYM one day.\n"
	.string "So, I'm studying how to set traps.$"
	.else
	.ifdef GERMAN
	.string "Eines Tages gründe ich meine eigene\n"
	.string "ARENA. Und hier studiere ich die Fallen.$"
	.endif
	.endif

Route110_TrickHousePuzzle2_Text_GeorgiaDefeat:
	.ifdef ENGLISH
	.string "I didn't study battling enough!$"
	.else
	.ifdef GERMAN
	.string "Ich habe das Kämpfen nicht genug\n"
	.string "studiert!$"
	.endif
	.endif

Route110_TrickHousePuzzle2_Text_GeorgiaPostBattle:
	.ifdef ENGLISH
	.string "You're strong, aren't you?\n"
	.string "Maybe even enough to be a GYM LEADER!$"
	.else
	.ifdef GERMAN
	.string "Du bist stark, nicht wahr?\n"
	.string "Stark genug, ein ARENALEITER zu sein.$"
	.endif
	.endif

