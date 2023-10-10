/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */


#include "mbed.h"
#include <string>
#include "morse.h"

string mess;
bool run;
DigitalOut led(LED1);

void init() {
    mess = "sos test";
    led = 0;
    run = true;
}

void exit() {
    led = 0;
}

int main()
{
    init();

    while (run) {
        blick_morse_code(led, mess);
    }

    exit();
}



