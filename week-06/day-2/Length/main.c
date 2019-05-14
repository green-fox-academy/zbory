#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ask_name(char *name);
int string_length(char* string);

int main()
{
    // Create a program which asks for the name of the user and stroes it
    // Create a function which takes a string as a parameter and returns the lenght of it
    // Solve this exercie with and without using string.h functions

    char name[30];
    ask_name(&name);
    printf("The length of your name is %d\n", string_length(name));
    printf("According to strlen() it is %d\n", strlen(name));
    return 0;
}

void ask_name(char *name){
    printf("Please input your name:\n");
    scanf("%s", name);
}

int string_length(char* string){
    int counter = 0;
    while(*string != '\0'){
        counter++;
        string++;
    }
    return counter;
}