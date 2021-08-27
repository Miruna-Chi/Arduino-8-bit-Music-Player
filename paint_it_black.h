#include "note_lib.h"

short paint_it_black_divider = 2000; // 2s
short paint_it_black_distinguisher = 0.5;

short paint_it_black_melody[] = {
    NOTE_F4, NOTE_G4, NOTE_GS4,
    NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_F4,
    NOTE_F4, NOTE_E4, NOTE_F4, NOTE_G4,
    NOTE_F4, NOTE_E4, 0,

    0, NOTE_F4, NOTE_G4, NOTE_GS4,
    NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_G4, NOTE_F4,
    NOTE_F4, NOTE_E4, NOTE_F4, NOTE_G4,
    NOTE_F4, NOTE_E4, 0,

    0, NOTE_F5, NOTE_DS5, NOTE_DS5,
    NOTE_GS4, NOTE_GS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_C5,
    NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_C5,
    NOTE_C5, 0,

    0, NOTE_F5, NOTE_DS5, NOTE_DS5,
    NOTE_GS4, NOTE_GS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_C5,
    NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_C5,
    NOTE_C5, 0

};

short paint_it_black_tempo[] = {
    4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4,
    8, 4, 2,

    4, 4, 8, 3,
    8, 4, 8, 4, 4,
    4, 4, 4, 4,
    8, 4, 2,

    4, 4, 4, 4,
    4, 8, 8, 8, 4, 4,
    3, 4, 8, 8,
    2, 2,

    4, 4, 4, 4,
    4, 8, 8, 8, 4, 4,
    3, 8, 8, 8, 8,
    2, 2


};