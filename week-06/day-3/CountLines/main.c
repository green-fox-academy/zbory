#include <stdio.h>
#include <string.h>

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file

int count_lines(char *filename);

int main ()
{
    char filename[] = "my-file.txt";
    printf("The number of lines in the file: %d", count_lines(filename));
    return 0;
}

int count_lines(char *filename){
    FILE *file;
    file = fopen(filename, "r");
    char temp[1000];

    if(file == NULL)
        return 0;

    int counter = 0;
    while(fgets(temp, 1000,file)){
        counter++;
    }
    return counter;
}