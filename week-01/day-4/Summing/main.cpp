#include <iostream>
#include <string>

int sum(int limit);

int main(int argc, char *args[]) {

    // Write a function called `sum` that returns the sum of numbers from zero to the given parameter
    int parameter  = 20;
    std::cout << sum(parameter);

    return 0;
}

int sum(int limit) {
    int sum = 0;

    for (int i = 0; i <= limit; i++) {
        sum += i;
    }
    return sum;
}