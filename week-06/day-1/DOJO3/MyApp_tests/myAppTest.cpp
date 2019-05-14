//
// Created by zbora on 2019-04-25.
//

#include "gtest/gtest.h"
#include "numberconvert.h"

TEST(numberConverter, test1)
{
    //Arrange
    int value = 745;

    //Act
    std::string result = convertNumber(value);

    //Assert
    ASSERT_EQ("seven hundred and fourty five", result);
}

TEST(numberConverter, test2)
{
    //Arrange
    int value = 746;

    //Act
    std::string result = convertNumber(value);

    //Assert
    ASSERT_EQ("seven hundred and fourty six", result);
}

TEST(numberConverter, test3)
{
    //Arrange
    int value = 756;

    //Act
    std::string result = convertNumber(value);

    //Assert
    ASSERT_EQ("seven hundred and fifty six", result);
}

TEST(numberConverter, test4)
{
    //Arrange
    int value = 856;

    //Act
    std::string result = convertNumber(value);

    //Assert
    ASSERT_EQ("eight hundred and fifty six", result);
}

TEST(numberConverter, test5)
{
    //Arrange
    int value = 6412856;

    //Act
    std::string result = convertNumber(value);

    //Assert
    ASSERT_EQ("six million four hundred and tewlve thousand eight hundred and fifty six", result);
}