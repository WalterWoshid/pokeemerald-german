.set LOCALID_MC, 1
.set LOCALID_JUDGE, 2
.set LOCALID_CONTESTANT_1, 3
.set LOCALID_CONTESTANT_2, 4
.set LOCALID_CONTESTANT_3, 5
.set LOCALID_AUDIENCE_1, 6
.set LOCALID_AUDIENCE_3, 7
.set LOCALID_AUDIENCE_4, 8
.set LOCALID_AUDIENCE_5, 9
.set LOCALID_AUDIENCE_6, 10
.set LOCALID_AUDIENCE_7, 11
.set LOCALID_AUDIENCE_2, 12
.set LOCALID_POKEBALL, 13
.set LOCALID_CONTESTANT_4, 14
.set LOCALID_ARTIST, 15

@ Either ends or returns to EventScript_ContestReceptionist after submitting a contest entry
LilycoveCity_ContestLobby_EventScript_SpeakToContestReceptionist::
	lock
	faceplayer
	goto_if_ne VAR_CONTEST_PRIZE_PICKUP, 0, LilycoveCity_ContestLobby_EventScript_PickUpPrize
	call_if_set FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_ReceptionWelcome
	call_if_unset FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_GivePokeblockCase
	goto LilycoveCity_ContestLobby_EventScript_AskEnterContest
	end

LilycoveCity_ContestLobby_EventScript_ReceptionWelcome::
	msgbox LilycoveCity_ContestLobby_Text_ContestReception, MSGBOX_DEFAULT
	return

LilycoveCity_ContestLobby_EventScript_GivePokeblockCase::
	msgbox LilycoveCity_ContestLobby_Text_ReceptionDontHavePokeblockCase, MSGBOX_DEFAULT
	giveitem ITEM_POKEBLOCK_CASE
	setflag FLAG_RECEIVED_POKEBLOCK_CASE
	msgbox LilycoveCity_ContestLobby_Text_NowThatWeveClearedThatUp, MSGBOX_DEFAULT
	return

LilycoveCity_ContestLobby_EventScript_PickUpPrize::
	msgbox LilycoveCity_ContestLobby_Text_PokemonWonWeHavePrize, MSGBOX_DEFAULT
	switch VAR_CONTEST_PRIZE_PICKUP
	case 4, LilycoveCity_ContestLobby_EventScript_GiveLuxuryBallAtCounter
	end

LilycoveCity_ContestLobby_EventScript_GiveLuxuryBallAtCounter::
	giveitem ITEM_LUXURY_BALL
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_ContestLobby_EventScript_NoRoomForLuxuryBallAtCounter
	setvar VAR_CONTEST_PRIZE_PICKUP, 0
	closemessage
	release
	end

LilycoveCity_ContestLobby_EventScript_NoRoomForLuxuryBallAtCounter::
	call Common_EventScript_BagIsFull
	msgbox LilycoveCity_ContestLobby_Text_ComeBackForPrizeLater, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_AskEnterContest::
	message LilycoveCity_ContestLobby_Text_EnterContest1
	waitmessage
	multichoice 0, 0, MULTI_ENTERINFO, FALSE
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_ChooseContestRank
	case 1, LilycoveCity_ContestLobby_EventScript_ContestInfo
	case 2, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	end

LilycoveCity_ContestLobby_EventScript_ContestInfo::
	message LilycoveCity_ContestLobby_Text_WhichTopic1
	waitmessage
	multichoice 0, 0, MULTI_CONTEST_INFO, FALSE
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_ExplainContests
	case 1, LilycoveCity_ContestLobby_EventScript_ExplainContestTypes
	case 2, LilycoveCity_ContestLobby_EventScript_ExplainContestRanks
	case 3, LilycoveCity_ContestLobby_EventScript_AskEnterContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_AskEnterContest
	end

LilycoveCity_ContestLobby_EventScript_ExplainContests::
	msgbox LilycoveCity_ContestLobby_Text_ExplainContests, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ContestInfo
	end

LilycoveCity_ContestLobby_EventScript_ExplainContestTypes::
	msgbox LilycoveCity_ContestLobby_Text_ExplainContestTypes, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ContestInfo
	end

LilycoveCity_ContestLobby_EventScript_ExplainContestRanks::
	msgbox LilycoveCity_ContestLobby_Text_ExplainContestRanks, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ContestInfo
	end

LilycoveCity_ContestLobby_EventScript_CancelEnterContest::
	msgbox LilycoveCity_ContestLobby_Text_ParticipateAnotherTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_ChooseContestMon::
	msgbox LilycoveCity_ContestLobby_Text_EnterWhichPokemon1, MSGBOX_DEFAULT
	choosecontestmon
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	special TryEnterContestMon
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST, LilycoveCity_ContestLobby_EventScript_CantEnterLowRank
	goto_if_eq VAR_RESULT, CAN_ENTER_CONTEST_EQUAL_RANK, LilycoveCity_ContestLobby_EventScript_EnterMon
	goto_if_eq VAR_RESULT, CAN_ENTER_CONTEST_HIGH_RANK, LilycoveCity_ContestLobby_EventScript_ConfirmEntryAlreadyWon
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST_EGG, LilycoveCity_ContestLobby_EventScript_CantEnterEgg
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST_FAINTED, LilycoveCity_ContestLobby_EventScript_CantEnterFainted
	end

LilycoveCity_ContestLobby_EventScript_ChooseContestRank::
	message LilycoveCity_ContestLobby_Text_EnterWhichRank
	waitmessage
	multichoice 0, 0, MULTI_CONTEST_RANK, FALSE
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_EnterNormalRank
	case 1, LilycoveCity_ContestLobby_EventScript_EnterSuperRank
	case 2, LilycoveCity_ContestLobby_EventScript_EnterHyperRank
	case 3, LilycoveCity_ContestLobby_EventScript_EnterMasterRank
	case 4, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	end

LilycoveCity_ContestLobby_EventScript_EnterNormalRank::
	setvar VAR_CONTEST_RANK, CONTEST_RANK_NORMAL
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestType
	end

LilycoveCity_ContestLobby_EventScript_EnterSuperRank::
	setvar VAR_CONTEST_RANK, CONTEST_RANK_SUPER
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestType
	end

LilycoveCity_ContestLobby_EventScript_EnterHyperRank::
	setvar VAR_CONTEST_RANK, CONTEST_RANK_HYPER
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestType
	end

LilycoveCity_ContestLobby_EventScript_EnterMasterRank::
	setvar VAR_CONTEST_RANK, CONTEST_RANK_MASTER
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestType
	end

@ The multichoice selection IDs are equal to the CATEGORY values
@ So rather than list the cases they just copy VAR_RESULT for a valid selection into VAR_CONTEST_CATEGORY
LilycoveCity_ContestLobby_EventScript_ChooseContestType::
	message LilycoveCity_ContestLobby_Text_EnterWhichContest1
	waitmessage
	multichoice 0, 0, MULTI_CONTEST_TYPE, FALSE
	switch VAR_RESULT
	case 5, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
	copyvar VAR_CONTEST_CATEGORY, VAR_RESULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	end

LilycoveCity_ContestLobby_EventScript_CantEnterLowRank::
	msgbox LilycoveCity_ContestLobby_Text_MonNotQualifiedForRank, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	release
	end

@ Unused
LilycoveCity_ContestLobby_EventScript_ConfirmEntry::
	msgbox LilycoveCity_ContestLobby_Text_ConfirmContestMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	case YES, LilycoveCity_ContestLobby_EventScript_EnterMon
	end

LilycoveCity_ContestLobby_EventScript_ConfirmEntryAlreadyWon::
	msgbox LilycoveCity_ContestLobby_Text_AlreadyWonEnterAnyway, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	case YES, LilycoveCity_ContestLobby_EventScript_EnterMon
	end

LilycoveCity_ContestLobby_EventScript_CantEnterEgg::
	msgbox LilycoveCity_ContestLobby_Text_EggCannotTakePart, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	release
	end

LilycoveCity_ContestLobby_EventScript_CantEnterFainted::
	msgbox LilycoveCity_ContestLobby_Text_MonInNoConditionForContest, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestMon
	release
	end

@ The return here is back to LilycoveCity_ContestLobby_EventScript_ContestReceptionist
LilycoveCity_ContestLobby_EventScript_EnterMon::
	msgbox LilycoveCity_ContestLobby_Text_YourMonIsEntryNum4, MSGBOX_DEFAULT
	closemessage
	releaseall
	setvar VAR_CONTEST_HALL_STATE, 1
	return

ContestHall_EventScript_DoContest::
	special LinkContestTryShowWirelessIndicator
	setvar VAR_0x8006, 0
	lockall
	applymovement LOCALID_CONTESTANT_4, ContestHall_Movement_Player4FaceUp
	waitmovement 0
	applymovement LOCALID_MC, ContestHall_Movement_MCWalkDown
	waitmovement 0
	releaseall
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_GetContestRankStringId
	call ContestHall_EventScript_GetContestCategory
	call ContestHall_EventScript_ContestGettingStarted
	call ContestHall_EventScript_ShowContestMons
	call ContestHall_EventScript_DoContestAppeals
	call ContestHall_EventScript_ContestResults
	call ContestHall_EventScript_GetWinnerObjEventId
	call ContestHall_EventScript_CongratulateWinner
	call ContestHall_EventScript_AudienceLookAround
	call ContestHall_EventScript_GiveWinnerPrize
	setvar VAR_CONTEST_HALL_STATE, 2
	return

ContestHall_EventScript_GetContestRankStringId::
	switch VAR_CONTEST_RANK
	case CONTEST_RANK_NORMAL, ContestHall_EventScript_GetNormalStringId
	case CONTEST_RANK_SUPER, ContestHall_EventScript_GetSuperStringId
	case CONTEST_RANK_HYPER, ContestHall_EventScript_GetHyperStringId
	case CONTEST_RANK_MASTER, ContestHall_EventScript_GetMasterStringId
	return

ContestHall_EventScript_GetNormalStringId::
	setvar VAR_0x8009, STDSTRING_NORMAL
	return

ContestHall_EventScript_GetSuperStringId::
	setvar VAR_0x8009, STDSTRING_SUPER
	return

ContestHall_EventScript_GetHyperStringId::
	setvar VAR_0x8009, STDSTRING_HYPER
	return

ContestHall_EventScript_GetMasterStringId::
	setvar VAR_0x8009, STDSTRING_MASTER
	return

@ This whole switch is equivalent to copyvar VAR_0x8008, VAR_CONTEST_CATEGORY
ContestHall_EventScript_GetContestCategory::
	switch VAR_CONTEST_CATEGORY
	case CONTEST_CATEGORY_COOL, ContestHall_EventScript_GetCategoryCool
	case CONTEST_CATEGORY_BEAUTY, ContestHall_EventScript_GetCategoryBeauty
	case CONTEST_CATEGORY_CUTE, ContestHall_EventScript_GetCategoryCute
	case CONTEST_CATEGORY_SMART, ContestHall_EventScript_GetCategorySmart
	case CONTEST_CATEGORY_TOUGH, ContestHall_EventScript_GetCategoryTough
	return

ContestHall_EventScript_GetCategoryCool::
	setvar VAR_0x8008, CONTEST_CATEGORY_COOL
	return

ContestHall_EventScript_GetCategoryBeauty::
	setvar VAR_0x8008, CONTEST_CATEGORY_BEAUTY
	return

ContestHall_EventScript_GetCategoryCute::
	setvar VAR_0x8008, CONTEST_CATEGORY_CUTE
	return

ContestHall_EventScript_GetCategorySmart::
	setvar VAR_0x8008, CONTEST_CATEGORY_SMART
	return

ContestHall_EventScript_GetCategoryTough::
	setvar VAR_0x8008, CONTEST_CATEGORY_TOUGH
	return

ContestHall_EventScript_ContestGettingStarted::
	buffercontestname STR_VAR_2, VAR_0x8008
	bufferstdstring STR_VAR_3, VAR_0x8009
	call ContestHall_EventScript_GettingStarted
	lockall
	applymovement LOCALID_MC, ContestHall_Movement_MCBackUp
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_GettingStarted::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_GettingStartedLink
	lockall
	msgbox ContestHall_Text_GettingStartedParticipantsAsFollows, MSGBOX_DEFAULT
	releaseall
	return

ContestHall_EventScript_GettingStartedLink::
	specialvar VAR_RESULT, IsWirelessContest
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_GettingStartedWireless
	messageautoscroll ContestHall_Text_GettingStartedParticipantsAsFollowsLink
	waitmessage
	return

ContestHall_EventScript_GettingStartedWireless::
	messageautoscroll ContestHall_Text_GettingStartedWireless
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_ParticipantsAsFollows
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	return

ContestHall_EventScript_ShowContestMons::
	call ContestHall_EventScript_ContestantWalkToCenter
	call ContestHall_EventScript_ShowContestMonPic
	call ContestHall_EventScript_AudienceHeartEmotes
	call ContestHall_EventScript_AudienceReactToContestant
	call ContestHall_EventScript_ContestantReturn
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_TryWaitForLink
	addvar VAR_0x8006, 1
	goto_if_ne VAR_0x8006, CONTESTANT_COUNT, ContestHall_EventScript_ShowContestMons
	call ContestHall_EventScript_AudienceVote
	setvar VAR_TEMP_1, 6
	return

ContestHall_EventScript_TryWaitForLink::
	specialvar VAR_RESULT, IsWirelessContest
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_WaitForLink
	return

ContestHall_EventScript_WaitForLink::
	special LinkContestWaitForConnection
	waitstate
	return

ContestHall_EventScript_ContestantWalkToCenter::
	goto_if_eq VAR_0x8006, 0, ContestHall_EventScript_Player1WalkToCenter
	goto_if_eq VAR_0x8006, 1, ContestHall_EventScript_Player2WalkToCenter
	goto_if_eq VAR_0x8006, 2, ContestHall_EventScript_Player3WalkToCenter
	goto_if_eq VAR_0x8006, 3, ContestHall_EventScript_Player4WalkToCenter
	return

ContestHall_EventScript_Player1WalkToCenter::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement LOCALID_CONTESTANT_1, ContestHall_Movement_Player1WalkToCenter
	waitmovement 0
	releaseall
	setvar VAR_0x800B, LOCALID_CONTESTANT_1
	return

ContestHall_EventScript_Player2WalkToCenter::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement LOCALID_CONTESTANT_2, ContestHall_Movement_Player2WalkToCenter
	waitmovement 0
	releaseall
	setvar VAR_0x800B, LOCALID_CONTESTANT_2
	return

ContestHall_EventScript_Player3WalkToCenter::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement LOCALID_CONTESTANT_3, ContestHall_Movement_Player3WalkToCenter
	waitmovement 0
	releaseall
	setvar VAR_0x800B, LOCALID_CONTESTANT_3
	return

ContestHall_EventScript_Player4WalkToCenter::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement LOCALID_CONTESTANT_4, ContestHall_Movement_Player4WalkToCenter
	waitmovement 0
	releaseall
	setvar VAR_0x800B, LOCALID_CONTESTANT_4
	return

ContestHall_EventScript_ShowContestMonPic::
	special BufferContestTrainerAndMonNames
	addvar VAR_0x8006, 1
	buffernumberstring STR_VAR_2, VAR_0x8006
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_ContestantDelay32
	waitmovement 0
	releaseall
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_CheckIfContestWithRSPlayer
	addobject LOCALID_POKEBALL
	playse SE_LEDGE
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_ContestantDelay32
	waitmovement 0
	releaseall
	addvar VAR_0x8006, -1
	playse SE_BALL_OPEN
	special ShowContestEntryMonPic
	call ContestHall_EventScript_EntryXTrainersMon
	return

ContestHall_EventScript_EntryXTrainersMon::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_EntryXTrainersMonLink
	message ContestHall_Text_EntryXTrainersMon
	waitmessage
	return

ContestHall_EventScript_EntryXTrainersMonLink::
	messageautoscroll ContestHall_Text_EntryXTrainersMon
	waitmessage
	return

ContestHall_EventScript_AudienceVote::
	call ContestHall_EventScript_AudienceWillVote
	call ContestHall_EventScript_VotingUnderWay
	playse SE_M_ENCORE2
	waitmessage
	call ContestHall_EventScript_AudienceLookAround
	applymovement LOCALID_MC, ContestHall_Movement_MCFaceJudge2
	waitmovement 0
	applymovement LOCALID_JUDGE, ContestHall_Movement_JudgeFaceMC
	waitmovement 0
	delay 20
	applymovement LOCALID_MC, ContestHall_Movement_FaceContestants
	applymovement LOCALID_JUDGE, ContestHall_Movement_FaceContestants
	waitmovement 0
	return

ContestHall_EventScript_AudienceWillVote::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_AudienceWillVoteLink
	msgbox ContestHall_Text_SeenContestantsAudienceWillVote, MSGBOX_DEFAULT
	return

ContestHall_EventScript_AudienceWillVoteLink::
	specialvar VAR_RESULT, IsWirelessContest
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_AudienceWillVoteWireless
	messageautoscroll ContestHall_Text_SeenContestantsAudienceWillVote
	waitmessage
	return

ContestHall_EventScript_AudienceWillVoteWireless::
	messageautoscroll ContestHall_Text_WeveSeenContestants
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_AudienceWillVote
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_LetVotingBegin
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	return

ContestHall_EventScript_VotingUnderWay::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_VotingUnderWayLink
	message ContestHall_Text_VotingUnderWay
	return

ContestHall_EventScript_VotingUnderWayLink::
	messageautoscroll ContestHall_Text_VotingUnderWay
	call ContestHall_EventScript_TryWaitForLink
	return

ContestHall_EventScript_AudienceReactToContestant::
	call ContestHall_EventScript_TryWaitForLink
	applymovement LOCALID_MC, ContestHall_Movement_AudienceMemberLookLeft
	waitmovement 0
	playse SE_M_ENCORE2
	call ContestHall_EventScript_VObjectAudienceLookAround
	applymovement LOCALID_AUDIENCE_5, ContestHall_Movement_AudienceMemberLookRight
	applymovement LOCALID_AUDIENCE_2, ContestHall_Movement_AudienceMemberLookDown
	applymovement LOCALID_AUDIENCE_3, ContestHall_Movement_AudienceMemberLookRight
	waitmovement 0
	applymovement LOCALID_MC, ContestHall_Movement_AudienceMemberLookRight
	waitmovement 0
	applymovement LOCALID_AUDIENCE_6, ContestHall_Movement_AudienceMemberLookLeft
	applymovement LOCALID_AUDIENCE_7, ContestHall_Movement_AudienceMemberLookDown
	applymovement LOCALID_AUDIENCE_1, ContestHall_Movement_AudienceMemberLookUp
	applymovement LOCALID_AUDIENCE_4, ContestHall_Movement_AudienceMemberLookLeft
	waitmovement 0
	applymovement LOCALID_MC, ContestHall_Movement_MCLookAtJudge
	waitmovement 0
	applymovement LOCALID_MC, ContestHall_Movement_MCWalkInPlaceDown
	applymovement LOCALID_JUDGE, ContestHall_Movement_JudgeLookAtMC
	waitmovement 0
	releaseall
	call ContestHall_EventScript_TryWaitForLink
	return

@ For below VAR_TEMP_0 is the number of heart emotes to try to display in the audience
@ The number of hearts to try to display is based on the condition of the presented pokemon and the rank
@ For each heart to display a random audience member is chosen, and a new one chosen if they already displayed a heart
@ VAR_TEMP_1 through VAR_TEMP_8 represent each of the 8 audience members that are actual object events
@    and are set to 9 if they havent displayed a heart yet, and 1 if they have
ContestHall_EventScript_AudienceHeartEmotes::
	special GetContestMonCondition
	call_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_NORMAL, ContestHall_EventScript_GetNumberOfHeartsNormal
	call_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_SUPER, ContestHall_EventScript_GetNumberOfHeartsSuper
	call_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_HYPER, ContestHall_EventScript_GetNumberOfHeartsHyper
	call_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_MASTER, ContestHall_EventScript_GetNumberOfHeartsMaster
	call_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_GetNumberOfHeartsLink
	setvar VAR_TEMP_1, 9
	setvar VAR_TEMP_2, 9
	setvar VAR_TEMP_3, 9
	setvar VAR_TEMP_4, 9
	setvar VAR_TEMP_5, 9
	setvar VAR_TEMP_6, 9
	setvar VAR_TEMP_7, 9
	setvar VAR_TEMP_8, 9
	call_if_gt VAR_TEMP_0, 0, ContestHall_EventScript_DisplayHearts
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_6, 0
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	return

ContestHall_EventScript_DisplayHearts::
	setvar VAR_RESULT, 8
	special GenerateContestRand
	call_if_eq VAR_RESULT, 0, ContestHall_EventScript_TryDisplayHeartAudienceMember1
	call_if_eq VAR_RESULT, 1, ContestHall_EventScript_TryDisplayHeartAudienceMember2
	call_if_eq VAR_RESULT, 2, ContestHall_EventScript_TryDisplayHeartAudienceMember3
	call_if_eq VAR_RESULT, 3, ContestHall_EventScript_TryDisplayHeartAudienceMember4
	call_if_eq VAR_RESULT, 4, ContestHall_EventScript_TryDisplayHeartAudienceMember5
	call_if_eq VAR_RESULT, 5, ContestHall_EventScript_TryDisplayHeartAudienceMember6
	call_if_eq VAR_RESULT, 6, ContestHall_EventScript_TryDisplayHeartAudienceMember7
	call_if_eq VAR_RESULT, 7, ContestHall_EventScript_TryDisplayHeartAudienceMember8
	goto_if_gt VAR_TEMP_0, 0, ContestHall_EventScript_DisplayHearts  @ Still more hearts to display
	waitmovement 0
	return

ContestHall_EventScript_GetNumberOfHeartsNormal::
	goto_if_gt VAR_0x8004, 80, ContestHall_EventScript_Set8Hearts
	goto_if_gt VAR_0x8004, 70, ContestHall_EventScript_Set7Hearts
	goto_if_gt VAR_0x8004, 60, ContestHall_EventScript_Set6Hearts
	goto_if_gt VAR_0x8004, 50, ContestHall_EventScript_Set5Hearts
	goto_if_gt VAR_0x8004, 40, ContestHall_EventScript_Set4Hearts
	goto_if_gt VAR_0x8004, 30, ContestHall_EventScript_Set3Hearts
	goto_if_gt VAR_0x8004, 20, ContestHall_EventScript_Set2Hearts
	goto_if_gt VAR_0x8004, 10, ContestHall_EventScript_Set1Heart
	setvar VAR_TEMP_0, 0
	return

ContestHall_EventScript_GetNumberOfHeartsSuper::
	goto_if_gt VAR_0x8004, 230, ContestHall_EventScript_Set8Hearts
	goto_if_gt VAR_0x8004, 210, ContestHall_EventScript_Set7Hearts
	goto_if_gt VAR_0x8004, 190, ContestHall_EventScript_Set6Hearts
	goto_if_gt VAR_0x8004, 170, ContestHall_EventScript_Set5Hearts
	goto_if_gt VAR_0x8004, 150, ContestHall_EventScript_Set4Hearts
	goto_if_gt VAR_0x8004, 130, ContestHall_EventScript_Set3Hearts
	goto_if_gt VAR_0x8004, 110, ContestHall_EventScript_Set2Hearts
	goto_if_gt VAR_0x8004, 90, ContestHall_EventScript_Set1Heart
	setvar VAR_TEMP_0, 0
	return

ContestHall_EventScript_GetNumberOfHeartsHyper::
	goto_if_gt VAR_0x8004, 380, ContestHall_EventScript_Set8Hearts
	goto_if_gt VAR_0x8004, 350, ContestHall_EventScript_Set7Hearts
	goto_if_gt VAR_0x8004, 320, ContestHall_EventScript_Set6Hearts
	goto_if_gt VAR_0x8004, 290, ContestHall_EventScript_Set5Hearts
	goto_if_gt VAR_0x8004, 260, ContestHall_EventScript_Set4Hearts
	goto_if_gt VAR_0x8004, 230, ContestHall_EventScript_Set3Hearts
	goto_if_gt VAR_0x8004, 200, ContestHall_EventScript_Set2Hearts
	goto_if_gt VAR_0x8004, 170, ContestHall_EventScript_Set1Heart
	setvar VAR_TEMP_0, 0
	return

ContestHall_EventScript_GetNumberOfHeartsMaster::
	goto_if_gt VAR_0x8004, 600, ContestHall_EventScript_Set8Hearts
	goto_if_gt VAR_0x8004, 560, ContestHall_EventScript_Set7Hearts
	goto_if_gt VAR_0x8004, 520, ContestHall_EventScript_Set6Hearts
	goto_if_gt VAR_0x8004, 480, ContestHall_EventScript_Set5Hearts
	goto_if_gt VAR_0x8004, 440, ContestHall_EventScript_Set4Hearts
	goto_if_gt VAR_0x8004, 400, ContestHall_EventScript_Set3Hearts
	goto_if_gt VAR_0x8004, 360, ContestHall_EventScript_Set2Hearts
	goto_if_gt VAR_0x8004, 320, ContestHall_EventScript_Set1Heart
	setvar VAR_TEMP_0, 0
	return

ContestHall_EventScript_GetNumberOfHeartsLink::
	goto_if_gt VAR_0x8004, 600, ContestHall_EventScript_Set8Hearts
	goto_if_gt VAR_0x8004, 550, ContestHall_EventScript_Set7Hearts
	goto_if_gt VAR_0x8004, 500, ContestHall_EventScript_Set6Hearts
	goto_if_gt VAR_0x8004, 450, ContestHall_EventScript_Set5Hearts
	goto_if_gt VAR_0x8004, 400, ContestHall_EventScript_Set4Hearts
	goto_if_gt VAR_0x8004, 300, ContestHall_EventScript_Set3Hearts
	goto_if_gt VAR_0x8004, 200, ContestHall_EventScript_Set2Hearts
	goto_if_gt VAR_0x8004, 100, ContestHall_EventScript_Set1Heart
	setvar VAR_TEMP_0, 0
	return

ContestHall_EventScript_Set1Heart::
	setvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_Set2Hearts::
	setvar VAR_TEMP_0, 2
	return

ContestHall_EventScript_Set3Hearts::
	setvar VAR_TEMP_0, 3
	return

ContestHall_EventScript_Set4Hearts::
	setvar VAR_TEMP_0, 4
	return

ContestHall_EventScript_Set5Hearts::
	setvar VAR_TEMP_0, 5
	return

ContestHall_EventScript_Set6Hearts::
	setvar VAR_TEMP_0, 6
	return

ContestHall_EventScript_Set7Hearts::
	setvar VAR_TEMP_0, 7
	return

ContestHall_EventScript_Set8Hearts::
	setvar VAR_TEMP_0, 8
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember1::
	goto_if_eq VAR_TEMP_1, 1, ContestHall_EventScript_AudienceMember1AlreadyEmoted
	applymovement LOCALID_AUDIENCE_1, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_1, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember1AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember2::
	goto_if_eq VAR_TEMP_2, 1, ContestHall_EventScript_AudienceMember2AlreadyEmoted
	applymovement LOCALID_AUDIENCE_2, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_2, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember2AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember3::
	goto_if_eq VAR_TEMP_3, 1, ContestHall_EventScript_AudienceMember3AlreadyEmoted
	applymovement LOCALID_AUDIENCE_3, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_3, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember3AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember4::
	goto_if_eq VAR_TEMP_4, 1, ContestHall_EventScript_Audience4MemberAlreadyEmoted
	applymovement LOCALID_AUDIENCE_4, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_4, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_Audience4MemberAlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember5::
	goto_if_eq VAR_TEMP_5, 1, ContestHall_EventScript_AudienceMember5AlreadyEmoted
	applymovement LOCALID_AUDIENCE_5, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_5, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember5AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember6::
	goto_if_eq VAR_TEMP_6, 1, ContestHall_EventScript_AudienceMember6AlreadyEmoted
	applymovement LOCALID_AUDIENCE_6, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_6, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember6AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember7::
	goto_if_eq VAR_TEMP_7, 1, ContestHall_EventScript_AudienceMember7AlreadyEmoted
	applymovement LOCALID_AUDIENCE_7, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_7, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember7AlreadyEmoted::
	return

ContestHall_EventScript_TryDisplayHeartAudienceMember8::
	goto_if_eq VAR_TEMP_8, 1, ContestHall_EventScript_AudienceMember8AlreadyEmoted
	applymovement LOCALID_ARTIST, ContestHall_Movement_Heart
	playse SE_PIN
	delay 14
	setvar VAR_TEMP_8, 1
	addvar VAR_TEMP_0, -1
	return

ContestHall_EventScript_AudienceMember8AlreadyEmoted::
	return

ContestHall_EventScript_ContestantReturn::
	closemessage
	release
	removeobject LOCALID_POKEBALL
	special HideContestEntryMonPic
	call ContestHall_EventScript_TryWaitForLink
	switch VAR_0x8006
	case 0, ContestHall_EventScript_Player1WalkBack
	case 1, ContestHall_EventScript_Player2WalkBack
	case 2, ContestHall_EventScript_Player3WalkBack
	case 3, ContestHall_EventScript_Player4WalkBack
	return

ContestHall_EventScript_Player1WalkBack::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_Player1WalkBack
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player2WalkBack::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_Player2WalkBack
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player3WalkBack::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_Player3WalkBack
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player4WalkBack::
	call ContestHall_EventScript_TryWaitForLink
	lockall
	applymovement VAR_0x800B, ContestHall_Movement_Player4WalkBack
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_DoContestAppeals::
	lockall
	applymovement LOCALID_MC, ContestHall_Movement_FaceContestants2
	waitmovement 0
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_LetsAppeal
	waitmessage
	applymovement LOCALID_MC, ContestHall_Movement_WalkStageLeft
	applymovement LOCALID_JUDGE, ContestHall_Movement_WalkStageRight
	waitmovement 0
	releaseall
	call ContestHall_EventScript_TryWaitForLink
	setvar VAR_TEMP_9, 1
	special LinkContestTryHideWirelessIndicator
	startcontest
	special LinkContestTryShowWirelessIndicator
	setvar VAR_TEMP_9, 0
	lockall
	applymovement LOCALID_MC, ContestHall_Movement_WalkStageRight
	applymovement LOCALID_JUDGE, ContestHall_Movement_WalkStageLeft
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_LetsAppeal::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_LetsAppealLink
	msgbox ContestHall_Text_VotingCompleteLetsAppeal, MSGBOX_DEFAULT
	return

ContestHall_EventScript_LetsAppealLink::
	specialvar VAR_RESULT, IsWirelessContest
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_LetsAppealWireless
	messageautoscroll ContestHall_Text_VotingCompleteLetsAppeal
	waitmessage
	return

ContestHall_EventScript_LetsAppealWireless::
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_VotingComplete
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_SecondStageOfJudging
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_LetsAppeal
	waitmessage
	call ContestHall_EventScript_TryWaitForLink
	return

ContestHall_EventScript_ContestResults::
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_ThatsItForJudging
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_ThankYouForAppeals
	call ContestHall_EventScript_TryWaitForLink
	applymovement LOCALID_MC, ContestHall_Movement_MCFaceJudge
	waitmovement 0
	call ContestHall_EventScript_JudgeLooksReady
	call ContestHall_EventScript_TryWaitForLink
	call ContestHall_EventScript_WeWillDeclareWinner
	call ContestHall_EventScript_TryWaitForLink
	applymovement LOCALID_MC, ContestHall_Movement_FaceContestants
	waitmovement 0
	closemessage
	releaseall
	special LinkContestTryHideWirelessIndicator
	setvar VAR_TEMP_9, 1
	showcontestresults
	setvar VAR_TEMP_9, 0
	playbgm MUS_CONTEST_WINNER, FALSE
	return

ContestHall_EventScript_ThatsItForJudging::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_ThatsItForJudgingLink
	msgbox ContestHall_Text_ThatsItForJudging, MSGBOX_DEFAULT
	return

ContestHall_EventScript_ThatsItForJudgingLink::
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_ThatsItForJudging
	waitmessage
	delay 30
	return

ContestHall_EventScript_ThankYouForAppeals::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_ThankYouForAppealsLink
	msgbox ContestHall_Text_ThankYouForAppeals, MSGBOX_DEFAULT
	return

ContestHall_EventScript_ThankYouForAppealsLink::
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_ThankYouForAppeals
	waitmessage
	delay 30
	return

ContestHall_EventScript_JudgeLooksReady::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_JudgeLooksReadyLink
	msgbox ContestHall_Text_JudgeLooksReady, MSGBOX_DEFAULT
	return

ContestHall_EventScript_JudgeLooksReadyLink::
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_JudgeLooksReady
	waitmessage
	delay 30
	return

ContestHall_EventScript_WeWillDeclareWinner::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_WeWillDeclareWinnerLink
	msgbox ContestHall_Text_WeWillNowDeclareWinner, MSGBOX_DEFAULT
	return

ContestHall_EventScript_WeWillDeclareWinnerLink::
	call ContestHall_EventScript_TryWaitForLink
	messageautoscroll ContestHall_Text_WeWillNowDeclareWinner
	waitmessage
	delay 30
	return

ContestHall_EventScript_GetWinnerObjEventId::
	special GetContestWinnerId
	switch VAR_0x8005
	case 0, ContestHall_EventScript_GetPlayer1ObjEventId
	case 1, ContestHall_EventScript_GetPlayer2ObjEventId
	case 2, ContestHall_EventScript_GetPlayer3ObjEventId
	case 3, ContestHall_EventScript_GetPlayer4ObjEventId
	return

ContestHall_EventScript_GetPlayer1ObjEventId::
	setvar VAR_TEMP_3, LOCALID_CONTESTANT_1
	return

ContestHall_EventScript_GetPlayer2ObjEventId::
	setvar VAR_TEMP_3, LOCALID_CONTESTANT_2
	return

ContestHall_EventScript_GetPlayer3ObjEventId::
	setvar VAR_TEMP_3, LOCALID_CONTESTANT_3
	return

ContestHall_EventScript_GetPlayer4ObjEventId::
	setvar VAR_TEMP_3, LOCALID_CONTESTANT_4
	return

ContestHall_EventScript_CongratulateWinner::
	special BufferContestWinnerTrainerName
	special BufferContestWinnerMonName
	addvar VAR_0x8005, 1
	buffernumberstring STR_VAR_2, VAR_0x8005
	addvar VAR_0x8005, -1
	call ContestHall_EventScript_CongratsWinner
	applymovement VAR_TEMP_3, ContestHall_Movement_WinningPlayerWalkUp
	waitmovement 0
	playse SE_M_ENCORE2
	setvar VAR_TEMP_1, 0
	return

ContestHall_EventScript_CongratsWinner::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_CongratsWinnerLink
	msgbox ContestHall_Text_CongratsTrainerXandMon, MSGBOX_DEFAULT
	return

ContestHall_EventScript_CongratsWinnerLink::
	messageautoscroll ContestHall_Text_CongratsTrainerXandMon
	waitmessage
	return

ContestHall_EventScript_AudienceLookAround::
	addvar VAR_TEMP_1, 1
	lockall
	call_if_gt VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_NORMAL, ContestHall_EventScript_VObjectAudienceLookAround
	applymovement LOCALID_AUDIENCE_5, ContestHall_Movement_AudienceMemberLookRight
	applymovement LOCALID_AUDIENCE_2, ContestHall_Movement_AudienceMemberLookDown
	applymovement LOCALID_AUDIENCE_3, ContestHall_Movement_AudienceMemberLookRight
	delay 30
	applymovement LOCALID_AUDIENCE_6, ContestHall_Movement_AudienceMemberLookLeft
	applymovement LOCALID_AUDIENCE_7, ContestHall_Movement_AudienceMemberLookDown
	applymovement LOCALID_AUDIENCE_1, ContestHall_Movement_AudienceMemberLookUp
	applymovement LOCALID_AUDIENCE_4, ContestHall_Movement_AudienceMemberLookLeft
	goto_if_ne VAR_TEMP_1, 4, ContestHall_EventScript_AudienceLookAround
	delay 30
	return

ContestHall_EventScript_VObjectAudienceLookAround::
	turnvobject 0, DIR_SOUTH
	turnvobject 2, DIR_SOUTH
	turnvobject 4, DIR_EAST
	turnvobject 6, DIR_SOUTH
	turnvobject 8, DIR_SOUTH
	turnvobject 10, DIR_SOUTH
	turnvobject 12, DIR_SOUTH
	turnvobject 14, DIR_SOUTH
	turnvobject 16, DIR_SOUTH
	turnvobject 18, DIR_SOUTH
	turnvobject 20, DIR_EAST
	turnvobject 22, DIR_EAST
	turnvobject 25, DIR_EAST
	turnvobject 27, DIR_WEST
	turnvobject 28, DIR_EAST
	delay 10
	turnvobject 0, DIR_EAST
	turnvobject 2, DIR_EAST
	turnvobject 4, DIR_EAST
	turnvobject 6, DIR_EAST
	turnvobject 8, DIR_EAST
	turnvobject 10, DIR_WEST
	turnvobject 12, DIR_WEST
	turnvobject 14, DIR_WEST
	turnvobject 16, DIR_WEST
	turnvobject 18, DIR_WEST
	turnvobject 20, DIR_SOUTH
	turnvobject 22, DIR_SOUTH
	turnvobject 25, DIR_NORTH
	turnvobject 27, DIR_NORTH
	turnvobject 28, DIR_NORTH
	delay 10
	turnvobject 1, DIR_NORTH
	turnvobject 3, DIR_NORTH
	turnvobject 5, DIR_NORTH
	turnvobject 7, DIR_NORTH
	turnvobject 9, DIR_EAST
	turnvobject 11, DIR_NORTH
	turnvobject 15, DIR_NORTH
	turnvobject 13, DIR_NORTH
	turnvobject 17, DIR_NORTH
	turnvobject 19, DIR_NORTH
	turnvobject 21, DIR_WEST
	turnvobject 23, DIR_WEST
	turnvobject 24, DIR_WEST
	turnvobject 26, DIR_EAST
	turnvobject 29, DIR_WEST
	turnvobject 30, DIR_WEST
	delay 10
	turnvobject 1, DIR_EAST
	turnvobject 3, DIR_EAST
	turnvobject 5, DIR_EAST
	turnvobject 7, DIR_EAST
	turnvobject 9, DIR_EAST
	turnvobject 11, DIR_WEST
	turnvobject 15, DIR_WEST
	turnvobject 13, DIR_WEST
	turnvobject 17, DIR_WEST
	turnvobject 19, DIR_WEST
	turnvobject 21, DIR_SOUTH
	turnvobject 23, DIR_SOUTH
	turnvobject 24, DIR_SOUTH
	turnvobject 26, DIR_NORTH
	turnvobject 29, DIR_NORTH
	turnvobject 30, DIR_NORTH
	delay 10
	return

ContestHall_EventScript_GiveWinnerPrize::
	goto_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_LINK, ContestHall_EventScript_EndLinkContest
	call ContestHall_EventScript_CheckShouldSkipPrize
	goto_if_set FLAG_TEMP_2, ContestHall_EventScript_SkipPrize
	lockall
	msgbox ContestHall_Text_AcceptYourPrize, MSGBOX_DEFAULT
	releaseall
	call ContestHall_EventScript_WinnerApproachForPrize
	call ContestHall_EventScript_GivePrizeIfWinner
	playse SE_M_ENCORE2
	setvar VAR_TEMP_1, 0
	call ContestHall_EventScript_AudienceLookAround
	delay 30
	special ShouldReadyContestArtist
	goto_if_eq VAR_0x8004, TRUE, ContestHall_EventScript_SetReadyForContestArtist
	return

ContestHall_EventScript_SkipPrize::
	lockall
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
	releaseall
	delay 90
	special ShouldReadyContestArtist
	goto_if_eq VAR_0x8004, TRUE, ContestHall_EventScript_SetReadyForContestArtist
	return

ContestHall_EventScript_CheckShouldSkipPrize::
	specialvar VAR_RESULT, HasMonWonThisContestBefore
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_CheckPlayerWon
	return

ContestHall_EventScript_CheckPlayerWon::
	special GetContestWinnerId
	goto_if_eq VAR_0x8005, 3, ContestHall_EventScript_CheckRankIsMaster
	return

ContestHall_EventScript_CheckRankIsMaster::
	goto_if_eq VAR_CONTEST_RANK, CONTEST_RANK_MASTER, ContestHall_EventScript_DontSkipPrize
	setflag FLAG_TEMP_2
	return

ContestHall_EventScript_DontSkipPrize::
	return

@ This flag is never read
ContestHall_EventScript_SetSketchFlag::
	setflag FLAG_CONTEST_SKETCH_CREATED
	return

ContestHall_EventScript_SetReadyForContestArtist::
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 1
	return

ContestHall_EventScript_EndLinkContest::
	delay 60
	special GetContestPlayerId
	special GetContestWinnerId
	special ShouldReadyContestArtist
	goto_if_eq VAR_0x8004, TRUE, ContestHall_EventScript_SetReadyForLinkContestArtist
	closemessage
	return

ContestHall_EventScript_SetReadyForLinkContestArtist::
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 2
	return

@ Unused
ContestHall_EventScript_Ret::
	return

ContestHall_EventScript_WinnerApproachForPrize::
	switch VAR_0x8005
	case 0, ContestHall_EventScript_Player1ApproachForPrize
	case 1, ContestHall_EventScript_Player2ApproachForPrize
	case 2, ContestHall_EventScript_Player3ApproachForPrize
	case 3, ContestHall_EventScript_Player4ApproachForPrize
	return

ContestHall_EventScript_Player1ApproachForPrize::
	lockall
	applymovement VAR_TEMP_3, ContestHall_Movement_Player1ApproachForPrize
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player2ApproachForPrize::
	lockall
	applymovement VAR_TEMP_3, ContestHall_Movement_Player2ApproachForPrize
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player3ApproachForPrize::
	lockall
	applymovement VAR_TEMP_3, ContestHall_Movement_Player3ApproachForPrize
	waitmovement 0
	releaseall
	return

ContestHall_EventScript_Player4ApproachForPrize::
	lockall
	applymovement VAR_TEMP_3, ContestHall_Movement_Player4ApproachForPrize
	waitmovement 0
	releaseall
	return

@ In NPC Contests, the player is always entry 4 (id number 3)
ContestHall_EventScript_GivePrizeIfWinner::
	special GetContestWinnerId
	goto_if_eq VAR_0x8005, 3, ContestHall_EventScript_GiveContestPrizes
	lockall
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
	releaseall
	return

ContestHall_EventScript_GiveContestPrizes::
	call_if_eq VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_SUPER, ContestHall_EventScript_SetSketchFlag
	specialvar VAR_RESULT, HasMonWonThisContestBefore
	goto_if_eq VAR_RESULT, FALSE, ContestHall_EventScript_ReceiveContestRibbon
	goto_if_eq VAR_CONTEST_RANK, CONTEST_RANK_MASTER, ContestHall_EventScript_GiveLuxuryBall
	lockall
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
	releaseall
	return

ContestHall_EventScript_NoRoomForLuxuryBall::
	lockall
	call Common_EventScript_BagIsFull
	msgbox ContestHall_Text_PickUpPrizeAtCounterLater, MSGBOX_DEFAULT
	releaseall
	setvar VAR_CONTEST_PRIZE_PICKUP, 4
	return

ContestHall_EventScript_GiveLuxuryBall::
	giveitem ITEM_LUXURY_BALL
	goto_if_eq VAR_RESULT, FALSE, ContestHall_EventScript_NoRoomForLuxuryBall
	lockall
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
	releaseall
	return

ContestHall_EventScript_ReceiveContestRibbon::
	special GiveMonContestRibbon
	incrementgamestat GAME_STAT_RECEIVED_RIBBONS
	setflag FLAG_SYS_RIBBON_GET
	lockall
	msgbox ContestHall_Text_ConferRibbonAsPrize, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox ContestHall_Text_ReceivedRibbon, MSGBOX_DEFAULT
	waitfanfare
	special BufferContestWinnerMonName
	msgbox ContestHall_Text_PutRibbonOnMon, MSGBOX_DEFAULT
	releaseall
	return

ContestHall_Movement_MCWalkDown:
	walk_down
	step_end

ContestHall_Movement_MCBackUp:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

ContestHall_Movement_MCFaceJudge:
	walk_in_place_faster_right
	step_end

ContestHall_Movement_Heart:
	emote_heart
	step_end

ContestHall_Movement_FaceContestants:
	walk_in_place_faster_down
	step_end

ContestHall_Movement_WalkStageLeft:
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

ContestHall_Movement_WalkStageRight:
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

ContestHall_Movement_WinningPlayerWalkUp:
	walk_up
	walk_in_place_faster_down
	step_end

ContestHall_Movement_ContestantDelay32:
	delay_16
	delay_16
	step_end

ContestHall_Movement_MCFaceJudge2:
	walk_in_place_faster_right
	step_end

ContestHall_Movement_JudgeFaceMC:
	walk_in_place_faster_left
	step_end

ContestHall_Movement_FaceContestants2:
	walk_in_place_faster_down
	step_end

ContestHall_Movement_Player3ApproachForPrize:
	walk_left
	walk_left
	walk_up
	step_end

ContestHall_Movement_Player4ApproachForPrize:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

ContestHall_Movement_AudienceMemberLookLeft:
	face_left
	delay_16
	face_original_direction
	step_end

ContestHall_Movement_AudienceMemberLookUp:
	face_up
	delay_16
	face_original_direction
	step_end

ContestHall_Movement_AudienceMemberLookRight:
	face_right
	delay_16
	face_original_direction
	step_end

ContestHall_Movement_AudienceMemberLookDown:
	face_down
	delay_16
	face_original_direction
	step_end

ContestHall_Movement_Player4FaceUp:
	face_up
	step_end

ContestHall_Movement_MCLookAtJudge:
	face_up
	delay_16
	walk_in_place_faster_right
	step_end

ContestHall_Movement_JudgeLookAtMC:
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

ContestHall_Movement_MCWalkInPlaceDown:
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

ContestHall_Movement_Player1WalkToCenter:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player1WalkBack:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player2WalkToCenter:
	walk_up
	walk_right
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player2WalkBack:
	walk_fast_left
	walk_fast_down
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player3WalkToCenter:
	walk_up
	walk_left
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player3WalkBack:
	walk_fast_right
	walk_fast_down
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player4WalkToCenter:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player4WalkBack:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_in_place_faster_up
	step_end

ContestHall_Movement_Player1ApproachForPrize:
	walk_right
	walk_right
	walk_up
	step_end

ContestHall_Movement_Player2ApproachForPrize:
	walk_up
	step_end

@ IsContestWithRSPlayer has no side effect, so this is nop
ContestHall_EventScript_CheckIfContestWithRSPlayer::
	specialvar VAR_RESULT, IsContestWithRSPlayer
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_RetRSPlayer
	return

ContestHall_EventScript_RetRSPlayer::
	return

LilycoveCity_ContestLobby_EventScript_DelayIfContestWithRSPlayer::
	specialvar VAR_RESULT, IsContestWithRSPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_ContestLobby_EventScript_DelayForRSPlayer
	return

LilycoveCity_ContestLobby_EventScript_DelayForRSPlayer::
	delay 9
	return

LilycoveCity_ContestLobby_Text_ReceptionDontHavePokeblockCase:
	.ifdef ENGLISH
	.string "Hello!\p"
	.string "This is the reception counter for\n"
	.string "POKéMON CONTESTS.\p"
	.string "Oh? It appears that you don't have\n"
	.string "a {POKEBLOCK} CASE yet.\p"
	.string "In that case, we need to provide you\n"
	.string "with this!$"
	.else
	.ifdef GERMAN
	.string "Hallo!\p"
	.string "Wir nehmen Anmeldungen für die\n"
	.string "POKéMON WETTBEWERBe entgegen.\p"
	.string "Oh, du hast ja gar keine {POKEBLOCK}BOX!\p"
	.string "Nun, dann geben wir dir eine.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_NowThatWeveClearedThatUp:
	.ifdef ENGLISH
	.string "Okay, now that we've cleared that\n"
	.string "up…\p"
	.string "Hello!\p"
	.string "This is the reception counter for\n"
	.string "POKéMON CONTESTS.$"
	.else
	.ifdef GERMAN
	.string "Das hätten wir erledigt…\p"
	.string "Hallo!\p"
	.string "Wir nehmen Anmeldungen für die\n"
	.string "POKéMON WETTBEWERBe entgegen.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_ContestReception:
	.ifdef ENGLISH
	.string "Hello!\p"
	.string "This is the reception counter for\n"
	.string "POKéMON CONTESTS.$"
	.else
	.ifdef GERMAN
	.string "Hallo! \p"
	.string "Wir nehmen Anmeldungen für die\n"
	.string "POKéMON WETTBEWERBe entgegen.$"
	.endif
	.endif

@ Unused
LilycoveCity_ContestLobby_Text_CounterOnlyFor4PlayerContests:
	.ifdef ENGLISH
	.string "Hello!\p"
	.string "This reception counter is only\n"
	.string "for 4-player POKéMON CONTESTS.$"
	.else
	.ifdef GERMAN
	.string "Hello!\p"
	.string "This reception counter is only\n"
	.string "for 4-player POKéMON CONTESTS.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_EnterContest1:
	.ifdef ENGLISH
	.string "Would you like to enter your POKéMON\n"
	.string "in our CONTESTS?$"
	.else
	.ifdef GERMAN
	.string "Soll eines deiner POKéMON an einem der\n"
	.string "WETTBEWERBe teilnehmen?$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_WhichTopic1:
	.ifdef ENGLISH
	.string "Which topic would you like?$"
	.else
	.ifdef GERMAN
	.string "Welches Thema möchtest du dir ansehen?$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_ExplainContests:
	.ifdef ENGLISH
	.string "A POKéMON CONTEST involves four\n"
	.string "TRAINERS entering one POKéMON each\l"
	.string "in competitive judging.\p"
	.string "A CONTEST has two stages of judging,\n"
	.string "primary and secondary.\p"
	.string "Primary judging is a popularity poll\n"
	.string "involving the audience.\p"
	.string "Secondary judging features appeals\n"
	.string "by the POKéMON using their moves.\p"
	.string "Plan appeals carefully to earn the\n"
	.string "most attention of the JUDGE and\l"
	.string "excite the audience.\l"
	.string "Do your best to stand out.\p"
	.string "The primary and secondary scores are\n"
	.string "added at the end.\p"
	.string "The POKéMON garnering the highest\n"
	.string "score is declared the winner.$"
	.else
	.ifdef GERMAN
	.string "In einem POKéMON WETTBEWERB zeigen\n"
	.string "4 TRAINER jeweils eines ihrer POKéMON\l"
	.string "einer Jury.\p"
	.string "Der WETTBEWERB besteht aus zwei\n"
	.string "Durchläufen.\p"
	.string "Im ersten Durchlauf wird geprüft, wie\n"
	.string "gut das POKéMON beim Publikum ankommt.\p"
	.string "Im zweiten Durchlauf muss das POKéMON\n"
	.string "mit der Ausdruckskraft seiner Attacken\l"
	.string "überzeugen.\p"
	.string "Die Attacken müssen sorgfältig gewählt\n"
	.string "werden, damit sie dem JUROR ins Auge\l"
	.string "fallen und das Publikum begeistern.\p"
	.string "Versuche, die Attacken gut zu\n"
	.string "platzieren.\p"
	.string "Am Ende werden die Ergebnisse beider\n"
	.string "Durchläufe addiert.\p"
	.string "Das POKéMON mit dem besten Ergebnis\n"
	.string "wird zum Gewinner erklärt.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_ExplainContestTypes:
	.ifdef ENGLISH
	.string "There are five kinds of CONTESTS.\p"
	.string "COOL, BEAUTY, CUTE, SMART, and\n"
	.string "TOUGH are the five categories.\p"
	.string "Choose the CONTEST that is right for\n"
	.string "the POKéMON you plan to enter.$"
	.else
	.ifdef GERMAN
	.string "Es gibt fünf verschiedene WETTBEWERBe.\p"
	.string "COOLNESS, SCHÖNHEIT, ANMUT, KLUGHEIT\n"
	.string "und STÄRKE heißen die Kategorien.\p"
	.string "Wähle einen WETTBEWERB, der deinem\n"
	.string "POKéMON am besten liegt.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_ExplainContestRanks:
	.ifdef ENGLISH
	.string "There are four ranks of POKéMON\n"
	.string "CONTESTS.\p"
	.string "NORMAL, SUPER, HYPER, and MASTER\n"
	.string "are the four ranks.\p"
	.string "In the NORMAL Rank, any POKéMON may\n"
	.string "enter.\p"
	.string "Any POKéMON that won a NORMAL Rank\n"
	.string "CONTEST may move up to the SUPER Rank\l"
	.string "in the same category.\p"
	.string "In the same way, a SUPER Rank winner\n"
	.string "can move up to the HYPER Rank, and\l"
	.string "a HYPER Rank winner can advance to\l"
	.string "the MASTER Rank in the same category.\p"
	.string "A POKéMON that won in the MASTER Rank\n"
	.string "may compete in the MASTER Rank as\l"
	.string "often as its TRAINER wants.$"
	.else
	.ifdef GERMAN
	.string "Die POKéMON WETTBEWERBe sind in vier\n"
	.string "Klassen aufgeteilt.\p"
	.string "NORMAL, SUPER, HYPER und MASTER.\p"
	.string "In der NORMAL-KLASSE kann jedes\n"
	.string "POKéMON antreten.\p"
	.string "Jedes POKéMON, das die NORMAL-KLASSE\n"
	.string "gewonnen hat, kann in der SUPER-KLASSE\l"
	.string "derselben Kategorie antreten.\p"
	.string "Genauso kann das POKéMON, das in der\n"
	.string "SUPER-KLASSE gewonnen hat, in der\l"
	.string "HYPER-KLASSE und nach einem Sieg\p"
	.string "dort in der MASTER-KLASSE antreten.\n"
	.string "Immer in derselben Kategorie.\p"
	.string "Ein POKéMON, das in der MASTER-KLASSE\n"
	.string "gewonnen hat, kann, sooft es sein\l"
	.string "TRAINER mag, wieder dort antreten.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_EnterWhichRank:
	.ifdef ENGLISH
	.string "Which Rank would you like to enter?$"
	.else
	.ifdef GERMAN
	.string "In welcher Klasse möchtest du\n"
	.string "teilnehmen?$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_EnterWhichContest1:
	.ifdef ENGLISH
	.string "Which CONTEST would you like to enter?$"
	.else
	.ifdef GERMAN
	.string "An welchem WETTBEWERB möchtest du\n"
	.string "teilnehmen?$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_EnterWhichPokemon1:
	.ifdef ENGLISH
	.string "Which POKéMON would you like to enter?$"
	.else
	.ifdef GERMAN
	.string "Welches POKéMON soll teilnehmen?$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_MonNotQualifiedForRank:
	.ifdef ENGLISH
	.string "I'm terribly sorry, but your POKéMON\n"
	.string "is not qualified to compete at this\l"
	.string "Rank yet…$"
	.else
	.ifdef GERMAN
	.string "Tut mir schrecklich Leid, aber dein\n"
	.string "POKéMON kann hier noch nicht\l"
	.string "antreten…$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_EggCannotTakePart:
	.ifdef ENGLISH
	.string "I'm sorry, but an EGG cannot take part\n"
	.string "in a POKéMON CONTEST.$"
	.else
	.ifdef GERMAN
	.string "Tut mit Leid, aber ein EI kann nicht an\n"
	.string "einem WETTBEWERB teilnehmen.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_MonInNoConditionForContest:
	.ifdef ENGLISH
	.string "Your POKéMON appears to be in no\n"
	.string "condition to take part in a CONTEST…$"
	.else
	.ifdef GERMAN
	.string "Dein POKéMON ist nicht in der Lage, an\n"
	.string "einem WETTBEWERB teilzunehmen…$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_AlreadyWonEnterAnyway:
	.ifdef ENGLISH
	.string "Oh, but that RIBBON…\p"
	.string "Your POKéMON has won this CONTEST\n"
	.string "before, hasn't it?\p"
	.string "Would you like to enter it in this\n"
	.string "CONTEST anyway?$"
	.else
	.ifdef GERMAN
	.string "Oh, aber das BAND…\p"
	.string "Dein POKéMON hat diesen WETTBEWERB\n"
	.string "schon einmal gewonnen, oder?\p"
	.string "Möchtest du es trotzdem für diesen\n"
	.string "WETTBEWERB anmelden?$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_ConfirmContestMon:
	.ifdef ENGLISH
	.string "Is that your CONTEST POKéMON?$"
	.else
	.ifdef GERMAN
	.string "Ist das dein WETTBEWERBs-POKéMON?$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_YourMonIsEntryNum4:
	.ifdef ENGLISH
	.string "Okay, your POKéMON will be entered\n"
	.string "in this CONTEST.\p"
	.string "Your POKéMON is Entry No. 4.\n"
	.string "The CONTEST will begin shortly.$"
	.else
	.ifdef GERMAN
	.string "Okay, dein POKéMON wird an diesem\n"
	.string "WETTBEWERB teilnehmen.\p"
	.string "Dein POKéMON ist die Nummer 4.\n"
	.string "Der WETTBEWERB wird in Kürze starten.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_ComeThroughHere:
	.ifdef ENGLISH
	.string "Please come in through here.\n"
	.string "Good luck!$"
	.else
	.ifdef GERMAN
	.string "Bitte folge mir und viel Glück!$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_PokemonWonWeHavePrize:
	.ifdef ENGLISH
	.string "Congratulations! Your POKéMON is the\n"
	.string "CONTEST winner!\p"
	.string "We have your prize right here.\n"
	.string "Please, right this way!$"
	.else
	.ifdef GERMAN
	.string "Herzlichen Glückwunsch! Dein POKéMON\n"
	.string "hat den WETTBEWERB gewonnen!\p"
	.string "Und hier haben wir deinen Preis.\n"
	.string "Bitte, komm hier herüber!$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_ComeBackForPrizeLater:
	.ifdef ENGLISH
	.string "Please come back for your prize\n"
	.string "later on.$"
	.else
	.ifdef GERMAN
	.string "Bitte hole deinen Preis später ab.$"
	.endif
	.endif

ContestHall_Text_GettingStartedParticipantsAsFollows:
	.ifdef ENGLISH
	.string "MC: Hello! We're just getting started\n"
	.string "with a {STR_VAR_3} Rank POKéMON\l"
	.string "{STR_VAR_2}!\p"
	.string "The participating TRAINERS and their\n"
	.string "POKéMON are as follows:$"
	.else
	.ifdef GERMAN
	.string "MC: Hallo! Wir fangen nun mit einem \n"
	.string "{STR_VAR_3}-KLASSE POKéMON\l"
	.string "{STR_VAR_2}-WETTBEWERB an!\p"
	.string "Die folgenden TRAINER und ihre POKéMON\n"
	.string "nehmen teil:$"
	.endif
	.endif

ContestHall_Text_GettingStartedParticipantsAsFollowsLink:
	.ifdef ENGLISH
	.string "MC: Hello! We're just getting started\n"
	.string "with a 4-player linked POKéMON\l"
	.string "{STR_VAR_2}!\p"
	.string "The participating TRAINERS and their\n"
	.string "POKéMON are as follows:$"
	.else
	.ifdef GERMAN
	.string "MC: Hallo! Wir fangen nun mit einem \n"
	.string "4-Spieler POKéMON {STR_VAR_2}-\l"
	.string "WETTBEWERB via Link an!\p"
	.string "Die folgenden TRAINER und ihre POKéMON\n"
	.string "nehmen teil:$"
	.endif
	.endif

ContestHall_Text_EntryXTrainersMon:
	.ifdef ENGLISH
	.string "MC: Entry No. {STR_VAR_2}!\n"
	.string "{STR_VAR_1}'s {STR_VAR_3}!$"
	.else
	.ifdef GERMAN
	.string "MC: Teilnehmer Nr. {STR_VAR_2}!\n"
	.string "{STR_VAR_3} von {STR_VAR_1}!$"
	.endif
	.endif

ContestHall_Text_SeenContestantsAudienceWillVote:
	.ifdef ENGLISH
	.string "MC: We've just seen the four POKéMON\n"
	.string "contestants.\p"
	.string "Now it's time for primary judging!\p"
	.string "The audience will vote on their\n"
	.string "favorite POKéMON contestants.\p"
	.string "Without any further ado, let the\n"
	.string "voting begin!$"
	.else
	.ifdef GERMAN
	.string "MC: Nun haben wir alle vier\n"
	.string "teilnehmenden POKéMON gesehen.\p"
	.string "Zeit für die erste Bewertung!\p"
	.string "Das Publikum entscheidet, welches\n"
	.string "POKéMON am besten gefällt.\p"
	.string "Und ohne weitere Verzögerung kommen\n"
	.string "wir zu der Bewertung!$"
	.endif
	.endif

ContestHall_Text_VotingUnderWay:
	.ifdef ENGLISH
	.string "Voting under way…$"
	.else
	.ifdef GERMAN
	.string "Bewertung läuft…$"
	.endif
	.endif

ContestHall_Text_VotingCompleteLetsAppeal:
	.ifdef ENGLISH
	.string "Voting is now complete!\p"
	.string "While the votes are being tallied,\n"
	.string "let's move on to secondary judging!\p"
	.string "The second stage of judging is the\n"
	.string "much anticipated appeal time!\p"
	.string "May the contestants amaze us with\n"
	.string "superb appeals of dazzling moves!\p"
	.string "Let's see a little enthusiasm!\n"
	.string "Let's appeal!$"
	.else
	.ifdef GERMAN
	.string "Die Bewertung ist nun abgeschlossen!\p"
	.string "Während diese ausgewertet wird, kommen\n"
	.string "wir zum zweiten Durchlauf!\p"
	.string "Im zweiten Durchlauf zeigen uns die\n"
	.string "Kontrahenten die Ausdruckskraft\l"
	.string "ihrer Attacken!\p"
	.string "Hoffen wir, dass sie uns mit ihren Vor-\n"
	.string "führungen den Atem rauben!\p"
	.string "Hoffen wir auf Enthusiasmus!\n"
	.string "Lasst die Vorführung beginnen!$"
	.endif
	.endif

ContestHall_Text_ThatsItForJudging:
	.ifdef ENGLISH
	.string "MC: That's it for judging!$"
	.else
	.ifdef GERMAN
	.string "MC: Die Bewertung ist auch hier\n"
	.string "beendet!$"
	.endif
	.endif

ContestHall_Text_ThankYouForAppeals:
	.ifdef ENGLISH
	.string "Thank you all for a most wonderful\n"
	.string "display of quality appeals!\p"
	.string "This concludes all judging!\n"
	.string "Thank you for your fine efforts!$"
	.else
	.ifdef GERMAN
	.string "Herzlichen Dank an die Teilnehmer für\n"
	.string "ihre wunderbare Vorführung!\p"
	.string "Damit ist die Bewertung abgeschlossen!\n"
	.string "Vielen Dank für alles!$"
	.endif
	.endif

ContestHall_Text_JudgeLooksReady:
	.ifdef ENGLISH
	.string "Now, all that remains is the pulse-\n"
	.string "pounding proclamation of the winner.\p"
	.string "The JUDGE looks ready to make\n"
	.string "the announcement!$"
	.else
	.ifdef GERMAN
	.string "Kommen wir nun zu dem, was unseren Puls\n"
	.string "höher schlagen lässt: Die Bekanntgabe\l"
	.string "der Gewinner.\p"
	.string "Der JUROR scheint für die Bekanntgabe\n"
	.string "bereit zu sein!$"
	.endif
	.endif

ContestHall_Text_WeWillNowDeclareWinner:
	.ifdef ENGLISH
	.string "JUDGE: We will now declare the winner!$"
	.else
	.ifdef GERMAN
	.string "JUROR: Ich werde nun den Sieger\n"
	.string "bekannt geben!$"
	.endif
	.endif

ContestHall_Text_CongratsTrainerXandMon:
	.ifdef ENGLISH
	.string "MC: Entry No. {STR_VAR_2}!\p"
	.string "{STR_VAR_3} and {STR_VAR_1},\n"
	.string "congratulations!$"
	.else
	.ifdef GERMAN
	.string "MC: Teilnehmer Nr. {STR_VAR_2}!\p"
	.string "{STR_VAR_3} und {STR_VAR_1}!\n"
	.string "Herzlichen Glückwunsch!$"
	.endif
	.endif

ContestHall_Text_CongratsPleaseCompeteAgain:
	.ifdef ENGLISH
	.string "MC: Congratulations!\n"
	.string "Please do compete again!$"
	.else
	.ifdef GERMAN
	.string "MC: Herzlichen Glückwunsch!\n"
	.string "Komm bald wieder!$"
	.endif
	.endif

ContestHall_Text_AcceptYourPrize:
	.ifdef ENGLISH
	.string "MC: Here you are!\n"
	.string "Please accept your prize!$"
	.else
	.ifdef GERMAN
	.string "MC: Bitte schön!\n"
	.string "Bitte, dies ist dein Preis!$"
	.endif
	.endif

ContestHall_Text_ConferRibbonAsPrize:
	.ifdef ENGLISH
	.string "We confer on you this RIBBON\n"
	.string "as your prize!$"
	.else
	.ifdef GERMAN
	.string "Wir überreichen dir hiermit dieses BAND\n"
	.string "als Zeichen deines Sieges!$"
	.endif
	.endif

ContestHall_Text_ReceivedRibbon:
	.ifdef ENGLISH
	.string "{PLAYER} received a RIBBON.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} erhält ein BAND.$"
	.endif
	.endif

ContestHall_Text_PutRibbonOnMon:
	.ifdef ENGLISH
	.string "{PLAYER} put the RIBBON on\n"
	.string "{STR_VAR_1}.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} befestigt das BAND an\n"
	.string "{STR_VAR_1}.$"
	.endif
	.endif

ContestHall_Text_PickUpPrizeAtCounterLater:
	.ifdef ENGLISH
	.string "Please pick up your prize at\n"
	.string "the reception counter later.\l"
	.string "Please do compete again!$"
	.else
	.ifdef GERMAN
	.string "Bitte hole deinen Preis später an der\n"
	.string "Rezeption ab.\l"
	.string "Und nimm bald wieder teil!$"
	.endif
	.endif

@ Unused
ContestHall_Text_OnlyRegister4Players:
	.ifdef ENGLISH
	.string "I only register four players for\n"
	.string "POKéMON CONTESTS.\p"
	.string "If three other players link up, all\n"
	.string "four may enter the same CONTEST.\p"
	.string "Would you like to take part?$"
	.else
	.ifdef GERMAN
	.string "I only register four players for\n"
	.string "POKéMON CONTESTS.\p"
	.string "If three other players link up, all\n"
	.string "four may enter the same CONTEST.\p"
	.string "Would you like to take part?$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_ProgressWillBeSaved:
	.ifdef ENGLISH
	.string "Before entering a CONTEST, your\n"
	.string "progress will be saved.$"
	.else
	.ifdef GERMAN
	.string "Bevor du an einem WETTBEWERB teil-\n"
	.string "nimmst, wird dein Spiel gespeichert.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_ParticipateAnotherTime:
	.ifdef ENGLISH
	.string "We hope you will participate another\n"
	.string "time.$"
	.else
	.ifdef GERMAN
	.string "Wir hoffen, du nimmst ein anderes Mal\n"
	.string "teil.$"
	.endif
	.endif

@ Unused
LilycoveCity_ContestLobby_Text_EnterContest2:
	.ifdef ENGLISH
	.string "Would you like to enter a CONTEST?$"
	.else
	.ifdef GERMAN
	.string "Would you like to enter a CONTEST?$"
	.endif
	.endif

@ Unused
LilycoveCity_ContestLobby_Text_Explain4PlayerContest:
	.ifdef ENGLISH
	.string "When four players are ready, connect\n"
	.string "over a Game Link cable, and register\l"
	.string "with me, please.\p"
	.string "Please choose the same CONTEST\n"
	.string "as your fellow contestants.\p"
	.string "The CONTEST begins as soon as all\n"
	.string "players register their entry.\p"
	.string "After that, the usual CONTEST rules\n"
	.string "apply.$"
	.else
	.ifdef GERMAN
	.string "When four players are ready, connect\n"
	.string "over a Game Link cable, and register\l"
	.string "with me, please.\p"
	.string "Please choose the same CONTEST\n"
	.string "as your fellow contestants.\p"
	.string "The CONTEST begins as soon as all\n"
	.string "players register their entry.\p"
	.string "After that, the usual CONTEST rules\n"
	.string "apply.$"
	.endif
	.endif

@ Unused
LilycoveCity_ContestLobby_Text_EnterWhichContest2:
	.ifdef ENGLISH
	.string "Which CONTEST would you like to enter?$"
	.else
	.ifdef GERMAN
	.string "Which CONTEST would you like to enter?$"
	.endif
	.endif

@ Unused
LilycoveCity_ContestLobby_Text_EnterWhichPokemon2:
	.ifdef ENGLISH
	.string "Which POKéMON would you like to enter?$"
	.else
	.ifdef GERMAN
	.string "Which POKéMON would you like to enter?$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_Transmitting:
	.ifdef ENGLISH
	.string "Transmitting…$"
	.else
	.ifdef GERMAN
	.string "Übertragung… $"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_TransmissionError:
	.ifdef ENGLISH
	.string "Transmission error…$"
	.else
	.ifdef GERMAN
	.string "Übertragungsfehler.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_PlayersChoseDifferentContest:
	.ifdef ENGLISH
	.string "You may have chosen a different\n"
	.string "CONTEST than another player.$"
	.else
	.ifdef GERMAN
	.string "Du hast wohl einen anderen WETTBEWERB\n"
	.string "gewählt als ein anderer Teilnehmer.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_PlayersMadeDifferentChoice:
	.ifdef ENGLISH
	.string "You may have made a different\n"
	.string "choice than another player.$"
	.else
	.ifdef GERMAN
	.string "Du hast wohl eine andere Entscheidung\n"
	.string "getroffen als ein anderer Teilnehmer.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_PleaseWaitBButtonCancel:
	.ifdef ENGLISH
	.string "Please wait.\n"
	.string "… … B Button: Cancel$"
	.else
	.ifdef GERMAN
	.string "Bitte warten.\n"
	.string "Drücke den B-Knopf, um abzubrechen…$"
	.endif
	.endif

@ Unused
LilycoveCity_ContestLobby_Text_ParticipateAnotherTime2:
	.ifdef ENGLISH
	.string "We hope you will participate another\n"
	.string "time.$"
	.else
	.ifdef GERMAN
	.string "We hope you will participate another\n"
	.string "time.$"
	.endif
	.endif

@ Unused
LilycoveCity_ContestLobby_Text_TransmissionErrorTryAgain:
	.ifdef ENGLISH
	.string "Transmission error.\n"
	.string "Please try again.$"
	.else
	.ifdef GERMAN
	.string "Transmission error.\n"
	.string "Please try again.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_YourMonIsEntryNumX:
	.ifdef ENGLISH
	.string "Your POKéMON will be entered in\n"
	.string "the CONTEST.\p"
	.string "Your POKéMON is Entry No. {STR_VAR_2}.$"
	.else
	.ifdef GERMAN
	.string "Dein POKéMON wird an dem WETTBEWERB\n"
	.string "teilnehmen.\p"
	.string "Dein POKéMON hat die Nummer {STR_VAR_2}.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_ContestBeginShortly:
	.ifdef ENGLISH
	.string "The CONTEST will begin shortly.$"
	.else
	.ifdef GERMAN
	.string "Der WETTBEWERB wird bald beginnen.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_LinkContestReception:
	.ifdef ENGLISH
	.string "Welcome! This is the POKéMON CONTEST\n"
	.string "link reception counter.\p"
	.string "You may enter CONTESTS together with\n"
	.string "one or more friends.$"
	.else
	.ifdef GERMAN
	.string "Willkommen! Wir nehmen Anmeldungen für\n"
	.string "Link-POKéMON WETTBEWERBe entgegen.\p"
	.string "Du kannst mit einem oder mehreren\n"
	.string "Freunden an WETTBEWERBen teilnehmen.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_WhichTopic2:
	.ifdef ENGLISH
	.string "Which topic would you like?$"
	.else
	.ifdef GERMAN
	.string "Welches Thema möchtest du dir ansehen?$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_EnterContest3:
	.ifdef ENGLISH
	.string "Would you like to enter a CONTEST?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du am WETTBEWERB teilnehmen?$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_EnterWhichContest3:
	.ifdef ENGLISH
	.string "Which CONTEST would you like to enter?$"
	.else
	.ifdef GERMAN
	.string "An welchem WETTBEWERB möchtest du\n"
	.string "teilnehmen?$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_MonInNoCondition2:
	.ifdef ENGLISH
	.string "Your POKéMON appears to be in no\n"
	.string "condition to take part in a CONTEST…$"
	.else
	.ifdef GERMAN
	.string "Dein POKéMON ist nicht in der Lage, an\n"
	.string "einem WETTBEWERB teilzunehmen…$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_EggCannotTakePart2:
	.ifdef ENGLISH
	.string "I'm sorry, but an EGG cannot take part\n"
	.string "in a POKéMON CONTEST.$"
	.else
	.ifdef GERMAN
	.string "Tut mit Leid, aber ein EI kann nicht an\n"
	.string "einem WETTBEWERB teilnehmen.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_EnterWhichPokemon3:
	.ifdef ENGLISH
	.string "Which POKéMON would you like to enter?$"
	.else
	.ifdef GERMAN
	.string "Welches POKéMON soll teilnehmen?$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_PleaseDecideLinkLeader:
	.ifdef ENGLISH
	.string "Please decide which of you will\n"
	.string "become the GROUP LEADER.\p"
	.string "The other players must then choose\n"
	.string "“JOIN GROUP.”$"
	.else
	.ifdef GERMAN
	.string "Bitte legt fest, wer in eurem TEAM\n"
	.string "der LEITER ist.\p"
	.string "Die anderen Spieler wählen\n"
	.string "“MITSPIELER” aus.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_PlayerAt4PCounterUseGMode:
	.ifdef ENGLISH
	.string "At least one player has entered using\n"
	.string "the 4-player reception counter.\p"
	.string "There must be four players connected\n"
	.string "using a GBA Game Link cable.\p"
	.string "When the four players are ready,\n"
	.string "select G-MODE (GLOBAL MODE),\l"
	.string "then register to enter again, please.$"
	.else
	.ifdef GERMAN
	.string "Mindestens ein Spieler hat sich bei der\n"
	.string "Anmeldung für 4 Spieler eingetragen.\p"
	.string "Vier Spieler müssen sich via GBA Game\n"
	.string "Link-Kabel zusammenschließen.\p"
	.string "Sind alle vier Spieler bereit, wählt den\n"
	.string "G-MODUS (GLOBALMODUS) und meldet euch\l"
	.string "erneut an.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_ExplainLinkContest:
	.ifdef ENGLISH
	.string "This is a CONTEST for two to four\n"
	.string "players linked using a Wireless\l"
	.string "Adapter or a GBA Game Link cable.\p"
	.string "Participants are first asked to choose\n"
	.string "the mode they wish to enter.\p"
	.string "There are two different modes.\p"
	.string "E-MODE (EMERALD MODE) is for\n"
	.string "two to four players, each with a\l"
	.string "POKéMON Emerald Game Pak.\p"
	.string "G-MODE (GLOBAL MODE) is only for\n"
	.string "four players, each with a POKéMON\l"
	.string "Emerald, Ruby, or Sapphire Game Pak.\p"
	.string "The players should discuss which mode\n"
	.string "they want, then choose the same mode.\p"
	.string "Once all the players have chosen\n"
	.string "the same CONTEST in the same mode,\l"
	.string "the entry registration is complete.\p"
	.string "After that, a CONTEST will start in\n"
	.string "the usual manner.$"
	.else
	.ifdef GERMAN
	.string "Dieser WETTBEWERB ist für 2 oder 4\n"
	.string "Spieler, die mit einem Drahtlos Adapter\l"
	.string "oder dem GBA Game Link-Kabel spielen.\p"
	.string "Die Teilnehmer müssen sich zunächst\n"
	.string "entscheiden, in welchem Modus sie\l"
	.string "spielen möchten.\p"
	.string "Es gibt zwei Modi.\p"
	.string "Der S-MODUS (SMARAGDMODUS) ist für\n"
	.string "zwei oder vier Spieler, wobei jeder\p"
	.string "Spieler ein POKéMON Smaragd-Spielmodul\n"
	.string "besitzen muss.\p"
	.string "Der G-MODUS (GLOBALMODUS) ist\n"
	.string "nur für vier Spieler, die je 1 Spielmodul\p"
	.string "entweder der Smaragd-, Rubin- oder\n"
	.string "Saphir-Edition besitzen.\p"
	.string "Alle Spieler müssen den gleichen Modus\n"
	.string "wählen.\p"
	.string "Sobald alle Spieler den gleichen\n"
	.string "WETTBEWERB im gleichen Modus gewählt\l"
	.string "haben, ist die Anmeldung abgeschlossen.\p"
	.string "Danach beginnt der WETTBEWERB.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_ExplainEMode:
	.ifdef ENGLISH
	.string "In E-MODE (EMERALD MODE),\n"
	.string "a LINK CONTEST can be held with\l"
	.string "two to four players. Each player must\l"
	.string "have a POKéMON Emerald Game Pak.\p"
	.string "The players must be linked with each\n"
	.string "other using Wireless Adapters or\l"
	.string "GBA Game Link cables.\p"
	.string "If there are fewer than four players,\n"
	.string "TRAINERS in the hall will join to fill\l"
	.string "the 4-player CONTEST lineup.\p"
	.string "Please be aware that E-MODE is not\n"
	.string "available in POKéMON Ruby or Sapphire.$"
	.else
	.ifdef GERMAN
	.string "Im S-MODUS (SMARAGDMODUS) können\n"
	.string "LINK WETTBEWERBe mit zwei oder vier\l"
	.string "Spielern veranstaltet werden. Jeder\p"
	.string "Spieler muss ein Spielmodul der \n"
	.string "POKéMON Smaragd-Edition besitzen.\p"
	.string "Die Verbindung wird mit dem Drahtlosen\n"
	.string "Adapter oder dem GBA Game Link-Kabel\l"
	.string "aufgebaut.\p"
	.string "Sind weniger als vier Spieler\n"
	.string "miteinander verbunden, dann wird ein\l"
	.string "TRAINER aus der Vorhalle den vierten\l"
	.string "Spieler ersetzen.\p"
	.string "Der S-MODUS ist mit der POKéMON\n"
	.string "Rubin- oder Saphir-Edition nicht\l"
	.string "spielbar.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_ExplainGMode:
	.ifdef ENGLISH
	.string "G-MODE (GLOBAL MODE) is specifically\n"
	.string "for four players who are linked using\l"
	.string "GBA Game Link cables.\p"
	.string "Each player must have a POKéMON\n"
	.string "Emerald, Ruby, or Sapphire Game Pak.\p"
	.string "The CONTEST starts after all players\n"
	.string "choose G-MODE (POKéMON Emerald) or\l"
	.string "enter through the 4-player reception\l"
	.string "counter (POKéMON Ruby or Sapphire).$"
	.else
	.ifdef GERMAN
	.string "G-MODUS (GLOBALMODUS) ist\n"
	.string "ausschließlich für vier Spieler gedacht,\p"
	.string "die mit dem GBA Game Link-Kabel eine\n"
	.string "Verbindung aufbauen.\p"
	.string "Jeder Spieler muss ein Spielmodul\n"
	.string "entweder der Smaragd-, Rubin- oder\l"
	.string "Saphir-Edition besitzen.\p"
	.string "Nachdem sich alle Spieler für den\n"
	.string "G-MODUS entschieden haben bzw. sich\l"
	.string "bei der 4-Spieler-Anmeldung\l"
	.string "(Rubin-/Saphir-Edition) eingetragen\p"
	.string "haben, beginnt der WETTBEWERB.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_NoWirelessAdapterInGMode:
	.ifdef ENGLISH
	.string "I'm terribly sorry.\p"
	.string "G-MODE does not function\n"
	.string "with Wireless Adapters.\p"
	.string "Please select E-MODE or try\n"
	.string "again using a GBA Game Link cable.$"
	.else
	.ifdef GERMAN
	.string "Es tut mir schrecklich Leid.\p"
	.string "Der G-MODUS kann mit dem Drahtlosen\n"
	.string "Adapter nicht gespielt werden.\p"
	.string "Bitte wähle S-MODUS oder versuche, mit\n"
	.string "dem GBA Game Link-Kabel eine\l"
	.string "Verbindung aufzubauen.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_WhichContestMode:
	.ifdef ENGLISH
	.string "Which CONTEST MODE would you like\n"
	.string "to enter?$"
	.else
	.ifdef GERMAN
	.string "In welchem WETTBEWERBs-MODUS\n"
	.string "möchtest du spielen?$"
	.endif
	.endif

ContestHall_Text_GettingStartedWireless:
	.ifdef ENGLISH
	.string "MC: Hello! We're just getting started\n"
	.string "with a 4-player linked POKéMON\l"
	.string "{STR_VAR_2}!$"
	.else
	.ifdef GERMAN
	.string "MC: Hallo! Wir fangen nun mit einem \n"
	.string "4-Spieler POKéMON {STR_VAR_2}-\l"
	.string "WETTBEWERB via Link an!$"
	.endif
	.endif

ContestHall_Text_ParticipantsAsFollows:
	.ifdef ENGLISH
	.string "The participating TRAINERS and their\n"
	.string "POKéMON are as follows:$"
	.else
	.ifdef GERMAN
	.string "Die folgenden TRAINER und ihre POKéMON\n"
	.string "nehmen teil:$"
	.endif
	.endif

ContestHall_Text_WeveSeenContestants:
	.ifdef ENGLISH
	.string "MC: We've just seen the four POKéMON\n"
	.string "contestants.\p"
	.string "Now it's time for primary judging!$"
	.else
	.ifdef GERMAN
	.string "MC: Nun haben wir alle vier\n"
	.string "teilnehmenden POKéMON gesehen.\p"
	.string "Zeit für die erste Bewertung!$"
	.endif
	.endif

ContestHall_Text_AudienceWillVote:
	.ifdef ENGLISH
	.string "The audience will vote on their\n"
	.string "favorite POKéMON contestants.$"
	.else
	.ifdef GERMAN
	.string "Das Publikum entscheidet, welches\n"
	.string "POKéMON am besten gefällt.$"
	.endif
	.endif

ContestHall_Text_LetVotingBegin:
	.ifdef ENGLISH
	.string "Without any further ado,\n"
	.string "let the voting begin!$"
	.else
	.ifdef GERMAN
	.string "Und ohne weitere Verzögerung kommen\n"
	.string "wir zu der Bewertung!$"
	.endif
	.endif

ContestHall_Text_VotingComplete:
	.ifdef ENGLISH
	.string "Voting is now complete!\p"
	.string "While the votes are being tallied,\n"
	.string "let's move on to secondary judging!$"
	.else
	.ifdef GERMAN
	.string "Die Bewertung ist nun abgeschlossen!\p"
	.string "Während diese ausgewertet wird, kommen\n"
	.string "wir zum zweiten Durchlauf!$"
	.endif
	.endif

ContestHall_Text_SecondStageOfJudging:
	.ifdef ENGLISH
	.string "The second stage of judging is\n"
	.string "the much-anticipated appeal time!\p"
	.string "May the contestants amaze us with\n"
	.string "superb appeals of dazzling moves!$"
	.else
	.ifdef GERMAN
	.string "Im zweiten Durchlauf zeigen uns die\n"
	.string "Kontrahenten die Ausdruckskraft\l"
	.string "ihrer Attacken!\p"
	.string "Hoffen wir, dass sie uns mit ihren Vor-\n"
	.string "führungen den Atem rauben!$"
	.endif
	.endif

ContestHall_Text_LetsAppeal:
	.ifdef ENGLISH
	.string "Let's see a little enthusiasm!\n"
	.string "Let's appeal!$"
	.else
	.ifdef GERMAN
	.string "Hoffen wir auf Enthusiasmus!\n"
	.string "Lasst die Vorführung beginnen!$"
	.endif
	.endif
