#include <stdio.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    char str = 'a';
    int counter = 0;
    while(str != '\0') {
        str = *(y + counter);
        *(x + counter) = *(y + counter);
        counter++;
    }
    *(x + counter) = '\0';
}

// /*
//     Searches the input string `str` for the first instance of the 
//     character `c` (an unsigned char). This function returns a pointer
//     that points to the first instance of the character `c` in the
//     input string `str`.

//     Do not use the `strchr` function from the standard library.
// */
char *find_char(char *str, int c)
{
    int len = sizeof(str) / sizeof(char);
    char character = 'a';
    int count = 0;
    while (character != '\0') {
        character = *(str + count);
        if (str[count] == c) {
            return &str[count];
        }
        count++;
    }
    return NULL;
}

// /*
//     Searches the input string `haystack` for the first instance of
//     the string `needle`. This function returns a pointer that points
//     to the first instance of the string `needle` in the input
//     string `haystack`. 

//     Do not use the `strstr` function from the standard library.
// */
char *find_string(char *haystack, char *needle)
{
    int len = strlen(haystack);
    int len2 = strlen(needle);
    for (int i = 0; i < len; i++) {
        if (*(haystack + i) == *needle) {
            for (int j = 0; j < len2; j++) {
                if (*(haystack + i + j) != *(needle + j)) {
                    return NULL;
                }
            }
            return haystack + i;
        }
    }
    return NULL;
}

#ifndef TESTING
int main(void)
{

    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
