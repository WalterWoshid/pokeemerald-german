.set LOCALID_CAPT_STERN, 1
.set LOCALID_ARCHIE, 2
.set LOCALID_GRUNT_1, 3
.set LOCALID_GRUNT_2, 4

SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_GRUNT_1
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject LOCALID_GRUNT_2
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_ARCHIE
	applymovement LOCALID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_GOODS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	removeobject LOCALID_CAPT_STERN
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.ifdef ENGLISH
	.string "Yes? If you're looking for STERN,\n"
	.string "that would be me.\p"
	.string "Ah! Those must be the parts I ordered\n"
	.string "from MR. STONE of DEVON.\p"
	.string "Thank you! That's great!\n"
	.string "We can prepare for our expedition now.$"
	.else
	.ifdef GERMAN
	.string "Ja? Wenn du BRIGG suchst… Der\n"
	.string "bin ich.\p"
	.string "Ah! Das müssen die Stücke sein, die ich\n"
	.string "bei MR. TRUMM von DEVON bestellt habe.\p"
	.string "Danke schön! Das ist großartig!\n"
	.string "Nun können wir unsere Expedition\l"
	.string "vorbereiten.$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.ifdef ENGLISH
	.string "Hehehe, hold it!\n"
	.string "We'll take those parts!$"
	.else
	.ifdef GERMAN
	.string "Hähähähä! Wartet! Das ist doch viel zu\n"
	.string "schwer für euch! Wir nehmen das an uns!$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.ifdef ENGLISH
	.string "CAPT. STERN: Wh-what?\n"
	.string "Who are you people?$"
	.else
	.ifdef GERMAN
	.string "KAPT. BRIGG: W… Was?\n"
	.string "Wer seid ihr?$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.ifdef ENGLISH
	.string "We're TEAM AQUA!\p"
	.string "Our BOSS wants those parts!\n"
	.string "Shut your yap and fork them over!$"
	.else
	.ifdef GERMAN
	.string "Wir sind TEAM AQUA!\p"
	.string "Unser BOSS will diese Dinge haben!\n"
	.string "Also hört auf zu labern und lasst die\l"
	.string "Teile rüberwachsen!$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.ifdef ENGLISH
	.string "Awaaaah!\n"
	.string "A kid beat me!$"
	.else
	.ifdef GERMAN
	.string "Oooaaah!\n"
	.string "Geschlagen von einem KIND!$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.ifdef ENGLISH
	.string "Oh, man, what a disaster…\n"
	.string "The BOSS is going to be furious…$"
	.else
	.ifdef GERMAN
	.string "Oh, Mann! Was für ein Desaster…\n"
	.string "Der BOSS wird verdammt wütend sein…$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.ifdef ENGLISH
	.string "Humph, sniveling wimp!\n"
	.string "Let me take care of this!$"
	.else
	.ifdef GERMAN
	.string "Pah, du Waschlappen!\n"
	.string "Ich werde das Ding schon schaukeln!$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.ifdef ENGLISH
	.string "What?!\n"
	.string "I lost, too!$"
	.else
	.ifdef GERMAN
	.string "Was?!?\n"
	.string "Ich habe auch verloren?!?$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.ifdef ENGLISH
	.string "Now what? If we don't get the parts,\n"
	.string "we're in for it!\p"
	.string "Arrgh, I didn't count on being meddled\n"
	.string "with by some meddling kid!$"
	.else
	.ifdef GERMAN
	.string "Und nun? Wenn wir die Stücke nicht\n"
	.string "bekommen, können wir uns auf etwas\l"
	.string "gefasst machen!\p"
	.string "Argh, ich hatte nicht damit gerechnet,\n"
	.string "dass ein nervendes Kind meine Nerven\l"
	.string "nervt.$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.ifdef ENGLISH
	.string "I came to see what was taking so\n"
	.string "long to snatch some parts, and you\l"
	.string "simps are held up by a mere child?$"
	.else
	.ifdef GERMAN
	.string "Ich bin gekommen, um zu sehen, warum ihr\n"
	.string "so lange braucht. Und was sehe ich? Ihr\l"
	.string "Idioten lasst euch von einem kleinen\l"
	.string "Kind die Suppe versalzen!$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.ifdef ENGLISH
	.string "We are TEAM AQUA,\n"
	.string "and we love the sea!\p"
	.string "And I am TEAM AQUA's leader,\n"
	.string "ARCHIE!\p"
	.string "What makes you interfere with us?\p"
	.string "…No! You can't be!\n"
	.string "You're not one of TEAM MAGMA?\p"
	.string "Wait, that can't be right.\n"
	.string "You're not dressed for the part.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "POKéMON, people… All life depends on\n"
	.string "the sea.\p"
	.string "So, TEAM AQUA is dedicated to\n"
	.string "the expansion of the sea.\p"
	.string "Don't you agree? What we are doing\n"
	.string "is a magnificent undertaking.\p"
	.string "Ah, fine…\n"
	.string "You're still too young to understand\l"
	.string "our noble objective.\p"
	.string "But, I warn you, don't even consider\n"
	.string "interfering with our plans again.\p"
	.string "The consequences will cost you\n"
	.string "dearly!\p"
	.string "And don't you forget it!$"
	.else
	.ifdef GERMAN
	.string "Wir sind TEAM AQUA und lieben\n"
	.string "das Meer!\p"
	.string "Und ich bin TEAM AQUAs BOSS,\n"
	.string "ADRIAN!\p"
	.string "Wieso mischst du dich in unsere\n"
	.string "Angelegenheiten ein?\p"
	.string "Nein… Das kann nicht sein!\n"
	.string "Du bist doch nicht von TEAM MAGMA?\p"
	.string "Warte mal, das stimmt doch einfach\n"
	.string "nicht! Du bist doch gar nicht danach\l"
	.string "angezogen!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "POKéMON, Menschen - alles Leben\n"
	.string "basiert auf den Kräften des Meeres.\p"
	.string "Daher setzt TEAM AQUA sich für die\n"
	.string "Ausweitung des Meeres ein.\p"
	.string "Meinst du nicht auch, dass wir uns eine\n"
	.string "großartige Aufgabe gestellt haben?\p"
	.string "Mhm…\n"
	.string "Du bist wahrscheinlich noch zu klein.\p"
	.string "Du kannst unsere Ideale einfach noch\n"
	.string "nicht verstehen.\p"
	.string "Aber: Wenn du dich jemals wieder gegen\n"
	.string "uns stellst, wirst du die Konsequenzen\l"
	.string "zu spüren bekommen!\p"
	.string "Vergiss das nicht!$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.ifdef ENGLISH
	.string "CAPT. STERN: You're…\n"
	.string "Ah, okay, you're {PLAYER}{KUN}…\p"
	.string "Anyway, that was a tense situation!\n"
	.string "Thank you for saving us!\p"
	.string "Oh, yes, I almost forgot that you\n"
	.string "even brought the parts from DEVON!$"
	.else
	.ifdef GERMAN
	.string "KAPT. BRIGG: Du bist…\n"
	.string "Aah, du bist {PLAYER}{KUN}…\p"
	.string "Wow, das war eine kritische Situation!\n"
	.string "Danke, dass du uns gerettet hast!\p"
	.string "Oh, fast hätte ich vergessen, dass du\n"
	.string "uns die Teile von DEVON gebracht hast!$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.ifdef ENGLISH
	.string "CAPT. STERN: Whoops!\n"
	.string "There's no time to lose!\p"
	.string "We have to set out on our ocean-floor\n"
	.string "expedition really soon.\p"
	.string "Thanks again, but now I've got\n"
	.string "to go!\p"
	.string "Feel free to wander around and check\n"
	.string "out our facilities, though.$"
	.else
	.ifdef GERMAN
	.string "KAPT. BRIGG: Hoppla!\n"
	.string "Wir dürfen keine Zeit mehr verlieren!\p"
	.string "Wir müssen so schnell wie möglich zur\n"
	.string "Expedition zum Meeresgrund\l"
	.string "aufbrechen.\p"
	.string "Danke! Und entschuldige mich nun!\p"
	.string "Du kannst dir hier ruhig alles in Ruhe\n"
	.string "anschauen, wenn du magst.$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.ifdef ENGLISH
	.string "I saw a model of a ship here.\p"
	.string "It reminded me of the ABANDONED SHIP\n"
	.string "near DEWFORD TOWN…$"
	.else
	.ifdef GERMAN
	.string "Ich habe hier ein Schiffsmodell\n"
	.string "gesehen.\p"
	.string "Es erinnert mich an das SCHIFFSWRACK\n"
	.string "in der Nähe von FAUSTAUHAVEN…$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.ifdef ENGLISH
	.string "Don't you dare run around inside\n"
	.string "the MUSEUM!$"
	.else
	.ifdef GERMAN
	.string "Es ist strikt verboten, im MUSEUM\n"
	.string "zu rennen!$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.ifdef ENGLISH
	.string "Wow, the submarine's awesome!\n"
	.string "I want to go for a ride!$"
	.else
	.ifdef GERMAN
	.string "Wow, das U-Boot ist der helle Wahnsinn!\n"
	.string "Damit würde ich gerne auf Fahrt gehen!$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.ifdef ENGLISH
	.string "“WATER QUALITY SAMPLE 1,” the\n"
	.string "label says.\p"
	.string "The sea is all connected, but the\n"
	.string "water seems to differ by region.$"
	.else
	.ifdef GERMAN
	.string "“WASSERQUALITÄT BEISPIEL 1”\n"
	.string "steht auf dem Schild.\p"
	.string "Das Meer ist grenzübergreifend, aber\n"
	.string "das Wasser scheint in jeder Region eine\l"
	.string "andere Qualität zu haben.$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.ifdef ENGLISH
	.string "“WATER QUALITY SAMPLE 2,” the\n"
	.string "label says.\p"
	.string "Does the saltiness of seawater differ\n"
	.string "by region, too?$"
	.else
	.ifdef GERMAN
	.string "“ WASSERQUALITÄT BEISPIEL 2”\n"
	.string "steht auf dem Schild.\p"
	.string "Anscheinend ist der Salzgehalt in jeder\n"
	.string "Region anders.$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.ifdef ENGLISH
	.string "A rubber ball is expanding and\n"
	.string "shrinking.\p"
	.string "“In the sea, the weight of water itself\n"
	.string "exerts pressure.\p"
	.string "“In shallow water, the pressure is not\n"
	.string "very heavy.\p"
	.string "“However, in extremely deep water,\n"
	.string "the pressure can reach even tens of\l"
	.string "thousands of tons on a small area.”$"
	.else
	.ifdef GERMAN
	.string "Ein Gummiball wird größer und kleiner.\p"
	.string "“Im Meer sorgt das Gewicht des Wassers\n"
	.string "für ständigen Druck.\p"
	.string "In seichtem Wasser ist der Druck nicht\n"
	.string "sehr hoch.\p"
	.string "In extrem tiefem Wasser kann der\n"
	.string "Druck zehntausende von Tonnen inner-\l"
	.string "halb eines kleinen Bereiches betragen.”$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.ifdef ENGLISH
	.string "“MODEL OF HOENN REGION”\p"
	.string "It's a miniature diorama of the\n"
	.string "HOENN region.\p"
	.string "Where is LITTLEROOT TOWN on this?$"
	.else
	.ifdef GERMAN
	.string "“MODELL DER HOENN-REGION”\p"
	.string "Ein Diorama der HOENN-Region.\p"
	.string "Wo liegt hier WURZELHEIM?$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.ifdef ENGLISH
	.string "It's a display on the flow of seawater.\p"
	.string "“Near the bottom of the sea, water\n"
	.string "flows due to differences in such\l"
	.string "factors as temperature and salinity.”$"
	.else
	.ifdef GERMAN
	.string "Dies ist eine Anzeige der Meeres-\n"
	.string "strömungen.\p"
	.string "“In der Nähe des Meeresbodens sind die\n"
	.string "Strömungen abhängig von Faktoren wie\l"
	.string "Temperatur und Salzgehalt.”$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.ifdef ENGLISH
	.string "It's a display on the flow of seawater.\p"
	.string "“Toward the surface, seawater flows\n"
	.string "as currents driven by the winds.”$"
	.else
	.ifdef GERMAN
	.string "Dies ist eine Anzeige der Meeres-\n"
	.string "strömungen.\p"
	.string "“An der Oberfläche sind die Strömungen\n"
	.string "abhängig vom Einfluss des Windes.”$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.ifdef ENGLISH
	.string "“THE FERRY S.S. TIDAL\p"
	.string "“A scale replica of the ship under\n"
	.string "construction at STERN'S SHIPYARD.”$"
	.else
	.ifdef GERMAN
	.string "“DIE FÄHRE MS TIDE”\p"
	.string "“Ein maßstabsgetreues Modell eines\n"
	.string "Schiffes unter Konstruktion in der\l"
	.string "BRIGGWERFT.”$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.ifdef ENGLISH
	.string "“SUBMARINE EXPLORER 1\p"
	.string "“A replica of the high-performance\n"
	.string "ocean floor exploration submarine.”$"
	.else
	.ifdef GERMAN
	.string "“TIEFSEE-FORSCHUNGSBOOT 1”\p"
	.string "“Ein Replikat des Hochleistungs-\n"
	.string "U-Bootes zur Erforschung des\l"
	.string "Meeresbodens.”$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.ifdef ENGLISH
	.string "“SUBMERSIBLE POD\p"
	.string "“A replica of a compact, unmanned\n"
	.string "pod for seafloor exploration.”$"
	.else
	.ifdef GERMAN
	.string "“TAUCHBOOT”\p"
	.string "“Ein Replikat eines kompakten,\n"
	.string "unbemannten Spezial-U-Bootes zur Er-\l"
	.string "forschung des Meeresbodens.”$"
	.endif
	.endif

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.ifdef ENGLISH
	.string "“S.S. ANNE\p"
	.string "“A replica of the luxury liner that\n"
	.string "circles the globe.”$"
	.else
	.ifdef GERMAN
	.string "“MS ANNE”\p"
	.string "“Ein Replikat eines Luxusliners, der\n"
	.string "um den Globus kreuzt.”$"
	.endif
	.endif

