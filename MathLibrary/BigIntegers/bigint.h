#ifndef _BIGINT_H_
#define _BIGINT_H_


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
    unsigned int noDigits;
    char *digits;
};

extern const bint BIG_INT_ZERO;

/**
 * @brief Create a Big Int object
 * 
 * @param capacity 
 * @return bint* 
 */
bint*
createBigInt(unsigned int capacity);

/**
 * @brief 
 * 
 * @param string 
 * @return bint* 
 */
bint*
stringToBint(char *string);

/**
 * @brief Create a New Big Int object
 * 
 * @param i 
 * @return bint* 
 */
bint*
createNewBigInt(int i);

/**
 * @brief Create a New Positive Bint object
 * 
 * @param i 
 * @return bint* 
 */
bint*
createNewPositiveBint(unsigned int i);

/**
 * @brief 
 * 
 * @param number
 * @return char* 
 */
char*
bintToString(bint *number);

/**
 * @brief 
 * 
 * @param number1 
 * @param number2 
 * @return char 
 */
char
compareBints(bint *number1, bint *number2);

/**
 * @brief 
 * 
 * @param number 
 */
void
destroyBint(bint **number);

#endif  //  _BIGINT_H_
