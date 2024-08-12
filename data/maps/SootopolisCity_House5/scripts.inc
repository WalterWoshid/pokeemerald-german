SootopolisCity_House5_MapScripts::
	.byte 0

SootopolisCity_House5_EventScript_Maniac::
	msgbox SootopolisCity_House5_Text_SootopolisMtPyreConnection, MSGBOX_NPC
	end

SootopolisCity_House5_EventScript_Girl::
	msgbox SootopolisCity_House5_Text_BrotherUsedToStudySea, MSGBOX_NPC
	end

SootopolisCity_House5_Text_SootopolisMtPyreConnection:
	.ifdef ENGLISH
	.string "There appears to be some connection\n"
	.string "between SOOTOPOLIS and MT. PYRE.\p"
	.string "My friends and I did some research on\n"
	.string "it at the lab where I used to work.$"
	.else
	.ifdef GERMAN
	.string "Es muss eine Verbindung zwischen\n"
	.string "XENEROVILLE und dem PYROBERG geben.\p"
	.string "Meine Freunde und ich haben ein\n"
	.string "bisschen nachgeforscht - im Labor,\l"
	.string "in dem wir gearbeitet haben.$"
	.endif
	.endif

SootopolisCity_House5_Text_BrotherUsedToStudySea:
	.ifdef ENGLISH
	.string "My big brother used to study the sea.$"
	.else
	.ifdef GERMAN
	.string "Mein großer Bruder studiert das Meer.$"
	.endif
	.endif

