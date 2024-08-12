RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.ifdef ENGLISH
	.string "The blackboard lists status changes\n"
	.string "that may affect POKéMON in battle.$"
	.else
	.ifdef GERMAN
	.string "Auf der Tafel sind die Statusverände-\n"
	.string "rungen von POKéMON aufgelistet.$"
	.endif
	.endif

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.ifdef ENGLISH
	.string "Which topic do you want to read?$"
	.else
	.ifdef GERMAN
	.string "Welches Thema möchtest du lesen?$"
	.endif
	.endif

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.ifdef ENGLISH
	.string "If a POKéMON is poisoned, it will\n"
	.string "steadily lose HP.\p"
	.string "The effects of poison remain after\n"
	.string "a battle.\p"
	.string "A poisoned POKéMON's HP will drop\n"
	.string "while it is traveling.\p"
	.string "Heal a poisoning using an ANTIDOTE.$"
	.else
	.ifdef GERMAN
	.string "Wenn ein POKéMON vergiftet wurde, wird\n"
	.string "es ständig KP verlieren.\p"
	.string "Die Auswirkungen des Giftes halten\n"
	.string "auch nach dem Kampf an.\p"
	.string "Die KP eines vergifteten POKéMON\n"
	.string "werden auch unterwegs weiter sinken.\p"
	.string "Mit einem GEGENGIFT kann das POKéMON\n"
	.string "geheilt werden.$"
	.endif
	.endif

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.ifdef ENGLISH
	.string "If a POKéMON becomes paralyzed,\n"
	.string "its SPEED drops.\p"
	.string "It may also not be able to move while\n"
	.string "it is in battle.\p"
	.string "Paralysis remains after battle.\n"
	.string "Cure it using a PARLYZ HEAL.$"
	.else
	.ifdef GERMAN
	.string "Wurde ein POKéMON paralysiert, sinkt\n"
	.string "seine INITIATIVE.\p"
	.string "Es kann passieren, dass es während des\n"
	.string "Kampfes bewegungsunfähig wird.\p"
	.string "Die Paralyse hält auch nach dem Kampf\n"
	.string "an. Heile das POKéMON mit PARA-HEILER.$"
	.endif
	.endif

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.ifdef ENGLISH
	.string "If a POKéMON falls asleep, it will be\n"
	.string "unable to attack.\p"
	.string "A POKéMON may wake up on its own,\n"
	.string "but if a battle ends while it is\l"
	.string "sleeping, it will stay asleep.\p"
	.string "Wake it up using an AWAKENING.$"
	.else
	.ifdef GERMAN
	.string "Wenn ein POKéMON einschläft, kann es\n"
	.string "nicht mehr angreifen.\p"
	.string "Das POKéMON wird vielleicht von selber\n"
	.string "wieder wach, aber wenn der Kampf endet\l"
	.string "und es noch schläft, schläft es weiter.\p"
	.string "Wecke es mit AUFWECKER auf.$"
	.endif
	.endif

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.ifdef ENGLISH
	.string "A burn reduces ATTACK power, and it\n"
	.string "steadily reduces the victim's HP.\p"
	.string "A burn lingers after battle.\n"
	.string "Cure a burn using a BURN HEAL.$"
	.else
	.ifdef GERMAN
	.string "Eine Verbrennung senkt die Kraft des\n"
	.string "ANGRIFFs. Die KP nehmen ständig ab.\p"
	.string "Eine Verbrennung hält auch nach dem\n"
	.string "Kampf an. Setze FEUERHEILER ein!$"
	.endif
	.endif

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.ifdef ENGLISH
	.string "If a POKéMON is frozen, it becomes\n"
	.string "completely helpless.\p"
	.string "It will remain frozen after battle.\n"
	.string "Thaw it out using an ICE HEAL.$"
	.else
	.ifdef GERMAN
	.string "Wurde ein POKéMON eingefroren, so ist\n"
	.string "es völlig hilflos.\p"
	.string "Auch nach dem Kampf hält der Zustand\n"
	.string "an. Setze dann EISHEILER ein.$"
	.endif
	.endif

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.ifdef ENGLISH
	.string "Students who don't study get a little\n"
	.string "taste of my QUICK CLAW.\p"
	.string "Whether or not you are a good student \n"
	.string "will be evident from the way you use\l"
	.string "this item.$"
	.else
	.ifdef GERMAN
	.string "Schüler, die nicht aufpassen, bekommen\n"
	.string "meine FLINKKLAUE zu spüren.\p"
	.string "Wie du dieses Item einsetzt, zeigt,\n"
	.string "ob du ein guter Schüler bist oder nicht.$"
	.endif
	.endif

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.ifdef ENGLISH
	.string "A POKéMON holding the QUICK CLAW will\n"
	.string "occasionally speed up and get to move\l"
	.string "before its opponent.\p"
	.string "There are many other items that are\n"
	.string "meant to be held by POKéMON.\p"
	.string "Just those alone will give you many\n"
	.string "topics to study!$"
	.else
	.ifdef GERMAN
	.string "Ein POKéMON, das die FLINKKLAUE trägt,\n"
	.string "steigert seine Schnelligkeit und greift\l"
	.string "eventuell schneller an als sein Gegner.\p"
	.string "Es gibt noch viele andere Items, die von\n"
	.string "einem POKéMON getragen werden können.\p"
	.string "Du kannst also noch viel lernen.$"
	.endif
	.endif

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.ifdef ENGLISH
	.string "I'm trading POKéMON with my friend\n"
	.string "right now.$"
	.else
	.ifdef GERMAN
	.string "Ich tausche gerade mit meinem Freund\n"
	.string "POKéMON.$"
	.endif
	.endif

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.ifdef ENGLISH
	.string "I always wanted a SEEDOT, and\n"
	.string "I'm finally getting one!$"
	.else
	.ifdef GERMAN
	.string "Ich wollte schon immer ein SAMURZEL\n"
	.string "haben - und endlich habe ich eines!$"
	.endif
	.endif

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.ifdef ENGLISH
	.string "POKéMON can hold items, but they\n"
	.string "don't know what to do with man-made\l"
	.string "items like POTION and ANTIDOTE.$"
	.else
	.ifdef GERMAN
	.string "POKéMON können Items tragen, aber sie\n"
	.string "wissen nicht, was sie mit Items von\l"
	.string "Menschen wie TRANK oder GEGENGIFT\l"
	.string "machen sollen.$"
	.endif
	.endif

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.ifdef ENGLISH
	.string "You know how some POKéMON moves can\n"
	.string "confuse a POKéMON?\p"
	.string "A confused POKéMON will sometimes\n"
	.string "attack itself without meaning to.\p"
	.string "But once it leaves battle, it will\n"
	.string "return to normal.$"
	.else
	.ifdef GERMAN
	.string "Weißt du, wie man mit einigen POKéMON-\n"
	.string "Attacken ein POKéMON verwirren kann?\p"
	.string "Ein verwirrtes POKéMON wird manchmal\n"
	.string "sich selber verletzen, ohne es zu\l"
	.string "wollen.\p"
	.string "Aber sobald es aus dem Kampf genommen\n"
	.string "wird, ist es wieder normal.$"
	.endif
	.endif

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.ifdef ENGLISH
	.string "A POKéMON holding a BERRY will heal\n"
	.string "itself…\p"
	.string "There are many kinds of items that\n"
	.string "POKéMON can hold…\p"
	.string "Boy, it sure is hard taking notes\n"
	.string "down…$"
	.else
	.ifdef GERMAN
	.string "Ein POKéMON, das eine BEERE trägt, wird\n"
	.string "sich selber heilen…\p"
	.string "Es gibt viele Items, die ein POKéMON\n"
	.string "tragen kann…\p"
	.string "Junge, Junge, ist das alles schwer\n"
	.string "zu merken…$"
	.endif
	.endif

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.ifdef ENGLISH
	.string "It's this student's notebook…\p"
	.string "POKéMON are to be caught using\n"
	.string "POKé BALLS.\p"
	.string "Up to six POKéMON can accompany\n"
	.string "a TRAINER.\p"
	.string "A TRAINER is someone who catches\n"
	.string "POKéMON, raises them, and battles\l"
	.string "with them.\p"
	.string "A TRAINER's mission is to defeat\n"
	.string "the strong TRAINERS who await\l"
	.string "challengers in POKéMON GYMS.$"
	.else
	.ifdef GERMAN
	.string "Das ist das Heft eines Schülers…\p"
	.string "POKéMON werden mit POKéBÄLLen\n"
	.string "gefangen.\p"
	.string "Bis zu sechs POKéMON können den\n"
	.string "TRAINER begleiten.\p"
	.string "Ein TRAINER ist jemand, der POKéMON\n"
	.string "fängt, sie aufzieht, und mit ihnen\l"
	.string "kämpft.\p"
	.string "Die Aufgabe eines TRAINERs ist es, die\n"
	.string "starken TRAINER, die ihn in den ARENen\l"
	.string "erwarten, zu besiegen.$"
	.endif
	.endif

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.ifdef ENGLISH
	.string "Hello? Didn't we meet before?\n"
	.string "I think back in PETALBURG CITY.\p"
	.string "Let me introduce myself.\n"
	.string "My name's SCOTT.\p"
	.string "I've been traveling everywhere in\n"
	.string "search of outstanding TRAINERS.\p"
	.string "More specifically, I'm looking for\n"
	.string "POKéMON battle experts.\p"
	.string "So, what brings you to this SCHOOL?\n"
	.string "Are you a TRAINER, too?\p"
	.string "The first thing you should do is to\n"
	.string "have a POKéMON learn the move CUT.\p"
	.string "If I remember correctly, someone in\n"
	.string "this town has CUT.$"
	.else
	.ifdef GERMAN
	.string "Hallo? Haben wir uns nicht schon einmal\n"
	.string "gesehen? Ich glaube, das war in\l"
	.string "BLÜTENBURG CITY?\p"
	.string "Ich will mich mal vorstellen.\n"
	.string "Mein Name ist SCOTT.\p"
	.string "Ich reise durch die Lande, auf der\n"
	.string "Suche nach herausragenden TRAINERn.\p"
	.string "Genauer gesagt bin ich auf der\n"
	.string "Suche nach Experten des POKéMON-\l"
	.string "Kampfes.\p"
	.string "Was machst du in dieser TRAINERSCHULE?\n"
	.string "Bist du auch ein TRAINER?\p"
	.string "Als Erstes solltest du einem POKéMON\n"
	.string "die Attacke ZERSCHNEIDER beibringen.\p"
	.string "Und wenn ich mich recht erinnere,\n"
	.string "besitzt einer in diesem Ort\l"
	.string "ZERSCHNEIDER.$"
	.endif
	.endif

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.ifdef ENGLISH
	.string "SCOTT: Hmm…\p"
	.string "The talent levels of the students here\n"
	.string "are unknown. The potential's there.$"
	.else
	.ifdef GERMAN
	.string "SCOTT: Hmm…\p"
	.string "Ich frage mich, welches Talent-Niveau\n"
	.string "die Schüler hier haben. Das ist völlig\l"
	.string "unbekannt.$"
	.endif
	.endif

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.ifdef ENGLISH
	.string "SCOTT: Oh, what's that?\p"
	.string "It's a STONE BADGE, isn't it?\n"
	.string "That's pretty impressive, I'd say.\p"
	.string "But, you know, I would've loved to see\n"
	.string "you in battle.\p"
	.string "It's hard to tell what you're like as\n"
	.string "a TRAINER from a LEAGUE BADGE.$"
	.else
	.ifdef GERMAN
	.string "SCOTT: Hmm…\p"
	.string "Das ist der STEINORDEN, oder?!?\n"
	.string "Wirklich beeindruckend, muss ich schon\l"
	.string "sagen.\p"
	.string "Ich würde dich liebend gerne mal in\n"
	.string "einem Kampf beobachten.\p"
	.string "Man kann einen TRAINER, der einen\n"
	.string "ORDEN der LIGA besitzt, immer schwer\l"
	.string "einschätzen.$"
	.endif
	.endif

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.ifdef ENGLISH
	.string "Hello? Didn't we meet before?\n"
	.string "I think back in PETALBURG CITY.\p"
	.string "Let me introduce myself.\n"
	.string "My name's SCOTT.\p"
	.string "I've been traveling everywhere in\n"
	.string "search of outstanding TRAINERS.\p"
	.string "More specifically, I'm looking for\n"
	.string "POKéMON battle experts.\p"
	.string "Oh, what's that?\n"
	.string "It's a STONE BADGE, isn't it?\p"
	.string "That's pretty impressive, I'd say, for\n"
	.string "a starting TRAINER like yourself.\p"
	.string "But, you know, I would've loved to see\n"
	.string "you in battle.\p"
	.string "It's hard to tell what you're like as\n"
	.string "a TRAINER from a LEAGUE BADGE.$"
	.else
	.ifdef GERMAN
	.string "Hallo? Haben wir uns nicht schon einmal\n"
	.string "gesehen? Ich glaube, das war in\l"
	.string "BLÜTENBURG CITY?\p"
	.string "Ich will mich mal vorstellen.\n"
	.string "Mein Name ist SCOTT.\p"
	.string "Ich reise durch die Lande, auf der\n"
	.string "Suche nach herausragenden TRAINERn.\p"
	.string "Besser gesagt, ich suche nach Experten\n"
	.string "des POKéMON-Kampfes.\p"
	.string "Was ist das?\n"
	.string "Das ist der STEINORDEN, oder?!?\p"
	.string "Wirklich beeindruckend, muss ich schon\n"
	.string "sagen.\p"
	.string "Ich würde dich liebend gerne mal in\n"
	.string "einem Kampf beobachten.\p"
	.string "Man kann einen TRAINER, der einen\n"
	.string "ORDEN der LIGA besitzt, immer schwer\l"
	.string "einschätzen.$"
	.endif
	.endif

