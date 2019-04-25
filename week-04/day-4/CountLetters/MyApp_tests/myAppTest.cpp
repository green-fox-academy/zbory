//
// Created by zbora on 2019-04-25.
//

#include "gtest/gtest.h"
#include "countLetters.h"


TEST(countLetterFunctionTest, CheckWithEmptyString)
{
    //Arrange
    std::string testString = "";
    std::map<char, int> result;

    //Act
    result = countLetters(testString);

    //Assert
    ASSERT_EQ(result.size(), 0);
}

TEST(countLetterFunctionTest, CheckWithBiscuitString)
{
    //Arrange
    std::string testString = "Biscuit";
    std::map<char, int> result;

    //Act
    result = countLetters(testString);

    //Assert
    ASSERT_EQ(result['B'], 1);
    ASSERT_EQ(result['i'], 2);
    ASSERT_EQ(result['s'], 1);
    ASSERT_EQ(result['c'], 1);
    ASSERT_EQ(result['u'], 1);
    ASSERT_EQ(result['t'], 1);
    ASSERT_EQ(result.size(), 6);
}

TEST(countLetterFunctionTest, CheckWithSameLettertString)
{
    //Arrange
    std::string testString = "DDDDD";
    std::map<char, int> result;

    //Act
    result = countLetters(testString);

    //Assert
    ASSERT_EQ(result['D'], 5);

    ASSERT_EQ(result.size(), 1);
}


