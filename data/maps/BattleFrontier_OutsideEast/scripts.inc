.set LOCALID_SUDOWOODO, 14

BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.ifdef ENGLISH
	.string "This is the BATTLE TOWER!\n"
	.string "Keep the win streak as the toughest\l"
	.string "TRAINER!$"
	.else
	.ifdef GERMAN
	.string "DUELLTURM\n"
	.string "“Besiege alle und werde der beste\l"
	.string "TRAINER!”$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.ifdef ENGLISH
	.string "This is the BATTLE PALACE!\n"
	.string "Keep your eyes on POKéMON battles!$"
	.else
	.ifdef GERMAN
	.string "Dies ist der KAMPFPALAST!\n"
	.string "Schaut euch die POKéMON-Kämpfe an!$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.ifdef ENGLISH
	.string "This is the BATTLE ARENA!\n"
	.string "Let the toughest teams gather!$"
	.else
	.ifdef GERMAN
	.string "Dies ist der KAMPFRING!\n"
	.string "Hier treffen sich die stärksten Teams!$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.ifdef ENGLISH
	.string "This is the BATTLE PYRAMID!\n"
	.string "Advance through the Battle Quest!$"
	.else
	.ifdef GERMAN
	.string "Dies ist die KAMPFPYRAMIDE!\n"
	.string "Geh in das Abenteuer Kampfforschung!$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.ifdef ENGLISH
	.string "BATTLE FRONTIER RANKING HALL\n"
	.string "Set your sights on new records!$"
	.else
	.ifdef GERMAN
	.string "KAMPFZONE ERGEBNISHALLE\n"
	.string "Schau dir die neuesten Rekorde an!$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.ifdef ENGLISH
	.string "BATTLE POINT EXCHANGE SERVICE CORNER\n"
	.string "Exchange your Battle Points!$"
	.else
	.ifdef GERMAN
	.string "GEWINNPUNKTE TAUSCHECKE\n"
	.string "Löse deine Gewinnpunkte ein!$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.ifdef ENGLISH
	.string "Wow!\n"
	.string "It's huge!\p"
	.string "The BATTLE TOWER feels special.\n"
	.string "It's different from the others.$"
	.else
	.ifdef GERMAN
	.string "Wow!\n"
	.string "Ist das riiiiesig!\p"
	.string "Der DUELLTURM hat eine besondere\n"
	.string "Atmosphäre. Ganz anders als die\l"
	.string "anderen Orte.$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.ifdef ENGLISH
	.string "My grand ambition is to conquer both\n"
	.string "the BATTLE FRONTIER and the POKéMON\l"
	.string "LEAGUE.\p"
	.string "And if my dream comes true…\p"
	.string "I… I'm going to ask MIMI next door\n"
	.string "if she will be friends with me!$"
	.else
	.ifdef GERMAN
	.string "Ich habe Großes vor! Ich will die KAMPF-\n"
	.string "ZONE und die POKéMON LIGA erobern!\p"
	.string "Und wenn dieser Traum wahr wird…\p"
	.string "Dann werde ich… meine Nachbarin MIMI\n"
	.string "fragen, ob sie meine Freundin wird!$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.ifdef ENGLISH
	.string "The BATTLE PYRAMID's too harsh!\n"
	.string "I just can't make it to the top!\p"
	.string "Since I'm out of options, maybe I can\n"
	.string "climb the outside…$"
	.else
	.ifdef GERMAN
	.string "Die KAMPFPYRAMIDE ist wirklich\n"
	.string "hammerhart! Ich schaff das nicht!\p"
	.string "Wenn ich es auf dem normalen Weg nicht\n"
	.string "nach oben schaffe… vielleicht sollte\l"
	.string "ich dann einfach außen hochklettern?!?$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.ifdef ENGLISH
	.string "I thrive in darkness…\n"
	.string "Yes… What is worthy of me?\l"
	.string "None other than the BATTLE PYRAMID…\p"
	.string "What say you to wandering in darkness\n"
	.string "and in utter and total desperation?$"
	.else
	.ifdef GERMAN
	.string "Ich lebe von der Dunkelheit…\n"
	.string "Ja… Und welche Herausforderung ist\l"
	.string "gerade gut genug für mich?\p"
	.string "Die KAMPFPYRAMIDE! Liebst du nicht\n"
	.string "auch die Dunkelheit? Die Verzweiflung\l"
	.string "und das Ungewisse?$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.ifdef ENGLISH
	.string "I didn't sleep for a week, but then\n"
	.string "I put together the ultimate team!\p"
	.string "I can't see myself losing, no joke.\n"
	.string "We're storming the BATTLE ARENA!$"
	.else
	.ifdef GERMAN
	.string "Es hat mich eine Woche Schlaf gekostet,\n"
	.string "aber jetzt habe ich es zusammen… Das\p"
	.string "ultimative Team!!! Ich sehe mich als\n"
	.string "Sieger, und nur als Sieger, kein Witz!\p"
	.string "Wir werden den KAMPFRING wie ein\n"
	.string "Orkan durchfegen und gewinnen!$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.ifdef ENGLISH
	.string "Did SCOTT bring you here, too?\n"
	.string "What is it with that guy?\p"
	.string "It sounds like he really does know\n"
	.string "how to spot talented TRAINERS, but…\p"
	.string "I've never seen him battling in person\n"
	.string "ever.$"
	.else
	.ifdef GERMAN
	.string "Hat SCOTT dich auch hierher einge-\n"
	.string "laden? Wie macht er das nur?\p"
	.string "Er scheint ein Auge für talentierte\n"
	.string "TRAINER zu haben, aber…\p"
	.string "Ich habe ihn selbst noch nie kämpfen\n"
	.string "gesehen…$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.ifdef ENGLISH
	.string "ZIGG!\n"
	.string "I believe in you, little buddy!\p"
	.string "I'll make my little ZIGG any favorite\n"
	.string "tasty treats you like if you win!$"
	.else
	.ifdef GERMAN
	.string "ZIGG!\n"
	.string "Ich glaube an dich, mein kleiner Freund!\p"
	.string "Und wenn du gewinnst, werde ich dich\n"
	.string "mit allem, was du magst, verwöhnen!$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.ifdef ENGLISH
	.string "ZIGZAGOON looks vacant…$"
	.else
	.ifdef GERMAN
	.string "ZIGZACHS schaut erwartungsvoll…$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.ifdef ENGLISH
	.string "People call me a busybody,\n"
	.string "but I can't help it.\p"
	.string "Your hat's on crooked!\n"
	.string "Oh, no, trash on the ground!\l"
	.string "Oops, it's almost dinnertime!\p"
	.string "I don't know if I can stand to just\n"
	.string "watch at the BATTLE PALACE…$"
	.else
	.ifdef GERMAN
	.string "Die anderen sagen, ich wäre eine\n"
	.string "Nervensäge, die sich überall einmischt.\p"
	.string "Aber wenn ich ihnen nicht sage, wo\n"
	.string "es langgeht, wer dann?\l"
	.string "… \p"
	.string "Du da, dein Hut sitzt schief!\n"
	.string "Du da, wirf keinen Müll auf den Boden!\l"
	.string "Du da, du machst das ja ganz falsch!\p"
	.string "Ich glaube nicht, dass ich es jemals\n"
	.string "schaffen werde, im KAMPFPALAST\l"
	.string "still zu sein und zuzuschauen…$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.ifdef ENGLISH
	.string "I may not look that impressive now,\n"
	.string "but I once beat a GYM LEADER.\p"
	.string "Who knows, maybe I should give it\n"
	.string "another shot at glory.$"
	.else
	.ifdef GERMAN
	.string "Heute ist das vielleicht schwer\n"
	.string "vorstellbar, aber ich habe mal einen\l"
	.string "ARENALEITER besiegt!\p"
	.string "Wer weiß? Vielleicht sollte ich es\n"
	.string "noch einmal versuchen?!?$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.ifdef ENGLISH
	.string "I'm fast on my BIKE, and that goes for\n"
	.string "the way I battle, too.\p"
	.string "I win matches in the blink of\n"
	.string "an eye!$"
	.else
	.ifdef GERMAN
	.string "Ich bin schnell mit meinem Fahrrad…\n"
	.string "Und genauso schnell bin ich auch im\p"
	.string "Kampf! Ich brauche nur eine\n"
	.string "Millisekunde für den Sieg!$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.ifdef ENGLISH
	.string "I'm better than my daddy\n"
	.string "at POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Ich kann besser mit POKéMON umgehen\n"
	.string "als mein Vati.$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.ifdef ENGLISH
	.string "Go on, my baby sweetie!\n"
	.string "Go rack up some wins for Daddy!\p"
	.string "You're just like your mother,\n"
	.string "so you'll be dominating!$"
	.else
	.ifdef GERMAN
	.string "Los, meine kleine Prinzessin! Besiege\n"
	.string "die TRAINER und mach deinen Vati stolz!\p"
	.string "Du bist deiner Mutti sehr ähnlich. Du\n"
	.string "bist dominant, du wirst das schaffen!$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.ifdef ENGLISH
	.string "It wasn't easy getting here,\n"
	.string "but I'd heard about this knockout\l"
	.string "pretty girl at the BATTLE ARENA.\p"
	.string "Instead of her, do you know what\n"
	.string "I found?\p"
	.string "A whole teeming mob of sweaty,\n"
	.string "stinky, and primitive martial artists!$"
	.else
	.ifdef GERMAN
	.string "Ich wusste, der Weg hierher ist sehr\n"
	.string "schwierig zu meistern. Aber ich hatte\l"
	.string "gehört, dass hier ein umwerfend süßes\p"
	.string "Mädchen im KAMPFRING sein soll.\n"
	.string "Und weißt du, auf wen ich getroffen bin,\l"
	.string "als ich dann endlich hier ankam?!?\p"
	.string "Auf ein Team stinkender, schwitzender,\n"
	.string "primitiver und nervtötender\l"
	.string "Kampfsportler. Ich könnte platzen…$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.ifdef ENGLISH
	.string "I sometimes see this really important-\n"
	.string "looking old man going in there.\p"
	.string "He has these really awesome POKéMON.\n"
	.string "He seems really nice, though.$"
	.else
	.ifdef GERMAN
	.string "Manchmal läuft hier ein wichtig\n"
	.string "aussehender, älterer Herr herum.\p"
	.string "Er hat wirklich beeindruckende POKéMON\n"
	.string "und er scheint sehr nett zu sein.$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.ifdef ENGLISH
	.string "Do you know it?\n"
	.string "The legend of the BATTLE PYRAMID?\p"
	.string "When there comes a confident TRAINER\n"
	.string "reaching for the golden pinnacle,\l"
	.string "there shall appear a man among men.\p"
	.string "Don't know that legend?\n"
	.string "Well, of course not!\l"
	.string "I just made it up!\p"
	.string "What's it supposed to mean?\n"
	.string "That, my friend, I can't say!$"
	.else
	.ifdef GERMAN
	.string "Hast du schon mal etwas über die\n"
	.string "Legende der KAMPFPYRAMIDE gehört?\p"
	.string "Wenn ein überzeugender TRAINER den\n"
	.string "goldenen Gipfel erreicht, dann\l"
	.string "erscheint der TRAINER aller TRAINER.\p"
	.string "Wie, das wusstest du nicht?\n"
	.string "Natürlich nicht!\l"
	.string "Das habe ich doch gerade erfunden!\p"
	.string "Was das heißen soll? Hähähä, das ist\n"
	.string "mein Geheimnis!$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.ifdef ENGLISH
	.string "Man! Oh man!\n"
	.string "I've never lost once before!\p"
	.string "But I got wiped out with no saving\n"
	.string "grace at all!\p"
	.string "And then I'm told I don't have any\n"
	.string "talent?! Man!$"
	.else
	.ifdef GERMAN
	.string "Grummel… Motz…\n"
	.string "Ich habe bisher noch nie verloren!\p"
	.string "Aber diesmal bin ich vom Platz gefegt\n"
	.string "worden. Meine Würde ist dahin…\p"
	.string "Und dann wird mir noch an den Kopf\n"
	.string "geworfen, ich hätte kein Talent?!?\l"
	.string "Argh… Motz… Meuter…$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.ifdef ENGLISH
	.string "This guy ran into a horribly tough\n"
	.string "TRAINER while he was on the BATTLE\l"
	.string "TOWER challenge.\p"
	.string "Now look at him…\p"
	.string "You need to be cautious if you ever\n"
	.string "decide to go to the BATTLE TOWER.$"
	.else
	.ifdef GERMAN
	.string "Er ist auf einen mordsmäßig starken\n"
	.string "TRAINER getroffen, als er sich durch\l"
	.string "den DUELLTURM gekämpft hat.\p"
	.string "Und nun schau ihn dir an…\n"
	.string "Ein Häufchen Elend…\p"
	.string "Du musst auf alles gefasst sein, wenn\n"
	.string "du den DUELLTURM betrittst!$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.ifdef ENGLISH
	.string "Yes!\n"
	.string "I've finally got enough Battle Points!\p"
	.string "I guess I'll trade for another giant\n"
	.string "plush DOLL!$"
	.else
	.ifdef GERMAN
	.string "Ja!\n"
	.string "Endlich habe ich genug Gewinnpunkte!\p"
	.string "Ich werde mir eine riesige, niedliche\n"
	.string "Plüschpuppe holen!$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.ifdef ENGLISH
	.string "Oh, yeah, okay!\n"
	.string "So this is the RANKING HALL!\p"
	.string "I'd like to go down in history as\n"
	.string "a super champ and have my name\l"
	.string "recorded here for posterity.$"
	.else
	.ifdef GERMAN
	.string "Oh, yeah, okay!\n"
	.string "Dies ist also die ERGEBNISHALLE!\p"
	.string "Ich will in die Geschichte eingehen! Als\n"
	.string "Superchamp! Ich will meinen Namen für\l"
	.string "die Nachwelt verewigen.$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.ifdef ENGLISH
	.string "With you by my side, I can do anything.$"
	.else
	.ifdef GERMAN
	.string "Mit dir an meiner Seite…\n"
	.string "kann ich alles schaffen!!!$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.ifdef ENGLISH
	.string "Ooh, darling, you are so wonderful!\p"
	.string "Ooh, I just can't wait anymore!\p"
	.string "Let's go to a MULTI BATTLE ROOM\n"
	.string "right this instant!\p"
	.string "If we get together in the BATTLE SALON,\n"
	.string "the power of our love will overcome\l"
	.string "everyone we meet.\p"
	.string "Why, before us, darling, everything\n"
	.string "will topple like dominoes!$"
	.else
	.ifdef GERMAN
	.string "Oh, Liebling, du bist wundervoll!\p"
	.string "Oh, ich kann nicht länger warten!\p"
	.string "Lass uns sofort zu den MULTIKÄMPFEN\n"
	.string "gehen!\p"
	.string "Wenn wir zusammen in der TEAMLOUNGE\n"
	.string "sind… wird die Macht unserer Liebe alle\l"
	.string "Hindernisse beseitigen!\p"
	.string "Sie werden umfallen wie 1000 Domino-\n"
	.string "steine in einer Reihe, Liebling!$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.ifdef ENGLISH
	.string "The BATTLE FRONTIER isn't exclusively\n"
	.string "for tough TRAINERS.\p"
	.string "Many people with special abilities\n"
	.string "have been invited, it seems.\p"
	.string "That man SCOTT…\p"
	.string "He may have built this place to serve\n"
	.string "a bigger objective…$"
	.else
	.ifdef GERMAN
	.string "Die KAMPFZONE steht nicht nur\n"
	.string "starken TRAINERn offen.\p"
	.string "Hier sind auch viele, die sich durch\n"
	.string "besondere Eigenschaften und\l"
	.string "Fähigkeiten auszeichnen.\p"
	.string "Dieser SCOTT…\p"
	.string "Er hat diesen Ort mit Sicherheit gebaut,\n"
	.string "weil er etwas Höheres im Sinn hat…$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.ifdef ENGLISH
	.string "Excuse me, young one.\n"
	.string "Have you good eyesight?\p"
	.string "There is an odd tree past here, and to\n"
	.string "my tired eyes it seems to wiggle.$"
	.else
	.ifdef GERMAN
	.string "Entschuldige! Du bist jung! Deine\n"
	.string "Augen sind bestimmt hervorragend?!?\p"
	.string "Da vorne ist ein komischer Baum, und\n"
	.string "meine müden Augen scheinen zu sehen,\l"
	.string "dass er sich bewegt.$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.ifdef ENGLISH
	.string "Excuse me, young one.\n"
	.string "Have you a good memory?\p"
	.string "I have this feeling there once was\n"
	.string "an odd tree past here.$"
	.else
	.ifdef GERMAN
	.string "Entschuldige! Du bist noch jung. Dein\n"
	.string "Gedächtnis ist bestimmt sehr gut.\p"
	.string "War hier nicht früher ein merkwürdiger\n"
	.string "Baum?!?$"
	.endif
	.endif

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.ifdef ENGLISH
	.string "I…\n"
	.string "I saw it!\p"
	.string "There was a sticky sort of a POKéMON\n"
	.string "with a long tail up ahead!\p"
	.string "It was hiding under a boulder, and\n"
	.string "it kept staring at me!$"
	.else
	.ifdef GERMAN
	.string "Ich…\n"
	.string "Ich habe es genau gesehen!!!\p"
	.string "Da vorne war ein merkwürdiges POKéMON\n"
	.string "mit einem langen Schweif!\p"
	.string "Es hatte sich unter einem Felsen\n"
	.string "versteckt und starrte mich an!$"
	.endif
	.endif
