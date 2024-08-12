AbandonedShip_HiddenFloorCorridors_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_HiddenFloorCorridors_OnResume
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_HiddenFloorCorridors_OnLoad
	.byte 0

AbandonedShip_HiddenFloorCorridors_OnResume:
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER1, 5, 4
	end

AbandonedShip_HiddenFloorCorridors_OnLoad:
	call_if_unset FLAG_USED_ROOM_1_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom1
	call_if_unset FLAG_USED_ROOM_2_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom2
	call_if_unset FLAG_USED_ROOM_4_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom4
	call_if_unset FLAG_USED_ROOM_6_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom6
	call_if_set FLAG_USED_ROOM_1_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom1
	call_if_set FLAG_USED_ROOM_2_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom2
	call_if_set FLAG_USED_ROOM_4_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom4
	call_if_set FLAG_USED_ROOM_6_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom6
	end

AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom1::
	setmetatile 3, 8, METATILE_InsideShip_IntactDoor_Bottom_Unlocked, TRUE
	return

AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom2::
	setmetatile 6, 8, METATILE_InsideShip_IntactDoor_Bottom_Unlocked, TRUE
	return

AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom4::
	setmetatile 3, 3, METATILE_InsideShip_DoorIndent_Unlocked, FALSE
	return

AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom6::
	setmetatile 9, 3, METATILE_InsideShip_DoorIndent_Unlocked, FALSE
	return

AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom1::
	setmetatile 3, 8, METATILE_InsideShip_IntactDoor_Bottom_Locked, TRUE
	return

AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom2::
	setmetatile 6, 8, METATILE_InsideShip_IntactDoor_Bottom_Locked, TRUE
	return

AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom4::
	setmetatile 3, 3, METATILE_InsideShip_DoorIndent_Locked, FALSE
	return

AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom6::
	setmetatile 9, 3, METATILE_InsideShip_DoorIndent_Locked, FALSE
	return

AbandonedShip_HiddenFloorCorridors_EventScript_Room1Door::
	lockall
	goto_if_set FLAG_USED_ROOM_1_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen
	checkitem ITEM_ROOM_1_KEY
	goto_if_eq VAR_RESULT, FALSE, AbandonedShip_HiddenFloorCorridors_EventScript_Rm1IsLocked
	msgbox AbandonedShip_HiddenFloorCorridors_Text_InsertedKey, MSGBOX_DEFAULT
	playse SE_PIN
	removeitem ITEM_ROOM_1_KEY
	setflag FLAG_USED_ROOM_1_KEY
	call AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom1
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Room2Door::
	lockall
	goto_if_set FLAG_USED_ROOM_2_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen
	checkitem ITEM_ROOM_2_KEY
	goto_if_eq VAR_RESULT, FALSE, AbandonedShip_HiddenFloorCorridors_EventScript_Rm2IsLocked
	msgbox AbandonedShip_HiddenFloorCorridors_Text_InsertedKey, MSGBOX_DEFAULT
	playse SE_PIN
	removeitem ITEM_ROOM_2_KEY
	setflag FLAG_USED_ROOM_2_KEY
	call AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom2
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Room4Door::
	lockall
	goto_if_set FLAG_USED_ROOM_4_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen
	checkitem ITEM_ROOM_4_KEY
	goto_if_eq VAR_RESULT, FALSE, AbandonedShip_HiddenFloorCorridors_EventScript_Rm4IsLocked
	msgbox AbandonedShip_HiddenFloorCorridors_Text_InsertedKey, MSGBOX_DEFAULT
	playse SE_PIN
	removeitem ITEM_ROOM_4_KEY
	setflag FLAG_USED_ROOM_4_KEY
	call AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom4
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Room6Door::
	lockall
	goto_if_set FLAG_USED_ROOM_6_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen
	checkitem ITEM_ROOM_6_KEY
	goto_if_eq VAR_RESULT, FALSE, AbandonedShip_HiddenFloorCorridors_EventScript_Rm6IsLocked
	msgbox AbandonedShip_HiddenFloorCorridors_Text_InsertedKey, MSGBOX_DEFAULT
	playse SE_PIN
	removeitem ITEM_ROOM_6_KEY
	setflag FLAG_USED_ROOM_6_KEY
	call AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom6
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Rm1IsLocked::
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Rm1DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Rm2IsLocked::
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Rm2DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Rm4IsLocked::
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Rm4DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Rm6IsLocked::
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Rm6DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen::
	msgbox AbandonedShip_Text_TheDoorIsOpen, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_Text_Rm1DoorIsLocked:
	.ifdef ENGLISH
	.string "The door is locked.\p"
	.string "“RM. 1” is painted on the door.$"
	.else
	.ifdef GERMAN
	.string "Die Tür ist verschlossen.\p"
	.string "“K. 1” steht auf der Tür.$"
	.endif
	.endif

AbandonedShip_HiddenFloorCorridors_Text_Rm2DoorIsLocked:
	.ifdef ENGLISH
	.string "The door is locked.\p"
	.string "“RM. 2” is painted on the door.$"
	.else
	.ifdef GERMAN
	.string "Die Tür ist verschlossen.\p"
	.string "“K. 2” steht auf der Tür.$"
	.endif
	.endif

AbandonedShip_HiddenFloorCorridors_Text_Rm4DoorIsLocked:
	.ifdef ENGLISH
	.string "The door is locked.\p"
	.string "“RM. 4” is painted on the door.$"
	.else
	.ifdef GERMAN
	.string "Die Tür ist verschlossen.\p"
	.string "“K. 4” steht auf der Tür.$"
	.endif
	.endif

AbandonedShip_HiddenFloorCorridors_Text_Rm6DoorIsLocked:
	.ifdef ENGLISH
	.string "The door is locked.\p"
	.string "“RM. 6” is painted on the door.$"
	.else
	.ifdef GERMAN
	.string "Die Tür ist verschlossen.\p"
	.string "“K. 6” steht auf der Tür.$"
	.endif
	.endif

AbandonedShip_HiddenFloorCorridors_Text_InsertedKey:
	.ifdef ENGLISH
	.string "{PLAYER} inserted and turned the\n"
	.string "KEY.\p"
	.string "The inserted KEY stuck fast,\n"
	.string "but the door opened.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} steckt den SCHLÜSSEL ins\n"
	.string "Schloss und dreht ihn um.\p"
	.string "Der SCHLÜSSEL ist schwergängig, aber\n"
	.string "die Tür öffnet sich.$"
	.endif
	.endif

