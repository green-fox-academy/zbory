#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_between_chars(char *string, char c);

int main()
{
    // Create a function which takes a string as a parameter and
    // returns the number of characters between two repeating characters
    // the repeating char can be a local variable in the function itself or
    // it can be passed to the function as parameter

    char word[50] = "asdhziaefvqffffffffffqefkmgldbfk";
    char c = 'q';

    // the output should be: 6 (in this case the repeating char was 'g')
    printf("%d", count_between_chars(word, c));

    return 0;
}

int count_between_chars(char *string, char c){
    int start_index = 0;
    int end_index = 0;
    for (int i = 0; string[i] != '\0'; ++i) {
        if(string[i] == c && start_index == 0)
            start_index = i;
        if(string[i] == c && i > start_index)
            end_index = i;
    }

    return end_index -1 - start_index;
}