//
// Created by zbora on 2019-04-25.
//
#include "anagram.h"
#include "gtest/gtest.h"


TEST(BubbleSortTest, TestSorting)
{
    //Arrange
    std::string testString = "edcba";

    //Act
    std::string result = bubbleSort(testString);

    //Assert
    ASSERT_STREQ(result.c_str(), "abcde");
}

TEST(isAnagramTest, TestIfAnagramStrings){
    //Arrange
    std::string testString1 = "god";
    std::string testString2 = "dog";

    //Act
    bool result = isAnagram(testString1,testString2);

    //Assert
    ASSERT_EQ(result, true);
}

TEST(isAnagramTest, TestIfNotAnagramStrings){
    //Arrange
    std::string testString1 = "god";
    std::string testString2 = "dad";

    //Act
    bool result = isAnagram(testString1,testString2);

    //Assert
    ASSERT_EQ(result, false);
}