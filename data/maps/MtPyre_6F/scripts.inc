MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
	.ifdef ENGLISH
	.string "When I'm here…\n"
	.string "A curious power flows into me…$"
	.else
	.ifdef GERMAN
	.string "Wenn ich hier bin… dann durchströmt\n"
	.string "mich eine seltsame Macht…$"
	.endif
	.endif

MtPyre_6F_Text_ValerieDefeat:
	.ifdef ENGLISH
	.string "The power is ebbing away…$"
	.else
	.ifdef GERMAN
	.string "Die Macht ebbt ab…$"
	.endif
	.endif

MtPyre_6F_Text_ValeriePostBattle:
	.ifdef ENGLISH
	.string "Perhaps the power is from the spirits\n"
	.string "of POKéMON in fitful sleep here…$"
	.else
	.ifdef GERMAN
	.string "Die Geister der hier ruhenden POKéMON,\n"
	.string "erfüllen mich mit ihrer Macht…$"
	.endif
	.endif

MtPyre_6F_Text_ValerieRegister:
	.ifdef ENGLISH
	.string "Fufufu… I lost the match, but…\n"
	.string "I have this little ability…\p"
	.string "Without ever laying my hands on\n"
	.string "your POKéNAV… Hiyah!$"
	.else
	.ifdef GERMAN
	.string "Hähähä… Ich habe den Kampf verloren,\n"
	.string "aber… ich habe dieses Talent…\p"
	.string "Ohne, dass ich den POKéNAV berühren\n"
	.string "muss… Hiyah!$"
	.endif
	.endif

MtPyre_6F_Text_ValerieRematchIntro:
	.ifdef ENGLISH
	.string "Behind you…\n"
	.string "What is it…$"
	.else
	.ifdef GERMAN
	.string "Hinter dir…\n"
	.string "W… Was ist das?$"
	.endif
	.endif

MtPyre_6F_Text_ValerieRematchDefeat:
	.ifdef ENGLISH
	.string "Something faded away…$"
	.else
	.ifdef GERMAN
	.string "Etwas war da und verschwand…$"
	.endif
	.endif

MtPyre_6F_Text_ValeriePostRematch:
	.ifdef ENGLISH
	.string "The POKéMON at rest here…\n"
	.string "Sometimes, they play…$"
	.else
	.ifdef GERMAN
	.string "Die POKéMON, die hier ruhen…\n"
	.string "Manchmal spielen sie…$"
	.endif
	.endif

MtPyre_6F_Text_CedricIntro:
	.ifdef ENGLISH
	.string "Have you lost your bearings?\n"
	.string "Have no fear for I am here!$"
	.else
	.ifdef GERMAN
	.string "Hast du die Orientierung verloren?\n"
	.string "Keine Angst, ich bin ja hier.$"
	.endif
	.endif

MtPyre_6F_Text_CedricDefeat:
	.ifdef ENGLISH
	.string "Weren't you lost?$"
	.else
	.ifdef GERMAN
	.string "Du hattest die Orientierung gar\n"
	.string "nicht verloren?$"
	.endif
	.endif

MtPyre_6F_Text_CedricPostBattle:
	.ifdef ENGLISH
	.string "I had this feeling that a lost TRAINER\n"
	.string "would be panicked and easy to beat.\p"
	.string "It's dirty and I won't try it again…$"
	.else
	.ifdef GERMAN
	.string "Mein Gefühl sagte mir, dass ein TRAINER,\n"
	.string "der sich verlaufen hat, panisch\l"
	.string "reagiert und leichter zu besiegen ist.\p"
	.string "Das war ein schmutziger Versuch…$"
	.endif
	.endif

