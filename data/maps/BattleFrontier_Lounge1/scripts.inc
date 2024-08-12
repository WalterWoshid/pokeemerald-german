BattleFrontier_Lounge1_MapScripts::
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder::
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_EventScript_BreederIntro::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder::
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
	special BufferVarsForIVRater
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs       @ Average of 15
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs @ Average of 20
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs         @ Average of 25
	goto_if_ge VAR_0x8005, 151, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs     @ Average of > 25
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder::
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat::
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue::
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments::
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP::
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow::
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid::
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh::
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax::
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect::
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro:
	.ifdef ENGLISH
	.string "For 70 years I have raised POKéMON!\n"
	.string "I am the man they revere as\l"
	.string "the legendary top POKéMON BREEDER!\p"
	.string "If you ever become as seasoned as me,\n"
	.string "you'll see the abilities of POKéMON\l"
	.string "at a glance.\p"
	.string "You're a TRAINER. Doesn't it interest\n"
	.string "you to know your own POKéMON's\l"
	.string "abilities?\p"
	.string "Here!\n"
	.string "Let's have a look at your POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Seit 70 Jahren ziehe ich POKéMON auf!\n"
	.string "Ich bin derjenige, den alle nur den\l"
	.string "legendären PKMN-ZÜCHTER nennen!\p"
	.string "Ein Mensch mit meiner Erfahrung\n"
	.string "erkennt die Fähigkeiten eines POKéMON\l"
	.string "mit einem Blick.\p"
	.string "Du bist ein TRAINER. Interessiert es\n"
	.string "dich nicht, welche Fähigkeiten deine\l"
	.string "POKéMON besitzen?\p"
	.string "Komm! Lass mich einen Blick auf deine\n"
	.string "POKéMON werfen!$"
	.endif
	.endif

BattleFrontier_Lounge1_Text_AverageAbility:
	.ifdef ENGLISH
	.string "…Hmm…\p"
	.string "This one, overall, I would describe\n"
	.string "as being of average ability.$"
	.else
	.ifdef GERMAN
	.string "Hmm… …\p"
	.string "Bei diesem hier erkenne ich\n"
	.string "durchschnittliche Fähigkeiten.$"
	.endif
	.endif

BattleFrontier_Lounge1_Text_BetterThanAverageAbility:
	.ifdef ENGLISH
	.string "…Hmm…\p"
	.string "This one, overall, I would describe as\n"
	.string "having better-than-average ability.$"
	.else
	.ifdef GERMAN
	.string "Hmm… …\p"
	.string "Bei diesem hier erkenne ich über-\n"
	.string "durchschnittliche Fähigkeiten.$"
	.endif
	.endif

BattleFrontier_Lounge1_Text_ImpressiveAbility:
	.ifdef ENGLISH
	.string "…Hmm…\p"
	.string "This one, overall, I would say is\n"
	.string "quite impressive in ability!$"
	.else
	.ifdef GERMAN
	.string "Hmm… …\p"
	.string "Bei diesem hier erkenne ich\n"
	.string "beeindruckende Fähigkeiten.$"
	.endif
	.endif

BattleFrontier_Lounge1_Text_OutstandingAbility:
	.ifdef ENGLISH
	.string "…Hmm…\p"
	.string "This one, overall, I would say is\n"
	.string "wonderfully outstanding in ability!$"
	.else
	.ifdef GERMAN
	.string "Hmm… …\p"
	.string "Bei diesem hier erkenne ich\n"
	.string "herausragende Fähigkeiten.$"
	.endif
	.endif

BattleFrontier_Lounge1_Text_BestAspectHP:
	.ifdef ENGLISH
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its HP…$"
	.else
	.ifdef GERMAN
	.string "Meiner Meinung nach liegt seine Stärke\n"
	.string "in seinen KP…$"
	.endif
	.endif

BattleFrontier_Lounge1_Text_BestAspectAtk:
	.ifdef ENGLISH
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its ATTACK…$"
	.else
	.ifdef GERMAN
	.string "Meiner Meinung nach liegt seine Stärke\n"
	.string "in seinem ANGRIFF…$"
	.endif
	.endif

BattleFrontier_Lounge1_Text_BestAspectDef:
	.ifdef ENGLISH
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its DEFENSE…$"
	.else
	.ifdef GERMAN
	.string "Meiner Meinung nach liegt seine Stärke\n"
	.string "in seiner VERTEIDIGUNG…$"
	.endif
	.endif

BattleFrontier_Lounge1_Text_BestAspectSpAtk:
	.ifdef ENGLISH
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its SPECIAL ATTACK…$"
	.else
	.ifdef GERMAN
	.string "Meiner Meinung nach liegt seine Stärke\n"
	.string "in seinem SPEZIAL-ANGRIFF…$"
	.endif
	.endif

BattleFrontier_Lounge1_Text_BestAspectSpDef:
	.ifdef ENGLISH
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its SPECIAL DEFENSE…$"
	.else
	.ifdef GERMAN
	.string "Meiner Meinung nach liegt seine Stärke\n"
	.string "in seiner SPEZIAL-VERTEIDIGUNG…$"
	.endif
	.endif

BattleFrontier_Lounge1_Text_BestAspectSpeed:
	.ifdef ENGLISH
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its SPEED…$"
	.else
	.ifdef GERMAN
	.string "Meiner Meinung nach liegt seine Stärke\n"
	.string "in seiner INITIATIVE…$"
	.endif
	.endif

BattleFrontier_Lounge1_Text_StatRelativelyGood:
	.ifdef ENGLISH
	.string "That stat is relatively good.\n"
	.string "…Hm… That's how I call it.$"
	.else
	.ifdef GERMAN
	.string "Sein Status ist relativ gut.\n"
	.string "Hm… Genauso würde ich es ausdrücken.$"
	.endif
	.endif

BattleFrontier_Lounge1_Text_StatImpressive:
	.ifdef ENGLISH
	.string "That stat is quite impressive.\n"
	.string "…Hm… That's how I call it.$"
	.else
	.ifdef GERMAN
	.string "Sein Status ist beeindruckend.\n"
	.string "Hm… Genauso würde ich es ausdrücken.$"
	.endif
	.endif

BattleFrontier_Lounge1_Text_StatOutstanding:
	.ifdef ENGLISH
	.string "That stat is outstanding!\n"
	.string "…Hm… That's how I call it.$"
	.else
	.ifdef GERMAN
	.string "Sein Status ist herausragend.\n"
	.string "Hm… Genauso würde ich es ausdrücken.$"
	.endif
	.endif

BattleFrontier_Lounge1_Text_StatFlawless:
	.ifdef ENGLISH
	.string "It's flawless! A thing of perfection!\n"
	.string "…Hm… That's how I call it.$"
	.else
	.ifdef GERMAN
	.string "Dies ist makellos! Einfach perfekt!\n"
	.string "Hm… Genauso würde ich es ausdrücken.$"
	.endif
	.endif

BattleFrontier_Lounge1_Text_NoTimeForMyAdvice:
	.ifdef ENGLISH
	.string "What?\n"
	.string "You have no time for my advice?\p"
	.string "You should always be eager to learn\n"
	.string "from the experiences of your elders!$"
	.else
	.ifdef GERMAN
	.string "Was? Du hast keine Zeit,\n"
	.string "meinen Rat zu hören?\p"
	.string "Du solltest dir immer die Zeit nehmen,\n"
	.string "von den Alten zu lernen.$"
	.endif
	.endif

@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending:
	.ifdef ENGLISH
	.string "Yes, what is it now?\p"
	.string "I have business that needs tending!\n"
	.string "Save it for next time!$"
	.else
	.ifdef GERMAN
	.string "Yes, what is it now?\p"
	.string "I have business that needs tending!\n"
	.string "Save it for next time!$"
	.endif
	.endif

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon:
	.ifdef ENGLISH
	.string "Ah, youngster! Do your POKéMON's\n"
	.string "abilities intrigue you?\p"
	.string "Here, here!\n"
	.string "Let's have a look at your POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Ah, ein junges Gesicht! Interessieren\n"
	.string "dich die Fähigkeiten deiner POKéMON?\p"
	.string "Dann komm! Lass uns einen Blick\n"
	.string "auf deine POKéMON werfen.$"
	.endif
	.endif

BattleFrontier_Lounge1_Text_EvenICantTell:
	.ifdef ENGLISH
	.string "An expert I am, but even I can't tell\n"
	.string "anything about an unhatched POKéMON!\p"
	.string "Show me a POKéMON!\n"
	.string "A POKéMON is what I need to see!$"
	.else
	.ifdef GERMAN
	.string "Ich bin zwar ein Experte, aber auch ich\n"
	.string "bin nicht in der Lage, etwas zu einem\l"
	.string "ungeschlüpften POKéMON zu sagen.\p"
	.string "Zeig mir ein POKéMON!\n"
	.string "Ich muss nur einen Blick drauf werfen.$"
	.endif
	.endif

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding:
	.ifdef ENGLISH
	.string "He said my POKéMON is outstanding!\n"
	.string "I'm glad I raised it carefully!$"
	.else
	.ifdef GERMAN
	.string "Er hat gesagt, mein POKéMON sei\n"
	.string "herausragend! Ich bin froh, dass ich\l"
	.string "es sorgfältig aufgezogen habe.$"
	.endif
	.endif

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt:
	.ifdef ENGLISH
	.string "He said my POKéMON is outstanding!\n"
	.string "But I didn't do anything special\l"
	.string "raising it…$"
	.else
	.ifdef GERMAN
	.string "Er hat gesagt, mein POKéMON sei\n"
	.string "herausragend! Dabei habe ich gar nichts\l"
	.string "Besonderes bei der Aufzucht gemacht…$"
	.endif
	.endif

