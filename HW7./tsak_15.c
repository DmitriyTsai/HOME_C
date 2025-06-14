#include <stdio.h>

int max_find(int current_max) {
    int num;
    scanf("%d", &num);
    
    if (num == 0) {
        return current_max;
    }
    
    if (num > current_max) {
        current_max = num;
    }
    
    return max_find(current_max);
}

int main() {
    int first_num;
    scanf("%d", &first_num);
    
    if (first_num == 0) {
        return 0;
    }
    
    int max = max_find(first_num);
    printf("%d\n", max);
    
    return 0;
}
