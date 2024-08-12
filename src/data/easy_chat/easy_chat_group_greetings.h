#if ENGLISH
const u8 gEasyChatWord_Thanks[] = _("THANKS");
const u8 gEasyChatWord_Yes[] = _("YES");
const u8 gEasyChatWord_HereGoes[] = _("HERE GOES");
const u8 gEasyChatWord_HereICome[] = _("HERE I COME");
const u8 gEasyChatWord_HereItIs[] = _("HERE IT IS");
const u8 gEasyChatWord_Yeah[] = _("YEAH");
const u8 gEasyChatWord_Welcome[] = _("WELCOME");
const u8 gEasyChatWord_Oi[] = _("OI");
const u8 gEasyChatWord_HowDo[] = _("HOW DO");
const u8 gEasyChatWord_Congrats[] = _("CONGRATS");
const u8 gEasyChatWord_GiveMe[] = _("GIVE ME");
const u8 gEasyChatWord_Sorry[] = _("SORRY");
const u8 gEasyChatWord_Apologize[] = _("APOLOGIZE");
const u8 gEasyChatWord_Forgive[] = _("FORGIVE");
const u8 gEasyChatWord_HeyThere[] = _("HEY, THERE");
const u8 gEasyChatWord_Hello[] = _("HELLO");
const u8 gEasyChatWord_GoodBye[] = _("GOOD-BYE");
const u8 gEasyChatWord_ThankYou[] = _("THANK YOU");
const u8 gEasyChatWord_IveArrived[] = _("I'VE ARRIVED");
const u8 gEasyChatWord_Pardon[] = _("PARDON");
const u8 gEasyChatWord_Excuse[] = _("EXCUSE");
const u8 gEasyChatWord_SeeYa[] = _("SEE YA");
const u8 gEasyChatWord_ExcuseMe[] = _("EXCUSE ME");
const u8 gEasyChatWord_WellThen[] = _("WELL, THEN");
const u8 gEasyChatWord_GoAhead[] = _("GO AHEAD");
const u8 gEasyChatWord_Appreciate[] = _("APPRECIATE");
const u8 gEasyChatWord_HeyQues[] = _("HEY?");
const u8 gEasyChatWord_WhatsUpQues[] = _("WHAT'S UP?");
const u8 gEasyChatWord_HuhQues[] = _("HUH?");
const u8 gEasyChatWord_No[] = _("NO");
const u8 gEasyChatWord_Hi[] = _("HI");
const u8 gEasyChatWord_YeahYeah[] = _("YEAH, YEAH");
const u8 gEasyChatWord_ByeBye[] = _("BYE-BYE");
const u8 gEasyChatWord_MeetYou[] = _("MEET YOU");
const u8 gEasyChatWord_Hey[] = _("HEY");
const u8 gEasyChatWord_Smell[] = _("SMELL");
const u8 gEasyChatWord_Listening[] = _("LISTENING");
const u8 gEasyChatWord_HooHah[] = _("HOO-HAH");
const u8 gEasyChatWord_Yahoo[] = _("YAHOO");
const u8 gEasyChatWord_Yo[] = _("YO");
const u8 gEasyChatWord_ComeOver[] = _("COME OVER");
const u8 gEasyChatWord_CountOn[] = _("COUNT ON");
#elif GERMAN
const u8 gEasyChatWord_Thanks[] = _("DANK");
const u8 gEasyChatWord_Yes[] = _("JA");
const u8 gEasyChatWord_HereGoes[] = _("HIER KOMMT");
const u8 gEasyChatWord_HereICome[] = _("HIER BIN ICH");
const u8 gEasyChatWord_HereItIs[] = _("HIER IST ES");
const u8 gEasyChatWord_Yeah[] = _("YEAH");
const u8 gEasyChatWord_Welcome[] = _("WILLKOMMEN");
const u8 gEasyChatWord_Oi[] = _("AU");
const u8 gEasyChatWord_HowDo[] = _("WIE");
const u8 gEasyChatWord_Congrats[] = _("GLÜCKWUNSCH");
const u8 gEasyChatWord_GiveMe[] = _("GIB");
const u8 gEasyChatWord_Sorry[] = _("SORRY");
const u8 gEasyChatWord_Apologize[] = _("VERZEIHUNG");
const u8 gEasyChatWord_Forgive[] = _("SCHON GUT");
const u8 gEasyChatWord_HeyThere[] = _("HEY DA");
const u8 gEasyChatWord_Hello[] = _("HALLO");
const u8 gEasyChatWord_GoodBye[] = _("TSCHÜSS");
const u8 gEasyChatWord_ThankYou[] = _("DANKE SCHÖN");
const u8 gEasyChatWord_IveArrived[] = _("ICH BIN DA");
const u8 gEasyChatWord_Pardon[] = _("PARDON");
const u8 gEasyChatWord_Excuse[] = _("TAGCHEN");
const u8 gEasyChatWord_SeeYa[] = _("BIS DANN");
const u8 gEasyChatWord_ExcuseMe[] = _("ENTSCHULDIGE");
const u8 gEasyChatWord_WellThen[] = _("NUN, DANN");
const u8 gEasyChatWord_GoAhead[] = _("WEITER SO");
const u8 gEasyChatWord_Appreciate[] = _("SCHÄTZEN");
const u8 gEasyChatWord_HeyQues[] = _("HEY?");
const u8 gEasyChatWord_WhatsUpQues[] = _("WAS IST LOS?");
const u8 gEasyChatWord_HuhQues[] = _("WIE?");
const u8 gEasyChatWord_No[] = _("NEIN");
const u8 gEasyChatWord_Hi[] = _("TAG AUCH");
const u8 gEasyChatWord_YeahYeah[] = _("YEAH, YEAH");
const u8 gEasyChatWord_ByeBye[] = _("TSCHAU");
const u8 gEasyChatWord_MeetYou[] = _("BIS BALD");
const u8 gEasyChatWord_Hey[] = _("HEY");
const u8 gEasyChatWord_Smell[] = _("GERUCH");
const u8 gEasyChatWord_Listening[] = _("HÖR ZU");
const u8 gEasyChatWord_HooHah[] = _("HUH HAH");
const u8 gEasyChatWord_Yahoo[] = _("JUCHUU");
const u8 gEasyChatWord_Yo[] = _("JEPP");
const u8 gEasyChatWord_ComeOver[] = _("ACH, KOMM");
const u8 gEasyChatWord_CountOn[] = _("ZÄHLEN AUF");
#endif

const struct EasyChatWordInfo gEasyChatGroup_Greetings[] = {
    [EC_INDEX(EC_WORD_THANKS)] =
    {
        .text = gEasyChatWord_Thanks,
#if ENGLISH
        .alphabeticalOrder = 12,
#elif GERMAN
        .alphabeticalOrder = 40,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YES)] =
    {
        .text = gEasyChatWord_Yes,
#if ENGLISH
        .alphabeticalOrder = 25,
#elif GERMAN
        .alphabeticalOrder = 7,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE_GOES)] =
    {
        .text = gEasyChatWord_HereGoes,
#if ENGLISH
        .alphabeticalOrder = 32,
#elif GERMAN
        .alphabeticalOrder = 33,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE_I_COME)] =
    {
        .text = gEasyChatWord_HereICome,
#if ENGLISH
        .alphabeticalOrder = 40,
#elif GERMAN
        .alphabeticalOrder = 21,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE_IT_IS)] =
    {
        .text = gEasyChatWord_HereItIs,
#if ENGLISH
        .alphabeticalOrder = 9,
#elif GERMAN
        .alphabeticalOrder = 0,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YEAH)] =
    {
        .text = gEasyChatWord_Yeah,
#if ENGLISH
        .alphabeticalOrder = 41,
#elif GERMAN
        .alphabeticalOrder = 17,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WELCOME)] =
    {
        .text = gEasyChatWord_Welcome,
#if ENGLISH
        .alphabeticalOrder = 20,
#elif GERMAN
        .alphabeticalOrder = 22,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OI)] =
    {
        .text = gEasyChatWord_Oi,
#if ENGLISH
        .alphabeticalOrder = 22,
#elif GERMAN
        .alphabeticalOrder = 35,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOW_DO)] =
    {
        .text = gEasyChatWord_HowDo,
#if ENGLISH
        .alphabeticalOrder = 13,
#elif GERMAN
        .alphabeticalOrder = 10,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONGRATS)] =
    {
        .text = gEasyChatWord_Congrats,
#if ENGLISH
        .alphabeticalOrder = 10,
#elif GERMAN
        .alphabeticalOrder = 9,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIVE_ME)] =
    {
        .text = gEasyChatWord_GiveMe,
#if ENGLISH
        .alphabeticalOrder = 24,
#elif GERMAN
        .alphabeticalOrder = 15,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SORRY)] =
    {
        .text = gEasyChatWord_Sorry,
#if ENGLISH
        .alphabeticalOrder = 16,
#elif GERMAN
        .alphabeticalOrder = 34,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APOLOGIZE)] =
    {
        .text = gEasyChatWord_Apologize,
#if ENGLISH
        .alphabeticalOrder = 15,
#elif GERMAN
        .alphabeticalOrder = 14,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FORGIVE)] =
    {
        .text = gEasyChatWord_Forgive,
#if ENGLISH
        .alphabeticalOrder = 2,
#elif GERMAN
        .alphabeticalOrder = 26,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEY_THERE)] =
    {
        .text = gEasyChatWord_HeyThere,
        .alphabeticalOrder = 3,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HELLO)] =
    {
        .text = gEasyChatWord_Hello,
        .alphabeticalOrder = 4,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOOD_BYE)] =
    {
        .text = gEasyChatWord_GoodBye,
#if ENGLISH
        .alphabeticalOrder = 34,
#elif GERMAN
        .alphabeticalOrder = 2,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THANK_YOU)] =
    {
        .text = gEasyChatWord_ThankYou,
#if ENGLISH
        .alphabeticalOrder = 14,
#elif GERMAN
        .alphabeticalOrder = 36,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_I_VE_ARRIVED)] =
    {
        .text = gEasyChatWord_IveArrived,
#if ENGLISH
        .alphabeticalOrder = 26,
#elif GERMAN
        .alphabeticalOrder = 37,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PARDON)] =
    {
        .text = gEasyChatWord_Pardon,
#if ENGLISH
        .alphabeticalOrder = 30,
#elif GERMAN
        .alphabeticalOrder = 18,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCUSE)] =
    {
        .text = gEasyChatWord_Excuse,
#if ENGLISH
        .alphabeticalOrder = 37,
#elif GERMAN
        .alphabeticalOrder = 1,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEE_YA)] =
    {
        .text = gEasyChatWord_SeeYa,
#if ENGLISH
        .alphabeticalOrder = 8,
#elif GERMAN
        .alphabeticalOrder = 39,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCUSE_ME)] =
    {
        .text = gEasyChatWord_ExcuseMe,
#if ENGLISH
        .alphabeticalOrder = 28,
#elif GERMAN
        .alphabeticalOrder = 38,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WELL_THEN)] =
    {
        .text = gEasyChatWord_WellThen,
#if ENGLISH
        .alphabeticalOrder = 18,
#elif GERMAN
        .alphabeticalOrder = 29,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GO_AHEAD)] =
    {
        .text = gEasyChatWord_GoAhead,
#if ENGLISH
        .alphabeticalOrder = 36,
#elif GERMAN
        .alphabeticalOrder = 23,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APPRECIATE)] =
    {
        .text = gEasyChatWord_Appreciate,
#if ENGLISH
        .alphabeticalOrder = 33,
#elif GERMAN
        .alphabeticalOrder = 19,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEY_QUES)] =
    {
        .text = gEasyChatWord_HeyQues,
#if ENGLISH
        .alphabeticalOrder = 29,
#elif GERMAN
        .alphabeticalOrder = 25,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHAT_S_UP_QUES)] =
    {
        .text = gEasyChatWord_WhatsUpQues,
#if ENGLISH
        .alphabeticalOrder = 7,
#elif GERMAN
        .alphabeticalOrder = 13,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HUH_QUES)] =
    {
        .text = gEasyChatWord_HuhQues,
#if ENGLISH
        .alphabeticalOrder = 19,
#elif GERMAN
        .alphabeticalOrder = 11,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NO)] =
    {
        .text = gEasyChatWord_No,
#if ENGLISH
        .alphabeticalOrder = 21,
#elif GERMAN
        .alphabeticalOrder = 30,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HI)] =
    {
        .text = gEasyChatWord_Hi,
#if ENGLISH
        .alphabeticalOrder = 35,
#elif GERMAN
        .alphabeticalOrder = 20,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YEAH_YEAH)] =
    {
        .text = gEasyChatWord_YeahYeah,
#if ENGLISH
        .alphabeticalOrder = 11,
#elif GERMAN
        .alphabeticalOrder = 32,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BYE_BYE)] =
    {
        .text = gEasyChatWord_ByeBye,
#if ENGLISH
        .alphabeticalOrder = 17,
#elif GERMAN
        .alphabeticalOrder = 16,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MEET_YOU)] =
    {
        .text = gEasyChatWord_MeetYou,
#if ENGLISH
        .alphabeticalOrder = 0,
#elif GERMAN
        .alphabeticalOrder = 12,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEY)] =
    {
        .text = gEasyChatWord_Hey,
#if ENGLISH
        .alphabeticalOrder = 6,
#elif GERMAN
        .alphabeticalOrder = 27,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMELL)] =
    {
        .text = gEasyChatWord_Smell,
#if ENGLISH
        .alphabeticalOrder = 23,
#elif GERMAN
        .alphabeticalOrder = 24,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LISTENING)] =
    {
        .text = gEasyChatWord_Listening,
#if ENGLISH
        .alphabeticalOrder = 27,
#elif GERMAN
        .alphabeticalOrder = 8,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOO_HAH)] =
    {
        .text = gEasyChatWord_HooHah,
#if ENGLISH
        .alphabeticalOrder = 38,
#elif GERMAN
        .alphabeticalOrder = 28,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YAHOO)] =
    {
        .text = gEasyChatWord_Yahoo,
#if ENGLISH
        .alphabeticalOrder = 5,
#elif GERMAN
        .alphabeticalOrder = 6,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YO)] =
    {
        .text = gEasyChatWord_Yo,
#if ENGLISH
        .alphabeticalOrder = 31,
#elif GERMAN
        .alphabeticalOrder = 5,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COME_OVER)] =
    {
        .text = gEasyChatWord_ComeOver,
#if ENGLISH
        .alphabeticalOrder = 1,
#elif GERMAN
        .alphabeticalOrder = 31,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COUNT_ON)] =
    {
        .text = gEasyChatWord_CountOn,
#if ENGLISH
        .alphabeticalOrder = 39,
#elif GERMAN
        .alphabeticalOrder = 41,
#endif
        .enabled = TRUE,
    },
};
