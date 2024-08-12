MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.ifdef ENGLISH
	.string "When TEAM MAGMA has roll call, we get\n"
	.string "important guarding assignments in\l"
	.string "the order that we line up.\p"
	.string "That's why I'm stuck off in this corner.\n"
	.string "I'm always late to roll call!$"
	.else
	.ifdef GERMAN
	.string "Wenn TEAM MAGMA zum Appell antritt,\n"
	.string "bekommen wir wichtige Aufgaben\l"
	.string "zugeteilt und zwar in der Reihenfolge,\p"
	.string "in der wir angetreten sind. Daher muss\n"
	.string "ich hier in der Ecke bleiben. Ich komme\l"
	.string "nämlich immer zu spät zum Appell.$"
	.endif
	.endif

MagmaHideout_1F_Text_Grunt1Defeat:
	.ifdef ENGLISH
	.string "I'm always late for training sessions,\n"
	.string "too!\p"
	.string "I hate to say it, but I'm wimpy…$"
	.else
	.ifdef GERMAN
	.string "Ich komme auch immer zu spät zum\n"
	.string "Training!\p"
	.string "Ich gebe es nur ungern zu, aber ich gebe\n"
	.string "ein jämmerliches Mitglied ab…$"
	.endif
	.endif

MagmaHideout_1F_Text_Grunt1PostBattle:
	.ifdef ENGLISH
	.string "Okay, I'll try to put a little more\n"
	.string "effort into things from now on…$"
	.else
	.ifdef GERMAN
	.string "Von nun an werde ich mich in allen\n"
	.string "Dingen mehr anstrengen!$"
	.endif
	.endif

MagmaHideout_1F_Text_Grunt2Intro:
	.ifdef ENGLISH
	.string "Our leader told us to dig into\n"
	.string "MT. CHIMNEY, so we dug and dug.\p"
	.string "And in the course of digging, we came\n"
	.string "across something that blew our minds!\p"
	.string "What did we find?\p"
	.string "Fuhahaha!\n"
	.string "I'll tell you if you beat me!$"
	.else
	.ifdef GERMAN
	.string "Unser Boss hat uns gesagt, wir sollen\n"
	.string "im SCHLOTBERG Grabungen durchführen,\l"
	.string "daher haben wir gegraben und gegraben…\p"
	.string "Und dann haben wir etwas gefunden, was\n"
	.string "uns den Atem verschlug.\p"
	.string "Was das war?!?\p"
	.string "Hahaha! Das verrate ich dir, wenn\n"
	.string "du mich besiegst.$"
	.endif
	.endif

MagmaHideout_1F_Text_Grunt2Defeat:
	.ifdef ENGLISH
	.string "Arrgh!\n"
	.string "Taken down!$"
	.else
	.ifdef GERMAN
	.string "Aaaarrgh!\n"
	.string "Treffer, versenkt.$"
	.endif
	.endif

MagmaHideout_1F_Text_Grunt2PostBattle:
	.ifdef ENGLISH
	.string "I won't tell you after all.\n"
	.string "You'll find out when you get there!\p"
	.string "It'd be better if you saved surprises\n"
	.string "to the end, don't you think?$"
	.else
	.ifdef GERMAN
	.string "Ich verrate es dir trotzdem nicht.\n"
	.string "Du wirst das schon herausfinden, wenn\l"
	.string "du dorthin gehst.\p"
	.string "Schließlich darf man sich nicht jede\n"
	.string "Überraschung nehmen lassen.$"
	.endif
	.endif

