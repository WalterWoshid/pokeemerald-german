MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.ifdef ENGLISH
	.string "This is where we DRAGON users do our\n"
	.string "training.\p"
	.string "The CHAMPION even visits.\n"
	.string "Now do you see how special it is here?$"
	.else
	.ifdef GERMAN
	.string "Dort trainieren wir DRACHEN-Besitzer…\p"
	.string "Auch der CHAMP kommt manchmal vorbei.\n"
	.string "Verstehst du nun, dass dies ein\l"
	.string "besonderer Ort ist?$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.ifdef ENGLISH
	.string "Urgh!\n"
	.string "I didn't expect you to be so strong!$"
	.else
	.ifdef GERMAN
	.string "Argh!\n"
	.string "Ich hätte nicht gedacht, dass du so\l"
	.string "stark bist!$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.ifdef ENGLISH
	.string "The road ahead remains long and harsh.\p"
	.string "When will my POKéMON and I become\n"
	.string "the best?$"
	.else
	.ifdef GERMAN
	.string "Der Weg vor mir ist lang und\n"
	.string "beschwerlich.\p"
	.string "Wann werden meine POKéMON und ich\n"
	.string "zu den Besten gehören?$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_NicolasRegister:
	.ifdef ENGLISH
	.string "I want to know more about your power.\n"
	.string "Let me register you in my POKéNAV.$"
	.else
	.ifdef GERMAN
	.string "Von dir möchte ich noch mehr erfahren.\n"
	.string "Ich trage dich in meinen POKéNAV ein.$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.ifdef ENGLISH
	.string "Since we met, we have trained hard\n"
	.string "with our sights on number one.\p"
	.string "Help us see how much stronger we've\n"
	.string "become!$"
	.else
	.ifdef GERMAN
	.string "Seit wir uns das letzte Mal gesehen\n"
	.string "haben, haben wir hart trainiert ver-\l"
	.string "glichen mit unserem ersten Kampf.\p"
	.string "Hilf uns, herauszufinden, wie stark wir\n"
	.string "wirklich sind.$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.ifdef ENGLISH
	.string "Urgh!\n"
	.string "I didn't expect you to be so strong!$"
	.else
	.ifdef GERMAN
	.string "Argh!\n"
	.string "Wie kannst du nur so stark sein?$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.ifdef ENGLISH
	.string "You've obviously kept up your\n"
	.string "POKéMON training.\p"
	.string "So long as you remain strong, I, too,\n"
	.string "can become stronger!$"
	.else
	.ifdef GERMAN
	.string "Du hast offenbar fleißig trainiert.\p"
	.string "Solange du stärker wirst, kann auch\n"
	.string "ich stärker werden.$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_JohnIntro:
	.ifdef ENGLISH
	.string "JOHN: We've always battled POKéMON\n"
	.string "together as a twosome.\l"
	.string "We've confidence in ourselves.$"
	.else
	.ifdef GERMAN
	.string "URS: Wir haben immer in trauter Zwei-\n"
	.string "samkeit mit unseren POKéMON gegen\l"
	.string "andere gekämpft. Wir werden siegen!$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_JohnDefeat:
	.ifdef ENGLISH
	.string "JOHN: Oh, my.\n"
	.string "We've lost, dear wife.$"
	.else
	.ifdef GERMAN
	.string "URS: O weh.\n"
	.string "Wir haben verloren, liebstes Weib.$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.ifdef ENGLISH
	.string "JOHN: We've been married for\n"
	.string "fifty years.\p"
	.string "Come to think of it, I've yet to beat\n"
	.string "my dear wife in a battle.$"
	.else
	.ifdef GERMAN
	.string "URS: Wir sind seit 50 Jahren glücklich\n"
	.string "verheiratet.\p"
	.string "Und denk mal, ich habe es noch nie ge-\n"
	.string "schafft, meine Frau zu besiegen.$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.ifdef ENGLISH
	.string "JOHN: Well, well, what a young TRAINER!\p"
	.string "Will you battle with us? If so, you'll\n"
	.string "have to return with more POKéMON.$"
	.else
	.ifdef GERMAN
	.string "URS: Nun, was für ein junger TRAINER!\p"
	.string "Möchtest du mit uns kämpfen? Wenn ja,\n"
	.string "dann musst du dir noch mehr POKéMON\l"
	.string "besorgen.$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_JohnRegister:
	.ifdef ENGLISH
	.string "JOHN: Young TRAINER, if the chance\n"
	.string "arises, will you battle with us again?$"
	.else
	.ifdef GERMAN
	.string "URS: Junger TRAINER! Wenn du die Chance\n"
	.string "hast, wirst du wieder gegen uns\l"
	.string "antreten?$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_JayIntro:
	.ifdef ENGLISH
	.string "JAY: We've been married for\n"
	.string "fifty years.\p"
	.string "The bond we share as a couple could\n"
	.string "never be broken.$"
	.else
	.ifdef GERMAN
	.string "EVI: Wir sind seit 50 Jahren glücklich\n"
	.string "verheiratet.\p"
	.string "Das Band, das uns verbindet, kann\n"
	.string "niemand durchtrennen.$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_JayDefeat:
	.ifdef ENGLISH
	.string "JAY: Oh, dear.\n"
	.string "We've lost, my dear husband.$"
	.else
	.ifdef GERMAN
	.string "EVI: O weh.\n"
	.string "Wir haben verloren, mein Lieber.$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_JayPostBattle:
	.ifdef ENGLISH
	.string "JAY: Fifty years of marriage…\p"
	.string "If we ever argued, we always settled\n"
	.string "it with a POKéMON battle…$"
	.else
	.ifdef GERMAN
	.string "EVI: 50 Jahre verheiratet…\p"
	.string "Immer wenn wir uneinig sind, ent-\n"
	.string "scheiden wir es mit einem POKéMON-\l"
	.string "Kampf.$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.ifdef ENGLISH
	.string "JAY: Well, well, aren't you a young\n"
	.string "TRAINER?\p"
	.string "If you'd care to battle with us, you'll\n"
	.string "have to come back with more POKéMON.$"
	.else
	.ifdef GERMAN
	.string "EVI: Hmm… Bist du nicht ein bisschen zu\n"
	.string "klein für einen TRAINER?\p"
	.string "Möchtest du mit uns kämpfen? Dann\n"
	.string "musst du dir noch mehr POKéMON\l"
	.string "besorgen.$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.ifdef ENGLISH
	.string "JOHN: We've always battled POKéMON\n"
	.string "together as a twosome.\l"
	.string "We've confidence in ourselves.$"
	.else
	.ifdef GERMAN
	.string "URS: Wir haben immer in trauter Zwei-\n"
	.string "samkeit mit unseren POKéMON gegen\l"
	.string "andere gekämpft. Wir werden siegen!$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.ifdef ENGLISH
	.string "JOHN: Oh, my.\n"
	.string "We've lost, dear wife.$"
	.else
	.ifdef GERMAN
	.string "URS: O weh.\n"
	.string "Wir haben verloren, liebstes Weib.$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.ifdef ENGLISH
	.string "JOHN: Married for fifty years…\p"
	.string "On reflection, the dear wife and I,\n"
	.string "we battled day in and day out…$"
	.else
	.ifdef GERMAN
	.string "URS: 50 Jahre verheiratet…\p"
	.string "Rückblickend kann man sagen: Meine\n"
	.string "Frau und ich haben Tag für Tag\l"
	.string "miteinander gekämpft…$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.ifdef ENGLISH
	.string "JOHN: Well, well, what a young TRAINER!\p"
	.string "Will you battle with us? If so, you'll\n"
	.string "have to return with more POKéMON.$"
	.else
	.ifdef GERMAN
	.string "URS: Nun, was für ein junger TRAINER!\p"
	.string "Möchtest du mit uns kämpfen? Wenn ja,\n"
	.string "dann musst du dir noch mehr POKéMON\l"
	.string "besorgen.$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.ifdef ENGLISH
	.string "JAY: We've been married for\n"
	.string "fifty years.\p"
	.string "We've supported each other all that\n"
	.string "time. We've made ourselves strong.$"
	.else
	.ifdef GERMAN
	.string "EVI: Wir sind seit 50 Jahren\n"
	.string "verheiratet.\p"
	.string "Wir haben uns immer gegenseitig unter-\n"
	.string "stützt. Das hat uns stark gemacht.$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.ifdef ENGLISH
	.string "JAY: Oh, dear.\n"
	.string "We've lost, my dear husband.$"
	.else
	.ifdef GERMAN
	.string "EVI: O weh.\n"
	.string "Wir haben verloren, mein Lieber.$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_JayPostRematch:
	.ifdef ENGLISH
	.string "JAY: Fifty years of marriage…\n"
	.string "Many things have happened.\p"
	.string "I hope that we will continue to make\n"
	.string "happy memories together.$"
	.else
	.ifdef GERMAN
	.string "EVI: 50 Jahre verheiratet…\n"
	.string "Vieles ist in dieser Zeit passiert.\p"
	.string "Ich hoffe, wir werden noch lange unsere\n"
	.string "Erinnerungen miteinander teilen\l"
	.string "können.$"
	.endif
	.endif

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.ifdef ENGLISH
	.string "JAY: Well, well, aren't you a young\n"
	.string "TRAINER?\p"
	.string "If you'd care to battle with us, you'll\n"
	.string "have to come back with more POKéMON.$"
	.else
	.ifdef GERMAN
	.string "EVI: Hmm… Bist du nicht ein bisschen zu\n"
	.string "klein für einen TRAINER?\p"
	.string "Möchtest du gegen uns kämpfen? Dann\n"
	.string "musst du dir noch mehr POKéMON\l"
	.string "besorgen.$"
	.endif
	.endif

