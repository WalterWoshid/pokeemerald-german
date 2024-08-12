BattleFrontier_RankingHall_MapScripts::
	.byte 0

BattleFrontier_RankingHall_EventScript_TowerSinglesRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_SINGLES
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_TowerDoublesRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_DOUBLES
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_TowerMultisRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_MULTIS
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_TowerLinkRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_LINK
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_ArenaRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_ARENA
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_PalaceRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PALACE
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_FactoryRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_FACTORY
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_DomeRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_DOME
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_PikeRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PIKE
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_PyramidRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PYRAMID
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_ShowRecords::
	special ShowRankingHallRecordsWindow
	waitbuttonpress
	special ScrollRankingHallRecordsWindow
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_RankingHall_EventScript_Attendant::
	msgbox BattleFrontier_RankingHall_Text_ExplainRankingHall, MSGBOX_NPC
	end

BattleFrontier_RankingHall_EventScript_DomePikeFactoryRecordsSign::
	msgbox BattleFrontier_RankingHall_Text_DomePikeFactoryRecords, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_PalaceArenaPyramidRecordsSIgn::
	msgbox BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_NinjaBoy::
	lock
	faceplayer
	msgbox BattleFrontier_RankingHall_Text_IsYourNameOnThisList, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleFrontier_RankingHall_EventScript_NinjaBoyNameOnList
	msgbox BattleFrontier_RankingHall_Text_WorkHarderIfYouSawFriendsName, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_NinjaBoyNameOnList::
	msgbox BattleFrontier_RankingHall_Text_WowThatsSuper, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_Boy::
	msgbox BattleFrontier_RankingHall_Text_MyNamesNotUpThere, MSGBOX_NPC
	end

BattleFrontier_RankingHall_Text_ExplainRankingHall:
	.ifdef ENGLISH
	.string "This is the RANKING HALL.\p"
	.string "This is where we recognize the immortal\n"
	.string "TRAINERS who left great records in\l"
	.string "BATTLE FRONTIER events.$"
	.else
	.ifdef GERMAN
	.string "Dies ist die ERGEBNISHALLE.\n"
	.string "Hier sind die Namen der TRAINER\p"
	.string "verewigt, die sich durch ihre Ergebnisse\n"
	.string "bei den KAMPFZONEn-Kämpfen\l"
	.string "unsterblich gemacht haben.$"
	.endif
	.endif

BattleFrontier_RankingHall_Text_DomePikeFactoryRecords:
	.ifdef ENGLISH
	.string "BATTLE DOME, BATTLE PIKE,\n"
	.string "and BATTLE FACTORY Records$"
	.else
	.ifdef GERMAN
	.string "Ergebnisse: KAMPFSTADION, KAMPFIPITIS\n"
	.string "und KAMPFFABRIK$"
	.endif
	.endif

BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords:
	.ifdef ENGLISH
	.string "BATTLE PALACE, BATTLE ARENA,\n"
	.string "and BATTLE PYRAMID Records$"
	.else
	.ifdef GERMAN
	.string "Ergebnisse: KAMPFPALAST, KAMPF-\n"
	.string "RING und KAMPFPYRAMIDE$"
	.endif
	.endif

BattleFrontier_RankingHall_Text_IsYourNameOnThisList:
	.ifdef ENGLISH
	.string "Hi, is your name on this list?$"
	.else
	.ifdef GERMAN
	.string "Hallo. Steht dein Name auch auf der\n"
	.string "Liste?$"
	.endif
	.endif

BattleFrontier_RankingHall_Text_WowThatsSuper:
	.ifdef ENGLISH
	.string "Wow, that's super!\n"
	.string "I'll have to try harder, too!$"
	.else
	.ifdef GERMAN
	.string "Wow, das ist ja super!!!\n"
	.string "Ich werde mich auch anstrengen!$"
	.endif
	.endif

BattleFrontier_RankingHall_Text_WorkHarderIfYouSawFriendsName:
	.ifdef ENGLISH
	.string "Oh, is that right?\p"
	.string "If you saw your friend's name up here,\n"
	.string "I bet it would make you work harder!$"
	.else
	.ifdef GERMAN
	.string "Wirklich?\n"
	.string "Wenn du die Namen deiner Freunde hier\p"
	.string "siehst, strengst du dich bestimmt noch\n"
	.string "mehr an.$"
	.endif
	.endif

BattleFrontier_RankingHall_Text_MyNamesNotUpThere:
	.ifdef ENGLISH
	.string "Hmm…\n"
	.string "My name's not up there…\p"
	.string "Well, it's only natural since I haven't\n"
	.string "taken any challenges yet.$"
	.else
	.ifdef GERMAN
	.string "Hmm…\n"
	.string "Ich kann meinen Namen nicht finden…\p"
	.string "Kein Wunder! Ich habe ja auch noch nie\n"
	.string "an Kämpfen teilgenommen…$"
	.endif
	.endif

