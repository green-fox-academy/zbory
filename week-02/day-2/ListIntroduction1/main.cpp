#include <iostream>
#include <vector>

int main() {

    //We are going to play with lists. Feel free to use the built-in methods where possible.

    //Create an empty list which will contain names (strings)
    std::vector<std::string> names;
    //Print out the number of elements in the list
    std::cout << "size: " << names.size() << std::endl;
    //Add William to the list
    names.push_back("William");
    //Print out whether the list is empty or not
    std::cout << "empty: " << names.empty() << std::endl;
//    Add John to the list
    names.push_back("John");
//    Add Amanda to the list
    names.push_back("Amanda");
//    Print out the number of elements in the list
    std::cout << "size: " << names.size() << std::endl;
//    Print out the 3rd element
    std::cout << "3rd element: " << names.at(2) << std::endl;
//    Iterate through the list and print out each name
    std::vector<std::string>::iterator vectorIterator;

    for (vectorIterator = names.begin(); vectorIterator != names.end(); vectorIterator++) {
        std::cout << *vectorIterator << std::endl;
    }
//    Iterate through the list and print
//    1. William
//    2. John
//    3. Amanda
    int i = 1;
    for (vectorIterator = names.begin(); vectorIterator != names.end(); vectorIterator++) {
        std::cout << i <<". " << *vectorIterator << std::endl;
        i++;
    }
//    Remove the 2nd element
    names.erase(names.begin() + 1);

//    Iterate through the list in a reversed order and print out each name
    std::vector<std::string>::reverse_iterator reverseVectorIterator;

    for (reverseVectorIterator = names.rbegin(); reverseVectorIterator != names.rend(); reverseVectorIterator++) {
        std::cout << *reverseVectorIterator << std::endl;
    }

//    Remove all elements
    names.clear();

    return 0;
}