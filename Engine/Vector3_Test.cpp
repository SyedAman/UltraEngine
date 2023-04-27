// Copyright Syed Aman. All Rights Reserved.
#include "TestingFramework.h"

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

    EXPECT_EQ(vector3, vector3Copy);
    EXPECT_NE(vector3, vector3Different);
}

TEST(Vector3, ShouldDoAddition) {}
TEST(Vector3, ShouldDoSubtraction) {}
TEST(Vector3, ShouldDoMultiplication) {}
TEST(Vector3, ShouldDoDivision) {}
TEST(Vector3, ShouldAccessComponents) {}
TEST(Vector3, ShouldDoDotProduct) {}
TEST(Vector3, ShouldDoCrossProduct) {}

