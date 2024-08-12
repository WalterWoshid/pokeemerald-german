#if ENGLISH
const u8 gEasyChatWord_Highs[] = _("HIGHS");
const u8 gEasyChatWord_Lows[] = _("LOWS");
const u8 gEasyChatWord_Um[] = _("UM");
const u8 gEasyChatWord_Rear[] = _("REAR");
const u8 gEasyChatWord_Things[] = _("THINGS");
const u8 gEasyChatWord_Thing[] = _("THING");
const u8 gEasyChatWord_Below[] = _("BELOW");
const u8 gEasyChatWord_Above[] = _("ABOVE");
const u8 gEasyChatWord_Back[] = _("BACK");
const u8 gEasyChatWord_High[] = _("HIGH");
const u8 gEasyChatWord_Here[] = _("HERE");
const u8 gEasyChatWord_Inside[] = _("INSIDE");
const u8 gEasyChatWord_Outside[] = _("OUTSIDE");
const u8 gEasyChatWord_Beside[] = _("BESIDE");
const u8 gEasyChatWord_ThisIsItExcl[] = _("THIS IS IT!");
const u8 gEasyChatWord_This[] = _("THIS");
const u8 gEasyChatWord_Every[] = _("EVERY");
const u8 gEasyChatWord_These[] = _("THESE");
const u8 gEasyChatWord_TheseWere[] = _("THESE WERE");
const u8 gEasyChatWord_Down[] = _("DOWN");
const u8 gEasyChatWord_That[] = _("THAT");
const u8 gEasyChatWord_ThoseAre[] = _("THOSE ARE");
const u8 gEasyChatWord_ThoseWere[] = _("THOSE WERE");
const u8 gEasyChatWord_ThatsItExcl[] = _("THAT'S IT!");
const u8 gEasyChatWord_Am[] = _("AM");
const u8 gEasyChatWord_ThatWas[] = _("THAT WAS");
const u8 gEasyChatWord_Front[] = _("FRONT");
const u8 gEasyChatWord_Up[] = _("UP");
const u8 gEasyChatWord_Choice[] = _("CHOICE");
const u8 gEasyChatWord_Far[] = _("FAR");
const u8 gEasyChatWord_Away[] = _("AWAY");
const u8 gEasyChatWord_Near[] = _("NEAR");
const u8 gEasyChatWord_Where[] = _("WHERE");
const u8 gEasyChatWord_When[] = _("WHEN");
const u8 gEasyChatWord_What[] = _("WHAT");
const u8 gEasyChatWord_Deep[] = _("DEEP");
const u8 gEasyChatWord_Shallow[] = _("SHALLOW");
const u8 gEasyChatWord_Why[] = _("WHY");
const u8 gEasyChatWord_Confused[] = _("CONFUSED");
const u8 gEasyChatWord_Opposite[] = _("OPPOSITE");
const u8 gEasyChatWord_Left[] = _("LEFT");
const u8 gEasyChatWord_Right[] = _("RIGHT");
#elif GERMAN
const u8 gEasyChatWord_Highs[] = _("HÖHEN");
const u8 gEasyChatWord_Lows[] = _("TIEFEN");
const u8 gEasyChatWord_Um[] = _("ÄH");
const u8 gEasyChatWord_Rear[] = _("HINTEN");
const u8 gEasyChatWord_Things[] = _("SACHEN");
const u8 gEasyChatWord_Thing[] = _("DING");
const u8 gEasyChatWord_Below[] = _("UNTERHALB");
const u8 gEasyChatWord_Above[] = _("OBERHALB");
const u8 gEasyChatWord_Back[] = _("ZURÜCK");
const u8 gEasyChatWord_High[] = _("HOCH");
const u8 gEasyChatWord_Here[] = _("HIER");
const u8 gEasyChatWord_Inside[] = _("INNEN");
const u8 gEasyChatWord_Outside[] = _("AUSSEN");
const u8 gEasyChatWord_Beside[] = _("NEBEN");
const u8 gEasyChatWord_ThisIsItExcl[] = _("DAS IST ES!");
const u8 gEasyChatWord_This[] = _("DIES");
const u8 gEasyChatWord_Every[] = _("ALLES");
const u8 gEasyChatWord_These[] = _("DIESE");
const u8 gEasyChatWord_TheseWere[] = _("DIESE WAREN");
const u8 gEasyChatWord_Down[] = _("HINUNTER");
const u8 gEasyChatWord_That[] = _("DAS");
const u8 gEasyChatWord_ThoseAre[] = _("SCHON");
const u8 gEasyChatWord_ThoseWere[] = _("GENUG");
const u8 gEasyChatWord_ThatsItExcl[] = _("DAS IST’S!");
const u8 gEasyChatWord_Am[] = _("DAS SIND");
const u8 gEasyChatWord_ThatWas[] = _("DAS WAR");
const u8 gEasyChatWord_Front[] = _("VORNE");
const u8 gEasyChatWord_Up[] = _("OBEN");
const u8 gEasyChatWord_Choice[] = _("WAHL");
const u8 gEasyChatWord_Far[] = _("WEIT");
const u8 gEasyChatWord_Away[] = _("FORT");
const u8 gEasyChatWord_Near[] = _("NAHE");
const u8 gEasyChatWord_Where[] = _("WO");
const u8 gEasyChatWord_When[] = _("GLEICH");
const u8 gEasyChatWord_What[] = _("WAS");
const u8 gEasyChatWord_Deep[] = _("TIEF");
const u8 gEasyChatWord_Shallow[] = _("SEICHT");
const u8 gEasyChatWord_Why[] = _("WARUM");
const u8 gEasyChatWord_Confused[] = _("VERWIRRT");
const u8 gEasyChatWord_Opposite[] = _("GEGENÜBER");
const u8 gEasyChatWord_Left[] = _("LINKS");
const u8 gEasyChatWord_Right[] = _("RECHTS");
#endif

const struct EasyChatWordInfo gEasyChatGroup_Misc[] = {
    [EC_INDEX(EC_WORD_HIGHS)] =
    {
        .text = gEasyChatWord_Highs,
#if ENGLISH
        .alphabeticalOrder = 7,
#elif GERMAN
        .alphabeticalOrder = 2,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOWS)] =
    {
        .text = gEasyChatWord_Lows,
#if ENGLISH
        .alphabeticalOrder = 24,
#elif GERMAN
        .alphabeticalOrder = 16,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UM)] =
    {
        .text = gEasyChatWord_Um,
#if ENGLISH
        .alphabeticalOrder = 30,
#elif GERMAN
        .alphabeticalOrder = 12,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REAR)] =
    {
        .text = gEasyChatWord_Rear,
#if ENGLISH
        .alphabeticalOrder = 8,
#elif GERMAN
        .alphabeticalOrder = 20,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THINGS)] =
    {
        .text = gEasyChatWord_Things,
#if ENGLISH
        .alphabeticalOrder = 6,
#elif GERMAN
        .alphabeticalOrder = 14,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THING)] =
    {
        .text = gEasyChatWord_Thing,
#if ENGLISH
        .alphabeticalOrder = 13,
#elif GERMAN
        .alphabeticalOrder = 23,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BELOW)] =
    {
        .text = gEasyChatWord_Below,
#if ENGLISH
        .alphabeticalOrder = 28,
#elif GERMAN
        .alphabeticalOrder = 24,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ABOVE)] =
    {
        .text = gEasyChatWord_Above,
#if ENGLISH
        .alphabeticalOrder = 38,
#elif GERMAN
        .alphabeticalOrder = 25,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BACK)] =
    {
        .text = gEasyChatWord_Back,
#if ENGLISH
        .alphabeticalOrder = 35,
#elif GERMAN
        .alphabeticalOrder = 15,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIGH)] =
    {
        .text = gEasyChatWord_High,
#if ENGLISH
        .alphabeticalOrder = 19,
#elif GERMAN
        .alphabeticalOrder = 17,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE)] =
    {
        .text = gEasyChatWord_Here,
#if ENGLISH
        .alphabeticalOrder = 16,
#elif GERMAN
        .alphabeticalOrder = 18,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INSIDE)] =
    {
        .text = gEasyChatWord_Inside,
#if ENGLISH
        .alphabeticalOrder = 29,
#elif GERMAN
        .alphabeticalOrder = 5,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OUTSIDE)] =
    {
        .text = gEasyChatWord_Outside,
#if ENGLISH
        .alphabeticalOrder = 26,
#elif GERMAN
        .alphabeticalOrder = 30,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BESIDE)] =
    {
        .text = gEasyChatWord_Beside,
#if ENGLISH
        .alphabeticalOrder = 10,
#elif GERMAN
        .alphabeticalOrder = 39,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIS_IS_IT_EXCL)] =
    {
        .text = gEasyChatWord_ThisIsItExcl,
#if ENGLISH
        .alphabeticalOrder = 9,
#elif GERMAN
        .alphabeticalOrder = 22,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIS)] =
    {
        .text = gEasyChatWord_This,
#if ENGLISH
        .alphabeticalOrder = 0,
#elif GERMAN
        .alphabeticalOrder = 33,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVERY)] =
    {
        .text = gEasyChatWord_Every,
#if ENGLISH
        .alphabeticalOrder = 11,
#elif GERMAN
        .alphabeticalOrder = 10,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THESE)] =
    {
        .text = gEasyChatWord_These,
#if ENGLISH
        .alphabeticalOrder = 40,
#elif GERMAN
        .alphabeticalOrder = 3,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THESE_WERE)] =
    {
        .text = gEasyChatWord_TheseWere,
#if ENGLISH
        .alphabeticalOrder = 1,
#elif GERMAN
        .alphabeticalOrder = 19,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOWN)] =
    {
        .text = gEasyChatWord_Down,
#if ENGLISH
        .alphabeticalOrder = 31,
#elif GERMAN
        .alphabeticalOrder = 9,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT)] =
    {
        .text = gEasyChatWord_That,
#if ENGLISH
        .alphabeticalOrder = 39,
#elif GERMAN
        .alphabeticalOrder = 0,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THOSE_ARE)] =
    {
        .text = gEasyChatWord_ThoseAre,
#if ENGLISH
        .alphabeticalOrder = 12,
#elif GERMAN
        .alphabeticalOrder = 11,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THOSE_WERE)] =
    {
        .text = gEasyChatWord_ThoseWere,
#if ENGLISH
        .alphabeticalOrder = 3,
#elif GERMAN
        .alphabeticalOrder = 40,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT_S_IT_EXCL)] =
    {
        .text = gEasyChatWord_ThatsItExcl,
#if ENGLISH
        .alphabeticalOrder = 41,
#elif GERMAN
        .alphabeticalOrder = 31,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AM)] =
    {
        .text = gEasyChatWord_Am,
#if ENGLISH
        .alphabeticalOrder = 36,
#elif GERMAN
        .alphabeticalOrder = 13,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT_WAS)] =
    {
        .text = gEasyChatWord_ThatWas,
#if ENGLISH
        .alphabeticalOrder = 20,
#elif GERMAN
        .alphabeticalOrder = 27,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FRONT)] =
    {
        .text = gEasyChatWord_Front,
#if ENGLISH
        .alphabeticalOrder = 25,
#elif GERMAN
        .alphabeticalOrder = 7,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UP)] =
    {
        .text = gEasyChatWord_Up,
#if ENGLISH
        .alphabeticalOrder = 23,
#elif GERMAN
        .alphabeticalOrder = 41,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHOICE)] =
    {
        .text = gEasyChatWord_Choice,
#if ENGLISH
        .alphabeticalOrder = 17,
#elif GERMAN
        .alphabeticalOrder = 4,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAR)] =
    {
        .text = gEasyChatWord_Far,
#if ENGLISH
        .alphabeticalOrder = 18,
#elif GERMAN
        .alphabeticalOrder = 21,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWAY)] =
    {
        .text = gEasyChatWord_Away,
#if ENGLISH
        .alphabeticalOrder = 5,
#elif GERMAN
        .alphabeticalOrder = 36,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEAR)] =
    {
        .text = gEasyChatWord_Near,
#if ENGLISH
        .alphabeticalOrder = 4,
#elif GERMAN
        .alphabeticalOrder = 35,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHERE)] =
    {
        .text = gEasyChatWord_Where,
#if ENGLISH
        .alphabeticalOrder = 15,
#elif GERMAN
        .alphabeticalOrder = 1,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHEN)] =
    {
        .text = gEasyChatWord_When,
#if ENGLISH
        .alphabeticalOrder = 14,
#elif GERMAN
        .alphabeticalOrder = 6,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHAT)] =
    {
        .text = gEasyChatWord_What,
#if ENGLISH
        .alphabeticalOrder = 21,
#elif GERMAN
        .alphabeticalOrder = 38,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DEEP)] =
    {
        .text = gEasyChatWord_Deep,
#if ENGLISH
        .alphabeticalOrder = 22,
#elif GERMAN
        .alphabeticalOrder = 26,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHALLOW)] =
    {
        .text = gEasyChatWord_Shallow,
#if ENGLISH
        .alphabeticalOrder = 2,
#elif GERMAN
        .alphabeticalOrder = 28,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHY)] =
    {
        .text = gEasyChatWord_Why,
#if ENGLISH
        .alphabeticalOrder = 27,
#elif GERMAN
        .alphabeticalOrder = 37,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONFUSED)] =
    {
        .text = gEasyChatWord_Confused,
        .alphabeticalOrder = 34,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OPPOSITE)] =
    {
        .text = gEasyChatWord_Opposite,
#if ENGLISH
        .alphabeticalOrder = 33,
#elif GERMAN
        .alphabeticalOrder = 29,
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEFT)] =
    {
        .text = gEasyChatWord_Left,
        .alphabeticalOrder = 32,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RIGHT)] =
    {
        .text = gEasyChatWord_Right,
#if ENGLISH
        .alphabeticalOrder = 37,
#elif GERMAN
        .alphabeticalOrder = 8,
#endif
        .enabled = TRUE,
    },
};
