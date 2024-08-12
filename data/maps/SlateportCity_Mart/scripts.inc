SlateportCity_Mart_MapScripts::
	.byte 0

SlateportCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_HARBOR_MAIL
	.2byte ITEM_NONE
	release
	end

SlateportCity_Mart_EventScript_BlackBelt::
	msgbox SlateportCity_Mart_Text_SomeItemsOnlyAtMart, MSGBOX_NPC
	end

SlateportCity_Mart_EventScript_Man::
	msgbox SlateportCity_Mart_Text_GreatBallIsBetter, MSGBOX_NPC
	end

SlateportCity_Mart_Text_SomeItemsOnlyAtMart:
	.ifdef ENGLISH
	.string "The MARKET does have some interesting\n"
	.string "merchandise.\p"
	.string "But there are some items you can only\n"
	.string "get at a POKéMON MART.$"
	.else
	.ifdef GERMAN
	.string "Der MARKT bietet einige interessante\n"
	.string "Merchandising-Artikel an.\p"
	.string "Aber einige Sachen wirst du nur in einem\n"
	.string "POKéMON-SUPERMARKT finden.$"
	.endif
	.endif

SlateportCity_Mart_Text_GreatBallIsBetter:
	.ifdef ENGLISH
	.string "A GREAT BALL is better than a POKé BALL\n"
	.string "at catching POKéMON.\p"
	.string "With this, I should be able to get that\n"
	.string "elusive POKéMON…$"
	.else
	.ifdef GERMAN
	.string "Ein SUPERBALL eignet sich besser zum\n"
	.string "Fangen von POKéMON als ein POKéBALL.\p"
	.string "Hiermit sollte ich in der Lage sein, das\n"
	.string "begehrte POKéMON zu überlisten.$"
	.endif
	.endif

