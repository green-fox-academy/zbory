#include <stdio.h>
#include <string.h>

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"

void print_lines(char *path, char *word, int number);

int main()
{
    print_lines("my-file.txt", "Who's your daddy?", 42);
    return 0;
}

void print_lines(char *path, char *word, int number)
{
    FILE *file;
    file = fopen(path, "w");

    if(file != NULL){
        for (int i = 0; i < number; ++i) {
            fprintf(file, "%s\n", word);
        }
    }
    fclose(file);
}