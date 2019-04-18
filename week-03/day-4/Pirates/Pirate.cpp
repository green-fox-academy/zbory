//
// Created by zbora on 2019-04-18.
//

#include "Pirate.h"

Pirate::Pirate()
{
    intoxicationLevel = 0;
    alive = true;
    passedOut = false;
}

bool Pirate::isAlive()
{
    return alive;
}

void Pirate::setAlive(bool state)
{
    alive = state;
}

void Pirate::setPassedOut(bool state)
{
    passedOut = true;
}

void Pirate::drinkSomeRum()
{
    if (!alive) {
        std::cout << "He's dead...";
    } else {
        intoxicationLevel++;
    }

}

void Pirate::howsItGoingMate()
{
    if (!alive) {
        std::cout << "He's dead...";
    } else {
        {
            if (intoxicationLevel < 5) {
                std::cout << "Pour me anudder!\n";
            } else {
                passedOut = true;
                std::cout << "Arghh, I'ma Pirate. How d'ya d'ink its goin?\n";
            }
        }
    }
}

void Pirate::die()
{
    alive = false;
}

void Pirate::brawl(Pirate pirate)
{
    if (!alive) {
        std::cout << "He's dead...";
    } else {
        if (pirate.isAlive()) {
            int outcome = randomNumber(100);
            if (outcome < 33) {
                this->alive = false;
            } else if (outcome > 66) {
                pirate.setAlive(false);
            } else {
                pirate.setPassedOut(true);
                this->passedOut = true;
            }
        }

    }
}

int Pirate::randomNumber(int limit)
{
    return rand() % (limit);;
}