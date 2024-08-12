AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.ifdef ENGLISH
	.string "DAN: While searching for treasures,\n"
	.string "we discovered a TRAINER!$"
	.else
	.ifdef GERMAN
	.string "MAX: Wir haben nach Schätzen gesucht\n"
	.string "- und einen TRAINER gefunden!$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.ifdef ENGLISH
	.string "DAN: We couldn't win even though\n"
	.string "we worked together…$"
	.else
	.ifdef GERMAN
	.string "MAX: Wir konnten nicht gewinnen, obwohl\n"
	.string "wir zusammengearbeitet haben…$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.ifdef ENGLISH
	.string "DAN: We can't find any treasures…\n"
	.string "I wonder if someone got them already?$"
	.else
	.ifdef GERMAN
	.string "MAX: Wir konnten keine Schätze finden.\n"
	.string "Ob uns jemand zuvorgekommen ist?$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.ifdef ENGLISH
	.string "DAN: You don't even have two POKéMON.\n"
	.string "You can't expect to beat us like that.$"
	.else
	.ifdef GERMAN
	.string "MAX: Du hast keine zwei POKéMON.\n"
	.string "So kannst du nicht gegen uns antreten.$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.ifdef ENGLISH
	.string "KIRA: Oh?\n"
	.string "We were searching for treasures.\l"
	.string "But we discovered a TRAINER instead!$"
	.else
	.ifdef GERMAN
	.string "JULE: Oh? Wir haben nach Schätzen\n"
	.string "gesucht und einen TRAINER gefunden.$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.ifdef ENGLISH
	.string "KIRA: Ooh, so strong!$"
	.else
	.ifdef GERMAN
	.string "JULE: Oh, wow, bist du stark!$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.ifdef ENGLISH
	.string "KIRA: Where could the treasures be?\p"
	.string "I've already decided what I'm buying\n"
	.string "when we find the treasures!$"
	.else
	.ifdef GERMAN
	.string "JULE: Ich frage mich, wo die Schätze\n"
	.string "versteckt sind…\p"
	.string "Ich weiß, was ich mir alles kaufen\n"
	.string "würde, wenn ich reich wäre…$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.ifdef ENGLISH
	.string "KIRA: Oh, you don't have two POKéMON?\n"
	.string "We'll have to battle some other time!$"
	.else
	.ifdef GERMAN
	.string "JULE: Hast du keine zwei POKéMON?\n"
	.string "Dann können wir jetzt nicht kämpfen.$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.ifdef ENGLISH
	.string "KIRA: Oh, you make me so angry!\n"
	.string "I'm going to register you for that!$"
	.else
	.ifdef GERMAN
	.string "JULE: Du machst mich echt wütend!\n"
	.string "Ich werde dich im POKéNAV eintragen.$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.ifdef ENGLISH
	.string "DAN: We've been searching for\n"
	.string "treasures all this time.\p"
	.string "Our POKéMON have grown stronger, too.\n"
	.string "Let us show you, okay?$"
	.else
	.ifdef GERMAN
	.string "MAX: Wir haben die ganze Zeit nur nach\n"
	.string "Schätzen gesucht.\p"
	.string "Aber unsere POKéMON sind auch stärker\n"
	.string "geworden. Dürfen wir dir das zeigen?$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.ifdef ENGLISH
	.string "DAN: You're strong, as usual!$"
	.else
	.ifdef GERMAN
	.string "MAX: Du bist stark wie immer.$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.ifdef ENGLISH
	.string "DAN: We can't find any treasures,\n"
	.string "we lose at POKéMON…\p"
	.string "I want to go home… But if I say that,\n"
	.string "she gets all angry with me…$"
	.else
	.ifdef GERMAN
	.string "MAX: Wir haben keine Schätze gefunden,\n"
	.string "sondern gegen POKéMON verloren…\p"
	.string "Ich will nach Hause… Aber wenn ich das\n"
	.string "laut sage, wird sie sauer auf mich.$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.ifdef ENGLISH
	.string "DAN: You don't even have two POKéMON.\n"
	.string "You can't expect to beat us like that.$"
	.else
	.ifdef GERMAN
	.string "MAX: Du hast keine zwei POKéMON.\n"
	.string "So können wir nicht kämpfen.$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.ifdef ENGLISH
	.string "KIRA: Oh? We meet again!\p"
	.string "Just like us, you still haven't given up\n"
	.string "searching for treasures, have you?\p"
	.string "Want to make it so the loser has\n"
	.string "to give up searching?$"
	.else
	.ifdef GERMAN
	.string "JULE: Oh, da bist du ja wieder!\p"
	.string "Genau wie wir, hast du die Suche nach\n"
	.string "Schätzen auch nicht aufgegeben, was?\p"
	.string "Wie wäre es mit einem Kampf? Und der\n"
	.string "Verlierer gibt die Suche auf?$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.ifdef ENGLISH
	.string "KIRA: Oh, we lost again…$"
	.else
	.ifdef GERMAN
	.string "JULE: Ach, wir haben wieder verloren…$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.ifdef ENGLISH
	.string "KIRA: We're not leaving until we raise\n"
	.string "our POKéMON some more and we find\l"
	.string "the treasures here!$"
	.else
	.ifdef GERMAN
	.string "JULE: Wir müssen unsere POKéMON mehr\n"
	.string "trainieren.\p"
	.string "Wir gehen nicht ohne Schatz nach\n"
	.string "Hause!$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.ifdef ENGLISH
	.string "KIRA: Oh, you don't have two POKéMON?\n"
	.string "We'll have to battle some other time!$"
	.else
	.ifdef GERMAN
	.string "JULE: Hast du keine zwei POKéMON?\n"
	.string "Dann müssen wir später kämpfen.$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.ifdef ENGLISH
	.string "I'm not good at swimming,\n"
	.string "but I am good at battles!$"
	.else
	.ifdef GERMAN
	.string "Ich kann nicht gut schwimmen.\n"
	.string "Aber im Kämpfen bin ich spitze!$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.ifdef ENGLISH
	.string "Oops.\n"
	.string "That didn't go very well.$"
	.else
	.ifdef GERMAN
	.string "Hups.\n"
	.string "Das ging daneben.$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.ifdef ENGLISH
	.string "Walking around barefoot in this ship\n"
	.string "is kind of gross.$"
	.else
	.ifdef GERMAN
	.string "Barfuß durch ein Schiff zu laufen, ist\n"
	.string "irgendwie eeekelig.$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.ifdef ENGLISH
	.string "Strength and compassion…\n"
	.string "Those are a TRAINER's treasures!$"
	.else
	.ifdef GERMAN
	.string "Stärke und Mitgefühl…\n"
	.string "Das wird bei TRAINERn sehr geschätzt!$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.ifdef ENGLISH
	.string "Ah, there is something about you\n"
	.string "that sparkles.$"
	.else
	.ifdef GERMAN
	.string "Irgendetwas an dir erstrahlt hell.$"
	.endif
	.endif

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.ifdef ENGLISH
	.string "In a cabin somewhere on board,\n"
	.string "I saw something sparkle.$"
	.else
	.ifdef GERMAN
	.string "In einer der Kabinen hier an Bord habe\n"
	.string "ich etwas Glitzerndes gesehen.$"
	.endif
	.endif
