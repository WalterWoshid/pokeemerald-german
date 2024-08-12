VerdanturfTown_FriendshipRatersHouse_MapScripts::
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
	case FRIENDSHIP_1_TO_49, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
	case FRIENDSHIP_50_TO_99, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
	case FRIENDSHIP_100_TO_149, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
	case FRIENDSHIP_150_TO_199, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
	case FRIENDSHIP_200_TO_254, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
	case FRIENDSHIP_MAX, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou:
	.ifdef ENGLISH
	.string "Let me see your POKéMON.\n"
	.string "I'll check to see how much it likes you.\p"
	.string "Oh.\n"
	.string "Your POKéMON…$"
	.else
	.ifdef GERMAN
	.string "Zeig mir doch mal dein POKéMON.\n"
	.string "Ich prüfe, wie sehr es dich mag.\p"
	.string "Oh.\n"
	.string "Dein POKéMON…$"
	.endif
	.endif

VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou:
	.ifdef ENGLISH
	.string "It adores you.\n"
	.string "It can't possibly love you any more.\l"
	.string "I even feel happy seeing it.$"
	.else
	.ifdef GERMAN
	.string "Es liebt dich über alles.\n"
	.string "Mehr lieben könnte es dich gar nicht.\l"
	.string "Das zu sehen, macht mich glücklich.$"
	.endif
	.endif

VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy:
	.ifdef ENGLISH
	.string "It seems to be very happy.\n"
	.string "It obviously likes you a whole lot.$"
	.else
	.ifdef GERMAN
	.string "Es scheint sehr glücklich zu sein.\n"
	.string "Es mag dich wirklich sehr.$"
	.endif
	.endif

VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot:
	.ifdef ENGLISH
	.string "It likes you quite a lot.\n"
	.string "It seems to want to be babied a little.$"
	.else
	.ifdef GERMAN
	.string "Es mag dich.\n"
	.string "Es möchte von dir verwöhnt werden.$"
	.endif
	.endif

VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou:
	.ifdef ENGLISH
	.string "It's getting used to you.\n"
	.string "It seems to believe in you.$"
	.else
	.ifdef GERMAN
	.string "Es gewöhnt sich langsam an dich.\n"
	.string "Es glaubt an dich.$"
	.endif
	.endif

VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou:
	.ifdef ENGLISH
	.string "It's not very used to you yet.\n"
	.string "It neither loves nor hates you.$"
	.else
	.ifdef GERMAN
	.string "Es hat sich noch nicht an dich gewöhnt.\n"
	.string "Weder liebt es dich, noch hasst es dich.$"
	.endif
	.endif

VerdanturfTown_FriendshipRatersHouse_Text_VeryWary:
	.ifdef ENGLISH
	.string "It's very wary.\n"
	.string "It has scary viciousness in its eyes.\l"
	.string "It doesn't like you much at all.$"
	.else
	.ifdef GERMAN
	.string "Es schwankt in seinen Gefühlen.\n"
	.string "Es hat eine beängstigende Bösartigkeit\l"
	.string "in den Augen. Es mag dich nicht.$"
	.endif
	.endif

VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou:
	.ifdef ENGLISH
	.string "This is a little hard for me to say…\p"
	.string "Your POKéMON simply detests you.\n"
	.string "Doesn't that make you uncomfortable?$"
	.else
	.ifdef GERMAN
	.string "Es fällt mir schwer, das zu sagen…\p"
	.string "Dein POKéMON hasst dich. Das ist nicht\n"
	.string "gerade angenehm für dich, oder?$"
	.endif
	.endif

VerdanturfTown_FriendshipRatersHouse_Text_Pikachu:
	.ifdef ENGLISH
	.string "PIKACHU: Pika pika!$"
	.else
	.ifdef GERMAN
	.string "PIKACHU: Pika pika!$"
	.endif
	.endif

