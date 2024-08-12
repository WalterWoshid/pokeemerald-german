SlateportCity_PokemonFanClub_MapScripts::
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon::
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_eq VAR_TEMP_2, CONTEST_CATEGORIES_COUNT, SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	goto_if_eq VAR_SLATEPORT_FAN_CLUB_STATE, 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves::
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon::
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname STR_VAR_1
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf::
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions::
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf::
	checkitemspace ITEM_RED_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf::
	checkitemspace ITEM_BLUE_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf::
	checkitemspace ITEM_PINK_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf::
	checkitemspace ITEM_GREEN_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf::
	checkitemspace ITEM_YELLOW_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf::
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool::
	specialvar VAR_RESULT, CheckLeadMonCool
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool::
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty::
	specialvar VAR_RESULT, CheckLeadMonBeauty
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty::
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute::
	specialvar VAR_RESULT, CheckLeadMonCute
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute::
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart::
	specialvar VAR_RESULT, CheckLeadMonSmart
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart::
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough::
	specialvar VAR_RESULT, CheckLeadMonTough
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough::
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest::
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest::
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman::
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell::
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man::
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin::
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman:
	.ifdef ENGLISH
	.string "Er-hem! I am the CHAIRMAN of the\n"
	.string "POKéMON FAN CLUB!\p"
	.string "Being the CHAIRMAN, I am naturally\n"
	.string "the most important!\p"
	.string "No one can best me when it comes\n"
	.string "to raising POKéMON. No one!\p"
	.string "Well, let me tell you about\n"
	.string "POKéMON CONTESTS.\p"
	.string "They're events where one can show off\n"
	.string "POKéMON for the world to see!\p"
	.string "However, they're held in far-off towns,\n"
	.string "so I cannot participate often enough.\p"
	.string "That is why we gather here to show\n"
	.string "off our POKéMON, and have others\l"
	.string "show us theirs.$"
	.else
	.ifdef GERMAN
	.string "Äh-hm. Ich bin der VORSITZENDE des\n"
	.string "POKéMON-FANCLUBs!\p"
	.string "Als VORSITZENDER bin ich natürlich die\n"
	.string "wichtigste Person hier!\p"
	.string "Keiner kann mir im Umgang mit POKéMON\n"
	.string "das Wasser reichen! Keiner!!!\p"
	.string "Aber jetzt lass mich dir etwas zu den\n"
	.string "POKéMON WETTBEWERBen sagen.\p"
	.string "Hier kann jeder seine POKéMON der\n"
	.string "Welt vorstellen!\p"
	.string "Sie finden allerdings in abgelegenen\n"
	.string "Orten statt, daher kann ich nicht an\l"
	.string "ihnen teilnehmen.\p"
	.string "Deshalb haben wir uns hier getroffen.\n"
	.string "Wir zeigen uns gegenseitig unsere\l"
	.string "POKéMON.$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon:
	.ifdef ENGLISH
	.string "The POKéMON of a TRAINER who has\n"
	.string "entered a POKéMON CONTEST…\l"
	.string "That, I would like to see.$"
	.else
	.ifdef GERMAN
	.string "Das POKéMON eines TRAINERs, das an\n"
	.string "einem POKéMON  WETTBEWERB teilnimmt…\l"
	.string "Das würde ich zu gerne mal sehen.$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon:
	.ifdef ENGLISH
	.string "Er-hem! I see you've participated in\n"
	.string "a POKéMON CONTEST!\p"
	.string "Please! Allow me to examine how you\n"
	.string "have raised your POKéMON.\p"
	.string "It delights me no end to see POKéMON\n"
	.string "raised by other TRAINERS.\p"
	.string "The happy expressions of POKéMON\n"
	.string "raised with proper care…\p"
	.string "The kindly eyes of the TRAINER that\n"
	.string "nurtured and raised the POKéMON…\p"
	.string "The very thought fills my heart to\n"
	.string "overwhelming with joy.\p"
	.string "Oh! I do beg your pardon!\n"
	.string "Forgive me for prattling on so!\p"
	.string "Please! Allow me to examine how much\n"
	.string "your POKéMON has grown!$"
	.else
	.ifdef GERMAN
	.string "Äh-hm. Wie ich sehe, hast du an einem\n"
	.string "POKéMON WETTBEWERB teilgenommen.\p"
	.string "Bitte! Darf ich mir mal anschauen, wie\n"
	.string "du deine POKéMON aufgezogen hast?\p"
	.string "Es ist toll, zu sehen, wie andere\n"
	.string "TRAINER ihre POKéMON aufziehen.\p"
	.string "Die zufriedenen Gesichter der POKéMON,\n"
	.string "die gut behandelt werden…\p"
	.string "Die fürsorgliche und liebevolle Art\n"
	.string "ihrer TRAINER…\p"
	.string "Mein Herz geht über vor Freude - da\n"
	.string "gibt es so viel Glück.\p"
	.string "Oh je! Entschuldige, ich schwatze hier\n"
	.string "die ganze Zeit vor mich hin!\p"
	.string "Bitte, erlaube mir einen Blick auf deine\n"
	.string "POKéMON. Wie sind sie gewachsen?$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing:
	.ifdef ENGLISH
	.string "How is your POKéMON growing?\n"
	.string "Allow me to examine it.$"
	.else
	.ifdef GERMAN
	.string "Wie sehen deine POKéMON aus? Wie sind\n"
	.string "sie gewachsen? Erlaube mir einen Blick!$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_HmHmISee:
	.ifdef ENGLISH
	.string "Hm, hm…\n"
	.string "I see…$"
	.else
	.ifdef GERMAN
	.string "Hm, hm…\n"
	.string "Verstehe…$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks:
	.ifdef ENGLISH
	.string "Hmmm… It's not bad, but it's not\n"
	.string "good, either…\p"
	.string "You, the TRAINER, must put more\n"
	.string "effort into raising this POKéMON!\p"
	.string "For instance, may I suggest that\n"
	.string "you give it more {POKEBLOCK}S?$"
	.else
	.ifdef GERMAN
	.string "Hmmm… Das ist weder gut noch\n"
	.string "schlecht…\p"
	.string "Du bist der TRAINER. Streng dich bei der\n"
	.string "Aufzucht dieses POKéMON mehr an!\p"
	.string "Dürfte ich vorschlagen, ihm mehr\n"
	.string "{POKEBLOCK} zu geben?$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_NoSpaceForReward:
	.ifdef ENGLISH
	.string "Oh, my…\p"
	.string "Your POKéMON is growing quite well,\n"
	.string "so you deserve a reward.\p"
	.string "Unfortunately, you have no space for\n"
	.string "this in your BAG.$"
	.else
	.ifdef GERMAN
	.string "Oh, hey…\p"
	.string "Dein POKéMON macht einen guten Ein-\n"
	.string "druck. Ich möchte dir eine Belohnung\l"
	.string "geben.\p"
	.string "Leider hast du in deinem BEUTEL nicht\n"
	.string "mehr genügend Platz.$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis:
	.ifdef ENGLISH
	.string "Your {STR_VAR_1}, it is growing in\n"
	.string "a most impressive manner!\l"
	.string "It is one fine specimen!\p"
	.string "But! If you were to give it this,\n"
	.string "it would grow even better! Indeed!$"
	.else
	.ifdef GERMAN
	.string "Dein {STR_VAR_1} ist wirklich sehr\n"
	.string "beeindruckend! Das ist wirklich ein\l"
	.string "wunderbares Exemplar!\p"
	.string "Und wenn du ihm dies gibst, wird\n"
	.string "es noch besser wachsen! Wirklich!$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_ExplainRedScarf:
	.ifdef ENGLISH
	.string "Let a POKéMON hold that RED SCARF.\p"
	.string "Everyone will recognize the coolness\n"
	.string "of that POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Lass ein POKéMON einen ROTEN SCHAL\n"
	.string "tragen.\p"
	.string "Dadurch wird die Coolness deines\n"
	.string "POKéMON unübersehbar!$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf:
	.ifdef ENGLISH
	.string "Let a POKéMON hold that BLUE SCARF.\p"
	.string "Its beauty will be accentuated much\n"
	.string "more than now!$"
	.else
	.ifdef GERMAN
	.string "Lass ein POKéMON einen BLAUEN SCHAL\n"
	.string "tragen.\p"
	.string "Dadurch wird die Schönheit deines\n"
	.string "POKéMON unübersehbar!$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf:
	.ifdef ENGLISH
	.string "Let a POKéMON hold that PINK SCARF.\p"
	.string "It will draw out the cuteness of\n"
	.string "the POKéMON some more!$"
	.else
	.ifdef GERMAN
	.string "Lass ein POKéMON einen ROSA SCHAL\n"
	.string "tragen.\p"
	.string "Dadurch wird die Anmut deines\n"
	.string "POKéMON unübersehbar!$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf:
	.ifdef ENGLISH
	.string "Let a POKéMON hold that GREEN SCARF.\p"
	.string "That will enhance the\n"
	.string "smartness of POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Lass ein POKéMON einen GRÜNEN SCHAL\n"
	.string "tragen.\p"
	.string "Dadurch wird die Klugheit deines\n"
	.string "POKéMON unübersehbar!$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf:
	.ifdef ENGLISH
	.string "Let a POKéMON hold that YELLOW SCARF.\p"
	.string "It will bolster your POKéMON's\n"
	.string "toughness so much more!$"
	.else
	.ifdef GERMAN
	.string "Lass ein POKéMON einen GELBEN SCHAL\n"
	.string "tragen.\p"
	.string "Dadurch wird die Stärke deines\n"
	.string "POKéMON unübersehbar!$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou:
	.ifdef ENGLISH
	.string "I'm sorry, but I've nothing else to\n"
	.string "give you! None at all!\p"
	.string "After all, you're blessed with the gift\n"
	.string "of raising POKéMON without resorting\l"
	.string "to any items!$"
	.else
	.ifdef GERMAN
	.string "Tut mir Leid, mehr kann ich dir leider\n"
	.string "nicht geben! Ich habe nichts mehr!\l"
	.string "Aber du besitzt etwas viel\p"
	.string "Wertvolleres: Das Talent, POKéMON ohne\n"
	.string "Zuhilfenahme von Items perfekt\l"
	.string "aufzuziehen!$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou:
	.ifdef ENGLISH
	.string "I love seeing POKéMON that love\n"
	.string "their TRAINERS.\p"
	.string "POKéMON are very sensitive to\n"
	.string "the feelings of their TRAINERS.\p"
	.string "If you treat your POKéMON with love\n"
	.string "and care, they'll love you back.\p"
	.string "When your POKéMON grow to love you,\n"
	.string "please come show me.$"
	.else
	.ifdef GERMAN
	.string "Ich freue mich immer, POKéMON zu sehen,\n"
	.string "die ihre TRAINER lieben.\p"
	.string "POKéMON haben ein sensibles Gespür\n"
	.string "für die Gefühle ihrer TRAINER.\p"
	.string "Wenn du einem POKéMON Liebe und\n"
	.string "Achtung entgegenbringst, werden die\l"
	.string "Gefühle erwidert.\p"
	.string "Sobald dein POKéMON dich liebt, komm\n"
	.string "und besuche mich nochmals.$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou:
	.ifdef ENGLISH
	.string "Your POKéMON really adores you.\p"
	.string "For you, a most compassionate\n"
	.string "TRAINER, a gift from the FAN CLUB!$"
	.else
	.ifdef GERMAN
	.string "Dein POKéMON betet dich geradezu an.\p"
	.string "Für einen so mitfühlenden TRAINER\n"
	.string "hat der FANCLUB ein Geschenk!$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove:
	.ifdef ENGLISH
	.string "POKéMON are very sensitive to\n"
	.string "the feelings of their TRAINERS.\p"
	.string "If you treat your POKéMON with love\n"
	.string "and care, they'll love you back.$"
	.else
	.ifdef GERMAN
	.string "POKéMON haben ein sensibles Gespür\n"
	.string "für die Gefühle ihrer TRAINER.\p"
	.string "Wenn du einem POKéMON Liebe und\n"
	.string "Achtung entgegenbringst, werden die\l"
	.string "Gefühle erwidert.$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting:
	.ifdef ENGLISH
	.string "If you keep letting a POKéMON faint\n"
	.string "in battle, it'll come to resent it.\p"
	.string "Soon, it will become less trusting\n"
	.string "of the TRAINER.\p"
	.string "In other words, it certainly won't\n"
	.string "like you very much.$"
	.else
	.ifdef GERMAN
	.string "Wenn ein POKéMON in einem Kampf besiegt\n"
	.string "wird, nimmt es das übel.\p"
	.string "Und bald wird es dem TRAINER weniger\n"
	.string "Vertrauen schenken.\p"
	.string "Mit anderen Worten: Es wird dich nicht\n"
	.string "mehr so sehr mögen.$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein:
	.ifdef ENGLISH
	.string "Do POKéMON enjoy having items used\n"
	.string "on them?\p"
	.string "Mine acted really happy when I gave\n"
	.string "it some PROTEIN.$"
	.else
	.ifdef GERMAN
	.string "Mögen POKéMON Items?\p"
	.string "Mein POKéMON hat sich sehr gefreut,\n"
	.string "als ich ihm PROTEIN gegeben habe.$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_Skitty:
	.ifdef ENGLISH
	.string "SKITTY: Fffnyaaaah…$"
	.else
	.ifdef GERMAN
	.string "ENECO: Fffnyaaaah…$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_Zigzagoon:
	.ifdef ENGLISH
	.string "ZIGZAGOON: Kyuuu…$"
	.else
	.ifdef GERMAN
	.string "ZIGZACHS: Kyuuu…$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_Azumarill:
	.ifdef ENGLISH
	.string "AZUMARILL: Marimari?$"
	.else
	.ifdef GERMAN
	.string "AZUMARILL: Marimari?$"
	.endif
	.endif

