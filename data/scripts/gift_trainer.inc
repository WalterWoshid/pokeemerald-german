MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.ifdef ENGLISH
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "By holding this WONDER CARD, you\n"
	.string "may take part in a survey at a\l"
	.string "POKéMON MART.\p"
	.string "Use these surveys to invite\n"
	.string "TRAINERS to SOOTOPOLIS CITY.\p"
	.string "…Let me give you a secret\n"
	.string "password for a survey:\p"
	.string "“GIVE ME\n"
	.string "AWESOME TRAINER”\p"
	.string "Write that in on a survey and send\n"
	.string "it to the WIRELESS\l"
	.string "COMMUNICATION SYSTEM.$"
	.else
	.ifdef GERMAN
	.string "Danke, dass du das GEHEIM-\n"
	.string "GESCHEHEN benutzt hast.\p"
	.string "Da du im Besitz dieser WUNDER-\n"
	.string "KARTE bist, darfst du bei einer\l"
	.string "Umfrage im PKMN-SUPERMARKT\l"
	.string "teilnehmen.\l"
	.string "Lade andere TRAINER zu diesen\l"
	.string "Umfragen nach XENEROVILLE\l"
	.string "ein.\l"
	.string "… Ich gebe dir ein geheimes\l"
	.string "Passwort für die Umfrage:\p"
	.string "“GIB MIR COOLE\n"
	.string "TRAINER”\p"
	.string "Schreibe dies in eine Umfrage und\n"
	.string "schicke es zum DRAHTLOSEN\l"
	.string "KOMMUNIKATIONS-SYSTEM.$"
	.endif
	.endif

sText_MysteryGiftVisitingTrainerArrived:
	.ifdef ENGLISH
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "A TRAINER has arrived in\n"
	.string "SOOTOPOLIS CITY looking for you.\p"
	.string "We hope you will enjoy\n"
	.string "battling the visiting TRAINER.\p"
	.string "You may invite other TRAINERS by\n"
	.string "entering other passwords.\p"
	.string "Try looking for other passwords\n"
	.string "that may work.$"
	.else
	.ifdef GERMAN
	.string "Danke, dass du das GEHEIM-\n"
	.string "GESCHEHEN benutzt hast.\p"
	.string "Ein TRAINER, der nach XENEROVILLE\n"
	.string "gekommen ist, sucht dich!\l"
	.string "Wir hoffen, der Kampf gegen\l"
	.string "diesen TRAINER macht dir Spaß!\p"
	.string "Wenn du andere Passwörter ein-\n"
	.string "gibst, kannst du andere TRAINER\l"
	.string "einladen.\l"
	.string "Sieh dich nach anderen Passwörtern\l"
	.string "um, die evtl. funktionieren könnten.$"
	.endif
	.endif
