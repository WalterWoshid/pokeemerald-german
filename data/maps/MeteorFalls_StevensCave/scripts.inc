.set LOCALID_STEVEN, 1

MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.ifdef ENGLISH
	.string "STEVEN: Oh, wow, {PLAYER}{KUN}.\n"
	.string "I'm amazed you knew where to find me.\p"
	.string "Do you, uh…maybe think of me as\n"
	.string "just a rock maniac?\p"
	.string "No, that can't be right.\p"
	.string "We battled alongside each other at\n"
	.string "the SOOTOPOLIS SPACE CENTER.\p"
	.string "You should have a very good idea\n"
	.string "about how good I am.\p"
	.string "Okay, {PLAYER}{KUN}, if you're going to mount\n"
	.string "a serious challenge, expect the worst!$"
	.else
	.ifdef GERMAN
	.string "TROY: Oh, wow, {PLAYER}{KUN}!\n"
	.string "Ich bin erstaunt, dass du mich\l"
	.string "gefunden hast!\p"
	.string "Du, äh… denkst bestimmt, ich bin nur\n"
	.string "verrückt nach Steinen, nicht wahr?\p"
	.string "Nein, das tust du bestimmt nicht.\p"
	.string "Wir haben ja schon als Team im\n"
	.string "MOOSBACH CITY RAUMFAHRTZENTRUM\l"
	.string "gekämpft.\p"
	.string "Da hast du bestimmt einen Eindruck\n"
	.string "davon gewonnen, wie gut ich bin.\p"
	.string "Okay, {PLAYER}{KUN}, wenn du dich auf eine\n"
	.string "ernsthafte Herausforderung einlässt,\l"
	.string "sei auf das Schlimmste gefasst!$"
	.endif
	.endif

MeteorFalls_StevensCave_Text_StevenDefeat:
	.ifdef ENGLISH
	.string "You…\n"
	.string "I had no idea you'd become so strong…$"
	.else
	.ifdef GERMAN
	.string "Du…\n"
	.string "Ich hätte nie gedacht, dass du so stark\l"
	.string "werden würdest…$"
	.endif
	.endif

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.ifdef ENGLISH
	.string "STEVEN: Come to think of it, ever since\n"
	.string "our paths first crossed in GRANITE\l"
	.string "CAVE in DEWFORD, I had this feeling.\p"
	.string "I thought that you would eventually\n"
	.string "become the CHAMPION.\p"
	.string "My predictions usually come true.\p"
	.string "And where will you go from here?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Fufufu, even I couldn't tell you that.$"
	.else
	.ifdef GERMAN
	.string "TROY: Aber, wenn ich es recht bedenke…\n"
	.string "Damals, als wir uns zum ersten Mal in der\p"
	.string "GRANITHÖHLE von FAUSTAUHAVEN\n"
	.string "begegneten, hatte ich schon dieses\l"
	.string "Gefühl.\p"
	.string "Ich wusste, du würdest irgendwann der\n"
	.string "CHAMP werden.\p"
	.string "Und mein Gefühl trügt mich nie!\p"
	.string "Wohin wird dein Weg dich jetzt führen?\p"
	.string "… … … … …\n"
	.string "…\l"
	.string "… … … … …\l"
	.string "…\p"
	.string "Hähähähä, das kann selbst ich dir\n"
	.string "nicht sagen.$"
	.endif
	.endif

