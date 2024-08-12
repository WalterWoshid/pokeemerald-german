.set LOCALID_WOMAN_1, 19
.set LOCALID_MAN_1, 20

LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.ifdef ENGLISH
	.string "MAY: Oh, hey?\n"
	.string "{PLAYER}{KUN}, are you shopping, too?\p"
	.string "I bought a whole bunch of DOLLS and\n"
	.string "POSTERS.\p"
	.string "Of course, I've also caught a lot of\n"
	.string "POKéMON, and I'm raising them\l"
	.string "properly, too.\p"
	.string "Actually, I'm more worried if you're\n"
	.string "raising POKéMON properly, {PLAYER}{KUN}.\p"
	.string "I'll battle with you, so you can show\n"
	.string "me your POKéMON, {PLAYER}{KUN}.$"
	.else
	.ifdef GERMAN
	.string "MAIKE: Oh, hey?\n"
	.string "{PLAYER}{KUN}, bist du auch am Einkaufen?\p"
	.string "Ich habe eine Menge PUPPEn und POSTER\n"
	.string "gekauft.\p"
	.string "Natürlich habe ich auch POKéMON\n"
	.string "gefangen und die ziehe ich geradezu\l"
	.string "vorbildlich auf.\p"
	.string "Ich habe eher Bedenken, dass du dich um\n"
	.string "deine POKéMON nicht richtig kümmerst.\p"
	.string "Ich werde gegen dich kämpfen, dann\n"
	.string "sehe ich, ob du sie gut behandelst.$"
	.endif
	.endif

LilycoveCity_Text_MayNotRaisingPokemon:
	.ifdef ENGLISH
	.string "MAY: Oh, why? {PLAYER}{KUN}, haven't you\n"
	.string "been raising your POKéMON?\p"
	.string "That's not a very good showing as a\n"
	.string "TRAINER…$"
	.else
	.ifdef GERMAN
	.string "MAIKE: Oh, hui. Hast du dich denn nicht\n"
	.string "um deine POKéMON gekümmert, {PLAYER}{KUN}?\p"
	.string "Als Trainer machst du wirklich keinen\n"
	.string "guten Eindruck!$"
	.endif
	.endif

LilycoveCity_Text_MayBattleMe:
	.ifdef ENGLISH
	.string "MAY: Come on, battle with me, so I can\n"
	.string "check out your POKéMON!$"
	.else
	.ifdef GERMAN
	.string "MAIKE: Komm, kämpfe mit mir, dann kann\n"
	.string "ich deine POKéMON beurteilen.$"
	.endif
	.endif

LilycoveCity_Text_MayWontBeBeaten:
	.ifdef ENGLISH
	.string "MAY: The POKéMON I raised won't be\n"
	.string "beaten by your POKéMON, {PLAYER}{KUN}!$"
	.else
	.ifdef GERMAN
	.string "MAIKE: Die POKéMON, die ich aufgezogen\n"
	.string "habe, sind mit Sicherheit unbesiegbar.$"
	.endif
	.endif

LilycoveCity_Text_MayDefeat:
	.ifdef ENGLISH
	.string "… … … … … … … …\p"
	.string "I remember the battle I had with you,\n"
	.string "{PLAYER}{KUN}, on ROUTE 103.\p"
	.string "That battle helped you become this\n"
	.string "strong, {PLAYER}{KUN}, didn't it?$"
	.else
	.ifdef GERMAN
	.string "… … … … … … … …\p"
	.string "Ich kann mich noch gut an unseren\n"
	.string "Kampf auf der ROUTE 103 erinnern,\l"
	.string "{PLAYER}{KUN}.\p"
	.string "Dieser Kampf hat dir enorm geholfen,\n"
	.string "stärker zu werden, oder?$"
	.endif
	.endif

LilycoveCity_Text_MayGoingBackToLittleroot:
	.ifdef ENGLISH
	.string "MAY: I'm thinking of going back to\n"
	.string "LITTLEROOT soon.\p"
	.string "I've caught a decent group of POKéMON,\n"
	.string "and my POKéDEX is coming along, so\l"
	.string "I'm going home to show my dad.$"
	.else
	.ifdef GERMAN
	.string "MAIKE: Ich überlege, ob ich bald nach\n"
	.string "WURZELHEIM zurückgehe.\p"
	.string "Ich habe eine anständige Gruppe von\n"
	.string "POKéMON gefangen und mein POKéDEX\p"
	.string "sieht immer besser aus. Ich gehe nach\n"
	.string "Hause und zeige das meinem Papa.$"
	.endif
	.endif

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.ifdef ENGLISH
	.string "{PLAYER}{KUN}, what are you going to do?\p"
	.string "Collect all the GYM BADGES and take\n"
	.string "the POKéMON LEAGUE challenge?\p"
	.string "Well, while you're collecting BADGES,\n"
	.string "{PLAYER}{KUN}, I'm going to work on my\l"
	.string "POKéDEX. I'll complete it before you!\p"
	.string "See you!$"
	.else
	.ifdef GERMAN
	.string "{PLAYER}{KUN}, was wirst du machen?\p"
	.string "Alle ORDEN der ARENen sammeln und die\n"
	.string "POKéMON LIGA herausfordern?\p"
	.string "Nun, während du deine ORDEN sammelst,\n"
	.string "werde ich weiter an meinem POKéDEX\l"
	.string "arbeiten. Ich werde ihn eher\l"
	.string "vollständig haben als du, wetten?\p"
	.string "Bis dann!$"
	.endif
	.endif

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.ifdef ENGLISH
	.string "{PLAYER}{KUN}, what are you going to do?\p"
	.string "Are you taking the POKéMON LEAGUE\n"
	.string "challenge?\p"
	.string "Or, are you going to complete your\n"
	.string "POKéDEX?\p"
	.string "I might've lost to you in battling,\n"
	.string "but I'll finish my POKéDEX before you!\p"
	.string "See you!$"
	.else
	.ifdef GERMAN
	.string "Und, {PLAYER}{KUN}, was wirst du machen?\p"
	.string "Wirst du die POKéMON LIGA heraus-\n"
	.string "fordern?\p"
	.string "Oder wirst du deinen POKéDEX vervoll-\n"
	.string "ständigen?\p"
	.string "Ich habe gegen dich verloren, aber den\n"
	.string "POKéDEX werde ich eher vollständig\l"
	.string "haben als du!\p"
	.string "Man sieht sich!$"
	.endif
	.endif

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.ifdef ENGLISH
	.string "{PLAYER}{KUN}, what are you going to do?\p"
	.string "Are you taking the BATTLE FRONTIER\n"
	.string "challenge?\p"
	.string "Or, are you going to complete your\n"
	.string "POKéDEX?\p"
	.string "I might've lost to you in battling,\n"
	.string "but I'll finish my POKéDEX before you!\p"
	.string "See you!$"
	.else
	.ifdef GERMAN
	.string "Und, {PLAYER}{KUN}, was wirst du machen?\p"
	.string "Wirst du zur KAMPFZONE gehen?\p"
	.string "Oder wirst du deinen POKéDEX vervoll-\n"
	.string "ständigen?\p"
	.string "Ich habe gegen dich verloren, aber den\n"
	.string "POKéDEX werde ich eher vollständig\l"
	.string "haben als du!\p"
	.string "Man sieht sich!$"
	.endif
	.endif

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.ifdef ENGLISH
	.string "BRENDAN: Oh, hey, it's {PLAYER}.\p"
	.string "I'm running an errand for my dad.\n"
	.string "No, I'm not buying any DOLLS.\p"
	.string "Anyways, it's been a while.\p"
	.string "Want to have a battle to see who's been\n"
	.string "raising POKéMON better?$"
	.else
	.ifdef GERMAN
	.string "BRIX: Oh, du bist es, {PLAYER}.\p"
	.string "Ich mache Besorgungen für meinen\n"
	.string "Vater. Nein, ich kaufe keine PUPPEn!\p"
	.string "Wir haben uns lange nicht mehr gesehen.\p"
	.string "Sollen wir kämpfen, um zu sehen, wer\n"
	.string "seine POKéMON besser trainiert?$"
	.endif
	.endif

LilycoveCity_Text_BrendanNoConfidence:
	.ifdef ENGLISH
	.string "BRENDAN: Oh, what's the matter?\n"
	.string "Don't have the confidence?$"
	.else
	.ifdef GERMAN
	.string "BRIX: Oh, hast du ein Problem? Nicht\n"
	.string "genügend Selbstbewusstsein, was?$"
	.endif
	.endif

LilycoveCity_Text_BrendanBattleMe:
	.ifdef ENGLISH
	.string "BRENDAN: Want to battle to see who's\n"
	.string "been raising POKéMON better?$"
	.else
	.ifdef GERMAN
	.string "BRIX: Sollen wir kämpfen, um zu\n"
	.string "sehen, wer seine POKéMON besser\l"
	.string "trainiert?$"
	.endif
	.endif

LilycoveCity_Text_BrendanWontBeBeaten:
	.ifdef ENGLISH
	.string "BRENDAN: Aww, but you know I'm not\n"
	.string "going to lose to no {PLAYER}.$"
	.else
	.ifdef GERMAN
	.string "BRIX: Aah, ich werde doch nicht\n"
	.string "gegen {PLAYER} verlieren! Niemals!$"
	.endif
	.endif

LilycoveCity_Text_BrendanDefeat:
	.ifdef ENGLISH
	.string "Humph…\n"
	.string "You've done a lot of raising.\p"
	.string "That stings a bit--I had a head start\n"
	.string "on you as a TRAINER…$"
	.else
	.ifdef GERMAN
	.string "Ach…\n"
	.string "Du hast dich stark verbessert.\p"
	.string "Das schmerzt - und dabei hatte ich als\n"
	.string "TRAINER sogar einen Vorsprung…$"
	.endif
	.endif

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.ifdef ENGLISH
	.string "BRENDAN: I…\n"
	.string "I plan on going home to LITTLEROOT.\p"
	.string "You know I'm helping out my dad on his\n"
	.string "POKéDEX. It's coming together pretty\l"
	.string "decently, so I should go show him.$"
	.else
	.ifdef GERMAN
	.string "BRIX: Ich…\n"
	.string "Ich gehe nach Hause, nach WURZELHEIM.\p"
	.string "Weißt du, ich helfe meinem Vater bei dem\n"
	.string "POKéDEX. Es geht ganz anständig voran\l"
	.string "und ich sollte ihm das mal zeigen.$"
	.endif
	.endif

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.ifdef ENGLISH
	.string "{PLAYER}, what are you going to do?\p"
	.string "Collect all the GYM BADGES and take\n"
	.string "the POKéMON LEAGUE challenge?\p"
	.string "Maybe I'll do that, too…\p"
	.string "Well, anyway, hang in there!$"
	.else
	.ifdef GERMAN
	.string "Und, {PLAYER}, was wirst du tun?\p"
	.string "Wirst du alle ORDEN der ARENen sammeln\n"
	.string "und die POKéMON LIGA herausfordern?\p"
	.string "Vielleicht werde ich das auch machen…\p"
	.string "Gut, bleib am Ball!$"
	.endif
	.endif

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.ifdef ENGLISH
	.string "{PLAYER}, what are you going to do?\p"
	.string "Since you're that strong, are you\n"
	.string "taking the POKéMON LEAGUE challenge?\p"
	.string "Heh, even me--if I trained my POKéMON\n"
	.string "a bit more, I should be stronger than\l"
	.string "you, {PLAYER}.\p"
	.string "Well, anyway, hang in there!$"
	.else
	.ifdef GERMAN
	.string "Und, {PLAYER}, was wirst du tun?\p"
	.string "Da du so stark geworden bist, wirst du\n"
	.string "die POKéMON LIGA herausfordern?\p"
	.string "Hey, ich habe meine POKéMON bestimmt\n"
	.string "viel besser trainiert und sollte\l"
	.string "eigentlich stärker sein als du…\p"
	.string "Nun ja, bleib am Ball!$"
	.endif
	.endif

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.ifdef ENGLISH
	.string "{PLAYER}, what are you going to do?\p"
	.string "Are you taking the BATTLE FRONTIER\n"
	.string "challenge?\p"
	.string "Or, are you going to complete your\n"
	.string "POKéDEX?\p"
	.string "Since you're that strong, you should\n"
	.string "consider the BATTLE FRONTIER.\p"
	.string "Heh, if I train my POKéMON a bit more,\n"
	.string "I'll get stronger than you, {PLAYER}.\p"
	.string "Maybe I should go to the BATTLE\n"
	.string "FRONTIER.\p"
	.string "Well, anyway, hang in there!$"
	.else
	.ifdef GERMAN
	.string "Und, {PLAYER}, was machst du nun?\p"
	.string "Wirst du zur KAMPFZONE gehen?\p"
	.string "Oder wirst du deinen POKéDEX\n"
	.string "vervollständigen?\p"
	.string "Da du so stark geworden bist, solltest\n"
	.string "du zur KAMPFZONE gehen.\p"
	.string "Häh, wenn ich meine POKéMON besser\n"
	.string "trainiere, sollte ich eigentlich stärker\l"
	.string "werden als du…\p"
	.string "Vielleicht sollte ich zur KAMPFZONE\n"
	.string "gehen.\p"
	.string "Wie dem auch sei… Bleib am Ball!$"
	.endif
	.endif

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.ifdef ENGLISH
	.string "Fufufu…\p"
	.string "We moved more loot into our secret\n"
	.string "HIDEOUT today…\p"
	.string "Wh-who are you?!\n"
	.string "I was just talking to myself!$"
	.else
	.ifdef GERMAN
	.string "Hähähä…\p"
	.string "Heute haben wir noch mehr Beute in\n"
	.string "unser VERSTECK gebracht…\p"
	.string "We…wer bist du denn??? Ich… äh, habe\n"
	.string "mit mir selbst gesprochen!$"
	.endif
	.endif

LilycoveCity_Text_ChanceToDoBigThings:
	.ifdef ENGLISH
	.string "I'm just a GRUNT, so I don't know what\n"
	.string "the BOSS is thinking…\p"
	.string "But being on TEAM AQUA, I know I'll get\n"
	.string "the chance to do big things!\p"
	.string "Wh-who are you?!\n"
	.string "I was just talking to myself!$"
	.else
	.ifdef GERMAN
	.string "Ich bin nur ein RÜPEL, ich weiß nicht,\n"
	.string "was unser BOSS so vorhat…\p"
	.string "Aber als Mitglied von TEAM AQUA habe\n"
	.string "ich die Möglichkeit, große Dinge zu tun!\p"
	.string "Ww…wer bist du denn??? I-Ich… hähähä,\n"
	.string "habe nur mit mir selber gesprochen!$"
	.endif
	.endif

LilycoveCity_Text_DontGoNearCaveInCove:
	.ifdef ENGLISH
	.string "Hey, you!\p"
	.string "Don't go near the cave in the cove!\p"
	.string "Why? You don't need a reason why!\n"
	.string "I'm an adult, so you just listen to me!$"
	.else
	.ifdef GERMAN
	.string "Hey, du da!\p"
	.string "Komm bloß nicht in die Nähe der Höhle in\n"
	.string "der Bucht!\p"
	.string "Warum nicht? Das geht dich nichts an!\n"
	.string "Ich bin ein Erwachsener, also gehorche!$"
	.endif
	.endif

LilycoveCity_Text_IfWorldBecomesOurs:
	.ifdef ENGLISH
	.string "If this whole wide world becomes ours,\n"
	.string "TEAM AQUA's, it will be a happier\l"
	.string "place for POKéMON, too.$"
	.else
	.ifdef GERMAN
	.string "Wenn die ganze Welt erst einmal uns\n"
	.string "gehört, TEAM AQUA, dann wird sie\l"
	.string "ein besserer Ort für POKéMON sein.$"
	.endif
	.endif

LilycoveCity_Text_WailmerLeapOutOfWater:
	.ifdef ENGLISH
	.string "There! WAILMER!\n"
	.string "Leap out of the water now!$"
	.else
	.ifdef GERMAN
	.string "Hier, WAILMER!!!\n"
	.string "Springt aus dem Wasser!$"
	.endif
	.endif

LilycoveCity_Text_GetLostMessingUpTraining:
	.ifdef ENGLISH
	.string "Hunh? What do you want?\p"
	.string "You're messing up our training,\n"
	.string "so can you, like, get lost?$"
	.else
	.ifdef GERMAN
	.string "Häh? Was willst du?\p"
	.string "Du störst uns beim Training, also würde\n"
	.string "ich vorschlagen, du verschwindest!$"
	.endif
	.endif

LilycoveCity_Text_ContestHallInTown:
	.ifdef ENGLISH
	.string "There's a POKéMON CONTEST HALL\n"
	.string "right in this here town. \p"
	.string "That means well-raised POKéMON will\n"
	.string "come from all over the country.\p"
	.string "My heart swells with excitement!$"
	.else
	.ifdef GERMAN
	.string "Hier gibt es eine POKéMON WETTBEWERBs-\n"
	.string "HALLE.\p"
	.string "Und das bedeutet, dass gut\n"
	.string "aufgezogene POKéMON aus dem ganzen\l"
	.string "Land zu sehen sind.\p"
	.string "Mein Herz strömt über vor Begeisterung!$"
	.endif
	.endif

LilycoveCity_Text_StrangeCaveInCove:
	.ifdef ENGLISH
	.string "Have you seen that strange cave in\n"
	.string "the cove at the edge of town?$"
	.else
	.ifdef GERMAN
	.string "Hast du die seltsame Höhle in der Bucht\n"
	.string "am Ende des Ortes gesehen?$"
	.endif
	.endif

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.ifdef ENGLISH
	.string "I'm going to teach my POKéMON some new\n"
	.string "moves for entering a CONTEST.\p"
	.string "So, I'm going to see the MOVE DELETER\n"
	.string "and make it forget HM moves.$"
	.else
	.ifdef GERMAN
	.string "Ich werde meinem POKéMON einige neue\n"
	.string "Attacken für den WETTBEWERB\l"
	.string "beibringen.\p"
	.string "Daher werde ich den ATTACKEN-\n"
	.string "VERLERNER besuchen, damit einige\l"
	.string "VMs verlernt werden.$"
	.endif
	.endif

LilycoveCity_Text_ImFromKanto:
	.ifdef ENGLISH
	.string "I came from KANTO.\p"
	.string "The HOENN region is beautiful with\n"
	.string "all its water and verdant nature.\p"
	.string "Hunh? Wait a second…\p"
	.string "Could there be rare POKéMON that live\n"
	.string "only in this area?$"
	.else
	.ifdef GERMAN
	.string "Ich komme aus KANTO.\p"
	.string "Die HOENN-Region ist wunderschön mit\n"
	.string "all dem Wasser und dem Grün.\p"
	.string "Hey, warte mal!\p"
	.string "Ob es seltene POKéMON gibt, die nur in\n"
	.string "dieser Region leben???$"
	.endif
	.endif

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.ifdef ENGLISH
	.string "TEAM AQUA's been training their\n"
	.string "WAILMER in the cove.\p"
	.string "We SAILORS can't get our boats out\n"
	.string "to sea with them in the way!$"
	.else
	.ifdef GERMAN
	.string "TEAM AQUA trainiert seine WAILMER\n"
	.string "drüben in der Bucht.\p"
	.string "Wir MATROSEN können nicht auslaufen,\n"
	.string "da sie uns im Weg sind.$"
	.endif
	.endif

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.ifdef ENGLISH
	.string "Ahoy, did you know?\p"
	.string "Someone punted TEAM AQUA out of\n"
	.string "the way for us!\p"
	.string "That got the WAILMER out of the cove,\n"
	.string "so we can get our boats out again.$"
	.else
	.ifdef GERMAN
	.string "Ahoi, hast du das mitbekommen?\p"
	.string "Jemand hat für uns TEAM AQUA aus\n"
	.string "unserer Fahrrinne verjagt!\p"
	.string "Die WAILMER befinden sich nicht mehr in\n"
	.string "der Bucht und wir haben freie Fahrt.$"
	.endif
	.endif

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.ifdef ENGLISH
	.string "I was taking a relaxing snooze at the\n"
	.string "seaside inn to the sound of waves…\p"
	.string "When someone stole my POKéMON!\p"
	.string "Who's the abductor?\n"
	.string "TEAM AQUA? Is it TEAM AQUA?$"
	.else
	.ifdef GERMAN
	.string "Ich habe ein entspannendes Nickerchen\n"
	.string "im Gasthof am Meer gehalten. Das\l"
	.string "Rauschen der Wellen war so angenehm.\p"
	.string "Und da hat mir jemand mein POKéMON\n"
	.string "gestohlen!\p"
	.string "Wer ist der schändliche Dieb?\n"
	.string "TEAM AQUA? Es war TEAM AQUA?!?$"
	.endif
	.endif

LilycoveCity_Text_MissingPokemonCameBack:
	.ifdef ENGLISH
	.string "My missing POKéMON…\n"
	.string "It came back without me noticing!$"
	.else
	.ifdef GERMAN
	.string "Mein gestohlenes POKéMON…\n"
	.string "Es kam zurück, ohne dass ich es merkte.$"
	.endif
	.endif

LilycoveCity_Text_ImArtDealer:
	.ifdef ENGLISH
	.string "I'm an ART DEALER.\p"
	.string "I am a buyer and seller of fine art,\n"
	.string "especially paintings.\p"
	.string "I've heard that the MUSEUM here has\n"
	.string "magnificent works on exhibit…$"
	.else
	.ifdef GERMAN
	.string "Ich bin ein KUNSTHÄNDLER.\p"
	.string "Ich kaufe und verkaufe Kunstgegen-\n"
	.string "stände. Vorzugsweise Gemälde.\p"
	.string "Ich habe gehört, dass das hiesige\n"
	.string "MUSEUM ständig erstklassige Werke\l"
	.string "ausstellt.$"
	.endif
	.endif

LilycoveCity_Text_SeaRemainsForeverYoung:
	.ifdef ENGLISH
	.string "Even as we grow old and wrinkled,\n"
	.string "the sea remains forever young with\l"
	.string "the vivid brilliance of life…\p"
	.string "Fwohoho fwohohohoho…$"
	.else
	.ifdef GERMAN
	.string "Auch wenn ich alt und grau werde, das\n"
	.string "Meer wird immer jung und voll von Leben\l"
	.string "sein…\p"
	.string "Hahahahaha… Haaahahahaha…$"
	.endif
	.endif

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.ifdef ENGLISH
	.string "It was sixty years ago that my husband\n"
	.string "proposed to me here.\l"
	.string "The sea remains as beautiful as ever.\p"
	.string "Mufufufu mufufufufufu…$"
	.else
	.ifdef GERMAN
	.string "Vor 60 Jahren hat mein Mann hier um\n"
	.string "meine Hand angehalten. Und das Meer\l"
	.string "ist immer noch genauso schön.\p"
	.string "Hahahahaha… Haaahahahaha…$"
	.endif
	.endif

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.ifdef ENGLISH
	.string "Hm, you know of the peculiar cavern\n"
	.string "in this cove?\p"
	.string "That had been a natural formation,\n"
	.string "but then that TEAM AQUA lot came\l"
	.string "along and made their renovations.\p"
	.string "They call themselves\n"
	.string "the “nature-loving TEAM AQUA”!\p"
	.string "But what they do and what they say\n"
	.string "don't match at all!$"
	.else
	.ifdef GERMAN
	.string "Hm, kennst du diese besondere Höhle in\n"
	.string "der Bucht?\p"
	.string "Das ist eine natürliche Formation, aber\n"
	.string "TEAM AQUA kam und hat das Aussehen\l"
	.string "verändert.\p"
	.string "Sie nennen sich selber “Naturliebendes\n"
	.string "TEAM AQUA”!\p"
	.string "Aber was sie sagen und was sie tun,\n"
	.string "passt überhaupt nicht zusammen!$"
	.endif
	.endif

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.ifdef ENGLISH
	.string "That cave in the cove…\p"
	.string "I didn't notice it right away,\n"
	.string "but it's completely empty now.\p"
	.string "That TEAM AQUA lot, they must\n"
	.string "have gone away for good.$"
	.else
	.ifdef GERMAN
	.string "Die Höhle in der Bucht…\p"
	.string "Es ist mir erst gar nicht aufgefallen,\n"
	.string "aber sie ist völlig leer.\p"
	.string "TEAM AQUA muss verschwunden sein.$"
	.endif
	.endif

LilycoveCity_Text_CitySign:
	.ifdef ENGLISH
	.string "LILYCOVE CITY\p"
	.string "“Where the land ends and the\n"
	.string "sea begins.”$"
	.else
	.ifdef GERMAN
	.string "SEEGRASULB CITY\p"
	.string "“Wo das Land endet und das\n"
	.string "Meer beginnt.”$"
	.endif
	.endif

LilycoveCity_Text_ContestHallSign:
	.ifdef ENGLISH
	.string "POKéMON CONTEST HALL\n"
	.string "“The gathering place for TRAINERS!”$"
	.else
	.ifdef GERMAN
	.string "POKéMON WETTBEWERBSHALLE\n"
	.string "“Der Treffpunkt für TRAINER.”$"
	.endif
	.endif

LilycoveCity_Text_MotelSign:
	.ifdef ENGLISH
	.string "COVE LILY MOTEL\p"
	.string "“Remember us as COVE LILY of\n"
	.string "LILYCOVE.”$"
	.else
	.ifdef GERMAN
	.string "GRASSEE MOTEL\p"
	.string "“Behalte uns als Rose von\n"
	.string "SEEGRASULB CITY in Erinnerung.”$"
	.endif
	.endif

LilycoveCity_Text_MuseumSign:
	.ifdef ENGLISH
	.string "LILYCOVE MUSEUM\p"
	.string "“POKéMON Masterpiece Collection\n"
	.string "on exhibit!”$"
	.else
	.ifdef GERMAN
	.string "SEEGRASULB CITY MUSEUM\p"
	.string "“Ausstellung von\n"
	.string "POKéMON-Meisterwerken!”$"
	.endif
	.endif

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.ifdef ENGLISH
	.string "LILYCOVE MUSEUM\p"
	.string "“{PLAYER}'s POKéMON Collection\n"
	.string "on exhibit!”$"
	.else
	.ifdef GERMAN
	.string "SEEGRASULB CITY MUSEUM\p"
	.string "“Aktuelle Ausstellung:\n"
	.string "Die POKéMON-Sammlung von {PLAYER}!”$"
	.endif
	.endif

LilycoveCity_Text_HarborSignUnderConstruction:
	.ifdef ENGLISH
	.string "LILYCOVE CITY HARBOR\p"
	.string "“The ferry S.S. TIDAL is under\n"
	.string "construction in SLATEPORT CITY.\p"
	.string "“Service is scheduled to begin\n"
	.string "shortly.”$"
	.else
	.ifdef GERMAN
	.string "HAFEN SEEGRASULB CITY\p"
	.string "“Die Fähre MS TIDE wird momentan\n"
	.string "in der WERFT gebaut.\p"
	.string "Die Fähre wird so bald wie möglich ihren\n"
	.string "Dienst aufnehmen.”$"
	.endif
	.endif

LilycoveCity_Text_HarborSign:
	.ifdef ENGLISH
	.string "LILYCOVE CITY HARBOR\p"
	.string "“Enjoy a delightful cruise on\n"
	.string "the ferry S.S. TIDAL.”$"
	.else
	.ifdef GERMAN
	.string "HAFEN SEEGRASULB CITY\p"
	.string "“Genießen Sie die entspannende Fahrt\n"
	.string "mit der Fähre MS TIDE.”$"
	.endif
	.endif

LilycoveCity_Text_TrainerFanClubSign:
	.ifdef ENGLISH
	.string "POKéMON TRAINER FAN CLUB\p"
	.string "The names of TRAINERS are scribbled\n"
	.string "all over the sign…$"
	.else
	.ifdef GERMAN
	.string "POKéMON TRAINER-FANCLUB\p"
	.string "Die Namen von TRAINERn sind auf dem\n"
	.string "Schild eingeritzt…$"
	.endif
	.endif

LilycoveCity_Text_DepartmentStoreSign:
	.ifdef ENGLISH
	.string "LILYCOVE DEPARTMENT STORE\p"
	.string "“Overflowing with great merchandise\n"
	.string "and excitement!\p"
	.string "“A great place to find that something\n"
	.string "you need!”$"
	.else
	.ifdef GERMAN
	.string "SEEGRASULB CITY EINKAUFSZENTRUM\p"
	.string "“Ein Überfluss an Waren und\n"
	.string "Überraschungen!\p"
	.string "Ein Ort, an dem man alles findet, was\n"
	.string "das Herz begehrt!”$"
	.endif
	.endif

LilycoveCity_Text_MoveDeletersHouseSign:
	.ifdef ENGLISH
	.string "MOVE DELETER'S HOUSE\p"
	.string "“Unwanted POKéMON moves deleted.”$"
	.else
	.ifdef GERMAN
	.string "HAUS des ATTACKEN-VERLERNERS\p"
	.string "“Hier werden POKéMON-Attacken\n"
	.string "verlernt.”$"
	.endif
	.endif

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.ifdef ENGLISH
	.string "Do you know about the machine\n"
	.string "BERRY BLENDER?$"
	.else
	.ifdef GERMAN
	.string "Hast du schon mal etwas über den\n"
	.string "BEERENMIXER gehört?$"
	.endif
	.endif

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.ifdef ENGLISH
	.string "People have to work together to get it\n"
	.string "to spin faster.\p"
	.string "The faster you can make it spin, the\n"
	.string "better {POKEBLOCK}S you can get, I've heard.$"
	.else
	.ifdef GERMAN
	.string "Man muss mit anderen zusammenarbeiten,\n"
	.string "um ihn schneller drehen zu können.\p"
	.string "Ich habe gehört, je schneller man ihn\n"
	.string "dreht, desto besser werden die {POKEBLOCK}.$"
	.endif
	.endif

LilycoveCity_Text_ExplainBerryBlender:
	.ifdef ENGLISH
	.string "It's used for making a kind of candy\n"
	.string "called a {POKEBLOCK}.\p"
	.string "If you give a good {POKEBLOCK} to a POKéMON,\n"
	.string "its condition will improve by a lot.$"
	.else
	.ifdef GERMAN
	.string "Damit stellt man eine Leckerei her, die\n"
	.string "{POKEBLOCK} genannt wird.\p"
	.string "Wenn du einem POKéMON einen guten\n"
	.string "{POKEBLOCK} gibst, verbessern sich seine\l"
	.string "Eigenschaften.$"
	.endif
	.endif

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.ifdef ENGLISH
	.string "I heard there's a tower somewhere out\n"
	.string "on the sea routes.\p"
	.string "It's called the SKY PILLAR, I hear.$"
	.else
	.ifdef GERMAN
	.string "Ich habe gehört, dass draußen auf dem\n"
	.string "Seeweg ein Turm sein soll.\p"
	.string "Er soll HIMMELTURM heißen.$"
	.endif
	.endif

LilycoveCity_Text_SawTallTowerOnRoute131:
	.ifdef ENGLISH
	.string "I saw this tall tower somewhere\n"
	.string "around ROUTE 131.\p"
	.string "Could that possibly be…?$"
	.else
	.ifdef GERMAN
	.string "Ich habe einen großen Turm in der Nähe\n"
	.string "der ROUTE 131 gesehen.\p"
	.string "Ist das der…$"
	.endif
	.endif

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.ifdef ENGLISH
	.string "We just arrived here on our\n"
	.string "honeymoon vacation.\p"
	.string "We happened to see a DRAGON-type\n"
	.string "POKéMON flying way up in the sky.\p"
	.string "Do cool POKéMON like that live in\n"
	.string "the HOENN region?$"
	.else
	.ifdef GERMAN
	.string "Wir sind in den Flitterwochen und\n"
	.string "gerade hier angekommen.\p"
	.string "Wir haben ein DRACHEn-POKéMON\n"
	.string "gesehen, das am Himmel flog.\p"
	.string "Leben in der HOENN-Region viele\n"
	.string "solcher coolen POKéMON?$"
	.endif
	.endif

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.ifdef ENGLISH
	.string "On our honeymoon, we vowed to see as\n"
	.string "many rare POKéMON as we can.\p"
	.string "So we were delighted to see a rare\n"
	.string "POKéMON as soon as we arrived.\p"
	.string "I mean, we are totally happy!$"
	.else
	.ifdef GERMAN
	.string "Wir haben uns vorgenommen, in unseren\n"
	.string "Flitterwochen so viele seltene POKéMON\l"
	.string "zu sehen, wie es eben geht.\p"
	.string "Daher waren wir auch total glücklich,\n"
	.string "als wir gleich nach unserer Ankunft\l"
	.string "dieses POKéMON zu Gesicht bekamen.\p"
	.string "Ich meine, wir waren wirklich glücklich!$"
	.endif
	.endif
