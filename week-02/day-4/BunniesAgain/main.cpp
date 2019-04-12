#include <iostream>

int recursiveBunnyEars(int n);

int main()
{
    std::cout << recursiveBunnyEars(100) << std::endl;
    return 0;
}

int recursiveBunnyEars(int n)
{

    if (n == 1) return 2;

    if (n % 2)
        return 2 + recursiveBunnyEars(n - 1);
    else
        return 3 + recursiveBunnyEars(n - 1);
}