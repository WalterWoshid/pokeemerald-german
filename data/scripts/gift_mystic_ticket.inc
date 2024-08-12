MysteryGiftScript_MysticTicket::
	setvaddress MysteryGiftScript_MysticTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_MYSTIC_TICKET, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_LUGIA, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_HO_OH, MysticTicket_Obtained
	checkitem ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, MysticTicket_Obtained
	vmessage sText_MysticTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, MysticTicket_NoBagSpace
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	vmessage sText_MysticTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_NoBagSpace:
	vmessage sText_MysticTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_Obtained:
	vmessage sText_MysticTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysticTicketForYou:
	.ifdef ENGLISH
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "You must be {PLAYER}.\n"
	.string "There is a ticket here for you.$"
	.else
	.ifdef GERMAN
	.string "Danke, dass du das GEHEIM-\n"
	.string "GESCHEHEN benutzt hast.\p"
	.string "Du musst {PLAYER} sein.\n"
	.string "Hier ist ein Ticket für dich!$"
	.endif
	.endif

sText_MysticTicketUseAtPort:
	.ifdef ENGLISH
	.string "It appears to be for use at the\n"
	.string "LILYCOVE CITY port.\p"
	.string "Why not give it a try and see what\n"
	.string "it is about?$"
	.else
	.ifdef GERMAN
	.string "Du kannst es am Hafen von\n"
	.string "SEEGRASULB CITY einsetzen.\p"
	.string "Warum probierst du es nicht\n"
	.string "einfach aus?$"
	.endif
	.endif

sText_MysticTicketThankYou:
	.ifdef ENGLISH
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.$"
	.else
	.ifdef GERMAN
	.string "Danke, dass du das GEHEIM-\n"
	.string "GESCHEHEN benutzt hast!$"
	.endif
	.endif

sText_MysticTicketBagFull:
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
