.set LOCALID_CURATOR, 1

LilycoveCity_LilycoveMuseum_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_LilycoveMuseum_2F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_LilycoveMuseum_2F_OnFrame
	.byte 0

LilycoveCity_LilycoveMuseum_2F_OnLoad:
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting::
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting::
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting::
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting::
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting::
	setmetatile 10, 6, METATILE_LilycoveMuseum_Painting2_Left, TRUE
	setmetatile 11, 6, METATILE_LilycoveMuseum_Painting2_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting::
	setmetatile 18, 6, METATILE_LilycoveMuseum_Painting1_Left, TRUE
	setmetatile 19, 6, METATILE_LilycoveMuseum_Painting1_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting::
	setmetatile 14, 10, METATILE_LilycoveMuseum_Painting3_Left, TRUE
	setmetatile 15, 10, METATILE_LilycoveMuseum_Painting3_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting::
	setmetatile 6, 10, METATILE_LilycoveMuseum_Painting0_Left, TRUE
	setmetatile 7, 10, METATILE_LilycoveMuseum_Painting0_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting::
	setmetatile 2, 6, METATILE_LilycoveMuseum_Painting4_Left, TRUE
	setmetatile 3, 6, METATILE_LilycoveMuseum_Painting4_Right, TRUE
	end

LilycoveCity_LilycoveMuseum_2F_OnFrame:
	map_script_2 VAR_LILYCOVE_MUSEUM_2F_STATE, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall
	.2byte 0

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall::
	lockall
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall, MSGBOX_SIGN
	applymovement LOCALID_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall, MSGBOX_SIGN
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit, MSGBOX_SIGN
	copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft:
	walk_in_place_faster_left
	step_end

LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall:
	face_up
	delay_16
	step_end

LilycoveCity_LilycoveMuseum_2F_EventScript_Curator::
	lockall
	goto_if_set FLAG_RECEIVED_GLASS_ORNAMENT, LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 1, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 2, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 3, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 4, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 5, LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer::
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer, MSGBOX_DEFAULT
	applymovement LOCALID_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests, MSGBOX_DEFAULT
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament::
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude, MSGBOX_DEFAULT
	givedecoration DECOR_GLASS_ORNAMENT
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament
	setflag FLAG_RECEIVED_GLASS_ORNAMENT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament::
	call Common_EventScript_NoRoomForDecor
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit, MSGBOX_NPC
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CutePainting::
	lockall
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ToughPainting::
	lockall
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CoolPainting::
	lockall
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_BeautyPainting::
	lockall
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SmartPainting::
	lockall
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_Girl::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ExpertM::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_RichBoy::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_COOL
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_BEAUTY
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_CUTE
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_SMART
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_TOUGH
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall:
	.ifdef ENGLISH
	.string "This is our special exhibit hall.$"
	.else
	.ifdef GERMAN
	.string "Dies ist unser besonderer\n"
	.string "Ausstellungsraum.$"
	.endif
	.endif

LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall:
	.ifdef ENGLISH
	.string "As you can plainly see, there is not\n"
	.string "a single painting on exhibit.\p"
	.string "Here, I don't wish to exhibit works of\n"
	.string "so-called classical art.\p"
	.string "Such classical works you can see on\n"
	.string "our ground floor.\p"
	.string "I wish to exhibit work that is far\n"
	.string "different from the classics.\p"
	.string "Art, after all, is not restricted to old,\n"
	.string "famous works!\p"
	.string "This exhibit hall, I wish to fill it with…\p"
	.string "Modern and vibrant artworks of\n"
	.string "POKéMON seemingly ready to spring\l"
	.string "forth into glorious life!$"
	.else
	.ifdef GERMAN
	.string "Wie du klar erkennen kannst, gibt es\n"
	.string "hier nicht ein einziges Gemälde.\p"
	.string "Ich möchte hier auch nicht einfach die\n"
	.string "Gemälde der so genannten Klassiker\l"
	.string "ausstellen.\p"
	.string "Hier soll Kunst zu sehen sein, die\n"
	.string "weit von den Klassikern entfernt ist.\p"
	.string "Kunst ist doch nicht nur auf alte,\n"
	.string "berühmte Werke begrenzt!\p"
	.string "In diesem Ausstellungsraum will ich…\p"
	.string "moderne und lebendige Kunst über\n"
	.string "POKéMON sehen, die bereit sind, in\l"
	.string "ein ruhmreiches Leben zu treten!$"
	.endif
	.endif

LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit:
	.ifdef ENGLISH
	.string "I beg your pardon. I didn't intend\n"
	.string "to monopolize the conversation.\p"
	.string "Now, as you are young, and yet\n"
	.string "obviously well traveled…\p"
	.string "You must encounter lively POKéMON\n"
	.string "and works of art depicting them.\p"
	.string "If you were to come across such\n"
	.string "a painting, may we ask you to obtain\l"
	.string "the artist's permission to exhibit\l"
	.string "it here?$"
	.else
	.ifdef GERMAN
	.string "Oh, entschuldige. Ich wollte dich nicht\n"
	.string "mit meinen Monologen langweilen.\p"
	.string "Nun, du bist jung und offensichtlich\n"
	.string "weit gereist…\p"
	.string "Du hast bestimmt schon viele POKéMON\n"
	.string "gesehen und Bilder, die sie darstellen.\p"
	.string "Wenn du ein solches Bild siehst, kannst\n"
	.string "du den Künstler bitte fragen, ob wir\l"
	.string "sein Werk hier ausstellen dürfen?$"
	.endif
	.endif

LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit:
	.ifdef ENGLISH
	.string "I wish to fill this exhibit hall with\n"
	.string "modern and vibrant paintings of\l"
	.string "POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Ich möchte diesen Ausstellungsraum mit\n"
	.string "modernen und lebendigen Gemälden von\l"
	.string "POKéMON füllen.$"
	.endif
	.endif

LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting:
	.ifdef ENGLISH
	.string "Thanks to you, we've added a new\n"
	.string "painting to our collection!\p"
	.string "I've heard it depicts your POKéMON.\n"
	.string "Truly magnificent!\p"
	.string "Thank you so very, very much!$"
	.else
	.ifdef GERMAN
	.string "Dank dir konnten wir ein neues Gemälde\n"
	.string "für unsere Kollektion erwerben!\p"
	.string "Ich habe gehört, es stellt dein POKéMON\n"
	.string "dar. Wirklich einzigartig!\p"
	.string "Vielen, vielen Dank!$"
	.endif
	.endif

LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer:
	.ifdef ENGLISH
	.string "Ah! It's you!\n"
	.string "{PLAYER}!$"
	.else
	.ifdef GERMAN
	.string "Ah! Du bist es!\n"
	.string "{PLAYER}!$"
	.endif
	.endif

LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests:
	.ifdef ENGLISH
	.string "Isn't this marvelous?\n"
	.string "This collection of paintings!\p"
	.string "Each one of them flawless!\n"
	.string "None better than another!\p"
	.string "These paintings have attracted\n"
	.string "more guests to our ART MUSEUM.\p"
	.string "Sincerely, I thank you, {PLAYER}.\n"
	.string "This is my dream come true!$"
	.else
	.ifdef GERMAN
	.string "Ist das nicht fantastisch?\n"
	.string "Diese Sammlung von Gemälden!\p"
	.string "Jedes einzelne makellos!\n"
	.string "Keines besser als das andere!\p"
	.string "Diese Gemälde ziehen viele neue\n"
	.string "Besucher für unser KUNSTMUSEUM an.\p"
	.string "Ehrlich, ich danke dir, {PLAYER}.\n"
	.string "Mein Traum ist wahr geworden!$"
	.endif
	.endif

LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude:
	.ifdef ENGLISH
	.string "This is merely a token of my gratitude.$"
	.else
	.ifdef GERMAN
	.string "Dies ist nur ein kleines Dankeschön.$"
	.endif
	.endif

LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou:
	.ifdef ENGLISH
	.string "I will keep this for you until we\n"
	.string "meet again.$"
	.else
	.ifdef GERMAN
	.string "Ich werde das für dich aufbewahren, bis\n"
	.string "wir uns wiedersehen.$"
	.endif
	.endif

LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit:
	.ifdef ENGLISH
	.string "Ah, so good to see you, {PLAYER}!\p"
	.string "It's an honor to have you visit us\n"
	.string "on your busy journeys.\p"
	.string "Please, relax and do enjoy your\n"
	.string "visit with us.$"
	.else
	.ifdef GERMAN
	.string "Ah, schön, dich zu sehen, {PLAYER}!\p"
	.string "Es ist eine Ehre für uns, dass du uns\n"
	.string "trotz deiner vielen Aufgaben besuchst.\p"
	.string "Bitte, entspanne dich und genieße\n"
	.string "deinen Besuch bei uns.$"
	.endif
	.endif

LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame:
	.ifdef ENGLISH
	.string "It's a picture frame with pink-colored\n"
	.string "adornments.$"
	.else
	.ifdef GERMAN
	.string "Ein Bilderrahmen mit pinkfarbenen\n"
	.string "Verzierungen.$"
	.endif
	.endif

LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame:
	.ifdef ENGLISH
	.string "It's a picture frame with\n"
	.string "yellow-colored adornments.$"
	.else
	.ifdef GERMAN
	.string "Ein Bilderrahmen mit gelben\n"
	.string "Verzierungen.$"
	.endif
	.endif

LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame:
	.ifdef ENGLISH
	.string "It's a picture frame with\n"
	.string "blue-colored adornments.$"
	.else
	.ifdef GERMAN
	.string "Ein Bilderrahmen mit blauen\n"
	.string "Verzierungen.$"
	.endif
	.endif

LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame:
	.ifdef ENGLISH
	.string "It's a picture frame with\n"
	.string "red-colored adornments.$"
	.else
	.ifdef GERMAN
	.string "Ein Bilderrahmen mit roten\n"
	.string "Verzierungen.$"
	.endif
	.endif

LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame:
	.ifdef ENGLISH
	.string "It's a picture frame with\n"
	.string "green-colored adornments.$"
	.else
	.ifdef GERMAN
	.string "Ein Bilderrahmen mit grünen\n"
	.string "Verzierungen.$"
	.endif
	.endif

LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon:
	.ifdef ENGLISH
	.string "It's a painting of POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Ein Bild eines POKéMON.$"
	.endif
	.endif

LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe:
	.ifdef ENGLISH
	.string "I've been away awhile, so the new\n"
	.string "paintings up here surprised me.\p"
	.string "I wish someone would paint my POKéMON\n"
	.string "this pretty.$"
	.else
	.ifdef GERMAN
	.string "Ich war eine Weile nicht hier, daher\n"
	.string "haben mich die neuen Gemälde über-\l"
	.string "rascht.\p"
	.string "Ich wünschte, jemand würde mein\n"
	.string "POKéMON so wunderbar porträtieren.$"
	.endif
	.endif

LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing:
	.ifdef ENGLISH
	.string "Well… So this is where they show\n"
	.string "the topical POKéMON paintings.\p"
	.string "I see, these new paintings are indeed\n"
	.string "rather amusing.$"
	.else
	.ifdef GERMAN
	.string "Nun… Hier stellen sie also Werke zum\n"
	.string "Thema POKéMON aus.\p"
	.string "Ich sehe schon. Die Gemälde sind\n"
	.string "wirklich amüsant.$"
	.endif
	.endif

LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon:
	.ifdef ENGLISH
	.string "Wow, is that right?\n"
	.string "These paintings are of your POKéMON.\p"
	.string "Isn't that just the ultimate joy for\n"
	.string "a TRAINER?$"
	.else
	.ifdef GERMAN
	.string "Wow, ehrlich?\n"
	.string "Das sind Gemälde deiner POKéMON?\p"
	.string "Ist das nicht die absolute Freude für\n"
	.string "einen TRAINER?$"
	.endif
	.endif

