SootopolisCity_House6_MapScripts::
	.byte 0

SootopolisCity_House6_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WAILMER_DOLL, SootopolisCity_House6_EventScript_ReceivedWailmerDoll
	msgbox SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, SootopolisCity_House6_EventScript_DeclineWailmerDoll
	msgbox SootopolisCity_House6_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	givedecoration DECOR_WAILMER_DOLL
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_House6_EventScript_NoRoomForWailmerDoll
	setflag FLAG_RECEIVED_WAILMER_DOLL
	release
	end

SootopolisCity_House6_EventScript_DeclineWailmerDoll::
	msgbox SootopolisCity_House6_Text_DontWantThisDoll, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_ReceivedWailmerDoll::
	msgbox SootopolisCity_House6_Text_LovePlushDolls, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_NoRoomForWailmerDoll::
	bufferdecorationname STR_VAR_2, DECOR_WAILMER_DOLL
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	msgbox SootopolisCity_House6_Text_IllHoldItForYou, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll:
	.ifdef ENGLISH
	.string "Hello! You're our first guest in\n"
	.string "a good while.\p"
	.string "You've brightened up my day, so I'll\n"
	.string "give you a big WAILMER DOLL.$"
	.else
	.ifdef GERMAN
	.string "Hallo! Du bist nach langer Zeit der\n"
	.string "erste Gast, den ich begrüße.\p"
	.string "Du hast mir den Tag gerettet, daher\n"
	.string "möchte ich dir diese WAILMER-PUPPE\l"
	.string "schenken.$"
	.endif
	.endif

SootopolisCity_House6_Text_TakeGoodCareOfIt:
	.ifdef ENGLISH
	.string "Take good care of it!$"
	.else
	.ifdef GERMAN
	.string "Pass gut auf sie auf!$"
	.endif
	.endif

SootopolisCity_House6_Text_IllHoldItForYou:
	.ifdef ENGLISH
	.string "Oh, you want it, but not right now?\n"
	.string "Okay, then I'll hold it for you.$"
	.else
	.ifdef GERMAN
	.string "Oh, du möchtest sie zwar haben, aber\n"
	.string "nicht sofort? Dann hebe ich sie dir auf.$"
	.endif
	.endif

SootopolisCity_House6_Text_DontWantThisDoll:
	.ifdef ENGLISH
	.string "Are you sure?\n"
	.string "You don't want this DOLL?$"
	.else
	.ifdef GERMAN
	.string "Bist du sicher?\n"
	.string "Du möchtest diese PUPPE wirklich nicht?$"
	.endif
	.endif

SootopolisCity_House6_Text_LovePlushDolls:
	.ifdef ENGLISH
	.string "I love plush DOLLS!$"
	.else
	.ifdef GERMAN
	.string "Ich liiiiebe Plüsch-PUPPEn!$"
	.endif
	.endif

