#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

// Read all data from 'log.txt'.
// Each line represents a log message from a web server
// Write a function that returns an array with the unique IP adresses.
// Write a function that returns the GET / POST request ratio.

void loadData(std::string path, std::vector<std::string> &fileLines);

void printVector(std::vector<std::string> vector);

void getAddresses(std::vector<std::string> source, std::vector<std::string> &result);

double getPostRatio(std::vector<std::string> vector);

void getUniqueAddress(std::vector<std::string> source, std::vector<std::string> &result);

bool findAddress(std::string address, std::vector<std::string> addressVector);

std::regex regexIp("\\b\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\b");

int main()
{
    std::string filePath = "../log.txt";
    std::vector<std::string> fileLines;
    std::vector<std::string> ipAddresses;
    std::vector<std::string> uniqueAddresses;

    try {
        loadData(filePath, fileLines);
    } catch (std::ifstream::failure &e) {
        std::cout << e.what();
    } catch (std::runtime_error e) {
        std::cout << e.what();
    }

    getAddresses(fileLines, ipAddresses);
//    printVector(ipAddresses);
    getUniqueAddress(ipAddresses, uniqueAddresses);
    printVector(uniqueAddresses);

    std::cout << getPostRatio(fileLines) << std::endl;

    return 0;
}

void loadData(std::string path, std::vector<std::string> &fileLines)
{
    std::ifstream logFile(path);
    std::string line;
    logFile.exceptions(std::ifstream::badbit);

    if (!logFile.is_open()) {
        throw std::runtime_error("File could not be opened!");
    }

    while (std::getline(logFile, line)) {
        fileLines.push_back(line);
    }

}

void printVector(std::vector<std::string> vector)
{
    std::vector<std::string>::iterator iterator = vector.begin();

    for (; iterator != vector.end(); iterator++) {
        std::cout << *iterator << std::endl;
    }
}

void getAddresses(std::vector<std::string> source, std::vector<std::string> &result)
{
    std::smatch sm;

    std::vector<std::string>::iterator iterator;

    for (iterator = source.begin(); iterator != source.end(); iterator++) {
        std::regex_search(*iterator, sm, regexIp);
        result.push_back(sm.str());
    }
}

double getPostRatio(std::vector<std::string> vector)
{
    std::vector<std::string>::iterator iterator;
    int getCount = 0;
    int postCount = 0;

    for (iterator = vector.begin(); iterator != vector.end(); iterator++) {
        if ((*iterator).find("GET") != std::string::npos) {
            getCount++;
        }
        if ((*iterator).find("POST") != std::string::npos) {
            postCount++;
        }
    }
    return getCount / (double) postCount;
}

void getUniqueAddress(std::vector<std::string> source, std::vector<std::string> &result)
{
    std::vector<std::string>::iterator iterator;

    for (iterator = source.begin(); iterator != source.end(); iterator++) {
        if(!findAddress(*iterator,result)){
            result.push_back(*iterator);
        }
    }
}

bool findAddress(std::string address, std::vector<std::string> addressVector)
{
    bool found = false;
    std::vector<std::string>::iterator iterator;
    for (iterator = addressVector.begin(); iterator != addressVector.end(); iterator++) {
        if (address.compare(*iterator) == 0)
            found = true;
    }
    return found;
}

/*std::string temp;

std::vector<std::string>::iterator iterator;

for (iterator = source.begin(); iterator != source.end(); iterator++) {
std::stringstream lineStream(*iterator);
//reading the line till the '   ' character
if (std::getline(lineStream, temp, '   ')) {

std::string ipAddress;

//reading the remainder of the line
if (std::getline(lineStream, ipAddress)) {

//if there is no date in the line, then we will ignore that line
if (ipAddress.empty()) {
continue;
}
//saving the key-value pair in the map
result.push_back(ipAddress);*/
