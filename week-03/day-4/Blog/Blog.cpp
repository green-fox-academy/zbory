//
// Created by zbora on 2019-04-18.
//

#include "Blog.h"

BlogPost *Blog::getPost(int i){
    return &blogPosts[i];
}

void Blog::addPost(BlogPost bp)
{
    blogPosts.push_back(bp);
}

int Blog::postCount(){
    return blogPosts.size();
}

void Blog::deletePost(int i)
{
    blogPosts.erase(blogPosts.begin() + i);
}

void Blog::updatePost(int i, BlogPost bp)
{
    deletePost(i);
    blogPosts.insert(blogPosts.begin() + i, bp);
}