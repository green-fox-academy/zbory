#include <stdio.h>
#include <string.h>

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/

typedef struct house {
    char address[70];
    float price;
    int room_amount;
    float floor_area;
} house_t;

int worth_buying(house_t *house);

int to_buy_number(house_t *house_array, int number);

int main()
{
    house_t houses[3];
    int size = sizeof(houses) / sizeof(house_t);
    strcpy(houses[0].address, "Heaven street 7");
    houses[0].price = 200000;
    houses[0].room_amount = 14;
    houses[0].floor_area = 450;

    strcpy(houses[1].address, "Average street 5");
    houses[1].price = 25000;
    houses[1].room_amount = 3;
    houses[1].floor_area = 72;

    strcpy(houses[1].address, "Poor street 1");
    houses[1].price = 8000;
    houses[1].room_amount = 1;
    houses[1].floor_area = 22;

    printf("Houses to buy: %d", to_buy_number(houses, size));

    return 0;
}

int worth_buying(house_t *house)
{
    if (house->price / house->floor_area > 400)
        return 0;
    else
        return 1;
}

int to_buy_number(house_t *house_array, int number)
{
    int count = 0;
    for (int i = 0; i < number - 1; ++i) {
        if (worth_buying(house_array))
            count++;
        house_array++;
    }
}