MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro:
	.ifdef ENGLISH
	.string "I don't have a bone to pick with you.\n"
	.string "I'm just following orders!$"
	.else
	.ifdef GERMAN
	.string "Ich habe nichts gegen dich!\n"
	.string "Aber ich habe meine Befehle.$"
	.endif
	.endif

MagmaHideout_2F_2R_Text_Grunt15Defeat:
	.ifdef ENGLISH
	.string "I may have lost, but…$"
	.else
	.ifdef GERMAN
	.string "Ich mag vielleicht verloren haben,\n"
	.string "aber…$"
	.endif
	.endif

MagmaHideout_2F_2R_Text_Grunt15PostBattle:
	.ifdef ENGLISH
	.string "We dug up something beyond belief!\n"
	.string "And, we got the BLUE ORB!\p"
	.string "All that's left is for our leader to…\n"
	.string "Fufufu… Fwahahaha!$"
	.else
	.ifdef GERMAN
	.string "Wir haben etwas Unglaubliches\n"
	.string "ausgegraben! Und… wir haben die BLAUE\l"
	.string "KUGEL!\p"
	.string "Nun muss unser Boss nur noch…\n"
	.string "Hahaha… Muahahahahahaha!$"
	.endif
	.endif

MagmaHideout_2F_2R_Text_Grunt6Intro:
	.ifdef ENGLISH
	.string "I can't stand heat. Maybe I should've\n"
	.string "joined TEAM AQUA instead…$"
	.else
	.ifdef GERMAN
	.string "Ich hasse Hitze! Ich hätte mich lieber\n"
	.string "TEAM AQUA anschließen sollen…$"
	.endif
	.endif

MagmaHideout_2F_2R_Text_Grunt6Defeat:
	.ifdef ENGLISH
	.string "Yeah, I really may not be right for\n"
	.string "TEAM MAGMA…$"
	.else
	.ifdef GERMAN
	.string "Ich bin tatsächlich nicht geschaffen\n"
	.string "für TEAM MAGMA…$"
	.endif
	.endif

MagmaHideout_2F_2R_Text_Grunt6PostBattle:
	.ifdef ENGLISH
	.string "Don't you get lonely for the sea\n"
	.string "being in a place like this?$"
	.else
	.ifdef GERMAN
	.string "Bekommst du an einem Ort wie diesem\n"
	.string "nicht Sehnsucht nach dem Meer?$"
	.endif
	.endif

MagmaHideout_2F_2R_Text_Grunt7Intro:
	.ifdef ENGLISH
	.string "You can hear tremors here sometimes.\p"
	.string "Could it be the volcano rattling?\n"
	.string "Or is it GROU…\p"
	.string "Whoops!\n"
	.string "No, no, never mind!$"
	.else
	.ifdef GERMAN
	.string "Ab und zu bemerkt man hier\n"
	.string "Erschütterungen.\p"
	.string "Ob der Vulkan daran schuld ist?\n"
	.string "Oder ist es GROU…\p"
	.string "Huuups!\n"
	.string "Ach, egal! Dummdidumm…$"
	.endif
	.endif

MagmaHideout_2F_2R_Text_Grunt7Defeat:
	.ifdef ENGLISH
	.string "You're a fiery battler.\n"
	.string "Just like a volcano!$"
	.else
	.ifdef GERMAN
	.string "Du bist ein hitziger Kämpfer.\n"
	.string "Wie ein Vulkan.$"
	.endif
	.endif

MagmaHideout_2F_2R_Text_Grunt7PostBattle:
	.ifdef ENGLISH
	.string "You just happened to win this time,\n"
	.string "but that doesn't matter.\p"
	.string "TEAM MAGMA's goal is about to be\n"
	.string "reached!$"
	.else
	.ifdef GERMAN
	.string "Dieses Mal hast du es tatsächlich\n"
	.string "geschafft, zu gewinnen. Aber das macht\l"
	.string "überhaupt nichts.\p"
	.string "TEAM MAGMA ist bald am Ziel.$"
	.endif
	.endif

MagmaHideout_2F_2R_Text_Grunt8Intro:
	.ifdef ENGLISH
	.string "One of our guys was freaking out that\n"
	.string "he lost his MAGMA EMBLEM…\p"
	.string "Wait a minute!\n"
	.string "Was it you who found it?$"
	.else
	.ifdef GERMAN
	.string "Eines unserer Mitglieder ist aus-\n"
	.string "gerastet. Es hat sein MAGMAEMBLEM\l"
	.string "verloren!\p"
	.string "Warte mal! Du hast das doch nicht\n"
	.string "etwa gefunden?!?$"
	.endif
	.endif

MagmaHideout_2F_2R_Text_Grunt8Defeat:
	.ifdef ENGLISH
	.string "I'm having trouble believing this…$"
	.else
	.ifdef GERMAN
	.string "Das kann ich einfach nicht glauben…$"
	.endif
	.endif

MagmaHideout_2F_2R_Text_Grunt8PostBattle:
	.ifdef ENGLISH
	.string "I'm getting this feeling that our plan\n"
	.string "is going to end in failure…$"
	.else
	.ifdef GERMAN
	.string "Ich habe das Gefühl, dass unser Plan\n"
	.string "scheitern wird…$"
	.endif
	.endif

