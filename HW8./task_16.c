#include <stdio.h>

int main() {
    int arr[10];
    
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    
    int most_frequent = arr[0];
    int max_count = 1;
    
    for (int i = 0; i < 10; i++) {
        int current_count = 0;
        
        for (int j = 0; j < 10; j++) {
            if (arr[j] == arr[i]) {
                current_count++;
            }
        }
        
        if (current_count > max_count) {
            max_count = current_count;
            most_frequent = arr[i];
        }
        else if (current_count == max_count && arr[i] < most_frequent) {
            most_frequent = arr[i];
        }
    }
    
    printf("%d\n", most_frequent);
    
    return 0;
}
