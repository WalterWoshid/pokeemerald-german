	.align 2
gText_ConfirmSave::
	.ifdef ENGLISH
	.string "Would you like to save the game?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du das Spiel speichern?$"
	.endif
	.endif

gText_AlreadySavedFile::
	.ifdef ENGLISH
	.string "There is already a saved file.\n"
	.string "Is it okay to overwrite it?$"
	.else
	.ifdef GERMAN
	.string "Es gibt bereits einen Spielstand.\n"
	.string "Spielstand überschreiben?$"
	.endif
	.endif

gText_SavingDontTurnOff::
	.ifdef ENGLISH
	.string "SAVING…\n"
	.string "DON'T TURN OFF THE POWER.$"
	.else
	.ifdef GERMAN
	.string "SPEICHERN…\n"
	.string "BITTE DAS GERÄT NICHT AUSSCHALTEN.$"
	.endif
	.endif

gText_PlayerSavedGame::
	.ifdef ENGLISH
	.string "{PLAYER} saved the game.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} hat das Spiel gespeichert.$"
	.endif
	.endif

gText_DifferentSaveFile::
	.ifdef ENGLISH
	.string "WARNING!\p"
	.string "There is a different game file that\n"
	.string "is already saved.\p"
	.string "If you save now, the other file's\n"
	.string "adventure, including items and\l"
	.string "POKéMON, will be entirely lost.\p"
	.string "Are you sure you want to save now\n"
	.string "and overwrite the other save file?$"
	.else
	.ifdef GERMAN
	.string "ACHTUNG!\p"
	.string "Es gibt bereits einen Spielstand.\p"
	.string "Wenn jetzt gesichert wird, geht\n"
	.string "der andere Spielstand mit allen\l"
	.string "Items und POKéMON für immer\l"
	.string "verloren.\l"
	.string "Bist du sicher, dass du sichern\l"
	.string "und den anderen Spielstand\l"
	.string "überschreiben möchtest?$"
	.endif
	.endif

gText_SaveError::
	.ifdef ENGLISH
	.string "Save error.\p"
	.string "Please exchange the\n"
	.string "backup memory.$"
	.else
	.ifdef GERMAN
	.string "Fehler beim Speichern!\p"
	.string "Bitte Backup Memory\n"
	.string "austauschen.$"
	.endif
	.endif

gText_SavingDontTurnOffPower::
	.ifdef ENGLISH
	.string "SAVING…\n"
	.string "DON'T TURN OFF THE POWER.$"
	.else
	.ifdef GERMAN
	.string "SPEICHERN…\n"
	.string "BITTE DAS GERÄT NICHT AUSSCHALTEN.$"
	.endif
	.endif
