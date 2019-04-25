//
// Created by zbora on 2019-04-25.
//


#include "anagram.h"

bool isAnagram(std::string string1, std::string string2)
{
    std::string sorted1 = bubbleSort(string1);
    std::string sorted2 = bubbleSort(string2);

    if (sorted1.compare(sorted2) == 0)
        return true;
    else
        return false;
}


std::string bubbleSort(std::string string)
{
    std::string result = string;
    for (int i = 0; i < result.length(); i++) {
        for (int j = i + 1; j < result.length(); j++) {
            if (result[i] > result[j]) {
                char temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }
    return result;
}
