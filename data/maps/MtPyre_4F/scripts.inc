MtPyre_4F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi::
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_AtsushiIntro:
	.ifdef ENGLISH
	.string "Teacher…\n"
	.string "Please watch over my progress!$"
	.else
	.ifdef GERMAN
	.string "Mein Lehrer…\n"
	.string "Bitte achtet auf meine Fortschritte!$"
	.endif
	.endif

MtPyre_5F_Text_AtsushiDefeat:
	.ifdef ENGLISH
	.string "Teacher…\n"
	.string "Please forgive me!$"
	.else
	.ifdef GERMAN
	.string "Mein Lehrer…\n"
	.string "Bitte verzeiht mir!$"
	.endif
	.endif

MtPyre_5F_Text_AtsushiPostBattle:
	.ifdef ENGLISH
	.string "Until I improve, my teacher, who rests\n"
	.string "here, will never find true peace…$"
	.else
	.ifdef GERMAN
	.string "Wenn ich nicht besser werde, wird mein\n"
	.string "Lehrer, der hier ruht, keine Ruhe finden.$"
	.endif
	.endif

