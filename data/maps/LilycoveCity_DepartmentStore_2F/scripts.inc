LilycoveCity_DepartmentStore_2F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_2F_EventScript_Cook::
	msgbox LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_PokefanF::
	msgbox LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_Sailor::
	msgbox LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart1
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_2F_Pokemart1:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_2F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_2F_Pokemart2:
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_WAVE_MAIL
	.2byte ITEM_MECH_MAIL
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly:
	.ifdef ENGLISH
	.string "Learn to use items properly.\n"
	.string "That's basic, really.$"
	.else
	.ifdef GERMAN
	.string "Lerne, mit Items vernünftig umzugehen.\n"
	.string "Das ist essentiell. Ehrlich.$"
	.endif
	.endif

LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband:
	.ifdef ENGLISH
	.string "My husband is waiting at home.\n"
	.string "What would make a good gift for him?$"
	.else
	.ifdef GERMAN
	.string "Mein Mann wartet zu Hause auf mich.\n"
	.string "Was wäre wohl ein passendes Geschenk\l"
	.string "für ihn?$"
	.endif
	.endif

LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems:
	.ifdef ENGLISH
	.string "I'm leaving on a long journey soon.\n"
	.string "I need to stock up on items.$"
	.else
	.ifdef GERMAN
	.string "Ich werde bald auf eine lange Reise\n"
	.string "gehen. Ich muss daher Items kaufen.$"
	.endif
	.endif

