FallarborTown_Mart_MapScripts::
	.byte 0

FallarborTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FallarborTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FallarborTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_NONE
	release
	end

FallarborTown_Mart_EventScript_Woman::
	msgbox FallarborTown_Mart_Text_DecidingSkittyEvolve, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_PokefanM::
	msgbox FallarborTown_Mart_Text_SellNuggetIFound, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox FallarborTown_Mart_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_Mart_Text_DecidingSkittyEvolve:
	.ifdef ENGLISH
	.string "I'm having a hard time deciding if I\n"
	.string "should make my SKITTY evolve or not.\p"
	.string "I only have to use this MOON STONE,\n"
	.string "but it's so hard to decide…\p"
	.string "If I make it evolve, it will become\n"
	.string "much stronger.\p"
	.string "But it will look so different, too.$"
	.else
	.ifdef GERMAN
	.string "Ich habe lange überlegt, ob sich mein\n"
	.string "ENECO entwickeln soll oder nicht.\p"
	.string "Ich müsste nur diesen MONDSTEIN ein-\n"
	.string "setzen, aber das ist eine schwere\l"
	.string "Entscheidung…\p"
	.string "Würde es sich entwickeln, wäre es viel\n"
	.string "stärker.\p"
	.string "Aber es würde auch anders aussehen.$"
	.endif
	.endif

FallarborTown_Mart_Text_Skitty:
	.ifdef ENGLISH
	.string "SKITTY: Miyao?$"
	.else
	.ifdef GERMAN
	.string "ENECO: Miyao?$"
	.endif
	.endif

FallarborTown_Mart_Text_SellNuggetIFound:
	.ifdef ENGLISH
	.string "This NUGGET I found here…\n"
	.string "I suppose I'll have to sell it, seeing\l"
	.string "as how it has no other use.$"
	.else
	.ifdef GERMAN
	.string "Ich habe hier ein NUGGET gefunden…\n"
	.string "Das werde ich wohl verkaufen. Was soll\l"
	.string "ich sonst damit machen?$"
	.endif
	.endif

