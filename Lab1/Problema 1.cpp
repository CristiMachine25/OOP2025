﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int convertStringToInt(const char* str) {
    if (str == NULL)
        return 0;

    int result = 0;
    int sign = 1;
    int i = 0;

    // Convert each digit
    while (str[i] != '\0') {
        if (isdigit((unsigned char)str[i])) {
            if (result > (INT_MAX - (str[i] - '0')) / 10) {
                return sign > 0 ? INT_MAX : INT_MIN;
            }
            result = result * 10 + (str[i] - '0');
        }
        else {
            break;
        }
        i++;
    }

    return sign * result;
}

int main() {
    FILE* file = NULL;
    char buffer[256];
    int sum = 0;
    errno_t err;
    err = fopen_s(&file, "in.txt", "r");
    if (err != 0 || file == NULL) {
        printf("Error opening file! Code: %d\n", err);
        return 1;
    }

    // Read each line from file
    memset(buffer, 0, sizeof(buffer));

    // Use regular fgets instead of fgets_s
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Process line
        size_t length = strlen(buffer);
        int number = convertStringToInt(buffer);
        sum += number;
        memset(buffer, 0, sizeof(buffer));
    }
    if (file != NULL) {
        fclose(file);
    }
    printf("%d\n", sum);
    return 0;
}