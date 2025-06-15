#include <stdio.h>

int main() {
    int arr[12];
    int sum = 0;
    float average;

    for (int i = 0; i < 12; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    average = (float)sum / 12;

    printf("%.2f\n", average);

    return 0;
}
