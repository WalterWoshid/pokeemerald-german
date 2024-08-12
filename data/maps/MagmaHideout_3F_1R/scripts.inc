MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.ifdef ENGLISH
	.string "What did I do to deserve this guard\n"
	.string "posting?\p"
	.string "My left ear is burning up!$"
	.else
	.ifdef GERMAN
	.string "Was habe ich nur getan, dass ich hier\n"
	.string "Wache schieben muss?\p"
	.string "Mein linkes Ohr brennt schon wie\n"
	.string "verrückt.$"
	.endif
	.endif

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.ifdef ENGLISH
	.string "I'm getting heat exhaustion…$"
	.else
	.ifdef GERMAN
	.string "Ich bekomme gleich einen Hitzschlag…$"
	.endif
	.endif

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.ifdef ENGLISH
	.string "Do you think it's odd that we're wearing\n"
	.string "hoods in this magma-filled volcano?$"
	.else
	.ifdef GERMAN
	.string "Findest du es merkwürdig, dass wir auf\n"
	.string "diesem Vulkan auch noch Hüte tragen?$"
	.endif
	.endif

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.ifdef ENGLISH
	.string "We joined so we can help our leader\n"
	.string "achieve his fantastic vision.\p"
	.string "I don't care if you're with TEAM AQUA\n"
	.string "or if you're just some kid passing by.\p"
	.string "No one interferes with us and gets\n"
	.string "away with it!$"
	.else
	.ifdef GERMAN
	.string "Wir haben uns zusammengeschlossen,\n"
	.string "damit seine fantastische Vision\l"
	.string "Wirklichkeit wird.\p"
	.string "Es ist mir schnurzegal, ob du zu TEAM\n"
	.string "AQUA gehörst oder einfach nur ein Kind\l"
	.string "bist, das hier vorbeikommt.\p"
	.string "Niemand mischt sich in unsere Belange\n"
	.string "ein und kommt ungeschoren davon!$"
	.endif
	.endif

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.ifdef ENGLISH
	.string "Oh, no!\n"
	.string "You're not to be trusted at all!$"
	.else
	.ifdef GERMAN
	.string "Oh, nein!\n"
	.string "Dich habe ich ganz falsch eingeschätzt.$"
	.endif
	.endif

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.ifdef ENGLISH
	.string "Listen to me.\n"
	.string "TEAM MAGMA is right!\p"
	.string "Don't listen to TEAM AQUA.\n"
	.string "Don't believe their lies!$"
	.else
	.ifdef GERMAN
	.string "Hör zu!\n"
	.string "TEAM MAGMA hat Recht!\p"
	.string "Hör nicht auf TEAM AQUA!\n"
	.string "Glaub ihren Lügen nicht.$"
	.endif
	.endif

