#include <iostream>
#include <ctime>

int main()
{
    srand(time(0));
    std::cout << rand() << std::endl;
    return 0;
}