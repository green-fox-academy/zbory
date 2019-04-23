//
// Created by zbora on 2019-04-23.
//

#include <iostream>
#include <vector>
#include "Cohort.h"

Cohort::Cohort(std::string name)
{
    this->name = name;
    students.clear();
    mentors.clear();
}

void Cohort::addStudent(Student* student)
{
    students.push_back(*student);
}

void Cohort::addMentor(Mentor* mentor)
{
    mentors.push_back(*mentor);
}

void Cohort::info()
{
    std::cout << "The " << name << " cohort has " << students.size() << " students and " << mentors.size() << " mentors.";
}