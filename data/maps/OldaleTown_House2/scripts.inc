OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.ifdef ENGLISH
	.string "When POKéMON battle, they eventually\n"
	.string "level up and become stronger.$"
	.else
	.ifdef GERMAN
	.string "Während eines Kampfes können POKéMON\n"
	.string "manchmal einen Level dazugewinnen und\l"
	.string "stärker werden.$"
	.endif
	.endif

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.ifdef ENGLISH
	.string "If the POKéMON with you become\n"
	.string "stronger, you'll be able to go farther\l"
	.string "away from here.$"
	.else
	.ifdef GERMAN
	.string "Sobald deine Team-POKéMON stärker\n"
	.string "geworden sind, kannst du auch andere\l"
	.string "Orte bereisen.$"
	.endif
	.endif

