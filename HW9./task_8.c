#include <stdio.h>

int main() {
    int num;
    int min = 1001;
    int max = 0;
    int sum = 0;
//    int count = 0;
    
    while (1) {
        scanf("%d", &num);
        if (num == 0) break;
        
        if (num < min) min = num;
        if (num > max) max = num;
        sum += num;
//        count++;
    }
    
    //float expected_sum = (((float)count + 1) / 2) * (min + max); 
    int expected_sum = (min + max) * (max - min + 1) / 2;

    int missing = expected_sum - sum;

    printf("%d\n", missing);
    return 0;
}
