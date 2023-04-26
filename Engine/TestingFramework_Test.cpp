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

class ExampleTest_ShouldFail : public TestBase
{
public:
    ExampleTest_ShouldFail() : TestBase("ExampleTest_ShouldFail") {}
    
    void Run() override
    {
        RunTest();
    }

    void RunTest()
    {
        EXPECT_TRUE(false);
    }
};

TEST(TestingFramework, ShouldFailWhenExpectTrueIsFalse)
{
    ExampleTest_ShouldFail test;
    test.Run();
    EXPECT_EQ(test.Passed(), false);
}