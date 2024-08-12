EverGrandeCity_DrakesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_DrakesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_DrakesRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

EverGrandeCity_DrakesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 4, EverGrandeCity_DrakesRoom_EventScript_CloseDoor
	end

EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_DrakesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_DrakesRoom_EventScript_Drake::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_Defeated::
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_Text_IntroSpeech:
	.ifdef ENGLISH
	.string "I am the last of the POKéMON LEAGUE\n"
	.string "ELITE FOUR, DRAKE the DRAGON master!\p"
	.string "In their natural state, POKéMON are\n"
	.string "wild living things. They are free.\p"
	.string "At times, they hinder us.\n"
	.string "At times, they help us.\p"
	.string "For us to battle with POKéMON as\n"
	.string "partners, do you know what it takes?\p"
	.string "Do you know what is needed?\p"
	.string "If you don't, then you will never\n"
	.string "prevail over me!$"
	.else
	.ifdef GERMAN
	.string "Ich bin der letzte der TOP VIER in der\n"
	.string "POKéMON LIGA, DRAGAN der\l"
	.string "DRACHEN-Meister!\p"
	.string "Von Natur aus sind POKéMON wild.\n"
	.string "Sie sind frei.\p"
	.string "Manchmal behindern sie uns.\n"
	.string "Manchmal helfen sie uns.\p"
	.string "Weißt du, was es bedeutet, mit POKéMON\n"
	.string "als gleichwertigen Partnern\l"
	.string "zu kämpfen?\p"
	.string "Weißt du, was verlangt wird?\p"
	.string "Wenn du das nicht weißt, wirst du\n"
	.string "hier an dieser Stelle scheitern!$"
	.endif
	.endif

EverGrandeCity_DrakesRoom_Text_Defeat:
	.ifdef ENGLISH
	.string "Superb, it should be said.$"
	.else
	.ifdef GERMAN
	.string "Hervorragend! Das muss man sagen.$"
	.endif
	.endif

EverGrandeCity_DrakesRoom_Text_PostBattleSpeech:
	.ifdef ENGLISH
	.string "You deserve every credit for coming\n"
	.string "this far as a TRAINER of POKéMON.\p"
	.string "You do seem to know what is needed.\p"
	.string "Yes, what a TRAINER needs is a\n"
	.string "virtuous heart.\p"
	.string "POKéMON touch the good hearts of\n"
	.string "TRAINERS and learn good from wrong.\p"
	.string "They touch the good hearts of\n"
	.string "TRAINERS and grow strong.\p"
	.string "Go! Go onwards!\n"
	.string "The CHAMPION is waiting!$"
	.else
	.ifdef GERMAN
	.string "Dir gebührt wahre Ehre, da du als\n"
	.string "TRAINER der POKéMON so weit\l"
	.string "gekommen bist.\p"
	.string "Du weißt, was verlangt wird.\p"
	.string "Ja, ein TRAINER braucht ein ehrliches\n"
	.string "Herz.\p"
	.string "POKéMON berühren das Gute im Herzen\n"
	.string "des TRAINERs und lernen, zwischen gut\l"
	.string "und schlecht zu unterscheiden.\p"
	.string "Sie berühren die guten Herzen der\n"
	.string "TRAINER und wachsen daran.\p"
	.string "Geh! Geh weiter!\n"
	.string "Der CHAMP erwartet dich!$"
	.endif
	.endif

