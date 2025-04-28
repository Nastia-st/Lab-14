#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

int main() {
    system("chcp 65001");
    char str[1000];
    printf("Введіть рядок англійською мовою: ");
    fgets(str, sizeof(str), stdin);
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    int minLen = INT_MAX;
    int currentLen = 0;
    int wordFound = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ' && str[i] != '\0') {
            currentLen++;
        } else if (currentLen > 0) {
            if (currentLen < minLen) {
                minLen = currentLen;
            }
            currentLen = 0;
        }
    }
    if (currentLen > 0 && currentLen < minLen) {
        minLen = currentLen;
    }

    if (minLen == INT_MAX) {
        printf("У рядку немає слів.\n");
    } else {
        printf("Довжина найкоротшого слова: %d\n", minLen);
    }
    return 0;
}