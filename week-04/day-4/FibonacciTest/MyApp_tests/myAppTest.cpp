//
// Created by zbora on 2019-04-25.
//

#include "gtest/gtest.h"
#include "fibonacci.h"


TEST(FibonacciFunctionTest, number0)
{
    //Arrange
    int numberOfNumber = 0;

    //Act
    int result = fibonacci(numberOfNumber);

    //Assert
    ASSERT_EQ(result, 0);
}

TEST(FibonacciFunctionTest, number10)
{
    //Arrange
    int numberOfNumber = 10;

    //Act
    int result = fibonacci(numberOfNumber);

    //Assert
    ASSERT_EQ(result, 55);
}

TEST(FibonacciFunctionTest, number20)
{
    //Arrange
    int numberOfNumber = 20;

    //Act
    int result = fibonacci(numberOfNumber);

    //Assert
    ASSERT_EQ(result, 6765);
}