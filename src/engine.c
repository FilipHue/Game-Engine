#include <stdio.h>

#include "mathlibrary.h"

int main() {
    bint *b1 = stringToBint("121");
    bint *b2 = stringToBint("-1121");
    bint *b3 = addBint(b1, b2);
    char *res = bintToString(b3);
    printf("%s\n", res);
    destroyBint(&b1);
    destroyBint(&b2);
    destroyBint(&b3);
    free(res);
    return 0;
}
