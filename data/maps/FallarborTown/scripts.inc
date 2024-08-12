FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.ifdef ENGLISH
	.string "Something's happening,\n"
	.string "and I don't like it!\p"
	.string "I've seen shady characters wandering\n"
	.string "in and out of PROF. COZMO's home…$"
	.else
	.ifdef GERMAN
	.string "Was ist los? Was ist los?\p"
	.string "Ich habe eine zwielichtige Gestalt aus\n"
	.string "dem LABOR von PROF. KOSMO flitzen\l"
	.string "sehen.$"
	.endif
	.endif

FallarborTown_Text_RegionKnownForMeteors:
	.ifdef ENGLISH
	.string "This region's been known for meteors\n"
	.string "since the olden days.\p"
	.string "They say METEOR FALLS was gouged out\n"
	.string "by a falling meteorite long ago.$"
	.else
	.ifdef GERMAN
	.string "Diese Region ist schon seit Urzeiten\n"
	.string "für ihre Meteoritenschauer bekannt.\p"
	.string "Man sagt, METEORFÄLLE sei durch\n"
	.string "den Aufprall eines METEORITen\l"
	.string "entstanden.$"
	.endif
	.endif

FallarborTown_Text_MyPreciousAzurill:
	.ifdef ENGLISH
	.string "See! Take a look!\n"
	.string "This is my precious AZURILL!\p"
	.string "It's slick and smooth and plushy, too!$"
	.else
	.ifdef GERMAN
	.string "Schau mal! Guck doch mal!\n"
	.string "Das ist mein süßes AZURILL!\p"
	.string "Es ist glatt, weich und plüschig!$"
	.endif
	.endif

FallarborTown_Text_Azurill:
	.ifdef ENGLISH
	.string "AZURILL: Rooreelooo.$"
	.else
	.ifdef GERMAN
	.string "AZURILL: Rooreelooo.$"
	.endif
	.endif

FallarborTown_Text_HaveYouChallengedFlannery:
	.ifdef ENGLISH
	.string "Have you already challenged FLANNERY,\n"
	.string "the LEADER of LAVARIDGE GYM?\p"
	.string "The girl's grandfather was famous.\n"
	.string "He was one of the ELITE FOUR in the\l"
	.string "POKéMON LEAGUE at one point.\p"
	.string "It wouldn't surprise me to see FLANNERY\n"
	.string "become a great TRAINER in her own\l"
	.string "right.$"
	.else
	.ifdef GERMAN
	.string "Hast du schon FLAVIA, die LEITERIN\n"
	.string "der ARENA von BAD LAVASTADT,\l"
	.string "herausgefordert?\p"
	.string "Ihr Großvater ist sehr berühmt.\n"
	.string "Er war einer der TOP VIER in der\l"
	.string "POKéMON LIGA.\p"
	.string "Es würde mich gar nicht wundern, wenn\n"
	.string "FLAVIA ebenfalls ein großer TRAINER\l"
	.string "wird.$"
	.endif
	.endif

FallarborTown_Text_BattleTentSign:
	.ifdef ENGLISH
	.string "BATTLE TENT FALLARBOR SITE\n"
	.string "“May the Greatest Teams Gather!”$"
	.else
	.ifdef GERMAN
	.string "KAMPFCAMP LAUBWECHSELFELD\n"
	.string "“Mögen Sich Die Besten Teams Hier\l"
	.string "Treffen!”$"
	.endif
	.endif

FallarborTown_Text_TownSign:
	.ifdef ENGLISH
	.string "FALLARBOR TOWN\n"
	.string "“A farm community with small gardens.”$"
	.else
	.ifdef GERMAN
	.string "LAUBWECHSELFELD\n"
	.string "“Eine Gemeinschaft von Farmern mit\l"
	.string "kleinen Gärten.”$"
	.endif
	.endif

FallarborTown_Text_MoveTutorSign:
	.ifdef ENGLISH
	.string "MOVE TUTOR'S HOUSE\n"
	.string "“New moves taught to POKéMON.”$"
	.else
	.ifdef GERMAN
	.string "HAUS des ATTACKEN-HELFERS\n"
	.string "“Neue Attacken für deine POKéMON.”$"
	.endif
	.endif
