//
// Created by zbora on 2019-04-24.
//

#ifndef FLYABLE_VEHICLE_H
#define FLYABLE_VEHICLE_H


class Vehicle {
public:
    Vehicle(int maxAltitude, int maxSpeed, int maxRange);
protected:
    int maxAltitude;
    int maxSpeed;
    int maxRange;
};


#endif //FLYABLE_VEHICLE_H
