.set LOCALID_WALLYS_DAD, 1

PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.ifdef ENGLISH
	.string "You're…\n"
	.string "Ah, you must be {PLAYER}{KUN}, right?\p"
	.string "Thank you for playing with WALLY a\n"
	.string "little while ago.\p"
	.string "He's been frail and sickly ever\n"
	.string "since he was a baby.\p"
	.string "We've sent him to stay with my relatives\n"
	.string "in VERDANTURF TOWN for a while.\p"
	.string "The air is a lot cleaner there\n"
	.string "than it is here.\p"
	.string "What's that? Where's WALLY?\n"
	.string "He's already left, our WALLY.\p"
	.string "I wonder where he could have\n"
	.string "gotten by now?$"
	.else
	.ifdef GERMAN
	.string "Du…\n"
	.string "Ach, du bist bestimmt {PLAYER}{KUN}, richtig?\p"
	.string "Danke, dass du dich um HEIKO gekümmert\n"
	.string "hast.\p"
	.string "Er war schon als Baby immer zart und\n"
	.string "kränklich.\p"
	.string "Wir haben ihn für eine Weile zu\n"
	.string "Verwandten nach WIESENFLUR\l"
	.string "geschickt.\p"
	.string "Die Luft ist dort viel sauberer als hier.\p"
	.string "Was heißt das? Wo ist HEIKO?\n"
	.string "Er ist fort, unser HEIKO?\p"
	.string "Ich frage mich, wo er jetzt wohl sein\n"
	.string "mag?$"
	.endif
	.endif

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.ifdef ENGLISH
	.string "I wonder how our WALLY is doing?$"
	.else
	.ifdef GERMAN
	.string "Ich frage mich, wie es unserem\n"
	.string "HEIKO geht.$"
	.endif
	.endif

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.ifdef ENGLISH
	.string "{PLAYER}{KUN}! Please excuse us for\n"
	.string "dragging you here this way.\p"
	.string "But our WALLY's become very healthy\n"
	.string "since he went to VERDANTURF TOWN.\p"
	.string "We owe it all to you!\p"
	.string "When WALLY left town, you helped\n"
	.string "him catch a POKéMON, right?\p"
	.string "I think that made WALLY really\n"
	.string "happy.\p"
	.string "Actually, not just WALLY.\n"
	.string "It made me, his father, happy too.\p"
	.string "Happy that he's gained such a great\n"
	.string "friend as you.\p"
	.string "This isn't a bribe or anything, but\n"
	.string "I'd really like you to have this.$"
	.else
	.ifdef GERMAN
	.string "Hallo {PLAYER}{KUN}! Bitte entschuldige,\n"
	.string "dass wir dich den weiten Weg hierher\l"
	.string "gerufen haben.\p"
	.string "Unser HEIKO ist viel robuster ge-\n"
	.string "worden, seit er in WIESENFLUR ist.\p"
	.string "Das verdanken wir allein dir!\p"
	.string "Als HEIKO den Ort verließ, hast du\n"
	.string "ihm geholfen, ein POKéMON zu fangen,\l"
	.string "stimmt’s?\p"
	.string "Ich glaube, das hat HEIKO richtig\n"
	.string "glücklich gemacht.\p"
	.string "Und nicht nur HEIKO. Auch mich als\n"
	.string "Vater hat es sehr glücklich gemacht.\p"
	.string "Glücklich darüber, dass er einen Freund\n"
	.string "wie dich gefunden hat.\p"
	.string "Das soll jetzt keine Bestechung sein!\n"
	.string "Aber ich möchte dir dies schenken.$"
	.endif
	.endif

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.ifdef ENGLISH
	.string "If your POKéMON can SURF, you'll be\n"
	.string "able to go to all sorts of places.$"
	.else
	.ifdef GERMAN
	.string "Wenn dein POKéMON SURFER beherrscht,\n"
	.string "kannst du viele neue Orte bereisen.$"
	.endif
	.endif

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.ifdef ENGLISH
	.string "WALLY's coming home soon.\n"
	.string "I'm looking forward to that.$"
	.else
	.ifdef GERMAN
	.string "HEIKO wird bald wieder nach Hause\n"
	.string "kommen. Ich freue mich schon so.$"
	.endif
	.endif

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.ifdef ENGLISH
	.string "Oh? You met WALLY in\n"
	.string "EVER GRANDE CITY?\p"
	.string "Oh, {PLAYER}{KUN}, don't be silly.\p"
	.string "He may have gotten healthy, but he\n"
	.string "can't go somewhere far away like\l"
	.string "that all by himself.$"
	.else
	.ifdef GERMAN
	.string "Oh! Du hast HEIKO in PRACHTPOLIS CITY\n"
	.string "getroffen?\p"
	.string "Ach, {PLAYER}{KUN}, du willst mich auf den Arm\n"
	.string "nehmen!\p"
	.string "Er mag sich gesundheitlich erholt\n"
	.string "haben, aber er wird nicht alleine so weit\l"
	.string "fortgegangen sein!$"
	.endif
	.endif

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.ifdef ENGLISH
	.string "WALLY was really happy when he told\n"
	.string "us that he caught a POKéMON.\p"
	.string "It's been ages since I've seen him\n"
	.string "smile like that.$"
	.else
	.ifdef GERMAN
	.string "HEIKO war richtig glücklich, als er\n"
	.string "uns erzählte, dass er ein POKéMON\l"
	.string "gefangen habe.\p"
	.string "Ich habe ihn schon seit Ewigkeiten\n"
	.string "nicht mehr so glücklich erlebt!$"
	.endif
	.endif

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.ifdef ENGLISH
	.string "I want you to keep this a secret\n"
	.string "from my husband…\p"
	.string "But our WALLY left VERDANTURF TOWN\n"
	.string "without telling anyone.\p"
	.string "You know, WALLY is frail, but\n"
	.string "he's surprisingly strong-willed.\p"
	.string "I'm sure that he'll come back safe\n"
	.string "and sound one day!$"
	.else
	.ifdef GERMAN
	.string "Ich muss das vor meinem Mann\n"
	.string "verheimlichen…\p"
	.string "Aber unser HEIKO hat WIESENFLUR\n"
	.string "verlassen, ohne jemandem davon zu\l"
	.string "erzählen.\p"
	.string "Weißt du, HEIKO ist nicht kräftig,\n"
	.string "besitzt aber einen starken Willen.\p"
	.string "Ich bin sicher, er wird gesund und wohl-\n"
	.string "behalten wieder nach Hause kommen.$"
	.endif
	.endif

