// Copyright Syed Aman. All rights reserved.
#pragma once
#include <functional>
#include <iostream>

#define TEST(TestCaseName, TestName) \
    class TestCaseName##_##TestName : public TestBase { \
    public: \
        TestCaseName##_##TestName() { \
            TestRegistry::Instance().AddTest(#TestCaseName "." #TestName, [this]() -> bool { return Run(); }); \
        } \
        bool Run() override; \
    } TestCaseName##_##TestName##_instance; \
    bool TestCaseName##_##TestName::Run()

#define EXPECT_TRUE(condition) \
    return ExpectTrue(condition, #condition, __FILE__, __LINE__)

#define EXPECT_FALSE(condition) \
    return ExpectFalse(condition, #condition, __FILE__, __LINE__)

#define EXPECT_EQ(expected, actual) \
    return ExpectEqual(expected, actual, #expected " == " #actual, __FILE__, __LINE__)

#define EXPECT_NE(expected, actual) \
    return ExpectNotEqual(expected, actual, #expected " != " #actual, __FILE__, __LINE__)

class TestBase
{
public:
    virtual bool Run() = 0;

    bool ExpectTrue(const bool condition, const std::string& expression, const char* file, int line) const
    {
        if (!condition)
        {
            std::cerr << file << ":" << line << ": Failure: expected " << expression << " is false" << std::endl;
            return false;
        }
        return true;
    }
    bool ExpectFalse(const bool condition, const std::string& expression, const char* file, int line) const
    {
        if (condition)
        {
            std::cerr << file << ":" << line << ": Failure: expected " << expression << " is true" << std::endl;
            return false;
        }
        return true;
    }

    template <typename T>
    bool ExpectEqual(T expected, T actual, const std::string& expression, const char* file, int line) const
    {
        if (expected != actual)
        {
            std::cerr << file << ":" << line << ": Failure: expected " << expression << " (" << expected << " vs. " << actual << ")" << std::endl;
            return false;
        }
        return true;
    }

    template <typename T>
    bool ExpectNotEqual(const T expected, const T actual, const std::string& expression, const char* file, int line) const
    {
        if (expected == actual)
        {
            std::cerr << file << ":" << line << ": Failure: expected " << expression << " (" << expected << " vs. " << actual << ")" << std::endl;
            return false;
        }
        return true;
    }
};

class TestRegistry
{
    TestRegistry() = default;
    std::vector<std::pair<std::string, std::function<bool()>>> Tests_;
    
public:
    static TestRegistry& Instance()
    {
        static TestRegistry registry;
        return registry;
    }
    
    void AddTest(const std::string& testName, const std::function<bool()>& testFunction)
    {
        Tests_.emplace_back(testName, testFunction);
    }
    
    void RunAllTests() const
    {
        int passed = 0;
        for (const auto& [testName, testFunction] : Tests_)
        {
            std::cout << "Running test: " << testName << std::endl;
            const bool bPassed = testFunction();
            passed = bPassed ? passed + 1 : passed;
        }

        int total = Tests_.size();

        std::cout << "Passed " << passed << " out of " << total << " tests." << std::endl;
    }
};
