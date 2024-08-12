BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.ifdef ENGLISH
	.string "Ehehe!\n"
	.string "I can tell what POKéMON are thinking!\p"
	.string "Please!\n"
	.string "Can I see your POKéMON?$"
	.else
	.ifdef GERMAN
	.string "Hihihi! Ich kann die Gedanken\n"
	.string "von POKéMON lesen!\p"
	.string "Bitte! Darf ich deine POKéMON mal\n"
	.string "sehen? Bitte, bitte, bitte, bitte…$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.ifdef ENGLISH
	.string "Boo!\n"
	.string "Cheapie!$"
	.else
	.ifdef GERMAN
	.string "Booh!\n"
	.string "Fiesling!$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlHardy::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "It will battle even if it has a lot\l"
	.string "of ouchies!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses hier sagt, es liebt Kämpfe!\n"
	.string "Es wird sogar kämpfen, wenn es\l"
	.string "ganz viele Autschies hat!$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlLonely::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will hit back!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses hier liebt es, sich anzu-\n"
	.string "schleichen. Tut ihm aber zu viel weh,\l"
	.string "dann wird es sich wehren.$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlBrave::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will worry about itself!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses hier sagt, dass es Kämpfe mag.\n"
	.string "Tut es sich im Kampf sehr weh, wird\l"
	.string "es sich um sich selbst kümmern.$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlAdamant::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "It will battle even if it has a lot\l"
	.string "of ouchies!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses hier sagt, es liebt Kämpfe!\n"
	.string "Es wird sogar kämpfen, wenn es\l"
	.string "ganz viele Autschies hat!$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlNaughty::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will hit back!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses hier passt auf sich selbst auf!\n"
	.string "Wenn es genug Autschies hat, dann wird\l"
	.string "es sich auch wehren.$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlBold::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will worry about itself!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses hier liebt es, heimtückisch\n"
	.string "zu sein. Tut es sich im Kampf sehr\l"
	.string "weh, kümmert es sich um sich selbst.$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "It will battle even if it has a lot\l"
	.string "of ouchies!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses hier sagt, es liebt Kämpfe!\n"
	.string "Es wird sogar kämpfen, wenn es\l"
	.string "ganz viele Autschies hat!$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlRelaxed::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will hit back!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses hier liebt es, sich anzu-\n"
	.string "schleichen. Tut ihm aber zu viel weh,\l"
	.string "dann wird es sich wehren.$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlImpish::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will worry about itself!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses hier sagt, dass es Kämpfe mag.\n"
	.string "Tut es sich im Kampf sehr weh, wird\l"
	.string "es sich um sich selbst kümmern.$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlLax::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "It says it likes to be sneaky even\l"
	.string "if it has a lot of ouchies!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses hier liebt es, heimtückisch\n"
	.string "zu sein. Auch wenn es ganz viele\l"
	.string "Autschies hat, wird es das tun.$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlTimid::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will turn sneaky!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses hier sagt, es liebt Kämpfe!\n"
	.string "Aber wenn es genug Autschies hat, wird\l"
	.string "es heimtückisch.$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlHasty::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "It will battle even if it has a lot\l"
	.string "of ouchies!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses hier sagt, es liebt Kämpfe!\n"
	.string "Es wird sogar kämpfen, wenn es\l"
	.string "ganz viele Autschies hat!$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlSerious::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "It says it likes to be sneaky even\l"
	.string "if it has a lot of ouchies!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses hier liebt es, sich anzu-\n"
	.string "schleichen. Auch wenn es ganz viele\l"
	.string "Autschies hat, wird es das tun.$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlJolly::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will worry about itself!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses hier liebt es, heimtückisch\n"
	.string "zu sein. Tut es sich im Kampf sehr\l"
	.string "weh, kümmert es sich um sich selbst.$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlModest::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "It says it worries about itself whether\l"
	.string "or not it has a lot of ouchies!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses kümmert sich um sich selbst.\n"
	.string "Egal, ob es Autschies hat oder nicht.$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlMild::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will turn sneaky!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses passt auf sich selbst auf. Hat\n"
	.string "es genug Autschies, wird es\l"
	.string "heimtückisch.$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlBashful::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "It says it worries about itself even\l"
	.string "if it has a lot of ouchies!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses kümmert sich um sich selbst.\n"
	.string "Auch wenn es ganz viele Autschies hat.$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlRash::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "It says it likes to be sneaky even\l"
	.string "if it has a lot of ouchies!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses hier liebt es, heimtückisch\n"
	.string "zu sein. Auch wenn es ganz viele\l"
	.string "Autschies hat, wird es das tun.$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlCalm::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "It says it worries about itself even\l"
	.string "if it has a lot of ouchies!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses kümmert sich um sich selbst.\n"
	.string "Auch wenn es ganz viele Autschies hat.$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlGentle::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will hit back!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses kümmert sich um sich selbst.\n"
	.string "Aber wenn es genug Autschies hat, wird\l"
	.string "es sich wehren!$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlSassy::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will turn sneaky!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses hier sagt, es liebt Kämpfe!\n"
	.string "Aber wenn es genug Autschies hat, wird\l"
	.string "es heimtückisch.$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlCareful::
	.ifdef ENGLISH
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will turn sneaky!$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Dieses passt auf sich selbst auf. Hat\n"
	.string "es genug Autschies, wird es\l"
	.string "heimtückisch.$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.ifdef ENGLISH
	.string "That's silly! An EGG is asleep!\n"
	.string "I can't talk to it!$"
	.else
	.ifdef GERMAN
	.string "Du bist komisch! Das ist ein EI. Das\n"
	.string "schläft doch! Wie soll ich damit reden?!$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.ifdef ENGLISH
	.string "How charming!\n"
	.string "That little lady claims she can\l"
	.string "understand POKéMON!$"
	.else
	.ifdef GERMAN
	.string "Wie charmant!\n"
	.string "Diese kleine Dame hier behauptet, sie\l"
	.string "könne die POKéMON verstehen!$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.ifdef ENGLISH
	.string "I have this feeling that the little girl\n"
	.string "is saying something profound.$"
	.else
	.ifdef GERMAN
	.string "Ich habe das Gefühl, dies kleine\n"
	.string "Mädchen sagt profunde Dinge!$"
	.endif
	.endif

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.ifdef ENGLISH
	.string "I know something!\p"
	.string "That little girl plays at the red house\n"
	.string "a lot!$"
	.else
	.ifdef GERMAN
	.string "Ich weiß was! Ich weiß was!\p"
	.string "Das kleine Mädchen spielt ganz oft\n"
	.string "im roten Haus!$"
	.endif
	.endif

