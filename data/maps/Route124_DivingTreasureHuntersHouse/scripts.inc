Route124_DivingTreasureHuntersHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route124_DivingTreasureHuntersHouse_OnTransition
	.byte 0

Route124_DivingTreasureHuntersHouse_OnTransition:
	setflag FLAG_LANDMARK_HUNTERS_HOUSE
	end

Route124_DivingTreasureHuntersHouse_EventScript_TreasureHunter::
	lock
	faceplayer
	goto_if_set FLAG_MET_DIVING_TREASURE_HUNTER, Route124_DivingTreasureHuntersHouse_EventScript_SkipGreeting
	msgbox Route124_DivingTreasureHuntersHouse_Text_Greeting, MSGBOX_DEFAULT
	setflag FLAG_MET_DIVING_TREASURE_HUNTER
	goto Route124_DivingTreasureHuntersHouse_EventScript_CheckPlayerHasShard
	end

Route124_DivingTreasureHuntersHouse_EventScript_SkipGreeting::
	msgbox Route124_DivingTreasureHuntersHouse_Text_HaveYouSeenAnyShards, MSGBOX_DEFAULT
	goto Route124_DivingTreasureHuntersHouse_EventScript_CheckPlayerHasShard
	end

Route124_DivingTreasureHuntersHouse_EventScript_CheckPlayerHasShard::
	call Route124_DivingTreasureHuntersHouse_EventScript_GetPlayersShards
	goto_if_eq VAR_TEMP_1, 0, Route124_DivingTreasureHuntersHouse_EventScript_NoShards
	goto Route124_DivingTreasureHuntersHouse_EventScript_HasShard
	end

Route124_DivingTreasureHuntersHouse_EventScript_GetPlayersShards::
	setvar VAR_TEMP_1, 0
	checkitem ITEM_RED_SHARD
	call_if_eq VAR_RESULT, TRUE, Route124_DivingTreasureHuntersHouse_EventScript_HasRedShard
	checkitem ITEM_YELLOW_SHARD
	call_if_eq VAR_RESULT, TRUE, Route124_DivingTreasureHuntersHouse_EventScript_HasYellowShard
	checkitem ITEM_BLUE_SHARD
	call_if_eq VAR_RESULT, TRUE, Route124_DivingTreasureHuntersHouse_EventScript_HasBlueShard
	checkitem ITEM_GREEN_SHARD
	call_if_eq VAR_RESULT, TRUE, Route124_DivingTreasureHuntersHouse_EventScript_HasGreenShard
	return

Route124_DivingTreasureHuntersHouse_EventScript_HasRedShard::
	addvar VAR_TEMP_1, 1
	return

Route124_DivingTreasureHuntersHouse_EventScript_HasYellowShard::
	addvar VAR_TEMP_1, 2
	return

Route124_DivingTreasureHuntersHouse_EventScript_HasBlueShard::
	addvar VAR_TEMP_1, 4
	return

Route124_DivingTreasureHuntersHouse_EventScript_HasGreenShard::
	addvar VAR_TEMP_1, 8
	return

Route124_DivingTreasureHuntersHouse_EventScript_HasShard::
	msgbox Route124_DivingTreasureHuntersHouse_Text_ThatsAShardIllTradeYou, MSGBOX_DEFAULT
	goto Route124_DivingTreasureHuntersHouse_EventScript_ShowTradeOptions
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShowTradeOptions::
	message Route124_DivingTreasureHuntersHouse_Text_WhatDoYouWantToTrade
	waitmessage
	switch VAR_TEMP_1
	case 1,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsR
	case 2,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsY
	case 3,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRY
	case 4,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsB
	case 5,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRB
	case 6,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYB
	case 7,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYB
	case 8,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsG
	case 9,  Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRG
	case 10, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYG
	case 11, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYG
	case 12, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsBG
	case 13, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRBG
	case 14, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYBG
	case 15, Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYBG
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsR::
	multichoice 0, 0, MULTI_SHARDS_R, FALSE
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsY::
	multichoice 0, 0, MULTI_SHARDS_Y, FALSE
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRY::
	multichoice 0, 0, MULTI_SHARDS_RY, FALSE
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsB::
	multichoice 0, 0, MULTI_SHARDS_B, FALSE
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRB::
	multichoice 0, 0, MULTI_SHARDS_RB, FALSE
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYB::
	multichoice 0, 0, MULTI_SHARDS_YB, FALSE
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYB::
	multichoice 0, 0, MULTI_SHARDS_RYB, FALSE
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsG::
	multichoice 0, 0, MULTI_SHARDS_G, FALSE
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRG::
	multichoice 0, 0, MULTI_SHARDS_RG, FALSE
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYG::
	multichoice 0, 0, MULTI_SHARDS_YG, FALSE
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYG::
	multichoice 0, 0, MULTI_SHARDS_RYG, FALSE
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsBG::
	multichoice 0, 0, MULTI_SHARDS_BG, FALSE
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRBG::
	multichoice 0, 0, MULTI_SHARDS_RBG, FALSE
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsYBG::
	multichoice 0, 0, MULTI_SHARDS_YBG, FALSE
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardOptionsRYBG::
	multichoice 0, 0, MULTI_SHARDS_RYBG, FALSE
	switch VAR_RESULT
	case 0, Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard
	case 1, Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard
	case 2, Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard
	case 3, Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard
	case 4, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_TradeRedShard::
	setvar VAR_0x8008, ITEM_RED_SHARD
	setvar VAR_0x8009, ITEM_FIRE_STONE
	goto Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard

Route124_DivingTreasureHuntersHouse_EventScript_TradeYellowShard::
	setvar VAR_0x8008, ITEM_YELLOW_SHARD
	setvar VAR_0x8009, ITEM_THUNDER_STONE
	goto Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard

Route124_DivingTreasureHuntersHouse_EventScript_TradeBlueShard::
	setvar VAR_0x8008, ITEM_BLUE_SHARD
	setvar VAR_0x8009, ITEM_WATER_STONE
	goto Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard

Route124_DivingTreasureHuntersHouse_EventScript_TradeGreenShard::
	setvar VAR_0x8008, ITEM_GREEN_SHARD
	setvar VAR_0x8009, ITEM_LEAF_STONE
	goto Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard

Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard::
	bufferitemname STR_VAR_1, VAR_0x8008
	bufferitemname STR_VAR_2, VAR_0x8009
	msgbox Route124_DivingTreasureHuntersHouse_Text_YoullTradeShardForStone, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, TRUE, Route124_DivingTreasureHuntersHouse_EventScript_TradeShard
	checkitem VAR_0x8008, 2
	goto_if_eq VAR_RESULT, FALSE, Route124_DivingTreasureHuntersHouse_EventScript_TradeShard
	goto Route124_DivingTreasureHuntersHouse_EventScript_BagFull
	end

Route124_DivingTreasureHuntersHouse_EventScript_TradeShard::
	removeitem VAR_0x8008
	giveitem VAR_0x8009
	msgbox Route124_DivingTreasureHuntersHouse_Text_ItsADeal, MSGBOX_DEFAULT
	call Route124_DivingTreasureHuntersHouse_EventScript_GetPlayersShards
	goto_if_eq VAR_TEMP_1, 0, Route124_DivingTreasureHuntersHouse_EventScript_EndTrade
	msgbox Route124_DivingTreasureHuntersHouse_Text_TradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route124_DivingTreasureHuntersHouse_EventScript_ShowTradeOptions
	goto Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade
	end

Route124_DivingTreasureHuntersHouse_EventScript_BagFull::
	msgbox Route124_DivingTreasureHuntersHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route124_DivingTreasureHuntersHouse_EventScript_DeclineTrade::
	msgbox Route124_DivingTreasureHuntersHouse_Text_ComeBackIfYouChangeMind, MSGBOX_DEFAULT
	release
	end

Route124_DivingTreasureHuntersHouse_EventScript_NoShards::
	msgbox Route124_DivingTreasureHuntersHouse_Text_YouHaventGotAnyShards, MSGBOX_DEFAULT
	release
	end

Route124_DivingTreasureHuntersHouse_EventScript_EndTrade::
	release
	end

Route124_DivingTreasureHuntersHouse_EventScript_ShardTradeBoard::
	msgbox Route124_DivingTreasureHuntersHouse_Text_ShardTradeBoard, MSGBOX_SIGN
	end

Route124_DivingTreasureHuntersHouse_Text_Greeting:
	.ifdef ENGLISH
	.string "I'm the DIVING TREASURE HUNTER!\p"
	.string "I'm the awesome dude who makes\n"
	.string "deep-sea dives to gather treasures\l"
	.string "resting at the bottom.$"
	.else
	.ifdef GERMAN
	.string "Ich bin der SCHATZTAUCHER!\p"
	.string "Ich bin der Typ, der in der Tiefsee\n"
	.string "taucht und nach Schätzen am Meeres-\l"
	.string "grund sucht.$"
	.endif
	.endif

Route124_DivingTreasureHuntersHouse_Text_HaveYouSeenAnyShards:
	.ifdef ENGLISH
	.string "Tell me, have you seen any SHARDS of\n"
	.string "tools made in ancient times?$"
	.else
	.ifdef GERMAN
	.string "Sag, hast du SCHERBEn antiker\n"
	.string "Werkzeuge gesehen?$"
	.endif
	.endif

Route124_DivingTreasureHuntersHouse_Text_YouHaventGotAnyShards:
	.ifdef ENGLISH
	.string "You haven't got any treasures\n"
	.string "for me…\p"
	.string "If you see any SHARDS, like the RED\n"
	.string "SHARD, you've got to trade it with me!$"
	.else
	.ifdef GERMAN
	.string "Du hast keinerlei Schätze für mich…\p"
	.string "Wenn du Stücke findest, besonders\n"
	.string "PURPURSTÜCKE, tausche sie mit mir!$"
	.endif
	.endif

Route124_DivingTreasureHuntersHouse_Text_ThatsAShardIllTradeYou:
	.ifdef ENGLISH
	.string "Oh, hey! That…\n"
	.string "That's a SHARD! I'm looking for those!\p"
	.string "Oh, man, you've got to trade that\n"
	.string "with me! I'll give you something good!$"
	.else
	.ifdef GERMAN
	.string "Oh, hey! Das… Das ist eine\n"
	.string "Scherbe! Genau die suche ich!\p"
	.string "Oh, du musst unbedingt mit mir\n"
	.string "tauschen! Ich gebe dir etwas\l"
	.string "Gutes dafür!$"
	.endif
	.endif

Route124_DivingTreasureHuntersHouse_Text_WhatDoYouWantToTrade:
	.ifdef ENGLISH
	.string "What do you want to trade?$"
	.else
	.ifdef GERMAN
	.string "Was möchtest du tauschen?$"
	.endif
	.endif

Route124_DivingTreasureHuntersHouse_Text_YoullTradeShardForStone:
	.ifdef ENGLISH
	.string "You'll trade your {STR_VAR_1} for\n"
	.string "my {STR_VAR_2}, then?$"
	.else
	.ifdef GERMAN
	.string "Du tauschst: {STR_VAR_1} gegen\n"
	.string "{STR_VAR_2}?$"
	.endif
	.endif

Route124_DivingTreasureHuntersHouse_Text_ItsADeal:
	.ifdef ENGLISH
	.string "It's a done deal!\n"
	.string "Use that wisely!$"
	.else
	.ifdef GERMAN
	.string "Das ist ein guter Tausch!\n"
	.string "Setze es wohl überlegt ein!$"
	.endif
	.endif

Route124_DivingTreasureHuntersHouse_Text_TradeSomethingElse:
	.ifdef ENGLISH
	.string "Do you want to trade something else?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du noch etwas tauschen?$"
	.endif
	.endif

Route124_DivingTreasureHuntersHouse_Text_BagFull:
	.ifdef ENGLISH
	.string "Whoops, your BAG's full.\n"
	.string "Get rid of some items, friend!$"
	.else
	.ifdef GERMAN
	.string "Hups, dein BEUTEL ist voll.\n"
	.string "Schaffe Platz, mein Freund!$"
	.endif
	.endif

Route124_DivingTreasureHuntersHouse_Text_ComeBackIfYouChangeMind:
	.ifdef ENGLISH
	.string "No? That's a downer.\n"
	.string "Well, if you change your mind, come back.$"
	.else
	.ifdef GERMAN
	.string "Nein? Das ist niederschmetternd.\n"
	.string "Wenn du deine Meinung änderst, ich\l"
	.string "bin hier!$"
	.endif
	.endif

Route124_DivingTreasureHuntersHouse_Text_ShardTradeBoard:
	.ifdef ENGLISH
	.string "{CLEAR_TO 0x0a}Wanted item{CLEAR_TO 0x7c}Trade item\n"
	.string "{CLEAR_TO 0x0f}RED SHARD{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x7b}FIRE STONE{CLEAR_TO 0xc8}\p"
	.string "{CLEAR_TO 0x0a}Wanted item{CLEAR_TO 0x7c}Trade item\n"
	.string "{CLEAR_TO 0x06}YELLOW SHARD{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x73}THUNDERSTONE{CLEAR_TO 0xc8}\p"
	.string "{CLEAR_TO 0x0a}Wanted item{CLEAR_TO 0x7c}Trade item\n"
	.string "{CLEAR_TO 0x0c}BLUE SHARD{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x79}WATER STONE{CLEAR_TO 0xc8}\p"
	.string "{CLEAR_TO 0x0a}Wanted item{CLEAR_TO 0x7c}Trade item\n"
	.string "{CLEAR_TO 0x08}GREEN SHARD{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x7b}LEAF STONE$"
	.else
	.ifdef GERMAN
	.string "{CLEAR_TO 0x03}Gesuchtes Item{CLEAR_TO 0x6a}Item zum Tausch\n"
	.string "{CLEAR_TO 0x0b}PURPURSTÜCK{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x76}FEUERSTEIN{CLEAR_TO 0xc8}\p"
	.string "{CLEAR_TO 0x03}Gesuchtes Item{CLEAR_TO 0x6a}Item zum Tausch\n"
	.string "{CLEAR_TO 0x11}GELBSTÜCK{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x73}DONNERSTEIN{CLEAR_TO 0xc8}\p"
	.string "{CLEAR_TO 0x03}Gesuchtes Item{CLEAR_TO 0x6a}Item zum Tausch\n"
	.string "{CLEAR_TO 0x0b}INDIGOSTÜCK{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x73}WASSERSTEIN{CLEAR_TO 0xc8}\p"
	.string "{CLEAR_TO 0x03}Gesuchtes Item{CLEAR_TO 0x6a}Item zum Tausch\n"
	.string "{CLEAR_TO 0x11}JADESTÜCK{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x76}BLATTSTEIN$"
	.endif
	.endif
