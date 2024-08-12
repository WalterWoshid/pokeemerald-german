SafariZone_EventScript_OutOfBallsMidBattle::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	end

SafariZone_EventScript_Exit::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
#ifdef BUGFIX
	releaseall  @ Only gets called from EventScript_PokeBlockFeeder which uses lockall.
#endif
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.ifdef ENGLISH
	.string "Would you like to exit the SAFARI\n"
	.string "ZONE right now?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du die SAFARI-ZONE jetzt\n"
	.string "verlassen?$"
	.endif
	.endif

SafariZone_Text_TimesUp:
	.ifdef ENGLISH
	.string "Ding-dong! Time's up!\n"
	.string "Your SAFARI Game is over.$"
	.else
	.ifdef GERMAN
	.string "Ding Dong! Die Zeit ist abgelaufen!\n"
	.string "Dein SAFARI-Spiel ist vorbei.$"
	.endif
	.endif

SafariZone_Text_OutOfBalls:
	.ifdef ENGLISH
	.string "You've run out of SAFARI BALLS.\n"
	.string "Your SAFARI Game is over.$"
	.else
	.ifdef GERMAN
	.string "Du hast keine SAFARIBÄLLe mehr.\n"
	.string "Dein SAFARI-Spiel ist vorbei.$"
	.endif
	.endif

SafariZone_Text_PlacePokeblockOnFeeder:
	.ifdef ENGLISH
	.string "Would you like to place a {POKEBLOCK}\n"
	.string "on the {POKEBLOCK} FEEDER?$"
	.else
	.ifdef GERMAN
	.string "Möchtest du einen {POKEBLOCK} in den\n"
	.string "{POKEBLOCK}NAPF legen?$"
	.endif
	.endif

SafariZone_Text_PokeblockStillHere:
	.ifdef ENGLISH
	.string "The {STR_VAR_1} you left\n"
	.string "before is still here.$"
	.else
	.ifdef GERMAN
	.string "Dein {STR_VAR_1} liegt immer hier.$"
	.endif
	.endif

SafariZone_Text_PokeblockWasPlaced:
	.ifdef ENGLISH
	.string "The {STR_VAR_1} was placed\n"
	.string "on the {POKEBLOCK} FEEDER.$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_1} wurde in den {POKEBLOCK}-\n"
	.string "NAPF gelegt.$"
	.endif
	.endif

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.ifdef ENGLISH
	.string "Welcome to the SAFARI ZONE!\p"
	.string "Here, you may witness many kinds of\n"
	.string "POKéMON rarely seen in HOENN.\p"
	.string "And, you'll see them in their wild,\n"
	.string "untamed state in natural habitats.\p"
	.string "What's more, we've thrown open the\n"
	.string "gates to POKéMON TRAINERS.\p"
	.string "You're encouraged to catch POKéMON\n"
	.string "for keeps!\p"
	.string "Come in and enjoy the SAFARI ZONE!$"
	.else
	.ifdef GERMAN
	.string "Willkommen in der SAFARI-ZONE!\p"
	.string "Hier bekommst du viele POKéMON zu\n"
	.string "Gesicht, die sehr selten in der HOENN-\l"
	.string "Region sind.\p"
	.string "Du kannst sie in ihrer ganzen Wildheit\n"
	.string "und ungezähmt in ihrer natürlichen\l"
	.string "Umgebung beobachten.\p"
	.string "Wir haben unsere Tore für die POKéMON-\n"
	.string "TRAINER geöffnet.\p"
	.string "Fangt euch POKéMON. Und behaltet sie!\p"
	.string "Kommt und genießt die Welt der\n"
	.string "SAFARI-ZONE!$"
	.endif
	.endif

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.ifdef ENGLISH
	.string "Welcome to the SAFARI ZONE!\n"
	.string "Is it your first time here?$"
	.else
	.ifdef GERMAN
	.string "Willkommen in der SAFARI-ZONE!\n"
	.string "Bist du zum ersten Mal hier?$"
	.endif
	.endif

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.ifdef ENGLISH
	.string "Come in and enjoy the SAFARI ZONE!$"
	.else
	.ifdef GERMAN
	.string "Komm und genieße die SAFARI-ZONE!$"
	.endif
	.endif

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.ifdef ENGLISH
	.string "When you enter the SAFARI ZONE, you\n"
	.string "start with 30 SAFARI BALLS for\l"
	.string "catching POKéMON.\p"
	.string "The SAFARI Game is over when you run\n"
	.string "out of SAFARI BALLS, or when you've\l"
	.string "walked 500 steps.\p"
	.string "Come in and enjoy the SAFARI ZONE!$"
	.else
	.ifdef GERMAN
	.string "Sobald du die SAFARI-ZONE betrittst,\n"
	.string "stehen dir 30 SAFARIBÄLLe zur Ver-\l"
	.string "fügung, um POKéMON zu fangen.\p"
	.string "Das SAFARI-Spiel ist vorbei, sobald du\n"
	.string "deine SAFARIBÄLLe verbraucht oder\l"
	.string "500 Schritte gemacht hast.\p"
	.string "Komm und genieße die SAFARI-ZONE!$"
	.endif
	.endif

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.ifdef ENGLISH
	.string "Welcome to the SAFARI ZONE!\p"
	.string "All you can catch for just ¥500!\n"
	.string "Would you like to play a SAFARI Game?$"
	.else
	.ifdef GERMAN
	.string "Willkommen in der SAFARI-ZONE!\p"
	.string "Alles, was du für nur ¥500 fangen\n"
	.string "kannst! Möchtest du es probieren?$"
	.endif
	.endif

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.ifdef ENGLISH
	.string "Okay.\n"
	.string "Please play another time!$"
	.else
	.ifdef GERMAN
	.string "Okay.\n"
	.string "Bitte beehre uns doch später einmal.$"
	.endif
	.endif

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.ifdef ENGLISH
	.string "You don't have enough money.\n"
	.string "Sorry.$"
	.else
	.ifdef GERMAN
	.string "Du hast nicht genug Geld dabei.\n"
	.string "Tut mir Leid.$"
	.endif
	.endif

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.ifdef ENGLISH
	.string "That will be ¥500, please.$"
	.else
	.ifdef GERMAN
	.string "Das macht dann ¥500, bitte.$"
	.endif
	.endif

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.ifdef ENGLISH
	.string "Here are your SAFARI BALLS.$"
	.else
	.ifdef GERMAN
	.string "Hier sind deine SAFARIBÄLLe.$"
	.endif
	.endif

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.ifdef ENGLISH
	.string "{PLAYER} received 30 SAFARI BALLS.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} erhält 30 SAFARIBÄLLe.$"
	.endif
	.endif

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.ifdef ENGLISH
	.string "We'll let you know when your game\n"
	.string "is over.\p"
	.string "So, until then, enjoy yourself, please!\n"
	.string "Off you go on your wild excursion!$"
	.else
	.ifdef GERMAN
	.string "Wir geben dir Bescheid, wenn das Spiel\n"
	.string "vorbei ist.\p"
	.string "Bis dahin wünschen wir viel Spaß!\n"
	.string "Und auf geht’s in die Wildnis!$"
	.endif
	.endif

Route121_SafariZoneEntrance_Text_PCIsFull:
	.ifdef ENGLISH
	.string "Excuse me!\n"
	.string "Your PC BOX is full.$"
	.else
	.ifdef GERMAN
	.string "Entschuldigung!\n"
	.string "Deine PC-BOXen sind voll.$"
	.endif
	.endif

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.ifdef ENGLISH
	.string "Excuse me!\n"
	.string "You seem to be without a {POKEBLOCK} CASE.\p"
	.string "Your SAFARI Game will be much more\n"
	.string "fruitful if you use {POKEBLOCK}S.\p"
	.string "Please come back with a {POKEBLOCK} CASE.\p"
	.string "You may obtain a {POKEBLOCK} CASE from\n"
	.string "the LILYCOVE CONTEST HALL.$"
	.else
	.ifdef GERMAN
	.string "Entschuldigung!\n"
	.string "Du besitzt keine {POKEBLOCK}BOX.\p"
	.string "Dein SAFARI-Spiel wäre viel erfolg-\n"
	.string "reicher, wenn du {POKEBLOCK} benutzen\l"
	.string "würdest.\p"
	.string "Bitte besorge dir doch eine {POKEBLOCK}BOX.\p"
	.string "Vielleicht erhältst du in der WETT-\n"
	.string "BEWERBSHALLE von\l"
	.string "SEEGRASULB CITY eine.$"
	.endif
	.endif

SafariZone_South_Text_StillHaveTimeExit:
	.ifdef ENGLISH
	.string "You still have time left. Would you like\n"
	.string "to exit the SAFARI ZONE now?$"
	.else
	.ifdef GERMAN
	.string "Du hast noch Zeit übrig. Möchtest du\n"
	.string "die SAFARI-ZONE jetzt verlassen?$"
	.endif
	.endif

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.ifdef ENGLISH
	.string "Please enjoy the rest of your wild\n"
	.string "adventure!$"
	.else
	.ifdef GERMAN
	.string "Viel Vergnügen bei dem Rest deines\n"
	.string "wilden Abenteuers!$"
	.endif
	.endif

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.ifdef ENGLISH
	.string "Okay.\p"
	.string "I'll take back your remaining SAFARI\n"
	.string "BALLS.\p"
	.string "Thank you for playing.\n"
	.string "We hope to see you again.$"
	.else
	.ifdef GERMAN
	.string "Okay.\p"
	.string "Ich nehme die verbleibenden\n"
	.string "SAFARIBÄLLe zurück.\p"
	.string "Vielen Dank für deine Teilnahme.\n"
	.string "Komm bald wieder!$"
	.endif
	.endif

SafariZone_South_Text_GoodLuck:
	.ifdef ENGLISH
	.string "Good luck!\p"
	.string "If you need anything, don't hesitate\n"
	.string "to tell me, please!$"
	.else
	.ifdef GERMAN
	.string "Viel Glück!\p"
	.string "Wenn du irgendetwas brauchst, zögere\n"
	.string "nicht, mich anzusprechen!$"
	.endif
	.endif

SafariZone_South_Text_Boy:
	.ifdef ENGLISH
	.string "Did you know?\p"
	.string "If you put a {POKEBLOCK} in that square box,\n"
	.string "POKéMON gather around.$"
	.else
	.ifdef GERMAN
	.string "Weißt du was?\p"
	.string "Wenn du einen {POKEBLOCK} in diese Kiste\n"
	.string "dort legst, werden POKéMON angelockt.$"
	.endif
	.endif

SafariZone_South_Text_Man:
	.ifdef ENGLISH
	.string "I want to keep going deeper, but I\n"
	.string "forgot to bring a BIKE.\p"
	.string "Something tells me that rare POKéMON\n"
	.string "live in the outlying areas.$"
	.else
	.ifdef GERMAN
	.string "Ich wollte noch weiter hinein, aber\n"
	.string "ich habe mein RAD vergessen.\p"
	.string "Irgendetwas sagt mir, dass in den abge-\n"
	.string "legenen Gegenden seltene POKéMON\l"
	.string "leben.$"
	.endif
	.endif

SafariZone_Southwest_Text_Woman:
	.ifdef ENGLISH
	.string "Sometimes, when I toss a {POKEBLOCK} at \n"
	.string "POKéMON, it gets ignored.\p"
	.string "Do POKéMON have likes and dislikes\n"
	.string "about what they eat?$"
	.else
	.ifdef GERMAN
	.string "Manchmal, wenn ich einem POKéMON einen\n"
	.string "{POKEBLOCK} zuwerfe, ignoriert es das total.\p"
	.string "Ob POKéMON auch manche Dinge mögen\n"
	.string "und manche nicht? Wie wir Menschen?$"
	.endif
	.endif

SafariZone_Northwest_Text_Man:
	.ifdef ENGLISH
	.string "Gasp… Gasp…\n"
	.string "I…made it out here…but…\p"
	.string "I'm exhausted… I don't have the\n"
	.string "energy to catch POKéMON…$"
	.else
	.ifdef GERMAN
	.string "Hechel… Keuch…\n"
	.string "Ich… bin hierher gekommen… aber…\p"
	.string "Ich bin erschöpft… Japs… Ich habe\n"
	.string "keine Energie, ein POKéMON zu fangen.$"
	.endif
	.endif

SafariZone_North_Text_Fisherman:
	.ifdef ENGLISH
	.string "I'm on a mission to find WATER POKéMON\n"
	.string "you don't see in HOENN.\p"
	.string "Do you have any idea where the lake is?$"
	.else
	.ifdef GERMAN
	.string "Ich habe eine Mission. Ich will WASSER-\n"
	.string "POKéMON fangen, die es in HOENN nicht\l"
	.string "gibt.\p"
	.string "Weißt du zufällig, wo hier der See ist?$"
	.endif
	.endif

SafariZone_North_Text_Man:
	.ifdef ENGLISH
	.string "I'm going to catch a lot of rare POKéMON\n"
	.string "here and trade them with my friends!$"
	.else
	.ifdef GERMAN
	.string "Ich will viele seltene POKéMON fangen\n"
	.string "und mit meinen Freunden tauschen.$"
	.endif
	.endif

SafariZone_South_Text_Youngster:
	.ifdef ENGLISH
	.string "I put a {POKEBLOCK} on the {POKEBLOCK} FEEDER.\n"
	.string "But it seems to have disappeared.\p"
	.string "I guess POKéMON must have eaten it\n"
	.string "without me noticing.$"
	.else
	.ifdef GERMAN
	.string "Ich habe einen {POKEBLOCK} in den {POKEBLOCK}-\n"
	.string "NAPF gelegt. Er ist verschwunden.\p"
	.string "Ein POKéMON muss ihn gefuttert haben,\n"
	.string "ohne dass ich das gemerkt habe.$"
	.endif
	.endif

Route121_SafariZoneEntrance_Text_TrainerTip:
	.ifdef ENGLISH
	.string "SAFARI ZONE TRAINER TIP!\p"
	.string "Throw {POKEBLOCK}S at wild POKéMON to make\n"
	.string "them less likely to flee.$"
	.else
	.ifdef GERMAN
	.string "TIPP für TRAINER in der SAFARI-ZONE!\p"
	.string "Wirf POKéMON {POKEBLOCK} zu, dann ergreifen\n"
	.string "sie nicht so schnell die Flucht.$"
	.endif
	.endif

SafariZone_Southwest_Text_RestHouseSign:
	.ifdef ENGLISH
	.string "“Relieve your tired feet.”\n"
	.string "REST HOUSE$"
	.else
	.ifdef GERMAN
	.string "RASTHAUS\n"
	.string "“Erhole deine gemarterten Füße.”$"
	.endif
	.endif

SafariZone_RestHouse_Text_Youngster:
	.ifdef ENGLISH
	.string "I don't have any {POKEBLOCK}S, but I caught\n"
	.string "a good number of POKéMON.\p"
	.string "You can improve your chances of making\n"
	.string "a catch by getting closer to them\l"
	.string "before throwing a SAFARI BALL.$"
	.else
	.ifdef GERMAN
	.string "Ich habe keine {POKEBLOCK}, aber ich habe\n"
	.string "trotzdem viele POKéMON gefangen.\p"
	.string "Du kannst deine Chancen erhöhen, indem\n"
	.string "du näher an das POKéMON herangehst,\l"
	.string "bevor du den SAFARIBALL wirfst.$"
	.endif
	.endif

SafariZone_RestHouse_Text_PsychicM:
	.ifdef ENGLISH
	.string "If you use {POKEBLOCK}S, wild POKéMON won't\n"
	.string "be so quick to run away.\p"
	.string "It's not much use to give {POKEBLOCK}S to\n"
	.string "POKéMON that don't flee easily.$"
	.else
	.ifdef GERMAN
	.string "POKéMON fliehen nicht so schnell, wenn\n"
	.string "man ihnen {POKEBLOCK} zuwirft.\p"
	.string "POKéMON, die von Natur aus nicht\n"
	.string "schnell fliehen, braucht man sie nicht\l"
	.string "unbedingt zuzuwerfen.$"
	.endif
	.endif

SafariZone_RestHouse_Text_FatMan:
	.ifdef ENGLISH
	.string "If you put a {POKEBLOCK} on the FEEDER,\n"
	.string "POKéMON are attracted to it.\p"
	.string "I think POKéMON with the same sort of\n"
	.string "nature are drawn by a certain {POKEBLOCK}.$"
	.else
	.ifdef GERMAN
	.string "Wird ein {POKEBLOCK} in den NAPF gelegt,\n"
	.string "werden POKéMON angelockt.\p"
	.string "Ich glaube, POKéMON mit der gleichen\n"
	.string "Wesensart werden von ähnlichen\l"
	.string "{POKEBLOCK}n angezogen.$"
	.endif
	.endif

SafariZone_South_Text_AreaOffLimits1:
	.ifdef ENGLISH
	.string "This area is still under construction.\n"
	.string "It's off-limits, sorry!$"
	.else
	.ifdef GERMAN
	.string "In diesem Gebiet finden Bauarbeiten\n"
	.string "statt. Zutritt verboten!$"
	.endif
	.endif

SafariZone_Southeast_Text_ExpansionIsFinished:
	.ifdef ENGLISH
	.string "The SAFARI ZONE's expansion project\n"
	.string "is finished now.\p"
	.string "We hope you will enjoy the new area.$"
	.else
	.ifdef GERMAN
	.string "Der Ausbau der SAFARI-ZONE ist\n"
	.string "abgeschlossen.\p"
	.string "Wir hoffen, du genießt den Aufenthalt.$"
	.endif
	.endif

SafariZone_South_Text_AreaOffLimits2:
	.ifdef ENGLISH
	.string "This area is still under construction.\n"
	.string "It's off-limits, sorry!$"
	.else
	.ifdef GERMAN
	.string "In diesem Gebiet finden Bauarbeiten\n"
	.string "statt. Zutritt verboten!$"
	.endif
	.endif

SafariZone_Southeast_Text_LittleGirl:
	.ifdef ENGLISH
	.string "Wow! Whee! I haven't seen any of\n"
	.string "these POKéMON before!$"
	.else
	.ifdef GERMAN
	.string "Wow! Huiii! Diese POKéMON habe ich noch\n"
	.string "nie vorher gesehen!$"
	.endif
	.endif

SafariZone_Southeast_Text_FatMan:
	.ifdef ENGLISH
	.string "The POKéMON in this area are all\n"
	.string "new to me.\p"
	.string "And I'm allowed to catch these rare\n"
	.string "POKéMON! Too cool!$"
	.else
	.ifdef GERMAN
	.string "Die POKéMON in diesem Gebiet sind mir\n"
	.string "völlig unbekannt.\p"
	.string "Und ich darf diese seltenen POKéMON\n"
	.string "auch noch fangen! Ich kann mein Glück\l"
	.string "kaum fassen! Cool!$"
	.endif
	.endif

SafariZone_Southeast_Text_RichBoy:
	.ifdef ENGLISH
	.string "The POKéMON around here seem to be\n"
	.string "from somewhere other than HOENN.$"
	.else
	.ifdef GERMAN
	.string "Die POKéMON in diesem Gebiet scheinen\n"
	.string "nicht aus HOENN zu kommen.$"
	.endif
	.endif

SafariZone_Northeast_Text_Boy:
	.ifdef ENGLISH
	.string "I only have a couple SAFARI BALLS left.\p"
	.string "I'm having a hard time trying to\n"
	.string "decide what I should catch.$"
	.else
	.ifdef GERMAN
	.string "Ich habe nur noch wenige SAFARIBÄLLe\n"
	.string "übrig.\p"
	.string "Mir fällt es schwer, mich zu\n"
	.string "entscheiden, welches POKéMON ich\l"
	.string "nun fangen soll.$"
	.endif
	.endif

SafariZone_Northeast_Text_Woman:
	.ifdef ENGLISH
	.string "I heard that you can see PIKACHU here.\n"
	.string "Where might one be?$"
	.else
	.ifdef GERMAN
	.string "Ich habe gehört, man könne hier auf\n"
	.string "PIKACHU treffen. Wo mag nur eins sein?$"
	.endif
	.endif

SafariZone_Northeast_Text_Girl:
	.ifdef ENGLISH
	.string "Oh, boo!\n"
	.string "I can't seem to catch anything!\p"
	.string "I'll end up wasting the admission\n"
	.string "price if I don't catch something!$"
	.else
	.ifdef GERMAN
	.string "Schluchz heul!\n"
	.string "Ich schaffe es nicht, eines zu fangen.\p"
	.string "Ich habe mein Geld umsonst ausgegeben,\n"
	.string "wenn ich nichts fange.$"
	.endif
	.endif
