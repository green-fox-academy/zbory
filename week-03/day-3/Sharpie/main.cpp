#include <iostream>
#include "Sharpie.h"

int main()
{
    Sharpie sharpie("purple", 10);
    sharpie.use();
    std::cout << sharpie.getInkAmount();
    return 0;
}