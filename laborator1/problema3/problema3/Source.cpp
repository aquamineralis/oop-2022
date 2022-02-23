#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

void sortWords(char words[][100], int wordCount) {
    for (int i = 0; i < wordCount - 1; i++)
        for (int j = i + 1; j < wordCount; j++) {
            if (strlen(words[i]) < strlen(words[j])) {
                char temp[100];
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            } else if (strlen(words[i]) == strlen(words[j])) {
                if (strcmp(words[i], words[j]) > 0) {
                    char temp[100];
                    strcpy(temp, words[i]);
                    strcpy(words[i], words[j]);
                    strcpy(words[j], temp);
                }
            }
        }
}

void solve() {
    int wordCount = 0;
    char words[100][100];
    char string[10000];

    scanf("%[^\n]s", string);
    char* word = strtok(string, " \n");
    while (word != NULL) {
        strcpy(words[wordCount++], word);
        word = strtok(NULL, " \n");
    }

    sortWords(words, wordCount);

    for (int i = 0; i < wordCount; i++)
        printf("%s\n", words[i]);
}

int main() {
    // I went to the library yesterday
    solve();
    return 0;
}