PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.ifdef ENGLISH
	.string "The sea between PACIFIDLOG and\n"
	.string "SLATEPORT has a fast-running tide.\p"
	.string "If you decide to SURF, you could end\n"
	.string "up swept away somewhere else.$"
	.else
	.ifdef GERMAN
	.string "Im Meer zwischen FLOSSBRUNN und\n"
	.string "GRAPHITPORT CITY befinden sich\l"
	.string "reißende Strömungen.\p"
	.string "Wenn du dort SURFER einsetzt, kann es\n"
	.string "sein, dass du fortgetrieben wirst.$"
	.endif
	.endif

PacifidlogTown_Text_NeatHousesOnWater:
	.ifdef ENGLISH
	.string "See, isn't it neat?\n"
	.string "These houses are on water!\p"
	.string "I was born here!$"
	.else
	.ifdef GERMAN
	.string "Schau mal. Ist das nicht hübsch?\n"
	.string "Die Häuser stehen auf dem Wasser.\p"
	.string "Ich wurde hier geboren.$"
	.endif
	.endif

PacifidlogTown_Text_SkyPillarTooScary:
	.ifdef ENGLISH
	.string "The SKY PILLAR?\p"
	.string "…Oh, you must mean that tall, tall\n"
	.string "tower a little further out.\p"
	.string "If you asked me, I wouldn't climb it.\n"
	.string "It's too scary to get up that high.\p"
	.string "Life at sea level in PACIFIDLOG,\n"
	.string "that suits me fine.$"
	.else
	.ifdef GERMAN
	.string "Der HIMMELTURM?\p"
	.string "Ach, du meinst bestimmt diesen hohen,\n"
	.string "hohen Turm, der sich hier in der Nähe\l"
	.string "befindet.\p"
	.string "Also, wenn du mich fragst - ich würde\n"
	.string "niemals da hochgehen. Da hätte ich viel\l"
	.string "zu viel Angst, weil das so hoch ist!\p"
	.string "Leben auf Höhe des Meeresspiegels in\n"
	.string "FLOSSBRUNN, das ist mein Ding.$"
	.endif
	.endif

PacifidlogTown_Text_TownSign:
	.ifdef ENGLISH
	.string "PACIFIDLOG TOWN\p"
	.string "“Where the morning sun smiles upon\n"
	.string "the waters.”$"
	.else
	.ifdef GERMAN
	.string "FLOSSBRUNN\p"
	.string "“Wo die Morgensonne ein Lächeln auf\n"
	.string "das Meer zaubert.”$"
	.endif
	.endif
