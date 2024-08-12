.set LOCALID_TWIN, 2

VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.ifdef ENGLISH
	.string "My papa told me.\p"
	.string "He says this tunnel is full of\n"
	.string "timid POKéMON.\p"
	.string "They get all scared of loud noise and\n"
	.string "make a big uproar.\p"
	.string "So they had to stop the big tunnel\n"
	.string "project.\p"
	.string "But there's one man. He's trying to dig\n"
	.string "the tunnel by himself!$"
	.else
	.ifdef GERMAN
	.string "Mein Papa hat mir das erzählt.\p"
	.string "Er sagt, der Tunnel sei voller scheuer\n"
	.string "POKéMON.\p"
	.string "Sie haben Angst vor lauten Geräuschen\n"
	.string "und machen einen Aufruhr.\p"
	.string "Daher musste das Tunnelprojekt\n"
	.string "gestoppt werden.\p"
	.string "Aber es gibt da einen Mann. Der ver-\n"
	.string "sucht, den Tunnel alleine zu graben.$"
	.endif
	.endif

VerdanturfTown_Text_ManDugTunnelForLove:
	.ifdef ENGLISH
	.string "There was a man who dug a tunnel for\n"
	.string "a lady he loved.\p"
	.string "I don't really get it, but hey!$"
	.else
	.ifdef GERMAN
	.string "Da war ein Mann, der hat den Tunnel\n"
	.string "ganz alleine für die Frau seines\l"
	.string "Herzens gegraben.\p"
	.string "Ich habe das nie so ganz verstanden.\n"
	.string "Aber, hey, ich finde es trotzdem klasse.$"
	.endif
	.endif

VerdanturfTown_Text_AirCleanHere:
	.ifdef ENGLISH
	.string "The way the winds blow, volcanic ash\n"
	.string "is never blown in this direction.\p"
	.string "The air is clean and delicious here.\n"
	.string "Living here should do wonders for even\l"
	.string "frail and sickly people.$"
	.else
	.ifdef GERMAN
	.string "Der Wind steht immer so günstig, dass\n"
	.string "die Asche vom Vulkan nie hierher\l"
	.string "geweht wird.\p"
	.string "Die Luft ist sauber und klar.\n"
	.string "Hier zu leben, hilft auch den schwachen\l"
	.string "und kränklichen Menschen.$"
	.endif
	.endif

VerdanturfTown_Text_MakeBattleTentDebut:
	.ifdef ENGLISH
	.string "My POKéMON and I, we've been riding\n"
	.string "a hot winning streak.\p"
	.string "So I decided to make my BATTLE TENT\n"
	.string "debut in this town.$"
	.else
	.ifdef GERMAN
	.string "Meine POKéMON und ich haben gerade\n"
	.string "eine Gewinnserie.\p"
	.string "Daher werde ich nun meinen Auftritt\n"
	.string "im KAMPFCAMP haben.$"
	.endif
	.endif

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.ifdef ENGLISH
	.string "Did you see the cave next to the\n"
	.string "POKéMON MART?\p"
	.string "There's a guy in there who's trying to\n"
	.string "bust up boulders so he can bust out\l"
	.string "through to the other side.\p"
	.string "It'd be great if we could go through…\n"
	.string "It'll make it easy to visit RUSTBORO.$"
	.else
	.ifdef GERMAN
	.string "Siehst du die Höhle neben dem PKMN-\n"
	.string "SUPERMARKT?\p"
	.string "Da ist ein Typ drin, der die Felsbrocken\n"
	.string "sprengen will, damit er auf die andere\l"
	.string "Seite gehen kann.\p"
	.string "Wäre das toll, wenn ich auch dort durch-\n"
	.string "gehen könnte… Ein Besuch in\l"
	.string "METAROST CITY wäre dann ganz einfach.$"
	.endif
	.endif

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.ifdef ENGLISH
	.string "That cave next to the POKéMON MART\n"
	.string "is now a tunnel to the other side.\p"
	.string "It's great--it's easy to go shop for\n"
	.string "new DEVON products in RUSTBORO now.$"
	.else
	.ifdef GERMAN
	.string "Die Höhle neben dem PKMN-SUPERMARKT\n"
	.string "ist nun ein Tunnel zur anderen Seite.\p"
	.string "Das ist toll! Jetzt kommt man ganz\n"
	.string "einfach nach METAROST CITY, um\l"
	.string "DEVON-WAREN zu kaufen.$"
	.endif
	.endif

VerdanturfTown_Text_TownSign:
	.ifdef ENGLISH
	.string "VERDANTURF TOWN\p"
	.string "“The windswept highlands with the\n"
	.string "sweet fragrance of grass.”$"
	.else
	.ifdef GERMAN
	.string "WIESENFLUR\p"
	.string "“Das vom Wind gestreichelte Hoch-\n"
	.string "land mit dem süßen Duft des Grases.”$"
	.endif
	.endif

VerdanturfTown_Text_WandasHouse:
	.ifdef ENGLISH
	.string "WANDA'S HOUSE$"
	.else
	.ifdef GERMAN
	.string "HEIKES HAUS$"
	.endif
	.endif

VerdanturfTown_Text_BattleTentSign:
	.ifdef ENGLISH
	.string "BATTLE TENT VERDANTURF SITE\n"
	.string "“Feast Your Eyes on Battles!”$"
	.else
	.ifdef GERMAN
	.string "KAMPFCAMP WIESENFLUR\n"
	.string "“Wo Kämpfe Eine Augenweide Sind”$"
	.endif
	.endif

VerdanturfTown_Text_RusturfTunnelSign:
	.ifdef ENGLISH
	.string "RUSTURF TUNNEL\n"
	.string "“Linking RUSTBORO and VERDANTURF\p"
	.string "“The tunnel project has been\n"
	.string "canceled.”$"
	.else
	.ifdef GERMAN
	.string "METAFLURTUNNEL\n"
	.string "“Verbindet METAROST CITY und\p"
	.string "WIESENFLUR.\nDas Tunnelprojekt wurde abgebrochen.”$"
	.endif
	.endif
