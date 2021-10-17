#include "utils.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>

size_t timer_from(int from) {
    size_t counter = 0;
    for (int i = from; i >= 0; i--) {
        ++counter;
	if (i == 0) {
        	printf("%d", i);
	} else {
		printf("%d ", i);
	}
    }
    return counter;
}

int custom_pow(int base, int power) {
    return pow(base, power);
}
