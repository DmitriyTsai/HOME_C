#include <stdio.h>

void print_sequence(int k, int count, int remaining) {
    if (remaining == 0) {
        return;
    }
    
    if (count == 0) {
        print_sequence(k + 1 , k + 1, remaining);
    } else {
        printf("%d ", k);
        print_sequence(k, count - 1 , remaining - 1 );
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    print_sequence(1, 1, n);
    printf("\n");
    
    return 0;
}
