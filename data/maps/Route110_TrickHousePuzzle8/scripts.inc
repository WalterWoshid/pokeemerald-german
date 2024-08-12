Route110_TrickHousePuzzle8_MapScripts::
	.byte 0

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle8_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Keira::
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Leroy::
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
	.ifdef ENGLISH
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER I love.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} hat den geheimen Code auf die\n"
	.string "Tür geschrieben.\p"
	.string "“Ich liebe den RÄTSELMEISTER.”\n"
	.string "… … … … … … … …\p"
	.string "Das Schloss geht klickend auf.$"
	.endif
	.endif

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.ifdef ENGLISH
	.string "Not many TRAINERS have made it\n"
	.string "this far.$"
	.else
	.ifdef GERMAN
	.string "Nicht viele TRAINER haben es bis\n"
	.string "hierher geschafft.$"
	.endif
	.endif

Route110_TrickHousePuzzle8_Text_VincentDefeat:
	.ifdef ENGLISH
	.string "That must mean you're tough, too…$"
	.else
	.ifdef GERMAN
	.string "Das bedeutet, dass du sehr stark bist…$"
	.endif
	.endif

Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.ifdef ENGLISH
	.string "You've beaten the POKéMON LEAGUE\n"
	.string "CHAMPION? That's too much!$"
	.else
	.ifdef GERMAN
	.string "Du hast den CHAMP der POKéMON LIGA\n"
	.string "besiegt? Das ist zu viel für mich!$"
	.endif
	.endif

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.ifdef ENGLISH
	.string "Consider yourself lucky to be\n"
	.string "battling me!$"
	.else
	.ifdef GERMAN
	.string "Sieh es als Glücksfall an, dass du gegen\n"
	.string "mich antreten darfst.$"
	.endif
	.endif

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.ifdef ENGLISH
	.string "This isn't right!\n"
	.string "I can't lose!$"
	.else
	.ifdef GERMAN
	.string "Das ist nicht korrekt!\n"
	.string "Ich darf nicht verlieren!$"
	.endif
	.endif

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.ifdef ENGLISH
	.string "It's a miracle that you beat me.\n"
	.string "You can brag about it.$"
	.else
	.ifdef GERMAN
	.string "Nur ein Wunder hat dir zu diesem Sieg\n"
	.string "verholfen. Prahl doch damit…$"
	.endif
	.endif

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.ifdef ENGLISH
	.string "You've been slugging through the TRICK\n"
	.string "HOUSE challenge, too.$"
	.else
	.ifdef GERMAN
	.string "Du schleichst hier auch durch das\n"
	.string "RÄTSELHAUS?$"
	.endif
	.endif

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.ifdef ENGLISH
	.string "I see…\n"
	.string "You possess an extraordinary style.$"
	.else
	.ifdef GERMAN
	.string "Ich verstehe…\n"
	.string "Du hast einen außergewöhnlichen Stil.$"
	.endif
	.endif

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.ifdef ENGLISH
	.string "Seeing someone like you should please\n"
	.string "the TRICK MASTER.$"
	.else
	.ifdef GERMAN
	.string "Dein Anblick wird den RÄTSELMEISTER\n"
	.string "bestimmt erfreuen.$"
	.endif
	.endif

