//
// Created by zbora on 2019-04-18.
//

#include <iostream>
#include "Pirate.h"

Pirate::Pirate()
{
    name = "Pirate" + std::to_string(rand() % 1000);
    intoxicationLevel = 0;
    alive = true;
    passedOut = false;
}

Pirate::Pirate(std::string name)
{
    this->name = name;
    intoxicationLevel = 0;
    alive = true;
    passedOut = false;
}

std::string Pirate::getName()
{
    return name;
}

int Pirate::getIntoxicationLevel()
{
    return intoxicationLevel;
}

bool Pirate::isAlive()
{
    return alive;
}

bool Pirate::isConscious()
{
    return !passedOut;
}

void Pirate::setPassedOut(bool state)
{
    std::cout << name << " got drunk and went sleepy go bye bye.\n";
    passedOut = state;
}

void Pirate::drinkSomeRum()
{
    if (!alive) {
        std::cout << "He's dead...\n";
    } else if (!passedOut) {
        intoxicationLevel++;
    }
    if (intoxicationLevel == 5 && !passedOut) {
        setPassedOut(true);
    }

}

void Pirate::howsItGoingMate()
{
    if (!alive) {
        std::cout << "He's dead...\n";
    } else {
        {
            if (intoxicationLevel < 5) {
                std::cout << "Pour me anudder!\n";
                drinkSomeRum();
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
    std::cout << name << " is sleeping with the fishes.\n";
}

void Pirate::brawl(Pirate pirate)
{
    if (!alive) {
        std::cout << "He's dead...\n";
    } else {
        if (pirate.isAlive()) {
            int outcome = rand() % 100;
            if (outcome < 33) {
                this->die();
            } else if (outcome > 66) {
                pirate.die();
            } else {
                pirate.setPassedOut(true);
                this->setPassedOut(true);
            }
        }

    }
}

std::string Pirate::toString()
{
    std::string state = "";
    if (!isAlive()) {
        state = "dead.\n";
    } else if (isConscious()) {
        state = "alive and conscious.\n";
    } else {
        state = "alive and passed out.\n";
    }
    return name + " is " + std::to_string(getIntoxicationLevel()) + "/4 drunk, " + state;
}
