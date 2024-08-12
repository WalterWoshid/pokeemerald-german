LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	waitstate
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.ifdef ENGLISH
	.string "I'm the GAME DESIGNER.\p"
	.string "Oh, is that right?\n"
	.string "You're working on a POKéDEX?\p"
	.string "It's tough trying to complete it,\n"
	.string "but don't give up.\p"
	.string "If you do complete it, please come\n"
	.string "show me.$"
	.else
	.ifdef GERMAN
	.string "Ich bin der GAME DESIGNER.\p"
	.string "Oh, wirklich?\n"
	.string "Du arbeitest an einem POKéDEX?\p"
	.string "Es ist schwer, ihn zu vervollständigen,\n"
	.string "aber du darfst nicht aufgeben.\p"
	.string "Sobald du ihn vervollständigt hast,\n"
	.string "komm mich wieder besuchen.$"
	.endif
	.endif

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.ifdef ENGLISH
	.string "Wow! That's awesome!\n"
	.string "Yep, it's totally awesome!\p"
	.string "This POKéDEX is completely filled!\n"
	.string "You really must love POKéMON!\p"
	.string "I'm so impressed!\p"
	.string "Let me give you something in\n"
	.string "recognition of your feat!$"
	.else
	.ifdef GERMAN
	.string "Wow! Das ist beeindruckend!\n"
	.string "Wirklich äußerst beeindruckend!\p"
	.string "Dein POKéDEX ist absolut vollständig!\n"
	.string "Du musst die POKéMON wirklich lieben!\p"
	.string "Ich bin echt beeindruckt!\p"
	.string "Ich möchte dir als Zeichen meiner Aner-\n"
	.string "kennung gerne etwas schenken!$"
	.endif
	.endif

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.ifdef ENGLISH
	.string "Me? You're talking to me?\n"
	.string "I'm the PROGRAMMER.\p"
	.string "I wonder what the SLOTS are\n"
	.string "like here.$"
	.else
	.ifdef GERMAN
	.string "Ich? Sprichst du mit mir?\n"
	.string "Ich bin der PROGRAMMIERER.\p"
	.string "Ich frage mich, wie die EINARMIGEN\n"
	.string "BANDITen hier wohl so sind.$"
	.endif
	.endif

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.ifdef ENGLISH
	.string "I'm the GRAPHIC ARTIST! Aren't the\n"
	.string "POKéMON of HOENN interesting?$"
	.else
	.ifdef GERMAN
	.string "Ich bin der GRAPHIC ARTIST! Sind die\n"
	.string "POKéMON in der Region von HOENN\l"
	.string "nicht interessant?$"
	.endif
	.endif

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.ifdef ENGLISH
	.string "The girl TUBERS, they're cute, hey?\n"
	.string "To battle against a cute TUBER…\p"
	.string "Whoop, it's so awesome!\p"
	.string "And the TWINS! Aren't they cute?\n"
	.string "A 2-on-2 battle with TWINS…\p"
	.string "Whoop, it's unbearably fun!$"
	.else
	.ifdef GERMAN
	.string "Die MÄDCHEN mit den SCHWIMMREIFEN\n"
	.string "sind total niedlich, meinst du nicht?\l"
	.string "Ein Kampf gegen so niedliche Mädchen…\p"
	.string "Huuh, das ist vielleicht ein Spaß!\p"
	.string "Und die ZWILLINGE erst! Sind die süß!?!\n"
	.string "Ein 2-gegen-2-Kampf mit ZWILLINGEN…\p"
	.string "Huuh, einfach unglaublicher Spaß!$"
	.endif
	.endif

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.ifdef ENGLISH
	.string "The sea breeze tickles my heart.\n"
	.string "It feels wonderful here!$"
	.else
	.ifdef GERMAN
	.string "Die frische Seebrise berührt mein Herz.\n"
	.string "Es ist einfach wundervoll hier.$"
	.endif
	.endif

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.ifdef ENGLISH
	.string "You never know when and where\n"
	.string "people will challenge you.\p"
	.string "That's why I never leave home without\n"
	.string "my GAME BOY ADVANCE.$"
	.else
	.ifdef GERMAN
	.string "Du kannst nie vorhersagen, wann und wo\n"
	.string "die Leute dich herausfordern.\p"
	.string "Daher gehe ich niemals ohne meinen GAME\n"
	.string "BOY ADVANCE aus dem Haus.$"
	.endif
	.endif

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.ifdef ENGLISH
	.string "SCOTT: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Huh?!\n"
	.string "Oh, sorry, sorry! I was snoozing!\p"
	.string "I came to check out this POKéMON\n"
	.string "CONTEST thing.\p"
	.string "I have to admit, it does look quite\n"
	.string "entertaining, but…\p"
	.string "Consider me a purist--I prefer\n"
	.string "battles and tough TRAINERS.\p"
	.string "But that's just me.\p"
	.string "{PLAYER}{KUN}, I hope you'll enjoy everything\n"
	.string "like the GYMS, CONTESTS, BATTLE TENT,\l"
	.string "the whole works!$"
	.else
	.ifdef GERMAN
	.string "SCOTT: … … … …\n"
	.string "…\l"
	.string "… … … … …\l"
	.string "Zzzzz…\p"
	.string "… … … … …\n"
	.string "Wie?!?\l"
	.string "Oh, tut mir Leid!\l"
	.string "Ich habe ein bisschen gedöst!\p"
	.string "Ich wollte mir mal einen POKéMON\n"
	.string "WETTBEWERB anschauen.\p"
	.string "Das scheint ganz interessant zu sein,\n"
	.string "aber…\p"
	.string "Vielleicht bin ich ja Purist - aber ich\n"
	.string "bevorzuge Kämpfe und starke TRAINER.\p"
	.string "Aber das liegt wohl an mir.\p"
	.string "Ich hoffe du genießt die ARENen,\n"
	.string "WETTBEWERBe, KAMPFCAMPs und all\l"
	.string "die wunderbaren Dinge, {PLAYER}{KUN}!$"
	.endif
	.endif

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.ifdef ENGLISH
	.string "SCOTT: I think it does take strategy\n"
	.string "to win a CONTEST.\p"
	.string "Devising CONTEST strategies is one way\n"
	.string "of becoming a better TRAINER, I'd say.$"
	.else
	.ifdef GERMAN
	.string "SCOTT: Ich denke schon, dass es auf\n"
	.string "Strategie ankommt, um einen WETTBEWERB\l"
	.string "zu gewinnen.\p"
	.string "Sich eine Strategie auszudenken ist\n"
	.string "nur ein Weg, ein guter TRAINER zu\l"
	.string "werden…$"
	.endif
	.endif

