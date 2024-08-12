MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.ifdef ENGLISH
	.string "Hey there, TRAINER!\n"
	.string "A SUPER ROD really is super!\p"
	.string "Say all you want, but this baby can\n"
	.string "catch POKéMON off the seafloor!\p"
	.string "What do you think?\n"
	.string "You want it, don't you?$"
	.else
	.ifdef GERMAN
	.string "Hey, du da! TRAINER!\n"
	.string "Eine SUPERANGEL ist wirklich super!\p"
	.string "Man kann sagen, was man will, aber mit\n"
	.string "diesem Baby kann man POKéMON vom\l"
	.string "Meeresboden weg fangen!\p"
	.string "Na? Du würdest doch zu gerne auch so\n"
	.string "eine Angel haben, oder?$"
	.endif
	.endif

MossdeepCity_House3_Text_SuperRodIsSuper:
	.ifdef ENGLISH
	.string "You bet, you bet!\n"
	.string "After all, a SUPER ROD is really super!$"
	.else
	.ifdef GERMAN
	.string "Sicher, sicher!\n"
	.string "Schließlich ist eine SUPERANGEL super!$"
	.endif
	.endif

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.ifdef ENGLISH
	.string "If there's any water, try dropping in\n"
	.string "your ROD and see what bites!$"
	.else
	.ifdef GERMAN
	.string "Stehst du am Wasser, dann wirf die\n"
	.string "ANGEL aus und schau, was anbeißt!$"
	.endif
	.endif

MossdeepCity_House3_Text_DontYouLikeToFish:
	.ifdef ENGLISH
	.string "Hunh?\n"
	.string "Don't you like to fish?$"
	.else
	.ifdef GERMAN
	.string "Was???\n"
	.string "Liebst du das Angeln nicht?$"
	.endif
	.endif

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.ifdef ENGLISH
	.string "Go after the seafloor POKéMON with\n"
	.string "your SUPER ROD.$"
	.else
	.ifdef GERMAN
	.string "Mit deiner SUPERANGEL kannst du die\n"
	.string "POKéMON am Meeresboden fangen.$"
	.endif
	.endif

