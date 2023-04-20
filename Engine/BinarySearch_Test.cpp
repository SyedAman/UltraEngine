// Copyright Syed Aman. All Rights Reserved.

#include <gtest/gtest.h>

#include "DynamicArray.h"
#include "BinarySearch.h"

TEST(BinarySearch, ShouldSearchCorrectIndex)
{
    const DynamicArray SortedArray = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    constexpr int TargetValue = 5;
    constexpr int ExpectedIndex = 4;

    const size_t ActualIndex = Algorithms::BinarySearch(SortedArray.Data(), SortedArray.Size(), TargetValue);
    EXPECT_EQ(ExpectedIndex, ActualIndex);
}

TEST(BinarySearch, ShouldSearchCorrectIndexWithProjection)
{
    const DynamicArray SortedArray = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    constexpr int TargetValue = 20;
    constexpr int ExpectedIndex = 9; // Since value 10 at index 9 will be multiplied by 2 and will be 20

    const size_t ActualIndex2 = Algorithms::BinarySearch(SortedArray.Data(), SortedArray.Size(), TargetValue, [](const int& Value) { return Value * 2; }, Less<int>());
    EXPECT_EQ(ActualIndex2, ExpectedIndex);
}

TEST(BinarySearch, ShouldSearchOtherTypes)
{
    const DynamicArray SortedArray = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f };
    constexpr float TargetValue = 5.0f;
    constexpr int ExpectedIndex = 4;

    const size_t ActualIndex = Algorithms::BinarySearch(SortedArray.Data(), SortedArray.Size(), TargetValue);
    EXPECT_EQ(ExpectedIndex, ActualIndex);

    const DynamicArray<char> SortedCharArray = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
    constexpr char TargetChar = 'e';
    constexpr int ExpectedCharIndex = 4;

    const size_t ActualCharIndex = Algorithms::BinarySearch(SortedCharArray.Data(), SortedCharArray.Size(), TargetChar);
    EXPECT_EQ(ExpectedCharIndex, ActualCharIndex);
}