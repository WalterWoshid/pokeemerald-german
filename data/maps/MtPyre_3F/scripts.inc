MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.ifdef ENGLISH
	.string "The rich atmosphere of the mountain\n"
	.string "has elevated my psychic power!\p"
	.string "A mere child like you…\n"
	.string "You dream of winning?$"
	.else
	.ifdef GERMAN
	.string "Die unglaubliche Atmosphäre der Berge\n"
	.string "hat meine psychischen Kräfte gestärkt!\p"
	.string "Ein kleines Kind wie du…\n"
	.string "Du willst gewinnen? Träum weiter!$"
	.endif
	.endif

MtPyre_3F_Text_WilliamDefeat:
	.ifdef ENGLISH
	.string "I drown in self-pity…$"
	.else
	.ifdef GERMAN
	.string "Ich vertiefe mich in Selbstmitleid.$"
	.endif
	.endif

MtPyre_3F_Text_WilliamPostBattle:
	.ifdef ENGLISH
	.string "My psychic powers have surely\n"
	.string "grown several times, but…$"
	.else
	.ifdef GERMAN
	.string "Meine psychischen Kräfte sind mit\n"
	.string "Sicherheit stärker geworden, aber…$"
	.endif
	.endif

MtPyre_3F_Text_KaylaIntro:
	.ifdef ENGLISH
	.string "Ahahahaha!\p"
	.string "This is no place for children, least\n"
	.string "of all you!$"
	.else
	.ifdef GERMAN
	.string "Ahahahahaha!!!!!\p"
	.string "Dies ist kein Platz für einen kleinen\n"
	.string "Hosenscheißer wie dich!$"
	.endif
	.endif

MtPyre_3F_Text_KaylaDefeat:
	.ifdef ENGLISH
	.string "I lost that cleanly…$"
	.else
	.ifdef GERMAN
	.string "Oh, ich habe mir in die Hose gemacht.$"
	.endif
	.endif

MtPyre_3F_Text_KaylaPostBattle:
	.ifdef ENGLISH
	.string "This means my training is still not\n"
	.string "enough…\p"
	.string "I've got to keep working toward the\n"
	.string "summit…\p"
	.string "Go, me!$"
	.else
	.ifdef GERMAN
	.string "Mein Training reicht also nicht aus…\p"
	.string "Ich muss mein Training auf die Spitze\n"
	.string "treiben…\p"
	.string "Ich darf keine Zeit verlieren!$"
	.endif
	.endif

MtPyre_3F_Text_GabrielleIntro:
	.ifdef ENGLISH
	.string "Why have you come here?$"
	.else
	.ifdef GERMAN
	.string "Warum bist du hier?$"
	.endif
	.endif

MtPyre_3F_Text_GabrielleDefeat:
	.ifdef ENGLISH
	.string "That was amazing!\n"
	.string "You're a very special TRAINER.$"
	.else
	.ifdef GERMAN
	.string "Das war unglaublich!\n"
	.string "Du bist ein ganz besonderer TRAINER!$"
	.endif
	.endif

MtPyre_3F_Text_GabriellePostBattle:
	.ifdef ENGLISH
	.string "POKéMON no longer of this world.\n"
	.string "POKéMON that are with you now.\p"
	.string "And the POKéMON that you will meet\n"
	.string "in the future…\p"
	.string "They are all to be equally cherished.\n"
	.string "Please remember that.$"
	.else
	.ifdef GERMAN
	.string "POKéMON werden bald nichts Besonderes\n"
	.string "mehr sein.\p"
	.string "Die, die du bei dir hast und die, die dir\n"
	.string "in der Zukunft begegnen werden…\p"
	.string "Sie sollen alle gleich geliebt werden.\n"
	.string "Vergiss das nicht.$"
	.endif
	.endif

MtPyre_3F_Text_GabrielleRegister:
	.ifdef ENGLISH
	.string "I would like to see your POKéMON\n"
	.string "when they grow up some more…\p"
	.string "Please, I need to see your POKéNAV.$"
	.else
	.ifdef GERMAN
	.string "Ich würde mir gerne deine POKéMON\n"
	.string "anschauen, wenn sie stärker geworden\l"
	.string "sind…\p"
	.string "Bitte, zeig sie mir dann unbedingt!$"
	.endif
	.endif

MtPyre_3F_Text_GabrielleRematchIntro:
	.ifdef ENGLISH
	.string "Oh, it's you…\p"
	.string "Have you come to show me your grown\n"
	.string "POKéMON?$"
	.else
	.ifdef GERMAN
	.string "Oh, du bist es…\p"
	.string "Willst du mir zeigen, wie sehr deine\n"
	.string "POKéMON gewachsen und wie stark sie\l"
	.string "geworden sind?$"
	.endif
	.endif

MtPyre_3F_Text_GabrielleRematchDefeat:
	.ifdef ENGLISH
	.string "How amazing!\n"
	.string "You are a special person.$"
	.else
	.ifdef GERMAN
	.string "Unglaublich!\n"
	.string "Du bist etwas ganz Besonderes.$"
	.endif
	.endif

MtPyre_3F_Text_GabriellePostRematch:
	.ifdef ENGLISH
	.string "POKéMON no longer of this world.\n"
	.string "POKéMON that are with you now.\p"
	.string "And the POKéMON that you will meet\n"
	.string "in the future…\p"
	.string "They are all to be equally cherished.\n"
	.string "I see that you've remembered that.$"
	.else
	.ifdef GERMAN
	.string "POKéMON werden bald nichts Besonderes\n"
	.string "mehr sein.\p"
	.string "Die, die du bei dir hast und die, die dir\n"
	.string "in der Zukunft begegnen werden…\p"
	.string "Sie sollen alle gleich geliebt werden.\n"
	.string "Du hast es also nicht vergessen.$"
	.endif
	.endif

