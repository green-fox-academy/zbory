#include <stdio.h>

int main()
{
    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // You should get these variables via console input
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000

    double a;
    double b;
    double c;

    printf("Input the sides of the cube (format: a b c): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    printf("Surface area: %.3f\nVolume: %.3f", 2 * (a * b + a * c + b * c), a * b * c);
    return 0;
}