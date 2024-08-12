BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
	.ifdef ENGLISH
	.string "I wonder if they'll be airing interviews\n"
	.string "with tough TRAINERS today?$"
	.else
	.ifdef GERMAN
	.string "Ich frage mich, ob sie heute Interviews\n"
	.string "mit starken TRAINERn ausstrahlen!$"
	.endif
	.endif

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.ifdef ENGLISH
	.string "If I opened a restaurant here,\n"
	.string "it'd make money for sure.$"
	.else
	.ifdef GERMAN
	.string "Wenn ich hier ein Restaurant eröffnen\n"
	.string "würde, würde meine Kasse klingeln!$"
	.endif
	.endif

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
	.ifdef ENGLISH
	.string "Whew…\p"
	.string "I need to take a breather after\n"
	.string "some intense battles…\p"
	.string "But even now, I never take a break\n"
	.string "from plotting strategy and combos.$"
	.else
	.ifdef GERMAN
	.string "Huuuh…\p"
	.string "Nach solch anstrengenden Kämpfen\n"
	.string "brauche ich eine Verschnaufpause…\p"
	.string "Aber auch in Pausen denke ich über neue\n"
	.string "Strategien und Combos nach!$"
	.endif
	.endif

