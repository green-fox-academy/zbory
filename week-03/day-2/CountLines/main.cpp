#include <iostream>
#include <fstream>
#include <string>

int countLines(std::string filename);

int main () {
    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file

    std::string filePath = "../text.txt";

    int linecount = 0;
    try{
        linecount = countLines(filePath);
    }catch(std::exception e){
        std::cout << e.what() << std::endl;
    }

    std::cout << linecount;

    return 0;
}

int countLines(std::string filename){
    int count = 0;
    std::ifstream file(filename);
    if(!file.is_open()){
        throw std::exception();
    }
    std::string temp;
    while(getline(file, temp)){
        count++;
    }

    return count;
//    file.close();
}