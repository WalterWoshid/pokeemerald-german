.set LOCALID_STAIR_GUARD, 2

RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.ifdef ENGLISH
	.string "Hello and welcome to the DEVON\n"
	.string "CORPORATION.\p"
	.string "We're proud producers of items and\n"
	.string "medicine that enhance your life.$"
	.else
	.ifdef GERMAN
	.string "Hallo und Willkommen in der\n"
	.string "DEVON CORPORATION.\p"
	.string "Wir sind die stolzen Entwickler von\n"
	.string "Medizin und Items, die das Leben\l"
	.string "bereichern.$"
	.endif
	.endif

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.ifdef ENGLISH
	.string "One of our research staff stupidly\n"
	.string "got robbed of an important parcel.$"
	.else
	.ifdef GERMAN
	.string "Einem Mitglied unseres Forschungs-\n"
	.string "teams ist blöderweise ein wichtiges\l"
	.string "Paket gestohlen worden.$"
	.endif
	.endif

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.ifdef ENGLISH
	.string "Hey, those RUNNING SHOES!\n"
	.string "They're one of our products!\p"
	.string "It makes me happy when I see someone\n"
	.string "using something we made.$"
	.else
	.ifdef GERMAN
	.string "Hey, diese TURBOTRETER!\n"
	.string "Die haben wir auch entwickelt!\p"
	.string "Ich freue mich immer, wenn ich jemanden\n"
	.string "treffe, der eines unserer Produkte\l"
	.string "benutzt.$"
	.endif
	.endif

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.ifdef ENGLISH
	.string "That stolen parcel…\p"
	.string "Well, sure it's important, but it's not\n"
	.string "anything that anyone can use.\p"
	.string "In my estimation, that robber must not\n"
	.string "have been very bright.$"
	.else
	.ifdef GERMAN
	.string "Das gestohlene Paket…\p"
	.string "Nun, es ist natürlich sehr wichtig, aber\n"
	.string "mit dem Inhalt kann niemand etwas\l"
	.string "anfangen.\p"
	.string "Meiner Einschätzung nach ist der Dieb\n"
	.string "wirklich nicht sehr schlau gewesen…$"
	.endif
	.endif

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.ifdef ENGLISH
	.string "It sounds like they've recovered\n"
	.string "the ripped-off DEVON GOODS.$"
	.else
	.ifdef GERMAN
	.string "Klingt, als hätten wir die gestohlenen\n"
	.string "DEVON-WAREN zurückerhalten.$"
	.endif
	.endif

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.ifdef ENGLISH
	.string "I'm sorry, only authorized people\n"
	.string "are allowed to enter here.$"
	.else
	.ifdef GERMAN
	.string "Tut mir Leid, aber nur autorisierte\n"
	.string "Personen haben hier Zutritt.$"
	.endif
	.endif

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.ifdef ENGLISH
	.string "It's beyond stupid.\n"
	.string "How could we get robbed?$"
	.else
	.ifdef GERMAN
	.string "Das ist mehr als blöd.\n"
	.string "Wie konnten wir nur ausgeraubt werden?$"
	.endif
	.endif

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.ifdef ENGLISH
	.string "Hi, there!\n"
	.string "You're always welcome here!$"
	.else
	.ifdef GERMAN
	.string "Hi, du da!\n"
	.string "Du bist hier jederzeit willkommen!$"
	.endif
	.endif

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.ifdef ENGLISH
	.string "Samples of rocks and metal are\n"
	.string "displayed in the glass case.\p"
	.string "There's a panel with some writing\n"
	.string "on it…\p"
	.string "“DEVON CORPORATION got its start as\n"
	.string "a producer of stones from quarries.\p"
	.string "“The company also produced iron from\n"
	.string "filings in the sand.\p"
	.string "“From that humble start as a producer\n"
	.string "of raw materials, DEVON developed.\p"
	.string "“DEVON is now a manufacturer of a wide\n"
	.string "range of industrial products.”$"
	.else
	.ifdef GERMAN
	.string "In diesem Schaukasten sind Steine und\n"
	.string "Metalle ausgestellt.\p"
	.string "Und da ist ein kleines Schild, auf dem\n"
	.string "etwas geschrieben steht…\p"
	.string "“Die DEVON CORPORATION begann\n"
	.string "ihre Erfolgsgeschichte mit der\p"
	.string "Verarbeitung von Steinen aus\n"
	.string "Steinbrüchen.\p"
	.string "Außerdem verarbeitete sie Eisenspäne,\n"
	.string "die man im Sand finden kann.\p"
	.string "Die Verarbeitung von Rohmaterialien\n"
	.string "war nur der Anfang.\p"
	.string "Heute stellt DEVON eine große Anzahl\n"
	.string "von Industrieprodukten her.”$"
	.endif
	.endif

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.ifdef ENGLISH
	.string "Prototypes and test products fill\n"
	.string "the glass display case.\p"
	.string "There's a panel with a description…\p"
	.string "“In addition to industrial products,\n"
	.string "DEVON now markets sundries and\l"
	.string "pharmaceuticals for better lifestyles.\p"
	.string "“Recently, DEVON has begun marketing\n"
	.string "tools for POKéMON TRAINERS, including\l"
	.string "POKé BALLS and POKéNAV systems.”$"
	.else
	.ifdef GERMAN
	.string "In diesem Schaukasten kann man\n"
	.string "Prototypen und Testprodukte sehen.\p"
	.string "Hier ist eine Beschreibung…\p"
	.string "“Neben der Herstellung von Industrie-\n"
	.string "produkten stellt DEVON eine Vielzahl\p"
	.string "an Gütern her, die das alltägliche Leben\n"
	.string "leichter machen.\p"
	.string "DEVON hat damit begonnen, hilfreiche\n"
	.string "Produkte für POKéMON TRAINER zu\p"
	.string "entwickeln, wie POKéBÄLLe und das\n"
	.string "POKéNAV-System.”$"
	.endif
	.endif

