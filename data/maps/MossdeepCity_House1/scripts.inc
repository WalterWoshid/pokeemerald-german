MossdeepCity_House1_MapScripts::
	.byte 0

MossdeepCity_House1_EventScript_BlackBelt::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox MossdeepCity_House1_Text_HmmYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetPokeblockNameByMonNature
	goto_if_eq VAR_RESULT, 0, MossdeepCity_House1_EventScript_NeutralNature
	msgbox MossdeepCity_House1_Text_ItLikesXPokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_NeutralNature::
	msgbox MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_Woman::
	msgbox MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes, MSGBOX_NPC
	end

MossdeepCity_House1_Text_HmmYourPokemon:
	.ifdef ENGLISH
	.string "Hmm!\n"
	.string "Your {STR_VAR_1}…$"
	.else
	.ifdef GERMAN
	.string "Hmm!\n"
	.string "Dein {STR_VAR_1}…$"
	.endif
	.endif

MossdeepCity_House1_Text_ItLikesXPokeblocks:
	.ifdef ENGLISH
	.string "It likes {STR_VAR_1}S,\n"
	.string "doesn't it?\p"
	.string "No, I'm positive of it! It definitely\n"
	.string "likes {STR_VAR_1}S!$"
	.else
	.ifdef GERMAN
	.string "Es mag {STR_VAR_1},\n"
	.string "nicht wahr?\p"
	.string "Nein, ich bin mir sicher. Es mag mit\n"
	.string "Sicherheit {STR_VAR_1}!$"
	.endif
	.endif

MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks:
	.ifdef ENGLISH
	.string "It doesn't appear to like or dislike\n"
	.string "any {POKEBLOCK}S.$"
	.else
	.ifdef GERMAN
	.string "Es scheint {POKEBLOCK}\n"
	.string "weder zu lieben noch abzulehnen.$"
	.endif
	.endif

MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes:
	.ifdef ENGLISH
	.string "My husband can tell what kind of\n"
	.string "{POKEBLOCK}S a POKéMON likes at a glance.$"
	.else
	.ifdef GERMAN
	.string "Mein Mann weiß auf den ersten Blick,\n"
	.string "welche Art von {POKEBLOCK}\l"
	.string "ein POKéMON mag und welche nicht.$"
	.endif
	.endif

