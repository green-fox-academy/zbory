#include <iostream>
#include <vector>
#include "printer.h"
#include "printer2d.h"
#include "printer3d.h"
#include "copier.h"

int main( int argc, char* args[] )
{
    // Create a vector that holds Printer* objects
    std::vector<Printer*> devices;
    // Fill the vector with 3 Printer2D, 2 Printer3D and 1 copier.
    Printer3d p3d1(1,2,3);
    Printer3d p3d2(4,5,6);
    Printer3d p3d3(7,8,9);

    Printer2d p2d1(1,2);
    Printer2d p2d2(3,4);

    Copier copier1(1,2,100);

    devices.push_back(&p3d1);
    devices.push_back(&p3d2);
    devices.push_back(&p3d3);
    devices.push_back(&p2d1);
    devices.push_back(&p2d2);
    devices.push_back(&copier1);
    // Iterate through the vector and invoke print function on all of them.
    for (int i = 0; i < devices.size(); ++i) {
        devices[i]->print();
    }

    // Create a vector that holds Scanner* objects
    std::vector<Scanner*> scanners;
    // Fill the vector with 2 Scanner and 2 Copier objects.
    Scanner scn1(90);
    Scanner scn2(120);

    Copier copier2(2,2,120);
    Copier copier3(3,4,110);

    scanners.push_back(&scn1);
    scanners.push_back(&scn2);
    scanners.push_back(&copier2);
    scanners.push_back(&copier3);
    // Iterate through the vector and invoke scan function on all of them
    for (int i = 0; i < scanners.size(); ++i) {
        scanners[i]->scan();
    }

    // Create a Copier object and invoke copy function on it.
    Copier copier4(4,4,200);
    copier4.copy();
}