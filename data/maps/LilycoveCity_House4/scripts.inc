LilycoveCity_House4_MapScripts::
	.byte 0

LilycoveCity_House4_EventScript_Man1::
	msgbox LilycoveCity_House4_Text_MysteriesAtBottomOfSea, MSGBOX_NPC
	end

LilycoveCity_House4_EventScript_Man2::
	msgbox LilycoveCity_House4_Text_UnderwaterTrenchMossdeepSootopolis, MSGBOX_NPC
	end

LilycoveCity_House4_Text_MysteriesAtBottomOfSea:
	.ifdef ENGLISH
	.string "This planet's biggest mysteries are\n"
	.string "at the bottom of the sea.\p"
	.string "Somebody said that, but I don't know…$"
	.else
	.ifdef GERMAN
	.string "Das größte Geheimnis dieses Planeten\n"
	.string "hütet der Meeresboden.\p"
	.string "Das hat mal jemand gesagt, aber ich\n"
	.string "weiß nicht…$"
	.endif
	.endif

LilycoveCity_House4_Text_UnderwaterTrenchMossdeepSootopolis:
	.ifdef ENGLISH
	.string "There's a deep underwater trench\n"
	.string "between MOSSDEEP and SOOTOPOLIS.\p"
	.string "That's what someone told me, anyway.$"
	.else
	.ifdef GERMAN
	.string "Zwischen MOOSBACH CITY und\n"
	.string "XENEROVILLE befindet sich ein\l"
	.string "tiefer Unterwassergraben.\p"
	.string "Das hat mir jemand erzählt.$"
	.endif
	.endif

