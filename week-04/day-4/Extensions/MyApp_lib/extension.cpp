#include "extension.h"

#include <algorithm>
#include <sstream>

int add(int a, int b)
{
    return a + b;
}

int maxOfThree(int a, int b, int c)
{
    if (a > b) {
        if (a > c)
            return a;
        else
            return c;
    } else
        return b;
}

int median(const std::vector<int> &pool)
{
    int elementNumber = pool.size();
    int temp[elementNumber];

    for (int k = 0; k < elementNumber; ++k) {
        temp[k] = pool[k];
    }

    for (int i = 0; i < elementNumber; i++) {
        for (int j = i + 1; j < elementNumber; j++) {
            if (temp[i] > temp[j]) {
                int tempElement = temp[i];
                temp[i] = temp[j];
                temp[j] = tempElement;
            }
        }
    }
    if(elementNumber % 2)
        return temp[elementNumber / 2];
    else
        return temp[elementNumber / 2];
}

bool isVowel(char c)
{
    static const std::vector<char> vowels = {'a', 'u', 'o', 'e', 'i', 'A', 'E', 'I', 'O', 'U'};
    return std::find(vowels.begin(), vowels.end(), c) != vowels.end();
}

std::vector<std::string> split(const std::string &str, char delim)
{
    std::stringstream ss(str);
    std::string token;
    std::vector<std::string> v;
    while (std::getline(ss, token, delim)) {
        v.push_back(token);
    }

    return v;
}

std::string join(const std::string &separator, const std::vector<std::string> &array)
{
    std::stringstream ss;
    for (int i = 0; i < array.size(); ++i) {
        ss << array[i];
        if (i != array.size() - 1) {
            ss << separator;
        }
    }

    return ss.str();
}

std::string translate(const std::string &hungarian)
{
    std::string teve = hungarian;
    int length = teve.size();
    for (int i = 0; i < length; i++) {
        const char c = teve.at(i);
        if (isVowel(c)) {
            teve = join(std::string(1, c) + "v" + std::string(1, c), split(teve, c));
            i += 2;
            length += 2;
        }
    }
    return teve;
}