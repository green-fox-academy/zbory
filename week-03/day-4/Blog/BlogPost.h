//
// Created by zbora on 2019-04-18.
//

#ifndef BLOGPOST_BLOGPOST_H
#define BLOGPOST_BLOGPOST_H

#include <iostream>

class BlogPost {
public:
    BlogPost(std::string authorName, std::string title, std::string text, std::string publicationDate);
    std::string toString();

private:
    std::string authorName;
    std::string title;
    std::string text;
    std::string publicationDate;
};


#endif //BLOGPOST_BLOGPOST_H
