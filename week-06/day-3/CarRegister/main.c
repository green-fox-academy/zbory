#include <string.h>
#include <stdio.h>
#include <time.h>

/* Write a car register!
 * You should store the following data in a structure, called "car":
 *  - the manufacturer's name (which is shorter than 256 characters)
 *  - the price of the car (in euros, stored as a floating point number)
 *  - the year of manufacture
 *  - the type of the transmission (as a custom type, see below)
 *
 * You should store the transmission type in an enumeration ("transmission"),
 * the valid types are:
 *  - manual
 *  - automatic
 *  - CVT
 *  - semi-automatic
 *  - dual-clutch
 *
 * The "car"-s are stored in an array.
 *
 * Write the following functions:
 *  - get_older_cars_than(struct car* array, int array_length, int age)
 *      - it returns the count of the older cars than "age"
 *  - get_transmission_count(struct car* array, int array_length, enum transmission trnsm)
 *      - it returns the count of cars which has "trnsm" transmission
 */

typedef enum transmission {
    MANUAL,
    AUTOMATIC,
    CVT,
    SEMI_AUTOMATIC,
    DUAL_CLUTCH
} Transmission;

typedef struct car {
    char manufacturer[256];
    float price;
    int year_of_manufacture;
    Transmission transmission_type;
} car_t;

int get_older_cars_than(struct car *array, int array_length, int age);

int get_transmission_count(struct car *array, int array_length, Transmission transmission);

int main()
{
    car_t cars[3];
    int size = sizeof(cars) / sizeof(car_t);
    strcpy(cars[0].manufacturer, "Toyota");
    cars[0].price = 1700;
    cars[0].year_of_manufacture = 2002;
    cars[0].transmission_type = MANUAL;

    strcpy(cars[1].manufacturer, "Mazda");
    cars[1].price = 2300;
    cars[1].year_of_manufacture = 2006;
    cars[1].transmission_type = AUTOMATIC;

    strcpy(cars[2].manufacturer, "Nissan");
    cars[2].price = 19000;
    cars[2].year_of_manufacture = 2012;
    cars[2].transmission_type = DUAL_CLUTCH;

    int age = 8;
    printf("Cars older than %d years: %d\n", age, get_older_cars_than(cars, size, age));

    Transmission trans = DUAL_CLUTCH;
    printf("Cars with dual clutch transmission: %d\n", get_transmission_count(cars, size, trans));
    return 0;
}

int get_older_cars_than(struct car *array, int array_length, int age)
{
    int counter = 0;
    time_t current_time = time(NULL);
    struct tm tm = *localtime(&current_time);
    for (int i = 0; i < array_length; ++i) {
        if (((tm.tm_year + 1900) - array[i].year_of_manufacture) > age)
            counter++;
    }
    return counter;
}

int get_transmission_count(struct car *array, int array_length, Transmission transmission)
{
    int counter = 0;
    for (int i = 0; i < array_length; ++i) {
        if (array[i].transmission_type == transmission)
            counter++;
    }
    return  counter;
}