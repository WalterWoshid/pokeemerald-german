ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.ifdef ENGLISH
	.string "Hello there, TRAINER!\n"
	.string "You've got a wonderful smile, there.\p"
	.string "I have a hobby--collecting the profiles\n"
	.string "of POKéMON TRAINERS.$"
	.else
	.ifdef GERMAN
	.string "Hallo, du! TRAINER!\n"
	.string "Du hast ein wundervolles Lächeln.\p"
	.string "Ich habe ein Hobby: Ich sammle die\n"
	.string "Profile von POKéMON-TRAINERn.$"
	.endif
	.endif

ProfileMan_Text_MayISeeYourProfile:
	.ifdef ENGLISH
	.string "So, how about it?\n"
	.string "May I see your profile?$"
	.else
	.ifdef GERMAN
	.string "Nun, wie sieht es aus?\n"
	.string "Darf ich dein Profil sehen?$"
	.endif
	.endif

ProfileMan_Text_EasyChatExplanation:
	.ifdef ENGLISH
	.string "You make your own profile by putting\n"
	.string "together four words or phrases.\p"
	.string "Here, I'll show you an example of a\n"
	.string "profile using four pieces of text.\p"
	.string "You can switch those four pieces with\n"
	.string "other text pieces any which way you\l"
	.string "like to make your own profile.\p"
	.string "There are a lot of text pieces that\n"
	.string "you can use.\p"
	.string "They are arranged in groups like\n"
	.string "POKéMON, lifestyles, and hobbies so\l"
	.string "it is easier to look them up.\p"
	.string "So, first, choose the group of text\n"
	.string "pieces to display a list of choices.\p"
	.string "Then, pick the choice you want.\p"
	.string "Repeat for the remaining text choices,\n"
	.string "and you'll have your very own profile.$"
	.else
	.ifdef GERMAN
	.string "Du erstellst dir dein eigenes Profil,\n"
	.string "indem du 4 Worte oder Phrasen\l"
	.string "zusammenstellst.\p"
	.string "Ich gebe dir ein Beispiel für ein Profil\n"
	.string "mit vier Begriffen.\p"
	.string "Du kannst diese vier Begriffe mit\n"
	.string "anderen Begriffen tauschen, ganz\l"
	.string "so, wie du dein Profil haben möchtest.\p"
	.string "Dir stehen sehr viele Begriffe\n"
	.string "zur Verfügung.\p"
	.string "Sie sind nach Gruppen sortiert wie\n"
	.string "POKéMON, Lifestyle und Hobbies. So\l"
	.string "hast du einen besseren Überblick.\p"
	.string "Wähle zunächst eine Gruppe aus, um\n"
	.string "eine Liste entsprechender Begriffe\p"
	.string "zu öffnen. Dann triffst du deine Wahl.\p"
	.string "Suche dir beliebige Begriffe aus den\n"
	.string "Gruppen aus, um dein ganz persönliches\l"
	.string "Profil zu erstellen.$"
	.endif
	.endif

ProfileMan_Text_LetsSeeItThen:
	.ifdef ENGLISH
	.string "Yes! Thank you!\n"
	.string "So, let's see it, then.$"
	.else
	.ifdef GERMAN
	.string "Ja! Danke schön!\n"
	.string "Zeigst du mir jetzt dein Profil?$"
	.endif
	.endif

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.ifdef ENGLISH
	.string "Oh, no, really?\p"
	.string "I imagine someone like you would have\n"
	.string "a wonderful profile…$"
	.else
	.ifdef GERMAN
	.string "Oh, nein, ehrlich?\p"
	.string "Ich dachte, jemand wie du hätte ein\n"
	.string "wundervolles Profil…$"
	.endif
	.endif

ProfileMan_Text_NotIntoItRightNow:
	.ifdef ENGLISH
	.string "Oh? You're not into it right now?\p"
	.string "Well, anytime is good by me!$"
	.else
	.ifdef GERMAN
	.string "Oh! Du bist noch nicht so weit?\p"
	.string "Nun, dann zeig es mir doch später!$"
	.endif
	.endif

ProfileMan_Text_YouHaveWonderfulSmile:
	.ifdef ENGLISH
	.string "Hello there, TRAINER!\n"
	.string "You've got a wonderful smile.$"
	.else
	.ifdef GERMAN
	.string "Hallo, da drüben! TRAINER!\p"
	.string "Du hast ein wundervolles Lächeln.$"
	.endif
	.endif

ProfileMan_Text_MayISeeYourNewProfile:
	.ifdef ENGLISH
	.string "May I see your new profile?$"
	.else
	.ifdef GERMAN
	.string "Darf ich dein neues Profil sehen?$"
	.endif
	.endif

ProfileMan_Text_EvenBetterThanLastProfile:
	.ifdef ENGLISH
	.string "Yes! Thank you!\p"
	.string "I hope it's even better than the profile\n"
	.string "you showed me before.$"
	.else
	.ifdef GERMAN
	.string "Ja? Danke schön!\p"
	.string "Ich hoffe, das Profil ist besser als das\n"
	.string "vorhergehende.$"
	.endif
	.endif

ProfileMan_Text_LikeProfileWayItIs:
	.ifdef ENGLISH
	.string "Oh, you like your profile the way it is.\p"
	.string "I don't blame you--it's a wonderful\n"
	.string "profile the way it is now.$"
	.else
	.ifdef GERMAN
	.string "Oh, du magst dein Profil, wie es ist?\p"
	.string "Ich mache dir keine Vorwürfe - so, wie\n"
	.string "es jetzt ist, ist das Profil wunderbar.$"
	.endif
	.endif

ProfileMan_Text_FantasticProfile:
	.ifdef ENGLISH
	.string "F-fantastic!\p"
	.string "Your profile, it's wonderful!\n"
	.string "It really says what you're about.\p"
	.string "Why, anyone hearing this profile would\n"
	.string "be captivated by you!\p"
	.string "Thank you!$"
	.else
	.ifdef GERMAN
	.string "Fa-fantastisch!\p"
	.string "Dein Profil… Einfach wunderbar!\n"
	.string "Es sagt wirklich alles über dich aus.\p"
	.string "Jeder, der dieses Profil sieht, wird\n"
	.string "von dir entzückt sein!\p"
	.string "Danke schön.$"
	.endif
	.endif

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.ifdef ENGLISH
	.string "Oh?\n"
	.string "You know the secret saying!\p"
	.string "That means you're now a fellow member\n"
	.string "of the MYSTERY EVENT CLUB!$"
	.else
	.ifdef GERMAN
	.string "Oh?\n"
	.string "You know the secret saying!\p"
	.string "That means you’re now a fellow member\n"
	.string "of the MYSTERY EVENT CLUB!$"
	.endif
	.endif
