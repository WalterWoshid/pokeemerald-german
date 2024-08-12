#if ENGLISH
const u8 gEasyChatWord_Appeal[] = _("APPEAL");
const u8 gEasyChatWord_Events[] = _("EVENTS");
const u8 gEasyChatWord_StayAtHome[] = _("STAY-AT-HOME");
const u8 gEasyChatWord_Berry[] = _("BERRY");
const u8 gEasyChatWord_Contest[] = _("CONTEST");
const u8 gEasyChatWord_Mc[] = _("MC");
const u8 gEasyChatWord_Judge[] = _("JUDGE");
const u8 gEasyChatWord_Super[] = _("SUPER");
const u8 gEasyChatWord_Stage[] = _("STAGE");
const u8 gEasyChatWord_HallOfFame[] = _("HALL OF FAME");
const u8 gEasyChatWord_Evolution[] = _("EVOLUTION");
const u8 gEasyChatWord_Hyper[] = _("HYPER");
const u8 gEasyChatWord_BattleTower[] = _("BATTLE TOWER");
const u8 gEasyChatWord_Leaders[] = _("LEADERS");
const u8 gEasyChatWord_BattleRoom[] = _("BATTLE ROOM");
const u8 gEasyChatWord_Hidden[] = _("HIDDEN");
const u8 gEasyChatWord_SecretBase[] = _("SECRET BASE");
const u8 gEasyChatWord_Blend[] = _("BLEND");
const u8 gEasyChatWord_POKEBLOCK[] = _("{POKEBLOCK}");
const u8 gEasyChatWord_Master[] = _("MASTER");
const u8 gEasyChatWord_Rank[] = _("RANK");
const u8 gEasyChatWord_Ribbon[] = _("RIBBON");
const u8 gEasyChatWord_Crush[] = _("CRUSH");
const u8 gEasyChatWord_Direct[] = _("DIRECT");
const u8 gEasyChatWord_Tower[] = _("TOWER");
const u8 gEasyChatWord_Union[] = _("UNION");
const u8 gEasyChatWord_Room[] = _("ROOM");
const u8 gEasyChatWord_Wireless[] = _("WIRELESS");
const u8 gEasyChatWord_Frontier[] = _("FRONTIER");
#elif GERMAN
const u8 gEasyChatWord_Appeal[] = _("AUSDRUCK");
const u8 gEasyChatWord_Events[] = _("EVENTS");
const u8 gEasyChatWord_StayAtHome[] = _("BABYSITTEN");
const u8 gEasyChatWord_Berry[] = _("BEERE");
const u8 gEasyChatWord_Contest[] = _("WETTBEWERB");
const u8 gEasyChatWord_Mc[] = _("MC");
const u8 gEasyChatWord_Judge[] = _("JUROR");
const u8 gEasyChatWord_Super[] = _("SUPER");
const u8 gEasyChatWord_Stage[] = _("BÜHNE");
const u8 gEasyChatWord_HallOfFame[] = _("RUHMESHALLE");
const u8 gEasyChatWord_Evolution[] = _("ENTWICKLUNG");
const u8 gEasyChatWord_Hyper[] = _("HYPER");
const u8 gEasyChatWord_BattleTower[] = _("DUELLTURM");
const u8 gEasyChatWord_Leaders[] = _("LEITER");
const u8 gEasyChatWord_BattleRoom[] = _("KAMPFRAUM");
const u8 gEasyChatWord_Hidden[] = _("VERSTECKTE");
const u8 gEasyChatWord_SecretBase[] = _("GEHEIMBASIS");
const u8 gEasyChatWord_Blend[] = _("MIXEN");
const u8 gEasyChatWord_POKEBLOCK[] = _("{POKEBLOCK}");
const u8 gEasyChatWord_Master[] = _("MEISTER");
const u8 gEasyChatWord_Rank[] = _("KLASSE");
const u8 gEasyChatWord_Ribbon[] = _("BAND");
const u8 gEasyChatWord_Crush[] = _("MÜHLE");
const u8 gEasyChatWord_Direct[] = _("DIREKT");
const u8 gEasyChatWord_Tower[] = _("TURM");
const u8 gEasyChatWord_Union[] = _("KONNEX");
const u8 gEasyChatWord_Room[] = _("KLUB");
const u8 gEasyChatWord_Wireless[] = _("DRAHTLOS");
const u8 gEasyChatWord_Frontier[] = _("ZONE");
#endif

const struct EasyChatWordInfo gEasyChatGroup_Events[] = {
    [EC_INDEX(EC_WORD_APPEAL)] =
    {
        .text = gEasyChatWord_Appeal,
        .alphabeticalOrder = 0,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVENTS)] =
    {
        .text = gEasyChatWord_Events,
#if ENGLISH
        .alphabeticalOrder = 14,
#elif GERMAN
        .alphabeticalOrder = 2,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STAY_AT_HOME)] =
    {
        .text = gEasyChatWord_StayAtHome,
#if ENGLISH
        .alphabeticalOrder = 12,
#elif GERMAN
        .alphabeticalOrder = 21,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BERRY)] =
    {
        .text = gEasyChatWord_Berry,
        .alphabeticalOrder = 3,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONTEST)] =
    {
        .text = gEasyChatWord_Contest,
#if ENGLISH
        .alphabeticalOrder = 17,
#elif GERMAN
        .alphabeticalOrder = 8,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MC)] =
    {
        .text = gEasyChatWord_Mc,
#if ENGLISH
        .alphabeticalOrder = 4,
#elif GERMAN
        .alphabeticalOrder = 23,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_JUDGE)] =
    {
        .text = gEasyChatWord_Judge,
#if ENGLISH
        .alphabeticalOrder = 22,
#elif GERMAN
        .alphabeticalOrder = 27,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SUPER)] =
    {
        .text = gEasyChatWord_Super,
#if ENGLISH
        .alphabeticalOrder = 23,
#elif GERMAN
        .alphabeticalOrder = 12,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STAGE)] =
    {
        .text = gEasyChatWord_Stage,
#if ENGLISH
        .alphabeticalOrder = 1,
#elif GERMAN
        .alphabeticalOrder = 10,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HALL_OF_FAME)] =
    {
        .text = gEasyChatWord_HallOfFame,
#if ENGLISH
        .alphabeticalOrder = 10,
#elif GERMAN
        .alphabeticalOrder = 1,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVOLUTION)] =
    {
        .text = gEasyChatWord_Evolution,
#if ENGLISH
        .alphabeticalOrder = 28,
#elif GERMAN
        .alphabeticalOrder = 16,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HYPER)] =
    {
        .text = gEasyChatWord_Hyper,
#if ENGLISH
        .alphabeticalOrder = 9,
#elif GERMAN
        .alphabeticalOrder = 11,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BATTLE_TOWER)] =
    {
        .text = gEasyChatWord_BattleTower,
#if ENGLISH
        .alphabeticalOrder = 15,
#elif GERMAN
        .alphabeticalOrder = 6,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEADERS)] =
    {
        .text = gEasyChatWord_Leaders,
#if ENGLISH
        .alphabeticalOrder = 11,
#elif GERMAN
        .alphabeticalOrder = 14,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BATTLE_ROOM)] =
    {
        .text = gEasyChatWord_BattleRoom,
#if ENGLISH
        .alphabeticalOrder = 6,
#elif GERMAN
        .alphabeticalOrder = 20,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIDDEN)] =
    {
        .text = gEasyChatWord_Hidden,
#if ENGLISH
        .alphabeticalOrder = 13,
#elif GERMAN
        .alphabeticalOrder = 26,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SECRET_BASE)] =
    {
        .text = gEasyChatWord_SecretBase,
#if ENGLISH
        .alphabeticalOrder = 19,
#elif GERMAN
        .alphabeticalOrder = 25,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BLEND)] =
    {
        .text = gEasyChatWord_Blend,
#if ENGLISH
        .alphabeticalOrder = 5,
#elif GERMAN
        .alphabeticalOrder = 13,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKEBLOCK)] =
    {
        .text = gEasyChatWord_POKEBLOCK,
#if ENGLISH
        .alphabeticalOrder = 18,
#elif GERMAN
        .alphabeticalOrder = 5,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MASTER)] =
    {
        .text = gEasyChatWord_Master,
#if ENGLISH
        .alphabeticalOrder = 20,
#elif GERMAN
        .alphabeticalOrder = 19,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RANK)] =
    {
        .text = gEasyChatWord_Rank,
#if ENGLISH
        .alphabeticalOrder = 21,
#elif GERMAN
        .alphabeticalOrder = 17,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RIBBON)] =
    {
        .text = gEasyChatWord_Ribbon,
#if ENGLISH
        .alphabeticalOrder = 26,
#elif GERMAN
        .alphabeticalOrder = 22,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CRUSH)] =
    {
        .text = gEasyChatWord_Crush,
#if ENGLISH
        .alphabeticalOrder = 16,
#elif GERMAN
        .alphabeticalOrder = 18,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DIRECT)] =
    {
        .text = gEasyChatWord_Direct,
#if ENGLISH
        .alphabeticalOrder = 8,
#elif GERMAN
        .alphabeticalOrder = 9,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOWER)] =
    {
        .text = gEasyChatWord_Tower,
#if ENGLISH
        .alphabeticalOrder = 2,
#elif GERMAN
        .alphabeticalOrder = 7,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNION)] =
    {
        .text = gEasyChatWord_Union,
#if ENGLISH
        .alphabeticalOrder = 7,
#elif GERMAN
        .alphabeticalOrder = 24,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ROOM)] =
    {
        .text = gEasyChatWord_Room,
#if ENGLISH
        .alphabeticalOrder = 24,
#elif GERMAN
        .alphabeticalOrder = 15,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WIRELESS)] =
    {
        .text = gEasyChatWord_Wireless,
#if ENGLISH
        .alphabeticalOrder = 25,
#elif GERMAN
        .alphabeticalOrder = 4,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FRONTIER)] =
    {
        .text = gEasyChatWord_Frontier,
#if ENGLISH
        .alphabeticalOrder = 27,
#elif GERMAN
        .alphabeticalOrder = 28,
#endif
        .enabled = TRUE,
    },
};
