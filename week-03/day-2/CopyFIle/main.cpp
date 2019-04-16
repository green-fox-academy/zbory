#include <iostream>
#include <fstream>
#include <string>

bool copyLines(std::string sourceFile, std::string destinationFile);

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful

int main()
{
    std::string source = "../source.txt";
    std::string destination = "../destination.txt";

    bool result;

    try {
        result = copyLines(source, destination);
    } catch (std::ifstream::failure &e) {
        std::cout << e.what() << std::endl;
    } catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

bool copyLines(std::string sourceFile, std::string destinationFile)
{
    std::ifstream sFile(sourceFile);
    std::ofstream oFile(destinationFile);
    sFile.exceptions(std::ifstream::badbit);
    oFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);

    if (!sFile.is_open() || !oFile.is_open()) {
        throw std::runtime_error("File could not be opened!");
    }
    std::string temp;
    while (getline(sFile, temp)) {
        oFile << temp << std::endl;
    }
    return true;
}