#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that cirle
// area = radius * radius * PI

float circle_area(float radius);

int main()
{
    float radius;
    printf("Please input the radius of the circle: ");
    scanf("%f", &radius);
    printf("The area of the circle is : %.3f", circle_area(radius));
    return 0;
}

float circle_area(float radius){
    return radius * radius *PI;
}