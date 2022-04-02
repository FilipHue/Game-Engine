#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "bigint.h"

const bint BIG_INT_ZERO = {true, 0, 0, NULL};


bint*
createBigInt(unsigned int capacity) {
    bint *new_bint;

    new_bint = malloc(sizeof(bint));
    new_bint->capacity = capacity;
    new_bint->noDigits = 0;
    new_bint->sign = true;
    new_bint->digits = malloc(capacity * sizeof(char));

    return new_bint;
}


bint*
createNewBigInt(int i) {
    bool sign;

    sign = true;
    if (i < 0) {
        sign = false;
        i *= -1;
    }

    bint *new_bint = createNewPositiveBint(i);
    new_bint->sign = sign;
    return new_bint;
}


bint*
createNewPositiveBint(unsigned int number) {
    int aux;
    int noDigits;

    aux = number;
    noDigits = 0;
    while (aux) {
        noDigits++;
        aux /= 10;
    }
    if (number == 0) {
        noDigits++;
    }

    bint *new_bint;

    new_bint = createBigInt(noDigits);
    new_bint->noDigits = noDigits;
    for (unsigned int i = 0; i < (unsigned int)noDigits; i++, number/=10) {
        new_bint->digits[i] = number % 10;
    }

    return new_bint;
}


bint*
stringToBint(char *string) {
    unsigned int length, noDIgits;
    bool sign;

    length = strlen(string);
    noDIgits = length;
    sign = true;
    if (string[0] == '-') {
        sign = false;
        noDIgits--;
    }
    if (noDIgits == 0) {
        return NULL;
    }

    bint *new_bint;

    new_bint = createBigInt(noDIgits);
    new_bint->noDigits = noDIgits;
    new_bint->sign = sign;
    for (unsigned int i = 0; i < noDIgits; i++) {
        char c = string[length - i - 1];
        if (c >= '0' && c <= '9') {
            new_bint->digits[i] = c - '0';
        } else {
            return NULL;
        }
    }

    return new_bint;
}


char*
bintToString(bint *number) {
    if (!number->noDigits) {
        return "0";
    }

    unsigned int noChars = number->noDigits;

    char *new_string_number;

    new_string_number = malloc((noChars + 1) * sizeof(char));
    if (!new_string_number) {
        return NULL;
    }
    unsigned int strIdx;

    strIdx = 0;
    
    if (!number->sign) {
        noChars++;
        new_string_number[strIdx] = '-';
        strIdx++;
    }

    for (unsigned int i = number->noDigits; i > 0; i--, strIdx++) {
        new_string_number[strIdx] = number->digits[i - 1] + '0';
    }

    new_string_number[noChars] = '\0';
    return new_string_number;
}


char
compareBints(bint *number1, bint *number2) {
    if (number1->sign && !number2->sign) {
        return 1;
    }
    if (!number1->sign && number2->sign) {
        return -1;
    }
    if (number1->noDigits != number2->noDigits) {
        return (number1->noDigits > number2->noDigits) ? 1 : -1;
    }
    unsigned int index;

    index = 0;
    if (!number1->sign && !number2->sign) {
        index++;
    }
    for(; index < number1->noDigits; index++) {
        if (number1->digits[index] != number2->digits[index]) {
            return (number1->digits[index] > number2->digits[index]) ? 1 : -1;
        }
    }
    return 0;
}


void
destroyBint(bint **number) {
    free((*number)->digits);
    free(*number);
    *number = NULL;
}
