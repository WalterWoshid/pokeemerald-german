Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
	giveitem ITEM_SODA_POP
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.ifdef ENGLISH
	.string "I'm the owner of the SEASHORE HOUSE.\n"
	.string "But you can call me MR. SEA!\p"
	.string "What I love above all is to see hot\n"
	.string "POKéMON battles.\p"
	.string "Let me see that your heart burns hot!\p"
	.string "If you can defeat all the TRAINERS\n"
	.string "here, I'll reward your efforts.$"
	.else
	.ifdef GERMAN
	.string "Ich bin der Besitzer des STRANDHAUSes.\n"
	.string "Du kannst MR. MARE zu mir sagen.\p"
	.string "Heißen POKéMON-Kämpfen zuzusehen,\n"
	.string "liebe ich über alles!\p"
	.string "Zeig mir, wie heiß dein Herz lodert!\p"
	.string "Wenn du alle TRAINER besiegen kannst,\n"
	.string "werde ich dich belohnen!$"
	.endif
	.endif

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.ifdef ENGLISH
	.string "Show me some hot matches!\p"
	.string "I run this SEASHORE HOUSE just for\n"
	.string "that reason alone!$"
	.else
	.ifdef GERMAN
	.string "Zeig mir heiße Kämpfe!\p"
	.string "Nur für diese habe ich das STRANDHAUS\n"
	.string "überhaupt geöffnet!$"
	.endif
	.endif

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.ifdef ENGLISH
	.string "You're scorching hot!\n"
	.string "Those battles blazed!\l"
	.string "I'm more than just satisfied!\p"
	.string "As thanks for showing me your hot\n"
	.string "streak, I want you to take these.\p"
	.string "It's half a dozen bottles of SODA POP!$"
	.else
	.ifdef GERMAN
	.string "Du bist brandheiß!\n"
	.string "Die Kämpfe glühen geradezu!\l"
	.string "Ich bin mehr als zufrieden!\p"
	.string "Du hast deine Fertigkeiten bewiesen.\n"
	.string "Zum Dank schenke ich dir etwas.\p"
	.string "Es sind sechs Flaschen SPRUDEL!$"
	.endif
	.endif

Route109_SeashoreHouse_Text_BagFull:
	.ifdef ENGLISH
	.string "Oh, but hey, your BAG's jammed full.\n"
	.string "I'll hang on to these for you.$"
	.else
	.ifdef GERMAN
	.string "Aber dein BEUTEL ist ja gerammelt voll.\n"
	.string "Ich werde sie für dich aufbewahren.$"
	.endif
	.endif

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.ifdef ENGLISH
	.string "Want to buy some SODA POP?\n"
	.string "POKéMON love it!\p"
	.string "Just ¥300 a bottle!\n"
	.string "Buy some!$"
	.else
	.ifdef GERMAN
	.string "Möchtest du etwas SPRUDEL kaufen?\n"
	.string "POKéMON lieben ihn!\p"
	.string "Nur ¥300 pro Flasche!\n"
	.string "Kauf doch welchen!$"
	.endif
	.endif

Route109_SeashoreHouse_Text_HereYouGo:
	.ifdef ENGLISH
	.string "Here you go!$"
	.else
	.ifdef GERMAN
	.string "Hier, bitte schön!$"
	.endif
	.endif

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.ifdef ENGLISH
	.string "You don't have the money.$"
	.else
	.ifdef GERMAN
	.string "Du hast nicht genügend Geld.$"
	.endif
	.endif

Route109_SeashoreHouse_Text_ThatsTooBad:
	.ifdef ENGLISH
	.string "No?\n"
	.string "That's too bad.$"
	.else
	.ifdef GERMAN
	.string "Nein?\n"
	.string "Das ist aber wirklich schade.$"
	.endif
	.endif

Route109_SeashoreHouse_Text_DwayneIntro:
	.ifdef ENGLISH
	.string "If you're looking for a battle in the\n"
	.string "SEASHORE HOUSE, you'll find no\l"
	.string "hotter TRAINER than me, matey!$"
	.else
	.ifdef GERMAN
	.string "Wenn du Lust auf einen heißen Kampf\n"
	.string "auf hoher See hast, findest du keinen\l"
	.string "lodernderen TRAINER als mich!$"
	.endif
	.endif

Route109_SeashoreHouse_Text_DwayneDefeated:
	.ifdef ENGLISH
	.string "That was a hot battle!\n"
	.string "I can accept that loss, matey!$"
	.else
	.ifdef GERMAN
	.string "Das war ein heißer Kampf!\n"
	.string "Ich kann die Niederlage verkraften!$"
	.endif
	.endif

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.ifdef ENGLISH
	.string "Whenever I'm in SLATEPORT, I enjoy\n"
	.string "hot battles and ice-cold SODA POP!$"
	.else
	.ifdef GERMAN
	.string "Immer wenn ich in GRAPHITPORT CITY bin,\n"
	.string "genieße ich heiße Kämpfe und\l"
	.string "eisgekühlten SPRUDEL!$"
	.endif
	.endif

Route109_SeashoreHouse_Text_JohannaIntro:
	.ifdef ENGLISH
	.string "Boring battles aren't worth the effort.\p"
	.string "Fiery hot battles are what toughen up\n"
	.string "TRAINERS and POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Langweilige Kämpfe lohnen sich nicht.\p"
	.string "Feurig heiße Kämpfe aber stählen\n"
	.string "TRAINER und POKéMON.$"
	.endif
	.endif

Route109_SeashoreHouse_Text_JohannaDefeated:
	.ifdef ENGLISH
	.string "That's hot!$"
	.else
	.ifdef GERMAN
	.string "Das war brandheiß!$"
	.endif
	.endif

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.ifdef ENGLISH
	.string "Whew, I'm all thirsty.\n"
	.string "Maybe I'll have a SODA POP.$"
	.else
	.ifdef GERMAN
	.string "Puh, ich bin am Verdursten.\n"
	.string "Ich sollte SPRUDEL trinken.$"
	.endif
	.endif

Route109_SeashoreHouse_Text_SimonIntro:
	.ifdef ENGLISH
	.string "I'm going to show you how great\n"
	.string "my POKéMON are, but don't cry!$"
	.else
	.ifdef GERMAN
	.string "Ich werde dir zeigen, wie toll meine\n"
	.string "POKéMON sind. Aber heul bloß nicht los!$"
	.endif
	.endif

Route109_SeashoreHouse_Text_SimonDefeated:
	.ifdef ENGLISH
	.string "…I lost, but I won't cry…$"
	.else
	.ifdef GERMAN
	.string "Ich habe verloren. Aber ich heule nicht!$"
	.endif
	.endif

Route109_SeashoreHouse_Text_SimonPostBattle:
	.ifdef ENGLISH
	.string "If one of my POKéMON knew the move\n"
	.string "for carrying me across water on its\l"
	.string "back, I could get rid of this inner tube.$"
	.else
	.ifdef GERMAN
	.string "Wenn doch nur eines meiner POKéMON\n"
	.string "wüsste, wie es mich über das Wasser\l"
	.string "tragen kann. Dann wäre ich den\l"
	.string "ollen Schwimmreifen los.$"
	.endif
	.endif

