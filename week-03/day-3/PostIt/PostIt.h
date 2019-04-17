//
// Created by zbora on 2019-04-17.
//

#ifndef POSTIT_POSTIT_H
#define POSTIT_POSTIT_H

#include <iostream>

class PostIt {
    std::string backgroundColor;
    std::string text;
    std::string textColor;
public:
    PostIt(std::string bgColor, std::string text, std::string txColor);
};


#endif //POSTIT_POSTIT_H
