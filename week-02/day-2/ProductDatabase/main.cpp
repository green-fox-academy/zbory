#include <iostream>
#include <map>

std::string max(std::map<std::string, int> list);

std::string min(std::map<std::string, int> list);

double average(std::map<std::string, int> list);

int belowLimit(std::map<std::string, int> list, int limit);

std::string forPrice(std::map<std::string, int> list, int price);

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

    int price = 125;
    int limit = 300;

//    How much is the fish?
//    What is the most expensive product?
//    What is the average price?
//    How many products' price is below 300?
//    Is there anything we can buy for exactly 125?
//    What is the cheapest product?

    std::cout << "Price of fish: " << products.at("Fish") << std::endl;
    std::cout << "The most expensive item is: " << max(products) << std::endl;
    std::cout << "The average price is: " << average(products) << std::endl;
    std::cout << "The number of products below 300 is: " << belowLimit(products, limit) << std::endl;
    std::cout << "Can we find anything for 125: " << forPrice(products, price) << std::endl;
    std::cout << "The cheapest item is: " << min(products) << std::endl;


    return 0;
}

std::string min(std::map<std::string, int> list) {
    std::string key;

    std::map<std::string, int>::iterator iterator = iterator = list.begin();
    int min = iterator->second;
    for (; iterator != list.end(); iterator++) {
        if (min > iterator->second) {
            min = iterator->second;
            key = iterator->first;
        }
    }
    return key;
}

std::string max(std::map<std::string, int> list) {
    std::string key;

    std::map<std::string, int>::iterator iterator = iterator = list.begin();
    int max = iterator->second;
    for (; iterator != list.end(); iterator++) {
        if (max < iterator->second) {
            max = iterator->second;
            key = iterator->first;
        }
    }
    return key;
}

double average(std::map<std::string, int> list) {
    int sum = 0;
    std::map<std::string, int>::iterator iterator;

    for (iterator = list.begin(); iterator != list.end(); iterator++) {
        sum += iterator->second;
    }
    return (double) sum / list.size();
}

int belowLimit(std::map<std::string, int> list, int limit) {
    int count = 0;
    std::map<std::string, int>::iterator iterator;

    for (iterator = list.begin(); iterator != list.end(); iterator++) {
        if (limit > iterator->second) {
            count++;
        }
    }
    return count;
}

std::string forPrice(std::map<std::string, int> list, int price) {
    bool flag = false;
    std::map<std::string, int>::iterator iterator;

    for (iterator = list.begin(); iterator != list.end(); iterator++) {
        if (price == iterator->second) {
            flag = true;
        }
    }
    if(flag){
        return "Yes";
    }else{
        return "No";
    }
}