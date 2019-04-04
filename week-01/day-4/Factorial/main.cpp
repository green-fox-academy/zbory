#include <iostream>
#include <string>

void factorio(int factorize, int &result);

int main(int argc, char *args[]) {

    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.
    int input = 5;
    int fact_result;

    factorio(input, fact_result);

    std::cout << fact_result;

    return 0;
}

void factorio(int factorize, int &result) {
    int factor = 1;

    for(int i = 1; i <= factorize; i++){
        factor *= i;
    }
    result = factor;
}