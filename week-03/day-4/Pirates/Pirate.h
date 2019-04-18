//
// Created by zbora on 2019-04-18.
//

#ifndef PIRATES_PIRATE_H
#define PIRATES_PIRATE_H

#include <iostream>


class Pirate {
public:
    Pirate();
    bool isAlive();
    void setAlive(bool alive);
    void setPassedOut(bool state);
    void drinkSomeRum();
    void howsItGoingMate();
    void die();
    void brawl(Pirate pirate);

private:
    bool passedOut;
    bool alive;
    int intoxicationLevel;
    int randomNumber(int limit);
};


#endif //PIRATES_PIRATE_H
