#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type {
    VOLVO, TOYOTA, LAND_ROVER, TESLA
};

struct car {
    enum car_type type;
    double km;
    double gas;
};

void printStats(struct car);

int main()
{

    struct car car1;
    car1.type = TOYOTA;
    car1.km = 13000;
    car1.gas = 26;

    struct car car2;
    car2.type = TESLA;
    car2.km = 7000;
    car2.gas = 0;

    printStats(car2);
    printStats(car1);
    return 0;
}

void printStats(struct car car)
{
    printf("This car has %.1lf kilometers on it", car.km);
    if (car.type != TESLA)
        printf(" and %.1lf litres of fuel in the tank\n", car.gas);
    else
        printf(" and it's electric\n", car.gas);
}