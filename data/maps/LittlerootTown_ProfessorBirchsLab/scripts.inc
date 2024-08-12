.set LOCALID_AIDE, 1
.set LOCALID_BIRCH, 2
.set LOCALID_RIVAL, 3
.set LOCALID_BALL_CYNDAQUIL, 4
.set LOCALID_BALL_TOTODILE, 5
.set LOCALID_BALL_CHIKORITA, 6

LittlerootTown_ProfessorBirchsLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_ProfessorBirchsLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_OnFrame
	.byte 0

	@ State descriptions for VAR_DEX_UPGRADE_JOHTO_STARTER_STATE
	@ 1: Beat Elite Four, Dex upgrade ready
	@ 2: Received National Dex
	@ 3: Left lab after receiving National Dex
	@ 4: Entered lab after catching all Hoenn mons
	@ 5: Birch told player to choose Johto starter
	@ 6: Chose Johto starter

	@ State descriptions for VAR_BIRCH_LAB_STATE
	@ 1: Never occurs
	@ 2: Chose starter
	@ 3: Received starter in lab
	@ 4: Defeated rival on Route 103
	@ 5: Received pokedex

LittlerootTown_ProfessorBirchsLab_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter::
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm LOCALID_RIVAL, 5, 10
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter::
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4
	goto LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout

LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout::
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout::
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm LOCALID_RIVAL, 5, 10
	end

LittlerootTown_ProfessorBirchsLab_OnWarp:
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
	.2byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	addobject LOCALID_BIRCH
	addobject LOCALID_RIVAL
	turnobject LOCALID_RIVAL, DIR_NORTH
	setobjectxy LOCALID_RIVAL, 5, 5
	turnobject LOCALID_BIRCH, DIR_SOUTH
	setobjectxy LOCALID_BIRCH, 6, 4
	turnobject LOCALID_AIDE, DIR_EAST
	setobjectxy LOCALID_AIDE, 10, 10
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject::
	addobject LOCALID_RIVAL
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters::
	addobject LOCALID_BALL_CYNDAQUIL
	addobject LOCALID_BALL_TOTODILE
	addobject LOCALID_BALL_CHIKORITA
	addobject LOCALID_RIVAL
	turnobject LOCALID_BALL_CYNDAQUIL, DIR_SOUTH
	setobjectxy LOCALID_BALL_CYNDAQUIL, 8, 4
	turnobject LOCALID_BALL_TOTODILE, DIR_SOUTH
	setobjectxy LOCALID_BALL_TOTODILE, 9, 4
	turnobject LOCALID_BALL_CHIKORITA, DIR_SOUTH
	setobjectxy LOCALID_BALL_CHIKORITA, 10, 4
	turnobject LOCALID_BIRCH, DIR_SOUTH
	setobjectxy LOCALID_BIRCH, 6, 4
	turnobject LOCALID_RIVAL, DIR_EAST
	setobjectxy LOCALID_RIVAL, 5, 5
	end

LittlerootTown_ProfessorBirchsLab_OnFrame:
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent
	map_script_2 VAR_BIRCH_LAB_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter
	.2byte 0

@ The starter is technically given prior to this on Route 101 by special ChooseStarter
@ This is just where the game tells you its yours and lets you nickname it
LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent::
	lockall
	bufferleadmonspeciesname STR_VAR_1
	message LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_ROUTE_101_BOY
	setvar VAR_BIRCH_LAB_STATE, 3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex
	waitmovement 0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex
	end

LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex::
	lockall
	delay 30
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes
	waitmovement 0
	delay 20
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 20
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment
	playse SE_PC_ON
	waitse
	delay 20
	applymovement LOCALID_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational
	waitmessage
	waitfanfare
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	setvar VAR_SCOTT_BF_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes:
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_in_place_faster_down
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_Aide::
	lock
	faceplayer
	goto_if_ge VAR_BIRCH_LAB_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter
	goto_if_set FLAG_BIRCH_AIDE_MET, LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork, MSGBOX_DEFAULT
	setflag FLAG_BIRCH_AIDE_MET
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Cyndaquil::
	release
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_CYNDAQUIL, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Totodile::
	release
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_TOTODILE, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Chikorita::
	release
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_CHIKORITA, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil::
	bufferspeciesname STR_VAR_1, SPECIES_CYNDAQUIL
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CYNDAQUIL
	givemon SPECIES_CYNDAQUIL, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BALL_CYNDAQUIL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BALL_CYNDAQUIL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile::
	bufferspeciesname STR_VAR_1, SPECIES_TOTODILE
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TOTODILE
	givemon SPECIES_TOTODILE, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BALL_TOTODILE
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BALL_TOTODILE
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita::
	bufferspeciesname STR_VAR_1, SPECIES_CHIKORITA
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHIKORITA
	givemon SPECIES_CHIKORITA, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BALL_CHIKORITA
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BALL_CHIKORITA
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter::
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter
	waitmessage
	waitfanfare
	return

LittlerootTown_ProfessorBirchsLab_EventScript_Birch::
	lock
	faceplayer
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting
	goto_if_unset FLAG_HAS_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister::
	goto_if_unset FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_eq VAR_BIRCH_LAB_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome, MSGBOX_DEFAULT
	release
	end

EventScript_RegisterProfBirch::
	msgbox MatchCall_Text_BirchRegisterCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredBirch, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	setvar VAR_REGISTER_BIRCH_STATE, 2
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex, MSGBOX_DEFAULT
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls
	setvar VAR_BIRCH_LAB_STATE, 5
	setflag FLAG_ADVENTURE_STARTED
	setvar VAR_OLDALE_TOWN_STATE, 1
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 5
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 5
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls, MSGBOX_DEFAULT
	setvar VAR_RESULT, 1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex::
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer:
	walk_down
	walk_in_place_faster_left
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_Machine::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Rival::
	lock
	faceplayer
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly:
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_PC::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Book::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall::
	lockall
	pokenavcall LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall
	waitmessage
	clearflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork:
	.ifdef ENGLISH
	.string "Hunh? PROF. BIRCH?\p"
	.string "The PROF's away on fieldwork.\n"
	.string "Ergo, he isn't here.\p"
	.string "Oh, let me explain what fieldwork is.\p"
	.string "It is to study things in the natural\n"
	.string "environment, like fields and mountains,\l"
	.string "instead of a laboratory.\p"
	.string "The PROF isn't one for doing desk work.\n"
	.string "He's the type of person who would\l"
	.string "rather go outside and experience\l"
	.string "things than read about them here.$"
	.else
	.ifdef GERMAN
	.string "Wie? PROF. BIRK?\p"
	.string "Der PROF arbeitet an einer Feld-Studie.\n"
	.string "Also ist er nicht hier.\p"
	.string "Oh, ich erkläre dir, was eine Feld-Studie\n"
	.string "in diesem Falle ist:\p"
	.string "Man beobachtet und studiert Dinge in\n"
	.string "ihrem natürlichen Umfeld. In Feldern\l"
	.string "oder auf Bergen, anstatt im Labor.\p"
	.string "Der PROF ist kein Typ, der am Schreib-\n"
	.string "tisch arbeiten kann. Er muss einfach\l"
	.string "draußen in der freien Natur die Dinge\l"
	.string "beobachten und studieren.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork:
	.ifdef ENGLISH
	.string "The PROF isn't one for doing desk work.\n"
	.string "He's the type of person who would\l"
	.string "rather go outside and experience\l"
	.string "things than read about them here.$"
	.else
	.ifdef GERMAN
	.string "Der PROF ist kein Typ, der am Schreib-\n"
	.string "tisch arbeiten kann. Er muss einfach\l"
	.string "draußen in der freien Natur die Dinge\l"
	.string "beobachten und studieren.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo:
	.ifdef ENGLISH
	.string "PROF. BIRCH is studying the habitats\n"
	.string "and distribution of POKéMON.\p"
	.string "The PROF enjoys {RIVAL}'s help, too.\n"
	.string "There's a lot of love there.$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRK studiert den Lebensraum\n"
	.string "und die Verbreitung von POKéMON.\p"
	.string "Der PROF freut sich über die Mitarbeit\n"
	.string "von {RIVAL}. Da spürt man Zuneigung!$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon:
	.ifdef ENGLISH
	.string "PROF. BIRCH: So, {PLAYER}{KUN}.\p"
	.string "I've heard so much about you from\n"
	.string "your father.\p"
	.string "I've heard that you don't have your\n"
	.string "own POKéMON yet.\p"
	.string "But the way you battled earlier,\n"
	.string "you pulled it off with aplomb!\p"
	.string "I guess you have your father's blood\n"
	.string "in your veins after all!\p"
	.string "Oh, yes. As thanks for rescuing me,\n"
	.string "I'd like you to have the POKéMON you\l"
	.string "used earlier.\p"
	.string "{PLAYER} received the {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRK: Du bist also {PLAYER}{KUN}!\p"
	.string "Dein Vater hat mir schon viel von dir\n"
	.string "erzählt.\p"
	.string "Ich habe auch erfahren, dass du noch\n"
	.string "kein eigenes POKéMON besitzt.\p"
	.string "Aber wie du eben gekämpft hast…\n"
	.string "Diese Gelassenheit…\p"
	.string "In deinen Adern fließt wirklich das Blut\n"
	.string "deines Vaters!\p"
	.string "Als Dank dafür, dass du mich gerettet\n"
	.string "hast, möchte ich dir das POKéMON\l"
	.string "schenken, das du dabei benutzt hast.\p"
	.string "{PLAYER} erhält {STR_VAR_1}!$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon:
	.ifdef ENGLISH
	.string "PROF. BIRCH: While you're at it, why not\n"
	.string "give a nickname to that {STR_VAR_1}?$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRK: Willst du dem\n"
	.string "{STR_VAR_1} einen Kosenamen geben?$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival:
	.ifdef ENGLISH
	.string "PROF. BIRCH: If you work at POKéMON\n"
	.string "and gain experience, I think you'll make\l"
	.string "an extremely good TRAINER.\p"
	.string "My kid, {RIVAL}, is also studying\n"
	.string "POKéMON while helping me out.\p"
	.string "{PLAYER}{KUN}, don't you think it might be\n"
	.string "a good idea to go see {RIVAL}?$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRK: Wenn du dich mit POKéMON\n"
	.string "beschäftigst und Erfahrungen\p"
	.string "sammelst, wirst du mit Sicherheit ein\n"
	.string "sehr guter TRAINER!\p"
	.string "Mein Kind, {RIVAL}, studiert ebenfalls\n"
	.string "POKéMON und hilft mir dabei sehr.\p"
	.string "{PLAYER}{KUN}, meinst du nicht, es wäre eine\n"
	.string "gute Idee, wenn du dich mit {RIVAL}\l"
	.string "triffst?$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou:
	.ifdef ENGLISH
	.string "PROF. BIRCH: Great!\n"
	.string "{RIVAL} should be happy, too.\p"
	.string "Get {RIVAL} to teach you what it\n"
	.string "means to be a TRAINER.$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRK: Großartig!\n"
	.string "{RIVAL} wird sich auch sehr freuen.\p"
	.string "{RIVAL} soll dir beibringen, was es\n"
	.string "bedeutet, ein TRAINER zu sein.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay:
	.ifdef ENGLISH
	.string "PROF. BIRCH: Oh, don't be that way.\n"
	.string "You should go meet my kid.$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRK: Ach, sei doch nicht so!\n"
	.string "Du solltest dich wirklich mit meinem\l"
	.string "Sprössling treffen!$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome:
	.ifdef ENGLISH
	.string "PROF. BIRCH: {RIVAL}?\n"
	.string "Gone home, I think.\p"
	.string "Or maybe that kid's scrabbling around\n"
	.string "in tall grass again somewhere…\p"
	.string "If you or your POKéMON get tired,\n"
	.string "you should get some rest at home.$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRK: {RIVAL}? {RIVAL} ist,\n"
	.string "glaube ich, nach Hause gegangen.\p"
	.string "Oder das Kind krabbelt mal wieder\n"
	.string "irgendwo durch hohes Gras…\p"
	.string "Wenn du und deine POKéMON müde\n"
	.string "sind, dann ruht euch zu Hause aus.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex:
	.ifdef ENGLISH
	.string "PROF. BIRCH: Oh, hi, {PLAYER}{KUN}!\p"
	.string "I heard you beat {RIVAL} on\n"
	.string "your first try. That's excellent!\p"
	.string "{RIVAL}'s been helping with my research\n"
	.string "for a long time.\p"
	.string "{RIVAL} has an extensive history as\n"
	.string "a TRAINER already.\p"
	.string "Here, {PLAYER}{KUN}, I ordered this for my\n"
	.string "research, but I think you should have\l"
	.string "this POKéDEX.$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRK: Oh, hallo, {PLAYER}{KUN}!\p"
	.string "Ich habe gehört, du hast {RIVAL} \n"
	.string "besiegt! Super! Das war dein erster\l"
	.string "Kampf gegen einen TRAINER!\p"
	.string "{RIVAL} hilft mir schon sehr lange bei\n"
	.string "meinen Forschungen.\p"
	.string "{RIVAL} besitzt eine respektable\n"
	.string "Geschichte als TRAINER.\p"
	.string "Hier, das hilft mir bei meinen For-\n"
	.string "schungen. Aber ich denke, du kannst\l"
	.string "den POKéDEX auch gebrauchen.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex:
	.ifdef ENGLISH
	.string "{PLAYER} received the POKéDEX!$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} erhält den POKéDEX!$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex:
	.ifdef ENGLISH
	.string "PROF. BIRCH: The POKéDEX is a high-tech\n"
	.string "tool that automatically makes a record\l"
	.string "of any POKéMON you meet or catch.\p"
	.string "My kid, {RIVAL}, goes everywhere\n"
	.string "with it.\p"
	.string "Whenever my kid catches a rare POKéMON\n"
	.string "and records its data in the POKéDEX,\l"
	.string "why, {RIVAL} looks for me while I'm out\l"
	.string "doing fieldwork, and shows me.$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRK: Der POKéDEX ist ein hoch\n"
	.string "entwickeltes, technisches Gerät, das\l"
	.string "automatisch jedes POKéMON, das du\l"
	.string "siehst oder fängst, registriert.\p"
	.string "{RIVAL} geht nie ohne ihn aus dem Haus.\p"
	.string "Immer, wenn mein Kind ein seltenes\n"
	.string "POKéMON fängt, kommt es und\l"
	.string "zeigt mir den Eintrag im POKéDEX,\l"
	.string "während ich draußen forsche.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait:
	.ifdef ENGLISH
	.string "PROF. BIRCH: Countless POKéMON\n"
	.string "await you!\p"
	.string "Argh, I'm getting the itch to get out\n"
	.string "and do fieldwork again!$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRK: Unzählige POKéMON erwarten\n"
	.string "dich bereits.\p"
	.string "Hach, ich muss jetzt auch dringend\n"
	.string "wieder meinen Forschungen nachgehen.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese:
	.ifdef ENGLISH
	.string "MAY: Oh, wow, {PLAYER}{KUN}!\n"
	.string "You got a POKéDEX, too!\p"
	.string "That's great! Just like me!\n"
	.string "I've got something for you, too!$"
	.else
	.ifdef GERMAN
	.string "MAIKE: Oh, wow, {PLAYER}{KUN}!\n"
	.string "Jetzt hast du auch einen POKéDEX!\p"
	.string "Das ist ja toll! Genau wie ich!\n"
	.string "Ich habe hier etwas für dich!$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls:
	.ifdef ENGLISH
	.string "MAY: It's fun if you can get a lot of\n"
	.string "POKéMON!\p"
	.string "I'm going to look all over the place\n"
	.string "because I want different POKéMON.\p"
	.string "If I find any cute POKéMON, I'll catch\n"
	.string "them with POKé BALLS!$"
	.else
	.ifdef GERMAN
	.string "MAIKE: Es macht unheimlich viel Spaß, all\n"
	.string "die verschiedenen POKéMON zu fangen!\p"
	.string "Ich schaue mich wirklich überall um,\n"
	.string "denn ich will die unterschiedlichsten\l"
	.string "POKéMON fangen.\p"
	.string "Sobald ich niedliche POKéMON entdecke,\n"
	.string "fange ich sie mit POKéBÄLLen.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull:
	.ifdef ENGLISH
	.string "Oh? Your BAG's full.$"
	.else
	.ifdef GERMAN
	.string "Oh! Dein BEUTEL ist voll.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext:
	.ifdef ENGLISH
	.string "MAY: I wonder where I should go look\n"
	.string "for POKéMON next?$"
	.else
	.ifdef GERMAN
	.string "MAIKE: Ich frage mich, wo ich jetzt nach\n"
	.string "weiteren POKéMON suchen soll.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese:
	.ifdef ENGLISH
	.string "BRENDAN: Huh…\n"
	.string "So you got a POKéDEX, too.\p"
	.string "Well then, here.\n"
	.string "I'll give you these.$"
	.else
	.ifdef GERMAN
	.string "BRIX: Ach…\n"
	.string "Du hast auch einen POKéDEX.\p"
	.string "Na, dann.\n"
	.string "Ich gebe dir dies.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls:
	.ifdef ENGLISH
	.string "BRENDAN: You know it's more fun to\n"
	.string "have a whole bunch of POKéMON.\p"
	.string "I'm going to explore all over the place\n"
	.string "to find different POKéMON.\p"
	.string "If I find any cool POKéMON, you bet\n"
	.string "I'll try to get them with POKé BALLS.$"
	.else
	.ifdef GERMAN
	.string "BRIX: Weißt du, je mehr POKéMON du\n"
	.string "besitzt, desto mehr Spaß macht es.\p"
	.string "Ich reise viel umher, um die unter-\n"
	.string "schiedlichsten POKéMON zu finden.\p"
	.string "Und wenn ich ein cooles POKéMON sehe,\n"
	.string "versuche ich natürlich, es zu fangen.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull:
	.ifdef ENGLISH
	.string "Hey, your BAG's full.$"
	.else
	.ifdef GERMAN
	.string "Hey, dein BEUTEL ist voll.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext:
	.ifdef ENGLISH
	.string "BRENDAN: Where should I look for\n"
	.string "POKéMON next…$"
	.else
	.ifdef GERMAN
	.string "BRIX: Und wo soll ich jetzt mal nach\n"
	.string "POKéMON suchen?$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine:
	.ifdef ENGLISH
	.string "It's a serious-looking machine.\n"
	.string "The PROF must use this for research.$"
	.else
	.ifdef GERMAN
	.string "Das ist eine kompliziert aussehende\n"
	.string "Maschine. Der PROF wird sie für seine\l"
	.string "Forschungen brauchen…$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch:
	.ifdef ENGLISH
	.string "It's a PC used for research.\n"
	.string "Better not mess around with it.$"
	.else
	.ifdef GERMAN
	.string "Ein PC, der in der Forschung eingesetzt\n"
	.string "wird. Besser nicht damit spielen!$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon:
	.ifdef ENGLISH
	.string "It's crammed with books on POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Es ist voll mit Büchern über POKéMON.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead:
	.ifdef ENGLISH
	.string "It's a book that's too hard to read.$"
	.else
	.ifdef GERMAN
	.string "Dieses Buch ist viel zu kompliziert…$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational:
	.ifdef ENGLISH
	.string "PROF. BIRCH: Now…\p"
	.string "{PLAYER}{KUN} and {RIVAL}, I've had the two\n"
	.string "of you help me study POKéMON.\p"
	.string "Thanks to your help, new facts\n"
	.string "are coming to light.\p"
	.string "It appears that in the HOENN region,\n"
	.string "there are also POKéMON from other\l"
	.string "regions.\p"
	.string "It goes to show how rich and varied\n"
	.string "the natural environments of HOENN\l"
	.string "happen to be.\p"
	.string "That's why I think it's necessary for\n"
	.string "me to upgrade your POKéDEX to\l"
	.string "the NATIONAL Mode.\p"
	.string "Here, let me see your POKéDEX units.$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRK: Nun…\p"
	.string "{PLAYER}{KUN} und {RIVAL}, ich hatte euch\n"
	.string "gebeten, mir bei meinen POKéMON-\l"
	.string "Studien zu helfen.\p"
	.string "Dank eurer Hilfe kommen neue Fakten\n"
	.string "ans Tageslicht.\p"
	.string "Scheinbar sind in der HOENN-Region\n"
	.string "auch PKMN anderer Regionen ansässig.\p"
	.string "Das ist auch ein Beweis, wie reich die\n"
	.string "Natur in HOENN ist.\p"
	.string "Daher ist es sinnvoll, wenn ich eure\n"
	.string "POKéDEXe mit dem NATIONALEN MODUS\l"
	.string "ausrüste.\p"
	.string "Gebt mir mal eure POKéDEXe.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool:
	.ifdef ENGLISH
	.string "MAY: Eheheh!\p"
	.string "It's so cool that even my POKéDEX\n"
	.string "is getting updated!\p"
	.string "It's because you went out and caught\n"
	.string "so many POKéMON, {PLAYER}{KUN}!$"
	.else
	.ifdef GERMAN
	.string "MAIKE: Hihihi!\p"
	.string "Ich finde es total cool, dass mein\n"
	.string "POKéDEX auch verbessert wird!\p"
	.string "Dank dir, {PLAYER}{KUN}! Denn du hast so\n"
	.string "viele POKéMON gefangen!$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe:
	.ifdef ENGLISH
	.string "BRENDAN: I went out all over HOENN\n"
	.string "and checked out POKéMON.\p"
	.string "You can thank me for getting\n"
	.string "the NATIONAL Mode POKéDEX.\p"
	.string "Yep, you're lucky, {PLAYER}!$"
	.else
	.ifdef GERMAN
	.string "BRIX: Ich bin durch ganz HOENN gereist\n"
	.string "und habe die POKéMON untersucht.\p"
	.string "Dank mir bekommen wir beide jetzt den\n"
	.string "NATIONALEN MODUS.\p"
	.string "Ja ja, heute ist dein Glückstag,\n"
	.string "{PLAYER}!$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone:
	.ifdef ENGLISH
	.string "PROF. BIRCH: Okay, all done!$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRK: Okay, fertig!$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational:
	.ifdef ENGLISH
	.string "{PLAYER}'s POKéDEX was upgraded\n"
	.string "to the NATIONAL Mode!$"
	.else
	.ifdef GERMAN
	.string "Der POKéDEX von {PLAYER} wurde mit dem\n"
	.string "NATIONALEN MODUS ausgerüstet.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2:
	.ifdef ENGLISH
	.string "PROF. BIRCH: But listen.\n"
	.string "You've become the CHAMPION,\l"
	.string "but your POKéMON journey isn't over.\p"
	.string "There is no end to the road\n"
	.string "that is POKéMON.\p"
	.string "Somewhere, there is a grassy patch\n"
	.string "that's waiting for you!$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRK: Vergiss nicht! Du bist der\n"
	.string "CHAMP, aber deine POKéMON-Reise ist\l"
	.string "noch lange nicht zu Ende.\p"
	.string "Die Straße namens POKéMON findet\n"
	.string "niemals ein Ende.\p"
	.string "Irgendwo gibt es hohes Gras, das auf\n"
	.string "dich wartet.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork:
	.ifdef ENGLISH
	.string "MAY: I think I'll take a short break\n"
	.string "from fieldwork.\p"
	.string "I think I'll help the PROF here for\n"
	.string "a while.$"
	.else
	.ifdef GERMAN
	.string "MAIKE: Ich glaube, ich gönne mir eine\n"
	.string "kurze Pause von der Arbeit draußen.\p"
	.string "Ich werde dem PROF hier ein bisschen\n"
	.string "helfen.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork:
	.ifdef ENGLISH
	.string "BRENDAN: For the time being,\n"
	.string "I'm taking a break from fieldwork.\p"
	.string "I'll be helping out the PROF here\n"
	.string "for a while.$"
	.else
	.ifdef GERMAN
	.string "BRIX: Ich glaube, ich gönne mir eine\n"
	.string "kurze Pause von der Arbeit draußen.\p"
	.string "Ich werde dem PROF hier ein bisschen\n"
	.string "helfen.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon:
	.ifdef ENGLISH
	.string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
	.string "Let's have a look at your POKéDEX.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Yes, there's no doubt about it.\p"
	.string "You really have completed the HOENN\n"
	.string "region's POKéDEX.\p"
	.string "That's more than just impressive.\p"
	.string "I have a gift for you.\p"
	.string "Consider it my show of appreciation\n"
	.string "for the fantastic work you've done.\p"
	.string "My gift is a rare POKéMON only found\n"
	.string "in another region!\p"
	.string "You can have any one of these\n"
	.string "three POKéMON!$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRK: Oh, {PLAYER}{KUN}!\n"
	.string "Lass mich einen Blick auf deinen\l"
	.string "POKéDEX werfen.\p"
	.string "… … … … …\n"
	.string "…\l"
	.string "… … … … …\l"
	.string "…\p"
	.string "Ja, es besteht kein Zweifel.\p"
	.string "Dein POKéDEX der HOENN-Region ist\n"
	.string "vollständig!\p"
	.string "Das ist mehr als beeindruckend.\p"
	.string "Ich habe ein Geschenk für dich.\p"
	.string "Nimm es als Anerkennung der\n"
	.string "fantastischen Arbeit, die du geleistet\l"
	.string "hast.\p"
	.string "Ich schenke dir ein seltenes POKéMON,\n"
	.string "das nur in einer anderen Region zu\l"
	.string "finden ist.\p"
	.string "Such dir eines von diesen drei POKéMON\n"
	.string "aus.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon:
	.ifdef ENGLISH
	.string "PROF. BIRCH: These are rare POKéMON\n"
	.string "only found in another region!\p"
	.string "You can have any one of these\n"
	.string "three POKéMON!$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRK: Dies sind seltene POKéMON,\n"
	.string "die in anderen Regionen beheimatet\l"
	.string "sind.\p"
	.string "Such dir eines von den drei POKéMON\n"
	.string "aus.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil:
	.ifdef ENGLISH
	.string "PROF. BIRCH: The FIRE POKéMON\n"
	.string "CYNDAQUIL caught your eye!\p"
	.string "You're as sharp as ever!\p"
	.string "So the CYNDAQUIL is your choice?$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRK: Das FEUER-POKéMON\n"
	.string "FEURIGEL hat dein Interesse geweckt?\p"
	.string "Du bist clever wie immer!\p"
	.string "Du möchtest FEURIGEL haben?$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile:
	.ifdef ENGLISH
	.string "PROF. BIRCH: The WATER POKéMON\n"
	.string "TOTODILE is your choice!\p"
	.string "You know how to pick a good one.\p"
	.string "So, you'll take the TOTODILE?$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRK: Das WASSER-POKéMON\n"
	.string "KARNIMANI hat dein Interesse geweckt?\p"
	.string "Eine gute Wahl!\p"
	.string "Du möchtest KARNIMANI haben?$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita:
	.ifdef ENGLISH
	.string "PROF. BIRCH: The GRASS POKéMON\n"
	.string "CHIKORITA is your choice!\p"
	.string "You sure know what you're doing.\p"
	.string "So, you'll take the CHIKORITA?$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRK: Das PFLANZEN-POKéMON\n"
	.string "ENDIVIE hat dein Interesse geweckt?\p"
	.string "Du weißt, was gut für dich ist!\p"
	.string "Du möchtest ENDIVIE haben?$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable:
	.ifdef ENGLISH
	.string "PROF. BIRCH: Take your time before\n"
	.string "you decide.\p"
	.string "They're all invaluable POKéMON.$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRK: Lass dir Zeit, bevor du dich\n"
	.string "entscheidest.\p"
	.string "Es sind alles POKéMON von\n"
	.string "unschätzbarem Wert.$"
	.endif
	.endif

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_PickedFinePokemon:
	.ifdef ENGLISH
	.string "PROF. BIRCH: I see!\n"
	.string "You picked a fine POKéMON!$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRCH: I see!\n"
	.string "You picked a fine POKéMON!$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter:
	.ifdef ENGLISH
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from PROF. BIRCH!$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} erhält\n"
	.string "{STR_VAR_1} von PROF. BIRK!$"
	.endif
	.endif

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_NicknameJohtoStarter:
	.ifdef ENGLISH
	.string "Want to give a nickname to\n"
	.string "the {STR_VAR_1} you received?$"
	.else
	.ifdef GERMAN
	.string "Want to give a nickname to\n"
	.string "the {STR_VAR_1} you received?$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting:
	.ifdef ENGLISH
	.string "PROF. BIRCH: Listen, {PLAYER}{KUN}.\n"
	.string "You've completed the HOENN POKéDEX,\l"
	.string "but your POKéMON journey isn't over.\p"
	.string "There is no end to the road\n"
	.string "that is POKéMON.\p"
	.string "Somewhere, there is a grassy patch\n"
	.string "that's waiting for you!$"
	.else
	.ifdef GERMAN
	.string "PROF. BIRK: Vergiss nicht! Dein\n"
	.string "HOENN-POKéDEX ist vollständig.\p"
	.string "Die Straße namens POKéMON findet\n"
	.string "niemals ein Ende.\p"
	.string "Irgendwo gibt es hohes Gras, das auf\n"
	.string "dich wartet.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone:
	.ifdef ENGLISH
	.string "You received the promised POKéMON.\n"
	.string "Better leave the others alone.$"
	.else
	.ifdef GERMAN
	.string "Du hast das POKéMON erhalten.\n"
	.string "Lass die anderen lieber in Ruhe.$"
	.endif
	.endif

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_DontHaveAnyRoomForPokemon:
	.ifdef ENGLISH
	.string "Oh, you don't have any room for\n"
	.string "this POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Oh, you don’t have any room for\n"
	.string "this POKéMON.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere:
	.ifdef ENGLISH
	.string "MAY: {PLAYER}{KUN}, after this…\n"
	.string "What are you going to do?\p"
	.string "Are you going to keep battling\n"
	.string "and sharpening your skills?\p"
	.string "Or are you going to try filling\n"
	.string "the NATIONAL POKéDEX?\p"
	.string "I'm staying here to help the PROF.$"
	.else
	.ifdef GERMAN
	.string "MAIKE: {PLAYER}{KUN}, jetzt…\n"
	.string "Was wirst du jetzt tun?\p"
	.string "Wirst du weiter in Kämpfen antreten\n"
	.string "und deine Fähigkeiten verbessern?\p"
	.string "Oder versuchst du, den NATIONALEN\n"
	.string "POKéDEX vollständig zu bekommen?\p"
	.string "Ich werde hier bleiben und dem PROF\n"
	.string "helfen.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly:
	.ifdef ENGLISH
	.string "BRENDAN: Rather than collecting\n"
	.string "POKéMON, I prefer slowly and \l"
	.string "steadily raising the one I chose.$"
	.else
	.ifdef GERMAN
	.string "BRIX: Statt nur POKéMON zu sammeln,\n"
	.string "konzentriere ich mich lieber auf das\l"
	.string "Aufziehen eines bestimmten POKéMON.$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier:
	.ifdef ENGLISH
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\n"
	.string "Have you gone to that place,\l"
	.string "the BATTLE FRONTIER?$"
	.else
	.ifdef GERMAN
	.string "MAIKE: Oh, hi {PLAYER}{KUN}!\n"
	.string "Hast du schon die KAMPFZONE\l"
	.string "besucht?$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier:
	.ifdef ENGLISH
	.string "BRENDAN: Hey, {PLAYER}!\n"
	.string "Have you gone out to that place,\l"
	.string "the BATTLE FRONTIER?$"
	.else
	.ifdef GERMAN
	.string "BRIX: Hey, {PLAYER}!\n"
	.string "Hast du schon die KAMPFZONE\l"
	.string "besucht?$"
	.endif
	.endif

LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall:
	.ifdef ENGLISH
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "SCOTT: Hi, hi, {PLAYER}!\n"
	.string "It's me, SCOTT.\p"
	.string "I'm aboard the S.S. TIDAL now.\n"
	.string "It feels great to be on the sea!\p"
	.string "By the way…\p"
	.string "There's this place that I'd like to\n"
	.string "invite you to for a visit.\p"
	.string "If you're interested, board a ferry\n"
	.string "at either SLATEPORT or LILYCOVE.\p"
	.string "I'll fill you in on the details when\n"
	.string "we meet. I'll be waiting!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"
	.else
	.ifdef GERMAN
	.string "… … … … …\n"
	.string "…\l"
	.string "… … … … …Piep!\p"
	.string "SCOTT: Hallo {PLAYER}!\n"
	.string "Ich bin’s, SCOTT.\p"
	.string "Ich bin auf der MS TIDE. Auf See zu\n"
	.string "sein ist einfach großartig!\p"
	.string "Übrigens…\p"
	.string "Ich würde dich gerne an einen\n"
	.string "bestimmten Ort einladen.\p"
	.string "Wenn du interessiert bist, dann\n"
	.string "nimm entweder in GRAPHITPORT oder\l"
	.string "SEEGRASULB die Fähre.\p"
	.string "Alles Weitere besprechen wir, wenn\n"
	.string "wir uns an Bord treffen. Bis dann!\p"
	.string "… … … … …\n"
	.string "…\l"
	.string "… … … … …Klick!$"
	.endif
	.endif
