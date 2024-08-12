.set LOCALID_DAYCARE_LADY, 1

Route117_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_EventScript_CheckOnTwoMons
	msgbox Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareEggWaiting::
	msgbox Route117_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route117_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route117_EventScript_DaycareReceiveEgg
	msgbox Route117_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareReceiveEgg::
	message Route117_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox Route117_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route117_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route117_EventScript_MonReceivedMail
	return

Route117_EventScript_MonReceivedMail::
	msgbox Route117_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route117_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_PokemonDayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_PokemonDayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_PokemonDayCare_EventScript_TwoMonsInDaycare
	msgbox Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons
	msgbox Route117_PokemonDayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route117_PokemonDayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CanRaiseOneMore
	release
	end

Route117_PokemonDayCare_EventScript_ComeAgain::
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_CanRaiseOneMore::
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_OnlyOneMon::
	msgbox Route117_PokemonDayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyOneAliveMon::
	msgbox Route117_PokemonDayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_EggWaiting::
	msgbox Route117_PokemonDayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route117_PokemonDayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route117_PokemonDayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels
	return

Route117_PokemonDayCare_EventScript_OneMonInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_TryRetrieveMon::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route117_PokemonDayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route117_PokemonDayCare_EventScript_ComeAgain
	goto Route117_PokemonDayCare_EventScript_CostPrompt
	end

Route117_PokemonDayCare_EventScript_CostPrompt::
	special GetDaycareCost
	msgbox Route117_PokemonDayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_CheckEnoughMoney
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_RetrieveMon
	msgbox Route117_PokemonDayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_RetrieveMon::
	applymovement LOCALID_DAYCARE_LADY, Route117_PokemonDayCare_Movement_RetrieveDaycareMon
	waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route117_PokemonDayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_NoRoom::
	msgbox Route117_PokemonDayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route117_PokemonDayCare_EventScript_UnusedEnd::
	end

Route117_PokemonDayCare_EventScript_TwoMonsInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

@ Unused
Route117_PokemonDayCare_EventScript_UnusedRetrieveMon::
	special ShowDaycareLevelMenu
	waitstate
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_ComeAgain
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, TakePokemonFromDaycare
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

EventScript_EggHatch::
	lockall
	msgbox Text_EggHatchHuh, MSGBOX_DEFAULT
	special EggHatch
	waitstate
	releaseall
	end

Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon:
	.ifdef ENGLISH
	.string "I'm the DAY-CARE MAN.\p"
	.string "I help take care of the precious\n"
	.string "POKéMON of TRAINERS.\p"
	.string "If you'd like me to raise your POKéMON,\n"
	.string "have a word with my wife.$"
	.else
	.ifdef GERMAN
	.string "Ich bin der PENSIONSLEITER.\p"
	.string "Ich kümmere mich um die wertvollen\n"
	.string "POKéMON der TRAINER.\p"
	.string "Wenn ich eines deiner POKéMON auf-\n"
	.string "ziehen soll, sprich mit meiner Frau.$"
	.endif
	.endif

Route117_Text_DoYouWantEgg:
	.ifdef ENGLISH
	.string "Ah, it's you!\p"
	.string "We were raising your POKéMON,\n"
	.string "and my goodness, were we surprised!\p"
	.string "Your POKéMON had an EGG!\p"
	.string "We don't know how it got there,\n"
	.string "but your POKéMON had it.\p"
	.string "You do want it, yes?$"
	.else
	.ifdef GERMAN
	.string "Ach, du bist es!\p"
	.string "Wir haben deine POKéMON aufgezogen\n"
	.string "und wurden überrascht!\p"
	.string "Deine POKéMON haben nun ein EI!\p"
	.string "Wir wissen nicht, wie das passiert ist,\n"
	.string "aber deine POKéMON haben es.\p"
	.string "Möchtest du es haben?$"
	.endif
	.endif

Route117_Text_YourMonIsDoingFine:
	.ifdef ENGLISH
	.string "Ah, it's you! Good to see you.\n"
	.string "Your {STR_VAR_1}'s doing fine.$"
	.else
	.ifdef GERMAN
	.string "Ach, du bist es! Schön, dich zu sehen.\n"
	.string "Deinem {STR_VAR_1} geht es sehr gut.$"
	.endif
	.endif

Route117_Text_IllKeepIt:
	.ifdef ENGLISH
	.string "Well then, I'll keep it.\n"
	.string "Thanks!$"
	.else
	.ifdef GERMAN
	.string "Ich werde es behalten.$"
	.endif
	.endif

Route117_Text_YouHaveNoRoomForIt:
	.ifdef ENGLISH
	.string "You have no room for it…\n"
	.string "Come back when you've made room.$"
	.else
	.ifdef GERMAN
	.string "Du hast keinen Platz dafür… Komm\n"
	.string "wieder, wenn du Platz geschafft hast.$"
	.endif
	.endif

Route117_Text_ReceivedEgg:
	.ifdef ENGLISH
	.string "{PLAYER} received the EGG from\n"
	.string "the DAY-CARE MAN.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} erhält das EI vom\n"
	.string "PENSIONSLEITER.$"
	.endif
	.endif

Route117_Text_TakeGoodCareOfIt:
	.ifdef ENGLISH
	.string "Take good care of it.$"
	.else
	.ifdef GERMAN
	.string "Kümmere dich gut darum.$"
	.endif
	.endif

Route117_Text_FriendlyWithOtherTrainersMon:
	.ifdef ENGLISH
	.string "By the way, about your {STR_VAR_1},\n"
	.string "it seemed to be friendly with\l"
	.string "{STR_VAR_2}'s {STR_VAR_3}.\p"
	.string "I may even have seen it receiving\n"
	.string "a piece of MAIL.$"
	.else
	.ifdef GERMAN
	.string "Übrigens, dein {STR_VAR_1} scheint sich\n"
	.string "gut mit dem {STR_VAR_3} von {STR_VAR_2} \l"
	.string "zu verstehen.\p"
	.string "Ich habe gesehen, wie sie einen BRIEF\n"
	.string "ausgetauscht haben…$"
	.endif
	.endif

@ Unused
Route117_Text_SeeWifeIfYouWantToPickUpMon:
	.ifdef ENGLISH
	.string "If you want to pick up your POKéMON,\n"
	.string "have a word with my wife.$"
	.else
	.ifdef GERMAN
	.string "If you want to pick up your POKéMON,\n"
	.string "have a word with my wife.$"
	.endif
	.endif

Route117_Text_YourMonsAreDoingFine:
	.ifdef ENGLISH
	.string "Ah, it's you! Your {STR_VAR_1} and\n"
	.string "{STR_VAR_2} are doing fine.$"
	.else
	.ifdef GERMAN
	.string "Ah, du bist es! Deine POKéMON\n"
	.string "{STR_VAR_1} und {STR_VAR_2} entwickeln\l"
	.string "sich prächtig.$"
	.endif
	.endif

Route117_Text_IWillKeepDoYouWantIt:
	.ifdef ENGLISH
	.string "I really will keep it.\n"
	.string "You do want this, yes?$"
	.else
	.ifdef GERMAN
	.string "Ich werde es behalten.\n"
	.string "Oder möchtest du es haben?$"
	.endif
	.endif

Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon:
	.ifdef ENGLISH
	.string "I'm the DAY-CARE LADY.\p"
	.string "We can raise POKéMON for you.\p"
	.string "Would you like us to raise one?$"
	.else
	.ifdef GERMAN
	.string "Ich bin die PENSIONSLEITERIN.\p"
	.string "Wir ziehen POKéMON für dich auf.\p"
	.string "Sollen wir eins für dich aufziehen?$"
	.endif
	.endif

Route117_PokemonDayCare_Text_WhichMonShouldWeRaise:
	.ifdef ENGLISH
	.string "Which POKéMON should we raise for\n"
	.string "you?$"
	.else
	.ifdef GERMAN
	.string "Welches POKéMON sollen wir für dich\n"
	.string "aufziehen?$"
	.endif
	.endif

Route117_PokemonDayCare_Text_WellRaiseYourMon:
	.ifdef ENGLISH
	.string "Fine, we'll raise your {STR_VAR_1}\n"
	.string "for a while.\p"
	.string "Come back for it later.$"
	.else
	.ifdef GERMAN
	.string "Fein, dann nehmen wir dein {STR_VAR_1}\n"
	.string "für eine Weile in Pflege.\p"
	.string "Schau später mal nach ihm.$"
	.endif
	.endif

Route117_PokemonDayCare_Text_WeCanRaiseOneMore:
	.ifdef ENGLISH
	.string "We can raise two of your POKéMON.\n"
	.string "Would you like us to raise one more?$"
	.else
	.ifdef GERMAN
	.string "Wir können zwei deiner POKéMON nehmen.\n"
	.string "Möchtest du noch eins in Pflege geben?$"
	.endif
	.endif

Route117_PokemonDayCare_Text_HusbandWasLookingForYou:
	.ifdef ENGLISH
	.string "My husband was looking for you.$"
	.else
	.ifdef GERMAN
	.string "Mein Mann hat dich schon gesucht.$"
	.endif
	.endif

Route117_PokemonDayCare_Text_FineThenComeAgain:
	.ifdef ENGLISH
	.string "Oh, fine, then.\n"
	.string "Come again.$"
	.else
	.ifdef GERMAN
	.string "Oh, gut.\n"
	.string "Komm bald wieder.$"
	.endif
	.endif

Route117_PokemonDayCare_Text_NotEnoughMoney:
	.ifdef ENGLISH
	.string "You don't have enough money…$"
	.else
	.ifdef GERMAN
	.string "Du hast nicht genug Geld…$"
	.endif
	.endif

Route117_PokemonDayCare_Text_TakeOtherOneBackToo:
	.ifdef ENGLISH
	.string "Will you take back the other one,\n"
	.string "too?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du das andere auch wieder\n"
	.string "mitnehmen?$"
	.endif
	.endif

Route117_PokemonDayCare_Text_ComeAgain:
	.ifdef ENGLISH
	.string "Fine.\n"
	.string "Come again.$"
	.else
	.ifdef GERMAN
	.string "Gut.\n"
	.string "Komm bald wieder.$"
	.endif
	.endif

Route117_PokemonDayCare_Text_GoodToSeeYou:
	.ifdef ENGLISH
	.string "Ah, it's you! Good to see you.\n"
	.string "Your POKéMON can only be doing good!$"
	.else
	.ifdef GERMAN
	.string "Ach, du bist es! Schön, dich zu sehen.\n"
	.string "Deinen POKéMON kann es einfach\l"
	.string "nur gut gehen!$"
	.endif
	.endif

Route117_PokemonDayCare_Text_YourMonHasGrownXLevels:
	.ifdef ENGLISH
	.string "By level, your {STR_VAR_1} has\n"
	.string "grown by {STR_VAR_2}.$"
	.else
	.ifdef GERMAN
	.string "Dein {STR_VAR_1} ist um {STR_VAR_2} Level\n"
	.string "gewachsen.$"
	.endif
	.endif

Route117_PokemonDayCare_Text_YourTeamIsFull:
	.ifdef ENGLISH
	.string "Your POKéMON team is full.\n"
	.string "Make room, then come see me.$"
	.else
	.ifdef GERMAN
	.string "Dein POKéMON-Team ist vollzählig.\n"
	.string "Schaffe Platz und komm dann wieder.$"
	.endif
	.endif

@ Unused
Route117_PokemonDayCare_Text_TakeBackWhichMon:
	.ifdef ENGLISH
	.string "Which POKéMON will you take back?$"
	.else
	.ifdef GERMAN
	.string "Which POKéMON will you take back?$"
	.endif
	.endif

Route117_PokemonDayCare_Text_ItWillCostX:
	.ifdef ENGLISH
	.string "If you want your {STR_VAR_1} back,\n"
	.string "it will cost ¥{STR_VAR_2}.$"
	.else
	.ifdef GERMAN
	.string "Wenn du dein {STR_VAR_1}\n"
	.string "mitnehmen willst, kostet das ¥{STR_VAR_2}.$"
	.endif
	.endif

Route117_PokemonDayCare_Text_HeresYourMon:
	.ifdef ENGLISH
	.string "Perfect!\n"
	.string "Here's your POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Sehr schön!\n"
	.string "Hier ist dein POKéMON!$"
	.endif
	.endif

Route117_PokemonDayCare_Text_TookBackMon:
	.ifdef ENGLISH
	.string "{PLAYER} took back {STR_VAR_1} from\n"
	.string "the DAY-CARE LADY.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} hat {STR_VAR_1} von der\n"
	.string "PENSIONSLEITERIN zurückerhalten.$"
	.endif
	.endif

Route117_PokemonDayCare_Text_YouHaveJustOneMon:
	.ifdef ENGLISH
	.string "Oh? But you have just one\n"
	.string "POKéMON.\p"
	.string "Come back another time.$"
	.else
	.ifdef GERMAN
	.string "Oh! Du hast aber nur ein POKéMON.\p"
	.string "Komm einfach später wieder.$"
	.endif
	.endif

Route117_PokemonDayCare_Text_TakeYourMonBack:
	.ifdef ENGLISH
	.string "Will you take your POKéMON back?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du dein POKéMON wieder\n"
	.string "mitnehmen?$"
	.endif
	.endif

Route117_PokemonDayCare_Text_WhatWillYouBattleWith:
	.ifdef ENGLISH
	.string "If you leave me that POKéMON,\n"
	.string "what will you battle with?\p"
	.string "Come back another time.$"
	.else
	.ifdef GERMAN
	.string "Wenn du das POKéMON hier lässt, womit\n"
	.string "willst du denn dann kämpfen?\p"
	.string "Komm einfach später wieder.$"
	.endif
	.endif

Text_EggHatchHuh:
	.ifdef ENGLISH
	.string "Huh?$"
	.else
	.ifdef GERMAN
	.string "Wie?$"
	.endif
	.endif

Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne:
	.ifdef ENGLISH
	.string "Huh?\n"
	.string "Now, now.\p"
	.string "If you leave that POKéMON with\n"
	.string "me, you'll be left with just one.\p"
	.string "You will be better off if you catch\n"
	.string "some more, I dare say.$"
	.else
	.ifdef GERMAN
	.string "Bitte?\n"
	.string "Aber, aber…\p"
	.string "Wenn du das POKéMON bei mir lässt, dann\n"
	.string "hast du ja nur noch ein einziges bei dir!\p"
	.string "Fang doch einfach ein paar POKéMON,\n"
	.string "dann sehen wir weiter.$"
	.endif
	.endif
