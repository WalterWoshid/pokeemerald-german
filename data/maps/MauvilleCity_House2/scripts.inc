MauvilleCity_House2_MapScripts::
	.byte 0

MauvilleCity_House2_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_ReceivedCoinCase
	msgbox MauvilleCity_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
	checkitem ITEM_HARBOR_MAIL
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_House2_EventScript_AskToTradeForHarborMail
	release
	end

MauvilleCity_House2_EventScript_AskToTradeForHarborMail::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_House2_EventScript_AcceptTrade
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House2_EventScript_DeclineTrade
	end

MauvilleCity_House2_EventScript_AcceptTrade::
	msgbox MauvilleCity_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
	removeitem ITEM_HARBOR_MAIL
	giveitem ITEM_COIN_CASE
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
	end

MauvilleCity_House2_EventScript_ReceivedCoinCase::
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_EventScript_DeclineTrade::
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_Text_BuyHarborMailAtSlateport:
	.ifdef ENGLISH
	.string "If I had a BIKE, it'd be easy to cycle to\n"
	.string "SLATEPORT for some shopping.\p"
	.string "I'd be able to buy HARBOR MAIL at the\n"
	.string "POKéMON MART in SLATEPORT…$"
	.else
	.ifdef GERMAN
	.string "Wenn ich doch nur ein RAD hätte…\n"
	.string "Dann könnte ich nach GRAPHITPORT\l"
	.string "CITY zum Einkaufen fahren.\p"
	.string "Dort würde ich mir dann einen HAFEN-\n"
	.string "BRIEF im PKMN-SUPERMARKT kaufen…$"
	.endif
	.endif

MauvilleCity_House2_Text_TradeHarborMailForCoinCase:
	.ifdef ENGLISH
	.string "Oh! You have HARBOR MAIL?\n"
	.string "Will you trade it for a COIN CASE?$"
	.else
	.ifdef GERMAN
	.string "Oh! Du besitzt einen HAFENBRIEF!!!\n"
	.string "Würdest du den gegen einen MÜNZKORB\l"
	.string "tauschen?$"
	.endif
	.endif

MauvilleCity_House2_Text_IllTradeYouCoinCase:
	.ifdef ENGLISH
	.string "Oh, I'm so happy!\n"
	.string "Okay, I'll trade you a COIN CASE!$"
	.else
	.ifdef GERMAN
	.string "Oh, ich bin so glücklich!\n"
	.string "Okay, ich gebe dir diesen MÜNZKORB!$"
	.endif
	.endif

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner:
	.ifdef ENGLISH
	.string "That COIN CASE can be used\n"
	.string "at the GAME CORNER.$"
	.else
	.ifdef GERMAN
	.string "Diesen MÜNZKORB brauchst du in der\n"
	.string "SPIELHALLE.$"
	.endif
	.endif

MauvilleCity_House2_Text_ThatsDisappointing:
	.ifdef ENGLISH
	.string "Oh, that's disappointing.\p"
	.string "A COIN CASE is needed for the\n"
	.string "GAME CORNER.$"
	.else
	.ifdef GERMAN
	.string "Oh, das ist schade.\p"
	.string "In der SPIELHALLE benötigt man einen\n"
	.string "MÜNZKORB.$"
	.endif
	.endif

