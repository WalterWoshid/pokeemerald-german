MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, 0
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 1
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_UNLOCKED_TRENDY_SAYINGS
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.ifdef ENGLISH
	.string "Hi, I'm the TRADER.\n"
	.string "Want to trade decorations with me?$"
	.else
	.ifdef GERMAN
	.string "Hallo! Ich bin der HÄNDLER. Möchtest\n"
	.string "du Dekorationen mit mir tauschen?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.ifdef ENGLISH
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"
	.else
	.ifdef GERMAN
	.string "Oh…\n"
	.string "Du überlässt mich meinem Blues?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.ifdef ENGLISH
	.string "But we've traded decorations already,\n"
	.string "you and I.$"
	.else
	.ifdef GERMAN
	.string "Aber wir beide haben doch bereits\n"
	.string "Dekorationen ausgetauscht.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.ifdef ENGLISH
	.string "If you see any decorative item that\n"
	.string "you want of mine, speak up.$"
	.else
	.ifdef GERMAN
	.string "Wenn du etwas Dekoratives siehst, das\n"
	.string "du haben möchtest, lass es mich wissen.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.ifdef ENGLISH
	.string "You don't want anything?\n"
	.string "I feel unwanted…$"
	.else
	.ifdef GERMAN
	.string "Du möchtest nichts haben?\n"
	.string "Ich fühle mich so überflüssig…$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.ifdef ENGLISH
	.string "That decorative item once belonged\n"
	.string "to {STR_VAR_1}.\p"
	.string "Do you want it?$"
	.else
	.ifdef GERMAN
	.string "Das dekorative Item gehörte einst\n"
	.string "{STR_VAR_1}.\p"
	.string "Möchtest du es haben?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.ifdef ENGLISH
	.string "Uh… Wait a second. You don't have a\n"
	.string "single piece of decoration!$"
	.else
	.ifdef GERMAN
	.string "Äh… Warte eine Sekunde. Du hast über-\n"
	.string "haupt kein dekoratives Item!$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.ifdef ENGLISH
	.string "Okay, pick the decoration that you'll\n"
	.string "trade to me.$"
	.else
	.ifdef GERMAN
	.string "Okay, wähle die Dekoration aus, die du\n"
	.string "mit mir tauschen willst.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.ifdef ENGLISH
	.string "You won't trade with me?\n"
	.string "I feel unwanted…$"
	.else
	.ifdef GERMAN
	.string "Du willst nicht mit mir tauschen?\n"
	.string "Ich fühle mich überflüssig…$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.ifdef ENGLISH
	.string "You've got all the {STR_VAR_2}S that can\n"
	.string "be stored. You've no room for this.$"
	.else
	.ifdef GERMAN
	.string "Du hast keinen Platz mehr für {STR_VAR_2}.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.ifdef ENGLISH
	.string "Okay, so we'll trade my {STR_VAR_3}\n"
	.string "for your {STR_VAR_2}?$"
	.else
	.ifdef GERMAN
	.string "Okay, dann lass uns tauschen:\n"
	.string "{STR_VAR_3} gegen\l"
	.string "{STR_VAR_2}!$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.ifdef ENGLISH
	.string "That piece of decoration is in use.\n"
	.string "You can't trade it.$"
	.else
	.ifdef GERMAN
	.string "Dieses Dekorationsstück ist in Ge-\n"
	.string "brauch. Das kannst du nicht tauschen.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.ifdef ENGLISH
	.string "Then we'll trade!\n"
	.string "I'll send my decoration to your PC.$"
	.else
	.ifdef GERMAN
	.string "Lass uns tauschen! Ich werde meine\n"
	.string "Dekorationen auf deinen PC senden.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.ifdef ENGLISH
	.string "Oops! Sorry! That's a really rare\n"
	.string "piece of decoration.\l"
	.string "I can't trade that one away!\p"
	.string "Can I interest you in something else?$"
	.else
	.ifdef GERMAN
	.string "Huups! Tut mir Leid!\n"
	.string "Das ist ein ganz seltenes Stück!\l"
	.string "Das kann ich nicht tauschen!\p"
	.string "Kann ich dich für etwas anderes\n"
	.string "begeistern?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	waitstate
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	waitstate
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.ifdef ENGLISH
	.string "I'm the STORYTELLER.\n"
	.string "I'll tell you tales of legendary\l"
	.string "TRAINERS.\p"
	.string "Will you hear my tale?$"
	.else
	.ifdef GERMAN
	.string "Ich bin der GESCHICHTENERZÄHLER.\n"
	.string "Ich erzähle dir die Geschichten von\l"
	.string "legendären TRAINERn.\p"
	.string "Soll ich dir etwas erzählen?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.ifdef ENGLISH
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"
	.else
	.ifdef GERMAN
	.string "Oh…\n"
	.string "Du überlässt mich meinem Blues?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.ifdef ENGLISH
	.string "I know of these legends.\n"
	.string "Which tale will you have me tell?$"
	.else
	.ifdef GERMAN
	.string "Ich kenne so manche Legende.\n"
	.string "Welche möchtest du hören?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.ifdef ENGLISH
	.string "But, I know of no legendary TRAINERS.\n"
	.string "Hence, I know no tales.\p"
	.string "Where does one find a TRAINER worthy\n"
	.string "of a legendary tale?$"
	.else
	.ifdef GERMAN
	.string "Aber ich weiß nichts über legendäre\n"
	.string "TRAINER. Also habe ich keine Ge-\l"
	.string "schichten darüber auf Lager.\p"
	.string "Wo findet man wohl einen TRAINER, der\n"
	.string "einer Legende würdig ist?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.ifdef ENGLISH
	.string "What's that?!\n"
	.string "You… You…\p"
	.string "{STR_VAR_2}\n"
	.string "{STR_VAR_1} time(s)?!\p"
	.string "That is indeed magnificent!\n"
	.string "It's the birth of a new legend!$"
	.else
	.ifdef GERMAN
	.string "Was ist?\n"
	.string "Du… Du…\p"
	.string "{STR_VAR_2}\n"
	.string "{STR_VAR_1}-mal?\p"
	.string "Das ist einfach großartig!\n"
	.string "Die Geburt einer neuen Legende!$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.ifdef ENGLISH
	.string "It gets me thinking, could there be\n"
	.string "other TRAINERS with more impressive\l"
	.string "legends awaiting discovery?$"
	.else
	.ifdef GERMAN
	.string "Ich überlege, ob es nicht noch andere\n"
	.string "TRAINER gibt, die mir beeindruckende\l"
	.string "Geschichten erzählen können.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.ifdef ENGLISH
	.string "Are you a TRAINER?\p"
	.string "Then tell me, have you any tales that\n"
	.string "are even remotely legendary?$"
	.else
	.ifdef GERMAN
	.string "Bist du ein TRAINER?\p"
	.string "Dann sag mir, ob du Geschichten\n"
	.string "für mich hast, die legendär sind?$"
	.endif
	.endif

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.ifdef ENGLISH
	.string "Incidentally… Would you care to hear\n"
	.string "another legendary tale?$"
	.else
	.ifdef GERMAN
	.string "Incidentally… Would you care to hear\n"
	.string "another legendary tale?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.ifdef ENGLISH
	.string "Hmm…\n"
	.string "I'm not satisfied…\p"
	.string "I wish you would bring me news worthy\n"
	.string "of being called a legend.$"
	.else
	.ifdef GERMAN
	.string "Hmm…\n"
	.string "Ich bin nicht zufrieden…\p"
	.string "Ich wünschte, du würdest mir Neuig-\n"
	.string "keiten erzählen, die den Titel Legende\l"
	.string "verdienen.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.ifdef ENGLISH
	.string "I wish more people would be interested\n"
	.string "in hearing my epic tales of legendary\l"
	.string "TRAINERS.$"
	.else
	.ifdef GERMAN
	.string "Ich wollte, mehr Leute würden sich für\n"
	.string "meine epischen Geschichten über\l"
	.string "legendäre TRAINER interessieren.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.ifdef ENGLISH
	.string "The Save-Happy TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der speicherfreudige TRAINER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.ifdef ENGLISH
	.string "Saved the game$"
	.else
	.ifdef GERMAN
	.string "Hast das Spiel gespeichert?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER saved the game\n"
	.string "{STR_VAR_1} times!\p"
	.string "A more cautious TRAINER than\n"
	.string "{STR_VAR_3} one will never find!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat das Spiel\n"
	.string "{STR_VAR_1}-mal gespeichert!\p"
	.string "Einen vorsichtigeren TRAINER als\n"
	.string "{STR_VAR_3} wird man nicht finden!$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.ifdef ENGLISH
	.string "The Trendsetter TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER als Trendsetter$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.ifdef ENGLISH
	.string "Started trends$"
	.else
	.ifdef GERMAN
	.string "Hast Trends gesetzt?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER started new trends\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is setting trends for all\n"
	.string "the HOENN region!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal\n"
	.string "neue Trends gesetzt!\p"
	.string "{STR_VAR_3} setzt den Trend für alle - in\n"
	.string "der ganzen HOENN-Region!$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.ifdef ENGLISH
	.string "The BERRY-Planting TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der BEEREn pflanzende TRAINER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.ifdef ENGLISH
	.string "Planted BERRIES$"
	.else
	.ifdef GERMAN
	.string "Hast BEEREn gepflanzt?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER planted BERRIES\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a legendary lover of\n"
	.string "BERRIES!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal\n"
	.string "BEEREn gepflanzt!\p"
	.string "{STR_VAR_3} ist ein legendärer Lieb-\n"
	.string "haber von BEEREn!$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.ifdef ENGLISH
	.string "The BIKE-Loving TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der RAD verrückte TRAINER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.ifdef ENGLISH
	.string "Traded BIKES$"
	.else
	.ifdef GERMAN
	.string "Hast RÄDER getauscht?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER swapped BIKES\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love BIKES deeply\n"
	.string "and passionately!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal\n"
	.string "das RAD getauscht!\p"
	.string "{STR_VAR_3} ist ein TRAINER, dessen\n"
	.string "Passion das RADfahren ist!$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.ifdef ENGLISH
	.string "The Interviewed TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der Interviews gebende TRAINER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.ifdef ENGLISH
	.string "Got interviewed$"
	.else
	.ifdef GERMAN
	.string "Hast Interviews gegeben?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER got interviewed\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER who's\n"
	.string "attracting much attention!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER wurde {STR_VAR_1}-mal\n"
	.string "interviewt!\p"
	.string "{STR_VAR_3} ist ein TRAINER, der überall\n"
	.string "Aufmerksamkeit erregt!$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.ifdef ENGLISH
	.string "The Battle-Happy TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der kampfliebende TRAINER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.ifdef ENGLISH
	.string "Battled$"
	.else
	.ifdef GERMAN
	.string "Hast oft gekämpft?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER battled {STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER who can\n"
	.string "never refuse a chance to battle!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal\n"
	.string "gekämpft!\p"
	.string "{STR_VAR_3} ist ein TRAINER, der zu\n"
	.string "einem Kampf nicht nein sagt!$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.ifdef ENGLISH
	.string "The POKéMON-Catching TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der POKéMON fangende TRAINER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.ifdef ENGLISH
	.string "Caught POKéMON$"
	.else
	.ifdef GERMAN
	.string "Hast POKéMON gefangen?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER caught\n"
	.string "{STR_VAR_1} POKéMON!\p"
	.string "{STR_VAR_3} is a legendary catcher of\n"
	.string "wild POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}\n"
	.string "POKéMON gefangen!\p"
	.string "{STR_VAR_3} ist ein legendärer Fänger\n"
	.string "von POKéMON!$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.ifdef ENGLISH
	.string "The Fishing TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der angelnde TRAINER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.ifdef ENGLISH
	.string "Caught POKéMON with a ROD$"
	.else
	.ifdef GERMAN
	.string "Hast POKéMON mit einer ANGEL gefangen?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER caught\n"
	.string "{STR_VAR_1} POKéMON while fishing!\p"
	.string "{STR_VAR_3} is a legendary fishing\n"
	.string "expert!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}\n"
	.string "POKéMON beim Angeln gefangen!\p"
	.string "{STR_VAR_3} ist ein legendärer Angel-\n"
	.string "experte!$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.ifdef ENGLISH
	.string "The EGG-Warming TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der EIer wärmende TRAINER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.ifdef ENGLISH
	.string "Hatched EGGS$"
	.else
	.ifdef GERMAN
	.string "Hast EIer ausgebrütet?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER hatched {STR_VAR_1} POKéMON\n"
	.string "from EGGS!\p"
	.string "{STR_VAR_3} is a legendary warmer\n"
	.string "of EGGS!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Es passierte {STR_VAR_1}-mal, dass der\n"
	.string "TRAINER ein POKéMON aus einem EI\l"
	.string "schlüpfen ließ!\p"
	.string "{STR_VAR_3} ist ein legendärer Pfleger\n"
	.string "von EIern!$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.ifdef ENGLISH
	.string "The Evolver TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER der Entwicklungen$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.ifdef ENGLISH
	.string "Evolved POKéMON$"
	.else
	.ifdef GERMAN
	.string "Hast POKéMON sich entwickeln lassen?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER made {STR_VAR_1} POKéMON\n"
	.string "evolve!\p"
	.string "{STR_VAR_3} is the ultimate evolver\n"
	.string "of POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}\n"
	.string "POKéMON zur Entwicklung gebracht!\p"
	.string "{STR_VAR_3} ist der ultimative Ent-\n"
	.string "wickler von POKéMON!$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.ifdef ENGLISH
	.string "The POKéMON CENTER-Loving TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der PKMN-CENTER liebende TRAINER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.ifdef ENGLISH
	.string "Used POKéMON CENTERS$"
	.else
	.ifdef GERMAN
	.string "Gingst in ein POKéMON-CENTER?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER healed POKéMON\n"
	.string "{STR_VAR_1} times at POKéMON CENTERS!\p"
	.string "There could be no greater lover of\n"
	.string "POKéMON CENTERS than {STR_VAR_3}!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat POKéMON\n"
	.string "{STR_VAR_1}-mal in einem POKéMON-CENTER\l"
	.string "heilen lassen!\p"
	.string "Es gibt keinen größeren Fan der\n"
	.string "POKéMON-CENTER als {STR_VAR_3}!$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.ifdef ENGLISH
	.string "The Homebody TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der gastfreundliche TRAINER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.ifdef ENGLISH
	.string "Rested POKéMON at home$"
	.else
	.ifdef GERMAN
	.string "POKéMON haben sich bei dir erholt?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER healed POKéMON\n"
	.string "{STR_VAR_1} times at home!\p"
	.string "There could be no more of a homebody\n"
	.string "than {STR_VAR_3}!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat POKéMON\n"
	.string "{STR_VAR_1}-mal bei sich zu Hause\l"
	.string "ausruhen und heilen lassen.\p"
	.string "Kein TRAINER ist so gastfreundlich\n"
	.string "wie {STR_VAR_3}!$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.ifdef ENGLISH
	.string "The SAFARI-Loving TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der SAFARI liebende TRAINER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.ifdef ENGLISH
	.string "Entered the SAFARI ZONE$"
	.else
	.ifdef GERMAN
	.string "Bist in die SAFARI-ZONE gegangen?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER went into the SAFARI ZONE\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER whose wild side\n"
	.string "must come out in the SAFARI ZONE!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER ist {STR_VAR_1}-mal in die\n"
	.string "SAFARI-ZONE gegangen!\p"
	.string "{STR_VAR_3} ist ein TRAINER, dessen\n"
	.string "wilde Seite in der SAFARI-ZONE zum\l"
	.string "Vorschein kommt!$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.ifdef ENGLISH
	.string "The CUT-Frenzy TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER als ZERSCHNEIDER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.ifdef ENGLISH
	.string "Used CUT$"
	.else
	.ifdef GERMAN
	.string "Hast ZERSCHNEIDER eingesetzt?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER used CUT\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER who just must\n"
	.string "love to CUT!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal\n"
	.string "ZERSCHNEIDER eingesetzt!\p"
	.string "{STR_VAR_3} ist ein TRAINER, der es\n"
	.string "liebt, etwas zu ZERSCHNEIDEN.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.ifdef ENGLISH
	.string "The ROCK-SMASHING TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER als ZERTRÜMMERER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.ifdef ENGLISH
	.string "Smashed rocks$"
	.else
	.ifdef GERMAN
	.string "Hast Felsen ZERTRÜMMERT?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER used ROCK SMASH\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER who\n"
	.string "can't leave a stone unsmashed!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal\n"
	.string "ZERTRÜMMERER eingesetzt!\p"
	.string "{STR_VAR_3} ist ein TRAINER, der keinen\n"
	.string "Felsen unbeschädigt lassen kann.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.ifdef ENGLISH
	.string "The Move-Loving TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der Umzüge liebende TRAINER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.ifdef ENGLISH
	.string "Moved the SECRET BASE$"
	.else
	.ifdef GERMAN
	.string "Bist du mit der GEHEIMBASIS umgezogen?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER moved the SECRET BASE\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER who loves\n"
	.string "to move houses often!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER ist {STR_VAR_1}-mal mit\n"
	.string "seiner GEHEIMBASIS umgezogen!\p"
	.string "{STR_VAR_3} ist ein TRAINER, der es\n"
	.string "liebt, sich ein neues Haus einzurichten.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.ifdef ENGLISH
	.string "The SPLASH-Happy TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der PLATSCHER des TRAINERs$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.ifdef ENGLISH
	.string "Used SPLASH$"
	.else
	.ifdef GERMAN
	.string "Hast PLATSCHER eingesetzt?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER used SPLASH\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER who must love\n"
	.string "SPLASHING around!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal\n"
	.string "PLATSCHER eingesetzt!\p"
	.string "{STR_VAR_3} ist ein TRAINER, der es\n"
	.string "liebt, zu PLATSCHEN.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.ifdef ENGLISH
	.string "The Tenacious TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der verbissene TRAINER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.ifdef ENGLISH
	.string "Resorted to using STRUGGLE$"
	.else
	.ifdef GERMAN
	.string "Hast VERZWEIFLER angewendet?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER had to rely on STRUGGLE\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a tenacious TRAINER\n"
	.string "who never gives in to adversity!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat sich {STR_VAR_1}-mal\n"
	.string "auf VERZWEIFLER verlassen!\p"
	.string "{STR_VAR_3}… Ein verbissener TRAINER,\n"
	.string "der auch in der Not nicht aufgibt.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.ifdef ENGLISH
	.string "The SLOT Champ$"
	.else
	.ifdef GERMAN
	.string "Der König der EINARMIGEN BANDITen$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.ifdef ENGLISH
	.string "Won the jackpot on the SLOTS$"
	.else
	.ifdef GERMAN
	.string "Hast den EINARMIGEN BANDITen besiegt?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER won the jackpot on\n"
	.string "the SLOTS {STR_VAR_1} times.\p"
	.string "{STR_VAR_3} is a TRAINER who was lucky\n"
	.string "on the SLOTS!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal\n"
	.string "am EINARMIGEN BANDITen gewonnen!\p"
	.string "{STR_VAR_3}… Ein TRAINER, der am\n"
	.string "EINARMIGEN BANDITen Glück hat.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.ifdef ENGLISH
	.string "The ROULETTE Champ$"
	.else
	.ifdef GERMAN
	.string "Der König des ROULETTEs$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.ifdef ENGLISH
	.string "Had consecutive ROULETTE wins of$"
	.else
	.ifdef GERMAN
	.string "Hast in Folge beim ROULETTE gewonnen?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER won in ROULETTE\n"
	.string "{STR_VAR_1} times in a row.\p"
	.string "{STR_VAR_3} was lucky when the ball\n"
	.string "bounced in ROULETTE!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal in\n"
	.string "Folge beim ROULETTE gewonnen!\p"
	.string "{STR_VAR_3}… Ein TRAINER, dem die Kugel\n"
	.string "beim ROULETTE gehorcht.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.ifdef ENGLISH
	.string "The BATTLE TOWER Challenger$"
	.else
	.ifdef GERMAN
	.string "Der Herausforderer im DUELLTURM$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.ifdef ENGLISH
	.string "Took the BATTLE TOWER challenge$"
	.else
	.ifdef GERMAN
	.string "Hast Gegner im DUELLTURM gefordert?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER took the BATTLE TOWER\n"
	.string "challenge {STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER who aspires\n"
	.string "for excellence in the BATTLE TOWER!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal\n"
	.string "Gegner im DUELLTURM herausgefordert!\p"
	.string "{STR_VAR_3}… Ein TRAINER, der im DUELL-\n"
	.string "TURM nach Perfektion strebt.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.ifdef ENGLISH
	.string "The Blend-Loving TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der mixende TRAINER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.ifdef ENGLISH
	.string "Made {POKEBLOCK}S$"
	.else
	.ifdef GERMAN
	.string "Hast {POKEBLOCK} hergestellt?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER made {POKEBLOCK}S\n"
	.string "{STR_VAR_1} times!\p"
	.string "There is none better at using a BERRY\n"
	.string "BLENDER than {STR_VAR_3}!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal\n"
	.string "{POKEBLOCK} hergestellt!\p"
	.string "Niemand bedient den BEERENMIXER\n"
	.string "besser als {STR_VAR_3}.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.ifdef ENGLISH
	.string "The CONTEST-Loving TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der Fan der WETTBEWERBe$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.ifdef ENGLISH
	.string "Entered CONTESTS$"
	.else
	.ifdef GERMAN
	.string "Hast an WETTBEWERBen teilgenommen?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER entered CONTESTS\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love showing off\n"
	.string "POKéMON to others!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal\n"
	.string "an einem WETTBEWERB teilgenommen!\p"
	.string "{STR_VAR_3} liebt es, anderen seine\n"
	.string "POKéMON zu zeigen.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.ifdef ENGLISH
	.string "The CONTEST Master$"
	.else
	.ifdef GERMAN
	.string "Der Meister der WETTBEWERBe$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.ifdef ENGLISH
	.string "Won CONTESTS$"
	.else
	.ifdef GERMAN
	.string "Hast WETTBEWERBe gewonnen?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER won CONTESTS\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be an incredible\n"
	.string "CONTEST master!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal\n"
	.string "einen WETTBEWERB gewonnen!\p"
	.string "{STR_VAR_3} ist ein unvergleichlicher\n"
	.string "Meister der WETTBEWERBe.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.ifdef ENGLISH
	.string "The Happy Shopper$"
	.else
	.ifdef GERMAN
	.string "Der glückliche Einkäufer$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.ifdef ENGLISH
	.string "Shopped$"
	.else
	.ifdef GERMAN
	.string "Bist einkaufen gegangen?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER bought items in shops\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be one of those\n"
	.string "people who are born to shop.$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal\n"
	.string "in einem Geschäft Items gekauft!\p"
	.string "{STR_VAR_3} - ein geborener Einkäufer.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.ifdef ENGLISH
	.string "The Item-Finding TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER, der Items findet$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.ifdef ENGLISH
	.string "Used an ITEMFINDER$"
	.else
	.ifdef GERMAN
	.string "Hast den DETEKTOR eingesetzt?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER used an ITEMFINDER\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must enjoy scouring the\n"
	.string "ground for hidden items!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal\n"
	.string "den DETEKTOR eingesetzt!\p"
	.string "{STR_VAR_3} liebt es, den Boden nach\n"
	.string "verborgenen Items abzusuchen.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.ifdef ENGLISH
	.string "The Rain-Soaked TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der regennasse TRAINER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.ifdef ENGLISH
	.string "Got rained on$"
	.else
	.ifdef GERMAN
	.string "Wurdest nass geregnet?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER got soaked by rain\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3}'s charisma must even\n"
	.string "attract rain!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER wurde {STR_VAR_1}-mal\n"
	.string "nass geregnet!\p"
	.string "Das Charisma von {STR_VAR_3} zieht\n"
	.string "sogar den Regen an.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.ifdef ENGLISH
	.string "The Avid POKéDEX Reader$"
	.else
	.ifdef GERMAN
	.string "Der passionierte POKéDEX-Leser$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.ifdef ENGLISH
	.string "Checked a POKéDEX$"
	.else
	.ifdef GERMAN
	.string "Hast im POKéDEX nachgeschlagen?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER checked a POKéDEX\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love inspecting\n"
	.string "POKéMON in a POKéDEX!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal\n"
	.string "im POKéDEX nachgeschlagen!\p"
	.string "{STR_VAR_3} liebt es, alles über\n"
	.string "POKéMON im POKéDEX nachzulesen.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.ifdef ENGLISH
	.string "The RIBBON Collector$"
	.else
	.ifdef GERMAN
	.string "Der Sammler der BÄNDER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.ifdef ENGLISH
	.string "Received RIBBONS$"
	.else
	.ifdef GERMAN
	.string "Hast BÄNDER erhalten?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER received RIBBONS\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER who\n"
	.string "loves to collect RIBBONS!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}\n"
	.string "BÄNDER erhalten!\p"
	.string "{STR_VAR_3} ist ein TRAINER, der es\n"
	.string "liebt, BÄNDER zu sammeln.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.ifdef ENGLISH
	.string "The Ledge-Jumping TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der springende TRAINER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.ifdef ENGLISH
	.string "Jumped down ledges$"
	.else
	.ifdef GERMAN
	.string "Bist Absätze heruntergesprungen?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER jumped down ledges\n"
	.string "{STR_VAR_1} times!\p"
	.string "If there's a ledge to be jumped,\n"
	.string "{STR_VAR_3} can't ignore it!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER ist {STR_VAR_1}-mal\n"
	.string "einen Absatz hinabgesprungen!\p"
	.string "Sobald er an einen Absatz kommt, muss\n"
	.string "TRAINER {STR_VAR_3} einfach hinab-\l"
	.string "springen.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.ifdef ENGLISH
	.string "The Legendary TV Viewer$"
	.else
	.ifdef GERMAN
	.string "Der legendäre Fernsehzuschauer$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.ifdef ENGLISH
	.string "Watched TV$"
	.else
	.ifdef GERMAN
	.string "Hast ferngesehen?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER watched TV\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love watching TV!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal\n"
	.string "Fernsehen geschaut!\p"
	.string "{STR_VAR_3} liebt es, fernzusehen.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.ifdef ENGLISH
	.string "The Time-Conscious TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der zeitbewusste TRAINER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.ifdef ENGLISH
	.string "Checked the time$"
	.else
	.ifdef GERMAN
	.string "Hast nach der Uhrzeit gesehen?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER checked the time\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a punctual TRAINER\n"
	.string "who's conscious of the time.$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal\n"
	.string "nach der Uhrzeit geschaut!\p"
	.string "{STR_VAR_3} ist ein pünktlicher\n"
	.string "TRAINER, der sich der Zeit bewusst ist.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.ifdef ENGLISH
	.string "The POKéMON LOTTERY Wizard$"
	.else
	.ifdef GERMAN
	.string "Der Zauberer der POKéMON-LOTTERIE$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.ifdef ENGLISH
	.string "Won POKéMON LOTTERIES$"
	.else
	.ifdef GERMAN
	.string "Hast in der LOTTERIE gewonnen?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER won POKéMON LOTTERIES\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must have many friends\n"
	.string "to trade POKéMON with!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal\n"
	.string "in der POKéMON-LOTTERIE gewonnen!\p"
	.string "TRAINER {STR_VAR_3} hat viele Freunde,\n"
	.string "die mit ihm POKéMON tauschen.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.ifdef ENGLISH
	.string "The DAY CARE-Using Trainer$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER und die PENSION$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.ifdef ENGLISH
	.string "Left POKéMON at the DAY CARE$"
	.else
	.ifdef GERMAN
	.string "Hast POKéMON in die PENSION gebracht?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER left POKéMON with the\n"
	.string "DAY CARE {STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a real go-getter\n"
	.string "who raises POKéMON aggressively!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal\n"
	.string "seine POKéMON in die PENSION gegeben!\p"
	.string "{STR_VAR_3} ist ein Ellenbogentyp, der\n"
	.string "alles für die Entwicklung seiner\l"
	.string "POKéMON tut.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.ifdef ENGLISH
	.string "The CABLE CAR-Loving TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der SEILBAHN verrückte TRAINER$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.ifdef ENGLISH
	.string "Rode the CABLE CAR$"
	.else
	.ifdef GERMAN
	.string "Bist mit der SEILBAHN gefahren?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER rode the CABLE CAR\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a busy TRAINER\n"
	.string "who's up and down all the time!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER ist {STR_VAR_1}-mal\n"
	.string "mit der SEILBAHN gefahren!\p"
	.string "{STR_VAR_3} ist ein sehr beschäftigter\n"
	.string "TRAINER, der ständig rauf und runter\l"
	.string "fährt.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.ifdef ENGLISH
	.string "The Hot Spring-Loving TRAINER$"
	.else
	.ifdef GERMAN
	.string "Der Liebhaber der Heißen Quellen$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.ifdef ENGLISH
	.string "Bathed in hot springs$"
	.else
	.ifdef GERMAN
	.string "Hast in den Heißen Quellen gebadet?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.ifdef ENGLISH
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER bathed in hot springs\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER with\n"
	.string "baby-smooth skin!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die Geschichte eines TRAINERs\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1}-mal\n"
	.string "in den Heißen Quellen gebadet!\p"
	.string "{STR_VAR_3} wird eine babyweiche Haut\n"
	.string "haben.$"
	.endif
	.endif


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.ifdef ENGLISH
	.string "I'm GIDDY!\n"
	.string "I have a scintillating story for you!\p"
	.string "Would you like to hear my story?$"
	.else
	.ifdef GERMAN
	.string "Ich bin MÄRCHEN-MAN! Ich habe eine\n"
	.string "sehr geistreiche Geschichte für dich!\p"
	.string "Soll ich sie dir erzählen?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.ifdef ENGLISH
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"
	.else
	.ifdef GERMAN
	.string "Oh…\n"
	.string "Du überlässt mich meinem Blues?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.ifdef ENGLISH
	.string "Also, I was thinking…$"
	.else
	.ifdef GERMAN
	.string "Außerdem habe ich so überlegt…$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.ifdef ENGLISH
	.string "That's about it, I think…\p"
	.string "We should chat again!\n"
	.string "Bye-bye!$"
	.else
	.ifdef GERMAN
	.string "Das wäre alles, glaube ich…\p"
	.string "Wir sollten bald wieder ein Schwätzchen\n"
	.string "halten! Tschüss!$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.ifdef ENGLISH
	.string "Hi, I'm the BARD.\n"
	.string "Would you like to hear my song?$"
	.else
	.ifdef GERMAN
	.string "Hallo, ich bin der BARDE.\n"
	.string "Möchtest du meinem Lied lauschen?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.ifdef ENGLISH
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"
	.else
	.ifdef GERMAN
	.string "Oh…\n"
	.string "Du überlässt mich meinem Blues?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.ifdef ENGLISH
	.string "Oh, what a moving song…\n"
	.string "I wish I could play it for others…$"
	.else
	.ifdef GERMAN
	.string "Hach, was für ein bewegendes Lied…\n"
	.string "Ich wünschte, ich könnte es für\l"
	.string "andere spielen…$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.ifdef ENGLISH
	.string "So?\n"
	.string "How do you like my song?\p"
	.string "But I'm none too happy about\n"
	.string "the lyrics.\p"
	.string "How would you like to write some\n"
	.string "new lyrics for me?$"
	.else
	.ifdef GERMAN
	.string "So?\n"
	.string "Wie fandest du mein Lied?\p"
	.string "Ich bin noch nicht ganz zufrieden mit\n"
	.string "dem Text.\p"
	.string "Hast du nicht Lust, den Text für mich\n"
	.string "neu zu schreiben?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.ifdef ENGLISH
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"
	.else
	.ifdef GERMAN
	.string "Oh…\n"
	.string "Du überlässt mich meinem Blues?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.ifdef ENGLISH
	.string "Thank you kindly!\n"
	.string "Let me sing it for you.$"
	.else
	.ifdef GERMAN
	.string "Vielen herzlichen Dank!\n"
	.string "Ich möchte für dich singen.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.ifdef ENGLISH
	.string "Was that how you wanted your song\n"
	.string "to go?$"
	.else
	.ifdef GERMAN
	.string "Hast du dir dein Lied so vorgestellt?$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.ifdef ENGLISH
	.string "Okay! That's it, then.\n"
	.string "I'll sing this song for a while.$"
	.else
	.ifdef GERMAN
	.string "Okay! Das ist es! Dieses Lied werde\n"
	.string "ich nun für eine Weile singen.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.ifdef ENGLISH
	.string "Hey, yo! They call me the HIPSTER.\n"
	.string "I'll teach you what's hip and happening.$"
	.else
	.ifdef GERMAN
	.string "Hey, yo! Man nennt mich TRENDWIG. Ich\n"
	.string "zeige dir, was hip ist und abgeht.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.ifdef ENGLISH
	.string "But, hey, I taught you what's hip and\n"
	.string "happening already.\p"
	.string "I'd like to spread the good word to\n"
	.string "other folks.$"
	.else
	.ifdef GERMAN
	.string "Aber, hey, ich habe dir doch schon ge-\n"
	.string "zeigt, was hip ist und abgeht.\p"
	.string "Ich will das auch anderen mitteilen.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.ifdef ENGLISH
	.string "But, hey, you already know a lot about\n"
	.string "what's hip and happening.\p"
	.string "I've got nothing new to teach you!$"
	.else
	.ifdef GERMAN
	.string "Aber, hey, ich habe dir doch schon ge-\n"
	.string "zeigt, was hip ist und abgeht.\p"
	.string "Ich habe nichts mehr in petto.$"
	.endif
	.endif

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.ifdef ENGLISH
	.string "Hey, have you heard about\n"
	.string "“{STR_VAR_1}”?\p"
	.string "What's it mean? Well…\n"
	.string "Ask your daddy or mommy, okay?$"
	.else
	.ifdef GERMAN
	.string "Hast du schon von\n"
	.string "“{STR_VAR_1}” gehört?\p"
	.string "Was das heißt? Ähäm…\n"
	.string "Frag mal deinen Papi oder deine Mami.$"
	.endif
	.endif
