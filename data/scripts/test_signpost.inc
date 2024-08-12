Text_ThisIsATestSignpostMsg::
	.ifdef ENGLISH
	.string "This is a test message.\n"
	.string "This is a signpost.$"
	.else
	.ifdef GERMAN
	.string "Dies ist ein Test.\n"
	.string "Ein Schild.$"
	.endif
	.endif

EventScript_TestSignpostMsg::
	msgbox Text_ThisIsATestSignpostMsg, MSGBOX_SIGN
	end
