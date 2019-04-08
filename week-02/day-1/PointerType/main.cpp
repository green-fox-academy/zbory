#include <iostream>

int main ()
{
    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers

    int a = 31;
    double b = 432.2;
    std::string name = "Bob";

    int *intPointer = &a;
    double *doublePointer = &b;
    std::string *stringPointer = &name;

    std::cout << "variable address: " << &a << ", value of pointer: " << intPointer << std::endl;
    std::cout << "variable address: " << &b << ", value of pointer " << doublePointer << std::endl;
    std::cout << "variable address: " << &name << ", value of pointer " << stringPointer << std::endl;

    return 0;
}