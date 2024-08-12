SootopolisCity_Gym_B1F_MapScripts::
	.byte 0

SootopolisCity_Gym_B1F_EventScript_Andrea::
	trainerbattle_single TRAINER_ANDREA, SootopolisCity_Gym_B1F_Text_AndreaIntro, SootopolisCity_Gym_B1F_Text_AndreaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AndreaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Crissy::
	trainerbattle_single TRAINER_CRISSY, SootopolisCity_Gym_B1F_Text_CrissyIntro, SootopolisCity_Gym_B1F_Text_CrissyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Brianna::
	trainerbattle_single TRAINER_BRIANNA, SootopolisCity_Gym_B1F_Text_BriannaIntro, SootopolisCity_Gym_B1F_Text_BriannaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BriannaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Connie::
	trainerbattle_single TRAINER_CONNIE, SootopolisCity_Gym_B1F_Text_ConnieIntro, SootopolisCity_Gym_B1F_Text_ConnieDefeat
	msgbox SootopolisCity_Gym_B1F_Text_ConniePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET, SootopolisCity_Gym_B1F_Text_BridgetIntro, SootopolisCity_Gym_B1F_Text_BridgetDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA, SootopolisCity_Gym_B1F_Text_OliviaIntro, SootopolisCity_Gym_B1F_Text_OliviaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_OliviaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY, SootopolisCity_Gym_B1F_Text_TiffanyIntro, SootopolisCity_Gym_B1F_Text_TiffanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_TiffanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bethany::
	trainerbattle_single TRAINER_BETHANY, SootopolisCity_Gym_B1F_Text_BethanyIntro, SootopolisCity_Gym_B1F_Text_BethanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Annika::
	trainerbattle_single TRAINER_ANNIKA, SootopolisCity_Gym_B1F_Text_AnnikaIntro, SootopolisCity_Gym_B1F_Text_AnnikaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AnnikaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Daphne::
	trainerbattle_single TRAINER_DAPHNE, SootopolisCity_Gym_B1F_Text_DaphneIntro, SootopolisCity_Gym_B1F_Text_DaphneDefeat
	msgbox SootopolisCity_Gym_B1F_Text_DaphnePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_Text_AndreaIntro:
	.ifdef ENGLISH
	.string "I'll show you the sublime techniques\n"
	.string "I learned from our LEADER JUAN!$"
	.else
	.ifdef GERMAN
	.string "Ich zeige dir die sublimen Techniken,\n"
	.string "die ich vom ARENALEITER JUAN\l"
	.string "gelernt habe.$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_AndreaDefeat:
	.ifdef ENGLISH
	.string "Please forgive me, JUAN…$"
	.else
	.ifdef GERMAN
	.string "Bitte verzeih mir, JUAN…$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_AndreaPostBattle:
	.ifdef ENGLISH
	.string "Watch what happens if you crack all\n"
	.string "the floor tiles.$"
	.else
	.ifdef GERMAN
	.string "Pass auf, was passiert, wenn du alle\n"
	.string "Bodenfliesen betreten hast…$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_CrissyIntro:
	.ifdef ENGLISH
	.string "You came all the way here, but you won't\n"
	.string "get to see JUAN.\p"
	.string "Not if you lose to me, you won't!$"
	.else
	.ifdef GERMAN
	.string "Du bist den ganzen Weg hierher ge-\n"
	.string "kommen, aber bis zu JUAN dringst\l"
	.string "du nicht vor.\p"
	.string "Weil du gegen mich verlieren wirst!$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_CrissyDefeat:
	.ifdef ENGLISH
	.string "You're strong!\n"
	.string "I was fooled by your cute looks!$"
	.else
	.ifdef GERMAN
	.string "Du bist stark! Ich habe mich durch dein\n"
	.string "unschuldiges Aussehen täuschen\l"
	.string "lassen.$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_CrissyPostBattle:
	.ifdef ENGLISH
	.string "You might be good enough to avoid\n"
	.string "being wiped out in one hit by JUAN.$"
	.else
	.ifdef GERMAN
	.string "Du bist gut genug, um nicht sofort von\n"
	.string "JUAN besiegt zu werden.$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_DaphneIntro:
	.ifdef ENGLISH
	.string "The sight of JUAN conducting\n"
	.string "a battle…\p"
	.string "The very beauty of it compelled me to\n"
	.string "become a TRAINER.$"
	.else
	.ifdef GERMAN
	.string "Die Art, wie JUAN kämpft…\p"
	.string "Dieser wunderbare Anblick hat mich dazu\n"
	.string "inspiriert, TRAINER zu werden.$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_DaphneDefeat:
	.ifdef ENGLISH
	.string "You battled with more beauty than\n"
	.string "I could muster…$"
	.else
	.ifdef GERMAN
	.string "Du kämpfst mit mehr Anmut als ich…$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_DaphnePostBattle:
	.ifdef ENGLISH
	.string "The grace you bring to battle is\n"
	.string "fabulous.\p"
	.string "Oh… I'm so fortunate to have found\n"
	.string "POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Die Ästhetik, die du in den Kampf ein-\n"
	.string "bringst, ist unbeschreiblich.\p"
	.string "Oh… Ich bin so glücklich, dass ich mich\n"
	.string "für POKéMON entschieden habe.$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_ConnieIntro:
	.ifdef ENGLISH
	.string "I should teach you how harsh battles\n"
	.string "can be.$"
	.else
	.ifdef GERMAN
	.string "Ich werde dir beibringen, dass Kämpfe\n"
	.string "kein Zuckerschlecken sind!$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_ConnieDefeat:
	.ifdef ENGLISH
	.string "Oh.\n"
	.string "You're strong.$"
	.else
	.ifdef GERMAN
	.string "Oh.\n"
	.string "Du bist stark.$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_ConniePostBattle:
	.ifdef ENGLISH
	.string "I'll tell you something good.\p"
	.string "If you want to reach JUAN, you\n"
	.string "need to walk on each floor tile once.$"
	.else
	.ifdef GERMAN
	.string "Ich verrate dir etwas.\p"
	.string "Wenn du zu JUAN willst, dann darfst\n"
	.string "du auf jede Fliese nur ein Mal treten.$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_BridgetIntro:
	.ifdef ENGLISH
	.string "The POKéMON GYM of the highest level\n"
	.string "in the HOENN region…\p"
	.string "That's the SOOTOPOLIS GYM.$"
	.else
	.ifdef GERMAN
	.string "Die POKéMON ARENA mit den höchsten\n"
	.string "Anforderungen in der HOENN-Region…\p"
	.string "Das ist die ARENA von XENEROVILLE.$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_BridgetDefeat:
	.ifdef ENGLISH
	.string "What a high level you are!$"
	.else
	.ifdef GERMAN
	.string "Du kämpfst aber auf einem hohen\n"
	.string "Niveau!$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_BridgetPostBattle:
	.ifdef ENGLISH
	.string "Rather than being satisfied by being\n"
	.string "in a strong GYM, I imagine training in\l"
	.string "other places will make you stronger.\l"
	.string "But above all, it looks more fun.$"
	.else
	.ifdef GERMAN
	.string "Statt damit zufrieden zu sein, zur\n"
	.string "besten ARENA zu gehören, würde ich\l"
	.string "gerne auch an anderen Orten trainieren.\l"
	.string "Aber hier ist es so lustig!$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_OliviaIntro:
	.ifdef ENGLISH
	.string "I train my POKéMON together with\n"
	.string "JUAN.\p"
	.string "Don't think I'm a pushover.$"
	.else
	.ifdef GERMAN
	.string "Ich trainiere meine POKéMON zusammen\n"
	.string "mit JUAN.\p"
	.string "Ich bin nicht leicht zu nehmen!$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_OliviaDefeat:
	.ifdef ENGLISH
	.string "I was beaten…$"
	.else
	.ifdef GERMAN
	.string "Da wurde ich glatt überrollt…$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_OliviaPostBattle:
	.ifdef ENGLISH
	.string "I think you have potential.\n"
	.string "Why don't you stay and train with us?$"
	.else
	.ifdef GERMAN
	.string "Ich denke, du hast durchaus Potenzial.\n"
	.string "Warum bleibst du nicht bei uns?$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_TiffanyIntro:
	.ifdef ENGLISH
	.string "A graceful glide across the ice while\n"
	.string "crossing no lines…\p"
	.string "A TRAINER putting on that performance\n"
	.string "would be elegantly beautiful!$"
	.else
	.ifdef GERMAN
	.string "Anmutig über das Eis zu gleiten, ohne\n"
	.string "die Linien zu berühren…\p"
	.string "Ein TRAINER, der das beherrscht, wird\n"
	.string "auch in anderen Dingen elegant wirken.$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_TiffanyDefeat:
	.ifdef ENGLISH
	.string "Well, excuse me?!$"
	.else
	.ifdef GERMAN
	.string "Äh, entschuldige mich…$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_TiffanyPostBattle:
	.ifdef ENGLISH
	.string "This is really obvious, but how strong\n"
	.string "you are as a TRAINER has nothing to do\l"
	.string "with how young or old you are.$"
	.else
	.ifdef GERMAN
	.string "Es ist offensichtlich: Die Stärke eines\n"
	.string "TRAINERs hat nichts mit seinem Alter\l"
	.string "zu tun!$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_BethanyIntro:
	.ifdef ENGLISH
	.string "When I'm with my POKéMON, the time\n"
	.string "flies by before you can say, “Oops!”$"
	.else
	.ifdef GERMAN
	.string "Wenn ich mit meinen POKéMON zusammen\n"
	.string "bin, vergeht die Zeit so schnell, dass\l"
	.string "ich noch nicht mal “Uuups” sagen kann.$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_BethanyDefeat:
	.ifdef ENGLISH
	.string "Oops!$"
	.else
	.ifdef GERMAN
	.string "Uuups!$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_BethanyPostBattle:
	.ifdef ENGLISH
	.string "I wish I could forget about lost causes\n"
	.string "before I can manage an “Oops!”$"
	.else
	.ifdef GERMAN
	.string "Ich wollte, ich könnte meine\n"
	.string "Niederlagen vergessen, bevor ich\l"
	.string "“Uuups” ausgesprochen habe.$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_AnnikaIntro:
	.ifdef ENGLISH
	.string "I can battle with really rare POKéMON\n"
	.string "if you'd like.$"
	.else
	.ifdef GERMAN
	.string "Wenn du magst, setze ich im Kampf viele\n"
	.string "seltene POKéMON ein.$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_AnnikaDefeat:
	.ifdef ENGLISH
	.string "Oh, there now! Did you have a good look\n"
	.string "at my POKéMON?$"
	.else
	.ifdef GERMAN
	.string "Und? Hast du dir meine POKéMON\n"
	.string "gut angesehen?$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_AnnikaPostBattle:
	.ifdef ENGLISH
	.string "I came to this GYM because JUAN\n"
	.string "praised me for my darling POKéMON.\p"
	.string "Oh, if only I'd met JUAN years ago\n"
	.string "when I was younger…$"
	.else
	.ifdef GERMAN
	.string "Ich bin zu dieser ARENA gekommen, weil\n"
	.string "JUAN meine geliebten POKéMON gelobt\l"
	.string "hat.\p"
	.string "Wäre ich JUAN nur früher begegnet, als\n"
	.string "ich noch jung war…$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_BriannaIntro:
	.ifdef ENGLISH
	.string "Giggle…\n"
	.string "Your grim look is so charming.$"
	.else
	.ifdef GERMAN
	.string "Kicher…\n"
	.string "Dein grimmiger Ausdruck ist total\l"
	.string "niedlich.$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_BriannaDefeat:
	.ifdef ENGLISH
	.string "Oh, dear.\n"
	.string "I went much too easy on you.$"
	.else
	.ifdef GERMAN
	.string "Oh je.\n"
	.string "Ich habe es dir viel zu leicht gemacht.$"
	.endif
	.endif

SootopolisCity_Gym_B1F_Text_BriannaPostBattle:
	.ifdef ENGLISH
	.string "You couldn't lay a finger on JUAN,\n"
	.string "I'm sure. Giggle…$"
	.else
	.ifdef GERMAN
	.string "Du kannst JUAN kein Härchen krümmen,\n"
	.string "wetten? Kicher…$"
	.endif
	.endif

