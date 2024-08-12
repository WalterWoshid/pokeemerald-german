DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.ifdef ENGLISH
	.string "Gorge your eyes on this!\p"
	.string "It's a SILK SCARF. It's right at the\n"
	.string "cutting edge of fashion, yeah!\p"
	.string "Oh, I can see your eyes twinkling!\n"
	.string "You appreciate my dazzling style!\p"
	.string "Oh, you're a delight!\n"
	.string "Here you go. I want you to have it!$"
	.else
	.ifdef GERMAN
	.string "Wirf dein Auge mal hierauf!\p"
	.string "Das ist ein SEIDENSCHAL. Das ist\n"
	.string "der letzte Schrei in der Mode. Yeah!\p"
	.string "Oh, deine Augen blitzen.\n"
	.string "Du magst meinen Stil, nicht wahr?\p"
	.string "Hihi, du machst mir eine Freude!\n"
	.string "Hier, das möchte ich dir schenken!$"
	.endif
	.endif

DewfordTown_House2_Text_NoRoom:
	.ifdef ENGLISH
	.string "Oh, you don't have room?\p"
	.string "Now, listen tight, this SCARF is a must-\n"
	.string "have! Why, I would sell all my items\l"
	.string "in order to get it!$"
	.else
	.ifdef GERMAN
	.string "Och, du hast ja gar keinen Platz mehr.\p"
	.string "Nun, hör gut zu… Diesen SCHAL musst\n"
	.string "du einfach haben! Ich würde alle meine\l"
	.string "Items verkaufen, um ihn zu bekommen!$"
	.endif
	.endif

DewfordTown_House2_Text_ExplainSilkScarf:
	.ifdef ENGLISH
	.string "The SILK SCARF raises the power of\n"
	.string "NORMAL-type moves.\p"
	.string "It's a marvelous SCARF that will go\n"
	.string "with almost all POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Dieser SEIDENSCHAL steigert die Stärke\n"
	.string "der NORMALen Attacken.\p"
	.string "Dieser wunderbare SCHAL passt einfach\n"
	.string "zu fast allen POKéMON!$"
	.endif
	.endif

DewfordTown_House2_Text_BrawlySoCool:
	.ifdef ENGLISH
	.string "Wow, you bothered to cross the sea\n"
	.string "to visit DEWFORD?\p"
	.string "Did you maybe come here because you\n"
	.string "heard about BRAWLY?\p"
	.string "He's so cool…\n"
	.string "Everyone idolizes him.$"
	.else
	.ifdef GERMAN
	.string "Wow, du hast die beschwerliche Reise\n"
	.string "über das Meer auf dich genommen, um\l"
	.string "nach FAUSTAUHAVEN zu gelangen?\p"
	.string "Bist du hier, weil du von KAMILLO\n"
	.string "gehört hast?\p"
	.string "Er ist sooo cool…\n"
	.string "Er ist ein Idol für jeden!$"
	.endif
	.endif

