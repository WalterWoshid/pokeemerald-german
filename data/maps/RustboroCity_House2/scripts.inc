RustboroCity_House2_MapScripts::
	.byte 0

RustboroCity_House2_EventScript_PokefanF::
	msgbox RustboroCity_House2_Text_TrainerSchoolExcellent, MSGBOX_NPC
	end

RustboroCity_House2_EventScript_LittleGirl::
	msgbox RustboroCity_House2_Text_RoxanneKnowsALot, MSGBOX_NPC
	end

RustboroCity_House2_Text_TrainerSchoolExcellent:
	.ifdef ENGLISH
	.string "The TRAINER'S SCHOOL is excellent.\p"
	.string "If you study there, you could even\n"
	.string "become a GYM LEADER.$"
	.else
	.ifdef GERMAN
	.string "Die TRAINERSCHULE ist hervorragend.\p"
	.string "Wenn du dort lernst, kannst du später\n"
	.string "sogar ARENALEITER werden.$"
	.endif
	.endif

RustboroCity_House2_Text_RoxanneKnowsALot:
	.ifdef ENGLISH
	.string "ROXANNE, the GYM LEADER, really knows\n"
	.string "a lot about POKéMON.\p"
	.string "She's really strong, too!$"
	.else
	.ifdef GERMAN
	.string "FELIZIA, die ARENALEITERIN, weiß\n"
	.string "wirklich eine Menge über POKéMON.\p"
	.string "Und sie ist sehr stark!$"
	.endif
	.endif

