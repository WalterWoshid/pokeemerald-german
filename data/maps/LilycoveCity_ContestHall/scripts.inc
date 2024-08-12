@ VAR_LAST_TALKED would have made all these direct references unnecessary
.set LOCALID_SMART_MC, 4
.set LOCALID_SMART_JUDGE, 5
.set LOCALID_SMART_CONTESTANT_1, 6
.set LOCALID_SMART_CONTESTANT_2, 7
.set LOCALID_SMART_CONTESTANT_3, 8
.set LOCALID_SMART_CONTESTANT_4, 9
.set LOCALID_SMART_AUDIENCE_4, 11
.set LOCALID_SMART_AUDIENCE_2, 12
.set LOCALID_BEAUTY_MC, 13
.set LOCALID_BEAUTY_JUDGE, 14
.set LOCALID_BEAUTY_CONTESTANT_1, 15
.set LOCALID_BEAUTY_CONTESTANT_2, 16
.set LOCALID_BEAUTY_CONTESTANT_3, 17
.set LOCALID_BEAUTY_CONTESTANT_4, 18
.set LOCALID_BEAUTY_AUDIENCE_1, 19
.set LOCALID_BEAUTY_AUDIENCE_3, 20
.set LOCALID_BEAUTY_AUDIENCE_2, 21
.set LOCALID_SMART_AUDIENCE_3, 22
.set LOCALID_CUTE_MC, 23
.set LOCALID_CUTE_JUDGE, 24
.set LOCALID_CUTE_CONTESTANT_1, 25
.set LOCALID_CUTE_CONTESTANT_2, 26
.set LOCALID_CUTE_CONTESTANT_3, 27
.set LOCALID_CUTE_CONTESTANT_4, 28
.set LOCALID_CUTE_AUDIENCE_1, 29
.set LOCALID_CUTE_AUDIENCE_3, 30
.set LOCALID_CUTE_AUDIENCE_2, 31

LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.ifdef ENGLISH
	.string "This POKéMON won the BEAUTY CONTEST\n"
	.string "here before.\p"
	.string "Well, guess what? Today, I made it\n"
	.string "win a SMARTNESS CONTEST!\p"
	.string "My abilities scare even me…$"
	.else
	.ifdef GERMAN
	.string "Dieses POKéMON hat den vorherigen\n"
	.string "SCHÖNHEITSWETTBEWERB gewonnen.\p"
	.string "Weißt du was? Heute werde ich den\n"
	.string "KLUGHEITS-WETTBEWERB gewinnen!\p"
	.string "Meine Fähigkeiten erstaunen sogar\n"
	.string "mich…$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.ifdef ENGLISH
	.string "I've entered a bunch of CONTESTS,\n"
	.string "so I'm seeing how things work.\p"
	.string "If you're in a COOLNESS CONTEST,\n"
	.string "cool moves go over as appeals.\p"
	.string "But smart moves and cute moves\n"
	.string "don't go over well, for instance.$"
	.else
	.ifdef GERMAN
	.string "Ich habe einige WETTBEWERBe mitge-\n"
	.string "macht, weil ich wissen wollte, wie\l"
	.string "das so läuft.\p"
	.string "Wenn du an einem COOLNESS-WETTBEWERB\n"
	.string "teilnimmst, zählen COOLe Attacken.\p"
	.string "Anmutige oder kluge Attacken sind\n"
	.string "dagegen nicht so angesagt.$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.ifdef ENGLISH
	.string "That young man who won earlier had\n"
	.string "a whole bunch of different {POKEBLOCK}S.\p"
	.string "Can you win if you had that many\n"
	.string "of those things?$"
	.else
	.ifdef GERMAN
	.string "Der junge Mann, der vor kurzem hier ge-\n"
	.string "wonnen hat, hatte viele verschiedene\l"
	.string "{POKEBLOCK} bei sich.\p"
	.string "Ob man gewinnt, wenn man genug dieser\n"
	.string "Items dabei hat?$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.ifdef ENGLISH
	.string "Whoa, isn't this place humongous!\p"
	.string "The tension in the air… It's not\n"
	.string "like a CONTEST hall in the sticks.$"
	.else
	.ifdef GERMAN
	.string "Wow, dieser Ort ist einfach riesig!\p"
	.string "Diese Spannung in der Luft… Das ist\n"
	.string "kein Vergleich zu einer WETTBEWERBs-\l"
	.string "HALLE in der tiefsten Provinz.$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.ifdef ENGLISH
	.string "MC: Okay, SMART POKéMON and their\n"
	.string "TRAINERS, are you ready?!\p"
	.string "Give it your best showing!\n"
	.string "Let's appeal!$"
	.else
	.ifdef GERMAN
	.string "MC: Okay, KLUGe POKéMON und TRAINER.\n"
	.string "Seid ihr bereit?!?\p"
	.string "Gebt euer Bestes!\n"
	.string "Es geht um den Ausdruck!$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.ifdef ENGLISH
	.string "JUDGE: Are you enjoying this CONTEST?\p"
	.string "Come back with three friends, and\n"
	.string "all of you may enter a CONTEST!$"
	.else
	.ifdef GERMAN
	.string "JUROR: Gefällt euch dieser\n"
	.string "WETTBEWERB?\p"
	.string "Komm mit drei Freunden wieder her,\n"
	.string "dann könnt ihr alle gemeinsam am\l"
	.string "WETTBEWERB teilnehmen.$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.ifdef ENGLISH
	.string "Ayayayay…\n"
	.string "I entered the wrong CONTEST.\p"
	.string "I entered this tough POKéMON in\n"
	.string "the SMARTNESS CONTEST…\p"
	.string "Come on, wow them with a smart-looking\n"
	.string "ROCK SMASH.$"
	.else
	.ifdef GERMAN
	.string "Eieieiei…\n"
	.string "Ich habe am falschen WETTBEWERB teil-\l"
	.string "genommen. Hach…\p"
	.string "Ich habe dieses starke POKéMON in\n"
	.string "einen KLUGHEITS-WETTBEWERB\l"
	.string "geschickt.\p"
	.string "Los, beeindrucke mit einem\n"
	.string "klugen ZERTRÜMMERER.$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.ifdef ENGLISH
	.string "I've spent many a year, and all my\n"
	.string "wisdom besides, raising this POKéMON\l"
	.string "to be smart.\p"
	.string "It won't be easily bested by some\n"
	.string "young pup's POKéMON.\p"
	.string "My dear wife, are you seeing this?$"
	.else
	.ifdef GERMAN
	.string "Ich habe viele Jahre und all meine\n"
	.string "Weisheit gebraucht, um dieses POKéMON\l"
	.string "KLUG zu machen.\p"
	.string "Damit mache ich es den jungen Spunden\n"
	.string "nicht leicht, mein POKéMON zu über-\l"
	.string "trumpfen.\p"
	.string "Mein holdes Weib, siehst du das?$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.ifdef ENGLISH
	.string "There it is!\p"
	.string "If my POKéMON pulls a smart move next,\n"
	.string "the audience's excitement will peak!$"
	.else
	.ifdef GERMAN
	.string "Das ist es!\p"
	.string "Wenn mein POKéMON eine kluge Attacke\n"
	.string "vorführt, wird das Publikum ausflippen\l"
	.string "vor Begeisterung!$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.ifdef ENGLISH
	.string "Oh, dear, no!\p"
	.string "My darling ZUBAT's LEECH LIFE is so\n"
	.string "cute I kept using it over and over!\p"
	.string "But these mean people don't appreciate\n"
	.string "it at all!$"
	.else
	.ifdef GERMAN
	.string "Oh, du liebe Güte, nein!\p"
	.string "Der BLUTSAUGER meines ZUBAT ist\n"
	.string "wirklich anmutig, daher setze ich ihn\l"
	.string "immer wieder ein!\p"
	.string "Aber diese gemeinen Leute wissen das\n"
	.string "überhaupt nicht zu schätzen!$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.ifdef ENGLISH
	.string "Kiyaaah! You're beautiful, Grandpa!$"
	.else
	.ifdef GERMAN
	.string "Kiaaayh! Du bist wunderbar, Opa!$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.ifdef ENGLISH
	.string "Even when TRAINERS enter the same\n"
	.string "kind of POKéMON, they all seem to use\l"
	.string "different moves for appeals.\p"
	.string "It's just like the way people have\n"
	.string "different styles for battling.$"
	.else
	.ifdef GERMAN
	.string "Selbst wenn die TRAINER die gleichen\n"
	.string "POKéMON einsetzen, so führen sie doch\l"
	.string "unterschiedliche Attacken vor.\p"
	.string "Das ist so wie bei den Kämpfen: Jeder\n"
	.string "hat seinen eigenen Stil.$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.ifdef ENGLISH
	.string "I think the POKéMON look smarter\n"
	.string "than their TRAINERS. By a lot.$"
	.else
	.ifdef GERMAN
	.string "Ich denke, die POKéMON machen einen\n"
	.string "klügeren Eindruck als ihre TRAINER.$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.ifdef ENGLISH
	.string "When all's said and done, I still love\n"
	.string "SMARTNESS CONTESTS.\p"
	.string "That intellectual green color…\n"
	.string "It's so… So… Cool.$"
	.else
	.ifdef GERMAN
	.string "Jetzt, wo alles vorbei ist, liebe ich\n"
	.string "KLUGHEITS-WETTBEWERBe noch immer.\p"
	.string "Diese intellektuelle, grüne Farbe…\n"
	.string "Das ist so… so… so cooool!$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.ifdef ENGLISH
	.string "MC: Are you entering the BEAUTY\n"
	.string "CONTEST, too? Good luck!$"
	.else
	.ifdef GERMAN
	.string "MC: Nimmst du auch am SCHÖNHEITS-\n"
	.string "WETTBEWERB teil? Viel Glück!$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.ifdef ENGLISH
	.string "JUDGE: Ah, every POKéMON here is\n"
	.string "a model of pristine beauty!\p"
	.string "Why, I almost forgot to score them!$"
	.else
	.ifdef GERMAN
	.string "JUROR: Ah, jedes POKéMON ist ein\n"
	.string "Beispiel makelloser Schönheit!\p"
	.string "Huch, fast hätte ich vergessen, sie zu\n"
	.string "bewerten…$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.ifdef ENGLISH
	.string "A POKéMON this beautiful…\n"
	.string "There isn't another one like it.\p"
	.string "Everyone's eyes will be glued to\n"
	.string "my beauty.$"
	.else
	.ifdef GERMAN
	.string "Ein POKéMON von dieser Schönheit…\n"
	.string "Es gibt keines wie dieses.\p"
	.string "Jedem werden die Augen übergehen, wenn\n"
	.string "er diese Schönheit betrachtet.$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.ifdef ENGLISH
	.string "Waaaah!\p"
	.string "I brushed and groomed my POKéMON\n"
	.string "carefully for this CONTEST…\p"
	.string "But I overdid it…\n"
	.string "My POKéMON's coat turned all scraggly…\p"
	.string "What should I do?$"
	.else
	.ifdef GERMAN
	.string "Aaaaargh!\p"
	.string "Ich habe mein POKéMON für diesen WETT-\n"
	.string "BEWERB sorgfältig gebürstet und\l"
	.string "gestriegelt.\p"
	.string "Dabei habe ich wohl übertrieben…\n"
	.string "Das Fell meines POKéMON ist nun ganz\l"
	.string "voller Fusseln…\p"
	.string "Was soll ich jetzt nur tun?$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.ifdef ENGLISH
	.string "This AURORA BEAM is so dazzling,\n"
	.string "the JUDGE won't be able to see it.\p"
	.string "Uh, wait a second…\n"
	.string "That'll be meaningless, then!$"
	.else
	.ifdef GERMAN
	.string "Der AURORASTRAHL ist eine so blendende\n"
	.string "Erscheinung, dass der JUROR sie nicht\l"
	.string "sehen wird.\p"
	.string "Äh, einen Moment mal…\n"
	.string "Dann ist sie ja völlig sinnlos…$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.ifdef ENGLISH
	.string "This pretty POKéMON looks just like\n"
	.string "me when I was younger.\p"
	.string "Right when I said that, my husband\n"
	.string "spewed the coffee he was drinking.\p"
	.string "Did I say something funny?$"
	.else
	.ifdef GERMAN
	.string "Dieses hübsche POKéMON sieht genauso\n"
	.string "aus wie ich, als ich jünger war.\p"
	.string "Als ich das zu meinem Mann sagte, hat er\n"
	.string "den Kaffee, den er trank, ausgespuckt.\p"
	.string "Was ist daran so lustig?$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.ifdef ENGLISH
	.string "You know, if I win at a BEAUTY\n"
	.string "CONTEST, sure it makes me\l"
	.string "happy. More than usual, anyway.$"
	.else
	.ifdef GERMAN
	.string "Natürlich, als Frau wäre ich überglück-\n"
	.string "lich, wenn ich den SCHÖNHEITS-\l"
	.string "WETTBEWERB gewinnen würde.$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.ifdef ENGLISH
	.string "Wahahahah!\p"
	.string "Will you take a gander at all those\n"
	.string "pretty POKéMON!\l"
	.string "I just love this sort of glitz!$"
	.else
	.ifdef GERMAN
	.string "Ahahahahaha!\p"
	.string "Wirf mal einen Blick auf all diese\n"
	.string "schönen POKéMON!\l"
	.string "Ich liebe diesen Liebreiz!$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.ifdef ENGLISH
	.string "You can't always win on just beauty\n"
	.string "alone.\p"
	.string "You have to groom your POKéMON so\n"
	.string "it's nice and glossy like mine.$"
	.else
	.ifdef GERMAN
	.string "Du kannst nicht immer nur aufgrund von\n"
	.string "Schönheit gewinnen.\p"
	.string "Du musst dein POKéMON striegeln, damit\n"
	.string "es so schön und glänzend ist wie meines.$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.ifdef ENGLISH
	.string "MC: Uh-oh! Hello!\n"
	.string "We're in the middle of a CONTEST!\p"
	.string "Please enter at our registration\n"
	.string "counter and come out, okay?$"
	.else
	.ifdef GERMAN
	.string "MC: Oh oh! Hallo!\n"
	.string "Wir sind mitten in einem WETTBEWERB!\p"
	.string "Lass dich bitte zuerst am Schalter\n"
	.string "registrieren und komm dann wieder, ja?$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.ifdef ENGLISH
	.string "JUDGE: Oh, such charming and cute\n"
	.string "appeals!\p"
	.string "Oh, my goodness! What a perfectly\n"
	.string "adorable WATER SPORT appeal!$"
	.else
	.ifdef GERMAN
	.string "JUROR: Oh, was für reizende und\n"
	.string "anmutige Ausdrücke!\p"
	.string "Oh, meine Güte! Was für ein perfekter\n"
	.string "NASSMACHER-Ausdruck!$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.ifdef ENGLISH
	.string "Oh, no… My sweet AZURILL was\n"
	.string "distracted by another POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Oh, nein… Mein AZURILL wurde von\n"
	.string "einem anderen POKéMON abgelenkt.$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.ifdef ENGLISH
	.string "My POKéMON has never won in a battle,\n"
	.string "but put it in a CONTEST and look out!$"
	.else
	.ifdef GERMAN
	.string "Mein POKéMON hat noch nie einen Kampf\n"
	.string "gewonnen. Aber geh mit ihm in einen\l"
	.string "WETTBEWERB und pass auf, was passiert.$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.ifdef ENGLISH
	.string "My POKéMON's PETAL DANCE is a marvel\n"
	.string "of elegance.\p"
	.string "I won't let anyone disturb its\n"
	.string "performance.$"
	.else
	.ifdef GERMAN
	.string "Der BLÄTTERTANZ meines POKéMON ist der\n"
	.string "Inbegriff von Eleganz.\p"
	.string "Ich lasse es nicht zu, dass irgend-\n"
	.string "jemand es dabei stört.$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.ifdef ENGLISH
	.string "Everyone's POKéMON are very cute.\p"
	.string "However, if my POKéMON were to make\n"
	.string "a cute appeal…\p"
	.string "I'm sure that it would be so much \n"
	.string "cuter than the others.$"
	.else
	.ifdef GERMAN
	.string "All diese POKéMON sind anmutig.\p"
	.string "Aber, wenn mein POKéMON einen\n"
	.string "anmutigen Ausdruck vorführt…\p"
	.string "Ich bin sicher, dass es dann anmutiger\n"
	.string "als all die anderen POKéMON sein wird.$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.ifdef ENGLISH
	.string "My child is in this CONTEST.$"
	.else
	.ifdef GERMAN
	.string "Mein Kind nimmt an diesem WETTBEWERB\n"
	.string "teil.$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_ComeOnDear:
	.ifdef ENGLISH
	.string "Come on, dear. Go for it!\n"
	.string "Your POKéMON is the best!$"
	.else
	.ifdef GERMAN
	.string "Los, mein Schatz! Zeig es ihnen!\n"
	.string "Dein POKéMON ist das Beste!$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.ifdef ENGLISH
	.string "I think that girl over there is\n"
	.string "the cutest of the lot.\p"
	.string "What's that? They're judging\n"
	.string "POKéMON by their looks?$"
	.else
	.ifdef GERMAN
	.string "Ich finde, das Mädchen dort drüben ist\n"
	.string "das anmutigste Geschöpf von allen.\p"
	.string "Wie bitte? Sie bewerten die POKéMON\n"
	.string "nach ihrer Anmut?!?$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.ifdef ENGLISH
	.string "Ohh, seeing all these cute POKéMON,\n"
	.string "they make we want to get my own!\p"
	.string "I'm going to go catch some!$"
	.else
	.ifdef GERMAN
	.string "Oooh, all diese anmutigen POKéMON!\n"
	.string "Ich möchte auch gerne eines haben!\p"
	.string "Ich werde mir jetzt eines fangen.$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.ifdef ENGLISH
	.string "BEAUTY CONTEST STAGE\n"
	.string "BE ALLURED BY BEAUTIFUL POKéMON!$"
	.else
	.ifdef GERMAN
	.string "BÜHNE DES SCHÖNHEITSWETTBEWERBS\n"
	.string "SEI GEBLENDET VON SCHÖNEN POKéMON!$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_CuteContestStage:
	.ifdef ENGLISH
	.string "CUTENESS CONTEST STAGE\n"
	.string "BE CHARMED BY CUTE POKéMON!$"
	.else
	.ifdef GERMAN
	.string "BÜHNE DES ANMUTWETTBEWERBS\n"
	.string "SEI GEFESSELT VON ANMUTIGEN POKéMON!$"
	.endif
	.endif

LilycoveCity_ContestHall_Text_SmartContestStage:
	.ifdef ENGLISH
	.string "SMARTNESS CONTEST STAGE\n"
	.string "BE IMPRESSED BY SMART POKéMON!$"
	.else
	.ifdef GERMAN
	.string "BÜHNE DES KLUGHEITS-WETTBEWERBS\n"
	.string "SEI BEEINDRUCKT VON KLUGEN POKéMON!$"
	.endif
	.endif

