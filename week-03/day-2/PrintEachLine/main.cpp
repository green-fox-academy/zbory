#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Write a program that opens a file called "my-file.txt", then prints
    // each line from the file.
    // You will have to create the file, you may use C-programming, although it is not mandatory

    std::ifstream file;
//    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        file.open("../text.txt");
        if(!file.is_open()){
            throw std::exception();
        }
        std::string text;
        while (getline(file, text)) {
            std::cout << text << std::endl;
        }
        file.close();
    } catch (std::exception &e) {
        std::cout << "file not found" << std::endl;
    }


    return 0;
}