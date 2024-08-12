VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.ifdef ENGLISH
	.string "The thought that I'm getting closer to\n"
	.string "the POKéMON LEAGUE…\p"
	.string "I'm getting stage fright…$"
	.else
	.ifdef GERMAN
	.string "Der Gedanke, dass ich der POKéMON LIGA\n"
	.string "immer näher komme…\p"
	.string "Ich bekomme Lampenfieber…$"
	.endif
	.endif

VictoryRoad_B1F_Text_SamuelDefeat:
	.ifdef ENGLISH
	.string "I couldn't do a thing…$"
	.else
	.ifdef GERMAN
	.string "Ich konnte gar nichts machen…$"
	.endif
	.endif

VictoryRoad_B1F_Text_SamuelPostBattle:
	.ifdef ENGLISH
	.string "The POKéMON LEAGUE became distant\n"
	.string "again… What a letdown…$"
	.else
	.ifdef GERMAN
	.string "Die POKéMON LIGA rückt in weite Ferne…\n"
	.string "Was für eine Enttäuschung…$"
	.endif
	.endif

VictoryRoad_B1F_Text_ShannonIntro:
	.ifdef ENGLISH
	.string "To win your way through the POKéMON\n"
	.string "LEAGUE, you need the trust of your\l"
	.string "POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Um dich siegreich durch die POKéMON\n"
	.string "LIGA zu kämpfen, brauchst du das\l"
	.string "Vertrauen deiner POKéMON.$"
	.endif
	.endif

VictoryRoad_B1F_Text_ShannonDefeat:
	.ifdef ENGLISH
	.string "Your relationship is based on\n"
	.string "solid trust.$"
	.else
	.ifdef GERMAN
	.string "Eure Beziehung ist auf solidem\n"
	.string "Vertrauen aufgebaut.$"
	.endif
	.endif

VictoryRoad_B1F_Text_ShannonPostBattle:
	.ifdef ENGLISH
	.string "By being together all the time, trust\n"
	.string "grows between POKéMON and TRAINERS.$"
	.else
	.ifdef GERMAN
	.string "Das Vertrauen zwischen POKéMON und\n"
	.string "TRAINER wächst beständig, da sie immer\l"
	.string "zusammen sind.$"
	.endif
	.endif

VictoryRoad_B1F_Text_MichelleIntro:
	.ifdef ENGLISH
	.string "This isn't the goal. It's only a place\n"
	.string "on the way to the POKéMON LEAGUE.$"
	.else
	.ifdef GERMAN
	.string "Das ist nicht das Ziel. Nur eine\n"
	.string "Zwischenstation auf dem Weg zur\l"
	.string "POKéMON LIGA.$"
	.endif
	.endif

VictoryRoad_B1F_Text_MichelleDefeat:
	.ifdef ENGLISH
	.string "That's the way!$"
	.else
	.ifdef GERMAN
	.string "Das ist der Weg!$"
	.endif
	.endif

VictoryRoad_B1F_Text_MichellePostBattle:
	.ifdef ENGLISH
	.string "You'll do fine, for sure!\n"
	.string "Your POKéMON are all eager to go!$"
	.else
	.ifdef GERMAN
	.string "Du wirst dich sehr gut schlagen, das ist\n"
	.string "sicher. Deine POKéMON lieben dich!$"
	.endif
	.endif

VictoryRoad_B1F_Text_MitchellIntro:
	.ifdef ENGLISH
	.string "My POKéMON are cosmically\n"
	.string "awe inspiring!$"
	.else
	.ifdef GERMAN
	.string "Meine POKéMON sind einfach kosmisch!\n"
	.string "Beeindruckend und inspirierend.$"
	.endif
	.endif

VictoryRoad_B1F_Text_MitchellDefeat:
	.ifdef ENGLISH
	.string "I've never met anyone like you before.$"
	.else
	.ifdef GERMAN
	.string "Jemanden wie dich habe ich noch nie\n"
	.string "getroffen.$"
	.endif
	.endif

VictoryRoad_B1F_Text_MitchellPostBattle:
	.ifdef ENGLISH
	.string "Even outside of battle, I sense\n"
	.string "incredible power emanating from you\l"
	.string "and your POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Auch außerhalb eines Kampfes spüre\n"
	.string "ich die Kraft, die von dir und deinen\l"
	.string "POKéMON ausgeht.$"
	.endif
	.endif

VictoryRoad_B1F_Text_HalleIntro:
	.ifdef ENGLISH
	.string "Okay, no need to get your back up!\n"
	.string "Relax, let's take it easy!$"
	.else
	.ifdef GERMAN
	.string "Du brauchst dich nicht gleich in Pose\n"
	.string "zu schmeißen! Bleib ganz ruhig.$"
	.endif
	.endif

VictoryRoad_B1F_Text_HalleDefeat:
	.ifdef ENGLISH
	.string "Whoa!\n"
	.string "Wonderful!$"
	.else
	.ifdef GERMAN
	.string "Whoa!\n"
	.string "Wunderbar!$"
	.endif
	.endif

VictoryRoad_B1F_Text_HallePostBattle:
	.ifdef ENGLISH
	.string "Sure, this is VICTORY ROAD.\p"
	.string "But it's not all that different from\n"
	.string "the path you've taken so far.\p"
	.string "Try to enjoy things the rest of\n"
	.string "the way!$"
	.else
	.ifdef GERMAN
	.string "Sicher, dies ist die SIEGESSTRASSE.\p"
	.string "Aber sie unterscheidet sich nicht viel\n"
	.string "von dem Weg, den du bisher gegangen\l"
	.string "bist.\p"
	.string "Versuch, den Rest des Weges zu\n"
	.string "genießen.$"
	.endif
	.endif

