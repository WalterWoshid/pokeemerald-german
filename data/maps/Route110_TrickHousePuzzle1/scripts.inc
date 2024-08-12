Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.ifdef ENGLISH
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is fabulous.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} hat den geheimen Code auf die\n"
	.string "Tür geschrieben.\p"
	.string "“RÄTSELMEISTER ist sagenhaft.”\n"
	.string "… … … … … … … …\p"
	.string "Das Schloss geht klickend auf.$"
	.endif
	.endif

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.ifdef ENGLISH
	.string "I'll hack and slash my way to victory\n"
	.string "with the CUT we just learned!$"
	.else
	.ifdef GERMAN
	.string "Ich habe mir den Weg zum Sieg mit dem\n"
	.string "ZERSCHNEIDER, den wir gerade gelernt\l"
	.string "haben, gebahnt.$"
	.endif
	.endif

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.ifdef ENGLISH
	.string "Why are you so serious?$"
	.else
	.ifdef GERMAN
	.string "Warum nimmst du das so ernst?$"
	.endif
	.endif

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.ifdef ENGLISH
	.string "I never get tired of hacking\n"
	.string "and slashing!$"
	.else
	.ifdef GERMAN
	.string "Ich werde des Hackens und\n"
	.string "Schneidens nie müde!$"
	.endif
	.endif

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.ifdef ENGLISH
	.string "I wandered into this weird house\n"
	.string "by accident…$"
	.else
	.ifdef GERMAN
	.string "Ich bin nur zufällig in diesem\n"
	.string "verrückten Haus gelandet…$"
	.endif
	.endif

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.ifdef ENGLISH
	.string "And now I've lost…$"
	.else
	.ifdef GERMAN
	.string "Und nun habe ich verloren…$"
	.endif
	.endif

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.ifdef ENGLISH
	.string "I lost my way, I lost a battle, and I'm\n"
	.string "now even more lost… I can't get out…$"
	.else
	.ifdef GERMAN
	.string "Ich bin vom Weg abgekommen, ich habe\n"
	.string "verloren und bin verloren. Ich finde den\l"
	.string "Ausgang nicht mehr…$"
	.endif
	.endif

Route110_TrickHousePuzzle1_Text_RobinIntro:
	.ifdef ENGLISH
	.string "Just who is the TRICK MASTER?$"
	.else
	.ifdef GERMAN
	.string "Wer ist dieser RÄTSELMEISTER bloß?$"
	.endif
	.endif

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.ifdef ENGLISH
	.string "I lost while I was lost in thought!$"
	.else
	.ifdef GERMAN
	.string "Ich verlor ganz gedankenverloren.$"
	.endif
	.endif

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.ifdef ENGLISH
	.string "You're strong!\n"
	.string "Just who are you?$"
	.else
	.ifdef GERMAN
	.string "Du bist stark!\n"
	.string "Wer bist du eigentlich?$"
	.endif
	.endif

