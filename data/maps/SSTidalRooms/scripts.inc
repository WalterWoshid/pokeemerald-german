SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed:
	.ifdef ENGLISH
	.string "There's a bed…\n"
	.string "Let's take a rest.$"
	.else
	.ifdef GERMAN
	.string "Da steht ein Bett…\n"
	.string "Eine Pause wäre willkommen.$"
	.endif
	.endif

SSTidalRooms_Text_ColtonIntro:
	.ifdef ENGLISH
	.string "I often sail to LILYCOVE CITY.\p"
	.string "I enjoy attending CONTESTS,\n"
	.string "you see.$"
	.else
	.ifdef GERMAN
	.string "Ich segle oft nach SEEGRASULB CITY.\p"
	.string "Ich liebe es, an den WETTBEWERBen\n"
	.string "teilzunehmen.$"
	.endif
	.endif

SSTidalRooms_Text_ColtonDefeat:
	.ifdef ENGLISH
	.string "That was an enjoyable match!$"
	.else
	.ifdef GERMAN
	.string "Das war ein wunderbarer Kampf!$"
	.endif
	.endif

SSTidalRooms_Text_ColtonPostBattle:
	.ifdef ENGLISH
	.string "I get so excited imagining what kinds\n"
	.string "of POKéMON I'll get to see in the next\l"
	.string "CONTEST. The anticipation of it thrills!$"
	.else
	.ifdef GERMAN
	.string "Ich bin schon ganz aufgeregt, wenn ich\n"
	.string "mir vorstelle, welche POKéMON ich im\l"
	.string "nächsten WETTBEWERB sehen werde!$"
	.endif
	.endif

SSTidalRooms_Text_MicahIntro:
	.ifdef ENGLISH
	.string "Are your friends strong?$"
	.else
	.ifdef GERMAN
	.string "Sind deine Freunde stark?$"
	.endif
	.endif

SSTidalRooms_Text_MicahDefeat:
	.ifdef ENGLISH
	.string "Your friends are, indeed, strong.$"
	.else
	.ifdef GERMAN
	.string "Deine Freunde sind in der Tat stark.$"
	.endif
	.endif

SSTidalRooms_Text_MicahPostBattle:
	.ifdef ENGLISH
	.string "Friends need not be human.\n"
	.string "For me, POKéMON are treasured friends!$"
	.else
	.ifdef GERMAN
	.string "Freunde müssen nicht unbedingt\n"
	.string "menschlich sein. Für mich sind\l"
	.string "POKéMON die besten Freunde.$"
	.endif
	.endif

SSTidalRooms_Text_ThomasIntro:
	.ifdef ENGLISH
	.string "Child…\n"
	.string "Did you knock on the door?$"
	.else
	.ifdef GERMAN
	.string "Kind…\n"
	.string "Hast du an der Tür geklopft?$"
	.endif
	.endif

SSTidalRooms_Text_ThomasDefeat:
	.ifdef ENGLISH
	.string "A loss is to be accepted without haste\n"
	.string "or panic.$"
	.else
	.ifdef GERMAN
	.string "Eine Niederlage muss mit erhobenem\n"
	.string "Haupt akzeptiert werden.$"
	.endif
	.endif

SSTidalRooms_Text_ThomasPostBattle:
	.ifdef ENGLISH
	.string "To be never ruffled in any situation is\n"
	.string "the GENTLEMAN's code of conduct.$"
	.else
	.ifdef GERMAN
	.string "In jeder Situation die absolute Ruhe zu\n"
	.string "bewahren, ist die Devise des GENTLEMAN.$"
	.endif
	.endif

SSTidalRooms_Text_JedIntro:
	.ifdef ENGLISH
	.string "JED: I feel a little shy about this, but…\n"
	.string "We'll show you our lovey-dovey power!$"
	.else
	.ifdef GERMAN
	.string "UWE: Eigentlich bin ich ja schüchtern…\n"
	.string "Aber die Liebe gibt einem Kraft!$"
	.endif
	.endif

SSTidalRooms_Text_JedDefeat:
	.ifdef ENGLISH
	.string "JED: Sigh…$"
	.else
	.ifdef GERMAN
	.string "UWE: Seufz…$"
	.endif
	.endif

SSTidalRooms_Text_JedPostBattle:
	.ifdef ENGLISH
	.string "JED: It's the first time that our lovey-\n"
	.string "dovey power couldn't prevail!\l"
	.string "You must be an awesome TRAINER!$"
	.else
	.ifdef GERMAN
	.string "UWE: Zum ersten Mal war unsere Kraft\n"
	.string "der Liebe unterlegen!\l"
	.string "Du bist ein unglaublicher TRAINER!$"
	.endif
	.endif

SSTidalRooms_Text_JedNotEnoughMons:
	.ifdef ENGLISH
	.string "JED: You only have one POKéMON?\n"
	.string "Isn't that just too lonesome?$"
	.else
	.ifdef GERMAN
	.string "UWE: Du hast nur ein POKéMON?\n"
	.string "Fühlt es sich nicht sehr einsam?$"
	.endif
	.endif

SSTidalRooms_Text_LeaIntro:
	.ifdef ENGLISH
	.string "LEA: I feel a little silly, but…\n"
	.string "We'll show you our lovey-dovey power!$"
	.else
	.ifdef GERMAN
	.string "LENA: Ich fühle mich etwas albern,\n"
	.string "aber… Aber die Liebe gibt mir Kraft!$"
	.endif
	.endif

SSTidalRooms_Text_LeaDefeat:
	.ifdef ENGLISH
	.string "LEA: Oh, boo!$"
	.else
	.ifdef GERMAN
	.string "LENA: Oh, buuuuh!$"
	.endif
	.endif

SSTidalRooms_Text_LeaPostBattle:
	.ifdef ENGLISH
	.string "LEA: I can't believe it!\n"
	.string "Our lovey-dovey power failed…\l"
	.string "You must be an awesome TRAINER!$"
	.else
	.ifdef GERMAN
	.string "LENA: Ich kann es einfach nicht fassen!\n"
	.string "Die Kraft unserer Liebe reichte nicht…\l"
	.string "Du bist ein unglaublicher TRAINER!$"
	.endif
	.endif

SSTidalRooms_Text_LeaNotEnoughMons:
	.ifdef ENGLISH
	.string "LEA: I wanted to battle…\n"
	.string "But you don't even have two POKéMON…$"
	.else
	.ifdef GERMAN
	.string "LENA: Ich möchte kämpfen…\n"
	.string "Aber du hast nur ein POKéMON…$"
	.endif
	.endif

SSTidalRooms_Text_GarretIntro:
	.ifdef ENGLISH
	.string "Ah, you've come just in time.\p"
	.string "I'm bored, you see.\n"
	.string "You may entertain me.$"
	.else
	.ifdef GERMAN
	.string "Ah, du kommst gerade rechtzeitig.\p"
	.string "Ich langweile mich schrecklich.\n"
	.string "Du musst mich jetzt unterhalten.$"
	.endif
	.endif

SSTidalRooms_Text_GarretDefeat:
	.ifdef ENGLISH
	.string "…That will do.$"
	.else
	.ifdef GERMAN
	.string "… Das reicht.$"
	.endif
	.endif

SSTidalRooms_Text_GarretPostBattle:
	.ifdef ENGLISH
	.string "Perhaps I shall get Father to acquire\n"
	.string "a yacht for me.\l"
	.string "A yacht for me and POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Ich muss meinen Vater unbedingt\n"
	.string "fragen, ob er mir eine Yacht schenkt.\l"
	.string "Eine Yacht für mich und meine POKéMON!$"
	.endif
	.endif

SSTidalRooms_Text_NaomiIntro:
	.ifdef ENGLISH
	.string "Oh, you're such an adorable TRAINER.\n"
	.string "Would you like to have tea?\l"
	.string "Or would you rather battle?$"
	.else
	.ifdef GERMAN
	.string "Oh, du bist so ein wunderbarer TRAINER.\n"
	.string "Möchtest du eine Tasse Tee?\l"
	.string "Oder möchtest du lieber kämpfen?$"
	.endif
	.endif

SSTidalRooms_Text_NaomiDefeat:
	.ifdef ENGLISH
	.string "I see.\n"
	.string "You're the active sort.$"
	.else
	.ifdef GERMAN
	.string "Ich verstehe.\n"
	.string "Du bist eher der aktive Typ.$"
	.endif
	.endif

SSTidalRooms_Text_NaomiPostBattle:
	.ifdef ENGLISH
	.string "A world cruise on a luxury liner has its\n"
	.string "charms, I must say…\p"
	.string "But, I will admit there is an appealing\n"
	.string "side to touring HOENN by ferry.$"
	.else
	.ifdef GERMAN
	.string "Eine Weltreise auf einem Luxusliner hat\n"
	.string "etwas für sich, das muss ich sagen…\p"
	.string "Aber auch eine Fahrt auf der Fähre\n"
	.string "durch HOENN hat etwas.$"
	.endif
	.endif

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.ifdef ENGLISH
	.string "Uh… Hi! I… I'm not acting suspicious!\n"
	.string "Uh… You can have this! For free!\p"
	.string "It… Honestly, I didn't SNATCH it from\n"
	.string "someone! I'd never do such a thing!\l"
	.string "It's clean! You can use it!$"
	.else
	.ifdef GERMAN
	.string "Äh… Hallo! Ich… Ich verhalte mich über-\n"
	.string "haupt nicht verdächtig! Äh… hier, das\l"
	.string "ist für dich! Es kostet dich nichts!\p"
	.string "Es… Ehrlich! Ich habe es nicht von\n"
	.string "jemandem ÜBERNOMMEN! Das würde ich\l"
	.string "nie tun! Es ist sauber! Nimm es ruhig!$"
	.endif
	.endif

SSTidalRooms_Text_ExplainSnatch:
	.ifdef ENGLISH
	.string "SNATCH steals the beneficial effects\n"
	.string "of certain moves before they can be\l"
	.string "used by a foe or ally.$"
	.else
	.ifdef GERMAN
	.string "ÜBERNAHME raubt die nächste Attacke\n"
	.string "eines POKéMON und setzt sie dann\l"
	.string "gegen diesen Gegner ein.$"
	.endif
	.endif

