FortreeCity_Mart_MapScripts::
	.byte 0

FortreeCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FortreeCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_WOOD_MAIL
	.2byte ITEM_NONE
	release
	end

FortreeCity_Mart_EventScript_Woman::
	msgbox FortreeCity_Mart_Text_SuperRepelBetter, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Girl::
	msgbox FortreeCity_Mart_Text_StockUpOnItems, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Boy::
	msgbox FortreeCity_Mart_Text_RareCandyMakesMonGrow, MSGBOX_NPC
	end

FortreeCity_Mart_Text_SuperRepelBetter:
	.ifdef ENGLISH
	.string "SUPER REPEL lasts a long time,\n"
	.string "and it gets the job done.\p"
	.string "It's much better than an ordinary\n"
	.string "REPEL.$"
	.else
	.ifdef GERMAN
	.string "SUPERSCHUTZ hält lange an und ist auch\n"
	.string "äußerst nützlich.\p"
	.string "Er ist viel besser als\n"
	.string "der normale SCHUTZ.$"
	.endif
	.endif

FortreeCity_Mart_Text_StockUpOnItems:
	.ifdef ENGLISH
	.string "I always stock up on more items than\n"
	.string "I'm sure I'll need.\p"
	.string "You never know what might happen.\n"
	.string "Better to be safe than sorry!$"
	.else
	.ifdef GERMAN
	.string "Ich horte immer mehr Items, als ich\n"
	.string "eigentlich benötige.\p"
	.string "Man weiß ja nie, was einem passieren\n"
	.string "kann. Vorsicht ist die Mutter der\l"
	.string "Porzellankiste!$"
	.endif
	.endif

FortreeCity_Mart_Text_RareCandyMakesMonGrow:
	.ifdef ENGLISH
	.string "A RARE CANDY makes a POKéMON grow\n"
	.string "immediately by one level.$"
	.else
	.ifdef GERMAN
	.string "Ein SONDERBONBON erhöht den Level\n"
	.string "eines POKéMON sofort um 1.$"
	.endif
	.endif

