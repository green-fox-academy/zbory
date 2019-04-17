#include <iostream>

#include "fleet.h"

int main(int argc, char *args[])
{
    Fleet fleet;
    // Create a fleet of things to have this output:
    // 1. [ ] Get milk
    // 2. [ ] Remove the obstacles
    // 3. [x] Stand up
    // 4. [x] Eat lunch

    Thing t1("Stand up");
    Thing t2("Eat lunch");

    t1.complete();
    t2.complete();

    fleet.add(Thing("Get milk"));
    fleet.add(Thing("Remove the obstacles"));
    fleet.add(t1);
    fleet.add(t2);
    
    fleet.toString();

    std::cout << fleet.toString() << std::endl;
    return 0;
}