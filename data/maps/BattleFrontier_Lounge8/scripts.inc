BattleFrontier_Lounge8_MapScripts::
	.byte 0

BattleFrontier_Lounge8_EventScript_Man::
	msgbox BattleFrontier_Lounge8_Text_WhatATrainerNeeds, MSGBOX_NPC
	end

BattleFrontier_Lounge8_EventScript_Woman::
	msgbox BattleFrontier_Lounge8_Text_KnowAboutFrontierBrains, MSGBOX_NPC
	end

BattleFrontier_Lounge8_EventScript_NinjaBoy::
	msgbox BattleFrontier_Lounge8_Text_ToldMeIHaveTalentForBattling, MSGBOX_NPC
	end

BattleFrontier_Lounge8_Text_WhatATrainerNeeds:
	.ifdef ENGLISH
	.string "What a TRAINER needs…\p"
	.string "Knowledge…\n"
	.string "Strategy…\l"
	.string "Luck…\l"
	.string "Guts…\l"
	.string "Spirit…\l"
	.string "Bravery…\l"
	.string "And ability…\p"
	.string "Well, I'm all set in every way!\n"
	.string "I'll be unstoppable at every building!\p"
	.string "Huh? POKéMON?\n"
	.string "What's that?$"
	.else
	.ifdef GERMAN
	.string "Was braucht ein TRAINER?\p"
	.string "Kenntnis…\n"
	.string "Strategie…\l"
	.string "Ein glückliches Los…\l"
	.string "Einen groben Überblick…\l"
	.string "Seele…\l"
	.string "Bravur…\l"
	.string "Und eine gute Anlage…\p"
	.string "Nun, das bringe ich alles mit!\n"
	.string "Ich werde überall einfach unschlagbar\l"
	.string "sein!\p"
	.string "Was? POKéMON?!?\n"
	.string "Was ist das denn? Kann man das essen?$"
	.endif
	.endif

BattleFrontier_Lounge8_Text_KnowAboutFrontierBrains:
	.ifdef ENGLISH
	.string "Do you know about the FRONTIER\n"
	.string "BRAINS?\p"
	.string "That's what SCOTT calls the seven\n"
	.string "special TRAINERS that run the seven\l"
	.string "facilities in the BATTLE FRONTIER.$"
	.else
	.ifdef GERMAN
	.string "Hast du schon mal was über die\n"
	.string "KAMPFKORYPHÄEN gehört?\p"
	.string "So nennt SCOTT die sieben TRAINER,\n"
	.string "die die sieben Einrichtungen der\l"
	.string "KAMPFZONE leiten.$"
	.endif
	.endif

BattleFrontier_Lounge8_Text_ToldMeIHaveTalentForBattling:
	.ifdef ENGLISH
	.string "At the BATTLE TOWER, an older girl\n"
	.string "told me that I have a lot of talent\l"
	.string "for battling!\p"
	.string "I like POKéMON CONTESTS more!\p"
	.string "But I'm no good at CONTESTS!\p"
	.string "I guess having talent and liking\n"
	.string "something aren't the same.$"
	.else
	.ifdef GERMAN
	.string "Im DUELLTURM hat mir ein älteres\n"
	.string "Mädchen gesagt, dass ich sehr viel\l"
	.string "Talent für’s Kämpfen habe!\p"
	.string "Ich mag aber lieber POKéMON\n"
	.string "WETTBEWERBE!\p"
	.string "Aber bei den WETTBEWERBEn schneide\n"
	.string "ich nie so sonderlich gut ab.\p"
	.string "Ob man auch für etwas Talent haben\n"
	.string "kann, obwohl man was anderes lieber\l"
	.string "mag?$"
	.endif
	.endif

