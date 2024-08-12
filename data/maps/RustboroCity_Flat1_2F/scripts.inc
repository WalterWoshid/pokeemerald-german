.set LOCALID_WALDAS_DAD, 6

RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	waitstate
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.ifdef ENGLISH
	.string "Oh, it's so hard every day…\p"
	.string "What's hard?\n"
	.string "You need to ask?\p"
	.string "It's trying to figure out what to\n"
	.string "make for meals every day.\p"
	.string "It really isn't easy coming up with\n"
	.string "meals every day.$"
	.else
	.ifdef GERMAN
	.string "Oh, jeden Tag wird es schwerer…\p"
	.string "Was so schwer ist?\n"
	.string "Das fragst du noch?\p"
	.string "Herauszufinden, was ich jeden Tag\n"
	.string "kochen soll, natürlich!\p"
	.string "Es ist nicht einfach, jeden Tag eine\n"
	.string "Mahlzeit auf den Tisch zu bringen.$"
	.endif
	.endif

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.ifdef ENGLISH
	.string "Oh, hello!\n"
	.string "Welcome to the PEPPER household.\p"
	.string "I have a question for you.\n"
	.string "Have you ever baby-sat?\p"
	.string "You see, I'm a new father, so raising\n"
	.string "a child is all new to me.\p"
	.string "And I have a problem. My daughter\n"
	.string "WALDA doesn't laugh enough.\p"
	.string "I think she'd laugh for me if I told\n"
	.string "her something funny.\p"
	.string "Do you know of a funny word or\n"
	.string "phrase you can tell me?$"
	.else
	.ifdef GERMAN
	.string "Oh, hallo!\n"
	.string "Willkommen im Hause SCHLÄFER.\p"
	.string "Ich würde dir gerne eine Frage stellen.\n"
	.string "Hast du jemals auf ein Kind\l"
	.string "aufgepasst?\p"
	.string "Weißt du, ich bin noch ein junger Vater\n"
	.string "und ein Kind zu haben, ist eine völlig\l"
	.string "neue Erfahrung für mich.\p"
	.string "Ich habe ein Problem: Meine Tochter\n"
	.string "TAPETRA lacht so selten.\p"
	.string "Vielleicht lacht sie ja für mich, wenn\n"
	.string "ich ihr etwas Lustiges erzähle…\p"
	.string "Fällt dir nicht etwas Lustiges ein, das\n"
	.string "ich ihr sagen könnte?$"
	.endif
	.endif

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.ifdef ENGLISH
	.string "I've been saying “{STR_VAR_1}”\n"
	.string "to amuse her lately.\p"
	.string "Do you know of a better word or\n"
	.string "a phrase that might work?$"
	.else
	.ifdef GERMAN
	.string "Ich habe neulich “{STR_VAR_1}”\n"
	.string "zu ihr gesagt, damit sie lacht…\p"
	.string "Fällt dir kein besseres Wort oder ein\n"
	.string "besserer Ausdruck ein?$"
	.endif
	.endif

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.ifdef ENGLISH
	.string "Oh, that's wonderful.\n"
	.string "So, let's hear it, your suggestion.$"
	.else
	.ifdef GERMAN
	.string "Oh, das ist einfach wundervoll!\n"
	.string "Komm, lass mal hören.$"
	.endif
	.endif

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.ifdef ENGLISH
	.string "Oh, is that right?\p"
	.string "Well, if you come up with a good\n"
	.string "suggestion, I'm all ears.$"
	.else
	.ifdef GERMAN
	.string "Wirklich?\p"
	.string "Nun, wenn dir irgendetwas Gutes\n"
	.string "einfällt, dann lass es mich wissen.$"
	.endif
	.endif

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.ifdef ENGLISH
	.string "Ah, I see.\n"
	.string "Well, let's give it a try, shall we?$"
	.else
	.ifdef GERMAN
	.string "Verstehe.\n"
	.string "Komm, wir versuchen es einfach.$"
	.endif
	.endif

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.ifdef ENGLISH
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Oh, yes! She's laughing!\n"
	.string "Oh, I am as delighted as she!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Oh, ja! Schau! Sie lacht!\n"
	.string "Ich bin so glücklich!$"
	.endif
	.endif

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.ifdef ENGLISH
	.string "Ah, I see.\n"
	.string "Well, let's give it a try, shall we?$"
	.else
	.ifdef GERMAN
	.string "Verstehe.\n"
	.string "Komm, wir versuchen es einfach.$"
	.endif
	.endif

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.ifdef ENGLISH
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… She's not smiling at all.\n"
	.string "Maybe WALDA is one serious child…$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… Sie lächelt noch nicht\n"
	.string "einmal… Vielleicht ist TAPETRA\l"
	.string "ja einfach nur ein sehr ernstes Kind…$"
	.endif
	.endif

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.ifdef ENGLISH
	.string "Oh, so you don't know any good words.\n"
	.string "I'd better think for myself, then.\p"
	.string "Hmm…\n"
	.string "How about “{STR_VAR_1}”?\l"
	.string "Let's see if that will work.$"
	.else
	.ifdef GERMAN
	.string "Och, du kennst keine guten Sprüche?\n"
	.string "Dann muss ich mir wohl selbst was\l"
	.string "einfallen lassen.\p"
	.string "Hmm…\n"
	.string "Wie wäre es mit “{STR_VAR_1}”?\l"
	.string "Mal sehen, ob das wirkt.$"
	.endif
	.endif

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.ifdef ENGLISH
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… She's not smiling at all.\n"
	.string "Maybe WALDA is one serious child…$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… Sie lächelt noch nicht\n"
	.string "einmal… Vielleicht ist TAPETRA\l"
	.string "ja einfach nur ein sehr ernstes Kind…$"
	.endif
	.endif

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.ifdef ENGLISH
	.string "Oh, so you don't know any good words.\n"
	.string "I guess I'll try to amuse her with\l"
	.string "the saying I used before.\p"
	.string "Anyways, if you have a good suggestion,\n"
	.string "don't hesitate in telling me, okay?$"
	.else
	.ifdef GERMAN
	.string "Och, du kennst keine guten Sprüche?\n"
	.string "Dann muss ich mir wohl selbst was\l"
	.string "einfallen lassen.\p"
	.string "Aber wenn dir noch etwas Gutes\n"
	.string "einfällt, dann musst du es mich\l"
	.string "unbedingt wissen lassen!$"
	.endif
	.endif

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.ifdef ENGLISH
	.string "Thank you!\p"
	.string "Thanks to you, my darling WALDA\n"
	.string "laughed for me!\p"
	.string "Actually, I may not look all that\n"
	.string "special, but I'm one of DEVON\l"
	.string "CORPORATION's top researchers.\p"
	.string "So, how about I do something in return\n"
	.string "for you?\p"
	.string "I know, I'll add some new wallpaper\n"
	.string "patterns for the BOXES in the PC\l"
	.string "POKéMON Storage System.\p"
	.string "In the wallpaper pattern menu,\n"
	.string "select “FRIENDS.”\p"
	.string "That will give you access to the new\n"
	.string "wallpaper patterns.$"
	.else
	.ifdef GERMAN
	.string "Vielen Dank!\p"
	.string "Dank dir hat meine TAPETRA\n"
	.string "für mich gelacht!\p"
	.string "Ich mag vielleicht nicht so aussehen,\n"
	.string "aber ich bin einer der Topforscher der\l"
	.string "DEVON CORPORATION.\p"
	.string "Ich würde dir gerne etwas zum Dank\n"
	.string "schenken.\p"
	.string "Da fällt mir was ein! Ich werde dir für\n"
	.string "die BOXen in deinem POKéMON-\p"
	.string "LAGERUNGS-SYSTEM ein neues\n"
	.string "Hintergrund-Muster schenken!\p"
	.string "Wenn du dich dort im Menü befindest,\n"
	.string "dann wähle einfach “FREUNDE”.\p"
	.string "Damit kannst du auf die neuen Muster\n"
	.string "zugreifen.$"
	.endif
	.endif

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.ifdef ENGLISH
	.string "It's a POKéMON plush DOLL!$"
	.else
	.ifdef GERMAN
	.string "Das ist eine POKéMON Plüsch-PUPPE.$"
	.endif
	.endif

