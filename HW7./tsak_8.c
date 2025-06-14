#include <stdio.h>

void print_sequence(int a, int b)
{ 
    if (a == b) {
        printf("%d ", a);
        return;
    }
    
    if (a < b) {
        printf("%d ", a);
        print_sequence(a + 1, b);
    }
    else {
        printf("%d ", a);
        print_sequence(a - 1, b);
    }
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    
    print_sequence(A, B);
    printf("\n");
    
    return 0;
}
