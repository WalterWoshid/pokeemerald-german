#if ENGLISH
const u8 gEasyChatWord_IChooseYou[] = _("I CHOOSE YOU");
const u8 gEasyChatWord_Gotcha[] = _("GOTCHA");
const u8 gEasyChatWord_Trade[] = _("TRADE");
const u8 gEasyChatWord_Sapphire[] = _("SAPPHIRE");
const u8 gEasyChatWord_Evolve[] = _("EVOLVE");
const u8 gEasyChatWord_Encyclopedia[] = _("ENCYCLOPEDIA");
const u8 gEasyChatWord_Nature[] = _("NATURE");
const u8 gEasyChatWord_Center[] = _("CENTER");
const u8 gEasyChatWord_Egg[] = _("EGG");
const u8 gEasyChatWord_Link[] = _("LINK");
const u8 gEasyChatWord_SpAbility[] = _("SP. ABILITY");
const u8 gEasyChatWord_Trainer[] = _("TRAINER");
const u8 gEasyChatWord_Version[] = _("VERSION");
const u8 gEasyChatWord_Pokenav[] = _("POKéNAV");
const u8 gEasyChatWord_Pokemon[] = _("POKéMON");
const u8 gEasyChatWord_Get[] = _("GET");
const u8 gEasyChatWord_Pokedex[] = _("POKéDEX");
const u8 gEasyChatWord_Ruby[] = _("RUBY");
const u8 gEasyChatWord_Level[] = _("LEVEL");
const u8 gEasyChatWord_Red[] = _("RED");
const u8 gEasyChatWord_Green[] = _("GREEN");
const u8 gEasyChatWord_Bag[] = _("BAG");
const u8 gEasyChatWord_Flame[] = _("FLAME");
const u8 gEasyChatWord_Gold[] = _("GOLD");
const u8 gEasyChatWord_Leaf[] = _("LEAF");
const u8 gEasyChatWord_Silver[] = _("SILVER");
const u8 gEasyChatWord_Emerald[] = _("EMERALD");
#elif GERMAN
const u8 gEasyChatWord_IChooseYou[] = _("DU BIST DRAN");
const u8 gEasyChatWord_Gotcha[] = _("HAB DICH");
const u8 gEasyChatWord_Trade[] = _("TAUSCH");
const u8 gEasyChatWord_Sapphire[] = _("SAPHIR");
const u8 gEasyChatWord_Evolve[] = _("ENTWICKELN");
const u8 gEasyChatWord_Encyclopedia[] = _("ENZYKLOPÄDIE");
const u8 gEasyChatWord_Nature[] = _("WESEN");
const u8 gEasyChatWord_Center[] = _("CENTER");
const u8 gEasyChatWord_Egg[] = _("EI");
const u8 gEasyChatWord_Link[] = _("LINK");
const u8 gEasyChatWord_SpAbility[] = _("FÄHIGKEIT");
const u8 gEasyChatWord_Trainer[] = _("TRAINER");
const u8 gEasyChatWord_Version[] = _("VERSION");
const u8 gEasyChatWord_Pokenav[] = _("POKéNAV");
const u8 gEasyChatWord_Pokemon[] = _("POKéMON");
const u8 gEasyChatWord_Get[] = _("BEKOMMEN");
const u8 gEasyChatWord_Pokedex[] = _("POKéDEX");
const u8 gEasyChatWord_Ruby[] = _("RUBIN");
const u8 gEasyChatWord_Level[] = _("LEVEL");
const u8 gEasyChatWord_Red[] = _("ROT");
const u8 gEasyChatWord_Green[] = _("GRÜN");
const u8 gEasyChatWord_Bag[] = _("BEUTEL");
const u8 gEasyChatWord_Flame[] = _("FLAMME");
const u8 gEasyChatWord_Gold[] = _("GOLD");
const u8 gEasyChatWord_Leaf[] = _("BLATT");
const u8 gEasyChatWord_Silver[] = _("SILBER");
const u8 gEasyChatWord_Emerald[] = _("SMARAGD");
#endif

const struct EasyChatWordInfo gEasyChatGroup_Trainer[] = {
    [EC_INDEX(EC_WORD_I_CHOOSE_YOU)] =
    {
        .text = gEasyChatWord_IChooseYou,
#if ENGLISH
        .alphabeticalOrder = 21,
#elif GERMAN
        .alphabeticalOrder = 15,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOTCHA)] =
    {
        .text = gEasyChatWord_Gotcha,
#if ENGLISH
        .alphabeticalOrder = 7,
#elif GERMAN
        .alphabeticalOrder = 21,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRADE)] =
    {
        .text = gEasyChatWord_Trade,
#if ENGLISH
        .alphabeticalOrder = 8,
#elif GERMAN
        .alphabeticalOrder = 24,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SAPPHIRE)] =
    {
        .text = gEasyChatWord_Sapphire,
#if ENGLISH
        .alphabeticalOrder = 26,
#elif GERMAN
        .alphabeticalOrder = 7,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVOLVE)] =
    {
        .text = gEasyChatWord_Evolve,
#if ENGLISH
        .alphabeticalOrder = 5,
#elif GERMAN
        .alphabeticalOrder = 0,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENCYCLOPEDIA)] =
    {
        .text = gEasyChatWord_Encyclopedia,
#if ENGLISH
        .alphabeticalOrder = 4,
#elif GERMAN
        .alphabeticalOrder = 8,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NATURE)] =
    {
        .text = gEasyChatWord_Nature,
#if ENGLISH
        .alphabeticalOrder = 22,
#elif GERMAN
        .alphabeticalOrder = 4,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CENTER)] =
    {
        .text = gEasyChatWord_Center,
#if ENGLISH
        .alphabeticalOrder = 15,
#elif GERMAN
        .alphabeticalOrder = 5,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EGG)] =
    {
        .text = gEasyChatWord_Egg,
#if ENGLISH
        .alphabeticalOrder = 23,
#elif GERMAN
        .alphabeticalOrder = 10,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LINK)] =
    {
        .text = gEasyChatWord_Link,
#if ENGLISH
        .alphabeticalOrder = 1,
#elif GERMAN
        .alphabeticalOrder = 22,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SP_ABILITY)] =
    {
        .text = gEasyChatWord_SpAbility,
#if ENGLISH
        .alphabeticalOrder = 20,
#elif GERMAN
        .alphabeticalOrder = 23,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRAINER)] =
    {
        .text = gEasyChatWord_Trainer,
#if ENGLISH
        .alphabeticalOrder = 0,
#elif GERMAN
        .alphabeticalOrder = 20,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VERSION)] =
    {
        .text = gEasyChatWord_Version,
#if ENGLISH
        .alphabeticalOrder = 24,
#elif GERMAN
        .alphabeticalOrder = 1,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKENAV)] =
    {
        .text = gEasyChatWord_Pokenav,
        .alphabeticalOrder = 18,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKEMON)] =
    {
        .text = gEasyChatWord_Pokemon,
        .alphabeticalOrder = 9,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GET)] =
    {
        .text = gEasyChatWord_Get,
#if ENGLISH
        .alphabeticalOrder = 6,
#elif GERMAN
        .alphabeticalOrder = 16,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKEDEX)] =
    {
        .text = gEasyChatWord_Pokedex,
#if ENGLISH
        .alphabeticalOrder = 16,
#elif GERMAN
        .alphabeticalOrder = 14,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RUBY)] =
    {
        .text = gEasyChatWord_Ruby,
#if ENGLISH
        .alphabeticalOrder = 14,
#elif GERMAN
        .alphabeticalOrder = 13,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEVEL)] =
    {
        .text = gEasyChatWord_Level,
#if ENGLISH
        .alphabeticalOrder = 13,
#elif GERMAN
        .alphabeticalOrder = 19,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RED)] =
    {
        .text = gEasyChatWord_Red,
#if ENGLISH
        .alphabeticalOrder = 19,
#elif GERMAN
        .alphabeticalOrder = 17,
#endif
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_GREEN)] =
    {
        .text = gEasyChatWord_Green,
#if ENGLISH
        .alphabeticalOrder = 17,
#elif GERMAN
        .alphabeticalOrder = 3,
#endif
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_BAG)] =
    {
        .text = gEasyChatWord_Bag,
#if ENGLISH
        .alphabeticalOrder = 3,
#elif GERMAN
        .alphabeticalOrder = 25,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FLAME)] =
    {
        .text = gEasyChatWord_Flame,
#if ENGLISH
        .alphabeticalOrder = 25,
#elif GERMAN
        .alphabeticalOrder = 26,
#endif
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_GOLD)] =
    {
        .text = gEasyChatWord_Gold,
#if ENGLISH
        .alphabeticalOrder = 10,
#elif GERMAN
        .alphabeticalOrder = 2,
#endif
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_LEAF)] =
    {
        .text = gEasyChatWord_Leaf,
#if ENGLISH
        .alphabeticalOrder = 2,
#elif GERMAN
        .alphabeticalOrder = 11,
#endif
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_SILVER)] =
    {
        .text = gEasyChatWord_Silver,
#if ENGLISH
        .alphabeticalOrder = 11,
#elif GERMAN
        .alphabeticalOrder = 12,
#endif
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_EMERALD)] =
    {
        .text = gEasyChatWord_Emerald,
#if ENGLISH
        .alphabeticalOrder = 12,
#elif GERMAN
        .alphabeticalOrder = 6,
#endif
        .enabled = TRUE,
    },
};
