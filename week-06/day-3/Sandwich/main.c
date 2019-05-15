#include <stdio.h>
#include <string.h>

/*
Create a sandwich struct
It should store:
 - name
 - price (float)
 - weight (float)
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/
typedef struct sandwich{
    char name[30];
    float price;
    float weight;
} sandwich_t;

float sumOrder(sandwich_t *type, int amount);


int main()
{
    sandwich_t sandwich1;
    strcpy(sandwich1.name, "BaconCheese");
    sandwich1.price = 6.5;
    sandwich1.weight = 130;
    printf("Your order costs %.2f golds!", sumOrder(&sandwich1, 5));
    return 0;
}

float sumOrder(sandwich_t *type, int amount){
    return type->price * amount;
}