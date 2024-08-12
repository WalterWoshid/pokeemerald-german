MossdeepCity_House4_MapScripts::
	.byte 0

MossdeepCity_House4_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_House4_EventScript_CanBattleAtSecretBases
	msgbox MossdeepCity_House4_Text_BrotherLikesToFindBases, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_CanBattleAtSecretBases::
	msgbox MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NinjaBoy::
	lock
	faceplayer
	special CheckPlayerHasSecretBase
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_House4_EventScript_NoSecretBase
	special GetSecretBaseNearbyMapName
	msgbox MossdeepCity_House4_Text_YouMadeSecretBaseNearX, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NoSecretBase::
	msgbox MossdeepCity_House4_Text_MakeSecretBase, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox MossdeepCity_House4_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MossdeepCity_House4_Text_BrotherLikesToFindBases:
	.ifdef ENGLISH
	.string "My little brother says he likes to go\n"
	.string "find people's SECRET BASES.$"
	.else
	.ifdef GERMAN
	.string "Mein kleiner Bruder liebt es, die\n"
	.string "GEHEIMBASEN der anderen zu finden.$"
	.endif
	.endif

MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle:
	.ifdef ENGLISH
	.string "My little brother says he likes to\n"
	.string "visit people's SECRET BASES and have\l"
	.string "POKéMON battles.$"
	.else
	.ifdef GERMAN
	.string "Mein kleiner Bruder sagt, er liebt es,\n"
	.string "die GEHEIMBASEN der anderen zu finden\l"
	.string "und Kämpfe mit POKéMON auszutragen.$"
	.endif
	.endif

MossdeepCity_House4_Text_YouMadeSecretBaseNearX:
	.ifdef ENGLISH
	.string "Was it you who made a SECRET BASE\n"
	.string "near {STR_VAR_1}?$"
	.else
	.ifdef GERMAN
	.string "Hast du dir eine GEHEIMBASIS in\n"
	.string "{STR_VAR_1} eingerichtet?$"
	.endif
	.endif

MossdeepCity_House4_Text_MakeSecretBase:
	.ifdef ENGLISH
	.string "You should make a SECRET BASE\n"
	.string "somewhere. I'll go find it!$"
	.else
	.ifdef GERMAN
	.string "Solltest du dir irgendwo eine GEHEIM-\n"
	.string "BASIS einrichten, werde ich sie sicher\l"
	.string "finden.$"
	.endif
	.endif

MossdeepCity_House4_Text_Skitty:
	.ifdef ENGLISH
	.string "SKITTY: Miyaan?$"
	.else
	.ifdef GERMAN
	.string "ENECO: Miayaan?$"
	.endif
	.endif

