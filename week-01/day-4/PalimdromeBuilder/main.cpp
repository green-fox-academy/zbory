#include <iostream>

std::string palindrome(std::string s1);

int main() {

    std::string base = "green";

    std::cout << palindrome(base);
    return 0;
}

std::string palindrome(std::string s1) {
    int length = s1.length();
    std::string temp = "";

    for (int i = 0; i < length; i++) {
        temp = temp + s1[length - 1 - i];
    }
    return s1 + temp;
}