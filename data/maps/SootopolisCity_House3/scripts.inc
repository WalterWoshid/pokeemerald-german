SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.ifdef ENGLISH
	.string "You're a POKéMON TRAINER, aren't you?\p"
	.string "SOOTOPOLIS's JUAN has many fans.\n"
	.string "Even more than his student WALLACE!\p"
	.string "Do you have any?$"
	.else
	.ifdef GERMAN
	.string "Du bist ein POKéMON-TRAINER, oder?\p"
	.string "Der ARENALEITER von XENEROVILLE, \n"
	.string "JUAN, hat viele Fans.\p"
	.string "Mehr als sein Schüler WASSILI.\n"
	.string "Hast du auch Fans?$"
	.endif
	.endif

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.ifdef ENGLISH
	.string "Oh, then you must be pretty strong.$"
	.else
	.ifdef GERMAN
	.string "Oh, dann musst du aber sehr stark sein.$"
	.endif
	.endif

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.ifdef ENGLISH
	.string "Oh, dear…\n"
	.string "That's a little lonesome.\p"
	.string "Try working a little harder to get\n"
	.string "a fan following.$"
	.else
	.ifdef GERMAN
	.string "Oh, meine Güte…\n"
	.string "Dann stehst du ja ganz alleine da.\p"
	.string "Streng dich einfach mehr an, dann\n"
	.string "bekommst du auch einen Fan.$"
	.endif
	.endif

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.ifdef ENGLISH
	.string "Dedicated fans come over from even\n"
	.string "outside of HOENN.\p"
	.string "It was really wild when I went to the\n"
	.string "TRAINER FAN CLUB in LILYCOVE.$"
	.else
	.ifdef GERMAN
	.string "Die Fans kommen auch von außerhalb\n"
	.string "von HOENN herbeigeströmt.\p"
	.string "Ich habe den TRAINER-FANCLUB in\n"
	.string "SEEGRASULB CITY besucht.\l"
	.string "Verrückte Sache…$"
	.endif
	.endif

