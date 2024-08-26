#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(char* s) {
    int size = strlen(s);
    char* s1 = (char*) malloc(size + 1);  // Allocate memory based on the string length plus one for '\0'
    if (!s1) {
        printf("Memory allocation failed\n");
        return false;
    }

    int j = 0;
    for (int i = 0; i < size; i++) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            s1[j++] = s[i] + 32;  // Convert to lowercase
        } else if (('a' <= s[i] && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9')) {
            s1[j++] = s[i];
        }
    }
    s1[j] = '\0';  // Null-terminate the string


    bool flag = true;
    int length = strlen(s1);
    for (int i = 0; i < length / 2; i++) {
        if (s1[i] != s1[length - i - 1]) {
            flag = false;
            break;
        }
    }

    free(s1);  // Free the allocated memory
    return flag;
}

int main(){
    char str[] ="Lool lool";
    bool r = isPalindrome(str);
    printf("\n");
    printf(r? "true" : "false");
    return 0;
}