#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_inside(char c, char *string);

int main()
{
    // Create a program which asks for a string and a character and stores them
    // Create a function which takes a string and a character as a parameter and
    // if the given character is in the string, it should return the index of the
    // first appearance (in the given string) otherwise the function should return -1
    //
    // Example:
    //
    // Case 1:
    //
    // given_string = "embedded"
    // given_char = 'd'
    //
    // the function should return: 4, because this is the index of the first appearance of char 'd'
    //
    //
    // Case 2:
    //
    // given_string = "embedded"
    // given_char = 'a'
    //
    // the function should return: -1, because there is no 'a' in the word "embedded"
    //

    char line[100];
    char c;
    printf("Please input a string!\n");
    scanf("%s", line);
    printf("Please input a character!\n");
    scanf(" %c", &c);

    printf("%d", is_inside(c, line));

    return 0;
}

int is_inside(char c, char *string)
{
    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] == c)
            return i;
    }
    return -1;
}