#include "note_lib.h"

short skyrim_divider = 1250; // 1.25s
short skyrim_distinguisher = 0.5;

short skyrim_melody[] = {

    NOTE_B3, NOTE_E4, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E5, NOTE_B5, NOTE_CS6,

    NOTE_D5, NOTE_CS5,
    NOTE_D5, NOTE_D5, NOTE_CS5,
    NOTE_D5, NOTE_D5, NOTE_CS5,
    NOTE_E5, NOTE_D5, NOTE_CS5,
    NOTE_B4, NOTE_B4, NOTE_A4,
    NOTE_B4, NOTE_B4, NOTE_A4,
    NOTE_B4, NOTE_A4, NOTE_B4,
    NOTE_CS5, NOTE_D5, NOTE_A4,
    NOTE_B4, NOTE_B4, NOTE_CS5,
    NOTE_D5, NOTE_D5, NOTE_D5, NOTE_E5,

    NOTE_FS5, NOTE_CS5, NOTE_D5,
    NOTE_E5, NOTE_D5, NOTE_CS5,
    NOTE_B4, NOTE_B4, NOTE_A4,
    NOTE_B4, NOTE_B4, NOTE_A4,
    NOTE_B4, NOTE_A4, NOTE_B4,
    NOTE_CS5, NOTE_D5, NOTE_A4,
    NOTE_B4,

    NOTE_B4, NOTE_CS5,
    NOTE_D5, NOTE_D5, NOTE_E5,
    NOTE_FS5, NOTE_FS5, NOTE_A5,
    NOTE_E5, NOTE_D5, NOTE_CS5,
    NOTE_B4, NOTE_B4, NOTE_CS5,
    NOTE_D5, NOTE_D5, NOTE_E5,
    NOTE_FS5, NOTE_FS5, NOTE_A5,
    NOTE_B5, NOTE_A5, NOTE_CS6,
    NOTE_B5, NOTE_B4, NOTE_CS5,
    NOTE_D5, NOTE_CS5, NOTE_B4,
    NOTE_A4, NOTE_G4, NOTE_FS4,
    NOTE_E4, NOTE_D4, NOTE_FS4,
    NOTE_E4

};

short skyrim_tempo[] = {

    1, 1, 1, 1, 1, 1, 1, 1,

    8, 8,
    2, 8, 8,
    2, 8, 8,
    4, 4, 4,
    2, 8, 8,
    2, 8, 8,
    2, 8, 8,
    4, 4, 4,
    2, 8, 8,
    4, 4, 8, 8,

    2, 8, 8,
    4, 4, 4,
    2, 8, 8,
    2, 8, 8,
    2, 8, 8,
    4, 4, 4,
    1,

    4, 4,
    1, 4, 4,
    1, 4, 4,
    1, 4, 4,
    1, 4, 4,
    1, 4, 4,
    1, 4, 4,
    1, 4, 4,
    1, 4, 4,
    2, 2, 2,
    2, 2, 2,
    1, 4, 4,
    1
};