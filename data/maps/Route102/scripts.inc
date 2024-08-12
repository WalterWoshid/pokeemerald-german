Route102_MapScripts::
	.byte 0

Route102_EventScript_LittleBoy::
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route102_EventScript_RouteSignOldale::
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg::
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_Boy::
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route102_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall::
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegister::
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch::
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Text_WatchMeCatchPokemon:
	.ifdef ENGLISH
	.string "WALLY: {PLAYER}…\n"
	.string "POKéMON hide in tall grass like this,\l"
	.string "don't they?\p"
	.string "Please watch me and see if I can\n"
	.string "catch one properly.\p"
	.string "…Whoa!$"
	.else
	.ifdef GERMAN
	.string "HEIKO: {PLAYER}…\n"
	.string "POKéMON verstecken sich in hohem Gras\l"
	.string "wie diesem hier, oder?\p"
	.string "Bitte bleib hier und schau, ob ich sie\n"
	.string "auch richtig fange.\p"
	.string "… Whoa!$"
	.endif
	.endif

Route102_Text_WallyIDidIt:
	.ifdef ENGLISH
	.string "WALLY: I did it… It's my…\n"
	.string "My POKéMON!$"
	.else
	.ifdef GERMAN
	.string "HEIKO: Ich habe es geschafft… Es\n"
	.string "gehört mir… Mein POKéMON!!!$"
	.endif
	.endif

Route102_Text_LetsGoBack:
	.ifdef ENGLISH
	.string "{PLAYER}, thank you!\n"
	.string "Let's go back to the GYM!$"
	.else
	.ifdef GERMAN
	.string "{PLAYER}, danke schön!\n"
	.string "Lass uns zurück zur ARENA gehen!$"
	.endif
	.endif

Route102_Text_ImNotVeryTall:
	.ifdef ENGLISH
	.string "I'm…not very tall, so I sink right\n"
	.string "into tall grass.\p"
	.string "The grass goes up my nose and…\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"
	.else
	.ifdef GERMAN
	.string "Ich… bin nicht groß, ich versinke im\n"
	.string "hohen Gras.\p"
	.string "Das Gras erreicht meine Nase und…\n"
	.string "Hahahaha…\p"
	.string "Haaatschiiii!$"
	.endif
	.endif

Route102_Text_CatchWholeBunchOfPokemon:
	.ifdef ENGLISH
	.string "I'm going to catch a whole bunch of\n"
	.string "POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Ich werde jede Menge POKéMON fangen!$"
	.endif
	.endif

Route102_Text_RouteSignOldale:
	.ifdef ENGLISH
	.string "ROUTE 102\n"
	.string "{RIGHT_ARROW} OLDALE TOWN$"
	.else
	.ifdef GERMAN
	.string "ROUTE 102\n"
	.string "{RIGHT_ARROW} ROSALTSTADT$"
	.endif
	.endif

Route102_Text_RouteSignPetalburg:
	.ifdef ENGLISH
	.string "ROUTE 102\n"
	.string "{LEFT_ARROW} PETALBURG CITY$"
	.else
	.ifdef GERMAN
	.string "ROUTE 102\n"
	.string "{LEFT_ARROW} BLÜTENBURG CITY$"
	.endif
	.endif
