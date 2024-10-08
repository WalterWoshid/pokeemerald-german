.set LOCALID_DOCK, 1

SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.ifdef ENGLISH
	.string "Umm… If this goes here, and that\n"
	.string "goes over there…\p"
	.string "Then where does this thing go?\n"
	.string "And what about that doohickey?\p"
	.string "Aaargh! I can't make heads or tails\n"
	.string "of this!$"
	.else
	.ifdef GERMAN
	.string "Ähmm… Wenn das hierhin gehört und das\n"
	.string "dahin…\p"
	.string "Wo gehört dieses dann hin?\n"
	.string "Und was ist mit diesem Dingsbums?\p"
	.string "Aaargh! Ich werde daraus einfach nicht\n"
	.string "schlau!$"
	.endif
	.endif

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.ifdef ENGLISH
	.string "Hm?\n"
	.string "Hi, I'm DOCK.\p"
	.string "CAPT. STERN commissioned me to\n"
	.string "design a ferry.\p"
	.string "Oh! That there…\n"
	.string "Are they DEVON GOODS?\p"
	.string "But, hmm…\n"
	.string "This won't do…\p"
	.string "CAPT. STERN went off somewhere.\n"
	.string "He said he had some work to do.\p"
	.string "Could I get you to go find CAPT.\n"
	.string "STERN and deliver that to him?$"
	.else
	.ifdef GERMAN
	.string "Hm?\n"
	.string "Hallo, ich bin BOOTMAR.\p"
	.string "KAPT. BRIGG hat mich damit\n"
	.string "beauftragt, eine Fähre zu konstruieren.\p"
	.string "Oh! Das da…\n"
	.string "Sind das DEVON-WAREN?\p"
	.string "Aber, ähm… Das ist ein ungünstiger\n"
	.string "Zeitpunkt…\p"
	.string "KAPT. BRIGG ist irgendwohin ge-\n"
	.string "gangen. Er sagte, er müsse was\l"
	.string "erledigen.\p"
	.string "Kann ich dich bitten, KAPT. BRIGG zu\n"
	.string "suchen und ihm das Paket zu bringen?$"
	.endif
	.endif

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.ifdef ENGLISH
	.string "DOCK: Where could CAPT. STERN have\n"
	.string "gone off to?\p"
	.string "Could you go find CAPT. STERN and\n"
	.string "deliver that parcel to him?$"
	.else
	.ifdef GERMAN
	.string "BOOTMAR: Wo könnte KAPT. BRIGG wohl\n"
	.string "hingegangen sein?\p"
	.string "Kannst du bitte KAPT. BRIGG suchen und\n"
	.string "ihm die Waren übergeben?$"
	.endif
	.endif

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.ifdef ENGLISH
	.string "DOCK: Shipbuilding is an art.\p"
	.string "A lot of things can't be figured out\n"
	.string "just by calculating.\p"
	.string "I really could use advice from a veteran\n"
	.string "who knows the seas…$"
	.else
	.ifdef GERMAN
	.string "BOOTMAR: Der Schiffsbau ist eine Kunst.\p"
	.string "Manche Dinge lassen sich auch durch\n"
	.string "Berechnungen nicht vorhersehen.\p"
	.string "Jemand, der das Meer kennt wie seine\n"
	.string "Westentasche, müsste mir helfen…$"
	.endif
	.endif

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.ifdef ENGLISH
	.string "DOCK: Hi! MR. BRINEY's joined us to\n"
	.string "lend us his help.\p"
	.string "Thanks to the veteran sailor, the\n"
	.string "ferry is steadily coming together.$"
	.else
	.ifdef GERMAN
	.string "BOOTMAR: Hallo! MR. BRACK hat sich\n"
	.string "bereit erklärt, uns zu helfen.\p"
	.string "Dank dieses erfahrenen Seemannes\n"
	.string "kommen wir zügig voran.$"
	.endif
	.endif

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.ifdef ENGLISH
	.string "DOCK: The ferry is finally ready!\p"
	.string "The new S.S. TIDAL is truly a marvel\n"
	.string "of technology!\p"
	.string "But, I get the feeling that we can\n"
	.string "make something even better.\p"
	.string "You know, there's never an end to\n"
	.string "technology's march.$"
	.else
	.ifdef GERMAN
	.string "BOOTMAR: Die Fähre ist bald fertig!\p"
	.string "Die neue MS TIDE ist ein wahres\n"
	.string "Technikwunder!\p"
	.string "Aber ich denke doch, dass wir noch\n"
	.string "einiges besser machen können.\p"
	.string "Weißt du, die technische Entwicklung\n"
	.string "wird niemals abgeschlossen sein.$"
	.endif
	.endif

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.ifdef ENGLISH
	.string "MR. BRINEY: Ah, {PLAYER}{KUN}!\n"
	.string "It's been too long!\p"
	.string "Aye, since I met you, this old sea dog's\n"
	.string "been feeling frisky!\p"
	.string "So I've decided to help DOCK make\n"
	.string "a ferry.\p"
	.string "Aye, after all, a ferry would be able\n"
	.string "to carry a lot of people.\p"
	.string "But, you know, that DOCK is really\n"
	.string "something special.\p"
	.string "With his knack for technology and\n"
	.string "my experience, I'm sure that we can\l"
	.string "build one great ship, aye!$"
	.else
	.ifdef GERMAN
	.string "MR. BRACK: Ah, {PLAYER}{KUN}!\n"
	.string "Es ist schon lange her!\p"
	.string "Aye, seit ich dich kennen gelernt habe,\n"
	.string "bin ich wieder voller Tatendrang.\p"
	.string "Also habe ich mich entschlossen,\n"
	.string "BOOTMAR beim Bau der Fähre zu helfen.\p"
	.string "Aye, so wie es aussieht, wird die Fähre\n"
	.string "viele Passagiere befördern können.\p"
	.string "Aber, weißt du, BOOTMAR ist wirklich\n"
	.string "eine besondere Persönlichkeit.\p"
	.string "Mit seinem technischen Wissen und\n"
	.string "meiner Erfahrung auf See werden wir\l"
	.string "ein ganz besonderes Schiff bauen, aye.$"
	.endif
	.endif

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.ifdef ENGLISH
	.string "The seasons, the weather, where\n"
	.string "the moon sits in the sky…\p"
	.string "These and other conditions make\n"
	.string "the sea change its expression.\p"
	.string "That's right!\n"
	.string "The sea is like a living thing!$"
	.else
	.ifdef GERMAN
	.string "Die Jahreszeit, das Wetter, der Mond,\n"
	.string "der vom Himmel herabstrahlt…\p"
	.string "Das sind die Bedingungen, die die See\n"
	.string "so wechselhaft machen.\p"
	.string "Ganz genau!\n"
	.string "Die See ist wie ein lebendiges Wesen!$"
	.endif
	.endif

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.ifdef ENGLISH
	.string "I get seasick real easily.\n"
	.string "So I get to help out here instead.$"
	.else
	.ifdef GERMAN
	.string "Ich werde sehr schnell seekrank.\n"
	.string "Deshalb helfe ich lieber hier aus.$"
	.endif
	.endif

