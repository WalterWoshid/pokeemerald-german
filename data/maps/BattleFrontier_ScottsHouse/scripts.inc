.set LOCALID_SCOTT, 1

BattleFrontier_ScottsHouse_MapScripts::
	.byte 0

BattleFrontier_ScottsHouse_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_4, BattleFrontier_ScottsHouse_EventScript_GivenBerry
	goto_if_set FLAG_TEMP_3, BattleFrontier_ScottsHouse_EventScript_GivenShield
	goto_if_set FLAG_TEMP_2, BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveItems
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveItems::
	goto_if_unset FLAG_SCOTT_GIVES_BATTLE_POINTS, BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols
	goto_if_unset FLAG_COLLECTED_ALL_GOLD_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveShield::
	goto_if_unset FLAG_RECEIVED_SILVER_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield
	goto_if_unset FLAG_RECEIVED_GOLD_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols::
	goto_if_unset FLAG_SYS_TOWER_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols, MSGBOX_DEFAULT
	giveitem ITEM_LANSAT_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_SILVER_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols::
	goto_if_unset FLAG_SYS_TOWER_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols, MSGBOX_DEFAULT
	giveitem ITEM_STARF_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_GOLD_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_BerryPocketFull::
	msgbox BattleFrontier_ScottsHouse_Text_BerryPocketStuffed, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenBerry::
	msgbox BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_RandomComment::
	random 3
	goto_if_eq VAR_RESULT, 1, BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment
	goto_if_eq VAR_RESULT, 2, BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment
	msgbox BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment::
	msgbox BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment::
	msgbox BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveSilverShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_SILVER_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_SILVER_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_NoRoomForShield::
	msgbox BattleFrontier_ScottsHouse_Text_ComeBackForThisLater, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenShield::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveGoldShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_GOLD_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_GOLD_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingGreatThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier::
	msgbox BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	closemessage
	delay 30
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest
	msgbox BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing, MSGBOX_DEFAULT
	goto_if_eq VAR_SCOTT_STATE, 13, BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 9, BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 6, BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint
	end

BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints::
	buffernumberstring STR_VAR_1, 4
	setvar VAR_0x8004, 4
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints::
	buffernumberstring STR_VAR_1, 3
	setvar VAR_0x8004, 3
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints::
	buffernumberstring STR_VAR_1, 2
	setvar VAR_0x8004, 2
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint::
	buffernumberstring STR_VAR_1, 1
	setvar VAR_0x8004, 1
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints::
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	msgbox BattleFrontier_ScottsHouse_Text_ExplainBattlePoints, MSGBOX_DEFAULT
	setflag FLAG_SCOTT_GIVES_BATTLE_POINTS
	setflag FLAG_TEMP_2
	release
	end

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth::
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth::
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast::
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest::
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier:
	.ifdef ENGLISH
	.string "SCOTT: Well, hello and welcome!\n"
	.string "Heheh… Sorry about the cramped space.\p"
	.string "Anyway, {PLAYER}{KUN}, let me formally\n"
	.string "welcome you to the BATTLE FRONTIER.\p"
	.string "This is my dream come true.\n"
	.string "It took me years and years, but I've\l"
	.string "finally given shape to my dream.$"
	.else
	.ifdef GERMAN
	.string "SCOTT: Oh, hallo! Herzlich willkommen!\n"
	.string "Ähähä… Bitte entschuldige die Enge.\p"
	.string "Nun, {PLAYER}{KUN}, ich darf dich herzlich\n"
	.string "hier in der KAMPFZONE begrüßen.\p"
	.string "Hier sind meine Träume wahr geworden.\n"
	.string "Jahre um Jahre anstrengender Arbeit,\l"
	.string "aber mein Traum ist Realität geworden!$"
	.endif
	.endif

BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal:
	.ifdef ENGLISH
	.string "On reflection, it was a terribly long\n"
	.string "journey…\p"
	.string "I left home alone on a quest to find\n"
	.string "strong TRAINERS.\p"
	.string "No one can imagine how much effort\n"
	.string "or time it took to make this real.$"
	.else
	.ifdef GERMAN
	.string "Rückblickend betrachtet war es eine\n"
	.string "lange Reise…\p"
	.string "Ich habe meine Heimat verlassen und\n"
	.string "mich auf die Suche nach starken\l"
	.string "TRAINERn gemacht.\p"
	.string "Niemand kann sich vorstellen, wie viel\n"
	.string "Zeit und wie viel Anstrengungen es mich\l"
	.string "gekostet hat, dies hier zu realisieren.$"
	.endif
	.endif

BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing:
	.ifdef ENGLISH
	.string "But that's all in the past.\n"
	.string "No point dwelling on that!\p"
	.string "All I want for you is to enjoy battling\n"
	.string "to your heart's content here.\p"
	.string "{PLAYER}{KUN}, I want you to have this\n"
	.string "as a memento for all the time our\l"
	.string "paths crossed on our journeys.$"
	.else
	.ifdef GERMAN
	.string "Aber lassen wir die Vergangenheit\n"
	.string "ruhen.\p"
	.string "Alles, was ich mir wünsche ist, dass du\n"
	.string "die Kämpfe hier aus vollem Herzen\l"
	.string "genießt.\p"
	.string "{PLAYER}{KUN}! Ich möchte dir dies als\n"
	.string "Andenken geben. Es soll dich daran er-\l"
	.string "innern, wie sich unsere Wege kreuzten.$"
	.endif
	.endif

BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints:
	.ifdef ENGLISH
	.string "{PLAYER} obtained\n"
	.string "{STR_VAR_1} Battle Point(s).$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} erhält {STR_VAR_1} Gewinnpunkt(e).$"
	.endif
	.endif

BattleFrontier_ScottsHouse_Text_ExplainBattlePoints:
	.ifdef ENGLISH
	.string "SCOTT: You can check your Battle\n"
	.string "Points on your FRONTIER PASS.\p"
	.string "The more success you have here at\n"
	.string "the BATTLE FRONTIER, the more Battle\l"
	.string "Points you will collect.\p"
	.string "Use your Battle Points the way you\n"
	.string "see fit, like trading them for items.$"
	.else
	.ifdef GERMAN
	.string "SCOTT: Du kannst die Anzahl deiner\n"
	.string "Gewinnpunkte auf deinem KAMPFZONEN-\l"
	.string "PASS ablesen.\p"
	.string "Je erfolgreicher du hier in der KAMPF-\n"
	.string "ZONE bist, desto mehr Gewinnpunkte\l"
	.string "erhältst du.\p"
	.string "Verwende sie ganz wie du magst. Tausche\n"
	.string "sie zum Beispiel gegen Items ein.$"
	.endif
	.endif

BattleFrontier_ScottsHouse_Text_ExpectingGreatThings:
	.ifdef ENGLISH
	.string "I'm expecting great things from you!$"
	.else
	.ifdef GERMAN
	.string "Ich erwarte Großes von dir!$"
	.endif
	.endif

BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers:
	.ifdef ENGLISH
	.string "SCOTT: Every TRAINER is an individual.\n"
	.string "They all lead lives of their own.\p"
	.string "But when they're in a battle,\n"
	.string "it doesn't matter who they are.\p"
	.string "They're all the same!\p"
	.string "I love the purity of battle,\n"
	.string "where everyone is equal.\p"
	.string "That's why I go everywhere seeking\n"
	.string "TRAINERS who are serious about\l"
	.string "battling, and invite them here.$"
	.else
	.ifdef GERMAN
	.string "SCOTT: Jeder TRAINER ist ein\n"
	.string "Individuum. Sie leben alle ihr Leben.\p"
	.string "Aber in Kämpfen ist es völlig egal,\n"
	.string "wer oder was sie sind.\p"
	.string "Sie sind alle gleich!\p"
	.string "Ich liebe die Reinheit der Kämpfe, in\n"
	.string "denen jeder gleich ist.\p"
	.string "Deshalb bin ich immer auf der Suche\n"
	.string "nach TRAINERn, die ihre Sache ernst\l"
	.string "nehmen, und lade sie hierher ein.$"
	.endif
	.endif

BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain:
	.ifdef ENGLISH
	.string "SCOTT: Have you met any of\n"
	.string "the FRONTIER BRAINS?\p"
	.string "Better yet, have you obtained any\n"
	.string "symbols from them?\p"
	.string "I handpicked the FRONTIER BRAINS\n"
	.string "as the toughest TRAINERS anywhere.\p"
	.string "But I'm sure that seeing how tough\n"
	.string "you are will startle even them!$"
	.else
	.ifdef GERMAN
	.string "SCOTT: Hast du schon die KAMPF-\n"
	.string "KORYPHÄEN getroffen?\p"
	.string "Oder hast du SYMBOLE von ihnen\n"
	.string "bekommen?\p"
	.string "Die KAMPFKORYPHÄEN sind handverlesen.\n"
	.string "Ich habe die stärksten TRAINER selbst\l"
	.string "ausgesucht.\p"
	.string "Aber ich bin sicher, deine Stärke wird\n"
	.string "sie zum Zittern bringen!$"
	.endif
	.endif

BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier:
	.ifdef ENGLISH
	.string "SCOTT: You don't just train for battle,\n"
	.string "right?\p"
	.string "I think I remember you working on\n"
	.string "a POKéDEX as well.\p"
	.string "Well, guess what?\p"
	.string "You may run into wild POKéMON in\n"
	.string "the BATTLE FRONTIER somewhere…\l"
	.string "Fufufu!$"
	.else
	.ifdef GERMAN
	.string "SCOTT: Du trainierst doch nicht nur für\n"
	.string "Kämpfe, oder?\p"
	.string "Ich meine mich zu erinnern, dass du auch\n"
	.string "an deinem POKéDEX arbeitest?\p"
	.string "Soll ich dir was verraten?\p"
	.string "Auch hier in der KAMPFZONE wirst\n"
	.string "du auf wilde POKéMON treffen…\l"
	.string "irgendwo… Ha ha ha ha!$"
	.endif
	.endif

BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols:
	.ifdef ENGLISH
	.string "SCOTT: Are you enjoying things in\n"
	.string "the BATTLE FRONTIER?\p"
	.string "…Wait a second…\n"
	.string "Oh!\p"
	.string "Your FRONTIER PASS!\n"
	.string "You've collected the full set\l"
	.string "of silver symbols!\p"
	.string "That's more than impressive!\n"
	.string "You are tough, just as I suspected!\p"
	.string "Normally, I wouldn't do something\n"
	.string "like this, but this is a special time!\p"
	.string "I want you to have this.\n"
	.string "I'm sure you can put it to proper use.$"
	.else
	.ifdef GERMAN
	.string "SCOTT: Gefällt es dir hier in der\n"
	.string "KAMPFZONE?\p"
	.string "Warte mal!\n"
	.string "Oh…\p"
	.string "Dein KAMPFZONENPASS!\n"
	.string "Du hast ja alle silbernen SYMBOLE\l"
	.string "zusammen!\p"
	.string "Das ist mehr als beeindruckend!\n"
	.string "Du bist stark, genau, wie ich es\l"
	.string "erwartet hatte!\p"
	.string "Normalerweise mache ich so etwas nicht,\n"
	.string "aber dies hier ist eine besondere\l"
	.string "Situation.\p"
	.string "Ich möchte dir dies hier schenken!\n"
	.string "Ich bin sicher, du weißt es gut zu\l"
	.string "nutzen.$"
	.endif
	.endif

BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols:
	.ifdef ENGLISH
	.string "SCOTT: I hope you're enjoying\n"
	.string "everything in the BATTLE FRONTIER.\p"
	.string "…Wait a second…\n"
	.string "Oh, my disbelieving eyes!\p"
	.string "Your FRONTIER PASS!\n"
	.string "You've gathered up the full set\l"
	.string "of gold symbols!\p"
	.string "That's more than stupendous!\n"
	.string "You're incredible, just as I suspected!\p"
	.string "… … … … … …\p"
	.string "{PLAYER}, you've got to accept this!\p"
	.string "I think you will be able to\n"
	.string "appreciate the value of my gift!$"
	.else
	.ifdef GERMAN
	.string "SCOTT: Ich hoffe, es gefällt dir hier in\n"
	.string "der KAMPFZONE?\p"
	.string "Warte mal…\n"
	.string "Ich traue meinen Augen nicht!\p"
	.string "Dein KAMPFZONENPASS!\n"
	.string "Du hast ja alle goldenen SYMBOLE\l"
	.string "zusammen!!!\p"
	.string "Das ist mehr als hervorragend!\n"
	.string "Du bist einfach unglaublich - ich hatte\l"
	.string "nichts anderes erwartet!\p"
	.string "… … … …\n"
	.string "…\p"
	.string "{PLAYER}, du musst dies von mir\n"
	.string "annehmen!\p"
	.string "Ich weiß, du wirst den Wert dieses\n"
	.string "Geschenks erkennen!$"
	.endif
	.endif

BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere:
	.ifdef ENGLISH
	.string "I must say I have the gift of knowing\n"
	.string "a good TRAINER when I see one.\p"
	.string "I'm so glad I had the foresight to\n"
	.string "bring you here!$"
	.else
	.ifdef GERMAN
	.string "Ich kann von mir behaupten, einen guten\n"
	.string "TRAINER auf Anhieb erkennen zu können.\p"
	.string "Ich bin froh, dass ich dein Potenzial\n"
	.string "erkannt habe und dich hierher gebeten\l"
	.string "habe!$"
	.endif
	.endif

BattleFrontier_ScottsHouse_Text_BerryPocketStuffed:
	.ifdef ENGLISH
	.string "Your BERRY POCKET seems to\n"
	.string "be stuffed.$"
	.else
	.ifdef GERMAN
	.string "Deine BEERENTASCHE scheint voll\n"
	.string "zu sein.$"
	.endif
	.endif

BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow:
	.ifdef ENGLISH
	.string "SCOTT: Oh, I heard about you!\n"
	.string "How you ruled the BATTLE TOWER!\l"
	.string "You beat over 50 TRAINERS in a row?\p"
	.string "That's fantastic!\n"
	.string "I want you to have this!$"
	.else
	.ifdef GERMAN
	.string "SCOTT: Ich habe schon von dir gehört!\n"
	.string "Wie du den DUELLTURM bezwungen hast!\l"
	.string "Du hast 50 TRAINER in Folge besiegt!\p"
	.string "Das ist fantastisch!\n"
	.string "Ich möchte dir dies gerne schenken.$"
	.endif
	.endif

BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow:
	.ifdef ENGLISH
	.string "SCOTT: Oh, my! I heard about you!\n"
	.string "How you overwhelmed the BATTLE TOWER!\l"
	.string "You beat over 100 TRAINERS in a row?\p"
	.string "That's ridiculously spectacular!\n"
	.string "You've got to have this!$"
	.else
	.ifdef GERMAN
	.string "SCOTT: Ich habe schon von dir gehört!\n"
	.string "Wie du den DUELLTURM bezwungen hast!\l"
	.string "Du hast 100 TRAINER in Folge besiegt!\p"
	.string "Das ist einfach spektakulär!\n"
	.string "Ich muss dir dies einfach schenken!$"
	.endif
	.endif

BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings:
	.ifdef ENGLISH
	.string "I'll be expecting to hear even greater\n"
	.string "things about you now!$"
	.else
	.ifdef GERMAN
	.string "Ich erwarte von dir ab jetzt noch\n"
	.string "größere Taten!$"
	.endif
	.endif

BattleFrontier_ScottsHouse_Text_ComeBackForThisLater:
	.ifdef ENGLISH
	.string "Oops, well, if you have too much\n"
	.string "stuff, come back for this later.$"
	.else
	.ifdef GERMAN
	.string "Oh, schade! Komm doch einfach wieder,\n"
	.string "wenn du Platz geschaffen hast.$"
	.endif
	.endif

