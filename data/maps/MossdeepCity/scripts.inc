.set LOCALID_GRUNT_1, 10
.set LOCALID_GRUNT_2, 11
.set LOCALID_GRUNT_3, 12
.set LOCALID_GRUNT_4, 13
.set LOCALID_MAXIE, 14
.set LOCALID_SCOTT, 16

MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.ifdef ENGLISH
	.string "I got this from STEVEN, but I don't\n"
	.string "know what it's good for.\p"
	.string "I think it's called KING'S ROCK.\n"
	.string "Do you want it?$"
	.else
	.ifdef GERMAN
	.string "Ich habe das von TROY bekommen, weiß\n"
	.string "aber nicht, was ich damit machen soll.\p"
	.string "Ich glaube, es heißt KING-STEIN.\n"
	.string "Möchtest du das haben?$"
	.endif
	.endif

MossdeepCity_Text_YouCanKeepIt:
	.ifdef ENGLISH
	.string "Why would you want it?\n"
	.string "You're weird.\p"
	.string "You can keep it, but keep it a secret\n"
	.string "from STEVEN.$"
	.else
	.ifdef GERMAN
	.string "Warum willst du das haben?\n"
	.string "Du bist komisch.\p"
	.string "Du kannst es behalten, aber erzähle\n"
	.string "es nicht TROY.$"
	.endif
	.endif

MossdeepCity_Text_StevensHouseOverThere:
	.ifdef ENGLISH
	.string "STEVEN's house is right over there!$"
	.else
	.ifdef GERMAN
	.string "TROYs Haus befindet sich gleich\ndort drüben.$"
	.endif
	.endif

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.ifdef ENGLISH
	.string "Yeah, you think so, too! What are you\n"
	.string "supposed to do with some weird rock?$"
	.else
	.ifdef GERMAN
	.string "Ach, du denkst das auch! Was soll man\n"
	.string "auch mit komischen Steinen anfangen?$"
	.endif
	.endif

MossdeepCity_Text_WailmerWatching:
	.ifdef ENGLISH
	.string "Around MOSSDEEP, you can see wild\n"
	.string "WAILMER.\p"
	.string "It's called, uh…\n"
	.string "What was it now…\p"
	.string "WAI, WAI, WAI…\p"
	.string "WAILMER watching!$"
	.else
	.ifdef GERMAN
	.string "In der Nähe von MOOSBACH CITY\n"
	.string "kann man wilde WAILMER sehen.\p"
	.string "Das nennt man, äh…\n"
	.string "Nennt man… äh… ähm…\p"
	.string "WAI…, WAI…, WAI…\p"
	.string "WAILMER Watching!$"
	.endif
	.endif

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.ifdef ENGLISH
	.string "The island's SPACE CENTER has been\n"
	.string "launching huge rockets.\p"
	.string "There's been some kind of an uproar\n"
	.string "over a letter they received recently.$"
	.else
	.ifdef GERMAN
	.string "Am RAUMFAHRTZENTRUM auf der Insel\n"
	.string "werden große Raketen gestartet.\p"
	.string "Dort ist vor kurzem ein Brief ange-\n"
	.string "kommen, der für Aufregung sorgte.$"
	.endif
	.endif

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.ifdef ENGLISH
	.string "The island's SPACE CENTER has been\n"
	.string "launching huge rockets.$"
	.else
	.ifdef GERMAN
	.string "Am RAUMFAHRTZENTRUM auf der Insel\n"
	.string "werden große Raketen gestartet.$"
	.endif
	.endif

MossdeepCity_Text_MossdeepTargetedByMagma:
	.ifdef ENGLISH
	.string "I heard from a SAILOR buddy that\n"
	.string "TEAM AQUA set up shop in LILYCOVE.\p"
	.string "I also heard that someone came along\n"
	.string "and wiped the floor with them!\p"
	.string "But MOSSDEEP here's been targeted\n"
	.string "by that TEAM MAGMA.\p"
	.string "If you want to know what they're up to,\n"
	.string "go visit the SPACE CENTER.$"
	.else
	.ifdef GERMAN
	.string "Ich habe von einem Freund, einem\n"
	.string "MATROSEN, gehört, dass TEAM AQUA sich\pin SEEGRASULB CITY aufgehalten\n"
	.string "haben soll.\p"
	.string "Aber dann ist jemand gekommen und hat\n"
	.string "sie aufgemischt.\p"
	.string "Und in MOOSBACH CITY ist TEAM\n"
	.string "MAGMA.\p"
	.string "Wenn du wissen willst, was sie vorhaben,\n"
	.string "dann geh zum RAUMFAHRTZENTRUM.$"
	.endif
	.endif

MossdeepCity_Text_FeelReliefOnLand:
	.ifdef ENGLISH
	.string "I'm a SAILOR, so the sea's obviously\n"
	.string "more important to me.\p"
	.string "But you know? When I get back on land\n"
	.string "after a long voyage, I do feel relief!$"
	.else
	.ifdef GERMAN
	.string "Ich bin ein MATROSE, daher ist das Meer\n"
	.string "sehr wichtig für mich.\p"
	.string "Aber weißt du, was? Wenn ich nach einer\n"
	.string "langen Seefahrt wieder festen Boden\p"
	.string "unter den Füßen habe, bin ich jedes Mal\n"
	.string "erleichtert.$"
	.endif
	.endif

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.ifdef ENGLISH
	.string "Wouldn't it be nice?\p"
	.string "If the whole world was covered in\n"
	.string "plants and flowers like this island?$"
	.else
	.ifdef GERMAN
	.string "Wäre das nicht schön?\p"
	.string "Wenn die ganze Welt so mit Blumen und\n"
	.string "Pflanzen bewachsen wäre wie diese\l"
	.string "Insel?$"
	.endif
	.endif

MossdeepCity_Text_LifeNeedsSeaToLive:
	.ifdef ENGLISH
	.string "All life needs the sea to live, even\n"
	.string "though it makes its home on the land.\p"
	.string "Life, having run its course, becomes\n"
	.string "soil and returns to the land.\p"
	.string "And the sea is always connected to\n"
	.string "the land.\p"
	.string "Yes, like the very shoreline here.$"
	.else
	.ifdef GERMAN
	.string "Alle Lebewesen brauchen das Meer, um\n"
	.string "leben zu können, auch wenn sie an Land\l"
	.string "leben.\p"
	.string "Am Ende ihrer Reise wird aus den\n"
	.string "Lebewesen Erde und sie kehren zurück\l"
	.string "zum Land.\p"
	.string "Und das Meer steht immer in Verbindung\n"
	.string "zum Land.\p"
	.string "Genau wie dieses Ufer hier.$"
	.endif
	.endif

MossdeepCity_Text_SurfExhilarating:
	.ifdef ENGLISH
	.string "A voyage on a ship is fine.\p"
	.string "But crossing the sea with POKéMON\n"
	.string "using SURF…\p"
	.string "Now that's an exhilarating trip!\n"
	.string "Wouldn't you agree, youngster?$"
	.else
	.ifdef GERMAN
	.string "Eine Reise auf einem Schiff ist toll.\p"
	.string "Aber das Meer auf einem POKéMON zu\n"
	.string "überqueren, das SURFER einsetzt…\p"
	.string "Das ist wirklich eine aufregende Sache.\n"
	.string "Meinst du nicht auch, Kindchen?$"
	.endif
	.endif

MossdeepCity_Text_SpecialSpaceCenterRock:
	.ifdef ENGLISH
	.string "This rock has a special meaning to\n"
	.string "the people at the SPACE CENTER.\p"
	.string "They put it here as their wish for\n"
	.string "their rockets to fly safely.\p"
	.string "When you make a wish, what do you use?\n"
	.string "Do you wish upon a star?\p"
	.string "I use a wish tag to make it happen.\n"
	.string "That's what I do.$"
	.else
	.ifdef GERMAN
	.string "Dieser Felsen hat eine ganz besondere\n"
	.string "Bedeutung für das RAUMFAHRTZENTRUM.\p"
	.string "Sie haben ihn hier hingesetzt als\n"
	.string "Glücksbringer für den sicheren Flug der\l"
	.string "Raketen.\p"
	.string "Wenn du dir etwas wünschst, was machst\n"
	.string "du dann? Sternschnuppen beobachten?\p"
	.string "Ich benutze ein Wunschkärtchen.\n"
	.string "Genau das mache ich.$"
	.endif
	.endif

MossdeepCity_Text_ItsAWhiteRock:
	.ifdef ENGLISH
	.string "It's a white rock.$"
	.else
	.ifdef GERMAN
	.string "Ein weißer Felsen.$"
	.endif
	.endif

MossdeepCity_Text_GymSign:
	.ifdef ENGLISH
	.string "MOSSDEEP CITY POKéMON GYM\n"
	.string "LEADERS: LIZA & TATE\p"
	.string "“The mystic combination!”$"
	.else
	.ifdef GERMAN
	.string "POKéMON ARENA von MOOSBACH CITY \n"
	.string "LEITER: SVENJA & BEN\p"
	.string "“Die mystische Kombination!”$"
	.endif
	.endif

MossdeepCity_Text_CitySign:
	.ifdef ENGLISH
	.string "MOSSDEEP CITY\n"
	.string "“Our slogan: Cherish POKéMON!”$"
	.else
	.ifdef GERMAN
	.string "MOOSBACH CITY\n"
	.string "“Unser Motto: Liebe POKéMON!”$"
	.endif
	.endif

MossdeepCity_Text_SpaceCenterSign:
	.ifdef ENGLISH
	.string "MOSSDEEP SPACE CENTER\n"
	.string "“The closest place to space.”$"
	.else
	.ifdef GERMAN
	.string "MOOSBACH CITY RAUMFAHRTZENTRUM\n"
	.string "“Der letzte Ort vor dem All.”$"
	.endif
	.endif

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.ifdef ENGLISH
	.string "SCOTT: {PLAYER}{KUN}, feeling good?\n"
	.string "I'm doing great!\p"
	.string "I'd heard MOSSDEEP's GYM LEADER is\n"
	.string "pretty strong, so I decided to come\l"
	.string "take a look-see for myself.\p"
	.string "But there's something wrong about\n"
	.string "this town.\p"
	.string "People are going on about a warning\n"
	.string "letter and the SPACE CENTER…\p"
	.string "I don't think it concerns me in any\n"
	.string "way, though.$"
	.else
	.ifdef GERMAN
	.string "SCOTT: Geht es dir gut, {PLAYER}{KUN}?\n"
	.string "Mir geht es fantastisch!\p"
	.string "Ich habe mir sagen lassen, dass die\n"
	.string "ARENALEITER von MOOSBACH sehr stark\l"
	.string "sein sollen.\p"
	.string "Davon musste ich mich einfach selbst\n"
	.string "überzeugen.\p"
	.string "Aber in dieser Stadt geht irgendetwas\n"
	.string "Merkwürdiges vor.\p"
	.string "Die Leute reden über einen Brief mit\n"
	.string "einer Warnung und dem\l"
	.string "RAUMFAHRTZENTRUM…\p"
	.string "Aber ich glaube nicht, dass mich das\n"
	.string "etwas angeht.$"
	.endif
	.endif

MossdeepCity_Text_SootopolisNewGymLeader:
	.ifdef ENGLISH
	.string "Ahh… It feels great letting the waves\n"
	.string "wash over my feet…\p"
	.string "Speaking of the waves, you know that\n"
	.string "island city SOOTOPOLIS?\p"
	.string "I think the GYM there had a new\n"
	.string "LEADER come in.\p"
	.string "People tell me the new LEADER once\n"
	.string "mentored WALLACE.$"
	.else
	.ifdef GERMAN
	.string "Ahh… Ein großartiges Gefühl, wenn\n"
	.string "die Wellen über meine Füße spülen…\p"
	.string "Apropos Wellen. Kennst du die Stadt\n"
	.string "XENEROVILLE?\p"
	.string "Ich glaube, die ARENA dort hat einen\n"
	.string "neuen LEITER.\p"
	.string "Das soll der frühere Mentor von\n"
	.string "WASSILI sein.$"
	.endif
	.endif
