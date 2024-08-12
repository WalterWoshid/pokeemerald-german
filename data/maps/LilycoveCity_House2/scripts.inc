LilycoveCity_House2_MapScripts::
	.byte 0

LilycoveCity_House2_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_REST, LilycoveCity_House2_EventScript_ReceivedRest
	msgbox LilycoveCity_House2_Text_NotAwakeYetHaveThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_REST
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_REST
	msgbox LilycoveCity_House2_Text_SleepIsEssential, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House2_EventScript_ReceivedRest::
	msgbox LilycoveCity_House2_Text_SleepIsEssential, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House2_Text_NotAwakeYetHaveThis:
	.ifdef ENGLISH
	.string "Huh? What? What's that?\p"
	.string "I'm not near awake yet…\n"
	.string "You can have this…$"
	.else
	.ifdef GERMAN
	.string "Huch? Was? Wie?\p"
	.string "Ich bin noch nicht ganz wach…\n"
	.string "Hier, das kannst du haben…$"
	.endif
	.endif

LilycoveCity_House2_Text_SleepIsEssential:
	.ifdef ENGLISH
	.string "Yawn…\p"
	.string "Sleep is essential for good health…\n"
	.string "Sleep and regain health…$"
	.else
	.ifdef GERMAN
	.string "Gääähn…\p"
	.string "Schlaf ist wichtig für die Gesundheit…\n"
	.string "Schlafe und erhole dich…$"
	.endif
	.endif
