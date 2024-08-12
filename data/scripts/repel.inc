EventScript_RepelWoreOff::
	msgbox Text_RepelWoreOff, MSGBOX_SIGN
	end

Text_RepelWoreOff:
	.ifdef ENGLISH
	.string "REPEL's effect wore off…$"
	.else
	.ifdef GERMAN
	.string "SCHUTZ wirkt nicht mehr…$"
	.endif
	.endif
