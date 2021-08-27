#include "bury_a_friend.h"
#include "paint_it_black.h"
#include "skyrim.h"
#include <LiquidCrystal.h>
#include "buttons.h"

//Initialise the LCD with the arduino. LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
// 12 - 8
// 11 - 9
// 5 4 3 2 - 10, 11, 12, 13
#define buzzerPin 2

#define prevButton 3
#define playpauseButton 4
#define nextButton 5
#define repeatButton 6
#define shuffleButton 7

char all = 2;
char one = 1;
char none = 0;

bool play = true;
bool prev = false;
bool next = false;
bool shuffle = false;
char repeat = all; // 0 - none, 1 - one, 2 - all

short n = 3;
short song = -1;

short history[] = {-1, -1, -1};
short history_index = -1;

void setup(void)
{
    //start serial connection
    Serial.begin(9600);
    pinMode(buzzerPin, OUTPUT); // buzzer

    pinMode(prevButton, INPUT_PULLUP);
    pinMode(playpauseButton, INPUT_PULLUP);
    pinMode(nextButton, INPUT_PULLUP);
    pinMode(repeatButton, INPUT_PULLUP);
    pinMode(shuffleButton, INPUT_PULLUP);

    // Switch on the LCD screen
    lcd.begin(16, 2);

    // Create button icons
    lcd.createChar(0, play1);
    lcd.createChar(1, pause);
    lcd.createChar(2, shuffle1);
    lcd.createChar(3, shuffle2);
    lcd.createChar(4, repeat1);
    lcd.createChar(5, repeat_all);
    lcd.createChar(6, repeat_one);

}
void loop()
{
    //play the tunes
    delay(1000);

    checkButtons();
    while (!play) { // pause
        checkButtons();
    }
    
    if (play == true) { 
        if (shuffle == false) {
            if (repeat == all) {
                if (next == true) {
                    if (song + 1 == n)
                        song = 0;
                    else song++;
                    next = false;
                }
                else if (prev == true) {
                    if (song - 1 < 0)
                        song = n - 1;
                    else song--;
                    prev = false;
                }
            }
            else if (repeat == none) {
                if (next == true) {
                    if (song + 1 == n) {
                        song = -1;
                        play = false;
                        next = false;
                        return;
                    }
                    song++;
                }
                else if (prev == true) {
                    if (song - 1 < 0) {
                        song = n - 1;
                    }
                    else song--;
                    prev = false;
                }
            }
            else if (repeat == one) {
                if (next == true) {
                    next = false;
                }
                else if (prev == true) {
                    if (song - 1 < 0) {
                        song = n - 1;
                    }
                    else song--;
                    prev = false;
                }
                if (history_index > -1)
                    history_index--;
            }

            if (history_index < n - 1) {
                history_index++;
            }
            else history_index = 0;
            
            history[history_index] = song;
            play_music(song);
        }
        else { // shuffle
            if (repeat == all) {
                if (next == true) {
                    song = random(0, n);
                    if (history_index < n - 1) {
                        history_index++;
                    }
                    else history_index = 0;
                    
                    history[history_index] = song;
                    next = false;
                }
                else if (prev == true) {
                    if (history_index > 0)
                        song = history[--history_index];
                    else if (history_index == 0) {
                        song = history[history_index];
                    } else {
                        song = random(0, n);
                        history[++history_index] = song;
                    }
                    prev = false;
                }
                play_music(song);
            }
            else if (repeat == none) {
                if (next == true) {
                    if (history_index < n - 1) {
                        history_index++;
                    }
                    else {
                        history_index = -1;
                        play = false;
                        next = false;
                        return;
                    }
                    song = random(0, n);
                    history[++history_index] = song;
                }
                else if (prev == true) {
                    if (history_index > 0)
                        song = history[--history_index];
                    else if (history_index == 0) {
                        song = history[history_index];
                    } else {
                        song = random(0, n);
                        history[++history_index] = song;
                    }
                }
                play_music(song);
            }
            else if (repeat == one) {
                if (next == true) {
                    if (song == -1) {
                        song = random(0, n - 1);
                        history[++history_index] = song;
                    }
                    next = false;
                }
                else if (prev == true) {
                    if (history_index > 0)
                        song = history[--history_index];
                    else if (history_index == 0) {
                        song = history[history_index];
                    } else {
                        song = random(0, n);
                        history[++history_index] = song;
                    }
                    prev = false;
                }
                play_music(song);
            }
        }
    }
}

void checkButtons() {
    int playVal = digitalRead(playpauseButton);
    int nextVal = digitalRead(nextButton);
    int prevVal = digitalRead(prevButton);
    int shuffleVal = digitalRead(shuffleButton);
    int repeatVal = digitalRead(repeatButton);

    if (playVal == LOW) {
        if (play) 
            play = false;
        else play = true;
        while (digitalRead(playpauseButton) == LOW) {}
    }

    if (nextVal == LOW) {
        next = true;
        play = true;
        while (digitalRead(nextButton) == LOW) {}
    }

    if (prevVal == LOW) {
        next = false;
        prev = true;
        play = true;
        while (digitalRead(prevButton) == LOW) {}
    }

    if (shuffleVal == LOW) {
        if (shuffle == false)
            shuffle = true;
        else shuffle = false;
        while (digitalRead(shuffleButton) == LOW) {}
    }

    if (repeatVal == LOW) {
        if (repeat == none)
            repeat = one;
        else if (repeat == one)
            repeat = all;
        else if (repeat == all)
            repeat = none;
        while (digitalRead(repeatButton) == LOW) {}
    }
    
}

void printToLCD(char *song, int strStart) {
    

    if (play) {
        lcd.setCursor(0, 0);
        lcd.write(byte(0));
    }
    else {
        lcd.setCursor(0, 0);
        lcd.write(byte(1));
    }

    if(shuffle) {
        lcd.setCursor(7, 0);
        lcd.write(byte(2));
        lcd.setCursor(8, 0);
        lcd.write(byte(3));
    }
    else {
        lcd.setCursor(7, 0);
        lcd.print(" ");
        lcd.setCursor(8, 0);
        lcd.print(" ");
    }

    if(repeat) {
        lcd.setCursor(14, 0);
        lcd.write(byte(4));
        lcd.setCursor(15, 0);
        if (repeat == one)
            lcd.write(byte(6));
        else lcd.write(byte(5));
    }
    else {
        lcd.setCursor(14, 0);
        lcd.print(" ");
        lcd.setCursor(15, 0);
        lcd.print(" ");
    }

    lcd.setCursor(0, 1);
    lcd.print(song + strStart);
}

void play_music(int s) {
    next = false;
    prev = false;

    // iterate over the notes of the melody:
    if (s == 0) {
            
        lcd.setCursor(0, 0);
        // Print these words to my LCD screen
        //String strDisplay;
        char strProcess[] = "   bury a friend - Billie Eilish   ";
        short strStart = 0;
        //strDisplay = strProcess.substring(strStart, strStart + 16);
        
        Serial.println(strProcess);

        short size = sizeof(bury_a_friend_melody1) / sizeof(short);
        for (short note = 0; note < size; note++) {

            printToLCD(strProcess, strStart);
            
            if (note % 3 == 0)
                strStart++;
           
            if (strStart > strlen(strProcess) - 15) {
                strStart = 0;
            }

            checkButtons();
            while (!play) { // pause
                checkButtons();
                delay(250);
                printToLCD(strProcess, strStart);
                if (prev || next)
                    return;
            }
            if (prev || next)
                    return;
    
            /* 
                * To calculate the note duration, take one second
                * divided by the note type.
                * e.g. quarter_note = 1000 / 4, eighth_note = 1000/8, etc.
                */
            int noteDuration = bury_a_friend_divider / bury_a_friend_tempo1[note];
            buzz(buzzerPin, bury_a_friend_melody1[note], noteDuration);
    
            /* 
                *  To distinguish the notes, set a minimum time between them.
                *  The note's duration * specific_percentage:
                */
            int pauseBetweenNotes = noteDuration * bury_a_friend_distinguisher;
            delay(pauseBetweenNotes);
    
            // stop the tone playing:
            //buzz(buzzerPin, 0, noteDuration / 100);
  
        }
  
        size = sizeof(bury_a_friend_melody4) / sizeof(short);
        for (short note = 0; note < size; note++) {
            printToLCD(strProcess, strStart);
            if (note % 3 == 0)
                strStart++;
           
            if (strStart > strlen(strProcess) - 15) {
                strStart = 0;
            }
          
            checkButtons();
            while (!play) { // pause
                checkButtons();
                printToLCD(strProcess, strStart);
                if (prev || next)
                    return;
            }
            if (prev || next)
                return;
            
            int noteDuration = bury_a_friend_divider / bury_a_friend_tempo4[note];
            buzz(buzzerPin, bury_a_friend_melody4[note], noteDuration);
    
            int pauseBetweenNotes = noteDuration * bury_a_friend_distinguisher;
            delay(pauseBetweenNotes);
            
            //buzz(buzzerPin, 0, noteDuration / 100);
        }

        size = sizeof(bury_a_friend_melody1) / sizeof(short);
        for (short note = 0; note < size; note++) {
          
            printToLCD(strProcess, strStart);
            if (note % 3 == 0)
                strStart++;
           
            if (strStart > strlen(strProcess) - 15) {
                strStart = 0;
            }

            checkButtons();
            while (!play) { // pause
                checkButtons();
                printToLCD(strProcess, strStart);
                if (prev || next)
                    return;
            }
            if (prev || next)
                return;
            
            int noteDuration = bury_a_friend_divider / bury_a_friend_tempo1[note];
            buzz(buzzerPin, bury_a_friend_melody1[note], noteDuration);
    
            int pauseBetweenNotes = noteDuration * bury_a_friend_distinguisher;
            delay(pauseBetweenNotes);
    
            //buzz(buzzerPin, 0, noteDuration / 100);
        }
        // end of song
        delay(3000);
    } else if (s == 1){
      
        char strProcess[] = "   Paint It Black - The Rolling Stones";
        short strStart = 0;
        short size = sizeof(paint_it_black_melody) / sizeof(short);
        for (short note = 0; note < size; note++) {
            printToLCD(strProcess, strStart);
            if (note % 3 == 0)
                strStart++;
           
            if (strStart > strlen(strProcess) - 15) {
                strStart = 0;
            }

            checkButtons();
            while (!play) { // pause
                checkButtons();
                printToLCD(strProcess, strStart);
                if (prev || next)
                    return;
            }
            if (prev || next)
                return;
            
            int noteDuration = paint_it_black_divider / paint_it_black_tempo[note];
            buzz(buzzerPin, paint_it_black_melody[note], noteDuration);
            
            int pauseBetweenNotes = noteDuration * paint_it_black_distinguisher;
            delay(pauseBetweenNotes);

            //buzz(buzzerPin, 0, noteDuration / 100);
        }
        delay(2000);
    } else if (s == 2) {
        char strProcess[] = "   Skyrim Theme Song    ";
        short strStart = 0;
        short size = sizeof(skyrim_melody) / sizeof(short);
        for (short note = 0; note < size; note++) {
            printToLCD(strProcess, strStart);
            if (note % 3 == 0)
                strStart++;
           
            if (strStart > strlen(strProcess) - 15) {
                strStart = 0;
            }

            checkButtons();
            while (!play) { // pause
                checkButtons();

                printToLCD(strProcess, strStart);

                if (prev || next)
                    return;
            }
            if (prev || next)
                return;

            int noteDuration = skyrim_divider / skyrim_tempo[note];
            buzz(buzzerPin, skyrim_melody[note], noteDuration);

            /* 
            *  To distinguish the notes, set a minimum time between them.
            *  The note's duration * specific_percentage:
            */
            int pauseBetweenNotes = noteDuration * skyrim_distinguisher;
            delay(pauseBetweenNotes);

            // stop the tone playing:
            //buzz(buzzerPin, 0, noteDuration / 100);
        }
        delay(2000);
    }

    next = true;
}

void buzz(int targetPin, long frequency, long length) {

    /*
    * Calculate the delay value between transitions.
    * 1 second's worth of microseconds, divided by the frequency, then split in half since
    * there are two phases to each cycle.
    */ 
    long delayValue = 1000000 / frequency / 2;

    /*
    * Calculate the number of cycles for proper timing.
    * Multiply frequency, which is really cycles per second, by the number of seconds to
    * get the total number of cycles to produce.
    */
    long numCycles = frequency * length / 1000;

    // If it's a pause:
    if (frequency == 0) {
        delayValue = 1000000;
        numCycles = length;
        
        for (long i = 0; i < numCycles; i++) {
            // wait again for the calculated delay value
            delayMicroseconds(delayValue);
        }
    } else { // It's a note

        // for the calculated length of time...
        for (long i = 0; i < numCycles; i++) {
        
            // write the buzzer pin high to push out the diaphram
            digitalWrite(targetPin, HIGH);
            // wait for the calculated delay value
            delayMicroseconds(delayValue);
            // write the buzzer pin low to pull prev the diaphram
            digitalWrite(targetPin, LOW);
            // wait again for the calculated delay value
            delayMicroseconds(delayValue);
        
        }
    }
}
