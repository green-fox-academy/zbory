#include <iostream>
#include <vector>

#include "Dominoes.h"

Domino findDomino(int number, std::vector<Domino> &dominoes);

void orderDominoes(std::vector<Domino> dominoes, std::vector<Domino> &result);

std::vector<Domino> initializeDominoes()
{
    std::vector<Domino> dominoes;
    dominoes.push_back(Domino(5, 2));
    dominoes.push_back(Domino(4, 6));
    dominoes.push_back(Domino(1, 5));
    dominoes.push_back(Domino(6, 7));
    dominoes.push_back(Domino(2, 4));
    dominoes.push_back(Domino(7, 1));
    return dominoes;
}

int main(int argc, char *args[])
{
    std::vector<Domino> dominoes = initializeDominoes();
    // You have the list of Dominoes
    // Order them into one snake where the adjacent dominoes have the same numbers on their adjacent sides
    // eg: [2, 4], [4, 3], [3, 5] ...

    std::vector<Domino> result;
    orderDominoes(dominoes, result);

    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i].toString();
    }

    return 0;
}

void orderDominoes(std::vector<Domino> dominoes, std::vector<Domino> &result)
{
    int startPos = 5;
    int count = 0;

    Domino currentDomino = dominoes[startPos];
    result.push_back(dominoes[startPos]);
    for (int i = 0; i < dominoes.size() - 1; i++) {
        Domino tempDomino = findDomino(currentDomino.getValues().second, dominoes);
        result.push_back(tempDomino);
        currentDomino = tempDomino;
    }
}

Domino findDomino(int number, std::vector<Domino> &dominoes)
{
    std::vector<Domino>::iterator iterator;

    for (iterator = dominoes.begin(); iterator != dominoes.end(); iterator++) {
        if (iterator->getValues().first == number)
            return *iterator;
    }
}

/*
void orderDominoRecursive(std::vector<Domino> dominoes, Domino currentDomino){

    if(dominoes.size() == 0) return;

    orderDominoRecursive(findDomino(currentDomino.getValues().second, dominoes));
}
*/
