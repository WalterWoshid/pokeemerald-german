RustboroCity_Flat2_1F_MapScripts::
	.byte 0

RustboroCity_Flat2_1F_EventScript_OldWoman::
	msgbox RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere, MSGBOX_NPC
	end

RustboroCity_Flat2_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox RustboroCity_Flat2_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere:
	.ifdef ENGLISH
	.string "DEVON CORPORATION's workers live in\n"
	.string "this building.$"
	.else
	.ifdef GERMAN
	.string "Die Angestellten der DEVON\n"
	.string "CORPORATION leben in diesem Haus.$"
	.endif
	.endif

RustboroCity_Flat2_1F_Text_Skitty:
	.ifdef ENGLISH
	.string "SKITTY: Gyaaaah!$"
	.else
	.ifdef GERMAN
	.string "ENECO: Gyaaaah!$"
	.endif
	.endif

