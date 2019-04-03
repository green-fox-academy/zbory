#include <iostream>

int main(int argc, char* args[]) {

    // Modify this program to greet user instead of the World!
    // The program should ask for the name of the user
    std::string userName;
    std::cout << "Please tell me your name: " << std::endl;
    std::cin >> userName;
    std::cout << "Hello " << userName << "!" << std::endl;

    return 0;
}