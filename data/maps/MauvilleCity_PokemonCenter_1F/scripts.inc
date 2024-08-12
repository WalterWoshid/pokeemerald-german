.set LOCALID_NURSE, 1

MauvilleCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MauvilleCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MAUVILLE_CITY
	call Common_EventScript_UpdateBrineyLocation
	goto MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx::
	special SetMauvilleOldManObjEventGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman1::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman2::
	msgbox MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings:
	.ifdef ENGLISH
	.string "That man over there, he says weird\n"
	.string "things!\p"
	.string "He's funny in a weird way.\n"
	.string "I doubt I'll forget about him!$"
	.else
	.ifdef GERMAN
	.string "Der Mann dort drüben, der sagt\n"
	.string "vielleicht verrückte Dinge!\p"
	.string "Auf seltsame Weise ist er aber amüsant.\n"
	.string "Den werde ich wohl nicht vergessen!$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner:
	.ifdef ENGLISH
	.string "When I accessed the RECORD CORNER,\n"
	.string "the data for what's hot in DEWFORD\l"
	.string "got updated.\p"
	.string "Now that bit of data is the same\n"
	.string "as my friend's!$"
	.else
	.ifdef GERMAN
	.string "Wenn ich auf STATISTIKTAUSCH Zugriff\n"
	.string "nehme, werden die neuesten Nachrichten\l"
	.string "aus FAUSTAUHAVEN hochgeladen.\p"
	.string "Diese Daten decken sich nun mit denen\n"
	.string "meines Freundes!$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun:
	.ifdef ENGLISH
	.string "A RECORD CORNER opened upstairs in\n"
	.string "the POKéMON CENTER.\p"
	.string "I don't know what it's about, but it\n"
	.string "sounds fun. I'll go check it out!$"
	.else
	.ifdef GERMAN
	.string "Im oberen Stockwerk des POKéMON-\n"
	.string "CENTERs wurde die Möglichkeit des\l"
	.string "STATISTIKTAUSCHes eingerichtet.\p"
	.string "Ich weiß nicht genau, was das ist. Aber\n"
	.string "das werde ich herausfinden! Ist\l"
	.string "bestimmt lustig!$"
	.endif
	.endif

