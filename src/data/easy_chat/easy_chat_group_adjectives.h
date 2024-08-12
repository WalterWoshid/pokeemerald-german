#if ENGLISH
const u8 gEasyChatWord_Wandering[] = _("WANDERING");
const u8 gEasyChatWord_Rickety[] = _("RICKETY");
const u8 gEasyChatWord_RockSolid[] = _("ROCK-SOLID");
const u8 gEasyChatWord_Hungry[] = _("HUNGRY");
const u8 gEasyChatWord_Tight[] = _("TIGHT");
const u8 gEasyChatWord_Ticklish[] = _("TICKLISH");
const u8 gEasyChatWord_Twirling[] = _("TWIRLING");
const u8 gEasyChatWord_Spiraling[] = _("SPIRALING");
const u8 gEasyChatWord_Thirsty[] = _("THIRSTY");
const u8 gEasyChatWord_Lolling[] = _("LOLLING");
const u8 gEasyChatWord_Silky[] = _("SILKY");
const u8 gEasyChatWord_Sadly[] = _("SADLY");
const u8 gEasyChatWord_Hopeless[] = _("HOPELESS");
const u8 gEasyChatWord_Useless[] = _("USELESS");
const u8 gEasyChatWord_Drooling[] = _("DROOLING");
const u8 gEasyChatWord_Exciting[] = _("EXCITING");
const u8 gEasyChatWord_Thick[] = _("THICK");
const u8 gEasyChatWord_Smooth[] = _("SMOOTH");
const u8 gEasyChatWord_Slimy[] = _("SLIMY");
const u8 gEasyChatWord_Thin[] = _("THIN");
const u8 gEasyChatWord_Break[] = _("BREAK");
const u8 gEasyChatWord_Voracious[] = _("VORACIOUS");
const u8 gEasyChatWord_Scatter[] = _("SCATTER");
const u8 gEasyChatWord_Awesome[] = _("AWESOME");
const u8 gEasyChatWord_Wimpy[] = _("WIMPY");
const u8 gEasyChatWord_Wobbly[] = _("WOBBLY");
const u8 gEasyChatWord_Shaky[] = _("SHAKY");
const u8 gEasyChatWord_Ripped[] = _("RIPPED");
const u8 gEasyChatWord_Shredded[] = _("SHREDDED");
const u8 gEasyChatWord_Increasing[] = _("INCREASING");
const u8 gEasyChatWord_Yet[] = _("YET");
const u8 gEasyChatWord_Destroyed[] = _("DESTROYED");
const u8 gEasyChatWord_Fiery[] = _("FIERY");
const u8 gEasyChatWord_LoveyDovey[] = _("LOVEY-DOVEY");
const u8 gEasyChatWord_Happily[] = _("HAPPILY");
const u8 gEasyChatWord_Anticipation[] = _("ANTICIPATION");
#elif GERMAN
const u8 gEasyChatWord_Wandering[] = _("LATSCH");
const u8 gEasyChatWord_Rickety[] = _("WACKEL");
const u8 gEasyChatWord_RockSolid[] = _("STEINHART");
const u8 gEasyChatWord_Hungry[] = _("MAGENKNURR");
const u8 gEasyChatWord_Tight[] = _("KNURSCHP");
const u8 gEasyChatWord_Ticklish[] = _("KILLE KILLE");
const u8 gEasyChatWord_Twirling[] = _("SCHLEUDER");
const u8 gEasyChatWord_Spiraling[] = _("WIRBEL");
const u8 gEasyChatWord_Thirsty[] = _("LECHZ");
const u8 gEasyChatWord_Lolling[] = _("LÜMMEL RÄKEL");
const u8 gEasyChatWord_Silky[] = _("WUSCHEL");
const u8 gEasyChatWord_Sadly[] = _("SCHNÜFF");
const u8 gEasyChatWord_Hopeless[] = _("OOCH");
const u8 gEasyChatWord_Useless[] = _("MÜLL");
const u8 gEasyChatWord_Drooling[] = _("SABBER");
const u8 gEasyChatWord_Exciting[] = _("JIPP! JIPP!");
const u8 gEasyChatWord_Thick[] = _("SCHWABBEL");
const u8 gEasyChatWord_Smooth[] = _("GLATT");
const u8 gEasyChatWord_Slimy[] = _("GLIBBER");
const u8 gEasyChatWord_Thin[] = _("KLAPPER");
const u8 gEasyChatWord_Break[] = _("SCHEPPER");
const u8 gEasyChatWord_Voracious[] = _("MAMPF FRESS");
const u8 gEasyChatWord_Scatter[] = _("SCHMEISS");
const u8 gEasyChatWord_Awesome[] = _("IRRE");
const u8 gEasyChatWord_Wimpy[] = _("ANGST BIBBER");
const u8 gEasyChatWord_Wobbly[] = _("ZITTER");
const u8 gEasyChatWord_Shaky[] = _("SCHÜTTEL");
const u8 gEasyChatWord_Ripped[] = _("RATSCH");
const u8 gEasyChatWord_Shredded[] = _("FETZ");
const u8 gEasyChatWord_Increasing[] = _("WURGS");
const u8 gEasyChatWord_Yet[] = _("NÖÖÖ");
const u8 gEasyChatWord_Destroyed[] = _("RUMMS BERST");
const u8 gEasyChatWord_Fiery[] = _("ZISCH FACKEL");
const u8 gEasyChatWord_LoveyDovey[] = _("SCHNUCKELIG");
const u8 gEasyChatWord_Happily[] = _("MEGAGRINS");
const u8 gEasyChatWord_Anticipation[] = _("GRINS HOFF");
#endif

const struct EasyChatWordInfo gEasyChatGroup_Adjectives[] = {
    [EC_INDEX(EC_WORD_WANDERING)] =
    {
        .text = gEasyChatWord_Wandering,
#if ENGLISH
        .alphabeticalOrder = 35,
#elif GERMAN
        .alphabeticalOrder = 24,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RICKETY)] =
    {
        .text = gEasyChatWord_Rickety,
#if ENGLISH
        .alphabeticalOrder = 23,
#elif GERMAN
        .alphabeticalOrder = 28,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ROCK_SOLID)] =
    {
        .text = gEasyChatWord_RockSolid,
#if ENGLISH
        .alphabeticalOrder = 20,
#elif GERMAN
        .alphabeticalOrder = 17,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HUNGRY)] =
    {
        .text = gEasyChatWord_Hungry,
#if ENGLISH
        .alphabeticalOrder = 31,
#elif GERMAN
        .alphabeticalOrder = 18,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TIGHT)] =
    {
        .text = gEasyChatWord_Tight,
#if ENGLISH
        .alphabeticalOrder = 14,
#elif GERMAN
        .alphabeticalOrder = 35,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TICKLISH)] =
    {
        .text = gEasyChatWord_Ticklish,
#if ENGLISH
        .alphabeticalOrder = 15,
#elif GERMAN
        .alphabeticalOrder = 23,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TWIRLING)] =
    {
        .text = gEasyChatWord_Twirling,
#if ENGLISH
        .alphabeticalOrder = 32,
#elif GERMAN
        .alphabeticalOrder = 15,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SPIRALING)] =
    {
        .text = gEasyChatWord_Spiraling,
#if ENGLISH
        .alphabeticalOrder = 34,
#elif GERMAN
        .alphabeticalOrder = 5,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIRSTY)] =
    {
        .text = gEasyChatWord_Thirsty,
#if ENGLISH
        .alphabeticalOrder = 12,
#elif GERMAN
        .alphabeticalOrder = 19,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOLLING)] =
    {
        .text = gEasyChatWord_Lolling,
#if ENGLISH
        .alphabeticalOrder = 3,
#elif GERMAN
        .alphabeticalOrder = 4,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SILKY)] =
    {
        .text = gEasyChatWord_Silky,
#if ENGLISH
        .alphabeticalOrder = 29,
#elif GERMAN
        .alphabeticalOrder = 0,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SADLY)] =
    {
        .text = gEasyChatWord_Sadly,
#if ENGLISH
        .alphabeticalOrder = 9,
#elif GERMAN
        .alphabeticalOrder = 8,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOPELESS)] =
    {
        .text = gEasyChatWord_Hopeless,
#if ENGLISH
        .alphabeticalOrder = 33,
#elif GERMAN
        .alphabeticalOrder = 9,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_USELESS)] =
    {
        .text = gEasyChatWord_Useless,
#if ENGLISH
        .alphabeticalOrder = 1,
#elif GERMAN
        .alphabeticalOrder = 3,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DROOLING)] =
    {
        .text = gEasyChatWord_Drooling,
#if ENGLISH
        .alphabeticalOrder = 27,
#elif GERMAN
        .alphabeticalOrder = 21,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCITING)] =
    {
        .text = gEasyChatWord_Exciting,
#if ENGLISH
        .alphabeticalOrder = 2,
#elif GERMAN
        .alphabeticalOrder = 34,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THICK)] =
    {
        .text = gEasyChatWord_Thick,
#if ENGLISH
        .alphabeticalOrder = 11,
#elif GERMAN
        .alphabeticalOrder = 13,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMOOTH)] =
    {
        .text = gEasyChatWord_Smooth,
#if ENGLISH
        .alphabeticalOrder = 22,
#elif GERMAN
        .alphabeticalOrder = 30,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SLIMY)] =
    {
        .text = gEasyChatWord_Slimy,
#if ENGLISH
        .alphabeticalOrder = 26,
#elif GERMAN
        .alphabeticalOrder = 12,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIN)] =
    {
        .text = gEasyChatWord_Thin,
#if ENGLISH
        .alphabeticalOrder = 28,
#elif GERMAN
        .alphabeticalOrder = 27,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BREAK)] =
    {
        .text = gEasyChatWord_Break,
#if ENGLISH
        .alphabeticalOrder = 10,
#elif GERMAN
        .alphabeticalOrder = 31,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VORACIOUS)] =
    {
        .text = gEasyChatWord_Voracious,
#if ENGLISH
        .alphabeticalOrder = 18,
#elif GERMAN
        .alphabeticalOrder = 14,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SCATTER)] =
    {
        .text = gEasyChatWord_Scatter,
#if ENGLISH
        .alphabeticalOrder = 17,
#elif GERMAN
        .alphabeticalOrder = 20,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWESOME)] =
    {
        .text = gEasyChatWord_Awesome,
#if ENGLISH
        .alphabeticalOrder = 7,
#elif GERMAN
        .alphabeticalOrder = 6,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WIMPY)] =
    {
        .text = gEasyChatWord_Wimpy,
#if ENGLISH
        .alphabeticalOrder = 16,
#elif GERMAN
        .alphabeticalOrder = 22,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WOBBLY)] =
    {
        .text = gEasyChatWord_Wobbly,
#if ENGLISH
        .alphabeticalOrder = 19,
#elif GERMAN
        .alphabeticalOrder = 33,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHAKY)] =
    {
        .text = gEasyChatWord_Shaky,
#if ENGLISH
        .alphabeticalOrder = 8,
#elif GERMAN
        .alphabeticalOrder = 11,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RIPPED)] =
    {
        .text = gEasyChatWord_Ripped,
#if ENGLISH
        .alphabeticalOrder = 5,
#elif GERMAN
        .alphabeticalOrder = 26,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHREDDED)] =
    {
        .text = gEasyChatWord_Shredded,
#if ENGLISH
        .alphabeticalOrder = 4,
#elif GERMAN
        .alphabeticalOrder = 16,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INCREASING)] =
    {
        .text = gEasyChatWord_Increasing,
#if ENGLISH
        .alphabeticalOrder = 6,
#elif GERMAN
        .alphabeticalOrder = 2,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YET)] =
    {
        .text = gEasyChatWord_Yet,
#if ENGLISH
        .alphabeticalOrder = 13,
#elif GERMAN
        .alphabeticalOrder = 1,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DESTROYED)] =
    {
        .text = gEasyChatWord_Destroyed,
#if ENGLISH
        .alphabeticalOrder = 21,
#elif GERMAN
        .alphabeticalOrder = 7,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FIERY)] =
    {
        .text = gEasyChatWord_Fiery,
#if ENGLISH
        .alphabeticalOrder = 0,
#elif GERMAN
        .alphabeticalOrder = 29,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOVEY_DOVEY)] =
    {
        .text = gEasyChatWord_LoveyDovey,
#if ENGLISH
        .alphabeticalOrder = 24,
#elif GERMAN
        .alphabeticalOrder = 10,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAPPILY)] =
    {
        .text = gEasyChatWord_Happily,
#if ENGLISH
        .alphabeticalOrder = 25,
#elif GERMAN
        .alphabeticalOrder = 32,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANTICIPATION)] =
    {
        .text = gEasyChatWord_Anticipation,
#if ENGLISH
        .alphabeticalOrder = 30,
#elif GERMAN
        .alphabeticalOrder = 25,
#endif
        .enabled = TRUE,
    },
};
