//
// Created by zbora on 2019-05-13.
//
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include "numberconvert.h"

std::string convertNumber(int value)
{
    std::vector<int> number;
    std::string result = "";
    do {
        int decimal = value % 10;
        number.insert(number.begin(), decimal);
        value /= 10;
    } while (value);

    std::map<int, std::string> myMap = {{0,       "zero"},
                                        {1,       "one"},
                                        {2,       "two"},
                                        {3,       "three"},
                                        {4,       "four"},
                                        {5,       "five"},
                                        {6,       "six"},
                                        {7,       "seven"},
                                        {8,       "eight"},
                                        {9,       "nine"},
                                        {10,      "ten"},
                                        {11,      "eleven"},
                                        {12,      "twelve"},
                                        {13,      "thirteen"},
                                        {14,      "fourteen"},
                                        {15,      "fifteen"},
                                        {16,      "sixteen"},
                                        {17,      "seventeen"},
                                        {18,      "eighteen"},
                                        {19,      "nineteen"},
                                        {20,      "twenty"},
                                        {30,      "thirty"},
                                        {40,      "fourty"},
                                        {50,      "fifty"},
                                        {60,      "sixty"},
                                        {70,      "seventy"},
                                        {80,      "eighty"},
                                        {90,      "ninety"},
                                        {100,     "hundred"},
                                        {1000,    "thousand"},
                                        {1000000, "million"}};

//    return myMap[value / 100] + " hundred and " + myMap[value % 100 - (value % 10)] + " " + myMap[value % 10];
//    std::string temp = "";
//    for (int i = 0; i < number.size(); ++i) {
//        temp += std::to_string(number[i]);
//    }
    for (int i = 0; i < number.size(); ++i) {
        if (i == number.size() - 2) {
            result += (myMap[number[i] * 10] + " ");
        }else if (i == number.size() - 1){
            result += myMap[number[i]];
        }
        else
            result += (myMap[number[i]] + " " + myMap[std::pow(10, number.size() - 1 - i)] + " ");
        if(i == 1){
            if(number[i] != 0){
                result += "hundred ";
            }
        }
    }
    return result;
}
