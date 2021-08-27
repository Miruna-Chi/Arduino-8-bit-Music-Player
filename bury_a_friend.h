#include "note_lib.h"

short bury_a_friend_divider = 2000; // 2s
short bury_a_friend_distinguisher = 0.5;

// order: 1, 3, 2, 1, 4, 2, 1

short bury_a_friend_melody1[] = {

    NOTE_D5, NOTE_DS5, NOTE_D5, NOTE_C5,
    NOTE_AS4, NOTE_G4, NOTE_C5, NOTE_D5,
    NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4,
    NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4,
    NOTE_G4, NOTE_FS4, NOTE_A4, NOTE_AS4,
    NOTE_A4, NOTE_G4, 0,

    NOTE_D5, NOTE_DS5, NOTE_D5, NOTE_C5,
    NOTE_AS4, NOTE_G4, NOTE_C5, NOTE_D5,
    NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4,
    NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4,
    NOTE_G4, NOTE_FS4, NOTE_A4, NOTE_AS4,
    NOTE_A4, NOTE_G4, 0
};

short bury_a_friend_tempo1[] = {

    8, 8, 8, 4,
    8, 4, 8, 8,
    8, 4, 8, 4,
    8, 8, 8, 4,
    8, 4, 8, 8,
    8, 8, 2,

    8, 8, 8, 4,
    8, 4, 8, 8,
    8, 4, 8, 4,
    8, 8, 8, 4,
    8, 4, 8, 8,
    8, 8, 2
};

short bury_a_friend_melody2[] = {

    0, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4, 0,
    NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_D5, NOTE_G4,
    0, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4, 0,
    NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_D5,
    0, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4, 0,
    NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_D5, NOTE_G4,
    0, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4, 0,
    0, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4,
    0,

    NOTE_D5, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_D5,
    0, NOTE_D5, NOTE_C5, NOTE_D5, 0, NOTE_D5, NOTE_C5, NOTE_D5,
    0, NOTE_D5, NOTE_C5, NOTE_D5, 0, NOTE_DS5, NOTE_D5,
    0, NOTE_D5, NOTE_C5, NOTE_D5, 0, NOTE_D5, NOTE_C5, NOTE_D5,
    0, NOTE_D5, NOTE_C5, NOTE_D5
};

short bury_a_friend_tempo2[] = {
    4, 8, 8, 8, 4, 4,
    8, 8, 8, 4, 4, 4,
    4, 8, 8, 8, 4, 4,
    8, 8, 8, 4, 4, 4,
    4, 8, 8, 8, 4, 4,
    8, 8, 8, 4, 4, 4,
    4, 8, 8, 8, 4, 4,
    2, 8, 8, 8, 8, 8,
    1,

    8, 8, 8, 8, 8,
    4, 8, 8, 8, 4, 8, 8, 8,
    4, 8, 8, 8, 4, 8, 8,
    4, 8, 8, 8, 4, 8, 8, 8,
    4, 8, 8, 8
};

short bury_a_friend_melody3[] = {

    0, NOTE_CS5, NOTE_C5, 0, NOTE_C5, NOTE_AS4, NOTE_C5, 0,
    0, 0, NOTE_AS4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4,
    0, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_C5, 0,
    NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4,
    0, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_C5, 0,
    0, 0, NOTE_AS4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4,
    0, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4,
    NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4
};

short bury_a_friend_tempo3[] = {

    4, 8, 8, 8, 8, 8, 8, 8,
    4, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8,
    4, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8
};

short bury_a_friend_melody4[] = {

    0, NOTE_CS5, NOTE_C5, 0, NOTE_C5, NOTE_AS4, NOTE_C5, 0,
    0, 0, NOTE_AS4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4,
    0, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_C5, 0,
    NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4,
    0, NOTE_C5, NOTE_D5, NOTE_C5, 0, NOTE_C5, NOTE_AS4, NOTE_C5, 0,
    0, 0, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4,

    0, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4,
    NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4,
    0, NOTE_G4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_G4,
    
    NOTE_D5, NOTE_D5, NOTE_D5, 0,
    0, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_G4,

    NOTE_D5, NOTE_D5, NOTE_D5, 0,
    0, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_G4,

    NOTE_D5, NOTE_D5, NOTE_D5, 0,
    0, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_G4,

    NOTE_D5, NOTE_D5, NOTE_D5, 0, 0, NOTE_D5,

    NOTE_G5, NOTE_D5, NOTE_G5, NOTE_D5, NOTE_D5,
    NOTE_DS5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5,
    NOTE_D5, NOTE_A4, NOTE_D5, NOTE_A4, NOTE_A4,
    NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_D5, NOTE_D5,
    NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_FS5, NOTE_G5,
    NOTE_A5, NOTE_G5, NOTE_DS5, NOTE_D5, NOTE_D5,
    NOTE_FS5, NOTE_D5, NOTE_D5, 0, NOTE_D5,
    NOTE_D5, NOTE_AS4, NOTE_G4, NOTE_G4, NOTE_G4
};

short bury_a_friend_tempo4[] = {
    4, 8, 8, 8, 8, 8, 8, 8,
    4, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8,
    4, 8, 8, 8, 8, 8, 8, 8, 8,

    8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,

    4, 4, 4, 2,
    4, 8, 8, 8, 8, 8, 8, 8, 8, 8,

    4, 4, 4, 2,
    4, 8, 8, 8, 8, 8, 8, 8, 8, 8,

    4, 4, 4, 2,
    4, 8, 8, 8, 8, 8, 8, 8, 8, 8,

    4, 4, 4, 2, 4, 4,

    4, 4, 4, 8, 8,
    4, 4, 4, 8, 8,
    4, 4, 4, 8, 8,
    4, 4, 4, 8, 8,
    4, 4, 4, 8, 8,
    4, 4, 4, 8, 8,
    4, 4, 4, 8, 8,
    4, 4, 4, 8, 8
};