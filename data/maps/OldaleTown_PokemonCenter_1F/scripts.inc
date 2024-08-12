.set LOCALID_NURSE, 1

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.ifdef ENGLISH
	.string "That PC in the corner there is\n"
	.string "for any POKéMON TRAINER to use.\p"
	.string "Naturally, that means you're welcome\n"
	.string "to use it, too.$"
	.else
	.ifdef GERMAN
	.string "Der PC dort in der Ecke ist für alle\n"
	.string "POKéMON-TRAINER.\p"
	.string "Das heißt, dass auch du ihn benutzen\n"
	.string "darfst.$"
	.endif
	.endif

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.ifdef ENGLISH
	.string "POKéMON CENTERS are great!\p"
	.string "You can use their services as much\n"
	.string "as you like, and it's all for free.\l"
	.string "You never have to worry!$"
	.else
	.ifdef GERMAN
	.string "POKéMON-CENTER sind eine großartige\n"
	.string "Einrichtung!\p"
	.string "Du kannst ihren Service sooft du willst\n"
	.string "in Anspruch nehmen - kostenlos! Daher\l"
	.string "kannst du unbeschwert umherreisen.$"
	.endif
	.endif

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.ifdef ENGLISH
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "But they say they're still making\n"
	.string "adjustments.$"
	.else
	.ifdef GERMAN
	.string "Der POKéMON DRAHTLOSKLUB im zweiten\n"
	.string "Stock wurde erst kürzlich eröffnet.\p"
	.string "Und sie sind immer noch nicht ganz\n"
	.string "fertig mit dem Einrichten.$"
	.endif
	.endif

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.ifdef ENGLISH
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "I traded POKéMON right away.$"
	.else
	.ifdef GERMAN
	.string "Der POKéMON DRAHTLOSKLUB im zweiten\n"
	.string "Stock wurde erst kürzlich eröffnet.\p"
	.string "Ich habe schon POKéMON getauscht!$"
	.endif
	.endif

