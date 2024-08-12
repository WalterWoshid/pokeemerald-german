CableClub_Text_WelcomeWhichCableClubService:
	.ifdef ENGLISH
	.string "Welcome to the POKéMON CABLE\n"
	.string "CLUB.\p"
	.string "Which of our services do you wish\n"
	.string "to use?$"
	.else
	.ifdef GERMAN
	.string "Willkommen im POKéMON\n"
	.string "KABEL-CLUB!\p"
	.string "Welchen Service möchtest du\n"
	.string "nutzen?$"
	.endif
	.endif

CableClub_Text_WhichService:
	.ifdef ENGLISH
	.string "Which of our services do you wish\n"
	.string "to use?$"
	.else
	.ifdef GERMAN
	.string "Welchen Service möchtest du\n"
	.string "nutzen?$"
	.endif
	.endif

CableClub_Text_TradeUsingLinkCable::
	.ifdef ENGLISH
	.string "Trade POKéMON with another player\n"
	.string "using a GBA Game Link cable.$"
	.else
	.ifdef GERMAN
	.string "Tausche POKéMON mit einem\n"
	.string "Mitspieler via GBA Game Link-Kabel.$"
	.endif
	.endif

CableClub_Text_BattleUsingLinkCable::
	.ifdef ENGLISH
	.string "You may battle another TRAINER\n"
	.string "using a GBA Game Link cable.$"
	.else
	.ifdef GERMAN
	.string "Tritt gegen einen anderen TRAINER\n"
	.string "via GBA Game Link-Kabel an.$"
	.endif
	.endif

CableClub_Text_RecordCornerUsingLinkCable::
	.ifdef ENGLISH
	.string "You can use the RECORD CORNER with\n"
	.string "others using a GBA Game Link cable.$"
	.else
	.ifdef GERMAN
	.string "Mit dem GBA Game Link-Kabel kannst du\n"
	.string "einen STATISTIKTAUSCH vornehmen.$"
	.endif
	.endif

@ Unused
CableClub_Text_CloseThisMenu:
	.ifdef ENGLISH
	.string "Close this menu.$"
	.else
	.ifdef GERMAN
	.string "Close this menu.$"
	.endif
	.endif

CableClub_Text_NeedTwoMonsForDoubleBattle:
	.ifdef ENGLISH
	.string "For a DOUBLE BATTLE, you must\n"
	.string "have at least two POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Für einen DOPPELKAMPF brauchst du\n"
	.string "mindestens zwei POKéMON.$"
	.endif
	.endif

CableClub_Text_NeedTwoMonsToTrade:
	.ifdef ENGLISH
	.string "For trading, you must have at\n"
	.string "least two POKéMON with you.$"
	.else
	.ifdef GERMAN
	.string "Für einen Tausch musst du mindestens\n"
	.string "zwei POKéMON bei dir haben.$"
	.endif
	.endif

CableClub_Text_CantTradeEnigmaBerry:
	.ifdef ENGLISH
	.string "A POKéMON holding the {STR_VAR_1}\n"
	.string "BERRY can't be traded.$"
	.else
	.ifdef GERMAN
	.string "Ein POKéMON, das eine {STR_VAR_1}BEERE\n"
	.string "hält, kann nicht getauscht werden.$"
	.endif
	.endif

gText_PleaseWaitForLink::
	.ifdef ENGLISH
	.string "Please wait.\n"
	.string "… … B Button: Cancel$"
	.else
	.ifdef GERMAN
	.string "Bitte warten.\n"
	.string "Drücke den B-Knopf, um abzubrechen…$"
	.endif
	.endif

gText_ConfirmLinkWhenPlayersReady::
	.ifdef ENGLISH
	.string "When all players are ready…\n"
	.string "A Button: Confirm\l"
	.string "B Button: Cancel$"
	.else
	.ifdef GERMAN
	.string "Wenn die Spieler bereit sind…\n"
	.string "A-Knopf: Bestätigen\l"
	.string "B-Knopf: Abbruch$"
	.endif
	.endif

gText_ConfirmStartLinkWithXPlayers::
	.ifdef ENGLISH
	.string "Start link with {STR_VAR_1} players.\n"
	.string "A Button: Confirm\l"
	.string "B Button: Cancel$"
	.else
	.ifdef GERMAN
	.string "Verbindung für {STR_VAR_1} Spieler aufbauen.\n"
	.string "A-Knopf: Bestätigen\l"
	.string "B-Knopf: Abbruch$"
	.endif
	.endif

gText_AwaitingLinkup::
	.ifdef ENGLISH
	.string "Awaiting linkup…\n"
	.string "… … B Button: Cancel$"
	.else
	.ifdef GERMAN
	.string "Verbindungsaufbau…\n"
	.string "… … B-Knopf: Abbruch$"
	.endif
	.endif

@ Unused
CableClub_Text_OkayToSaveProgress::
	.ifdef ENGLISH
	.string "Your progress must be saved before\n"
	.string "linking. Is it okay to save?$"
	.else
	.ifdef GERMAN
	.string "Your progress must be saved before\n"
	.string "linking. Is it okay to save?$"
	.endif
	.endif

CableClub_Text_PleaseEnter:
	.ifdef ENGLISH
	.string "Please enter.$"
	.else
	.ifdef GERMAN
	.string "Bitte eintreten.$"
	.endif
	.endif

CableClub_Text_DirectYouToYourRoom:
	.ifdef ENGLISH
	.string "I'll direct you to your room now.$"
	.else
	.ifdef GERMAN
	.string "Bitte eintreten.$"
	.endif
	.endif

Text_SomeoneIsNotReadyToLink:
	.ifdef ENGLISH
	.string "Someone is not ready to link.\p"
	.string "Please come back after everyone\n"
	.string "has made preparations.$"
	.else
	.ifdef GERMAN
	.string "Ein Spieler ist noch nicht bereit\n"
	.string "für den Link.\p"
	.string "Bitte kommt wieder, wenn jeder seine\n"
	.string "Vorbereitungen getroffen hat.$"
	.endif
	.endif

Text_LinkErrorPleaseReset:
	.ifdef ENGLISH
	.string "Sorry, we have a link error…\n"
	.string "Please reset and try again.$"
	.else
	.ifdef GERMAN
	.string "Verbindungsfehler…\n"
	.string "Die Kabelverbindungen überprüfen und\l"
	.string "eine erneute Verbindung herstellen.$"
	.endif
	.endif

Text_PlayersMadeDifferentSelections:
	.ifdef ENGLISH
	.string "The link partners appear to have\n"
	.string "made different selections.$"
	.else
	.ifdef GERMAN
	.string "Die Link-Partner haben eine unter-\n"
	.string "schiedliche Auswahl getroffen.$"
	.endif
	.endif

CableClub_Text_PleaseVisitAgain:
	.ifdef ENGLISH
	.string "Please do visit again.$"
	.else
	.ifdef GERMAN
	.string "Bitte komm bald wieder.$"
	.endif
	.endif

CableClub_Text_IncorrectNumberOfParticipants:
	.ifdef ENGLISH
	.string "The number of participants is\n"
	.string "incorrect.$"
	.else
	.ifdef GERMAN
	.string "Die Anzahl der Teilnehmer ist nicht\n"
	.string "korrekt.$"
	.endif
	.endif

CableClub_Text_CantSingleBattleWithXPlayers:
	.ifdef ENGLISH
	.string "The SINGLE BATTLE Mode can't be\n"
	.string "played by {STR_VAR_1} players.$"
	.else
	.ifdef GERMAN
	.string "Ein EINZELKAMPF kann nicht von\n"
	.string "{STR_VAR_1} Spielern geführt werden.$"
	.endif
	.endif

CableClub_Text_CantDoubleBattleWithXPlayers:
	.ifdef ENGLISH
	.string "The DOUBLE BATTLE Mode can't be\n"
	.string "played by {STR_VAR_1} players.$"
	.else
	.ifdef GERMAN
	.string "Ein DOPPELKAMPF kann nicht von\n"
	.string "{STR_VAR_1} Spielern geführt werden.$"
	.endif
	.endif

CableClub_Text_NeedFourPlayers:
	.ifdef ENGLISH
	.string "There must be four players to play\n"
	.string "this Battle Mode.$"
	.else
	.ifdef GERMAN
	.string "Für diesen Kampfmodus werden vier\n"
	.string "Spieler benötigt.$"
	.endif
	.endif

CableClub_Text_PleaseConfirmNumberAndRestart:
	.ifdef ENGLISH
	.string "Please confirm the number of\n"
	.string "players and start again.$"
	.else
	.ifdef GERMAN
	.string "Bitte überprüfe die Anzahl der\n"
	.string "Spieler und fange nochmals an.$"
	.endif
	.endif

Text_TerminateLinkConfirmation:
	.ifdef ENGLISH
	.string "The link will be terminated if you\n"
	.string "leave the room. Is that okay?$"
	.else
	.ifdef GERMAN
	.string "Wenn du den Raum verlässt, wird die\n"
	.string "Verbindung abgebrochen.\l"
	.string "Einverstanden?$"
	.endif
	.endif

Text_TerminateLinkPleaseWait:
	.ifdef ENGLISH
	.string "Terminating link…\n"
	.string "You will be escorted out of\l"
	.string "the room. Please wait.$"
	.else
	.ifdef GERMAN
	.string "Verbindung wird abgebrochen…\n"
	.string "Du wirst aus dem Raum begleitet.\l"
	.string "Bitte warten.$"
	.endif
	.endif

CableClub_Text_TooBusyToNotice:
	.ifdef ENGLISH
	.string "This TRAINER is too busy to\n"
	.string "notice…$"
	.else
	.ifdef GERMAN
	.string "Dieser TRAINER ist zu beschäftigt…$"
	.endif
	.endif

CableClub_Text_GotToLookAtTrainerCard:
	.ifdef ENGLISH
	.string "Score! Got to look at {STR_VAR_1}'s\n"
	.string "TRAINER CARD!$"
	.else
	.ifdef GERMAN
	.string "Hey! Schau dir mal den TRAINERPASS\n"
	.string "von {STR_VAR_1} an!$"
	.endif
	.endif

CableClub_Text_GotToLookAtColoredTrainerCard:
	.ifdef ENGLISH
	.string "Score! Got to look at {STR_VAR_1}'s\n"
	.string "TRAINER CARD!\p"
	.string "It's a {STR_VAR_2} card!$"
	.else
	.ifdef GERMAN
	.string "Hey! Schau dir mal den TRAINERPASS\n"
	.string "von {STR_VAR_1} an! Es ist ein\l"
	.string "{STR_VAR_2}PASS.$"
	.endif
	.endif

BattleColosseum_2P_Text_TakePlaceStartBattle:
	.ifdef ENGLISH
	.string "Please take your place and start\n"
	.string "your battle.$"
	.else
	.ifdef GERMAN
	.string "Bitte geh in Position und beginne mit\n"
	.string "dem Kampf.$"
	.endif
	.endif

TradeCenter_Text_TakeSeatStartTrade:
	.ifdef ENGLISH
	.string "Please take your seat and start\n"
	.string "your trade.$"
	.else
	.ifdef GERMAN
	.string "Bitte geh in Position und beginne mit\n"
	.string "dem Tausch.$"
	.endif
	.endif

RecordCorner_Text_ThanksForComing:
	.ifdef ENGLISH
	.string "Thanks for coming.$"
	.else
	.ifdef GERMAN
	.string "Danke für den Besuch!$"
	.endif
	.endif

CableClub_Text_TrainerCardDataOverwritten:
	.ifdef ENGLISH
	.string "The TRAINER CARD data will\n"
	.string "be overwritten.$"
	.else
	.ifdef GERMAN
	.string "Der Eintrag auf dem TRAINERPASS wird\n"
	.string "geändert.$"
	.endif
	.endif

CableClub_Text_HopeToSeeYouAgain:
	.ifdef ENGLISH
	.string "I hope to see you again!$"
	.else
	.ifdef GERMAN
	.string "Ich hoffe, du kommst bald wieder vorbei.$"
	.endif
	.endif

CableClub_Text_NotSetUpForFarAwayRegion:
	.ifdef ENGLISH
	.string "I'm awfully sorry.\p"
	.string "We're not set up to conduct trades\n"
	.string "with TRAINERS far away in another\l"
	.string "region yet…$"
	.else
	.ifdef GERMAN
	.string "Es tut mir schrecklich Leid.\p"
	.string "Wir sind noch nicht auf einen\n"
	.string "Tausch mit TRAINERn aus\l"
	.string "entfernten Gebieten vorbereitet…$"
	.endif
	.endif

CableClub_Text_OtherTrainerNotReady:
	.ifdef ENGLISH
	.string "The other TRAINER is not ready.$"
	.else
	.ifdef GERMAN
	.string "Der andere TRAINER ist noch\n"
	.string "nicht bereit!$"
	.endif
	.endif

CableClub_Text_YouHaveAMonThatCantBeTaken:
	.ifdef ENGLISH
	.string "You have at least one POKéMON\n"
	.string "that can't be taken.$"
	.else
	.ifdef GERMAN
	.string "Du besitzt mindestens ein POKéMON,\n"
	.string "das nicht mitgenommen werden kann.$"
	.endif
	.endif

RecordCorner_Text_TakeSeatAndWait:
	.ifdef ENGLISH
	.string "Please take your seat and wait.$"
	.else
	.ifdef GERMAN
	.string "Bitte geh in Position und warte.$"
	.endif
	.endif

RecordCorner_Text_PlayerSentOverOneX:
	.ifdef ENGLISH
	.string "{STR_VAR_1} sent over one\n"
	.string "{STR_VAR_2}.$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_1} hat ein {STR_VAR_2}\n"
	.string "versandt.$"
	.endif
	.endif

CableClub_Text_CantMixWithJapaneseGame:
	.ifdef ENGLISH
	.string "Sorry, there is a transmission error.\p"
	.string "You may not mix records with  \n"
	.string "Japanese Ruby or Sapphire games.\p"
	.string "Also, you can't mix records with\n"
	.string "Japanese Emerald and overseas Ruby\l"
	.string "or Sapphire games at the same time.$"
	.else
	.ifdef GERMAN
	.string "Tut mir Leid, es gibt einen\n"
	.string "Verbindungsfehler.\p"
	.string "Du kannst mit den japanischen\n"
	.string "Versionen der Rubin- und Saphir-\l"
	.string "Edition keine Statistiken tauschen.\p"
	.string "Du kannst zeitgleich keine Statistiken\n"
	.string "mit der japanischen Smaragd-Edition\l"
	.string "und den außerjapanischen Rubin- und\l"
	.string "Saphir-Editionen tauschen.$"
	.endif
	.endif

CableClub_Text_AdapterNotConnected:
	.ifdef ENGLISH
	.string "The Wireless Adapter is not\n"
	.string "connected properly.$"
	.else
	.ifdef GERMAN
	.string "Der Drahtlose Game Boy\n"
	.string "Advance-Adapter ist nicht\l"
	.string "ordnungsgemäß angeschlossen.$"
	.endif
	.endif

CableClub_Text_ParticipantsStepUpToCounter:
	.ifdef ENGLISH
	.string "Participants are asked to step up\n"
	.string "to the reception counter.$"
	.else
	.ifdef GERMAN
	.string "Die Teilnehmer werden gebeten,\n"
	.string "zur Rezeption zu gehen.$"
	.endif
	.endif

@ Unused
CableClub_Text_Hello:
	.ifdef ENGLISH
	.string "Hello!$"
	.else
	.ifdef GERMAN
	.string "Hello!$"
	.endif
	.endif

@ Unused
CableClub_Text_PleaseWait:
	.ifdef ENGLISH
	.string "Please wait.$"
	.else
	.ifdef GERMAN
	.string "Please wait.$"
	.endif
	.endif

CableClub_Text_YouMayTradeHere::
	.ifdef ENGLISH
	.string "You may trade your POKéMON here\n"
	.string "with another TRAINER.$"
	.else
	.ifdef GERMAN
	.string "Hier kannst du mit deinen Freunden\n"
	.string "POKéMON tauschen.$"
	.endif
	.endif

CableClub_Text_YouMayBattleHere::
	.ifdef ENGLISH
	.string "You may battle with your friends\n"
	.string "here.$"
	.else
	.ifdef GERMAN
	.string "Hier kannst du mit deinen Freunden\n"
	.string "kämpfen.$"
	.endif
	.endif

CableClub_Text_CanMakeBerryPowder::
	.ifdef ENGLISH
	.string "Two to five TRAINERS can make\n"
	.string "BERRY POWDER together.$"
	.else
	.ifdef GERMAN
	.string "Zwei bis fünf TRAINER können\n"
	.string "zusammen BEERENPUDER herstellen.$"
	.endif
	.endif

CableClub_Text_CanMixRecords::
	.ifdef ENGLISH
	.string "The records of two to four players\n"
	.string "can be mixed together.$"
	.else
	.ifdef GERMAN
	.string "Die Statistiken von zwei bis vier\n"
	.string "Spielern können getauscht werden.$"
	.endif
	.endif

@ Unused
CableClub_Text_GuideToVariousServices:
	.ifdef ENGLISH
	.string "A guide to the WIRELESS CLUB's\n"
	.string "various services.$"
	.else
	.ifdef GERMAN
	.string "A guide to the WIRELESS CLUB’s\n"
	.string "various services.$"
	.endif
	.endif

CableClub_Text_CancelSelectedItem::
	.ifdef ENGLISH
	.string "Cancels the selected MENU item.$"
	.else
	.ifdef GERMAN
	.string "Widerruft das MENÜ.$"
	.endif
	.endif

@ Unused
CableClub_Text_WhichBattleMode:
	.ifdef ENGLISH
	.string "Which battle mode would you like?$"
	.else
	.ifdef GERMAN
	.string "Which battle mode would you like?$"
	.endif
	.endif

@ Unused
CableClub_Text_ReturnsToPreviousStep:
	.ifdef ENGLISH
	.string "Returns to the previous step.$"
	.else
	.ifdef GERMAN
	.string "Returns to the previous step.$"
	.endif
	.endif

CableClub_Text_NeedBerryForBerryCrush:
	.ifdef ENGLISH
	.string "To use the BERRY CRUSH service,\n"
	.string "you must have at least one BERRY.$"
	.else
	.ifdef GERMAN
	.string "Um die BEERENMÜHLE benutzen\n"
	.string "zu können, musst du mindestens\l"
	.string "eine BEERE besitzen.$"
	.endif
	.endif

CableClub_Text_NeedTwoMonsForUnionRoom:
	.ifdef ENGLISH
	.string "To enter the UNION ROOM, you must\n"
	.string "have at least two POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Um den KONNEX-KLUB betreten zu\n"
	.string "dürfen, musst du mindestens zwei\l"
	.string "POKéMON besitzen.$"
	.endif
	.endif

CableClub_Text_NoEnigmaBerryInUnionRoom:
	.ifdef ENGLISH
	.string "No POKéMON holding the {STR_VAR_1}\n"
	.string "BERRY may enter the UNION ROOM.$"
	.else
	.ifdef GERMAN
	.string "Ein POKéMON, das eine {STR_VAR_1}BEERE\n"
	.string "hält, darf den KONNEX-KLUB nicht\l"
	.string "betreten.$"
	.endif
	.endif

CableClub_Text_UnionRoomAdapterNotConnected:
	.ifdef ENGLISH
	.string "This is the POKéMON WIRELESS CLUB\n"
	.string "UNION ROOM.\p"
	.string "Unfortunately, your Wireless\n"
	.string "Adapter is not connected properly.\p"
	.string "Please do come again.$"
	.else
	.ifdef GERMAN
	.string "Das ist der DRAHTLOSE POKéMON\n"
	.string "KONNEX-KLUB.\p"
	.string "Leider ist dein Drahtloser Game Boy\n"
	.string "Advance-Adapter nicht\l"
	.string "ordnungsgemäß angeschlossen.\l"
	.string "Bitte komme später wieder!$"
	.endif
	.endif

@ Unused
CableClub_Text_OhExcuseMe:
	.ifdef ENGLISH
	.string "Oh…\n"
	.string "Excuse me!$"
	.else
	.ifdef GERMAN
	.string "Oh…\n"
	.string "Excuse me!$"
	.endif
	.endif

CableClub_Text_PlayerIsWaiting:
	.ifdef ENGLISH
	.string "It appears as if {STR_VAR_1} is playing\n"
	.string "right now.\l"
	.string "Go for it!$"
	.else
	.ifdef GERMAN
	.string "Es scheint, als ob {STR_VAR_1} gerade\n"
	.string "spielt.\l"
	.string "Los!$"
	.endif
	.endif

MossdeepCity_GameCorner_1F_Text_DescribeWhichGame:
	.ifdef ENGLISH
	.string "I can explain game rules to you,\n"
	.string "if you'd like.\p"
	.string "Which game should I describe?$"
	.else
	.ifdef GERMAN
	.string "Ich kann dir die Spielregeln\n"
	.string "erklären, wenn du möchtest.\p"
	.string "Welches Spiel möchtest du erklärt\n"
	.string "bekommen?$"
	.endif
	.endif

MossdeepCity_GameCorner_1F_Text_PokemonJumpInfo:
	.ifdef ENGLISH
	.string "“POKéMON JUMP”\p"
	.string "Make your POKéMON skip the VINE WHIP\n"
	.string "rope with the A Button.\p"
	.string "Only mini POKéMON around 28 inches\n"
	.string "or less may participate.\p"
	.string "POKéMON that only swim, burrow,\n"
	.string "or fly are not good at jumping.\p"
	.string "As a result, those POKéMON may not\n"
	.string "participate.\p"
	.string "Good things happen if everyone\n"
	.string "jumps in time.$"
	.else
	.ifdef GERMAN
	.string "“POKéMON-SPRUNG”\p"
	.string "Springe mit deinem POKéMON durch\n"
	.string "Drücken des A-Knopfs über den\l"
	.string "RANKENHIEB.\l"
	.string "Es dürfen nur kleine, circa\l"
	.string "70 cm große POKéMON\l"
	.string "teilnehmen.\l"
	.string "POKéMON, die ausschließlich\l"
	.string "schwimmen, graben oder fliegen,\l"
	.string "können nicht gut springen.\l"
	.string "Daher dürfen diese POKéMON auch\l"
	.string "nicht teilnehmen.\p"
	.string "Etwas Schönes passiert, wenn alle\n"
	.string "rechtzeitig springen.$"
	.endif
	.endif

MossdeepCity_GameCorner_1F_Text_DodrioBerryPickingInfo:
	.ifdef ENGLISH
	.string "“DODRIO BERRY-PICKING”\p"
	.string "Command DODRIO's three heads to\n"
	.string "catch falling BERRIES.\p"
	.string "Press right, up, or left on the\n"
	.string "{PLUS} Control Pad to move the heads.\p"
	.string "To play this game, you must have\n"
	.string "a DODRIO.$"
	.else
	.ifdef GERMAN
	.string "“BEERENERNTE MIT DODRI”\p"
	.string "Bewege DODRIs drei Köpfe, um die\n"
	.string "fallenden BEEREn zu fangen.\p"
	.string "Drücke das {PLUS} Steuerkreuz nach\n"
	.string "rechts, oben oder links, um die\l"
	.string "Köpfe zu bewegen.\l"
	.string "Um an diesem Spiel teilnehmen zu\l"
	.string "dürfen, benötigst du ein DODRI.$"
	.endif
	.endif

MossdeepCity_GameCorner_1F_Text_TalkToOldManToPlay:
	.ifdef ENGLISH
	.string "If you want to play a game,\n"
	.string "please tell the old man beside me.$"
	.else
	.ifdef GERMAN
	.string "Wenn du spielen möchtest, dann wende\n"
	.string "dich bitte an den älteren Herrn\l"
	.string "neben mir.$"
	.endif
	.endif

MossdeepCity_GameCorner_1F_Text_WelcomeCanYouWait:
	.ifdef ENGLISH
	.string "Hi, welcome!\n"
	.string "Are you here to play games using\l"
	.string "Wireless Communication?\p"
	.string "Can you wait just a little bit?$"
	.else
	.ifdef GERMAN
	.string "Hallo! Herzlich willkommen!\p"
	.string "Möchtest du mit Hilfe des Drahtlosen\n"
	.string "Kommunikations-Systems spielen?\p"
	.string "Bitte gedulde dich noch ein wenig!$"
	.endif
	.endif

MossdeepCity_GameCorner_1F_Text_ComeAgain:
	.ifdef ENGLISH
	.string "All right, come again!$"
	.else
	.ifdef GERMAN
	.string "In Ordnung! Komme wieder!$"
	.endif
	.endif

MossdeepCity_GameCorner_1F_Text_AdapterNotConnected:
	.ifdef ENGLISH
	.string "The Wireless Adapter isn't connected.\n"
	.string "Come back when it's hooked up!$"
	.else
	.ifdef GERMAN
	.string "Der Drahtlose Game Boy\n"
	.string "Advance-Adapter ist nicht\l"
	.string "angeschlossen.\p"
	.string "Komm wieder, wenn er\n"
	.string "angeschlossen ist!$"
	.endif
	.endif

MossdeepCity_GameCorner_1F_Text_PlayWhichGame:
	.ifdef ENGLISH
	.string "All right, which game did you want\n"
	.string "to play?$"
	.else
	.ifdef GERMAN
	.string "O.K., was wolltest du spielen?$"
	.endif
	.endif

MossdeepCity_GameCorner_1F_Text_EnterWhichPokemon:
	.ifdef ENGLISH
	.string "Which POKéMON would you like to\n"
	.string "enter?$"
	.else
	.ifdef GERMAN
	.string "Welches POKéMON soll teilnehmen?$"
	.endif
	.endif

MossdeepCity_GameCorner_1F_Text_AllGoodToGo:
	.ifdef ENGLISH
	.string "Okay, you're all good to go.\n"
	.string "Don't let the others beat you!$"
	.else
	.ifdef GERMAN
	.string "Gut, du kannst loslegen!\n"
	.string "Lass nicht zu, dass dich die\l"
	.string "anderen besiegen!$"
	.endif
	.endif

@ Unused
MossdeepCity_GameCorner_1F_Text_LeavingDoComeAgain:
	.ifdef ENGLISH
	.string "Are you leaving now?\n"
	.string "Do come again!$"
	.else
	.ifdef GERMAN
	.string "Are you leaving now?\n"
	.string "Do come again!$"
	.endif
	.endif

MossdeepCity_GameCorner_1F_Text_ExplainRequiredMon:
	.ifdef ENGLISH
	.string "It doesn't look like you have any\n"
	.string "POKéMON that you can enter…\p"
	.string "Would you like me to explain what\n"
	.string "kinds of POKéMON can enter?$"
	.else
	.ifdef GERMAN
	.string "Es scheint, dass keines deiner\n"
	.string "POKéMON teilnehmen kann…\p"
	.string "Soll ich dir erklären, welche\n"
	.string "POKéMON teilnehmen dürfen?$"
	.endif
	.endif

MossdeepCity_GameCorner_1F_Text_ShortJumpingPokemonAllowed:
	.ifdef ENGLISH
	.string "“POKéMON JUMP” is open to POKéMON\n"
	.string "around 28 inches or less.\p"
	.string "What you can't enter are those\n"
	.string "POKéMON that can't jump.\p"
	.string "You know, like POKéMON that only\n"
	.string "swim, burrow, or fly.\p"
	.string "That's all you need to know.$"
	.else
	.ifdef GERMAN
	.string "Am “POKéMON-SPRUNG”\n"
	.string "dürfen POKéMON, die 70 cm oder\l"
	.string "kleiner sind, teilnehmen.\p"
	.string "POKéMON, die nicht springen können,\n"
	.string "dürfen nicht teilnehmen.\p"
	.string "Zum Beispiel POKéMON, die nur\n"
	.string "schwimmen, graben oder fliegen.\p"
	.string "Das ist schon alles!$"
	.endif
	.endif

MossdeepCity_GameCorner_1F_Text_OnlyDodrioAllowed:
	.ifdef ENGLISH
	.string "DODRIO BERRY-PICKING is a game that \n"
	.string "only DODRIO may enter.$"
	.else
	.ifdef GERMAN
	.string "“BEERENERNTE MIT DODRI”…\n"
	.string "Nur ein DODRI kann teilnehmen.$"
	.endif
	.endif

@ Unused
MossdeepCity_GameCorner_1F_Text_RetryPlease:
	.ifdef ENGLISH
	.string "Could you retry this from the start\n"
	.string "again, please?$"
	.else
	.ifdef GERMAN
	.string "Could you retry this from the start\n"
	.string "again, please?$"
	.endif
	.endif

CableClub_Text_WelcomeWhichDirectCornerRoom:
	.ifdef ENGLISH
	.string "Welcome to the POKéMON WIRELESS\n"
	.string "CLUB DIRECT CORNER.\p"
	.string "You may interact directly with\n"
	.string "your friends here.\p"
	.string "Which room would you like to\n"
	.string "enter?$"
	.else
	.ifdef GERMAN
	.string "Willkommen im POKéMON\n"
	.string "DRAHTLOSEN DIREKTKLUB.\p"
	.string "Welchen KLUB möchtest du betreten?$"
	.endif
	.endif

CableClub_Text_TradePokemon:
	.ifdef ENGLISH
	.string "Would you like to trade POKéMON?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du jetzt POKéMON\n"
	.string "tauschen?$"
	.endif
	.endif

CableClub_Text_PlayWhichBattleMode:
	.ifdef ENGLISH
	.string "Which Battle Mode would you like\n"
	.string "to play?$"
	.else
	.ifdef GERMAN
	.string "Welche Art des Kampfes?$"
	.endif
	.endif

CableClub_Text_AccessRecordCorner:
	.ifdef ENGLISH
	.string "Would you like to access\n"
	.string "the RECORD CORNER?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du am STATISTIKTAUSCH\n"
	.string "teilnehmen?$"
	.endif
	.endif

CableClub_Text_UseBerryCrush:
	.ifdef ENGLISH
	.string "Would you like to use the\n"
	.string "BERRY CRUSH System?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du die BEERENMÜHLE\n"
	.string "benutzen?$"
	.endif
	.endif

CableClub_Text_ExplainBattleModes:
	.ifdef ENGLISH
	.string "There are three Battle Modes.\p"
	.string "SINGLE BATTLE is for two TRAINERS\n"
	.string "with one or more POKéMON each.\p"
	.string "Each TRAINER can have one POKéMON\n"
	.string "in battle at a time.\p"
	.string "DOUBLE BATTLE is for two TRAINERS\n"
	.string "with two or more POKéMON each.\p"
	.string "Each TRAINER will send out two\n"
	.string "POKéMON in battle at a time.\p"
	.string "MULTI BATTLE is for four TRAINERS\n"
	.string "with one or more POKéMON each.\p"
	.string "Each TRAINER can have one POKéMON\n"
	.string "in battle at a time.$"
	.else
	.ifdef GERMAN
	.string "Es gibt drei Kampfarten.\p"
	.string "EINZELKAMPF ist für zwei TRAINER,\n"
	.string "mit je einem oder\l"
	.string "mehreren POKéMON.\p"
	.string "Jeder TRAINER schickt pro Runde\n"
	.string "ein POKéMON in den Kampf.\p"
	.string "DOPPELKAMPF ist für zwei TRAINER\n"
	.string "mit je zwei oder mehr PKMN.\p"
	.string "Jeder TRAINER schickt pro Runde\n"
	.string "zwei POKéMON in den Kampf.\p"
	.string "MULTIKÄMPFE sind für vier TRAINER\n"
	.string "mit je einem oder mehreren PKMN.\p"
	.string "Jeder TRAINER schickt pro Runde\n"
	.string "ein POKéMON in den Kampf.$"
	.endif
	.endif

CableClub_Text_ChooseGroupLeaderOfTwo:
	.ifdef ENGLISH
	.string "Please decide which of you two\n"
	.string "will become the LEADER.\p"
	.string "The other player must then choose\n"
	.string "“JOIN GROUP.”$"
	.else
	.ifdef GERMAN
	.string "Bitte legt fest, wer von euch der\n"
	.string "LEITER ist.\p"
	.string "Der andere Spieler wählt\n"
	.string "“MITSPIELER” aus.$"
	.endif
	.endif

CableClub_Text_ChooseGroupLeaderOfFour:
	.ifdef ENGLISH
	.string "Please decide which of you four\n"
	.string "will become the GROUP LEADER.\p"
	.string "The other players must then choose\n"
	.string "“JOIN GROUP.”$"
	.else
	.ifdef GERMAN
	.string "Bitte legt fest, wer in eurem TEAM\n"
	.string "der LEITER ist.\p"
	.string "Die anderen Spieler wählen\n"
	.string "“MITSPIELER” aus.$"
	.endif
	.endif

CableClub_Text_ChooseGroupLeader:
	.ifdef ENGLISH
	.string "Please decide which of you will\n"
	.string "become the GROUP LEADER.\p"
	.string "The other players must then choose\n"
	.string "“JOIN GROUP.”$"
	.else
	.ifdef GERMAN
	.string "Bitte legt fest, wer in eurem TEAM\n"
	.string "der LEITER ist.\p"
	.string "Die anderen Spieler wählen\n"
	.string "“MITSPIELER” aus.$"
	.endif
	.endif

CableClub_Text_WelcomeUnionRoomEnter:
	.ifdef ENGLISH
	.string "Welcome to the POKéMON WIRELESS\n"
	.string "CLUB UNION ROOM.\p"
	.string "You may interact directly with\n"
	.string "other TRAINERS here, some of\l"
	.string "whom you may not even know.\p"
	.string "Would you like to enter the ROOM?$"
	.else
	.ifdef GERMAN
	.string "Willkommen im POKéMON DRAHTLOSEN\n"
	.string "KONNEX-KLUB.\p"
	.string "Du kannst hier direkt mit anderen\n"
	.string "TRAINERn interagieren, sogar\l"
	.string "mit unbekannten.\l"
	.string "Möchtest du den KLUB betreten?$"
	.endif
	.endif

CableClub_Text_UnionRoomInfo:
	.ifdef ENGLISH
	.string "The TRAINERS in the UNION ROOM\n"
	.string "will be those players around you\l"
	.string "who have also entered the ROOM.\p"
	.string "You may do all sorts of things\n"
	.string "here, such as exchanging greetings.\p"
	.string "You may enter two POKéMON up to\n"
	.string "Lv. 30 for a one-on-one battle.\p"
	.string "You may take part in a chat with\n"
	.string "two to five people.\p"
	.string "Or, you may register a POKéMON for\n"
	.string "trade.\p"
	.string "Would you like to enter the ROOM?$"
	.else
	.ifdef GERMAN
	.string "Die TRAINER im KONNEX-KLUB sind\n"
	.string "die Spieler, die ebenfalls den KLUB\l"
	.string "betreten haben.\p"
	.string "Hier kannst du alles Mögliche\n"
	.string "machen, z.B. Grußformeln\l"
	.string "austauschen!\l"
	.string "Du darfst zwei POKéMON bis\l"
	.string "Level 30 für einen Einzelkampf\l"
	.string "mitnehmen.\l"
	.string "Du kannst eine Unterhaltung mit\l"
	.string "zwei bis fünf Teilnehmern führen.\p"
	.string "Oder du meldest ein POKéMON zum\n"
	.string "Tausch an.\p"
	.string "Möchtest du den Klub betreten?$"
	.endif
	.endif

CableClub_Text_EnjoyUnionRoom:
	.ifdef ENGLISH
	.string "I hope you enjoy your time in\n"
	.string "the UNION ROOM.$"
	.else
	.ifdef GERMAN
	.string "Ich hoffe, du genießt deinen\n"
	.string "Aufenthalt im KONNEX-KLUB.$"
	.endif
	.endif

CableClub_Text_FirstTimeRightThisWay:
	.ifdef ENGLISH
	.string "Hello!\n"
	.string "My name is TEALA.\p"
	.string "This must be your first time\n"
	.string "up here.\p"
	.string "I'll show you how the Wireless\n"
	.string "Communication System works.\p"
	.string "First, I need to show you this\n"
	.string "floor of our POKéMON CENTER.\p"
	.string "Right this way, please.$"
	.else
	.ifdef GERMAN
	.string "Hallo!\n"
	.string "Ich bin TEALA.\p"
	.string "Dies scheint dein erstes Mal hier\n"
	.string "zu sein.\p"
	.string "Ich zeige dir, wie das Drahtlose\n"
	.string "Kommunikations-System funktioniert.\p"
	.string "Zunächst zeige ich dir dieses\n"
	.string "Stockwerk unseres POKéMON-\l"
	.string "CENTERs.\p"
	.string "Hier entlang bitte!$"
	.endif
	.endif

CableClub_Text_ExplainWirelessClubFirstTime:
	.ifdef ENGLISH
	.string "On the top floor, there are two\n"
	.string "rooms.\p"
	.string "First, the room on the left.\n"
	.string "It's the UNION ROOM.\p"
	.string "You may link up with TRAINERS\n"
	.string "around you who have also entered\l"
	.string "the UNION ROOM.\p"
	.string "With them, you may do things like\n"
	.string "chat, battle, and trade.\p"
	.string "Second, the room on the right is\n"
	.string "the DIRECT CORNER.\p"
	.string "You may trade or battle POKéMON\n"
	.string "with your friends in this room.\p"
	.string "If the Wireless Adapter isn't\n"
	.string "connected, you may still link up\l"
	.string "using a GBA Game Link cable.\p"
	.string "If that is the case, you must go\n"
	.string "to the DIRECT CORNER.\p"
	.string "I hope you enjoy the Wireless \n"
	.string "Communication System.$"
	.else
	.ifdef GERMAN
	.string "Im Obergeschoss gibt es zwei\n"
	.string "KLUBs.\p"
	.string "Zum Ersten den KLUB links.\n"
	.string "Das ist der KONNEX-KLUB.\p"
	.string "Hier kannst du TRAINER treffen, die\n"
	.string "ebenfalls den KONNEX-KLUB\l"
	.string "betreten haben.\p"
	.string "Du kannst mit ihnen sprechen,\n"
	.string "kämpfen und tauschen.\p"
	.string "Zum Zweiten den KLUB rechts.\n"
	.string "Das ist der DIREKTKLUB.\p"
	.string "Hier kannst du mit POKéMON gegen\n"
	.string "Freunde kämpfen oder sie tauschen.\p"
	.string "Falls der Drahtlose Game Boy\n"
	.string "Advance-Adapter nicht\l"
	.string "eingesteckt ist, kannst du das\l"
	.string "GBA Game Link-Kabel benutzen.\p"
	.string "In diesem Fall musst du den\n"
	.string "DIREKTKLUB betreten.\p"
	.string "Viel Vergnügen mit dem Drahtlosen\n"
	.string "Kommunikations-System.$"
	.endif
	.endif

CableClub_Text_AskAboutLinking:
	.ifdef ENGLISH
	.string "Hello, {PLAYER}!\p"
	.string "It's me, TEALA, the POKéMON\n"
	.string "CENTER 2F attendant.\p"
	.string "Is there something you needed to\n"
	.string "ask me about linking?$"
	.else
	.ifdef GERMAN
	.string "Hallo {PLAYER}!\p"
	.string "Ich bin es, TEALA, die Angestellte\n"
	.string "vom 1. Stock im POKéMON-CENTER.\p"
	.string "Möchtest du mich etwas über das\n"
	.string "Herstellen einer Verbindung fragen?$"
	.endif
	.endif

CableClub_Text_ExplainWirelessClub:
	.ifdef ENGLISH
	.string "Let me explain how the POKéMON\n"
	.string "WIRELESS CLUB works.\p"
	.string "On this, the top floor, there are\n"
	.string "two rooms.\p"
	.string "First, the room on the left.\n"
	.string "It's the UNION ROOM.\p"
	.string "You may link up with TRAINERS\n"
	.string "around you who have also entered\l"
	.string "the UNION ROOM.\p"
	.string "With them, you may do things like\n"
	.string "chat, battle, and trade.\p"
	.string "Second, the room on the right is\n"
	.string "the DIRECT CORNER.\p"
	.string "You may trade or battle POKéMON\n"
	.string "with your friends in this room.\p"
	.string "Sometimes, you may not be able to\n"
	.string "find your friends in the UNION ROOM\l"
	.string "or the DIRECT CORNER.\p"
	.string "In that case, please move closer\n"
	.string "to your friends.\p"
	.string "If the Wireless Adapter isn't\n"
	.string "connected, you may still link up\l"
	.string "using a GBA Game Link cable.\p"
	.string "If that is the case, you must go\n"
	.string "to the DIRECT CORNER.\p"
	.string "I hope you enjoy the Wireless \n"
	.string "Communication System.$"
	.else
	.ifdef GERMAN
	.string "Ich erkläre dir, wie der POKéMON\n"
	.string "DRAHTLOSKLUB funktioniert.\p"
	.string "Im Obergeschoss gibt es zwei\n"
	.string "KLUBs.\p"
	.string "Zum Ersten den linken KLUB.\n"
	.string "Das ist der KONNEX-KLUB.\p"
	.string "Hier kannst du TRAINER treffen, die\n"
	.string "ebenfalls den KONNEX-KLUB\l"
	.string "betreten haben.\p"
	.string "Du kannst mit ihnen sprechen,\n"
	.string "kämpfen und tauschen.\p"
	.string "Zum Zweiten den KLUB rechts.\n"
	.string "Das ist der DIREKTKLUB.\p"
	.string "Hier kannst du mit POKéMON gegen\n"
	.string "Freunde kämpfen oder sie tauschen.\p"
	.string "Manchmal kannst du deine\n"
	.string "Freunde in keinem der KLUBs\l"
	.string "treffen.\p"
	.string "In diesem Fall musst du näher\n"
	.string "zu deinen Freunden rücken.\p"
	.string "Falls der Drahtlose Game Boy\n"
	.string "Advance-Adapter nicht\l"
	.string "benutzt wird, kannst\l"
	.string "du via Game Boy Advance\l"
	.string "Game Link-Kabel eine\l"
	.string "Verbindung herstellen.\p"
	.string "In diesem Fall musst du in\n"
	.string "den DIREKTKLUB gehen.\p"
	.string "Viel Vergnügen mit dem Drahtlosen\n"
	.string "Kommunikations-System.$"
	.endif
	.endif

CableClub_Text_HopeYouEnjoyWirelessSystem:
	.ifdef ENGLISH
	.string "I hope you enjoy the Wireless\n"
	.string "Communication System.$"
	.else
	.ifdef GERMAN
	.string "Viel Vergnügen mit dem Drahtlosen\n"
	.string "Kommunikations-System.$"
	.endif
	.endif
