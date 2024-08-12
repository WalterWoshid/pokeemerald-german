.set LOCALID_NURSE, 1

SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_Sailor::
	msgbox SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon:
	.ifdef ENGLISH
	.string "Want a tip for battling?\p"
	.string "I'd say it's raising different kinds\n"
	.string "of POKéMON in a balanced manner.\p"
	.string "It's no good to make just one\n"
	.string "POKéMON strong.\p"
	.string "If it has a type disadvantage,\n"
	.string "it might not stand a chance.$"
	.else
	.ifdef GERMAN
	.string "Möchtest du einen Tipp?\p"
	.string "Ich sage dir, es ist wichtig, die unter-\n"
	.string "schiedlichsten POKéMON zu trainieren.\p"
	.string "Gleichmäßigkeit ist wichtig. Ein\n"
	.string "einzelnes starkes POKéMON reicht\l"
	.string "nicht.\p"
	.string "Wenn es vom Typ her Nachteile besitzt,\n"
	.string "kann auch ein sehr starkes POKéMON\l"
	.string "einen Kampf verlieren.$"
	.endif
	.endif

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend:
	.ifdef ENGLISH
	.string "I trade POKéMON with my friends.\p"
	.string "If a traded POKéMON is holding an\n"
	.string "item, it makes me twice as happy!$"
	.else
	.ifdef GERMAN
	.string "Ich tausche mit Freunden POKéMON.\p"
	.string "Und wenn ein getauschtes POKéMON ein\n"
	.string "Item trägt, bin ich umso glücklicher!$"
	.endif
	.endif

