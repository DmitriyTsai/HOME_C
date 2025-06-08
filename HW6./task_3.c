#include <stdio.h>

int middle(int a, int b) {
    int result = (a+b)/2;

    return result;
}

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    int res = middle(a, b);
    
    printf("%d\n", res);
    
    return 0;
}

