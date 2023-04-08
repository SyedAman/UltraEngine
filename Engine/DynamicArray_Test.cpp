

#include "DynamicArray.h"

#include <gtest/gtest.h>

TEST(DynamicArray, ShouldConstructWithZeroSize)
{
    DynamicArray<int> Array;
    EXPECT_EQ(0, Array.Size());
}

TEST(DynamicArray, ShouldConstructWithSize)
{
    DynamicArray<int> Array(10);
    EXPECT_EQ(10, Array.Size());
}

TEST(DynamicArray, ShouldPushBack)
{
    DynamicArray<int> Array;
    Array.push_back(1);
    EXPECT_EQ(1, Array[0]);
}

TEST(DynamicArray, ShouldNotHaveMemoryLeaks)
{
    // 
}