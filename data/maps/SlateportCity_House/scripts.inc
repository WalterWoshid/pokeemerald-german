SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.ifdef ENGLISH
	.string "My POKéMON has a HASTY nature.\p"
	.string "It has higher SPEED compared to\n"
	.string "my other POKéMON.\p"
	.string "Maybe their nature has something to\n"
	.string "do with the stat gains of POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Mein POKéMON hat ein HASTIGes Wesen.\p"
	.string "Seine INITIATIVE ist im Vergleich\n"
	.string "zu meinen anderen POKéMON höher.\p"
	.string "Vielleicht hat ihr Wesen etwas mit den\n"
	.string "Statusvorteilen der POKéMON zu tun.$"
	.endif
	.endif

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.ifdef ENGLISH
	.string "You're a TRAINER, aren't you?\p"
	.string "Since you came to SLATEPORT CITY,\n"
	.string "you must be going to the BATTLE TENT.$"
	.else
	.ifdef GERMAN
	.string "Du bist doch ein TRAINER, oder?\p"
	.string "Da du schon mal in GRAPHITPORT CITY\n"
	.string "bist, besuch unbedingt das KAMPFCAMP!$"
	.endif
	.endif

