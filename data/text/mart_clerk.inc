gText_HowMayIServeYou::
	.ifdef ENGLISH
	.string "Welcome!\p"
	.string "How may I serve you?$"
	.else
	.ifdef GERMAN
	.string "Willkommen!\p"
	.string "Kann ich dir helfen?$"
	.endif
	.endif

gText_PleaseComeAgain::
	.ifdef ENGLISH
	.string "Please come again!$"
	.else
	.ifdef GERMAN
	.string "Bitte komm bald wieder!$"
	.endif
	.endif

gText_PlayerWhatCanIDoForYou::
	.ifdef ENGLISH
	.string "{PLAYER}{STRING 5}, welcome!\p"
	.string "What can I do for you?$"
	.else
	.ifdef GERMAN
	.string "{PLAYER}{KUN}, willkommen!\p"
	.string "Wie kann ich dir behilflich sein?$"
	.endif
	.endif
