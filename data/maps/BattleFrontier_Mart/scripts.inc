.set LOCALID_OLD_WOMAN, 2

BattleFrontier_Mart_MapScripts::
	.byte 0

BattleFrontier_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

BattleFrontier_Mart_EventScript_OldMan::
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson, MSGBOX_NPC
	end

BattleFrontier_Mart_EventScript_OldWoman::
	lock
	applymovement LOCALID_OLD_WOMAN, Common_Movement_FaceDown
	waitmovement 0
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Boy::
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems, MSGBOX_NPC
	end

BattleFrontier_Mart_Text_ChaperonGrandson:
	.ifdef ENGLISH
	.string "We came here to chaperon our\n"
	.string "grandson.\p"
	.string "But since we're here, we thought\n"
	.string "we should get some souvenirs.$"
	.else
	.ifdef GERMAN
	.string "Wir sind hier, um unseren Enkel zu\n"
	.string "begleiten.\p"
	.string "Und da wir schon mal hier sind, kaufen\n"
	.string "wir uns auch ein paar Andenken.$"
	.endif
	.endif

BattleFrontier_Mart_Text_ProteinMakeNiceGift:
	.ifdef ENGLISH
	.string "Dear, what do you think of this?\n"
	.string "Wouldn't this make a nice gift?\p"
	.string "It's…PRO…TE…IN?\n"
	.string "It sounds delicious, doesn't it?$"
	.else
	.ifdef GERMAN
	.string "Schau mal. Was hältst du hiervon? Wäre\n"
	.string "das nicht ein hübsches Geschenk?\p"
	.string "…PRO…TE…IN?\n"
	.string "Das scheint doch lecker zu sein, oder?$"
	.endif
	.endif

BattleFrontier_Mart_Text_FacilitiesDontAllowItems:
	.ifdef ENGLISH
	.string "A lot of the BATTLE FRONTIER's\n"
	.string "facilities don't allow the use of items\l"
	.string "during battles.\p"
	.string "That rule makes things tougher than\n"
	.string "they already are!$"
	.else
	.ifdef GERMAN
	.string "In vielen Einrichtungen der KAMPF-\n"
	.string "ZONE ist der Einsatz von Items in\l"
	.string "Kämpfen nicht erlaubt.\p"
	.string "Das macht alles viel schwerer, als es\n"
	.string "eh schon ist!$"
	.endif
	.endif

