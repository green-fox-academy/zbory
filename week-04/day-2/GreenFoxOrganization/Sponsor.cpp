//
// Created by zbora on 2019-04-23.
//

#include <iostream>
#include "Sponsor.h"

Sponsor::Sponsor() : Person()
{
    company = "Google";
    hiredStudents = 0;
}

Sponsor::Sponsor(std::string name, int age, Gender gender, std::string company) : Person(name, age, gender)
{
    this->company = company;
    hiredStudents = 0;
}

void Sponsor::introduce()
{
    std::cout << "Hi, I'm " << name << ", a " << age << " year old " << getGenderInString() << " who represents "
              << company << " and hired " << hiredStudents << " students so far." << std::endl;
}

void Sponsor::getGoal()
{
    std::cout << "My goal is: Hire brilliant junior software developers." << std::endl;
}

void Sponsor::hire()
{
    hiredStudents++;
}