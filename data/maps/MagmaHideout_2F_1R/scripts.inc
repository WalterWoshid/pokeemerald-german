MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.ifdef ENGLISH
	.string "What, what, what?\p"
	.string "Only TEAM MAGMA members are supposed\n"
	.string "to be in here!\p"
	.string "But you're not dressed in TEAM MAGMA's\n"
	.string "uniform…\p"
	.string "You rouse my suspicion!\n"
	.string "Battle with me!$"
	.else
	.ifdef GERMAN
	.string "Was, wie, wer?\p"
	.string "Nur Mitglieder von TEAM MAGMA dürfen\n"
	.string "hier sein.\p"
	.string "Aber du hast keine Uniform von TEAM\n"
	.string "MAGMA an…\p"
	.string "Das erregt Verdacht!\n"
	.string "Kämpf mit mir!$"
	.endif
	.endif

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.ifdef ENGLISH
	.string "Aiyiyi…\n"
	.string "My pride as a TEAM MAGMA member…$"
	.else
	.ifdef GERMAN
	.string "Aiyiyi…\n"
	.string "Mein Stolz als Mitglied von TEAM MAGMA…$"
	.endif
	.endif

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.ifdef ENGLISH
	.string "If you suffer from chills, you should\n"
	.string "join TEAM MAGMA.$"
	.else
	.ifdef GERMAN
	.string "Wenn du an Schüttelfrost leidest,\n"
	.string "solltest du TEAM MAGMA beitreten.$"
	.endif
	.endif

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.ifdef ENGLISH
	.string "Hold it right there!\p"
	.string "You don't really expect me to keep\n"
	.string "my trap shut and let you waltz by me?$"
	.else
	.ifdef GERMAN
	.string "Stopp!\p"
	.string "Du erwartest doch nicht ernsthaft,\n"
	.string "dass ich dich einfach so vorbeigehen\l"
	.string "lasse?!?$"
	.endif
	.endif

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.ifdef ENGLISH
	.string "Ooh wow!\n"
	.string "I concede!$"
	.else
	.ifdef GERMAN
	.string "Ooh wow!\n"
	.string "Ich gebe mich geschlagen!$"
	.endif
	.endif

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.ifdef ENGLISH
	.string "Maybe it would've been better if I did\n"
	.string "just let you go unchallenged…$"
	.else
	.ifdef GERMAN
	.string "Es wäre vielleicht doch besser gewesen,\n"
	.string "dich nicht herauszufordern…$"
	.endif
	.endif

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.ifdef ENGLISH
	.string "Ahah!\n"
	.string "An intruder!$"
	.else
	.ifdef GERMAN
	.string "Ahah!\n"
	.string "Ein Eindringling!$"
	.endif
	.endif

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.ifdef ENGLISH
	.string "Graaah!$"
	.else
	.ifdef GERMAN
	.string "Graah!$"
	.endif
	.endif

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.ifdef ENGLISH
	.string "I've already lost.\p"
	.string "Do I really need to keep running\n"
	.string "around in a circle?$"
	.else
	.ifdef GERMAN
	.string "Ich habe doch schon verloren!\p"
	.string "Musst du unbedingt im Kreis\n"
	.string "herumlaufen?$"
	.endif
	.endif

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.ifdef ENGLISH
	.string "Oh, oh!\n"
	.string "An intruder!$"
	.else
	.ifdef GERMAN
	.string "Oh oh!\n"
	.string "Ein Eindringling!$"
	.endif
	.endif

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.ifdef ENGLISH
	.string "Mutter…$"
	.else
	.ifdef GERMAN
	.string "Murmel…$"
	.endif
	.endif

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.ifdef ENGLISH
	.string "Actually, I'm no expert at battling…$"
	.else
	.ifdef GERMAN
	.string "Eigentlich bin ich kein Kampf-Experte…$"
	.endif
	.endif

