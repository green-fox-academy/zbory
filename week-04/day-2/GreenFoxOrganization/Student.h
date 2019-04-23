//
// Created by zbora on 2019-04-23.
//

#ifndef GREENFOXORGANIZATION_STUDENT_H
#define GREENFOXORGANIZATION_STUDENT_H

#include "Person.h"

class Student : public Person {
public:
    Student();
    Student(std::string name, int age, Gender gender, std::string previousOrganization);
    void introduce() override;
    void getGoal() override;
    void skipDays(int numberOfDays);
private:
    std::string previousOrganization;
    int skippedDays;
};


#endif //GREENFOXORGANIZATION_STUDENT_H
