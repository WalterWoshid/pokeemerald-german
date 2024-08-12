Text_BootUpPC:
	.ifdef ENGLISH
	.string "{PLAYER} booted up the PC.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} schaltet den PC ein.$"
	.endif
	.endif

gText_WhichPCShouldBeAccessed::
	.ifdef ENGLISH
	.string "Which PC should be accessed?$"
	.else
	.ifdef GERMAN
	.string "Zugriff auf wessen PC?$"
	.endif
	.endif

gText_AccessedSomeonesPC::
	.ifdef ENGLISH
	.string "Accessed SOMEONE'S PC.$"
	.else
	.ifdef GERMAN
	.string "Verbindung zu JEMANDES PC hergestellt.$"
	.endif
	.endif

gText_StorageSystemOpened::
	.ifdef ENGLISH
	.string "POKéMON Storage System opened.$"
	.else
	.ifdef GERMAN
	.string "POKéMON-Lagerungs-System geöffnet.$"
	.endif
	.endif

gText_AccessedPlayersPC::
	.ifdef ENGLISH
	.string "Accessed {PLAYER}'s PC.$"
	.else
	.ifdef GERMAN
	.string "Verbindung mit PC von {PLAYER}.$"
	.endif
	.endif

gText_AccessedLanettesPC::
	.ifdef ENGLISH
	.string "Accessed LANETTE's PC.$"
	.else
	.ifdef GERMAN
	.string "Verbindung zu LANETTEs PC hergestellt.$"
	.endif
	.endif
