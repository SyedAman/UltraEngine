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

    const char* PluralEnding(const size_t total) const
    {
        return total != 1 ? "s" : "";
    }

    void OutputTestResults(const size_t total, const int passed) const
    {
        const int failed = total - passed;

        std::cout << std::endl << "[==========] " << total << " test" << PluralEnding(total) << " ran." << std::endl;
        std::cout << "[  PASSED  ] " << passed << " test" << PluralEnding(passed) << "." << std::endl;
        std::cout << "[  FAILED  ] " << failed << " test" << PluralEnding(failed) << "." << std::endl;
    }

    void OutputTestPreRun(const std::string testName) const
    {
        std::cout << "[  RUN  ] " << testName << std::endl;
    }

    void OutputTestPostRun(const bool bPassed, const std::string testName) const
    {
        std::cout << (bPassed ? "[  PASSED  ] " : "[  FAILED  ] ") << testName << std::endl;
    }

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
        const size_t total = Tests_.size();
        int passed = 0;
        for (const auto& [testName, testFunction] : Tests_)
        {
            OutputTestPreRun(testName);
            const bool bPassed = testFunction();
            OutputTestPostRun(bPassed, testName);
            passed = bPassed ? passed + 1 : passed;
        }

        OutputTestResults(total, passed);
    }
};
