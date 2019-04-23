//
// Created by zbora on 2019-04-23.
//

#include <iostream>
#include "Person.h"

Person::Person()
{
    name = "Jane Doe";
    age = 30;
    gender = FEMALE;
}

Person::Person(std::string name, int age, Gender gender)
{
    this->name = name;
    this->age = age;
    this->gender = gender;
}

void Person::introduce()
{
    std::cout << "Hi, I'm " << name << ", a " << age << " year old " << getGenderInString() << "." << std::endl;
}

void Person::getGoal()
{
    std::cout << "My goal is: Live for the moment!" << std::endl;
}

std::string Person::getGenderInString()
{
    switch (gender) {
        case 0:
            return "male";
        case 1:
            return "female";
        case 2:
            return "other";
    }
}