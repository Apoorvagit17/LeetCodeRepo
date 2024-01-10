#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1) return s;

    int len = strlen(s);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;

    // Calculate the zigzag pattern
    for (int i = 0; i < numRows; i++) {
        for (int j = i; j < len; j += 2 * (numRows - 1)) {
            result[index++] = s[j];
            if (i != 0 && i != numRows - 1 && j + 2 * (numRows - i - 1) < len) {
                result[index++] = s[j + 2 * (numRows - i - 1)];
            }
        }
    }
    result[index] = '\0';
    return result;
}

int main() {
    char s[100];
    printf("enter a string\n");
    gets(s);
    int numRows = 3;
    char* converted = convert(s, numRows);
    printf("%s\n", converted);
    free(converted);
    return 0;
}