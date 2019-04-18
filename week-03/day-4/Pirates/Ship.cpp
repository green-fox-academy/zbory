//
// Created by zbora on 2019-04-18.
//
#include <iostream>
#include <vector>
#include "Ship.h"


Ship::Ship()
{
    name = "Ship" + std::to_string(rand() % 100);
    maxCrewSize = 100;
}

Ship::Ship(std::string name)
{
    this->name = name;
    maxCrewSize = 100;
}

std::string Ship::getName()
{
    return name;
}

Pirate *Ship::getPirate(int i)
{
    return &crew[i];
}

Pirate *Ship::getCaptain(){
    return &captain;
}

void Ship::fillShip()
{
    int crewCount = rand() % maxCrewSize;
    for (int i = 0; i < crewCount; ++i) {
        crew.push_back(Pirate());
    }
    captain = Pirate();
}

int Ship::countAlive()
{
    int count = 0;
    for (int i = 0; i < crew.size(); ++i) {
        if (crew[i].isAlive())
            count++;
    }
    return count;
}

bool Ship::battle(Ship enemy)
{
    int score = countAlive() - captain.getIntoxicationLevel();
    int enemyScore = enemy.countAlive() - enemy.captain.getIntoxicationLevel();

    std::cout << "\nBattle!\n";
    if (score > enemyScore) {
        //This ship wins
        std::cout << std::endl << enemy.name << " has lost\n";
        for (int i = 0; i < rand() % enemy.countAlive(); i++) {
            enemy.getPirate(i)->die();
        }
        std::cout << std::endl << name << " has won and having a party!\n";
        party();
        return true;
        //Enemy ship wins
    } else {
        std::cout << std::endl << name << " has lost\n";
        for (int i = 0; i < rand() % countAlive(); i++) {
            getPirate(i)->die();
        }
        std::cout << std::endl << enemy.name << " has won and having a party!\n";
        enemy.party();
    }
    return false;
}

void Ship::party(){
    int numberOfDrinks = 10;

    for(int i = 0; i < rand() % numberOfDrinks; i++){
        captain.drinkSomeRum();
    }

    for (int i = 0; i < crew.size(); ++i) {
        for(int j = 0; j < rand() % numberOfDrinks; j++){
            crew[i].drinkSomeRum();
        }
    }
}

void Ship::printCrewState()
{
    std::cout << "------------------------------------------------------\n";
    std::cout << name << std::endl;
    std::cout << "Captain " << captain.toString();
    std::cout << "There are " << countAlive() << " lard brained screechy gobshytes on board.\n";
//    std::cout << "------------------------------------------------------\n";
}