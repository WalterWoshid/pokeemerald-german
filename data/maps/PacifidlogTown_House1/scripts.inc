PacifidlogTown_House1_MapScripts::
	.byte 0

PacifidlogTown_House1_EventScript_Man::
	msgbox PacifidlogTown_House1_Text_RegiStory, MSGBOX_NPC
	end

PacifidlogTown_House1_EventScript_Woman::
	msgbox PacifidlogTown_House1_Text_SixDotsOpenThreeDoors, MSGBOX_NPC
	end

PacifidlogTown_House1_Text_RegiStory:
	.ifdef ENGLISH
	.string "In the HOENN region, there are three\n"
	.string "POKéMON that represent the power of\l"
	.string "rock, ice, and steel.\p"
	.string "Each of them is said to hide away deep\n"
	.string "inside caves.\p"
	.string "That's the story I heard when I was\n"
	.string "just a little kid.$"
	.else
	.ifdef GERMAN
	.string "In der HOENN-Region gibt es drei\n"
	.string "POKéMON, die die Stärke von Gestein,\l"
	.string "Eis und Stahl repräsentieren.\p"
	.string "Man sagt, sie verstecken sich in\n"
	.string "Höhlen vor den Augen der Menschen.\p"
	.string "Diese Geschichte wurde mir als Kind\n"
	.string "erzählt.$"
	.endif
	.endif

PacifidlogTown_House1_Text_SixDotsOpenThreeDoors:
	.ifdef ENGLISH
	.string "“Six dots open three doors.”\p"
	.string "Grandpa used to say that, but I don't\n"
	.string "know what he meant.$"
	.else
	.ifdef GERMAN
	.string "“Sechs Punkte öffnen drei Türen.”\p"
	.string "Mein Großvater sagte das immer, aber\n"
	.string "ich habe keine Ahnung, was es bedeutet.$"
	.endif
	.endif

