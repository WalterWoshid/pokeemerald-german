PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.ifdef ENGLISH
	.string "I can't see MIRAGE ISLAND today…$"
	.else
	.ifdef GERMAN
	.string "Ich kann WUNDEREILAND heute\n"
	.string "nicht sehen…$"
	.endif
	.endif

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.ifdef ENGLISH
	.string "Oh! Oh my!\n"
	.string "I can see MIRAGE ISLAND today!$"
	.else
	.ifdef GERMAN
	.string "Oh! Oh! Heute kann ich WUNDEREILAND\n"
	.string "sehen!$"
	.endif
	.endif

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.ifdef ENGLISH
	.string "MIRAGE ISLAND…\p"
	.string "It must become visible and invisible\n"
	.string "depending on the weather conditions\l"
	.string "that make mirages appear.\p"
	.string "Or is it really appearing and\n"
	.string "disappearing?$"
	.else
	.ifdef GERMAN
	.string "WUNDEREILAND…\p"
	.string "Die Insel ist sichtbar oder nicht\n"
	.string "sichtbar. Das hängt vom Wetter ab, das\l"
	.string "Fata Morganen möglich macht oder nicht.\p"
	.string "Oder verschwindet die Insel\n"
	.string "tatsächlich manchmal?$"
	.endif
	.endif

