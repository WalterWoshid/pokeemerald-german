.set LOCALID_GRUNT, 3
.set LOCALID_DEVON_EMPLOYEE, 4

PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_GRUNT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.ifdef ENGLISH
	.string "Hmmm…\n"
	.string "Not a one to be found…$"
	.else
	.ifdef GERMAN
	.string "Hmmm…\n"
	.string "Kein Einziges zu finden.$"
	.endif
	.endif

PetalburgWoods_Text_HaveYouSeenShroomish:
	.ifdef ENGLISH
	.string "Hello, have you seen any POKéMON\n"
	.string "called SHROOMISH around here?\p"
	.string "I really love that POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Hallo, du hast nicht zufällig einige\n"
	.string "POKéMON namens KNILZ hier\p"
	.string "gesehen? Ich liebe diese POKéMON.$"
	.endif
	.endif

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.ifdef ENGLISH
	.string "I was going to ambush you, but you\n"
	.string "had to dawdle in PETALBURG WOODS\l"
	.string "forever, didn't you?\p"
	.string "I got sick of waiting, so here I am!$"
	.else
	.ifdef GERMAN
	.string "Ich wollte dich eigentlich aus dem\n"
	.string "Hinterhalt angreifen, aber du trödelst\l"
	.string "wohl auf ewig im BLÜTENBURGWALD\l"
	.string "herum, oder?\p"
	.string "Das Warten machte mich ganz krank.\n"
	.string "Also, hier bin ich.$"
	.endif
	.endif

PetalburgWoods_Text_HandOverThosePapers:
	.ifdef ENGLISH
	.string "You! DEVON RESEARCHER!\p"
	.string "Hand over those papers!$"
	.else
	.ifdef GERMAN
	.string "He, du! FORSCHER von DEVON!\p"
	.string "Gib sofort die Papiere her!$"
	.endif
	.endif

PetalburgWoods_Text_YouHaveToHelpMe:
	.ifdef ENGLISH
	.string "Aiyeeeh!\p"
	.string "You're a POKéMON TRAINER, aren't you?\n"
	.string "You've got to help me, please!$"
	.else
	.ifdef GERMAN
	.string "Attackeee!\p"
	.string "Du bist ein POKéMON-TRAINER, oder?\n"
	.string "Du musst mir bitte helfen!$"
	.endif
	.endif

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.ifdef ENGLISH
	.string "Hunh? What do you think you're doing?\n"
	.string "What, you're going to protect him?\p"
	.string "No one who crosses TEAM AQUA\n"
	.string "gets any mercy, not even a kid!\p"
	.string "Come on and battle me!$"
	.else
	.ifdef GERMAN
	.string "Huch. Was machst du da eigentlich???\n"
	.string "Was?!? Du schützt ihn???\p"
	.string "Niemand, der sich TEAM AQUA in den Weg\n"
	.string "stellt, kann auf Gnade hoffen. Niemand!\p"
	.string "Los, kämpfe gegen mich!$"
	.endif
	.endif

PetalburgWoods_Text_YoureKiddingMe:
	.ifdef ENGLISH
	.string "You're kidding me! You're tough!$"
	.else
	.ifdef GERMAN
	.string "Du hast mich geleimt! Du bist stark!$"
	.endif
	.endif

PetalburgWoods_Text_YouveGotSomeNerve:
	.ifdef ENGLISH
	.string "Grrr… You've got some nerve\n"
	.string "meddling with TEAM AQUA!\l"
	.string "Come on and battle me again!\p"
	.string "I wish I could say that, but I'm out of\n"
	.string "POKéMON…\p"
	.string "And, hey, we of TEAM AQUA are also\n"
	.string "after something in RUSTBORO.\p"
	.string "I'll let you go today!$"
	.else
	.ifdef GERMAN
	.string "Grrr… Du hast vielleicht Nerven, dich\n"
	.string "mit TEAM AQUA anzulegen!\l"
	.string "Los, kämpfen wir noch einmal!\p"
	.string "Hm, das würde ich jetzt zu gerne sagen,\n"
	.string "aber ich habe keine POKéMON mehr…\p"
	.string "Außerdem sind wir, TEAM AQUA, auf dem\n"
	.string "Weg nach METAROST CITY.\p"
	.string "Für heute lasse ich dich gehen.$"
	.endif
	.endif

PetalburgWoods_Text_ThatWasAwfullyClose:
	.ifdef ENGLISH
	.string "Whew…\n"
	.string "That was awfully close!\p"
	.string "Thanks to you, he didn't rob me of\n"
	.string "these important papers.\p"
	.string "I know, I'll give you a GREAT BALL as\n"
	.string "my thanks!$"
	.else
	.ifdef GERMAN
	.string "Huuuh…\n"
	.string "Das war aber mehr als knapp!\p"
	.string "Dank dir konnte er mir diese\n"
	.string "wichtigen Papiere nicht rauben.\p"
	.string "Ich weiß! Ich gebe dir diesen\n"
	.string "SUPERBALL als Dankeschön!$"
	.endif
	.endif

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.ifdef ENGLISH
	.string "Didn't that TEAM AQUA thug say\n"
	.string "they were after something in\l"
	.string "RUSTBORO, too?$"
	.else
	.ifdef GERMAN
	.string "Hat dieser Schuft von TEAM AQUA nicht\n"
	.string "gesagt, dass sie irgendetwas in\l"
	.string "METAROST CITY erledigen wollen?$"
	.endif
	.endif

PetalburgWoods_Text_ICantBeWastingTime:
	.ifdef ENGLISH
	.string "Uh-oh! It's a crisis!\n"
	.string "I can't be wasting time!$"
	.else
	.ifdef GERMAN
	.string "Oh oh! Das ist ein Notfall!\n"
	.string "Ich darf keine Zeit verlieren!$"
	.endif
	.endif

PetalburgWoods_Text_YoureLoadedWithItems:
	.ifdef ENGLISH
	.string "You're loaded with items.\n"
	.string "I can't give you this GREAT BALL.$"
	.else
	.ifdef GERMAN
	.string "Du bist mit Items überfrachtet.\n"
	.string "Ich kann dir den SUPERBALL nicht geben.$"
	.endif
	.endif

PetalburgWoods_Text_GoBugPokemonTeam:
	.ifdef ENGLISH
	.string "I caught a whole bunch of POKéMON!\p"
	.string "Go, go, go!\n"
	.string "My BUG POKéMON team!$"
	.else
	.ifdef GERMAN
	.string "Ich habe eine Menge POKéMON gefangen!\p"
	.string "Los, los, los!\n"
	.string "Mein KÄFER-POKéMON-Team!$"
	.endif
	.endif

PetalburgWoods_Text_ICouldntWin:
	.ifdef ENGLISH
	.string "I have all these POKéMON,\n"
	.string "but I couldn't win…$"
	.else
	.ifdef GERMAN
	.string "Ich habe all diese POKéMON, aber ich\n"
	.string "konnte doch nicht gewinnen…$"
	.endif
	.endif

PetalburgWoods_Text_ImOutOfPokeBalls:
	.ifdef ENGLISH
	.string "I caught a bunch of POKéMON.\n"
	.string "Now I'm out of POKé BALLS.$"
	.else
	.ifdef GERMAN
	.string "Ich habe eine Menge POKéMON gefangen.\n"
	.string "Nun habe ich keine POKéBÄLLe mehr.$"
	.endif
	.endif

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.ifdef ENGLISH
	.string "If you take BUG POKéMON to school,\n"
	.string "you get to be instantly popular!$"
	.else
	.ifdef GERMAN
	.string "Wenn du ein KÄFER-POKéMON mit zur\n"
	.string "Schule bringst, bist du sofort beliebt.$"
	.endif
	.endif

PetalburgWoods_Text_CantBePopularIfILose:
	.ifdef ENGLISH
	.string "I can't be popular if I lose.$"
	.else
	.ifdef GERMAN
	.string "Wenn ich verliere, kann ich nicht\n"
	.string "beliebt werden.$"
	.endif
	.endif

PetalburgWoods_Text_PeopleRespectYou:
	.ifdef ENGLISH
	.string "If you have a big BUG POKéMON,\n"
	.string "people respect you for it.$"
	.else
	.ifdef GERMAN
	.string "Hast du ein großes KÄFER-POKéMON,\n"
	.string "werden die Leute dich respektieren.$"
	.endif
	.endif

PetalburgWoods_Text_IWantRematch1:
	.ifdef ENGLISH
	.string "I want a rematch when my BUG\n"
	.string "POKéMON grow up!\p"
	.string "I'm registering you in my POKéNAV!$"
	.else
	.ifdef GERMAN
	.string "Ich möchte wieder kämpfen, wenn meine\n"
	.string "KÄFER-POKéMON stärker geworden sind.\p"
	.string "Ich trage dich in meinen POKéNAV ein.$"
	.endif
	.endif

PetalburgWoods_Text_IWantRematch2:
	.ifdef ENGLISH
	.string "I want a rematch when my BUG \n"
	.string "POKéMON grow up!\p"
	.string "I'm registering you in my POKéNAV!$"
	.else
	.ifdef GERMAN
	.string "Ich möchte wieder kämpfen, wenn meine\n"
	.string "KÄFER-POKéMON stärker geworden sind.\p"
	.string "Ich trage dich in meinen POKéNAV ein.$"
	.endif
	.endif

PetalburgWoods_Text_MyPokemonHaveGrown:
	.ifdef ENGLISH
	.string "My BUG POKéMON have grown.\n"
	.string "I'll be popular again.$"
	.else
	.ifdef GERMAN
	.string "Meine KÄFER-POKéMON sind gewachsen.\n"
	.string "Ich werde wieder beliebt sein.$"
	.endif
	.endif

PetalburgWoods_Text_CantBePopularIfLose:
	.ifdef ENGLISH
	.string "I can't be popular if I lose.$"
	.else
	.ifdef GERMAN
	.string "Ich werde nie beliebt, wenn ich\n"
	.string "immer verliere.$"
	.endif
	.endif

PetalburgWoods_Text_IveBeenTrainingHard:
	.ifdef ENGLISH
	.string "You get to be popular if you have\n"
	.string "strong POKéMON, right?\l"
	.string "So, I've been training hard.$"
	.else
	.ifdef GERMAN
	.string "Du wirst beliebt, wenn du starke\n"
	.string "POKéMON besitzt, oder?\l"
	.string "Daher trainiere ich bis zum Umfallen.$"
	.endif
	.endif

PetalburgWoods_Text_StayOutOfTallGrass:
	.ifdef ENGLISH
	.string "Yo, there!\n"
	.string "Your POKéMON doing okay?\p"
	.string "If your POKéMON are weak and you want\n"
	.string "to avoid battles, you should stay out\l"
	.string "of tall grass.$"
	.else
	.ifdef GERMAN
	.string "Hey, du!\n"
	.string "Geht es deinen POKéMON gut?\p"
	.string "Wenn deine POKéMON schwach sind und\n"
	.string "du Kämpfe vermeiden willst, solltest du\l"
	.string "dich von hohem Gras fernhalten.$"
	.endif
	.endif

PetalburgWoods_Text_HiddenItemsExplanation:
	.ifdef ENGLISH
	.string "Sometimes, there are things on the\n"
	.string "ground even if you can't see them.\p"
	.string "That's why I always check where I'm\n"
	.string "walking.$"
	.else
	.ifdef GERMAN
	.string "Manchmal liegen auf dem Boden Dinge,\n"
	.string "die einem auf Anhieb gar nicht\l"
	.string "auffallen.\p"
	.string "Daher schaue ich mich bei jedem Schritt\n"
	.string "sorgfältig um.$"
	.endif
	.endif

PetalburgWoods_Text_TryUsingThisItem:
	.ifdef ENGLISH
	.string "Oh, neat!\n"
	.string "That's the BADGE from RUSTBORO GYM!\p"
	.string "You must be a TRAINER.\n"
	.string "You should try using this item.$"
	.else
	.ifdef GERMAN
	.string "Oh, hübsch! Das ist der ORDEN\n"
	.string "der ARENA in METAROST CITY!\p"
	.string "Du siehst wie ein TRAINER aus. Dann\n"
	.string "musst du dieses Item ausprobieren.$"
	.endif
	.endif

PetalburgWoods_Text_MiracleSeedExplanation:
	.ifdef ENGLISH
	.string "It's a MIRACLE SEED.\n"
	.string "If a POKéMON holds that item, its\l"
	.string "GRASS-type moves become stronger.\p"
	.string "Besides MIRACLE SEED, I think there are\n"
	.string "other convenient items for POKéMON\l"
	.string "to hold.$"
	.else
	.ifdef GERMAN
	.string "Das ist WUNDERSAAT.\n"
	.string "Wenn ein POKéMON sie trägt, werden\l"
	.string "die PFLANZEN-Attacken stärker.\p"
	.string "Neben der WUNDERSAAT gibt es bestimmt\n"
	.string "noch andere nützliche Items, die von\l"
	.string "POKéMON getragen werden können.$"
	.endif
	.endif

PetalburgWoods_Text_TrainerTipsExperience:
	.ifdef ENGLISH
	.string "TRAINER TIPS\p"
	.string "Any POKéMON that appears even once\n"
	.string "in a battle is awarded EXP Points.\p"
	.string "To raise a weak POKéMON, put it at the\n"
	.string "left of the team list.\p"
	.string "As soon as a battle starts, switch it\n"
	.string "out. It will earn EXP Points without\l"
	.string "being exposed to any harm.$"
	.else
	.ifdef GERMAN
	.string "TIPPS für TRAINER\p"
	.string "Jedes POKéMON, das am Kampf teilnimmt,\n"
	.string "erhält ERFAHRUNGSPUNKTE, auch wenn es\l"
	.string "nur ganz kurz dabei ist.\p"
	.string "Setze eines deiner schwachen POKéMON\n"
	.string "daher an die Spitze der Liste.\p"
	.string "Sobald der Kampf beginnt, wechselst du\n"
	.string "es aus. Es wird E-Punkte bekommen und\l"
	.string "bleibt trotzdem immer unbeschadet.$"
	.endif
	.endif

PetalburgWoods_Text_TrainerTipsPP:
	.ifdef ENGLISH
	.string "TRAINER TIPS\p"
	.string "In addition to Hit Points (HP), POKéMON\n"
	.string "have Power Points (PP) that are used to\l"
	.string "make moves during battle.\p"
	.string "If a POKéMON runs out of PP, it must be\n"
	.string "taken to a POKéMON CENTER.$"
	.else
	.ifdef GERMAN
	.string "TIPPS für TRAINER\p"
	.string "Neben den Kraftpunkten (KP) besitzt\n"
	.string "ein POKéMON auch Angriffspunkte (AP),\l"
	.string "die für die Attacken im Kampf gebraucht\l"
	.string "werden.\p"
	.string "Wenn ein POKéMON keine AP mehr besitzt,\n"
	.string "muss es in ein POKéMON-CENTER gebracht\l"
	.string "werden.$"
	.endif
	.endif

