#include <iostream>

void recursiveChangeX(std::string &string, std::string &result);

std::string recursiveChangeX2(std::string string);

int main()
{
    std::string sample = "Sexxx is fun!";
    std::string result = "";
    recursiveChangeX(sample, result);
    std::cout << result << std::endl;
    return 0;
}

void recursiveChangeX(std::string &string, std::string &result)
{
    if (string == "") return;

    if (string.at(string.size() - 1) == 'x') {
        result.insert(0, "X");
    } else {
        result.insert(0, 1, string.at(string.size() - 1));
    }

    return recursiveChangeX(string.erase(string.size() - 1, 1), result);
}

/*char recursiveChangeX2(std::string string)
{
    if (string.size() == 0) return '';

    if (string.at(string.size() - 1) == 'x') {
        return 'X';
    } else {
        return string.at(string.size() - 1);
    }

    return recursiveChangeX(string.erase(string.size() - 1, 1));
}*/

}