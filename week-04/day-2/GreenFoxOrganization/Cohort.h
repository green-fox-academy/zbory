//
// Created by zbora on 2019-04-23.
//


#include "Student.h"
#include "Mentor.h"

#ifndef GREENFOXORGANIZATION_COHORT_H
#define GREENFOXORGANIZATION_COHORT_H


class Cohort {
public:
    Cohort(std::string name);

    void addStudent(Student* student);

    void addMentor(Mentor* mentor);

    void info();

private:
    std::string name;
    std::vector<Student> students;
    std::vector<Mentor> mentors;
};


#endif //GREENFOXORGANIZATION_COHORT_H
