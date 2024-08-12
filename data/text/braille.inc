@ NOTE: The brailleformat macro in this file is leftover from RS.
@       The numbers are simply skipped over. If you'd like to omit
@       this macro you must also stop it from skipping over this
@       section by editing ScrCmd_braillemessage.
Underwater_SealedChamber_Braille_GoUpHere:
	brailleformat 4, 6, 26, 13, 7, 9
	.ifdef ENGLISH
	.braille "GO UP HERE.$"
	.else
	.ifdef GERMAN
	.braille "HIER HINAUF"
	.byte 0x3F, 0x10 @ .
	.braille "$"
	.endif
	.endif

SealedChamber_OuterRoom_Braille_ABC:
	brailleformat 7, 6, 21, 13, 10, 9
	.ifdef ENGLISH
	.braille "ABC$"
	.else
	.ifdef GERMAN
	.braille "ABCD$"
	.endif
	.endif

SealedChamber_OuterRoom_Braille_GHI:
	brailleformat 7, 6, 21, 13, 10, 9
	.ifdef ENGLISH
	.braille "GHI$"
	.else
	.ifdef GERMAN
	.braille "IJKL$"
	.endif
	.endif

SealedChamber_OuterRoom_Braille_MNO:
	brailleformat 7, 6, 21, 13, 10, 9
	.ifdef ENGLISH
	.braille "MNO$"
	.else
	.ifdef GERMAN
	.braille "QRST$"
	.endif
	.endif

SealedChamber_OuterRoom_Braille_TUV:
	brailleformat 7, 6, 21, 13, 10, 9
	.ifdef ENGLISH
	.braille "TUV$"
	.else
	.ifdef GERMAN
	.braille "YZ$"
	.endif
	.endif

SealedChamber_OuterRoom_Braille_DEF:
	brailleformat 7, 6, 21, 13, 10, 9
	.ifdef ENGLISH
	.braille "DEF$"
    .else
    .ifdef GERMAN
    .braille "EFGH$"
    .endif
    .endif

SealedChamber_OuterRoom_Braille_JKL:
	brailleformat 7, 6, 21, 13, 10, 9
    .ifdef ENGLISH
	.braille "JKL$"
	.else
    .ifdef GERMAN
    .braille "MNOP$"
    .endif
    .endif

SealedChamber_OuterRoom_Braille_PQRS:
	brailleformat 7, 6, 21, 13, 10, 9
	.ifdef ENGLISH
	.braille "PQRS$"
	.else
	.ifdef GERMAN
	.braille "UVWX$"
	.endif
	.endif

SealedChamber_OuterRoom_Braille_Period:
	brailleformat 9, 6, 19, 13, 12, 9
	.ifdef ENGLISH
	.braille ".$"
	.else
	.ifdef GERMAN
	.byte 0x3F, 0x10 @ .
	.braille "$"
	.endif
	.endif

SealedChamber_OuterRoom_Braille_WXYZ:
	brailleformat 7, 6, 21, 13, 10, 9
	.ifdef ENGLISH
	.braille "WXYZ$"
	.else
	.ifdef GERMAN
	.byte 0x1A, 0x26, 0x2D @ ÄÖÜ
	.braille "$"
	.endif
	.endif

SealedChamber_OuterRoom_Braille_Comma:
	brailleformat 9, 6, 19, 13, 12, 9
	.ifdef ENGLISH
	.braille ",$"
	.else
	.ifdef GERMAN
	.byte 0x3F, 0x04 @ ,
	.braille "$"
	.endif
	.endif

SealedChamber_OuterRoom_Braille_DigHere:
	brailleformat 7, 4, 23, 15, 10, 7
	.ifdef ENGLISH
	.braille "DIG HERE.$"
	.else
	.ifdef GERMAN
	.braille "SCHAUFLE\n"
	.braille "HIER"
	.byte 0x3F, 0x10 @ .
	.braille "$"
	.endif
	.endif

SealedChamber_InnerRoom_Braille_FirstWailordLastRelicanth:
	brailleformat 0, 0, 29, 19, 3, 3
	.ifdef ENGLISH
	.braille "FIRST COMES\n"
	.braille "WAILORD.\n"
	.braille "LAST COMES\n"
	.braille "RELICANTH.$"
	.else
	.ifdef GERMAN
	.braille "ZUERST\n"
	.braille "WAILORD"
    .byte 0x3F, 0x04 @ ,
    .braille "\n"
    .braille "ZULETZT\n"
    .braille "RELICANTH"
    .byte 0x3F, 0x10 @ .
    .braille "$"
	.endif
	.endif

SealedChamber_InnerRoom_Braille_InThisCaveWeHaveLived:
	brailleformat 2, 0, 26, 19, 5, 3
	.ifdef ENGLISH
	.braille "IN THIS\n"
	.braille "CAVE WE\n"
	.braille "HAVE\n"
	.braille "LIVED.$"
	.else
	.ifdef GERMAN
	.braille "IN DIESER\n"
	.braille "H"
	.byte 0x26 @ Ö
	.braille "HLE HABEN\n"
	.braille "WIR GELEBT"
	.byte 0x3F, 0x10 @ .
	.braille "$"
	.endif
	.endif

SealedChamber_InnerRoom_Braille_WeOweAllToThePokemon:
	brailleformat 7, 2, 23, 17, 10, 5
	.ifdef ENGLISH
	.braille "WE OWE ALL\n"
	.braille "TO THE\n"
	.braille "POKEMON.$"
	.else
	.ifdef GERMAN
	.braille "WIR VERDANKEN\n"
	.braille "ALLES DEN\n"
	.braille "POKEMON"
	.byte 0x3F, 0x04 @ ,
	.braille "$"
	.endif
	.endif

SealedChamber_InnerRoom_Braille_ButWeSealedThePokemonAway:
	brailleformat 3, 0, 25, 19, 6, 3
	.ifdef ENGLISH
	.braille "BUT, WE\n"
	.braille "SEALED THE\n"
	.braille "POKEMON\n"
	.braille "AWAY.$"
	.else
	.ifdef GERMAN
	.braille "DENNOCH\n"
	.braille "SPERRTEN WIR\n"
	.braille "DIE POKEMON\n"
	.braille "WEG"
	.byte 0x3F, 0x10 @ .
	.braille "$"
	.endif
	.endif

SealedChamber_InnerRoom_Braille_WeFearedIt:
	brailleformat 5, 6, 25, 13, 8, 9
	.ifdef ENGLISH
	.braille "WE FEARED IT.$"
	.else
	.ifdef GERMAN
	.braille "WIR HATTEN\n"
	.braille "ANGST"
	.byte 0x3F, 0x10 @ .
	.braille "$"
	.endif
	.endif

SealedChamber_InnerRoom_Braille_ThoseWithCourageHope:
	brailleformat 6, 0, 24, 19, 9, 3
	.ifdef ENGLISH
	.braille "THOSE WITH\n"
	.braille "COURAGE,\n"
	.braille "THOSE WITH\n"
	.braille "HOPE.$"
	.else
	.ifdef GERMAN
	.braille "DENJENIGEN"
	.byte 0x3F, 0x04 @ ,
	.braille "\n"
	.braille "DIE HOFFEN UND\n"
	.braille "MUTIG SIND"
	.byte 0x3F, 0x04 @ ,
	.braille "\n"
	.braille "WIRD SICH$"
	.endif
	.endif

SealedChamber_InnerRoom_Braille_OpenDoorEternalPokemonWaits:
	brailleformat 3, 2, 27, 17, 6, 5
	.ifdef ENGLISH
	.braille "OPEN A DOOR.\n"
	.braille "AN ETERNAL\n"
	.braille "POKEMON\n"
	.braille "WAITS.$"
	.else
	.ifdef GERMAN
	.braille "EINE T"
	.byte 0x2D @ Ü
	.braille "RE ZU\n"
	.braille "EINEM EWIGEN\n"
	.braille "POKEMON\n"
	.byte 0x26 @ Ö
	.braille "FFNEN"
	.byte 0x3F, 0x10 @ .
	.braille "$"
	.endif
	.endif

DesertRuins_Braille_UseRockSmash:
	brailleformat 1, 0, 27, 19, 4, 3
	.ifdef ENGLISH
	.braille "LEFT, LEFT,\n"
	.braille "DOWN, DOWN.\n"
	.braille "THEN, USE\n"
	.braille "ROCK SMASH.$"
	.else
	.ifdef GERMAN
	.braille "ZWEI LINKS"
	.byte 0x3F, 0x04 @ ,
	.braille "\n"
	.braille "ZWEI RUNTER"
	.byte 0x3F, 0x04 @ ,
	.braille "\n"
	.braille "ANSCHLIESSEND\n"
	.braille "ZERTR"
	.byte 0x2D @ Ü
	.braille "MMERER"
	.byte 0x3F, 0x10 @ .
	.braille "$"
	.endif
	.endif

IslandCave_Braille_RunLapAroundWall:
	brailleformat 5, 0, 25, 19, 8, 3
	.ifdef ENGLISH
	.braille "STAY CLOSE\n"
	.braille "TO THE WALL.\n"
	.braille "RUN AROUND\n"
	.braille "ONE LAP.$"
	.else
	.ifdef GERMAN
	.braille "BLEIB NAHE\n"
	.braille "DER WAND UND\n"
	.braille "RENN EINE\n"
	.braille "RUNDE UMHER"
	.byte 0x3F, 0x10 @ .
	.braille "$"
	.endif
	.endif

AncientTomb_Braille_ShineInTheMiddle:
	brailleformat 3, 0, 25, 19, 6, 3
	.ifdef ENGLISH
	.braille "THOSE WHO\n"
	.braille "INHERIT OUR\n"
	.braille "WILL, SHINE\n"
	.braille "IN THE MIDDLE.$"
	.else
	.ifdef GERMAN
	.braille "DIE UNSEREN\n"
	.braille "WILLEN ERBEN"
	.byte 0x3F, 0x04 @ ,
	.braille "\n"
	.braille "ERSTRAHLEN \n"
	.braille "IM ZENTRUM"
	.byte 0x3F, 0x10 @ .
	.braille "$"
	.endif
	.endif
