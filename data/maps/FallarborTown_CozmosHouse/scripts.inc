FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.ifdef ENGLISH
	.string "PROF. COZMO: Oh…\n"
	.string "I never should have let myself be\l"
	.string "conned into telling TEAM MAGMA where\l"
	.string "you can find METEORITES…\p"
	.string "That METEORITE from METEOR FALLS…\n"
	.string "It's never going to be mine now…$"
	.else
	.ifdef GERMAN
	.string "PROF. KOSMO: Oh…\n"
	.string "Ich hätte mich nie dazu verleiten\l"
	.string "lassen dürfen, TEAM MAGMA zu verraten,\l"
	.string "wo METEORITen zu finden sind…\p"
	.string "Der METEORIT von den METEORFÄLLEn…\n"
	.string "Nun wird er niemals mir gehören…$"
	.endif
	.endif

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.ifdef ENGLISH
	.string "Oh!\n"
	.string "Hah?\p"
	.string "That item…\p"
	.string "Could it be?\p"
	.string "Is it the METEORITE that TEAM MAGMA\n"
	.string "took from METEOR FALLS?\p"
	.string "Please, may I have it?\p"
	.string "I'm not asking for it for free.\n"
	.string "How about in exchange for this TM?$"
	.else
	.ifdef GERMAN
	.string "Oh!\n"
	.string "Oooh?\p"
	.string "Dieses Item…\p"
	.string "Kann es sein?\p"
	.string "Ist das der METEORIT, den TEAM MAGMA\n"
	.string "aus den METEORFÄLLEn entwendet hat?\p"
	.string "Bitte, darf ich den haben?\p"
	.string "Du bekommst auch etwas dafür.\n"
	.string "Was hältst du von dieser TM?$"
	.endif
	.endif

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.ifdef ENGLISH
	.string "PROF. COZMO: This TM, it represents\n"
	.string "my feeling of gratitude.\l"
	.string "Please use it!$"
	.else
	.ifdef GERMAN
	.string "PROF. KOSMO: Mit dieser TM möchte ich\n"
	.string "dir meine Dankbarkeit ausdrücken.\l"
	.string "Bitte, nimm sie an!$"
	.endif
	.endif

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.ifdef ENGLISH
	.string "PROF. COZMO: Oh, I can't believe it.\n"
	.string "This is really, really great!\p"
	.string "This is really going to help my research!$"
	.else
	.ifdef GERMAN
	.string "PROF. KOSMO: Oh, ich kann es einfach\n"
	.string "nicht glauben! Das ist nett! So nett!!!\p"
	.string "Das wird mir bei meinen Forschungen\n"
	.string "enorm weiterhelfen!$"
	.endif
	.endif

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.ifdef ENGLISH
	.string "PROF. COZMO: Oh, but…\n"
	.string "I'm crushed with disappointment…$"
	.else
	.ifdef GERMAN
	.string "PROF. KOSMO: Oh, aber…\n"
	.string "Das enttäuscht mich jetzt maßlos…$"
	.endif
	.endif

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.ifdef ENGLISH
	.string "PROF. COZMO: Please, may I have that\n"
	.string "METEORITE?\p"
	.string "I'm not asking for it for free.\n"
	.string "How about in exchange for this TM?$"
	.else
	.ifdef GERMAN
	.string "PROF. KOSMO: Bitte, darf ich den\n"
	.string "METEORITen haben?\p"
	.string "Ich möchte ihn nicht umsonst haben! Wie\n"
	.string "wäre es mit dieser TM im Tausch dafür?$"
	.endif
	.endif

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.ifdef ENGLISH
	.string "PROF. COZMO went off to METEOR FALLS\n"
	.string "on ROUTE 114 with some people from\l"
	.string "TEAM MAGMA.$"
	.else
	.ifdef GERMAN
	.string "PROF. KOSMO ist unterwegs zu\n"
	.string "METEORFÄLLE an der ROUTE 114. Einige\l"
	.string "Leute von TEAM MAGMA begleiten ihn.$"
	.endif
	.endif

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.ifdef ENGLISH
	.string "Poor PROF. COZMO…\n"
	.string "He's so depressed… I feel sorry for him.$"
	.else
	.ifdef GERMAN
	.string "Armer PROF. KOSMO…\n"
	.string "Er ist so deprimiert… Er tut mir Leid.$"
	.endif
	.endif

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.ifdef ENGLISH
	.string "Look at PROF. COZMO…\n"
	.string "He's so happy! I think it's cute.$"
	.else
	.ifdef GERMAN
	.string "Schau dir nur PROF. KOSMO an…\n"
	.string "Er ist so glücklich! Richtig niedlich.$"
	.endif
	.endif

