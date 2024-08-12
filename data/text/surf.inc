gText_WantToUseSurf::
	.ifdef ENGLISH
	.string "The water is dyed a deep blue…\n"
	.string "Would you like to SURF?$"
	.else
	.ifdef GERMAN
	.string "Das Wasser ist tiefblau.\n"
	.string "Möchtest du SURFER einsetzen?$"
	.endif
	.endif

gText_PlayerUsedSurf::
	.ifdef ENGLISH
	.string "{STR_VAR_1} used SURF!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_1} setzt SURFER ein.$"
	.endif
	.endif
