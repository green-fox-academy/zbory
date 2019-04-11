#include <iostream>

int recursiveGreatestCommonDivisor(int a, int b);

int main()
{
    std::cout << recursiveGreatestCommonDivisor(36, 6) << std::endl;
    return 0;
}

int recursiveGreatestCommonDivisor(int a, int b)
{
    if (a % b == 0) return b;


    return recursiveGreatestCommonDivisor(b, a % b);
}