

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

    // Add some elements to the dynamic array
    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(3);

    // Clear the dynamic array
    arr.Clear();

    // Check if the Size is now 0
    EXPECT_EQ(arr.Size(), 0);

    // Add another element to the dynamic array
    arr.PushBack(4);

    // Check if the new element is added correctly
    EXPECT_EQ(arr.Size(), 1);
    EXPECT_EQ(arr[0], 4);
    
    DynamicArray<int> arr2(10);
    arr2.PushBack(1);
    arr2.PushBack(2);
    arr2.PushBack(3);
    arr2.Clear();
    // EXPECT_EQ(arr2.Size(), 0);
}

// #include <Windows.h>
// #include <psapi.h>
// #include <iostream>
//
// size_t getMemoryUsage() {
//     // Get the handle to the current process
//     HANDLE processHandle = GetCurrentProcess();
//
//     // Retrieve the process memory information
//     PROCESS_MEMORY_COUNTERS pmc;
//     if (GetProcessMemoryInfo(processHandle, &pmc, sizeof(pmc))) {
//         return pmc.WorkingSetSize;
//     } else {
//         std::cerr << "Failed to get memory usage information." << std::endl;
//         return 0;
//     }
// }

// #include <cstdlib>
//
// TEST(DynamicArrayTest, DestructorTest) {
//     size_t initialMemoryUsage = getMemoryUsage();
//
//     for (int i = 0; i < 1000; ++i) {
//         {
//             DynamicArray<int> arr;
//             for (int j = 0; j < 100; ++j) {
//                 arr.PushBack(j);
//             }
//         } // arr goes out of scope here and its destructor should be called
//     }
//
//     size_t finalMemoryUsage = getMemoryUsage();
//
//     // Check if the memory usage remains stable (allowing for some tolerance)
//     const double tolerance = 1.05; // 5% tolerance
//     EXPECT_LE(finalMemoryUsage, initialMemoryUsage * tolerance);
// }
