gText_PkmnTransferredSomeonesPC::
	.ifdef ENGLISH
	.string "{STR_VAR_2} was transferred to\n"
	.string "SOMEONE'S PC.\p"
	.string "It was placed in \n"
	.string "BOX “{STR_VAR_1}.”$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2} wurde auf JEMANDES PC\n"
	.string "übertragen.\p"
	.string "Es wurde in BOX\n"
	.string "“{STR_VAR_1}” abgelegt.$"
	.endif
	.endif

gText_PkmnTransferredLanettesPC::
	.ifdef ENGLISH
	.string "{STR_VAR_2} was transferred to\n"
	.string "LANETTE'S PC.\p"
	.string "It was placed in \n"
	.string "BOX “{STR_VAR_1}.”$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2} wurde auf LANETTEs PC\n"
	.string "übertragen.\p"
	.string "Es wurde in BOX\n"
	.string "“{STR_VAR_1}” abgelegt.$"
	.endif
	.endif

gText_PkmnTransferredSomeonesPCBoxFull::
	.ifdef ENGLISH
	.string "BOX “{STR_VAR_3}” on\n"
	.string "SOMEONE'S PC was full.\p"
	.string "{STR_VAR_2} was transferred to\n"
	.string "BOX “{STR_VAR_1}.”$"
	.else
	.ifdef GERMAN
	.string "BOX “{STR_VAR_3}” in\n"
	.string "JEMANDES PC ist voll.\p"
	.string "{STR_VAR_2} wurde in BOX\n"
	.string "“{STR_VAR_1}” übertragen.$"
	.endif
	.endif

gText_PkmnTransferredLanettesPCBoxFull::
	.ifdef ENGLISH
	.string "BOX “{STR_VAR_3}” on\n"
	.string "LANETTE'S PC was full.\p"
	.string "{STR_VAR_2} was transferred to\n"
	.string "BOX “{STR_VAR_1}.”$"
	.else
	.ifdef GERMAN
	.string "BOX “{STR_VAR_3}” in\n"
	.string "LANETTEs PC ist voll.\p"
	.string "{STR_VAR_2} wurde in BOX\n"
	.string "“{STR_VAR_1}” übertragen.$"
	.endif
	.endif

gText_NoMoreRoomForPokemon::
	.ifdef ENGLISH
	.string "There's no more room for POKéMON!\p"
	.string "The POKéMON BOXES are full and\n"
	.string "can't accept any more!$"
	.else
	.ifdef GERMAN
	.string "Es ist kein Platz mehr für POKéMON\n"
	.string "vorhanden!\p"
	.string "Die POKéMON BOXen sind voll und\n"
	.string "es kann kein POKéMON mehr\l"
	.string "abgelegt werden!$"
	.endif
	.endif

gText_NicknameThisPokemon::
	.ifdef ENGLISH
	.string "Do you want to give a nickname to\n"
	.string "this {STR_VAR_1}?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du {STR_VAR_1} einen\n"
	.string "Spitznamen geben?$"
	.endif
	.endif
