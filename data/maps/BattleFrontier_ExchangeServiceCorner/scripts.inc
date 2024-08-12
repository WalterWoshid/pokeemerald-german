BattleFrontier_ExchangeServiceCorner_MapScripts::
	.byte 0

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize::
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor::
	checkdecorspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	adddecoration VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_BagFull
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	additem VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BagFull::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissPoster, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, DECOR_KISS_POSTER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissCushion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_KISS_CUSHION
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSmoochumDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_SMOOCHUM_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTogepiDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_TOGEPI_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMeowthDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_MEOWTH_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmClefairyDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_CLEFAIRY_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmDittoDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_DITTO_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CYNDAQUIL_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChikoritaDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CHIKORITA_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTotodileDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_TOTODILE_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaprasDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_LAPRAS_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_SNORLAX_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmVenusaurDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_VENUSAUR_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCharizardDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_CHARIZARD_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_BLASTOISE_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Protein
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_Calcium
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_Iron
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_Zinc
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Carbos
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_HPUp
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Protein::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmProtein, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_PROTEIN
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Calcium::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalcium, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CALCIUM
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Iron::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmIron, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_IRON
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Zinc::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmZinc, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_ZINC
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Carbos::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarbos, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CARBOS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HPUp::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPUp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_HP_UP
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LEFTOVERS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_WHITE_HERB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_QUICK_CLAW
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_MENTAL_HERB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_BRIGHT_POWDER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_CHOICE_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_KINGS_ROCK
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_FOCUS_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_SCOPE_LENS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Man::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Sailor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Girl::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.ifdef ENGLISH
	.string "Hello, this is the EXCHANGE SERVICE\n"
	.string "CORNER.\p"
	.string "We exchange the Battle Points you\n"
	.string "have collected for lovely prizes.\p"
	.string "Please choose a prize from this list.$"
	.else
	.ifdef GERMAN
	.string "Hallo, dies ist die TAUSCHECKE.\p"
	.string "Wir tauschen deine Gewinnpunkte gegen\n"
	.string "großartige Preise ein.\p"
	.string "Bitte such dir einen Preis von dieser\n"
	.string "Liste aus.$"
	.endif
	.endif

@ Unused
BattleFrontier_ExchangeServiceCorner_Text_PleaseChoosePrize:
	.ifdef ENGLISH
	.string "Please choose a prize from this list.$"
	.else
	.ifdef GERMAN
	.string "Please choose a prize from this list.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissPoster:
	.ifdef ENGLISH
	.string "You've chosen the KISS POSTER.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest das KUSS-POSTER\n"
	.string "haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissCushion:
	.ifdef ENGLISH
	.string "You've chosen the KISS CUSHION.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest das KUSS-KISSEN\n"
	.string "haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSmoochumDoll:
	.ifdef ENGLISH
	.string "You've chosen the SMOOCHUM DOLL.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest die KUSSILLA-PUPPE\n"
	.string "haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmTogepiDoll:
	.ifdef ENGLISH
	.string "You've chosen the TOGEPI DOLL.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest die TOGEPI-PUPPE\n"
	.string "haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMeowthDoll:
	.ifdef ENGLISH
	.string "You've chosen the MEOWTH DOLL.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest die MAUZI-PUPPE\n"
	.string "haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmClefairyDoll:
	.ifdef ENGLISH
	.string "You've chosen the CLEFAIRY DOLL.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest die PIEPI-PUPPE\n"
	.string "haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmDittoDoll:
	.ifdef ENGLISH
	.string "You've chosen the DITTO DOLL.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest die DITTO-PUPPE\n"
	.string "haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll:
	.ifdef ENGLISH
	.string "You've chosen the CYNDAQUIL DOLL.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest die FEURIGEL-PUPPE\n"
	.string "haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChikoritaDoll:
	.ifdef ENGLISH
	.string "You've chosen the CHIKORITA DOLL.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest die ENDIVIE-PUPPE\n"
	.string "haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmTotodileDoll:
	.ifdef ENGLISH
	.string "You've chosen the TOTODILE DOLL.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest die KARNIMANI-PUPPE\n"
	.string "haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaprasDoll:
	.ifdef ENGLISH
	.string "You've chosen the LAPRAS DOLL.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest die LAPRAS-PUPPE\n"
	.string "haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll:
	.ifdef ENGLISH
	.string "You've chosen the SNORLAX DOLL.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest die RELAXO-PUPPE\n"
	.string "haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmVenusaurDoll:
	.ifdef ENGLISH
	.string "You've chosen the VENUSAUR DOLL.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest die BISAFLOR-PUPPE\n"
	.string "haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCharizardDoll:
	.ifdef ENGLISH
	.string "You've chosen the CHARIZARD DOLL.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest die GLURAK-PUPPE\n"
	.string "haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll:
	.ifdef ENGLISH
	.string "You've chosen the BLASTOISE DOLL.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest die TURTOK-PUPPE\n"
	.string "haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmProtein:
	.ifdef ENGLISH
	.string "You've chosen the PROTEIN.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest das PROTEIN haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalcium:
	.ifdef ENGLISH
	.string "You've chosen the CALCIUM.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest das KALZIUM haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmIron:
	.ifdef ENGLISH
	.string "You've chosen the IRON.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest das EISEN haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmZinc:
	.ifdef ENGLISH
	.string "You've chosen the ZINC.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest das ZINK haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarbos:
	.ifdef ENGLISH
	.string "You've chosen the CARBOS.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest das CARBON haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPUp:
	.ifdef ENGLISH
	.string "You've chosen the HP UP.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest das KP-PLUS haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder:
	.ifdef ENGLISH
	.string "You've chosen the BRIGHTPOWDER.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest das BLENDPUDER haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb:
	.ifdef ENGLISH
	.string "You've chosen the WHITE HERB.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest das SCHLOHKRAUT haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw:
	.ifdef ENGLISH
	.string "You've chosen the QUICK CLAW.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest die FLINKKLAUE haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb:
	.ifdef ENGLISH
	.string "You've chosen the MENTAL HERB.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest das MENTALKRAUT haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand:
	.ifdef ENGLISH
	.string "You've chosen the CHOICE BAND.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest das WAHLBAND haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock:
	.ifdef ENGLISH
	.string "You've chosen the KING'S ROCK.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest den KING-STEIN haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand:
	.ifdef ENGLISH
	.string "You've chosen the FOCUS BAND.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest das FOKUS-BAND haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens:
	.ifdef ENGLISH
	.string "You've chosen the SCOPE LENS.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest die SCOPE-LINSE haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers:
	.ifdef ENGLISH
	.string "You've chosen the LEFTOVERS.\n"
	.string "Is that correct?$"
	.else
	.ifdef GERMAN
	.string "Du möchtest die ÜBERRESTE haben?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC:
	.ifdef ENGLISH
	.string "Thank you!\n"
	.string "We'll send it to your PC at home.$"
	.else
	.ifdef GERMAN
	.string "Danke!\n"
	.string "Wir senden das auf deinen PC.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize:
	.ifdef ENGLISH
	.string "Here is your prize!$"
	.else
	.ifdef GERMAN
	.string "Bitte, hier ist dein Preis.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.ifdef ENGLISH
	.string "I'm so sorry…\n"
	.string "You don't have enough Battle Points…$"
	.else
	.ifdef GERMAN
	.string "Es tut mir sehr Leid… Aber\n"
	.string "du hast nicht genug Gewinnpunkte…$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_PCIsFull:
	.ifdef ENGLISH
	.string "I'm so sorry…\n"
	.string "Your PC appears to be full…$"
	.else
	.ifdef GERMAN
	.string "Es tut mir sehr Leid…\n"
	.string "Aber dein PC ist voll…$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
	.ifdef ENGLISH
	.string "I'm so sorry…\n"
	.string "You don't have space to hold it…$"
	.else
	.ifdef GERMAN
	.string "Es tut mir sehr Leid…\n"
	.string "Aber du hast keinen Platz dafür…$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.ifdef ENGLISH
	.string "Thank you very much.\p"
	.string "Please visit us when you have\n"
	.string "saved up Battle Points.$"
	.else
	.ifdef GERMAN
	.string "Vielen Dank.\p"
	.string "Bitte komm wieder, wenn du \n"
	.string "dich entschieden hast.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.ifdef ENGLISH
	.string "Oh, they're so nice!\n"
	.string "I wish I had them!\l"
	.string "Cute cushions!\l"
	.string "Big plush DOLLS!\l"
	.string "Little plush DOLLS!\l"
	.string "I wish I had them all!$"
	.else
	.ifdef GERMAN
	.string "Oh, die sind so hübsch.\n"
	.string "Die hätte ich auch gerne!\l"
	.string "Niedliche Kissen!\l"
	.string "Große, fluffige PUPPEn!\l"
	.string "Kleine, fluffige PUPPEn!\l"
	.string "Ich würde sie am liebsten alle nehmen!$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.ifdef ENGLISH
	.string "Leave it to your mommy!\p"
	.string "If it's anything you want, I'll go\n"
	.string "through anything to get it, honey!$"
	.else
	.ifdef GERMAN
	.string "Überlass das deiner Mami!\p"
	.string "Möchtest du irgendetwas haben, werde\n"
	.string "ich alles tun, damit du es bekommst.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.ifdef ENGLISH
	.string "If I can get hold of the items here,\n"
	.string "my POKéMON will get tougher.\p"
	.string "You bet they will!\n"
	.string "No question about it!$"
	.else
	.ifdef GERMAN
	.string "Hätte ich nur eines dieser Items hier,\n"
	.string "würden meine POKéMON viel stärker!\p"
	.string "Mit Sicherheit! Darauf kannst du\n"
	.string "wetten! Das steht fest!$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.ifdef ENGLISH
	.string "Hah?\n"
	.string "What are you gawking at?\p"
	.string "I don't like you staring at my plush\n"
	.string "doll like that.\p"
	.string "If you want it, go get one yourself!\n"
	.string "Isn't that right, SMOOCHUM?$"
	.else
	.ifdef GERMAN
	.string "Häh?\n"
	.string "Was glotzt du denn so doof?\p"
	.string "Ich mag es nicht, wie du meine\n"
	.string "Plüschpuppe anstarrst!\p"
	.string "Wenn du auch so eine haben willst,\n"
	.string "besorg dir eine! Nicht wahr, KUSSILLA?$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.ifdef ENGLISH
	.string "Did you know?\p"
	.string "If you stretch your record at any of\n"
	.string "the BATTLE facilities, they start\l"
	.string "giving you more and more Battle Points.$"
	.else
	.ifdef GERMAN
	.string "Weißt du was?\n"
	.string "Wenn du deine Ergebnisse hier in den\p"
	.string "KAMPF-Einrichtungen stetig\n"
	.string "verbesserst, geben sie dir mehr\l"
	.string "Gewinnpunkte.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_KissPosterDesc::
	.ifdef ENGLISH
	.string "A large poster with a SMOOCHUM print.$"
	.else
	.ifdef GERMAN
	.string "Ein großes Poster von KUSSILLA.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_KissCushionDesc::
	.ifdef ENGLISH
	.string "A SMOOCHUM cushion.\n"
	.string "Place it on a mat or a desk.$"
	.else
	.ifdef GERMAN
	.string "KUSSILLA-Kissen.\n"
	.string "Für eine Matte oder den Tisch.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_SmoochumDollDesc::
	.ifdef ENGLISH
	.string "A SMOOCHUM DOLL.\n"
	.string "Place it on a mat or a desk.$"
	.else
	.ifdef GERMAN
	.string "KUSSILLA-PUPPE.\n"
	.string "Für eine Matte oder den Tisch.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_TogepiDollDesc::
	.ifdef ENGLISH
	.string "A TOGEPI DOLL.\n"
	.string "Place it on a mat or a desk.$"
	.else
	.ifdef GERMAN
	.string "TOGEPI-PUPPE. Leg sie auf eine Matte\n"
	.string "oder einen Tisch.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_MeowthDollDesc::
	.ifdef ENGLISH
	.string "A MEOWTH DOLL.\n"
	.string "Place it on a mat or a desk.$"
	.else
	.ifdef GERMAN
	.string "MAUZI-PUPPE. Leg sie auf eine Matte\n"
	.string "oder einen Tisch.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ClefairyDollDesc::
	.ifdef ENGLISH
	.string "A CLEFAIRY DOLL.\n"
	.string "Place it on a mat or a desk.$"
	.else
	.ifdef GERMAN
	.string "PIEPI-PUPPE. Leg sie auf eine Matte\n"
	.string "oder einen Tisch.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_DittoDollDesc::
	.ifdef ENGLISH
	.string "A DITTO DOLL.\n"
	.string "Place it on a mat or a desk.$"
	.else
	.ifdef GERMAN
	.string "DITTO-PUPPE. Leg sie auf eine Matte\n"
	.string "oder einen Tisch.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_CyndaquilDollDesc::
	.ifdef ENGLISH
	.string "A CYNDAQUIL DOLL.\n"
	.string "Place it on a mat or a desk.$"
	.else
	.ifdef GERMAN
	.string "FEURIGEL-PUPPE.\n"
	.string "Für eine Matte oder den Tisch.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ChikoritaDollDesc::
	.ifdef ENGLISH
	.string "A CHIKORITA DOLL.\n"
	.string "Place it on a mat or a desk.$"
	.else
	.ifdef GERMAN
	.string "ENDIVIE-PUPPE. Leg sie auf eine Matte\n"
	.string "oder einen Tisch.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_TotodileDollDesc::
	.ifdef ENGLISH
	.string "A TOTODILE DOLL.\n"
	.string "Place it on a mat or a desk.$"
	.else
	.ifdef GERMAN
	.string "KARNIMANI-PUPPE.\n"
	.string "Für eine Matte oder den Tisch.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc::
	.ifdef ENGLISH
	.string "A large DOLL.\n"
	.string "Place it on a mat or a desk.$"
	.else
	.ifdef GERMAN
	.string "Große PUPPE. Leg sie auf eine Matte\n"
	.string "oder den Tisch.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ProteinDesc::
	.ifdef ENGLISH
	.string "Raises the stat ATTACK of one\n"
	.string "POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Hebt den ANGR.-Wert eines POKéMON.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_CalciumDesc::
	.ifdef ENGLISH
	.string "Raises the stat SP. ATK of one\n"
	.string "POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Hebt den SP. ANGR.-Wert eines POKéMON.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_IronDesc::
	.ifdef ENGLISH
	.string "Raises the stat DEFENSE of one\n"
	.string "POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Hebt den VERT.-Wert eines POKéMON.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ZincDesc::
	.ifdef ENGLISH
	.string "Raises the stat SP. DEF of one\n"
	.string "POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Hebt den SP. VERT.-Wert eines POKéMON.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_CarbosDesc::
	.ifdef ENGLISH
	.string "Raises the stat SPEED of one\n"
	.string "POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Hebt den INIT.-Wert eines POKéMON.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_HPUpDesc::
	.ifdef ENGLISH
	.string "Raises the HP of one POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Hebt die KP eines POKéMON.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc::
	.ifdef ENGLISH
	.string "A hold item that gradually restores\n"
	.string "HP in battle.$"
	.else
	.ifdef GERMAN
	.string "Item (Tragen) füllt im Kampf langsam\n"
	.string "KP wieder auf.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc::
	.ifdef ENGLISH
	.string "A hold item that restores any\n"
	.string "lowered stat.$"
	.else
	.ifdef GERMAN
	.string "Item (Tragen) hebt jede\n"
	.string "Statusveränderung auf.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc::
	.ifdef ENGLISH
	.string "A hold item that occasionally allows\n"
	.string "the first strike.$"
	.else
	.ifdef GERMAN
	.string "Item (Tragen) hebt die\n"
	.string "Erstschlagquote.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc::
	.ifdef ENGLISH
	.string "A hold item that snaps POKéMON out\n"
	.string "of infatuation.$"
	.else
	.ifdef GERMAN
	.string "Item (Tragen) erlöst POKéMON von der\n"
	.string "Anziehung.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc::
	.ifdef ENGLISH
	.string "A hold item that casts a glare to\n"
	.string "reduce accuracy.$"
	.else
	.ifdef GERMAN
	.string "Item (Tragen) senkt die Genauigkeit\n"
	.string "des Gegners.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc::
	.ifdef ENGLISH
	.string "Raises a move's power, but permits\n"
	.string "only that move.$"
	.else
	.ifdef GERMAN
	.string "Stärkt eine Attacke. Aber nur diese\n"
	.string "ist einsetzbar.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc::
	.ifdef ENGLISH
	.string "A hold item that may cause flinching\n"
	.string "when the foe is hit.$"
	.else
	.ifdef GERMAN
	.string "Item (Tragen) kann Gegner\n"
	.string "zurückweichen lassen.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc::
	.ifdef ENGLISH
	.string "A hold item that occasionally\n"
	.string "prevents fainting.$"
	.else
	.ifdef GERMAN
	.string "Item (Tragen) kann manchmal K.O.\n"
	.string "verhindern.$"
	.endif
	.endif

BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc::
	.ifdef ENGLISH
	.string "A hold item that raises the\n"
	.string "critical-hit rate.$"
	.else
	.ifdef GERMAN
	.string "Item (Tragen) erhöht die\n"
	.string "Volltrefferquote.$"
	.endif
	.endif
