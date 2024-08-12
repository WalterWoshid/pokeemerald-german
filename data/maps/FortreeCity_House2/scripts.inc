FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
	.ifdef ENGLISH
	.string "People… POKéMON…\p"
	.string "Their hidden powers are aroused by\n"
	.string "living in natural environments…$"
	.else
	.ifdef GERMAN
	.string "Menschen… POKéMON…\p"
	.string "Ihre versteckten Kräfte werden durch\n"
	.string "das Leben in der Natur geweckt.$"
	.endif
	.endif

FortreeCity_House2_Text_CoinInWhichHand:
	.ifdef ENGLISH
	.string "Let this old woman see if your hidden\n"
	.string "power has awoken…\p"
	.string "I hold a coin in my hand.\p"
	.string "Now, tell me, have I palmed it in\n"
	.string "the right hand? Or in the left?$"
	.else
	.ifdef GERMAN
	.string "Lass diese alte Frau mal sehen, ob deine\n"
	.string "versteckten Kräfte erwacht sind…\p"
	.string "Ich halte eine Münze in meiner Hand.\p"
	.string "Nun? In welcher Hand halte ich sie?\n"
	.string "In der linken oder rechten Hand?$"
	.endif
	.endif

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.ifdef ENGLISH
	.string "Oh! Yes, correct!\p"
	.string "We shall try again.\p"
	.string "In which hand have I palmed the coin?\n"
	.string "The right or left?$"
	.else
	.ifdef GERMAN
	.string "Oh! Das stimmt!\p"
	.string "Versuchen wir es noch einmal.\p"
	.string "In welcher Hand halte ich die Münze?\n"
	.string "Rechts oder links?$"
	.endif
	.endif

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.ifdef ENGLISH
	.string "Oh! Yes, correct!\p"
	.string "We shall try again.\p"
	.string "In which hand have I palmed the coin?\n"
	.string "The right or left?$"
	.else
	.ifdef GERMAN
	.string "Oh! Schon wieder richtig!\p"
	.string "Probieren wir es noch einmal.\p"
	.string "In welcher Hand ist die Münze nun?\n"
	.string "In der linken oder der rechten Hand?$"
	.endif
	.endif

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.ifdef ENGLISH
	.string "Oh! Splendid!\n"
	.string "Your hidden power has awoken!\p"
	.string "Here, take this and awaken the hidden\n"
	.string "power of your POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Oh! Hervorragend!\n"
	.string "Deine versteckten Kräfte sind erwacht!\p"
	.string "Hier, das ist für dich. Wecke damit die\n"
	.string "versteckten Kräfte deiner POKéMON.$"
	.endif
	.endif

FortreeCity_House2_Text_ExplainHiddenPower:
	.ifdef ENGLISH
	.string "HIDDEN POWER is a move that changes\n"
	.string "with the POKéMON.$"
	.else
	.ifdef GERMAN
	.string "KRAFTRESERVE ist eine Attacke, die je\n"
	.string "nach POKéMON anders aussieht.$"
	.endif
	.endif

FortreeCity_House2_Text_YouGuessedWrong:
	.ifdef ENGLISH
	.string "No, too bad.\n"
	.string "You guessed wrong.$"
	.else
	.ifdef GERMAN
	.string "Och, zu schade!\n"
	.string "Du hast falsch geraten.$"
	.endif
	.endif

