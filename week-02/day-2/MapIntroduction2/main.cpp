#include <iostream>
#include <map>

int main() {
//Create a map where the keys are strings and the values are strings with the following initial values
//Key	Value
//978-1-60309-452-8	A Letter to Jo
//978-1-60309-459-7	Lupus
//978-1-60309-444-3	Red Panda and Moon Bear
//978-1-60309-461-0	The Lab

    std::map<std::string, std::string> myMap = {{"978-1-60309-452-8", "A Letter to Jo"},
                                                {"978-1-60309-459-7", "Lupus"},
                                                {"978-1-60309-444-3", "Red Panda and Moon Bear"},
                                                {"978-1-60309-461-0", "The Lab"}};

//    Print all the key-value pairs in the following format
//    A Letter to Jo (ISBN: 978-1-60309-452-8)
//    Lupus (ISBN: 978-1-60309-459-7)
//    Red Panda and Moon Bear (ISBN: 978-1-60309-444-3)
//    The Lab (ISBN: 978-1-60309-461-0)
    std::map<std::string, std::string>::iterator myIterator;

    for (myIterator = myMap.begin(); myIterator != myMap.end(); myIterator++) {
        std::cout << myIterator->second << " (ISBN: " << myIterator->first << ")" << std::endl;
    }

//    Remove the key-value pair with key 978-1-60309-444-3
    myMap.erase("978-1-60309-444-3");

//    Remove the key-value pair with value The Lab
    for (myIterator = myMap.begin(); myIterator != myMap.end(); myIterator++) {
        if (myIterator->second.compare("The Lab") == 0) {
            myMap.erase(myIterator);
        }
    }
    std::cout << std::endl;
    for (myIterator = myMap.begin(); myIterator != myMap.end(); myIterator++) {
        std::cout << myIterator->second << " (ISBN: " << myIterator->first << ")" << std::endl;
    }

//    Add the following key-value pairs to the map
//    Key	Value
//    978-1-60309-450-4	They Called Us Enemy
//    978-1-60309-453-5	Why Did We Trust Him?


    myMap["978-1-60309-450-4"] = "They Called Us Enemy";
    myMap["978-1-60309-453-5"] = "Why Did We Trust Him?";

    std::cout << std::endl;
    for (myIterator = myMap.begin(); myIterator != myMap.end(); myIterator++) {
        std::cout << myIterator->second << " (ISBN: " << myIterator->first << ")" << std::endl;
    }

//    Print whether there is an associated value with key 478-0-61159-424-8 or not
    if (myMap.count("478-0-61159-424-8") == 1) {
        std::cout << "The key appears in the map";
    } else {
        std::cout << "The key does not appear in the map";
    }

//    Print the value associated with key 978-1-60309-453-5
    std::cout << std::endl;
    std::cout << myMap.at("978-1-60309-453-5");
    return 0;
}