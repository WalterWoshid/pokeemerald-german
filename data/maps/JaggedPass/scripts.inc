.set LOCALID_HIDEOUT_GUARD, 5

JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
	.ifdef ENGLISH
	.string "MT. CHIMNEY's JAGGED PASS…\p"
	.string "Now this is what I've always wanted\n"
	.string "in a mountain.\p"
	.string "This jagged bumpiness…\n"
	.string "It rocks my soul!$"
	.else
	.ifdef GERMAN
	.string "SCHLOTBERG STEILPASS…\p"
	.string "Davon habe ich immer geträumt, wenn ich\n"
	.string "in den Bergen unterwegs war.\p"
	.string "Zerklüftete Massive…\n"
	.string "Das bringt meine Seele zum Erbeben.$"
	.endif
	.endif

JaggedPass_Text_EricDefeat:
	.ifdef ENGLISH
	.string "Losing left me bitter!$"
	.else
	.ifdef GERMAN
	.string "Verlieren ist bitter.$"
	.endif
	.endif

JaggedPass_Text_EricPostBattle:
	.ifdef ENGLISH
	.string "Yes, I did lose at POKéMON…\p"
	.string "But, when it comes to the love of\n"
	.string "the mountains, I have you beat!$"
	.else
	.ifdef GERMAN
	.string "Ja, ich bin im Umgang mit POKéMON nicht\n"
	.string "gerade talentiert.\p"
	.string "Aber wenn es um die Leidenschaft für\n"
	.string "die Berge geht, stecke ich dich locker\l"
	.string "in die Tasche!$"
	.endif
	.endif

JaggedPass_Text_DianaIntro:
	.ifdef ENGLISH
	.string "This place isn't your casual hike.\n"
	.string "It's not suited for a picnic.$"
	.else
	.ifdef GERMAN
	.string "Dich habe ich hier noch nie gesehen.\n"
	.string "Dieser Platz eignet sich nicht für ein\l"
	.string "Picknick.$"
	.endif
	.endif

JaggedPass_Text_DianaDefeat:
	.ifdef ENGLISH
	.string "Ohhh, no!\n"
	.string "The ground is too bumpy…$"
	.else
	.ifdef GERMAN
	.string "Oooh, nein!\n"
	.string "Das liegt am Boden. Er ist zu uneben!$"
	.endif
	.endif

JaggedPass_Text_DianaPostBattle:
	.ifdef ENGLISH
	.string "Did you know?\p"
	.string "Some people cleverly ride their\n"
	.string "bicycles up this horribly bumpy pass.$"
	.else
	.ifdef GERMAN
	.string "Stell dir mal vor!\p"
	.string "Einige fahren tatsächlich mit ihren\n"
	.string "Fahrrädern diesen zerklüfteten Pass\l"
	.string "hinauf.$"
	.endif
	.endif

JaggedPass_Text_DianaRegister:
	.ifdef ENGLISH
	.string "Will you ever be back in this area?\n"
	.string "If you do return, I'd like a rematch.$"
	.else
	.ifdef GERMAN
	.string "Kommst du irgendwann wieder in diese\n"
	.string "Gegend? Ich würde gerne wieder gegen\l"
	.string "dich antreten.$"
	.endif
	.endif

JaggedPass_Text_DianaRematchIntro:
	.ifdef ENGLISH
	.string "Picnics are fun wherever you go.\n"
	.string "Just like POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Picknicke machen überall und immer\n"
	.string "Spaß. Und PKMN leisten mir dabei\l"
	.string "Gesellschaft!$"
	.endif
	.endif

JaggedPass_Text_DianaRematchDefeat:
	.ifdef ENGLISH
	.string "I only lost because the ground is\n"
	.string "too bumpy!$"
	.else
	.ifdef GERMAN
	.string "Ich habe nur verloren, weil der Boden\n"
	.string "wirklich sehr uneben ist.$"
	.endif
	.endif

JaggedPass_Text_DianaPostRematch:
	.ifdef ENGLISH
	.string "I'll forget about losing and just\n"
	.string "enjoy this bumpy hike.$"
	.else
	.ifdef GERMAN
	.string "Ich werde meine Niederlage einfach\n"
	.string "vergessen und mit dem Rad den Pass\l"
	.string "entlangdüsen.$"
	.endif
	.endif

JaggedPass_Text_EthanIntro:
	.ifdef ENGLISH
	.string "JAGGED PASS is hard to walk on.\n"
	.string "It's a good place for training.$"
	.else
	.ifdef GERMAN
	.string "Der STEILPASS ist sehr schwer zu Fuß\n"
	.string "zu meistern. Aber ein guter Ort zum\l"
	.string "Trainieren.$"
	.endif
	.endif

JaggedPass_Text_EthanDefeat:
	.ifdef ENGLISH
	.string "It was all over while we were still\n"
	.string "trying to find a good footing…$"
	.else
	.ifdef GERMAN
	.string "Schon vorbei? Ich habe überhaupt\n"
	.string "keinen sicheren Stand gehabt.$"
	.endif
	.endif

JaggedPass_Text_EthanPostBattle:
	.ifdef ENGLISH
	.string "If I had an ACRO BIKE, I'd be able to\n"
	.string "jump ledges.$"
	.else
	.ifdef GERMAN
	.string "Wenn ich ein KUNSTRAD hätte, könnte\n"
	.string "ich die Abhänge einfach überspringen.$"
	.endif
	.endif

JaggedPass_Text_EthanRegister:
	.ifdef ENGLISH
	.string "When I get more used to this bumpiness,\n"
	.string "I'll be sure to win!\p"
	.string "Can you register me in your POKéNAV?$"
	.else
	.ifdef GERMAN
	.string "Wenn ich mich erstmal an diesen\n"
	.string "unebenen Boden gewöhnt habe,\l"
	.string "werde ich mit Sicherheit gewinnen!\p"
	.string "Trägst du mich in deinen POKéNAV ein?$"
	.endif
	.endif

JaggedPass_Text_EthanRematchIntro:
	.ifdef ENGLISH
	.string "I got used to this bumpiness.\n"
	.string "I sing while I climb now.$"
	.else
	.ifdef GERMAN
	.string "Ich habe mich an die Unebenheiten ge-\n"
	.string "wöhnt. Ich singe beim Klettern.$"
	.endif
	.endif

JaggedPass_Text_EthanRematchDefeat:
	.ifdef ENGLISH
	.string "It's still not easy to battle on this\n"
	.string "bumpy ground…$"
	.else
	.ifdef GERMAN
	.string "Auf diesem unebenen Boden ist es wirk-\n"
	.string "lich nicht leicht, gut zu kämpfen.$"
	.endif
	.endif

JaggedPass_Text_EthanPostRematch:
	.ifdef ENGLISH
	.string "I should get an ACRO BIKE from RYDEL\n"
	.string "in MAUVILLE CITY…$"
	.else
	.ifdef GERMAN
	.string "Ich sollte mir ein KUNSTRAD von RADLA\n"
	.string "in MALVENFROH CITY besorgen…$"
	.endif
	.endif

JaggedPass_Text_GruntIntro:
	.ifdef ENGLISH
	.string "Wah!\n"
	.string "What are you doing here?\p"
	.string "What am I doing in a place like this?\p"
	.string "What business is it of yours?$"
	.else
	.ifdef GERMAN
	.string "Wah!\n"
	.string "Was machst du hier?\p"
	.string "Was ich hier mache?\p"
	.string "Was geht dich das an?$"
	.endif
	.endif

JaggedPass_Text_GruntDefeat:
	.ifdef ENGLISH
	.string "Urrrgh…\p"
	.string "I should've ducked into our HIDEOUT\n"
	.string "right away…$"
	.else
	.ifdef GERMAN
	.string "Arrrrgh…\p"
	.string "Ich hätte mich besser sofort in\n"
	.string "unserem VERSTECK versteckt…$"
	.endif
	.endif

JaggedPass_Text_GoWhereverYouWant:
	.ifdef ENGLISH
	.string "Okay, oh-kay!\n"
	.string "I admit it--you're strong!\p"
	.string "Don't worry about me.\n"
	.string "Go wherever you want!$"
	.else
	.ifdef GERMAN
	.string "Okay, oh-kay!\n"
	.string "Ich geb es ja zu - du bist stark!\p"
	.string "Mach dir um mich keine Sorgen.\n"
	.string "Geh, wo immer du hin willst.$"
	.endif
	.endif

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.ifdef ENGLISH
	.string "Oh! This boulder is shaking in response\n"
	.string "to the MAGMA EMBLEM!$"
	.else
	.ifdef GERMAN
	.string "Oh! Der Felsen reagiert auf das\n"
	.string "MAGMAEMBLEM.$"
	.endif
	.endif

JaggedPass_Text_JulioIntro:
	.ifdef ENGLISH
	.string "Aiyeeh! It's awfully scary to shoot\n"
	.string "down the mountain in one go!$"
	.else
	.ifdef GERMAN
	.string "Aiyeeeh! Man bekommt wirklich Angst,\n"
	.string "wenn man den ganzen Weg hinunterrennt\l"
	.string "ohne anzuhalten.$"
	.endif
	.endif

JaggedPass_Text_JulioDefeat:
	.ifdef ENGLISH
	.string "I feel like I'm falling apart…$"
	.else
	.ifdef GERMAN
	.string "Ich fühle mich, als würde ich\n"
	.string "zu Sand zerbröseln…$"
	.endif
	.endif

JaggedPass_Text_JulioPostBattle:
	.ifdef ENGLISH
	.string "My bicycle bounced around so much,\n"
	.string "my rear end's sore…$"
	.else
	.ifdef GERMAN
	.string "Mein Fahrrad hat mich durch-\n"
	.string "geschüttelt, mein Hintern tut weh…$"
	.endif
	.endif

JaggedPass_Text_AutumnIntro:
	.ifdef ENGLISH
	.string "I climb this hill every day.\n"
	.string "I have confidence in my strength!$"
	.else
	.ifdef GERMAN
	.string "Ich klettere jeden Tag auf diesen Berg!\n"
	.string "Ich weiß, wie stark ich bin.$"
	.endif
	.endif

JaggedPass_Text_AutumnDefeat:
	.ifdef ENGLISH
	.string "Hmm…\n"
	.string "What went wrong?$"
	.else
	.ifdef GERMAN
	.string "Hmm…\n"
	.string "Was ist denn nur schief gelaufen?$"
	.endif
	.endif

JaggedPass_Text_AutumnPostBattle:
	.ifdef ENGLISH
	.string "What is that odd rock protrusion\n"
	.string "a little up the hill from here?$"
	.else
	.ifdef GERMAN
	.string "Da oben ist ein kleiner Vorsprung. Der\n"
	.string "sieht sehr merkwürdig aus.$"
	.endif
	.endif

