// Copyright Syed Aman. All Rights Reserved.
#include "Pair.h"

#include <gtest/gtest.h>

TEST(Pair, ShouldConstructWithTypeDifferentTypes)
{
    Pair<bool, int> Pair(true, 1);

    EXPECT_EQ(true, Pair.First);
    EXPECT_EQ(1, Pair.Second);
}

TEST(Pair, ShouldSupportEquality)
{
    EXPECT_TRUE(Pair(true,1) == Pair(true,1));
    EXPECT_FALSE(Pair(1, 1) == Pair(1, 2));
}

TEST(Pair, ShouldSupportLessThan)
{
    EXPECT_TRUE(Pair(1,1) < Pair(2,2));
    EXPECT_TRUE(Pair(1,1) < Pair(1,2));
    EXPECT_FALSE(Pair(1,1) < Pair(1,1));
}

TEST(Pair, ShouldSupportGreaterThan)
{
    EXPECT_TRUE(Pair(2,1) > Pair(1,1));
    EXPECT_TRUE(Pair(1,2) > Pair(1,1));
    EXPECT_FALSE(Pair(1,1) > Pair(1,1));
}

TEST(Pair, ShouldSupportLessThanOrEqual)
{
    EXPECT_TRUE(Pair(1,1) <= Pair(2,2));
    EXPECT_TRUE(Pair(1,1) <= Pair(1,2));
    EXPECT_TRUE(Pair(1,1) <= Pair(1,1));
    EXPECT_FALSE(Pair(2,1) <= Pair(1,1));
    EXPECT_FALSE(Pair(1,2) <= Pair(1,1));
}
