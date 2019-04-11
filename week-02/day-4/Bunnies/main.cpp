#include <iostream>

int recursiveCountBunnyEars(int n);


int main()
{
    std::cout << recursiveCountBunnyEars(39) << std::endl;
    return 0;
}

int recursiveCountBunnyEars(int n)
{
    if (n == 1) return 2;

    return  2 + recursiveCountBunnyEars(n - 1);
}