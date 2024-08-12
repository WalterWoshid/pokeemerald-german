.set LOCALID_TRICK_MASTER, 1

Route110_TrickHouseEnd_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHouseEnd_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEnd_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEnd_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEnd_OnWarp
	.byte 0

Route110_TrickHouseEnd_OnResume:
	call_if_eq VAR_TEMP_1, 1, Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	end

Route110_TrickHouseEnd_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	special SetTrickHouseNuggetFlag
	end

Route110_TrickHouseEnd_OnWarp:
	map_script_2 VAR_TEMP_2, 0, Route110_TrickHouseEnd_EventScript_SetTrickMasterPos
	.2byte 0

Route110_TrickHouseEnd_EventScript_SetTrickMasterPos::
	addobject LOCALID_TRICK_MASTER
	showobjectat LOCALID_TRICK_MASTER, MAP_ROUTE110_TRICK_HOUSE_END
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
	end

Route110_TrickHouseEnd_OnFrame:
	map_script_2 VAR_TEMP_1, 0, Route110_TrickHouseEnd_EventScript_CloseDoor
	.2byte 0

Route110_TrickHouseEnd_EventScript_CloseDoor::
	setvar VAR_TEMP_1, 1
	call Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	special DrawWholeMapView
	end

Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile::
	setmetatile 10, 1, METATILE_GenericBuilding_TrickHouse_Door_Closed, TRUE
	return

Route110_TrickHouseEnd_EventScript_TrickMaster::
	lock
	faceplayer
	msgbox Route110_TrickHouseEnd_Text_YouveMadeItToMe, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEnd_EventScript_CompletedPuzzle1
	case 1, Route110_TrickHouseEnd_EventScript_CompletedPuzzle2
	case 2, Route110_TrickHouseEnd_EventScript_CompletedPuzzle3
	case 3, Route110_TrickHouseEnd_EventScript_CompletedPuzzle4
	case 4, Route110_TrickHouseEnd_EventScript_CompletedPuzzle5
	case 5, Route110_TrickHouseEnd_EventScript_CompletedPuzzle6
	case 6, Route110_TrickHouseEnd_EventScript_CompletedPuzzle7
	case 7, Route110_TrickHouseEnd_EventScript_CompletedPuzzle8
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle1::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPlantTrees, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_RARE_CANDY
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle2::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMaze, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TIMER_BALL
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle3::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPreparePanels, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_HARD_STONE
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle4::
	msgbox Route110_TrickHouseEnd_Text_AllNightToShoveBoulders, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_SMOKE_BALL
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle5::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TM_TAUNT
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle6::
	msgbox Route110_TrickHouseEnd_Text_AllNightToInstallDoors, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_MAGNET
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle7::
	msgbox Route110_TrickHouseEnd_Text_AllNightSettingUpArrows, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_PP_MAX
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle8::
	msgbox Route110_TrickHouseEnd_Text_AllNightPolishingFloors, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_SOUTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth
	call_if_eq VAR_FACING, DIR_NORTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth
	call_if_eq VAR_FACING, DIR_WEST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest
	call_if_eq VAR_FACING, DIR_EAST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast
	delay 30
	msgbox Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
	waitmovement 0
	delay 30
	msgbox Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	call Route110_TrickHouseEnd_EventScript_ChooseTent
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_NoRoomForTent
	msgbox Route110_TrickHouseEnd_Text_LeavingOnJourney, MSGBOX_DEFAULT
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	special ResetTrickHouseNuggetFlag
	release
	end

Route110_TrickHouseEnd_EventScript_ChooseTent::
	multichoice 0, 0, MULTI_TENT, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHouseEnd_EventScript_GiveRedTent
	goto Route110_TrickHouseEnd_EventScript_GiveBlueTent

Route110_TrickHouseEnd_EventScript_GiveRedTent::
	givedecoration DECOR_RED_TENT
	return

Route110_TrickHouseEnd_EventScript_GiveBlueTent::
	givedecoration DECOR_BLUE_TENT
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExit::
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterSpin
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterJumpAway
	waitmovement 0
	removeobject LOCALID_TRICK_MASTER
	addvar VAR_TRICK_HOUSE_LEVEL, 1
	return

Route110_TrickHouseEnd_EventScript_BagFull::
	call Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEnd_Text_NoRoomForThis, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_NoRoomForTent::
	call Common_EventScript_NoRoomForDecor
	msgbox Route110_TrickHouseEnd_Text_NoRoomInPC, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExitTrigger::
	lockall
	turnobject LOCALID_TRICK_MASTER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_TRICK_MASTER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouseEnd_Movement_TrickMasterSurprise
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route110_TrickHouseEnd_Text_YoureIgnoringMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route110_TrickHouseEnd_Movement_KeepPlayerInRoom
	waitmovement 0
	delay 4
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
	releaseall
	end

Route110_TrickHouseEnd_Movement_KeepPlayerInRoom:
	walk_down
	step_end

Route110_TrickHouseEnd_Movement_TrickMasterSurprise:
	jump_in_place_left
	step_end

Route110_TrickHouseEnd_Text_YouveMadeItToMe:
	.ifdef ENGLISH
	.string "Aak!\n"
	.string "You've made it to me?\l"
	.string "Hmmm… You're sharp!$"
	.else
	.ifdef GERMAN
	.string "Argh!\n"
	.string "Du hast mich gefunden?\l"
	.string "Hmmm… Du bist verdammt clever!$"
	.endif
	.endif

Route110_TrickHouseEnd_Text_AllNightToPlantTrees:
	.ifdef ENGLISH
	.string "It took me all night to plant all those\n"
	.string "trees…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two, three, four, five, six places!$"
	.else
	.ifdef GERMAN
	.string "Ich habe die ganze Nacht gebraucht,\n"
	.string "all die Bäume zu pflanzen…\p"
	.string "Du bist meiner Größe fast ebenbürtig,\n"
	.string "bis auf ein, zwei, drei, vier, fünf, sechs\l"
	.string "Punkte!$"
	.endif
	.endif

Route110_TrickHouseEnd_Text_AllNightToMakeMaze:
	.ifdef ENGLISH
	.string "It took me all night to make the maze…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two, three, four, five places!$"
	.else
	.ifdef GERMAN
	.string "Ich habe die ganze Nacht gebraucht,\n"
	.string "das Labyrinth anzulegen…\p"
	.string "Du bist meiner Größe fast ebenbürtig,\n"
	.string "bis auf ein, zwei, drei, vier, fünf \l"
	.string "Punkte!$"
	.endif
	.endif

Route110_TrickHouseEnd_Text_AllNightToPreparePanels:
	.ifdef ENGLISH
	.string "It took me all night to prepare\n"
	.string "the wall panels…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two, three, four places!$"
	.else
	.ifdef GERMAN
	.string "Ich habe die ganze Nacht gebraucht,\n"
	.string "die Wände zu platzieren…\p"
	.string "Du bist meiner Größe fast ebenbürtig,\n"
	.string "bis auf ein, zwei, drei, vier Punkte!$"
	.endif
	.endif

Route110_TrickHouseEnd_Text_AllNightToShoveBoulders:
	.ifdef ENGLISH
	.string "It took me all night to shove in those\n"
	.string "boulders…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two, three places!$"
	.else
	.ifdef GERMAN
	.string "Ich habe die ganze Nacht gebraucht,\n"
	.string "die Felsen hin- und herzuschieben…\p"
	.string "Du bist meiner Größe fast ebenbürtig,\n"
	.string "bis auf ein, zwei, drei Punkte!$"
	.endif
	.endif

Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls:
	.ifdef ENGLISH
	.string "It took me all night to make MECHADOLLS\n"
	.string "and another to think up the quiz…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two places!$"
	.else
	.ifdef GERMAN
	.string "Ich habe die ganze Nacht gebraucht,\n"
	.string "die ROBOPUPPEn zu konstruieren und\l"
	.string "mir das Quiz auszudenken…\p"
	.string "Du bist meiner Größe fast ebenbürtig,\n"
	.string "bis auf ein oder zwei Punkte!$"
	.endif
	.endif

Route110_TrickHouseEnd_Text_AllNightToInstallDoors:
	.ifdef ENGLISH
	.string "It took me all night to install\n"
	.string "the doors…\p"
	.string "You're almost my equal in greatness!$"
	.else
	.ifdef GERMAN
	.string "Ich habe die ganze Nacht gebraucht,\n"
	.string "die Türen zu installieren…\p"
	.string "Du bist meiner Größe fast ebenbürtig!$"
	.endif
	.endif

Route110_TrickHouseEnd_Text_AllNightSettingUpArrows:
	.ifdef ENGLISH
	.string "It took me all night setting up arrows…\p"
	.string "You're my equal in greatness!$"
	.else
	.ifdef GERMAN
	.string "Ich habe die ganze Nacht gebraucht,\n"
	.string "die Pfeile anzubringen.\p"
	.string "Du bist meiner Größe ebenbürtig!$"
	.endif
	.endif

Route110_TrickHouseEnd_Text_AllNightPolishingFloors:
	.ifdef ENGLISH
	.string "It took me all night polishing floors…\p"
	.string "You're above me in greatness!\n"
	.string "Possibly…$"
	.else
	.ifdef GERMAN
	.string "Ich habe die ganze Nacht gebraucht,\n"
	.string "den Boden zu polieren…\p"
	.string "Du bist mir weit überlegen!\n"
	.string "Unmöglich…$"
	.endif
	.endif

Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry:
	.ifdef ENGLISH
	.string "Wh-what should I do?\n"
	.string "My fountain of ideas for tricks has\l"
	.string "run dry…\p"
	.string "Perhaps it is time I toured the country\n"
	.string "on a quest to devise new tricks…$"
	.else
	.ifdef GERMAN
	.string "Was soll ich nur tun?\n"
	.string "Die Quelle der Ideen für meine Tricks\l"
	.string "ist trocken gelegt…\p"
	.string "Vielleicht ist es an der Zeit, durch die\n"
	.string "Lande zu reisen und mich für neue\l"
	.string "Tricks inspirieren zu lassen…$"
	.endif
	.endif

Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent:
	.ifdef ENGLISH
	.string "I hate to admit defeat, but you have\n"
	.string "bested me!\p"
	.string "Still, you must have been reeled in by\n"
	.string "my charisma for you to visit me again\l"
	.string "and again. Yes, you must have!\p"
	.string "But that has nothing to do with my\n"
	.string "losing!\p"
	.string "In recognition of the friendship\n"
	.string "between you, the driven, and the genius\l"
	.string "that is myself, I demand that you take\l"
	.string "this keepsake!\p"
	.string "Actually there are two--\n"
	.string "a RED TENT and a BLUE TENT.\l"
	.string "Which do you prefer?$"
	.else
	.ifdef GERMAN
	.string "Ich hasse es, zuzugeben, dass ich be-\n"
	.string "siegt wurde. Du hast mich geschlagen!\p"
	.string "Mein Charisma muss dich gefangen\n"
	.string "genommen haben, da du immer wieder\l"
	.string "herkommst. Ja, so muss es sein!\p"
	.string "Aber das hat nichts mit meiner\n"
	.string "Niederlage zu tun!\p"
	.string "Als Zeichen der Freundschaft zwischen\n"
	.string "dir, dem Aufstrebenden, und mir, dem\l"
	.string "Genie, überreiche ich dir dieses\l"
	.string "Andenken!\p"
	.string "Eigentlich sind es zwei Andenken - \n"
	.string "ein ROTES ZELT und ein BLAUES ZELT.\l"
	.string "Welches möchtest du haben?$"
	.endif
	.endif

Route110_TrickHouseEnd_Text_NoRoomInPC:
	.ifdef ENGLISH
	.string "What? No room in your PC?\n"
	.string "What am I to make of that?\p"
	.string "I wish I could say that, but I am much\n"
	.string "too kind and caring, so come back later!$"
	.else
	.ifdef GERMAN
	.string "Was? Du hast keinen Platz im PC?\n"
	.string "Und was soll ich jetzt damit machen?\p"
	.string "Sei froh, dass ich so nett und rück-\n"
	.string "sichtsvoll bin. Ich verwahre es für\l"
	.string "dich. Komm einfach später wieder.$"
	.endif
	.endif

Route110_TrickHouseEnd_Text_LeavingOnJourney:
	.ifdef ENGLISH
	.string "… … … … … …\p"
	.string "I am leaving on a journey of discovery.\n"
	.string "A quest in search of new tricks.\p"
	.string "I wish that you will one day visit and\n"
	.string "entertain me again.\p"
	.string "And now, farewell!$"
	.else
	.ifdef GERMAN
	.string "… … … … … …\p"
	.string "Ich gehe jetzt auf eine Entdeckungs-\n"
	.string "reise. Auf die Suche nach neuen Tricks.\p"
	.string "Ich hoffe, du besuchst mich eines\n"
	.string "Tages wieder und unterhältst mich.\p"
	.string "Für heute lebe wohl!$"
	.endif
	.endif

Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward:
	.ifdef ENGLISH
	.string "Fine!\n"
	.string "You have earned this reward!$"
	.else
	.ifdef GERMAN
	.string "Gut!\n"
	.string "Du hast dir diese Belohnung verdient!$"
	.endif
	.endif

Route110_TrickHouseEnd_Text_NoRoomForThis:
	.ifdef ENGLISH
	.string "What? Have you no room for this?\n"
	.string "What manner of items do you carry?\p"
	.string "But fine, since you've reached me,\n"
	.string "your reward will be with me till later.$"
	.else
	.ifdef GERMAN
	.string "Was? Du hast keinen Platz dafür?\n"
	.string "Wie viele Items schleppst du denn mit?\p"
	.string "Aber du kannst dir deine Belohnung\n"
	.string "auch später bei mir abholen.$"
	.endif
	.endif

Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou:
	.ifdef ENGLISH
	.string "Scrub that smug smirk from your face!\n"
	.string "It's much too early to think you've won!\p"
	.string "I'll make new tricks to stump you, I will.\n"
	.string "You may mock me only when you're done.\p"
	.string "Come back for the next exciting\n"
	.string "installment!$"
	.else
	.ifdef GERMAN
	.string "Putz dir das selbstgefällige Grinsen\n"
	.string "von der Backe! Noch hast du nicht\l"
	.string "gewonnen!\p"
	.string "Ich werde neue Tricks erfinden, die\n"
	.string "dich zu Fall bringen werden. Zum Grinsen\p"
	.string "hast du erst Grund, wenn du es\n"
	.string "geschafft hast.\p"
	.string "Komm wieder, wenn ich die nächste\n"
	.string "interessante Installation fertig habe.$"
	.endif
	.endif

Route110_TrickHouseEnd_Text_YoureIgnoringMe:
	.ifdef ENGLISH
	.string "Now, now! You're ignoring me now?\n"
	.string "Now that, I consider heartbreaking!$"
	.else
	.ifdef GERMAN
	.string "Nun, nun! Du ignorierst mich?\n"
	.string "Das bricht mir glatt das Herz!$"
	.endif
	.endif

