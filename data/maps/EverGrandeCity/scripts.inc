EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

EverGrandeCity_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

EverGrandeCity_EventScript_VictoryRoadSign::
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_CitySign::
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_PokemonLeagueSign::
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_SetVisitedEverGrande::
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end

EverGrandeCity_Text_EnteringVictoryRoad:
	.ifdef ENGLISH
	.string "ENTERING VICTORY ROAD$"
	.else
	.ifdef GERMAN
	.string "SIE BETRETEN DIE SIEGESSTRASSE$"
	.endif
	.endif

EverGrandeCity_Text_EnteringPokemonLeague:
	.ifdef ENGLISH
	.string "ENTERING POKéMON LEAGUE\n"
	.string "CENTER GATE$"
	.else
	.ifdef GERMAN
	.string "SIE ERREICHEN DEN EINGANG ZUR\n"
	.string "POKéMON LIGA$"
	.endif
	.endif

EverGrandeCity_Text_CitySign:
	.ifdef ENGLISH
	.string "EVER GRANDE CITY\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and POKéMON.”$"
	.else
	.ifdef GERMAN
	.string "PRACHTPOLIS CITY\p"
	.string "“Das Paradies der Blumen, des Meeres\n"
	.string "und der POKéMON.”$"
	.endif
	.endif
