RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.ifdef ENGLISH
	.string "That determined expression…\n"
	.string "That limber way you move…\l"
	.string "And your well-trained POKéMON…\p"
	.string "You're obviously a skilled TRAINER!\p"
	.string "No, wait, don't say a word.\n"
	.string "I can tell just by looking at you.\p"
	.string "I'm sure that you can put this\n"
	.string "HIDDEN MACHINE to good use.\p"
	.string "No need to be modest or shy.\n"
	.string "Go on, take it!$"
	.else
	.ifdef GERMAN
	.string "Diese Entschlossenheit…\n"
	.string "Deine Beweglichkeit…\l"
	.string "Deine Hingabe für POKéMON…\p"
	.string "Du bist wirklich ein talentierter\n"
	.string "TRAINER!\p"
	.string "Nein, warte. Sag jetzt nichts.\n"
	.string "Ich brauche dich nur anzuschauen.\p"
	.string "Ich bin mir sicher, dass du mit dieser\n"
	.string "VM sehr gut umgehen wirst.\p"
	.string "Kein Grund, so schüchtern zu sein.\n"
	.string "Hier, nimm sie!$"
	.endif
	.endif

RustboroCity_CuttersHouse_Text_ExplainCut:
	.ifdef ENGLISH
	.string "That HIDDEN MACHINE, or HM for\n"
	.string "short, is CUT.\p"
	.string "An HM move is one that can be used\n"
	.string "by POKéMON outside of battle.\p"
	.string "Any POKéMON that's learned CUT can\n"
	.string "chop down thin trees if the TRAINER\l"
	.string "has earned the STONE BADGE.\p"
	.string "And, unlike a TM, an HM can be used\n"
	.string "more than once.$"
	.else
	.ifdef GERMAN
	.string "Diese VM, sie enthält ZERSCHNEIDER.\p"
	.string "Eine VM ist eine Attacke, die auch\n"
	.string "außerhalb des Kampfes von einem\l"
	.string "POKéMON angewandt werden kann.\p"
	.string "Jedes POKéMON, das diese Attacke\n"
	.string "gelernt hat, kann Bäume damit\p"
	.string "zerschneiden, wenn der TRAINER den\n"
	.string "STEINORDEN besitzt.\p"
	.string "Und, im Gegensatz zur TM, kann eine VM\n"
	.string "mehrfach gelehrt werden.$"
	.endif
	.endif

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.ifdef ENGLISH
	.string "When they were expanding the city of\n"
	.string "RUSTBORO, my dad helped out.\p"
	.string "He made his POKéMON use CUT to clear\n"
	.string "the land of trees.$"
	.else
	.ifdef GERMAN
	.string "Als sie die Stadt METAROST CITY\n"
	.string "vergrößert haben, hat mein Vater ihnen\l"
	.string "geholfen.\p"
	.string "Seine POKéMON fällten die Bäume mit\n"
	.string "ZERSCHNEIDER.$"
	.endif
	.endif

