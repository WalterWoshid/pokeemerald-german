RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.ifdef ENGLISH
	.string "For my own POKéMON, I give them\n"
	.string "perfectly suited nicknames!\p"
	.string "It's my expression of, uh…\n"
	.string "originality, yes, that's it!$"
	.else
	.ifdef GERMAN
	.string "Meinen eigenen POKéMON habe ich\n"
	.string "perfekt passende Kosenamen gegeben!\p"
	.string "Das ist mein Ausdruck von… äh…\n"
	.string "Originalität. Genau! Originalität!$"
	.endif
	.endif

RustboroCity_House3_Text_NamingPikachuPekachu:
	.ifdef ENGLISH
	.string "But giving the name PEKACHU to\n"
	.string "a PIKACHU? It seems pointless.\p"
	.string "I suppose it is good to use a name\n"
	.string "that's easy to understand, but…$"
	.else
	.ifdef GERMAN
	.string "Aber ein PIKACHU einfach PEKACHU zu\n"
	.string "nennen? Das haut einen nicht gerade\l"
	.string "vom Hocker.\p"
	.string "Ich glaube ja auch, man sollte einen\n"
	.string "leicht verständlichen Kosenamen\l"
	.string "wählen, aber irgendwie…$"
	.endif
	.endif

RustboroCity_House3_Text_Pekachu:
	.ifdef ENGLISH
	.string "PEKACHU: Peka!$"
	.else
	.ifdef GERMAN
	.string "PEKACHU: Peka!$"
	.endif
	.endif

