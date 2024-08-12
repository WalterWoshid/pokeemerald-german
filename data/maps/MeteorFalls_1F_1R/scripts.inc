.set LOCALID_MAGMA_GRUNT_1, 5
.set LOCALID_MAGMA_GRUNT_2, 6
.set LOCALID_ARCHIE, 7
.set LOCALID_AQUA_GRUNT_1, 8
.set LOCALID_AQUA_GRUNT_2, 9

MeteorFalls_1F_1R_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
	.byte 0

MeteorFalls_1F_1R_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
	end

MeteorFalls_1F_1R_EventScript_OpenStevensCave::
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, TRUE
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, TRUE
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, FALSE
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, TRUE
	return

MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_WithThisMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_Delay48
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_HoldItRightThereMagma, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	addobject LOCALID_ARCHIE
	addobject LOCALID_AQUA_GRUNT_1
	addobject LOCALID_AQUA_GRUNT_2
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieArrive
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive
	waitmovement 0
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
	applymovement LOCALID_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit
	applymovement LOCALID_MAGMA_GRUNT_2, MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit
	waitmovement 0
	removeobject LOCALID_MAGMA_GRUNT_1
	removeobject LOCALID_MAGMA_GRUNT_2
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieSeenYouBefore, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma, MSGBOX_DEFAULT
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo, MSGBOX_DEFAULT
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieExit
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Exit
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Exit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_AQUA_GRUNT_1
	removeobject LOCALID_AQUA_GRUNT_2
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	setvar VAR_METEOR_FALLS_STATE, 1
	releaseall
	end

MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieArrive:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Exit:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Exit:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay:
	walk_in_place_faster_down
	delay_4
	walk_in_place_faster_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	face_right
	step_end

MeteorFalls_1F_1R_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_MET_PROF_COZMO, MeteorFalls_1F_1R_EventScript_MetCozmo
	setflag FLAG_MET_PROF_COZMO
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_MetCozmo::
	msgbox MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_Text_WithThisMeteorite:
	.ifdef ENGLISH
	.string "Hehehe!\p"
	.string "With this METEORITE, that thing in\n"
	.string "MT. CHIMNEY will…$"
	.else
	.ifdef GERMAN
	.string "Hähähä!\p"
	.string "Mit diesem METEORITen wird das Ding\n"
	.string "am SCHLOTBERG…$"
	.endif
	.endif

MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma:
	.ifdef ENGLISH
	.string "Heh?\p"
	.string "I don't know who you are, but if you get\n"
	.string "in the way of TEAM MAGMA, don't\l"
	.string "expect any mercy!$"
	.else
	.ifdef GERMAN
	.string "Häh?\p"
	.string "Ich weiß zwar nicht, wer du bist. Aber\n"
	.string "wenn du dich TEAM MAGMA in den Weg\l"
	.string "stellst, erwarte keine Gnade!$"
	.endif
	.endif

MeteorFalls_1F_1R_Text_HoldItRightThereMagma:
	.ifdef ENGLISH
	.string "Hold it right there, TEAM MAGMA!\p"
	.string "You're badly mistaken if you think you\n"
	.string "can have your way with the world!$"
	.else
	.ifdef GERMAN
	.string "Bleibt sofort stehen, TEAM MAGMA!\p"
	.string "Ihr irrt euch gewaltig, wenn ihr meint,\n"
	.string "ihr könntet mit der Welt machen, was ihr\l"
	.string "wollt!$"
	.endif
	.endif

MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua:
	.ifdef ENGLISH
	.string "Hehehe!\n"
	.string "Even TEAM AQUA joins us!\p"
	.string "But it's too much trouble to deal with\n"
	.string "you all…\p"
	.string "Heh, it doesn't matter!\p"
	.string "We've got the METEORITE, so off to\n"
	.string "MT. CHIMNEY we go!\p"
	.string "Hehehe! Be seeing you, you TEAM\n"
	.string "AQUA dingbats!$"
	.else
	.ifdef GERMAN
	.string "Hähähä!\n"
	.string "Sogar TEAM AQUA leistet uns\l"
	.string "Gesellschaft!\p"
	.string "Aber es ist viel zu anstrengend, sich\n"
	.string "mit allen auseinander zu setzen…\p"
	.string "Hey, das spielt auch keine Rolle!\p"
	.string "Wir haben den METEORITen und so\n"
	.string "machen wir uns auf zum SCHLOTBERG!\p"
	.string "Hähähä! Wir sehen uns, ihr Würstchen\n"
	.string "von TEAM AQUA!$"
	.endif
	.endif

MeteorFalls_1F_1R_Text_ArchieSeenYouBefore:
	.ifdef ENGLISH
	.string "ARCHIE: Didn't I see you before?\n"
	.string "At SLATEPORT's MUSEUM?\p"
	.string "Ah, so your name is {PLAYER}.\p"
	.string "At the time, I thought you were one\n"
	.string "of TEAM MAGMA's goons.\p"
	.string "Humph…\n"
	.string "You're one odd kid.\p"
	.string "TEAM MAGMA is a dangerous group of\n"
	.string "total fanatics.\p"
	.string "They engage in destruction, claiming\n"
	.string "to expand the land mass.\p"
	.string "They are the rivals to us,\n"
	.string "the sea-loving TEAM AQUA!$"
	.else
	.ifdef GERMAN
	.string "ADRIAN: Dich kenne ich doch!\n"
	.string "Vom MUSEUM in GRAPHITPORT.\p"
	.string "Ah, du bist {PLAYER}.\p"
	.string "Damals dachte ich, du würdest zu\n"
	.string "TEAM MAGMA gehören.\p"
	.string "Hmpf…\n"
	.string "Du bist ein merkwürdiges Kind.\p"
	.string "TEAM MAGMA besteht aus Fanatikern.\p"
	.string "Sie zerstören alles und behaupten,\n"
	.string "die Landmasse vergrößern zu wollen.\p"
	.string "Wir, TEAM AQUA, lieben das Meer über\n"
	.string "alles. TEAM MAGMA ist unser Erzfeind!$"
	.endif
	.endif

MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma:
	.ifdef ENGLISH
	.string "BOSS, we should give chase to\n"
	.string "TEAM MAGMA…$"
	.else
	.ifdef GERMAN
	.string "BOSS, wir sollten TEAM MAGMA\n"
	.string "verfolgen…$"
	.endif
	.endif

MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo:
	.ifdef ENGLISH
	.string "ARCHIE: Yes, yes, we must!\n"
	.string "We've got to hurry.\p"
	.string "There's no telling what TEAM MAGMA\n"
	.string "will do at MT. CHIMNEY!$"
	.else
	.ifdef GERMAN
	.string "ADRIAN: Ja, ja. Das müssen wir!\n"
	.string "Wir müssen uns beeilen.\p"
	.string "Nicht auszudenken, was TEAM MAGMA am\n"
	.string "SCHLOTBERG anrichten will!$"
	.endif
	.endif

MeteorFalls_1F_1R_Text_ArchieFarewell:
	.ifdef ENGLISH
	.string "ARCHIE: {PLAYER}, you should keep\n"
	.string "an eye out for TEAM MAGMA, too.\p"
	.string "Farewell!$"
	.else
	.ifdef GERMAN
	.string "ADRIAN: {PLAYER}, du solltest\n"
	.string "TEAM MAGMA im Auge behalten.\p"
	.string "Leb wohl!$"
	.endif
	.endif

MeteorFalls_1F_1R_Text_MeetProfCozmo:
	.ifdef ENGLISH
	.string "I… I'm COZMO…\n"
	.string "I'm a PROFESSOR…\p"
	.string "TEAM MAGMA asked me to guide them\n"
	.string "to METEOR FALLS…\p"
	.string "But they tricked me.\n"
	.string "They even took my METEORITE away…\p"
	.string "And then another similar bunch,\n"
	.string "TEAM AQUA showed up.\p"
	.string "After that…\n"
	.string "I don't understand any of it.\p"
	.string "But that TEAM MAGMA…\p"
	.string "What are they going to do with that\n"
	.string "METEORITE at MT. CHIMNEY?$"
	.else
	.ifdef GERMAN
	.string "Ich… Ich bin KOSMO…\n"
	.string "Ich bin Professor…\p"
	.string "Einige Typen von TEAM MAGMA haben\n"
	.string "mich überredet, sie zu METEOR-\l"
	.string "FÄLLE zu führen…\p"
	.string "Sie haben mich hereingelegt.\n"
	.string "Sie haben sogar den METEORITen\l"
	.string "mitgenommen…\p"
	.string "Und dann tauchte TEAM AQUA auf. Die\n"
	.string "sind auch nicht anders.\p"
	.string "Und ich?\n"
	.string "Ich verstehe absolut nicht, was los ist.\p"
	.string "TEAM MAGMA…\p"
	.string "Was haben sie mit dem METEORITen am\n"
	.string "SCHLOTBERG vor?$"
	.endif
	.endif

MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney:
	.ifdef ENGLISH
	.string "PROF. COZMO: But that TEAM MAGMA…\p"
	.string "What are they going to do with that\n"
	.string "METEORITE at MT. CHIMNEY?$"
	.else
	.ifdef GERMAN
	.string "PROF. KOSMO: Dieses TEAM MAGMA…\p"
	.string "Was haben sie mit dem METEORITen am\n"
	.string "SCHLOTBERG vor?$"
	.endif
	.endif
