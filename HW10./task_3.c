#include <stdio.h>
#include <string.h>

int main() {

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    if (input == NULL || output == NULL) {
        return 1; 
    }
    
    char str[1001];
    if (fgets(str, sizeof(str), input) == NULL) {
        return 1;
    }
    
    str[strcspn(str, "\n")] = '\0';
    
    int length = strlen(str);
    if (length == 0) {
        return 1;
    }
    
    char last_char = str[length-1];
    
    int first = 1;
    for (int i = 0; i < length-1; i++) {
        if (str[i] == last_char) {
            if (!first) {
                fprintf(output, " ");
            }
            fprintf(output, "%d", i);
            first = 0;
        }
    }
    
    fclose(input);
    fclose(output);
    
    return 0;
}
