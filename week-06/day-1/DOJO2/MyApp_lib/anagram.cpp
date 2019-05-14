//
// Created by zbora on 2019-05-13.
//
#include <iostream>
#include <algorithm>
#include <string>
#include "anagram.h"


bool checkIfAnagram(std::string string1, std::string string2)
{
    std::sort(string1.begin(), string1.end());
    std::sort(string2.begin(), string2.end());


    return !(string1.compare(string2));
}
