@ Interact with cuttable tree
EventScript_CutTree::
	lockall
	goto_if_unset FLAG_BADGE01_GET, EventScript_CheckTreeCantCut
	checkpartymove MOVE_CUT
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckTreeCantCut
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_CUT
	msgbox Text_WantToCut, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

@ Use cut from party menu
EventScript_UseCut::
	lockall
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

EventScript_CutTreeDown::
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	releaseall
	end

Movement_CutTreeDown:
	cut_tree
	step_end

EventScript_CheckTreeCantCut::
	msgbox Text_CantCut, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelCut::
	closemessage
	releaseall
	end

Text_WantToCut:
	.ifdef ENGLISH
	.string "This tree looks like it can be\n"
	.string "CUT down!\p"
	.string "Would you like to CUT it?$"
	.else
	.ifdef GERMAN
	.string "Du kannst den ZERSCHNEIDER hier\n"
	.string "einsetzen!\p"
	.string "Möchtest du den ZERSCHNEIDER\n"
	.string "einsetzen?$"
	.endif
	.endif

Text_MonUsedFieldMove:
	.ifdef ENGLISH
	.string "{STR_VAR_1} used {STR_VAR_2}!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_1} setzt {STR_VAR_2} ein.$"
	.endif
	.endif

Text_CantCut:
	.ifdef ENGLISH
	.string "This tree looks like it can be\n"
	.string "CUT down!$"
	.else
	.ifdef GERMAN
	.string "Der ZERSCHNEIDER kann hier eingesetzt\n"
	.string "werden.$"
	.endif
	.endif

@ Interact with smashable rock
EventScript_RockSmash::
	lockall
	goto_if_unset FLAG_BADGE03_GET, EventScript_CantSmashRock
	checkpartymove MOVE_ROCK_SMASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
	msgbox Text_WantToSmash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

@ Use rock smash from party menu
EventScript_UseRockSmash::
	lockall
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

EventScript_SmashRock::
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	releaseall
	end

EventScript_EndSmash::
	releaseall
	end

Movement_SmashRock:
	rock_smash_break
	step_end

EventScript_CantSmashRock::
	msgbox Text_CantSmash, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelSmash::
	closemessage
	releaseall
	end

Text_WantToSmash:
	.ifdef ENGLISH
	.string "This rock appears to be breakable.\n"
	.string "Would you like to use ROCK SMASH?$"
	.else
	.ifdef GERMAN
	.string "Dieser Fels sieht zerbrechlich aus.\n"
	.string "Soll ZERTRÜMMERER eingesetzt werden?$"
	.endif
	.endif

Text_CantSmash:
	.ifdef ENGLISH
	.string "It's a rugged rock, but a POKéMON\n"
	.string "may be able to smash it.$"
	.else
	.ifdef GERMAN
	.string "Ein großer Felsen. Ein POKéMON könnte\n"
	.string "ihn vielleicht zertrümmern.$"
	.endif
	.endif

EventScript_StrengthBoulder::
	lockall
	goto_if_unset FLAG_BADGE04_GET, EventScript_CantStrength
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
	checkpartymove MOVE_STRENGTH
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantStrength
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToStrength, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelStrength
	closemessage
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_UseStrength::
	lockall
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_ActivateStrength::
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_MonUsedStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CantStrength::
	msgbox Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CheckActivatedBoulder::
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelStrength::
	closemessage
	releaseall
	end

Text_WantToStrength:
	.ifdef ENGLISH
	.string "It's a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.\p"
	.string "Would you like to use STRENGTH?$"
	.else
	.ifdef GERMAN
	.string "Ein POKéMON kann diesen Felsen\n"
	.string "vielleicht bewegen.\p"
	.string "Möchtest du STÄRKE einsetzen?$"
	.endif
	.endif

Text_MonUsedStrength:
	.ifdef ENGLISH
	.string "{STR_VAR_1} used STRENGTH!\p"
	.string "{STR_VAR_1}'s STRENGTH made it\n"
	.string "possible to move boulders around!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_1} setzt STÄRKE ein.\p"
	.string "STÄRKE von {STR_VAR_1} ermöglicht es,\n"
	.string "den Felsen zu bewegen.$"
	.endif
	.endif

Text_CantStrength:
	.ifdef ENGLISH
	.string "It's a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.$"
	.else
	.ifdef GERMAN
	.string "Ein POKéMON kann diesen Felsen\n"
	.string "vielleicht bewegen.$"
	.endif
	.endif

Text_StrengthActivated:
	.ifdef ENGLISH
	.string "STRENGTH made it possible to move\n"
	.string "boulders around.$"
	.else
	.ifdef GERMAN
	.string "STÄRKE ermöglicht es, Felsen zu\n"
	.string "bewegen.$"
	.endif
	.endif

EventScript_UseWaterfall::
	lockall
	checkpartymove MOVE_WATERFALL
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantWaterfall
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToWaterfall, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndWaterfall
	msgbox Text_MonUsedWaterfall, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_WATERFALL
	goto EventScript_EndWaterfall

EventScript_CannotUseWaterfall::
	lockall

EventScript_CantWaterfall::
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT

EventScript_EndWaterfall::
	releaseall
	end

Text_CantWaterfall:
	.ifdef ENGLISH
	.string "A wall of water is crashing down with\n"
	.string "a mighty roar.$"
	.else
	.ifdef GERMAN
	.string "Das Wasser fällt steil wie eine Wand\n"
	.string "brüllend in die Tiefe.$"
	.endif
	.endif

Text_WantToWaterfall:
	.ifdef ENGLISH
	.string "It's a large waterfall.\n"
	.string "Would you like to use WATERFALL?$"
	.else
	.ifdef GERMAN
	.string "Ein riesiger Wasserfall.\n"
	.string "Möchtest du KASKADE einsetzen?$"
	.endif
	.endif

Text_MonUsedWaterfall:
	.ifdef ENGLISH
	.string "{STR_VAR_1} used WATERFALL.$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_1} setzt KASKADE ein.$"
	.endif
	.endif

EventScript_UseDive::
	lockall
	checkpartymove MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantDive
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToDive, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndDive
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive
	end

EventScript_CantDive::
	msgbox Text_CantDive, MSGBOX_DEFAULT
	releaseall
	end

EventScript_EndDive::
	releaseall
	end

EventScript_UseDiveUnderwater::
	lockall
	checkpartymove MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSurface
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToSurface, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndSurface
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface
	end

EventScript_CantSurface::
	lockall
	msgbox Text_CantSurface, MSGBOX_DEFAULT
	goto EventScript_EndSurface
	end

EventScript_EndSurface::
	releaseall
	end

Text_CantDive:
	.ifdef ENGLISH
	.string "The sea is deep here. A POKéMON\n"
	.string "may be able to go underwater.$"
	.else
	.ifdef GERMAN
	.string "Das Wasser ist hier tief. Ein POKéMON\n"
	.string "könnte hier vielleicht tauchen.$"
	.endif
	.endif

Text_WantToDive:
	.ifdef ENGLISH
	.string "The sea is deep here.\n"
	.string "Would you like to use DIVE?$"
	.else
	.ifdef GERMAN
	.string "Das Meer ist an dieser Stelle sehr tief.\n"
	.string "Möchtest du TAUCHER einsetzen?$"
	.endif
	.endif

Text_MonUsedDive:
	.ifdef ENGLISH
	.string "{STR_VAR_1} used DIVE.$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_1} setzt TAUCHER ein.$"
	.endif
	.endif

Text_CantSurface:
	.ifdef ENGLISH
	.string "Light is filtering down from above.\n"
	.string "A POKéMON may be able to surface.$"
	.else
	.ifdef GERMAN
	.string "Licht schimmert von oben herab. Ein\n"
	.string "POKéMON könnte hier auftauchen.$"
	.endif
	.endif

Text_WantToSurface:
	.ifdef ENGLISH
	.string "Light is filtering down from above.\n"
	.string "Would you like to use DIVE?$"
	.else
	.ifdef GERMAN
	.string "Licht schimmert von oben herab.\n"
	.string "Möchtest du TAUCHER einsetzen?$"
	.endif
	.endif

EventScript_FailSweetScent::
	msgbox Text_FailSweetScent, MSGBOX_SIGN
	end

Text_FailSweetScent:
	.ifdef ENGLISH
	.string "Looks like there's nothing here…$"
	.else
	.ifdef GERMAN
	.string "Hier scheint nichts zu sein…$"
	.endif
	.endif
