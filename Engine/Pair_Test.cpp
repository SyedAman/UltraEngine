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

TEST(Pair, ShouldSupportLessThan)
{
    const Pair<int, int> Pair1(1, 1);
    const Pair<int, int> Pair2(2, 1);

    EXPECT_TRUE(Pair1 < Pair2);
}

TEST(Pair, ShouldSupportGreaterThan)
{
    const Pair<int, int> Pair1(2, 1);
    const Pair<int, int> Pair2(1, 1);

    EXPECT_TRUE(Pair1 > Pair2);
}
