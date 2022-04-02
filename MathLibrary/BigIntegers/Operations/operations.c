#include "../bigint.h"
#include "./operations.h"
#include "../../../src/utils.h"


bint*
addBint(bint *number1, bint *number2) {
    unsigned int maxNoDIgits;
    bint *new_bint;

    if (number1->sign && !number2->sign) {
        number2->sign = true;
        new_bint = substractBint(number1, number2);
        number2->sign = false;
        return new_bint;
    }
    if (!number1->sign && number2->sign) {
        number1->sign = true;
        new_bint = substractBint(number2, number1);
        number1->sign = true;
        return new_bint;
    }
    bool carryOver;
    
    maxNoDIgits = MAX(number1->noDigits, number2->noDigits) + 1;
    new_bint = createBigInt(maxNoDIgits);
    new_bint->noDigits = maxNoDIgits;
    carryOver = false;
    for (unsigned int i = 0; i < maxNoDIgits; i++) {
        char result;

        result = carryOver ? 1 : 0;
        if (i < number1->noDigits) {
            result += number1->digits[i];
        }
        if (i < number2->noDigits) {
            result += number2->digits[i];
        }
        if (result >= 10) {
            carryOver = true;
            result -= 10;
        } else {
            carryOver = false;
        }
        new_bint->digits[i] = result;
    }
    while (!new_bint->digits[new_bint->noDigits - 1]) {
        new_bint->noDigits--;
    }
    if (!number1->sign && !number2->sign) {
        new_bint->sign = false;
    }

    return new_bint;
}


bint*
substractBint(bint *number1, bint *number2) {
    unsigned int maxNoDigits;
    bint *new_bint;

    if (compareBints(number1, number2) == 0) {
        return createNewBigInt(0);
    }
    if (compareBints(number1, number2) < 0) {
        new_bint = substractBint(number2, number1);
        new_bint->sign = false;
        return new_bint;
    }
    if (number1->sign && !number2->sign) {
        number2->sign = true;
        new_bint = addBint(number1, number2);
        number2->sign = false;
        return new_bint;
    }
    if (!number1->sign && number2->sign) {
        number2->sign = false;
        new_bint = addBint(number1, number2);
        number2->sign = true;
        return new_bint;
    }
    if (!number1->sign && !number2->sign) {
        number1->sign = number2->sign = true;
        new_bint = substractBint(number1, number2);
        number1->sign = number2->sign = false;
        return new_bint;
    }
    bool carryOver = false;

    maxNoDigits = number1->noDigits;
    new_bint = createBigInt(maxNoDigits);
    new_bint->noDigits = maxNoDigits;
    for (unsigned int i = 0; i < maxNoDigits; i++) {
        char result;

        result = carryOver ? -1 : 0;
        if (i < number1->noDigits) {
            result += number1->digits[i];
        }
        if (i < number2->noDigits) {
            result -= number2->digits[i];
        }
        if (result < 0) {
            carryOver = true;
            result += 10;
        } else {
            carryOver = false;
        }
        new_bint->digits[i] = result;
    }
    while (!new_bint->digits[new_bint->noDigits - 1]) {
        new_bint->noDigits--;
    }

    return new_bint;
}