.set LOCALID_ATTENDANT, 1

BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_ATTENDANT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.ifdef ENGLISH
	.string "Please find a partner from out of\n"
	.string "the TRAINERS gathered here.$"
	.else
	.ifdef GERMAN
	.string "Bitte such dir unter den TRAINERn hier\n"
	.string "einen Partner aus.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.ifdef ENGLISH
	.string "{PLAYER}, you have not found a partner\n"
	.string "for your tag team.\p"
	.string "Would you like to quit looking and\n"
	.string "return to the reception counter?$"
	.else
	.ifdef GERMAN
	.string "{PLAYER}, du hast noch keinen Partner\n"
	.string "gefunden.\p"
	.string "Möchtest du die Suche aufgeben und\n"
	.string "zurück zur Rezeption gehen?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.ifdef ENGLISH
	.string "Then, please find a partner from\n"
	.string "the TRAINERS gathered here.$"
	.else
	.ifdef GERMAN
	.string "Dann such dir bitte unter den TRAINERn\n"
	.string "hier einen Partner aus.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.ifdef ENGLISH
	.string "Thank you for choosing a partner.\p"
	.string "I will now show you to your\n"
	.string "MULTI BATTLE ROOM.$"
	.else
	.ifdef GERMAN
	.string "Vielen Dank!\p"
	.string "Nun werde ich dir den Raum für die\n"
	.string "MULTIKÄMPFE zeigen.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.ifdef ENGLISH
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
	.string "You can call me {STR_VAR_3}!$"
	.else
	.ifdef GERMAN
	.string "I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice.\n"
	.string "You can call me {STR_VAR_3}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.ifdef ENGLISH
	.string "On {STR_VAR_1}'s advice, I brought\n"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"
	.else
	.ifdef GERMAN
	.string "On {STR_VAR_1}’s advice, I brought\n"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please, let me join you as a tag team.$"
	.else
	.ifdef GERMAN
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please, let me join you as a tag team.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.ifdef ENGLISH
	.string "Thank you!\n"
	.string "I'll go register right now.$"
	.else
	.ifdef GERMAN
	.string "Thank you!\n"
	.string "I’ll go register right now.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.ifdef ENGLISH
	.string "I really wanted to form a tag team\n"
	.string "with you, {PLAYER}…$"
	.else
	.ifdef GERMAN
	.string "I really wanted to form a tag team\n"
	.string "with you, {PLAYER}…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.ifdef ENGLISH
	.string "I am {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
	.string "My name is {STR_VAR_3}.$"
	.else
	.ifdef GERMAN
	.string "I am {STR_VAR_1}’s no. {STR_VAR_2} apprentice.\n"
	.string "My name is {STR_VAR_3}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.ifdef ENGLISH
	.string "I got advice from {STR_VAR_1} and chose\n"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"
	.else
	.ifdef GERMAN
	.string "I got advice from {STR_VAR_1} and chose\n"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please, let's form a tag team!$"
	.else
	.ifdef GERMAN
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please, let’s form a tag team!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.ifdef ENGLISH
	.string "Thank you very much!\n"
	.string "I'll be done with registration quickly!$"
	.else
	.ifdef GERMAN
	.string "Thank you very much!\n"
	.string "I’ll be done with registration quickly!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.ifdef ENGLISH
	.string "{PLAYER}, I was hoping that I could\n"
	.string "partner up with you…$"
	.else
	.ifdef GERMAN
	.string "{PLAYER}, I was hoping that I could\n"
	.string "partner up with you…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.ifdef ENGLISH
	.string "Um, my name's {STR_VAR_3}, and I'm\n"
	.string "{STR_VAR_1}'s no. {STR_VAR_2} apprentice.\p"
	.string "Snivel…\p"
	.string "I'm sorry!\n"
	.string "This tension is making me cry…$"
	.else
	.ifdef GERMAN
	.string "Ähm, ich heiße {STR_VAR_3} und ich bin\n"
	.string "Schüler Nr. {STR_VAR_2} von {STR_VAR_1}.\p"
	.string "SCHLUCHZ…\p"
	.string "Tut mir Leid! Schnüff… Aber die\n"
	.string "Spannung bringt mich zum Weinen.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.ifdef ENGLISH
	.string "{STR_VAR_3} advised me, so I have\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_3} ist mir mit Rat und Tat zur\n"
	.string "Seite gestanden, daher habe ich\p"
	.string "ein {STR_VAR_2}, das {STR_VAR_1} kann,$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Snivel…\n"
	.string "Please, please team up with me!$"
	.else
	.ifdef GERMAN
	.string "und ein {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann.\p"
	.string "SCHLUCHZ…\n"
	.string "Bitte, biiiitte, nimm mich als Partner!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.ifdef ENGLISH
	.string "Oh, really? You will?\n"
	.string "Awesome! Wicked! Awoooh!\p"
	.string "Oh… I'm sorry…\n"
	.string "I'm so happy, I'm crying…\p"
	.string "I'll go register right away.\n"
	.string "Please don't go away!$"
	.else
	.ifdef GERMAN
	.string "Oh, wirklich?!? ECHT?!?\n"
	.string "Wahnsinn! Irre! Toll! Juhuuuu!\p"
	.string "Oh… Hihihi… Tut mir Leid…\n"
	.string "Ich bin so glücklich, dass ich weine…\p"
	.string "Ich gehe mich sofort anmelden, bitte\n"
	.string "lauf nicht weg!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.ifdef ENGLISH
	.string "Oh, b-but…\n"
	.string "Sob… Waaaaah!$"
	.else
	.ifdef GERMAN
	.string "Oh, ab-abber… abber…\n"
	.string "SCHLUCHZ… UAAAHAAA…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.ifdef ENGLISH
	.string "Hi, there! I'm {STR_VAR_3}!\n"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"
	.else
	.ifdef GERMAN
	.string "Hallo, du da! Ich bin {STR_VAR_3}!\n"
	.string "Ich bin Schüler Nr. {STR_VAR_2} von {STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.ifdef ENGLISH
	.string "{STR_VAR_3} recommended my crew.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_3} hat mich beraten. Ich habe\n"
	.string "ein {STR_VAR_2}, das {STR_VAR_1} kann,$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1},\n"
	.string "that's what I have! Cool, huh?\p"
	.string "So come on!\n"
	.string "Let's form a tag team!$"
	.else
	.ifdef GERMAN
	.string "und ein {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann. Ist das nicht cool?\p"
	.string "Also los!\n"
	.string "Wir beide bilden ein Team!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.ifdef ENGLISH
	.string "Yay! Great!\n"
	.string "Okay, I'll go register, okay?$"
	.else
	.ifdef GERMAN
	.string "Super! Klasse!\n"
	.string "Ich registriere mich jetzt!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.ifdef ENGLISH
	.string "Aww, why?\n"
	.string "I wanted to team up, {PLAYER}!$"
	.else
	.ifdef GERMAN
	.string "Oooh, warum denn nicht? Ich wollte\n"
	.string "doch so gerne dein Partner sein.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.ifdef ENGLISH
	.string "I'm {STR_VAR_3}, the no. {STR_VAR_2} apprentice\n"
	.string "of the famous {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Ich bin {STR_VAR_3}, Schüler Nr. {STR_VAR_2} des\n"
	.string "berühmten {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.ifdef ENGLISH
	.string "I looked to {STR_VAR_3} for advice.\n"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"
	.else
	.ifdef GERMAN
	.string "Ich habe mich an den Rat von\n"
	.string "{STR_VAR_3} gehalten.\p"
	.string "Mein {STR_VAR_2} kann {STR_VAR_1}$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.ifdef ENGLISH
	.string "and one {STR_VAR_2} with {STR_VAR_1},\n"
	.string "that's my pair.\p"
	.string "Please, will you join me in\n"
	.string "a tag team?$"
	.else
	.ifdef GERMAN
	.string "und mein {STR_VAR_2} kann\n"
	.string "{STR_VAR_1}. Das ist mein Pärchen.\p"
	.string "Bitte bilde ein Team mit uns.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.ifdef ENGLISH
	.string "Thank you!\n"
	.string "I'll register right away!$"
	.else
	.ifdef GERMAN
	.string "Danke schön!\n"
	.string "Ich werde mich sofort registrieren.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.ifdef ENGLISH
	.string "{PLAYER}, I had been hoping to join\n"
	.string "you in a tag team…$"
	.else
	.ifdef GERMAN
	.string "Ich hatte gehofft, mit dir ein Team\n"
	.string "bilden zu können, {PLAYER}…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.ifdef ENGLISH
	.string "Um… I'm sincerely happy that you\n"
	.string "would take the time to talk to me.\p"
	.string "I'm {STR_VAR_3}.\n"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice…$"
	.else
	.ifdef GERMAN
	.string "Ähm… Ich bin froh, dass du dir die Zeit\n"
	.string "genommen hast, mit mir zu reden.\p"
	.string "Ich heiße {STR_VAR_3}.\n"
	.string "Ich bin Schülerin Nr. {STR_VAR_2} von {STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.ifdef ENGLISH
	.string "{STR_VAR_3} gave me advice.\n"
	.string "I'm very grateful for it.\p"
	.string "I have a team of one {STR_VAR_2}\n"
	.string "with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_3} hat mir einen Rat gegeben.\n"
	.string "Dafür bin ich sehr dankbar.\p"
	.string "In meinem Team ist ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann, und$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
	.string "I know I'm asking a lot…\p"
	.string "I don't think you'll be willing to,\n"
	.string "but may I join you as a partner?$"
	.else
	.ifdef GERMAN
	.string "ein {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann. Ich weiß, ich verlange viel, aber…\p"
	.string "Würdest du ein Team mit mir bilden?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.ifdef ENGLISH
	.string "Really? I can't believe it!\n"
	.string "I can't believe you'll let me join you!\l"
	.string "I… I won't let you down!\p"
	.string "Um… If it's really okay, I'll go register\n"
	.string "right this instant!$"
	.else
	.ifdef GERMAN
	.string "Wirklich? Ich kann es kaum glauben!\n"
	.string "Ich werde dich nicht enttäuschen!\l"
	.string "Ich kann es immer noch nicht glauben…\p"
	.string "Ähm… Wenn es wirklich okay ist,\n"
	.string "dann registriere ich mich jetzt sofort.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.ifdef ENGLISH
	.string "Oh…\n"
	.string "I didn't think I was good enough…$"
	.else
	.ifdef GERMAN
	.string "Oh…\n"
	.string "Ich glaube, ich war nicht gut genug…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.ifdef ENGLISH
	.string "Hi, I'm {STR_VAR_3}.\n"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"
	.else
	.ifdef GERMAN
	.string "Oh, ich bin {STR_VAR_3}.\n"
	.string "Schülerin Nr. {STR_VAR_2}\p"
	.string "von {STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.ifdef ENGLISH
	.string "{STR_VAR_3} told me that it would be\n"
	.string "good to make this team:\l"
	.string "one {STR_VAR_1}-using {STR_VAR_2}$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_3} hat mir zu folgendem Team\n"
	.string "geraten: ein {STR_VAR_2}, das\l"
	.string "{STR_VAR_1} kann,$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.ifdef ENGLISH
	.string "and one {STR_VAR_2} that knows how\n"
	.string "to use {STR_VAR_1}.\p"
	.string "Not bad, huh?\n"
	.string "Want me to team up with you?$"
	.else
	.ifdef GERMAN
	.string "und ein {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann.\p"
	.string "Nicht schlecht, was? Sollen wir\n"
	.string "beide ein Team bilden?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.ifdef ENGLISH
	.string "Okay, glad to join you!\n"
	.string "I hope you won't mess things up for me!\l"
	.string "I'll do my registration now.$"
	.else
	.ifdef GERMAN
	.string "Das freut mich jetzt wirklich!\n"
	.string "Ich hoffe nur, du versaust es nicht!\l"
	.string "Ich werde mich jetzt registrieren.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.ifdef ENGLISH
	.string "Huh? Why did you turn me down?\n"
	.string "You're no judge of character!$"
	.else
	.ifdef GERMAN
	.string "Wie? Du willst mich nicht zum Partner?\n"
	.string "Du unterschätzt mich gewaltig!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.ifdef ENGLISH
	.string "I'm {STR_VAR_3} and I'm a TRIATHLETE.\n"
	.string "I'm busy every day what with jogging,\l"
	.string "training, and rapping.\p"
	.string "I also happen to be {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice.$"
	.else
	.ifdef GERMAN
	.string "Ich bin {STR_VAR_3} und TRIATHLET.\n"
	.string "Ich bin immer schwer beschäftigt mit\l"
	.string "Joggen, Trainieren und Sprüche klopfen.\p"
	.string "Ich bin außerdem Schüler Nr. {STR_VAR_2}\n"
	.string "von {STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.ifdef ENGLISH
	.string "This is what {STR_VAR_3} recommended.\n"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"
	.else
	.ifdef GERMAN
	.string "Ich folge dem Rat von {STR_VAR_3}:\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1} kann.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.ifdef ENGLISH
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}.\p"
	.string "I put a lot of effort into raising\n"
	.string "them, even though I'm busy.\p"
	.string "Let's form a tag team\n"
	.string "and give it a go!$"
	.else
	.ifdef GERMAN
	.string "Und ein {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann.\p"
	.string "Ich habe mich sehr um meine POKéMON\n"
	.string "gekümmert, auch wenn ich beschäftigt\p"
	.string "war. Komm, wir bilden ein Team und\n"
	.string "versuchen unser Bestes!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.ifdef ENGLISH
	.string "Thanks, that's the spirit!\n"
	.string "Hang tight while I go register, okay?$"
	.else
	.ifdef GERMAN
	.string "Das ist der richtige Kampfgeist!\n"
	.string "Warte hier. Ich registriere mich.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.ifdef ENGLISH
	.string "I took time from my busy schedule\n"
	.string "to be here! Give me a break!$"
	.else
	.ifdef GERMAN
	.string "Ich habe mir extra frei genommen.\n"
	.string "Und dann enttäuschst du mich. Pah!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.ifdef ENGLISH
	.string "Hi!\n"
	.string "How's it going?\p"
	.string "I'm {STR_VAR_3}, {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice. Glad to meet you!$"
	.else
	.ifdef GERMAN
	.string "Hallo! Wie geht’s dir?\n"
	.string "Ich bin {STR_VAR_3}.\p"
	.string "Schülerin Nr. {STR_VAR_2} von {STR_VAR_1}.\n"
	.string "Nett, dich kennen zu lernen.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.ifdef ENGLISH
	.string "Listen, listen! You have to hear about\n"
	.string "the POKéMON {STR_VAR_3} recommended.\l"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Ich erzähl dir, zu was {STR_VAR_3} mir\n"
	.string "geraten hat: Zu einem {STR_VAR_2}, das\l"
	.string "{STR_VAR_1} kann, und$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
	.string "Of course I raised them superbly!\p"
	.string "So, want to team up?\n"
	.string "I'm sure it'll be a great combo!$"
	.else
	.ifdef GERMAN
	.string "einem {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann. Natürlich wurden sie von mir\p"
	.string "sorgfältig aufgezogen! Sollen wir ein\n"
	.string "Team bilden? Wir wären unschlagbar!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.ifdef ENGLISH
	.string "Yay, I think this will be fun!\n"
	.string "I'll go register!$"
	.else
	.ifdef GERMAN
	.string "Ha, das macht bestimmt Spaß!\n"
	.string "Ich gehe mich jetzt registrieren.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.ifdef ENGLISH
	.string "Oh, you're mean!\n"
	.string "I come recommended, you know.$"
	.else
	.ifdef GERMAN
	.string "Bah, du bist gemein!\n"
	.string "Ich habe Referenzen, weißt du!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.ifdef ENGLISH
	.string "Please let me introduce myself.\n"
	.string "I am {STR_VAR_3}.\p"
	.string "I serve as {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice.$"
	.else
	.ifdef GERMAN
	.string "Ich bin {STR_VAR_3}.\n"
	.string "Schön, dich kennen zu lernen.\p"
	.string "Ich bin Schülerin Nr. {STR_VAR_2} von\n"
	.string "{STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.ifdef ENGLISH
	.string "I sought the sage advice of\n"
	.string "{STR_VAR_3} and raised my team\l"
	.string "of one {STR_VAR_2} with {STR_VAR_1}$"
	.else
	.ifdef GERMAN
	.string "Ich hielt mich an die Lehren von\n"
	.string "{STR_VAR_3} und mein Team ist: Ein\l"
	.string "{STR_VAR_2}, das {STR_VAR_1} kann$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.ifdef ENGLISH
	.string "and one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please agree to a tag team with me!$"
	.else
	.ifdef GERMAN
	.string "und ein {STR_VAR_2}, das\n"
	.string "{STR_VAR_1} kann.\p"
	.string "Bitte nimm uns als Partner.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.ifdef ENGLISH
	.string "Oh… I'm delighted!\n"
	.string "I promise to give you my best!\p"
	.string "Of course I will register us!\n"
	.string "Please wait!$"
	.else
	.ifdef GERMAN
	.string "Oh… Ich bin entzückt!\n"
	.string "Ich werde mein Bestes geben!\p"
	.string "Ich werde uns jetzt registrieren!\n"
	.string "Warte bitte hier auf mich!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.ifdef ENGLISH
	.string "I had been hoping to join you,\n"
	.string "{PLAYER}…$"
	.else
	.ifdef GERMAN
	.string "Ich hatte gehofft, an deiner Seite\n"
	.string "kämpfen zu dürfen, {PLAYER}…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.ifdef ENGLISH
	.string "Eek! You spoke to me!\n"
	.string "I… I'm overjoyed!\p"
	.string "I'm {STR_VAR_3}! I'm {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice!$"
	.else
	.ifdef GERMAN
	.string "Hihihi! Du hast mich angesprochen!\n"
	.string "Ich bin ja sooo glücklich…\p"
	.string "Ich heiße {STR_VAR_3}! Ich bin Schülerin\n"
	.string "Nr. {STR_VAR_2} von {STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.ifdef ENGLISH
	.string "On {STR_VAR_3}'s advice, I trained\n"
	.string "one {STR_VAR_1}-using {STR_VAR_2}$"
	.else
	.ifdef GERMAN
	.string "Ich folgte dem Rat meines Lehrers! Ich\n"
	.string "habe ein {STR_VAR_2}, das {STR_VAR_1}$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.ifdef ENGLISH
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}.\p"
	.string "Please, can you grant me my wish?\n"
	.string "I want to be your tag-team partner!$"
	.else
	.ifdef GERMAN
	.string "kann, und ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann.\p"
	.string "Erfüllst du mir einen Wunsch?\n"
	.string "Bilde mit mir ein Team.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.ifdef ENGLISH
	.string "Eek! I… I feel giddy!\n"
	.string "Thank you so much!\l"
	.string "I'll go register us right away!$"
	.else
	.ifdef GERMAN
	.string "Hihihi… Mir ist richtig schwindelig!\n"
	.string "Vielen, vielen Dank!\l"
	.string "Ich werde mich jetzt registrieren.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.ifdef ENGLISH
	.string "Waaah! Don't you feel any pity?\n"
	.string "But that makes you cooler…$"
	.else
	.ifdef GERMAN
	.string "Uaaahaa! Hast du denn kein Mitleid?\n"
	.string "Aber irgendwie bist du cool…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.ifdef ENGLISH
	.string "Yeehaw! I'm {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice!\p"
	.string "{STR_VAR_3}'s my name, hello, hello!$"
	.else
	.ifdef GERMAN
	.string "Jahaa! Ich bin Schüler Nr. {STR_VAR_2} von\n"
	.string "{STR_VAR_1}!\p"
	.string "Ich heiße {STR_VAR_3}. Hallooo, hallooo!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.ifdef ENGLISH
	.string "My mentor {STR_VAR_3} recommended\n"
	.string "one {STR_VAR_1}-master {STR_VAR_2}$"
	.else
	.ifdef GERMAN
	.string "Mein Mentor {STR_VAR_3} riet mir zu\n"
	.string "einem {STR_VAR_2}, das {STR_VAR_1}$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.ifdef ENGLISH
	.string "and one {STR_VAR_1}-master\n"
	.string "{STR_VAR_2}.\p"
	.string "Good stuff, huh?\n"
	.string "You'll partner with me, won't you?$"
	.else
	.ifdef GERMAN
	.string "kann, und zu einem {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann.\p"
	.string "Gut, nicht wahr? Du wählst mich als\n"
	.string "deinen Partner, ja?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.ifdef ENGLISH
	.string "Okay, excellent!\n"
	.string "I'll get the registration done quickly!$"
	.else
	.ifdef GERMAN
	.string "Hervorragend!!! Ich werde mich\n"
	.string "ganz schnell registrieren!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.ifdef ENGLISH
	.string "Gwaaah!\n"
	.string "You're a calculating one, {PLAYER}!$"
	.else
	.ifdef GERMAN
	.string "Uuuuuh! Du bist ganz schön\n"
	.string "berechnend, {PLAYER}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.ifdef ENGLISH
	.string "Hey! There's big trouble! This is\n"
	.string "the BATTLE TOWER's last day!\p"
	.string "… … … … … …\n"
	.string "I'm only joking!\p"
	.string "People call me {STR_VAR_3} and I do, too!\n"
	.string "I'm {STR_VAR_1}'s 1,000th apprentice!\l"
	.string "Actually, I'm no. {STR_VAR_2}!$"
	.else
	.ifdef GERMAN
	.string "Hey! Jetzt geht’s hier richtig rund.\n"
	.string "Heute ist der letzte Tag des\p"
	.string "DUELLTURMs!\n"
	.string "………………\l"
	.string "Haha! War nur ein Witz!\p"
	.string "Man nennt mich {STR_VAR_3} und das\n"
	.string "passt! Ich bin der 1.000ste Schüler von\l"
	.string "{STR_VAR_1}! Nun, ich bin Nr. {STR_VAR_2}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.ifdef ENGLISH
	.string "{STR_VAR_3} gave me some advice.\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_3} hat mir einen Rat gegeben.\n"
	.string "{STR_VAR_2}, das {STR_VAR_1} kann,$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.ifdef ENGLISH
	.string "{STR_VAR_2} with {STR_VAR_1}.\n"
	.string "I've got ten of each kind!\l"
	.string "Actually, just one of each!\p"
	.string "How about it?\n"
	.string "Want to try tag battles with me?$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann…\n"
	.string "Ich habe zehn von jedem!\l"
	.string "Nun, ich habe eines von jedem.\p"
	.string "Nun, wie wär’s?\n"
	.string "Sollen wir zusammen kämpfen?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.ifdef ENGLISH
	.string "Yippee!\n"
	.string "I'll give you a POKéMON as my thanks!\p"
	.string "Just joking! But I will really go do\n"
	.string "the registration, okay?$"
	.else
	.ifdef GERMAN
	.string "Juhuu! Ich schenke dir zum\n"
	.string "Dank ein POKéMON!\p"
	.string "War ein Witz! Aber ich werde mich\n"
	.string "jetzt tatsächlich registrieren, okay?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.ifdef ENGLISH
	.string "Oh, that's so cold! I'll have to wreck\n"
	.string "the BATTLE TOWER for that!\p"
	.string "Of course I won't!$"
	.else
	.ifdef GERMAN
	.string "Bah, wie fies! Dafür werde ich den\n"
	.string "DUELLTURM in Schutt und Asche legen!\p"
	.string "Natürlich nicht! War ein Witz.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.ifdef ENGLISH
	.string "Hey, there, I'm rockin' and a-rollin'!\n"
	.string "POKéMON, I be controllin'!\p"
	.string "I'm {STR_VAR_3} the rappin' SAILOR.\n"
	.string "Don't be mistakin' me for no wailer!\p"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
	.string "Me, you shouldn't be quick to dismiss!$"
	.else
	.ifdef GERMAN
	.string "Hey, da! Ich bin echt gut drauf.\n"
	.string "Meine POKéMON auch!\p"
	.string "Ich heiße {STR_VAR_3} und bin ein\n"
	.string "MATROSE. Ich bin Schüler Nr. {STR_VAR_2}\p"
	.string "von {STR_VAR_1}. Lehn mich nicht\n"
	.string "vorschnell ab!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.ifdef ENGLISH
	.string "With the advice of {STR_VAR_3} I did\n"
	.string "abide, put together my team of pride!\l"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"
	.else
	.ifdef GERMAN
	.string "Mein Team habe ich nach dem Rat meines\n"
	.string "Lehrers zusammengestellt.\l"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1} kann,$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.ifdef ENGLISH
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}!\p"
	.string "Our meeting we should commemorate,\n"
	.string "with a tag-team victory to celebrate!$"
	.else
	.ifdef GERMAN
	.string "und ein {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann!\p"
	.string "Wir beide sollten uns wirklich\n"
	.string "zusammentun! Der Sieg wäre uns sicher.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.ifdef ENGLISH
	.string "Hey, hey, I like your style!\n"
	.string "Our registration, I will go file!$"
	.else
	.ifdef GERMAN
	.string "Hey, hey! Du gefällst mir, du hast Stil!\n"
	.string "Ich gehe jetzt und registriere mich.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.ifdef ENGLISH
	.string "Oh, hey, {PLAYER}, now that's cold!\n"
	.string "If I may be so bold!$"
	.else
	.ifdef GERMAN
	.string "Oh, {PLAYER}, das ist gemein und fies!\n"
	.string "Wenn ich mal so ehrlich sein darf…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.ifdef ENGLISH
	.string "Yippee-yahoo!\n"
	.string "Oh, don't run! I was just having fun!\p"
	.string "Howdy! I'm {STR_VAR_3}!\n"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"
	.else
	.ifdef GERMAN
	.string "Juhuu juhuu juhuu!\n"
	.string "Ich mag alles, was Spaß macht!\p"
	.string "Wie geht’s? Ich bin {STR_VAR_3}!\n"
	.string "Schüler Nr. {STR_VAR_2} von {STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.ifdef ENGLISH
	.string "{STR_VAR_3} told me what to do.\n"
	.string "So one {STR_VAR_1}-using {STR_VAR_2}$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_3} gab mir Anweisungen.\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1}$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.ifdef ENGLISH
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}, I did choose.\p"
	.string "So, what do you say?\n"
	.string "Come on, make my day!\p"
	.string "Please, I'm begging you!\n"
	.string "Let me join you, don't leave me blue!$"
	.else
	.ifdef GERMAN
	.string "kann, und ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann.\p"
	.string "Was bleibt da noch zu sagen?\n"
	.string "Los, komm! Mach schon!\p"
	.string "Bitte! Ich flehe dich an!\n"
	.string "Kämpfe zusammen mit mir. Biiitte!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.ifdef ENGLISH
	.string "Yeahah! Luck is with me!\n"
	.string "It sure makes me happy!\p"
	.string "Before we go join the fray,\n"
	.string "I'll go register right away!$"
	.else
	.ifdef GERMAN
	.string "Yeah! Das Glück ist heute auf meiner\n"
	.string "Seite. Ich bin sooo froh!\p"
	.string "Bevor wir anfangen, laufe ich schnell\n"
	.string "und registriere mich.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.ifdef ENGLISH
	.string "You're turning me down?\n"
	.string "{PLAYER}, you're making me frown!$"
	.else
	.ifdef GERMAN
	.string "Du weist mich ab?\n"
	.string "{PLAYER}, du enttäuschst mich sehr.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.ifdef ENGLISH
	.string "Cough!\p"
	.string "Oh, sorry, I have a cold.\n"
	.string "My POKéMON are fine, though.\p"
	.string "My name's {STR_VAR_3}, {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice. Cough!$"
	.else
	.ifdef GERMAN
	.string "Hust… Röchel…\p"
	.string "Tut mir Leid, ich bin erkältet.\n"
	.string "Aber meinen POKéMON geht es gut.\p"
	.string "Ich heiße {STR_VAR_3}, Schüler Nr. {STR_VAR_2}\n"
	.string "von {STR_VAR_1}. Hust… Hust…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.ifdef ENGLISH
	.string "I took {STR_VAR_3}'s advice to heart\n"
	.string "and put together my team of\l"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Ich habe mir den Rat meines Lehrers zu\n"
	.string "Herzen genommen und ein {STR_VAR_2},\l"
	.string "das {STR_VAR_1} kann, sowie$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "I trained them every day,\n"
	.string "even in wind and rain.\p"
	.string "That's why I have this cold,\n"
	.string "I think.\p"
	.string "That's what I'm about.\n"
	.string "Want to be my tag partner?$"
	.else
	.ifdef GERMAN
	.string "ein {STR_VAR_2}, das {STR_VAR_1} kann,\n"
	.string "in meinem Team.\p"
	.string "Ich trainiere jeden Tag, bei Wind und\n"
	.string "Wetter, mit ihnen.\p"
	.string "Deswegen bin ich wahrscheinlich auch\n"
	.string "erkältet. Glaube ich…\p"
	.string "Nun? Sollen wir beide uns zusammentun\n"
	.string "und Seite an Seite kämpfen?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.ifdef ENGLISH
	.string "Thanks, I appreciate this!\n"
	.string "Cough, cough!\l"
	.string "Hang on while I go register.$"
	.else
	.ifdef GERMAN
	.string "Danke, das freut mich sehr!\n"
	.string "Hust… Hust…\l"
	.string "Warte, ich registriere mich eben.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.ifdef ENGLISH
	.string "Oh, you won't?\n"
	.string "{PLAYER}, I think we'd make a good pair.$"
	.else
	.ifdef GERMAN
	.string "Ach, du willst nicht? {PLAYER},\n"
	.string "wir wären ein gutes Team gewesen…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.ifdef ENGLISH
	.string "Oh, hello!\n"
	.string "This is nerve-racking.\p"
	.string "I'm {STR_VAR_3}.\n"
	.string "I'm the no. {STR_VAR_2} apprentice of {STR_VAR_1}.$"
	.else
	.ifdef GERMAN
	.string "Hallo!\n"
	.string "Das hier ist echt Nerven zerreißend!\p"
	.string "Ich heiße {STR_VAR_3}.\n"
	.string "Ich bin Schüler Nr. {STR_VAR_2} von {STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.ifdef ENGLISH
	.string "{STR_VAR_3} said this team'll be good--\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_3} riet mir zu diesem Team:\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1}$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "I'm feeling self-conscious about this,\n"
	.string "but will you let me join you?$"
	.else
	.ifdef GERMAN
	.string "kann, und ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann.\p"
	.string "Ich bin sehr zufrieden und zu-\n"
	.string "versichtlich. Bilden wir ein Team?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.ifdef ENGLISH
	.string "Oh, gee, thank you!\n"
	.string "I feel bashful, but I'll do my best!\p"
	.string "I'll go get the registration done.$"
	.else
	.ifdef GERMAN
	.string "Ja! Toll! Danke! Ich bin schüchtern,\n"
	.string "aber ich werde mein Bestes geben!\p"
	.string "Ich werde mich jetzt registrieren.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.ifdef ENGLISH
	.string "Oh, please don't say no!\n"
	.string "I feel self-conscious enough already…$"
	.else
	.ifdef GERMAN
	.string "Och, sag doch nicht einfach Nein!\n"
	.string "Ich bin doch eh schon verlegen genug…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.ifdef ENGLISH
	.string "I am {STR_VAR_3}, and that's no lie.\n"
	.string "I am {STR_VAR_1}'s no. {STR_VAR_2} apprentice.$"
	.else
	.ifdef GERMAN
	.string "Ich bin {STR_VAR_3}. Das ist keine Lüge!\n"
	.string "Ich bin Schüler Nr. {STR_VAR_2} von {STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.ifdef ENGLISH
	.string "{STR_VAR_3} recommended my team.\p"
	.string "Since the advice sounded sincere,\n"
	.string "I decided to bring with me\l"
	.string "my {STR_VAR_1}-using {STR_VAR_2} and$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_3} hat mir einen Rat gegeben.\p"
	.string "Und da ich diesen wertvollen Rat gerne\n"
	.string "befolge, habe ich ein {STR_VAR_2},\l"
	.string "das {STR_VAR_1} kann, und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.ifdef ENGLISH
	.string "my {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "If possible, I would like you to accept\n"
	.string "me as your tag-team partner.$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann.\p"
	.string "Wenn es dir genehm ist, dann würde ich\n"
	.string "dich bitten, mich als Partner zu wählen.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.ifdef ENGLISH
	.string "You really will accept me?\n"
	.string "It would be too terrible otherwise.\p"
	.string "But since you've agreed, this is fine.\n"
	.string "I shall go register the both of us.$"
	.else
	.ifdef GERMAN
	.string "Du entscheidest dich wirklich für mich?\n"
	.string "Wenn nicht, wäre das schrecklich für\p"
	.string "mich. Da du zustimmst, werde ich uns\n"
	.string "jetzt anmelden.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.ifdef ENGLISH
	.string "Hm? Now why would you refuse?\n"
	.string "Is this your idea of a joke?$"
	.else
	.ifdef GERMAN
	.string "Hm? Warum lehnst du mich ab? Ist das\n"
	.string "deine spezielle Art von Humor?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.ifdef ENGLISH
	.string "I'm {STR_VAR_1}, and I'm a LASS!$"
	.else
	.ifdef GERMAN
	.string "Ich bin {STR_VAR_1} und eine GÖRE!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.ifdef ENGLISH
	.string "What I have are one {STR_VAR_2}\n"
	.string "that uses {STR_VAR_1} and one$"
	.else
	.ifdef GERMAN
	.string "Ich habe ein {STR_VAR_2}, das\n"
	.string "{STR_VAR_1} kann, und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.ifdef ENGLISH
	.string "{STR_VAR_2} that uses {STR_VAR_1}.\n"
	.string "Those are what I have with me.\p"
	.string "Will you be my partner?$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann.\n"
	.string "Die beiden begleiten mich.\p"
	.string "Willst du mein Teampartner sein?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.ifdef ENGLISH
	.string "Thank you!\n"
	.string "I'll go do the registration!$"
	.else
	.ifdef GERMAN
	.string "Danke!\n"
	.string "Ich werde uns jetzt registrieren.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.ifdef ENGLISH
	.string "You don't want to be my partner?\n"
	.string "You'll regret it later!$"
	.else
	.ifdef GERMAN
	.string "Du willst nicht mein Teampartner sein?\n"
	.string "Das wird dir später bestimmt Leid tun…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.ifdef ENGLISH
	.string "Hello!\p"
	.string "I'm YOUNGSTER {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Hallo!\p"
	.string "Ich bin TEENAGER {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.ifdef ENGLISH
	.string "Want to know what I have?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Willst du wissen, was ich hab?\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1} kann,$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "You'll be my tag-team partner,\n"
	.string "won't you?$"
	.else
	.ifdef GERMAN
	.string "und ein {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann!\p"
	.string "Du wählst mich doch als deinen\n"
	.string "Partner, oder etwa nicht?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.ifdef ENGLISH
	.string "Yay!\n"
	.string "I'll go and register, okay?$"
	.else
	.ifdef GERMAN
	.string "Spitze!\n"
	.string "Ich werde uns registrieren!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.ifdef ENGLISH
	.string "Aww! If you'd form a tag team with\n"
	.string "my POKéMON, we'd be unstoppable!$"
	.else
	.ifdef GERMAN
	.string "Oooh! Dabei wären wir mit meinen\n"
	.string "POKéMON unschlagbar gewesen!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.ifdef ENGLISH
	.string "Yahoo!\n"
	.string "I'm HIKER {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Halli hallo!\n"
	.string "Ich bin der WANDERER {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.ifdef ENGLISH
	.string "Know what I have with me?\n"
	.string "My {STR_VAR_1}-using {STR_VAR_2} and$"
	.else
	.ifdef GERMAN
	.string "Willst du wissen, welche PKMN ich habe?\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1}$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.ifdef ENGLISH
	.string "my {STR_VAR_1}-using {STR_VAR_2}!\p"
	.string "Sounds good, eh?\n"
	.string "Want to form a tag team?$"
	.else
	.ifdef GERMAN
	.string "kann, und ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann!\p"
	.string "Na, hört sich das gut an? Sollen wir\n"
	.string "mit dir ein Team bilden?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.ifdef ENGLISH
	.string "Yahoo!\n"
	.string "I'll go do the registering, then.$"
	.else
	.ifdef GERMAN
	.string "Hallo hallo!\n"
	.string "Dann werde ich uns mal registrieren.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.ifdef ENGLISH
	.string "I would've liked to battle with you\n"
	.string "at my side.$"
	.else
	.ifdef GERMAN
	.string "Ich hätte gerne mit dir Seite an Seite\n"
	.string "gekämpft.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.ifdef ENGLISH
	.string "Hello!\n"
	.string "I'm {STR_VAR_1}, and I'm a BEAUTY!$"
	.else
	.ifdef GERMAN
	.string "Hallo! Ich bin {STR_VAR_1},\n"
	.string "eine wahre SCHÖNHEIT!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.ifdef ENGLISH
	.string "Do you know what I've been raising?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Dies sind meine POKéMON!\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1}$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "What do you think?\n"
	.string "Want to make a tag team together?$"
	.else
	.ifdef GERMAN
	.string "kann, und ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann!\p"
	.string "Was meinst du? Möchtest du mit mir ein\n"
	.string "Team bilden?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.ifdef ENGLISH
	.string "Wonderful!\n"
	.string "I'll get the registration done now!$"
	.else
	.ifdef GERMAN
	.string "Wunderbar!\n"
	.string "Ich werde uns jetzt registrieren.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.ifdef ENGLISH
	.string "How disappointing!\p"
	.string "We two together--we would've been\n"
	.string "the best!$"
	.else
	.ifdef GERMAN
	.string "Was für eine Enttäuschung!\p"
	.string "Wir beide Seite an Seite - das wäre\n"
	.string "wirklich schön gewesen…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.ifdef ENGLISH
	.string "Yo!\p"
	.string "You know who I am?\n"
	.string "I'm {STR_VAR_1} the FISHERMAN!$"
	.else
	.ifdef GERMAN
	.string "Yo!\p"
	.string "Weißt du, wer ich bin?\n"
	.string "Ich bin {STR_VAR_1}, der ANGLER!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.ifdef ENGLISH
	.string "I've got with me a team of one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"
	.else
	.ifdef GERMAN
	.string "Mein Team: ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann, und$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "So, how about it?\n"
	.string "Will you battle at my side?$"
	.else
	.ifdef GERMAN
	.string "ein {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann!\p"
	.string "Wie sieht’s aus? Interesse, mit\n"
	.string "uns ein Team zu bilden?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.ifdef ENGLISH
	.string "Good, good!\n"
	.string "Leave it up to me!\p"
	.string "I'll go and register us now.$"
	.else
	.ifdef GERMAN
	.string "Fein, fein!\n"
	.string "Überlass den Rest ruhig mir!\p"
	.string "Ich werde uns jetzt registrieren.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.ifdef ENGLISH
	.string "We matched up perfectly, too…$"
	.else
	.ifdef GERMAN
	.string "Und dabei wären wir so ein gutes Team\n"
	.string "gewesen…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.ifdef ENGLISH
	.string "Glad to make your acquaintance.\n"
	.string "I am {STR_VAR_1}, a LADY.$"
	.else
	.ifdef GERMAN
	.string "Freut mich, dich kennen zu lernen.\n"
	.string "Ich bin die LADY {STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.ifdef ENGLISH
	.string "I am accompanied by a team of\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Mich begleitet ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann, und$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "I hope I meet your approval.\n"
	.string "For I wish to have you as my partner.$"
	.else
	.ifdef GERMAN
	.string "ein {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann. Ich hoffe, wir erfüllen deine\p"
	.string "Erwartungen, denn ich würde gerne\n"
	.string "an deiner Seite kämpfen.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.ifdef ENGLISH
	.string "I thank you sincerely.\n"
	.string "I shall handle the registration.$"
	.else
	.ifdef GERMAN
	.string "Ich bedanke mich sehr! Ich werde\n"
	.string "mich nun um die Registrierung kümmern.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.ifdef ENGLISH
	.string "I'm sure that you will regret not\n"
	.string "having me as your partner.$"
	.else
	.ifdef GERMAN
	.string "Ich bin sicher, du wirst es irgendwann\n"
	.string "bedauern, uns abgelehnt zu haben. $"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.ifdef ENGLISH
	.string "I'm TRIATHLETE {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Ich bin TRIATHLET {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.ifdef ENGLISH
	.string "What I have…\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Ich habe…\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1} kann,$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\n"
	.string "That's my pair!\p"
	.string "Please?\n"
	.string "Will you form a tag team with me?$"
	.else
	.ifdef GERMAN
	.string "und ein {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann. Das ist mein Paar!\p"
	.string "Bitte?\n"
	.string "Lass uns ein Team bilden, ja?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.ifdef ENGLISH
	.string "Gee, thanks!\n"
	.string "I'll go register at the counter.$"
	.else
	.ifdef GERMAN
	.string "Juhuu, danke!\n"
	.string "Ich werde mich nun registrieren.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.ifdef ENGLISH
	.string "We two together, we would've been\n"
	.string "tough for certain!$"
	.else
	.ifdef GERMAN
	.string "Dabei wären wir beide wirklich\n"
	.string "unglaublich stark gewesen…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.ifdef ENGLISH
	.string "Hiya!\n"
	.string "I'm BUG CATCHER {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Hallo!\n"
	.string "Ich bin KÄFERSAMMLER {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.ifdef ENGLISH
	.string "Check out what I have!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Guck mal, was ich hier habe!\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1} kann,$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "So, listen!\n"
	.string "Do you want to form a tag team?$"
	.else
	.ifdef GERMAN
	.string "und ein {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann!\p"
	.string "Hast du gehört?\n"
	.string "Komm, wir bilden ein Team!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.ifdef ENGLISH
	.string "Gotcha!\p"
	.string "I'll go do the registration stuff\n"
	.string "at the counter.$"
	.else
	.ifdef GERMAN
	.string "Verstanden!\n"
	.string "Ich kümmere mich um die Registrierung.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.ifdef ENGLISH
	.string "Aww, my POKéMON are awesome.\n"
	.string "I hope you won't regret this!$"
	.else
	.ifdef GERMAN
	.string "Ach, dabei sind meine POKéMON klasse!\n"
	.string "Ich hoffe, du wirst das nicht bereuen.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.ifdef ENGLISH
	.string "Good day!\n"
	.string "I'm SCHOOL KID {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Guten Tag!\n"
	.string "Ich bin SCHULKIND {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.ifdef ENGLISH
	.string "What I've been raising are one\n"
	.string "{STR_VAR_2} that uses {STR_VAR_1}$"
	.else
	.ifdef GERMAN
	.string "Ich ziehe ein {STR_VAR_2} auf, das\n"
	.string "{STR_VAR_1} kann, und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.ifdef ENGLISH
	.string "and one {STR_VAR_2} that uses\n"
	.string "{STR_VAR_1}.\p"
	.string "Not too bad, don't you think?\n"
	.string "Would you care to form a tag team?$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann.\p"
	.string "Nicht schlecht, was? Bist du be-\n"
	.string "eindruckt und wählst uns als Partner?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.ifdef ENGLISH
	.string "Thank you very much!\n"
	.string "I'll get done with the registration.$"
	.else
	.ifdef GERMAN
	.string "Vielen Dank! Ich werde mich\n"
	.string "um die Registrierung kümmern.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.ifdef ENGLISH
	.string "That's too bad…\p"
	.string "I was hoping that I could learn\n"
	.string "from you as your partner…$"
	.else
	.ifdef GERMAN
	.string "Das ist schade…\p"
	.string "Ich hoffte, etwas von dir lernen zu\n"
	.string "können…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.ifdef ENGLISH
	.string "Yo! Let me tell you who I am!\n"
	.string "I'm RICH BOY {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Hallo! Ich werde mich dir vorstellen!\n"
	.string "Ich bin SCHNÖSEL {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.ifdef ENGLISH
	.string "Guess what I got!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Rate mal, was ich bei mir habe!\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1} kann,$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "I'm willing to offer you the chance\n"
	.string "to be in a tag team with me.$"
	.else
	.ifdef GERMAN
	.string "und ein {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann!\p"
	.string "Ich gebe dir hier und jetzt die Chance,\n"
	.string "mit uns ein Team zu bilden.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.ifdef ENGLISH
	.string "Smart move!\p"
	.string "I'll finish up the registration\n"
	.string "process quick!$"
	.else
	.ifdef GERMAN
	.string "Kluge Entscheidung!\p"
	.string "Ich werde mich um die Registrierung\n"
	.string "kümmern.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.ifdef ENGLISH
	.string "You'd turn me of all people down?\n"
	.string "You'll regret that decision for sure!$"
	.else
	.ifdef GERMAN
	.string "Ausgerechnet mich lehnst du ab?!?\n"
	.string "Das wird dir bestimmt noch Leid tun!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.ifdef ENGLISH
	.string "Hiyah!\n"
	.string "I am BLACK BELT {STR_VAR_1}.$"
	.else
	.ifdef GERMAN
	.string "Kiyaii!\n"
	.string "Ich bin SCHWARZGURT {STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.ifdef ENGLISH
	.string "As my companions, I have\n"
	.string "one {STR_VAR_2} using {STR_VAR_1}$"
	.else
	.ifdef GERMAN
	.string "Meine Begleiter sind ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann, und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.ifdef ENGLISH
	.string "and one {STR_VAR_2} using\n"
	.string "{STR_VAR_1}.\p"
	.string "Please, grant me my wish!\n"
	.string "Allow me to be your tag partner!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann.\p"
	.string "Bitte, erfüll mir einen Wunsch!\n"
	.string "Bilde ein Team mit mir.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.ifdef ENGLISH
	.string "Hiyah!\n"
	.string "I will go register forthwith!$"
	.else
	.ifdef GERMAN
	.string "Kiyaii! Ich werde mich um\n"
	.string "die Registrierung kümmern.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.ifdef ENGLISH
	.string "I see… I hope for an opportunity\n"
	.string "the next time we meet…$"
	.else
	.ifdef GERMAN
	.string "Verstehe… Ich hoffe, du gibst mir\n"
	.string "beim nächsten Mal die Gelegenheit…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.ifdef ENGLISH
	.string "Hi, there!\n"
	.string "I'm {STR_VAR_1}, and I'm a TUBER!$"
	.else
	.ifdef GERMAN
	.string "Hallo, du da!\n"
	.string "Ich bin {STR_VAR_1}, ein PLANSCHER!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.ifdef ENGLISH
	.string "I'll tell you what I have.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Weißt du, ich habe ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann, und$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\n"
	.string "May I please be on your tag team?$"
	.else
	.ifdef GERMAN
	.string "ein {STR_VAR_2}, das {STR_VAR_1} kann.\n"
	.string "Wählst du mich als Partner, ja?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.ifdef ENGLISH
	.string "Thank you!\n"
	.string "I'll go register us now!$"
	.else
	.ifdef GERMAN
	.string "Hui! Fein!\n"
	.string "Ich werde uns registrieren.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.ifdef ENGLISH
	.string "If we'd become partners, we could\n"
	.string "have been so strong!$"
	.else
	.ifdef GERMAN
	.string "Wären wir Partner geworden, wären\n"
	.string "wir bestimmt superstark gewesen.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.ifdef ENGLISH
	.string "Greetings…\n"
	.string "I am HEX MANIAC {STR_VAR_1}…$"
	.else
	.ifdef GERMAN
	.string "Sei gegrüßt…\n"
	.string "Ich bin HEXE {STR_VAR_1}…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.ifdef ENGLISH
	.string "I bear with me one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2} together with one$"
	.else
	.ifdef GERMAN
	.string "Ich habe ein {STR_VAR_2} bei mir, das\n"
	.string "{STR_VAR_1} kann, und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.ifdef ENGLISH
	.string "{STR_VAR_1}-using {STR_VAR_2}…\p"
	.string "I beseech you…\n"
	.string "Join me in a tag team…$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann…\p"
	.string "Ich bitte dich…\n"
	.string "Nimm uns als deine Partner an…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.ifdef ENGLISH
	.string "I thank you…\n"
	.string "I shall register us…$"
	.else
	.ifdef GERMAN
	.string "Vielen Dank…\n"
	.string "Ich werde uns registrieren…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.ifdef ENGLISH
	.string "I so longed to join you…$"
	.else
	.ifdef GERMAN
	.string "Und wir wären so gerne deine\n"
	.string "Partner geworden…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.ifdef ENGLISH
	.string "How do you do? I'm {STR_VAR_1},\n"
	.string "and I'm a POKéMON BREEDER!$"
	.else
	.ifdef GERMAN
	.string "Wie geht es dir? Ich bin {STR_VAR_1},\n"
	.string "ein PKMN-ZÜCHTER.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.ifdef ENGLISH
	.string "I'm raising a couple good ones!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Ich züchte die besten POKéMON!\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1} kann,$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "How about it?\n"
	.string "Feel like making a tag team with me?$"
	.else
	.ifdef GERMAN
	.string "und ein {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann.\p"
	.string "Wie sieht’s aus? Sollen wir ein Team\n"
	.string "bilden?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.ifdef ENGLISH
	.string "Thank you kindly!\p"
	.string "I'll go take care of the registration\n"
	.string "stuff, so you wait right here!$"
	.else
	.ifdef GERMAN
	.string "Vielen, vielen Dank!\p"
	.string "Ich kümmere mich um die Registrierung,\n"
	.string "du kannst hier entspannt warten.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.ifdef ENGLISH
	.string "I was looking forward to being\n"
	.string "your partner…$"
	.else
	.ifdef GERMAN
	.string "Schade, ich wäre gerne dein Teampartner\n"
	.string "geworden…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.ifdef ENGLISH
	.string "Well, hello!\n"
	.string "I'm TRIATHLETE {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Hallo!\n"
	.string "Ich bin TRIATHLET {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.ifdef ENGLISH
	.string "Want to know what I run with?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Wer mich beim Laufen begleitet?\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1} kann,$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Well?\n"
	.string "Want to be in a tag team with me?$"
	.else
	.ifdef GERMAN
	.string "und ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann!\p"
	.string "Nun?\n"
	.string "Sollen wir ein Team mit dir bilden?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.ifdef ENGLISH
	.string "Good going!\p"
	.string "I'll be quick and get the registration\n"
	.string "all done!$"
	.else
	.ifdef GERMAN
	.string "Das ist wahrer Sportsgeist!\p"
	.string "Ich werde uns schnell registrieren.\n"
	.string "Lauf nicht weg!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.ifdef ENGLISH
	.string "You and me, we would've been tops.\n"
	.string "It's too bad…$"
	.else
	.ifdef GERMAN
	.string "Wir beide hätten uns den ersten Platz\n"
	.string "geholt. Schade, schade, schade!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.ifdef ENGLISH
	.string "Hey, there! My name's {STR_VAR_1}!\n"
	.string "I'm a TRIATHLETE!$"
	.else
	.ifdef GERMAN
	.string "Hey, du! Mein Name ist {STR_VAR_1}!\n"
	.string "Ich bin ein TRIATHLET.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.ifdef ENGLISH
	.string "I go on runs with my durable team--\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Mein Team trainiert mit mir.\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1} kann,$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Not too shabby, huh?\n"
	.string "We should be in a tag team together!$"
	.else
	.ifdef GERMAN
	.string "und ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann.\p"
	.string "Nicht gerade unterste Schublade, nicht\n"
	.string "wahr? Wir sollten ein Team bilden!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.ifdef ENGLISH
	.string "All right!\n"
	.string "I'll go register in a flash!$"
	.else
	.ifdef GERMAN
	.string "Sehr gut!\n"
	.string "Ich übernehme die Registrierung.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.ifdef ENGLISH
	.string "I really wanted to battle as your\n"
	.string "tag-team partner…$"
	.else
	.ifdef GERMAN
	.string "Schade! Ich hätte mich wirklich\n"
	.string "angestrengt und mein Bestes gegeben!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.ifdef ENGLISH
	.string "I'm BATTLE GIRL {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Ich bin KÄMPFERIN {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.ifdef ENGLISH
	.string "I've been toughening up one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"
	.else
	.ifdef GERMAN
	.string "Ich habe ein {STR_VAR_2}, das\n"
	.string "{STR_VAR_1} kann, und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_1}-using {STR_VAR_2}!\p"
	.string "Do you like that combo?\n"
	.string "How about you and me join up?$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann!\p"
	.string "Sagt dir diese Combo zu?\n"
	.string "Sollen wir mit dir ein Team bilden?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.ifdef ENGLISH
	.string "Why, thanks!\p"
	.string "I'll get the registration done\n"
	.string "right now!$"
	.else
	.ifdef GERMAN
	.string "Danke!\p"
	.string "Ich werde uns registrieren.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.ifdef ENGLISH
	.string "With you, I thought we could form\n"
	.string "the ultimate tag team…$"
	.else
	.ifdef GERMAN
	.string "Und ich hatte gehofft, mit dir das\n"
	.string "ultimative Kampfteam bilden zu können…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.ifdef ENGLISH
	.string "I'm TRIATHLETE {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Ich bin TRIATHLET {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.ifdef ENGLISH
	.string "I've been running with one {STR_VAR_2}\n"
	.string "that knows how to use {STR_VAR_1}$"
	.else
	.ifdef GERMAN
	.string "Mich begleiten ein {STR_VAR_2}, das\n"
	.string "{STR_VAR_1} kann, und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.ifdef ENGLISH
	.string "and one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "We could be in a tag team.\n"
	.string "Wouldn't that be great?$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann.\p"
	.string "Wir könnten mit dir ein Team bilden.\n"
	.string "Wäre das nicht super?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.ifdef ENGLISH
	.string "Thank you!\p"
	.string "I'll go register us, and that's\n"
	.string "right now!$"
	.else
	.ifdef GERMAN
	.string "Danke!\p"
	.string "Ich werde uns jetzt sofort\n"
	.string "registrieren.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.ifdef ENGLISH
	.string "Aww, that's too bad. We would've been\n"
	.string "the toughest tag team around!$"
	.else
	.ifdef GERMAN
	.string "Schade! Schade!!! Wir wären das\n"
	.string "stärkste Team weit und breit gewesen!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.ifdef ENGLISH
	.string "Me?\n"
	.string "I'm TUBER {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Meinst du mich? Ich bin ein\n"
	.string "PLANSCHER und heiße {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.ifdef ENGLISH
	.string "What do I have with me?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Welche POKéMON ich dabei habe?\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1}$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Hey?\n"
	.string "You'll team up with me, right?$"
	.else
	.ifdef GERMAN
	.string "kann, und ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann…\p"
	.string "Hey? Du und ich - wir bilden ein\n"
	.string "Team, okay?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.ifdef ENGLISH
	.string "Okay!\p"
	.string "I'll go register!\n"
	.string "Let's be excellent together!$"
	.else
	.ifdef GERMAN
	.string "Okay!!!\p"
	.string "Ich werde mich registrieren!\n"
	.string "Die anderen werden blass vor Neid!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.ifdef ENGLISH
	.string "My POKéMON are tough for sure…\n"
	.string "It's too bad you don't want to team up.$"
	.else
	.ifdef GERMAN
	.string "Meine POKéMON sind stark, jawohl!\n"
	.string "Schade, dass du Nein sagst.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.ifdef ENGLISH
	.string "Yay-hey!\n"
	.string "Call me GUITARIST {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Jahuu!\n"
	.string "Ich bin GITARRIST {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.ifdef ENGLISH
	.string "Check out my entourage!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Schau dir meine Begleitband an!\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1} kann,$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Yay-hey! Pretty wild, huh?\n"
	.string "We'll have to do a duet in a tag team!$"
	.else
	.ifdef GERMAN
	.string "und ein {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann!\p"
	.string "Richtig wild, was? Komm, tritt\n"
	.string "unserer Band bei!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.ifdef ENGLISH
	.string "Yay-hey! Right on!\n"
	.string "I'll do that registration stuff now!$"
	.else
	.ifdef GERMAN
	.string "Ja! Das ist der richtige Takt! Ich werde\n"
	.string "mich um die Registrierung kümmern.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.ifdef ENGLISH
	.string "My POKéMON rock hard!\n"
	.string "You'll be sorry, I tell you!$"
	.else
	.ifdef GERMAN
	.string "Meine POKéMON sind megastark!\n"
	.string "Du wirst das bestimmt bedauern!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.ifdef ENGLISH
	.string "Pleased to meet you.\n"
	.string "I am {STR_VAR_1}, a GENTLEMAN.$"
	.else
	.ifdef GERMAN
	.string "Nett, dich kennen zu lernen.\n"
	.string "Ich bin GENTLEMAN {STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.ifdef ENGLISH
	.string "I am accompanied by my trusted\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"
	.else
	.ifdef GERMAN
	.string "Ich werde begleitet von meinem treuen\n"
	.string "{STR_VAR_2}, das {STR_VAR_1} kann,$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "May I ask you to join me in a tag-team\n"
	.string "partnership arrangement?$"
	.else
	.ifdef GERMAN
	.string "und meinem treuen {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann.\p"
	.string "Darf ich dich fragen, ob wir mit dir im\n"
	.string "Team Seite an Seite kämpfen dürfen?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.ifdef ENGLISH
	.string "Ah, I thank you for your trust.\n"
	.string "I shall be done with the registration.$"
	.else
	.ifdef GERMAN
	.string "Vielen Dank! Es ist mir eine Ehre,\n"
	.string "mich um die Registrierung zu kümmern!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.ifdef ENGLISH
	.string "That is most unfortunate…\p"
	.string "I shall look forward to the next\n"
	.string "opportunity…$"
	.else
	.ifdef GERMAN
	.string "Welch ein Unglück…\p"
	.string "Ich werde geduldig auf die nächste\n"
	.string "Gelegenheit warten…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.ifdef ENGLISH
	.string "Hello, I'm {STR_VAR_1},\n"
	.string "and I'm a POKéFAN.$"
	.else
	.ifdef GERMAN
	.string "Hallo! Ich bin {STR_VAR_1},\n"
	.string "ein großer POKéFAN.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.ifdef ENGLISH
	.string "I have with me now one {STR_VAR_2}\n"
	.string "that knows the move {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Ich habe ein {STR_VAR_2} dabei, das\n"
	.string "{STR_VAR_1} kann, und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Do you like what you see?\n"
	.string "Why don't you be my tag partner?$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann.\p"
	.string "Gefällt dir, was du siehst?\n"
	.string "Warum werden wir nicht Partner?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.ifdef ENGLISH
	.string "Thank you!\n"
	.string "I'll look after the registration!$"
	.else
	.ifdef GERMAN
	.string "Vielen Dank!\n"
	.string "Ich kümmere mich um die Registrierung.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.ifdef ENGLISH
	.string "My POKéMON are top grade…\n"
	.string "It's too bad you can't appreciate that.$"
	.else
	.ifdef GERMAN
	.string "Meine POKéMON sind erste Klasse!\n"
	.string "Schade, dass du das nicht akzeptierst.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.ifdef ENGLISH
	.string "Hm!\n"
	.string "I am {STR_VAR_1}, and an EXPERT am I!$"
	.else
	.ifdef GERMAN
	.string "Hm!\n"
	.string "Ich bin der EXPERTE {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.ifdef ENGLISH
	.string "The POKéMON that I've toughened up are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Meine POKéMON sind ein {STR_VAR_2}, das\n"
	.string "{STR_VAR_1} kann, und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "What say you to a tag team with me?$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann!\p"
	.string "Willst du zu uns ins Team?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.ifdef ENGLISH
	.string "Hm!\n"
	.string "I shall register us right away!\l"
	.string "Let us both do our best!$"
	.else
	.ifdef GERMAN
	.string "Hm!\n"
	.string "Ich werde uns sofort anmelden!\l"
	.string "Lass uns beide unser Bestes geben!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.ifdef ENGLISH
	.string "I will hope that your choice is\n"
	.string "indeed correct…$"
	.else
	.ifdef GERMAN
	.string "Hoffen wir mal, dass deine Entscheidung\n"
	.string "richtig war…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.ifdef ENGLISH
	.string "Hello, hello.\n"
	.string "I'm {STR_VAR_1}, and I'm an EXPERT.$"
	.else
	.ifdef GERMAN
	.string "Hallo, hallo.\n"
	.string "Ich bin EXPERTE {STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.ifdef ENGLISH
	.string "I've raised my POKéMON thoroughly.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Ich zog meine PKMN sorgfältig auf.\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1}$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
	.string "they're what I have.\p"
	.string "Wouldn't you like to team up with me?$"
	.else
	.ifdef GERMAN
	.string "kann, und ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann.\p"
	.string "Möchtest du mit uns ein Team bilden?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.ifdef ENGLISH
	.string "Good, good.\n"
	.string "I'll see to the registration right away.$"
	.else
	.ifdef GERMAN
	.string "Sehr gut! Fein! Ich werde mich\n"
	.string "sofort um die Registrierung kümmern.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.ifdef ENGLISH
	.string "Perhaps we can form a team the next\n"
	.string "time we meet.$"
	.else
	.ifdef GERMAN
	.string "Na, vielleicht beim nächsten Mal…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.ifdef ENGLISH
	.string "I'm DRAGON TAMER {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Ich bin DRACHENPROFI {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.ifdef ENGLISH
	.string "The team I've been toughening up is\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "In meinem Team ist ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann, und$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "How about it?\n"
	.string "Want to be my partner?$"
	.else
	.ifdef GERMAN
	.string "ein {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann!\p"
	.string "Was meinst du? Möchtest du mit uns\n"
	.string "ein Team bilden?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.ifdef ENGLISH
	.string "Okay, I'll give it my best!\n"
	.string "I'll go register now, all right?$"
	.else
	.ifdef GERMAN
	.string "Okay, ich werde mein Bestes geben!\n"
	.string "Ich werde uns jetzt registrieren.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.ifdef ENGLISH
	.string "You're not going to find many tougher\n"
	.string "partners than me!$"
	.else
	.ifdef GERMAN
	.string "Du wirst keinen stärkeren Partner als\n"
	.string "mich finden!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.ifdef ENGLISH
	.string "I'm BIRD KEEPER {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Ich bin VOGELFÄNGER {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.ifdef ENGLISH
	.string "What POKéMON do I have?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Welche POKéMON ich habe?\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1} kann,$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Don't you think we'd make a decent\n"
	.string "tag team?$"
	.else
	.ifdef GERMAN
	.string "und ein {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann.\p"
	.string "Sind wir nicht ein tolles Gespann?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.ifdef ENGLISH
	.string "Great, thanks!\n"
	.string "I'll look after the registration!$"
	.else
	.ifdef GERMAN
	.string "Super, danke!\n"
	.string "Ich werde uns anmelden.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.ifdef ENGLISH
	.string "My POKéMON and I are strong.\n"
	.string "What a letdown.$"
	.else
	.ifdef GERMAN
	.string "Meine POKéMON und ich sind stark.\n"
	.string "Was für eine Enttäuschung…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.ifdef ENGLISH
	.string "I'm NINJA BOY {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Ich bin NINJAJUNGE {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.ifdef ENGLISH
	.string "My POKéMON team consists of one\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Meine POKéMON?!? Ein {STR_VAR_2}, das\n"
	.string "{STR_VAR_1} kann, und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Let's be in a tag team together!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann!\p"
	.string "Komm, wir bilden ein Team!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.ifdef ENGLISH
	.string "Yay!\n"
	.string "Let me go register!$"
	.else
	.ifdef GERMAN
	.string "Ja!\n"
	.string "Ich melde uns an.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.ifdef ENGLISH
	.string "You'll regret not having my tough\n"
	.string "POKéMON on your side!$"
	.else
	.ifdef GERMAN
	.string "Du wirst meine starken POKéMON\n"
	.string "bestimmt vermissen!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.ifdef ENGLISH
	.string "Hello!\n"
	.string "I'm PARASOL LADY {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Hallo!\n"
	.string "Ich bin SCHIRMDAME {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.ifdef ENGLISH
	.string "Escorting me now are my {STR_VAR_2}\n"
	.string "that uses {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Meine Begleiter sind ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann, und$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} that uses\n"
	.string "{STR_VAR_1}.\p"
	.string "Aren't they nice?\n"
	.string "Care to join us in a tag team?$"
	.else
	.ifdef GERMAN
	.string "ein {STR_VAR_2}, das {STR_VAR_1} kann.\p"
	.string "Sind sie nicht bezaubernd?\n"
	.string "Möchtest du mit uns ein Team bilden?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.ifdef ENGLISH
	.string "Thanks a bunch!\p"
	.string "I'll go register at the counter.\n"
	.string "Let's not disappoint each other!$"
	.else
	.ifdef GERMAN
	.string "Vielen Dank!\p"
	.string "Ich werde uns anmelden. Wir sollten\n"
	.string "uns beide nicht enttäuschen!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.ifdef ENGLISH
	.string "My POKéMON are tremendously strong.\n"
	.string "How disappointing…$"
	.else
	.ifdef GERMAN
	.string "Meine POKéMON sind ungeheuer stark.\n"
	.string "Wie enttäuschend…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.ifdef ENGLISH
	.string "Hello.\n"
	.string "I'm {STR_VAR_1}, and I'm a BUG MANIAC!$"
	.else
	.ifdef GERMAN
	.string "Hallo!\n"
	.string "Ich bin KÄFERMANIAC {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.ifdef ENGLISH
	.string "I have found my POKéMON, yes.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Ich habe meine PKMN selbst gefunden!\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1}$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
	.string "they are what I found.\p"
	.string "Could I interest you in forming\n"
	.string "a tag team?$"
	.else
	.ifdef GERMAN
	.string "kann, und ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann.\p"
	.string "Alle selbst gefunden!!! Möchtest du mit\n"
	.string "uns ein Team bilden?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.ifdef ENGLISH
	.string "Okay!\n"
	.string "Understood!\p"
	.string "I won't be long with the registration!$"
	.else
	.ifdef GERMAN
	.string "Okay!\n"
	.string "Verstanden!\p"
	.string "Die Registrierung geht ganz schnell.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.ifdef ENGLISH
	.string "With the POKéMON I found, we wouldn't\n"
	.string "have lost…$"
	.else
	.ifdef GERMAN
	.string "Mit meinen selbst gefundenen POKéMON\n"
	.string "hätten wir nicht verlieren können…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.ifdef ENGLISH
	.string "Ahoy, there!\n"
	.string "I'm SAILOR {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Ahoi, Landratte!\n"
	.string "Ich bin MATROSE {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.ifdef ENGLISH
	.string "Let me show you my pride and joy!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Ich zeige dir meinen ganzen Stolz!\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1}$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Of course you're not going to turn\n"
	.string "me down. We will team up, right?$"
	.else
	.ifdef GERMAN
	.string "kann, und ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann!\p"
	.string "Natürlich kannst du so nicht Nein\n"
	.string "sagen! Also? Sind wir ein Team?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.ifdef ENGLISH
	.string "I didn't expect any less!\n"
	.string "I'll go register now.$"
	.else
	.ifdef GERMAN
	.string "Ich habe nichts anderes erwartet!\n"
	.string "Ich kümmere mich um die Registrierung.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.ifdef ENGLISH
	.string "We would've stormed through\n"
	.string "the opposition! Too bad!$"
	.else
	.ifdef GERMAN
	.string "Wir wären über die Gegner wie ein Sturm\n"
	.string "auf hoher See hinweggefegt…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.ifdef ENGLISH
	.string "Hi, I'm {STR_VAR_1}.\n"
	.string "I'm a COLLECTOR.$"
	.else
	.ifdef GERMAN
	.string "Hi, ich bin {STR_VAR_1}.\n"
	.string "Ich bin ein PKMN-SAMMLER.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.ifdef ENGLISH
	.string "The jewels in my collection are\n"
	.string "my {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Meine Juwelen! Ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann, und$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Swell, huh?\n"
	.string "We should be in a team together.$"
	.else
	.ifdef GERMAN
	.string "ein {STR_VAR_2}, das {STR_VAR_1} kann.\p"
	.string "Nobel, was? Wir beide sollten echt\n"
	.string "ein Team bilden. Was meinst du?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.ifdef ENGLISH
	.string "Oh, yeah!\p"
	.string "Well, let's not waste any time.\n"
	.string "I'll go register the two of us.$"
	.else
	.ifdef GERMAN
	.string "Oh, yeah!\p"
	.string "Dann lass uns keine weitere Zeit\n"
	.string "mehr vergeuden! Ich melde uns an.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.ifdef ENGLISH
	.string "Well, that's upsetting.\n"
	.string "You don't appreciate my POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Das betrübt mich jetzt wirklich.\n"
	.string "Meine POKéMON sind doch wahre Schätze!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.ifdef ENGLISH
	.string "Howdy, I'm {STR_VAR_1}.\n"
	.string "I'm a POKéMON RANGER.$"
	.else
	.ifdef GERMAN
	.string "Na, du? Ich bin {STR_VAR_1}.\n"
	.string "Ich bin ein PKMN-RANGER.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.ifdef ENGLISH
	.string "Keeping me company are one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"
	.else
	.ifdef GERMAN
	.string "Ich habe ein {STR_VAR_2}, das\n"
	.string "{STR_VAR_1} kann, und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Don't you think we'd make an impressive\n"
	.string "tag team?$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann!\p"
	.string "Meinst du nicht, dass wir ein\n"
	.string "beeindruckendes Team wären?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.ifdef ENGLISH
	.string "That's super!\n"
	.string "I'll deal with the registration now.$"
	.else
	.ifdef GERMAN
	.string "Das ist klasse!\n"
	.string "Ich melde uns an.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.ifdef ENGLISH
	.string "Next time, choose my POKéMON,\n"
	.string "will you?$"
	.else
	.ifdef GERMAN
	.string "Nächstes Mal wählst du meine POKéMON\n"
	.string "aus. Ja?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.ifdef ENGLISH
	.string "My name's {STR_VAR_1}.\n"
	.string "I'm a POKéMON RANGER!$"
	.else
	.ifdef GERMAN
	.string "Ich heiße {STR_VAR_1}.\n"
	.string "Ich bin ein PKMN-RANGER.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.ifdef ENGLISH
	.string "Let me tell you about my team. I have\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Ich habe folgende POKéMON dabei:\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1} kann,$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "How would you like to form a tag team\n"
	.string "with my little posse?$"
	.else
	.ifdef GERMAN
	.string "und ein {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann.\p"
	.string "Würdest du nicht gerne mit meiner\n"
	.string "Bande ein Team bilden?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.ifdef ENGLISH
	.string "We'll be at our best!\n"
	.string "I'll get the registration done quick!$"
	.else
	.ifdef GERMAN
	.string "Wir werden unser Bestes geben!\n"
	.string "Ich werde uns ganz schnell anmelden!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.ifdef ENGLISH
	.string "I hope you'll choose my POKéMON\n"
	.string "next time.$"
	.else
	.ifdef GERMAN
	.string "Ich hoffe, das nächste Mal wählst du\n"
	.string "die POKéMON für mich aus.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.ifdef ENGLISH
	.string "Pleased to meet you. I'm {STR_VAR_1}.\n"
	.string "I consider myself an AROMA LADY.$"
	.else
	.ifdef GERMAN
	.string "Schön, dich kennen zu lernen. Ich bin\n"
	.string "AROMALADY {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.ifdef ENGLISH
	.string "I travel with one {STR_VAR_2}\n"
	.string "that uses {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Ich reise mit einem {STR_VAR_2}, das\n"
	.string "{STR_VAR_1} kann, und einem$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} that uses\n"
	.string "{STR_VAR_1}.\p"
	.string "I hope they strike your fancy.\n"
	.string "Would you care to be my partner?$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann.\p"
	.string "Ich hoffe, sie treffen deinen Ge-\n"
	.string "schmack? Möchtest du ein Team bilden?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.ifdef ENGLISH
	.string "I'm honored by your acceptance.\n"
	.string "I will go register right this instant.$"
	.else
	.ifdef GERMAN
	.string "Ich fühle mich geehrt!\n"
	.string "Ich werde uns sofort anmelden.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.ifdef ENGLISH
	.string "It would be wonderful if we could form\n"
	.string "a tag team the next time we meet.$"
	.else
	.ifdef GERMAN
	.string "Es wäre schön, wenn wir das nächste\n"
	.string "Mal ein Team bilden könnten.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.ifdef ENGLISH
	.string "Want to know who I am?\n"
	.string "I'm {STR_VAR_1}, the RUIN MANIAC!$"
	.else
	.ifdef GERMAN
	.string "Weißt du, wer ich bin?\n"
	.string "Ich bin der RUINENMANIAC {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.ifdef ENGLISH
	.string "The POKéMON that I have with me are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Ich habe ein {STR_VAR_2}, das\n"
	.string "{STR_VAR_1} kann, und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Intriguing, eh?\n"
	.string "How about you and I partner up?$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann!\p"
	.string "Faszinierend, nicht wahr?\n"
	.string "Möchtest du ein Team mit uns bilden?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.ifdef ENGLISH
	.string "That's a sound decision!\n"
	.string "I'll go do the registration paperwork.$"
	.else
	.ifdef GERMAN
	.string "Das ist eine gute Entscheidung! Ich\n"
	.string "werde mich um die Anmeldung kümmern.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.ifdef ENGLISH
	.string "Hmm…\n"
	.string "I think my POKéMON are tough…$"
	.else
	.ifdef GERMAN
	.string "Hmm… Ich bin überzeugt,\n"
	.string "meine POKéMON sind stark…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.ifdef ENGLISH
	.string "I'm COOLTRAINER {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Ich bin ASS-TRAINER {STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.ifdef ENGLISH
	.string "The POKéMON I have right now are one\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Ich habe ein {STR_VAR_2}, das\n"
	.string "{STR_VAR_1} kann, und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
	.string "Cool, huh?\p"
	.string "Don't you think it'd be pretty cool\n"
	.string "if we made a tag team?$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann,\n"
	.string "dabei. Cool, was?\p"
	.string "Und wäre es nicht noch viel cooler, wenn\n"
	.string "wir ein Team bilden würden?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.ifdef ENGLISH
	.string "Cool!\n"
	.string "I'll go do the registration in a flash!$"
	.else
	.ifdef GERMAN
	.string "Cool!!!\n"
	.string "Ich melde uns blitzschnell an.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.ifdef ENGLISH
	.string "I thought that we'd make just\n"
	.string "the greatest team ever.$"
	.else
	.ifdef GERMAN
	.string "Und ich dachte, wir könnten das coolste\n"
	.string "Team in der Geschichte werden…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.ifdef ENGLISH
	.string "I'm COOLTRAINER {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Ich bin ASS-TRAINER {STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.ifdef ENGLISH
	.string "The team I've been raising has one\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Mein Team, fragst du? Ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann, und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Does that sound okay?\n"
	.string "How about we become tag partners?$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann.\p"
	.string "Hört sich das gut an?\n"
	.string "Warum werden wir nicht Partner?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.ifdef ENGLISH
	.string "Sounds A-OK!\n"
	.string "I'd better do the registration.$"
	.else
	.ifdef GERMAN
	.string "Das hört sich gut an!\n"
	.string "Ich sorge für die Registrierung.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.ifdef ENGLISH
	.string "I was thinking how we would be\n"
	.string "one tough team…$"
	.else
	.ifdef GERMAN
	.string "Und ich dachte, ich könnte endlich mal\n"
	.string "mit einem starken Partner kämpfen…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.ifdef ENGLISH
	.string "Heyo!\n"
	.string "I'm {STR_VAR_1}, the POKéMANIAC!$"
	.else
	.ifdef GERMAN
	.string "Tach!\n"
	.string "Ich bin POKéMANIAC {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.ifdef ENGLISH
	.string "What does a guy like me have?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Was ich als Kenner zu bieten habe?\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1} kann,$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1},\n"
	.string "that's what!\p"
	.string "Let's do it!\n"
	.string "We'll stomp around as a tag team!$"
	.else
	.ifdef GERMAN
	.string "und ein {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann! Ist das was? Ja oder ja?\p"
	.string "Also los! Stampfen wir die andern\n"
	.string "in Grund und Boden. Ja oder ja?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.ifdef ENGLISH
	.string "Good call!\n"
	.string "I'll register the both of us!$"
	.else
	.ifdef GERMAN
	.string "Sehr gute Entscheidung!\n"
	.string "Ich werde uns registrieren.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.ifdef ENGLISH
	.string "My POKéMON are brutal!\n"
	.string "It's not my fault if you regret this!$"
	.else
	.ifdef GERMAN
	.string "Meine POKéMON sind der Hammer!\n"
	.string "Dein Pech, wenn du es bedauerst.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.ifdef ENGLISH
	.string "Yo, there!\n"
	.string "I'm KINDLER {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Hallo, du da! Ich bin {STR_VAR_1},\n"
	.string "ein wahrer HITZKOPF!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.ifdef ENGLISH
	.string "You know what my training cooked up?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Womit ich das Feuer entfache? Mit\n"
	.string "einem {STR_VAR_2}, das {STR_VAR_1}$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Well, what do you say?\n"
	.string "Want to form a tag team?$"
	.else
	.ifdef GERMAN
	.string "kennt, und einem\n"
	.string "{STR_VAR_2}, das {STR_VAR_1} kennt!\p"
	.string "Und was sagst du?\n"
	.string "Sollen wir ein Team bilden?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.ifdef ENGLISH
	.string "All right!\n"
	.string "I'll get on with the registration.$"
	.else
	.ifdef GERMAN
	.string "Gut!\n"
	.string "Ich werde uns dann mal anmelden.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.ifdef ENGLISH
	.string "Promise you'll partner up with me\n"
	.string "the next time we run into each other.$"
	.else
	.ifdef GERMAN
	.string "Versprich mir, dass wir, wenn wir uns das\n"
	.string "nächste Mal treffen, Partner werden.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.ifdef ENGLISH
	.string "I'm {STR_VAR_1}, and I'm a CAMPER!$"
	.else
	.ifdef GERMAN
	.string "Ich bin {STR_VAR_1}, ein CAMPER.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.ifdef ENGLISH
	.string "I've been raising one {STR_VAR_1}-\n"
	.string "using {STR_VAR_2} and one$"
	.else
	.ifdef GERMAN
	.string "Ich kümmere mich um ein {STR_VAR_2}, das\n"
	.string "{STR_VAR_1} kann, und um ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.ifdef ENGLISH
	.string "{STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "Do you think it'd be fun to team up?\n"
	.string "I bet it would be!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann.\p"
	.string "Meinst du, es wäre lustig, wenn wir\n"
	.string "ein Team bilden? Ich denke schon!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.ifdef ENGLISH
	.string "Yeah!\n"
	.string "Off I go to register!$"
	.else
	.ifdef GERMAN
	.string "Yeah!\n"
	.string "Ich melde uns an.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.ifdef ENGLISH
	.string "Next time, okay?\n"
	.string "I want to be on your team.$"
	.else
	.ifdef GERMAN
	.string "Dann aber das nächste Mal, ja?\n"
	.string "Ich wäre gerne in deinem Team.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.ifdef ENGLISH
	.string "Hello!\n"
	.string "I'm {STR_VAR_1}, and I'm a PICNICKER!$"
	.else
	.ifdef GERMAN
	.string "Hallo!\n"
	.string "Ich bin PICKNICKER {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.ifdef ENGLISH
	.string "The POKéMON I've been taking are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Ich habe ein {STR_VAR_2} dabei, das\n"
	.string "{STR_VAR_1} kann, und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Are you interested in joining me\n"
	.string "on a tag team?$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann.\p"
	.string "Sollen wir ein Team bilden?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.ifdef ENGLISH
	.string "Why, thank you!\n"
	.string "I will do the registration now.$"
	.else
	.ifdef GERMAN
	.string "Vielen Dank!\n"
	.string "Ich werde uns registrieren.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.ifdef ENGLISH
	.string "It would be nice if I could join you\n"
	.string "some other time.$"
	.else
	.ifdef GERMAN
	.string "Ich hoffe, dass wir irgendwann mal\n"
	.string "Teampartner werden!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.ifdef ENGLISH
	.string "I'm PSYCHIC {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Ich bin PSYCHO {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.ifdef ENGLISH
	.string "The twosome I've been raising are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Ich habe ein {STR_VAR_2}, das\n"
	.string "{STR_VAR_1} kann, und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Would you like to form a tag team\n"
	.string "with me?$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann.\p"
	.string "Würdest du gerne ein Team mit\n"
	.string "uns bilden?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.ifdef ENGLISH
	.string "Sure thing!\n"
	.string "I'll take care of the registration!$"
	.else
	.ifdef GERMAN
	.string "Na, wunderbar!\n"
	.string "Ich melde uns an.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.ifdef ENGLISH
	.string "If we meet again, that's when I'd like\n"
	.string "to team up with you.$"
	.else
	.ifdef GERMAN
	.string "Wenn wir uns das nächste Mal treffen,\n"
	.string "müssen wir unbedingt ein Team bilden!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.ifdef ENGLISH
	.string "I'm {STR_VAR_1}.\n"
	.string "I'm a PSYCHIC.$"
	.else
	.ifdef GERMAN
	.string "Ich bin {STR_VAR_1}!\n"
	.string "Ich bin ein PSYCHO…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.ifdef ENGLISH
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Ein {STR_VAR_2}, das {STR_VAR_1} kann,\n"
	.string "und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
	.string "they're my disciples.\p"
	.string "Doesn't the idea of forming a tag-team\n"
	.string "partnership intrigue you?$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann,\n"
	.string "sind meine Schüler.\p"
	.string "Kann ich dich überzeugen, ein Team\n"
	.string "mit uns zu bilden?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.ifdef ENGLISH
	.string "Thank you.\n"
	.string "I'll go deal with the registration.$"
	.else
	.ifdef GERMAN
	.string "Danke schön.\n"
	.string "Ich kümmere mich um die Anmeldung.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.ifdef ENGLISH
	.string "I hope there will be another chance\n"
	.string "to forge an alliance.$"
	.else
	.ifdef GERMAN
	.string "Ich hoffe, es wird sich eine weitere\n"
	.string "Gelegenheit für uns bieten…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.ifdef ENGLISH
	.string "I'm SCHOOL KID {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Ich bin SCHULKIND {STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.ifdef ENGLISH
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"
	.else
	.ifdef GERMAN
	.string "Mein Pärchen ist ein {STR_VAR_2}, das\n"
	.string "{STR_VAR_1} kann, und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.ifdef ENGLISH
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2} are my POKéMON pair.\p"
	.string "May I please be your partner on\n"
	.string "a tag team?$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann.\p"
	.string "Darf ich bitte dein Teampartner sein?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.ifdef ENGLISH
	.string "Ooh, thank you!\n"
	.string "I'll register at the counter right away!$"
	.else
	.ifdef GERMAN
	.string "Oooh, das ist prima!\n"
	.string "Ich melde uns sofort an!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.ifdef ENGLISH
	.string "Please?\n"
	.string "May I join you the next time?$"
	.else
	.ifdef GERMAN
	.string "Och… Darf ich dann das nächste Mal\n"
	.string "dein Teampartner sein?!?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.ifdef ENGLISH
	.string "Hiya! The name's {STR_VAR_1}!\n"
	.string "I'm a POKéMON BREEDER!$"
	.else
	.ifdef GERMAN
	.string "Huhu! Ich heiße {STR_VAR_1}!\n"
	.string "Ich bin ein PKMN-ZÜCHTER!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.ifdef ENGLISH
	.string "The POKéMON I've raised are one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"
	.else
	.ifdef GERMAN
	.string "Ich habe ein {STR_VAR_2} gezüchtet, das\n"
	.string "{STR_VAR_1} kann, und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "Sound interesting?\n"
	.string "How about we form a tag team, then?$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann.\p"
	.string "Hört sich das für dich interessant an?\n"
	.string "Dann lass uns doch ein Team bilden.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.ifdef ENGLISH
	.string "All righty!\n"
	.string "You leave the registration to me!$"
	.else
	.ifdef GERMAN
	.string "Fein, fein! Sehr gut!\n"
	.string "Überlass die Anmeldung ruhig mir.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.ifdef ENGLISH
	.string "You have to team up with me next time,\n"
	.string "all right?$"
	.else
	.ifdef GERMAN
	.string "Nächstes Mal bilden wir aber ein\n"
	.string "Team, ja?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.ifdef ENGLISH
	.string "I'm {STR_VAR_1}, and I'm proud to say\n"
	.string "that I am a POKéFAN.$"
	.else
	.ifdef GERMAN
	.string "Ich bin {STR_VAR_1} und kann mit Stolz\n"
	.string "behaupten, dass ich ein POKéFAN bin!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.ifdef ENGLISH
	.string "The darling POKéMON I've raised are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Meine geliebten POKéMON:\n"
	.string "{STR_VAR_2}, das {STR_VAR_1} kann,$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Aren't they just the cutest?\n"
	.string "We ought to make a team!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann.\p"
	.string "Sind sie nicht allerliebst? Komm! Wir\n"
	.string "müssen einfach ein Team bilden!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.ifdef ENGLISH
	.string "Thank you, dear!\n"
	.string "I'll be on my way to register!$"
	.else
	.ifdef GERMAN
	.string "Vielen Dank!\n"
	.string "Ich melde uns sofort an!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.ifdef ENGLISH
	.string "My darling POKéMON are the best,\n"
	.string "I'll have you know. How annoying!$"
	.else
	.ifdef GERMAN
	.string "Weißt du, meine geliebten POKéMON sind\n"
	.string "die Besten. Wie ärgerlich…$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.ifdef ENGLISH
	.string "Hi, I'm SWIMMER {STR_VAR_1}.$"
	.else
	.ifdef GERMAN
	.string "Hi, ich bin SCHWIMMERIN {STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.ifdef ENGLISH
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"
	.else
	.ifdef GERMAN
	.string "Ein {STR_VAR_2}, das {STR_VAR_1} kann,\n"
	.string "und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.ifdef ENGLISH
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2} are what I've trained.\p"
	.string "You and me, let's make a tag team.$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann.\n"
	.string "Damit lässt es sich gut trainieren!\p"
	.string "Wir beide sollten ein Team bilden!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.ifdef ENGLISH
	.string "That's cool!\n"
	.string "I'll register the two of us.$"
	.else
	.ifdef GERMAN
	.string "Cool!\n"
	.string "Ich werde uns registrieren.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.ifdef ENGLISH
	.string "If we meet again, you owe me\n"
	.string "a tag team!$"
	.else
	.ifdef GERMAN
	.string "Für das nächste Mal schuldest du mir\n"
	.string "einen Teamkampf!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.ifdef ENGLISH
	.string "What's happening?\n"
	.string "I'm {STR_VAR_1}, and I'm a TRIATHLETE.$"
	.else
	.ifdef GERMAN
	.string "Was geht ab?\n"
	.string "Ich bin TRIATHLET {STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.ifdef ENGLISH
	.string "I got a couple decent POKéMON.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Ich habe ein paar ganz anständige\n"
	.string "PKMN. Ein {STR_VAR_2}, das {STR_VAR_1}$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "It'd be neat if we made a tag team\n"
	.string "together, so how about it?$"
	.else
	.ifdef GERMAN
	.string "kann, und ein {STR_VAR_2},\n"
	.string "das {STR_VAR_1} kann.\p"
	.string "Und du und ich würden auch ein ganz\n"
	.string "anständiges Team abgeben. Oder?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.ifdef ENGLISH
	.string "Right on!\n"
	.string "You wait while I register, okay?$"
	.else
	.ifdef GERMAN
	.string "Wunderbar!\n"
	.string "Warte, ich melde uns eben an.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.ifdef ENGLISH
	.string "I expect you'll let me join you\n"
	.string "next time, how's that?$"
	.else
	.ifdef GERMAN
	.string "Nächstes Mal erwarte ich, dass wir ein \n"
	.string "Team werden. Vergiss das nicht.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.ifdef ENGLISH
	.string "I'm the TRIATHLETE {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Ich bin TRIATHLET {STR_VAR_1}.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.ifdef ENGLISH
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Ein {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann, und ein$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.ifdef ENGLISH
	.string "another {STR_VAR_2} that knows how\n"
	.string "to use {STR_VAR_1}. That's my pair.\p"
	.string "What do you think?\n"
	.string "We'd make a good team, I'd say.$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1} kann. So\n"
	.string "sieht mein Paar aus.\p"
	.string "Was meinst du? Ich würde sagen, wir\n"
	.string "würden ein gutes Team abgeben.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.ifdef ENGLISH
	.string "I like that answer!\n"
	.string "I'll get done with registration fast!$"
	.else
	.ifdef GERMAN
	.string "Das wollte ich hören!\n"
	.string "Ich melde uns schnell an.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.ifdef ENGLISH
	.string "You'll give me another chance to form\n"
	.string "a partnership, won't you?$"
	.else
	.ifdef GERMAN
	.string "Du gibst mir aber nochmal die Chance,\n"
	.string "mit dir ein Team zu bilden, oder?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.ifdef ENGLISH
	.string "Hi, there! Hello!\n"
	.string "I'm {STR_VAR_1}, and I'm a SWIMMER!$"
	.else
	.ifdef GERMAN
	.string "Hallo! Ich bin {STR_VAR_1},\n"
	.string "ein SCHWIMMER.$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.ifdef ENGLISH
	.string "Check out what I've been raising!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
	.else
	.ifdef GERMAN
	.string "Schau dir mal diese Prachtexemplare an!\n"
	.string "Ein {STR_VAR_2}, das {STR_VAR_1} kann,$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.ifdef ENGLISH
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Sweet, huh?\n"
	.string "It'd be sweet to form a team, too!$"
	.else
	.ifdef GERMAN
	.string "und ein {STR_VAR_2}, das {STR_VAR_1}\n"
	.string "kann!\p"
	.string "Niedlich, was? Und beeindruckend?\n"
	.string "Bildest du mit uns ein perfektes Team?$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.ifdef ENGLISH
	.string "Much obliged!\n"
	.string "I'll get this registration thing done!$"
	.else
	.ifdef GERMAN
	.string "Fantastisch!\n"
	.string "Ich registriere uns!$"
	.endif
	.endif

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.ifdef ENGLISH
	.string "If we meet again, you have to team up\n"
	.string "with me. You'll do that, right?$"
	.else
	.ifdef GERMAN
	.string "Nächstes Mal, wenn wir uns treffen,\n"
	.string "müssen wir aber ein Team bilden!!!$"
	.endif
	.endif

