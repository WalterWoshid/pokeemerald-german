PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_HORSEA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PacifidlogTown_House3_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House3_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PacifidlogTown_House3_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, PacifidlogTown_House3_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou, MSGBOX_DEFAULT
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.ifdef ENGLISH
	.string "Check out this {STR_VAR_2}!\p"
	.string "It's the {STR_VAR_2} that I caught\n"
	.string "yesterday to celebrate my birthday!\p"
	.string "Oh, I can see that you want it!\n"
	.string "After all, it's priceless!\p"
	.string "I'll tell you what. I might be willing\n"
	.string "to trade it for a {STR_VAR_1}.$"
	.else
	.ifdef GERMAN
	.string "Schau dir dieses {STR_VAR_2} an!\p"
	.string "Das {STR_VAR_2} habe ich gestern ge-\n"
	.string "fangen, um meinen Geburtstag zu feiern.\p"
	.string "Oh, ich sehe dir an der Nasenspitze an,\n"
	.string "dass du es gerne hättest! Aber es ist\p"
	.string "unbezahlbar! Ich bin aber bereit, es\n"
	.string "gegen ein {STR_VAR_1} zu tauschen.$"
	.endif
	.endif

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.ifdef ENGLISH
	.string "Oh, so this is a {STR_VAR_1}?\p"
	.string "It's sort of like a {STR_VAR_2},\n"
	.string "and yet it's subtly different.\p"
	.string "Thank you!$"
	.else
	.ifdef GERMAN
	.string "Oh, das ist also ein {STR_VAR_1}?\p"
	.string "Es sieht einem {STR_VAR_2} ähnlich und\n"
	.string "ist doch völlig anders.\p"
	.string "Danke schön!$"
	.endif
	.endif

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.ifdef ENGLISH
	.string "No, no, no! I won't accept any\n"
	.string "less than a real {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Nein, nein, nein! Ich akzeptiere nur ein\n"
	.string "echtes {STR_VAR_1}!!!$"
	.endif
	.endif

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.ifdef ENGLISH
	.string "Oh, so you're not going to go through\n"
	.string "with this?\p"
	.string "That's cool. I'm not desperate to make\n"
	.string "a trade or anything.$"
	.else
	.ifdef GERMAN
	.string "Oh, du willst also nicht mit mir\n"
	.string "tauschen?\p"
	.string "Macht nichts. Ich bin gar nicht so wild\n"
	.string "auf einen Tausch!$"
	.endif
	.endif

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.ifdef ENGLISH
	.string "I know I could go looking for one\n"
	.string "on my own, but…\p"
	.string "But I really wanted to get a BAGON\n"
	.string "that another TRAINER caught…$"
	.else
	.ifdef GERMAN
	.string "Ich weiß, ich könnte mir ja auch selbst\n"
	.string "eines suchen…\p"
	.string "Aber ich hätte gerne ein KINDWURM, das\n"
	.string "von einem anderen TRAINER\l"
	.string "gefangen wurde…$"
	.endif
	.endif

PacifidlogTown_House3_Text_IsThatAPokedex:
	.ifdef ENGLISH
	.string "Is that a POKéDEX?\p"
	.string "Did you get to meet a lot of different\n"
	.string "POKéMON?\p"
	.string "I wish I was like you.$"
	.else
	.ifdef GERMAN
	.string "Ist das ein POKéDEX?\p"
	.string "Hast du schon viele verschiedene\n"
	.string "POKéMON getroffen?\p"
	.string "Ich wollte, ich wäre wie du.$"
	.endif
	.endif

