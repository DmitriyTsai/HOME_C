#include <stdio.h>

void sort_even_odd(int n, int a[]) {
    int result[n];
    int even_index = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            result[even_index++] = a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            result[even_index++] = a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        a[i] = result[i];
    }
}
/*
int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    int a[n];
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }

    sort_even_odd(n, a);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
	 */
