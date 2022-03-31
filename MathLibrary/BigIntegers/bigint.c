#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "bigint.h"


bint*
createBigInt(unsigned int capacity) {
    bint *new_bint;

    new_bint = malloc(sizeof(bint));
    new_bint->capacity = capacity;
    new_bint->size = 0;
    new_bint->sign = true;
    new_bint->digits = malloc(sizeof(capacity * sizeof(char)));

    return new_bint;
}

bint*
stringToBint(char *string) {
    unsigned int length, noDIgits;
    bool sign;

    length = strlen(string);
    noDIgits = length;
    sign = true;
    if (string[0] == "-") {
        sign = false;
        noDIgits--;
    }

    bint *new_bint;

    new_bint = createBigInt(noDIgits);
    new_bint->size = noDIgits;
    new_bint->sign = sign;
    for (unsigned int i = 0; i < noDIgits; i++) {
        char c = string[i];
    }

}
