MtPyre_5F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro:
	.ifdef ENGLISH
	.string "I love all things horrifying…\n"
	.string "It's like a disease…\p"
	.string "When I'm here…\n"
	.string "I shiver with fear…$"
	.else
	.ifdef GERMAN
	.string "Ich mag gruselige Horrordinge…\n"
	.string "Es ist wie eine Sucht…\p"
	.string "Sobald ich hier bin…\n"
	.string "stehen mir die Haare zu Berge.$"
	.endif
	.endif

MtPyre_4F_Text_TashaDefeat:
	.ifdef ENGLISH
	.string "Losing, I dislike…$"
	.else
	.ifdef GERMAN
	.string "Ich hasse Niederlagen…$"
	.endif
	.endif

MtPyre_4F_Text_TashaPostBattle:
	.ifdef ENGLISH
	.string "I want to see dreadful things…\n"
	.string "I can't leave…\p"
	.string "Stay…\n"
	.string "Won't you stay with me?$"
	.else
	.ifdef GERMAN
	.string "Ich will unheimliche Dinge sehen…\n"
	.string "Ich kann nicht weggehen…\p"
	.string "Muss bleiben…\n"
	.string "Willst du nicht bei mir bleiben?$"
	.endif
	.endif

