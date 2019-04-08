#include <iostream>

int main()
{
    // Add two numbers using pointers

    int a = 20;
    int b = 17;

    int *aPointer = &a;
    int *bPointer = &b;

    int c = *aPointer + *bPointer;

    std::cout << c;

    return 0;
}