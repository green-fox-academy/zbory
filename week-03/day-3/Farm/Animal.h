//
// Created by zbora on 2019-04-17.
//

#ifndef ANIMAL_ANIMAL_H
#define ANIMAL_ANIMAL_H


class Animal {
public:
    Animal();
    Animal(int hunger, int thirst);
    void eat();
    void drink();
    void play();
    int getHunger() const;
    int getThirst() const;

private:
    int hunger;
    int thirst;

};


#endif //ANIMAL_ANIMAL_H
