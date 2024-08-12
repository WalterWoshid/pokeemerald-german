PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_LittleGirl::
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman::
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy::
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes::
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No::
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
	.ifdef ENGLISH
	.string "People were saying they saw a POKéMON\n"
	.string "flying high above HOENN.\p"
	.string "Is it flying around all the time?\n"
	.string "Doesn't it need to rest somewhere?$"
	.else
	.ifdef GERMAN
	.string "Die Menschen sagen, sie hätten ein \n"
	.string "POKéMON über HOENN FLIEGEN sehen.\p"
	.string "FLIEGT es die ganze Zeit über herum?\n"
	.string "Muss es sich nicht ausruhen?$"
	.endif
	.endif

PacifidlogTown_House4_Text_SkyPokemon:
	.ifdef ENGLISH
	.string "A sky POKéMON!\n"
	.string "A sky POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Ein Himmels-POKéMON!\n"
	.string "Ein Himmels-POKéMON!$"
	.endif
	.endif

PacifidlogTown_House4_Text_WhereDidYouComeFrom:
	.ifdef ENGLISH
	.string "Where did you come from?$"
	.else
	.ifdef GERMAN
	.string "Woher kommst du?$"
	.endif
	.endif

PacifidlogTown_House4_Text_YesTown:
	.ifdef ENGLISH
	.string "Yes?\n"
	.string "YES TOWN?\p"
	.string "I've never heard of a place like that.$"
	.else
	.ifdef GERMAN
	.string "Ja?\n"
	.string "JA-Stadt???\p"
	.string "Davon habe ich ja noch nie gehört!$"
	.endif
	.endif

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
	.ifdef ENGLISH
	.string "No? That doesn't make any sense.\n"
	.string "You have to come from somewhere.\p"
	.string "Oh! Wait! You're not going to say you\n"
	.string "were born at the bottom of the sea?$"
	.else
	.ifdef GERMAN
	.string "Nein? Das ergibt doch gar keinen Sinn.\n"
	.string "Du musst doch von irgendwo herkommen!\p"
	.string "Oh! Warte! Du willst doch nicht etwa be-\n"
	.string "haupten, du wärest in den Tiefen des\l"
	.string "Meeres geboren???$"
	.endif
	.endif

