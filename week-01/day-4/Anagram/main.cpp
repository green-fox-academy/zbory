#include <iostream>

bool isAnagram(std::string s1, std::string s2);

int main() {

    std::string c1 = "baaaab";
    std::string c2 = "aabbaa";

    if (isAnagram(c1, c2)) {
        std::cout << "They are anagrams.";
    } else {
        std::cout << "They are not anagrams.";
    }

    return 0;
}

//Wont work on words with multiple same letters
bool isAnagram(std::string s1, std::string s2) {
    bool flag = true;
    int size = s1.length();

    if (s1.length() != s2.length())
        return false;

    for (int i = 0; i < size && flag; i++) {
        for (int j = 0; j < size; j++) {
            if (s1[i] == s2[j]) {
                flag = true;
                s2.erase((s2.begin() + j ));
                break;
            } else
                flag = false;
        }
    }
    return flag;
}