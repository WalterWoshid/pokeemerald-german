@ With the exception of Link standby, none of the below texts are used

gTest_MissedTurn::
	.ifdef ENGLISH
	.string "Missed turn$"
	.else
	.ifdef GERMAN
	.string "Missed turn$"
	.endif
	.endif

gText_LinkStandby4::
	.ifdef ENGLISH
	.string "Link standby!$"
	.else
	.ifdef GERMAN
	.string "Verbindung…$"
	.endif
	.endif

gText_WinnerIsPlayersMonCongrats::
	.ifdef ENGLISH
	.string "The winner is {STR_VAR_1}'s {STR_VAR_2}!\n"
	.string "Congratulations!$"
	.else
	.ifdef GERMAN
	.string "The winner is {STR_VAR_1}’s {STR_VAR_2}!\n"
	.string "Congratulations!$"
	.endif
	.endif

gText_WinnerIsPlayersMon::
	.ifdef ENGLISH
	.string "The winner is {STR_VAR_1}'s {STR_VAR_2}!{PAUSE_UNTIL_PRESS}$"
	.else
	.ifdef GERMAN
	.string "Gewinner: {STR_VAR_2} von {STR_VAR_1}!{PAUSE_UNTIL_PRESS}$"
	.endif
	.endif

gText_PrimaryJudgingNumX::
	.ifdef ENGLISH
	.string "Primary judging: No. {STR_VAR_1}{PAUSE_UNTIL_PRESS}$"
	.else
	.ifdef GERMAN
	.string "Erstes Urteil: Nr. {STR_VAR_1}{PAUSE_UNTIL_PRESS}$"
	.endif
	.endif

gText_SecondaryJudgingNumX::
	.ifdef ENGLISH
	.string "Secondary judging: No. {STR_VAR_1}{PAUSE_UNTIL_PRESS}$"
	.else
	.ifdef GERMAN
	.string "Zweites Urteil: Nr. {STR_VAR_1}{PAUSE_UNTIL_PRESS}$"
	.endif
	.endif

gText_SetEventNumX::
	.ifdef ENGLISH
	.string "Set event: No. {STR_VAR_1}{PAUSE_UNTIL_PRESS}$"
	.else
	.ifdef GERMAN
	.string "Event Nr. {STR_VAR_1}{PAUSE_UNTIL_PRESS}$"
	.endif
	.endif

gText_MoveUsedMostOften::
	.ifdef ENGLISH
	.string "The move used most often:\n"
	.string "{STR_VAR_1}{PAUSE_UNTIL_PRESS}$"
	.else
	.ifdef GERMAN
	.string "Attacke, die am häufigsten eingesetzt\n"
	.string "wurde: {STR_VAR_1}{PAUSE_UNTIL_PRESS}$"
	.endif
	.endif

gText_MostImpressiveMon::
	.ifdef ENGLISH
	.string "The most impressive POKéMON:\n"
	.string "{STR_VAR_1}'s {STR_VAR_2}{PAUSE_UNTIL_PRESS}$"
	.else
	.ifdef GERMAN
	.string "Das beeindruckendste POKéMON:\n"
	.string "{STR_VAR_2} von {STR_VAR_1}{PAUSE_UNTIL_PRESS}$"
	.endif
	.endif

gText_SetEventNumX2::
	.ifdef ENGLISH
	.string "Set event: No. {STR_VAR_1}{PAUSE_UNTIL_PRESS}$"
	.else
	.ifdef GERMAN
	.string "Event Nr. {STR_VAR_1}{PAUSE_UNTIL_PRESS}$"
	.endif
	.endif

gText_LinkTVProgramWillNotBeMadeTrainerLost::
	.ifdef ENGLISH
	.string "A link TV program will not be made\n"
	.string "because the TRAINER lost.{PAUSE_UNTIL_PRESS}$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER hat verloren, daher wird\n"
	.string "kein TV-Programm gesendet.$"
	.endif
	.endif
