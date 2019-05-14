//
// Created by zbora on 2019-04-25.
//

#include "gtest/gtest.h"
#include "anagram.h"

TEST(anagramTest, isAnagram1)
{
    //Arrange:
    std::string string1 = "cat";
    std::string string2 = "dog";

    //Act:
    bool result = checkIfAnagram(string1, string2);

    //Assert:
    ASSERT_FALSE(result);
}

TEST(anagramTest, isAnagram2)
{
    //Arrange:
    std::string string1 = "cat";
    std::string string2 = "tac";

    //Act:
    bool result = checkIfAnagram(string1, string2);

    //Assert:
    ASSERT_TRUE(result);
}

TEST(anagramTest, isAnagram3)
{
    //Arrange:
    std::string string1 = "cat";
    std::string string2 = "tictac";

    //Act:
    bool result = checkIfAnagram(string1, string2);

    //Assert:
    ASSERT_FALSE(result);
}

TEST(anagramTest, isAnagram4)
{
    //Arrange:
    std::string string1 = "cat";
    std::string string2 = "tca";

    //Act:
    bool result = checkIfAnagram(string1, string2);

    //Assert:
    ASSERT_TRUE(result);
}