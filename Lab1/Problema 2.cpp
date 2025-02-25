#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    char* words[100];
    char* temp;
    int wordCount = 0;

    printf("Introduceti o propozitie: ");
    fgets(sentence, sizeof(sentence), stdin);

    size_t len = strlen(sentence);
    if (len > 0 && sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
        len--;
    }

    char* context = NULL;
    char* token = strtok_s(sentence, " ", &context);
    while (token != NULL && wordCount < 100) {
        words[wordCount] = token;
        wordCount++;
        token = strtok_s(NULL, " ", &context);
    }

    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - i - 1; j++) {
           
            size_t len1 = strlen(words[j]);
            size_t len2 = strlen(words[j + 1]);

            if (len1 < len2 || (len1 == len2 && strcmp(words[j], words[j + 1]) > 0)) {
                temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }

    printf("Cuvintele sortate (de la cel mai lung la cel mai scurt):\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}