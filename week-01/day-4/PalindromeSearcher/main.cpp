#include <iostream>
#include <algorithm>

void palindromeFinder(int position, std::string sampleString, std::string &resultString);

void palindromeFinderEven(int position, std::string sampleString, std::string &resultString);


int main() {
    std::string sample = "dog goat dad duck doodle never";
    std::string result = "";


    for (int i = 0; i < sample.length(); i++) {
        palindromeFinder(i, sample, result);
    }

    std::cout << result;

    return 0;
}

void palindromeFinder(int position, std::string sampleString, std::string &resultString) {

    int distanceToEnd = std::min((int) (sampleString.length() - position - 1), position);


    for (int i = 0; i < distanceToEnd; i++) {
        if (sampleString.at(position - i - 1) == sampleString.at(position + i + 1)) {
            resultString.append(sampleString.substr(position - i - 1, 3 + i * 2));
            resultString.append(" ");
        } else if (sampleString.at(position) == sampleString.at(position + 1)) {
            if (sampleString.at(position - i) == sampleString.at(position + 1 + i)) {
                if (i * 2 > 0) {
                    resultString.append(sampleString.substr(position - i, 2 + i * 2));
                    resultString.append(" ");
                }
            }
        } else
            break;
    }
}

void palindromeFinderEven(int position, std::string sampleString, std::string &resultString) {

    int distanceToEnd = std::min((int) (sampleString.length() - position - 1), position);
    for (int i = 0; i < distanceToEnd; i++) {
        if (sampleString.at(position) == sampleString.at(position + 1)) {
            if (sampleString.at(position - i) == sampleString.at(position + 1 + i)) {
                resultString.append(sampleString.substr(position - i, 2 + i * 2));
                resultString.append(" ");
            }
        } else
            break;
    }

}