#include <stdio.h>
#include "func.h"

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("max(%d %d) = %d \n", a, b, max(a, b));
    printf("m = %d\n", m);
}
