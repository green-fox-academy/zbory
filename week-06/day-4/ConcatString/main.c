#include <stdio.h>
#include <stdlib.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.

char *concat_string(char *string1, char *string2);

int string_size(char *string);

int main()
{
    char string1[20];
    char string2[20];

    printf("Input two strings!\n");
    scanf("%s", string1);
    scanf("%s", string2);

    char *concatd_string = concat_string(string1, string2);
    printf("%s", concatd_string);
    free(concatd_string);
    concatd_string = NULL;
    return 0;
}

char *concat_string(char *string1, char *string2)
{
    int string1_length = string_size(string1);
    int string2_length = string_size(string2);

    char *result = (char *) malloc(sizeof(char) * (string1_length + string2_length) + 1);
    for (int i = 0; i < string1_length; ++i) {
        result[i] = string1[i];
    }
    for (int j = 0; j < string2_length; ++j) {
        result[j + string1_length] = string2[j];
    }
    result[string1_length + string2_length] = '\0';
    return result;
}

int string_size(char *string)
{
    int counter = 0;
    while (*string != '\0') {
        counter++;
        string++;
    }
    return counter;
}