#include <stdio.h>

#include "./constants.h"
#include "./vector.h"
#include "./vector_funcs.h"


int main() {
    vector vec1 = vector(3.0f, 4.0f, 5.0f);
    printVector(vec1);

    vector vec2 = powerVector(vec1, 3.0f);
    printVector(vec2);

    printf("%d\n", isOrthogonal(vec1, vec2));

    vector vec3 = normalizeVector(vec1);
    printVector(vec3);

    vector vec4 = crossProduct(vec1, vec2);
    printVector(vec4);
    printf("%d\n", isOrthogonal(vec4, vec1));
    printf("%d\n", isOrthogonal(vec4, vec2));


    vector vec5 = vector(4.0f, 1.0f, 2.0f);
    vector vec6 = vector(1.0f, 0.0f, -2.0f);
    printf("%d\n", isOrthogonal(vec5, vec6));


    return 0;
}