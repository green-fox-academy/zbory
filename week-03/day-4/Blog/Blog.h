//
// Created by zbora on 2019-04-18.
//

#ifndef BLOG_BLOG_H
#define BLOG_BLOG_H

#include <vector>
#include "BlogPost.h"

class Blog {
public:
    BlogPost *getPost(int i);
    void addPost(BlogPost bp);
    int postCount();
    void deletePost(int i);
    void updatePost(int i, BlogPost bp);
private:
    std::vector<BlogPost> blogPosts;
};


#endif //BLOG_BLOG_H
