.set LOCALID_VIVI, 1
.set LOCALID_VICTOR, 2
.set LOCALID_VICTORIA, 3
.set LOCALID_VICKY, 4

Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.ifdef ENGLISH
	.string "You're the first TRAINER I've seen who\n"
	.string "deploys POKéMON so masterfully.\p"
	.string "But, I should tell you--my son is\n"
	.string "stronger than you.\p"
	.string "He even took the POKéMON LEAGUE\n"
	.string "challenge, I'll have you know.$"
	.else
	.ifdef GERMAN
	.string "Ich habe noch nie einen TRAINER ge-\n"
	.string "sehen, der seine POKéMON so meister-\l"
	.string "haft einsetzt wie du.\p"
	.string "Aber, ich muss dir auch sagen… mein\n"
	.string "Sohn ist stärker als du.\p"
	.string "Er hat sogar die POKéMON LIGA heraus-\n"
	.string "gefordert. Das solltest du wissen.$"
	.endif
	.endif

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.ifdef ENGLISH
	.string "We use this MACHO BRACE to more\n"
	.string "effectively strengthen our POKéMON\l"
	.string "in training.\p"
	.string "Since you've beaten all of us here,\n"
	.string "I don't know if you need it, but we\l"
	.string "would like you to have our MACHO BRACE.$"
	.else
	.ifdef GERMAN
	.string "Wir benutzen dieses MACHOBAND, um die\n"
	.string "POKéMON im Training noch mehr\l"
	.string "zu stärken.\p"
	.string "Da du unsere gesamte Familie besiegt\n"
	.string "hast, brauchst du es vielleicht gar\l"
	.string "nicht. Aber wir möchten dir dieses\l"
	.string "MACHOBAND trotzdem gerne schenken.$"
	.endif
	.endif

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.ifdef ENGLISH
	.string "When it comes to POKéMON battles,\n"
	.string "we tend to be pretty passionate.$"
	.else
	.ifdef GERMAN
	.string "Wenn es um POKéMON-Kämpfe geht, ist\n"
	.string "die ganze Familie sehr leidenschaftlich.$"
	.endif
	.endif

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.ifdef ENGLISH
	.string "Mommy is stronger than Daddy.\p"
	.string "I'm stronger than Mommy.\p"
	.string "And Grandma's stronger than me!\p"
	.string "But my big brother is even stronger\n"
	.string "than Grandma.$"
	.else
	.ifdef GERMAN
	.string "Mami ist stärker als Papi.\p"
	.string "Ich bin stärker als Mami.\p"
	.string "Und Omi ist stärker als ich!\p"
	.string "Und mein großer Bruder ist noch\n"
	.string "stärker als Omi!$"
	.endif
	.endif

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.ifdef ENGLISH
	.string "There's no question that you're strong.\p"
	.string "But if you were to battle my grandson,\n"
	.string "you'd end up crying in frustration.\p"
	.string "He's much stronger than any TRAINER\n"
	.string "our family knows.\p"
	.string "He must be challenging the POKéMON\n"
	.string "LEAGUE CHAMPION by now.\p"
	.string "Knowing my grandson, he could be the\n"
	.string "CHAMPION already!$"
	.else
	.ifdef GERMAN
	.string "Es steht außer Frage, dass du stark\n"
	.string "bist.\p"
	.string "Aber wenn du gegen meinen Enkel an-\n"
	.string "treten willst, bringt dir das nur Tränen\l"
	.string "der Frustration ein.\p"
	.string "Er ist viel stärker als jeder TRAINER,\n"
	.string "den unsere Familie kennt.\p"
	.string "Er müsste jetzt gerade eigentlich dabei\n"
	.string "sein, die POKéMON LIGA\l"
	.string "herauszufordern.\p"
	.string "Wie ich meinen Enkel kenne, ist er\n"
	.string "mittlerweile bestimmt schon der CHAMP!$"
	.endif
	.endif

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.ifdef ENGLISH
	.string "My grandson must be challenging the\n"
	.string "POKéMON LEAGUE CHAMPION by now.\p"
	.string "Knowing my grandson, he could be the\n"
	.string "CHAMPION already!$"
	.else
	.ifdef GERMAN
	.string "Mein Enkel müsste jetzt gerade dabei\n"
	.string "sein, die POKéMON LIGA\l"
	.string "herauszufordern.\p"
	.string "Wie ich meinen Enkel kenne, ist er\n"
	.string "mittlerweile bestimmt schon der CHAMP!$"
	.endif
	.endif

