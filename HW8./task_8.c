#include <stdio.h>

void reverse_half(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int arr[12];
    
    for (int i = 0; i < 12; i++) {
        scanf("%d", &arr[i]);
    }
    
    reverse_half(arr, 0, 3);
    reverse_half(arr, 4, 7);
    reverse_half(arr, 8, 11);
    
    for (int i = 0; i < 12; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
