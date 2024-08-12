Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.ifdef ENGLISH
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is cool.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} hat den geheimen Code auf die\n"
	.string "Tür geschrieben.\p"
	.string "“RÄTSELMEISTER ist cool.”\n"
	.string "… … … … … … … …\p"
	.string "Das Schloss geht klickend auf.$"
	.endif
	.endif

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.ifdef ENGLISH
	.string "It's too much bother to think this out.\n"
	.string "I only wanted to battle!$"
	.else
	.ifdef GERMAN
	.string "Ich habe keine Zeit, das zu verstehen.\n"
	.string "Ich will nur kämpfen!$"
	.endif
	.endif

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.ifdef ENGLISH
	.string "Even though I lost, I still like battling\n"
	.string "the best!$"
	.else
	.ifdef GERMAN
	.string "Auch wenn ich verloren habe, liebe ich\n"
	.string "das Kämpfen.$"
	.endif
	.endif

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.ifdef ENGLISH
	.string "Wouldn't you agree? You would go\n"
	.string "anywhere if TRAINERS were there.$"
	.else
	.ifdef GERMAN
	.string "Stimmst du mir zu? Du würdest überall\n"
	.string "hingehen, wo man TRAINER findet.$"
	.endif
	.endif

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.ifdef ENGLISH
	.string "Heh! Boulders like this, I can brush\n"
	.string "aside with one finger!$"
	.else
	.ifdef GERMAN
	.string "Hey! Felsen wie diese räume ich mit\n"
	.string "dem kleinen Finger aus dem Weg.$"
	.endif
	.endif

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.ifdef ENGLISH
	.string "I can push boulders, but I can't solve\n"
	.string "the puzzle…$"
	.else
	.ifdef GERMAN
	.string "Ich kann Felsen bewegen, aber ein\n"
	.string "Rätsel zu lösen ist mir zu schwer…$"
	.endif
	.endif

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.ifdef ENGLISH
	.string "It's not good enough to be brawny…\n"
	.string "You have to use your head. Be brainy!$"
	.else
	.ifdef GERMAN
	.string "Muskeln alleine sind nicht alles… Auch\n"
	.string "Gehirnschmalz ist wichtig. Sei helle!$"
	.endif
	.endif

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.ifdef ENGLISH
	.string "The TRICK HOUSE is getting trickier,\n"
	.string "isn't it?$"
	.else
	.ifdef GERMAN
	.string "Das RÄTSELHAUS wird immer\n"
	.string "verrätselter… äh, komplizierter, oder?$"
	.endif
	.endif

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.ifdef ENGLISH
	.string "Aaak!$"
	.else
	.ifdef GERMAN
	.string "Aaaak!$"
	.endif
	.endif

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.ifdef ENGLISH
	.string "Has anyone made it to the end?$"
	.else
	.ifdef GERMAN
	.string "Hat es jemand schon mal bis zum\n"
	.string "Ende geschafft?$"
	.endif
	.endif

