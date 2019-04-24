#include <iostream>
#include "reptile.h"
#include "mammals.h"
#include "bird.h"


#include <iostream>

int main( int argc, char* args[] )
{
    Reptile reptile("Crocodile");
    Mammal mammal("Koala");
    Bird bird("Parrot");

    std::cout << "How do you breed?" << std::endl;
    std::cout << "A " << reptile.getName() << " is breeding by " << reptile.breed() << std::endl;
    std::cout << "A " << mammal.getName() << " is breeding by " << mammal.breed() << std::endl;
    std::cout << "A " << bird.getName() << " is breeding by " << bird.breed() << std::endl;

    std::cout << "\nWhat do you eat?" << std::endl;
    std::cout << "A " << reptile.getName() << ": " << reptile.feed() << std::endl;
    std::cout << "A " << mammal.getName() << ": " << mammal.feed() << std::endl;
    std::cout << "A " << bird.getName() << ": " << bird.feed() << std::endl;

    std::cout << "\nHow do you hunt?" << std::endl;
    std::cout << "A " << reptile.getName() << ": " << reptile.hunt() << std::endl;
    std::cout << "A " << mammal.getName() << ": " << mammal.hunt() << std::endl;
    std::cout << "A " << bird.getName() << ": " << bird.hunt() << std::endl;
}