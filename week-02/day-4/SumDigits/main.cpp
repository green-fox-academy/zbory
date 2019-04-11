#include <iostream>

int recursiveSumDigits(int n);

int main()
{
    std::cout << recursiveSumDigits(100001) << std::endl;
    return 0;
}

int recursiveSumDigits(int n)
{
    if (n < 1) return 0;

    return (n % 10) + recursiveSumDigits(n / 10);
}