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
    const Pair<bool, int> Pair1(true, 1);
    const Pair<bool, int> Pair2(true, 1);

    EXPECT_TRUE(Pair1 == Pair2);
}