#ifndef GUARD_DATA_BARD_MUSIC_MOVES_H
#define GUARD_DATA_BARD_MUSIC_MOVES_H

#include "constants/moves.h"

const u16 gNumBardWords_Moves = MOVES_COUNT;

const struct BardSound gBardSounds_Moves[MOVES_COUNT][6] = {
    [MOVE_NONE] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [MOVE_POUND] = {
#if ENGLISH
        { .songLengthId = 33 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_KARATE_CHOP] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 29 },
        { .songLengthId = 14 },
        { .songLengthId = 29 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_DOUBLE_SLAP] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 10 },
        { .songLengthId =  2 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_COMET_PUNCH] = {
#if ENGLISH
        { .songLengthId = 29 },
        { .songLengthId = 11 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MEGA_PUNCH] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 42 },
        { .songLengthId = 44 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_PAY_DAY] = {
#if ENGLISH
        { .songLengthId = 5 },
        { .songLengthId = 5 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FIRE_PUNCH] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 48 },
        { .songLengthId = 42 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ICE_PUNCH] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 29 },
        { .songLengthId = 14 },
        { .songLengthId = 29 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_THUNDER_PUNCH] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 48 },
        { .songLengthId = 44 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SCRATCH] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_VICE_GRIP] = {
#if ENGLISH
        { .songLengthId = 20 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_GUILLOTINE] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 44 },
        { .songLengthId = 14 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_RAZOR_WIND] = {
#if ENGLISH
        { .songLengthId = 5 },
        { .songLengthId = 48 },
        { .songLengthId = 15 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SWORDS_DANCE] = {
#if ENGLISH
        { .songLengthId = 26 },
        { .songLengthId = 48 },
        { .songLengthId =  1 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_CUT] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_GUST] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_WING_ATTACK] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 42 },
        { .songLengthId =  0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_WHIRLWIND] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 29 },
        { .songLengthId = 14 },
        { .songLengthId = 29 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FLY] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BIND] = {
#if ENGLISH
        { .songLengthId = 20 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SLAM] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_VINE_WHIP] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_STOMP] = {
#if ENGLISH
        { .songLengthId = 29 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_DOUBLE_KICK] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 44 },
        { .songLengthId = 17 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MEGA_KICK] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 42 },
        { .songLengthId = 17 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_JUMP_KICK] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ROLLING_KICK] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 12 },
        { .songLengthId = 17 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SAND_ATTACK] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 42 },
        { .songLengthId =  0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_HEADBUTT] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_HORN_ATTACK] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 42 },
        { .songLengthId =  0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FURY_ATTACK] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
        { .songLengthId =  2 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_HORN_DRILL] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_TACKLE] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 36 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BODY_SLAM] = {
#if ENGLISH
        { .songLengthId = 29 },
        { .songLengthId = 12 },
        { .songLengthId =  2 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_WRAP] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_TAKE_DOWN] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 35 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_THRASH] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId =  2 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_DOUBLE_EDGE] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 36 },
        { .songLengthId = 10 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_TAIL_WHIP] = {
#if ENGLISH
        { .songLengthId = 5 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_POISON_STING] = {
#if ENGLISH
        { .songLengthId = 30 },
        { .songLengthId = 44 },
        { .songLengthId = 14 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_TWINEEDLE] = {
#if ENGLISH
        { .songLengthId = 15 },
        { .songLengthId = 12 },
        { .songLengthId = 36 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_PIN_MISSILE] = {
#if ENGLISH
        { .songLengthId = 15 },
        { .songLengthId = 17 },
        { .songLengthId = 36 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_LEER] = {
#if ENGLISH
        { .songLengthId = 14 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BITE] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_GROWL] = {
#if ENGLISH
        { .songLengthId = 33 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ROAR] = {
#if ENGLISH
        { .songLengthId = 26 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SING] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SUPERSONIC] = {
#if ENGLISH
        { .songLengthId = 39 },
        { .songLengthId = 48 },
        { .songLengthId = 27 },
        { .songLengthId = 17 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SONIC_BOOM] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 17 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_DISABLE] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId =  3 },
        { .songLengthId = 36 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ACID] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_EMBER] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FLAMETHROWER] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 26 },
        { .songLengthId = 48 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MIST] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_WATER_GUN] = {
#if ENGLISH
        { .songLengthId = 29 },
        { .songLengthId = 50 },
        { .songLengthId = 44 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_HYDRO_PUMP] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 24 },
        { .songLengthId = 42 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SURF] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ICE_BEAM] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BLIZZARD] = {
#if ENGLISH
        { .songLengthId = 15 },
        { .songLengthId = 50 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_PSYBEAM] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BUBBLE_BEAM] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 36 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_AURORA_BEAM] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 26 },
        { .songLengthId = 44 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_HYPER_BEAM] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 48 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_PECK] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_DRILL_PECK] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 11 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SUBMISSION] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 17 },
        { .songLengthId = 11 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_LOW_KICK] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_COUNTER] = {
#if ENGLISH
        { .songLengthId = 33 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SEISMIC_TOSS] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 17 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_STRENGTH] = {
#if ENGLISH
        { .songLengthId = 50 },
        { .songLengthId =  3 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ABSORB] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 26 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MEGA_DRAIN] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 44 },
        { .songLengthId =  3 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_LEECH_SEED] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 14 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_GROWTH] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_RAZOR_LEAF] = {
#if ENGLISH
        { .songLengthId = 5 },
        { .songLengthId = 48 },
        { .songLengthId = 12 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SOLAR_BEAM] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 48 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_POISON_POWDER] = {
#if ENGLISH
        { .songLengthId = 30 },
        { .songLengthId = 44 },
        { .songLengthId = 33 },
        { .songLengthId = 48 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_STUN_SPORE] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 26 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SLEEP_POWDER] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 33 },
        { .songLengthId = 48 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_PETAL_DANCE] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 44 },
        { .songLengthId =  2 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_STRING_SHOT] = {
#if ENGLISH
        { .songLengthId = 50 },
        { .songLengthId = 12 },
        { .songLengthId = 27 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_DRAGON_RAGE] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 27 },
        { .songLengthId = 5 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FIRE_SPIN] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 48 },
        { .songLengthId = 15 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_THUNDER_SHOCK] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 48 },
        { .songLengthId = 27 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_THUNDERBOLT] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 48 },
        { .songLengthId = 26 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_THUNDER_WAVE] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 48 },
        { .songLengthId = 5 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_THUNDER] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ROCK_THROW] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_EARTHQUAKE] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 5 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FISSURE] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 50 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_DIG] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_TOXIC] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_CONFUSION] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 41 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_PSYCHIC] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 15 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_HYPNOSIS] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 24 },
        { .songLengthId = 17 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MEDITATE] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 17 },
        { .songLengthId =  3 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_AGILITY] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 17 },
        { .songLengthId = 17 },
        { .songLengthId = 14 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_QUICK_ATTACK] = {
#if ENGLISH
        { .songLengthId = 39 },
        { .songLengthId = 17 },
        { .songLengthId = 42 },
        { .songLengthId =  0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_RAGE] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_TELEPORT] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 12 },
        { .songLengthId = 26 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_NIGHT_SHADE] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 5 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MIMIC] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SCREECH] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 13 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_DOUBLE_TEAM] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 44 },
        { .songLengthId = 12 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_RECOVER] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 44 },
        { .songLengthId = 48 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_HARDEN] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MINIMIZE] = {
#if ENGLISH
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        { .songLengthId = 18 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SMOKESCREEN] = {
#if ENGLISH
        { .songLengthId = 26 },
        { .songLengthId = 14 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_CONFUSE_RAY] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 45 },
        { .songLengthId =  3 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_WITHDRAW] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_DEFENSE_CURL] = {
#if ENGLISH
        { .songLengthId = 14 },
        { .songLengthId = 11 },
        { .songLengthId = 50 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BARRIER] = {
#if ENGLISH
        { .songLengthId = 5 },
        { .songLengthId = 14 },
        { .songLengthId = 48 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_LIGHT_SCREEN] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_HAZE] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_REFLECT] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FOCUS_ENERGY] = {
#if ENGLISH
        { .songLengthId = 26 },
        { .songLengthId = 44 },
        { .songLengthId = 11 },
        { .songLengthId = 48 },
        { .songLengthId = 12 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BIDE] = {
#if ENGLISH
        { .songLengthId = 11 },
        { .songLengthId = 50 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_METRONOME] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MIRROR_MOVE] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 50 },
        { .songLengthId = 41 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SELF_DESTRUCT] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_EGG_BOMB] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_LICK] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SMOG] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SLUDGE] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BONE_CLUB] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FIRE_BLAST] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 48 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_WATERFALL] = {
#if ENGLISH
        { .songLengthId = 29 },
        { .songLengthId = 48 },
        { .songLengthId = 29 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_CLAMP] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SWIFT] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SKULL_BASH] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 51 },
        { .songLengthId =  0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SPIKE_CANNON] = {
#if ENGLISH
        { .songLengthId = 20 },
        { .songLengthId =  0 },
        { .songLengthId = 29 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_CONSTRICT] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_AMNESIA] = {
#if ENGLISH
        { .songLengthId =  2 },
        { .songLengthId = 14 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_KINESIS] = {
#if ENGLISH
        { .songLengthId = 15 },
        { .songLengthId = 12 },
        { .songLengthId = 17 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SOFT_BOILED] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 30 },
        { .songLengthId = 11 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_HI_JUMP_KICK] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 44 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_GLARE] = {
#if ENGLISH
        { .songLengthId = 5 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_DREAM_EATER] = {
#if ENGLISH
        { .songLengthId = 14 },
        { .songLengthId = 12 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_POISON_GAS] = {
#if ENGLISH
        { .songLengthId = 30 },
        { .songLengthId = 27 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BARRAGE] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_LEECH_LIFE] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 18 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_LOVELY_KISS] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 44 },
        { .songLengthId = 12 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SKY_ATTACK] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 42 },
        { .songLengthId =  0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_TRANSFORM] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 26 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BUBBLE] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 36 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_DIZZY_PUNCH] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 14 },
        { .songLengthId = 44 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SPORE] = {
#if ENGLISH
        { .songLengthId = 26 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FLASH] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_PSYWAVE] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId =  3 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SPLASH] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ACID_ARMOR] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 17 },
        { .songLengthId = 27 },
        { .songLengthId = 48 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_CRABHAMMER] = {
#if ENGLISH
        { .songLengthId =  2 },
        { .songLengthId =  0 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_EXPLOSION] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FURY_SWIPES] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 12 },
        { .songLengthId = 18 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BONEMERANG] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 48 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_REST] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ROCK_SLIDE] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 18 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_HYPER_FANG] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 48 },
        { .songLengthId =  0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SHARPEN] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_CONVERSION] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 48 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_TRI_ATTACK] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 42 },
        { .songLengthId =  0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SUPER_FANG] = {
#if ENGLISH
        { .songLengthId = 39 },
        { .songLengthId = 48 },
        { .songLengthId =  1 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SLASH] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SUBSTITUTE] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 17 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_STRUGGLE] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 36 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SKETCH] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_TRIPLE_KICK] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 36 },
        { .songLengthId = 17 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_THIEF] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SPIDER_WEB] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 48 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MIND_READER] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 12 },
        { .songLengthId = 48 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_NIGHTMARE] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 5 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FLAME_WHEEL] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 14 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SNORE] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_CURSE] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FLAIL] = {
#if ENGLISH
        { .songLengthId = 5 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_CONVERSION_2] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 48 },
        { .songLengthId = 44 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_AEROBLAST] = {
#if ENGLISH
        { .songLengthId = 5 },
        { .songLengthId = 24 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_COTTON_SPORE] = {
#if ENGLISH
        { .songLengthId = 29 },
        { .songLengthId = 29 },
        { .songLengthId = 26 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_REVERSAL] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 48 },
        { .songLengthId = 36 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SPITE] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_POWDER_SNOW] = {
#if ENGLISH
        { .songLengthId = 33 },
        { .songLengthId = 48 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_PROTECT] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MACH_PUNCH] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SCARY_FACE] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 12 },
        { .songLengthId =  3 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FAINT_ATTACK] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 42 },
        { .songLengthId =  0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SWEET_KISS] = {
#if ENGLISH
        { .songLengthId = 14 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BELLY_DRUM] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SLUDGE_BOMB] = {
#if ENGLISH
        { .songLengthId = 43 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MUD_SLAP] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_OCTAZOOKA] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 44 },
        { .songLengthId = 40 },
        { .songLengthId = 44 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SPIKES] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ZAP_CANNON] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId =  1 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FORESIGHT] = {
#if ENGLISH
        { .songLengthId = 26 },
        { .songLengthId = 20 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_DESTINY_BOND] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 12 },
        { .songLengthId = 27 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_PERISH_SONG] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 17 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ICY_WIND] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 12 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_DETECT] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BONE_RUSH] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_LOCK_ON] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 29 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_OUTRAGE] = {
#if ENGLISH
        { .songLengthId = 33 },
        { .songLengthId =  3 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SANDSTORM] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 26 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_GIGA_DRAIN] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 42 },
        { .songLengthId =  3 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ENDURE] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_CHARM] = {
#if ENGLISH
        { .songLengthId = 21 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ROLLOUT] = {
#if ENGLISH
        { .songLengthId = 26 },
        { .songLengthId = 33 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FALSE_SWIPE] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 18 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SWAGGER] = {
#if ENGLISH
        { .songLengthId =  2 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MILK_DRINK] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 14 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SPARK] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FURY_CUTTER] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
        { .songLengthId = 48 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_STEEL_WING] = {
#if ENGLISH
        { .songLengthId = 14 },
        { .songLengthId = 13 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MEAN_LOOK] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 36 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ATTRACT] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SLEEP_TALK] = {
#if ENGLISH
        { .songLengthId = 14 },
        { .songLengthId = 29 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_HEAL_BELL] = {
#if ENGLISH
        { .songLengthId = 14 },
        { .songLengthId = 10 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_RETURN] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_PRESENT] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FRUSTRATION] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId =  3 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SAFEGUARD] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_PAIN_SPLIT] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 15 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SACRED_FIRE] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 17 },
        { .songLengthId = 18 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
#endif
    },
    [MOVE_MAGNITUDE] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 15 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_DYNAMIC_PUNCH] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId =  0 },
        { .songLengthId = 17 },
        { .songLengthId = 44 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MEGAHORN] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 42 },
        { .songLengthId = 26 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_DRAGON_BREATH] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 27 },
        { .songLengthId = 11 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BATON_PASS] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 27 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ENCORE] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_PURSUIT] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_RAPID_SPIN] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SWEET_SCENT] = {
#if ENGLISH
        { .songLengthId = 14 },
        { .songLengthId = 11 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_IRON_TAIL] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 27 },
        { .songLengthId = 5 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_METAL_CLAW] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 36 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_VITAL_THROW] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 36 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MORNING_SUN] = {
#if ENGLISH
        { .songLengthId = 26 },
        { .songLengthId = 14 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SYNTHESIS] = {
#if ENGLISH
        { .songLengthId = 15 },
        { .songLengthId = 42 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MOONLIGHT] = {
#if ENGLISH
        { .songLengthId = 39 },
        { .songLengthId = 18 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_HIDDEN_POWER] = {
#if ENGLISH
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 33 },
        { .songLengthId = 48 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_CROSS_CHOP] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 29 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_TWISTER] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_RAIN_DANCE] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SUNNY_DAY] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 14 },
        { .songLengthId = 5 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_CRUNCH] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MIRROR_COAT] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 48 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_PSYCH_UP] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_EXTREME_SPEED] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 12 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ANCIENT_POWER] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 12 },
        { .songLengthId = 33 },
        { .songLengthId = 50 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SHADOW_BALL] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 24 },
        { .songLengthId = 27 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FUTURE_SIGHT] = {
#if ENGLISH
        { .songLengthId = 39 },
        { .songLengthId = 48 },
        { .songLengthId = 18 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ROCK_SMASH] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_WHIRLPOOL] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 39 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BEAT_UP] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FAKE_OUT] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 33 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_UPROAR] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 26 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_STOCKPILE] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 20 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SPIT_UP] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SWALLOW] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_HEAT_WAVE] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId =  3 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_HAIL] = {
#if ENGLISH
        { .songLengthId = 5 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_TORMENT] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FLATTER] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_WILL_O_WISP] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 24 },
        { .songLengthId = 17 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MEMENTO] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FACADE] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FOCUS_PUNCH] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 44 },
        { .songLengthId = 44 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SMELLING_SALT] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 12 },
        { .songLengthId = 27 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FOLLOW_ME] = {
#if ENGLISH
        { .songLengthId = 21 },
        { .songLengthId = 24 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_NATURE_POWER] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 48 },
        { .songLengthId = 33 },
        { .songLengthId = 48 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_CHARGE] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_TAUNT] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_HELPING_HAND] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 12 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_TRICK] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ROLE_PLAY] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId =  3 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_WISH] = {
#if ENGLISH
        { .songLengthId = 15 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ASSIST] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_INGRAIN] = {
#if ENGLISH
        { .songLengthId = 15 },
        { .songLengthId =  3 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SUPERPOWER] = {
#if ENGLISH
        { .songLengthId = 39 },
        { .songLengthId = 48 },
        { .songLengthId = 33 },
        { .songLengthId = 48 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MAGIC_COAT] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 17 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_RECYCLE] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 18 },
        { .songLengthId = 36 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 39 },
#endif
    },
    [MOVE_REVENGE] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BRICK_BREAK] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 5 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_YAWN] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_KNOCK_OFF] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 29 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ENDEAVOR] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 48 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
#endif
    },
    [MOVE_ERUPTION] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 44 },
        { .songLengthId = 29 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SKILL_SWAP] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_IMPRISON] = {
#if ENGLISH
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_REFRESH] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_GRUDGE] = {
#if ENGLISH
        { .songLengthId = 43 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SNATCH] = {
#if ENGLISH
        { .songLengthId =  0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SECRET_POWER] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 9 },
        { .songLengthId = 33 },
        { .songLengthId = 48 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
#endif
    },
    [MOVE_DIVE] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ARM_THRUST] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_CAMOUFLAGE] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 24 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_TAIL_GLOW] = {
#if ENGLISH
        { .songLengthId = 4 },
        { .songLengthId = 26 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_LUSTER_PURGE] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 48 },
        { .songLengthId = 50 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MIST_BALL] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FEATHER_DANCE] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 48 },
        { .songLengthId =  0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
#endif
    },
    [MOVE_TEETER_DANCE] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 48 },
        { .songLengthId =  0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BLAZE_KICK] = {
#if ENGLISH
        { .songLengthId = 5 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MUD_SPORT] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 24 },
        { .songLengthId = 48 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ICE_BALL] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_NEEDLE_ARM] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 42 },
        { .songLengthId = 29 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SLACK_OFF] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_HYPER_VOICE] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 48 },
        { .songLengthId = 30 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_POISON_FANG] = {
#if ENGLISH
        { .songLengthId = 30 },
        { .songLengthId = 42 },
        { .songLengthId =  0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_CRUSH_CLAW] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BLAST_BURN] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        { .songLengthId = 48 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
#endif
    },
    [MOVE_HYDRO_CANNON] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 24 },
        { .songLengthId =  0 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
#endif
    },
    [MOVE_METEOR_MASH] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 12 },
        { .songLengthId = 24 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ASTONISH] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 27 },
        { .songLengthId = 17 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_WEATHER_BALL] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 48 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
#endif
    },
    [MOVE_AROMATHERAPY] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 24 },
        { .songLengthId = 44 },
        { .songLengthId =  0 },
        { .songLengthId = 27 },
        { .songLengthId = 14 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FAKE_TEARS] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 14 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_AIR_CUTTER] = {
#if ENGLISH
        { .songLengthId = 5 },
        { .songLengthId = 42 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_OVERHEAT] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 48 },
        { .songLengthId = 12 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ODOR_SLEUTH] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 48 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ROCK_TOMB] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SILVER_WIND] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 48 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_METAL_SOUND] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 27 },
        { .songLengthId = 33 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_GRASS_WHISTLE] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 17 },
        { .songLengthId = 36 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_TICKLE] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 36 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_COSMIC_POWER] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 17 },
        { .songLengthId = 33 },
        { .songLengthId = 48 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_WATER_SPOUT] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 48 },
        { .songLengthId = 33 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SIGNAL_BEAM] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 27 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SHADOW_PUNCH] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 24 },
        { .songLengthId = 44 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_EXTRASENSORY] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 42 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 12 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SKY_UPPERCUT] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 44 },
        { .songLengthId = 48 },
        { .songLengthId = 42 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SAND_TOMB] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SHEER_COLD] = {
#if ENGLISH
        { .songLengthId = 14 },
        { .songLengthId = 48 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MUDDY_WATER] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 12 },
        { .songLengthId = 27 },
        { .songLengthId = 48 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BULLET_SEED] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 9 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_AERIAL_ACE] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
        { .songLengthId =  3 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ICICLE_SPEAR] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 15 },
        { .songLengthId = 42 },
        { .songLengthId = 12 },
        { .songLengthId = 48 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_IRON_DEFENSE] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 27 },
        { .songLengthId = 12 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BLOCK] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_HOWL] = {
#if ENGLISH
        { .songLengthId = 33 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_DRAGON_CLAW] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 27 },
        { .songLengthId = 29 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_FRENZY_PLANT] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 9 },
        { .songLengthId = 12 },
        { .songLengthId =  0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
#endif
    },
    [MOVE_BULK_UP] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_BOUNCE] = {
#if ENGLISH
        { .songLengthId = 33 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MUD_SHOT] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 29 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_POISON_TAIL] = {
#if ENGLISH
        { .songLengthId = 30 },
        { .songLengthId = 44 },
        { .songLengthId = 5 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_COVET] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_VOLT_TACKLE] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 51 },
        { .songLengthId =  0 },
        { .songLengthId = 36 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_MAGICAL_LEAF] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 17 },
        { .songLengthId = 36 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_WATER_SPORT] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 48 },
        { .songLengthId = 26 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_CALM_MIND] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 18 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_LEAF_BLADE] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 5 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_DRAGON_DANCE] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 27 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_ROCK_BLAST] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_SHOCK_WAVE] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId =  3 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_WATER_PULSE] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 48 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_DOOM_DESIRE] = {
#if ENGLISH
        { .songLengthId = 39 },
        { .songLengthId = 51 },
        { .songLengthId = 12 },
        { .songLengthId = 18 },
        { .songLengthId = 48 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    },
    [MOVE_PSYCHO_BOOST] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 15 },
        { .songLengthId = 51 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
    }
};

#endif //GUARD_DATA_BARD_MUSIC_MOVES_H
