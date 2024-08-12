MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.ifdef ENGLISH
	.string "Woohoo!\p"
	.string "I hear people call me the ROCK SMASH\n"
	.string "GUY, but I find that sort of degrading.\p"
	.string "I think I deserve a bit more respect,\n"
	.string "like maybe the ROCK SMASH DUDE.\p"
	.string "Woohoo!\p"
	.string "Anyways, your POKéMON look pretty\n"
	.string "strong.\p"
	.string "I like that!\n"
	.string "Here, take this HIDDEN MACHINE!$"
	.else
	.ifdef GERMAN
	.string "Woohoo!\p"
	.string "Die Leute nennen mich den\n"
	.string "ZERTRÜMMERER, aber ich finde den Namen\l"
	.string "unter meinem Niveau!\p"
	.string "Ich verdiene doch wohl etwas mehr\n"
	.string "Respekt! Man sollte mich ZERTRÜMMERER-\l"
	.string "Meister nennen!\p"
	.string "Woohoo, deine POKéMON sehen wirklich\n"
	.string "sehr stark aus.\p"
	.string "Das sehe ich gerne!\n"
	.string "Hier, nimm diese VM!$"
	.endif
	.endif

MauvilleCity_House1_Text_ExplainRockSmash:
	.ifdef ENGLISH
	.string "That HM contains ROCK SMASH.\p"
	.string "If you come across large boulders\n"
	.string "that block your path…\p"
	.string "Well, use that HM move and smash\n"
	.string "them right out of your way!\p"
	.string "Yes, sir! Smash rocks aside, I say!\n"
	.string "Woohoo!$"
	.else
	.ifdef GERMAN
	.string "Diese VM enthält ZERTRÜMMERER.\p"
	.string "Wenn du unterwegs auf große\n"
	.string "Felsbrocken stößt…\p"
	.string "Dann nutze diese VM, um dir den Weg\n"
	.string "freizumachen.\p"
	.string "Jawohl! Zertrümmert Hindernisse, das\n"
	.string "ist meine Devise. Woohoo!$"
	.endif
	.endif

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.ifdef ENGLISH
	.string "Oh, yes, if you smash a rock, a POKéMON\n"
	.string "could come flying out of hiding.\p"
	.string "Woohoo!$"
	.else
	.ifdef GERMAN
	.string "Oh ja, wenn du einen Felsen\n"
	.string "zertrümmerst, könnte ein POKéMON\l"
	.string "zum Vorschein kommen.\p"
	.string "Woohoo!$"
	.endif
	.endif

