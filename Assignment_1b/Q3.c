#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

void toLowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char paragraph[10000];
    char words[MAX_WORDS][MAX_WORD_LEN];
    int freq[MAX_WORDS] = {0};
    int wordCount = 0;

    printf("Enter a paragraph: ");
    fgets(paragraph, sizeof(paragraph), stdin);

    char *token = strtok(paragraph, " ,.-\n");
    while (token != NULL) {
        toLowercase(token);
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], token) == 0) {
                freq[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[wordCount], token);
            freq[wordCount]++;
            wordCount++;
        }
        token = strtok(NULL, " ,.-\n");
    }

    printf("Word frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i], freq[i]);
    }

    return 0;
}
