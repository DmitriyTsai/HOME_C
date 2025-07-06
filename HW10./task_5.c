#include <stdio.h>
#include <string.h>

#define MAX_LEN 1001

int main() {

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    if (input == NULL || output == NULL) {
        return 1;
    }
    
    char str[MAX_LEN];
    if (fgets(str, MAX_LEN, input) == NULL) {
        return 1;
    }
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a') {
            str[i] = 'b';
        } else if (str[i] == 'b') {
            str[i] = 'a';
        } else if (str[i] == 'A') {
            str[i] = 'B';
        } else if (str[i] == 'B') {
            str[i] = 'A';
        }
    }
    
    fprintf(output, "%s", str);
    
    fclose(input);
    fclose(output);
    return 0;
}
