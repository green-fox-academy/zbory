//
// Created by zbora on 2019-04-18.
//

#include "BlogPost.h"

BlogPost::BlogPost(std::string authorName, std::string title, std::string text, std::string publicationDate)
{
    this->authorName = authorName;
    this->title = title;
    this->text = text;
    this->publicationDate = publicationDate;
}

std::string BlogPost::toString()
{
    return authorName + "\n" + title + "\n" + text + "\n" + publicationDate + "\n";
}