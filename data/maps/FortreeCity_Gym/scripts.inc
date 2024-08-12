FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.ifdef ENGLISH
	.string "Yo, how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "FORTREE GYM LEADER WINONA is\n"
	.string "a master of FLYING-type POKéMON.\p"
	.string "She's waiting at the back of this GYM,\n"
	.string "behind the rotating doors.\p"
	.string "She's waiting for new challengers\n"
	.string "who are trying to take wing!\p"
	.string "Okay, go for it!$"
	.else
	.ifdef GERMAN
	.string "Na, wie sieht es aus? Auf dem Weg zum\n"
	.string "CHAMP, {PLAYER}?\p"
	.string "Die LEITERIN der ARENA von BAUMHAUSEN\n"
	.string "CITY, WIBKE, ist eine Meisterin der\l"
	.string "FLUG-POKéMON.\p"
	.string "Sie wartet hinten in der ARENA auf dich,\n"
	.string "hinter den Drehtüren.\p"
	.string "Sie wartet auf neue Herausforderer,\n"
	.string "denen sie die Flügel stutzen kann!\p"
	.string "Okay, dann viel Glück!$"
	.endif
	.endif

FortreeCity_Gym_Text_GymGuidePostVictory:
	.ifdef ENGLISH
	.string "You did it!\n"
	.string "You've achieved liftoff!$"
	.else
	.ifdef GERMAN
	.string "Du hast es geschafft!\n"
	.string "Du hast Startfreigabe!$"
	.endif
	.endif

FortreeCity_Gym_Text_JaredIntro:
	.ifdef ENGLISH
	.string "Behold the elegant battle style of\n"
	.string "BIRD POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Bewundere den eleganten Kampfstil der\n"
	.string "VOGEL-POKéMON!$"
	.endif
	.endif

FortreeCity_Gym_Text_JaredDefeat:
	.ifdef ENGLISH
	.string "You…\n"
	.string "You're strong…$"
	.else
	.ifdef GERMAN
	.string "Du…\n"
	.string "Du bist stark…$"
	.endif
	.endif

FortreeCity_Gym_Text_JaredPostBattle:
	.ifdef ENGLISH
	.string "A TRAINER has to be smart to keep\n"
	.string "up with unexpected turns of events.\p"
	.string "Do you have the smarts to get to\n"
	.string "our LEADER?$"
	.else
	.ifdef GERMAN
	.string "Ein TRAINER muss clever genug sein, mit\n"
	.string "den Wendungen im Kampf fertig zu\l"
	.string "werden.\p"
	.string "Mal sehen, ob du clever genug bist, bis\n"
	.string "zu unserer LEITERIN vorzudringen.$"
	.endif
	.endif

FortreeCity_Gym_Text_EdwardoIntro:
	.ifdef ENGLISH
	.string "The lovers of BIRD POKéMON aspire\n"
	.string "to join this GYM.\p"
	.string "As a member of the FORTREE GYM,\n"
	.string "I'm not allowed to lose!$"
	.else
	.ifdef GERMAN
	.string "Liebhaber von VOGEL-POKéMON streben\n"
	.string "danach, dieser ARENA beizutreten.\p"
	.string "Als Mitglied der ARENA von BAUMHAUSEN\n"
	.string "CITY darf ich nicht verlieren!$"
	.endif
	.endif

FortreeCity_Gym_Text_EdwardoDefeat:
	.ifdef ENGLISH
	.string "It was too much of a load for me\n"
	.string "to bear…$"
	.else
	.ifdef GERMAN
	.string "Das war doch etwas zu schwer für mich\n"
	.string "zu tragen…$"
	.endif
	.endif

FortreeCity_Gym_Text_EdwardoPostBattle:
	.ifdef ENGLISH
	.string "The world is huge, and there are\n"
	.string "countless tough TRAINERS.\p"
	.string "I'm going to keep training and make\n"
	.string "myself even stronger.$"
	.else
	.ifdef GERMAN
	.string "Die Welt ist groß und es gibt zahlreiche\n"
	.string "starke TRAINER.\p"
	.string "Ich werde weiter trainieren und so\n"
	.string "immer stärker werden!$"
	.endif
	.endif

FortreeCity_Gym_Text_FlintIntro:
	.ifdef ENGLISH
	.string "There's no need for WINONA, our GYM\n"
	.string "LEADER, to deal with you!\p"
	.string "I'm plenty good enough for you!$"
	.else
	.ifdef GERMAN
	.string "Es gibt keinen Grund, dass WIBKE,\n"
	.string "unsere ARENALEITERIN, sich mit dir\l"
	.string "abgibt!\p"
	.string "Ich bin schon stark genug für dich!$"
	.endif
	.endif

FortreeCity_Gym_Text_FlintDefeat:
	.ifdef ENGLISH
	.string "WINONA, I…\n"
	.string "I lost!$"
	.else
	.ifdef GERMAN
	.string "WIBKE… Ich…\n"
	.string "Ich habe verlooooren!$"
	.endif
	.endif

FortreeCity_Gym_Text_FlintPostBattle:
	.ifdef ENGLISH
	.string "WINONA is cute and she's strong.\n"
	.string "She's the ultimate LEADER!\p"
	.string "Blush…$"
	.else
	.ifdef GERMAN
	.string "WIBKE ist süß, aber auch stark.\n"
	.string "Sie ist die ultimative LEITERIN!\p"
	.string "Hups… Wie peinlich. Ich werde nicht rot!$"
	.endif
	.endif

FortreeCity_Gym_Text_AshleyIntro:
	.ifdef ENGLISH
	.string "WINONA taught me personally!\n"
	.string "You can't beat me easily!$"
	.else
	.ifdef GERMAN
	.string "WIBKE hat mich persönlich geschult!\n"
	.string "Du wirst kein leichtes Spiel haben!$"
	.endif
	.endif

FortreeCity_Gym_Text_AshleyDefeat:
	.ifdef ENGLISH
	.string "I was beaten…$"
	.else
	.ifdef GERMAN
	.string "Ich wurde geschlagen…$"
	.endif
	.endif

FortreeCity_Gym_Text_AshleyPostBattle:
	.ifdef ENGLISH
	.string "Thanks to WINONA, the people of\n"
	.string "FORTREE can live without fear.$"
	.else
	.ifdef GERMAN
	.string "Dank WIBKE leben die Einwohner von\n"
	.string "BAUMHAUSEN CITY ohne Furcht.$"
	.endif
	.endif

FortreeCity_Gym_Text_HumbertoIntro:
	.ifdef ENGLISH
	.string "When WINONA takes to battle, her face\n"
	.string "shines with beautiful determination…\p"
	.string "I'm not letting you witness that\n"
	.string "lovely sight!$"
	.else
	.ifdef GERMAN
	.string "WIBKEs Gesicht strahlt eine\n"
	.string "Entschlossenheit aus, wenn sie in den\l"
	.string "Kampf geht. Sie ist dann wunderhübsch!\p"
	.string "Ich werde dir dieses hübsche Gesicht\n"
	.string "zeigen!$"
	.endif
	.endif

FortreeCity_Gym_Text_HumbertoDefeat:
	.ifdef ENGLISH
	.string "Urk!\n"
	.string "I couldn't stop you.$"
	.else
	.ifdef GERMAN
	.string "Argh!\n"
	.string "Ich konnte dich einfach nicht stoppen!$"
	.endif
	.endif

FortreeCity_Gym_Text_HumbertoPostBattle:
	.ifdef ENGLISH
	.string "You'd better watch it!\n"
	.string "Don't get distracted staring at WINONA\l"
	.string "or you'll go crashing down in a heap!$"
	.else
	.ifdef GERMAN
	.string "Pass mal besser auf! Du solltest WIBKE\n"
	.string "nicht mit offenem Mund anstarren,\l"
	.string "sonst gehst du erbärmlich unter!$"
	.endif
	.endif

FortreeCity_Gym_Text_DariusIntro:
	.ifdef ENGLISH
	.string "You'd better know that there are all\n"
	.string "sorts of FLYING-type POKéMON.\p"
	.string "You do know that, right?$"
	.else
	.ifdef GERMAN
	.string "Es gibt viele verschiedene\n"
	.string "FLUG-POKéMON.\p"
	.string "Das weißt du, oder?$"
	.endif
	.endif

FortreeCity_Gym_Text_DariusDefeat:
	.ifdef ENGLISH
	.string "You seem to know your stuff!$"
	.else
	.ifdef GERMAN
	.string "Du weißt wirklich, was du tust!$"
	.endif
	.endif

FortreeCity_Gym_Text_DariusPostBattle:
	.ifdef ENGLISH
	.string "Sure, you beat me all right.\n"
	.string "But you'd better watch it! Our LEADER\l"
	.string "WINONA's POKéMON are all business.$"
	.else
	.ifdef GERMAN
	.string "Okay, du hast mich besiegt. Na und?\n"
	.string "Aber gegen unsere LEITERIN WIBKE\l"
	.string "hast du keine Chance!$"
	.endif
	.endif

FortreeCity_Gym_Text_WinonaIntro:
	.ifdef ENGLISH
	.string "I am WINONA. I am the LEADER of\n"
	.string "the FORTREE POKéMON GYM.\p"
	.string "I have become one with BIRD POKéMON\n"
	.string "and have soared the skies…\p"
	.string "However grueling the battle, we have\n"
	.string "triumphed with grace…\p"
	.string "Witness the elegant choreography\n"
	.string "of BIRD POKéMON and I!$"
	.else
	.ifdef GERMAN
	.string "Ich bin WIBKE, die LEITERIN der ARENA\n"
	.string "von BAUMHAUSEN CITY.\p"
	.string "Ich wurde das mit Hilfe meiner VOGEL-\n"
	.string "POKéMON und habe den Himmel berührt.\p"
	.string "Wie anstrengend der Kampf auch war, wir\n"
	.string "haben mit Grazie gewonnen…\p"
	.string "Werde Zeuge der eleganten Choreo-\n"
	.string "graphie meiner VOGEL-POKéMON!$"
	.endif
	.endif

FortreeCity_Gym_Text_WinonaDefeat:
	.ifdef ENGLISH
	.string "Never before have I seen a TRAINER\n"
	.string "command POKéMON with more grace\l"
	.string "than I…\p"
	.string "In recognition of your prowess,\n"
	.string "I present to you this GYM BADGE.$"
	.else
	.ifdef GERMAN
	.string "Ich habe noch nie einen TRAINER ge-\n"
	.string "sehen, der seine POKéMON mit mehr\l"
	.string "Grazie trainiert als ich…\p"
	.string "In Anbetracht deiner Fähigkeiten\n"
	.string "überreiche ich dir diesen ARENAORDEN.$"
	.endif
	.endif

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.ifdef ENGLISH
	.string "{PLAYER} received the FEATHER BADGE\n"
	.string "from WINONA.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} erhält den FEDERORDEN von\n"
	.string "WIBKE.$"
	.endif
	.endif

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.ifdef ENGLISH
	.string "With the FEATHER BADGE, all POKéMON up\n"
	.string "to LV 70, even those received through\l"
	.string "trades, will obey your every command.\p"
	.string "You will also be able to use\n"
	.string "the HM move FLY outside of battle.\p"
	.string "And this…\n"
	.string "This is a gift from me.$"
	.else
	.ifdef GERMAN
	.string "Mit dem FEDERORDEN gehorchen dir alle\n"
	.string "POKéMON bis Lv. 70, auch die, die du\l"
	.string "durch Tausch bekommen hast.\p"
	.string "Außerdem kannst du nun die VM FLIEGEN\n"
	.string "außerhalb eines Kampfes einsetzen.\p"
	.string "Und dies…\n"
	.string "Dies ist ein Geschenk von mir.$"
	.endif
	.endif

FortreeCity_Gym_Text_ExplainAerialAce:
	.ifdef ENGLISH
	.string "TM40 contains AERIAL ACE.\p"
	.string "Its speed…\n"
	.string "No POKéMON should be able to avoid it.\p"
	.string "… … … … … …$"
	.else
	.ifdef GERMAN
	.string "TM40 enthält AERO-ASS.\p"
	.string "Diese Geschwindigkeit…\n"
	.string "Kein POKéMON kann ihr entgehen.\p"
	.string "… … … … … …$"
	.endif
	.endif

FortreeCity_Gym_Text_RegisteredWinona:
	.ifdef ENGLISH
	.string "Registered GYM LEADER WINONA\n"
	.string "in the POKéNAV.$"
	.else
	.ifdef GERMAN
	.string "ARENALEITERIN WIBKE wurde im POKéNAV-\n"
	.string "Verzeichnis eingetragen.$"
	.endif
	.endif

FortreeCity_Gym_Text_WinonaPostBattle:
	.ifdef ENGLISH
	.string "Though I fell to you, I will remain\n"
	.string "devoted to BIRD POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Auch wenn ich gegen dich verloren habe,\n"
	.string "gehört meine Liebe den VOGEL-POKéMON.$"
	.endif
	.endif

FortreeCity_Gym_Text_GymStatue:
	.ifdef ENGLISH
	.string "FORTREE CITY POKéMON GYM$"
	.else
	.ifdef GERMAN
	.string "POKéMON ARENA von BAUMHAUSEN CITY$"
	.endif
	.endif

FortreeCity_Gym_Text_GymStatueCertified:
	.ifdef ENGLISH
	.string "FORTREE CITY POKéMON GYM\p"
	.string "WINONA'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
	.else
	.ifdef GERMAN
	.string "POKéMON ARENA von BAUMHAUSEN CITY\p"
	.string "WIBKES ANERKANNTE TRAINER:\n"
	.string "{PLAYER}$"
	.endif
	.endif

FortreeCity_Gym_Text_WinonaPreRematch:
	.ifdef ENGLISH
	.string "WINONA: We humans can never escape\n"
	.string "gravity's pull on the ground.\p"
	.string "But by striving for excellence,\n"
	.string "we have the power to soar!\p"
	.string "You have scaled the pinnacle as\n"
	.string "the reigning CHAMPION.\p"
	.string "Please, allow me to see your power\n"
	.string "at full flight!$"
	.else
	.ifdef GERMAN
	.string "WIBKE: Wir Menschen können uns der\n"
	.string "Schwerkraft nicht widersetzen.\p"
	.string "Aber in unserem Streben nach\n"
	.string "Perfektion haben auch wir die Kraft,\l"
	.string "vom Boden abzuheben!\p"
	.string "Du hast den Gipfel erstürmt. Als\n"
	.string "CHAMP.\p"
	.string "Bitte, zeig mir, wie du abhebst! Zeig\n"
	.string "mir deine Kraft.$"
	.endif
	.endif

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.ifdef ENGLISH
	.string "I failed to reach your height again…$"
	.else
	.ifdef GERMAN
	.string "Du fliegst mir zu hoch…$"
	.endif
	.endif

FortreeCity_Gym_Text_WinonaPostRematch:
	.ifdef ENGLISH
	.string "WINONA: Even though I have lost,\n"
	.string "the wings of my heart remain unbroken.\p"
	.string "I can rise and soar again and\n"
	.string "yet again.\p"
	.string "I am convinced of it!$"
	.else
	.ifdef GERMAN
	.string "WIBKE: Auch wenn ich verloren habe, mein\n"
	.string "Herz wird stets fliegen.\p"
	.string "Ich werde immer wieder aufsteigen und\n"
	.string "mich in die Lüfte erheben.\p"
	.string "Das weiß ich genau!$"
	.endif
	.endif

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.ifdef ENGLISH
	.string "WINONA: We humans can never escape\n"
	.string "gravity's pull on the ground.\p"
	.string "But by striving for excellence,\n"
	.string "we have the power to soar!\p"
	.string "You have scaled the pinnacle as\n"
	.string "the reigning CHAMPION.\p"
	.string "Please, allow me to see your power\n"
	.string "at full flight!\p"
	.string "Oh, no… Do you have but one\n"
	.string "POKéMON with you?\p"
	.string "Please return with two POKéMON\n"
	.string "at the very least.$"
	.else
	.ifdef GERMAN
	.string "WIBKE: Wir Menschen können uns der\n"
	.string "Schwerkraft nicht widersetzen.\p"
	.string "Aber in unserem Streben nach\n"
	.string "Perfektion haben auch wir die Kraft,\l"
	.string "vom Boden abzuheben!\p"
	.string "Du hast den Gipfel erstürmt. Als\n"
	.string "CHAMP.\p"
	.string "Bitte, zeig mir wie du abhebst! Zeig\n"
	.string "mir deine Kraft.\p"
	.string "Oh… Du hast nur ein POKéMON bei\n"
	.string "dir?\p"
	.string "Bitte komm später wieder und bring\n"
	.string "mindestens zwei POKéMON mit.$"
	.endif
	.endif
