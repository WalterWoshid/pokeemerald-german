BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.ifdef ENGLISH
	.string "Howdy! When it comes to news about\n"
	.string "the BATTLE FRONTIER, I'm no. 1.\p"
	.string "You can think of me as\n"
	.string "the FRONTIER MANIAC.\p"
	.string "Just checking, but you are a TRAINER,\n"
	.string "isn't that right?\p"
	.string "I'll happily share the hottest news\n"
	.string "I gathered about the BATTLE FRONTIER.$"
	.else
	.ifdef GERMAN
	.string "Halli hallo! Wenn du Neuigkeiten über\n"
	.string "die KAMPFZONE erfahren willst,\l"
	.string "bin ich die Nummer eins für dich!\p"
	.string "Ich bin der KAMPFZONEN-MANIAC.\p"
	.string "Nur zur Sicherheit: Du bist doch ein\n"
	.string "TRAINER, oder?\p"
	.string "Ich werde dir die neuesten Neuigkeiten\n"
	.string "über die KAMPFZONE erzählen!$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.ifdef ENGLISH
	.string "Howdy! Did you swing by to grill me\n"
	.string "about the latest word? Oh, all right!$"
	.else
	.ifdef GERMAN
	.string "Halli hallo! Du willst bestimmt die\n"
	.string "neuesten Neuigkeiten aus mir\l"
	.string "herauspressen! Hab ich Recht?$"
	.endif
	.endif

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.ifdef ENGLISH
	.string "Well? Well? Well?\p"
	.string "I'm sure my information's been\n"
	.string "seriously useful to you, right?$"
	.else
	.ifdef GERMAN
	.string "Well? Well? Well?\p"
	.string "I’m sure my information’s been\n"
	.string "seriously useful to you, right?$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.ifdef ENGLISH
	.string "Let's see now…\p"
	.string "It sounds like the {STR_VAR_1}\n"
	.string "is the hottest place going.$"
	.else
	.ifdef GERMAN
	.string "Mal sehen…\p"
	.string "Scheinbar ist {STR_VAR_1}\n"
	.string "im Moment der angesagteste Ort.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.ifdef ENGLISH
	.string "Let's see now…\p"
	.string "It sounds like BATTLE TOWER\n"
	.string "{STR_VAR_1} is the hottest.$"
	.else
	.ifdef GERMAN
	.string "Mal sehen…\p"
	.string "Scheinbar ist der DUELLTURM\n"
	.string "{STR_VAR_1} im Moment der\l"
	.string "angesagteste Ort.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.ifdef ENGLISH
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this mysterious TRAINER called\n"
	.string "the SALON MAIDEN that runs the place.$"
	.else
	.ifdef GERMAN
	.string "Ich wette, das hier weißt du noch nicht!\p"
	.string "Einer der Top-TRAINER, die SCOTT die\n"
	.string "KAMPFKORYPHÄEN nennt, ist hier.\p"
	.string "Ein sehr geheimnisvoller TRAINER…\n"
	.string "Der KAMPFKOLOSS, der hier alles leitet.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.ifdef ENGLISH
	.string "Have you battled the SALON MAIDEN?\p"
	.string "When she's measuring up her opponent,\n"
	.string "she apparently uses these POKéMON:\p"
	.string "A PSYCHIC-type PSI POKéMON,\n"
	.string "a FIRE-type VOLCANO POKéMON,\l"
	.string "and a NORMAL-type SLEEPING POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Bist du schon gegen den KAMPFKOLOSS\n"
	.string "angetreten?\p"
	.string "Er schätzt seine Gegner ab und setzt\n"
	.string "die folgenden drei POKéMON ein:\p"
	.string "Ein PSI-POKéMON, Typ PSYCHO.\n"
	.string "Ein VULKAN-POKéMON, Typ FEUER.\p"
	.string "Und ein TAGTRÄUMER-POKéMON,\n"
	.string "Typ NORMAL.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.ifdef ENGLISH
	.string "Have you battled the SALON MAIDEN\n"
	.string "when she's serious?\p"
	.string "When she's battling flat out,\n"
	.string "she apparently uses these POKéMON:\p"
	.string "A DRAGON & PSYCHIC EON POKéMON,\n"
	.string "an ELECTRIC-type THUNDER POKéMON,\l"
	.string "and a NORMAL-type SLEEPING POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Bist du dem KAMPFKOLOSS schon\n"
	.string "begegnet, wenn er ernsthaft kämpft?\p"
	.string "In dem Fall setzt er folgende POKéMON\n"
	.string "ein:\p"
	.string "Ein ÄON-POKéMON, Typ DRACHE & PSYCHO.\n"
	.string "Ein DONNER-POKéMON, Typ ELEKTRO.\l"
	.string "Und ein TAGTRÄUMER-POKéMON,\l"
	.string "Typ NORMAL.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.ifdef ENGLISH
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this flamboyant TRAINER called\n"
	.string "the DOME ACE that runs the place.$"
	.else
	.ifdef GERMAN
	.string "Ich wette, das hier weißt du noch nicht!\p"
	.string "Einer der Top-TRAINER, die SCOTT die\n"
	.string "KAMPFKORYPHÄEN nennt, ist hier.\p"
	.string "Ein großspuriger TRAINER…\n"
	.string "Der STADIONSTAR, der hier alles leitet.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.ifdef ENGLISH
	.string "Have you battled the DOME ACE?\p"
	.string "When he's treating the opponent\n"
	.string "lightly, he uses these three POKéMON:\p"
	.string "A DRAGON & FLYING DRAGON POKéMON,\n"
	.string "a WATER & GROUND MUD FISH POKéMON,\l"
	.string "and a FIRE & FLYING FLAME POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Bist du schon gegen den STADIONSTAR\n"
	.string "angetreten?\p"
	.string "Er tritt mit folgenden POKéMON gegen\n"
	.string "seine Herausforderer an:\p"
	.string "Ein DRACHE-POKéMON, Typ DRACHE & FLUG.\n"
	.string "Ein LEHMHÜPFER-POKéMON, Typ WASSER\l"
	.string "& BODEN.\p"
	.string "Und ein FLAMME-POKéMON, Typ\n"
	.string "FEUER & FLUG.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.ifdef ENGLISH
	.string "Have you battled the DOME ACE\n"
	.string "when he's serious?\p"
	.string "When he's demonstrating his strategy,\n"
	.string "he uses these three POKéMON:\p"
	.string "A DRAGON & FLYING EON POKéMON,\n"
	.string "a WATER & GROUND MUD FISH POKéMON,\l"
	.string "and a STEEL- & PSYCHIC-type IRON LEG\l"
	.string "POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Bist du schon gegen den STADIONSTAR\n"
	.string "angetreten, wenn er ernsthaft kämpft?\p"
	.string "Dann zeigt er dem Gegner mit den\n"
	.string "folgenden 3 POKéMON seine Strategie:\p"
	.string "Ein ÄON-POKéMON, Typ DRACHE & PSYCHO.\n"
	.string "Ein LEHMHÜPFER-POKéMON, Typ WASSER\l"
	.string "& BODEN.\p"
	.string "Und ein EISENFUSS-POKéMON, Typ\n"
	.string "STAHL & PSYCHO.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.ifdef ENGLISH
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this freaky TRAINER called\n"
	.string "the FACTORY HEAD that runs the place.$"
	.else
	.ifdef GERMAN
	.string "Ich wette, das hier weißt du noch nicht!\p"
	.string "Einer der Top-TRAINER, die SCOTT die\n"
	.string "KAMPFKORYPHÄEN nennt, ist hier.\p"
	.string "Ein sehr geheimnisvoller TRAINER…\n"
	.string "Der FABRIKLEITER, der hier alles leitet.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.ifdef ENGLISH
	.string "Have you battled the FACTORY HEAD\n"
	.string "already?\p"
	.string "Let me think… When he goes to battle,\n"
	.string "he just gets three rental POKéMON.\p"
	.string "He battles under pretty much the same\n"
	.string "conditions as you.$"
	.else
	.ifdef GERMAN
	.string "Bist du schon gegen den FABRIKLEITER\n"
	.string "angetreten?\p"
	.string "Lass mich mal nachdenken… Er geht\n"
	.string "immer mit drei Leih-PKMN in den Kampf.\p"
	.string "Er kämpft also fast unter den gleichen\n"
	.string "Bedingungen wie du.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.ifdef ENGLISH
	.string "Have you battled the FACTORY HEAD\n"
	.string "when he's serious?\p"
	.string "When he goes seriously to battle,\n"
	.string "he still gets three rental POKéMON.\p"
	.string "He battles under virtually the same\n"
	.string "conditions as you.$"
	.else
	.ifdef GERMAN
	.string "Bist du schon gegen den FABRIKLEITER\n"
	.string "angetreten, wenn er ernsthaft kämpft?\p"
	.string "Auch wenn er sich nicht zurückhalten\n"
	.string "will, nimmt er drei Leih-POKéMON mit in\l"
	.string "den Kampf.\p"
	.string "Er kämpft also fast unter den gleichen\n"
	.string "Bedingungen wie du.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.ifdef ENGLISH
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this scary TRAINER called\n"
	.string "the PIKE QUEEN that runs the place.$"
	.else
	.ifdef GERMAN
	.string "Ich wette, das hier weißt du noch nicht!\p"
	.string "Einer der Top-TRAINER, die SCOTT die\n"
	.string "KAMPFKORYPHÄEN nennt, ist hier.\p"
	.string "Ein sehr geheimnisvoller TRAINER…\n"
	.string "Die PFIPITISTIN, die hier alles leitet.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.ifdef ENGLISH
	.string "Have you battled the PIKE QUEEN\n"
	.string "before?\p"
	.string "When she's in a good mood, they say\n"
	.string "she uses these three POKéMON:\p"
	.string "A POISON-type FANG SNAKE POKéMON,\n"
	.string "a BUG & ROCK MOLD POKéMON,\l"
	.string "and a WATER-type TENDER POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Bist du schon mal gegen die\n"
	.string "PFIPITISTIN angetreten?\p"
	.string "Wenn sie gute Laune hat, dann setzt sie\n"
	.string "die folgenden drei POKéMON ein:\p"
	.string "Ein REISSZAHN-POKéMON, Typ GIFT.\n"
	.string "Ein SCHIMMEL-POKéMON, Typ KÄFER &\p"
	.string "GESTEIN sowie ein ZARTHEIT-POKéMON,\n"
	.string "Typ WASSER.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.ifdef ENGLISH
	.string "Have you battled the PIKE QUEEN\n"
	.string "when she's serious?\p"
	.string "When she's seriously annoyed, they say\n"
	.string "she uses these three POKéMON:\p"
	.string "A POISON-type FANG SNAKE POKéMON,\n"
	.string "a STEEL & GROUND IRON SNAKE POKéMON,\l"
	.string "and a WATER- & FLYING-type ATROCIOUS\l"
	.string "POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Bist du mal gegen die PFIPITISTIN an-\n"
	.string "getreten, wenn sie ernsthaft kämpft?\p"
	.string "Wenn sie schlechte Laune hat, dann\n"
	.string "setzt sie die folgenden 3 POKéMON ein:\p"
	.string "Ein REISSZAHN-POKéMON, Typ GIFT.\n"
	.string "Ein STAHLBOA-POKéMON, Typ STAHL &\p"
	.string "BODEN sowie ein GRAUSAM-POKéMON,\n"
	.string "Typ WASSER & FLUG.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.ifdef ENGLISH
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this cute TRAINER called\n"
	.string "the ARENA TYCOON that runs the place.$"
	.else
	.ifdef GERMAN
	.string "Ich wette, das hier weißt du noch nicht!\p"
	.string "Einer der Top-TRAINER, die SCOTT die\n"
	.string "KAMPFKORYPHÄEN nennt, ist hier.\p"
	.string "Ein niedlicher TRAINER…\n"
	.string "Der RINGMEISTER, der hier\l"
	.string "alles leitet.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.ifdef ENGLISH
	.string "Have you battled the ARENA TYCOON\n"
	.string "before?\p"
	.string "When she's assessing the foe's ability,\n"
	.string "she supposedly uses these POKéMON:\p"
	.string "A BUG & FIGHTING SINGLE HORN POKéMON,\n"
	.string "a DARK-type MOONLIGHT POKéMON,\l"
	.string "and a BUG & GHOST SHED POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Bist du schon mal gegen den\n"
	.string "RINGMEISTER angetreten?\p"
	.string "Wenn er seinen Gegner abschätzen will,\n"
	.string "setzt er diese drei POKéMON ein:\p"
	.string "Ein EINZELHORN-POKéMON, Typ KÄFER &\n"
	.string "KAMPF. Ein MONDSCHEIN-POKéMON, Typ\p"
	.string "UNLICHT sowie ein HÄUTUNG-POKéMON,\n"
	.string "Typ KÄFER & GEIST.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.ifdef ENGLISH
	.string "Have you battled the ARENA TYCOON\n"
	.string "when she's serious?\p"
	.string "When she battles for keeps,\n"
	.string "she supposedly uses these POKéMON:\p"
	.string "A DARK-type MOONLIGHT POKéMON,\n"
	.string "a GHOST & POISON SHADOW POKéMON\l"
	.string "and a GRASS- & FIGHTING-type\l"
	.string "MUSHROOM POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Bist du schon mal gegen den\n"
	.string "RINGMEISTER angetreten, wenn er\l"
	.string "ernsthaft kämpft?\p"
	.string "Er bleibt auch dann noch sehr höflich\n"
	.string "und setzt diese drei POKéMON ein:\p"
	.string "Ein MONDSCHEIN-POKéMON, Typ\n"
	.string "UNLICHT, ein SCHATTEN-POKéMON, Typ\l"
	.string "GEIST & GIFT sowie ein PILZ-POKéMON,\l"
	.string "Typ PFLANZE & KAMPF.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.ifdef ENGLISH
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this sinister TRAINER called\n"
	.string "the PALACE MAVEN that runs the place.$"
	.else
	.ifdef GERMAN
	.string "Ich wette, das hier weißt du noch nicht!\p"
	.string "Einer der Top-TRAINER, die SCOTT die\n"
	.string "KAMPFKORYPHÄEN nennt, ist hier.\p"
	.string "Ein sehr hinterhältiger TRAINER…\n"
	.string "Der PALASTREGENT, der hier alles leitet.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.ifdef ENGLISH
	.string "Have you battled the PALACE MAVEN\n"
	.string "before?\p"
	.string "When he's testing the opponent's\n"
	.string "spirit, he's said to use these POKéMON:\p"
	.string "A POISON & FLYING-type BAT POKéMON,\n"
	.string "a NORMAL-type LAZY POKéMON, and a\l"
	.string "WATER- & ICE-type TRANSPORT POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Bist du schon mal gegen den PALAST-\n"
	.string "REGENTEN angetreten?\p"
	.string "Wenn er den Geist seiner Gegner\n"
	.string "abschätzen will, setzt er diese\l"
	.string "3 POKéMON ein:\p"
	.string "Ein FLEDERMAUS-POKéMON, Typ GIFT &\n"
	.string "FLUG. Ein MÜSSIG-POKéMON, Typ\p"
	.string "NORMAL sowie ein TRANSPORT-POKéMON,\n"
	.string "Typ WASSER & EIS.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.ifdef ENGLISH
	.string "Have you battled the PALACE MAVEN\n"
	.string "when he's serious?\p"
	.string "When he throws his entire might into\n"
	.string "battle, he's said to use these POKéMON:\p"
	.string "A FIRE-type LEGENDARY POKéMON,\n"
	.string "a NORMAL-type LAZY POKéMON,\l"
	.string "and a WATER-type AURORA POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Bist du schon mal gegen den PALAST-\n"
	.string "REGENTEN angetreten, wenn er\l"
	.string "ernsthaft kämpft?\p"
	.string "Wenn er im Kampf alles geben will, setzt\n"
	.string "er diese drei POKéMON ein:\p"
	.string "Ein LEGENDÄRES POKéMON, Typ FEUER.\n"
	.string "Ein MÜSSIG-POKéMON, Typ\p"
	.string "NORMAL sowie ein POLARLICHT-POKéMON,\n"
	.string "Typ WASSER.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.ifdef ENGLISH
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this fiery-hot TRAINER called\n"
	.string "the PYRAMID KING that runs the place.$"
	.else
	.ifdef GERMAN
	.string "Ich wette, das hier weißt du noch nicht!\p"
	.string "Einer der Top-TRAINER, die SCOTT die\n"
	.string "KAMPFKORYPHÄEN nennt, ist hier.\p"
	.string "Ein sehr hitzköpfiger TRAINER…\n"
	.string "Der PYRAKÖNIG, der hier alles leitet.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.ifdef ENGLISH
	.string "Have you battled the PYRAMID KING\n"
	.string "before?\p"
	.string "When he's checking the foe's power,\n"
	.string "he apparently uses these POKéMON:\p"
	.string "A ROCK-type ROCK PEAK POKéMON,\n"
	.string "an ICE-type ICEBERG POKéMON,\l"
	.string "and a STEEL-type IRON POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Bist du schon mal gegen den PYRAKÖNIG\n"
	.string "angetreten?\p"
	.string "Wenn er die Kraft seiner Gegner\n"
	.string "abschätzen will, setzt er diese\l"
	.string "3 POKéMON ein:\p"
	.string "Ein STEINGIPFEL-POKéMON, Typ GESTEIN.\n"
	.string "Ein EISBERG-POKéMON, Typ\p"
	.string "EIS sowie ein EISEN-POKéMON,\n"
	.string "Typ STAHL.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.ifdef ENGLISH
	.string "Have you battled the PYRAMID KING\n"
	.string "when he's serious?\p"
	.string "When he's pumped with hot power,\n"
	.string "he apparently uses these POKéMON:\p"
	.string "An ICE & FLYING FREEZE POKéMON, an\n"
	.string "ELECTRIC & FLYING ELECTRIC POKéMON,\l"
	.string "and a FIRE- & FLYING-type FLAME\l"
	.string "POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Bist du schon mal gegen den PYRAKÖNIG\n"
	.string "angetreten, wenn er ernsthaft\l"
	.string "kämpft?\p"
	.string "Wenn er vor Kraft fast explodiert,\n"
	.string "setzt er diese drei POKéMON ein:\p"
	.string "Ein EIS-POKéMON, Typ EIS & FLUG.\n"
	.string "Ein ELEKTRO-POKéMON, Typ\p"
	.string "ELEKTRO & FLUG sowie ein FLAMME-\n"
	.string "POKéMON, Typ FEUER & FLUG$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.ifdef ENGLISH
	.string "Sure, there are several places where\n"
	.string "you can enter DOUBLE BATTLES.\p"
	.string "But the DOUBLE BATTLE ROOMS of\n"
	.string "the BATTLE TOWER are, like, basic!\p"
	.string "They're where you should learn about\n"
	.string "how DOUBLE BATTLES are played here\l"
	.string "in the BATTLE FRONTIER.$"
	.else
	.ifdef GERMAN
	.string "Natürlich gibt es verschiedene Orte, an\n"
	.string "denen du DOPPELKÄMPFE austragen\l"
	.string "kannst.\p"
	.string "Aber die DOPPELKÄMPFE des\n"
	.string "DUELLTURMs sind klasse!\p"
	.string "Dort kannst du lernen, wie die DOPPEL-\n"
	.string "KÄMPFE hier in der KAMPFZONE\l"
	.string "ausgetragen werden.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.ifdef ENGLISH
	.string "Watch yourself in the battles here.\p"
	.string "I hear there are TRAINERS that have\n"
	.string "strategies they developed just for\l"
	.string "DOUBLE BATTLES.$"
	.else
	.ifdef GERMAN
	.string "Beobachte dich selbst und lerne dazu.\p"
	.string "Die TRAINER hier haben Strategien\n"
	.string "entwickelt, die sie nur hier in\l"
	.string "DOPPELKÄMPFEN einsetzen!$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.ifdef ENGLISH
	.string "Once you're confident and comfortable\n"
	.string "with DOUBLE BATTLES here, you should\l"
	.string "think about challenging other places\l"
	.string "offering DOUBLE BATTLES.$"
	.else
	.ifdef GERMAN
	.string "Sobald du Selbstvertrauen gewonnen\n"
	.string "hast und du dich bei DOPPELKÄMPFEN\l"
	.string "auskennst, solltest du andere Orte\l"
	.string "aufsuchen, die diese Kämpfe anbieten.$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.ifdef ENGLISH
	.string "All sorts of TRAINERS gather in\n"
	.string "the BATTLE SALON.\p"
	.string "Just think--you may run into your\n"
	.string "friends or followers!\l"
	.string "You should look carefully!$"
	.else
	.ifdef GERMAN
	.string "In der TEAMLOUNGE trifft man auf die\n"
	.string "unterschiedlichsten TRAINER.\p"
	.string "Stell dir mal vor! Du triffst vielleicht\n"
	.string "auf einen Freund oder Fans!\l"
	.string "Schau dich gut um!$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.ifdef ENGLISH
	.string "If you're with a friend, head for the\n"
	.string "LINK MULTI BATTLE ROOM.\p"
	.string "If you play with a strong friend,\n"
	.string "you can expect to see tough foes!$"
	.else
	.ifdef GERMAN
	.string "Begleitet dich ein Freund, solltet ihr\n"
	.string "den LINK-MULTIKAMPF-Raum aufsuchen.\p"
	.string "Trittst du mit einem starken Freund\n"
	.string "an, sind auch deine Gegner stark!$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.ifdef ENGLISH
	.string "What amazing news-gathering power!\n"
	.string "My mentor's like none other!$"
	.else
	.ifdef GERMAN
	.string "Was für ein Talent, Neuigkeiten aufzu-\n"
	.string "spüren! Niemand kann meinem Mentor\l"
	.string "darin das Wasser reichen!!!$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.ifdef ENGLISH
	.string "What amazing powers of observation!\n"
	.string "My mentor's like none other!$"
	.else
	.ifdef GERMAN
	.string "Was für eine Beobachtungsgabe!\n"
	.string "Niemand kann meinem Mentor\l"
	.string "darin das Wasser reichen!!!$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.ifdef ENGLISH
	.string "What amazing power of persuasion!\n"
	.string "My mentor's like none other!$"
	.else
	.ifdef GERMAN
	.string "Was für eine Überzeugungskraft!\n"
	.string "Niemand kann meinem Mentor\l"
	.string "darin das Wasser reichen!!!$"
	.endif
	.endif

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.ifdef ENGLISH
	.string "…What is this place?\n"
	.string "It's scaring me…$"
	.else
	.ifdef GERMAN
	.string "Was ist dies für ein Ort?\n"
	.string "Er macht mir Angst…$"
	.endif
	.endif

