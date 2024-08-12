LilycoveCity_DepartmentStore_1F_Text_LotteryCornerDrawTicket:
	.ifdef ENGLISH
	.string "This is the POKéMON LOTTERY CORNER.\p"
	.string "All shoppers at our DEPARTMENT STORE\n"
	.string "get to draw a POKéMON LOTO TICKET.\p"
	.string "If the LOTO TICKET's number matches\n"
	.string "the ID number of any of your POKéMON,\l"
	.string "you will receive a fabulous gift.\p"
	.string "Would you like to draw a POKéMON\n"
	.string "LOTO TICKET?$"
	.else
	.ifdef GERMAN
	.string "Dies ist die POKéMON-LOTTERIE.\p"
	.string "Alle Besucher des EINKAUFSZENTRUMs\n"
	.string "können einen POKéMON-LOTTOSCHEIN\l"
	.string "ziehen.\p"
	.string "Wenn die Nummer des LOTTOSCHEINs mit\n"
	.string "der ID-Nummer eines deiner POKéMON\l"
	.string "übereinstimmt, gewinnst du einen Preis.\p"
	.string "Möchtest du einen\n"
	.string "POKéMON-LOTTOSCHEIN ziehen?$"
	.endif
	.endif

LilycoveCity_DepartmentStore_1F_Text_ComeBackTomorrow:
	.ifdef ENGLISH
	.string "Please come back tomorrow.$"
	.else
	.ifdef GERMAN
	.string "Bitte, komme morgen wieder.$"
	.endif
	.endif

LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain:
	.ifdef ENGLISH
	.string "Please do visit again.$"
	.else
	.ifdef GERMAN
	.string "Bitte, komm bald wieder.$"
	.endif
	.endif

LilycoveCity_DepartmentStore_1F_Text_PleasePickTicket:
	.ifdef ENGLISH
	.string "Please pick a LOTO TICKET.\n"
	.string "…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}$"
	.else
	.ifdef GERMAN
	.string "Bitte, ziehe einen LOTTOSCHEIN.\n"
	.string "…{PAUSE 15}{PAUSE 15}{PAUSE 15}{PAUSE 15}…{PAUSE 15}{PAUSE 15}{PAUSE 15}{PAUSE 15}…{PAUSE 15}{PAUSE 15}{PAUSE 15}{PAUSE 15}$"
	.endif
	.endif

LilycoveCity_DepartmentStore_1F_Text_TicketNumberIsXPleaseWait:
	.ifdef ENGLISH
	.string "The LOTO TICKET number is {STR_VAR_1}.\p"
	.string "I need to run a check on this number\n"
	.string "to see if it matches any of your\l"
	.string "POKéMON's ID numbers. Please wait.$"
	.else
	.ifdef GERMAN
	.string "Der LOTTOSCHEIN hat die Nummer {STR_VAR_1}.\p"
	.string "Ich muss diese Nummer jetzt prüfen,\n"
	.string "um zu sehen, ob sie mit der ID-Nummer\l"
	.string "eines deiner POKéMON übereinstimmt.$"
	.endif
	.endif

LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPartyMon:
	.ifdef ENGLISH
	.string "Congratulations!\p"
	.string "The ID number of your team's\n"
	.string "{STR_VAR_1} matches your\l"
	.string "LOTO TICKET's number!$"
	.else
	.ifdef GERMAN
	.string "Herzlichen Glückwunsch!\p"
	.string "Die ID-Nummer deines {STR_VAR_1} im\n"
	.string "Team stimmt mit der des LOTTO-\l"
	.string "SCHEINs überein!$"
	.endif
	.endif

LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPCMon:
	.ifdef ENGLISH
	.string "Congratulations!\p"
	.string "The ID number of your PC-boxed\n"
	.string "{STR_VAR_1} matches your\l"
	.string "LOTO TICKET's number!$"
	.else
	.ifdef GERMAN
	.string "Herzlichen Glückwunsch!\p"
	.string "Die ID-Nummer deines {STR_VAR_1} in\n"
	.string "der Box des PCs stimmt mit der des\l"
	.string "LOTTOSCHEINs überein!$"
	.endif
	.endif

LilycoveCity_DepartmentStore_1F_Text_NoNumbersMatched:
	.ifdef ENGLISH
	.string "I'm sorry.\n"
	.string "None of the numbers matched.$"
	.else
	.ifdef GERMAN
	.string "Tut mir Leid.\n"
	.string "Keine der Nummern stimmt überein.$"
	.endif
	.endif

LilycoveCity_DepartmentStore_1F_Text_TwoDigitsMatched:
	.ifdef ENGLISH
	.string "Two digits matched, so you win the\n"
	.string "third prize!\l"
	.string "You've won the {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Zwei Ziffern stimmen überein,\n"
	.string "daher bekommst du den dritten Preis!\l"
	.string "Du gewinnst {STR_VAR_1}!$"
	.endif
	.endif

LilycoveCity_DepartmentStore_1F_Text_ThreeDigitsMatched:
	.ifdef ENGLISH
	.string "Three digits matched, so you win the\n"
	.string "second prize!\l"
	.string "You've won the {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Drei Ziffern stimmen überein,\n"
	.string "daher bekommst du den zweiten Preis!\l"
	.string "Du gewinnst {STR_VAR_1}!$"
	.endif
	.endif

LilycoveCity_DepartmentStore_1F_Text_FourDigitsMatched:
	.ifdef ENGLISH
	.string "Four digits matched, so you win the\n"
	.string "first prize!\l"
	.string "You've won the {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Vier Ziffern stimmen überein,\n"
	.string "daher bekommst du den ersten Preis!\l"
	.string "Du gewinnst {STR_VAR_1}!$"
	.endif
	.endif

LilycoveCity_DepartmentStore_1F_Text_AllFiveDigitsMatched:
	.ifdef ENGLISH
	.string "Oh, my goodness, all five digits\n"
	.string "matched!\p"
	.string "You've won the jackpot prize!\n"
	.string "You've won the {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Meine Güte! Alle fünf Ziffern stimmen\n"
	.string "überein!\p"
	.string "Du hast den Jackpot geknackt!\n"
	.string "Du gewinnst {STR_VAR_1}!$"
	.endif
	.endif

LilycoveCity_DepartmentStore_1F_Text_NoRoomForThis:
	.ifdef ENGLISH
	.string "Oh?\n"
	.string "You seem to have no room for this.\p"
	.string "Please make room in your BAG and\n"
	.string "let me know.$"
	.else
	.ifdef GERMAN
	.string "Oh! Du scheinst keinen Platz\n"
	.string "dafür zu haben.\p"
	.string "Wenn du wieder Platz in deinem BEUTEL\n"
	.string "hast, lass es mich wissen.$"
	.endif
	.endif

LilycoveCity_DepartmentStore_1F_Text_PrizeWeveBeenHolding:
	.ifdef ENGLISH
	.string "{PLAYER}?\n"
	.string "Yes, I've been expecting you.\p"
	.string "This is the prize we've been holding\n"
	.string "for you.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER}?\n"
	.string "Ja, ich habe dich schon erwartet.\p"
	.string "Diesen Preis habe ich für dich\n"
	.string "aufbewahrt.$"
	.endif
	.endif

LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain2:
	.ifdef ENGLISH
	.string "Please do visit again.$"
	.else
	.ifdef GERMAN
	.string "Bitte komm bald wieder.$"
	.endif
	.endif
