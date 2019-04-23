//
// Created by zbora on 2019-04-23.
//

#ifndef GREENFOXORGANIZATION_PERSON_H
#define GREENFOXORGANIZATION_PERSON_H

enum Gender {
    MALE,
    FEMALE,
    OTHER
};


class Person {
public:
    Person();

    Person(std::string name, int age, Gender gender);

    virtual void introduce();

    virtual void getGoal();

    virtual std::string getGenderInString() final;

protected:
    std::string name;
    int age;
    Gender gender;
};


#endif //GREENFOXORGANIZATION_PERSON_H
