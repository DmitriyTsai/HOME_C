#include <stdio.h>
#include <string.h>

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    
    if (input_file == NULL || output_file == NULL) {
        return 1;
    }
    
    char str[1000]; // Буфер для строки
    if (fgets(str, sizeof(str), input_file) == NULL) {
        return 1;
    }
    
    str[strcspn(str, "\n")] = '\0';
    
    int length = strlen(str);
    
    fprintf(output_file, "%s, %s, %s %d", str, str, str, length);
    
    fclose(input_file);
    fclose(output_file);
    
//    printf("Количество символов в строке: %d\n", length);
    
    return 0;
}
