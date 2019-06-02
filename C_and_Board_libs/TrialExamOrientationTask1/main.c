#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char decode_binary(char *binary_string);

char *decode_file(char *path);

int main()
{
    char *string = decode_file("input.txt");
    printf("%s", string);

    free(string);
    return 0;
}

char *decode_file(char *path)
{
    int length = 0;
    char *result = (char *) malloc(sizeof(char));
    result[length] = '\0';

    FILE *file = NULL;
    file = fopen(path, "r");

    if (file == NULL)
        return result;

    char temp;
    char binary_character[8];
    while(fscanf(file, "%s", binary_character) != EOF){
        temp = decode_binary(binary_character);
        result = (char *) realloc(result, sizeof(char) * length + 2);
        result[length] = temp;
        result[length + 1] = '\0';
        length++;
    }

    fclose(file);
    file = NULL;

    return result;
}

char decode_binary(char *binary_string)
{
    char ascii = 0;
    for (int i = 0; i < 8; ++i) {
        ascii += (binary_string[i] - '0') * pow(2, 7 - i);
    }
    return ascii;
}