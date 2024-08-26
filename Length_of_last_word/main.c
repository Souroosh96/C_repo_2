#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord(char* s) {
    int length = strlen(s);
    
    // Allocate memory for temp and last based on the input string length
    char* temp = (char*)malloc((length + 1) * sizeof(char));
    char* last = (char*)malloc((length + 1) * sizeof(char));

    if (!temp || !last) {  // Check if memory allocation was successful
        printf("Memory allocation failed\n");
        return -1;  // Return an error code if allocation fails
    }

    temp[0] = '\0';  // Initialize temp as an empty string
    last[0] = '\0';  // Initialize last as an empty string

    int j = 0;

    for (int i = 0; i < length; i++) {
        if (s[i] != ' ' && s[i] != '\0') {
            temp[j] = s[i];  // Add character to temp
            temp[j + 1] = '\0';  // Null-terminate temp
            j++;
        } else if (j > 0) {
            strcpy(last, temp);  // Copy temp to last if temp is not empty
            j = 0;  // Reset index for temp
            temp[0] = '\0';  // Reset temp to an empty string
        }
    }

    // After the loop, check if temp has the last word
    if (j > 0) {
        strcpy(last, temp);
    }

    int lastWordLength = strlen(last);

    // Free the dynamically allocated memory
    free(temp);
    free(last);

    return lastWordLength;
}

int main() {
    char s[] = "Hello World";
    int length = lengthOfLastWord(s);
    printf("Length of the last word: %d\n", length);
    return 0;
}