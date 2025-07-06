#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 101

void count_chars(const char *word, int *count) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (islower(word[i])) {
            count[word[i] - 'a']++;
        }
    }
}

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    if (input == NULL || output == NULL) {
        return 1;
    }
    
    char word1[MAX_LEN], word2[MAX_LEN];
    if (fscanf(input, "%100s %100s", word1, word2) != 2) {
        return 1;
    }
    
    int count1[26] = {0};
    int count2[26] = {0};
    
    count_chars(word1, count1);
    count_chars(word2, count2);
    
    int first = 1;
    for (char c = 'a'; c <= 'z'; c++) {
        if (count1[c - 'a'] == 1 && count2[c - 'a'] == 1) {
            if (!first) {
                fprintf(output, " ");
            }
            fprintf(output, "%c", c);
            first = 0;
        }
    }
    
    fclose(input);
    fclose(output);
    return 0;
}
