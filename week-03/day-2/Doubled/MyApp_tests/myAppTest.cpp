//
// Created by zbora on 2019-04-25.
//
#include "doubled.h"
#include "gtest/gtest.h"


TEST(decryptLineFunctionTest, test1)
{
    //Arrange
    std::string testString = "TThhee  ZZeenn  ooff  PPyytthhoonn";

    //Act
    std::string resultString = decryptLine(testString);

    //Assert
    ASSERT_EQ(resultString, "The Zen of Python\n");

}