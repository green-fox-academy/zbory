#include <iostream>
#include "Carrier.h"
#include "F35.h"
#include "F16.h"

int main()
{

    //Creating carriers and adding plane
    //Carrier 1
    Carrier carrier1(5000, 2300);
    F35 plane1;
    F35 plane2;
    F35 plane3;
    F35 plane4;
    F35 plane5;
    F35 plane6;
    F35 plane11;
    F35 plane12;
    F16 plane13;
    F16 plane14;
    F16 plane15;
    F16 plane16;
    F16 plane17;
    carrier1.addAircraft(&plane1);
    carrier1.addAircraft(&plane2);
    carrier1.addAircraft(&plane3);
    carrier1.addAircraft(&plane4);
    carrier1.addAircraft(&plane5);
    carrier1.addAircraft(&plane6);
    carrier1.addAircraft(&plane11);
    carrier1.addAircraft(&plane12);
    carrier1.addAircraft(&plane13);
    carrier1.addAircraft(&plane14);
    carrier1.addAircraft(&plane15);
    carrier1.addAircraft(&plane16);
    carrier1.addAircraft(&plane17);

    //Carrier 2
    Carrier carrier2(4000, 1800);
    F35 plane7;
    F35 plane8;
    F16 plane9;
    F16 plane10;
    carrier2.addAircraft(&plane7);
    carrier2.addAircraft(&plane8);
    carrier2.addAircraft(&plane9);
    carrier2.addAircraft(&plane10);

    carrier1.getCarrierStatus();
    carrier2.getCarrierStatus();

    std::cout << "\n-----Filling-----";
    carrier1.fill();
    carrier2.fill();

    carrier1.getCarrierStatus();
    carrier2.getCarrierStatus();

    std::cout << "\n-----Battle!-----";

    carrier1.fight(carrier2);
    carrier2.fight(carrier1);

    carrier1.getCarrierStatus();
    carrier2.getCarrierStatus();



    return 0;
}