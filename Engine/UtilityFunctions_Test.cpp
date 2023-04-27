// Copyright Syed Aman. All Rights Reserved.
#include "TestingFramework.h"

#include "UtilityFunctions.h"

TEST(Swap, ShouldSwapTwoInts)
{
    int First = 1;
    int Second = 2;

    Swap(First, Second);

    EXPECT_EQ(2, First);
    EXPECT_EQ(1, Second);
}

TEST(Swap, ShouldSpawnTwoElementsInArray)
{
    int Array[] = { 1, 2, 3, 4, 5 };

    Swap(Array[0], Array[1]);

    EXPECT_EQ(2, Array[0]);
    EXPECT_EQ(1, Array[1]);
}

TEST(Less, ShouldReturnTrueWhenLeftIsLessThanRight)
{
    EXPECT_TRUE(Less<int>()(1, 2));
    EXPECT_FALSE(Less<int>()(2,1));
    EXPECT_FALSE(Less<int>()(1,1));
}