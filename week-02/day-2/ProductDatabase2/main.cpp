#include <iostream>
#include <map>
#include <vector>

std::vector<std::string> belowLimit(std::map<std::string, int> list, int limit);
std::map<std::string, int> aboveLimit(std::map<std::string, int> list, int limit);

int main() {
//We are going to represent our products in a map where the keys are strings representing the product's name and the values are numbers representing the product's price.
//
//Create a map with the following key-value pairs.
//Product name (key)	Price (value)
//Eggs	200
//Milk	200
//Fish	400
//Apples	150
//Bread	50
//Chicken	550

    std::map<std::string, int> products = {{"Eggs",    200},
                                           {"Milk",    200},
                                           {"Fish",    400},
                                           {"Apples",  150},
                                           {"Bread",   50},
                                           {"Chicken", 550}};

    int upper_limit = 201;
    int lower_limit = 150;

    std::cout << "The products below " << upper_limit << " are:" << std::endl;
    std::vector<std::string> result = belowLimit(products, upper_limit);
    for(unsigned int i = 0; i < result.size(); i++){
        std::cout << result[i] << std::endl;
    }

    std::cout << "The products above " << lower_limit << " are:" << std::endl;
    std::map<std::string, int> resultWithPrice = aboveLimit(products, lower_limit);
    std::map<std::string, int>::iterator it;
    for(it = resultWithPrice.begin(); it != resultWithPrice.end(); it++){
        std::cout << it->first  <<", " << it->second << std::endl;
    }

    return 0;
}

std::vector<std::string> belowLimit(std::map<std::string, int> list, int limit) {
    std::vector<std::string> result;
    std::map<std::string, int>::iterator iterator;

    for (iterator = list.begin(); iterator != list.end(); iterator++) {
        if (limit > iterator->second) {
            result.push_back(iterator->first);
        }
    }
    return result;
}
std::map<std::string, int> aboveLimit(std::map<std::string, int> list, int limit) {
    std::map<std::string, int> result;
    std::map<std::string, int>::iterator iterator;

    for (iterator = list.begin(); iterator != list.end(); iterator++) {
        if (limit < iterator->second) {
            result.insert(std::make_pair(iterator->first, iterator->second));
        }
    }
    return result;
}