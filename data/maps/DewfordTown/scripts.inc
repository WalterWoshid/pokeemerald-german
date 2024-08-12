@ Sailing to and from Dewford uses local IDs from different maps
@ e.g. Route 104's sail to Dewford script references local IDs from Dewford's map
@ All of these local IDs are labeled here
.equ LOCALID_BRINEY_DEWFORD, 2
.equ LOCALID_BOAT_DEWFORD, 4

.equ LOCALID_BOAT_R109, 1
.equ LOCALID_BRINEY_R109, 2

.equ LOCALID_BOAT_R104, 7
.equ LOCALID_BRINEY_R104, 8

DewfordTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_OnTransition
	.byte 0

DewfordTown_OnTransition:
	setflag FLAG_VISITED_DEWFORD_TOWN
	end

DewfordTown_EventScript_Briney::
	lock
	faceplayer
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, DewfordTown_EventScript_ReturnToPetalburgPrompt
	message DewfordTown_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 21, 6, MULTI_BRINEY_ON_DEWFORD, 2, FALSE
	switch VAR_RESULT
	case 0, DewfordTown_EventScript_ChoosePetalburg
	case 1, DewfordTown_EventScript_ChooseSlateport
	case 2, DewfordTown_EventScript_CancelSailSelect
	case MULTI_B_PRESSED, DewfordTown_EventScript_CancelSailSelect
	end

DewfordTown_EventScript_ChoosePetalburg::
	msgbox DewfordTown_Text_PetalburgWereSettingSail, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_SailToPetalburg
	release
	end

DewfordTown_EventScript_ChooseSlateport::
	msgbox DewfordTown_Text_SlateportWereSettingSail, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_SailToSlateport
	release
	end

DewfordTown_EventScript_CancelSailSelect::
	msgbox DewfordTown_Text_JustTellMeWhenYouNeedToSetSail, MSGBOX_DEFAULT
	closemessage
	release
	end

DewfordTown_EventScript_ReturnToPetalburgPrompt::
	msgbox DewfordTown_Text_SetSailBackToPetalburg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_SailBackToPetalburg
	msgbox DewfordTown_Text_GoDeliverIllBeWaiting, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_SailBackToPetalburg::
	msgbox DewfordTown_Text_PetalburgWereSettingSail2, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_SailToPetalburg
	end

DewfordTown_EventScript_Woman::
	msgbox DewfordTown_Text_TinyIslandCommunity, MSGBOX_NPC
	end

DewfordTown_EventScript_TownSign::
	msgbox DewfordTown_Text_TownSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_GymSign::
	msgbox DewfordTown_Text_GymSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_HallSign::
	msgbox DewfordTown_Text_HallSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_OldRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, DewfordTown_EventScript_HowsFishing
	msgbox DewfordTown_Text_GettingItchToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_GiveOldRod
	goto_if_eq VAR_RESULT, NO, DewfordTown_EventScript_NotGettingItchToFish
	end

DewfordTown_EventScript_GiveOldRod::
	msgbox DewfordTown_Text_GiveYouOneOfMyRods, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox DewfordTown_Text_ThrowInFishingAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_NotGettingItchToFish::
	msgbox DewfordTown_Text_ThatsTooBadThen, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_HowsFishing::
	message DewfordTown_Text_HowsYourFishing
	waitmessage
	multichoice 20, 8, MULTI_HOWS_FISHING, TRUE
	goto_if_eq VAR_RESULT, 0, DewfordTown_EventScript_FishingExcellent
	goto_if_eq VAR_RESULT, 1, DewfordTown_EventScript_FishingNotSoGood
	end

DewfordTown_EventScript_FishingExcellent::
	msgbox DewfordTown_Text_GreatHaulInSomeBigOnes, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_FishingNotSoGood::
	msgbox DewfordTown_Text_FishingAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_SailToPetalburg::
	call EventScript_BackupMrBrineyLocation
	setobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN, 0
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN, 0
	applymovement LOCALID_BRINEY_DEWFORD, DewfordTown_Movement_BrineyBoardBoat
	waitmovement 0
	removeobject LOCALID_BRINEY_DEWFORD
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_PlayerBoardBoat
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement LOCALID_BOAT_DEWFORD, DewfordTown_Movement_SailToPetalburg
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_SailToPetalburg
	waitmovement 0
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
	call Common_EventScript_StopBrineysBoatMusic
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_ExitBoatPetalburg
	waitmovement 0
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	hideobjectat LOCALID_BOAT_DEWFORD, MAP_DEWFORD_TOWN
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 2
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
	warp MAP_ROUTE104_MR_BRINEYS_HOUSE, 5, 4
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	waitstate
	release
	end

DewfordTown_EventScript_SailToSlateport::
	call EventScript_BackupMrBrineyLocation
	setobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN, 0
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN, 1
	applymovement LOCALID_BRINEY_DEWFORD, DewfordTown_Movement_BrineyBoardBoat
	waitmovement 0
	removeobject LOCALID_BRINEY_DEWFORD
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_PlayerBoardBoat
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement LOCALID_BOAT_DEWFORD, DewfordTown_Movement_SailToSlateport
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_SailToSlateport
	waitmovement 0
	call Common_EventScript_StopBrineysBoatMusic
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE109
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_ExitBoatSlateport
	waitmovement 0
	setobjectxyperm LOCALID_BRINEY_R109, 21, 26
	addobject LOCALID_BRINEY_R109
	setobjectsubpriority LOCALID_BRINEY_R109, MAP_ROUTE109, 0
	applymovement LOCALID_BRINEY_R109, DewfordTown_Movement_BrineyExitBoat
	waitmovement 0
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	addobject LOCALID_BOAT_R109
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	hideobjectat LOCALID_BOAT_DEWFORD, MAP_DEWFORD_TOWN
	call_if_unset FLAG_DELIVERED_DEVON_GOODS, DewfordTown_EventScript_LandedSlateportDeliverGoods
	call_if_set FLAG_DELIVERED_DEVON_GOODS, DewfordTown_EventScript_LandedSlateport
	closemessage
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
	resetobjectsubpriority LOCALID_BRINEY_R109, MAP_ROUTE109
	copyobjectxytoperm LOCALID_BRINEY_R109
	release
	end

DewfordTown_EventScript_LandedSlateportDeliverGoods::
	msgbox DewfordTown_Text_BrineyLandedInSlateportDeliverGoods, MSGBOX_DEFAULT
	return

DewfordTown_EventScript_LandedSlateport::
	msgbox DewfordTown_Text_BrineyLandedInSlateport, MSGBOX_DEFAULT
	return

DewfordTown_Movement_SailToPetalburg:
	walk_up
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DewfordTown_Movement_SailToSlateport:
	walk_right
	walk_fast_right
	walk_fast_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

DewfordTown_Movement_PlayerBoardBoat:
	walk_right
	walk_up
	step_end

DewfordTown_Movement_ExitBoatPetalburg:
	walk_up
	walk_up
	walk_up
	step_end

DewfordTown_Movement_ExitBoatSlateport:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

DewfordTown_Movement_BrineyBoardBoat:
	walk_up
	step_end

DewfordTown_Movement_BrineyExitBoat:
	walk_up
	walk_up
	step_end

DewfordTown_EventScript_TrendyPhraseBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Text_XIsTheBiggestHappeningThingRight, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_ConfirmTrendyPhrase
	goto_if_eq VAR_RESULT, NO, DewfordTown_EventScript_RejectTrendyPhrase
	end

DewfordTown_EventScript_ConfirmTrendyPhrase::
	msgbox DewfordTown_Text_YeahDefinitionOfInRightNow, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_RejectTrendyPhrase::
	msgbox DewfordTown_Text_TellMeWhatsNewAndIn, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRENDY_PHRASE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_EventScript_GiveNewTrendyPhrase
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_EventScript_CancelNewTrendyPhrase
	end

DewfordTown_EventScript_GiveNewTrendyPhrase::
	incrementgamestat GAME_STAT_STARTED_TRENDS
	goto_if_eq VAR_0x8004, FALSE, DewfordTown_EventScript_PhraseNotTrendyEnough
	msgbox DewfordTown_Text_OfCourseIKnowAboutThat, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_CancelNewTrendyPhrase::
	msgbox DewfordTown_Text_HearOfAnyTrendsComeShareWithMe, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_PhraseNotTrendyEnough::
	msgbox DewfordTown_Text_XHuhIThinkYIsCool, MSGBOX_DEFAULT
	release
	end

DewfordTown_Text_TinyIslandCommunity:
	.ifdef ENGLISH
	.string "DEWFORD is a tiny island community.\n"
	.string "If something gets trendy here,\l"
	.string "everyone picks up on it right away.$"
	.else
	.ifdef GERMAN
	.string "FAUSTAUHAVEN ist eine kleine\n"
	.string "Inselgemeinschaft. Wenn hier etwas in\l"
	.string "Mode kommt, will jeder es haben.$"
	.endif
	.endif

DewfordTown_Text_TownSign:
	.ifdef ENGLISH
	.string "DEWFORD TOWN\n"
	.string "“A tiny island in the blue sea.”$"
	.else
	.ifdef GERMAN
	.string "FAUSTAUHAVEN\n"
	.string "“Eine kleine Insel im blauen Meer.”$"
	.endif
	.endif

DewfordTown_Text_GymSign:
	.ifdef ENGLISH
	.string "DEWFORD TOWN POKéMON GYM\n"
	.string "LEADER: BRAWLY\l"
	.string "“A big wave in fighting!”$"
	.else
	.ifdef GERMAN
	.string "POKéMON ARENA von FAUSTAUHAVEN\n"
	.string "LEITER: KAMILLO\l"
	.string "“Eine große Welle des Kampfes!”$"
	.endif
	.endif

DewfordTown_Text_HallSign:
	.ifdef ENGLISH
	.string "DEWFORD HALL\n"
	.string "“Everyone's information exchange!”$"
	.else
	.ifdef GERMAN
	.string "FAUSTAUHAVEN HALLE\n"
	.string "“Die Informationsbörse für jedermann!”$"
	.endif
	.endif

Route104_Text_LandedInDewfordDeliverLetter:
	.ifdef ENGLISH
	.string "MR. BRINEY: Ahoy!\n"
	.string "We've hit land in DEWFORD.\p"
	.string "I suppose you're off to deliver that\n"
	.string "LETTER to, who was it now, STEVEN!$"
	.else
	.ifdef GERMAN
	.string "MR. BRACK: Ahoi! Wir haben in\n"
	.string "FAUSTAUHAVEN Anker geworfen.\p"
	.string "Ich vermute, du wirst diesen BRIEF\n"
	.string "jetzt diesem… TROY bringen!?!$"
	.endif
	.endif

DewfordTown_Text_SetSailBackToPetalburg:
	.ifdef ENGLISH
	.string "MR. BRINEY: Have you delivered your\n"
	.string "LETTER?\p"
	.string "Or were you meaning to sail back to\n"
	.string "PETALBURG?$"
	.else
	.ifdef GERMAN
	.string "MR. BRACK: Hast du den BRIEF\n"
	.string "überbracht?\p"
	.string "Oder meinst du, wir müssen zurück\n"
	.string "nach BLÜTENBURG CITY segeln?$"
	.endif
	.endif

DewfordTown_Text_PetalburgWereSettingSail2:
	.ifdef ENGLISH
	.string "MR. BRINEY: PETALBURG it is, then!\p"
	.string "Anchors aweigh!\n"
	.string "PEEKO, we're setting sail, my darling!$"
	.else
	.ifdef GERMAN
	.string "MR. BRACK: BLÜTENBURG CITY…\n"
	.string "In Ordnung.\p"
	.string "Anker gelichtet!\n"
	.string "PECKO, mein Schatz, wir setzen Segel!$"
	.endif
	.endif

DewfordTown_Text_GoDeliverIllBeWaiting:
	.ifdef ENGLISH
	.string "MR. BRINEY: Then you go on and deliver\n"
	.string "the LETTER. I'll be waiting.$"
	.else
	.ifdef GERMAN
	.string "MR. BRACK: Dann bring den BRIEF zu\n"
	.string "seinem Empfänger. Ich warte hier.$"
	.endif
	.endif

DewfordTown_Text_BrineyLandedInDewford:
	.ifdef ENGLISH
	.string "MR. BRINEY: Ahoy!\n"
	.string "We've hit land in DEWFORD!\p"
	.string "You just go on and tell me whenever\n"
	.string "you want to set sail again!$"
	.else
	.ifdef GERMAN
	.string "MR. BRACK: Ahoi! Wir haben in\n"
	.string "FAUSTAUHAVEN Anker geworfen!\p"
	.string "Komm, wenn wir wieder Segel\n"
	.string "setzen sollen.$"
	.endif
	.endif

DewfordTown_Text_WhereAreWeBound:
	.ifdef ENGLISH
	.string "MR. BRINEY: Ahoy!\n"
	.string "For you, I'll go out to sea anytime!\p"
	.string "Now, my friend, where are we bound?$"
	.else
	.ifdef GERMAN
	.string "MR. BRACK: Ahoi! Für dich fahre ich\n"
	.string "jederzeit wieder raus!\p"
	.string "Nun, wo soll es hingehen?$"
	.endif
	.endif

DewfordTown_Text_PetalburgWereSettingSail:
	.ifdef ENGLISH
	.string "MR. BRINEY: PETALBURG, is it?\p"
	.string "Anchors aweigh!\n"
	.string "PEEKO, we're setting sail, my darling!$"
	.else
	.ifdef GERMAN
	.string "MR. BRACK: BLÜTENBURG CITY soll es\n"
	.string "sein?\p"
	.string "Anker gelichtet!\n"
	.string "PECKO, mein Schatz, wir setzen Segel!$"
	.endif
	.endif

DewfordTown_Text_SlateportWereSettingSail:
	.ifdef ENGLISH
	.string "MR. BRINEY: SLATEPORT, is it?\p"
	.string "Anchors aweigh!\n"
	.string "PEEKO, we're setting sail, my darling!$"
	.else
	.ifdef GERMAN
	.string "MR. BRACK: GRAPHITPORT CITY soll\n"
	.string "es sein?\p"
	.string "Anker gelichtet!\n"
	.string "PECKO, mein Schatz, wir setzen Segel!$"
	.endif
	.endif

DewfordTown_Text_JustTellMeWhenYouNeedToSetSail:
	.ifdef ENGLISH
	.string "MR. BRINEY: You just tell me whenever\n"
	.string "you need to set sail again!$"
	.else
	.ifdef GERMAN
	.string "MR. BRACK: Sag mir einfach Bescheid,\n"
	.string "wenn wir wieder Segel setzen sollen.$"
	.endif
	.endif

DewfordTown_Text_GettingItchToFish:
	.ifdef ENGLISH
	.string "This is a renowned fishing spot.\n"
	.string "Are you getting the itch to fish?$"
	.else
	.ifdef GERMAN
	.string "Dies ist ein berühmter Angelplatz.\n"
	.string "Hast du Lust zu angeln?$"
	.endif
	.endif

DewfordTown_Text_GiveYouOneOfMyRods:
	.ifdef ENGLISH
	.string "I hear you, and I like what\n"
	.string "you're saying!\p"
	.string "I'll give you one of my fishing RODS.$"
	.else
	.ifdef GERMAN
	.string "Ich habe dir genau zugehört und mir\n"
	.string "gefällt, was du gesagt hast!\p"
	.string "Ich werde dir eine meiner ANGELn\n"
	.string "geben.$"
	.endif
	.endif

DewfordTown_Text_ThrowInFishingAdvice:
	.ifdef ENGLISH
	.string "And, as an added bonus, I'll even throw\n"
	.string "in a little fishing advice!\p"
	.string "First, you want to face the water,\n"
	.string "then use the ROD.\p"
	.string "Focus your mind…\n"
	.string "If you get a bite, pull on the ROD.\p"
	.string "Sometimes you can snag something\n"
	.string "immediately, but with bigger catches,\l"
	.string "you need to time the pulls on your ROD\l"
	.string "to haul them in.$"
	.else
	.ifdef GERMAN
	.string "Und, als kleine Zugabe, gebe ich dir noch\n"
	.string "einige Tipps zum Angeln!\p"
	.string "Schau dir zuerst das Wasser an und dann\n"
	.string "benutze deine ANGEL.\p"
	.string "Konzentriere dich… Wenn etwas anbeißt,\n"
	.string "hol die ANGEL ein.\p"
	.string "Manchmal kannst du mit einem Mal etwas\n"
	.string "Großes fangen, manchmal musst du\l"
	.string "immer wieder kurz die ANGEL anheben,\l"
	.string "um etwas an Land zu ziehen.$"
	.endif
	.endif

DewfordTown_Text_ThatsTooBadThen:
	.ifdef ENGLISH
	.string "Oh, is that so?\n"
	.string "That's too bad, then.$"
	.else
	.ifdef GERMAN
	.string "Oh, wirklich?\n"
	.string "Das ist aber schade.$"
	.endif
	.endif

DewfordTown_Text_HowsYourFishing:
	.ifdef ENGLISH
	.string "Yo!\n"
	.string "How's your fishing?$"
	.else
	.ifdef GERMAN
	.string "Yeah!\n"
	.string "Wie steht’s mit deinen Angelkünsten?$"
	.endif
	.endif

DewfordTown_Text_GreatHaulInSomeBigOnes:
	.ifdef ENGLISH
	.string "Is that right! That's great!\n"
	.string "Haul in some big ones!$"
	.else
	.ifdef GERMAN
	.string "Also, wenn das stimmt… Das wäre\n"
	.string "großartig! Petri heil!$"
	.endif
	.endif

DewfordTown_Text_FishingAdvice:
	.ifdef ENGLISH
	.string "Oh, hey, don't get down on yourself!\n"
	.string "I'll give you a little fishing advice.\p"
	.string "First, you want to face the water,\n"
	.string "then use the ROD.\p"
	.string "Focus your mind…\n"
	.string "If you get a bite, pull the ROD.\p"
	.string "Sometimes you can snag something\n"
	.string "immediately, but with bigger catches,\l"
	.string "you need to time the pulls on your ROD\l"
	.string "to haul them in.$"
	.else
	.ifdef GERMAN
	.string "Hey, lass den Kopf nicht hängen! Ich\n"
	.string "gebe dir einige Tipps zum Angeln!\p"
	.string "Schau dir zuerst das Wasser an\n"
	.string "und dann benutze deine ANGEL.\p"
	.string "Konzentriere dich… Wenn etwas\n"
	.string "anbeißt, hol die ANGEL ein.\p"
	.string "Manchmal kannst du mit einem Mal etwas\n"
	.string "Großes fangen, manchmal musst du\limmer wieder kurz die ANGEL anheben,\l"
	.string "um etwas an Land zu ziehen.$"
	.endif
	.endif

DewfordTown_Text_XIsTheBiggestHappeningThingRight:
	.ifdef ENGLISH
	.string "I like what's hip, happening, and trendy.\n"
	.string "I'm always checking it out.\p"
	.string "Listen, have you heard about this new\n"
	.string "“{STR_VAR_1}”?\p"
	.string "That's right!\n"
	.string "Of course you know!\p"
	.string "I mean, sheesh,\n"
	.string "“{STR_VAR_1}”…\l"
	.string "It's the hottest thing in cool!\p"
	.string "Wherever you're from,\n"
	.string "“{STR_VAR_1}”\l"
	.string "is the biggest happening thing, right?$"
	.else
	.ifdef GERMAN
	.string "Ich mag, was hip, aufregend und modern\n"
	.string "ist. So etwas probiere ich immer aus.\p"
	.string "Hast du schon einmal was von\n"
	.string "“{STR_VAR_1}” gehört?\p"
	.string "Wusste ich es doch!\n"
	.string "Natürlich hast du schon davon gehört!\p"
	.string "Oh, meine Güte,\n"
	.string "“{STR_VAR_1}”…\l"
	.string "Das ist das Coolste überhaupt!\p"
	.string "Wo immer du auch herkommst,\n"
	.string "“{STR_VAR_1}”\l"
	.string "ist das Aufregendste überhaupt!$"
	.endif
	.endif

DewfordTown_Text_TellMeWhatsNewAndIn:
	.ifdef ENGLISH
	.string "Hunh?\n"
	.string "It's not the hip and happening thing?\p"
	.string "Well, hey, you have to tell me,\n"
	.string "what's new and what's “in”?$"
	.else
	.ifdef GERMAN
	.string "Wie bitte?\n"
	.string "Es ist nicht hip und aufregend?\p"
	.string "Nun, hey, dann verrate mir aber, was\n"
	.string "wirklich cool und “in” ist?$"
	.endif
	.endif

DewfordTown_Text_OfCourseIKnowAboutThat:
	.ifdef ENGLISH
	.string "Hunh?\n"
	.string "“{STR_VAR_2}”?\p"
	.string "… …\p"
	.string "…Uh… Yeah! That's right!\n"
	.string "Yeah, I knew that! Knew it all along!\p"
	.string "Of course I know about that!\n"
	.string "“{STR_VAR_2},” right?\p"
	.string "Yeah, that's it, it's there!\n"
	.string "Isn't “{STR_VAR_2}”\l"
	.string "the coolest, or what?\p"
	.string "It's the hippest thing in hip.\n"
	.string "You think I'd not know about it?\p"
	.string "“{STR_VAR_1}”…\n"
	.string "It's, like, so five minutes ago.\p"
	.string "Now, “{STR_VAR_2}” is\n"
	.string "what's vital and in tune with the times!$"
	.else
	.ifdef GERMAN
	.string "Was?\n"
	.string "“{STR_VAR_2}”?\p"
	.string "… …\p"
	.string "… Hm… Äh… Yeah! Das stimmt!\n"
	.string "Yeah, ich wusste das! Schon lange!\p"
	.string "Natürlich weiß ich das!\n"
	.string "“{STR_VAR_2}”, richtig?\p"
	.string "Yeah, das ist es, das ist es!\n"
	.string "Ist “{STR_VAR_2}”\l"
	.string "nicht das Coolste?\p"
	.string "Das ist die hippeste Sache überhaupt.\n"
	.string "Und du dachtest, ich wüsste das nicht?\p"
	.string "“{STR_VAR_1}”…\n"
	.string "Das ist doch schon uralt und unmodern.\p"
	.string "“{STR_VAR_2}” ist das,\n"
	.string "was vital und zeitgemäß ist!$"
	.endif
	.endif

DewfordTown_Text_XHuhIThinkYIsCool:
	.ifdef ENGLISH
	.string "Hmm…\n"
	.string "“{STR_VAR_2},” huh?\p"
	.string "But personally, I think\n"
	.string "“{STR_VAR_1}”\l"
	.string "is what's real in cool.$"
	.else
	.ifdef GERMAN
	.string "Hmm…\n"
	.string "“{STR_VAR_2}”, oder?\p"
	.string "Aber ich persönlich finde,\n"
	.string "“{STR_VAR_1}”\l"
	.string "ist das Coolste überhaupt!$"
	.endif
	.endif

DewfordTown_Text_HearOfAnyTrendsComeShareWithMe:
	.ifdef ENGLISH
	.string "Well, if you hear of any happening new\n"
	.string "trends, come share them with me, okay?$"
	.else
	.ifdef GERMAN
	.string "Wenn du irgendetwas über neue, auf-\n"
	.string "regende Sachen hörst, erzähl mir davon!$"
	.endif
	.endif

DewfordTown_Text_YeahDefinitionOfInRightNow:
	.ifdef ENGLISH
	.string "Yeah, absolutely right!\p"
	.string "“{STR_VAR_1}” is the\n"
	.string "definition of “in” right now.$"
	.else
	.ifdef GERMAN
	.string "Yeah, absolut richtig!\p"
	.string "“{STR_VAR_1}” ist die\n"
	.string "Definition von “in”.$"
	.endif
	.endif
