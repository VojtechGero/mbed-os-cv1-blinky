#include "mbed.h"
#include <string>

#define BLINKING_RATE     500ms
#define BLINKING_RATE_LONG 1000ms
#define BLINKING_RATE_SHORT 100ms
#define BLINKING_RATE_SPACE     1000ms

void blick_morse_code(DigitalOut led, string mess);