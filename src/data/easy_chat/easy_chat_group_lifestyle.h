#if ENGLISH
const u8 gEasyChatWord_Chores[] = _("CHORES");
const u8 gEasyChatWord_Home[] = _("HOME");
const u8 gEasyChatWord_Money[] = _("MONEY");
const u8 gEasyChatWord_Allowance[] = _("ALLOWANCE");
const u8 gEasyChatWord_Bath[] = _("BATH");
const u8 gEasyChatWord_Conversation[] = _("CONVERSATION");
const u8 gEasyChatWord_School[] = _("SCHOOL");
const u8 gEasyChatWord_Commemorate[] = _("COMMEMORATE");
const u8 gEasyChatWord_Habit[] = _("HABIT");
const u8 gEasyChatWord_Group[] = _("GROUP");
const u8 gEasyChatWord_Word[] = _("WORD");
const u8 gEasyChatWord_Store[] = _("STORE");
const u8 gEasyChatWord_Service[] = _("SERVICE");
const u8 gEasyChatWord_Work[] = _("WORK");
const u8 gEasyChatWord_System[] = _("SYSTEM");
const u8 gEasyChatWord_Train[] = _("TRAIN");
const u8 gEasyChatWord_Class[] = _("CLASS");
const u8 gEasyChatWord_Lessons[] = _("LESSONS");
const u8 gEasyChatWord_Information[] = _("INFORMATION");
const u8 gEasyChatWord_Living[] = _("LIVING");
const u8 gEasyChatWord_Teacher[] = _("TEACHER");
const u8 gEasyChatWord_Tournament[] = _("TOURNAMENT");
const u8 gEasyChatWord_Letter[] = _("LETTER");
const u8 gEasyChatWord_Event[] = _("EVENT");
const u8 gEasyChatWord_Digital[] = _("DIGITAL");
const u8 gEasyChatWord_Test[] = _("TEST");
const u8 gEasyChatWord_DeptStore[] = _("DEPT. STORE");
const u8 gEasyChatWord_Television[] = _("TELEVISION");
const u8 gEasyChatWord_Phone[] = _("PHONE");
const u8 gEasyChatWord_Item[] = _("ITEM");
const u8 gEasyChatWord_Name[] = _("NAME");
const u8 gEasyChatWord_News[] = _("NEWS");
const u8 gEasyChatWord_Popular[] = _("POPULAR");
const u8 gEasyChatWord_Party[] = _("PARTY");
const u8 gEasyChatWord_Study[] = _("STUDY");
const u8 gEasyChatWord_Machine[] = _("MACHINE");
const u8 gEasyChatWord_Mail[] = _("MAIL");
const u8 gEasyChatWord_Message[] = _("MESSAGE");
const u8 gEasyChatWord_Promise[] = _("PROMISE");
const u8 gEasyChatWord_Dream[] = _("DREAM");
const u8 gEasyChatWord_Kindergarten[] = _("KINDERGARTEN");
const u8 gEasyChatWord_Life[] = _("LIFE");
const u8 gEasyChatWord_Radio[] = _("RADIO");
const u8 gEasyChatWord_Rental[] = _("RENTAL");
const u8 gEasyChatWord_World[] = _("WORLD");
#elif GERMAN
const u8 gEasyChatWord_Chores[] = _("PFLICHTEN");
const u8 gEasyChatWord_Home[] = _("HEIM");
const u8 gEasyChatWord_Money[] = _("GELD");
const u8 gEasyChatWord_Allowance[] = _("TASCHENGELD");
const u8 gEasyChatWord_Bath[] = _("BAD");
const u8 gEasyChatWord_Conversation[] = _("GESPRÄCH");
const u8 gEasyChatWord_School[] = _("SCHULE");
const u8 gEasyChatWord_Commemorate[] = _("GEDENKEN");
const u8 gEasyChatWord_Habit[] = _("GEWOHNHEIT");
const u8 gEasyChatWord_Group[] = _("GRUPPE");
const u8 gEasyChatWord_Word[] = _("WORT");
const u8 gEasyChatWord_Store[] = _("LAGER");
const u8 gEasyChatWord_Service[] = _("SERVICE");
const u8 gEasyChatWord_Work[] = _("ARBEIT");
const u8 gEasyChatWord_System[] = _("SYSTEM");
const u8 gEasyChatWord_Train[] = _("TRAINIEREN");
const u8 gEasyChatWord_Class[] = _("LEKTION");
const u8 gEasyChatWord_Lessons[] = _("UNTERRICHT");
const u8 gEasyChatWord_Information[] = _("INFORMATION");
const u8 gEasyChatWord_Living[] = _("LEBENDIG");
const u8 gEasyChatWord_Teacher[] = _("LEHRER");
const u8 gEasyChatWord_Tournament[] = _("TURNIER");
const u8 gEasyChatWord_Letter[] = _("BRIEF");
const u8 gEasyChatWord_Event[] = _("GESCHEHEN");
const u8 gEasyChatWord_Digital[] = _("DIGITALES");
const u8 gEasyChatWord_Test[] = _("TEST");
const u8 gEasyChatWord_DeptStore[] = _("KAUFHAUS");
const u8 gEasyChatWord_Television[] = _("FERNSEHER");
const u8 gEasyChatWord_Phone[] = _("TELEFON");
const u8 gEasyChatWord_Item[] = _("ITEM");
const u8 gEasyChatWord_Name[] = _("NAME");
const u8 gEasyChatWord_News[] = _("NEUIGKEITEN");
const u8 gEasyChatWord_Popular[] = _("POPULÄR");
const u8 gEasyChatWord_Party[] = _("PARTY");
const u8 gEasyChatWord_Study[] = _("LERNEN");
const u8 gEasyChatWord_Machine[] = _("MASCHINE");
const u8 gEasyChatWord_Mail[] = _("POST");
const u8 gEasyChatWord_Message[] = _("MITTEILUNG");
const u8 gEasyChatWord_Promise[] = _("VERSPRECHEN");
const u8 gEasyChatWord_Dream[] = _("TRAUM");
const u8 gEasyChatWord_Kindergarten[] = _("KINDERGARTEN");
const u8 gEasyChatWord_Life[] = _("LEBEN");
const u8 gEasyChatWord_Radio[] = _("RADIO");
const u8 gEasyChatWord_Rental[] = _("MIETE");
const u8 gEasyChatWord_World[] = _("WELT");
#endif

const struct EasyChatWordInfo gEasyChatGroup_Lifestyle[] = {
    [EC_INDEX(EC_WORD_CHORES)] =
    {
        .text = gEasyChatWord_Chores,
#if ENGLISH
        .alphabeticalOrder = 3,
#elif GERMAN
        .alphabeticalOrder = 13,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOME)] =
    {
        .text = gEasyChatWord_Home,
        .alphabeticalOrder = 4,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MONEY)] =
    {
        .text = gEasyChatWord_Money,
#if ENGLISH
        .alphabeticalOrder = 0,
#elif GERMAN
        .alphabeticalOrder = 22,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALLOWANCE)] =
    {
        .text = gEasyChatWord_Allowance,
#if ENGLISH
        .alphabeticalOrder = 16,
#elif GERMAN
        .alphabeticalOrder = 24,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BATH)] =
    {
        .text = gEasyChatWord_Bath,
#if ENGLISH
        .alphabeticalOrder = 7,
#elif GERMAN
        .alphabeticalOrder = 27,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONVERSATION)] =
    {
        .text = gEasyChatWord_Conversation,
#if ENGLISH
        .alphabeticalOrder = 5,
#elif GERMAN
        .alphabeticalOrder = 7,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SCHOOL)] =
    {
        .text = gEasyChatWord_School,
#if ENGLISH
        .alphabeticalOrder = 26,
#elif GERMAN
        .alphabeticalOrder = 2,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COMMEMORATE)] =
    {
        .text = gEasyChatWord_Commemorate,
#if ENGLISH
        .alphabeticalOrder = 24,
#elif GERMAN
        .alphabeticalOrder = 23,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HABIT)] =
    {
        .text = gEasyChatWord_Habit,
#if ENGLISH
        .alphabeticalOrder = 39,
#elif GERMAN
        .alphabeticalOrder = 5,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GROUP)] =
    {
        .text = gEasyChatWord_Group,
#if ENGLISH
        .alphabeticalOrder = 23,
#elif GERMAN
        .alphabeticalOrder = 8,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORD)] =
    {
        .text = gEasyChatWord_Word,
        .alphabeticalOrder = 9,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STORE)] =
    {
        .text = gEasyChatWord_Store,
#if ENGLISH
        .alphabeticalOrder = 8,
#elif GERMAN
        .alphabeticalOrder = 1,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SERVICE)] =
    {
        .text = gEasyChatWord_Service,
#if ENGLISH
        .alphabeticalOrder = 1,
#elif GERMAN
        .alphabeticalOrder = 18,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORK)] =
    {
        .text = gEasyChatWord_Work,
#if ENGLISH
        .alphabeticalOrder = 18,
#elif GERMAN
        .alphabeticalOrder = 29,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SYSTEM)] =
    {
        .text = gEasyChatWord_System,
#if ENGLISH
        .alphabeticalOrder = 29,
#elif GERMAN
        .alphabeticalOrder = 26,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRAIN)] =
    {
        .text = gEasyChatWord_Train,
        .alphabeticalOrder = 40,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CLASS)] =
    {
        .text = gEasyChatWord_Class,
#if ENGLISH
        .alphabeticalOrder = 17,
#elif GERMAN
        .alphabeticalOrder = 11,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LESSONS)] =
    {
        .text = gEasyChatWord_Lessons,
#if ENGLISH
        .alphabeticalOrder = 22,
#elif GERMAN
        .alphabeticalOrder = 41,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INFORMATION)] =
    {
        .text = gEasyChatWord_Information,
#if ENGLISH
        .alphabeticalOrder = 41,
#elif GERMAN
        .alphabeticalOrder = 19,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIVING)] =
    {
        .text = gEasyChatWord_Living,
#if ENGLISH
        .alphabeticalOrder = 19,
#elif GERMAN
        .alphabeticalOrder = 20,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TEACHER)] =
    {
        .text = gEasyChatWord_Teacher,
#if ENGLISH
        .alphabeticalOrder = 35,
#elif GERMAN
        .alphabeticalOrder = 16,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOURNAMENT)] =
    {
        .text = gEasyChatWord_Tournament,
#if ENGLISH
        .alphabeticalOrder = 36,
#elif GERMAN
        .alphabeticalOrder = 34,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LETTER)] =
    {
        .text = gEasyChatWord_Letter,
#if ENGLISH
        .alphabeticalOrder = 37,
#elif GERMAN
        .alphabeticalOrder = 35,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVENT)] =
    {
        .text = gEasyChatWord_Event,
#if ENGLISH
        .alphabeticalOrder = 2,
#elif GERMAN
        .alphabeticalOrder = 43,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DIGITAL)] =
    {
        .text = gEasyChatWord_Digital,
#if ENGLISH
        .alphabeticalOrder = 30,
#elif GERMAN
        .alphabeticalOrder = 37,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TEST)] =
    {
        .text = gEasyChatWord_Test,
#if ENGLISH
        .alphabeticalOrder = 31,
#elif GERMAN
        .alphabeticalOrder = 30,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DEPT_STORE)] =
    {
        .text = gEasyChatWord_DeptStore,
#if ENGLISH
        .alphabeticalOrder = 33,
#elif GERMAN
        .alphabeticalOrder = 31,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TELEVISION)] =
    {
        .text = gEasyChatWord_Television,
#if ENGLISH
        .alphabeticalOrder = 28,
#elif GERMAN
        .alphabeticalOrder = 33,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PHONE)] =
    {
        .text = gEasyChatWord_Phone,
#if ENGLISH
        .alphabeticalOrder = 32,
#elif GERMAN
        .alphabeticalOrder = 0,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ITEM)] =
    {
        .text = gEasyChatWord_Item,
#if ENGLISH
        .alphabeticalOrder = 38,
#elif GERMAN
        .alphabeticalOrder = 32,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NAME)] =
    {
        .text = gEasyChatWord_Name,
#if ENGLISH
        .alphabeticalOrder = 42,
#elif GERMAN
        .alphabeticalOrder = 36,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEWS)] =
    {
        .text = gEasyChatWord_News,
#if ENGLISH
        .alphabeticalOrder = 43,
#elif GERMAN
        .alphabeticalOrder = 42,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POPULAR)] =
    {
        .text = gEasyChatWord_Popular,
        .alphabeticalOrder = 6,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PARTY)] =
    {
        .text = gEasyChatWord_Party,
        .alphabeticalOrder = 12,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STUDY)] =
    {
        .text = gEasyChatWord_Study,
#if ENGLISH
        .alphabeticalOrder = 11,
#elif GERMAN
        .alphabeticalOrder = 14,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MACHINE)] =
    {
        .text = gEasyChatWord_Machine,
#if ENGLISH
        .alphabeticalOrder = 34,
#elif GERMAN
        .alphabeticalOrder = 3,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MAIL)] =
    {
        .text = gEasyChatWord_Mail,
#if ENGLISH
        .alphabeticalOrder = 14,
#elif GERMAN
        .alphabeticalOrder = 28,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MESSAGE)] =
    {
        .text = gEasyChatWord_Message,
#if ENGLISH
        .alphabeticalOrder = 20,
#elif GERMAN
        .alphabeticalOrder = 25,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PROMISE)] =
    {
        .text = gEasyChatWord_Promise,
#if ENGLISH
        .alphabeticalOrder = 27,
#elif GERMAN
        .alphabeticalOrder = 15,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DREAM)] =
    {
        .text = gEasyChatWord_Dream,
#if ENGLISH
        .alphabeticalOrder = 25,
#elif GERMAN
        .alphabeticalOrder = 39,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KINDERGARTEN)] =
    {
        .text = gEasyChatWord_Kindergarten,
        .alphabeticalOrder = 21,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIFE)] =
    {
        .text = gEasyChatWord_Life,
#if ENGLISH
        .alphabeticalOrder = 15,
#elif GERMAN
        .alphabeticalOrder = 17,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RADIO)] =
    {
        .text = gEasyChatWord_Radio,
#if ENGLISH
        .alphabeticalOrder = 10,
#elif GERMAN
        .alphabeticalOrder = 38,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RENTAL)] =
    {
        .text = gEasyChatWord_Rental,
#if ENGLISH
        .alphabeticalOrder = 13,
#elif GERMAN
        .alphabeticalOrder = 44,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORLD)] =
    {
        .text = gEasyChatWord_World,
#if ENGLISH
        .alphabeticalOrder = 44,
#elif GERMAN
        .alphabeticalOrder = 10,
#endif
        .enabled = TRUE,
    },
};
