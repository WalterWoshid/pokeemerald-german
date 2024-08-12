.set LOCALID_NURSE, 1

FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.ifdef ENGLISH
	.string "Listen, kid, are you working\n"
	.string "on a POKéDEX?\p"
	.string "Hmm… Go to the SAFARI ZONE.\n"
	.string "That's my suggestion.$"
	.else
	.ifdef GERMAN
	.string "Na, Kindchen, arbeitest du an einem\n"
	.string "POKéDEX?\p"
	.string "Hmm… Ich an deiner Stelle würde mal\n"
	.string "die SAFARI-ZONE auf der ROUTE 121\l"
	.string "besuchen.$"
	.endif
	.endif

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.ifdef ENGLISH
	.string "Have you done anything at\n"
	.string "the RECORD CORNER?\p"
	.string "It's pretty neat. It mixes and matches\n"
	.string "the records of TRAINERS.\p"
	.string "I don't know quite how it works,\n"
	.string "but it's cool. It's exciting, even!$"
	.else
	.ifdef GERMAN
	.string "Hast du schon mal eine\n"
	.string "STATISTIK geTAUSCHt?\p"
	.string "Sehr nützliche Einrichtung! Die Erfolge\n"
	.string "eines jeden TRAINERs werden dort ge-\l"
	.string "speichert und miteinander verglichen.\p"
	.string "Ich weiß zwar nicht, wie das passiert,\n"
	.string "aber es ist einfach irre. Und aufregend!$"
	.endif
	.endif

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.ifdef ENGLISH
	.string "Oh, wow, you have a POKéNAV!\n"
	.string "And it's just like mine!\p"
	.string "Do you know about POKéNAV's\n"
	.string "MATCH CALL system?\p"
	.string "Access it, and you can chat with\n"
	.string "registered TRAINERS anytime.\p"
	.string "It also shows you which TRAINERS\n"
	.string "want a rematch with you.\p"
	.string "It's really nifty! Those DEVON guys\n"
	.string "sure know what they're doing!$"
	.else
	.ifdef GERMAN
	.string "Hey, du hast einen POKéNAV!\n"
	.string "Ich habe auch so einen.\p"
	.string "Kennst du schon das TRAINER/RUF-\n"
	.string "System des POKéNAVs?\p"
	.string "Wenn du das in Betrieb nimmst, kannst\n"
	.string "du jederzeit mit den registrierten\l"
	.string "TRAINERn sprechen.\p"
	.string "Außerdem kannst du sehen, welche\n"
	.string "TRAINER erneut gegen dich antreten\l"
	.string "möchten.\p"
	.string "Ist das nicht einfach super?\n"
	.string "Das muss man DEVON wirklich lassen!$"
	.endif
	.endif

