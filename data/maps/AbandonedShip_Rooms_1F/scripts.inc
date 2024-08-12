AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.ifdef ENGLISH
	.string "Ships of this sort are rare, so I'm\n"
	.string "taking a look around.\p"
	.string "Hmhm…\n"
	.string "There appear to be other cabins…$"
	.else
	.ifdef GERMAN
	.string "Schiffe dieser Art sind sehr selten,\n"
	.string "daher schaue ich mich hier gut um.\p"
	.string "Hmhm…\n"
	.string "Da sind die anderen Kabinen…$"
	.endif
	.endif

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.ifdef ENGLISH
	.string "What on earth would compel you to\n"
	.string "come here? You must be curious!$"
	.else
	.ifdef GERMAN
	.string "Was bringt dich hierher?\n"
	.string "Das ist bestimmt die schiere Neugier.$"
	.endif
	.endif

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.ifdef ENGLISH
	.string "Not just curious, but also strong…$"
	.else
	.ifdef GERMAN
	.string "Nicht nur neugierig, sondern auch\n"
	.string "stark…$"
	.endif
	.endif

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.ifdef ENGLISH
	.string "The man next door…\p"
	.string "He says he's just sightseeing,\n"
	.string "but I don't know about that.$"
	.else
	.ifdef GERMAN
	.string "Der Mann nebenan…\p"
	.string "Er sagt, er habe nur einen Ausflug\n"
	.string "hierher gemacht, aber Genaues\l"
	.string "weiß ich auch nicht…$"
	.endif
	.endif

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.ifdef ENGLISH
	.string "You're such a tough TRAINER!\n"
	.string "Let me register you as a memento!$"
	.else
	.ifdef GERMAN
	.string "Du bist so ein starker TRAINER!\n"
	.string "Ich werde dich zur Erinnerung im\l"
	.string "POKéNAV eintragen.$"
	.endif
	.endif

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.ifdef ENGLISH
	.string "What on earth would compel you to\n"
	.string "come back? You must really be curious!$"
	.else
	.ifdef GERMAN
	.string "Was bringt dich hierher?\n"
	.string "Das ist bestimmt die schiere Neugier.$"
	.endif
	.endif

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.ifdef ENGLISH
	.string "Aren't you too strong?$"
	.else
	.ifdef GERMAN
	.string "Bist du nicht ein bisschen zu stark?$"
	.endif
	.endif

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.ifdef ENGLISH
	.string "I'm sure that man's up to something!\n"
	.string "He just acts so suspiciously!$"
	.else
	.ifdef GERMAN
	.string "Ich bin sicher, der Mann hat was vor!\n"
	.string "Der benimmt sich ganz eigenartig!$"
	.endif
	.endif

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.ifdef ENGLISH
	.string "Waaah!\n"
	.string "I've been found! …Huh?$"
	.else
	.ifdef GERMAN
	.string "Waaaah!\n"
	.string "Ich wurde entdeckt! Häh…$"
	.endif
	.endif

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.ifdef ENGLISH
	.string "Oh, you're not my mom.$"
	.else
	.ifdef GERMAN
	.string "Oh, du bist ja gar nicht meine Mama!$"
	.endif
	.endif

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.ifdef ENGLISH
	.string "I'm in trouble with my mom, so I ran.\n"
	.string "Keep it a secret where I am!$"
	.else
	.ifdef GERMAN
	.string "Ich habe mich mit meiner Mama gezankt\n"
	.string "und verstecke mich jetzt.\l"
	.string "Verrat mich nicht!$"
	.endif
	.endif

