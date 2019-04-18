//
// Created by zbora on 2019-04-17.
//

#include "Sharpie.h"

Sharpie::Sharpie(std::string color, float width)
{
    this->color = color;
    this->width = width;
    this->inkAmount = 100;
}

void Sharpie::use(){
    inkAmount -= 5;
}

const std::string &Sharpie::getColor() const
{
    return color;
}

float Sharpie::getWidth() const
{
    return width;
}

void Sharpie::setWidth(float &width){
    this->width = width;
}

float Sharpie::getInkAmount() const
{
    return inkAmount;
}

void Sharpie::drawALot()
{
    inkAmount = 0;
}