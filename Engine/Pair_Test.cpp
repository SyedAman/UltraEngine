#include "Pair.h"

#include <gtest/gtest.h>

TEST(Pair, ShouldConstructWithTypeDifferentTypes)
{
    Pair<bool, int> Pair(true, 1);

    EXPECT_EQ(true, Pair.First);
    EXPECT_EQ(1, Pair.Second);
}

