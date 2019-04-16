#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Open a file called "my-file.txt"
    // Write your name in it as a single line

    std::ofstream file;
    try {
        file.open("../my-file.txt");
        if (!file.is_open()) {
            throw std::runtime_error("File not found");
        }
        file << "Balazs Zboray";
        file.close();
    }catch(std::runtime_error e){
        std::cout << e.what();
    }


    return 0;
}