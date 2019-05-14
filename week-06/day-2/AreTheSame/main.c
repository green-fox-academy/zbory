#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int equal_strings(char *string, char *string2);

main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char string1[100];
    char string2[100];
    printf("Please input two strings!\n");
    scanf("%s %s", string1, string2);

    printf("These strings are %s!", equal_strings(string1, string2) ? "the same" : "not the same");

    return 0;
}

int equal_strings(char *string1, char *string2)
{
    int string1_length = strlen(string1);
    int string2_length = strlen(string2);

    if (string1_length != string2_length)
        return 0;

    for (int i = 0; i < string1_length; ++i) {
        if (string1[i] != string2[i])
            return 0;
    }
    return 1;
}