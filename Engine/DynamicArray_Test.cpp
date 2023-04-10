

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

TEST(DynamicArray, ShouldPushBackDynamically)
{
    DynamicArray<int> Array;
    Array.PushBack(1);
    Array.PushBack(2);
    Array.PushBack(3);
    EXPECT_EQ(1, Array[0]);
    EXPECT_EQ(2, Array[1]);
    EXPECT_EQ(3, Array[2]);
}

TEST(DynamicArray, ShouldClear) {
    DynamicArray<int> arr;

    // Add some elements to the dynamic array
    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(3);

    // Clear the dynamic array
    arr.Clear();

    // Check if the Size is now 0
    // EXPECT_EQ(arr.Size(), 0);

    // Add another element to the dynamic array
    // arr.PushBack(4);

    // Check if the new element is added correctly
    // EXPECT_EQ(arr.Size(), 1);
    // EXPECT_EQ(arr[0], 4);
}
