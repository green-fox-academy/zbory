#include <iostream>
#include <vector>

int main() {
//    Create a list ('List A') which contains the following values
//    Apple, Avocado, Blueberries, Durian, Lychee
    std::vector<std::string> ListA = {"Apple", "Avocado", "Blueberries", "Durian", "Lychee"};

//    Create a new list ('List B') with the values of List A
    std::vector<std::string> ListB;
    std::vector<std::string>::iterator vectorIterator;

    for (vectorIterator = ListA.begin(); vectorIterator != ListA.end(); vectorIterator++) {
        ListB.push_back(*vectorIterator);
    }

//    Print out whether List A contains Durian or not
    for (vectorIterator = ListA.begin(); vectorIterator != ListA.end(); vectorIterator++) {
        if ((*vectorIterator).compare("Durian") == 0) {
            std::cout << "The list contains Durian\n";
        } else if (vectorIterator == ListA.end()) {
            std::cout << "The list does not contains Durian\n";
        }
    }

//    Remove Durian from List B
    for (vectorIterator = ListB.begin(); vectorIterator != ListB.end(); vectorIterator++) {
        if ((*vectorIterator).compare("Durian") == 0) {
            ListB.erase(vectorIterator);
        }
    }
//    Add Kiwifruit to List A after the 4th element
    ListA.insert(ListA.begin() + 5, "KiviFruit");

//    Compare the size of List A and List B
    if (ListA.size() > ListB.size()) {
        std::cout << "List A is bigger\n";
    } else {
        std::cout << "List B is bigger\n";
    }
//    Get the index of Avocado from List A
    for (int i = 0; i < ListA.size(); i++) {
        if (ListA.at(i).compare("Avocado") == 0) {
            std::cout << "index of Avocado: " << i;
        }
    }
//    Get the index of Durian from List B
    for (int i = 0; i < ListB.size(); i++) {
        if (ListB.at(i).compare("Durian") == 0) {
            std::cout << "index of Durian: " << i;
        }
    }
//    Add Passion Fruit and Pummelo to List B in a single statement
    std::vector<std::string> temp = {"Passion Fruit", "Pummelo"};
    ListB.insert(ListB.end(), temp.begin(), temp.end());

    std::cout << std::endl;
    for (vectorIterator = ListB.begin(); vectorIterator != ListB.end(); vectorIterator++) {
        std::cout << (*vectorIterator) << std::endl;
    }

//    Print out the 3rd element from List A
    std::cout << std::endl << ListA.at(2);
    return 0;
}