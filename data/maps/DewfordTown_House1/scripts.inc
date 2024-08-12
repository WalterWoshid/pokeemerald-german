DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.ifdef ENGLISH
	.string "There's a lot to be said for living on\n"
	.string "a small island like this in harmony with\l"
	.string "POKéMON and the family.$"
	.else
	.ifdef GERMAN
	.string "Über das harmonische Leben mit den\n"
	.string "POKéMON und der Familie auf diesem\l"
	.string "kleinen Eiland ließe sich viel erzählen.$"
	.endif
	.endif

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.ifdef ENGLISH
	.string "I left the major port of SLATEPORT\n"
	.string "CITY when I married my husband here.\p"
	.string "Life goes by slowly on this little\n"
	.string "island. But being surrounded by the\l"
	.string "beautiful sea--that's happiness, too.$"
	.else
	.ifdef GERMAN
	.string "Bevor ich meinen Mann geheiratet habe,\n"
	.string "lebte ich in der großen Hafenstadt\l"
	.string "GRAPHITPORT CITY.\p"
	.string "Hier auf der Insel verläuft das Leben\n"
	.string "geruhsamer. Vom wunderbaren Meer um-\l"
	.string "geben - das ist die pure Glückseligkeit!$"
	.endif
	.endif

DewfordTown_House1_Text_Zigzagoon:
	.ifdef ENGLISH
	.string "ZIGZAGOON: Guguuh!$"
	.else
	.ifdef GERMAN
	.string "ZIGZACHS: Guguuh!$"
	.endif
	.endif

