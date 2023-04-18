// Copyright Syed Aman. All rights reserved.
#pragma once
#include <iostream>

class TestingFramework
{
public:
    
};

void ExpectEqual(int expected, int actual)
{
    if (expected != actual)
    {
        std::cerr << "Failure: " << expected << " vs. " << actual << std::endl;
    }
    
}