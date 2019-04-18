//
// Created by zbora on 2019-04-18.
//

#ifndef PIRATES_PIRATE_H
#define PIRATES_PIRATE_H



class Pirate {
public:
    Pirate();
    Pirate(std::string name);
    std::string getName();
    int getIntoxicationLevel();
    bool isAlive();
    bool isConscious();
    void setPassedOut(bool state);
    void drinkSomeRum();
    void howsItGoingMate();
    void die();
    void brawl(Pirate pirate);
    std::string toString();

private:
    std::string name;
    bool passedOut;
    bool alive;
    int intoxicationLevel;
};


#endif //PIRATES_PIRATE_H
