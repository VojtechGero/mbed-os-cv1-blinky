#include "mbed.h"
#include <string>
#include "morse.h"


void blink(DigitalOut led, bool isShort) {
    led = !led;
    if (isShort)
    {
        ThisThread::sleep_for(BLINKING_RATE_SHORT);
    } else {
        ThisThread::sleep_for(BLINKING_RATE_LONG);
    }
    led = !led;
    ThisThread::sleep_for(BLINKING_RATE);
}


string morse_code(char letter) {
    switch(letter) {
        case 'a':    return ".-";        break;
        case 'b':    return "-...";      break;
        case 'c':    return  "-.-.";     break;
        case 'd':    return  "-..";      break;
        case 'e':    return  ".";        break;
        case 'f':    return  "..-.";     break;
        case 'g':    return  "--.";      break;
        case 'h':    return  "....";     break;
        case 'i':    return  "..";       break;
        case 'j':    return  ".---";     break;
        case 'k':    return  "-.-";      break;
        case 'l':    return  ".-..";     break;
        case 'm':    return  "--";       break;
        case 'n':    return  "-.";       break;
        case 'o':    return  "---";      break;
        case 'p':    return  "-.-.";     break;
        case 'q':    return  "--.-";     break;
        case 'r':    return  ".-.";      break;
        case 's':    return  "...";      break;
        case 't':    return  "-";        break;
        case 'u':    return  "..-";      break;
        case 'v':    return  "...-";     break;
        case 'w':    return  ".--";      break;
        case 'x':    return  "-..-";     break;
        case 'y':    return  "-.--";     break;
        case 'z':    return  "--..";     break;
        case ' ':    return  "";         break;
    }
    return "";
}

void blick_morse_code(DigitalOut led, string mess) {
    for (int i=0; i<mess.length();i++) {
        char letter = mess[i];
        string sequence = morse_code(letter);

        for (int j=0; j<sequence.length();j++) {
            if (sequence[j] == '.') {
                blink(led, true);
            } else {
                blink(led, false);
            }
        }

        ThisThread::sleep_for(BLINKING_RATE_SPACE);
    }
}
