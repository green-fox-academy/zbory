//
// Created by zbora on 2019-04-24.
//

#ifndef ANIMALSINTHEZOO_ANIMAL_H
#define ANIMALSINTHEZOO_ANIMAL_H


#include <string>

class Animal {
public:
    Animal(std::string name);

    std::string getName();

    virtual std::string breed() = 0;

    virtual std::string feed() = 0;

    virtual std::string hunt() = 0;

protected:
    std::string name;
    int age;
    double weight;
    bool carnivore;
};


#endif //ANIMALSINTHEZOO_ANIMAL_H
