#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

int main() {
    char *str = NULL;
    size_t len = 0;

    printf("Enter a string: ");
    getline(&str, &len, stdin);

    str[strcspn(str, "\n")] = '\0';

    reverseString(str);

    printf("Reversed string: %s\n", str);

    free(str);

    return 0;
}
