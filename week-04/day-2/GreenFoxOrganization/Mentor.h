//
// Created by zbora on 2019-04-23.
//

#ifndef GREENFOXORGANIZATION_MENTOR_H
#define GREENFOXORGANIZATION_MENTOR_H

#include "Person.h"

enum Level {
    JUNIOR,
    INTERMEDIATE,
    SENIOR
};

class Mentor : public Person {
public:
    Mentor();

    Mentor(std::string name, int age, Gender gender, Level level);

    void introduce() override;

    void getGoal() override;

    std::string getLevelInString();

private:
    Level level;
};


#endif //GREENFOXORGANIZATION_MENTOR_H
