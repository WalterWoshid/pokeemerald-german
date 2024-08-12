.set LOCALID_SS_TIDAL, 2
.set LOCALID_FERRY_ATTENDANT, 3
.set LOCALID_MANIAC_1, 9
.set LOCALID_MANIAC_2, 10
.set LOCALID_GIRL, 12
.set LOCALID_CAMPER, 14
.set LOCALID_FISHERMAN_2, 18
.set LOCALID_MAN_4, 23

BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.ifdef ENGLISH
	.string "This is the BATTLE DOME!\n"
	.string "Your path to the invincible superstar!$"
	.else
	.ifdef GERMAN
	.string "Dies ist das KAMPFSTADION!\n"
	.string "Dein Weg zum unschlagbaren Superstar!$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.ifdef ENGLISH
	.string "This is the BATTLE FACTORY!\n"
	.string "Seek out the toughest POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die KAMPFFABRIK!\n"
	.string "Hier gibt es die härtesten POKéMON!$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.ifdef ENGLISH
	.string "This is the BATTLE PIKE!\n"
	.string "Choose one of three paths!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die KAMPFIPITIS!\n"
	.string "Welche der drei Bahnen betrittst du?$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.ifdef ENGLISH
	.string "This is the BATTLE TOWER.\p"
	.string "TRAINERS bring their best-raised\n"
	.string "POKéMON for elimination-style matches.$"
	.else
	.ifdef GERMAN
	.string "Dies ist der DUELLTURM.\p"
	.string "TRAINER tragen mit ihren besten\n"
	.string "POKéMON Ausscheidungskämpfe aus.$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.ifdef ENGLISH
	.string "Hello, are you here for the ferry?\n"
	.string "May I see your TICKET?$"
	.else
	.ifdef GERMAN
	.string "Hi! Möchtest du mit der Fähre fahren?\n"
	.string "Zeigst du mir bitte dein TICKET?$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.ifdef ENGLISH
	.string "{PLAYER} doesn't have the TICKET…\p"
	.string "I'm terribly sorry.\p"
	.string "You must have a TICKET to board\n"
	.string "the ferry.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} hat kein TICKET…\p"
	.string "Das tut mir schrecklich Leid.\p"
	.string "Nur mit einem TICKET kannst du mit der\n"
	.string "Fähre fahren.$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.ifdef ENGLISH
	.string "{PLAYER} flashed the TICKET.\p"
	.string "Perfect! That's all you need!\p"
	.string "And where would you like to go?$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} zückt das TICKET.\p"
	.string "Perfekt! Damit kannst du an Bord!\p"
	.string "Und wo soll die Reise hingehen?$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.ifdef ENGLISH
	.string "SLATEPORT CITY it is, then!$"
	.else
	.ifdef GERMAN
	.string "Nach GRAPHITPORT CITY?$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.ifdef ENGLISH
	.string "LILYCOVE CITY it is, then!$"
	.else
	.ifdef GERMAN
	.string "Nach SEEGRASULB CITY?$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.ifdef ENGLISH
	.string "Please sail with us another time!$"
	.else
	.ifdef GERMAN
	.string "Bitte komm später noch einmal wieder!$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.ifdef ENGLISH
	.string "Please board the ferry and wait for\n"
	.string "departure.$"
	.else
	.ifdef GERMAN
	.string "Bitte komm an Bord. Wir legen bald ab.$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.ifdef ENGLISH
	.string "Then, where would you like to go?$"
	.else
	.ifdef GERMAN
	.string "Und wo soll die Reise hingehen?$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.ifdef ENGLISH
	.string "I'm the best out of all my friends.\n"
	.string "But here…\l"
	.string "I've been useless!$"
	.else
	.ifdef GERMAN
	.string "Ich bin der Beste aus unserem\n"
	.string "Freundeskreis. Aber hier…\l"
	.string "Hier bin ich echt aufgeschmissen!$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.ifdef ENGLISH
	.string "I want to go to the BATTLE TOWER,\n"
	.string "but I can't find it even though I have\l"
	.string "a map of the BATTLE FRONTIER.\p"
	.string "This place is just too big!$"
	.else
	.ifdef GERMAN
	.string "Ich möchte gerne in den DUELLTURM,\n"
	.string "aber ich finde den einfach nicht, obwohl\l"
	.string "ich eine Karte der KAMPFZONE\p"
	.string "habe.\n"
	.string "Hier ist alles so groß…$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.ifdef ENGLISH
	.string "I wanted to take a challenge as soon\n"
	.string "as I arrived here.\p"
	.string "But on the way, I got seasick…\n"
	.string "Urrrrp…$"
	.else
	.ifdef GERMAN
	.string "Ich wollte mich einer Herausforderung\n"
	.string "stellen, sobald ich hier angekommen bin.\p"
	.string "Aber auf dem Weg hierhin bin ich\n"
	.string "seekrank geworden… hurps…$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.ifdef ENGLISH
	.string "It's not as if just anyone can come\n"
	.string "here, you know?\p"
	.string "Only those TRAINERS who've been\n"
	.string "recognized as tough are brought here.\p"
	.string "That's why many TRAINERS don't even\n"
	.string "know about the BATTLE FRONTIER.$"
	.else
	.ifdef GERMAN
	.string "Weißt du, hier kann nicht einfach jeder\n"
	.string "hinkommen.\p"
	.string "Nur die TRAINER, die durch ihr Talent\n"
	.string "und ihre Stärke aufgefallen sind,\l"
	.string "werden eingeladen.\p"
	.string "Deshalb haben viele TRAINER noch nie\n"
	.string "etwas über die KAMPFZONE gehört.$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.ifdef ENGLISH
	.string "Hey, bro…\p"
	.string "Are you sure we can make challenges\n"
	.string "even if we don't have any POKéMON?$"
	.else
	.ifdef GERMAN
	.string "Hey, Brüderchen…\p"
	.string "Bist du sicher, wir können Heraus-\n"
	.string "forderungen annehmen, obwohl wir\l"
	.string "keine POKéMON besitzen?$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.ifdef ENGLISH
	.string "Uh…\n"
	.string "I'm sure it'll be okay.\p"
	.string "I think…\p"
	.string "But remember that big scary guy?\n"
	.string "He said, “I'll lend you POKéMON!”$"
	.else
	.ifdef GERMAN
	.string "Ääh…\n"
	.string "Ich bin sicher, dass das geht!\p"
	.string "Denke ich…\p"
	.string "Erinnerst du dich an diesen großen\n"
	.string "unheimlichen Kerl, der sagte “Ich leihe\l"
	.string "euch POKéMON!”?$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.ifdef ENGLISH
	.string "That's the BATTLE FACTORY.\n"
	.string "You can rent strong POKéMON there.\p"
	.string "But it makes me wonder.\n"
	.string "Who's raising those rental POKéMON?$"
	.else
	.ifdef GERMAN
	.string "Dies ist die KAMPFFABRIK. Hier\n"
	.string "kannst du dir starke POKéMON leihen.\p"
	.string "Ich frage mich nur, wer diese POKéMON\n"
	.string "aufzieht?$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.ifdef ENGLISH
	.string "I'm scared of going into the BATTLE\n"
	.string "PIKE because of SEVIPER…\p"
	.string "B-but I came all the way here, so I will\n"
	.string "try to conquer everything!\l"
	.string "…Shudder…$"
	.else
	.ifdef GERMAN
	.string "Ich habe Angst, zur KAMPFIPITIS zu\n"
	.string "gehen. Ich fürchte mich vor VIPITIS…\p"
	.string "Ab-aber ich bin von so weit gekommen,\n"
	.string "ich muss einfach weitergehen!\l"
	.string "… Zitter bibber…$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.ifdef ENGLISH
	.string "Let's play rock, paper, scissors!\n"
	.string "One, two, three!\p"
	.string "… … … … … …$"
	.else
	.ifdef GERMAN
	.string "Komm, wir spielen Schere Stein Papier!\n"
	.string "Eins, zwei, drei!\p"
	.string "… … … … …\n"
	.string "…$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.ifdef ENGLISH
	.string "Yay! I won!\n"
	.string "I will take the BATTLE PIKE challenge!$"
	.else
	.ifdef GERMAN
	.string "Juhuu! Ich habe geeewonnen!!!\n"
	.string "Ich werde die KAMPFIPITIS-Heraus-\l"
	.string "forderung annehmen!$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.ifdef ENGLISH
	.string "Oh, no…\n"
	.string "I lost.\p"
	.string "I guess I'm not very lucky today.\n"
	.string "I'll put off my BATTLE PIKE challenge\l"
	.string "until tomorrow.$"
	.else
	.ifdef GERMAN
	.string "Oh jeee…\n"
	.string "Ich habe verloren.\p"
	.string "Heute ist anscheinend nicht mein\n"
	.string "Glückstag. Ich warte mit der Eroberung\l"
	.string "der KAMPFIPITIS bis morgen.$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.ifdef ENGLISH
	.string "I believe I'm the only person here who,\n"
	.string "for some unknown reason, would choose\l"
	.string "fishing over battling.\p"
	.string "Huh? You can't catch anything here?\n"
	.string "That's disappointing…$"
	.else
	.ifdef GERMAN
	.string "Ich glaube, ich bin das einzige Wesen\n"
	.string "hier, das lieber angelt als kämpft.\l"
	.string "Warum auch immer…\p"
	.string "Wie? Hier kann man gar nichts fangen?!?\n"
	.string "Was für eine Enttäuschung…$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.ifdef ENGLISH
	.string "Today, I'm going to keep battling, no\n"
	.string "matter what, until I get a Symbol.$"
	.else
	.ifdef GERMAN
	.string "Heute werde ich unter allen Umständen\n"
	.string "so lange kämpfen, bis ich ein SYMBOL\l"
	.string "bekomme!$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.ifdef ENGLISH
	.string "Oh? You're off to challenge\n"
	.string "the BATTLE DOME?\p"
	.string "I'll wish you the best of luck.\n"
	.string "Let us both win our way up and meet\l"
	.string "in challenges.$"
	.else
	.ifdef GERMAN
	.string "Wie? Du willst dich den Heraus-\n"
	.string "forderungen des KAMPFSTADIONs\l"
	.string "stellen?\p"
	.string "Dann wünsche ich dir viel Glück!\n"
	.string "Wir siegen uns den Weg nach oben und\l"
	.string "treffen uns an der Spitze wieder.$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.ifdef ENGLISH
	.string "Grandpa, over here!\n"
	.string "The BATTLE DOME is here!\l"
	.string "Go get 'em, Grandpa!$"
	.else
	.ifdef GERMAN
	.string "Opa, hier drüben!\n"
	.string "Das KAMPFSTADION ist hier!\l"
	.string "Los, Opa, zeig’s ihnen!$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.ifdef ENGLISH
	.string "Ah, so this here is the BATTLE DOME?\n"
	.string "I won't let GENTLEMEN beat me!\p"
	.string "But where is the entrance?$"
	.else
	.ifdef GERMAN
	.string "So, dies ist also das KAMPFSTADION?!?\n"
	.string "Kein GENTLEMAN wird mich besiegen!\p"
	.string "Aber wo ist denn nur der Eingang?$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.ifdef ENGLISH
	.string "There used to be nothing here not all\n"
	.string "that long ago.\p"
	.string "But, now look at this place! Amazing!\n"
	.string "I'll bring my mother out to see this.$"
	.else
	.ifdef GERMAN
	.string "Vor nicht allzu langer Zeit gab es hier\n"
	.string "nichts. Nur Ödnis.\p"
	.string "Und nun schau sich einer diesen Ort an!\n"
	.string "Unglaublich! Ich werde meine Mutter mal\l"
	.string "hierher bringen, damit sie das sieht.$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.ifdef ENGLISH
	.string "I've finally arrived at the BATTLE\n"
	.string "FRONTIER!\p"
	.string "I'm sure to grab attention with\n"
	.string "my looks and ability!$"
	.else
	.ifdef GERMAN
	.string "Endlich habe ich die KAMPFZONE\n"
	.string "erreicht.\p"
	.string "Mit meinem Aussehen und meinem Talent\n"
	.string "sorge ich bestimmt für Aufsehen.$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.ifdef ENGLISH
	.string "Munch, munch…\p"
	.string "It looks like this square's filled with\n"
	.string "tough people.\p"
	.string "Munch, munch…$"
	.else
	.ifdef GERMAN
	.string "… Kau… … Schmatz…\p"
	.string "Hier sind offensichtlich nur starke\n"
	.string "Typen anwesend.\p"
	.string "… Schmatz… … Kau…$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.ifdef ENGLISH
	.string "Crunch, munch…\p"
	.string "A while back, I met this older girl\n"
	.string "at the BATTLE PIKE.\p"
	.string "She had these eyes that were scary\n"
	.string "in a real ornery way.\p"
	.string "Crunch, munch…\p"
	.string "She got all furious: “Will you quit\n"
	.string "eating!” Then she whaled on me.\p"
	.string "It was a hair-raising kind of\n"
	.string "scary experience, sure enough.\p"
	.string "Crunch, munch…$"
	.else
	.ifdef GERMAN
	.string "… Mampf… … Mampf…\p"
	.string "Vor einiger Zeit habe ich dieses ältere\n"
	.string "Mädchen an der KAMPFIPITIS getroffen.\p"
	.string "Ihre Augen hatten einen bösartigen\n"
	.string "Ausdruck, sie machte einem richtig\l"
	.string "Angst.\p"
	.string "… Mampf… … Mampf…\p"
	.string "Sie wurde richtig giftig: “KÖNNTEST DU\n"
	.string "WOHL ENDLICH AUFHÖREN ZU ESSEN?!?”\p"
	.string "Dann hat sie sich lustig über mich\n"
	.string "gemacht.\p"
	.string "Das war wirklich haarsträubend\n"
	.string "unheimlich. Ehrlich!\p"
	.string "… Mampf… … Mampf…$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.ifdef ENGLISH
	.string "Huh? Will you listen to yourself?\n"
	.string "That's nothing!\p"
	.string "Why, the last time I cheered for him,\n"
	.string "our eyes met and sparks flew!$"
	.else
	.ifdef GERMAN
	.string "Was? Hör dir doch mal selber zu!\n"
	.string "Das ist doch wirklich popelig!\p"
	.string "Das letzte Mal als ICH ihm zugejubelt\n"
	.string "habe, haben sich unsere Augen\p"
	.string "getroffen. Es hat richtig gefunkt\n"
	.string "zwischen uns!$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.ifdef ENGLISH
	.string "Whaaaaaat?!\n"
	.string "Pfft!\p"
	.string "That only happened because\n"
	.string "I happened to be sitting next to you!\p"
	.string "The DOME ACE only looked our way\n"
	.string "because my cheering was so loud!$"
	.else
	.ifdef GERMAN
	.string "WIIIIIE BITTE?!?\n"
	.string "HAH! Ha ha ha!\p"
	.string "Der STADIONSTAR hat doch nur in deine\n"
	.string "Richtung geschaut, weil ICH ihm\l"
	.string "zugejubelt habe!$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.ifdef ENGLISH
	.string "Oh, shush!\n"
	.string "Keep that racket down!\p"
	.string "You fair-weather fans should stick\n"
	.string "to cheering for some GYM LEADER!\p"
	.string "The DOME ACE is mine!\n"
	.string "The only idol for me!$"
	.else
	.ifdef GERMAN
	.string "Oh, bitte, vertragt euch!\n"
	.string "Hört auf zu streiten!\p"
	.string "Ihr solltet lieber einem ARENALEITER\n"
	.string "zujubeln!\p"
	.string "Der STADIONSTAR ist mein großes Idol!\n"
	.string "Ihr seid zu jung, um sein Talent zu\l"
	.string "verstehen!$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.ifdef ENGLISH
	.string "Those people squabbling over there…\p"
	.string "It's hard to believe, but they once\n"
	.string "were TRAINERS, and good ones, too.\p"
	.string "They used to be incredibly tough,\n"
	.string "and they were famous, too.\p"
	.string "But they were obliterated by this\n"
	.string "certain TRAINER at a tournament.\p"
	.string "They were so thoroughly whipped,\n"
	.string "they became smitten by the TRAINER.\p"
	.string "Now they're just fans of the TRAINER.\n"
	.string "They go cheer for their idol at the\l"
	.string "BATTLE DOME every day now.$"
	.else
	.ifdef GERMAN
	.string "Diese Leute da, die sich gerade in den\n"
	.string "Haaren liegen…\p"
	.string "Es ist schwer zu glauben, aber das\n"
	.string "waren mal TRAINER. Gute TRAINER sogar!\p"
	.string "Sie waren stark und auch berühmt.\p"
	.string "Aber ein bestimmter TRAINER hat sie bei\n"
	.string "einem Turnier mit Pauken und Trompeten\l"
	.string "besiegt.\p"
	.string "Trotz ihrer Niederlage haben sie sich\n"
	.string "regelrecht in ihn verliebt.\p"
	.string "Nun leben sie ihr Leben als Fans und\n"
	.string "jubeln diesem TRAINER jeden Tag im\l"
	.string "KAMPFSTADION zu.$"
	.endif
	.endif

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.ifdef ENGLISH
	.string "I heard a rumor that someone saw\n"
	.string "a POKéMON with an unusually long tail\l"
	.string "somewhere in the BATTLE FRONTIER.\p"
	.string "It must be adorable. I'm sure of it…\p"
	.string "Oh, challenges can wait. I feel driven\n"
	.string "to find the delightful creature!$"
	.else
	.ifdef GERMAN
	.string "Ich habe gehört, dass jemand gehört\n"
	.string "hat, ein PKMN mit einem ungewöhnlich\l"
	.string "langen Schweif sei hier in der\p"
	.string "KAMPFZONE aufgetaucht. Das ist\n"
	.string "bestimmt anbetungswürdig…\p"
	.string "Die Herausforderungen können warten.\n"
	.string "Ich will dieses hübsche Geschöpf\l"
	.string "finden!$"
	.endif
	.endif

