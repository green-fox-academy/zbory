#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Create a point struct which has two float variables: x and y
Create a function that constructs a point
It should take it's x and y coordinate as parameter
Create a function that takes 2 points and returns the distance between them
Example:
int main()
{
	point_t p1 = create_point(1, 1);
	point_t p2 = create_point(1, 5.5);
	float dist = distance(p1, p2);
	printf("%f", dist);
	return 0;
}
*/

typedef struct point {
    float x;
    float y;
} point_t;

point_t create_point(float x, float y);

double distance(point_t a, point_t b);

int main()
{
    point_t p1 = create_point(0, 0);
    point_t p2 = create_point(3, 4);
    printf("The distance between these points is %.2lf\n", distance(p1, p2));
    return 0;
}

point_t create_point(float x, float y)
{
    point_t point;
    point.x = x;
    point.y = y;
    return point;
}

double distance(point_t a, point_t b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}