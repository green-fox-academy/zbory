#include <iostream>
#include "Sharpie.h"
#include "SharpieSet.h"

int main()
{

    Sharpie s1("yellow", 3.0);

    s1.drawALot();
    SharpieSet set;
    set.addSharpie(Sharpie("red", 5.0));
    set.addSharpie(Sharpie("orange", 8.0));
    set.addSharpie(s1);
    set.addSharpie(Sharpie("green", 5.0));

    std::cout << "Number of usable sharpies: " << set.countUsable() << std::endl;

//    s1.drawALot();
    (*set.getSharpie(0)).drawALot();

    std::cout << "Number of usable sharpies: " << set.countUsable() << std::endl;


    return 0;
}