#include <stdio.h>
#include <string.h>

// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, for that you may use C-programming, although it is not mandatory

int main()
{
    char line[100];
    FILE *file;
    file = fopen("my-file.txt", "r");
    if (file != NULL) {
        while (fgets(line, 100, file)) {

            printf("%s", line);
        }
    }
    fclose(file);
    return 0;
}