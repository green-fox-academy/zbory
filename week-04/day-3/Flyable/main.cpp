#include <iostream>
#include "Helicopter.h"
#include "bird.h"

int main()
{
    std::cout << "Helicopter\n";
    Helicopter helicopter(4000, 200, 800);
    helicopter.takeOff();
    helicopter.fly();
    helicopter.land();

    std::cout << "Bird\n";
    Bird bird("raven");
    bird.takeOff();
    bird.fly();
    bird.land();
    return 0;
}