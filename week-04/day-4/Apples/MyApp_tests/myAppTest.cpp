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

TEST(SumFunctionTest, TestSumElements)
{
    //Arrange
    std::vector<int> testVector = {1, 2, 3, 4};
    int result;

    //Act
    result = sum(testVector);

    //Assert
    ASSERT_EQ(result, 10);

}

TEST(SumFunctionTest, TestEmptyVector)
{
    //Arrange
    std::vector<int> testVector; // = {1, 2, 3, 4};
    int result;

    //Act
    result = sum(testVector);

    //Assert
    ASSERT_EQ(result, 0);

}

TEST(SumFunctionTest, Test1Element)
{
    //Arrange
    std::vector<int> testVector = {42};
    int result;

    //Act
    result = sum(testVector);

    //Assert
    ASSERT_EQ(result, 42);

}

TEST(SumFunctionTest, TestNegativeElements)
{
    //Arrange
    std::vector<int> testVector = {-42, -10, -8};
    int result;

    //Act
    result = sum(testVector);

    //Assert
    ASSERT_EQ(result, -60);

}