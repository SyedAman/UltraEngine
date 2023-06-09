// Copyright Syed Aman. All Rights Reserved.
#include <Windows.h>
#include <psapi.h>
#include <iostream>
#include "TestingFramework.h"

#include "DynamicArray.h"
#include "Pair.h"


TEST(DynamicArray, ShouldConstructWithZeroSize)
{
    DynamicArray<int> Array;
    EXPECT_EQ(0, Array.Size());
}

TEST(DynamicArray, ShouldConstructWithSize)
{
    DynamicArray<int> Array(10);
    EXPECT_EQ(0, Array.Size());
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

    EXPECT_EQ(Array.Size(), 3);
}

TEST(DynamicArray, ShouldClear) {
    DynamicArray<int> arr;
    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(3);

    arr.Clear();
    EXPECT_EQ(arr.Size(), 0);

    // Check to see if the array is usable
    for (int i = 0; i < 6; ++i) {
        arr.PushBack(i);
    }
    EXPECT_EQ(arr.Size(), 6);
}

size_t GetMemoryUsage() {
    HANDLE ProcessHandle = GetCurrentProcess();

    PROCESS_MEMORY_COUNTERS ProcessMemoryInformation;
    if (GetProcessMemoryInfo(ProcessHandle, &ProcessMemoryInformation, sizeof(ProcessMemoryInformation)))
    {
        return ProcessMemoryInformation.WorkingSetSize;
    }
    
    std::cerr << "Failed to get memory usage information." << std::endl;
    return 0;
}

TEST(DynamicArray, ShouldNotLeakMemory) {
    size_t initialMemoryUsage = GetMemoryUsage();

    for (int i = 0; i < 1000; ++i) {
        {
            DynamicArray<int> arr;
            for (int j = 0; j < 1000; ++j) {
                arr.PushBack(j);
            }
        } // arr goes out of scope here and its destructor should be called
    }

    size_t finalMemoryUsage = GetMemoryUsage();

    // Check if the memory usage remains stable (allowing for some tolerance)
    const double tolerance = 1.01; // 1% tolerance
    EXPECT_LE(finalMemoryUsage, initialMemoryUsage * tolerance);
}

TEST(DynamicArray, ShouldReturnReferenceToFirstElementWhenFrontIsCalled) {
    DynamicArray<Pair<int,int>> arr;

    // Add some elements to the array
    Pair<int,int> p1(5,3);
    arr.PushBack(p1);
    arr.PushBack({4,3});
    arr.PushBack({5,6});

    // Test the Front() method
    Pair<int,int>& FirstElement = arr.Front();
    EXPECT_EQ(FirstElement, p1);
    
    // Modify the first element using the Front() method
    Pair<int,int> pNew(0, 0);
    FirstElement = pNew;
    
    // Check if the first element has been modified
    EXPECT_EQ(FirstElement, pNew);
    EXPECT_EQ(arr[0], pNew);
}

TEST(DynamicArray, Empty)
{
    DynamicArray<int> arr;
    EXPECT_TRUE(arr.Empty());
    arr.PushBack(1);
    EXPECT_FALSE(arr.Empty());
}

TEST(DynamicArray, PopBack)
{
    DynamicArray<int> arr;
    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(3);
    arr.PopBack();
    EXPECT_EQ(arr.Size(), 2);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
}

TEST(DynamicArray, ConstBracketOperator)
{
    DynamicArray<int> arr;
    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(3);
    const DynamicArray<int>& constArr = arr;
    EXPECT_EQ(constArr[0], 1);
    EXPECT_EQ(constArr[1], 2);
    EXPECT_EQ(constArr[2], 3);
}

TEST(DynamicArray, BeginAndBeginConst)
{
    DynamicArray<int> arr;
    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(3);
    EXPECT_EQ(*arr.begin(), 1);

    const DynamicArray<int>& constArr = arr;
    EXPECT_EQ(*constArr.begin(), 1);
}

TEST(DynamicArray, EndAndEndConst)
{
    DynamicArray<int> arr;
    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(3);
    EXPECT_EQ(*(arr.end() - 1), 3);

    const DynamicArray<int>& constArr = arr;
    EXPECT_EQ(*(constArr.end() - 1), 3);

    // Works for other types too
    DynamicArray<Pair<int, int>> arr2;
    arr2.PushBack({ 1, 2 });
    arr2.PushBack({ 3, 4 });
    arr2.PushBack({ 5, 6 });
    EXPECT_EQ((arr2.end() - 1)->First, 5);
}

TEST(DynamicArray, RangedFor)
{
    DynamicArray<int> arr;
    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(3);

    int sum = 0;
    for (int i : arr) {
        sum += i;
    }
    EXPECT_EQ(sum, 6);
}

TEST(DynamicArray, SupportsInitializerList)
{
    DynamicArray<int> arr = { 1, 2, 3 };
    EXPECT_EQ(arr.Size(), 3);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);

    DynamicArray<Pair<int, int>> arr2 = { {1, 2}, {3, 4}, {5, 6} };
    EXPECT_EQ(arr2.Size(), 3);
    EXPECT_EQ(arr2[0].First, 1);
    
    DynamicArray<Pair<int, int>> arr3 = {};
}

TEST(DynamicArray, GetData)
{
    DynamicArray<int> arr = { 1, 2, 3 };
    int* data = arr.Data();
    EXPECT_EQ(data[0], 1);
    EXPECT_EQ(data[1], 2);
    EXPECT_EQ(data[2], 3);
}