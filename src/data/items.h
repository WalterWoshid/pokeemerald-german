const struct Item gItems[] =
{
    [ITEM_NONE] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Pokeballs

    [ITEM_MASTER_BALL] =
    {
#if ENGLISH
        .name = _("MASTER BALL"),
#elif GERMAN
        .name = _("MEISTERBALL"),
#endif
        .itemId = ITEM_MASTER_BALL,
        .price = 0,
        .description = sMasterBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_MASTER_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_MASTER_BALL - FIRST_BALL,
    },

    [ITEM_ULTRA_BALL] =
    {
#if ENGLISH
        .name = _("ULTRA BALL"),
#elif GERMAN
        .name = _("HYPERBALL"),
#endif
        .itemId = ITEM_ULTRA_BALL,
        .price = 1200,
        .description = sUltraBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_ULTRA_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_ULTRA_BALL - FIRST_BALL,
    },

    [ITEM_GREAT_BALL] =
    {
#if ENGLISH
        .name = _("GREAT BALL"),
#elif GERMAN
        .name = _("SUPERBALL"),
#endif
        .itemId = ITEM_GREAT_BALL,
        .price = 600,
        .description = sGreatBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_GREAT_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_GREAT_BALL - FIRST_BALL,
    },

    [ITEM_POKE_BALL] =
    {
#if ENGLISH
        .name = _("POKé BALL"),
#elif GERMAN
        .name = _("POKéBALL"),
#endif
        .itemId = ITEM_POKE_BALL,
        .price = 200,
        .description = sPokeBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_POKE_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_POKE_BALL - FIRST_BALL,
    },

    [ITEM_SAFARI_BALL] =
    {
#if ENGLISH
        .name = _("SAFARI BALL"),
#elif GERMAN
        .name = _("SAFARIBALL"),
#endif
        .itemId = ITEM_SAFARI_BALL,
        .price = 0,
        .description = sSafariBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_SAFARI_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_SAFARI_BALL - FIRST_BALL,
    },

    [ITEM_NET_BALL] =
    {
#if ENGLISH
        .name = _("NET BALL"),
#elif GERMAN
        .name = _("NETZBALL"),
#endif
        .itemId = ITEM_NET_BALL,
        .price = 1000,
        .description = sNetBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_NET_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_NET_BALL - FIRST_BALL,
    },

    [ITEM_DIVE_BALL] =
    {
#if ENGLISH
        .name = _("DIVE BALL"),
#elif GERMAN
        .name = _("TAUCHBALL"),
#endif
        .itemId = ITEM_DIVE_BALL,
        .price = 1000,
        .description = sDiveBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_DIVE_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_DIVE_BALL - FIRST_BALL,
    },

    [ITEM_NEST_BALL] =
    {
#if ENGLISH
        .name = _("NEST BALL"),
#elif GERMAN
        .name = _("NESTBALL"),
#endif
        .itemId = ITEM_NEST_BALL,
        .price = 1000,
        .description = sNestBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_NEST_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_NEST_BALL - FIRST_BALL,
    },

    [ITEM_REPEAT_BALL] =
    {
#if ENGLISH
        .name = _("REPEAT BALL"),
#elif GERMAN
        .name = _("WIEDERBALL"),
#endif
        .itemId = ITEM_REPEAT_BALL,
        .price = 1000,
        .description = sRepeatBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_REPEAT_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_REPEAT_BALL - FIRST_BALL,
    },

    [ITEM_TIMER_BALL] =
    {
#if ENGLISH
        .name = _("TIMER BALL"),
#elif GERMAN
        .name = _("TIMERBALL"),
#endif
        .itemId = ITEM_TIMER_BALL,
        .price = 1000,
        .description = sTimerBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_TIMER_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_TIMER_BALL - FIRST_BALL,
    },

    [ITEM_LUXURY_BALL] =
    {
#if ENGLISH
        .name = _("LUXURY BALL"),
#elif GERMAN
        .name = _("LUXUSBALL"),
#endif
        .itemId = ITEM_LUXURY_BALL,
        .price = 1000,
        .description = sLuxuryBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_LUXURY_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_LUXURY_BALL - FIRST_BALL,
    },

    [ITEM_PREMIER_BALL] =
    {
#if ENGLISH
        .name = _("PREMIER BALL"),
#elif GERMAN
        .name = _("PREMIERBALL"),
#endif
        .itemId = ITEM_PREMIER_BALL,
        .price = 200,
        .description = sPremierBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_PREMIER_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_PREMIER_BALL - FIRST_BALL,
    },

// Medicine

    [ITEM_POTION] =
    {
#if ENGLISH
        .name = _("POTION"),
#elif GERMAN
        .name = _("TRANK"),
#endif
        .itemId = ITEM_POTION,
        .price = 300,
        .holdEffectParam = 20,
        .description = sPotionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ANTIDOTE] =
    {
#if ENGLISH
        .name = _("ANTIDOTE"),
#elif GERMAN
        .name = _("GEGENGIFT"),
#endif
        .itemId = ITEM_ANTIDOTE,
        .price = 100,
        .description = sAntidoteDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_BURN_HEAL] =
    {
#if ENGLISH
        .name = _("BURN HEAL"),
#elif GERMAN
        .name = _("FEUERHEILER"),
#endif
        .itemId = ITEM_BURN_HEAL,
        .price = 250,
        .description = sBurnHealDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ICE_HEAL] =
    {
#if ENGLISH
        .name = _("ICE HEAL"),
#elif GERMAN
        .name = _("EISHEILER"),
#endif
        .itemId = ITEM_ICE_HEAL,
        .price = 250,
        .description = sIceHealDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_AWAKENING] =
    {
#if ENGLISH
        .name = _("AWAKENING"),
#elif GERMAN
        .name = _("AUFWECKER"),
#endif
        .itemId = ITEM_AWAKENING,
        .price = 250,
        .description = sAwakeningDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_PARALYZE_HEAL] =
    {
#if ENGLISH
        .name = _("PARLYZ HEAL"),
#elif GERMAN
        .name = _("PARA-HEILER"),
#endif
        .itemId = ITEM_PARALYZE_HEAL,
        .price = 200,
        .description = sParalyzeHealDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_FULL_RESTORE] =
    {
#if ENGLISH
        .name = _("FULL RESTORE"),
#elif GERMAN
        .name = _("TOP-GENESUNG"),
#endif
        .itemId = ITEM_FULL_RESTORE,
        .price = 3000,
        .holdEffectParam = 255,
        .description = sFullRestoreDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_MAX_POTION] =
    {
#if ENGLISH
        .name = _("MAX POTION"),
#elif GERMAN
        .name = _("TOP-TRANK"),
#endif
        .itemId = ITEM_MAX_POTION,
        .price = 2500,
        .holdEffectParam = 255,
        .description = sMaxPotionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_HYPER_POTION] =
    {
#if ENGLISH
        .name = _("HYPER POTION"),
#elif GERMAN
        .name = _("HYPERTRANK"),
#endif
        .itemId = ITEM_HYPER_POTION,
        .price = 1200,
        .holdEffectParam = 200,
        .description = sHyperPotionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_SUPER_POTION] =
    {
#if ENGLISH
        .name = _("SUPER POTION"),
#elif GERMAN
        .name = _("SUPERTRANK"),
#endif
        .itemId = ITEM_SUPER_POTION,
        .price = 700,
        .holdEffectParam = 50,
        .description = sSuperPotionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_FULL_HEAL] =
    {
#if ENGLISH
        .name = _("FULL HEAL"),
#elif GERMAN
        .name = _("HYPERHEILER"),
#endif
        .itemId = ITEM_FULL_HEAL,
        .price = 600,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_REVIVE] =
    {
#if ENGLISH
        .name = _("REVIVE"),
#elif GERMAN
        .name = _("BELEBER"),
#endif
        .itemId = ITEM_REVIVE,
        .price = 1500,
        .description = sReviveDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_MAX_REVIVE] =
    {
#if ENGLISH
        .name = _("MAX REVIVE"),
#elif GERMAN
        .name = _("TOP-BELEBER"),
#endif
        .itemId = ITEM_MAX_REVIVE,
        .price = 4000,
        .description = sMaxReviveDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_FRESH_WATER] =
    {
#if ENGLISH
        .name = _("FRESH WATER"),
#elif GERMAN
        .name = _("TAFELWASSER"),
#endif
        .itemId = ITEM_FRESH_WATER,
        .price = 200,
        .holdEffectParam = 50,
        .description = sFreshWaterDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_SODA_POP] =
    {
#if ENGLISH
        .name = _("SODA POP"),
#elif GERMAN
        .name = _("SPRUDEL"),
#endif
        .itemId = ITEM_SODA_POP,
        .price = 300,
        .holdEffectParam = 60,
        .description = sSodaPopDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_LEMONADE] =
    {
#if ENGLISH
        .name = _("LEMONADE"),
#elif GERMAN
        .name = _("LIMONADE"),
#endif
        .itemId = ITEM_LEMONADE,
        .price = 350,
        .holdEffectParam = 80,
        .description = sLemonadeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_MOOMOO_MILK] =
    {
#if ENGLISH
        .name = _("MOOMOO MILK"),
#elif GERMAN
        .name = _("KUHMUH-MILCH"),
#endif
        .itemId = ITEM_MOOMOO_MILK,
        .price = 500,
        .holdEffectParam = 100,
        .description = sMoomooMilkDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ENERGY_POWDER] =
    {
#if ENGLISH
        .name = _("ENERGYPOWDER"),
#elif GERMAN
        .name = _("ENERGIESTAUB"),
#endif
        .itemId = ITEM_ENERGY_POWDER,
        .price = 500,
        .description = sEnergyPowderDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ENERGY_ROOT] =
    {
#if ENGLISH
        .name = _("ENERGY ROOT"),
#elif GERMAN
        .name = _("KRAFTWURZEL"),
#endif
        .itemId = ITEM_ENERGY_ROOT,
        .price = 800,
        .description = sEnergyRootDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_HEAL_POWDER] =
    {
#if ENGLISH
        .name = _("HEAL POWDER"),
#elif GERMAN
        .name = _("HEILPUDER"),
#endif
        .itemId = ITEM_HEAL_POWDER,
        .price = 450,
        .description = sHealPowderDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_REVIVAL_HERB] =
    {
#if ENGLISH
        .name = _("REVIVAL HERB"),
#elif GERMAN
        .name = _("VITALKRAUT"),
#endif
        .itemId = ITEM_REVIVAL_HERB,
        .price = 2800,
        .description = sRevivalHerbDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ETHER] =
    {
#if ENGLISH
        .name = _("ETHER"),
#elif GERMAN
        .name = _("ÄTHER"),
#endif
        .itemId = ITEM_ETHER,
        .price = 1200,
        .holdEffectParam = 10,
        .description = sEtherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
    },

    [ITEM_MAX_ETHER] =
    {
#if ENGLISH
        .name = _("MAX ETHER"),
#elif GERMAN
        .name = _("TOP-ÄTHER"),
#endif
        .itemId = ITEM_MAX_ETHER,
        .price = 2000,
        .holdEffectParam = 255,
        .description = sMaxEtherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
    },

    [ITEM_ELIXIR] =
    {
#if ENGLISH
        .name = _("ELIXIR"),
#elif GERMAN
        .name = _("ELIXIER"),
#endif
        .itemId = ITEM_ELIXIR,
        .price = 3000,
        .holdEffectParam = 10,
        .description = sElixirDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
    },

    [ITEM_MAX_ELIXIR] =
    {
#if ENGLISH
        .name = _("MAX ELIXIR"),
#elif GERMAN
        .name = _("TOP-ELIXIER"),
#endif
        .itemId = ITEM_MAX_ELIXIR,
        .price = 4500,
        .holdEffectParam = 255,
        .description = sMaxElixirDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
    },

    [ITEM_LAVA_COOKIE] =
    {
#if ENGLISH
        .name = _("LAVA COOKIE"),
#elif GERMAN
        .name = _("LAVAKEKS"),
#endif
        .itemId = ITEM_LAVA_COOKIE,
        .price = 200,
        .description = sLavaCookieDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_BLUE_FLUTE] =
    {
#if ENGLISH
        .name = _("BLUE FLUTE"),
#elif GERMAN
        .name = _("BLAUE FLÖTE"),
#endif
        .itemId = ITEM_BLUE_FLUTE,
        .price = 100,
        .description = sBlueFluteDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_YELLOW_FLUTE] =
    {
#if ENGLISH
        .name = _("YELLOW FLUTE"),
#elif GERMAN
        .name = _("GELBE FLÖTE"),
#endif
        .itemId = ITEM_YELLOW_FLUTE,
        .price = 200,
        .description = sYellowFluteDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_RED_FLUTE] =
    {
#if ENGLISH
        .name = _("RED FLUTE"),
#elif GERMAN
        .name = _("ROTE FLÖTE"),
#endif
        .itemId = ITEM_RED_FLUTE,
        .price = 300,
        .description = sRedFluteDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_BLACK_FLUTE] =
    {
#if ENGLISH
        .name = _("BLACK FLUTE"),
#elif GERMAN
        .name = _("SCHW. FLÖTE"),
#endif
        .itemId = ITEM_BLACK_FLUTE,
        .price = 400,
        .holdEffectParam = 50,
        .description = sBlackFluteDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
    },

    [ITEM_WHITE_FLUTE] =
    {
#if ENGLISH
        .name = _("WHITE FLUTE"),
#elif GERMAN
        .name = _("WEISSE FLÖTE"),
#endif
        .itemId = ITEM_WHITE_FLUTE,
        .price = 500,
        .holdEffectParam = 150,
        .description = sWhiteFluteDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
    },

    [ITEM_BERRY_JUICE] =
    {
#if ENGLISH
        .name = _("BERRY JUICE"),
#elif GERMAN
        .name = _("BEERENSAFT"),
#endif
        .itemId = ITEM_BERRY_JUICE,
        .price = 100,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 20,
        .description = sBerryJuiceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_SACRED_ASH] =
    {
#if ENGLISH
        .name = _("SACRED ASH"),
#elif GERMAN
        .name = _("ZAUBERASCHE"),
#endif
        .itemId = ITEM_SACRED_ASH,
        .price = 200,
        .description = sSacredAshDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_SacredAsh,
    },

// Collectibles

    [ITEM_SHOAL_SALT] =
    {
#if ENGLISH
        .name = _("SHOAL SALT"),
#elif GERMAN
        .name = _("KÜSTENSALZ"),
#endif
        .itemId = ITEM_SHOAL_SALT,
        .price = 20,
        .description = sShoalSaltDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SHOAL_SHELL] =
    {
#if ENGLISH
        .name = _("SHOAL SHELL"),
#elif GERMAN
        .name = _("KÜSTENSCHALE"),
#endif
        .itemId = ITEM_SHOAL_SHELL,
        .price = 20,
        .description = sShoalShellDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RED_SHARD] =
    {
#if ENGLISH
        .name = _("RED SHARD"),
#elif GERMAN
        .name = _("PURPURSTÜCK"),
#endif
        .itemId = ITEM_RED_SHARD,
        .price = 200,
        .description = sRedShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLUE_SHARD] =
    {
#if ENGLISH
        .name = _("BLUE SHARD"),
#elif GERMAN
        .name = _("INDIGOSTÜCK"),
#endif
        .itemId = ITEM_BLUE_SHARD,
        .price = 200,
        .description = sBlueShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_YELLOW_SHARD] =
    {
#if ENGLISH
        .name = _("YELLOW SHARD"),
#elif GERMAN
        .name = _("GELBSTÜCK"),
#endif
        .itemId = ITEM_YELLOW_SHARD,
        .price = 200,
        .description = sYellowShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GREEN_SHARD] =
    {
#if ENGLISH
        .name = _("GREEN SHARD"),
#elif GERMAN
        .name = _("GRÜNSTÜCK"),
#endif
        .itemId = ITEM_GREEN_SHARD,
        .price = 200,
        .description = sGreenShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_034] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_035] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_036] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_037] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_038] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_039] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_03A] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_03B] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_03C] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_03D] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_03E] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Vitamins

    [ITEM_HP_UP] =
    {
#if ENGLISH
        .name = _("HP UP"),
#elif GERMAN
        .name = _("KP-PLUS"),
#endif
        .itemId = ITEM_HP_UP,
        .price = 9800,
        .description = sHPUpDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_PROTEIN] =
    {
        .name = _("PROTEIN"),
        .itemId = ITEM_PROTEIN,
        .price = 9800,
        .description = sProteinDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_IRON] =
    {
#if ENGLISH
        .name = _("IRON"),
#elif GERMAN
        .name = _("EISEN"),
#endif
        .itemId = ITEM_IRON,
        .price = 9800,
        .description = sIronDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_CARBOS] =
    {
#if ENGLISH
        .name = _("CARBOS"),
#elif GERMAN
        .name = _("CARBON"),
#endif
        .itemId = ITEM_CARBOS,
        .price = 9800,
        .description = sCarbosDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_CALCIUM] =
    {
#if ENGLISH
        .name = _("CALCIUM"),
#elif GERMAN
        .name = _("KALZIUM"),
#endif
        .itemId = ITEM_CALCIUM,
        .price = 9800,
        .description = sCalciumDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_RARE_CANDY] =
    {
#if ENGLISH
        .name = _("RARE CANDY"),
#elif GERMAN
        .name = _("SONDERBONBON"),
#endif
        .itemId = ITEM_RARE_CANDY,
        .price = 4800,
        .description = sRareCandyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
    },

    [ITEM_PP_UP] =
    {
#if ENGLISH
        .name = _("PP UP"),
#elif GERMAN
        .name = _("AP-PLUS"),
#endif
        .itemId = ITEM_PP_UP,
        .price = 9800,
        .description = sPPUpDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
    },

    [ITEM_ZINC] =
    {
#if ENGLISH
        .name = _("ZINC"),
#elif GERMAN
        .name = _("ZINK"),
#endif
        .itemId = ITEM_ZINC,
        .price = 9800,
        .description = sZincDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_PP_MAX] =
    {
#if ENGLISH
        .name = _("PP MAX"),
#elif GERMAN
        .name = _("AP-TOP"),
#endif
        .itemId = ITEM_PP_MAX,
        .price = 9800,
        .description = sPPMaxDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
    },

    [ITEM_048] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Battle items

    [ITEM_GUARD_SPEC] =
    {
#if ENGLISH
        .name = _("GUARD SPEC."),
#elif GERMAN
        .name = _("MEGABLOCK"),
#endif
        .itemId = ITEM_GUARD_SPEC,
        .price = 700,
        .description = sGuardSpecDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_DIRE_HIT] =
    {
#if ENGLISH
        .name = _("DIRE HIT"),
#elif GERMAN
        .name = _("ANGRIFFPLUS"),
#endif
        .itemId = ITEM_DIRE_HIT,
        .price = 650,
        .description = sDireHitDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_X_ATTACK] =
    {
#if ENGLISH
        .name = _("X ATTACK"),
#elif GERMAN
        .name = _("X-ANGRIFF"),
#endif
        .itemId = ITEM_X_ATTACK,
        .price = 500,
        .description = sXAttackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_X_DEFEND] =
    {
#if ENGLISH
        .name = _("X DEFEND"),
#elif GERMAN
        .name = _("X-ABWEHR"),
#endif
        .itemId = ITEM_X_DEFEND,
        .price = 550,
        .description = sXDefendDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_X_SPEED] =
    {
#if ENGLISH
        .name = _("X SPEED"),
#elif GERMAN
        .name = _("X-TEMPO"),
#endif
        .itemId = ITEM_X_SPEED,
        .price = 350,
        .description = sXSpeedDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_X_ACCURACY] =
    {
#if ENGLISH
        .name = _("X ACCURACY"),
#elif GERMAN
        .name = _("X-TREFFER"),
#endif
        .itemId = ITEM_X_ACCURACY,
        .price = 950,
        .description = sXAccuracyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_X_SPECIAL] =
    {
#if ENGLISH
        .name = _("X SPECIAL"),
#elif GERMAN
        .name = _("X-SPEZIAL"),
#endif
        .itemId = ITEM_X_SPECIAL,
        .price = 350,
        .description = sXSpecialDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_POKE_DOLL] =
    {
#if ENGLISH
        .name = _("POKé DOLL"),
#elif GERMAN
        .name = _("POKéPUPPE"),
#endif
        .itemId = ITEM_POKE_DOLL,
        .price = 1000,
        .description = sPokeDollDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_Escape,
    },

    [ITEM_FLUFFY_TAIL] =
    {
#if ENGLISH
        .name = _("FLUFFY TAIL"),
#elif GERMAN
        .name = _("ENECO-RUTE"),
#endif
        .itemId = ITEM_FLUFFY_TAIL,
        .price = 1000,
        .description = sFluffyTailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_Escape,
    },

    [ITEM_052] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Field items

    [ITEM_SUPER_REPEL] =
    {
#if ENGLISH
        .name = _("SUPER REPEL"),
#elif GERMAN
        .name = _("SUPERSCHUTZ"),
#endif
        .itemId = ITEM_SUPER_REPEL,
        .price = 500,
        .holdEffectParam = 200,
        .description = sSuperRepelDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
    },

    [ITEM_MAX_REPEL] =
    {
#if ENGLISH
        .name = _("MAX REPEL"),
#elif GERMAN
        .name = _("TOP-SCHUTZ"),
#endif
        .itemId = ITEM_MAX_REPEL,
        .price = 700,
        .holdEffectParam = 250,
        .description = sMaxRepelDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
    },

    [ITEM_ESCAPE_ROPE] =
    {
#if ENGLISH
        .name = _("ESCAPE ROPE"),
#elif GERMAN
        .name = _("FLUCHTSEIL"),
#endif
        .itemId = ITEM_ESCAPE_ROPE,
        .price = 550,
        .description = sEscapeRopeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_EscapeRope,
    },

    [ITEM_REPEL] =
    {
#if ENGLISH
        .name = _("REPEL"),
#elif GERMAN
        .name = _("SCHUTZ"),
#endif
        .itemId = ITEM_REPEL,
        .price = 350,
        .holdEffectParam = 100,
        .description = sRepelDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
    },

    [ITEM_057] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_058] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_059] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_05A] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_05B] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_05C] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Evolution stones

    [ITEM_SUN_STONE] =
    {
#if ENGLISH
        .name = _("SUN STONE"),
#elif GERMAN
        .name = _("SONNENSTEIN"),
#endif
        .itemId = ITEM_SUN_STONE,
        .price = 2100,
        .description = sSunStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_MOON_STONE] =
    {
#if ENGLISH
        .name = _("MOON STONE"),
#elif GERMAN
        .name = _("MONDSTEIN"),
#endif
        .itemId = ITEM_MOON_STONE,
        .price = 0,
        .description = sMoonStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_FIRE_STONE] =
    {
#if ENGLISH
        .name = _("FIRE STONE"),
#elif GERMAN
        .name = _("FEUERSTEIN"),
#endif
        .itemId = ITEM_FIRE_STONE,
        .price = 2100,
        .description = sFireStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_THUNDER_STONE] =
    {
#if ENGLISH
        .name = _("THUNDERSTONE"),
#elif GERMAN
        .name = _("DONNERSTEIN"),
#endif
        .itemId = ITEM_THUNDER_STONE,
        .price = 2100,
        .description = sThunderStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_WATER_STONE] =
    {
#if ENGLISH
        .name = _("WATER STONE"),
#elif GERMAN
        .name = _("WASSERSTEIN"),
#endif
        .itemId = ITEM_WATER_STONE,
        .price = 2100,
        .description = sWaterStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_LEAF_STONE] =
    {
#if ENGLISH
        .name = _("LEAF STONE"),
#elif GERMAN
        .name = _("BLATTSTEIN"),
#endif
        .itemId = ITEM_LEAF_STONE,
        .price = 2100,
        .description = sLeafStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_063] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_064] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_065] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_066] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Valuable items

    [ITEM_TINY_MUSHROOM] =
    {
#if ENGLISH
        .name = _("TINYMUSHROOM"),
#elif GERMAN
        .name = _("MINIPILZ"),
#endif
        .itemId = ITEM_TINY_MUSHROOM,
        .price = 500,
        .description = sTinyMushroomDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BIG_MUSHROOM] =
    {
#if ENGLISH
        .name = _("BIG MUSHROOM"),
#elif GERMAN
        .name = _("RIESENPILZ"),
#endif
        .itemId = ITEM_BIG_MUSHROOM,
        .price = 5000,
        .description = sBigMushroomDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_069] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PEARL] =
    {
#if ENGLISH
        .name = _("PEARL"),
#elif GERMAN
        .name = _("PERLE"),
#endif
        .itemId = ITEM_PEARL,
        .price = 1400,
        .description = sPearlDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BIG_PEARL] =
    {
#if ENGLISH
        .name = _("BIG PEARL"),
#elif GERMAN
        .name = _("RIESENPERLE"),
#endif
        .itemId = ITEM_BIG_PEARL,
        .price = 7500,
        .description = sBigPearlDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STARDUST] =
    {
#if ENGLISH
        .name = _("STARDUST"),
#elif GERMAN
        .name = _("STERNENSTAUB"),
#endif
        .itemId = ITEM_STARDUST,
        .price = 2000,
        .description = sStardustDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STAR_PIECE] =
    {
#if ENGLISH
        .name = _("STAR PIECE"),
#elif GERMAN
        .name = _("STERNENSTÜCK"),
#endif
        .itemId = ITEM_STAR_PIECE,
        .price = 9800,
        .description = sStarPieceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_NUGGET] =
    {
        .name = _("NUGGET"),
        .itemId = ITEM_NUGGET,
        .price = 10000,
        .description = sNuggetDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_HEART_SCALE] =
    {
#if ENGLISH
        .name = _("HEART SCALE"),
#elif GERMAN
        .name = _("HERZSCHUPPE"),
#endif
        .itemId = ITEM_HEART_SCALE,
        .price = 100,
        .description = sHeartScaleDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_070] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_071] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_072] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_073] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_074] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_075] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_076] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_077] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_078] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Mail
    [ITEM_ORANGE_MAIL] =
    {
#if ENGLISH
        .name = _("ORANGE MAIL"),
#elif GERMAN
        .name = _("ZIGZAGBRIEF"),
#endif
        .itemId = ITEM_ORANGE_MAIL,
        .price = 50,
        .description = sOrangeMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_ORANGE_MAIL),
    },

    [ITEM_HARBOR_MAIL] =
    {
#if ENGLISH
        .name = _("HARBOR MAIL"),
#elif GERMAN
        .name = _("HAFENBRIEF"),
#endif
        .itemId = ITEM_HARBOR_MAIL,
        .price = 50,
        .description = sHarborMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_HARBOR_MAIL),
    },

    [ITEM_GLITTER_MAIL] =
    {
#if ENGLISH
        .name = _("GLITTER MAIL"),
#elif GERMAN
        .name = _("GLITZERBRIEF"),
#endif
        .itemId = ITEM_GLITTER_MAIL,
        .price = 50,
        .description = sGlitterMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_GLITTER_MAIL),
    },

    [ITEM_MECH_MAIL] =
    {
#if ENGLISH
        .name = _("MECH MAIL"),
#elif GERMAN
        .name = _("EILBRIEF"),
#endif
        .itemId = ITEM_MECH_MAIL,
        .price = 50,
        .description = sMechMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_MECH_MAIL),
    },

    [ITEM_WOOD_MAIL] =
    {
#if ENGLISH
        .name = _("WOOD MAIL"),
#elif GERMAN
        .name = _("WALDBRIEF"),
#endif
        .itemId = ITEM_WOOD_MAIL,
        .price = 50,
        .description = sWoodMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_WOOD_MAIL),
    },

    [ITEM_WAVE_MAIL] =
    {
#if ENGLISH
        .name = _("WAVE MAIL"),
#elif GERMAN
        .name = _("WELLENBRIEF"),
#endif
        .itemId = ITEM_WAVE_MAIL,
        .price = 50,
        .description = sWaveMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_WAVE_MAIL),
    },

    [ITEM_BEAD_MAIL] =
    {
#if ENGLISH
        .name = _("BEAD MAIL"),
#elif GERMAN
        .name = _("PERLENBRIEF"),
#endif
        .itemId = ITEM_BEAD_MAIL,
        .price = 50,
        .description = sBeadMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_BEAD_MAIL),
    },

    [ITEM_SHADOW_MAIL] =
    {
#if ENGLISH
        .name = _("SHADOW MAIL"),
#elif GERMAN
        .name = _("DUNKELBRIEF"),
#endif
        .itemId = ITEM_SHADOW_MAIL,
        .price = 50,
        .description = sShadowMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_SHADOW_MAIL),
    },

    [ITEM_TROPIC_MAIL] =
    {
#if ENGLISH
        .name = _("TROPIC MAIL"),
#elif GERMAN
        .name = _("TROPENBRIEF"),
#endif
        .itemId = ITEM_TROPIC_MAIL,
        .price = 50,
        .description = sTropicMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_TROPIC_MAIL),
    },

    [ITEM_DREAM_MAIL] =
    {
#if ENGLISH
        .name = _("DREAM MAIL"),
#elif GERMAN
        .name = _("TRAUMBRIEF"),
#endif
        .itemId = ITEM_DREAM_MAIL,
        .price = 50,
        .description = sDreamMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_DREAM_MAIL),
    },

    [ITEM_FAB_MAIL] =
    {
#if ENGLISH
        .name = _("FAB MAIL"),
#elif GERMAN
        .name = _("EDELBRIEF"),
#endif
        .itemId = ITEM_FAB_MAIL,
        .price = 50,
        .description = sFabMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_FAB_MAIL),
    },

    [ITEM_RETRO_MAIL] =
    {
#if ENGLISH
        .name = _("RETRO MAIL"),
#elif GERMAN
        .name = _("RETROBRIEF"),
#endif
        .itemId = ITEM_RETRO_MAIL,
        .price = 0,
        .description = sRetroMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_RETRO_MAIL),
    },

// Berries

    [ITEM_CHERI_BERRY] =
    {
#if ENGLISH
        .name = _("CHERI BERRY"),
#elif GERMAN
        .name = _("AMRENABEERE"),
#endif
        .itemId = ITEM_CHERI_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_PAR,
        .description = sCheriBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_CHESTO_BERRY] =
    {
#if ENGLISH
        .name = _("CHESTO BERRY"),
#elif GERMAN
        .name = _("MARONBEERE"),
#endif
        .itemId = ITEM_CHESTO_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_SLP,
        .description = sChestoBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_PECHA_BERRY] =
    {
#if ENGLISH
        .name = _("PECHA BERRY"),
#elif GERMAN
        .name = _("PIRSIFBEERE"),
#endif
        .itemId = ITEM_PECHA_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_PSN,
        .description = sPechaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_RAWST_BERRY] =
    {
#if ENGLISH
        .name = _("RAWST BERRY"),
#elif GERMAN
        .name = _("FRAGIABEERE"),
#endif
        .itemId = ITEM_RAWST_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_BRN,
        .description = sRawstBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ASPEAR_BERRY] =
    {
#if ENGLISH
        .name = _("ASPEAR BERRY"),
#elif GERMAN
        .name = _("WILBIRBEERE"),
#endif
        .itemId = ITEM_ASPEAR_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_FRZ,
        .description = sAspearBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_LEPPA_BERRY] =
    {
#if ENGLISH
        .name = _("LEPPA BERRY"),
#elif GERMAN
        .name = _("JONAGOBEERE"),
#endif
        .itemId = ITEM_LEPPA_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESTORE_PP,
        .holdEffectParam = 10,
        .description = sLeppaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
    },

    [ITEM_ORAN_BERRY] =
    {
#if ENGLISH
        .name = _("ORAN BERRY"),
#elif GERMAN
        .name = _("SINELBEERE"),
#endif
        .itemId = ITEM_ORAN_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 10,
        .description = sOranBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_PERSIM_BERRY] =
    {
#if ENGLISH
        .name = _("PERSIM BERRY"),
#elif GERMAN
        .name = _("PERSIMBEERE"),
#endif
        .itemId = ITEM_PERSIM_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_CONFUSION,
        .description = sPersimBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_LUM_BERRY] =
    {
#if ENGLISH
        .name = _("LUM BERRY"),
#elif GERMAN
        .name = _("PRUNUSBEERE"),
#endif
        .itemId = ITEM_LUM_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_STATUS,
        .description = sLumBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_SITRUS_BERRY] =
    {
#if ENGLISH
        .name = _("SITRUS BERRY"),
#elif GERMAN
        .name = _("TSITRUBEERE"),
#endif
        .itemId = ITEM_SITRUS_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 30,
        .description = sSitrusBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_FIGY_BERRY] =
    {
#if ENGLISH
        .name = _("FIGY BERRY"),
#elif GERMAN
        .name = _("GIEFEBEERE"),
#endif
        .itemId = ITEM_FIGY_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SPICY,
        .holdEffectParam = 8,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WIKI_BERRY] =
    {
#if ENGLISH
        .name = _("WIKI BERRY"),
#elif GERMAN
        .name = _("WIKIBEERE"),
#endif
        .itemId = ITEM_WIKI_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_DRY,
        .holdEffectParam = 8,
        .description = sWikiBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MAGO_BERRY] =
    {
#if ENGLISH
        .name = _("MAGO BERRY"),
#elif GERMAN
        .name = _("MAGOBEERE"),
#endif
        .itemId = ITEM_MAGO_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SWEET,
        .holdEffectParam = 8,
        .description = sMagoBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_AGUAV_BERRY] =
    {
#if ENGLISH
        .name = _("AGUAV BERRY"),
#elif GERMAN
        .name = _("GAUVEBEERE"),
#endif
        .itemId = ITEM_AGUAV_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_BITTER,
        .holdEffectParam = 8,
        .description = sAguavBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_IAPAPA_BERRY] =
    {
#if ENGLISH
        .name = _("IAPAPA BERRY"),
#elif GERMAN
        .name = _("YAPABEERE"),
#endif
        .itemId = ITEM_IAPAPA_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SOUR,
        .holdEffectParam = 8,
        .description = sIapapaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RAZZ_BERRY] =
    {
#if ENGLISH
        .name = _("RAZZ BERRY"),
#elif GERMAN
        .name = _("HIMMIHBEERE"),
#endif
        .itemId = ITEM_RAZZ_BERRY,
        .price = 20,
        .description = sRazzBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLUK_BERRY] =
    {
#if ENGLISH
        .name = _("BLUK BERRY"),
#elif GERMAN
        .name = _("MORBBEERE"),
#endif
        .itemId = ITEM_BLUK_BERRY,
        .price = 20,
        .description = sBlukBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_NANAB_BERRY] =
    {
#if ENGLISH
        .name = _("NANAB BERRY"),
#elif GERMAN
        .name = _("NANABBEERE"),
#endif
        .itemId = ITEM_NANAB_BERRY,
        .price = 20,
        .description = sNanabBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WEPEAR_BERRY] =
    {
#if ENGLISH
        .name = _("WEPEAR BERRY"),
#elif GERMAN
        .name = _("NIRBEBEERE"),
#endif
        .itemId = ITEM_WEPEAR_BERRY,
        .price = 20,
        .description = sWepearBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PINAP_BERRY] =
    {
#if ENGLISH
        .name = _("PINAP BERRY"),
#elif GERMAN
        .name = _("SANANABEERE"),
#endif
        .itemId = ITEM_PINAP_BERRY,
        .price = 20,
        .description = sPinapBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POMEG_BERRY] =
    {
#if ENGLISH
        .name = _("POMEG BERRY"),
#elif GERMAN
        .name = _("GRANABEERE"),
#endif
        .itemId = ITEM_POMEG_BERRY,
        .price = 20,
        .description = sPomegBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_KELPSY_BERRY] =
    {
#if ENGLISH
        .name = _("KELPSY BERRY"),
#elif GERMAN
        .name = _("SETANGBEERE"),
#endif
        .itemId = ITEM_KELPSY_BERRY,
        .price = 20,
        .description = sKelpsyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_QUALOT_BERRY] =
    {
#if ENGLISH
        .name = _("QUALOT BERRY"),
#elif GERMAN
        .name = _("QUALOTBEERE"),
#endif
        .itemId = ITEM_QUALOT_BERRY,
        .price = 20,
        .description = sQualotBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_HONDEW_BERRY] =
    {
#if ENGLISH
        .name = _("HONDEW BERRY"),
#elif GERMAN
        .name = _("HONMELBEERE"),
#endif
        .itemId = ITEM_HONDEW_BERRY,
        .price = 20,
        .description = sHondewBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_GREPA_BERRY] =
    {
#if ENGLISH
        .name = _("GREPA BERRY"),
#elif GERMAN
        .name = _("LABRUSBEERE"),
#endif
        .itemId = ITEM_GREPA_BERRY,
        .price = 20,
        .description = sGrepaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_TAMATO_BERRY] =
    {
#if ENGLISH
        .name = _("TAMATO BERRY"),
#elif GERMAN
        .name = _("TAMOTBEERE"),
#endif
        .itemId = ITEM_TAMATO_BERRY,
        .price = 20,
        .description = sTamatoBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_CORNN_BERRY] =
    {
#if ENGLISH
        .name = _("CORNN BERRY"),
#elif GERMAN
        .name = _("SAIMBEERE"),
#endif
        .itemId = ITEM_CORNN_BERRY,
        .price = 20,
        .description = sCornnBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MAGOST_BERRY] =
    {
#if ENGLISH
        .name = _("MAGOST BERRY"),
#elif GERMAN
        .name = _("MAGOSTBEERE"),
#endif
        .itemId = ITEM_MAGOST_BERRY,
        .price = 20,
        .description = sMagostBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RABUTA_BERRY] =
    {
#if ENGLISH
        .name = _("RABUTA BERRY"),
#elif GERMAN
        .name = _("RABUTABEERE"),
#endif
        .itemId = ITEM_RABUTA_BERRY,
        .price = 20,
        .description = sRabutaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_NOMEL_BERRY] =
    {
#if ENGLISH
        .name = _("NOMEL BERRY"),
#elif GERMAN
        .name = _("TRONZIBEERE"),
#endif
        .itemId = ITEM_NOMEL_BERRY,
        .price = 20,
        .description = sNomelBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SPELON_BERRY] =
    {
#if ENGLISH
        .name = _("SPELON BERRY"),
#elif GERMAN
        .name = _("KIWANBEERE"),
#endif
        .itemId = ITEM_SPELON_BERRY,
        .price = 20,
        .description = sSpelonBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PAMTRE_BERRY] =
    {
#if ENGLISH
        .name = _("PAMTRE BERRY"),
#elif GERMAN
        .name = _("PALLMBEERE"),
#endif
        .itemId = ITEM_PAMTRE_BERRY,
        .price = 20,
        .description = sPamtreBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WATMEL_BERRY] =
    {
#if ENGLISH
        .name = _("WATMEL BERRY"),
#elif GERMAN
        .name = _("WASMELBEERE"),
#endif
        .itemId = ITEM_WATMEL_BERRY,
        .price = 20,
        .description = sWatmelBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DURIN_BERRY] =
    {
#if ENGLISH
        .name = _("DURIN BERRY"),
#elif GERMAN
        .name = _("DURINBEERE"),
#endif
        .itemId = ITEM_DURIN_BERRY,
        .price = 20,
        .description = sDurinBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BELUE_BERRY] =
    {
#if ENGLISH
        .name = _("BELUE BERRY"),
#elif GERMAN
        .name = _("MYRTILBEERE"),
#endif
        .itemId = ITEM_BELUE_BERRY,
        .price = 20,
        .description = sBelueBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LIECHI_BERRY] =
    {
#if ENGLISH
        .name = _("LIECHI BERRY"),
#elif GERMAN
        .name = _("LYDZIBEERE"),
#endif
        .itemId = ITEM_LIECHI_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_ATTACK_UP,
        .holdEffectParam = 4,
        .description = sLiechiBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GANLON_BERRY] =
    {
#if ENGLISH
        .name = _("GANLON BERRY"),
#elif GERMAN
        .name = _("LINGANBEERE"),
#endif
        .itemId = ITEM_GANLON_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = sGanlonBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SALAC_BERRY] =
    {
#if ENGLISH
        .name = _("SALAC BERRY"),
#elif GERMAN
        .name = _("SALKABEERE"),
#endif
        .itemId = ITEM_SALAC_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_SPEED_UP,
        .holdEffectParam = 4,
        .description = sSalacBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PETAYA_BERRY] =
    {
#if ENGLISH
        .name = _("PETAYA BERRY"),
#elif GERMAN
        .name = _("TAHAYBEERE"),
#endif
        .itemId = ITEM_PETAYA_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_SP_ATTACK_UP,
        .holdEffectParam = 4,
        .description = sPetayaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_APICOT_BERRY] =
    {
#if ENGLISH
        .name = _("APICOT BERRY"),
#elif GERMAN
        .name = _("APIKOBEERE"),
#endif
        .itemId = ITEM_APICOT_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_SP_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = sApicotBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LANSAT_BERRY] =
    {
#if ENGLISH
        .name = _("LANSAT BERRY"),
#elif GERMAN
        .name = _("LANSATBEERE"),
#endif
        .itemId = ITEM_LANSAT_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CRITICAL_UP,
        .holdEffectParam = 4,
        .description = sLansatBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STARF_BERRY] =
    {
#if ENGLISH
        .name = _("STARF BERRY"),
#elif GERMAN
        .name = _("KRAMBOBEERE"),
#endif
        .itemId = ITEM_STARF_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_RANDOM_STAT_UP,
        .holdEffectParam = 4,
        .description = sStarfBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ENIGMA_BERRY] =
    {
#if ENGLISH
        .name = _("ENIGMA BERRY"),
#elif GERMAN
        .name = _("ENIGMABEERE"),
#endif
        .itemId = ITEM_ENIGMA_BERRY,
        .price = 20,
        .description = sEnigmaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU, // Type handled by ItemUseOutOfBattle_EnigmaBerry
        .fieldUseFunc = ItemUseOutOfBattle_EnigmaBerry,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_EnigmaBerry,
    },

    [ITEM_UNUSED_BERRY_1] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_UNUSED_BERRY_2] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_UNUSED_BERRY_3] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Hold items

    [ITEM_BRIGHT_POWDER] =
    {
#if ENGLISH
        .name = _("BRIGHTPOWDER"),
#elif GERMAN
        .name = _("BLENDPUDER"),
#endif
        .itemId = ITEM_BRIGHT_POWDER,
        .price = 10,
        .holdEffect = HOLD_EFFECT_EVASION_UP,
        .holdEffectParam = 10,
        .description = sBrightPowderDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WHITE_HERB] =
    {
#if ENGLISH
        .name = _("WHITE HERB"),
#elif GERMAN
        .name = _("SCHLOHKRAUT"),
#endif
        .itemId = ITEM_WHITE_HERB,
        .price = 100,
        .holdEffect = HOLD_EFFECT_RESTORE_STATS,
        .description = sWhiteHerbDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MACHO_BRACE] =
    {
#if ENGLISH
        .name = _("MACHO BRACE"),
#elif GERMAN
        .name = _("MACHOBAND"),
#endif
        .itemId = ITEM_MACHO_BRACE,
        .price = 3000,
        .holdEffect = HOLD_EFFECT_MACHO_BRACE,
        .description = sMachoBraceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EXP_SHARE] =
    {
#if ENGLISH
        .name = _("EXP. SHARE"),
#elif GERMAN
        .name = _("EP-TEILER"),
#endif
        .itemId = ITEM_EXP_SHARE,
        .price = 3000,
        .holdEffect = HOLD_EFFECT_EXP_SHARE,
        .description = sExpShareDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_QUICK_CLAW] =
    {
#if ENGLISH
        .name = _("QUICK CLAW"),
#elif GERMAN
        .name = _("FLINKKLAUE"),
#endif
        .itemId = ITEM_QUICK_CLAW,
        .price = 100,
        .holdEffect = HOLD_EFFECT_QUICK_CLAW,
        .holdEffectParam = 20,
        .description = sQuickClawDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SOOTHE_BELL] =
    {
#if ENGLISH
        .name = _("SOOTHE BELL"),
#elif GERMAN
        .name = _("SANFTGLOCKE"),
#endif
        .itemId = ITEM_SOOTHE_BELL,
        .price = 100,
        .holdEffect = HOLD_EFFECT_FRIENDSHIP_UP,
        .description = sSootheBellDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MENTAL_HERB] =
    {
#if ENGLISH
        .name = _("MENTAL HERB"),
#elif GERMAN
        .name = _("MENTALKRAUT"),
#endif
        .itemId = ITEM_MENTAL_HERB,
        .price = 100,
        .holdEffect = HOLD_EFFECT_CURE_ATTRACT,
        .description = sMentalHerbDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CHOICE_BAND] =
    {
#if ENGLISH
        .name = _("CHOICE BAND"),
#elif GERMAN
        .name = _("WAHLBAND"),
#endif
        .itemId = ITEM_CHOICE_BAND,
        .price = 100,
        .holdEffect = HOLD_EFFECT_CHOICE_BAND,
        .description = sChoiceBandDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_KINGS_ROCK] =
    {
#if ENGLISH
        .name = _("KING'S ROCK"),
#elif GERMAN
        .name = _("KING-STEIN"),
#endif
        .itemId = ITEM_KINGS_ROCK,
        .price = 100,
        .holdEffect = HOLD_EFFECT_FLINCH,
        .holdEffectParam = 10,
        .description = sKingsRockDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SILVER_POWDER] =
    {
#if ENGLISH
        .name = _("SILVERPOWDER"),
#elif GERMAN
        .name = _("SILBERSTAUB"),
#endif
        .itemId = ITEM_SILVER_POWDER,
        .price = 100,
        .holdEffect = HOLD_EFFECT_BUG_POWER,
        .holdEffectParam = 10,
        .description = sSilverPowderDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_AMULET_COIN] =
    {
#if ENGLISH
        .name = _("AMULET COIN"),
#elif GERMAN
        .name = _("MÜNZAMULETT"),
#endif
        .itemId = ITEM_AMULET_COIN,
        .price = 100,
        .holdEffect = HOLD_EFFECT_DOUBLE_PRIZE,
        .holdEffectParam = 10,
        .description = sAmuletCoinDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CLEANSE_TAG] =
    {
#if ENGLISH
        .name = _("CLEANSE TAG"),
#elif GERMAN
        .name = _("SCHUTZBAND"),
#endif
        .itemId = ITEM_CLEANSE_TAG,
        .price = 200,
        .holdEffect = HOLD_EFFECT_REPEL,
        .description = sCleanseTagDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SOUL_DEW] =
    {
#if ENGLISH
        .name = _("SOUL DEW"),
#elif GERMAN
        .name = _("SEELENTAU"),
#endif
        .itemId = ITEM_SOUL_DEW,
        .price = 200,
        .holdEffect = HOLD_EFFECT_SOUL_DEW,
        .description = sSoulDewDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DEEP_SEA_TOOTH] =
    {
#if ENGLISH
        .name = _("DEEPSEATOOTH"),
#elif GERMAN
        .name = _("ABYSSZAHN"),
#endif
        .itemId = ITEM_DEEP_SEA_TOOTH,
        .price = 200,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_TOOTH,
        .description = sDeepSeaToothDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DEEP_SEA_SCALE] =
    {
#if ENGLISH
        .name = _("DEEPSEASCALE"),
#elif GERMAN
        .name = _("ABYSSPLATTE"),
#endif
        .itemId = ITEM_DEEP_SEA_SCALE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_SCALE,
        .description = sDeepSeaScaleDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SMOKE_BALL] =
    {
#if ENGLISH
        .name = _("SMOKE BALL"),
#elif GERMAN
        .name = _("RAUCHBALL"),
#endif
        .itemId = ITEM_SMOKE_BALL,
        .price = 200,
        .holdEffect = HOLD_EFFECT_CAN_ALWAYS_RUN,
        .description = sSmokeBallDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EVERSTONE] =
    {
#if ENGLISH
        .name = _("EVERSTONE"),
#elif GERMAN
        .name = _("EWIGSTEIN"),
#endif
        .itemId = ITEM_EVERSTONE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PREVENT_EVOLVE,
        .description = sEverstoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_FOCUS_BAND] =
    {
#if ENGLISH
        .name = _("FOCUS BAND"),
#elif GERMAN
        .name = _("FOKUS-BAND"),
#endif
        .itemId = ITEM_FOCUS_BAND,
        .price = 200,
        .holdEffect = HOLD_EFFECT_FOCUS_BAND,
        .holdEffectParam = 10,
        .description = sFocusBandDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LUCKY_EGG] =
    {
#if ENGLISH
        .name = _("LUCKY EGG"),
#elif GERMAN
        .name = _("GLÜCKS-EI"),
#endif
        .itemId = ITEM_LUCKY_EGG,
        .price = 200,
        .holdEffect = HOLD_EFFECT_LUCKY_EGG,
        .description = sLuckyEggDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SCOPE_LENS] =
    {
#if ENGLISH
        .name = _("SCOPE LENS"),
#elif GERMAN
        .name = _("SCOPE-LINSE"),
#endif
        .itemId = ITEM_SCOPE_LENS,
        .price = 200,
        .holdEffect = HOLD_EFFECT_SCOPE_LENS,
        .description = sScopeLensDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_METAL_COAT] =
    {
#if ENGLISH
        .name = _("METAL COAT"),
#elif GERMAN
        .name = _("METALLMANTEL"),
#endif
        .itemId = ITEM_METAL_COAT,
        .price = 100,
        .holdEffect = HOLD_EFFECT_STEEL_POWER,
        .holdEffectParam = 10,
        .description = sMetalCoatDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LEFTOVERS] =
    {
#if ENGLISH
        .name = _("LEFTOVERS"),
#elif GERMAN
        .name = _("ÜBERRESTE"),
#endif
        .itemId = ITEM_LEFTOVERS,
        .price = 200,
        .holdEffect = HOLD_EFFECT_LEFTOVERS,
        .holdEffectParam = 10,
        .description = sLeftoversDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DRAGON_SCALE] =
    {
#if ENGLISH
        .name = _("DRAGON SCALE"),
#elif GERMAN
        .name = _("DRACHENHAUT"),
#endif
        .itemId = ITEM_DRAGON_SCALE,
        .price = 2100,
        .holdEffect = HOLD_EFFECT_DRAGON_SCALE,
        .holdEffectParam = 10,
        .description = sDragonScaleDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LIGHT_BALL] =
    {
#if ENGLISH
        .name = _("LIGHT BALL"),
#elif GERMAN
        .name = _("KUGELBLITZ"),
#endif
        .itemId = ITEM_LIGHT_BALL,
        .price = 100,
        .holdEffect = HOLD_EFFECT_LIGHT_BALL,
        .description = sLightBallDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SOFT_SAND] =
    {
#if ENGLISH
        .name = _("SOFT SAND"),
#elif GERMAN
        .name = _("PUDERSAND"),
#endif
        .itemId = ITEM_SOFT_SAND,
        .price = 100,
        .holdEffect = HOLD_EFFECT_GROUND_POWER,
        .holdEffectParam = 10,
        .description = sSoftSandDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_HARD_STONE] =
    {
#if ENGLISH
        .name = _("HARD STONE"),
#elif GERMAN
        .name = _("GRANITSTEIN"),
#endif
        .itemId = ITEM_HARD_STONE,
        .price = 100,
        .holdEffect = HOLD_EFFECT_ROCK_POWER,
        .holdEffectParam = 10,
        .description = sHardStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MIRACLE_SEED] =
    {
#if ENGLISH
        .name = _("MIRACLE SEED"),
#elif GERMAN
        .name = _("WUNDERSAAT"),
#endif
        .itemId = ITEM_MIRACLE_SEED,
        .price = 100,
        .holdEffect = HOLD_EFFECT_GRASS_POWER,
        .holdEffectParam = 10,
        .description = sMiracleSeedDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLACK_GLASSES] =
    {
#if ENGLISH
        .name = _("BLACKGLASSES"),
#elif GERMAN
        .name = _("SCHATTENGLAS"),
#endif
        .itemId = ITEM_BLACK_GLASSES,
        .price = 100,
        .holdEffect = HOLD_EFFECT_DARK_POWER,
        .holdEffectParam = 10,
        .description = sBlackGlassesDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLACK_BELT] =
    {
#if ENGLISH
        .name = _("BLACK BELT"),
#elif GERMAN
        .name = _("SCHWARZGURT"),
#endif
        .itemId = ITEM_BLACK_BELT,
        .price = 100,
        .holdEffect = HOLD_EFFECT_FIGHTING_POWER,
        .holdEffectParam = 10,
        .description = sBlackBeltDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MAGNET] =
    {
        .name = _("MAGNET"),
        .itemId = ITEM_MAGNET,
        .price = 100,
        .holdEffect = HOLD_EFFECT_ELECTRIC_POWER,
        .holdEffectParam = 10,
        .description = sMagnetDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MYSTIC_WATER] =
    {
#if ENGLISH
        .name = _("MYSTIC WATER"),
#elif GERMAN
        .name = _("ZAUBERWASSER"),
#endif
        .itemId = ITEM_MYSTIC_WATER,
        .price = 100,
        .holdEffect = HOLD_EFFECT_WATER_POWER,
        .holdEffectParam = 10,
        .description = sMysticWaterDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SHARP_BEAK] =
    {
#if ENGLISH
        .name = _("SHARP BEAK"),
#elif GERMAN
        .name = _("HACKATTACK"),
#endif
        .itemId = ITEM_SHARP_BEAK,
        .price = 100,
        .holdEffect = HOLD_EFFECT_FLYING_POWER,
        .holdEffectParam = 10,
        .description = sSharpBeakDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POISON_BARB] =
    {
#if ENGLISH
        .name = _("POISON BARB"),
#elif GERMAN
        .name = _("GIFTSTICH"),
#endif
        .itemId = ITEM_POISON_BARB,
        .price = 100,
        .holdEffect = HOLD_EFFECT_POISON_POWER,
        .holdEffectParam = 10,
        .description = sPoisonBarbDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_NEVER_MELT_ICE] =
    {
#if ENGLISH
        .name = _("NEVERMELTICE"),
#elif GERMAN
        .name = _("EWIGES EIS"),
#endif
        .itemId = ITEM_NEVER_MELT_ICE,
        .price = 100,
        .holdEffect = HOLD_EFFECT_ICE_POWER,
        .holdEffectParam = 10,
        .description = sNeverMeltIceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SPELL_TAG] =
    {
#if ENGLISH
        .name = _("SPELL TAG"),
#elif GERMAN
        .name = _("BANNSTICKER"),
#endif
        .itemId = ITEM_SPELL_TAG,
        .price = 100,
        .holdEffect = HOLD_EFFECT_GHOST_POWER,
        .holdEffectParam = 10,
        .description = sSpellTagDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TWISTED_SPOON] =
    {
#if ENGLISH
        .name = _("TWISTEDSPOON"),
#elif GERMAN
        .name = _("KRÜMMLÖFFEL"),
#endif
        .itemId = ITEM_TWISTED_SPOON,
        .price = 100,
        .holdEffect = HOLD_EFFECT_PSYCHIC_POWER,
        .holdEffectParam = 10,
        .description = sTwistedSpoonDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CHARCOAL] =
    {
#if ENGLISH
        .name = _("CHARCOAL"),
#elif GERMAN
        .name = _("HOLZKOHLE"),
#endif
        .itemId = ITEM_CHARCOAL,
        .price = 9800,
        .holdEffect = HOLD_EFFECT_FIRE_POWER,
        .holdEffectParam = 10,
        .description = sCharcoalDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DRAGON_FANG] =
    {
#if ENGLISH
        .name = _("DRAGON FANG"),
#elif GERMAN
        .name = _("DRACHENZAHN"),
#endif
        .itemId = ITEM_DRAGON_FANG,
        .price = 100,
        .holdEffect = HOLD_EFFECT_DRAGON_POWER,
        .holdEffectParam = 10,
        .description = sDragonFangDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SILK_SCARF] =
    {
#if ENGLISH
        .name = _("SILK SCARF"),
#elif GERMAN
        .name = _("SEIDENSCHAL"),
#endif
        .itemId = ITEM_SILK_SCARF,
        .price = 100,
        .holdEffect = HOLD_EFFECT_NORMAL_POWER,
        .holdEffectParam = 10,
        .description = sSilkScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_UP_GRADE] =
    {
        .name = _("UP-GRADE"),
        .itemId = ITEM_UP_GRADE,
        .price = 2100,
        .holdEffect = HOLD_EFFECT_UP_GRADE,
        .description = sUpGradeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SHELL_BELL] =
    {
#if ENGLISH
        .name = _("SHELL BELL"),
#elif GERMAN
        .name = _("SEEGESANG"),
#endif
        .itemId = ITEM_SHELL_BELL,
        .price = 200,
        .holdEffect = HOLD_EFFECT_SHELL_BELL,
        .holdEffectParam = 8,
        .description = sShellBellDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SEA_INCENSE] =
    {
#if ENGLISH
        .name = _("SEA INCENSE"),
#elif GERMAN
        .name = _("SEERAUCH"),
#endif
        .itemId = ITEM_SEA_INCENSE,
        .price = 9600,
        .holdEffect = HOLD_EFFECT_WATER_POWER,
        .holdEffectParam = 5,
        .description = sSeaIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LAX_INCENSE] =
    {
#if ENGLISH
        .name = _("LAX INCENSE"),
#elif GERMAN
        .name = _("LAXRAUCH"),
#endif
        .itemId = ITEM_LAX_INCENSE,
        .price = 9600,
        .holdEffect = HOLD_EFFECT_EVASION_UP,
        .holdEffectParam = 5,
        .description = sLaxIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LUCKY_PUNCH] =
    {
        .name = _("LUCKY PUNCH"),
        .itemId = ITEM_LUCKY_PUNCH,
        .price = 10,
        .holdEffect = HOLD_EFFECT_LUCKY_PUNCH,
        .description = sLuckyPunchDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_METAL_POWDER] =
    {
#if ENGLISH
        .name = _("METAL POWDER"),
#elif GERMAN
        .name = _("METALLSTAUB"),
#endif
        .itemId = ITEM_METAL_POWDER,
        .price = 10,
        .holdEffect = HOLD_EFFECT_METAL_POWDER,
        .description = sMetalPowderDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_THICK_CLUB] =
    {
#if ENGLISH
        .name = _("THICK CLUB"),
#elif GERMAN
        .name = _("KAMPFKNOCHEN"),
#endif
        .itemId = ITEM_THICK_CLUB,
        .price = 500,
        .holdEffect = HOLD_EFFECT_THICK_CLUB,
        .description = sThickClubDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STICK] =
    {
#if ENGLISH
        .name = _("STICK"),
#elif GERMAN
        .name = _("LAUCHSTANGE"),
#endif
        .itemId = ITEM_STICK,
        .price = 200,
        .holdEffect = HOLD_EFFECT_STICK,
        .description = sStickDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E2] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E3] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E4] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E5] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E6] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E7] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E8] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E9] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0EA] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0EB] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0EC] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0ED] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0EE] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0EF] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F0] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F1] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F2] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F3] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F4] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F5] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F6] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F7] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F8] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F9] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0FA] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0FB] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0FC] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0FD] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RED_SCARF] =
    {
#if ENGLISH
        .name = _("RED SCARF"),
#elif GERMAN
        .name = _("ROTER SCHAL"),
#endif
        .itemId = ITEM_RED_SCARF,
        .price = 100,
        .description = sRedScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLUE_SCARF] =
    {
#if ENGLISH
        .name = _("BLUE SCARF"),
#elif GERMAN
        .name = _("BLAUER SCHAL"),
#endif
        .itemId = ITEM_BLUE_SCARF,
        .price = 100,
        .description = sBlueScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PINK_SCARF] =
    {
#if ENGLISH
        .name = _("PINK SCARF"),
#elif GERMAN
        .name = _("ROSA SCHAL"),
#endif
        .itemId = ITEM_PINK_SCARF,
        .price = 100,
        .description = sPinkScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GREEN_SCARF] =
    {
#if ENGLISH
        .name = _("GREEN SCARF"),
#elif GERMAN
        .name = _("GRÜNER SCHAL"),
#endif
        .itemId = ITEM_GREEN_SCARF,
        .price = 100,
        .description = sGreenScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_YELLOW_SCARF] =
    {
#if ENGLISH
        .name = _("YELLOW SCARF"),
#elif GERMAN
        .name = _("GELBER SCHAL"),
#endif
        .itemId = ITEM_YELLOW_SCARF,
        .price = 100,
        .description = sYellowScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Key items

    [ITEM_MACH_BIKE] =
    {
#if ENGLISH
        .name = _("MACH BIKE"),
#elif GERMAN
        .name = _("EILRAD"),
#endif
        .itemId = ITEM_MACH_BIKE,
        .price = 0,
        .description = sMachBikeDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = MACH_BIKE,
    },

    [ITEM_COIN_CASE] =
    {
#if ENGLISH
        .name = _("COIN CASE"),
#elif GERMAN
        .name = _("MÜNZKORB"),
#endif
        .itemId = ITEM_COIN_CASE,
        .price = 0,
        .description = sCoinCaseDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CoinCase,
    },

    [ITEM_ITEMFINDER] =
    {
#if ENGLISH
        .name = _("ITEMFINDER"),
#elif GERMAN
        .name = _("DETEKTOR"),
#endif
        .itemId = ITEM_ITEMFINDER,
        .price = 0,
        .description = sItemfinderDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Itemfinder,
    },

    [ITEM_OLD_ROD] =
    {
#if ENGLISH
        .name = _("OLD ROD"),
#elif GERMAN
        .name = _("ANGEL"),
#endif
        .itemId = ITEM_OLD_ROD,
        .price = 0,
        .description = sOldRodDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = OLD_ROD,
    },

    [ITEM_GOOD_ROD] =
    {
#if ENGLISH
        .name = _("GOOD ROD"),
#elif GERMAN
        .name = _("PROFIANGEL"),
#endif
        .itemId = ITEM_GOOD_ROD,
        .price = 0,
        .description = sGoodRodDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = GOOD_ROD,
    },

    [ITEM_SUPER_ROD] =
    {
#if ENGLISH
        .name = _("SUPER ROD"),
#elif GERMAN
        .name = _("SUPERANGEL"),
#endif
        .itemId = ITEM_SUPER_ROD,
        .price = 0,
        .description = sSuperRodDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = SUPER_ROD,
    },

    [ITEM_SS_TICKET] =
    {
#if ENGLISH
        .name = _("S.S. TICKET"),
#elif GERMAN
        .name = _("BOOTSTICKET"),
#endif
        .itemId = ITEM_SS_TICKET,
        .price = 0,
        .description = sSSTicketDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CONTEST_PASS] =
    {
#if ENGLISH
        .name = _("CONTEST PASS"),
#elif GERMAN
        .name = _("WETTB.-KARTE"),
#endif
        .itemId = ITEM_CONTEST_PASS,
        .price = 0,
        .description = sContestPassDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_10B] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WAILMER_PAIL] =
    {
#if ENGLISH
        .name = _("WAILMER PAIL"),
#elif GERMAN
        .name = _("WAILMERKANNE"),
#endif
        .itemId = ITEM_WAILMER_PAIL,
        .price = 0,
        .description = sWailmerPailDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_WailmerPail,
    },

    [ITEM_DEVON_GOODS] =
    {
#if ENGLISH
        .name = _("DEVON GOODS"),
#elif GERMAN
        .name = _("DEVON-WAREN"),
#endif
        .itemId = ITEM_DEVON_GOODS,
        .price = 0,
        .description = sDevonGoodsDesc,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SOOT_SACK] =
    {
#if ENGLISH
        .name = _("SOOT SACK"),
#elif GERMAN
        .name = _("ASCHETASCHE"),
#endif
        .itemId = ITEM_SOOT_SACK,
        .price = 0,
        .description = sSootSackDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BASEMENT_KEY] =
    {
#if ENGLISH
        .name = _("BASEMENT KEY"),
#elif GERMAN
        .name = _("KELLERÖFFNER"),
#endif
        .itemId = ITEM_BASEMENT_KEY,
        .price = 0,
        .description = sBasementKeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ACRO_BIKE] =
    {
#if ENGLISH
        .name = _("ACRO BIKE"),
#elif GERMAN
        .name = _("KUNSTRAD"),
#endif
        .itemId = ITEM_ACRO_BIKE,
        .price = 0,
        .description = sAcroBikeDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = ACRO_BIKE,
    },

    [ITEM_POKEBLOCK_CASE] =
    {
#if ENGLISH
        .name = _("{POKEBLOCK} CASE"),
#elif GERMAN
        .name = _("{POKEBLOCK}BOX"),
#endif
        .itemId = ITEM_POKEBLOCK_CASE,
        .price = 0,
        .description = sPokeblockCaseDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PBLOCK_CASE,
        .fieldUseFunc = ItemUseOutOfBattle_PokeblockCase,
    },

    [ITEM_LETTER] =
    {
#if ENGLISH
        .name = _("LETTER"),
#elif GERMAN
        .name = _("BRIEF"),
#endif
        .itemId = ITEM_LETTER,
        .price = 0,
        .description = sLetterDesc,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EON_TICKET] =
    {
#if ENGLISH
        .name = _("EON TICKET"),
#elif GERMAN
        .name = _("ÄON-TICKET"),
#endif
        .itemId = ITEM_EON_TICKET,
        .price = 0,
        .description = sEonTicketDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 1,
    },

    [ITEM_RED_ORB] =
    {
#if ENGLISH
        .name = _("RED ORB"),
#elif GERMAN
        .name = _("ROTE KUGEL"),
#endif
        .itemId = ITEM_RED_ORB,
        .price = 0,
        .description = sRedOrbDesc,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLUE_ORB] =
    {
#if ENGLISH
        .name = _("BLUE ORB"),
#elif GERMAN
        .name = _("BLAUE KUGEL"),
#endif
        .itemId = ITEM_BLUE_ORB,
        .price = 0,
        .description = sBlueOrbDesc,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SCANNER] =
    {
        .name = _("SCANNER"),
        .itemId = ITEM_SCANNER,
        .price = 0,
        .description = sScannerDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GO_GOGGLES] =
    {
#if ENGLISH
        .name = _("GO-GOGGLES"),
#elif GERMAN
        .name = _("WÜSTENGLAS"),
#endif
        .itemId = ITEM_GO_GOGGLES,
        .price = 0,
        .description = sGoGogglesDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_METEORITE] =
    {
#if ENGLISH
        .name = _("METEORITE"),
#elif GERMAN
        .name = _("METEORIT"),
#endif
        .itemId = ITEM_METEORITE,
        .price = 0,
        .description = sMeteoriteDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROOM_1_KEY] =
    {
#if ENGLISH
        .name = _("RM. 1 KEY"),
#elif GERMAN
        .name = _("K1-SCHLÜSSEL"),
#endif
        .itemId = ITEM_ROOM_1_KEY,
        .price = 0,
        .description = sRoom1KeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROOM_2_KEY] =
    {
#if ENGLISH
        .name = _("RM. 2 KEY"),
#elif GERMAN
        .name = _("K2-SCHLÜSSEL"),
#endif
        .itemId = ITEM_ROOM_2_KEY,
        .price = 0,
        .description = sRoom2KeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROOM_4_KEY] =
    {
#if ENGLISH
        .name = _("RM. 4 KEY"),
#elif GERMAN
        .name = _("K4-SCHLÜSSEL"),
#endif
        .itemId = ITEM_ROOM_4_KEY,
        .price = 0,
        .description = sRoom4KeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROOM_6_KEY] =
    {
#if ENGLISH
        .name = _("RM. 6 KEY"),
#elif GERMAN
        .name = _("K6-SCHLÜSSEL"),
#endif
        .itemId = ITEM_ROOM_6_KEY,
        .price = 0,
        .description = sRoom6KeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STORAGE_KEY] =
    {
#if ENGLISH
        .name = _("STORAGE KEY"),
#elif GERMAN
        .name = _("L.-SCHLÜSSEL"),
#endif
        .itemId = ITEM_STORAGE_KEY,
        .price = 0,
        .description = sStorageKeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROOT_FOSSIL] =
    {
#if ENGLISH
        .name = _("ROOT FOSSIL"),
#elif GERMAN
        .name = _("WURZELFOSSIL"),
#endif
        .itemId = ITEM_ROOT_FOSSIL,
        .price = 0,
        .description = sRootFossilDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CLAW_FOSSIL] =
    {
#if ENGLISH
        .name = _("CLAW FOSSIL"),
#elif GERMAN
        .name = _("KLAUENFOSSIL"),
#endif
        .itemId = ITEM_CLAW_FOSSIL,
        .price = 0,
        .description = sClawFossilDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DEVON_SCOPE] =
    {
#if ENGLISH
        .name = _("DEVON SCOPE"),
#elif GERMAN
        .name = _("DEVON-SCOPE"),
#endif
        .itemId = ITEM_DEVON_SCOPE,
        .price = 0,
        .description = sDevonScopeDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// TMs/HMs

    [ITEM_TM_FOCUS_PUNCH] =
    {
        .name = _("TM01"),
        .itemId = ITEM_TM01,
        .price = 3000,
        .description = sTM01Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DRAGON_CLAW] =
    {
        .name = _("TM02"),
        .itemId = ITEM_TM02,
        .price = 3000,
        .description = sTM02Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_WATER_PULSE] =
    {
        .name = _("TM03"),
        .itemId = ITEM_TM03,
        .price = 3000,
        .description = sTM03Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_CALM_MIND] =
    {
        .name = _("TM04"),
        .itemId = ITEM_TM04,
        .price = 3000,
        .description = sTM04Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ROAR] =
    {
        .name = _("TM05"),
        .itemId = ITEM_TM05,
        .price = 1000,
        .description = sTM05Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TOXIC] =
    {
        .name = _("TM06"),
        .itemId = ITEM_TM06,
        .price = 3000,
        .description = sTM06Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HAIL] =
    {
        .name = _("TM07"),
        .itemId = ITEM_TM07,
        .price = 3000,
        .description = sTM07Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BULK_UP] =
    {
        .name = _("TM08"),
        .itemId = ITEM_TM08,
        .price = 3000,
        .description = sTM08Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BULLET_SEED] =
    {
        .name = _("TM09"),
        .itemId = ITEM_TM09,
        .price = 3000,
        .description = sTM09Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HIDDEN_POWER] =
    {
        .name = _("TM10"),
        .itemId = ITEM_TM10,
        .price = 3000,
        .description = sTM10Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SUNNY_DAY] =
    {
        .name = _("TM11"),
        .itemId = ITEM_TM11,
        .price = 2000,
        .description = sTM11Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TAUNT] =
    {
        .name = _("TM12"),
        .itemId = ITEM_TM12,
        .price = 3000,
        .description = sTM12Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ICE_BEAM] =
    {
        .name = _("TM13"),
        .itemId = ITEM_TM13,
        .price = 3000,
        .description = sTM13Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BLIZZARD] =
    {
        .name = _("TM14"),
        .itemId = ITEM_TM14,
        .price = 5500,
        .description = sTM14Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HYPER_BEAM] =
    {
        .name = _("TM15"),
        .itemId = ITEM_TM15,
        .price = 7500,
        .description = sTM15Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_LIGHT_SCREEN] =
    {
        .name = _("TM16"),
        .itemId = ITEM_TM16,
        .price = 3000,
        .description = sTM16Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_PROTECT] =
    {
        .name = _("TM17"),
        .itemId = ITEM_TM17,
        .price = 3000,
        .description = sTM17Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_RAIN_DANCE] =
    {
        .name = _("TM18"),
        .itemId = ITEM_TM18,
        .price = 2000,
        .description = sTM18Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_GIGA_DRAIN] =
    {
        .name = _("TM19"),
        .itemId = ITEM_TM19,
        .price = 3000,
        .description = sTM19Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SAFEGUARD] =
    {
        .name = _("TM20"),
        .itemId = ITEM_TM20,
        .price = 3000,
        .description = sTM20Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FRUSTRATION] =
    {
        .name = _("TM21"),
        .itemId = ITEM_TM21,
        .price = 1000,
        .description = sTM21Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SOLAR_BEAM] =
    {
        .name = _("TM22"),
        .itemId = ITEM_TM22,
        .price = 3000,
        .description = sTM22Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_IRON_TAIL] =
    {
        .name = _("TM23"),
        .itemId = ITEM_TM23,
        .price = 3000,
        .description = sTM23Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THUNDERBOLT] =
    {
        .name = _("TM24"),
        .itemId = ITEM_TM24,
        .price = 3000,
        .description = sTM24Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THUNDER] =
    {
        .name = _("TM25"),
        .itemId = ITEM_TM25,
        .price = 5500,
        .description = sTM25Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_EARTHQUAKE] =
    {
        .name = _("TM26"),
        .itemId = ITEM_TM26,
        .price = 3000,
        .description = sTM26Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_RETURN] =
    {
        .name = _("TM27"),
        .itemId = ITEM_TM27,
        .price = 1000,
        .description = sTM27Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DIG] =
    {
        .name = _("TM28"),
        .itemId = ITEM_TM28,
        .price = 2000,
        .description = sTM28Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_PSYCHIC] =
    {
        .name = _("TM29"),
        .itemId = ITEM_TM29,
        .price = 2000,
        .description = sTM29Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SHADOW_BALL] =
    {
        .name = _("TM30"),
        .itemId = ITEM_TM30,
        .price = 3000,
        .description = sTM30Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BRICK_BREAK] =
    {
        .name = _("TM31"),
        .itemId = ITEM_TM31,
        .price = 3000,
        .description = sTM31Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DOUBLE_TEAM] =
    {
        .name = _("TM32"),
        .itemId = ITEM_TM32,
        .price = 2000,
        .description = sTM32Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_REFLECT] =
    {
        .name = _("TM33"),
        .itemId = ITEM_TM33,
        .price = 3000,
        .description = sTM33Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SHOCK_WAVE] =
    {
        .name = _("TM34"),
        .itemId = ITEM_TM34,
        .price = 3000,
        .description = sTM34Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FLAMETHROWER] =
    {
        .name = _("TM35"),
        .itemId = ITEM_TM35,
        .price = 3000,
        .description = sTM35Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SLUDGE_BOMB] =
    {
        .name = _("TM36"),
        .itemId = ITEM_TM36,
        .price = 1000,
        .description = sTM36Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SANDSTORM] =
    {
        .name = _("TM37"),
        .itemId = ITEM_TM37,
        .price = 2000,
        .description = sTM37Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FIRE_BLAST] =
    {
        .name = _("TM38"),
        .itemId = ITEM_TM38,
        .price = 5500,
        .description = sTM38Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ROCK_TOMB] =
    {
        .name = _("TM39"),
        .itemId = ITEM_TM39,
        .price = 3000,
        .description = sTM39Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_AERIAL_ACE] =
    {
        .name = _("TM40"),
        .itemId = ITEM_TM40,
        .price = 3000,
        .description = sTM40Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TORMENT] =
    {
        .name = _("TM41"),
        .itemId = ITEM_TM41,
        .price = 3000,
        .description = sTM41Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FACADE] =
    {
        .name = _("TM42"),
        .itemId = ITEM_TM42,
        .price = 3000,
        .description = sTM42Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SECRET_POWER] =
    {
        .name = _("TM43"),
        .itemId = ITEM_TM43,
        .price = 3000,
        .description = sTM43Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_REST] =
    {
        .name = _("TM44"),
        .itemId = ITEM_TM44,
        .price = 3000,
        .description = sTM44Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ATTRACT] =
    {
        .name = _("TM45"),
        .itemId = ITEM_TM45,
        .price = 3000,
        .description = sTM45Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THIEF] =
    {
        .name = _("TM46"),
        .itemId = ITEM_TM46,
        .price = 3000,
        .description = sTM46Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_STEEL_WING] =
    {
        .name = _("TM47"),
        .itemId = ITEM_TM47,
        .price = 3000,
        .description = sTM47Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SKILL_SWAP] =
    {
        .name = _("TM48"),
        .itemId = ITEM_TM48,
        .price = 3000,
        .description = sTM48Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SNATCH] =
    {
        .name = _("TM49"),
        .itemId = ITEM_TM49,
        .price = 3000,
        .description = sTM49Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_OVERHEAT] =
    {
        .name = _("TM50"),
        .itemId = ITEM_TM50,
        .price = 3000,
        .description = sTM50Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_CUT] =
    {
#if ENGLISH
        .name = _("HM01"),
#elif GERMAN
        .name = _("VM01"),
#endif
        .itemId = ITEM_HM01,
        .price = 0,
        .description = sHM01Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_FLY] =
    {
#if ENGLISH
        .name = _("HM02"),
#elif GERMAN
        .name = _("VM02"),
#endif
        .itemId = ITEM_HM02,
        .price = 0,
        .description = sHM02Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_SURF] =
    {
#if ENGLISH
        .name = _("HM03"),
#elif GERMAN
        .name = _("VM03"),
#endif
        .itemId = ITEM_HM03,
        .price = 0,
        .description = sHM03Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_STRENGTH] =
    {
#if ENGLISH
        .name = _("HM04"),
#elif GERMAN
        .name = _("VM04"),
#endif
        .itemId = ITEM_HM04,
        .price = 0,
        .description = sHM04Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_FLASH] =
    {
#if ENGLISH
        .name = _("HM05"),
#elif GERMAN
        .name = _("VM05"),
#endif
        .itemId = ITEM_HM05,
        .price = 0,
        .description = sHM05Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_ROCK_SMASH] =
    {
#if ENGLISH
        .name = _("HM06"),
#elif GERMAN
        .name = _("VM06"),
#endif
        .itemId = ITEM_HM06,
        .price = 0,
        .description = sHM06Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_WATERFALL] =
    {
#if ENGLISH
        .name = _("HM07"),
#elif GERMAN
        .name = _("VM07"),
#endif
        .itemId = ITEM_HM07,
        .price = 0,
        .description = sHM07Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_DIVE] =
    {
#if ENGLISH
        .name = _("HM08"),
#elif GERMAN
        .name = _("VM08"),
#endif
        .itemId = ITEM_HM08,
        .price = 0,
        .description = sHM08Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_15B] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_15C] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// FireRed/LeafGreen key items

    [ITEM_OAKS_PARCEL] =
    {
#if ENGLISH
        .name = _("OAK'S PARCEL"),
#elif GERMAN
        .name = _("EICHs PAKET"),
#endif
        .itemId = ITEM_OAKS_PARCEL,
        .price = 0,
        .description = sOaksParcelDesc,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POKE_FLUTE] =
    {
#if ENGLISH
        .name = _("POKé FLUTE"),
#elif GERMAN
        .name = _("POKéFLÖTE"),
#endif
        .itemId = ITEM_POKE_FLUTE,
        .price = 0,
        .description = sPokeFluteDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SECRET_KEY] =
    {
#if ENGLISH
        .name = _("SECRET KEY"),
#elif GERMAN
        .name = _("?-ÖFFNER"),
#endif
        .itemId = ITEM_SECRET_KEY,
        .price = 0,
        .description = sSecretKeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BIKE_VOUCHER] =
    {
#if ENGLISH
        .name = _("BIKE VOUCHER"),
#elif GERMAN
        .name = _("RAD-COUPON"),
#endif
        .itemId = ITEM_BIKE_VOUCHER,
        .price = 0,
        .description = sBikeVoucherDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GOLD_TEETH] =
    {
#if ENGLISH
        .name = _("GOLD TEETH"),
#elif GERMAN
        .name = _("GOLDZÄHNE"),
#endif
        .itemId = ITEM_GOLD_TEETH,
        .price = 0,
        .description = sGoldTeethDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_OLD_AMBER] =
    {
#if ENGLISH
        .name = _("OLD AMBER"),
#elif GERMAN
        .name = _("ALTBERNSTEIN"),
#endif
        .itemId = ITEM_OLD_AMBER,
        .price = 0,
        .description = sOldAmberDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CARD_KEY] =
    {
#if ENGLISH
        .name = _("CARD KEY"),
#elif GERMAN
        .name = _("TÜRÖFFNER"),
#endif
        .itemId = ITEM_CARD_KEY,
        .price = 0,
        .description = sCardKeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LIFT_KEY] =
    {
#if ENGLISH
        .name = _("LIFT KEY"),
#elif GERMAN
        .name = _("LIFTÖFFNER"),
#endif
        .itemId = ITEM_LIFT_KEY,
        .price = 0,
        .description = sLiftKeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_HELIX_FOSSIL] =
    {
#if ENGLISH
        .name = _("HELIX FOSSIL"),
#elif GERMAN
        .name = _("HELIXFOSSIL"),
#endif
        .itemId = ITEM_HELIX_FOSSIL,
        .price = 0,
        .description = sHelixFossilDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DOME_FOSSIL] =
    {
#if ENGLISH
        .name = _("DOME FOSSIL"),
#elif GERMAN
        .name = _("DOMFOSSIL"),
#endif
        .itemId = ITEM_DOME_FOSSIL,
        .price = 0,
        .description = sDomeFossilDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SILPH_SCOPE] =
    {
        .name = _("SILPH SCOPE"),
        .itemId = ITEM_SILPH_SCOPE,
        .price = 0,
        .description = sSilphScopeDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BICYCLE] =
    {
#if ENGLISH
        .name = _("BICYCLE"),
#elif GERMAN
        .name = _("FAHRRAD"),
#endif
        .itemId = ITEM_BICYCLE,
        .price = 0,
        .description = sBicycleDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TOWN_MAP] =
    {
#if ENGLISH
        .name = _("TOWN MAP"),
#elif GERMAN
        .name = _("KARTE"),
#endif
        .itemId = ITEM_TOWN_MAP,
        .price = 0,
        .description = sTownMapDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_VS_SEEKER] =
    {
#if ENGLISH
        .name = _("VS SEEKER"),
#elif GERMAN
        .name = _("KAMPFFAHNDER"),
#endif
        .itemId = ITEM_VS_SEEKER,
        .price = 0,
        .description = sVSSeekerDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_FAME_CHECKER] =
    {
#if ENGLISH
        .name = _("FAME CHECKER"),
#elif GERMAN
        .name = _("RUHMESDATEI"),
#endif
        .itemId = ITEM_FAME_CHECKER,
        .price = 0,
        .description = sFameCheckerDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TM_CASE] =
    {
#if ENGLISH
        .name = _("TM CASE"),
#elif GERMAN
        .name = _("VM/TM-BOX"),
#endif
        .itemId = ITEM_TM_CASE,
        .price = 0,
        .description = sTMCaseDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BERRY_POUCH] =
    {
#if ENGLISH
        .name = _("BERRY POUCH"),
#elif GERMAN
        .name = _("BEERENTÜTE"),
#endif
        .itemId = ITEM_BERRY_POUCH,
        .price = 0,
        .description = sBerryPouchDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TEACHY_TV] =
    {
#if ENGLISH
        .name = _("TEACHY TV"),
#elif GERMAN
        .name = _("LEHRKANAL"),
#endif
        .itemId = ITEM_TEACHY_TV,
        .price = 0,
        .description = sTeachyTVDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TRI_PASS] =
    {
        .name = _("TRI-PASS"),
        .itemId = ITEM_TRI_PASS,
        .price = 0,
        .description = sTriPassDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RAINBOW_PASS] =
    {
#if ENGLISH
        .name = _("RAINBOW PASS"),
#elif GERMAN
        .name = _("BUNT-PASS"),
#endif
        .itemId = ITEM_RAINBOW_PASS,
        .price = 0,
        .description = sRainbowPassDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TEA] =
    {
#if ENGLISH
        .name = _("TEA"),
#elif GERMAN
        .name = _("TEE"),
#endif
        .itemId = ITEM_TEA,
        .price = 0,
        .description = sTeaDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MYSTIC_TICKET] =
    {
#if ENGLISH
        .name = _("MYSTICTICKET"),
#elif GERMAN
        .name = _("GEHEIMTICKET"),
#endif
        .itemId = ITEM_MYSTIC_TICKET,
        .price = 0,
        .description = sMysticTicketDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_AURORA_TICKET] =
    {
        .name = _("AURORATICKET"),
        .itemId = ITEM_AURORA_TICKET,
        .price = 0,
        .description = sAuroraTicketDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POWDER_JAR] =
    {
#if ENGLISH
        .name = _("POWDER JAR"),
#elif GERMAN
        .name = _("PUDERDÖSCHEN"),
#endif
        .itemId = ITEM_POWDER_JAR,
        .price = 0,
        .description = sPowderJarDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PowderJar,
    },

    [ITEM_RUBY] =
    {
#if ENGLISH
        .name = _("RUBY"),
#elif GERMAN
        .name = _("RUBIN"),
#endif
        .itemId = ITEM_RUBY,
        .price = 0,
        .description = sRubyDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SAPPHIRE] =
    {
#if ENGLISH
        .name = _("SAPPHIRE"),
#elif GERMAN
        .name = _("SAPHIR"),
#endif
        .itemId = ITEM_SAPPHIRE,
        .price = 0,
        .description = sSapphireDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Emerald-specific key items

    [ITEM_MAGMA_EMBLEM] =
    {
#if ENGLISH
        .name = _("MAGMA EMBLEM"),
#elif GERMAN
        .name = _("MAGMAEMBLEM"),
#endif
        .itemId = ITEM_MAGMA_EMBLEM,
        .price = 0,
        .description = sMagmaEmblemDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_OLD_SEA_MAP] =
    {
#if ENGLISH
        .name = _("OLD SEA MAP"),
#elif GERMAN
        .name = _("ALTE KARTE"),
#endif
        .itemId = ITEM_OLD_SEA_MAP,
        .price = 0,
        .description = sOldSeaMapDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },
};
