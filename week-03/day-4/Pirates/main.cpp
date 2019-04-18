#include <iostream>
#include <ctime>
#include <vector>
#include "Ship.h"


int main()
{
    srand(time(0));

    std::string asciiShip = "              |    |    |\n"
                            "             )_)  )_)  )_)\n"
                            "            )___))___))___)\\\n"
                            "           )____)____)_____)\\\\\n"
                            "         _____|____|____|____\\\\\\__\n"
                            "---------\\                   /---------\n"
                            "  ^^^^^ ^^^^^^^^^^^^^^^^^^^^^\n"
                            "    ^^^^      ^^^^     ^^^    ^^\n"
                            "         ^^^^      ^^^";

    std::cout << asciiShip << std::endl;
    //Creating ships
    Ship ship1("Black Pearl");
    Ship ship2("The Dirty Titanic");
    //Filling them with crew
    ship1.fillShip();
    ship2.fillShip();
    //Ship1 heavy drinking
    ship1.getCaptain()->drinkSomeRum();
    ship1.getCaptain()->drinkSomeRum();
    ship1.getCaptain()->drinkSomeRum();


    ship1.printCrewState();
    ship2.printCrewState();

    //Battle
    bool result = ship1.battle(ship2);

//    ship1.printCrewState();
//    ship2.printCrewState();

    return 0;
}