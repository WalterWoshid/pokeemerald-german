LilycoveCity_House1_MapScripts::
	.byte 0

LilycoveCity_House1_EventScript_ExpertM::
	msgbox LilycoveCity_House1_Text_PokemonPartnersNotTools, MSGBOX_NPC
	end

LilycoveCity_House1_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	msgbox LilycoveCity_House1_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_House1_Text_PokemonPartnersNotTools:
	.ifdef ENGLISH
	.string "POKéMON are partners to people.\n"
	.string "They aren't our tools.\p"
	.string "Unfortunately, there are some people\n"
	.string "who fail to understand that…$"
	.else
	.ifdef GERMAN
	.string "POKéMON sind die Partner der Menschen.\n"
	.string "Sie sind nicht unser Spielzeug!\p"
	.string "Leider gibt es immer wieder Menschen,\n"
	.string "die das nicht begreifen.$"
	.endif
	.endif

LilycoveCity_House1_Text_Kecleon:
	.ifdef ENGLISH
	.string "KECLEON: Ruroro?$"
	.else
	.ifdef GERMAN
	.string "KECLEON: Ruroro?$"
	.endif
	.endif

