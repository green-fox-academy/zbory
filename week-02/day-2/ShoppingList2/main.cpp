#include <iostream>
#include <map>

double cost(std::map<std::string, double> products, std::map<std::string, int> list);

double checkPrice(std::map<std::string, double> products, std::string item);

int checkQuantity(std::map<std::string, int> list, std::string item);

int numberOfItems(std::map<std::string, int> list);

int numberOfCategories(std::map<std::string, int> list);

int main() {

//    Represent the following products with their prices
//
//    Product	Amount
//    Milk	1.07
//    Rice	1.59
//    Eggs	3.14
//    Cheese	12.60
//    Chicken Breasts	9.40
//    Apples	2.31
//    Tomato	2.58
//    Potato	1.75
//    Onion	1.10
    std::map<std::string, double> products = {{"Milk",            1.07},
                                              {"Rice",            1.59},
                                              {"Eggs",            3.14},
                                              {"Cheese",          12.60},
                                              {"Chicken Breasts", 9.40},
                                              {"Apples",          2.31},
                                              {"Tomato",          2.58},
                                              {"Potato",          1.75},
                                              {"Onion",           1.10}};

//    Product	Amount
//    Milk	3
//    Rice	2
//    Eggs	2
//    Cheese	1
//    Chicken Breasts	4
//    Apples	1
//    Tomato	2
//    Potato	1

    std::map<std::string, int> listBob = {{"Milk",            3},
                                          {"Rice",            2},
                                          {"Eggs",            2},
                                          {"Cheese",          1},
                                          {"Chicken Breasts", 4},
                                          {"Apples",          1},
                                          {"Tomato",          2},
                                          {"Potato",          1}};

//    Product	Amount
//    Rice	1
//    Eggs	5
//    Chicken Breasts	2
//    Apples	1
//    Tomato	10

    std::map<std::string, int> listAlice = {{"Rice",            1},
                                            {"Eggs",            5},
                                            {"Chicken Breasts", 2},
                                            {"Apples",          1},
                                            {"Tomato",          10}};
    //Cost
    std::cout << "Bob pays: " << cost(products, listBob) << std::endl;
    std::cout << "Alice pays: " << cost(products, listAlice) << std::endl;

    //Rice
    if (checkQuantity(listBob, "Rice") > checkQuantity(listAlice, "Rice")) {
        std::cout << "Bob buys more rice" << std::endl;
    } else {
        std::cout << "Alice buys more rice" << std::endl;
    }

    //Potato
    if (checkQuantity(listBob, "Potato") > checkQuantity(listAlice, "Potato")) {
        std::cout << "Bob buys more potato" << std::endl;
    } else {
        std::cout << "Alice buys more potato" << std::endl;
    }

    //Item count
    if (numberOfItems(listBob) > numberOfItems(listAlice)) {
        std::cout << "Bob buys more items" << std::endl;
    } else {
        std::cout << "Alice buys more items" << std::endl;
    }

    //Type of items
    if (numberOfCategories(listBob) > numberOfCategories(listAlice)) {
        std::cout << "Bob buys more types of items" << std::endl;
    } else {
        std::cout << "Alice buys more types of items" << std::endl;
    }
    return 0;
}

double cost(std::map<std::string, double> products, std::map<std::string, int> list) {
    double cost = 0;
    std::map<std::string, int>::iterator iterator;

    for (iterator = list.begin(); iterator != list.end(); iterator++) {
        cost += checkPrice(products, iterator->first) * iterator->second;
    }
    return cost;
}

double checkPrice(std::map<std::string, double> products, std::string item) {
    std::map<std::string, double>::iterator iterator;

    for (iterator = products.begin(); iterator != products.end(); iterator++) {
        if (iterator->first.compare(item) == 0) {
            return iterator->second;
        }
    }
    return 0;
}

int checkQuantity(std::map<std::string, int> list, std::string item) {
    std::map<std::string, int>::iterator iterator;

    for (iterator = list.begin(); iterator != list.end(); iterator++) {
        if (iterator->first.compare(item) == 0) {
            return iterator->second;
        }
    }
    return 0;
}

int numberOfItems(std::map<std::string, int> list) {
    std::map<std::string, int>::iterator iterator;
    int sum = 0;

    for (iterator = list.begin(); iterator != list.end(); iterator++) {
        sum += iterator->second;
    }
    return sum;
}

int numberOfCategories(std::map<std::string, int> list) {
    std::map<std::string, int>::iterator iterator;
    int count = 0;

    for (iterator = list.begin(); iterator != list.end(); iterator++) {
        count++;
    }
    return count;
}


