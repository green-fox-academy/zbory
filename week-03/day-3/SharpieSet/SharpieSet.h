//
// Created by zbora on 2019-04-17.
//

#ifndef SHARPIESET_SHARPIESET_H
#define SHARPIESET_SHARPIESET_H

#include <vector>
#include "Sharpie.h"

class SharpieSet {
public:
    SharpieSet();
    Sharpie *getSharpie(int i);
    void addSharpie(Sharpie s);
    int countUsable();
    void removeTrash();
private:
    std::vector<Sharpie> sharpies;
};


#endif //SHARPIESET_SHARPIESET_H
