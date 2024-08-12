FortreeCity_House3_MapScripts::
	.byte 0

FortreeCity_House3_EventScript_Maniac::
	msgbox FortreeCity_House3_Text_MetStevenHadAmazingPokemon, MSGBOX_NPC
	end

FortreeCity_House3_EventScript_SchoolKidM::
	msgbox FortreeCity_House3_Text_OhYouHavePokedex, MSGBOX_NPC
	end

FortreeCity_House3_Text_MetStevenHadAmazingPokemon:
	.ifdef ENGLISH
	.string "While speaking about POKéDEXES,\n"
	.string "I remembered something.\p"
	.string "I met this TRAINER, STEVEN, when\n"
	.string "I was searching for rare stones.\p"
	.string "Hoo, boy, he had some amazing POKéMON\n"
	.string "with him.\p"
	.string "They weren't just rare, they were\n"
	.string "trained to terrifying extremes!\p"
	.string "He might even be stronger than the\n"
	.string "GYM LEADER in this town…$"
	.else
	.ifdef GERMAN
	.string "Da wir gerade vom POKéDEX reden… Ich\n"
	.string "erinnere mich…\p"
	.string "Ich habe diesen TRAINER, TROY,\n"
	.string "getroffen, als ich seltene Steine\l"
	.string "suchte.\p"
	.string "Oh Junge, der hatte vielleicht\n"
	.string "interessante POKéMON bei sich!\p"
	.string "Die waren nicht nur selten, sondern\n"
	.string "auch ausgesprochen gut trainiert!\p"
	.string "Er ist bestimmt stärker als die ARENA-\n"
	.string "LEITERIN in diesem Ort…$"
	.endif
	.endif

FortreeCity_House3_Text_OhYouHavePokedex:
	.ifdef ENGLISH
	.string "What's that thing you have there?\p"
	.string "… … … … … …\p"
	.string "Oh, it's called a POKéDEX?\n"
	.string "It's really awesome!$"
	.else
	.ifdef GERMAN
	.string "Was ist das da? Was hast du da?\p"
	.string "… … … … … …\p"
	.string "Oh, das ist also ein POKéDEX?\n"
	.string "Der ist aber wirklich klasse!$"
	.endif
	.endif

