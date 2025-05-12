#include <stdio.h>

int main() {
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    
    int min = a, max = a;
    
    if (b < min) min = b; else if (b > max) max = b;
    if (c < min) min = c; else if (c > max) max = c;
    if (d < min) min = d; else if (d > max) max = d;
    if (e < min) min = e; else if (e > max) max = e;
    
    printf("%d\n", min + max);
    return 0;
}
