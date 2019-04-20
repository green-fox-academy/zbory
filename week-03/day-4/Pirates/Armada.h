//
// Created by zbora on 2019-04-18.
//

#ifndef PIRATES_ARMADA_H
#define PIRATES_ARMADA_H

#include <vector>
#include "Ship.h"

class Armada {
public:
    Armada();
    void fillArmada();
    bool war(Armada &armada);
private:
    std::vector<Ship> ships;
    int maxArmadaSize;
};


#endif //PIRATES_ARMADA_H
