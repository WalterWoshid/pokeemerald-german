MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.ifdef ENGLISH
	.string "All sorts of beings wander the slopes\n"
	.string "of MT. PYRE…\p"
	.string "There is no telling what may happen.\n"
	.string "Take this. It's for your own good.$"
	.else
	.ifdef GERMAN
	.string "Auf den Pfaden des PYROBERGs kreucht\n"
	.string "und fleucht alles Mögliche…\p"
	.string "Niemand kann sagen, was passieren wird.\n"
	.string "Dies ist für dich, es wird dir helfen.$"
	.endif
	.endif

MtPyre_1F_Text_ExplainCleanseTag:
	.ifdef ENGLISH
	.string "Have a POKéMON hold that\n"
	.string "CLEANSE TAG.\p"
	.string "It will help ward off wild POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Lass ein POKéMON das SCHUTZBAND\n"
	.string "tragen.\p"
	.string "Das hilft, wilde POKéMON fern zu halten.$"
	.endif
	.endif

MtPyre_1F_Text_ComeToPayRespects:
	.ifdef ENGLISH
	.string "Did you come to pay your respect\n"
	.string "to the spirits of departed POKéMON?\p"
	.string "You must care for your POKéMON a lot.$"
	.else
	.ifdef GERMAN
	.string "Bist du hier, um den verstorbenen\n"
	.string "POKéMON deinen Respekt zu zollen?\p"
	.string "Du musst immer sehr fürsorglich zu\n"
	.string "deinen POKéMON sein.$"
	.endif
	.endif

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.ifdef ENGLISH
	.string "This is the final resting place of my\n"
	.string "ZIGZAGOON. I cherished it…$"
	.else
	.ifdef GERMAN
	.string "Hier ruht mein ZIGZACHS. Ich habe\n"
	.string "es wirklich sehr geliebt…$"
	.endif
	.endif

