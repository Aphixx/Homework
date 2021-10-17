#include "utils.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>

size_t timer_from(unsigned char from) {
    size_t counter = 0;
    for (unsigned char i = from; ; --i) {
        ++counter;
        printf("%c", i);
    }
    return counter;
}

int custom_pow(int base, int power) {
    return pow(base, power);
}
