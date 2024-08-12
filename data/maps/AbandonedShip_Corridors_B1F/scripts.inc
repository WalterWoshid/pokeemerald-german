AbandonedShip_Corridors_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Corridors_B1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_Corridors_B1F_OnLoad
	.byte 0

AbandonedShip_Corridors_B1F_OnResume:
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER1, 5, 4
	end

AbandonedShip_Corridors_B1F_OnLoad:
	call_if_unset FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_LockStorageRoom
	call_if_set FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom
	end

AbandonedShip_Corridors_B1F_EventScript_LockStorageRoom::
	setmetatile 11, 4, METATILE_InsideShip_IntactDoor_Bottom_Locked, TRUE
	return

AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom::
	setmetatile 11, 4, METATILE_InsideShip_IntactDoor_Bottom_Unlocked, TRUE
	return

AbandonedShip_Corridors_B1F_EventScript_TuberM::
	msgbox AbandonedShip_Corridors_B1F_Text_YayItsAShip, MSGBOX_NPC
	end

AbandonedShip_Corridors_B1F_EventScript_StorageRoomDoor::
	lockall
	goto_if_set FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_DoorIsUnlocked
	checkitem ITEM_STORAGE_KEY
	goto_if_eq VAR_RESULT, FALSE, AbandonedShip_Corridors_B1F_EventScript_DoorIsLocked
	msgbox AbandonedShip_Corridors_B1F_Text_InsertedStorageKey, MSGBOX_DEFAULT
	playse SE_PIN
	removeitem ITEM_STORAGE_KEY
	setflag FLAG_USED_STORAGE_KEY
	call AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_DoorIsLocked::
	msgbox AbandonedShip_Corridors_B1F_Text_DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_DoorIsUnlocked::
	msgbox AbandonedShip_Text_TheDoorIsOpen, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_Duncan::
	trainerbattle_single TRAINER_DUNCAN, AbandonedShip_Corridors_B1F_Text_DuncanIntro, AbandonedShip_Corridors_B1F_Text_DuncanDefeat
	msgbox AbandonedShip_Corridors_B1F_Text_DuncanPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_B1F_Text_DuncanIntro:
	.ifdef ENGLISH
	.string "When we go out to sea, we SAILORS\n"
	.string "always bring our POKéMON.\l"
	.string "How about a quick battle?$"
	.else
	.ifdef GERMAN
	.string "Wenn wir zur See fahren, nehmen wir\n"
	.string "MATROSEN immer unsere POKéMON mit.\l"
	.string "Wie wäre es mit einem schnellen Kampf?$"
	.endif
	.endif

AbandonedShip_Corridors_B1F_Text_DuncanDefeat:
	.ifdef ENGLISH
	.string "Whoops, I'm sunk!$"
	.else
	.ifdef GERMAN
	.string "Huups, da bin ich abgesoffen.$"
	.endif
	.endif

AbandonedShip_Corridors_B1F_Text_DuncanPostBattle:
	.ifdef ENGLISH
	.string "The ship's bottom has sunk into the\n"
	.string "depths.\p"
	.string "If a POKéMON knew how to go underwater,\n"
	.string "we might make some progress…$"
	.else
	.ifdef GERMAN
	.string "Der Schiffsrumpf liegt tief unter der\n"
	.string "Wasserlinie.\p"
	.string "Wenn ein POKéMON wissen würde, wie\n"
	.string "man taucht, würden wir Fortschritte\l"
	.string "machen.$"
	.endif
	.endif

AbandonedShip_Corridors_B1F_Text_YayItsAShip:
	.ifdef ENGLISH
	.string "Yay!\n"
	.string "It's a ship!$"
	.else
	.ifdef GERMAN
	.string "Jahaa!\n"
	.string "Ein Schiff!$"
	.endif
	.endif

AbandonedShip_Corridors_B1F_Text_DoorIsLocked:
	.ifdef ENGLISH
	.string "The door is locked.\p"
	.string "“STORAGE” is painted on the door.$"
	.else
	.ifdef GERMAN
	.string "Die Tür ist verschlossen.\p"
	.string "“LAGER” steht auf dem Schild.$"
	.endif
	.endif

AbandonedShip_Corridors_B1F_Text_InsertedStorageKey:
	.ifdef ENGLISH
	.string "{PLAYER} inserted and turned the\n"
	.string "STORAGE KEY.\p"
	.string "The inserted KEY stuck fast,\n"
	.string "but the door opened.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} steckt den SCHLÜSSEL zum\n"
	.string "LAGER ins Schlüsselloch und dreht ihn.\p"
	.string "Der SCHLÜSSEL ist schwergängig, aber\n"
	.string "das Schloss lässt sich öffnen.$"
	.endif
	.endif

AbandonedShip_Text_TheDoorIsOpen:
	.ifdef ENGLISH
	.string "The door is open.$"
	.else
	.ifdef GERMAN
	.string "Die Tür ist offen.$"
	.endif
	.endif

