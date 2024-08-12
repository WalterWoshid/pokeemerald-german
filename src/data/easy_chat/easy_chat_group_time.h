#if ENGLISH
const u8 gEasyChatWord_Fall[] = _("FALL");
const u8 gEasyChatWord_Morning[] = _("MORNING");
const u8 gEasyChatWord_Tomorrow[] = _("TOMORROW");
const u8 gEasyChatWord_Last[] = _("LAST");
const u8 gEasyChatWord_Day[] = _("DAY");
const u8 gEasyChatWord_Sometime[] = _("SOMETIME");
const u8 gEasyChatWord_Always[] = _("ALWAYS");
const u8 gEasyChatWord_Current[] = _("CURRENT");
const u8 gEasyChatWord_Forever[] = _("FOREVER");
const u8 gEasyChatWord_Days[] = _("DAYS");
const u8 gEasyChatWord_End[] = _("END");
const u8 gEasyChatWord_Tuesday[] = _("TUESDAY");
const u8 gEasyChatWord_Yesterday[] = _("YESTERDAY");
const u8 gEasyChatWord_Today[] = _("TODAY");
const u8 gEasyChatWord_Friday[] = _("FRIDAY");
const u8 gEasyChatWord_Monday[] = _("MONDAY");
const u8 gEasyChatWord_Later[] = _("LATER");
const u8 gEasyChatWord_Earlier[] = _("EARLIER");
const u8 gEasyChatWord_Another[] = _("ANOTHER");
const u8 gEasyChatWord_Time[] = _("TIME");
const u8 gEasyChatWord_Finish[] = _("FINISH");
const u8 gEasyChatWord_Wednesday[] = _("WEDNESDAY");
const u8 gEasyChatWord_Soon[] = _("SOON");
const u8 gEasyChatWord_Start[] = _("START");
const u8 gEasyChatWord_Month[] = _("MONTH");
const u8 gEasyChatWord_Stop[] = _("STOP");
const u8 gEasyChatWord_Now[] = _("NOW");
const u8 gEasyChatWord_Final[] = _("FINAL");
const u8 gEasyChatWord_Next[] = _("NEXT");
const u8 gEasyChatWord_Age[] = _("AGE");
const u8 gEasyChatWord_Saturday[] = _("SATURDAY");
const u8 gEasyChatWord_Summer[] = _("SUMMER");
const u8 gEasyChatWord_Sunday[] = _("SUNDAY");
const u8 gEasyChatWord_Beginning[] = _("BEGINNING");
const u8 gEasyChatWord_Spring[] = _("SPRING");
const u8 gEasyChatWord_Daytime[] = _("DAYTIME");
const u8 gEasyChatWord_Winter[] = _("WINTER");
const u8 gEasyChatWord_Daily[] = _("DAILY");
const u8 gEasyChatWord_Olden[] = _("OLDEN");
const u8 gEasyChatWord_Almost[] = _("ALMOST");
const u8 gEasyChatWord_Nearly[] = _("NEARLY");
const u8 gEasyChatWord_Thursday[] = _("THURSDAY");
const u8 gEasyChatWord_Nighttime[] = _("NIGHTTIME");
const u8 gEasyChatWord_Night[] = _("NIGHT");
const u8 gEasyChatWord_Week[] = _("WEEK");
#elif GERMAN
const u8 gEasyChatWord_Fall[] = _("HERBST");
const u8 gEasyChatWord_Morning[] = _("MORGEN");
const u8 gEasyChatWord_Tomorrow[] = _("ÜBERMORGEN");
const u8 gEasyChatWord_Last[] = _("LETZTE(N)");
const u8 gEasyChatWord_Day[] = _("TAG");
const u8 gEasyChatWord_Sometime[] = _("IRGENDWANN");
const u8 gEasyChatWord_Always[] = _("IMMER");
const u8 gEasyChatWord_Current[] = _("MOMENTAN");
const u8 gEasyChatWord_Forever[] = _("EWIG");
const u8 gEasyChatWord_Days[] = _("TAGE");
const u8 gEasyChatWord_End[] = _("ENDE");
const u8 gEasyChatWord_Tuesday[] = _("DIENSTAG");
const u8 gEasyChatWord_Yesterday[] = _("GESTERN");
const u8 gEasyChatWord_Today[] = _("HEUTE");
const u8 gEasyChatWord_Friday[] = _("FREITAG");
const u8 gEasyChatWord_Monday[] = _("MONTAG");
const u8 gEasyChatWord_Later[] = _("SPÄTER");
const u8 gEasyChatWord_Earlier[] = _("FRÜHER");
const u8 gEasyChatWord_Another[] = _("AM ANDEREN");
const u8 gEasyChatWord_Time[] = _("ZEIT");
const u8 gEasyChatWord_Finish[] = _("SCHLUSS");
const u8 gEasyChatWord_Wednesday[] = _("MITTWOCH");
const u8 gEasyChatWord_Soon[] = _("BALD");
const u8 gEasyChatWord_Start[] = _("START");
const u8 gEasyChatWord_Month[] = _("MONAT");
const u8 gEasyChatWord_Stop[] = _("STOPP");
const u8 gEasyChatWord_Now[] = _("JETZT");
const u8 gEasyChatWord_Final[] = _("LETZTER");
const u8 gEasyChatWord_Next[] = _("NÄCHSTES");
const u8 gEasyChatWord_Age[] = _("ALTER");
const u8 gEasyChatWord_Saturday[] = _("SAMSTAG");
const u8 gEasyChatWord_Summer[] = _("SOMMER");
const u8 gEasyChatWord_Sunday[] = _("SONNTAG");
const u8 gEasyChatWord_Beginning[] = _("ANFANG");
const u8 gEasyChatWord_Spring[] = _("FRÜHLING");
const u8 gEasyChatWord_Daytime[] = _("TAGESZEIT");
const u8 gEasyChatWord_Winter[] = _("WINTER");
const u8 gEasyChatWord_Daily[] = _("TÄGLICH");
const u8 gEasyChatWord_Olden[] = _("DAMALS");
const u8 gEasyChatWord_Almost[] = _("FAST");
const u8 gEasyChatWord_Nearly[] = _("BEINAHE");
const u8 gEasyChatWord_Thursday[] = _("DONNERSTAG");
const u8 gEasyChatWord_Nighttime[] = _("BETTZEIT");
const u8 gEasyChatWord_Night[] = _("NACHT");
const u8 gEasyChatWord_Week[] = _("WOCHE");
#endif

const struct EasyChatWordInfo gEasyChatGroup_Time[] = {
    [EC_INDEX(EC_WORD_FALL)] =
    {
        .text = gEasyChatWord_Fall,
        .alphabeticalOrder = 29,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MORNING)] =
    {
        .text = gEasyChatWord_Morning,
#if ENGLISH
        .alphabeticalOrder = 39,
#elif GERMAN
        .alphabeticalOrder = 18,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOMORROW)] =
    {
        .text = gEasyChatWord_Tomorrow,
#if ENGLISH
        .alphabeticalOrder = 6,
#elif GERMAN
        .alphabeticalOrder = 33,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LAST)] =
    {
        .text = gEasyChatWord_Last,
#if ENGLISH
        .alphabeticalOrder = 18,
#elif GERMAN
        .alphabeticalOrder = 22,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DAY)] =
    {
        .text = gEasyChatWord_Day,
#if ENGLISH
        .alphabeticalOrder = 33,
#elif GERMAN
        .alphabeticalOrder = 40,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SOMETIME)] =
    {
        .text = gEasyChatWord_Sometime,
#if ENGLISH
        .alphabeticalOrder = 7,
#elif GERMAN
        .alphabeticalOrder = 42,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALWAYS)] =
    {
        .text = gEasyChatWord_Always,
#if ENGLISH
        .alphabeticalOrder = 37,
#elif GERMAN
        .alphabeticalOrder = 38,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CURRENT)] =
    {
        .text = gEasyChatWord_Current,
#if ENGLISH
        .alphabeticalOrder = 4,
#elif GERMAN
        .alphabeticalOrder = 11,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FOREVER)] =
    {
        .text = gEasyChatWord_Forever,
#if ENGLISH
        .alphabeticalOrder = 9,
#elif GERMAN
        .alphabeticalOrder = 41,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DAYS)] =
    {
        .text = gEasyChatWord_Days,
#if ENGLISH
        .alphabeticalOrder = 35,
#elif GERMAN
        .alphabeticalOrder = 10,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_END)] =
    {
        .text = gEasyChatWord_End,
#if ENGLISH
        .alphabeticalOrder = 17,
#elif GERMAN
        .alphabeticalOrder = 8,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TUESDAY)] =
    {
        .text = gEasyChatWord_Tuesday,
#if ENGLISH
        .alphabeticalOrder = 10,
#elif GERMAN
        .alphabeticalOrder = 39,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YESTERDAY)] =
    {
        .text = gEasyChatWord_Yesterday,
#if ENGLISH
        .alphabeticalOrder = 0,
#elif GERMAN
        .alphabeticalOrder = 14,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TODAY)] =
    {
        .text = gEasyChatWord_Today,
#if ENGLISH
        .alphabeticalOrder = 27,
#elif GERMAN
        .alphabeticalOrder = 17,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FRIDAY)] =
    {
        .text = gEasyChatWord_Friday,
#if ENGLISH
        .alphabeticalOrder = 20,
#elif GERMAN
        .alphabeticalOrder = 34,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MONDAY)] =
    {
        .text = gEasyChatWord_Monday,
#if ENGLISH
        .alphabeticalOrder = 8,
#elif GERMAN
        .alphabeticalOrder = 12,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LATER)] =
    {
        .text = gEasyChatWord_Later,
#if ENGLISH
        .alphabeticalOrder = 14,
#elif GERMAN
        .alphabeticalOrder = 0,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EARLIER)] =
    {
        .text = gEasyChatWord_Earlier,
#if ENGLISH
        .alphabeticalOrder = 3,
#elif GERMAN
        .alphabeticalOrder = 13,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANOTHER)] =
    {
        .text = gEasyChatWord_Another,
#if ENGLISH
        .alphabeticalOrder = 16,
#elif GERMAN
        .alphabeticalOrder = 6,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TIME)] =
    {
        .text = gEasyChatWord_Time,
#if ENGLISH
        .alphabeticalOrder = 15,
#elif GERMAN
        .alphabeticalOrder = 5,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FINISH)] =
    {
        .text = gEasyChatWord_Finish,
#if ENGLISH
        .alphabeticalOrder = 24,
#elif GERMAN
        .alphabeticalOrder = 26,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEDNESDAY)] =
    {
        .text = gEasyChatWord_Wednesday,
#if ENGLISH
        .alphabeticalOrder = 1,
#elif GERMAN
        .alphabeticalOrder = 3,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SOON)] =
    {
        .text = gEasyChatWord_Soon,
#if ENGLISH
        .alphabeticalOrder = 40,
#elif GERMAN
        .alphabeticalOrder = 27,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_START)] =
    {
        .text = gEasyChatWord_Start,
#if ENGLISH
        .alphabeticalOrder = 28,
#elif GERMAN
        .alphabeticalOrder = 21,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MONTH)] =
    {
        .text = gEasyChatWord_Month,
#if ENGLISH
        .alphabeticalOrder = 43,
#elif GERMAN
        .alphabeticalOrder = 7,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STOP)] =
    {
        .text = gEasyChatWord_Stop,
#if ENGLISH
        .alphabeticalOrder = 42,
#elif GERMAN
        .alphabeticalOrder = 24,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOW)] =
    {
        .text = gEasyChatWord_Now,
#if ENGLISH
        .alphabeticalOrder = 26,
#elif GERMAN
        .alphabeticalOrder = 15,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FINAL)] =
    {
        .text = gEasyChatWord_Final,
#if ENGLISH
        .alphabeticalOrder = 38,
#elif GERMAN
        .alphabeticalOrder = 1,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEXT)] =
    {
        .text = gEasyChatWord_Next,
#if ENGLISH
        .alphabeticalOrder = 30,
#elif GERMAN
        .alphabeticalOrder = 28,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AGE)] =
    {
        .text = gEasyChatWord_Age,
#if ENGLISH
        .alphabeticalOrder = 5,
#elif GERMAN
        .alphabeticalOrder = 43,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SATURDAY)] =
    {
        .text = gEasyChatWord_Saturday,
#if ENGLISH
        .alphabeticalOrder = 22,
#elif GERMAN
        .alphabeticalOrder = 30,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SUMMER)] =
    {
        .text = gEasyChatWord_Summer,
#if ENGLISH
        .alphabeticalOrder = 34,
#elif GERMAN
        .alphabeticalOrder = 20,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SUNDAY)] =
    {
        .text = gEasyChatWord_Sunday,
#if ENGLISH
        .alphabeticalOrder = 23,
#elif GERMAN
        .alphabeticalOrder = 31,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEGINNING)] =
    {
        .text = gEasyChatWord_Beginning,
#if ENGLISH
        .alphabeticalOrder = 25,
#elif GERMAN
        .alphabeticalOrder = 32,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SPRING)] =
    {
        .text = gEasyChatWord_Spring,
#if ENGLISH
        .alphabeticalOrder = 31,
#elif GERMAN
        .alphabeticalOrder = 16,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DAYTIME)] =
    {
        .text = gEasyChatWord_Daytime,
#if ENGLISH
        .alphabeticalOrder = 32,
#elif GERMAN
        .alphabeticalOrder = 23,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WINTER)] =
    {
        .text = gEasyChatWord_Winter,
#if ENGLISH
        .alphabeticalOrder = 41,
#elif GERMAN
        .alphabeticalOrder = 25,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DAILY)] =
    {
        .text = gEasyChatWord_Daily,
#if ENGLISH
        .alphabeticalOrder = 19,
#elif GERMAN
        .alphabeticalOrder = 4,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OLDEN)] =
    {
        .text = gEasyChatWord_Olden,
#if ENGLISH
        .alphabeticalOrder = 13,
#elif GERMAN
        .alphabeticalOrder = 9,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALMOST)] =
    {
        .text = gEasyChatWord_Almost,
#if ENGLISH
        .alphabeticalOrder = 2,
#elif GERMAN
        .alphabeticalOrder = 35,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEARLY)] =
    {
        .text = gEasyChatWord_Nearly,
#if ENGLISH
        .alphabeticalOrder = 11,
#elif GERMAN
        .alphabeticalOrder = 37,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THURSDAY)] =
    {
        .text = gEasyChatWord_Thursday,
#if ENGLISH
        .alphabeticalOrder = 21,
#elif GERMAN
        .alphabeticalOrder = 2,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NIGHTTIME)] =
    {
        .text = gEasyChatWord_Nighttime,
#if ENGLISH
        .alphabeticalOrder = 44,
#elif GERMAN
        .alphabeticalOrder = 36,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NIGHT)] =
    {
        .text = gEasyChatWord_Night,
#if ENGLISH
        .alphabeticalOrder = 36,
#elif GERMAN
        .alphabeticalOrder = 44,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEEK)] =
    {
        .text = gEasyChatWord_Week,
#if ENGLISH
        .alphabeticalOrder = 12,
#elif GERMAN
        .alphabeticalOrder = 19,
#endif
        .enabled = TRUE,
    },
};
