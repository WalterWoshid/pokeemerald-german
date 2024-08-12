VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.ifdef ENGLISH
	.string "I trained together with my whole family,\n"
	.string "every one of us!\l"
	.string "I'm not losing to anyone!$"
	.else
	.ifdef GERMAN
	.string "Ich habe mit meiner Familie trainiert,\n"
	.string "mit jedem einzelnen Mitglied!\l"
	.string "Ich verliere gegen niemanden!$"
	.endif
	.endif

VictoryRoad_B2F_Text_VitoDefeat:
	.ifdef ENGLISH
	.string "Better than my family?!\n"
	.string "Is that possible?!$"
	.else
	.ifdef GERMAN
	.string "Besser als meine Familie?\n"
	.string "Ist das möglich?$"
	.endif
	.endif

VictoryRoad_B2F_Text_VitoPostBattle:
	.ifdef ENGLISH
	.string "I was better than everyone in my\n"
	.string "family. I've never lost before…\p"
	.string "I've lost my confidence…\n"
	.string "Maybe I'll go home…$"
	.else
	.ifdef GERMAN
	.string "Ich war besser als jeder andere aus\n"
	.string "meiner Familie. Ich habe nie verloren!\p"
	.string "Ich habe mein Selbstvertrauen ver-\n"
	.string "loren. Ich gehe nach Hause…$"
	.endif
	.endif

VictoryRoad_B2F_Text_OwenIntro:
	.ifdef ENGLISH
	.string "I'd heard that there was a tough\n"
	.string "little kid around. Do they mean you?$"
	.else
	.ifdef GERMAN
	.string "Ich habe gehört, dass sich hier ein sehr\n"
	.string "starkes Kind herumtreibt. Bist du das?$"
	.endif
	.endif

VictoryRoad_B2F_Text_OwenDefeat:
	.ifdef ENGLISH
	.string "The little shrimp is tough!$"
	.else
	.ifdef GERMAN
	.string "Diese kleine Kröte ist echt stark!$"
	.endif
	.endif

VictoryRoad_B2F_Text_OwenPostBattle:
	.ifdef ENGLISH
	.string "The rumors I heard, that tough little\n"
	.string "kid is from PETALBURG CITY.$"
	.else
	.ifdef GERMAN
	.string "Das Gerücht sagt, das Kind käme aus\n"
	.string "BLÜTENBURG CITY.$"
	.endif
	.endif

VictoryRoad_B2F_Text_CarolineIntro:
	.ifdef ENGLISH
	.string "You must be getting a little tired.$"
	.else
	.ifdef GERMAN
	.string "Du musst doch langsam mal müde werden.$"
	.endif
	.endif

VictoryRoad_B2F_Text_CarolineDefeat:
	.ifdef ENGLISH
	.string "No signs of tiring at all!$"
	.else
	.ifdef GERMAN
	.string "Keine Anzeichen von Müdigkeit…$"
	.endif
	.endif

VictoryRoad_B2F_Text_CarolinePostBattle:
	.ifdef ENGLISH
	.string "VICTORY ROAD and the POKéMON LEAGUE\n"
	.string "are long and grueling challenges.\l"
	.string "Beware of fatigue!$"
	.else
	.ifdef GERMAN
	.string "Die SIEGESSTRASSE und die POKéMON\n"
	.string "LIGA sind große und langwierige Heraus-\l"
	.string "forderungen. Werde bloß nicht müde!!!$"
	.endif
	.endif

VictoryRoad_B2F_Text_JulieIntro:
	.ifdef ENGLISH
	.string "You shouldn't get complacent just\n"
	.string "because you have a lot of GYM BADGES.\p"
	.string "There's always going to be someone\n"
	.string "who's better than you!$"
	.else
	.ifdef GERMAN
	.string "Du solltest nicht selbstzufrieden\n"
	.string "werden, nur weil du viele ORDEN der\l"
	.string "ARENen besitzt.\p"
	.string "Es wird immer jemanden geben, der\n"
	.string "besser ist als du!$"
	.endif
	.endif

VictoryRoad_B2F_Text_JulieDefeat:
	.ifdef ENGLISH
	.string "You're better than me!$"
	.else
	.ifdef GERMAN
	.string "Du bist besser als ich!$"
	.endif
	.endif

VictoryRoad_B2F_Text_JuliePostBattle:
	.ifdef ENGLISH
	.string "Gaze on your collected BADGES and\n"
	.string "remember the TRAINERS you've faced.$"
	.else
	.ifdef GERMAN
	.string "Schau dir deine ORDEN an - erinnere dich\n"
	.string "an die TRAINER, die du getroffen hast.$"
	.endif
	.endif

VictoryRoad_B2F_Text_FelixIntro:
	.ifdef ENGLISH
	.string "I've come this far, but the tension's\n"
	.string "giving me awful stomach pain…$"
	.else
	.ifdef GERMAN
	.string "Ich bin weit gekommen, aber die\n"
	.string "Anspannung verursacht mir\l"
	.string "Magenschmerzen…$"
	.endif
	.endif

VictoryRoad_B2F_Text_FelixDefeat:
	.ifdef ENGLISH
	.string "Ooh…\n"
	.string "It hurts…$"
	.else
	.ifdef GERMAN
	.string "Ooh…\n"
	.string "Es tut weh…$"
	.endif
	.endif

VictoryRoad_B2F_Text_FelixPostBattle:
	.ifdef ENGLISH
	.string "I can't help getting all tense knowing\n"
	.string "that I'm nearing the POKéMON LEAGUE.\p"
	.string "It's all I can do to feign calm.$"
	.else
	.ifdef GERMAN
	.string "Ich kann nicht anders. Hier in der Nähe\n"
	.string "der POKéMON LIGA bin ich total nervös\l"
	.string "und angespannt.\p"
	.string "Ich tue so, als sei ich die Ruhe selbst.$"
	.endif
	.endif

VictoryRoad_B2F_Text_DianneIntro:
	.ifdef ENGLISH
	.string "The elite among the elite gather in\n"
	.string "this cave.\p"
	.string "How are you finding it?$"
	.else
	.ifdef GERMAN
	.string "Die Elite der Elite versammelt sich in\n"
	.string "dieser Höhle.\p"
	.string "Wie findest du das?$"
	.endif
	.endif

VictoryRoad_B2F_Text_DianneDefeat:
	.ifdef ENGLISH
	.string "Not rattled in the least bit!$"
	.else
	.ifdef GERMAN
	.string "Nicht ein bisschen erschüttert.$"
	.endif
	.endif

VictoryRoad_B2F_Text_DiannePostBattle:
	.ifdef ENGLISH
	.string "You do have guts! I like that!\n"
	.string "Keep it going!$"
	.else
	.ifdef GERMAN
	.string "Du hast echt Nerven! Das mag ich!\n"
	.string "Mach weiter so!$"
	.endif
	.endif

