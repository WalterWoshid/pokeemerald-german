PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.ifdef ENGLISH
	.string "NORMAN became our town's new\n"
	.string "GYM LEADER.\p"
	.string "I think he called his family over from\n"
	.string "somewhere far away.$"
	.else
	.ifdef GERMAN
	.string "NORMAN ist unser neuer ARENALEITER.\p"
	.string "Ich glaube, er und seine Familie kommen\n"
	.string "von weit her.$"
	.endif
	.endif

PetalburgCity_House2_Text_BattledNormanOnce:
	.ifdef ENGLISH
	.string "I battled NORMAN once, but, whew,\n"
	.string "he was way too strong.\p"
	.string "How would I put it?\p"
	.string "I just got the feeling that he\n"
	.string "lives for POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Ich bin erst einmal gegen NORMAN\n"
	.string "angetreten. Wow, war der stark!\p"
	.string "Wie soll ich es sagen?\p"
	.string "Ich habe den Eindruck, er lebt für\n"
	.string "seine POKéMON.$"
	.endif
	.endif

