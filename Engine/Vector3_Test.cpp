#include <gtest/gtest.h>

#include "Vector3.h"


TEST(Vector3, ShouldCreateWithValues)
{
    Vector3 vector3(1.0f, 2.0f, 3.0f);
}

TEST(Vector3, ShouldTestEqualityAndInequality)
{
    Vector3 vector3(1.0f, 2.0f, 3.0f);
    Vector3 vector3Copy(1.0f, 2.0f, 3.0f);
    Vector3 vector3Different(1.0f, 2.0f, 4.0f);

    ASSERT_EQ(vector3, vector3Copy);
    ASSERT_NE(vector3, vector3Different);
}

// ShouldDoAddition

// ShouldDoSubtraction

// ShouldDoMultiplication

// ShouldDoDivision

// ShouldAccessComponents

// ShouldDoDotProduct

// ShouldDoCrossProduct

