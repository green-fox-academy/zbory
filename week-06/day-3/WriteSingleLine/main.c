#include <stdio.h>
#include <string.h>

// Open a file called "my-file.txt"
// Write your name in it as a single line

int main ()
{
    FILE *file;
    file = fopen("my-file.txt", "w");

    if(file != NULL){
        fprintf(file, "Hi my name is %s", "Slim Shady");
        fclose(file);
    }
    return 0;
}