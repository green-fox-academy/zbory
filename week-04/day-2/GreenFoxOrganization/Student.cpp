//
// Created by zbora on 2019-04-23.
//

#include <iostream>
#include "Student.h"


Student::Student() :Person(){
    previousOrganization = " The School of Life";
    skippedDays = 0;
}

Student::Student(std::string name, int age, Gender gender, std::string previousOrganization) :Person(name, age, gender){
    this->previousOrganization = previousOrganization;
    skippedDays = 0;
};

void Student::introduce()
{
    std::cout << "Hi, I'm " <<name << ", a " << age << "year old " << getGenderInString()
    << " from " << previousOrganization  << " who skipped " << skippedDays << " days from the course already." << std::endl;
}

void Student::getGoal()
{
    std::cout << "My goal is: Be a junior software developer." << std::endl;
}

void Student::skipDays(int numberOfDays)
{
    skippedDays += numberOfDays;
}