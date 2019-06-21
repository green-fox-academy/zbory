
#include "pch.h"
#include "../opencvTest/opencvTestHelper.h"

TEST(TestDegree, testZeroDeg)
{
	//Arrange
	int cx = 0;
	int cy = 0;
	int x = 10;
	int y = 0;

	//Act
	float result = getDegree(cx, cy, x, y);

	//Assert
	ASSERT_EQ(result, 0.000000);
}

TEST(TestDegree, testFirstQuarter)
{
	//Arrange
	int cx = 0;
	int cy = 0;
	int x = 10;
	int y = -10;

	//Act
	float result = getDegree(cx, cy, x, y);

	//Assert
	ASSERT_TRUE((result > 44.9) && (result < 45.1));
}

TEST(TestDegree, test90Deg)
{
	//Arrange
	int cx = 0;
	int cy = 0;
	int x = 0;
	int y = -10;

	//Act
	float result = getDegree(cx, cy, x, y);

	//Assert
	ASSERT_EQ(result, 90.000000);
}

TEST(TestDegree, test180Deg)
{
	//Arrange
	int cx = 0;
	int cy = 0;
	int x = -10;
	int y = 0;

	//Act
	float result = getDegree(cx, cy, x, y);

	//Assert
	ASSERT_EQ(result, 180.000000);
}

TEST(TestDegree, test270Deg)
{
	//Arrange
	int cx = 0;
	int cy = 0;
	int x = 0;
	int y = 10;

	//Act
	float result = getDegree(cx, cy, x, y);

	//Assert
	ASSERT_EQ(result, 270.000000);
}

TEST(TestDegree, testSecondQuarter)
{
	//Arrange
	int cx = 0;
	int cy = 0;
	int x = -10;
	int y = -10;

	//Act
	float result = getDegree(cx, cy, x, y);

	//Assert
	ASSERT_TRUE((result > 134.9) && (result < 135.1));
}

TEST(TestDegree, testThirdQuarter)
{
	//Arrange
	int cx = 0;
	int cy = 0;
	int x = -10;
	int y = 10;

	//Act
	float result = getDegree(cx, cy, x, y);

	//Assert
	ASSERT_TRUE((result > 224.9) && (result < 225.1));
}

TEST(TestDegree, testFourthQuarter)
{
	//Arrange
	int cx = 0;
	int cy = 0;
	int x = 10;
	int y = 10;

	//Act
	float result = getDegree(cx, cy, x, y);

	//Assert
	ASSERT_TRUE((result > 314.9) && (result < 315.1));
}