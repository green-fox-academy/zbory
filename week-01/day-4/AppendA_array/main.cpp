#include <iostream>
#include <string>

int main(int argc, char *args[]) {

    // - Create an array variable named `animals`
    //   with the following content: `["koal", "pand", "zebr"]`
    // - Add all elements an `"a"` at the end

    std::string animals[] = {"koal", "pand", "zebr"};

    int size = sizeof(animals) / sizeof(animals[0]);

    for (int i = 0; i < size; i++) {
        animals[i] = animals[i] + "a";
        std::cout << animals[i] << std::endl;
    }

    return 0;
}