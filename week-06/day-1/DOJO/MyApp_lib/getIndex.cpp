//
// Created by zbora on 2019-05-13.
//
#include "getIndex.h"

int getItemIndex(int item, std::vector<int> vector){

    for (int i = 0; i < vector.size() ; ++i) {
        if(item == vector.at(i)){
            return i;
        }
    }
    return -1;
}