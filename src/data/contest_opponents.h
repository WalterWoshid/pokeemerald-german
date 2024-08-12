
#include "global.h"
#include "contest.h"

enum {
    CONTEST_OPPONENT_JIMMY,
    CONTEST_OPPONENT_EDITH,
    CONTEST_OPPONENT_EVAN,
    CONTEST_OPPONENT_KELSEY,
    CONTEST_OPPONENT_MADISON,
    CONTEST_OPPONENT_RAYMOND,
    CONTEST_OPPONENT_GRANT,
    CONTEST_OPPONENT_PAIGE,
    CONTEST_OPPONENT_ALEC,
    CONTEST_OPPONENT_SYDNEY,
    CONTEST_OPPONENT_MORRIS,
    CONTEST_OPPONENT_MARIAH,
    CONTEST_OPPONENT_RUSSELL,
    CONTEST_OPPONENT_MELANIE,
    CONTEST_OPPONENT_CHANCE,
    CONTEST_OPPONENT_AGATHA,
    CONTEST_OPPONENT_BEAU,
    CONTEST_OPPONENT_KAY,
    CONTEST_OPPONENT_CALE,
    CONTEST_OPPONENT_CAITLIN,
    CONTEST_OPPONENT_COLBY,
    CONTEST_OPPONENT_KYLIE,
    CONTEST_OPPONENT_LIAM,
    CONTEST_OPPONENT_MILO,
    CONTEST_OPPONENT_KARINA,
    CONTEST_OPPONENT_BOBBY,
    CONTEST_OPPONENT_CLAIRE,
    CONTEST_OPPONENT_WILLIE,
    CONTEST_OPPONENT_CASSIDY,
    CONTEST_OPPONENT_MORGAN,
    CONTEST_OPPONENT_SUMMER,
    CONTEST_OPPONENT_MILES,
    CONTEST_OPPONENT_AUDREY,
    CONTEST_OPPONENT_AVERY,
    CONTEST_OPPONENT_ARIANA,
    CONTEST_OPPONENT_ASHTON,
    CONTEST_OPPONENT_SANDRA,
    CONTEST_OPPONENT_CARSON,
    CONTEST_OPPONENT_KATRINA,
    CONTEST_OPPONENT_LUKE,
    CONTEST_OPPONENT_RAUL,
    CONTEST_OPPONENT_JADA,
    CONTEST_OPPONENT_ZEEK,
    CONTEST_OPPONENT_DIEGO,
    CONTEST_OPPONENT_ALIYAH,
    CONTEST_OPPONENT_NATALIA,
    CONTEST_OPPONENT_DEVIN,
    CONTEST_OPPONENT_TYLOR,
    CONTEST_OPPONENT_RONNIE,
    CONTEST_OPPONENT_CLAUDIA,
    CONTEST_OPPONENT_ELIAS,
    CONTEST_OPPONENT_JADE,
    CONTEST_OPPONENT_FRANCIS,
    CONTEST_OPPONENT_ALISHA,
    CONTEST_OPPONENT_SAUL,
    CONTEST_OPPONENT_FELICIA,
    CONTEST_OPPONENT_EMILIO,
    CONTEST_OPPONENT_KARLA,
    CONTEST_OPPONENT_DARRYL,
    CONTEST_OPPONENT_SELENA,
    CONTEST_OPPONENT_NOEL,
    CONTEST_OPPONENT_LACEY,
    CONTEST_OPPONENT_CORBIN,
    CONTEST_OPPONENT_GRACIE,
    CONTEST_OPPONENT_COLTIN,
    CONTEST_OPPONENT_ELLIE,
    CONTEST_OPPONENT_MARCUS,
    CONTEST_OPPONENT_KIARA,
    CONTEST_OPPONENT_BRYCE,
    CONTEST_OPPONENT_JAMIE,
    CONTEST_OPPONENT_JORGE,
    CONTEST_OPPONENT_DEVON,
    CONTEST_OPPONENT_JUSTINA,
    CONTEST_OPPONENT_RALPH,
    CONTEST_OPPONENT_ROSA,
    CONTEST_OPPONENT_KEATON,
    CONTEST_OPPONENT_MAYRA,
    CONTEST_OPPONENT_LAMAR,
    CONTEST_OPPONENT_AUBREY,
    CONTEST_OPPONENT_NIGEL,
    CONTEST_OPPONENT_CAMILLE,
    CONTEST_OPPONENT_DEON,
    CONTEST_OPPONENT_JANELLE,
    CONTEST_OPPONENT_HEATH,
    CONTEST_OPPONENT_SASHA,
    CONTEST_OPPONENT_FRANKIE,
    CONTEST_OPPONENT_HELEN,
    CONTEST_OPPONENT_CAMILE,
    CONTEST_OPPONENT_MARTIN,
    CONTEST_OPPONENT_SERGIO,
    CONTEST_OPPONENT_KAILEY,
    CONTEST_OPPONENT_PERLA,
    CONTEST_OPPONENT_CLARA,
    CONTEST_OPPONENT_JAKOB,
    CONTEST_OPPONENT_TREY,
    CONTEST_OPPONENT_LANE
};

// All contest opponents have a common set of AI flags (which contains all of the actually
// useful AI scripts, as well as some dummys) and a random combination of 2-3 dummy flags.
// Seems that like the battle AI they had more plans for this than what ended up in the final game
#define CONTEST_AI_SET_1  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_20 | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_2  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_19 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_3  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_18 | CONTEST_AI_DUMMY_23)
#define CONTEST_AI_SET_4  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_17 | CONTEST_AI_DUMMY_23)
#define CONTEST_AI_SET_5  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_16 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_6  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_15 | CONTEST_AI_DUMMY_22)
#define CONTEST_AI_SET_7  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_14 | CONTEST_AI_DUMMY_23)
#define CONTEST_AI_SET_8  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_13 | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_9  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_12 | CONTEST_AI_DUMMY_24)
#define CONTEST_AI_SET_A  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_11 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_B  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_10 | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_C  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_9  | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_D  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_8  | CONTEST_AI_DUMMY_22 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_E  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_7  | CONTEST_AI_DUMMY_24)
#define CONTEST_AI_SET_F  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_6  | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_10 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_20 | CONTEST_AI_DUMMY_23)
#define CONTEST_AI_SET_11 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_18 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_12 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_17 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_13 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_16 | CONTEST_AI_DUMMY_22)
#define CONTEST_AI_SET_14 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_15 | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_15 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_14 | CONTEST_AI_DUMMY_22)
#define CONTEST_AI_SET_16 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_13 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_17 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_12 | CONTEST_AI_DUMMY_23 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_18 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_10 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_19 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_9  | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_1A (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_8  | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_1B (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_7  | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_1C (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_6  | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_1D (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_20 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_1E (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_15 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_1F (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_14 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_20 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_12 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_21 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_7  | CONTEST_AI_DUMMY_25)

// All AI contestants have the same trainer ID
#define CONTEST_AI_TRAINER_ID 0xFFFF

const struct ContestWinner gDefaultContestWinners[] =
{
    [CONTEST_WINNER_HALL_1 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_ELECTRIKE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
#if ENGLISH
        .monName = _("ELECTER"),
#elif GERMAN
        .monName = _("FRIZZO"),
#endif
#if ENGLISH
        .trainerName = _("EZRA"),
#elif GERMAN
        .trainerName = _("GÜNTER"),
#endif
        .contestRank = CONTEST_RANK_NORMAL
    },
    [CONTEST_WINNER_HALL_2 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_TROPIUS,
        .contestCategory = CONTEST_CATEGORY_COOL,
#if ENGLISH
        .monName = _("TROPO"),
#elif GERMAN
        .monName = _("TROPI"),
#endif
#if ENGLISH
        .trainerName = _("ALLAN"),
#elif GERMAN
        .trainerName = _("ERNST"),
#endif
        .contestRank = CONTEST_RANK_HYPER
    },
    [CONTEST_WINNER_HALL_3 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_XATU,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
#if ENGLISH
        .monName = _("TUXA"),
#elif GERMAN
        .monName = _("UTAX"),
#endif
#if ENGLISH
        .trainerName = _("JULIET"),
#elif GERMAN
        .trainerName = _("PIA"),
#endif
        .contestRank = CONTEST_RANK_NORMAL
    },
    [CONTEST_WINNER_HALL_4 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_PLUSLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
#if ENGLISH
        .monName = _("PULSE"),
#elif GERMAN
        .monName = _("PLUSIMO"),
#endif
#if ENGLISH
        .trainerName = _("BAILY"),
#elif GERMAN
        .trainerName = _("UDO"),
#endif
        .contestRank = CONTEST_RANK_MASTER
    },
    [CONTEST_WINNER_HALL_5 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_SHUPPET,
        .contestCategory = CONTEST_CATEGORY_SMART,
#if ENGLISH
        .monName = _("SHUPUP"),
#elif GERMAN
        .monName = _("SHUPSI"),
#endif
#if ENGLISH
        .trainerName = _("MELANY"),
#elif GERMAN
        .trainerName = _("MIRJAM"),
#endif
        .contestRank = CONTEST_RANK_SUPER
    },
    [CONTEST_WINNER_HALL_6 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_ZANGOOSE,
        .contestCategory = CONTEST_CATEGORY_COOL,
#if ENGLISH
        .monName = _("GOOZAN"),
#elif GERMAN
        .monName = _("GENSO"),
#endif
#if ENGLISH
        .trainerName = _("HANA"),
#elif GERMAN
        .trainerName = _("EVA"),
#endif
        .contestRank = CONTEST_RANK_HYPER
    },
    [CONTEST_WINNER_HALL_UNUSED_1 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_LOUDRED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
#if ENGLISH
        .monName = _("LOUDED"),
#elif GERMAN
        .monName = _("KEELO"),
#endif
#if ENGLISH
        .trainerName = _("BRYANT"),
#elif GERMAN
        .trainerName = _("ISEGRIM"),
#endif
        .contestRank = CONTEST_RANK_HYPER
    },
    [CONTEST_WINNER_HALL_UNUSED_2 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_DELCATTY,
        .contestCategory = CONTEST_CATEGORY_CUTE,
#if ENGLISH
        .monName = _("KITSY"),
#elif GERMAN
        .monName = _("CONEC"),
#endif
#if ENGLISH
        .trainerName = _("OMAR"),
#elif GERMAN
        .trainerName = _("HAUBERT"),
#endif
        .contestRank = CONTEST_RANK_MASTER
    }
};

const struct ContestPokemon gContestOpponents[] =
{
    [CONTEST_OPPONENT_JIMMY] = {
        .species = SPECIES_POOCHYENA,
#if ENGLISH
        .nickname = _("POOCHY"),
#elif GERMAN
        .nickname = _("FIFFI"),
#endif
        .trainerName = _("JIMMY"),
        .trainerGfxId = OBJ_EVENT_GFX_BOY_1,
        .aiFlags = CONTEST_AI_SET_1,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_ROAR,
            MOVE_BITE,
            MOVE_TAKE_DOWN,
            MOVE_HOWL
        },
        .cool = 10,
        .beauty = 4,
        .cute = 10,
        .smart = 3,
        .tough = 4,
        .sheen = 50,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_EDITH] = {
        .species = SPECIES_ILLUMISE,
#if ENGLISH
        .nickname = _("MUSILLE"),
#elif GERMAN
        .nickname = _("LUXI"),
#endif
#if ENGLISH
        .trainerName = _("EDITH"),
#elif GERMAN
        .trainerName = _("KLARA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_1,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_REST,
            MOVE_FACADE,
            MOVE_TACKLE,
            MOVE_COVET
        },
        .cool = 10,
        .beauty = 10,
        .cute = 6,
        .smart = 1,
        .tough = 2,
        .sheen = 60,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_EVAN] = {
        .species = SPECIES_DUSTOX,
#if ENGLISH
        .nickname = _("DUSTER"),
#elif GERMAN
        .nickname = _("DOXU"),
#endif
#if ENGLISH
        .trainerName = _("EVAN"),
#elif GERMAN
        .trainerName = _("KARLO"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_LITTLE_BOY,
        .aiFlags = CONTEST_AI_SET_3,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SILVER_WIND,
            MOVE_MOONLIGHT,
            MOVE_LIGHT_SCREEN,
            MOVE_GUST
        },
        .cool = 2,
        .beauty = 10,
        .cute = 10,
        .smart = 12,
        .tough = 4,
        .sheen = 70,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_KELSEY] = {
        .species = SPECIES_SEEDOT,
#if ENGLISH
        .nickname = _("DOTS"),
#elif GERMAN
        .nickname = _("SAMINI"),
#endif
#if ENGLISH
        .trainerName = _("KELSEY"),
#elif GERMAN
        .trainerName = _("TRUDI"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_1,
        .aiFlags = CONTEST_AI_SET_4,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_BIDE,
            MOVE_SYNTHESIS,
            MOVE_BULLET_SEED,
            MOVE_GROWTH
        },
        .cool = 3,
        .beauty = 3,
        .cute = 5,
        .smart = 2,
        .tough = 7,
        .sheen = 80,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_MADISON] = {
        .species = SPECIES_TAILLOW,
#if ENGLISH
        .nickname = _("TATAY"),
#elif GERMAN
        .nickname = _("SCHWALBI"),
#endif
#if ENGLISH
        .trainerName = _("MADISON"),
#elif GERMAN
        .trainerName = _("HELENA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_POKEFAN_F,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_WING_ATTACK,
            MOVE_AGILITY,
            MOVE_AERIAL_ACE,
            MOVE_GROWL
        },
        .cool = 1,
        .beauty = 3,
        .cute = 3,
        .smart = 5,
        .tough = 4,
        .sheen = 90,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_RAYMOND] = {
        .species = SPECIES_NINCADA,
#if ENGLISH
        .nickname = _("NINDA"),
#elif GERMAN
        .nickname = _("CADINJA"),
#endif
#if ENGLISH
        .trainerName = _("RAYMOND"),
#elif GERMAN
        .trainerName = _("WILLI"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_BLACK_BELT,
        .aiFlags = CONTEST_AI_SET_6,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_LEECH_LIFE,
            MOVE_FALSE_SWIPE,
            MOVE_FURY_SWIPES,
            MOVE_MIND_READER
        },
        .cool = 5,
        .beauty = 2,
        .cute = 10,
        .smart = 7,
        .tough = 8,
        .sheen = 100,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_GRANT] = {
        .species = SPECIES_SHROOMISH,
#if ENGLISH
        .nickname = _("SMISH"),
#elif GERMAN
        .nickname = _("KNILZLI"),
#endif
#if ENGLISH
        .trainerName = _("GRANT"),
#elif GERMAN
        .trainerName = _("HARTMUT"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_YOUNGSTER,
        .aiFlags = CONTEST_AI_SET_7,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_STUN_SPORE,
            MOVE_LEECH_SEED,
            MOVE_MEGA_DRAIN,
            MOVE_ATTRACT
        },
        .cool = 3,
        .beauty = 3,
        .cute = 10,
        .smart = 2,
        .tough = 2,
        .sheen = 50,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_PAIGE] = {
        .species = SPECIES_SPHEAL,
#if ENGLISH
        .nickname = _("SLEAL"),
#elif GERMAN
        .nickname = _("MOPSO"),
#endif
#if ENGLISH
        .trainerName = _("PAIGE"),
#elif GERMAN
        .trainerName = _("CLAUDIA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_4,
        .aiFlags = CONTEST_AI_SET_8,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_AURORA_BEAM,
            MOVE_WATER_GUN,
            MOVE_GROWL,
            MOVE_ROCK_TOMB
        },
        .cool = 3,
        .beauty = 5,
        .cute = 1,
        .smart = 10,
        .tough = 10,
        .sheen = 60,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_ALEC] = {
        .species = SPECIES_SLAKOTH,
#if ENGLISH
        .nickname = _("SLOKTH"),
#elif GERMAN
        .nickname = _("BLUMPI"),
#endif
        .trainerName = _("ALEC"),
        .trainerGfxId = OBJ_EVENT_GFX_CAMPER,
        .aiFlags = CONTEST_AI_SET_9,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_STRENGTH,
            MOVE_COUNTER,
            MOVE_YAWN,
            MOVE_ENCORE
        },
        .cool = 10,
        .beauty = 4,
        .cute = 4,
        .smart = 5,
        .tough = 18,
        .sheen = 70,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_SYDNEY] = {
        .species = SPECIES_WHISMUR,
#if ENGLISH
        .nickname = _("WHIRIS"),
#elif GERMAN
        .nickname = _("FLURMI"),
#endif
#if ENGLISH
        .trainerName = _("SYDNEY"),
#elif GERMAN
        .trainerName = _("SILKE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_LASS,
        .aiFlags = CONTEST_AI_SET_A,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_ASTONISH,
            MOVE_SCREECH,
            MOVE_UPROAR,
            MOVE_HYPER_VOICE
        },
        .cool = 2,
        .beauty = 2,
        .cute = 7,
        .smart = 2,
        .tough = 7,
        .sheen = 80,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_MORRIS] = {
        .species = SPECIES_MAKUHITA,
        .nickname = _("MAHITA"),
#if ENGLISH
        .trainerName = _("MORRIS"),
#elif GERMAN
        .trainerName = _("PEER"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_SCHOOL_KID_M,
        .aiFlags = CONTEST_AI_SET_B,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SEISMIC_TOSS,
            MOVE_VITAL_THROW,
            MOVE_TACKLE,
            MOVE_REVERSAL
        },
        .cool = 9,
        .beauty = 1,
        .cute = 1,
        .smart = 8,
        .tough = 1,
        .sheen = 90,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_MARIAH] = {
        .species = SPECIES_ARON,
#if ENGLISH
        .nickname = _("RONAR"),
#elif GERMAN
        .nickname = _("STOLLI"),
#endif
#if ENGLISH
        .trainerName = _("MARIAH"),
#elif GERMAN
        .trainerName = _("MARIA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_2,
        .aiFlags = CONTEST_AI_SET_C,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_METAL_CLAW,
            MOVE_IRON_DEFENSE,
            MOVE_HEADBUTT,
            MOVE_TAKE_DOWN
        },
        .cool = 5,
        .beauty = 10,
        .cute = 2,
        .smart = 10,
        .tough = 2,
        .sheen = 100,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_RUSSELL] = {
        .species = SPECIES_CROBAT,
#if ENGLISH
        .nickname = _("BATRO"),
#elif GERMAN
        .nickname = _("X-FLIES"),
#endif
#if ENGLISH
        .trainerName = _("RUSSELL"),
#elif GERMAN
        .trainerName = _("RUDOLF"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_3,
        .aiFlags = CONTEST_AI_SET_D,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_HAZE,
            MOVE_MEAN_LOOK,
            MOVE_CONFUSE_RAY,
            MOVE_LEECH_LIFE
        },
        .cool = 4,
        .beauty = 2,
        .cute = 2,
        .smart = 2,
        .tough = 10,
        .sheen = 50,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_MELANIE] = {
        .species = SPECIES_GULPIN,
#if ENGLISH
        .nickname = _("GULIN"),
#elif GERMAN
        .nickname = _("SCHLUPPI"),
#endif
        .trainerName = _("MELANIE"),
        .trainerGfxId = OBJ_EVENT_GFX_TWIN,
        .aiFlags = CONTEST_AI_SET_E,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SLUDGE,
            MOVE_AMNESIA,
            MOVE_TOXIC,
            MOVE_YAWN
        },
        .cool = 1,
        .beauty = 10,
        .cute = 1,
        .smart = 10,
        .tough = 5,
        .sheen = 60,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CHANCE] = {
        .species = SPECIES_MANECTRIC,
#if ENGLISH
        .nickname = _("RIKELEC"),
#elif GERMAN
        .nickname = _("FRIZZZEL"),
#endif
#if ENGLISH
        .trainerName = _("CHANCE"),
#elif GERMAN
        .trainerName = _("BERTRAM"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_RICH_BOY,
        .aiFlags = CONTEST_AI_SET_F,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SPARK,
            MOVE_THUNDER_WAVE,
            MOVE_THUNDER,
            MOVE_ROAR
        },
        .cool = 20,
        .beauty = 10,
        .cute = 1,
        .smart = 1,
        .tough = 1,
        .sheen = 70,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_AGATHA] = {
        .species = SPECIES_BULBASAUR,
#if ENGLISH
        .nickname = _("BULBY"),
#elif GERMAN
        .nickname = _("SAMSI"),
#endif
#if ENGLISH
        .trainerName = _("AGATHA"),
#elif GERMAN
        .trainerName = _("DESIREE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_2,
        .aiFlags = CONTEST_AI_SET_1,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_GROWL,
            MOVE_LEECH_SEED,
            MOVE_TACKLE,
            MOVE_SWEET_SCENT
        },
        .cool = 5,
        .beauty = 3,
        .cute = 10,
        .smart = 10,
        .tough = 4,
        .sheen = 50,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_BEAU] = {
        .species = SPECIES_BUTTERFREE,
#if ENGLISH
        .nickname = _("FUTTERBE"),
#elif GERMAN
        .nickname = _("SCHMETTI"),
#endif
#if ENGLISH
        .trainerName = _("BEAU"),
#elif GERMAN
        .trainerName = _("EMMA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_HEX_MANIAC,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SUPERSONIC,
            MOVE_WHIRLWIND,
            MOVE_SILVER_WIND,
            MOVE_SAFEGUARD
        },
        .cool = 3,
        .beauty = 10,
        .cute = 2,
        .smart = 10,
        .tough = 4,
        .sheen = 60,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_KAY] = {
        .species = SPECIES_PIDGEOTTO,
#if ENGLISH
        .nickname = _("PIDEOT"),
#elif GERMAN
        .nickname = _("OGABOGA"),
#endif
#if ENGLISH
        .trainerName = _("KAY"),
#elif GERMAN
        .trainerName = _("JULIA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_5,
        .aiFlags = CONTEST_AI_SET_3,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_MIRROR_MOVE,
            MOVE_QUICK_ATTACK,
            MOVE_AERIAL_ACE,
            MOVE_FEATHER_DANCE
        },
        .cool = 10,
        .beauty = 8,
        .cute = 4,
        .smart = 2,
        .tough = 3,
        .sheen = 70,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CALE] = {
        .species = SPECIES_DIGLETT,
#if ENGLISH
        .nickname = _("DIGLE"),
#elif GERMAN
        .nickname = _("GIDDA"),
#endif
#if ENGLISH
        .trainerName = _("CALE"),
#elif GERMAN
        .trainerName = _("HANS"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_HIKER,
        .aiFlags = CONTEST_AI_SET_4,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_DIG,
            MOVE_EARTHQUAKE,
            MOVE_FISSURE,
            MOVE_MAGNITUDE
        },
        .cool = 4,
        .beauty = 2,
        .cute = 3,
        .smart = 5,
        .tough = 10,
        .sheen = 80,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CAITLIN] = {
        .species = SPECIES_POLIWAG,
#if ENGLISH
        .nickname = _("WAGIL"),
#elif GERMAN
        .nickname = _("QUAPPI"),
#endif
#if ENGLISH
        .trainerName = _("CAITLIN"),
#elif GERMAN
        .trainerName = _("ANDREA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_TUBER_F,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_HYDRO_PUMP,
            MOVE_RAIN_DANCE,
            MOVE_BODY_SLAM,
            MOVE_ICE_BEAM
        },
        .cool = 2,
        .beauty = 10,
        .cute = 5,
        .smart = 3,
        .tough = 10,
        .sheen = 90,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_COLBY] = {
        .species = SPECIES_TOTODILE,
#if ENGLISH
        .nickname = _("TOTDIL"),
#elif GERMAN
        .nickname = _("KROKA"),
#endif
#if ENGLISH
        .trainerName = _("COLBY"),
#elif GERMAN
        .trainerName = _("KEVIN"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_NINJA_BOY,
        .aiFlags = CONTEST_AI_SET_6,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_RAGE,
            MOVE_SCREECH,
            MOVE_SURF,
            MOVE_BLIZZARD
        },
        .cool = 6,
        .beauty = 10,
        .cute = 2,
        .smart = 1,
        .tough = 5,
        .sheen = 100,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_KYLIE] = {
        .species = SPECIES_LEDYBA,
#if ENGLISH
        .nickname = _("BALEDY"),
#elif GERMAN
        .nickname = _("MARIKÄ"),
#endif
#if ENGLISH
        .trainerName = _("KYLIE"),
#elif GERMAN
        .trainerName = _("BEATE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_BEAUTY,
        .aiFlags = CONTEST_AI_SET_7,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_BATON_PASS,
            MOVE_AGILITY,
            MOVE_SWIFT,
            MOVE_ATTRACT
        },
        .cool = 8,
        .beauty = 6,
        .cute = 8,
        .smart = 6,
        .tough = 2,
        .sheen = 90,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_LIAM] = {
        .species = SPECIES_DELIBIRD,
#if ENGLISH
        .nickname = _("BIRDLY"),
#elif GERMAN
        .nickname = _("KURRY"),
#endif
#if ENGLISH
        .trainerName = _("LIAM"),
#elif GERMAN
        .trainerName = _("LESLIE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_5,
        .aiFlags = CONTEST_AI_SET_8,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_PRESENT,
            MOVE_FACADE,
            MOVE_FOCUS_PUNCH,
            MOVE_RETURN
        },
        .cool = 4,
        .beauty = 3,
        .cute = 10,
        .smart = 5,
        .tough = 3,
        .sheen = 80,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_MILO] = {
        .species = SPECIES_LARVITAR,
#if ENGLISH
        .nickname = _("TARVITAR"),
#elif GERMAN
        .nickname = _("TARLAR"),
#endif
#if ENGLISH
        .trainerName = _("MILO"),
#elif GERMAN
        .trainerName = _("OSKAR"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_MANIAC,
        .aiFlags = CONTEST_AI_SET_9,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_THRASH,
            MOVE_TORMENT,
            MOVE_CRUNCH,
            MOVE_DIG
        },
        .cool = 8,
        .beauty = 5,
        .cute = 5,
        .smart = 8,
        .tough = 10,
        .sheen = 70,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_KARINA] = {
        .species = SPECIES_ROSELIA,
#if ENGLISH
        .nickname = _("RELIA"),
#elif GERMAN
        .nickname = _("ROSALI"),
#endif
        .trainerName = _("KARINA"),
        .trainerGfxId = OBJ_EVENT_GFX_PICNICKER,
        .aiFlags = CONTEST_AI_SET_10,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_PETAL_DANCE,
            MOVE_MAGICAL_LEAF,
            MOVE_GRASS_WHISTLE,
            MOVE_INGRAIN
        },
        .cool = 50,
        .beauty = 15,
        .cute = 75,
        .smart = 10,
        .tough = 20,
        .sheen = 100,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_BOBBY] = {
        .species = SPECIES_DODRIO,
#if ENGLISH
        .nickname = _("DUODO"),
#elif GERMAN
        .nickname = _("DOLDI"),
#endif
        .trainerName = _("BOBBY"),
        .trainerGfxId = OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_PECK,
            MOVE_FURY_ATTACK,
            MOVE_RETURN,
            MOVE_GROWL
        },
        .cool = 15,
        .beauty = 21,
        .cute = 15,
        .smart = 85,
        .tough = 35,
        .sheen = 110,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CLAIRE] = {
        .species = SPECIES_TRAPINCH,
#if ENGLISH
        .nickname = _("PINCHIN"),
#elif GERMAN
        .nickname = _("KNACKI"),
#endif
#if ENGLISH
        .trainerName = _("CLAIRE"),
#elif GERMAN
        .trainerName = _("JUDITH"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_1,
        .aiFlags = CONTEST_AI_SET_11,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_BITE,
            MOVE_SAND_ATTACK,
            MOVE_DIG,
            MOVE_FAINT_ATTACK
        },
        .cool = 75,
        .beauty = 25,
        .cute = 25,
        .smart = 10,
        .tough = 25,
        .sheen = 120,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_WILLIE] = {
        .species = SPECIES_CACNEA,
#if ENGLISH
        .nickname = _("NACAC"),
#elif GERMAN
        .nickname = _("KOTUS"),
#endif
#if ENGLISH
        .trainerName = _("WILLIE"),
#elif GERMAN
        .trainerName = _("HELMUT"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_LITTLE_BOY,
        .aiFlags = CONTEST_AI_SET_12,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SPIKES,
            MOVE_LEER,
            MOVE_POISON_STING,
            MOVE_SAND_ATTACK
        },
        .cool = 10,
        .beauty = 30,
        .cute = 25,
        .smart = 65,
        .tough = 25,
        .sheen = 130,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CASSIDY] = {
        .species = SPECIES_SANDSLASH,
#if ENGLISH
        .nickname = _("SHRAND"),
#elif GERMAN
        .nickname = _("SADAN"),
#endif
#if ENGLISH
        .trainerName = _("CASSIDY"),
#elif GERMAN
        .trainerName = _("BRITTA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_POKEFAN_F,
        .aiFlags = CONTEST_AI_SET_13,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SLASH,
            MOVE_DEFENSE_CURL,
            MOVE_SWIFT,
            MOVE_FURY_SWIPES
        },
        .cool = 30,
        .beauty = 90,
        .cute = 30,
        .smart = 10,
        .tough = 100,
        .sheen = 140,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_MORGAN] = {
        .species = SPECIES_BALTOY,
#if ENGLISH
        .nickname = _("TOYBAL"),
#elif GERMAN
        .nickname = _("PUPPIBAL"),
#endif
#if ENGLISH
        .trainerName = _("MORGAN"),
#elif GERMAN
        .trainerName = _("TORBEN"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_BLACK_BELT,
        .aiFlags = CONTEST_AI_SET_14,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SELF_DESTRUCT,
            MOVE_ROCK_TOMB,
            MOVE_PSYBEAM,
            MOVE_CONFUSION
        },
        .cool = 50,
        .beauty = 40,
        .cute = 10,
        .smart = 35,
        .tough = 35,
        .sheen = 150,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_SUMMER] = {
        .species = SPECIES_MEDICHAM,
#if ENGLISH
        .nickname = _("CHAMCHAM"),
#elif GERMAN
        .nickname = _("INFERNALIS"),
#endif
#if ENGLISH
        .trainerName = _("SUMMER"),
#elif GERMAN
        .trainerName = _("BIANKA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_4,
        .aiFlags = CONTEST_AI_SET_15,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_REVERSAL,
            MOVE_THUNDER_PUNCH,
            MOVE_FIRE_PUNCH,
            MOVE_ICE_PUNCH
        },
        .cool = 40,
        .beauty = 20,
        .cute = 40,
        .smart = 40,
        .tough = 40,
        .sheen = 100,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_MILES] = {
        .species = SPECIES_SPINDA,
#if ENGLISH
        .nickname = _("SPININ"),
#elif GERMAN
        .nickname = _("SPIRRWIRR"),
#endif
#if ENGLISH
        .trainerName = _("MILES"),
#elif GERMAN
        .trainerName = _("ALEX"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_CAMPER,
        .aiFlags = CONTEST_AI_SET_16,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_TEETER_DANCE,
            MOVE_PSYCH_UP,
            MOVE_HYPNOSIS,
            MOVE_UPROAR
        },
        .cool = 25,
        .beauty = 75,
        .cute = 25,
        .smart = 10,
        .tough = 25,
        .sheen = 110,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_AUDREY] = {
        .species = SPECIES_SWABLU,
#if ENGLISH
        .nickname = _("SWABY"),
#elif GERMAN
        .nickname = _("BLUPPF"),
#endif
#if ENGLISH
        .trainerName = _("AUDREY"),
#elif GERMAN
        .trainerName = _("SABINE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_LASS,
        .aiFlags = CONTEST_AI_SET_17,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_MIRROR_MOVE,
            MOVE_PERISH_SONG,
            MOVE_SAFEGUARD,
            MOVE_MIST
        },
        .cool = 30,
        .beauty = 30,
        .cute = 40,
        .smart = 30,
        .tough = 25,
        .sheen = 120,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_AVERY] = {
        .species = SPECIES_SPOINK,
#if ENGLISH
        .nickname = _("POINKER"),
#elif GERMAN
        .nickname = _("GRUNZO"),
#endif
#if ENGLISH
        .trainerName = _("AVERY"),
#elif GERMAN
        .trainerName = _("AUGUST"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_SCHOOL_KID_M,
        .aiFlags = CONTEST_AI_SET_A,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SPLASH,
            MOVE_CONFUSE_RAY,
            MOVE_SNORE,
            MOVE_REST
        },
        .cool = 40,
        .beauty = 10,
        .cute = 30,
        .smart = 40,
        .tough = 30,
        .sheen = 130,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_ARIANA] = {
        .species = SPECIES_KECLEON,
#if ENGLISH
        .nickname = _("KECON"),
#elif GERMAN
        .nickname = _("KECLI"),
#endif
        .trainerName = _("ARIANA"),
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_2,
        .aiFlags = CONTEST_AI_SET_18,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_THIEF,
            MOVE_SCREECH,
            MOVE_ANCIENT_POWER,
            MOVE_BIND
        },
        .cool = 10,
        .beauty = 10,
        .cute = 40,
        .smart = 75,
        .tough = 35,
        .sheen = 140,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_ASHTON] = {
        .species = SPECIES_GOLDEEN,
#if ENGLISH
        .nickname = _("GOLDEN"),
#elif GERMAN
        .nickname = _("GOLDINCHEN"),
#endif
#if ENGLISH
        .trainerName = _("ASHTON"),
#elif GERMAN
        .trainerName = _("TONI"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_3,
        .aiFlags = CONTEST_AI_SET_19,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_HORN_ATTACK,
            MOVE_FURY_ATTACK,
            MOVE_HORN_DRILL,
            MOVE_TAIL_WHIP
        },
        .cool = 70,
        .beauty = 30,
        .cute = 5,
        .smart = 30,
        .tough = 25,
        .sheen = 150,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_SANDRA] = {
        .species = SPECIES_BARBOACH,
#if ENGLISH
        .nickname = _("BOBOACH"),
#elif GERMAN
        .nickname = _("SCHMERBSE"),
#endif
#if ENGLISH
        .trainerName = _("SANDRA"),
#elif GERMAN
        .trainerName = _("SUSI"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_TWIN,
        .aiFlags = CONTEST_AI_SET_1A,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_MUD_SPORT,
            MOVE_WATER_SPORT,
            MOVE_EARTHQUAKE,
            MOVE_FUTURE_SIGHT
        },
        .cool = 45,
        .beauty = 45,
        .cute = 60,
        .smart = 25,
        .tough = 15,
        .sheen = 100,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CARSON] = {
        .species = SPECIES_SKARMORY,
#if ENGLISH
        .nickname = _("CORPY"),
#elif GERMAN
        .nickname = _("LEOPANZ"),
#endif
#if ENGLISH
        .trainerName = _("CARSON"),
#elif GERMAN
        .trainerName = _("CLEMENS"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_YOUNGSTER,
        .aiFlags = CONTEST_AI_SET_1B,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SWIFT,
            MOVE_DOUBLE_TEAM,
            MOVE_AGILITY,
            MOVE_CUT
        },
        .cool = 40,
        .beauty = 30,
        .cute = 25,
        .smart = 60,
        .tough = 20,
        .sheen = 110,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_KATRINA] = {
        .species = SPECIES_LOTAD,
#if ENGLISH
        .nickname = _("TADO"),
#elif GERMAN
        .nickname = _("URLOTZO"),
#endif
#if ENGLISH
        .trainerName = _("KATRINA"),
#elif GERMAN
        .trainerName = _("KATRIN"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_1,
        .aiFlags = CONTEST_AI_SET_1C,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_ASTONISH,
            MOVE_GROWL,
            MOVE_RAIN_DANCE,
            MOVE_WATER_PULSE
        },
        .cool = 15,
        .beauty = 15,
        .cute = 30,
        .smart = 15,
        .tough = 75,
        .sheen = 120,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_LUKE] = {
        .species = SPECIES_SLOWBRO,
#if ENGLISH
        .nickname = _("BROWLO"),
#elif GERMAN
        .nickname = _("JAHNUS"),
#endif
#if ENGLISH
        .trainerName = _("LUKE"),
#elif GERMAN
        .trainerName = _("LUKAS"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_FAT_MAN,
        .aiFlags = CONTEST_AI_SET_1,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_YAWN,
            MOVE_DISABLE,
            MOVE_GROWL,
            MOVE_CONFUSION
        },
        .cool = 20,
        .beauty = 40,
        .cute = 40,
        .smart = 30,
        .tough = 20,
        .sheen = 100,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_RAUL] = {
        .species = SPECIES_FARFETCHD,
#if ENGLISH
        .nickname = _("FETCHIN"),
#elif GERMAN
        .nickname = _("POLENTE"),
#endif
#if ENGLISH
        .trainerName = _("RAUL"),
#elif GERMAN
        .trainerName = _("RAMON"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_5,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_FACADE,
            MOVE_FURY_CUTTER,
            MOVE_FLY,
            MOVE_RETURN
        },
        .cool = 40,
        .beauty = 10,
        .cute = 40,
        .smart = 20,
        .tough = 20,
        .sheen = 110,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_JADA] = {
        .species = SPECIES_SEEL,
#if ENGLISH
        .nickname = _("SEELEY"),
#elif GERMAN
        .nickname = _("ROBBIE"),
#endif
#if ENGLISH
        .trainerName = _("JADA"),
#elif GERMAN
        .trainerName = _("JANINA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_2,
        .aiFlags = CONTEST_AI_SET_3,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_ATTRACT,
            MOVE_ICE_BEAM,
            MOVE_SAFEGUARD,
            MOVE_GROWL
        },
        .cool = 10,
        .beauty = 30,
        .cute = 40,
        .smart = 20,
        .tough = 20,
        .sheen = 120,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_ZEEK] = {
        .species = SPECIES_DROWZEE,
#if ENGLISH
        .nickname = _("DROWZIN"),
#elif GERMAN
        .nickname = _("TRAUDEL"),
#endif
#if ENGLISH
        .trainerName = _("ZEEK"),
#elif GERMAN
        .trainerName = _("KARL"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_PSYCHIC_M,
        .aiFlags = CONTEST_AI_SET_4,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_DISABLE,
            MOVE_FUTURE_SIGHT,
            MOVE_HIDDEN_POWER,
            MOVE_RETURN
        },
        .cool = 10,
        .beauty = 40,
        .cute = 50,
        .smart = 30,
        .tough = 45,
        .sheen = 130,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_DIEGO] = {
        .species = SPECIES_HITMONCHAN,
#if ENGLISH
        .nickname = _("HITEMON"),
#elif GERMAN
        .nickname = _("GINOCKJAN"),
#endif
#if ENGLISH
        .trainerName = _("DIEGO"),
#elif GERMAN
        .trainerName = _("FABIO"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_EXPERT_M,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SKY_UPPERCUT,
            MOVE_DETECT,
            MOVE_REVENGE,
            MOVE_MEGA_PUNCH
        },
        .cool = 45,
        .beauty = 20,
        .cute = 10,
        .smart = 20,
        .tough = 45,
        .sheen = 140,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_ALIYAH] = {
        .species = SPECIES_BLISSEY,
#if ENGLISH
        .nickname = _("BLISS"),
#elif GERMAN
        .nickname = _("HEIDI"),
#endif
#if ENGLISH
        .trainerName = _("ALIYAH"),
#elif GERMAN
        .trainerName = _("RAMONA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_TEALA,
        .aiFlags = CONTEST_AI_SET_6,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SING,
            MOVE_SOFT_BOILED,
            MOVE_EGG_BOMB,
            MOVE_DOUBLE_EDGE
        },
        .cool = 20,
        .beauty = 35,
        .cute = 40,
        .smart = 20,
        .tough = 20,
        .sheen = 150,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_NATALIA] = {
        .species = SPECIES_ELEKID,
#if ENGLISH
        .nickname = _("KIDLEK"),
#elif GERMAN
        .nickname = _("ELLI"),
#endif
#if ENGLISH
        .trainerName = _("NATALIA"),
#elif GERMAN
        .trainerName = _("NADINE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_POKEFAN_F,
        .aiFlags = CONTEST_AI_SET_7,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SHOCK_WAVE,
            MOVE_QUICK_ATTACK,
            MOVE_SCREECH,
            MOVE_ATTRACT
        },
        .cool = 40,
        .beauty = 10,
        .cute = 40,
        .smart = 25,
        .tough = 25,
        .sheen = 140,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_DEVIN] = {
        .species = SPECIES_SNUBBULL,
#if ENGLISH
        .nickname = _("SNUBBINS"),
#elif GERMAN
        .nickname = _("STUPSI"),
#endif
#if ENGLISH
        .trainerName = _("DEVIN"),
#elif GERMAN
        .trainerName = _("MIRKO"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_GENTLEMAN,
        .aiFlags = CONTEST_AI_SET_8,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SCARY_FACE,
            MOVE_TAUNT,
            MOVE_TAIL_WHIP,
            MOVE_BITE
        },
        .cool = 20,
        .beauty = 20,
        .cute = 20,
        .smart = 20,
        .tough = 20,
        .sheen = 130,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_TYLOR] = {
        .species = SPECIES_MISDREAVUS,
#if ENGLISH
        .nickname = _("DREAVIS"),
#elif GERMAN
        .nickname = _("TRAUNI"),
#endif
#if ENGLISH
        .trainerName = _("TYLOR"),
#elif GERMAN
        .trainerName = _("HANNA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_HEX_MANIAC,
        .aiFlags = CONTEST_AI_SET_9,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_PERISH_SONG,
            MOVE_MEAN_LOOK,
            MOVE_CONFUSE_RAY,
            MOVE_PAIN_SPLIT
        },
        .cool = 10,
        .beauty = 35,
        .cute = 10,
        .smart = 45,
        .tough = 20,
        .sheen = 120,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_RONNIE] = {
        .species = SPECIES_LAIRON,
#if ENGLISH
        .nickname = _("LAIRN"),
#elif GERMAN
        .nickname = _("STROLLAK"),
#endif
#if ENGLISH
        .trainerName = _("RONNIE"),
#elif GERMAN
        .trainerName = _("ACHIM"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_HIKER,
        .aiFlags = CONTEST_AI_SET_1D,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_METAL_SOUND,
            MOVE_METAL_CLAW,
            MOVE_HARDEN,
            MOVE_TAKE_DOWN
        },
        .cool = 30,
        .beauty = 50,
        .cute = 35,
        .smart = 100,
        .tough = 90,
        .sheen = 200,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CLAUDIA] = {
        .species = SPECIES_SHIFTRY,
#if ENGLISH
        .nickname = _("SHIFTY"),
#elif GERMAN
        .nickname = _("STILUG"),
#endif
#if ENGLISH
        .trainerName = _("CLAUDIA"),
#elif GERMAN
        .trainerName = _("GABI"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_1,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_GROWTH,
            MOVE_RAZOR_WIND,
            MOVE_EXPLOSION,
            MOVE_EXTRASENSORY
        },
        .cool = 75,
        .beauty = 75,
        .cute = 65,
        .smart = 35,
        .tough = 70,
        .sheen = 210,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_ELIAS] = {
        .species = SPECIES_NINJASK,
#if ENGLISH
        .nickname = _("NINAS"),
#elif GERMAN
        .nickname = _("ASKINJA"),
#endif
#if ENGLISH
        .trainerName = _("ELIAS"),
#elif GERMAN
        .trainerName = _("ROLF"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_LITTLE_BOY,
        .aiFlags = CONTEST_AI_SET_11,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SCREECH,
            MOVE_FURY_SWIPES,
            MOVE_SAND_ATTACK,
            MOVE_BATON_PASS
        },
        .cool = 30,
        .beauty = 50,
        .cute = 95,
        .smart = 70,
        .tough = 70,
        .sheen = 220,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_JADE] = {
        .species = SPECIES_SWELLOW,
#if ENGLISH
        .nickname = _("WELOW"),
#elif GERMAN
        .nickname = _("SCHWALLO"),
#endif
#if ENGLISH
        .trainerName = _("JADE"),
#elif GERMAN
        .trainerName = _("ELSE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_POKEFAN_F,
        .aiFlags = CONTEST_AI_SET_12,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_AGILITY,
            MOVE_AERIAL_ACE,
            MOVE_WING_ATTACK,
            MOVE_FLY
        },
        .cool = 65,
        .beauty = 85,
        .cute = 35,
        .smart = 75,
        .tough = 40,
        .sheen = 230,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_FRANCIS] = {
        .species = SPECIES_MIGHTYENA,
#if ENGLISH
        .nickname = _("YENA"),
#elif GERMAN
        .nickname = _("JÄNAGI"),
#endif
#if ENGLISH
        .trainerName = _("FRANCIS"),
#elif GERMAN
        .trainerName = _("FRANK"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_BLACK_BELT,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_TAUNT,
            MOVE_THIEF,
            MOVE_ODOR_SLEUTH,
            MOVE_TAKE_DOWN
        },
        .cool = 40,
        .beauty = 80,
        .cute = 35,
        .smart = 70,
        .tough = 70,
        .sheen = 240,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_ALISHA] = {
        .species = SPECIES_BEAUTIFLY,
#if ENGLISH
        .nickname = _("TIFLY"),
#elif GERMAN
        .nickname = _("PAPINILLI"),
#endif
#if ENGLISH
        .trainerName = _("ALISHA"),
#elif GERMAN
        .trainerName = _("ANNA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_4,
        .aiFlags = CONTEST_AI_SET_1E,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_MORNING_SUN,
            MOVE_SILVER_WIND,
            MOVE_STUN_SPORE,
            MOVE_SECRET_POWER
        },
        .cool = 40,
        .beauty = 70,
        .cute = 25,
        .smart = 80,
        .tough = 100,
        .sheen = 250,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_SAUL] = {
        .species = SPECIES_SEAKING,
#if ENGLISH
        .nickname = _("KINGSEA"),
#elif GERMAN
        .nickname = _("KINGOLA"),
#endif
#if ENGLISH
        .trainerName = _("SAUL"),
#elif GERMAN
        .trainerName = _("KONRAD"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_CAMPER,
        .aiFlags = CONTEST_AI_SET_1F,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_FLAIL,
            MOVE_SUPERSONIC,
            MOVE_HORN_ATTACK,
            MOVE_FURY_ATTACK
        },
        .cool = 80,
        .beauty = 60,
        .cute = 30,
        .smart = 70,
        .tough = 90,
        .sheen = 200,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_FELICIA] = {
        .species = SPECIES_CASTFORM,
#if ENGLISH
        .nickname = _("CASTER"),
#elif GERMAN
        .nickname = _("FEOMORF"),
#endif
#if ENGLISH
        .trainerName = _("FELICIA"),
#elif GERMAN
        .trainerName = _("LUISE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_LASS,
        .aiFlags = CONTEST_AI_SET_16,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SUNNY_DAY,
            MOVE_WEATHER_BALL,
            MOVE_SANDSTORM,
            MOVE_RETURN
        },
        .cool = 70,
        .beauty = 80,
        .cute = 80,
        .smart = 50,
        .tough = 65,
        .sheen = 210,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_EMILIO] = {
        .species = SPECIES_MACHOKE,
#if ENGLISH
        .nickname = _("CHOKEM"),
#elif GERMAN
        .nickname = _("SCHOCKMA"),
#endif
#if ENGLISH
        .trainerName = _("EMILIO"),
#elif GERMAN
        .trainerName = _("MICHAEL"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_SCHOOL_KID_M,
        .aiFlags = CONTEST_AI_SET_20,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SEISMIC_TOSS,
            MOVE_FOCUS_ENERGY,
            MOVE_KARATE_CHOP,
            MOVE_SCARY_FACE
        },
        .cool = 70,
        .beauty = 85,
        .cute = 25,
        .smart = 60,
        .tough = 50,
        .sheen = 220,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_KARLA] = {
        .species = SPECIES_LOMBRE,
#if ENGLISH
        .nickname = _("LOMBE"),
#elif GERMAN
        .nickname = _("OMBRE"),
#endif
#if ENGLISH
        .trainerName = _("KARLA"),
#elif GERMAN
        .trainerName = _("ANIKA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_2,
        .aiFlags = CONTEST_AI_SET_A,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_ATTRACT,
            MOVE_FLASH,
            MOVE_UPROAR,
            MOVE_GROWL
        },
        .cool = 40,
        .beauty = 60,
        .cute = 90,
        .smart = 45,
        .tough = 70,
        .sheen = 230,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_DARRYL] = {
        .species = SPECIES_SEVIPER,
#if ENGLISH
        .nickname = _("VIPES"),
#elif GERMAN
        .nickname = _("PITISVI"),
#endif
#if ENGLISH
        .trainerName = _("DARRYL"),
#elif GERMAN
        .trainerName = _("DETLEF"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_3,
        .aiFlags = CONTEST_AI_SET_18,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_POISON_FANG,
            MOVE_GLARE,
            MOVE_WRAP,
            MOVE_SCREECH
        },
        .cool = 35,
        .beauty = 50,
        .cute = 90,
        .smart = 40,
        .tough = 100,
        .sheen = 240,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_SELENA] = {
        .species = SPECIES_WAILMER,
#if ENGLISH
        .nickname = _("MERAIL"),
#elif GERMAN
        .nickname = _("WAILA"),
#endif
#if ENGLISH
        .trainerName = _("SELENA"),
#elif GERMAN
        .trainerName = _("XENIA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_EXPERT_F,
        .aiFlags = CONTEST_AI_SET_19,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_WATER_PULSE,
            MOVE_REST,
            MOVE_WATER_SPOUT,
            MOVE_SPLASH
        },
        .cool = 30,
        .beauty = 100,
        .cute = 100,
        .smart = 50,
        .tough = 30,
        .sheen = 250,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_NOEL] = {
        .species = SPECIES_MAGIKARP,
#if ENGLISH
        .nickname = _("KARPAG"),
#elif GERMAN
        .nickname = _("KARDORPA"),
#endif
#if ENGLISH
        .trainerName = _("NOEL"),
#elif GERMAN
        .trainerName = _("FLORIAN"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_YOUNGSTER,
        .aiFlags = CONTEST_AI_SET_1A,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_TACKLE,
            MOVE_SPLASH,
            MOVE_FLAIL,
            MOVE_TACKLE
        },
        .cool = 30,
        .beauty = 30,
        .cute = 160,
        .smart = 50,
        .tough = 160,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_LACEY] = {
        .species = SPECIES_LUNATONE,
#if ENGLISH
        .nickname = _("LUNONE"),
#elif GERMAN
        .nickname = _("LUNA"),
#endif
#if ENGLISH
        .trainerName = _("LACEY"),
#elif GERMAN
        .trainerName = _("DIANA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_1,
        .aiFlags = CONTEST_AI_SET_21,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_EXPLOSION,
            MOVE_FUTURE_SIGHT,
            MOVE_PSYCHIC,
            MOVE_CONFUSION
        },
        .cool = 50,
        .beauty = 70,
        .cute = 60,
        .smart = 70,
        .tough = 50,
        .sheen = 210,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CORBIN] = {
        .species = SPECIES_ABSOL,
#if ENGLISH
        .nickname = _("ABSO"),
#elif GERMAN
        .nickname = _("SLOAB"),
#endif
#if ENGLISH
        .trainerName = _("CORBIN"),
#elif GERMAN
        .trainerName = _("LUTZ"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_MANIAC,
        .aiFlags = CONTEST_AI_SET_F,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_PERISH_SONG,
            MOVE_HAIL,
            MOVE_HYPER_BEAM,
            MOVE_SLASH
        },
        .cool = 95,
        .beauty = 80,
        .cute = 85,
        .smart = 35,
        .tough = 35,
        .sheen = 220,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_GRACIE] = {
        .species = SPECIES_EXEGGUTOR,
#if ENGLISH
        .nickname = _("EGGSOR"),
#elif GERMAN
        .nickname = _("OWEIOH"),
#endif
#if ENGLISH
        .trainerName = _("GRACIE"),
#elif GERMAN
        .trainerName = _("TAMARA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_PICNICKER,
        .aiFlags = CONTEST_AI_SET_1,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_STOMP,
            MOVE_HYPNOSIS,
            MOVE_EGG_BOMB,
            MOVE_SKILL_SWAP
        },
        .cool = 40,
        .beauty = 50,
        .cute = 60,
        .smart = 100,
        .tough = 80,
        .sheen = 200,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_COLTIN] = {
        .species = SPECIES_CUBONE,
#if ENGLISH
        .nickname = _("CUBIN"),
#elif GERMAN
        .nickname = _("GOSSAR"),
#endif
#if ENGLISH
        .trainerName = _("COLTIN"),
#elif GERMAN
        .trainerName = _("MERLIN"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_4,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_BONE_CLUB,
            MOVE_BONEMERANG,
            MOVE_BONE_RUSH,
            MOVE_GROWL
        },
        .cool = 40,
        .beauty = 35,
        .cute = 85,
        .smart = 35,
        .tough = 100,
        .sheen = 210,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_ELLIE] = {
        .species = SPECIES_HITMONLEE,
#if ENGLISH
        .nickname = _("HITMON"),
#elif GERMAN
        .nickname = _("KNICKO"),
#endif
#if ENGLISH
        .trainerName = _("ELLIE"),
#elif GERMAN
        .trainerName = _("BIRTE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_EXPERT_F,
        .aiFlags = CONTEST_AI_SET_3,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_REVERSAL,
            MOVE_REVENGE,
            MOVE_FOCUS_ENERGY,
            MOVE_MEGA_KICK
        },
        .cool = 85,
        .beauty = 30,
        .cute = 25,
        .smart = 50,
        .tough = 100,
        .sheen = 220,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_MARCUS] = {
        .species = SPECIES_SQUIRTLE,
#if ENGLISH
        .nickname = _("SURTLE"),
#elif GERMAN
        .nickname = _("KRÖTOX"),
#endif
#if ENGLISH
        .trainerName = _("MARCUS"),
#elif GERMAN
        .trainerName = _("ALBERT"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_SAILOR,
        .aiFlags = CONTEST_AI_SET_4,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_TAIL_WHIP,
            MOVE_BUBBLE,
            MOVE_FOCUS_PUNCH,
            MOVE_WITHDRAW
        },
        .cool = 30,
        .beauty = 35,
        .cute = 100,
        .smart = 40,
        .tough = 95,
        .sheen = 230,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_KIARA] = {
        .species = SPECIES_KANGASKHAN,
#if ENGLISH
        .nickname = _("KHANKAN"),
#elif GERMAN
        .nickname = _("AMAKAN"),
#endif
#if ENGLISH
        .trainerName = _("KIARA"),
#elif GERMAN
        .trainerName = _("PAULA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_3,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_MEGA_PUNCH,
            MOVE_RAGE,
            MOVE_FOCUS_PUNCH,
            MOVE_TAIL_WHIP
        },
        .cool = 100,
        .beauty = 50,
        .cute = 30,
        .smart = 50,
        .tough = 100,
        .sheen = 240,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_BRYCE] = {
        .species = SPECIES_PINECO,
#if ENGLISH
        .nickname = _("PINOC"),
#elif GERMAN
        .nickname = _("ZAPFOK"),
#endif
#if ENGLISH
        .trainerName = _("BRYCE"),
#elif GERMAN
        .trainerName = _("KLAUS"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_BUG_CATCHER,
        .aiFlags = CONTEST_AI_SET_6,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_EXPLOSION,
            MOVE_SPIKES,
            MOVE_LIGHT_SCREEN,
            MOVE_GIGA_DRAIN
        },
        .cool = 80,
        .beauty = 80,
        .cute = 80,
        .smart = 80,
        .tough = 80,
        .sheen = 250,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_JAMIE] = {
        .species = SPECIES_DUNSPARCE,
#if ENGLISH
        .nickname = _("DILTOT"),
#elif GERMAN
        .nickname = _("MANNI"),
#endif
#if ENGLISH
        .trainerName = _("JAMIE"),
#elif GERMAN
        .trainerName = _("GERDA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_5,
        .aiFlags = CONTEST_AI_SET_7,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SPITE,
            MOVE_YAWN,
            MOVE_DEFENSE_CURL,
            MOVE_TAKE_DOWN
        },
        .cool = 40,
        .beauty = 35,
        .cute = 100,
        .smart = 40,
        .tough = 110,
        .sheen = 240,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_JORGE] = {
        .species = SPECIES_HOUNDOOM,
#if ENGLISH
        .nickname = _("DOOMOND"),
#elif GERMAN
        .nickname = _("DEIMELMON"),
#endif
#if ENGLISH
        .trainerName = _("JORGE"),
#elif GERMAN
        .trainerName = _("HUGO"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_GENTLEMAN,
        .aiFlags = CONTEST_AI_SET_8,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_ROAR,
            MOVE_FLAMETHROWER,
            MOVE_FAINT_ATTACK,
            MOVE_SUNNY_DAY
        },
        .cool = 100,
        .beauty = 100,
        .cute = 30,
        .smart = 25,
        .tough = 80,
        .sheen = 230,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_DEVON] = {
        .species = SPECIES_MILTANK,
#if ENGLISH
        .nickname = _("MILKAN"),
#elif GERMAN
        .nickname = _("MILLI"),
#endif
#if ENGLISH
        .trainerName = _("DEVON"),
#elif GERMAN
        .trainerName = _("DAVID"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_POKEFAN_M,
        .aiFlags = CONTEST_AI_SET_9,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_MILK_DRINK,
            MOVE_HEAL_BELL,
            MOVE_DEFENSE_CURL,
            MOVE_BLIZZARD
        },
        .cool = 50,
        .beauty = 110,
        .cute = 100,
        .smart = 35,
        .tough = 40,
        .sheen = 220,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_JUSTINA] = {
        .species = SPECIES_GYARADOS,
#if ENGLISH
        .nickname = _("RADOS"),
#elif GERMAN
        .nickname = _("GARADI"),
#endif
#if ENGLISH
        .trainerName = _("JUSTINA"),
#elif GERMAN
        .trainerName = _("JASMIN"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_PICNICKER,
        .aiFlags = CONTEST_AI_SET_1D,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_HYPER_BEAM,
            MOVE_HYDRO_PUMP,
            MOVE_RAIN_DANCE,
            MOVE_BITE
        },
        .cool = 160,
        .beauty = 200,
        .cute = 20,
        .smart = 40,
        .tough = 160,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_RALPH] = {
        .species = SPECIES_LOUDRED,
#if ENGLISH
        .nickname = _("LOUDERD"),
#elif GERMAN
        .nickname = _("KRAKEEL"),
#endif
#if ENGLISH
        .trainerName = _("RALPH"),
#elif GERMAN
        .trainerName = _("GERT"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_EXPERT_M,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_HYPER_VOICE,
            MOVE_STOMP,
            MOVE_ROAR,
            MOVE_HOWL
        },
        .cool = 170,
        .beauty = 50,
        .cute = 55,
        .smart = 150,
        .tough = 160,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_ROSA] = {
        .species = SPECIES_SKITTY,
#if ENGLISH
        .nickname = _("SITTY"),
#elif GERMAN
        .nickname = _("NECOCO"),
#endif
        .trainerName = _("ROSA"),
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_1,
        .aiFlags = CONTEST_AI_SET_11,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_ATTRACT,
            MOVE_ASSIST,
            MOVE_FAINT_ATTACK,
            MOVE_TAIL_WHIP
        },
        .cool = 40,
        .beauty = 200,
        .cute = 150,
        .smart = 185,
        .tough = 60,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_KEATON] = {
        .species = SPECIES_SLAKING,
#if ENGLISH
        .nickname = _("SLING"),
#elif GERMAN
        .nickname = _("ASSIMAX"),
#endif
#if ENGLISH
        .trainerName = _("KEATON"),
#elif GERMAN
        .trainerName = _("KURT"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_LITTLE_BOY,
        .aiFlags = CONTEST_AI_SET_12,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_COVET,
            MOVE_COUNTER,
            MOVE_ENCORE,
            MOVE_SLACK_OFF
        },
        .cool = 85,
        .beauty = 85,
        .cute = 170,
        .smart = 110,
        .tough = 150,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_MAYRA] = {
        .species = SPECIES_ALTARIA,
#if ENGLISH
        .nickname = _("TARIA"),
#elif GERMAN
        .nickname = _("RIA"),
#endif
#if ENGLISH
        .trainerName = _("MAYRA"),
#elif GERMAN
        .trainerName = _("SONJA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_POKEFAN_F,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_DRAGON_DANCE,
            MOVE_HYPER_BEAM,
            MOVE_PERISH_SONG,
            MOVE_SAFEGUARD
        },
        .cool = 170,
        .beauty = 150,
        .cute = 30,
        .smart = 30,
        .tough = 90,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_LAMAR] = {
        .species = SPECIES_KIRLIA,
#if ENGLISH
        .nickname = _("LIRKI"),
#elif GERMAN
        .nickname = _("KIROJAL"),
#endif
#if ENGLISH
        .trainerName = _("LAMAR"),
#elif GERMAN
        .trainerName = _("SÖNKE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_RICH_BOY,
        .aiFlags = CONTEST_AI_SET_1E,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SHOCK_WAVE,
            MOVE_SHADOW_BALL,
            MOVE_SKILL_SWAP,
            MOVE_RETURN
        },
        .cool = 230,
        .beauty = 60,
        .cute = 60,
        .smart = 230,
        .tough = 80,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_AUBREY] = {
        .species = SPECIES_BELLOSSOM,
#if ENGLISH
        .nickname = _("BLOSSOM"),
#elif GERMAN
        .nickname = _("BELLA"),
#endif
#if ENGLISH
        .trainerName = _("AUBREY"),
#elif GERMAN
        .trainerName = _("MAGDA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_4,
        .aiFlags = CONTEST_AI_SET_1F,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_PETAL_DANCE,
            MOVE_SWEET_SCENT,
            MOVE_STUN_SPORE,
            MOVE_FLASH
        },
        .cool = 35,
        .beauty = 200,
        .cute = 150,
        .smart = 130,
        .tough = 40,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_NIGEL] = {
        .species = SPECIES_SABLEYE,
#if ENGLISH
        .nickname = _("EYESAB"),
#elif GERMAN
        .nickname = _("IRIZO"),
#endif
#if ENGLISH
        .trainerName = _("NIGEL"),
#elif GERMAN
        .trainerName = _("SASCHA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_CAMPER,
        .aiFlags = CONTEST_AI_SET_16,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_MEAN_LOOK,
            MOVE_FAINT_ATTACK,
            MOVE_KNOCK_OFF,
            MOVE_CONFUSE_RAY
        },
        .cool = 25,
        .beauty = 35,
        .cute = 230,
        .smart = 150,
        .tough = 160,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CAMILLE] = {
        .species = SPECIES_NATU,
#if ENGLISH
        .nickname = _("UTAN"),
#elif GERMAN
        .nickname = _("TUMANI"),
#endif
#if ENGLISH
        .trainerName = _("CAMILLE"),
#elif GERMAN
        .trainerName = _("MILA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_LASS,
        .aiFlags = CONTEST_AI_SET_20,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_NIGHT_SHADE,
            MOVE_FUTURE_SIGHT,
            MOVE_CONFUSE_RAY,
            MOVE_PSYCHIC
        },
        .cool = 35,
        .beauty = 35,
        .cute = 150,
        .smart = 130,
        .tough = 170,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_DEON] = {
        .species = SPECIES_SHARPEDO,
#if ENGLISH
        .nickname = _("PEDOS"),
#elif GERMAN
        .nickname = _("HAITODO"),
#endif
#if ENGLISH
        .trainerName = _("DEON"),
#elif GERMAN
        .trainerName = _("KNUT"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_SCHOOL_KID_M,
        .aiFlags = CONTEST_AI_SET_A,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_AGILITY,
            MOVE_SWAGGER,
            MOVE_TAUNT,
            MOVE_TAKE_DOWN
        },
        .cool = 140,
        .beauty = 70,
        .cute = 140,
        .smart = 75,
        .tough = 100,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_JANELLE] = {
        .species = SPECIES_LUVDISC,
#if ENGLISH
        .nickname = _("LUVIS"),
#elif GERMAN
        .nickname = _("KUSSLIEB"),
#endif
#if ENGLISH
        .trainerName = _("JANELLE"),
#elif GERMAN
        .trainerName = _("INCA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_2,
        .aiFlags = CONTEST_AI_SET_18,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SWEET_KISS,
            MOVE_ATTRACT,
            MOVE_TAKE_DOWN,
            MOVE_CHARM
        },
        .cool = 50,
        .beauty = 100,
        .cute = 220,
        .smart = 40,
        .tough = 190,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_HEATH] = {
        .species = SPECIES_HERACROSS,
#if ENGLISH
        .nickname = _("HEROSS"),
#elif GERMAN
        .nickname = _("SKARAB"),
#endif
#if ENGLISH
        .trainerName = _("HEATH"),
#elif GERMAN
        .trainerName = _("FELIX"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_3,
        .aiFlags = CONTEST_AI_SET_19,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_STRENGTH,
            MOVE_ENDURE,
            MOVE_REVERSAL,
            MOVE_ROCK_TOMB
        },
        .cool = 170,
        .beauty = 70,
        .cute = 110,
        .smart = 240,
        .tough = 140,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_SASHA] = {
        .species = SPECIES_ELECTRODE,
#if ENGLISH
        .nickname = _("RODLECT"),
#elif GERMAN
        .nickname = _("LEKBAL"),
#endif
#if ENGLISH
        .trainerName = _("SASHA"),
#elif GERMAN
        .trainerName = _("DEBORA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_TWIN,
        .aiFlags = CONTEST_AI_SET_1A,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_EXPLOSION,
            MOVE_LIGHT_SCREEN,
            MOVE_SWIFT,
            MOVE_FLASH
        },
        .cool = 200,
        .beauty = 200,
        .cute = 30,
        .smart = 35,
        .tough = 50,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_FRANKIE] = {
        .species = SPECIES_PICHU,
#if ENGLISH
        .nickname = _("CHUPY"),
#elif GERMAN
        .nickname = _("DEIBEL"),
#endif
#if ENGLISH
        .trainerName = _("FRANKIE"),
#elif GERMAN
        .trainerName = _("BORIS"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_YOUNGSTER,
        .aiFlags = CONTEST_AI_SET_21,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SWEET_KISS,
            MOVE_ATTRACT,
            MOVE_REST,
            MOVE_TAIL_WHIP
        },
        .cool = 25,
        .beauty = 150,
        .cute = 180,
        .smart = 115,
        .tough = 120,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_HELEN] = {
        .species = SPECIES_WOBBUFFET,
#if ENGLISH
        .nickname = _("WOBET"),
#elif GERMAN
        .nickname = _("WOHINGENAU"),
#endif
#if ENGLISH
        .trainerName = _("HELEN"),
#elif GERMAN
        .trainerName = _("DELIA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_1,
        .aiFlags = CONTEST_AI_SET_F,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_COUNTER,
            MOVE_MIRROR_COAT,
            MOVE_SAFEGUARD,
            MOVE_DESTINY_BOND
        },
        .cool = 60,
        .beauty = 230,
        .cute = 50,
        .smart = 220,
        .tough = 210,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CAMILE] = {
        .species = SPECIES_GENGAR,
#if ENGLISH
        .nickname = _("GAREN"),
#elif GERMAN
        .nickname = _("GAROK"),
#endif
#if ENGLISH
        .trainerName = _("CAMILE"),
#elif GERMAN
        .trainerName = _("HELGA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_HEX_MANIAC,
        .aiFlags = CONTEST_AI_SET_1,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_DESTINY_BOND,
            MOVE_CONFUSE_RAY,
            MOVE_LICK,
            MOVE_SLUDGE_BOMB
        },
        .cool = 200,
        .beauty = 100,
        .cute = 50,
        .smart = 80,
        .tough = 180,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_MARTIN] = {
        .species = SPECIES_PORYGON,
#if ENGLISH
        .nickname = _("GONPOR"),
#elif GERMAN
        .nickname = _("POLY"),
#endif
#if ENGLISH
        .trainerName = _("MARTIN"),
#elif GERMAN
        .trainerName = _("MAX"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_SCIENTIST_1,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_CONVERSION_2,
            MOVE_CONVERSION,
            MOVE_RETURN,
            MOVE_RECYCLE
        },
        .cool = 130,
        .beauty = 130,
        .cute = 130,
        .smart = 130,
        .tough = 130,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_SERGIO] = {
        .species = SPECIES_DRAGONITE,
#if ENGLISH
        .nickname = _("DRITE"),
#elif GERMAN
        .nickname = _("DRAGAN"),
#endif
#if ENGLISH
        .trainerName = _("SERGIO"),
#elif GERMAN
        .trainerName = _("SILVIO"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_BOY_1,
        .aiFlags = CONTEST_AI_SET_3,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_OUTRAGE,
            MOVE_SLAM,
            MOVE_TWISTER,
            MOVE_EARTHQUAKE
        },
        .cool = 150,
        .beauty = 140,
        .cute = 50,
        .smart = 120,
        .tough = 150,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_KAILEY] = {
        .species = SPECIES_MEOWTH,
#if ENGLISH
        .nickname = _("MEOWY"),
#elif GERMAN
        .nickname = _("MIAUZI"),
#endif
#if ENGLISH
        .trainerName = _("KAILEY"),
#elif GERMAN
        .trainerName = _("KARLA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_TWIN,
        .aiFlags = CONTEST_AI_SET_4,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_GROWL,
            MOVE_TAUNT,
            MOVE_PAY_DAY,
            MOVE_BITE
        },
        .cool = 125,
        .beauty = 110,
        .cute = 180,
        .smart = 170,
        .tough = 80,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_PERLA] = {
        .species = SPECIES_JYNX,
#if ENGLISH
        .nickname = _("NYX"),
#elif GERMAN
        .nickname = _("ROSSA"),
#endif
#if ENGLISH
        .trainerName = _("PERLA"),
#elif GERMAN
        .trainerName = _("PAMELA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_BEAUTY,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_PERISH_SONG,
            MOVE_MEAN_LOOK,
            MOVE_LOVELY_KISS,
            MOVE_FAKE_TEARS
        },
        .cool = 100,
        .beauty = 150,
        .cute = 100,
        .smart = 150,
        .tough = 120,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CLARA] = {
        .species = SPECIES_TOGEPI,
#if ENGLISH
        .nickname = _("GEPITO"),
#elif GERMAN
        .nickname = _("EPIGO"),
#endif
#if ENGLISH
        .trainerName = _("CLARA"),
#elif GERMAN
        .trainerName = _("HANNA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_2,
        .aiFlags = CONTEST_AI_SET_6,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_GROWL,
            MOVE_YAWN,
            MOVE_ENCORE,
            MOVE_FOLLOW_ME
        },
        .cool = 80,
        .beauty = 120,
        .cute = 200,
        .smart = 120,
        .tough = 80,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_JAKOB] = {
        .species = SPECIES_ESPEON,
#if ENGLISH
        .nickname = _("SPEON"),
#elif GERMAN
        .nickname = _("PSYSY"),
#endif
#if ENGLISH
        .trainerName = _("JAKOB"),
#elif GERMAN
        .trainerName = _("JULIUS"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_PSYCHIC_M,
        .aiFlags = CONTEST_AI_SET_7,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SWIFT,
            MOVE_QUICK_ATTACK,
            MOVE_MORNING_SUN,
            MOVE_TAIL_WHIP
        },
        .cool = 180,
        .beauty = 150,
        .cute = 100,
        .smart = 80,
        .tough = 150,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_TREY] = {
        .species = SPECIES_SLOWKING,
#if ENGLISH
        .nickname = _("SLOWGO"),
#elif GERMAN
        .nickname = _("LETHARGO"),
#endif
#if ENGLISH
        .trainerName = _("TREY"),
#elif GERMAN
        .trainerName = _("ANSGAR"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_SAILOR,
        .aiFlags = CONTEST_AI_SET_8,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_FACADE,
            MOVE_CURSE,
            MOVE_YAWN,
            MOVE_FOCUS_PUNCH
        },
        .cool = 100,
        .beauty = 80,
        .cute = 200,
        .smart = 110,
        .tough = 170,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_LANE] = {
        .species = SPECIES_URSARING,
#if ENGLISH
        .nickname = _("URSING"),
#elif GERMAN
        .nickname = _("RINGO"),
#endif
#if ENGLISH
        .trainerName = _("LANE"),
#elif GERMAN
        .trainerName = _("LUDWIG"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_BLACK_BELT,
        .aiFlags = CONTEST_AI_SET_9,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_THRASH,
            MOVE_AERIAL_ACE,
            MOVE_FAKE_TEARS,
            MOVE_LEER
        },
        .cool = 180,
        .beauty = 140,
        .cute = 30,
        .smart = 80,
        .tough = 190,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    }
};


const u8 gPostgameContestOpponentFilter[] =
{
    [CONTEST_OPPONENT_JIMMY] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_EDITH] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_EVAN] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_KELSEY] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_MADISON] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_RAYMOND] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_GRANT] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_PAIGE] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_ALEC] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_SYDNEY] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_MORRIS] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_MARIAH] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_RUSSELL] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_MELANIE] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_CHANCE] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_AGATHA] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_BEAU] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_KAY] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_CALE] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_CAITLIN] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_COLBY] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_KYLIE] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_LIAM] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_MILO] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_KARINA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_BOBBY] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_CLAIRE] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_WILLIE] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_CASSIDY] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_MORGAN] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_SUMMER] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_MILES] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_AUDREY] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_AVERY] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_ARIANA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_ASHTON] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_SANDRA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_CARSON] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_KATRINA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_LUKE] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_RAUL] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_JADA] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_ZEEK] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_DIEGO] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_ALIYAH] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_NATALIA] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_DEVIN] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_TYLOR] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_RONNIE] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_CLAUDIA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_ELIAS] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_JADE] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_FRANCIS] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_ALISHA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_SAUL] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_FELICIA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_EMILIO] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_KARLA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_DARRYL] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_SELENA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_NOEL] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_LACEY] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_CORBIN] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_GRACIE] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_COLTIN] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_ELLIE] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_MARCUS] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_KIARA] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_BRYCE] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_JAMIE] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_JORGE] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_DEVON] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_JUSTINA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_RALPH] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_ROSA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_KEATON] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_MAYRA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_LAMAR] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_AUBREY] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_NIGEL] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_CAMILLE] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_DEON] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_JANELLE] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_HEATH] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_SASHA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_FRANKIE] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_HELEN] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_CAMILE] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_MARTIN] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_SERGIO] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_KAILEY] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_PERLA] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_CLARA] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_JAKOB] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_TREY] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_LANE] = CONTEST_FILTER_ONLY_POSTGAME
};
