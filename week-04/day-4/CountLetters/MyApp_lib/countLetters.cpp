//
// Created by zbora on 2019-04-25.
//

#include <iostream>
#include <map>
#include "countLetters.h"

std::map<char, int> countLetters(std::string string)
{
    std::map<char, int> result;
    for (int i = 0; i < string.length(); ++i) {
        result[string[i]]++;
    }

    return result;
}