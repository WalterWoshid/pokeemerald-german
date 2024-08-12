	.section .rodata

gMultiBootProgram_BerryGlitchFix_Start::
    .ifdef ENGLISH
	.incbin "data/mb_berry_fix.gba"
	.else
	.ifdef GERMAN
	.incbin "data/mb_berry_fix_de.gba"
	.endif
	.endif
gMultiBootProgram_BerryGlitchFix_End::
