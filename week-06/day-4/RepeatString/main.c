#include <stdio.h>
#include <stdlib.h>

// write a function which takes a string and an integer as a parameter.
// The function should return a string where the input string is repeating. The number of repetition is based on the value of the integer parameter.
// For example: Apple, 5 -> AppleAppleAppleAppleApple
// Try to use the least amount of memory that's possible.

char *repeat_string(char *string, int number);

int string_size(char *string);

int main()
{
    char string[20];
    int number;

    printf("Input a strings!\n");
    scanf("%s", string);
    printf("Input a number!\n");
    scanf("%d", &number);

    char *result = repeat_string(string, number);
    printf("%s", result);
    return 0;
}

char *repeat_string(char *string, int number)
{
    int string_length = string_size(string);


    char *result = (char *) malloc(sizeof(char) * string_length * number + 1);
    for (int i = 0; i < string_length * number; ++i) {
        result[i] = string[i % string_length];
    }

    result[string_length * number] = '\0';
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