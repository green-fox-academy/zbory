#include <iostream>

int recursiveNumberAdder(int n);

int main()
{
    std::cout << recursiveNumberAdder(5) << std::endl;
    return 0;
}

int recursiveNumberAdder(int n)
{
    if (n < 1) return 0;

    return n + recursiveNumberAdder(n - 1);
}