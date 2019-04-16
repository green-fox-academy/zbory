#include <iostream>
#include <fstream>
#include <string>

void printLines(std::string path, std::string word, int number);

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"

int main() {

    try{
        printLines("../tetx.txt", "The cake is Lie", 10);
    }catch(std::runtime_error e){
        std::cout << e.what();
    }
    return 0;
}

void printLines(std::string path, std::string word, int number){
    std::ofstream file(path);
    if(!file.is_open()){
        throw std::runtime_error("File could not be opened!");
    }
    for (int i = 0; i <  number; ++i) {
        file << word << std::endl;
    }
}