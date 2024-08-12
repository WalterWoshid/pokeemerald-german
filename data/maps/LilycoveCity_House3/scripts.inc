LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.ifdef ENGLISH
	.string "Oh, my, my! Are you traveling alone?\n"
	.string "But you're so young! Good for you!\p"
	.string "I'm sure my kids could learn a thing\n"
	.string "or two from you!\p"
	.string "Me? I'm a master of {POKEBLOCK}S.\p"
	.string "If I get serious just a little, why,\n"
	.string "I can concoct great {POKEBLOCK}S.\p"
	.string "Would you like to learn from me,\n"
	.string "a master of {POKEBLOCK}S?$"
	.else
	.ifdef GERMAN
	.string "Ach, du liebes bisschen! Reist du ganz\n"
	.string "alleine? Aber du bist so jung! Gut!\p"
	.string "Ich bin sicher, meine Kinder könnten\n"
	.string "das eine oder andere von dir lernen!\p"
	.string "Ich? Ich bin die Expertin der {POKEBLOCK}.\p"
	.string "Wenn ich es mir recht überlege, dann\n"
	.string "könnte ich ein paar {POKEBLOCK} zaubern.\p"
	.string "Möchtest du das von mir, der Expertin\n"
	.string "der {POKEBLOCK}, lernen?$"
	.endif
	.endif

LilycoveCity_House3_Text_OhAreYouSure:
	.ifdef ENGLISH
	.string "Oh? Are you sure?\p"
	.string "You shouldn't always try to do\n"
	.string "everything by yourself, dear!$"
	.else
	.ifdef GERMAN
	.string "Oh? Ganz sicher?\p"
	.string "Du solltest nicht immer versuchen, alles\n"
	.string "alleine zu meistern, mein Kind.$"
	.endif
	.endif

LilycoveCity_House3_Text_ExplainPokeblocks:
	.ifdef ENGLISH
	.string "Oh, good! You're a smart soul!\n"
	.string "This is a bit long, so listen up!\p"
	.string "Are you ready?\p"
	.string "If you look at {POKEBLOCK}S, you should see\n"
	.string "that they are rated on how they feel.\p"
	.string "The lower the feel rating,\n"
	.string "the better it is. Don't forget this!\p"
	.string "A good {POKEBLOCK} has a low feel\n"
	.string "rating and a high level.\p"
	.string "A POKéMON can eat more good\n"
	.string "{POKEBLOCK}S than ordinary ones, too.\p"
	.string "And this is important.\p"
	.string "If you want to make smooth {POKEBLOCK}S,\n"
	.string "use different kinds of BERRIES.\p"
	.string "Don't be stingy--the kinds of BERRIES\n"
	.string "affect the smoothness of {POKEBLOCK}S.\p"
	.string "And another thing.\p"
	.string "The more people blending BERRIES,\n"
	.string "the smoother the {POKEBLOCK}S.\p"
	.string "That's why you should talk to other\n"
	.string "people and make {POKEBLOCK}S together.\p"
	.string "That's about all you need to know to\n"
	.string "make good {POKEBLOCK}S.\p"
	.string "If everyone had POKéMON they love,\n"
	.string "smooth {POKEBLOCK}S, and a loving family,\l"
	.string "the world would be a happier place.\p"
	.string "Don't give up, dear!$"
	.else
	.ifdef GERMAN
	.string "Oh, schön! Du bist clever! Das\n"
	.string "wird eine lange Erklärung. Hör gut zu.\p"
	.string "Bist du bereit?\p"
	.string "Wenn du einen {POKEBLOCK} betrachtest,\n"
	.string "siehst du, dass er danach bewertet\l"
	.string "wird, wie würzig er ist.\p"
	.string "Je niedriger dieser Wert ist, desto\n"
	.string "besser ist das. Vergiss das nicht!\p"
	.string "Ein guter {POKEBLOCK} hat einen niedrigen\n"
	.string "Würzwert und einen hohen Level.\p"
	.string "Ein POKéMON kann mehr gute {POKEBLOCK}\n"
	.string "essen als durchschnittliche.\p"
	.string "Und das ist wichtig.\p"
	.string "Wenn du weiche {POKEBLOCK} herstellen\n"
	.string "willst, benutze verschiedene BEEREn.\p"
	.string "Sei nicht geizig - die Art der BEEREn\n"
	.string "beeinflusst die Weichheit der {POKEBLOCK}.\p"
	.string "Und noch etwas:\p"
	.string "Je mehr Leute BEEREn mixen,\n"
	.string "desto weicher werden die {POKEBLOCK}.\p"
	.string "Daher solltest du andere Leute an-\n"
	.string "sprechen und mit ihnen zusammen\l"
	.string "{POKEBLOCK} herstellen.\p"
	.string "Das ist alles, was du wissen musst, um\n"
	.string "gute {POKEBLOCK} herstellen zu können.\p"
	.string "Wenn jeder POKéMON hätte, die er liebt,\n"
	.string "weiche {POKEBLOCK} und eine liebevolle\p"
	.string "Familie, sähe es auf der Welt viel\n"
	.string "besser aus.\p"
	.string "Lass dich nicht unterkriegen, Schatz!$"
	.endif
	.endif

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.ifdef ENGLISH
	.string "When my wife gave birth to quadruplets,\n"
	.string "you bet I was shocked.\p"
	.string "But, now, seeing them play together,\n"
	.string "it makes me happy.$"
	.else
	.ifdef GERMAN
	.string "Als meine Frau Vierlinge zur Welt\n"
	.string "brachte, war ich zuerst geschockt.\p"
	.string "Aber wenn ich sie jetzt zusammen\n"
	.string "spielen sehe, bin ich richtig glücklich.$"
	.endif
	.endif

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.ifdef ENGLISH
	.string "We're having MULTI BATTLES, but I know\n"
	.string "I'm going to win.$"
	.else
	.ifdef GERMAN
	.string "Wir üben MULTIKÄMPFe, aber ich\n"
	.string "weiß, dass ich gewinnen werde.$"
	.endif
	.endif

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.ifdef ENGLISH
	.string "We like mixing stuff at\n"
	.string "the RECORD CORNER.\p"
	.string "But what gets mixed up?$"
	.else
	.ifdef GERMAN
	.string "Wir lieben es, Sachen beim STATISTIK-\n"
	.string "TAUSCH durcheinander zu würfeln.\p"
	.string "Aber, was kann man durcheinander\n"
	.string "würfeln?$"
	.endif
	.endif

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.ifdef ENGLISH
	.string "We're going to make super {POKEBLOCK}S\n"
	.string "with a BERRY BLENDER!$"
	.else
	.ifdef GERMAN
	.string "Wir wollen super {POKEBLOCK}\n"
	.string "im BEERENMIXER machen!$"
	.endif
	.endif

LilycoveCity_House3_Text_GoingToEnterContest:
	.ifdef ENGLISH
	.string "I want to brag about how tough my\n"
	.string "POKéMON is, so we're going to enter\l"
	.string "a CONTEST together.$"
	.else
	.ifdef GERMAN
	.string "Ich möchte damit angeben, wie stark\n"
	.string "mein POKéMON ist, daher werden wir\l"
	.string "an einem WETTBEWERB teilnehmen.$"
	.endif
	.endif

