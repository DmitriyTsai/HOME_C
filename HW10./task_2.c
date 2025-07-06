#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    if (input == NULL || output == NULL) {
        return 1;
    }
    
    int N;
    if (fscanf(input, "%d", &N) != 1) {
        return 1;
    }
    
    if (N <= 0 || N > 26 || N % 2 != 0) {
        return 1;
    }
    
    char result[N + 1];
    int digit = 2;
    char letter = 'A';
    
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            result[i] = letter++;
        } else {
            result[i] = digit + '0';
            digit += 2;
            if (digit > 8) {
                digit = 2;
            }
        }
    }
    result[N] = '\0';
    
    fprintf(output, "%s", result);
    
    fclose(input);
    fclose(output);
    
    return 0;
}
