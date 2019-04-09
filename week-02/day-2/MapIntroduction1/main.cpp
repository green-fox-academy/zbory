#include <iostream>
#include <map>

int main() {
//    We are going to play with maps. Feel free to use the built-in methods where possible.
//    Create an empty map where the keys are integers and the values are characters
    std::map<int, char> myMap;
//    Print out whether the map is empty or not
    std::cout << "empty: " << myMap.empty() << std::endl;
//    Add the following key-value pairs to the map
//    Key	Value
//    97	a
//    98	b
//    99	c
//    65	A
//    66	B
//    67	C
    myMap[97] = 'a';
    myMap[98] = 'b';
    myMap[99] = 'c';
    myMap[65] = 'A';
    myMap[66] = 'B';
    myMap[67] = 'C';

//    Print all the keys
    std::cout << "Keys: " << std::endl;
    std::map<int, char>::iterator mapIterator;

    for (mapIterator = myMap.begin(); mapIterator != myMap.end(); mapIterator++) {
        std::cout << mapIterator->first << std::endl;
    }
//    Print all the values
    std::cout << "Values: " << std::endl;

    for (mapIterator = myMap.begin(); mapIterator != myMap.end(); mapIterator++) {
        std::cout << mapIterator->second << std::endl;
    }

//    Add value D with the key 68
    myMap.insert(std::make_pair(68, 'D'));

//    Print how many key-value pairs are in the map
    std::cout << "key-value pairs: " << myMap.size() << std::endl;

//    Print the value that is associated with key 99
    std::cout << "key 99: " << myMap.at(99) << std::endl;

//    Remove the key-value pair where with key 97
    myMap.erase(97);

//    Print whether there is an associated value with key 100 or not
    if (myMap.count(100) > 0){
        std::cout << "There IS an element with the key 100";
    }else{
        std::cout << "There IS NOT an element with the key 100";
    }

//    Remove all the key-value pairs
        myMap.clear();
    return 0;
}