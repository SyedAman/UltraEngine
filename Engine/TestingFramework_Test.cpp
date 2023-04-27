#include "TestingFramework.h"

TEST(TestingFramework, ExpectTrue) {
    EXPECT_TRUE(true);
    EXPECT_FALSE(false);
}

TEST(TestingFramework, ExpectFalse) {
    EXPECT_FALSE(false);
    EXPECT_TRUE(true);
}

TEST(TestingFramework, ExpectEqual) {
    int a = 5;
    int b = 5;
    EXPECT_EQ(a, b);
}

TEST(TestingFramework, ExpectNotEqual) {
    int a = 5;
    int b = 6;
    EXPECT_NE(a, b);
}

TEST(TestingFramework, ShouldFailWhenExpectTrueIsFalse)
{
    EXPECT_FAIL(EXPECT_TRUE(false));
}

TEST(TestingFramework, ShouldFailWhenExpectFalseIsTrue)
{
    EXPECT_FAIL(EXPECT_FALSE(true));
}

TEST(TestingFramework, ShouldFailWhenExpectEqualIsNotEqual)
{
    EXPECT_FAIL(EXPECT_EQ(5, 6));
}

TEST(TestingFramework, ShouldFailWhenExpectNotEqualIsEqual)
{
    EXPECT_FAIL(EXPECT_NE(5, 5));
}