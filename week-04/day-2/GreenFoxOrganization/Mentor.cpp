//
// Created by zbora on 2019-04-23.
//

#include "iostream"
#include "Mentor.h"

Mentor::Mentor() :Person(){
    level = INTERMEDIATE;
};

Mentor::Mentor(std::string name, int age, Gender gender, Level level) :Person(name, age, gender){
    this->level = level;
}

void Mentor::introduce()
{
    std::cout << "Hi, I'm " << name << ", a " << age <<" year old " << getGenderInString() << " " << getLevelInString() <<  " mentor." << std::endl;
}

void Mentor::getGoal()
{
    std::cout << "My goal is: Educate brilliant junior software developers." << std::endl;
}

std::string Mentor::getLevelInString()
{
    switch (level){
        case 0: return "junior";
        case 1: return "intermediate";
        case 2: return "senior";
    }
}