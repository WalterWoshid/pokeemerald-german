MysteryGiftScript_SurfPichu::
	setvaddress MysteryGiftScript_SurfPichu
	vgoto_if_unset FLAG_MYSTERY_GIFT_DONE, SurfPichu_GiveIfPossible
	returnram

SurfPichu_GiveIfPossible:
	specialvar VAR_GIFT_PICHU_SLOT, CalculatePlayerPartyCount
	vgoto_if_eq VAR_GIFT_PICHU_SLOT, PARTY_SIZE, SurfPichu_FullParty
	setflag FLAG_MYSTERY_GIFT_DONE
	vcall SurfPichu_GiveEgg
	lock
	faceplayer
	vmessage sText_MysteryGiftEgg
	waitmessage
	waitbuttonpress
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	release
	end

SurfPichu_FullParty:
	lock
	faceplayer
	vmessage sText_FullParty
	waitmessage
	waitbuttonpress
	release
	end

SurfPichu_GiveEgg:
	giveegg SPECIES_PICHU
	setmodernfatefulencounter VAR_GIFT_PICHU_SLOT
	setmonmetlocation VAR_GIFT_PICHU_SLOT, METLOC_FATEFUL_ENCOUNTER
	vgoto_if_eq VAR_GIFT_PICHU_SLOT, 1, SurfPichu_Slot1
	vgoto_if_eq VAR_GIFT_PICHU_SLOT, 2, SurfPichu_Slot2
	vgoto_if_eq VAR_GIFT_PICHU_SLOT, 3, SurfPichu_Slot3
	vgoto_if_eq VAR_GIFT_PICHU_SLOT, 4, SurfPichu_Slot4
	vgoto_if_eq VAR_GIFT_PICHU_SLOT, 5, SurfPichu_Slot5
	return

SurfPichu_Slot1:
	setmonmove 1, 2, MOVE_SURF
	return

SurfPichu_Slot2::
	setmonmove 2, 2, MOVE_SURF
	return

SurfPichu_Slot3:
	setmonmove 3, 2, MOVE_SURF
	return

SurfPichu_Slot4:
	setmonmove 4, 2, MOVE_SURF
	return

SurfPichu_Slot5:
	setmonmove 5, 2, MOVE_SURF
	return

sText_MysteryGiftEgg:
	.ifdef ENGLISH
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "From the POKéMON CENTER we\n"
	.string "have a gift--a POKéMON EGG!\p"
	.string "Please raise it with love and\n"
	.string "kindness.$"
	.else
	.ifdef GERMAN
	.string "Danke, dass du das GEHEIM-\n"
	.string "GESCHEHEN benutzt hast.\p"
	.string "Im POKéMON-CENTER wartet\n"
	.string "ein Geschenk auf dich. Ein\l"
	.string "POKéMON-EI!\l"
	.string "Bitte trainiere das POKéMON\l"
	.string "mit Liebe und Sorgfalt.$"
	.endif
	.endif

sText_FullParty:
	.ifdef ENGLISH
	.string "Oh, your party appears to be full.\p"
	.string "Please come see me after storing\n"
	.string "a POKéMON on a PC.$"
	.else
	.ifdef GERMAN
	.string "Oh, du hast keinen Platz in deinem\n"
	.string "Team!\l"
	.string "Bitte komme wieder, nachdem du\l"
	.string "ein POKéMON auf einem PC\l"
	.string "gelagert hast.$"
	.endif
	.endif
