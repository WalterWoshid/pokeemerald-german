LavaridgeTown_Mart_MapScripts::
	.byte 0

LavaridgeTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavaridgeTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_NONE
	release
	end

LavaridgeTown_Mart_EventScript_ExpertM::
	msgbox LavaridgeTown_Mart_Text_XSpeedFirstStrike, MSGBOX_NPC
	end

LavaridgeTown_Mart_EventScript_OldWoman::
	msgbox LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney, MSGBOX_NPC
	end

LavaridgeTown_Mart_Text_XSpeedFirstStrike:
	.ifdef ENGLISH
	.string "Use X SPEED to add to a POKéMON's\n"
	.string "SPEED in battle.\p"
	.string "That will help it get in the first\n"
	.string "strike--a decided advantage!$"
	.else
	.ifdef GERMAN
	.string "Mit X-TEMPO kannst du die INITIATIVE\n"
	.string "im Kampf erhöhen.\p"
	.string "So kann man eventuell den ersten\n"
	.string "Angriff ausführen - ein entscheidender\l"
	.string "Vorteil!$"
	.endif
	.endif

LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney:
	.ifdef ENGLISH
	.string "On MT. CHIMNEY's peak, there's a local\n"
	.string "specialty that you can buy only there.\p"
	.string "Give it to a POKéMON--it will be elated.$"
	.else
	.ifdef GERMAN
	.string "Auf dem Gipfel des SCHLOTBERGs wird\n"
	.string "eine lokale Spezialität angeboten.\p"
	.string "Gib sie einem POKéMON und es wird\n"
	.string "begeistert sein.$"
	.endif
	.endif

