//
// Created by zbora on 2019-04-25.
//

#include "apples.h"


std::string getApple(){
    return "apple";
}

int sum(std::vector<int> vector){
    int sum = 0;

    for (int i = 0; i < vector.size() ; ++i) {
        sum += vector[i];
    }

    return sum;
}