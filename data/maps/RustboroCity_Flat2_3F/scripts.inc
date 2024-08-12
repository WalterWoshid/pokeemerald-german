RustboroCity_Flat2_3F_MapScripts::
	.byte 0

RustboroCity_Flat2_3F_EventScript_DevonEmployee::
	msgbox RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_EventScript_Woman::
	msgbox RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones:
	.ifdef ENGLISH
	.string "DEVON's PRESIDENT likes to collect\n"
	.string "rare stones.$"
	.else
	.ifdef GERMAN
	.string "Der PRÄSIDENT von DEVON sammelt\n"
	.string "leidenschaftlich gerne seltene Steine.$"
	.endif
	.endif

RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones:
	.ifdef ENGLISH
	.string "I think the PRESIDENT's son also\n"
	.string "collects rare stones.$"
	.else
	.ifdef GERMAN
	.string "Ich glaube, der Sohn des PRÄSIDENTen\n"
	.string "sammelt auch seltene Steine.$"
	.endif
	.endif

