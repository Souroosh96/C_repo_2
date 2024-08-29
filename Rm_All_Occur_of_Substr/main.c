#include <stdio.h>
#include <string.h>

char* removeOccurrences(char* s, char* part) {
    int len_s = strlen(s);
    int len_part = strlen(part);

    // Continue the process while there are still parts to remove
    while (1) {
        char *pos = strstr(s, part); // Find the leftmost occurrence of 'part' in 's'
        if (pos == NULL) {
            break; // No more occurrences found, exit the loop
        }
        
        // Calculate the position where part was found
        int index = pos - s;

        // Remove the part by shifting the remaining string leftward
        memmove(&s[index], &s[index + len_part], len_s - index - len_part + 1);

        // Update the length of the string
        len_s -= len_part;
    }
    
    return s;
}
int main() {
    char str[] = "kaabcbcbc";
    char part[] = "abc";
    
    printf("Original string: %s\n", str);
    printf("String after removal: %s\n", removeOccurrences(str, part));

    return 0;
}