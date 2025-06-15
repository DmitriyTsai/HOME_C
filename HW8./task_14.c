#include <stdio.h>

int main() {
    int arr[10];
    int result[10];
    int result_size = 0;
    
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < 10; i++) {
        int already_added = 0;
        for (int k = 0; k < result_size; k++) {
            if (result[k] == arr[i]) {
                already_added = 1;
                break;
            }
        }
        if (already_added) continue;
        
        int count = 0;
        for (int j = 0; j < 10; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        
        if (count > 1) {
            result[result_size++] = arr[i];
        }
    }
    
    for (int i = 0; i < result_size; i++) {
        printf("%d ", result[i]);
    }
    
    return 0;
}
