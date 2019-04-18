#include <iostream>
#include "Blog.h"

void printPosts(Blog blog);

int main()
{
    Blog blog;
    blog.addPost(BlogPost("Jancsi", "Miert nem?", "Hat azert!", "1996-12-04"));
    blog.addPost(BlogPost("Bela", "Recursion", "And again", "2016-02-24"));
    blog.addPost(BlogPost("Margit", "Cipok", "Tobb kell", "2019-03-15"));

    printPosts(blog);

    blog.deletePost(0);

    printPosts(blog);

    blog.updatePost(1, BlogPost("Bela", "Recursion", "And again, and again", "2019-04-18"));

    printPosts(blog);

    return 0;
}

void printPosts(Blog blog){
    for (int i = 0; i < blog.postCount(); ++i) {
        std::cout << (*blog.getPost(i)).toString() << std::endl;
    }
    std::cout << "======================================================\n";
}