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
    for (unsigned int i = 0; i < names.size(); i++) {
        std::cout << "names: " << names.at(i) << std::endl;
    }


    return 0;
}