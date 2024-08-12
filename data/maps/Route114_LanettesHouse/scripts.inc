Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.ifdef ENGLISH
	.string "LANETTE: Oh! {PLAYER}{KUN}!\p"
	.string "I'm sorry everything is so cluttered…\n"
	.string "When I get engrossed in research,\l"
	.string "things end up this way…\p"
	.string "This is embarrassing… Please keep\n"
	.string "this a secret in exchange for this.$"
	.else
	.ifdef GERMAN
	.string "LANETTE: Oh! {PLAYER}{KUN}!\p"
	.string "Entschuldige, dass es hier so chaotisch\n"
	.string "aussieht. Immer, wenn ich forsche,\l"
	.string "vergesse ich aufzuräumen…\p"
	.string "Das ist echt peinlich… Erzähl das bloß\n"
	.string "niemandem! Ich gebe dir auch dies hier…$"
	.endif
	.endif

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.ifdef ENGLISH
	.string "May I offer advice about my POKéMON\n"
	.string "Storage System?\p"
	.string "You should organize your BOXES so you\n"
	.string "can tell which POKéMON are in them.$"
	.else
	.ifdef GERMAN
	.string "Soll ich dir einige Hinweise zum\n"
	.string "POKéMON-Lagerungs-System geben?\p"
	.string "Du solltest deine BOXen gut verwalten,\n"
	.string "damit du weißt, welche POKéMON sich \l"
	.string "in welcher BOX befinden…$"
	.endif
	.endif

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.ifdef ENGLISH
	.string "It's LANETTE's research notes.\n"
	.string "There's information about BOXES.\p"
	.string "Design BOXES to hold 30 POKéMON each.\p"
	.string "Each TRAINER should be able to store\n"
	.string "420 POKéMON on the PC system.\p"
	.string "Keep reading?$"
	.else
	.ifdef GERMAN
	.string "LANETTEs Forschungs-Aufzeichnungen.\n"
	.string "Das sind Informationen zu den BOXen.\p"
	.string "Es sollten BOXen eingerichtet werden,\n"
	.string "die jeweils 30 POKéMON aufnehmen\l"
	.string "können.\p"
	.string "Jeder TRAINER sollte in der Lage sein,\n"
	.string "420 POKéMON im PC-System zu lagern.\p"
	.string "Weiterlesen?$"
	.endif
	.endif

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.ifdef ENGLISH
	.string "A marking system should be added to\n"
	.string "make POKéMON easier to organize.\p"
	.string "The name and wallpaper design of each\n"
	.string "BOX will be made changeable to please\l"
	.string "the stored POKéMON.\p"
	.string "Keep reading?$"
	.else
	.ifdef GERMAN
	.string "Es muss ein Markierungssystem einge-\n"
	.string "richtet werden, mit dem man eine gute\l"
	.string "Übersicht über die POKéMON bekommt.\p"
	.string "Der Name und der Hintergrund jeder BOX\n"
	.string "lassen sich verändern, zur Freude der\l"
	.string "darin gelagerten POKéMON.\p"
	.string "Weiterlesen?$"
	.endif
	.endif

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.ifdef ENGLISH
	.string "When storing a POKéMON, it should be\n"
	.string "sent to the BOX inspected last.\p"
	.string "If that BOX is full, the received\n"
	.string "POKéMON is stored in the next BOX.\p"
	.string "In other words, when a BOX is examined,\n"
	.string "it is automatically selected as the BOX\l"
	.string "to which POKéMON are sent.$"
	.else
	.ifdef GERMAN
	.string "Immer, wenn ein POKéMON gelagert wird,\n"
	.string "wird es in der BOX gelagert, die als\l"
	.string "Letzte geöffnet wurde.\p"
	.string "Ist diese BOX voll, wird das POKéMON in\n"
	.string "der nächsten BOX gelagert.\p"
	.string "Mit anderen Worten, die zuletzt ge-\n"
	.string "öffnete BOX wird automatisch gewählt,\l"
	.string "um ein POKéMON zu lagern.$"
	.endif
	.endif

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.ifdef ENGLISH
	.string "{PLAYER} closed the notebook.$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} schließt das Notizbuch.$"
	.endif
	.endif

Route114_LanettesHouse_Text_EmailFromBill:
	.ifdef ENGLISH
	.string "There's an e-mail from someone on\n"
	.string "the PC.\p"
	.string "“… … … … … … …\p"
	.string "“Your Storage System offers more\n"
	.string "convenience than mine.\p"
	.string "“It has a lot of user-friendly features\n"
	.string "that make it fun and useful, too.\p"
	.string "“It makes me proud that I played\n"
	.string "a part in its development.\p"
	.string "“Here's hoping that you'll continue\n"
	.string "research in Storage Systems.\p"
	.string "“From BILL\n"
	.string "… … … … … … … …”$"
	.else
	.ifdef GERMAN
	.string "Da ist eine E-Mail von jemandem\n"
	.string "auf dem PC.\p"
	.string "“… … … … … … …\p"
	.string "Dein Lagerungs-System bietet viel mehr\n"
	.string "Komfort als meines.\p"
	.string "Es besitzt viele anwenderfreundliche\n"
	.string "Features, die nützlich sind und Spaß\l"
	.string "machen.\p"
	.string "Es macht mich stolz, dass ich Teil\n"
	.string "dieser Entwicklung war.\p"
	.string "Ich hoffe sehr, du setzt deine For-\n"
	.string "schungen in diesem Bereich weiter fort.\p"
	.string "BILL\n"
	.string "… … … … … … … …”$"
	.endif
	.endif

