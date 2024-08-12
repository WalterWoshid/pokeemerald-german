BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_MEOWTH
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge6_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge6_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, BattleFrontier_Lounge6_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt, MSGBOX_DEFAULT
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
	.ifdef ENGLISH
	.string "My POKéMON is a {STR_VAR_2}.\n"
	.string "Do you know it?\l"
	.string "It's quite cute and rather nice.\p"
	.string "This little one, I could trade with\n"
	.string "pride!\p"
	.string "Would you like to trade me a {STR_VAR_1}\n"
	.string "for my {STR_VAR_2}?$"
	.else
	.ifdef GERMAN
	.string "Mein POKéMON ist ein {STR_VAR_2}.\n"
	.string "Kennst du das?\l"
	.string "Es ist sehr süß und hübsch.\p"
	.string "Diesen kleinen Schatz könnte ich ohne\n"
	.string "Bedenken tauschen.\p"
	.string "Möchtest du mein {STR_VAR_2} haben?\n"
	.string "Dann gib mir ein {STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
	.ifdef ENGLISH
	.string "Oh, it's adorable!\n"
	.string "Thank you!\l"
	.string "I promise I'll be good to it!\p"
	.string "Oh! I hope you'll be good to\n"
	.string "my {STR_VAR_2}, too!$"
	.else
	.ifdef GERMAN
	.string "Oh, das ist einfach meganiedlich.\n"
	.string "Vielen Dank! Ich verspreche, es\l"
	.string "wird es gut bei mir haben!\p"
	.string "Oh! Und ich hoffe, du bist auch gut\n"
	.string "zu meinem {STR_VAR_2}!$"
	.endif
	.endif

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
	.ifdef ENGLISH
	.string "Oh, I'm sorry!\n"
	.string "I don't intend to trade for anything\l"
	.string "but a {STR_VAR_1}.$"
	.else
	.ifdef GERMAN
	.string "Oh, tut mir Leid!\n"
	.string "Ich tausche nur, wenn ich dafür ein\l"
	.string "{STR_VAR_1} bekomme!$"
	.endif
	.endif

BattleFrontier_Lounge6_Text_WellThatsFineToo:
	.ifdef ENGLISH
	.string "Oh, you won't?\n"
	.string "Well, that's fine, too.\l"
	.string "Please come visit us again.$"
	.else
	.ifdef GERMAN
	.string "Oh, du magst nicht tauschen?\n"
	.string "Nun, das ist auch in Ordnung.\l"
	.string "Komm doch bald mal wieder vorbei.$"
	.endif
	.endif

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
	.ifdef ENGLISH
	.string "Giggle!\n"
	.string "A SKITTY is so much cuter than I had\l"
	.string "imagined. I'm delighted!$"
	.else
	.ifdef GERMAN
	.string "Kicher!\n"
	.string "Ein ENECO ist viel süüüßer, als ich\l"
	.string "gedacht habe. Ich bin total glücklich!$"
	.endif
	.endif
