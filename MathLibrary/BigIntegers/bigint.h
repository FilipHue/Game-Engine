#ifndef _BIGINT_H
#define _BIGINT_H


#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../../src/constants.h"

typedef struct bint bint;
struct bint
{
    bool sign;
    unsigned int capacity;
    unsigned int size;
    char *digits;
};

bint*
createBigInt(unsigned int capacity);

bint*
stringToBint(char *string);

#endif  //  _BIGINT_