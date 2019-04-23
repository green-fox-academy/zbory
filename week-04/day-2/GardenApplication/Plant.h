//
// Created by zbora on 2019-04-23.
//

#ifndef GARDENAPPLICATION_PLANT_H
#define GARDENAPPLICATION_PLANT_H


class Plant {
public:
    Plant(std::string color, std::string type);
    double getWaterLevel();
    virtual bool needsWater();
    virtual void toWater(double waterAmount);
    void printPlantState();
protected:
    std::string color;
    std::string type;
    double waterLevel;
};


#endif //GARDENAPPLICATION_PLANT_H
