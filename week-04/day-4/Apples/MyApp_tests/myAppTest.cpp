//
// Created by zbora on 2019-04-25.
//
#include "apples.h"
#include "gtest/gtest.h"


TEST(AppleFunctionTest, ResultEqualsApple)
{
    //Arrange
    std::string result;

    //Act
    result = getApple();

    //Assert
    ASSERT_STREQ(result.c_str(), "apple");
}
