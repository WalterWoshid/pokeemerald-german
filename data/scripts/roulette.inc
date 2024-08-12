Roulette_EventScript_Table1::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Table2::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Play::
	special PlayRoulette
	waitstate
	end

Roulette_Text_PlayMinimumWagerIsX::
	.ifdef ENGLISH
	.string "The minimum wager at this table\n"
	.string "is {STR_VAR_1}. Do you want to play?$"
	.else
	.ifdef GERMAN
	.string "Der Einsatz an diesem Tisch ist\n"
	.string "{STR_VAR_1}. Möchtest du spielen?$"
	.endif
	.endif

Roulette_Text_NotEnoughCoins::
	.ifdef ENGLISH
	.string "You don't have enough COINS.$"
	.else
	.ifdef GERMAN
	.string "Du hast nicht genug MÜNZEn.$"
	.endif
	.endif

Roulette_Text_SpecialRateTable::
	.ifdef ENGLISH
	.string "Special rate table right now!$"
	.else
	.ifdef GERMAN
	.string "Und nun eine Bonusrunde!$"
	.endif
	.endif

Roulette_Text_ControlsInstruction::
	.ifdef ENGLISH
	.string "Place your wager with the + Control\n"
	.string "Pad, then press the A Button.$"
	.else
	.ifdef GERMAN
	.string "Mache den Einsatz mit dem Steuer-\n"
	.string "kreuz und drücke dann den A-Knopf.$"
	.endif
	.endif

Roulette_Text_ItsAHit::
	.ifdef ENGLISH
	.string "It's a hit!$"
	.else
	.ifdef GERMAN
	.string "Ein Treffer!$"
	.endif
	.endif

Roulette_Text_Jackpot::
	.ifdef ENGLISH
	.string "Jackpot!$"
	.else
	.ifdef GERMAN
	.string "Jackpot!$"
	.endif
	.endif

Roulette_Text_NothingDoing::
	.ifdef ENGLISH
	.string "Nothing doing!$"
	.else
	.ifdef GERMAN
	.string "Das war nichts!$"
	.endif
	.endif

Roulette_Text_YouveWonXCoins::
	.ifdef ENGLISH
	.string "You've won {STR_VAR_1} COINS!$"
	.else
	.ifdef GERMAN
	.string "Du hast {STR_VAR_1} MÜNZEn gewonnen!$"
	.endif
	.endif

Roulette_Text_NoCoinsLeft::
	.ifdef ENGLISH
	.string "No COINS left…$"
	.else
	.ifdef GERMAN
	.string "Nicht mehr genug MÜNZEn übrig…$"
	.endif
	.endif

Roulette_Text_KeepPlaying::
	.ifdef ENGLISH
	.string "Keep playing?$"
	.else
	.ifdef GERMAN
	.string "Weiterspielen?$"
	.endif
	.endif

Roulette_Text_BoardWillBeCleared::
	.ifdef ENGLISH
	.string "The ROULETTE board will be cleared.$"
	.else
	.ifdef GERMAN
	.string "Der ROULETTE-Tisch wird abgeräumt.$"
	.endif
	.endif

@ Unused
Roulette_Text_YouDontHaveACoinCase::
	.ifdef ENGLISH
	.string "You don't have a COIN CASE.$"
	.else
	.ifdef GERMAN
	.string "You don’t have a COIN CASE.$"
	.endif
	.endif

Roulette_Text_CoinCaseIsFull::
	.ifdef ENGLISH
	.string "Your COIN CASE is full!\n"
	.string "Coins can be exchanged for prizes.$"
	.else
	.ifdef GERMAN
	.string "Dein MÜNZKORB ist voll! MÜNZEn können\n"
	.string "gegen Preise eingetauscht werden.$"
	.endif
	.endif
