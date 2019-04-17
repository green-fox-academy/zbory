#include <iostream>
#include <vector>
#include "Car.h"
#include "Station.h"

int main()
{

    Station station(1000);

    std::vector<Car> cars;
    cars.push_back(Car("car1", 23, 100));
    cars.push_back(Car("car2", 45, 100));
    cars.push_back(Car("car3", 10, 100));
    cars.push_back(Car("car4", 56, 100));
    cars.push_back(Car("car5", 86, 100));

    for (int i = 0; i < cars.size(); i++) {
        station.fill(cars[i]);
    }
    return 0;
}

