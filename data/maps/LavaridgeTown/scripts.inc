.set LOCALID_RIVAL_ON_BIKE, 7
.set LOCALID_RIVAL, 8

LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_RIVAL, 11, 9
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LavaridgeTown_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LavaridgeTown_EventScript_RivalNoticePlayer::
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.ifdef ENGLISH
	.string "MAY: {PLAYER}{KUN}! Long time no see!\p"
	.string "Oh? While I visited the hot springs,\n"
	.string "you got the LAVARIDGE GYM BADGE.\p"
	.string "You must have collected\n"
	.string "good POKéMON…\l"
	.string "No, I believe you raised some.\p"
	.string "I guess it would be okay for you to\n"
	.string "have this.$"
	.else
	.ifdef GERMAN
	.string "MAIKE: {PLAYER}{KUN}! Wir haben uns lange\n"
	.string "nicht gesehen!\p"
	.string "Oh? Als ich die Heißen Quellen aufge-\n"
	.string "sucht habe, habe ich den ORDEN der\p"
	.string "ARENA von BAD LAVASTADT erhalten.\n"
	.string "Du hast anscheinend viele POKéMON\p"
	.string "gefangen… Äh, ich meine, du hast ja\n"
	.string "schon einige POKéMON aufgezogen. \p"
	.string "Ich denke, das hier wirst du gut\n"
	.string "gebrauchen können.$"
	.endif
	.endif

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.ifdef ENGLISH
	.string "MAY: With those GO-GOGGLES, you'll\n"
	.string "have no trouble getting through the\l"
	.string "desert near ROUTE 111.\p"
	.string "But, wow, {PLAYER}{KUN}…\n"
	.string "Challenging GYMS…\p"
	.string "You're trying hard because you don't\n"
	.string "want to lose to me, I bet!\p"
	.string "{PLAYER}{KUN}, I think I should challenge\n"
	.string "your dad in PETALBURG GYM.\p"
	.string "See you again!$"
	.else
	.ifdef GERMAN
	.string "MAIKE: Mit diesem WÜSTENGLAS wirst du\n"
	.string "keine Probleme haben, durch die Wüste\l"
	.string "in der Nähe von ROUTE 111 zu gehen.\p"
	.string "Aber, wow, {PLAYER}{KUN}…\n"
	.string "In ARENen antreten…\p"
	.string "Du strengst dich bestimmt sehr an, weil\n"
	.string "du nicht gegen mich verlieren willst!\p"
	.string "{PLAYER}{KUN}, ich glaube, ich sollte deinen\n"
	.string "Vater in der ARENA von BLÜTENBURG\l"
	.string "CITY herausfordern.\p"
	.string "{PLAYER}{KUN}, man sieht sich!$"
	.endif
	.endif

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.ifdef ENGLISH
	.string "BRENDAN: {PLAYER}, hey, it's been a while.\n"
	.string "How's it going?\p"
	.string "Hmm…\n"
	.string "That's a decent collection of BADGES.\p"
	.string "All right, then.\n"
	.string "You may as well have this.$"
	.else
	.ifdef GERMAN
	.string "BRIX: {PLAYER}, wie geht es dir?\p"
	.string "Hmm… Das ist eine beachtliche\n"
	.string "Sammlung von ORDEN.\p"
	.string "Also gut.\n"
	.string "Hier, dies schenke ich dir.$"
	.endif
	.endif

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.ifdef ENGLISH
	.string "BRENDAN: Keep those with you if you're\n"
	.string "planning on going into that desert near\l"
	.string "ROUTE 111.\p"
	.string "There should be some POKéMON that\n"
	.string "are exclusively desert-dwellers.\l"
	.string "You might look around for those.\p"
	.string "As for me…\n"
	.string "I'm considering challenging NORMAN,\l"
	.string "the GYM LEADER of PETALBURG.\p"
	.string "Unlike you, {PLAYER}, your dad looks like\n"
	.string "he really is tough.\p"
	.string "See you around!$"
	.else
	.ifdef GERMAN
	.string "BRIX: Nimm das mit, wenn du in die\n"
	.string "Wüste in der Nähe von ROUTE 111 willst.\p"
	.string "Da sollten sich einige POKéMON fangen\n"
	.string "lassen, die Wüstenbewohner sind. Schau\l"
	.string "dich nach ihnen um.\p"
	.string "Und ich…\n"
	.string "Ich werde wohl NORMAN, den ARENALEITER\l"
	.string "in BLÜTENBURG CITY, herausfordern.\p"
	.string "Im Gegensatz zu dir, macht dein Vater\n"
	.string "einen sehr starken Eindruck.\p"
	.string "Man sieht sich!$"
	.endif
	.endif

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.ifdef ENGLISH
	.string "I have here an EGG.\p"
	.string "I'd hoped to hatch it by covering it in\n"
	.string "hot sand by the hot springs.\l"
	.string "But that doesn't seem to be enough…\p"
	.string "I've heard it would be best if it were\n"
	.string "kept together with POKéMON and\l"
	.string "carried about.\p"
	.string "You are a TRAINER, yes?\n"
	.string "And your POKéMON radiate vitality.\p"
	.string "So, what say you?\n"
	.string "Will you take this EGG to hatch?$"
	.else
	.ifdef GERMAN
	.string "Ich habe hier ein EI.\p"
	.string "Ich dachte, ich könnte es ausbrüten,\n"
	.string "indem ich es im heißen Sand bei den\p"
	.string "Heißen Quellen vergrabe. Aber das\n"
	.string "reicht offensichtlich nicht aus.\p"
	.string "Jemand erzählte mir, dass man es\n"
	.string "zusammen mit den POKéMON tragen\l"
	.string "soll.\p"
	.string "Du bist ein TRAINER, nicht wahr? Und\n"
	.string "deine POKéMON strahlen Vitalität aus.\p"
	.string "So, was meinst du? Wirst du das EI mit-\n"
	.string "nehmen und zum Ausschlüpfen bringen?$"
	.endif
	.endif

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.ifdef ENGLISH
	.string "Good! I hope you'll walk plenty with\n"
	.string "this here EGG!$"
	.else
	.ifdef GERMAN
	.string "Gut! Ich hoffe, du hast mehr Glück\n"
	.string "mit diesem EI!$"
	.endif
	.endif

LavaridgeTown_Text_ReceivedTheEgg:
	.ifdef ENGLISH
	.string "{PLAYER} received the EGG.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} erhält ein EI.$"
	.endif
	.endif

LavaridgeTown_Text_NoRoomForThisEgg:
	.ifdef ENGLISH
	.string "Oh? You've too many POKéMON.\n"
	.string "There's no room for this EGG…$"
	.else
	.ifdef GERMAN
	.string "Oh! Du hast zu viele POKéMON dabei.\n"
	.string "Du hast keinen Platz für das EI…$"
	.endif
	.endif

LavaridgeTown_Text_AsYouWishThen:
	.ifdef ENGLISH
	.string "As you wish, then…\p"
	.string "If you have a change of heart about\n"
	.string "hatching this EGG, I will be here.$"
	.else
	.ifdef GERMAN
	.string "Ganz, wie du willst…\p"
	.string "Wenn dein Herz sich anders entscheidet\n"
	.string "und das EI haben möchte, ich bin hier.$"
	.endif
	.endif

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.ifdef ENGLISH
	.string "Every so often, an EGG will be found at\n"
	.string "the POKéMON DAY CARE.\p"
	.string "Or at least that's how the rumor goes.$"
	.else
	.ifdef GERMAN
	.string "Von Zeit zu Zeit findet man in der\n"
	.string "PENSION ein EI.\p"
	.string "So zumindest erzählt man es sich.$"
	.endif
	.endif

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.ifdef ENGLISH
	.string "We draw as much hot water as we need,\n"
	.string "and yet the hot springs never run dry.\p"
	.string "Isn't it magical?\p"
	.string "These hot springs appear near active\n"
	.string "volcanoes. Veins of water under the\l"
	.string "ground are heated by magma to well up\l"
	.string "as hot springs.$"
	.else
	.ifdef GERMAN
	.string "Wir nehmen uns so viel heißes Wasser,\n"
	.string "wie wir brauchen, und trotzdem trocknen\l"
	.string "die Heißen Quellen nicht aus.\p"
	.string "Ist das nicht schon fast Magie?\p"
	.string "Diese Heißen Quellen bilden sich in der\n"
	.string "Nähe von aktiven Vulkanen. Wasseradern\l"
	.string "im Boden werden durch das Magma\l"
	.string "erhitzt und kommen als heiße Quellen\l"
	.string "an die Erdoberfläche.$"
	.endif
	.endif

LavaridgeTown_Text_PokemonNippedBackside:
	.ifdef ENGLISH
	.string "Being buried in this hot sand is…\n"
	.string "Sigh…\p"
	.string "So warm and heavenly…\p"
	.string "Eh? Gyaah! Ouch!\p"
	.string "A POKéMON nipped my backside!$"
	.else
	.ifdef GERMAN
	.string "Hier im heißen Sand vergraben zu sein,\n"
	.string "ist…  Seufz…\p"
	.string "So warm und einfach himmlisch… Seufz…\p"
	.string "Äh? Gyaah! Aua!\p"
	.string "Ein POKéMON hat meinen Rücken ange-\n"
	.string "knabbert!$"
	.endif
	.endif

LavaridgeTown_Text_OhYouLikeHotSprings:
	.ifdef ENGLISH
	.string "Oh, you like hot springs, do you?\p"
	.string "That's surprising for one as young\n"
	.string "as you.$"
	.else
	.ifdef GERMAN
	.string "Ach, du magst auch heiße Quellen?\p"
	.string "Das ist überraschend bei einem so\n"
	.string "jungen Menschen wie dir.$"
	.endif
	.endif

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.ifdef ENGLISH
	.string "I bathe in the hot springs every day.\p"
	.string "I want to become a beautiful and strong\n"
	.string "GYM LEADER like FLANNERY.$"
	.else
	.ifdef GERMAN
	.string "Ich bade jeden Tag in den\n"
	.string "Heißen Quellen.\p"
	.string "Ich will ein wunderschöner und starker\n"
	.string "ARENALEITER wie FLAVIA werden.$"
	.endif
	.endif

LavaridgeTown_Text_IfPokemonInHotSprings:
	.ifdef ENGLISH
	.string "If people put POKéMON in hot springs,\n"
	.string "it might be seriously strange.\p"
	.string "Why, it might be an electric bath, or\n"
	.string "a bubble bath, or even a lava bath…$"
	.else
	.ifdef GERMAN
	.string "Wenn Leute ihre POKéMON in die Heißen\n"
	.string "Quellen setzen, ist das schon\l"
	.string "merkwürdig.\p"
	.string "Nun, es könnte auch ein Bad in\n"
	.string "Elektrizität, ein Schaumbad oder sogar\l"
	.string "ein Bad in Lava sein…$"
	.endif
	.endif

LavaridgeTown_Text_HotSpringsClaims:
	.ifdef ENGLISH
	.string "They're claiming that these hot springs\n"
	.string "are good for calming nervous tension,\l"
	.string "relieving aching muscles, solving\l"
	.string "romantic problems, and attracting\l"
	.string "money…$"
	.else
	.ifdef GERMAN
	.string "Man sagt, diese Heißen Quellen seien\n"
	.string "gut gegen nervliche Anspannungen, ge-\l"
	.string "gen Muskelkrämpfe, sie sollen bei\l"
	.string "romantischen Problemen helfen und\l"
	.string "auch bei Geldsorgen…$"
	.endif
	.endif

LavaridgeTown_Text_TownSign:
	.ifdef ENGLISH
	.string "LAVARIDGE TOWN\p"
	.string "“POKéMON CENTER HOT SPRINGS\n"
	.string "An excellent place for relaxing!”$"
	.else
	.ifdef GERMAN
	.string "BAD LAVASTADT\p"
	.string "“POKéMON-CENTER - HEISSE QUELLEN\n"
	.string "Der ideale Ort zum Entspannen!”$"
	.endif
	.endif

LavaridgeTown_Text_GymSign:
	.ifdef ENGLISH
	.string "LAVARIDGE TOWN POKéMON GYM\n"
	.string "LEADER: FLANNERY\l"
	.string "“One with a fiery passion that burns!”$"
	.else
	.ifdef GERMAN
	.string "POKéMON ARENA von BAD LAVASTADT\n"
	.string "LEITERIN: FLAVIA\l"
	.string "“Die mit der brennenden Leidenschaft!”$"
	.endif
	.endif

LavaridgeTown_Text_HerbShopSign:
	.ifdef ENGLISH
	.string "POKéMON HERB SHOP\n"
	.string "“Bitter taste--better cure!”$"
	.else
	.ifdef GERMAN
	.string "POKéMON KRÄUTERLADEN\n"
	.string "“Bitterer Geschmack - Bessere Kur!”$"
	.endif
	.endif
