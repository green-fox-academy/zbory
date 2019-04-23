//
// Created by zbora on 2019-04-18.
//
#include <iostream>
#include <vector>
#include "Ship.h"


Ship::Ship()
{
    name = "Ship" + std::to_string(rand() % 100);
    maxCrewSize = 40;
    fillShip();
    parrotOnBoard = (rand() % 2) ? true : false;
    printCrewState();
}

Ship::Ship(std::string name) :Ship()
{
    this->name = name;
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

int Ship::countDead()
{
    int count = 0;
    for (int i = 0; i < crew.size(); ++i) {
        if (!crew[i].isAlive())
            count++;
    }
    return count;
}

int Ship::countPassedOut()
{
    int count = 0;
    for (int i = 0; i < crew.size(); ++i) {
        if (crew[i].isConscious())
            count++;
    }
    return count;
}

bool Ship::hasParrot(){
    return parrotOnBoard;
}

bool Ship::battle(Ship &enemy)
{
    //Original score definition modified by substracting half the drunk ones from score, if the ship has a parrot passed out
    //pirates don't count as negative
    int score = countAlive() - captain.getIntoxicationLevel() - hasParrot() ? 0 : countPassedOut() / 2;
    int enemyScore = enemy.countAlive() - enemy.captain.getIntoxicationLevel() - enemy.hasParrot() ? 0 : enemy.countPassedOut() / 2;

    std::cout << "\nBattle!\n" << name << " VS " << enemy.name << std::endl;
    if (score > enemyScore) {
        //This ship wins
        std::cout << std::endl << enemy.name << " has lost\n";
        int enemyToKill = rand() % enemy.countAlive() + 1;
        int enemyDead = enemy.countDead();
        for (int i = 0; i <  enemyToKill; i++) {
            //To set the rest of the crew dead, not the first n element again, i is offset by the amount of dead
            enemy.getPirate(enemyDead + i)->die();
        }
        std::cout << std::endl << name << " has won and having a party!\n";
        party();
        return true;
        //Enemy ship wins
    } else {
        std::cout << std::endl << name << " has lost\n";
        int toKill = rand() % countAlive() + 1;
        int dead = countDead();
        for (int i = 0; i < toKill; i++) {
            //To set the rest of the crew dead, not the first n element again, i is offset by the amount of dead
            getPirate(dead + i)->die();
        }
        std::cout << std::endl << enemy.name << " has won and having a party!\n";
        enemy.party();
    }
    return false;
}

void Ship::party(){
    int numberOfDrinks = 5;

    int drinksServed = rand() % numberOfDrinks;
    for(int i = 0; i < drinksServed; i++){
        captain.drinkSomeRum();
    }

    for (int i = 0; i < crew.size(); ++i) {
        drinksServed = rand() % numberOfDrinks;
        for(int j = 0; j < drinksServed; j++){
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
    std::cout << (hasParrot() ? "The ship has a parrot!\n" : "This ship has no parrot.\n");
//    std::cout << "------------------------------------------------------\n";
}