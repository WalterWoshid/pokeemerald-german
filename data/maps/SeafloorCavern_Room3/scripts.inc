SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.ifdef ENGLISH
	.string "Ahahahaha!\p"
	.string "How did you manage to get here without\n"
	.string "a submarine?\l"
	.string "What an impressive child!\p"
	.string "But… It won't do to have you\n"
	.string "meddling about here.\p"
	.string "And, I do want payback for what\n"
	.string "happened at the WEATHER INSTITUTE…\p"
	.string "I'm going to give you a little taste\n"
	.string "of pain! Resign yourself to it!$"
	.else
	.ifdef GERMAN
	.string "Ahahahahaha!\p"
	.string "Wie bist du uns ohne U-Boot gefolgt?\n"
	.string "Was für ein bemerkenswertes Kind!\p"
	.string "Aber… das berechtigt dich nicht, hier\n"
	.string "herumzuschnüffeln!\p"
	.string "Jetzt kann ich dir die Sache vom\n"
	.string "KLIMA-INSTITUT heimzahlen…\p"
	.string "Ich gebe dir eine Lektion in Sachen\n"
	.string "Schmerz! Pass gut auf!$"
	.endif
	.endif

SeafloorCavern_Room3_Text_ShellyDefeat:
	.ifdef ENGLISH
	.string "Ahahahaha!\p"
	.string "Ouch!$"
	.else
	.ifdef GERMAN
	.string "Ahahahahaha!\p"
	.string "Auuuaaa!$"
	.endif
	.endif

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.ifdef ENGLISH
	.string "Ahahahaha!\n"
	.string "You're so darn strong.\p"
	.string "It's terribly disappointing that you're\n"
	.string "not a TEAM AQUA member.\p"
	.string "You could have enjoyed the fabulous\n"
	.string "world our BOSS has promised as\l"
	.string "one of us…$"
	.else
	.ifdef GERMAN
	.string "Ahahahaha!\n"
	.string "Du bist unglaublich stark!\p"
	.string "Es ist verdammt schade, dass du kein\n"
	.string "Mitglied von TEAM AQUA bist!\p"
	.string "So könntest du an der wunderbaren,\n"
	.string "neuen Welt, die unser BOSS seinen\l"
	.string "Leuten versprochen hat, teilhaben…$"
	.endif
	.endif

SeafloorCavern_Room3_Text_Grunt5Intro:
	.ifdef ENGLISH
	.string "For our dream to become real, we need\n"
	.string "the power of POKéMON.\p"
	.string "But meddlers like you use the power of\n"
	.string "POKéMON to mess with us even at\l"
	.string "a place like this!\p"
	.string "Life just doesn't work the way we\n"
	.string "need it to!$"
	.else
	.ifdef GERMAN
	.string "Um unseren Traum Wirklichkeit werden\n"
	.string "zu lassen, brauchen wir die Kraft von\l"
	.string "POKéMON.\p"
	.string "Aber Nervensägen wie du nutzen die\n"
	.string "Kraft der POKéMON, um selbst an Orten\l"
	.string "wie diesem allen auf den Keks zu gehen!\p"
	.string "Das Leben funktioniert nicht so, wie wir\n"
	.string "uns das vorstellen.$"
	.endif
	.endif

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.ifdef ENGLISH
	.string "Gwah!$"
	.else
	.ifdef GERMAN
	.string "Gwah!$"
	.endif
	.endif

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.ifdef ENGLISH
	.string "You know, we don't dare question\n"
	.string "the motives of our leader.\p"
	.string "But here you are, just some punk,\n"
	.string "going up against our BOSS.\p"
	.string "Maybe…\n"
	.string "You must be something…$"
	.else
	.ifdef GERMAN
	.string "Weißt du, wir stellen die Motive\n"
	.string "unseres Anführers nie in Frage.\p"
	.string "Und dann kommt ein Frettchen wie du\n"
	.string "dahergelaufen und legt sich\l"
	.string "mit unserem BOSS an.\p"
	.string "Vielleicht…\n"
	.string "bist du ja doch kein Frettchen…$"
	.endif
	.endif

