#include <stdio.h>
#include <stdlib.h>
#include "pi.h"

// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that cirle
// area = radius * radius * PI



int main()
{
    float radius;
    printf("Please input the radius of the circle: ");
    scanf("%f", &radius);
    printf("The area of the circle is : %.3f\n", circle_area(radius));
    printf("The circumference of the circle is : %.3f\n", circle_circumference(radius));
    return 0;
}

