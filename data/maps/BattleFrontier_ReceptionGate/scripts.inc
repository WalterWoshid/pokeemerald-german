.set LOCALID_GREETER, 1
.set LOCALID_GUIDE, 2
.set LOCALID_SCOTT, 4

BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_GREETER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_GUIDE, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
	.ifdef ENGLISH
	.string "Is it your first time here?\n"
	.string "Please step this way!$"
	.else
	.ifdef GERMAN
	.string "Bist du zum ersten Mal hier?\n"
	.string "Komm bitte hier entlang.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
	.ifdef ENGLISH
	.string "The front lines of POKéMON battling!\n"
	.string "Welcome to the BATTLE FRONTIER!$"
	.else
	.ifdef GERMAN
	.string "Der ultimative Ort für ultimative\n"
	.string "Kämpfe! Willkommen in der\l"
	.string "KAMPFZONE!$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
	.ifdef ENGLISH
	.string "For a first-time visitor, we issue\n"
	.string "the FRONTIER PASS.\p"
	.string "It's for use at all the facilities\n"
	.string "in the BATTLE FRONTIER.\p"
	.string "Here you are!$"
	.else
	.ifdef GERMAN
	.string "Jeder, der zum ersten Mal hier ist,\n"
	.string "bekommt einen KAMPFZONENPASS von uns.\p"
	.string "Damit kannst du alle Einrichtungen der\n"
	.string "KAMPFZONE besuchen.\p"
	.string "Hier, bitte schön!$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.ifdef ENGLISH
	.string "{PLAYER} obtained\n"
	.string "the FRONTIER PASS.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} erhält den KAMPFZONENPASS.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.ifdef ENGLISH
	.string "{PLAYER} placed the TRAINER CARD\n"
	.string "in the FRONTIER PASS.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} steckt den TRAINERPASS\n"
	.string "zum KAMPFZONENPASS.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
	.ifdef ENGLISH
	.string "We hope you enjoy all that the BATTLE\n"
	.string "FRONTIER has to offer!$"
	.else
	.ifdef GERMAN
	.string "Wir hoffen, dir gefällt, was die KAMPF-\n"
	.string "ZONE zu bieten hat.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.ifdef ENGLISH
	.string "???: Well, if it isn't {PLAYER}{KUN}!\n"
	.string "You came out here!$"
	.else
	.ifdef GERMAN
	.string "???: Oh, wenn das nicht {PLAYER}{KUN} ist!\n"
	.string "Du bist also doch gekommen! Schön!$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
	.ifdef ENGLISH
	.string "GUIDE: Oh! MR. SCOTT, sir!\n"
	.string "Good day to you, sir!$"
	.else
	.ifdef GERMAN
	.string "TUTOR: Oh! Herr SCOTT!\n"
	.string "Einen schönen guten Tag, der Herr!$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
	.ifdef ENGLISH
	.string "SCOTT: It's great to see you here,\n"
	.string "it really is!\p"
	.string "I hope you'll take your time and\n"
	.string "explore everywhere.\p"
	.string "Naturally, I hope you'll also experience\n"
	.string "the pure essence of battling.\p"
	.string "I also have my quarters here, so feel\n"
	.string "free to visit if you have time.$"
	.else
	.ifdef GERMAN
	.string "SCOTT: Es ist großartig, dich hier\n"
	.string "zu sehen!\p"
	.string "Ich hoffe, du hast ein bisschen Zeit\n"
	.string "mitgebracht, um dir hier alles\l"
	.string "anzusehen?!?\p"
	.string "Und natürlich hoffe ich auch, dass\n"
	.string "du die Reinheit unserer Kämpfe hier\l"
	.string "genießen wirst!\p"
	.string "Ich wohne hier auf dem Gelände,\n"
	.string "also komm mich doch mal besuchen!$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
	.ifdef ENGLISH
	.string "I'm your guide to the various facilities\n"
	.string "here in the BATTLE FRONTIER.$"
	.else
	.ifdef GERMAN
	.string "Ich begleite dich durch die\n"
	.string "Einrichtungen der KAMPFZONE.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.ifdef ENGLISH
	.string "Which would you like to learn about?$"
	.else
	.ifdef GERMAN
	.string "Was möchtest du gerne wissen?$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
	.ifdef ENGLISH
	.string "It is the gigantic tower considered\n"
	.string "to be the BATTLE FRONTIER's symbol.\p"
	.string "There are four kinds of BATTLE ROOMS\n"
	.string "in the tower for SINGLE, DOUBLE, MULTI,\l"
	.string "and LINK MULTI BATTLES.$"
	.else
	.ifdef GERMAN
	.string "Der riesige Turm ist das Symbol der\n"
	.string "KAMPFZONE.\p"
	.string "Es gibt vier verschiedene Arten von\n"
	.string "KAMPFRÄUMEN - für EINZEL-, DOPPEL-,\l"
	.string "MULTI- und LINK-MULTIKÄMPFE.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
	.ifdef ENGLISH
	.string "The BATTLE DOME is the large building\n"
	.string "shaped like a huge egg.\p"
	.string "Events named Battle Tourneys are held\n"
	.string "in this facility.\p"
	.string "The Battle Tourneys are offered in\n"
	.string "two courses--for SINGLE and DOUBLE\l"
	.string "BATTLES.$"
	.else
	.ifdef GERMAN
	.string "Das KAMPFSTADION hat die Form eines\n"
	.string "gewaltigen Eis.\p"
	.string "Hier werden so genannte Kampfturniere\n"
	.string "abgehalten.\p"
	.string "Diese können in EINZEL- oder DOPPEL-\n"
	.string "KÄMPFEN ausgefochten werden.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
	.ifdef ENGLISH
	.string "The BATTLE PALACE is the red building\n"
	.string "on the right of the BATTLE FRONTIER.\p"
	.string "There are two kinds of BATTLE HALLS\n"
	.string "for SINGLE and DOUBLE BATTLES.$"
	.else
	.ifdef GERMAN
	.string "Der KAMPFPALAST ist das rote Gebäude,\n"
	.string "ganz rechts in der KAMPFZONE.\p"
	.string "Hier gibt es zwei KAMPFHALLEn: Eine\n"
	.string "für EINZEL- und eine für DOPPELKÄMPFE.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
	.ifdef ENGLISH
	.string "The BATTLE ARENA is the dojo-like\n"
	.string "building at the center-right of\l"
	.string "the BATTLE FRONTIER.\p"
	.string "An event called the Set KO Tourney\n"
	.string "takes place at the BATTLE ARENA.$"
	.else
	.ifdef GERMAN
	.string "Das einem Dojo nachempfundene Gebäude\n"
	.string "ist der KAMPFRING, er ist in der\l"
	.string "Mitte rechts zu finden.\p"
	.string "Hier findet das K.O.-Teamturnier statt.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
	.ifdef ENGLISH
	.string "The BATTLE FACTORY is the large\n"
	.string "building that is the closest to us.\p"
	.string "An event called the Battle Swap\n"
	.string "is conducted there.\p"
	.string "The Battle Swap event is offered in\n"
	.string "two courses for SINGLE and DOUBLE\l"
	.string "BATTLES.$"
	.else
	.ifdef GERMAN
	.string "Uns am nächsten ist das große Gebäude\n"
	.string "der KAMPFFABRIK.\p"
	.string "Hier findet der so genannte Wechsel-\n"
	.string "kampf statt.\p"
	.string "Auch hier kannst du in EINZEL- oder\n"
	.string "DOPPELKÄMPFEN antreten.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
	.ifdef ENGLISH
	.string "The BATTLE PIKE is the building shaped\n"
	.string "like a POKéMON at the center-left of\l"
	.string "the BATTLE FRONTIER.\p"
	.string "An event called the Battle Choice\n"
	.string "is conducted there.$"
	.else
	.ifdef GERMAN
	.string "Das Gebäude, das wie ein POKéMON\n"
	.string "aussieht, ist die KAMPFIPITIS - in der\l"
	.string "Mitte links.\p"
	.string "Hier findet man die Kampfbahnen.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
	.ifdef ENGLISH
	.string "The BATTLE PYRAMID is the enormous\n"
	.string "pyramid.\p"
	.string "An event called the Battle Quest\n"
	.string "is conducted there.$"
	.else
	.ifdef GERMAN
	.string "Die KAMPFPYRAMIDE ist eine riesen-\n"
	.string "große Pyramide.\p"
	.string "Hier finden die so genannten Kampf-\n"
	.string "forschungen statt.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
	.ifdef ENGLISH
	.string "The RANKING HALL is located near\n"
	.string "the BATTLE TOWER.\p"
	.string "There, you may see the most fantastic\n"
	.string "records left by the TRAINERS that\l"
	.string "took on the many challenges of\l"
	.string "the BATTLE FRONTIER.$"
	.else
	.ifdef GERMAN
	.string "Die ERGEBNISHALLE befindet sich in der\n"
	.string "Nähe des DUELLTURMs.\p"
	.string "Hier kannst du dir die Rekorde\n"
	.string "der TRAINER anschauen, die sich den\l"
	.string "Herausforderungen der KAMPFZONE\l"
	.string "gestellt haben.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
	.ifdef ENGLISH
	.string "The EXCHANGE SERVICE CORNER is near\n"
	.string "the BATTLE TOWER.\p"
	.string "The Battle Points you have earned in\n"
	.string "the BATTLE FRONTIER may be exchanged\l"
	.string "for fabulous prizes there.$"
	.else
	.ifdef GERMAN
	.string "Die TAUSCHECKE befindet\n"
	.string "sich in der Nähe des DUELLTURMs.\p"
	.string "Hier kannst du Gewinnpunkte, die du in\n"
	.string "der KAMPFZONE erhalten hast,\l"
	.string "gegen tolle Preise eintauschen.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
	.ifdef ENGLISH
	.string "I'm your guide to the basic rules that\n"
	.string "are common to all the challenges\l"
	.string "offered by the facilities in the BATTLE\l"
	.string "FRONTIER.$"
	.else
	.ifdef GERMAN
	.string "Ich erkläre dir die Basisregeln, die für\n"
	.string "alle Herausforderungen der KAMPFZONE\l"
	.string "gelten.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.ifdef ENGLISH
	.string "What would you like to learn about?$"
	.else
	.ifdef GERMAN
	.string "Was möchtest du gerne wissen?$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
	.ifdef ENGLISH
	.string "All the challenges at the BATTLE\n"
	.string "FRONTIER's facilities come in\l"
	.string "two courses--Level 50 and Open Level.$"
	.else
	.ifdef GERMAN
	.string "Alle Herausforderungen der KAMPFZONE\n"
	.string "haben zwei Kategorien:\l"
	.string "Level 50 und Offene Kämpfe.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_Level50Info:
	.ifdef ENGLISH
	.string "The Level 50 course is open to POKéMON\n"
	.string "up to and including Level 50.\p"
	.string "Please keep in mind, however, that\n"
	.string "no TRAINER you face will have any\l"
	.string "POKéMON below Level 50.\p"
	.string "This course is the entry level for\n"
	.string "battles at the BATTLE FRONTIER.\p"
	.string "To begin, we hope you will challenge\n"
	.string "this course.$"
	.else
	.ifdef GERMAN
	.string "Die Level 50-Herausforderungen sind\n"
	.string "offen für POKéMON bis einschließlich\l"
	.string "Level 50.\p"
	.string "Beachte aber, dass kein TRAINER, gegen\n"
	.string "den du antrittst, POKéMON besitzt, die\l"
	.string "unter Level 50 sind!\p"
	.string "Diese Kategorie ist die Eingangsstufe\n"
	.string "für die Kämpfe in der KAMPFZONE.\p"
	.string "Wir hoffen, dass du dich am Anfang\n"
	.string "für diese Stufe entscheiden wirst.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
	.ifdef ENGLISH
	.string "The Open Level course places no limit\n"
	.string "on the levels of POKéMON entering\l"
	.string "challenges.\p"
	.string "The levels of your opponents will\n"
	.string "be adjusted to match the levels of\l"
	.string "your POKéMON.\p"
	.string "However, no TRAINER you face will\n"
	.string "have any POKéMON below Level 60.$"
	.else
	.ifdef GERMAN
	.string "In den Offenen Kämpfen gibt es kein\n"
	.string "Limit für die Level der POKéMON.\p"
	.string "Der Level deiner Gegner wird dem\n"
	.string "Level deiner POKéMON angepasst.\p"
	.string "Trotzdem wird kein TRAINER, gegen den\n"
	.string "du antrittst, ein POKéMON haben, das\l"
	.string "unter Level 60 ist.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
	.ifdef ENGLISH
	.string "Virtually any kind of POKéMON may take\n"
	.string "on the challenges at all facilities.\p"
	.string "EGGS and certain kinds of POKéMON,\n"
	.string "however, are not permitted.\p"
	.string "The numbers of POKéMON required for\n"
	.string "challenges will depend on the facility.\p"
	.string "At all facilities, however, two or more\n"
	.string "of the same kind of POKéMON are not\l"
	.string "permitted.$"
	.else
	.ifdef GERMAN
	.string "Praktisch gesehen, kann jede Art von\n"
	.string "POKéMON an jeder Herausforderung\l"
	.string "teilnehmen.\p"
	.string "EIer und bestimmte Arten von POKéMON\n"
	.string "sind dennoch nicht zugelassen.\p"
	.string "Die Anzahl der POKéMON, die du mit in den\n"
	.string "Kampf nehmen kannst, variiert von\l"
	.string "Einrichtung zu Einrichtung.\p"
	.string "In allen Einrichtungen gilt aber: Zwei\n"
	.string "oder mehr PKMN der gleichen Art dürfen\l"
	.string "nicht in einen Kampf gebracht werden.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
	.ifdef ENGLISH
	.string "When entering a challenge at a BATTLE\n"
	.string "FRONTIER facility, POKéMON may not\l"
	.string "be holding the same kind of item.\p"
	.string "Please make sure that all POKéMON\n"
	.string "entering a challenge are holding\l"
	.string "different items.$"
	.else
	.ifdef GERMAN
	.string "Nimmst du eine Herausforderung der\n"
	.string "KAMPFZONE an, musst du\p"
	.string "darauf achten, dass deine POKéMON\n"
	.string "unterschiedliche Items halten.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.ifdef ENGLISH
	.string "I'm your guide to the FRONTIER PASS.$"
	.else
	.ifdef GERMAN
	.string "Ich erkläre dir den KAMPFZONENPASS.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.ifdef ENGLISH
	.string "Which would you like to learn about?$"
	.else
	.ifdef GERMAN
	.string "Was möchtest du wissen?$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
	.ifdef ENGLISH
	.string "There are seven facilities at\n"
	.string "the BATTLE FRONTIER.\p"
	.string "TRAINERS who gain recognition for\n"
	.string "their abilities may be rewarded with\l"
	.string "symbols from each of the facilities.\p"
	.string "To earn a symbol, TRAINERS may need\n"
	.string "to defeat other TRAINERS in a row,\l"
	.string "and may need to win events repeatedly.\p"
	.string "It's certainly not easy to win symbols.\n"
	.string "I wish you the best of luck!$"
	.else
	.ifdef GERMAN
	.string "Es gibt sieben Einrichtungen hier in der\n"
	.string "KAMPFZONE.\p"
	.string "TRAINER, die sich durch hervorragendes\n"
	.string "Talent auszeichnen, können als\l"
	.string "Anerkennung SYMBOLE erlangen.\p"
	.string "Um diese Medaillen zu erhalten, müssen\n"
	.string "mehrere TRAINER in Folge besiegt\l"
	.string "werden und manchmal auch bestimmte\p"
	.string "Herausforderungen mehrmals bestritten\n"
	.string "werden. Es ist sicherlich nicht einfach,\l"
	.string "hier zu gewinnen. Daher: Viel Glück!$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
	.ifdef ENGLISH
	.string "It is possible to record one battle\n"
	.string "on your FRONTIER PASS.\p"
	.string "You may record a battle you had with\n"
	.string "a friend or friends.\p"
	.string "Or you may record a battle conducted\n"
	.string "at the BATTLE FRONTIER excluding\l"
	.string "matches at the BATTLE PIKE or\l"
	.string "the BATTLE PYRAMID.\p"
	.string "You may choose to record your match\n"
	.string "at the end of a battle.$"
	.else
	.ifdef GERMAN
	.string "Du hast die Möglichkeit, einen Kampf in\n"
	.string "deinen KAMPFZONENPASS aufnehmen zu\l"
	.string "lassen.\p"
	.string "Vielleicht möchtest du einen Kampf, den\n"
	.string "du gegen oder mit Freunden geführt\l"
	.string "hast, dort eintragen lassen.\p"
	.string "Oder du lässt Kämpfe in der KAMPFZONE\n"
	.string "eintragen. Kämpfe der\l"
	.string "KAMPFIPITIS und der KAMPFPYRAMIDE\l"
	.string "werden nicht eingetragen.\p"
	.string "Am Ende eines Kampfes kannst du dich\n"
	.string "entscheiden, ob du ihn eintragen lassen\l"
	.string "möchtest oder nicht.$"
	.endif
	.endif

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
	.ifdef ENGLISH
	.string "Battle Points are rewards given to\n"
	.string "TRAINERS who battled outstandingly\l"
	.string "at the BATTLE FRONTIER.\p"
	.string "You may trade in your Battle Points\n"
	.string "for prizes at the EXCHANGE SERVICE\l"
	.string "CORNER.$"
	.else
	.ifdef GERMAN
	.string "TRAINER, die herausragend in der\n"
	.string "KAMPFZONE gekämpft haben,\l"
	.string "erhalten so genannte Gewinnpunkte.\p"
	.string "Diese kannst du nach Belieben in der\n"
	.string "TAUSCHECKE gegen Preise eintauschen.$"
	.endif
	.endif

