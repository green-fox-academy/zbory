//
// Created by zbora on 2019-04-24.
//

#include <iostream>
#include "scanner.h"

Scanner::Scanner(int speed)
{
    this->speed = speed;
}

void Scanner::scan()
{
    std::cout << "I'm scanning a document " << speed << " ppm\n";
}