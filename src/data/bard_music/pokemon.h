#ifndef GUARD_DATA_BARD_MUSIC_POKEMON_H
#define GUARD_DATA_BARD_MUSIC_POKEMON_H

const u16 gNumBardWords_Species = NUM_SPECIES;

const struct BardSound gBardSounds_Pokemon[NUM_SPECIES][6] = {
    [SPECIES_NONE] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_BULBASAUR] = {
#if ENGLISH
        { .songLengthId = 36 },
        { .songLengthId = 42 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_IVYSAUR] = {
#if ENGLISH
        { .songLengthId = 20 },
        { .songLengthId = 12 },
        { .songLengthId = 50 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_VENUSAUR] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 44 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CHARMANDER] = {
#if ENGLISH
        { .songLengthId = 6 },
        { .songLengthId =  2 },
        { .songLengthId = 50 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CHARMELEON] = {
#if ENGLISH
        { .songLengthId = 6 },
        { .songLengthId = 12 },
        { .songLengthId = 12 },
        { .songLengthId = 21 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
    },
    [SPECIES_CHARIZARD] = {
#if ENGLISH
        { .songLengthId = 6 },
        { .songLengthId = 17 },
        { .songLengthId = 50 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
    },
    [SPECIES_SQUIRTLE] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 36 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_WARTORTLE] = {
#if ENGLISH
        { .songLengthId = 8 },
        { .songLengthId = 48 },
        { .songLengthId = 36 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_BLASTOISE] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 30 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CATERPIE] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 48 },
        { .songLengthId = 12 },
#elif GERMAN
        { .songLengthId =  0 },
        { .songLengthId = 39 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_METAPOD] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 42 },
        { .songLengthId = 21 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_BUTTERFREE] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 48 },
        { .songLengthId = 12 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_WEEDLE] = {
#if ENGLISH
        { .songLengthId = 14 },
        { .songLengthId = 38 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 39 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_KAKUNA] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 39 },
        { .songLengthId = 42 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 39 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_BEEDRILL] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_PIDGEY] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_PIDGEOTTO] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 12 },
        { .songLengthId = 24 },
        { .songLengthId = 24 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_PIDGEOT] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 12 },
        { .songLengthId = 21 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_RATTATA] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId =  0 },
        { .songLengthId = 44 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_RATICATE] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 12 },
        { .songLengthId =  3 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SPEAROW] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_FEAROW] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_EKANS] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ARBOK] = {
#if ENGLISH
        { .songLengthId = 6 },
        { .songLengthId = 23 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_PIKACHU] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 42 },
        { .songLengthId = 39 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_RAICHU] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 39 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SANDSHREW] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SANDSLASH] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_NIDORAN_F] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 24 },
        { .songLengthId =  0 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_NIDORINA] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 24 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_NIDOQUEEN] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 24 },
        { .songLengthId = 12 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_NIDORAN_M] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 24 },
        { .songLengthId =  0 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_NIDORINO] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 24 },
        { .songLengthId = 12 },
        { .songLengthId = 24 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_NIDOKING] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 24 },
        { .songLengthId = 12 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CLEFAIRY] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 11 },
        { .songLengthId = 12 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CLEFABLE] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 42 },
        { .songLengthId = 36 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_VULPIX] = {
#if ENGLISH
        { .songLengthId = 36 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_NINETALES] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 5 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_JIGGLYPUFF] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 39 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
    },
    [SPECIES_WIGGLYTUFF] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 39 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
    },
    [SPECIES_ZUBAT] = {
#if ENGLISH
        { .songLengthId = 39 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GOLBAT] = {
#if ENGLISH
        { .songLengthId = 26 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ODDISH] = {
#if ENGLISH
        { .songLengthId = 21 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GLOOM] = {
#if ENGLISH
        { .songLengthId = 39 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_VILEPLUME] = {
#if ENGLISH
        { .songLengthId = 20 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_PARAS] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_PARASECT] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId =  0 },
        { .songLengthId = 9 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_VENONAT] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 26 },
        { .songLengthId =  0 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_VENOMOTH] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 26 },
        { .songLengthId = 21 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_DIGLETT] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_DUGTRIO] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 12 },
        { .songLengthId = 24 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MEOWTH] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 33 },
        { .songLengthId = 17 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_PERSIAN] = {
#if ENGLISH
        { .songLengthId = 50 },
        { .songLengthId = 17 },
        { .songLengthId =  0 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_PSYDUCK] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GOLDUCK] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MANKEY] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_PRIMEAPE] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId =  3 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GROWLITHE] = {
#if ENGLISH
        { .songLengthId = 33 },
        { .songLengthId = 15 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ARCANINE] = {
#if ENGLISH
        { .songLengthId = 6 },
        { .songLengthId =  3 },
        { .songLengthId = 18 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_POLIWAG] = {
#if ENGLISH
        { .songLengthId = 21 },
        { .songLengthId = 12 },
        { .songLengthId =  0 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_POLIWHIRL] = {
#if ENGLISH
        { .songLengthId = 21 },
        { .songLengthId = 12 },
        { .songLengthId = 48 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_POLIWRATH] = {
#if ENGLISH
        { .songLengthId = 21 },
        { .songLengthId = 12 },
        { .songLengthId =  0 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ABRA] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_KADABRA] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId =  0 },
        { .songLengthId = 44 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ALAKAZAM] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 44 },
        { .songLengthId = 44 },
        { .songLengthId =  0 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MACHOP] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 21 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MACHOKE] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 26 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MACHAMP] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_BELLSPROUT] = {
#if ENGLISH
        { .songLengthId = 11 },
        { .songLengthId = 33 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_WEEPINBELL] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 15 },
        { .songLengthId = 11 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
    },
    [SPECIES_VICTREEBEL] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 12 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_TENTACOOL] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 42 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_TENTACRUEL] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 42 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GEODUDE] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 24 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GRAVELER] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 9 },
        { .songLengthId = 48 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GOLEM] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_PONYTA] = {
#if ENGLISH
        { .songLengthId = 26 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_RAPIDASH] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 17 },
        { .songLengthId =  0 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SLOWPOKE] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SLOWBRO] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MAGNEMITE] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 9 },
        { .songLengthId = 18 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MAGNETON] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 9 },
        { .songLengthId = 42 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_FARFETCHD] = {
#if ENGLISH
        { .songLengthId = 6 },
        { .songLengthId = 11 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_DODUO] = {
#if ENGLISH
        { .songLengthId = 26 },
        { .songLengthId = 39 },
        { .songLengthId = 24 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_DODRIO] = {
#if ENGLISH
        { .songLengthId = 26 },
        { .songLengthId = 12 },
        { .songLengthId = 24 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SEEL] = {
#if ENGLISH
        { .songLengthId = 14 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_DEWGONG] = {
#if ENGLISH
        { .songLengthId = 39 },
        { .songLengthId = 21 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GRIMER] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MUK] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SHELLDER] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CLOYSTER] = {
#if ENGLISH
        { .songLengthId = 30 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GASTLY] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 14 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_HAUNTER] = {
#if ENGLISH
        { .songLengthId = 21 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GENGAR] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 8 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ONIX] = {
#if ENGLISH
        { .songLengthId = 21 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_DROWZEE] = {
#if ENGLISH
        { .songLengthId = 33 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_HYPNO] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_KRABBY] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_KINGLER] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_VOLTORB] = {
#if ENGLISH
        { .songLengthId = 26 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ELECTRODE] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_EXEGGCUTE] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 44 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_EXEGGUTOR] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 44 },
        { .songLengthId = 9 },
        { .songLengthId = 50 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
    },
    [SPECIES_CUBONE] = {
#if ENGLISH
        { .songLengthId = 45 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MAROWAK] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 26 },
        { .songLengthId =  0 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_HITMONLEE] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 21 },
        { .songLengthId = 12 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_HITMONCHAN] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 21 },
        { .songLengthId =  0 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_LICKITUNG] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
#elif GERMAN
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_KOFFING] = {
#if ENGLISH
        { .songLengthId = 21 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_WEEZING] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_RHYHORN] = {
#if ENGLISH
        { .songLengthId = 20 },
        { .songLengthId = 26 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_RHYDON] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 21 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CHANSEY] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_TANGELA] = {
#if ENGLISH
        { .songLengthId =  2 },
        { .songLengthId = 9 },
        { .songLengthId = 42 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_KANGASKHAN] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId =  0 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_HORSEA] = {
#if ENGLISH
        { .songLengthId = 26 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SEADRA] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GOLDEEN] = {
#if ENGLISH
        { .songLengthId = 26 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SEAKING] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_STARYU] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_STARMIE] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MR_MIME] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 48 },
        { .songLengthId = 18 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SCYTHER] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_JYNX] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ELECTABUZZ] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 9 },
        { .songLengthId = 44 },
        { .songLengthId = 44 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MAGMAR] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 29 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_PINSIR] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_TAUROS] = {
#if ENGLISH
        { .songLengthId = 29 },
        { .songLengthId = 26 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MAGIKARP] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 17 },
        { .songLengthId = 27 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GYARADOS] = {
#if ENGLISH
        { .songLengthId = 29 },
        { .songLengthId = 9 },
        { .songLengthId = 17 },
        { .songLengthId = 29 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_LAPRAS] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_DITTO] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_EEVEE] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_VAPOREON] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 24 },
        { .songLengthId = 12 },
        { .songLengthId = 21 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_JOLTEON] = {
#if ENGLISH
        { .songLengthId = 26 },
        { .songLengthId = 12 },
        { .songLengthId = 21 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_FLAREON] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 12 },
        { .songLengthId = 21 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_PORYGON] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 12 },
        { .songLengthId = 21 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OMANYTE] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId =  0 },
        { .songLengthId = 18 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OMASTAR] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId =  0 },
        { .songLengthId = 21 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_KABUTO] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 39 },
        { .songLengthId = 26 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_KABUTOPS] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 39 },
        { .songLengthId = 21 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_AERODACTYL] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 24 },
        { .songLengthId =  0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
    },
    [SPECIES_SNORLAX] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ARTICUNO] = {
#if ENGLISH
        { .songLengthId = 6 },
        { .songLengthId = 17 },
        { .songLengthId = 39 },
        { .songLengthId = 24 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ZAPDOS] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MOLTRES] = {
#if ENGLISH
        { .songLengthId = 26 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_DRATINI] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 12 },
        { .songLengthId = 12 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_DRAGONAIR] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 21 },
        { .songLengthId = 11 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_DRAGONITE] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 21 },
        { .songLengthId = 18 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MEWTWO] = {
#if ENGLISH
        { .songLengthId = 45 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 39 },
        { .songLengthId = 39 },
        { .songLengthId = 39 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MEW] = {
#if ENGLISH
        { .songLengthId = 45 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 39 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CHIKORITA] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 24 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_BAYLEEF] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MEGANIUM] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 9 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CYNDAQUIL] = {
#if ENGLISH
        { .songLengthId = 15 },
        { .songLengthId = 42 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_QUILAVA] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 6 },
        { .songLengthId = 8 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_TYPHLOSION] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 24 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 39 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
    },
    [SPECIES_TOTODILE] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        { .songLengthId = 18 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CROCONAW] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 24 },
        { .songLengthId = 27 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_FERALIGATR] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId =  0 },
        { .songLengthId = 15 },
        { .songLengthId =  3 },
        { .songLengthId = 48 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
    },
    [SPECIES_SENTRET] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_FURRET] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_HOOTHOOT] = {
#if ENGLISH
        { .songLengthId = 39 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_NOCTOWL] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 33 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_LEDYBA] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_LEDIAN] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 12 },
        { .songLengthId =  0 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SPINARAK] = {
#if ENGLISH
        { .songLengthId = 15 },
        { .songLengthId = 48 },
        { .songLengthId =  0 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ARIADOS] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
        { .songLengthId = 24 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CROBAT] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CHINCHOU] = {
#if ENGLISH
        { .songLengthId = 15 },
        { .songLengthId = 33 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_LANTURN] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_PICHU] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CLEFFA] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_IGGLYBUFF] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 42 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_TOGEPI] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 12 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_TOGETIC] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 17 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_NATU] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_XATU] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MAREEP] = {
#if ENGLISH
        { .songLengthId = 29 },
        { .songLengthId = 14 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_FLAAFFY] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_AMPHAROS] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 6 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_BELLOSSOM] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 27 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MARILL] = {
#if ENGLISH
        { .songLengthId = 8 },
        { .songLengthId = 16 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_AZUMARILL] = {
#if ENGLISH
        { .songLengthId = 8 },
        { .songLengthId = 39 },
        { .songLengthId = 44 },
        { .songLengthId = 16 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SUDOWOODO] = {
#if ENGLISH
        { .songLengthId = 39 },
        { .songLengthId = 24 },
        { .songLengthId = 39 },
        { .songLengthId = 24 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_POLITOED] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 12 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_HOPPIP] = {
#if ENGLISH
        { .songLengthId = 29 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SKIPLOOM] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_JUMPLUFF] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_AIPOM] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SUNKERN] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SUNFLORA] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 24 },
        { .songLengthId = 44 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_YANMA] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_WOOPER] = {
#if ENGLISH
        { .songLengthId = 39 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_QUAGSIRE] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 18 },
        { .songLengthId = 50 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ESPEON] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 12 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_UMBREON] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 12 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MURKROW] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SLOWKING] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MISDREAVUS] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 12 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 39 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_UNOWN] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 26 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_WOBBUFFET] = {
#if ENGLISH
        { .songLengthId = 29 },
        { .songLengthId = 44 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
#endif
        NULL_BARD_SOUND,
    },
    [SPECIES_GIRAFARIG] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId =  0 },
        { .songLengthId = 42 },
        { .songLengthId = 17 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_PINECO] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_FORRETRESS] = {
#if ENGLISH
        { .songLengthId = 26 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_DUNSPARCE] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 28 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GLIGAR] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_STEELIX] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SNUBBULL] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GRANBULL] = {
#if ENGLISH
        { .songLengthId =  2 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_QWILFISH] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SCIZOR] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 50 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SHUCKLE] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 38 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_HERACROSS] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 42 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SNEASEL] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 38 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_TEDDIURSA] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 12 },
        { .songLengthId = 48 },
        { .songLengthId = 44 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 39 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_URSARING] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 44 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SLUGMA] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MAGCARGO] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 27 },
        { .songLengthId = 24 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SWINUB] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_PILOSWINE] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 26 },
        { .songLengthId = 18 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CORSOLA] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        { .songLengthId = 42 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_REMORAID] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId =  3 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OCTILLERY] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 17 },
        { .songLengthId = 48 },
        { .songLengthId = 12 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_DELIBIRD] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 12 },
        { .songLengthId = 48 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MANTINE] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SKARMORY] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 26 },
        { .songLengthId = 12 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_HOUNDOUR] = {
#if ENGLISH
        { .songLengthId = 35 },
        { .songLengthId = 26 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_HOUNDOOM] = {
#if ENGLISH
        { .songLengthId = 33 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_KINGDRA] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_PHANPY] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_DONPHAN] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_PORYGON2] = {
#if ENGLISH
        { .songLengthId = 26 },
        { .songLengthId = 12 },
        { .songLengthId = 27 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
    },
    [SPECIES_STANTLER] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SMEARGLE] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 38 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_TYROGUE] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_HITMONTOP] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 21 },
        { .songLengthId = 29 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SMOOCHUM] = {
#if ENGLISH
        { .songLengthId = 39 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ELEKID] = {
#if ENGLISH
        { .songLengthId = 11 },
        { .songLengthId = 11 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MAGBY] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MILTANK] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId =  3 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_BLISSEY] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 14 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
    },
    [SPECIES_RAIKOU] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 39 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ENTEI] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId =  3 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SUICUNE] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_LARVITAR] = {
#if ENGLISH
        { .songLengthId = 21 },
        { .songLengthId = 17 },
        { .songLengthId = 21 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_PUPITAR] = {
#if ENGLISH
        { .songLengthId = 39 },
        { .songLengthId = 17 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_TYRANITAR] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId =  0 },
        { .songLengthId = 17 },
        { .songLengthId = 27 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_LUGIA] = {
#if ENGLISH
        { .songLengthId = 39 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_HO_OH] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CELEBI] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 12 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_B] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_C] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_D] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_E] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_F] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_G] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_H] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_I] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_J] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_K] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_L] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_M] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_N] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_O] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_P] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_Q] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_R] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_S] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_T] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_U] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_V] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_W] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_X] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_Y] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_OLD_UNOWN_Z] = {
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_TREECKO] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GROVYLE] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 18 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SCEPTILE] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 18 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_TORCHIC] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_COMBUSKEN] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 44 },
        { .songLengthId = 15 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_BLAZIKEN] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 17 },
        { .songLengthId = 15 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MUDKIP] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MARSHTOMP] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 29 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SWAMPERT] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_POOCHYENA] = {
#if ENGLISH
        { .songLengthId = 39 },
        { .songLengthId = 12 },
        { .songLengthId = 9 },
        { .songLengthId = 44 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MIGHTYENA] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 12 },
        { .songLengthId = 9 },
        { .songLengthId = 44 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ZIGZAGOON] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId =  0 },
        { .songLengthId = 39 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_LINOONE] = {
#if ENGLISH
        { .songLengthId = 20 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_WURMPLE] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 36 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SILCOON] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 40 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_BEAUTIFLY] = {
#if ENGLISH
        { .songLengthId = 45 },
        { .songLengthId = 9 },
        { .songLengthId = 18 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CASCOON] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_DUSTOX] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 23 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_LOTAD] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_LOMBRE] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId =  3 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_LUDICOLO] = {
#if ENGLISH
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 26 },
        { .songLengthId = 26 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SEEDOT] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_NUZLEAF] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 14 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SHIFTRY] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_NINCADA] = {
#if ENGLISH
        { .songLengthId = 15 },
        { .songLengthId = 6 },
        { .songLengthId = 6 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_NINJASK] = {
#if ENGLISH
        { .songLengthId = 15 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SHEDINJA] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 42 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_TAILLOW] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 26 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SWELLOW] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SHROOMISH] = {
#if ENGLISH
        { .songLengthId = 39 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_BRELOOM] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SPINDA] = {
#if ENGLISH
        { .songLengthId = 15 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_WINGULL] = {
#if ENGLISH
        { .songLengthId = 15 },
        { .songLengthId = 36 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_PELIPPER] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 12 },
        { .songLengthId = 48 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SURSKIT] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MASQUERAIN] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 48 },
        { .songLengthId =  3 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_WAILMER] = {
#if ENGLISH
        { .songLengthId = 5 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_WAILORD] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 26 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SKITTY] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_DELCATTY] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId =  0 },
        { .songLengthId = 12 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_KECLEON] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 12 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_BALTOY] = {
#if ENGLISH
        { .songLengthId =  1 },
        { .songLengthId = 30 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CLAYDOL] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_NOSEPASS] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_TORKOAL] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 26 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SABLEYE] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 11 },
        { .songLengthId = 18 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_BARBOACH] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_WHISCASH] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_LUVDISC] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        { .songLengthId = 39 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CORPHISH] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CRAWDAUNT] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_FEEBAS] = {
#if ENGLISH
        { .songLengthId = 14 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MILOTIC] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 24 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CARVANHA] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId =  1 },
        { .songLengthId = 42 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SHARPEDO] = {
#if ENGLISH
        { .songLengthId = 29 },
        { .songLengthId = 12 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_TRAPINCH] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 15 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_VIBRAVA] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 27 },
        { .songLengthId = 42 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_FLYGON] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MAKUHITA] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 39 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_HARIYAMA] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 12 },
        { .songLengthId = 27 },
        { .songLengthId = 42 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ELECTRIKE] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 9 },
        { .songLengthId = 18 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MANECTRIC] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 9 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_NUMEL] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 11 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 39 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CAMERUPT] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 48 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SPHEAL] = {
#if ENGLISH
        { .songLengthId = 14 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SEALEO] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 12 },
        { .songLengthId = 24 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_WALREIN] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId =  3 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CACNEA] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CACTURNE] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 39 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SNORUNT] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 44 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GLALIE] = {
#if ENGLISH
        { .songLengthId = 5 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_LUNATONE] = {
#if ENGLISH
        { .songLengthId = 39 },
        { .songLengthId = 44 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SOLROCK] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_AZURILL] = {
#if ENGLISH
        { .songLengthId = 6 },
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SPOINK] = {
#if ENGLISH
        { .songLengthId = 30 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GRUMPIG] = {
#if ENGLISH
        { .songLengthId = 44 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_PLUSLE] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 36 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MINUN] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MAWILE] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 18 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MEDITITE] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 17 },
        { .songLengthId = 18 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_MEDICHAM] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 17 },
        { .songLengthId =  0 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SWABLU] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ALTARIA] = {
#if ENGLISH
        { .songLengthId = 6 },
        { .songLengthId = 27 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_WYNAUT] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_DUSKULL] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 38 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_DUSCLOPS] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ROSELIA] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SLAKOTH] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_VIGOROTH] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 48 },
        { .songLengthId = 27 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SLAKING] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GULPIN] = {
#if ENGLISH
        { .songLengthId = 36 },
        { .songLengthId = 15 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SWALOT] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_TROPIUS] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_WHISMUR] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 48 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_LOUDRED] = {
#if ENGLISH
        { .songLengthId = 33 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_EXPLOUD] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 33 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CLAMPERL] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 50 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_HUNTAIL] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 5 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GOREBYSS] = {
#if ENGLISH
        { .songLengthId = 26 },
        { .songLengthId = 44 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ABSOL] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SHUPPET] = {
#if ENGLISH
        { .songLengthId = 42 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_BANETTE] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SEVIPER] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 18 },
        { .songLengthId = 48 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ZANGOOSE] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 39 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_RELICANTH] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 17 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ARON] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 29 },
        { .songLengthId = 51 },
        NULL_BARD_SOUND,
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_LAIRON] = {
#if ENGLISH
        { .songLengthId = 5 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_AGGRON] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CASTFORM] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 26 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_VOLBEAT] = {
#if ENGLISH
        { .songLengthId = 24 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 9 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ILLUMISE] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 39 },
        { .songLengthId = 12 },
        { .songLengthId =  3 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 39 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_LILEEP] = {
#if ENGLISH
        { .songLengthId = 17 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CRADILY] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId = 17 },
        { .songLengthId = 12 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ANORITH] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 24 },
        { .songLengthId = 17 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_ARMALDO] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 27 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_RALTS] = {
#if ENGLISH
        { .songLengthId =  7 },
        { .songLengthId = 51 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_KIRLIA] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 12 },
        { .songLengthId = 42 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GARDEVOIR] = {
#if ENGLISH
        { .songLengthId = 27 },
        { .songLengthId = 9 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_BAGON] = {
#if ENGLISH
        { .songLengthId = 5 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 39 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SHELGON] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_SALAMENCE] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId =  0 },
        { .songLengthId = 9 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 39 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_BELDUM] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_METANG] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_METAGROSS] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 42 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 0 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_REGIROCK] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 12 },
        { .songLengthId = 27 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_REGICE] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 12 },
        { .songLengthId = 18 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_REGISTEEL] = {
#if ENGLISH
        { .songLengthId = 9 },
        { .songLengthId = 12 },
        { .songLengthId = 14 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 15 },
        { .songLengthId = 9 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_KYOGRE] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 24 },
        { .songLengthId = 48 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        { .songLengthId = 9 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_GROUDON] = {
#if ENGLISH
        { .songLengthId = 33 },
        { .songLengthId = 27 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 24 },
        { .songLengthId = 39 },
        { .songLengthId = 24 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_RAYQUAZA] = {
#if ENGLISH
        { .songLengthId =  3 },
        { .songLengthId =  3 },
        { .songLengthId = 42 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 0 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_LATIAS] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 12 },
        { .songLengthId =  0 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_LATIOS] = {
#if ENGLISH
        { .songLengthId =  0 },
        { .songLengthId = 12 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 24 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_JIRACHI] = {
#if ENGLISH
        { .songLengthId = 48 },
        { .songLengthId = 27 },
        { .songLengthId = 12 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_DEOXYS] = {
#if ENGLISH
        { .songLengthId = 12 },
        { .songLengthId = 27 },
        { .songLengthId = 17 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 15 },
        NULL_BARD_SOUND,
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    },
    [SPECIES_CHIMECHO] = {
#if ENGLISH
        { .songLengthId = 18 },
        { .songLengthId = 9 },
        { .songLengthId = 24 },
        { .songLengthId = 51 },
#elif GERMAN
        { .songLengthId = 0 },
        { .songLengthId = 15 },
        { .songLengthId = 0 },
        { .songLengthId = 15 },
#endif
        NULL_BARD_SOUND,
        NULL_BARD_SOUND,
    }
};

#endif //GUARD_DATA_BARD_MUSIC_POKEMON_H
