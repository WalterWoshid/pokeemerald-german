OldaleTown_Mart_MapScripts::
	.byte 0

OldaleTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_ExpandedItems
	pokemart OldaleTown_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Basic:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end

OldaleTown_Mart_ExpandedItems::
	pokemart OldaleTown_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end

OldaleTown_Mart_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_PokeBallsInStock
	msgbox OldaleTown_Mart_Text_PokeBallsAreSoldOut, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_PokeBallsInStock::
	msgbox OldaleTown_Mart_Text_ImGoingToBuyPokeBalls, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_Boy::
	msgbox OldaleTown_Mart_Text_RestoreHPWithPotion, MSGBOX_NPC
	end

OldaleTown_Mart_Text_PokeBallsAreSoldOut:
	.ifdef ENGLISH
	.string "The clerk says they're all sold out.\n"
	.string "I can't buy any POKé BALLS.$"
	.else
	.ifdef GERMAN
	.string "Der Verkäufer sagt, es sei alles\n"
	.string "ausverkauft. Jetzt stehe ich ohne\l"
	.string "POKéBÄLLE da.$"
	.endif
	.endif

OldaleTown_Mart_Text_ImGoingToBuyPokeBalls:
	.ifdef ENGLISH
	.string "I'm going to buy a bunch of POKé BALLS\n"
	.string "and catch a bunch of POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Ich will mir viele POKéBÄLLe kaufen und\n"
	.string "damit genauso viele POKéMON fangen!$"
	.endif
	.endif

OldaleTown_Mart_Text_RestoreHPWithPotion:
	.ifdef ENGLISH
	.string "If a POKéMON gets hurt and loses its HP\n"
	.string "and faints, it won't be able to battle.\p"
	.string "To prevent your POKéMON from fainting,\n"
	.string "restore its HP with a POTION.$"
	.else
	.ifdef GERMAN
	.string "Wird ein POKéMON verletzt und verliert\n"
	.string "alle KP, so ist es kampfunfähig.\p"
	.string "Um das zu vermeiden, solltest du die KP\n"
	.string "bei Bedarf mit einem TRANK auffüllen.$"
	.endif
	.endif

