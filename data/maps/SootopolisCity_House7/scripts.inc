SootopolisCity_House7_MapScripts::
	.byte 0

SootopolisCity_House7_EventScript_OldMan::
	msgbox SootopolisCity_House7_Text_CityFromEruptedVolcano, MSGBOX_NPC
	end

SootopolisCity_House7_EventScript_PokefanF::
	msgbox SootopolisCity_House7_Text_CaveMadeToKeepSomething, MSGBOX_NPC
	end

SootopolisCity_House7_Text_CityFromEruptedVolcano:
	.ifdef ENGLISH
	.string "An underwater volcano erupted and\n"
	.string "forced itself up from the depths.\p"
	.string "Its crater emerged from the sea and\n"
	.string "became filled with rainwater.\p"
	.string "That's how SOOTOPOLIS CITY came into\n"
	.string "being.$"
	.else
	.ifdef GERMAN
	.string "Ein Unterwasservulkan brach aus\n"
	.string "und schob sich an die Oberfläche.\p"
	.string "Der Krater lag über der Meeresober-\n"
	.string "fläche und konnte sich so mit Regen-\p"
	.string "wasser füllen.\n"
	.string "Und so entstand XENEROVILLE.$"
	.endif
	.endif

SootopolisCity_House7_Text_CaveMadeToKeepSomething:
	.ifdef ENGLISH
	.string "The cave that links SOOTOPOLIS and\n"
	.string "the outside world…\p"
	.string "It seems as if the cave was made to\n"
	.string "keep something from getting out.\p"
	.string "Or am I just imagining things?$"
	.else
	.ifdef GERMAN
	.string "Die Höhle, die XENEROVILLE mit der Welt\n"
	.string "verbindet…\p"
	.string "Sie sollte ursprünglich wohl etwas\n"
	.string "in der Stadt festhalten.\p"
	.string "Oder bilde ich mir das nur ein?$"
	.endif
	.endif

