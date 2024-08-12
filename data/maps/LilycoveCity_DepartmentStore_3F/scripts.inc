LilycoveCity_DepartmentStore_3F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_3F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins:
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_3F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_StatBoosters
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_3F_Pokemart_StatBoosters:
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_3F_EventScript_TriathleteM::
	msgbox LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_EventScript_PokefanM::
	msgbox LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_EventScript_Woman::
	msgbox LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon:
	.ifdef ENGLISH
	.string "For quickly toughening up POKéMON,\n"
	.string "items are the best.\p"
	.string "PROTEIN boosts ATTACK,\n"
	.string "and CALCIUM raises SP. ATK.$"
	.else
	.ifdef GERMAN
	.string "Um POKéMON schnell stärker zu machen,\n"
	.string "eignen sich Items hervorragend.\p"
	.string "PROTEIN steigert den ANGRIFF und\n"
	.string "KALZIUM den SPEZ. ANGRIFF.$"
	.endif
	.endif

LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance:
	.ifdef ENGLISH
	.string "I want my POKéMON to have more\n"
	.string "endurance.\p"
	.string "I'm trying to decide whether to raise\n"
	.string "DEFENSE with IRON, or SP. DEF with ZINC.$"
	.else
	.ifdef GERMAN
	.string "Ich möchte, dass mein POKéMON mehr\n"
	.string "Ausdauer hat.\p"
	.string "Ich frage mich, ob ich lieber die\n"
	.string "VERTEIDIGUNG mit EISEN oder die SPEZ.\l"
	.string "VER. mit ZINK steigern soll.$"
	.endif
	.endif

LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon:
	.ifdef ENGLISH
	.string "I gave a CARBOS to my POKéMON,\n"
	.string "and its SPEED went up.$"
	.else
	.ifdef GERMAN
	.string "Ich habe meinem POKéMON CARBON\n"
	.string "gegeben, um die INIT. zu erhöhen.$"
	.endif
	.endif

