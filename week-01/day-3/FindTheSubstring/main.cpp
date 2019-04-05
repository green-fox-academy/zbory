#include <iostream>

bool find_in_string(std::string searchFor, std::string inThis);

int main() {
    std::string sample = "dog goat dad duck doodle never";

    std::cout << find_in_string("never", sample);
    return 0;
}

bool find_in_string(std::string searchFor, std::string inThis) {

    int counter = 0;

    if (searchFor.length() > inThis.length())
        return false;

    for (int i = 0; i < inThis.length(); i++) {
        if (searchFor[counter] == inThis[i]) {
            counter++;
            if (counter == searchFor.length())
                return true;
        } else {
            counter = 0;
        }
        if (i == inThis.length() - 1){
            return false;
        }
    }
}