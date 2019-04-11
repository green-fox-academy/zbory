#include <iostream>

void recursiveRemoveX(std::string &string, std::string &result);

int main()
{
    std::string sample = "Sexxx is fun!";
    std::string result = "";
    recursiveRemoveX(sample, result);
    std::cout << result << std::endl;
    return 0;
}

void recursiveRemoveX(std::string &string, std::string &result)
{
    if (string == "") return;

    if (string.at(string.size() - 1) == 'x') {
        //result.insert(0, "X");
    } else {
        result.insert(0, 1, string.at(string.size() - 1));
    }

    return recursiveRemoveX(string.erase(string.size() - 1, 1), result);
}