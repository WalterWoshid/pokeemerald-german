MysteryGiftScript_OldSeaMap::
	setvaddress MysteryGiftScript_OldSeaMap
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_OLD_SEA_MAP, OldSeaMap_Obtained
	vgoto_if_set FLAG_CAUGHT_MEW, OldSeaMap_Obtained
	checkitem ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, TRUE, OldSeaMap_Obtained
	vmessage sText_MysteryGiftOldSeaMapForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, FALSE, OldSeaMap_NoBagSpace
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	vmessage sText_MysteryGiftOldSeaMapUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_NoBagSpace:
	vmessage sText_MysteryGiftOldSeaMapBagFull
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_Obtained:
	vmessage sText_MysteryGiftOldSeaMapThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftOldSeaMapForYou:
	.ifdef ENGLISH
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "Let me confirm--you are {PLAYER}?\p"
	.string "We received this OLD SEA MAP\n"
	.string "addressed to you.$"
	.else
	.ifdef GERMAN
	.string "Danke, dass du das GEHEIM-\n"
	.string "GESCHEHEN benutzt hast.\p"
	.string "Du musst {PLAYER} sein.\n"
	.string "Hier ist eine ALTE KARTE für dich!$"
	.endif
	.endif

sText_MysteryGiftOldSeaMapUseAtPort:
	.ifdef ENGLISH
	.string "It appears to be for use at the\n"
	.string "LILYCOVE CITY port.\p"
	.string "Why not give it a try and see what\n"
	.string "it is about?$"
	.else
	.ifdef GERMAN
	.string "Du kannst sie am Hafen von\n"
	.string "SEEGRASULB CITY einsetzen.\p"
	.string "Warum probierst du es nicht\n"
	.string "einfach aus?$"
	.endif
	.endif

sText_MysteryGiftOldSeaMapThankYou:
	.ifdef ENGLISH
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.$"
	.else
	.ifdef GERMAN
	.string "Danke, dass du das GEHEIM-\n"
	.string "GESCHEHEN benutzt hast!$"
	.endif
	.endif

sText_MysteryGiftOldSeaMapBagFull:
	.ifdef ENGLISH
	.string "Oh, I'm sorry, {PLAYER}.\n"
	.string "Your BAG's KEY ITEMS POCKET is full.\p"
	.string "Please store something on your PC,\n"
	.string "then come back for this.$"
	.else
	.ifdef GERMAN
	.string "Oh, es tut mir Leid, {PLAYER}! Die\n"
	.string "BASIS-ITEM-TASCHE in deinem\l"
	.string "BEUTEL ist voll.\l"
	.string "Lagere etwas auf deinem PC und\l"
	.string "komme anschließend zurück.$"
	.endif
	.endif
