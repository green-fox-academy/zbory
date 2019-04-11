#include <iostream>

void recursiveChangeX(std::string &string, std::string &result);

int main()
{
    std::string sample = "MASH4077";
    std::string result = "";
    recursiveChangeX(sample, result);
    std::cout << result << std::endl;
    return 0;
}

void recursiveChangeX(std::string &string, std::string &result)
{
    if (string.size() == 0) return;

    //if-else selection to not put * before first character (iterating through string backwards)
    if (string.size() != 1) {
        result.insert(0, 1, string.at(string.size() - 1));
        result.insert(0, "*");
    }else{
        result.insert(0, 1, string.at(string.size() - 1));
    }

    return recursiveChangeX(string.erase(string.size() - 1, 1), result);
}