#include <iostream>

void itemSwapper(int *value1, int *value2);

int main() {
    // Create a function which swaps the values of 'a' and 'b'
    // This time use a void funtion and pointers

    int a = 10;
    int b = 316;

    std::cout << "before: " << a << ", " << b << std::endl;
    itemSwapper(&a, &b);
    std::cout << "after: " << a << ", " << b;

    return 0;
}

void itemSwapper(int *value1, int *value2) {
    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}