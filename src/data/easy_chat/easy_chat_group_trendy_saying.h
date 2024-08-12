#if ENGLISH
const u8 gEasyChatWord_KthxBye[] = _("KTHX, BYE.");
const u8 gEasyChatWord_YesSirExcl[] = _("YES, SIR!");
const u8 gEasyChatWord_AvantGarde[] = _("AVANT GARDE");
const u8 gEasyChatWord_Couple[] = _("COUPLE");
const u8 gEasyChatWord_MuchObliged[] = _("MUCH OBLIGED");
const u8 gEasyChatWord_YeehawExcl[] = _("YEEHAW!");
const u8 gEasyChatWord_Mega[] = _("MEGA");
const u8 gEasyChatWord_1HitKOExcl[] = _("1-HIT KO!");
const u8 gEasyChatWord_Destiny[] = _("DESTINY");
const u8 gEasyChatWord_Cancel[] = _("CANCEL");
const u8 gEasyChatWord_New[] = _("NEW");
const u8 gEasyChatWord_Flatten[] = _("FLATTEN");
const u8 gEasyChatWord_Kidding[] = _("KIDDING");
const u8 gEasyChatWord_Loser[] = _("LOSER");
const u8 gEasyChatWord_Losing[] = _("LOSING");
const u8 gEasyChatWord_Happening[] = _("HAPPENING");
const u8 gEasyChatWord_HipAnd[] = _("HIP AND");
const u8 gEasyChatWord_Shake[] = _("SHAKE");
const u8 gEasyChatWord_Shady[] = _("SHADY");
const u8 gEasyChatWord_Upbeat[] = _("UPBEAT");
const u8 gEasyChatWord_Modern[] = _("MODERN");
const u8 gEasyChatWord_SmellYa[] = _("SMELL YA");
const u8 gEasyChatWord_Bang[] = _("BANG");
const u8 gEasyChatWord_Knockout[] = _("KNOCKOUT");
const u8 gEasyChatWord_Hassle[] = _("HASSLE");
const u8 gEasyChatWord_Winner[] = _("WINNER");
const u8 gEasyChatWord_Fever[] = _("FEVER");
const u8 gEasyChatWord_Wannabe[] = _("WANNABE");
const u8 gEasyChatWord_Baby[] = _("BABY");
const u8 gEasyChatWord_Heart[] = _("HEART");
const u8 gEasyChatWord_Old[] = _("OLD");
const u8 gEasyChatWord_Young[] = _("YOUNG");
const u8 gEasyChatWord_Ugly[] = _("UGLY");
#elif GERMAN
const u8 gEasyChatWord_KthxBye[] = _("VOKUHILA");
const u8 gEasyChatWord_YesSirExcl[] = _("AYE, AYE!");
const u8 gEasyChatWord_AvantGarde[] = _("AVANTGARDE");
const u8 gEasyChatWord_Couple[] = _("YUPPIES");
const u8 gEasyChatWord_MuchObliged[] = _("IHR DIENER!");
const u8 gEasyChatWord_YeehawExcl[] = _("JIIHAAH");
const u8 gEasyChatWord_Mega[] = _("MEGA");
const u8 gEasyChatWord_1HitKOExcl[] = _("GUMMIPUNKT");
const u8 gEasyChatWord_Destiny[] = _("KARMA");
const u8 gEasyChatWord_Cancel[] = _("NDW");
const u8 gEasyChatWord_New[] = _("POPPER");
const u8 gEasyChatWord_Flatten[] = _("ERDBEERTEE");
const u8 gEasyChatWord_Kidding[] = _("SCHOFEL");
const u8 gEasyChatWord_Loser[] = _("LOSER");
const u8 gEasyChatWord_Losing[] = _("ZOFF");
const u8 gEasyChatWord_Happening[] = _("GIMMICK");
const u8 gEasyChatWord_HipAnd[] = _("HIP UND");
const u8 gEasyChatWord_Shake[] = _("BANANENSHAKE");
const u8 gEasyChatWord_Shady[] = _("ROCK’N’ROLL");
const u8 gEasyChatWord_Upbeat[] = _("DUFTE");
const u8 gEasyChatWord_Modern[] = _("MODERN");
const u8 gEasyChatWord_SmellYa[] = _("RÜBENNASE");
const u8 gEasyChatWord_Bang[] = _("STULPEN");
const u8 gEasyChatWord_Knockout[] = _("LICHT AUS...");
const u8 gEasyChatWord_Hassle[] = _("AUFSTAND");
const u8 gEasyChatWord_Winner[] = _("LEUCHTKEKS");
const u8 gEasyChatWord_Fever[] = _("KÖRPERHITZE");
const u8 gEasyChatWord_Wannabe[] = _("GERNEGROSS");
const u8 gEasyChatWord_Baby[] = _("BABY");
const u8 gEasyChatWord_Heart[] = _("HOLDE");
const u8 gEasyChatWord_Old[] = _("OLL");
const u8 gEasyChatWord_Young[] = _("JUNG");
const u8 gEasyChatWord_Ugly[] = _("ÄTZEND");
#endif

const struct EasyChatWordInfo gEasyChatGroup_TrendySaying[] = {
    [EC_INDEX(EC_WORD_KTHX_BYE)] =
    {
        .text = gEasyChatWord_KthxBye,
#if ENGLISH
        .alphabeticalOrder = 7,
#elif GERMAN
        .alphabeticalOrder = 32,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YES_SIR_EXCL)] =
    {
        .text = gEasyChatWord_YesSirExcl,
#if ENGLISH
        .alphabeticalOrder = 2,
#elif GERMAN
        .alphabeticalOrder = 24,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AVANT_GARDE)] =
    {
        .text = gEasyChatWord_AvantGarde,
#if ENGLISH
        .alphabeticalOrder = 28,
#elif GERMAN
        .alphabeticalOrder = 2,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COUPLE)] =
    {
        .text = gEasyChatWord_Couple,
#if ENGLISH
        .alphabeticalOrder = 22,
#elif GERMAN
        .alphabeticalOrder = 1,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MUCH_OBLIGED)] =
    {
        .text = gEasyChatWord_MuchObliged,
#if ENGLISH
        .alphabeticalOrder = 9,
#elif GERMAN
        .alphabeticalOrder = 28,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YEEHAW_EXCL)] =
    {
        .text = gEasyChatWord_YeehawExcl,
#if ENGLISH
        .alphabeticalOrder = 3,
#elif GERMAN
        .alphabeticalOrder = 17,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MEGA)] =
    {
        .text = gEasyChatWord_Mega,
#if ENGLISH
        .alphabeticalOrder = 8,
#elif GERMAN
        .alphabeticalOrder = 19,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_1_HIT_KO_EXCL)] =
    {
        .text = gEasyChatWord_1HitKOExcl,
#if ENGLISH
        .alphabeticalOrder = 26,
#elif GERMAN
        .alphabeticalOrder = 11,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DESTINY)] =
    {
        .text = gEasyChatWord_Destiny,
#if ENGLISH
        .alphabeticalOrder = 11,
#elif GERMAN
        .alphabeticalOrder = 27,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CANCEL)] =
    {
        .text = gEasyChatWord_Cancel,
        .alphabeticalOrder = 15,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEW)] =
    {
        .text = gEasyChatWord_New,
#if ENGLISH
        .alphabeticalOrder = 24,
#elif GERMAN
        .alphabeticalOrder = 7,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FLATTEN)] =
    {
        .text = gEasyChatWord_Flatten,
#if ENGLISH
        .alphabeticalOrder = 29,
#elif GERMAN
        .alphabeticalOrder = 16,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KIDDING)] =
    {
        .text = gEasyChatWord_Kidding,
#if ENGLISH
        .alphabeticalOrder = 16,
#elif GERMAN
        .alphabeticalOrder = 29,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOSER)] =
    {
        .text = gEasyChatWord_Loser,
#if ENGLISH
        .alphabeticalOrder = 12,
#elif GERMAN
        .alphabeticalOrder = 4,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOSING)] =
    {
        .text = gEasyChatWord_Losing,
#if ENGLISH
        .alphabeticalOrder = 23,
#elif GERMAN
        .alphabeticalOrder = 5,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAPPENING)] =
    {
        .text = gEasyChatWord_Happening,
#if ENGLISH
        .alphabeticalOrder = 0,
#elif GERMAN
        .alphabeticalOrder = 31,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIP_AND)] =
    {
        .text = gEasyChatWord_HipAnd,
#if ENGLISH
        .alphabeticalOrder = 13,
#elif GERMAN
        .alphabeticalOrder = 8,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHAKE)] =
    {
        .text = gEasyChatWord_Shake,
#if ENGLISH
        .alphabeticalOrder = 14,
#elif GERMAN
        .alphabeticalOrder = 26,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHADY)] =
    {
        .text = gEasyChatWord_Shady,
#if ENGLISH
        .alphabeticalOrder = 6,
#elif GERMAN
        .alphabeticalOrder = 25,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UPBEAT)] =
    {
        .text = gEasyChatWord_Upbeat,
#if ENGLISH
        .alphabeticalOrder = 20,
#elif GERMAN
        .alphabeticalOrder = 23,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MODERN)] =
    {
        .text = gEasyChatWord_Modern,
#if ENGLISH
        .alphabeticalOrder = 4,
#elif GERMAN
        .alphabeticalOrder = 13,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMELL_YA)] =
    {
        .text = gEasyChatWord_SmellYa,
#if ENGLISH
        .alphabeticalOrder = 10,
#elif GERMAN
        .alphabeticalOrder = 6,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BANG)] =
    {
        .text = gEasyChatWord_Bang,
#if ENGLISH
        .alphabeticalOrder = 30,
#elif GERMAN
        .alphabeticalOrder = 20,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KNOCKOUT)] =
    {
        .text = gEasyChatWord_Knockout,
#if ENGLISH
        .alphabeticalOrder = 18,
#elif GERMAN
        .alphabeticalOrder = 9,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HASSLE)] =
    {
        .text = gEasyChatWord_Hassle,
#if ENGLISH
        .alphabeticalOrder = 17,
#elif GERMAN
        .alphabeticalOrder = 30,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WINNER)] =
    {
        .text = gEasyChatWord_Winner,
#if ENGLISH
        .alphabeticalOrder = 21,
#elif GERMAN
        .alphabeticalOrder = 10,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FEVER)] =
    {
        .text = gEasyChatWord_Fever,
#if ENGLISH
        .alphabeticalOrder = 32,
#elif GERMAN
        .alphabeticalOrder = 18,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WANNABE)] =
    {
        .text = gEasyChatWord_Wannabe,
#if ENGLISH
        .alphabeticalOrder = 19,
#elif GERMAN
        .alphabeticalOrder = 21,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BABY)] =
    {
        .text = gEasyChatWord_Baby,
#if ENGLISH
        .alphabeticalOrder = 27,
#elif GERMAN
        .alphabeticalOrder = 12,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEART)] =
    {
        .text = gEasyChatWord_Heart,
#if ENGLISH
        .alphabeticalOrder = 25,
#elif GERMAN
        .alphabeticalOrder = 22,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OLD)] =
    {
        .text = gEasyChatWord_Old,
#if ENGLISH
        .alphabeticalOrder = 5,
#elif GERMAN
        .alphabeticalOrder = 0,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YOUNG)] =
    {
        .text = gEasyChatWord_Young,
#if ENGLISH
        .alphabeticalOrder = 1,
#elif GERMAN
        .alphabeticalOrder = 3,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UGLY)] =
    {
        .text = gEasyChatWord_Ugly,
#if ENGLISH
        .alphabeticalOrder = 31,
#elif GERMAN
        .alphabeticalOrder = 14,
#endif
        .enabled = TRUE,
    },
};
