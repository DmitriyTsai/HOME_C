#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int counts[10] = {0};
    
    for (int i = 2; i <= 9; i++) {
        counts[i] = (N / i) - (1 / i);
    }
    
    printf("2 %d\n", counts[2]);
    printf("3 %d\n", counts[3]);
    printf("4 %d\n", counts[4]);
    printf("5 %d\n", counts[5]);
    printf("6 %d\n", counts[6]);
    printf("7 %d\n", counts[7]);
    printf("8 %d\n", counts[8]);
    printf("9 %d\n", counts[9]);
    
    return 0;
}
