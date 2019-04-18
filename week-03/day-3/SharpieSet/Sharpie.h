//
// Created by zbora on 2019-04-17.
//

#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H

#include <iostream>

class Sharpie {
public:
    Sharpie(std::string color, float width);
    void use();

    const std::string &getColor() const;

    void setWidth(float &width);

    float getWidth() const;

    float getInkAmount() const;

    void drawALot();



private:
    std::string color;
    float width;
    float inkAmount;
};


#endif //SHARPIE_SHARPIE_H
