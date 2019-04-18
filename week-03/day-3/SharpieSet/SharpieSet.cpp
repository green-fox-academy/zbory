//
// Created by zbora on 2019-04-17.
//

#include "SharpieSet.h"

SharpieSet::SharpieSet(){}

Sharpie *SharpieSet::getSharpie(int i){
    return &sharpies[i];
}

int SharpieSet::countUsable()
{
    int count = 0;
    for (int i = 0; i < sharpies.size(); i++){
        if(sharpies[i].getInkAmount() > 0){
            count++;
        }
    }
    return count;
}

void SharpieSet::removeTrash()
{
    for (int i = 0; i < sharpies.size(); i++){
        if(sharpies[i].getInkAmount() == 0){
            sharpies.erase(sharpies.begin() + i);
        }
    }
}

void SharpieSet::addSharpie(Sharpie s)
{
    sharpies.push_back(s);
}