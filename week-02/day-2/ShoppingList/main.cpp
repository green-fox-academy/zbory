#include <iostream>
#include <vector>

bool isOnTheList(std::vector<std::string> list, std::string element);

int main() {
//    Create a list with the following items.
//    Eggs, milk, fish, apples, bread and chicken

    std::vector<std::string> shoppingList = {"eggs", "milk", "fish", "apples", "bread", "chicken"};

//    Do we have milk on the list?
//    Do we have bananas on the list?
    std::cout << "Milk " << (isOnTheList(shoppingList, "milk") ? "is" : "is not") << " and banana "
                                            << (isOnTheList(shoppingList, "banana") ? "is" : "is not") << " on the list.";

}

bool isOnTheList(std::vector<std::string> list, std::string element){
    std::vector<std::string>::iterator listIterator;

    for(listIterator = list.begin(); listIterator != list.end(); listIterator++){
        if((*listIterator).compare(element) == 0){
            return true;
        }
    }
    return false;
}