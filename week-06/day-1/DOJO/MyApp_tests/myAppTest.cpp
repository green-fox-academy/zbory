//
// Created by zbora on 2019-04-25.
//

#include "getIndex.h"
#include "gtest/gtest.h"

TEST(getIndex, getIndex1)
{
    //Arrange
    std::vector<int> vector = {1,2,3,4,5,6,7};

    //Act
    int result = getItemIndex(6, vector);

    //Assert
    ASSERT_EQ(result, 5);
}

TEST(getIndex, getIndex2)
{
    //Arrange
    std::vector<int> vector = {1,6,3,4,5,8,7};

    //Act
    int result = getItemIndex(6, vector);

    //Assert
    ASSERT_EQ(result, 1);
}

TEST(getIndex, notContained1)
{
    //Arrange
    std::vector<int> vector = {1,6,3,4,5,8,7};

    //Act
    int result = getItemIndex(9, vector);

    //Assert
    ASSERT_EQ(result, -1);
}

TEST(getIndex, emptyVector)
{
    //Arrange
    std::vector<int> vector = {};

    //Act
    int result = getItemIndex(9, vector);

    //Assert
    ASSERT_EQ(result, -1);
}

