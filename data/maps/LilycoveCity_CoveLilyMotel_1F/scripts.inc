.set LOCALID_OWNER, 1

LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.ifdef ENGLISH
	.string "Hm, so they doubled the guests by\n"
	.string "using POKéMON as attractions?\p"
	.string "Hm, well, maybe I should make a cute\n"
	.string "POKéMON our inn's mascot.\p"
	.string "I wonder if that will attract more\n"
	.string "guests to stay with us?$"
	.else
	.ifdef GERMAN
	.string "Hm, so haben sie also die Anzahl der\n"
	.string "Gäste verdoppelt. Indem sie POKéMON\l"
	.string "als Attraktion präsentieren?\p"
	.string "Hm, vielleicht sollte ich ein niedliches\n"
	.string "POKéMON zum Maskottchen meines\l"
	.string "Gasthofes machen…\p"
	.string "Ich frage mich, ob ich so mehr\n"
	.string "Gäste hätte?$"
	.endif
	.endif

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.ifdef ENGLISH
	.string "Oh, sorry, sorry!\n"
	.string "I was too involved in watching TV!\p"
	.string "Since that TEAM AQUA came to town,\n"
	.string "the tourists have been staying away.$"
	.else
	.ifdef GERMAN
	.string "Oh, tut mir Leid, tut mir Leid!\n"
	.string "Ich habe so konzentriert ferngesehen!\p"
	.string "Seit TEAM AQUA in diesem Ort ist,\n"
	.string "bleiben die Gäste aus.$"
	.endif
	.endif

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.ifdef ENGLISH
	.string "Hey, down in front!\n"
	.string "I can't see the TV!$"
	.else
	.ifdef GERMAN
	.string "Hey, geh weg da!\n"
	.string "Du bist doch nicht aus Glas!$"
	.endif
	.endif

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.ifdef ENGLISH
	.string "Amazing! You're telling me a POKéMON\n"
	.string "found someone's lost item?\p"
	.string "That's something. If we had some smart\n"
	.string "POKéMON like that…\p"
	.string "We could recover anything that our\n"
	.string "guests mislaid…$"
	.else
	.ifdef GERMAN
	.string "Interessant! Du sagst, ein POKéMON\n"
	.string "hat ein Item gefunden, das jemand ver-\l"
	.string "loren hat?\p"
	.string "Das ist ja was! Wenn wir auch so clevere\n"
	.string "POKéMON hätten…\p"
	.string "Dann könnten wir alles wiederfinden,\n"
	.string "was unsere Gäste verloren haben.$"
	.endif
	.endif

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.ifdef ENGLISH
	.string "Oh, sorry, sorry!\n"
	.string "I was too involved in watching TV!\p"
	.string "I heard that someone busted\n"
	.string "the TEAM AQUA HIDEOUT.\p"
	.string "Thanks to that, we just booked\n"
	.string "a reservation from a big group.\p"
	.string "It was a company called… Uh…\n"
	.string "GAME something…$"
	.else
	.ifdef GERMAN
	.string "Oh, tut mir Leid, tut mir Leid!\n"
	.string "Ich habe so konzentriert ferngesehen!\p"
	.string "Ich habe gehört, dass jemand das VER-\n"
	.string "STECK von TEAM AQUA auffliegen ließ.\p"
	.string "Gut! Dadurch haben wir endlich Gäste.\n"
	.string "Eine ganze Gruppe hat reserviert!\p"
	.string "Das sind Angestellte einer Firma… Äh…\n"
	.string "GAME irgendwas…$"
	.endif
	.endif

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.ifdef ENGLISH
	.string "Amazing! A house-sitting POKéMON\n"
	.string "caught a burglar?\p"
	.string "That's something. If we had a tough\n"
	.string "POKéMON as a security guard…\p"
	.string "We would be able to provide our guests\n"
	.string "with greater safety.$"
	.else
	.ifdef GERMAN
	.string "Irre! Ein POKéMON, das das Haus be-\n"
	.string "wachte, hat Einbrecher geschnappt?\p"
	.string "Klasse! Wir sollten auch über einen\n"
	.string "Wachschutz durch POKéMON nachdenken.\p"
	.string "Dadurch könnten wir unseren Gästen\n"
	.string "viel mehr Sicherheit bieten.$"
	.endif
	.endif

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.ifdef ENGLISH
	.string "Oh, sorry, sorry!\n"
	.string "I was too involved in watching TV.\p"
	.string "Oh, yes. A big group of guests arrived\n"
	.string "a little while ago.\p"
	.string "They booked in as GAME FREAK,\n"
	.string "so I guess they must make games.\p"
	.string "Uh-oh, I'd better get working on\n"
	.string "their dinner!$"
	.else
	.ifdef GERMAN
	.string "Oh, tut mir Leid, tut mir Leid!\n"
	.string "Ich habe so konzentriert ferngesehen!\p"
	.string "Oh, ja. Eine große Gruppe von Gästen\n"
	.string "ist vor kurzem hier eingetroffen.\p"
	.string "Sie haben sich als GAME FREAK einge-\n"
	.string "tragen. Ich denke, sie entwickeln\l"
	.string "Spiele.\p"
	.string "Oh oh, ich sollte mich besser um ihr\n"
	.string "Abendessen kümmern!$"
	.endif
	.endif

