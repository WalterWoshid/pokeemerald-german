MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.ifdef ENGLISH
	.string "Yo, how's it going, CHAMPION-bound\n"
	.string "{PLAYER}?\p"
	.string "The GYM LEADERS here use\n"
	.string "PSYCHIC-type POKéMON.\p"
	.string "If you go up against them with\n"
	.string "FIGHTING- or POISON-type POKéMON,\l"
	.string "they'll inflict horrible damage!\p"
	.string "Plus, they'll come at you with\n"
	.string "outstanding combination attacks.\p"
	.string "If you want to win, you'll need to show\n"
	.string "them how tight you are with your\l"
	.string "POKéMON. Go for it!$"
	.else
	.ifdef GERMAN
	.string "Na, wie sieht es aus, auf dem Weg zum\n"
	.string "CHAMP, {PLAYER}?\p"
	.string "Die ARENALEITER hier setzen PSYCHO-\n"
	.string "POKéMON ein.\p"
	.string "Setzt du KAMPF- oder GIFT-POKéMON ein,\n"
	.string "werden diese großen Schaden nehmen!\p"
	.string "Und außerdem wirst du dich gegen eine\n"
	.string "außergewöhnliche Kombination von\l"
	.string "Attacken behaupten müssen.\p"
	.string "Wenn du gewinnen willst, musst du ihnen\n"
	.string "beweisen, wie sehr du mit deinen\l"
	.string "POKéMON verbunden bist! Und nun los!$"
	.endif
	.endif

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.ifdef ENGLISH
	.string "Wow, you're astounding!\n"
	.string "You're one great TRAINER!$"
	.else
	.ifdef GERMAN
	.string "Wow, du bist erstaunlich!\n"
	.string "Du bist ein großartiger TRAINER!$"
	.endif
	.endif

MossdeepCity_Gym_Text_PrestonIntro:
	.ifdef ENGLISH
	.string "Battles hinge on the strength of your\n"
	.string "spirit! The weak-spirited will never win!$"
	.else
	.ifdef GERMAN
	.string "Kämpfe hängen von der Stärke deines\n"
	.string "Geistes ab! Die mit schwachem Geist\l"
	.string "werden niemals gewinnen.$"
	.endif
	.endif

MossdeepCity_Gym_Text_PrestonDefeat:
	.ifdef ENGLISH
	.string "I lost!\n"
	.string "I must temper my spirit again!$"
	.else
	.ifdef GERMAN
	.string "Ich habe verloren! Ich muss meinen\n"
	.string "Geist stärken!$"
	.endif
	.endif

MossdeepCity_Gym_Text_PrestonPostBattle:
	.ifdef ENGLISH
	.string "The indecisive lose.\n"
	.string "That's my warning to you.$"
	.else
	.ifdef GERMAN
	.string "Eine nichtssagende Niederlage.\n"
	.string "Das war doch nur eine Warnung an dich.$"
	.endif
	.endif

MossdeepCity_Gym_Text_VirgilIntro:
	.ifdef ENGLISH
	.string "Let me see your talent!$"
	.else
	.ifdef GERMAN
	.string "Zeig mir, ob du Talent hast.$"
	.endif
	.endif

MossdeepCity_Gym_Text_VirgilDefeat:
	.ifdef ENGLISH
	.string "You possess spectacular talent!$"
	.else
	.ifdef GERMAN
	.string "Du besitzt offensichtlich Talent.$"
	.endif
	.endif

MossdeepCity_Gym_Text_VirgilPostBattle:
	.ifdef ENGLISH
	.string "If there are prodigies in the world,\n"
	.string "then our GYM LEADERS are them!\p"
	.string "However, you may be even more talented\n"
	.string "than them…$"
	.else
	.ifdef GERMAN
	.string "Wenn es überhaupt Wunderkinder gibt, \n"
	.string "dann sind es unsere ARENALEITER.\p"
	.string "Aber du scheinst doch talentierter\n"
	.string "als sie zu sein…$"
	.endif
	.endif

MossdeepCity_Gym_Text_BlakeIntro:
	.ifdef ENGLISH
	.string "Fufufufu… Watch me levitate a POKé\n"
	.string "BALL telekinetically!\p"
	.string "Wrooooooooaaaar!\n"
	.string "… … … … … … …\p"
	.string "Sometimes, I'm out of sync…$"
	.else
	.ifdef GERMAN
	.string "Hihihihi… Achtung! Ich lasse meinen\n"
	.string "POKéBALL durch Telekinese schweben!\p"
	.string "Wuhuuuuuuuhuiii!\n"
	.string "… … … … … … …\p"
	.string "Äh, manchmal fehlt es mir etwas an\n"
	.string "Balance…$"
	.endif
	.endif

MossdeepCity_Gym_Text_BlakeDefeat:
	.ifdef ENGLISH
	.string "My POKéMON battling skills are out\n"
	.string "of sync, too!$"
	.else
	.ifdef GERMAN
	.string "Meine POKéMON kämpften nicht\n"
	.string "synchron!$"
	.endif
	.endif

MossdeepCity_Gym_Text_BlakePostBattle:
	.ifdef ENGLISH
	.string "A POKé BALL was too heavy to lift\n"
	.string "psychically. But this dust bunny…\p"
	.string "Whoooooooooooooooh!\n"
	.string "… … … … … …\p"
	.string "No, I'm not cheating!\n"
	.string "I didn't blow on it! Honestly!$"
	.else
	.ifdef GERMAN
	.string "Ein POKéBALL ist doch etwas zu schwer,\n"
	.string "um ihn schweben zu lassen!\l"
	.string "Aber ein Staubknäuel…\p"
	.string "Wuhuuuuuuuhu!\n"
	.string "… … … … … … …\p"
	.string "Das ist kein Trick!\n"
	.string "Da ist kein Luftstrom! Ehrlich!$"
	.endif
	.endif

MossdeepCity_Gym_Text_HannahIntro:
	.ifdef ENGLISH
	.string "When you lose to me, don't be too hard\n"
	.string "on yourself.\p"
	.string "It's not that you're weak--I'm just\n"
	.string "too strong!$"
	.else
	.ifdef GERMAN
	.string "Solltest du gegen mich verlieren,\n"
	.string "darfst du dir das nicht so zu Herzen\l"
	.string "nehmen.\p"
	.string "Du bist nicht zu schwach - ich bin nur\n"
	.string "zu stark für dich!$"
	.endif
	.endif

MossdeepCity_Gym_Text_HannahDefeat:
	.ifdef ENGLISH
	.string "You're just too strong!$"
	.else
	.ifdef GERMAN
	.string "Du bist nur zu stark für mich!$"
	.endif
	.endif

MossdeepCity_Gym_Text_HannahPostBattle:
	.ifdef ENGLISH
	.string "I'm not going to get down on myself for\n"
	.string "losing. I just need to train harder.\p"
	.string "Positive thinking--that's my strong\n"
	.string "point!$"
	.else
	.ifdef GERMAN
	.string "Ich lasse mich von dieser Niederlage\n"
	.string "nicht herunterziehen. Ich werde härter\l"
	.string "trainieren.\p"
	.string "Positives Denken - das ist meine\n"
	.string "Stärke!$"
	.endif
	.endif

MossdeepCity_Gym_Text_SamanthaIntro:
	.ifdef ENGLISH
	.string "I see it…\n"
	.string "I see your future…\p"
	.string "If you can beat me, I will tell you\n"
	.string "your future!$"
	.else
	.ifdef GERMAN
	.string "Ich kann sie sehen…\n"
	.string "Ich sehe deine Zukunft…\p"
	.string "Wenn du mich besiegen kannst, sage ich\n"
	.string "dir deine Zukunft voraus.$"
	.endif
	.endif

MossdeepCity_Gym_Text_SamanthaDefeat:
	.ifdef ENGLISH
	.string "I surrender!$"
	.else
	.ifdef GERMAN
	.string "Ich ergebe mich!$"
	.endif
	.endif

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.ifdef ENGLISH
	.string "You will wage a terrifically intense\n"
	.string "battle with our GYM LEADERS…\p"
	.string "The result…\n"
	.string "You won't hear it from me!$"
	.else
	.ifdef GERMAN
	.string "Du wirst einen irrsinnigen Kampf gegen\n"
	.string "unsere ARENALEITER führen…\p"
	.string "Der Ausgang dieses Kampfes…\n"
	.string "Meine Lippen sind versiegelt.$"
	.endif
	.endif

MossdeepCity_Gym_Text_MauraIntro:
	.ifdef ENGLISH
	.string "The roads you have traveled…\n"
	.string "What you have experienced…\p"
	.string "Come at me with everything you've\n"
	.string "learned!$"
	.else
	.ifdef GERMAN
	.string "Die Straßen, die du gewandert bist…\n"
	.string "Das, was du erfahren hast…\p"
	.string "Leg mir alles, was du gelernt hast,\n"
	.string "zu Füßen.$"
	.endif
	.endif

MossdeepCity_Gym_Text_MauraDefeat:
	.ifdef ENGLISH
	.string "You've traveled a path of greatness!$"
	.else
	.ifdef GERMAN
	.string "Du wandelst auf dem Pfad der Größe!$"
	.endif
	.endif

MossdeepCity_Gym_Text_MauraPostBattle:
	.ifdef ENGLISH
	.string "A bright future awaits those who have\n"
	.string "worked diligently.\p"
	.string "For those who lazed idly, there is\n"
	.string "only despair at the end.\p"
	.string "What goes around comes around…$"
	.else
	.ifdef GERMAN
	.string "Eine glänzende Zukunft erwartet die,\n"
	.string "die fleißig sind.\p"
	.string "Die, die dem Müßiggang frönen, erwartet\n"
	.string "am Ende des Weges nur die Verzweiflung.\p"
	.string "Man erntet das, was man sät.$"
	.endif
	.endif

MossdeepCity_Gym_Text_SylviaIntro:
	.ifdef ENGLISH
	.string "Even at the risk of life, I will win\n"
	.string "this battle!$"
	.else
	.ifdef GERMAN
	.string "Auch wenn ich dabei mein Leben aufs\n"
	.string "Spiel setze - ich werde den Kampf\l"
	.string "gewinnen!$"
	.endif
	.endif

MossdeepCity_Gym_Text_SylviaDefeat:
	.ifdef ENGLISH
	.string "What you do…\n"
	.string "It horrifies me…$"
	.else
	.ifdef GERMAN
	.string "Was du da machst…\n"
	.string "Das macht mir Angst…$"
	.endif
	.endif

MossdeepCity_Gym_Text_SylviaPostBattle:
	.ifdef ENGLISH
	.string "How dare you beat me…\p"
	.string "It won't be my fault if something\n"
	.string "horrible befalls you…$"
	.else
	.ifdef GERMAN
	.string "Wie konntest du es wagen, mich zu\n"
	.string "besiegen…\p"
	.string "Es ist nicht meine Schuld, wenn dir bald\n"
	.string "etwas Schreckliches passiert…$"
	.endif
	.endif

MossdeepCity_Gym_Text_NateIntro:
	.ifdef ENGLISH
	.string "Hohoho.\p"
	.string "You need me to show you how tenacious\n"
	.string "the PSYCHIC type can be.$"
	.else
	.ifdef GERMAN
	.string "Hohoho.\p"
	.string "Du lässt mir keine andere Wahl. Ich\n"
	.string "werde dir zeigen, wie zäh PSYCHO-\l"
	.string "POKéMON sind.$"
	.endif
	.endif

MossdeepCity_Gym_Text_NateDefeat:
	.ifdef ENGLISH
	.string "Oh! My, my!\n"
	.string "Your battle style is fantastic!$"
	.else
	.ifdef GERMAN
	.string "Oh! Meine Güte!\n"
	.string "Dein Kampfstil ist einfach fantastisch!$"
	.endif
	.endif

MossdeepCity_Gym_Text_NatePostBattle:
	.ifdef ENGLISH
	.string "I… I don't let defeat rattle m-me,\n"
	.string "however b-badly.$"
	.else
	.ifdef GERMAN
	.string "Ich… lasse mich durch eine Niederlage\n"
	.string "nicht aus der Ruhe bringen.$"
	.endif
	.endif

MossdeepCity_Gym_Text_KathleenIntro:
	.ifdef ENGLISH
	.string "Let me show you a perfectly awful,\n"
	.string "horrifying time!$"
	.else
	.ifdef GERMAN
	.string "Ich werde dir eine wunderbar\n"
	.string "schreckliche und gruselige Zeit\l"
	.string "bereiten.$"
	.endif
	.endif

MossdeepCity_Gym_Text_KathleenDefeat:
	.ifdef ENGLISH
	.string "N-nooooo!$"
	.else
	.ifdef GERMAN
	.string "NnnneeeeeiiiinnnnN!$"
	.endif
	.endif

MossdeepCity_Gym_Text_KathleenPostBattle:
	.ifdef ENGLISH
	.string "Your vitality is contagious!\n"
	.string "Get away from me quickly!$"
	.else
	.ifdef GERMAN
	.string "Deine Dynamik ist mit Sicherheit\n"
	.string "ansteckend! Geh schnell weg!$"
	.endif
	.endif

MossdeepCity_Gym_Text_CliffordIntro:
	.ifdef ENGLISH
	.string "I may be past my prime, but I suggest\n"
	.string "you not patronize me.$"
	.else
	.ifdef GERMAN
	.string "Ich mag meine beste Zeit gesehen\n"
	.string "haben, aber ich lasse mich von dir nicht\l"
	.string "bevormunden.$"
	.endif
	.endif

MossdeepCity_Gym_Text_CliffordDefeat:
	.ifdef ENGLISH
	.string "Ah, you overflow with the power\n"
	.string "of youth!$"
	.else
	.ifdef GERMAN
	.string "Ah, deine jugendliche Energie strömt\n"
	.string "nur so aus dir heraus.$"
	.endif
	.endif

MossdeepCity_Gym_Text_CliffordPostBattle:
	.ifdef ENGLISH
	.string "It seems that I could not overcome\n"
	.string "your youthful energy.$"
	.else
	.ifdef GERMAN
	.string "Gegen deine jugendliche Energie habe\n"
	.string "ich keine Chance.$"
	.endif
	.endif

MossdeepCity_Gym_Text_MaceyIntro:
	.ifdef ENGLISH
	.string "You're not getting through to the end!\n"
	.string "Not if I can help it!$"
	.else
	.ifdef GERMAN
	.string "Du wirst den Weg nicht zu Ende gehen!\n"
	.string "Nicht, wenn ich mich dir in den Weg\l"
	.string "stellen kann.$"
	.endif
	.endif

MossdeepCity_Gym_Text_MaceyDefeat:
	.ifdef ENGLISH
	.string "How could you be so ludicrously\n"
	.string "strong?$"
	.else
	.ifdef GERMAN
	.string "Wie kann man nur so stark sein wie du?\n"
	.string "Lächerlich!$"
	.endif
	.endif

MossdeepCity_Gym_Text_MaceyPostBattle:
	.ifdef ENGLISH
	.string "Humph! You may be strong, but you're\n"
	.string "not suitable for the PSYCHIC type!\p"
	.string "The way you battle is somehow brutal!$"
	.else
	.ifdef GERMAN
	.string "Hmpf! Du magst ja stark sein, aber mit\n"
	.string "PSYCHO-POKéMON kommst du nicht\l"
	.string "zurecht!\p"
	.string "Du hast einen recht brutalen Kampfstil.$"
	.endif
	.endif

MossdeepCity_Gym_Text_NicholasIntro:
	.ifdef ENGLISH
	.string "Wroooar! Have a taste of my super\n"
	.string "POKéMON hard-battling power!$"
	.else
	.ifdef GERMAN
	.string "Wroooaaar! Schmeck die Superkraft\n"
	.string "meines POKéMON!$"
	.endif
	.endif

MossdeepCity_Gym_Text_NicholasDefeat:
	.ifdef ENGLISH
	.string "Oh!\n"
	.string "Done in!$"
	.else
	.ifdef GERMAN
	.string "Oh!\n"
	.string "Das war’s dann wohl.$"
	.endif
	.endif

MossdeepCity_Gym_Text_NicholasPostBattle:
	.ifdef ENGLISH
	.string "All right! I think I'll develop a special\n"
	.string "invincible POKéMON power next.$"
	.else
	.ifdef GERMAN
	.string "Gut! Ich glaube, ich sollte eine un-\n"
	.string "schlagbare POKéMON-Kraft entwickeln.$"
	.endif
	.endif

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.ifdef ENGLISH
	.string "TATE: Hehehe… Were you surprised?\p"
	.string "LIZA: Fufufu… Were you surprised?\p"
	.string "TATE: That there are two GYM LEADERS?\n"
	.string "LIZA: That there are two GYM LEADERS?\p"
	.string "TATE: We're twins!\n"
	.string "LIZA: We're twins!\p"
	.string "TATE: We don't need to talk because…\n"
	.string "LIZA: We can each determine what…\p"
	.string "TATE: The other is thinking…\n"
	.string "LIZA: All in our minds!\p"
	.string "TATE: This combination of ours…\n"
	.string "LIZA: Can you beat it?$"
	.else
	.ifdef GERMAN
	.string "BEN: Hähähä… Bist du überrascht?\p"
	.string "SVENJA: Hihihi… Bist du überrascht?\p"
	.string "BEN: Dass es hier 2 ARENALEITER gibt?\n"
	.string "SVENJA: Dass es hier 2 ARENALEITER\l"
	.string "gibt?\p"
	.string "BEN: Wir sind Zwillinge!\n"
	.string "SVENJA: Wir sind Zwillinge!\p"
	.string "BEN: Wir brauchen nicht zu sprechen…\n"
	.string "SVENJA: Wir wissen, was…\p"
	.string "BEN: Der andere gerade denkt…\n"
	.string "SVENJA: Gedankenübertragung!\p"
	.string "BEN: Diese doppelte Stärke…\n"
	.string "SVENJA: Kannst du sie besiegen?$"
	.endif
	.endif

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.ifdef ENGLISH
	.string "TATE: What?! Our combination…\n"
	.string "LIZA: Was shattered!\p"
	.string "TATE: It can't be helped. You've won…\n"
	.string "LIZA: So, in recognition, take this.$"
	.else
	.ifdef GERMAN
	.string "BEN: Was?!? Unsere Kombination…\n"
	.string "SVENJA: Wurde auseinander gerissen!\p"
	.string "BEN: So sieht’s aus. Du hast gewonnen.\n"
	.string "SVENJA: Daher überreichen wir dir dies.$"
	.endif
	.endif

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.ifdef ENGLISH
	.string "{PLAYER} received the MIND BADGE\n"
	.string "from TATE and LIZA.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} erhält den MENTALORDEN von\n"
	.string "SVENJA und BEN.$"
	.endif
	.endif

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.ifdef ENGLISH
	.string "TATE: The MIND BADGE enhances the\n"
	.string "SP. ATK and SP. DEF of POKéMON.\p"
	.string "LIZA: It also lets you use the HM move\n"
	.string "DIVE outside of battle.\p"
	.string "TATE: You should also take this, too.$"
	.else
	.ifdef GERMAN
	.string "BEN: Der MENTALORDEN erhöht den SP.\n"
	.string "ANG. und die SP. VER. von POKéMON.\p"
	.string "SVENJA: Und du kannst damit die VM\n"
	.string "TAUCHER außerhalb eines Kampfes\l"
	.string "einsetzen.\p"
	.string "BEN: Dies ist ebenfalls für dich.$"
	.endif
	.endif

MossdeepCity_Gym_Text_ExplainCalmMind:
	.ifdef ENGLISH
	.string "TATE: That TM04 contains…\n"
	.string "LIZA: CALM MIND!\p"
	.string "TATE: It raises SP. ATK and…\n"
	.string "LIZA: It raises SP. DEF!\p"
	.string "TATE: It's a move that's perfect…\n"
	.string "LIZA: For PSYCHIC POKéMON!\p"
	.string "… … … … … …$"
	.else
	.ifdef GERMAN
	.string "BEN: TM04 enthält…\n"
	.string "SVENJA: GEDANKENGUT!\p"
	.string "BEN: Dies erhöht den SP. ANG. und…\n"
	.string "SVENJA: Erhöht die SP. VER.!\p"
	.string "BEN: Eine Attacke, die perfekt…\n"
	.string "SVENJA: Für PSYCHO-POKéMON ist!\p"
	.string "… … … … … …$"
	.endif
	.endif

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.ifdef ENGLISH
	.string "Registered GYM LEADERS TATE & LIZA\n"
	.string "in the POKéNAV.$"
	.else
	.ifdef GERMAN
	.string "ARENALEITER BEN und SVENJA wurden im\n"
	.string "POKéNAV-Verzeichnis eingetragen.$"
	.endif
	.endif

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.ifdef ENGLISH
	.string "TATE: Looks like the bond between you\n"
	.string "and your POKéMON is far stronger than\l"
	.string "the bond that we share as twins.\p"
	.string "LIZA: You will become even stronger!\n"
	.string "We've battled you, so we know.$"
	.else
	.ifdef GERMAN
	.string "BEN: Es scheint, als sei das Band\n"
	.string "zwischen dir und deinen POKéMON viel\l"
	.string "stärker als zwischen uns Zwillingen.\p"
	.string "SVENJA: Und du wirst noch stärker\n"
	.string "werden! Wir haben gegen dich gekämpft,\l"
	.string "daher können wir das vorhersagen.$"
	.endif
	.endif

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.ifdef ENGLISH
	.string "TATE: Hehehe… Were you surprised?\p"
	.string "LIZA: That there are two GYM LEADERS?\p"
	.string "TATE: Oops, you have only one…\n"
	.string "LIZA: POKéMON that can battle.\p"
	.string "TATE: We can't battle that way!\p"
	.string "LIZA: If you want to challenge us,\n"
	.string "bring some more POKéMON.$"
	.else
	.ifdef GERMAN
	.string "BEN: Hähähä… Bist du überrascht?\p"
	.string "SVENJA: Dass es hier 2 ARENALEITER\n"
	.string "gibt?\p"
	.string "BEN: Hups, du hast nur ein…\n"
	.string "SVENJA: POKéMON für den Kampf.\p"
	.string "BEN: So können wir nicht kämpfen!\p"
	.string "SVENJA: Wenn du uns herausfordern\n"
	.string "willst, dann musst du mehr POKéMON\l"
	.string "haben.$"
	.endif
	.endif

MossdeepCity_Gym_Text_GymStatue:
	.ifdef ENGLISH
	.string "MOSSDEEP CITY POKéMON GYM$"
	.else
	.ifdef GERMAN
	.string "POKéMON ARENA von MOOSBACH CITY$"
	.endif
	.endif

MossdeepCity_Gym_Text_GymStatueCertified:
	.ifdef ENGLISH
	.string "MOSSDEEP CITY POKéMON GYM\p"
	.string "LIZA AND TATE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
	.else
	.ifdef GERMAN
	.string "POKéMON ARENA von MOOSBACH CITY\p"
	.string "SVENJA UND BENS ANERKANNTE TRAINER:\n"
	.string "{PLAYER}$"
	.endif
	.endif

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.ifdef ENGLISH
	.string "TATE: POKéMON…\n"
	.string "LIZA: POKéMON…\p"
	.string "TATE: By changing the party's mix…\n"
	.string "LIZA: The battle style changes.\p"
	.string "TATE: But me…\n"
	.string "LIZA: But me…\p"
	.string "TATE: I'll always be with LIZA!\n"
	.string "LIZA: I'll always be with TATE!\p"
	.string "TATE: Our combination…\n"
	.string "LIZA: We'll show you again and again!$"
	.else
	.ifdef GERMAN
	.string "BEN: POKéMON…\n"
	.string "SVENJA: POKéMON…\p"
	.string "BEN: Die Zusammensetzung des Teams…\n"
	.string "SVENJA: Bestimmt den Kampfstil.\p"
	.string "BEN: Aber ich…\n"
	.string "SVENNJA: Aber ich…\p"
	.string "BEN: Kämpfe nur zusammen mit SVENJA!\n"
	.string "SVENJA: Kämpfe nur zusammen mit BEN!\p"
	.string "BEN: Diese Kombination…\n"
	.string "SVENJA: Wirst du immer wieder sehen!$"
	.endif
	.endif

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.ifdef ENGLISH
	.string "TATE: You and your POKéMON…\n"
	.string "LIZA: It's as if you were siblings!$"
	.else
	.ifdef GERMAN
	.string "BEN: Du und deine POKéMON…\n"
	.string "SVENJA: Seid wie Geschwister! $"
	.endif
	.endif

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.ifdef ENGLISH
	.string "TATE: You can knock us down,\n"
	.string "but we'll never stay down!\p"
	.string "LIZA: Because the two of us,\n"
	.string "we always support each other!$"
	.else
	.ifdef GERMAN
	.string "BEN: Du magst uns besiegen, aber wir\n"
	.string "werden nicht am Boden liegen bleiben!\p"
	.string "SVENJA: Denn wir beide werden immer\n"
	.string "füreinander da sein!$"
	.endif
	.endif

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.ifdef ENGLISH
	.string "TATE: You're back again…\n"
	.string "LIZA: You're back again…\p"
	.string "TATE: To give us a rematch.\n"
	.string "LIZA: To give us a rematch.\p"
	.string "TATE: But…\n"
	.string "LIZA: For our match…\p"
	.string "TATE: You brought just one POKéMON!\n"
	.string "LIZA: You brought just one POKéMON!\p"
	.string "TATE: We need you to bring at least…\n"
	.string "LIZA: Two POKéMON when you come back.$"
	.else
	.ifdef GERMAN
	.string "BEN: Du bist zurückgekommen…\n"
	.string "SVENJA: Du bist zurückgekommen…\p"
	.string "BEN: Um erneut gegen uns anzutreten.\n"
	.string "SVENJA: Um erneut gegen uns\l"
	.string "anzutreten.\p"
	.string "BEN: Aber…\n"
	.string "SVENJA: Für diesen Kampf hast du…\p"
	.string "BEN: Nur ein einziges POKéMON dabei!\n"
	.string "SVENJA: Nur ein einziges POKéMON dabei!\p"
	.string "BEN: Du musst mindestens zwei…\n"
	.string "SVENJA: POKéMON haben.$"
	.endif
	.endif
