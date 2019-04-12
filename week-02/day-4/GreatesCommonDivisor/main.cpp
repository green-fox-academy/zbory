#include <iostream>

int recursiveGreatestCommonDivisor(int a, int b);

int main()
{
    std::cout << recursiveGreatestCommonDivisor(120, 199) << std::endl;
    return 0;
}

int recursiveGreatestCommonDivisor(int a, int b)
{
    if (a % b == 0) return b;

    return recursiveGreatestCommonDivisor(b, a % b);
}