ShoalCave_LowTideLowerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ShoalCave_LowTideLowerRoom_OnLoad
	.byte 0

ShoalCave_LowTideLowerRoom_OnLoad:
	call ShoalCave_LowTideLowerRoom_EventScript_SetShoalItemMetatiles
	end

ShoalCave_LowTideLowerRoom_EventScript_SetShoalItemMetatiles::
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_4, ShoalCave_LowTideLowerRoom_EventScript_SetShoalItemMetatilesEnd
	setmetatile 18, 2, METATILE_Cave_ShoalCave_DirtPile_Large, TRUE
	return

ShoalCave_LowTideLowerRoom_EventScript_SetShoalItemMetatilesEnd::
	return

ShoalCave_LowTideLowerRoom_EventScript_ShoalSalt4::
	lockall
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_4, ShoalCave_LowTideLowerRoom_EventScript_ReceivedShoalSalt
	giveitem ITEM_SHOAL_SALT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setmetatile 18, 2, METATILE_Cave_ShoalCave_DirtPile_Small, FALSE
	special DrawWholeMapView
	setflag FLAG_RECEIVED_SHOAL_SALT_4
	releaseall
	end

ShoalCave_LowTideLowerRoom_EventScript_ReceivedShoalSalt::
	msgbox ShoalCave_Text_WasShoalSaltNowNothing, MSGBOX_DEFAULT
	releaseall
	end

ShoalCave_LowTideLowerRoom_EventScript_BlackBelt::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_FOCUS_BAND, ShoalCave_LowTideLowerRoom_EventScript_ReceivedFocusBand
	msgbox ShoalCave_LowTideLowerRoom_Text_CanOvercomeColdWithFocus, MSGBOX_DEFAULT
	giveitem ITEM_FOCUS_BAND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FOCUS_BAND
	release
	end

ShoalCave_LowTideLowerRoom_EventScript_ReceivedFocusBand::
	msgbox ShoalCave_LowTideLowerRoom_Text_EverythingStartsWithFocus, MSGBOX_DEFAULT
	release
	end

ShoalCave_LowTideLowerRoom_Text_CanOvercomeColdWithFocus:
	.ifdef ENGLISH
	.string "The penetrating cold around these\n"
	.string "parts is an impediment to training.\p"
	.string "But with focus, one can overcome!\p"
	.string "With this FOCUS BAND, buckle down and\n"
	.string "withstand the cold!$"
	.else
	.ifdef GERMAN
	.string "Die eisige Kälte in dieser Gegend ist\n"
	.string "ein gewaltiges Hindernis beim Training.\p"
	.string "Aber wenn man sich konzentriert, kann\n"
	.string "man doch gewinnen!\p"
	.string "Mit diesem FOKUS-BAND kannst du dich\n"
	.string "besser konzentrieren und der Kälte\l"
	.string "widerstehen.$"
	.endif
	.endif

ShoalCave_LowTideLowerRoom_Text_EverythingStartsWithFocus:
	.ifdef ENGLISH
	.string "Everything starts with focus!$"
	.else
	.ifdef GERMAN
	.string "Alles hängt von der Konzentration ab!$"
	.endif
	.endif

