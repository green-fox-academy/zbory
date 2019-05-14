#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void append_a(char *string);

main()
{
    // Create a program which asks for a string and stores it
    // Create a function which takes a string as a parameter and
    // appends a character 'a' to the end of it and returns the new string

    char string[100];
    printf("Please input a string!\n");
    scanf("%s", string);

    append_a(string);
    printf("%s\n", string);

    append_a(string);
    printf("%s\n", string);

    return 0;
}

void append_a(char *string){
    //TODO: check if there's room to append
    int length = strlen(string);
    string[length] = 'a';
    string[length + 1] = '\0';
}