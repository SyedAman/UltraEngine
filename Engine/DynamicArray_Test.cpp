#include <Windows.h>
#include <psapi.h>
#include <iostream>
#include <gtest/gtest.h>

#include "DynamicArray.h"


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
