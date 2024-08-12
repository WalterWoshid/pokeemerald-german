LilycoveCity_DepartmentStore_4F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_4F_EventScript_Gentleman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Woman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Youngster::
	msgbox LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs:
	.2byte ITEM_TM_FIRE_BLAST
	.2byte ITEM_TM_THUNDER
	.2byte ITEM_TM_BLIZZARD
	.2byte ITEM_TM_HYPER_BEAM
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_4F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs:
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_SAFEGUARD
	.2byte ITEM_TM_REFLECT
	.2byte ITEM_TM_LIGHT_SCREEN
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM:
	.ifdef ENGLISH
	.string "Hmm…\p"
	.string "An attacking move…\n"
	.string "Or a defensive move…\p"
	.string "It's no easy matter to decide which TM\n"
	.string "moves should be taught to POKéMON…$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Eine offensive Attacke…\n"
	.string "oder eine defensive Attacke…\p"
	.string "Es ist nicht einfach, zu entscheiden,\n"
	.string "welche TM ein POKéMON lernen soll.$"
	.endif
	.endif

LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs:
	.ifdef ENGLISH
	.string "There are so many different kinds of\n"
	.string "TM moves.\p"
	.string "A catalog I read said there are fifty\n"
	.string "different kinds.$"
	.else
	.ifdef GERMAN
	.string "Es gibt so viele verschiedene Arten von\n"
	.string "TMs.\p"
	.string "In einem Katalog habe ich gelesen, dass\n"
	.string "es 50 verschiedene Arten gibt.$"
	.endif
	.endif

LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves:
	.ifdef ENGLISH
	.string "I'd like to get all the different TMs,\n"
	.string "but a POKéMON learns only four moves.$"
	.else
	.ifdef GERMAN
	.string "Ich hätte gerne all die unterschied-\n"
	.string "lichen TMs, aber ein POKéMON kann nur\l"
	.string "vier Attacken lernen.$"
	.endif
	.endif

