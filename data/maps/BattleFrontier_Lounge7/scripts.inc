BattleFrontier_Lounge7_MapScripts::
	.byte 0

BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_FRONTIER_TUTOR_SELECTION
	copyvar VAR_0x8005, VAR_TEMP_FRONTIER_TUTOR_ID
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end

BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.ifdef ENGLISH
	.string "Buhahaha!\p"
	.string "You couldn't tell it from looking now,\n"
	.string "but I used to be one tough TRAINER.\p"
	.string "I had a reputation as the toughest\n"
	.string "BEAUTY around, I tell you!\p"
	.string "… … … … … …\p"
	.string "What is it now?\n"
	.string "You don't believe me.\p"
	.string "I'm not like that blowhard woman over\n"
	.string "there. I'm actually talented!\p"
	.string "Let me prove it to you.\n"
	.string "I can teach your POKéMON special and\l"
	.string "yet cute moves.\p"
	.string "But my lessons don't come free.\n"
	.string "How about paying for the moves I teach\l"
	.string "with a wee bit of Battle Points?$"
	.else
	.ifdef GERMAN
	.string "Muahahahaha!\p"
	.string "Du wirst es mir wahrscheinlich nicht\n"
	.string "glauben, aber ich war eine starke\l"
	.string "TRAINERin.\p"
	.string "Ich war die stärkste SCHÖNHEIT, die es\n"
	.string "weit und breit gab!\p"
	.string "… … … … …\n"
	.string "… …\p"
	.string "Und?\n"
	.string "Glaubst du mir etwa nicht? Nein?\p"
	.string "Ich bin nicht so wie die Angeberin hier\n"
	.string "neben mir. ICH habe wirklich Talent!\p"
	.string "Das werde ich dir beweisen.\n"
	.string "Ich kann deinen POKéMON Spezial-\l"
	.string "Attacken beibringen,\p"
	.string "die auch noch niedlich sind. Aber das\n"
	.string "kostet eine Kleinigkeit. Dafür möchte\l"
	.string "ich von dir Gewinnpunkte haben.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.ifdef ENGLISH
	.string "Buhahaha!\p"
	.string "Are you back to learn special and\n"
	.string "yet cute POKéMON moves?$"
	.else
	.ifdef GERMAN
	.string "Muahahahaha!\p"
	.string "Soll ich deinen POKéMON ein paar\n"
	.string "hübsche Spezial-Attacken beibringen?$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.ifdef ENGLISH
	.string "Fine, fine, look here!\n"
	.string "Which move should I teach?$"
	.else
	.ifdef GERMAN
	.string "Schön, schön. Sehr gut. Welche\n"
	.string "Attacke soll ich ihnen beibringen?$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.ifdef ENGLISH
	.string "The move {STR_VAR_1}, is it?\n"
	.string "That will be {STR_VAR_2} Battle Points, okay?$"
	.else
	.ifdef GERMAN
	.string "Die Attacke {STR_VAR_1} soll es sein?\n"
	.string "Die kostet dich {STR_VAR_2} Gewinnpunkte.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.ifdef ENGLISH
	.string "Fine, fine, now pick the POKéMON\n"
	.string "I should teach the move to.$"
	.else
	.ifdef GERMAN
	.string "Schön, schön. Und welchem POKéMON\n"
	.string "soll ich sie beibringen?$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.ifdef ENGLISH
	.string "What the…\n"
	.string "You haven't got enough Battle Points!$"
	.else
	.ifdef GERMAN
	.string "Was… Du hast ja gar\n"
	.string "nicht genug Gewinnpunkte!$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.ifdef ENGLISH
	.string "Do you see how skilled I am now?\n"
	.string "I'll take your Battle Points, thanks!$"
	.else
	.ifdef GERMAN
	.string "Siehst du nun, wie talentiert ich bin?\n"
	.string "Und nun hätte ich gerne deine\l"
	.string "Gewinnpunkte. Danke!$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.ifdef ENGLISH
	.string "What's that?\n"
	.string "You don't want to…\p"
	.string "If you want to see how skilled I am,\n"
	.string "you come see me anytime!$"
	.else
	.ifdef GERMAN
	.string "Was denn? Was denn?\n"
	.string "Du musst doch nicht gleich…\p"
	.string "Wenn du sehen willst, wie talentiert ich\n"
	.string "bin, dann komm wieder. Jederzeit!$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.ifdef ENGLISH
	.string "Ihihihi!\p"
	.string "I know it's hard to see now, but I used\n"
	.string "to be one fantastic TRAINER.\p"
	.string "I had a reputation as the most\n"
	.string "invincible SWIMMER around, I tell you!\p"
	.string "… … … … … …\p"
	.string "What's wrong?\n"
	.string "You don't believe me.\p"
	.string "I'm not like that buffoonish woman over\n"
	.string "there. I'm actually experienced!\p"
	.string "I can prove it to you.\n"
	.string "I can teach your POKéMON hard and\l"
	.string "yet pretty moves.\p"
	.string "But my lessons don't come free.\n"
	.string "How about paying for the moves I teach\l"
	.string "with a wee bit of Battle Points?$"
	.else
	.ifdef GERMAN
	.string "Hihihihi!\p"
	.string "Auch wenn es schwer zu glauben ist: Ich\n"
	.string "war einmal eine grandiose TRAINERin!\p"
	.string "Ich hatte den Ruf einer unschlagbaren\n"
	.string "SCHWIMMERIN. Das ist wahr!\p"
	.string "… … … … …\n"
	.string "… …\p"
	.string "Wie bitte?\n"
	.string "Du glaubst mir nicht!\p"
	.string "Ich bin nicht so närrisch wie die da\n"
	.string "drüben. Ich habe wirklich Erfahrung!\p"
	.string "Das kann ich dir gerne beweisen!\n"
	.string "Ich kann deinen POKéMON starke und\l"
	.string "schöne Attacken beibringen.\p"
	.string "Aber das kostet dich etwas. Bring ich\n"
	.string "deinen POKéMON etwas bei, bekomme\l"
	.string "ich von dir Gewinnpunkte.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.ifdef ENGLISH
	.string "Ihihihi!\p"
	.string "Have you come to learn hard and\n"
	.string "yet pretty POKéMON moves?$"
	.else
	.ifdef GERMAN
	.string "Hihihihi!\p"
	.string "Ich soll deinen POKéMON starke und\n"
	.string "schöne Attacken beibringen?$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.ifdef ENGLISH
	.string "Those ladies, the way they bad-mouth\n"
	.string "each other, you probably think that\l"
	.string "they don't get along.\p"
	.string "But if that were true, they wouldn't\n"
	.string "stay out here together, would they?$"
	.else
	.ifdef GERMAN
	.string "Diese Damen dahinten, die beschimpfen\n"
	.string "sich ständig. Du denkst bestimmt, die\l"
	.string "verstehen sich überhaupt nicht.\p"
	.string "Aber in Wahrheit würde die eine keinen\n"
	.string "Schritt ohne die andere machen.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.ifdef ENGLISH
	.string "When I was just a wee YOUNGSTER,\n"
	.string "those ladies were strong and beautiful.\p"
	.string "They were idols among us TRAINERS.\p"
	.string "Even now, age hasn't dulled their\n"
	.string "abilities.\p"
	.string "In fact, their POKéMON moves have\n"
	.string "grown even more polished.\p"
	.string "But… For some reason, I can't help\n"
	.string "but feel this…\p"
	.string "Time is so cruel…$"
	.else
	.ifdef GERMAN
	.string "Als ich noch ein junger Spund, ein\n"
	.string "TEENAGER, war, waren diese Damen stark\l"
	.string "und wunderschön.\p"
	.string "Wir TRAINER haben sie vergöttert.\p"
	.string "Und auch jetzt, im Alter, haben ihre\n"
	.string "Fähigkeiten nicht nachgelassen.\p"
	.string "Im Gegenteil: Ihre POKéMON-Attacken\n"
	.string "sind einfach vollkommen.\p"
	.string "Aber…\n"
	.string "Trotzdem denke ich…\p"
	.string "Die Zeit ist grausam…$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.ifdef ENGLISH
	.string "Recovers up to\n"
	.string "half the user's\n"
	.string "maximum HP.$"
	.else
	.ifdef GERMAN
	.string "Max. KP des Anwen-\n"
	.string "ders w. zur Hälfte\n"
	.string "aufgefüllt.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.ifdef ENGLISH
	.string "Inflicts damage\n"
	.string "identical to the\n"
	.string "user's level.$"
	.else
	.ifdef GERMAN
	.string "Richtet Schaden\n"
	.string "gemäß Level d.\n"
	.string "Angreifers an.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.ifdef ENGLISH
	.string "Recovers half the\n"
	.string "damage inflicted\n"
	.string "on a sleeping foe.$"
	.else
	.ifdef GERMAN
	.string "Schlafendem Geg.\n"
	.string "wird halber Scha-\n"
	.string "den abgezogen.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.ifdef ENGLISH
	.string "A strong punch\n"
	.string "thrown with\n"
	.string "incredible power.$"
	.else
	.ifdef GERMAN
	.string "Ein unglaublich\n"
	.string "kräftiger Hieb.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.ifdef ENGLISH
	.string "An extremely\n"
	.string "powerful kick with\n"
	.string "intense force.$"
	.else
	.ifdef GERMAN
	.string "Ein extrem\n"
	.string "heftiger Tritt.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.ifdef ENGLISH
	.string "A full-body slam\n"
	.string "that may cause\n"
	.string "paralysis.$"
	.else
	.ifdef GERMAN
	.string "Körper-Ramme,\n"
	.string "kann Paralyse\n"
	.string "hervorrufen.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.ifdef ENGLISH
	.string "Large boulders\n"
	.string "are hurled. May\n"
	.string "cause flinching.$"
	.else
	.ifdef GERMAN
	.string "Schleudert\n"
	.string "Felsen. Ver-\n"
	.string "schreckt Gegner.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_CounterDesc::
	.ifdef ENGLISH
	.string "Retaliates any\n"
	.string "physical hit with\n"
	.string "double the power.$"
	.else
	.ifdef GERMAN
	.string "Kontert phys.\n"
	.string "Treffer mit\n"
	.string "doppelter Kraft.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.ifdef ENGLISH
	.string "A weak jolt of\n"
	.string "electricity that\n"
	.string "paralyzes the foe.$"
	.else
	.ifdef GERMAN
	.string "Ein schwacher\n"
	.string "Stromstoß, der d.\n"
	.string "Gegner paralys.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.ifdef ENGLISH
	.string "A fighting dance\n"
	.string "that sharply\n"
	.string "raises ATTACK.$"
	.else
	.ifdef GERMAN
	.string "Erhöht den\n"
	.string "Angriffs-Wert\n"
	.string "drastisch.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.ifdef ENGLISH
	.string "Curls up to con-\n"
	.string "ceal weak spots\n"
	.string "and raise DEFENSE.$"
	.else
	.ifdef GERMAN
	.string "Verbirgt Schwäche\n"
	.string "durch Einrollen,\n"
	.string "VERT.-Wert hoch.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_SnoreDesc::
	.ifdef ENGLISH
	.string "A loud attack\n"
	.string "that can be used\n"
	.string "only while asleep.$"
	.else
	.ifdef GERMAN
	.string "Laute Attacke.\n"
	.string "Kann nur im Schlaf\n"
	.string "benutzt werden.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.ifdef ENGLISH
	.string "Hurls mud in the\n"
	.string "foe's face to re-\n"
	.string "duce its accuracy.$"
	.else
	.ifdef GERMAN
	.string "Wirft Gegner\n"
	.string "Matsch i. Gesicht.\n"
	.string "Genauigkeit sinkt.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_SwiftDesc::
	.ifdef ENGLISH
	.string "Sprays star-\n"
	.string "shaped rays\n"
	.string "that never miss.$"
	.else
	.ifdef GERMAN
	.string "Verschießt stern-\n"
	.string "förmige Strahlen.\n"
	.string "Treffergarantie!$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.ifdef ENGLISH
	.string "A chilling attack\n"
	.string "that lowers the\n"
	.string "foe's SPEED.$"
	.else
	.ifdef GERMAN
	.string "Eis-Attacke, die\n"
	.string "den INIT.-Wert d.\n"
	.string "Gegners senkt.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_EndureDesc::
	.ifdef ENGLISH
	.string "Endures any at-\n"
	.string "tack for 1 turn,\n"
	.string "leaving 1HP.$"
	.else
	.ifdef GERMAN
	.string "Hält jed. Attacke\n"
	.string "1 Runde stand.\n"
	.string "1 KP bleibt stets.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.ifdef ENGLISH
	.string "Copies the foe's\n"
	.string "effect(s) and\n"
	.string "gives to the user.$"
	.else
	.ifdef GERMAN
	.string "Kopiert Effekte d.\n"
	.string "Gegners u. gibt\n"
	.string "sie dem Angreifer.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.ifdef ENGLISH
	.string "An icy punch\n"
	.string "that may\n"
	.string "freeze the foe.$"
	.else
	.ifdef GERMAN
	.string "Ein Schlag, der\n"
	.string "den Gegner\n"
	.string "evtl. einfriert.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.ifdef ENGLISH
	.string "An electrified\n"
	.string "punch that may\n"
	.string "paralyze the foe.$"
	.else
	.ifdef GERMAN
	.string "Schlag, der den\n"
	.string "Gegner evtl.\n"
	.string "paralysiert.$"
	.endif
	.endif

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.ifdef ENGLISH
	.string "A fiery punch\n"
	.string "that may burn\n"
	.string "the foe.$"
	.else
	.ifdef GERMAN
	.string "Schlag, der dem\n"
	.string "Gegner evtl. Ver-\n"
	.string "brennung zufügt.$"
	.endif
	.endif
