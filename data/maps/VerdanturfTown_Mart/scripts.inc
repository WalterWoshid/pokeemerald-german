VerdanturfTown_Mart_MapScripts::
	.byte 0

VerdanturfTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_NONE
	release
	end

VerdanturfTown_Mart_EventScript_Boy::
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_ExpertF::
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_Lass::
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_XSpecialIsCrucial:
	.ifdef ENGLISH
	.string "For any POKéMON match, X SPECIAL\n"
	.string "is crucial.\p"
	.string "It jacks up the power of some moves\n"
	.string "even though it's only for one battle.$"
	.else
	.ifdef GERMAN
	.string "X-SPEZIAL ist für jeden POKéMON-Kampf\n"
	.string "äußerst wichtig.\p"
	.string "Es erhöht die Stärke mancher Attacken.\n"
	.string "Aber leider nur für einen Kampf.$"
	.endif
	.endif

VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent:
	.ifdef ENGLISH
	.string "They don't seem to sell any winning\n"
	.string "strategy guides for the BATTLE TENT…\p"
	.string "It seems one must rely on one's\n"
	.string "own wits after all…$"
	.else
	.ifdef GERMAN
	.string "Strategie-Ratgeber für das KAMPFCAMP\n"
	.string "scheinen sie hier leider nicht zu\p"
	.string "verkaufen… Man muss sich\n"
	.string "auf sich selbst verlassen.$"
	.endif
	.endif

VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
	.ifdef ENGLISH
	.string "The NEST BALL works better on\n"
	.string "weakened POKéMON.\p"
	.string "VERDANTURF is the only place you can\n"
	.string "buy it.$"
	.else
	.ifdef GERMAN
	.string "Der NESTBALL ist bei schwächeren\n"
	.string "POKéMON hervorragend geeignet.\p"
	.string "Den kannst du nur in WIESENFLUR\n"
	.string "kaufen.$"
	.endif
	.endif

