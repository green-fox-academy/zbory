//
// Created by zbora on 2019-05-02.
//

#include <iostream>
#include <fstream>
#include "doubled.h"

void decryptFile(std::string path)
{
    std::ifstream inputFile;
    std::ofstream outputFile;

    inputFile.exceptions(std::ifstream::badbit);
    outputFile.exceptions(std::ofstream::badbit | std::ofstream::failbit);

    try{
        inputFile.open(path);
        outputFile.open("decrypted.txt");

        std::string line;
        while(std::getline(inputFile, line)){
            std::string temp = decryptLine(line);
            outputFile << temp;
        }

        inputFile.close();
        outputFile.close();

    }catch(std::fstream::failure &e){
        std::cout << e.what();
    }
}

std::string decryptLine(std::string cryptedLine)
{
    std::string result = "";

    for (int i = 0; i < cryptedLine.length(); ++i) {
        if(!(i%2)){
            result.push_back(cryptedLine[i]);
        }
    }
    result.push_back('\n');
    return result;
}