BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle::
	trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_PHILLIP, 0, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.ifdef ENGLISH
	.string "This is a sample message.$"
	.else
	.ifdef GERMAN
	.string "Dies ist ein Beispiel.$"
	.endif
	.endif

gText_BattlePyramidConfirmRest::
	.ifdef ENGLISH
	.string "Your BATTLE PYRAMID quest will be\n"
	.string "saved so that you may quit for now.\l"
	.string "Is that okay?$"
	.else
	.ifdef GERMAN
	.string "Dein Abenteuer in der KAMPFPYRAMIDE\n"
	.string "wird gespeichert, damit du es\l"
	.string "unterbrechen kannst. Einverstanden?$"
	.endif
	.endif

gText_BattlePyramidConfirmRetire::
	.ifdef ENGLISH
	.string "Are you sure you want to quit your\n"
	.string "PYRAMID quest?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du das Abenteuer in der\n"
	.string "KAMPFPYRAMIDE wirklich unterbrechen?$"
	.endif
	.endif

BattlePyramid_Text_ExitHintUp1::
	.ifdef ENGLISH
	.string "This floor's exit is in\n"
	.string "that direction: {UP_ARROW}$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang dieser Ebene\n"
	.string "befindet sich: {UP_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintLeft1::
	.ifdef ENGLISH
	.string "This floor's exit is in\n"
	.string "that direction: {LEFT_ARROW}$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang dieser Ebene\n"
	.string "befindet sich: {LEFT_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintRight1::
	.ifdef ENGLISH
	.string "This floor's exit is in\n"
	.string "that direction: {RIGHT_ARROW}$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang dieser Ebene\n"
	.string "befindet sich: {RIGHT_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintDown1::
	.ifdef ENGLISH
	.string "This floor's exit is in\n"
	.string "that direction: {DOWN_ARROW}$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang dieser Ebene\n"
	.string "befindet sich: {DOWN_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintUp2::
	.ifdef ENGLISH
	.string "The exit on this floor is in\n"
	.string "the {UP_ARROW} direction.$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang dieser Ebene\n"
	.string "befindet sich: {UP_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintLeft2::
	.ifdef ENGLISH
	.string "The exit on this floor is in\n"
	.string "the {LEFT_ARROW} direction.$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang dieser Ebene\n"
	.string "befindet sich: {LEFT_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintRight2::
	.ifdef ENGLISH
	.string "The exit on this floor is in\n"
	.string "the {RIGHT_ARROW} direction.$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang dieser Ebene\n"
	.string "befindet sich: {RIGHT_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintDown2::
	.ifdef ENGLISH
	.string "The exit on this floor is in\n"
	.string "the {DOWN_ARROW} direction.$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang dieser Ebene\n"
	.string "befindet sich: {DOWN_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintUp3::
	.ifdef ENGLISH
	.string "The exit is over\n"
	.string "that {UP_ARROW} way.$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang befindet sich\n"
	.string "in dieser Richtung: {UP_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintLeft3::
	.ifdef ENGLISH
	.string "The exit is over\n"
	.string "that {LEFT_ARROW} way.$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang befindet sich\n"
	.string "in dieser Richtung: {LEFT_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintRight3::
	.ifdef ENGLISH
	.string "The exit is over\n"
	.string "that {RIGHT_ARROW} way.$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang befindet sich\n"
	.string "in dieser Richtung: {RIGHT_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintDown3::
	.ifdef ENGLISH
	.string "The exit is over\n"
	.string "that {DOWN_ARROW} way.$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang befindet sich\n"
	.string "in dieser Richtung: {DOWN_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintUp4::
	.ifdef ENGLISH
	.string "On this floor, the exit is somewhere\n"
	.string "in the {UP_ARROW} direction.$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang befindet sich irgendwo\n"
	.string "in dieser Richtung: {UP_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintLeft4::
	.ifdef ENGLISH
	.string "On this floor, the exit is somewhere\n"
	.string "in the {LEFT_ARROW} direction.$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang befindet sich irgendwo\n"
	.string "in dieser Richtung: {LEFT_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintRight4::
	.ifdef ENGLISH
	.string "On this floor, the exit is somewhere\n"
	.string "in the {RIGHT_ARROW} direction.$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang befindet sich irgendwo\n"
	.string "in dieser Richtung: {RIGHT_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintDown4::
	.ifdef ENGLISH
	.string "On this floor, the exit is somewhere\n"
	.string "in the {DOWN_ARROW} direction.$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang befindet sich irgendwo\n"
	.string "in dieser Richtung: {DOWN_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintUp5::
	.ifdef ENGLISH
	.string "The exit?\n"
	.string "It's that {UP_ARROW} way.$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang?\n"
	.string "Da entlang: {UP_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintLeft5::
	.ifdef ENGLISH
	.string "The exit?\n"
	.string "It's that {LEFT_ARROW} way.$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang?\n"
	.string "Da entlang: {LEFT_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintRight5::
	.ifdef ENGLISH
	.string "The exit?\n"
	.string "It's that {RIGHT_ARROW} way.$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang?\n"
	.string "Da entlang: {RIGHT_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintDown5::
	.ifdef ENGLISH
	.string "The exit?\n"
	.string "It's that {DOWN_ARROW} way.$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang?\n"
	.string "Da entlang: {DOWN_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintUp6::
	.ifdef ENGLISH
	.string "The exit happens to be in\n"
	.string "the {UP_ARROW} direction.$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang befindet sich\n"
	.string "dort drüben: {UP_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintLeft6::
	.ifdef ENGLISH
	.string "The exit happens to be in\n"
	.string "the {LEFT_ARROW} direction.$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang befindet sich\n"
	.string "dort drüben: {LEFT_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintRight6::
	.ifdef ENGLISH
	.string "The exit happens to be in\n"
	.string "the {RIGHT_ARROW} direction.$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang befindet sich\n"
	.string "dort drüben: {RIGHT_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_ExitHintDown6::
	.ifdef ENGLISH
	.string "The exit happens to be in\n"
	.string "the {DOWN_ARROW} direction.$"
	.else
	.ifdef GERMAN
	.string "Der Ausgang befindet sich\n"
	.string "dort drüben: {DOWN_ARROW}$"
	.endif
	.endif

BattlePyramid_Text_EightItemsRemaining1::
	.ifdef ENGLISH
	.string "Are you looking for items?\p"
	.string "There are eight items left to\n"
	.string "be found.$"
	.else
	.ifdef GERMAN
	.string "Suchst du nach Items?\p"
	.string "Hier sind noch acht Items versteckt.$"
	.endif
	.endif

BattlePyramid_Text_SevenItemsRemaining1::
	.ifdef ENGLISH
	.string "Are you looking for items?\p"
	.string "There are seven items left to\n"
	.string "be found.$"
	.else
	.ifdef GERMAN
	.string "Suchst du nach Items?\p"
	.string "Hier sind noch sieben Items\n"
	.string "versteckt.$"
	.endif
	.endif

BattlePyramid_Text_SixItemsRemaining1::
	.ifdef ENGLISH
	.string "Are you looking for items?\p"
	.string "There are six items left to\n"
	.string "be found.$"
	.else
	.ifdef GERMAN
	.string "Suchst du nach Items?\p"
	.string "Hier sind noch sechs Items\n"
	.string "versteckt.$"
	.endif
	.endif

BattlePyramid_Text_FiveItemsRemaining1::
	.ifdef ENGLISH
	.string "Are you looking for items?\p"
	.string "There are five items left to\n"
	.string "be found.$"
	.else
	.ifdef GERMAN
	.string "Suchst du nach Items?\p"
	.string "Hier sind noch fünf Items\n"
	.string "versteckt.$"
	.endif
	.endif

BattlePyramid_Text_FourItemsRemaining1::
	.ifdef ENGLISH
	.string "Are you looking for items?\p"
	.string "There are four items left to\n"
	.string "be found.$"
	.else
	.ifdef GERMAN
	.string "Suchst du nach Items?\p"
	.string "Hier sind noch vier Items\n"
	.string "versteckt.$"
	.endif
	.endif

BattlePyramid_Text_ThreeItemsRemaining1::
	.ifdef ENGLISH
	.string "Are you looking for items?\p"
	.string "There are three items left to\n"
	.string "be found.$"
	.else
	.ifdef GERMAN
	.string "Suchst du nach Items?\p"
	.string "Hier sind noch drei Items\n"
	.string "versteckt.$"
	.endif
	.endif

BattlePyramid_Text_TwoItemsRemaining1::
	.ifdef ENGLISH
	.string "Are you looking for items?\p"
	.string "There are two items left to\n"
	.string "be found.$"
	.else
	.ifdef GERMAN
	.string "Suchst du nach Items?\p"
	.string "Hier sind noch zwei Items\n"
	.string "versteckt.$"
	.endif
	.endif

BattlePyramid_Text_OneItemRemaining1::
	.ifdef ENGLISH
	.string "Are you looking for items?\p"
	.string "There is one item left to\n"
	.string "be found.$"
	.else
	.ifdef GERMAN
	.string "Suchst du nach Items?\p"
	.string "Hier ist noch ein Item\n"
	.string "versteckt.$"
	.endif
	.endif

BattlePyramid_Text_ZeroItemsRemaining1::
	.ifdef ENGLISH
	.string "Are you looking for items?\p"
	.string "There isn't anything left to\n"
	.string "be found!$"
	.else
	.ifdef GERMAN
	.string "Suchst du nach Items?\p"
	.string "Hier gibt es keine mehr.$"
	.endif
	.endif

BattlePyramid_Text_EightItemsRemaining2::
	.ifdef ENGLISH
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are eight items\n"
	.string "lying around here.$"
	.else
	.ifdef GERMAN
	.string "Du hast gewonnen, daher verrate ich\n"
	.string "dir ein Geheimnis!\p"
	.string "Hier sind irgendwo acht Items\n"
	.string "versteckt.$"
	.endif
	.endif

BattlePyramid_Text_SevenItemsRemaining2::
	.ifdef ENGLISH
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are seven items left\n"
	.string "lying around here.$"
	.else
	.ifdef GERMAN
	.string "Du hast gewonnen, daher verrate ich\n"
	.string "dir ein Geheimnis!\p"
	.string "Hier sind irgendwo sieben Items\n"
	.string "versteckt.$"
	.endif
	.endif

BattlePyramid_Text_SixItemsRemaining2::
	.ifdef ENGLISH
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are six items left\n"
	.string "lying around here.$"
	.else
	.ifdef GERMAN
	.string "Du hast gewonnen, daher verrate ich\n"
	.string "dir ein Geheimnis!\p"
	.string "Hier sind irgendwo sechs Items\n"
	.string "versteckt.$"
	.endif
	.endif

BattlePyramid_Text_FiveItemsRemaining2::
	.ifdef ENGLISH
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are five items left\n"
	.string "lying around here.$"
	.else
	.ifdef GERMAN
	.string "Du hast gewonnen, daher verrate ich\n"
	.string "dir ein Geheimnis!\p"
	.string "Hier sind irgendwo fünf Items\n"
	.string "versteckt.$"
	.endif
	.endif

BattlePyramid_Text_FourItemsRemaining2::
	.ifdef ENGLISH
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are four items left\n"
	.string "lying around here.$"
	.else
	.ifdef GERMAN
	.string "Du hast gewonnen, daher verrate ich\n"
	.string "dir ein Geheimnis!\p"
	.string "Hier sind irgendwo vier Items\n"
	.string "versteckt.$"
	.endif
	.endif

BattlePyramid_Text_ThreeItemsRemaining2::
	.ifdef ENGLISH
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are three items left\n"
	.string "lying around here.$"
	.else
	.ifdef GERMAN
	.string "Du hast gewonnen, daher verrate ich\n"
	.string "dir ein Geheimnis!\p"
	.string "Hier sind irgendwo drei Items\n"
	.string "versteckt.$"
	.endif
	.endif

BattlePyramid_Text_TwoItemsRemaining2::
	.ifdef ENGLISH
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are two items left\n"
	.string "lying around here.$"
	.else
	.ifdef GERMAN
	.string "Du hast gewonnen, daher verrate ich\n"
	.string "dir ein Geheimnis!\p"
	.string "Hier sind irgendwo zwei Items\n"
	.string "versteckt.$"
	.endif
	.endif

BattlePyramid_Text_OneItemRemaining2::
	.ifdef ENGLISH
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There is just one item\n"
	.string "lying around here.$"
	.else
	.ifdef GERMAN
	.string "Du hast gewonnen, daher verrate ich\n"
	.string "dir ein Geheimnis!\p"
	.string "Hier ist irgendwo ein Item\n"
	.string "versteckt.$"
	.endif
	.endif

BattlePyramid_Text_ZeroItemsRemaining2::
	.ifdef ENGLISH
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There isn't anything left\n"
	.string "lying around here.$"
	.else
	.ifdef GERMAN
	.string "Du hast gewonnen, daher verrate ich\n"
	.string "dir ein Geheimnis!\p"
	.string "Hier sind keine Items mehr versteckt.$"
	.endif
	.endif

BattlePyramid_Text_EightItemsRemaining3::
	.ifdef ENGLISH
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are eight items left\n"
	.string "waiting to be found on this floor.$"
	.else
	.ifdef GERMAN
	.string "Wie macht sich deine Item-Sammlung?\p"
	.string "Ich verrate dir was: Auf dieser Ebene\n"
	.string "sind acht Items versteckt.$"
	.endif
	.endif

BattlePyramid_Text_SevenItemsRemaining3::
	.ifdef ENGLISH
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are seven items left\n"
	.string "waiting to be found on this floor.$"
	.else
	.ifdef GERMAN
	.string "Wie macht sich deine Item-Sammlung?\p"
	.string "Ich verrate dir was: Auf dieser Ebene\n"
	.string "sind sieben Items versteckt.$"
	.endif
	.endif

BattlePyramid_Text_SixItemsRemaining3::
	.ifdef ENGLISH
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are six items left\n"
	.string "waiting to be found on this floor.$"
	.else
	.ifdef GERMAN
	.string "Wie macht sich deine Item-Sammlung?\p"
	.string "Ich verrate dir was: Auf dieser Ebene\n"
	.string "sind sechs Items versteckt.$"
	.endif
	.endif

BattlePyramid_Text_FiveItemsRemaining3::
	.ifdef ENGLISH
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are five items left\n"
	.string "waiting to be found on this floor.$"
	.else
	.ifdef GERMAN
	.string "Wie macht sich deine Item-Sammlung?\p"
	.string "Ich verrate dir was: Auf dieser Ebene\n"
	.string "sind fünf Items versteckt.$"
	.endif
	.endif

BattlePyramid_Text_FourItemsRemaining3::
	.ifdef ENGLISH
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are four items left\n"
	.string "waiting to be found on this floor.$"
	.else
	.ifdef GERMAN
	.string "Wie macht sich deine Item-Sammlung?\p"
	.string "Ich verrate dir was: Auf dieser Ebene\n"
	.string "sind vier Items versteckt.$"
	.endif
	.endif

BattlePyramid_Text_ThreeItemsRemaining3::
	.ifdef ENGLISH
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are three items left\n"
	.string "waiting to be found on this floor.$"
	.else
	.ifdef GERMAN
	.string "Wie macht sich deine Item-Sammlung?\p"
	.string "Ich verrate dir was: Auf dieser Ebene\n"
	.string "sind drei Items versteckt.$"
	.endif
	.endif

BattlePyramid_Text_TwoItemsRemaining3::
	.ifdef ENGLISH
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are two items left\n"
	.string "waiting to be found on this floor.$"
	.else
	.ifdef GERMAN
	.string "Wie macht sich deine Item-Sammlung?\p"
	.string "Ich verrate dir was: Auf dieser Ebene\n"
	.string "sind zwei Items versteckt.$"
	.endif
	.endif

BattlePyramid_Text_OneItemRemaining3::
	.ifdef ENGLISH
	.string "How's your stock of items holding up?\p"
	.string "I reckon there's but one item left\n"
	.string "waiting to be found on this floor.$"
	.else
	.ifdef GERMAN
	.string "Wie macht sich deine Item-Sammlung?\p"
	.string "Ich verrate dir was: Auf dieser Ebene\n"
	.string "ist ein Item versteckt.$"
	.endif
	.endif

BattlePyramid_Text_ZeroItemsRemaining3::
	.ifdef ENGLISH
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are no more items\n"
	.string "waiting to be found on this floor.\l"
	.string "You take care now!$"
	.else
	.ifdef GERMAN
	.string "Wie macht sich deine Item-Sammlung?\p"
	.string "Auf dieser Ebene gibt es keine Items\n"
	.string "mehr. Pass auf dich auf!$"
	.endif
	.endif

BattlePyramid_Text_EightItemsRemaining4::
	.ifdef ENGLISH
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be eight more\n"
	.string "items on the ground.$"
	.else
	.ifdef GERMAN
	.string "Deine Stärke muss belohnt werden!\p"
	.string "Hier scheinen acht Items versteckt\n"
	.string "zu sein.$"
	.endif
	.endif

BattlePyramid_Text_SevenItemsRemaining4::
	.ifdef ENGLISH
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be seven more\n"
	.string "items on the ground.$"
	.else
	.ifdef GERMAN
	.string "Deine Stärke muss belohnt werden!\p"
	.string "Hier scheinen sieben Items versteckt\n"
	.string "zu sein.$"
	.endif
	.endif

BattlePyramid_Text_SixItemsRemaining4::
	.ifdef ENGLISH
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be six more\n"
	.string "items on the ground.$"
	.else
	.ifdef GERMAN
	.string "Deine Stärke muss belohnt werden!\p"
	.string "Hier scheinen sechs Items versteckt\n"
	.string "zu sein.$"
	.endif
	.endif

BattlePyramid_Text_FiveItemsRemaining4::
	.ifdef ENGLISH
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be five more\n"
	.string "items on the ground.$"
	.else
	.ifdef GERMAN
	.string "Deine Stärke muss belohnt werden!\p"
	.string "Hier scheinen fünf Items versteckt\n"
	.string "zu sein.$"
	.endif
	.endif

BattlePyramid_Text_FourItemsRemaining4::
	.ifdef ENGLISH
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be four more\n"
	.string "items on the ground.$"
	.else
	.ifdef GERMAN
	.string "Deine Stärke muss belohnt werden!\p"
	.string "Hier scheinen vier Items versteckt\n"
	.string "zu sein.$"
	.endif
	.endif

BattlePyramid_Text_ThreeItemsRemaining4::
	.ifdef ENGLISH
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be three more\n"
	.string "items on the ground.$"
	.else
	.ifdef GERMAN
	.string "Deine Stärke muss belohnt werden!\p"
	.string "Hier scheinen drei Items versteckt\n"
	.string "zu sein.$"
	.endif
	.endif

BattlePyramid_Text_TwoItemsRemaining4::
	.ifdef ENGLISH
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be two more\n"
	.string "items on the ground.$"
	.else
	.ifdef GERMAN
	.string "Deine Stärke muss belohnt werden!\p"
	.string "Hier scheinen zwei Items versteckt\n"
	.string "zu sein.$"
	.endif
	.endif

BattlePyramid_Text_OneItemRemaining4::
	.ifdef ENGLISH
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appears to be only one more\n"
	.string "item on the ground.$"
	.else
	.ifdef GERMAN
	.string "Deine Stärke muss belohnt werden!\p"
	.string "Hier scheint ein Item versteckt\n"
	.string "zu sein.$"
	.endif
	.endif

BattlePyramid_Text_ZeroItemsRemaining4::
	.ifdef ENGLISH
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be no more\n"
	.string "items on the ground.$"
	.else
	.ifdef GERMAN
	.string "Deine Stärke muss belohnt werden!\p"
	.string "Aber leider scheinen hier keine\n"
	.string "Items mehr versteckt zu sein.$"
	.endif
	.endif

BattlePyramid_Text_EightItemsRemaining5::
	.ifdef ENGLISH
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are eight items…$"
	.else
	.ifdef GERMAN
	.string "Auf dieser Ebene der PYRAMIDE\n"
	.string "sollen… acht Items liegen.$"
	.endif
	.endif

BattlePyramid_Text_SevenItemsRemaining5::
	.ifdef ENGLISH
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are seven items…$"
	.else
	.ifdef GERMAN
	.string "Auf dieser Ebene der PYRAMIDE\n"
	.string "sollen… sieben Items liegen.$"
	.endif
	.endif

BattlePyramid_Text_SixItemsRemaining5::
	.ifdef ENGLISH
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are six items…$"
	.else
	.ifdef GERMAN
	.string "Auf dieser Ebene der PYRAMIDE\n"
	.string "sollen… sechs Items liegen.$"
	.endif
	.endif

BattlePyramid_Text_FiveItemsRemaining5::
	.ifdef ENGLISH
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are five items…$"
	.else
	.ifdef GERMAN
	.string "Auf dieser Ebene der PYRAMIDE\n"
	.string "sollen… fünf Items liegen.$"
	.endif
	.endif

BattlePyramid_Text_FourItemsRemaining5::
	.ifdef ENGLISH
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are four items…$"
	.else
	.ifdef GERMAN
	.string "Auf dieser Ebene der PYRAMIDE\n"
	.string "sollen… vier Items liegen.$"
	.endif
	.endif

BattlePyramid_Text_ThreeItemsRemaining5::
	.ifdef ENGLISH
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are three items…$"
	.else
	.ifdef GERMAN
	.string "Auf dieser Ebene der PYRAMIDE\n"
	.string "sollen… drei Items liegen.$"
	.endif
	.endif

BattlePyramid_Text_TwoItemsRemaining5::
	.ifdef ENGLISH
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are two items…$"
	.else
	.ifdef GERMAN
	.string "Auf dieser Ebene der PYRAMIDE\n"
	.string "sollen… zwei Items liegen.$"
	.endif
	.endif

BattlePyramid_Text_OneItemRemaining5::
	.ifdef ENGLISH
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there is one item…$"
	.else
	.ifdef GERMAN
	.string "Auf dieser Ebene der PYRAMIDE\n"
	.string "soll… ein Item liegen.$"
	.endif
	.endif

BattlePyramid_Text_ZeroItemsRemaining5::
	.ifdef ENGLISH
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are no items…$"
	.else
	.ifdef GERMAN
	.string "Auf dieser Ebene der PYRAMIDE\n"
	.string "soll es keine Items geben…$"
	.endif
	.endif

BattlePyramid_Text_EightItemsRemaining6::
	.ifdef ENGLISH
	.string "Have you collected any items?\p"
	.string "I believe there are eight more\n"
	.string "items on this floor.$"
	.else
	.ifdef GERMAN
	.string "Hast du schon alle Items gefunden?\p"
	.string "Ich glaube, hier müssten noch acht\n"
	.string "weitere Items versteckt sein.$"
	.endif
	.endif

BattlePyramid_Text_SevenItemsRemaining6::
	.ifdef ENGLISH
	.string "Have you collected any items?\p"
	.string "I believe there are seven more\n"
	.string "items on this floor.$"
	.else
	.ifdef GERMAN
	.string "Hast du schon alle Items gefunden?\p"
	.string "Ich glaube, hier müssten noch sieben\n"
	.string "weitere Items versteckt sein.$"
	.endif
	.endif

BattlePyramid_Text_SixItemsRemaining6::
	.ifdef ENGLISH
	.string "Have you collected any items?\p"
	.string "I believe there are six more\n"
	.string "items on this floor.$"
	.else
	.ifdef GERMAN
	.string "Hast du schon alle Items gefunden?\p"
	.string "Ich glaube, hier müssten noch sechs\n"
	.string "weitere Items versteckt sein.$"
	.endif
	.endif

BattlePyramid_Text_FiveItemsRemaining6::
	.ifdef ENGLISH
	.string "Have you collected any items?\p"
	.string "I believe there are five more\n"
	.string "items on this floor.$"
	.else
	.ifdef GERMAN
	.string "Hast du schon alle Items gefunden?\p"
	.string "Ich glaube, hier müssten noch fünf\n"
	.string "weitere Items versteckt sein.$"
	.endif
	.endif

BattlePyramid_Text_FourItemsRemaining6::
	.ifdef ENGLISH
	.string "Have you collected any items?\p"
	.string "I believe there are four more\n"
	.string "items on this floor.$"
	.else
	.ifdef GERMAN
	.string "Hast du schon alle Items gefunden?\p"
	.string "Ich glaube, hier müssten noch vier\n"
	.string "weitere Items versteckt sein.$"
	.endif
	.endif

BattlePyramid_Text_ThreeItemsRemaining6::
	.ifdef ENGLISH
	.string "Have you collected any items?\p"
	.string "I believe there are three more\n"
	.string "items on this floor.$"
	.else
	.ifdef GERMAN
	.string "Hast du schon alle Items gefunden?\p"
	.string "Ich glaube, hier müssten noch drei\n"
	.string "weitere Items versteckt sein.$"
	.endif
	.endif

BattlePyramid_Text_TwoItemsRemaining6::
	.ifdef ENGLISH
	.string "Have you collected any items?\p"
	.string "I believe there are two more\n"
	.string "items on this floor.$"
	.else
	.ifdef GERMAN
	.string "Hast du schon alle Items gefunden?\p"
	.string "Ich glaube, hier müssten noch zwei\n"
	.string "weitere Items versteckt sein.$"
	.endif
	.endif

BattlePyramid_Text_OneItemRemaining6::
	.ifdef ENGLISH
	.string "Have you collected any items?\p"
	.string "I believe there is one more\n"
	.string "item on this floor.$"
	.else
	.ifdef GERMAN
	.string "Hast du schon alle Items gefunden?\p"
	.string "Ich glaube, hier müsste noch ein\n"
	.string "weiteres Item versteckt sein.$"
	.endif
	.endif

BattlePyramid_Text_ZeroItemsRemaining6::
	.ifdef ENGLISH
	.string "Have you collected any items?\p"
	.string "I believe there are no more\n"
	.string "items on this floor.$"
	.else
	.ifdef GERMAN
	.string "Hast du schon alle Items gefunden?\p"
	.string "Ich glaube, hier gibt es keine Items\n"
	.string "mehr.$"
	.endif
	.endif

BattlePyramid_Text_SevenTrainersRemaining1::
	.ifdef ENGLISH
	.string "You were really awesome!\p"
	.string "But there are still seven tough\n"
	.string "TRAINERS other than me!$"
	.else
	.ifdef GERMAN
	.string "Du warst wirklich unglaublich gut!\p"
	.string "Aber es warten noch sieben\n"
	.string "weitere starke TRAINER auf dich!$"
	.endif
	.endif

BattlePyramid_Text_SixTrainersRemaining1::
	.ifdef ENGLISH
	.string "You were really awesome!\p"
	.string "But there are still six tough\n"
	.string "TRAINERS other than me!$"
	.else
	.ifdef GERMAN
	.string "Du warst wirklich unglaublich gut!\p"
	.string "Aber es warten noch sechs\n"
	.string "weitere starke TRAINER auf dich!$"
	.endif
	.endif

BattlePyramid_Text_FiveTrainersRemaining1::
	.ifdef ENGLISH
	.string "You were really awesome!\p"
	.string "But there are still five tough\n"
	.string "TRAINERS other than me!$"
	.else
	.ifdef GERMAN
	.string "Du warst wirklich unglaublich gut!\p"
	.string "Aber es warten noch fünf\n"
	.string "weitere starke TRAINER auf dich!$"
	.endif
	.endif

BattlePyramid_Text_FourTrainersRemaining1::
	.ifdef ENGLISH
	.string "You were really awesome!\p"
	.string "But there are still four tough\n"
	.string "TRAINERS other than me!$"
	.else
	.ifdef GERMAN
	.string "Du warst wirklich unglaublich gut!\p"
	.string "Aber es warten noch vier\n"
	.string "weitere starke TRAINER auf dich!$"
	.endif
	.endif

BattlePyramid_Text_ThreeTrainersRemaining1::
	.ifdef ENGLISH
	.string "You were really awesome!\p"
	.string "But there are still three tough\n"
	.string "TRAINERS other than me!$"
	.else
	.ifdef GERMAN
	.string "Du warst wirklich unglaublich gut!\p"
	.string "Aber es warten noch drei\n"
	.string "weitere starke TRAINER auf dich!$"
	.endif
	.endif

BattlePyramid_Text_TwoTrainersRemaining1::
	.ifdef ENGLISH
	.string "You were really awesome!\p"
	.string "But there are still two tough\n"
	.string "TRAINERS other than me!$"
	.else
	.ifdef GERMAN
	.string "Du warst wirklich unglaublich gut!\p"
	.string "Aber es warten noch zwei\n"
	.string "weitere starke TRAINER auf dich!$"
	.endif
	.endif

BattlePyramid_Text_OneTrainersRemaining1::
	.ifdef ENGLISH
	.string "You were really awesome!\p"
	.string "But there's still one tough\n"
	.string "TRAINER other than me!$"
	.else
	.ifdef GERMAN
	.string "Du warst wirklich unglaublich gut!\p"
	.string "Aber es wartet noch ein\n"
	.string "weiterer starker TRAINER auf dich!$"
	.endif
	.endif

BattlePyramid_Text_ZeroTrainersRemaining1::
	.ifdef ENGLISH
	.string "You were really awesome!\p"
	.string "There's no one left that\n"
	.string "can beat you!$"
	.else
	.ifdef GERMAN
	.string "Du warst wirklich unglaublich gut!\p"
	.string "Aber es ist niemand mehr da, den\n"
	.string "du besiegen könntest.$"
	.endif
	.endif

BattlePyramid_Text_SevenTrainersRemaining2::
	.ifdef ENGLISH
	.string "This is so upsetting!\p"
	.string "But there are seven TRAINERS left!\n"
	.string "Someone will humble you!$"
	.else
	.ifdef GERMAN
	.string "Das ist doch einfach ärgerlich!\p"
	.string "Aber es gibt hier noch sieben weitere\n"
	.string "TRAINER. Einer wird dich zu Fall bringen!$"
	.endif
	.endif

BattlePyramid_Text_SixTrainersRemaining2::
	.ifdef ENGLISH
	.string "This is so upsetting!\p"
	.string "But there are six TRAINERS left!\n"
	.string "Someone will humble you!$"
	.else
	.ifdef GERMAN
	.string "Das ist doch einfach ärgerlich!\p"
	.string "Aber es gibt hier noch sechs weitere\n"
	.string "TRAINER. Einer wird dich zu Fall bringen!$"
	.endif
	.endif

BattlePyramid_Text_FiveTrainersRemaining2::
	.ifdef ENGLISH
	.string "This is so upsetting!\p"
	.string "But there are five TRAINERS left!\n"
	.string "Someone will humble you!$"
	.else
	.ifdef GERMAN
	.string "Das ist doch einfach ärgerlich!\p"
	.string "Aber es gibt hier noch fünf weitere\n"
	.string "TRAINER. Einer wird dich zu Fall bringen!$"
	.endif
	.endif

BattlePyramid_Text_FourTrainersRemaining2::
	.ifdef ENGLISH
	.string "This is so upsetting!\p"
	.string "But there are four TRAINERS left!\n"
	.string "Someone will humble you!$"
	.else
	.ifdef GERMAN
	.string "Das ist doch einfach ärgerlich!\p"
	.string "Aber es gibt hier noch vier weitere\n"
	.string "TRAINER. Einer wird dich zu Fall bringen!$"
	.endif
	.endif

BattlePyramid_Text_ThreeTrainersRemaining2::
	.ifdef ENGLISH
	.string "This is so upsetting!\p"
	.string "But there are three TRAINERS left!\n"
	.string "Someone will humble you!$"
	.else
	.ifdef GERMAN
	.string "Das ist doch einfach ärgerlich!\p"
	.string "Aber es gibt hier noch drei weitere\n"
	.string "TRAINER. Einer wird dich zu Fall bringen!$"
	.endif
	.endif

BattlePyramid_Text_TwoTrainersRemaining2::
	.ifdef ENGLISH
	.string "This is so upsetting!\p"
	.string "But there are two TRAINERS left!\n"
	.string "Someone will humble you!$"
	.else
	.ifdef GERMAN
	.string "Das ist doch einfach ärgerlich!\p"
	.string "Aber es gibt hier noch zwei weitere\n"
	.string "TRAINER. Einer wird dich zu Fall bringen!$"
	.endif
	.endif

BattlePyramid_Text_OneTrainersRemaining2::
	.ifdef ENGLISH
	.string "This is so upsetting!\p"
	.string "But there's one TRAINER left!\n"
	.string "I'm sure you will be humbled!$"
	.else
	.ifdef GERMAN
	.string "Das ist doch einfach ärgerlich!\p"
	.string "Aber es gibt hier noch einen weiteren\n"
	.string "TRAINER. Der wird dich zu Fall bringen!$"
	.endif
	.endif

BattlePyramid_Text_ZeroTrainersRemaining2::
	.ifdef ENGLISH
	.string "This is so upsetting!\p"
	.string "But there are no more TRAINERS\n"
	.string "who can engage you!$"
	.else
	.ifdef GERMAN
	.string "Das ist doch einfach ärgerlich!\p"
	.string "Aber es gibt keine weiteren TRAINER!\n"
	.string "Keiner wird dich zu Fall bringen!$"
	.endif
	.endif

BattlePyramid_Text_SevenTrainersRemaining3::
	.ifdef ENGLISH
	.string "That's pretty impressive!\p"
	.string "But there are seven more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"
	.else
	.ifdef GERMAN
	.string "Wow! Das war beeindruckend!\p"
	.string "Aber hier sind noch sieben weitere\n"
	.string "TRAINER. Kannst du die auch besiegen?$"
	.endif
	.endif

BattlePyramid_Text_SixTrainersRemaining3::
	.ifdef ENGLISH
	.string "That's pretty impressive!\p"
	.string "But there are six more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"
	.else
	.ifdef GERMAN
	.string "Wow! Das war beeindruckend!\p"
	.string "Aber hier sind noch sechs weitere\n"
	.string "TRAINER. Kannst du die auch besiegen?$"
	.endif
	.endif

BattlePyramid_Text_FiveTrainersRemaining3::
	.ifdef ENGLISH
	.string "That's pretty impressive!\p"
	.string "But there are five more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"
	.else
	.ifdef GERMAN
	.string "Wow! Das war beeindruckend!\p"
	.string "Aber hier sind noch fünf weitere\n"
	.string "TRAINER. Kannst du die auch besiegen?$"
	.endif
	.endif

BattlePyramid_Text_FourTrainersRemaining3::
	.ifdef ENGLISH
	.string "That's pretty impressive!\p"
	.string "But there are four more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"
	.else
	.ifdef GERMAN
	.string "Wow! Das war beeindruckend!\p"
	.string "Aber hier sind noch vier weitere\n"
	.string "TRAINER. Kannst du die auch besiegen?$"
	.endif
	.endif

BattlePyramid_Text_ThreeTrainersRemaining3::
	.ifdef ENGLISH
	.string "That's pretty impressive!\p"
	.string "But there are three more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"
	.else
	.ifdef GERMAN
	.string "Wow! Das war beeindruckend!\p"
	.string "Aber hier sind noch drei weitere\n"
	.string "TRAINER. Kannst du die auch besiegen?$"
	.endif
	.endif

BattlePyramid_Text_TwoTrainersRemaining3::
	.ifdef ENGLISH
	.string "That's pretty impressive!\p"
	.string "But there are two more TRAINERS\n"
	.string "on this floor. Can you beat them both?$"
	.else
	.ifdef GERMAN
	.string "Wow! Das war beeindruckend!\p"
	.string "Aber hier sind noch zwei weitere\n"
	.string "TRAINER. Kannst du die auch besiegen?$"
	.endif
	.endif

BattlePyramid_Text_OneTrainersRemaining3::
	.ifdef ENGLISH
	.string "That's pretty impressive!\p"
	.string "But there's still one more TRAINER\n"
	.string "on this floor. Can you prevail?$"
	.else
	.ifdef GERMAN
	.string "Wow! Das war beeindruckend!\p"
	.string "Aber hier ist noch ein weiterer\n"
	.string "TRAINER. Kannst du den auch besiegen?$"
	.endif
	.endif

BattlePyramid_Text_ZeroTrainersRemaining3::
	.ifdef ENGLISH
	.string "That's pretty impressive!\p"
	.string "You've gone through all the TRAINERS\n"
	.string "on this floor.$"
	.else
	.ifdef GERMAN
	.string "Wow! Das war beeindruckend!\p"
	.string "Du hast alle TRAINER auf dieser\n"
	.string "Ebene besiegt.$"
	.endif
	.endif

BattlePyramid_Text_SevenTrainersRemaining4::
	.ifdef ENGLISH
	.string "Maybe you could sweep through\n"
	.string "the seven TRAINERS left on this floor.$"
	.else
	.ifdef GERMAN
	.string "Vielleicht kannst du die sieben TRAINER\n"
	.string "auf dieser Ebene besiegen?$"
	.endif
	.endif

BattlePyramid_Text_SixTrainersRemaining4::
	.ifdef ENGLISH
	.string "Maybe you could sweep through\n"
	.string "the six TRAINERS left on this floor.$"
	.else
	.ifdef GERMAN
	.string "Vielleicht kannst du die sechs TRAINER\n"
	.string "auf dieser Ebene besiegen?$"
	.endif
	.endif

BattlePyramid_Text_FiveTrainersRemaining4::
	.ifdef ENGLISH
	.string "Maybe you could sweep through\n"
	.string "the five TRAINERS left on this floor.$"
	.else
	.ifdef GERMAN
	.string "Vielleicht kannst du die fünf TRAINER\n"
	.string "auf dieser Ebene besiegen?$"
	.endif
	.endif

BattlePyramid_Text_FourTrainersRemaining4::
	.ifdef ENGLISH
	.string "Maybe you could sweep through\n"
	.string "the four TRAINERS left on this floor.$"
	.else
	.ifdef GERMAN
	.string "Vielleicht kannst du die vier TRAINER\n"
	.string "auf dieser Ebene besiegen?$"
	.endif
	.endif

BattlePyramid_Text_ThreeTrainersRemaining4::
	.ifdef ENGLISH
	.string "Maybe you could sweep through\n"
	.string "the three TRAINERS left on this floor.$"
	.else
	.ifdef GERMAN
	.string "Vielleicht kannst du die drei TRAINER\n"
	.string "auf dieser Ebene besiegen?$"
	.endif
	.endif

BattlePyramid_Text_TwoTrainersRemaining4::
	.ifdef ENGLISH
	.string "Maybe you could sweep through\n"
	.string "the two TRAINERS left on this floor.$"
	.else
	.ifdef GERMAN
	.string "Vielleicht kannst du die zwei TRAINER\n"
	.string "auf dieser Ebene besiegen?$"
	.endif
	.endif

BattlePyramid_Text_OneTrainersRemaining4::
	.ifdef ENGLISH
	.string "Maybe you could complete your sweep\n"
	.string "with the one TRAINER left on this floor.$"
	.else
	.ifdef GERMAN
	.string "Vielleicht kannst du den TRAINER\n"
	.string "auf dieser Ebene besiegen?$"
	.endif
	.endif

BattlePyramid_Text_ZeroTrainersRemaining4::
	.ifdef ENGLISH
	.string "There isn't a single person left who\n"
	.string "can defeat you now…$"
	.else
	.ifdef GERMAN
	.string "Auf dieser Ebene ist niemand mehr, den\n"
	.string "du besiegen könntest.$"
	.endif
	.endif

BattlePyramid_Text_SevenTrainersRemaining5::
	.ifdef ENGLISH
	.string "You may have what it takes to beat\n"
	.string "the seven expert TRAINERS who remain.$"
	.else
	.ifdef GERMAN
	.string "Du könntest es tatsächlich schaffen,\n"
	.string "die sieben TRAINER hier zu besiegen.$"
	.endif
	.endif

BattlePyramid_Text_SixTrainersRemaining5::
	.ifdef ENGLISH
	.string "You may have what it takes to beat\n"
	.string "the six expert TRAINERS who remain.$"
	.else
	.ifdef GERMAN
	.string "Du könntest es tatsächlich schaffen,\n"
	.string "die sechs TRAINER hier zu besiegen.$"
	.endif
	.endif

BattlePyramid_Text_FiveTrainersRemaining5::
	.ifdef ENGLISH
	.string "You may have what it takes to beat\n"
	.string "the five expert TRAINERS who remain.$"
	.else
	.ifdef GERMAN
	.string "Du könntest es tatsächlich schaffen,\n"
	.string "die fünf TRAINER hier zu besiegen.$"
	.endif
	.endif

BattlePyramid_Text_FourTrainersRemaining5::
	.ifdef ENGLISH
	.string "You may have what it takes to beat\n"
	.string "the four expert TRAINERS who remain.$"
	.else
	.ifdef GERMAN
	.string "Du könntest es tatsächlich schaffen,\n"
	.string "die vier TRAINER hier zu besiegen.$"
	.endif
	.endif

BattlePyramid_Text_ThreeTrainersRemaining5::
	.ifdef ENGLISH
	.string "You may have what it takes to beat\n"
	.string "the three expert TRAINERS who remain.$"
	.else
	.ifdef GERMAN
	.string "Du könntest es tatsächlich schaffen,\n"
	.string "die drei TRAINER hier zu besiegen.$"
	.endif
	.endif

BattlePyramid_Text_TwoTrainersRemaining5::
	.ifdef ENGLISH
	.string "You may have what it takes to beat\n"
	.string "the two expert TRAINERS who remain.$"
	.else
	.ifdef GERMAN
	.string "Du könntest es tatsächlich schaffen,\n"
	.string "die zwei TRAINER hier zu besiegen.$"
	.endif
	.endif

BattlePyramid_Text_OneTrainersRemaining5::
	.ifdef ENGLISH
	.string "You may have what it takes to beat\n"
	.string "the one expert TRAINER who remains.$"
	.else
	.ifdef GERMAN
	.string "Du könntest es tatsächlich schaffen,\n"
	.string "den TRAINER hier zu besiegen.$"
	.endif
	.endif

BattlePyramid_Text_ZeroTrainersRemaining5::
	.ifdef ENGLISH
	.string "Your skills are beyond reproach.\p"
	.string "There are no more TRAINERS here\n"
	.string "who have any chance of beating you.$"
	.else
	.ifdef GERMAN
	.string "Deine Fähigkeiten sind unerreichbar!\p"
	.string "Es sind keine TRAINER mehr vorhanden,\n"
	.string "gegen die du antreten könntest.$"
	.endif
	.endif

BattlePyramid_Text_SevenTrainersRemaining6::
	.ifdef ENGLISH
	.string "Can you keep winning against\n"
	.string "the seven remaining TRAINERS?$"
	.else
	.ifdef GERMAN
	.string "Schaffst du es, die sieben\n"
	.string "verbleibenden TRAINER zu besiegen?$"
	.endif
	.endif

BattlePyramid_Text_SixTrainersRemaining6::
	.ifdef ENGLISH
	.string "Can you keep winning against\n"
	.string "the six remaining TRAINERS?$"
	.else
	.ifdef GERMAN
	.string "Schaffst du es, die sechs\n"
	.string "verbleibenden TRAINER zu besiegen?$"
	.endif
	.endif

BattlePyramid_Text_FiveTrainersRemaining6::
	.ifdef ENGLISH
	.string "Can you keep winning against\n"
	.string "the five remaining TRAINERS?$"
	.else
	.ifdef GERMAN
	.string "Schaffst du es, die fünf\n"
	.string "verbleibenden TRAINER zu besiegen?$"
	.endif
	.endif

BattlePyramid_Text_FourTrainersRemaining6::
	.ifdef ENGLISH
	.string "Can you keep winning against\n"
	.string "the four remaining TRAINERS?$"
	.else
	.ifdef GERMAN
	.string "Schaffst du es, die vier\n"
	.string "verbleibenden TRAINER zu besiegen?$"
	.endif
	.endif

BattlePyramid_Text_ThreeTrainersRemaining6::
	.ifdef ENGLISH
	.string "Can you keep winning against\n"
	.string "the three remaining TRAINERS?$"
	.else
	.ifdef GERMAN
	.string "Schaffst du es, die drei\n"
	.string "verbleibenden TRAINER zu besiegen?$"
	.endif
	.endif

BattlePyramid_Text_TwoTrainersRemaining6::
	.ifdef ENGLISH
	.string "Can you keep winning against\n"
	.string "the two remaining TRAINERS?$"
	.else
	.ifdef GERMAN
	.string "Schaffst du es, die zwei\n"
	.string "verbleibenden TRAINER zu besiegen?$"
	.endif
	.endif

BattlePyramid_Text_OneTrainersRemaining6::
	.ifdef ENGLISH
	.string "Can you keep winning against\n"
	.string "the last remaining TRAINER?$"
	.else
	.ifdef GERMAN
	.string "Schaffst du es, den\n"
	.string "verbleibenden TRAINER zu besiegen?$"
	.endif
	.endif

BattlePyramid_Text_ZeroTrainersRemaining6::
	.ifdef ENGLISH
	.string "There aren't any TRAINERS left that\n"
	.string "can take you on now…$"
	.else
	.ifdef GERMAN
	.string "Es ist niemand mehr da, dem du dein\n"
	.string "Können zeigen kannst.$"
	.endif
	.endif
