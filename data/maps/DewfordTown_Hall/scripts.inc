.set LOCALID_EXPERT_M, 4
.set LOCALID_TWIN, 5
.set LOCALID_SCHOOL_KID_M, 7
.set LOCALID_PSYCHIC_M, 8

DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.ifdef ENGLISH
	.string "What's in vogue? Why, it has to be\n"
	.string "“{STR_VAR_1}”!\p"
	.string "I can't imagine what life would be like\n"
	.string "without “{STR_VAR_1}”!$"
	.else
	.ifdef GERMAN
	.string "Was in ist? Nun, mit Sicherheit\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Ich kann mir ein Leben ohne\n"
	.string "“{STR_VAR_1}” nicht\l"
	.string "vorstellen!$"
	.endif
	.endif

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.ifdef ENGLISH
	.string "What's in vogue? Why, it has to be\n"
	.string "“{STR_VAR_1}”!\p"
	.string "But I'm getting kind of bored with it.\p"
	.string "I should look for the next big thing.$"
	.else
	.ifdef GERMAN
	.string "Was in ist? Nun, mit Sicherheit\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Aber so langsam langweilt es mich.\p"
	.string "Ich sollte mich nach neuen Sachen\n"
	.string "umsehen.$"
	.endif
	.endif

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.ifdef ENGLISH
	.string "I'm teaching my POKéMON about\n"
	.string "“{STR_VAR_1},”\l"
	.string "but it's not going well.\p"
	.string "It's a bit too much, I think.$"
	.else
	.ifdef GERMAN
	.string "Ich bringe meinen POKéMON etwas über\n"
	.string "“{STR_VAR_1}” bei,\l"
	.string "aber es klappt nicht so recht.\p"
	.string "Scheinbar sind sie damit überfordert.$"
	.endif
	.endif

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.ifdef ENGLISH
	.string "I'm studying up on the hip and trendy\n"
	.string "“{STR_VAR_1}” now.\p"
	.string "Is it true that there's a deep link\n"
	.string "between “{STR_VAR_1}”\l"
	.string "and “{STR_VAR_2}”?$"
	.else
	.ifdef GERMAN
	.string "Ich vertiefe mich gerade in ein hippes\n"
	.string "“{STR_VAR_1}”.\p"
	.string "Gibt es eine enge Verbindung\n"
	.string "zwischen “{STR_VAR_1}”\l"
	.string "und “{STR_VAR_2}”?$"
	.endif
	.endif

DewfordTown_Hall_Text_MyHunchWasRight:
	.ifdef ENGLISH
	.string "Oh!\n"
	.string "So, my hunch was right!\p"
	.string "I'm one step closer to being hip and\n"
	.string "happening, yowza!$"
	.else
	.ifdef GERMAN
	.string "Oh!\n"
	.string "Da lag ich ja absolut richtig!\p"
	.string "Ich bin einen Schritt weiter in meinen\n"
	.string "Bemühungen, hip und aufregend zu sein!$"
	.endif
	.endif

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.ifdef ENGLISH
	.string "What?!\n"
	.string "Is that so?!\p"
	.string "It's not easy for an older fellow like\n"
	.string "me to keep up with trends!$"
	.else
	.ifdef GERMAN
	.string "Was?!?\n"
	.string "Wirklich?!?\p"
	.string "Für einen alten Menschen ist es gar\n"
	.string "nicht so leicht, mit der Mode zu gehen!$"
	.endif
	.endif

DewfordTown_Hall_Text_TVShowAboutTrend:
	.ifdef ENGLISH
	.string "This whole business about\n"
	.string "“{STR_VAR_1}”…\l"
	.string "Isn't there a TV show on it?$"
	.else
	.ifdef GERMAN
	.string "Diese ganze Sache mit\n"
	.string "“{STR_VAR_1}”…\l"
	.string "Gibt es da nicht eine Sendung drüber?$"
	.endif
	.endif

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.ifdef ENGLISH
	.string "Across the sea…\p"
	.string "Is “{STR_VAR_1}”\n"
	.string "even more popular?$"
	.else
	.ifdef GERMAN
	.string "Jenseits des Meeres…\p"
	.string "Ist dort “{STR_VAR_1}”\n"
	.string "noch beliebter?$"
	.endif
	.endif

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.ifdef ENGLISH
	.string "I collect official\n"
	.string "“{STR_VAR_1}”\l"
	.string "licensed merchandise.\p"
	.string "I have official\n"
	.string "“{STR_VAR_1}” DOLLS…\p"
	.string "Official “{STR_VAR_1}”\n"
	.string "brand clothing…\p"
	.string "And officially licensed\n"
	.string "“{STR_VAR_1}”\l"
	.string "picture books.\p"
	.string "Heheh, I own!\n"
	.string "I'm not sharing anything with you!$"
	.else
	.ifdef GERMAN
	.string "Ich sammle lizenzierte\n"
	.string "“{STR_VAR_1}”-\l"
	.string "Artikel.\p"
	.string "Ich habe die offiziellen\n"
	.string "“{STR_VAR_1}”-Puppen.\p"
	.string "Offizielle\n"
	.string "“{STR_VAR_1}”-\l"
	.string "Kleidung…\p"
	.string "Und die offiziellen\n"
	.string "“{STR_VAR_1}”-\l"
	.string "Bilderbücher.\p"
	.string "Hähähä, das besitze ich alles!\n"
	.string "Und ich gebe dir nichts ab! Ätsch!$"
	.endif
	.endif

DewfordTown_Hall_Text_BooksAboutTrend:
	.ifdef ENGLISH
	.string "IDENTIFYING GOOD\n"
	.string "“{STR_VAR_1}” &\l"
	.string "BAD “{STR_VAR_1}”…\p"
	.string "THE LINK BETWEEN\n"
	.string "“{STR_VAR_1}” AND\l"
	.string "POKéMON…\p"
	.string "USEFUL\n"
	.string "“{STR_VAR_1}”…\p"
	.string "It's neatly jammed with books about\n"
	.string "“{STR_VAR_1}.”$"
	.else
	.ifdef GERMAN
	.string "GUTE “{STR_VAR_1}” &\n"
	.string "SCHLECHTE\l"
	.string "“{STR_VAR_1}”…\p"
	.string "DAS BAND ZWISCHEN\n"
	.string "“{STR_VAR_1}”\l"
	.string "UND POKéMON…\p"
	.string "HILFREICHE\n"
	.string "“{STR_VAR_1}”…\p"
	.string "Es ist total voll gestopft mit Büchern\n"
	.string "über “{STR_VAR_1}”.$"
	.endif
	.endif

DewfordTown_Hall_Text_TrendsScream:
	.ifdef ENGLISH
	.string "“{STR_VAR_1}'S\n"
	.string "SCREAM” is the title.$"
	.else
	.ifdef GERMAN
	.string "“DER RUF VON\n"
	.string "{STR_VAR_1}”\l"
	.string "ist der Titel.$"
	.endif
	.endif

DewfordTown_Hall_Text_TrendsSmile:
	.ifdef ENGLISH
	.string "“{STR_VAR_1}'S\n"
	.string "SMILE” is the title.$"
	.else
	.ifdef GERMAN
	.string "“DAS LÄCHELN VON\n"
	.string "{STR_VAR_1}”\l"
	.string "ist der Titel.$"
	.endif
	.endif

DewfordTown_Hall_Text_LastTrend:
	.ifdef ENGLISH
	.string "It's titled “THE LAST\n"
	.string "{STR_VAR_1}”.$"
	.else
	.ifdef GERMAN
	.string "Es heißt “DAS LETZTE\n"
	.string "{STR_VAR_1}”.$"
	.endif
	.endif

DewfordTown_Hall_Text_BirthOfTrend:
	.ifdef ENGLISH
	.string "It's titled “THE BIRTH OF\n"
	.string "{STR_VAR_1}”.$"
	.else
	.ifdef GERMAN
	.string "Es heißt “DIE GEBURT EINES\n"
	.string "{STR_VAR_1}”.$"
	.endif
	.endif

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.ifdef ENGLISH
	.string "I saw “{STR_VAR_1}”!\n"
	.string "Cool, huh?\p"
	.string "It's, like, the coolest thing going!\p"
	.string "It was awesome!\n"
	.string "It was the real thing, oh yeah!$"
	.else
	.ifdef GERMAN
	.string "Ich habe “{STR_VAR_1}”\n"
	.string "gesehen! Cool, was?\p"
	.string "Das Coolste überhaupt, würde ich sagen!\p"
	.string "Es war unglaublich!\n"
	.string "Das war das absolut Wahre, oh yeah!$"
	.endif
	.endif

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.ifdef ENGLISH
	.string "Oh, no, no, no.\p"
	.string "That alleged\n"
	.string "“{STR_VAR_1}”\l"
	.string "you claim to have seen--it's not.\p"
	.string "The authentic article is much…\n"
	.string "How should I say it?\l"
	.string "Sharper, yet more mellow!\p"
	.string "Ah, no matter. It's astonishing!$"
	.else
	.ifdef GERMAN
	.string "Oh, nein, nein, nein.\p"
	.string "Das vermeintliche\n"
	.string "“{STR_VAR_1}”,\l"
	.string "das du gesehen hast - war nicht echt.\p"
	.string "Das echte ist…\n"
	.string "Wie soll ich sagen?\l"
	.string "Ist spitzer und wohlgeformter!\p"
	.string "Aber egal. Es ist erstaunlich!$"
	.endif
	.endif

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.ifdef ENGLISH
	.string "Hey, listen, I composed a theme song\n"
	.string "for “{STR_VAR_1}.”\p"
	.string "“{STR_VAR_1}”\n"
	.string "is really popular right now.\p"
	.string "Okay, listen!\n"
	.string "… …\p"
	.string "Oh!\n"
	.string "{STR_VAR_1}!\p"
	.string "Wonderful\n"
	.string "{STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Hey, hör zu! Ich habe ein Leitmotiv\n"
	.string "für “{STR_VAR_1}”\l"
	.string "komponiert.\p"
	.string "“{STR_VAR_1}”\n"
	.string "ist gerade sehr populär.\p"
	.string "Okay, hör zu!\n"
	.string "… …\p"
	.string "Oh!\n"
	.string "{STR_VAR_1}!\p"
	.string "Wundervolles\n"
	.string "{STR_VAR_1}!$"
	.endif
	.endif

DewfordTown_Hall_Text_WorkOnYourSinging:
	.ifdef ENGLISH
	.string "… …\p"
	.string "I dare say, chap, it would pay for you\n"
	.string "to work on your singing before you\l"
	.string "trifle yourself with\l"
	.string "“{STR_VAR_1}.”$"
	.else
	.ifdef GERMAN
	.string "… …\p"
	.string "Ich würde sagen, du solltest erst\n"
	.string "einmal Gesangsunterricht nehmen, bevor\l"
	.string "du es mit “{STR_VAR_1}”\l"
	.string "aufnimmst.$"
	.endif
	.endif

DewfordTown_Hall_Text_OrganizeTrendParty:
	.ifdef ENGLISH
	.string "Anyway, as I was saying earlier, we\n"
	.string "should get together and organize a\l"
	.string "“{STR_VAR_1}” party\l"
	.string "on the island.$"
	.else
	.ifdef GERMAN
	.string "Wie ich vorhin schon sagte, sollten wir\n"
	.string "uns zusammentun und eine\l"
	.string "“{STR_VAR_1}”-Party\l"
	.string "auf der Insel veranstalten.$"
	.endif
	.endif

DewfordTown_Hall_Text_BrilliantIndeed:
	.ifdef ENGLISH
	.string "Oh, a smashing good idea!\p"
	.string "It will settle once and for all\n"
	.string "who is the best at\l"
	.string "“{STR_VAR_1}.”\l"
	.string "Brilliant, indeed!\p"
	.string "Starting today, our lives will revolve\n"
	.string "around “{STR_VAR_1}”!$"
	.else
	.ifdef GERMAN
	.string "Oh, was für eine gute Idee!\p"
	.string "Nun stellen wir ein für alle Mal fest, wer\n"
	.string "der Beste in\l"
	.string "“{STR_VAR_1}” ist.\l"
	.string "Brillant, wirklich!\p"
	.string "Von heute an dreht sich unser Leben\n"
	.string "um “{STR_VAR_1}”!$"
	.endif
	.endif

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.ifdef ENGLISH
	.string "I was thinking, though…\p"
	.string "Wouldn't you agree that\n"
	.string "“{STR_VAR_1}” has\l"
	.string "grown from being something trendy to\l"
	.string "being a part of our daily lives?$"
	.else
	.ifdef GERMAN
	.string "Ich habe nachgedacht…\p"
	.string "Stimmst du mir zu, dass\n"
	.string "“{STR_VAR_1}” von\l"
	.string "etwas Modernem zu einem Teil unseres\l"
	.string "Lebens geworden ist?$"
	.endif
	.endif

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.ifdef ENGLISH
	.string "Beg pardon?\n"
	.string "That much, what?\p"
	.string "However, it's true that\n"
	.string "“{STR_VAR_1}”\l"
	.string "weighs heavily on your mind, whether\l"
	.string "you're awake or asleep.\p"
	.string "Absolutely, you're the\n"
	.string "“{STR_VAR_1}”\l"
	.string "PROFESSOR, old sport!$"
	.else
	.ifdef GERMAN
	.string "Bitte?\n"
	.string "So dominant?\p"
	.string "Nun ja, natürlich bestimmt\n"
	.string "“{STR_VAR_1}” auch\l"
	.string "unsere Gedanken, im Wachen und\l"
	.string "im Schlafen.\p"
	.string "Du bist mit Sicherheit der\n"
	.string "“{STR_VAR_1}”-\l"
	.string "PROFESSOR!$"
	.endif
	.endif

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.ifdef ENGLISH
	.string "If you and me team up as a combo,\n"
	.string "we'll be invincible when it comes to all\l"
	.string "things “{STR_VAR_1}”!$"
	.else
	.ifdef GERMAN
	.string "Wenn du und ich ein Team bilden,\n"
	.string "sind wir unverwundbar gegen\l"
	.string "“{STR_VAR_1}”!$"
	.endif
	.endif

DewfordTown_Hall_Text_WellBeTrendDuo:
	.ifdef ENGLISH
	.string "Spot on, my friend!\p"
	.string "We shall be the\n"
	.string "“{STR_VAR_1}” DUO!\p"
	.string "Isn't that a ripe image?\n"
	.string "Hahahah!$"
	.else
	.ifdef GERMAN
	.string "Licht an, mein Freund!\p"
	.string "Wir sind das\n"
	.string "“{STR_VAR_1}”-DUO!\p"
	.string "Ist das nicht eine irre Vorstellung?\n"
	.string "Hahahaha!$"
	.endif
	.endif

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.ifdef ENGLISH
	.string "For me, SLUDGE BOMB is at the peak\n"
	.string "of popularity. It's the one.\p"
	.string "Hunh? You're telling me that you don't\n"
	.string "know about SLUDGE BOMB?\p"
	.string "That's outright pitiful.\n"
	.string "I'll give you one.$"
	.else
	.ifdef GERMAN
	.string "Für mich ist MATSCHBOMBE das absolut\n"
	.string "Größte!\p"
	.string "Wie? Du willst mir doch nicht\n"
	.string "weismachen, dass du MATSCHBOMBE\l"
	.string "nicht kennst?\p"
	.string "Das ist aber jammerschade.\n"
	.string "Ich werde dir eine geben.$"
	.endif
	.endif

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.ifdef ENGLISH
	.string "I love SLUDGE BOMB.\p"
	.string "But POKéMON with the move\n"
	.string "“{STR_VAR_1}”\l"
	.string "are in, too.$"
	.else
	.ifdef GERMAN
	.string "Ich liebe MATSCHBOMBE.\p"
	.string "Aber POKéMON, die\n"
	.string "“{STR_VAR_1}” kennen,\l"
	.string "sind auch absolut angesagt.$"
	.endif
	.endif

