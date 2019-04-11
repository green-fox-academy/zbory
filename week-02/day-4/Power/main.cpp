#include <iostream>

int recursivePowerN(int base, int power);

int main()
{
    std::cout << recursivePowerN(2, 12) << std::endl;
    return 0;
}

int recursivePowerN(int base, int power)
{
    if (power < 1) return 1;

    return base * recursivePowerN(base, power - 1);
}