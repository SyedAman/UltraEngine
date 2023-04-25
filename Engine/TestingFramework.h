﻿// Copyright Syed Aman. All rights reserved.
#pragma once
#include <iostream>
#include <vector>

using namespace std;


#define TEST(TestCaseName, TestName) \
    class TestCaseName##_##TestName : public TestBase { \
    public: \
        TestCaseName##_##TestName() : TestBase(#TestCaseName "." #TestName) {} \
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


class ITest
{
public:
    virtual ~ITest() = default;
    virtual bool Run() = 0;
    virtual string GetName() = 0;
};


class TestRegistry
{
public:
    static TestRegistry& Instance();
    void AddTest(ITest* test);
    void RunAllTests() const;

private:
    TestRegistry();
    vector<ITest*> Tests_;
    
    const char* PluralEnding(const size_t total) const;
    void OutputTestResults(const size_t total, const int passed) const;
    void OutputTestPreRun(const string testName) const;
    void OutputTestPostRun(const bool bPassed, const string testName) const;
};


class TestBase : public ITest
{
public:
    TestBase(const string& name);
    string GetName() override;

protected:
    bool ExpectTrue(const bool condition, const string& expression, const char* file, int line) const;
    bool ExpectFalse(const bool condition, const string& expression, const char* file, int line) const;

    template <typename T, typename EqualityComparator = std::equal_to<T>, std::enable_if_t<!std::is_same_v<EqualityComparator, void>, int> = 0>
    bool ExpectEqual(T expected, T actual, const string& expression, const char* file, int line) const
    {
        EqualityComparator comparator;
        if (!comparator(expected, actual))
        {
            OutputExceptionFailed<T>(expected, actual, expression, file, line);
            return false;
        }
        return true;
    }

    template <typename T, typename EqualityComparator = std::equal_to<T>,
              std::enable_if_t<std::is_same_v<EqualityComparator, void>, int> = 0>
    bool ExpectEqual(T expected, T actual, const string& expression, const char* file, int line) const
    {
        cerr << file << ":" << line << ": Failure: No suitable comparator found for the type '" << typeid(T).name() << "'" << endl;
        return false;
    }

    template <typename T>
    bool ExpectNotEqual(const T expected, const T actual, const string& expression, const char* file,
        int line) const
    {
        if (expected == actual)
        {
            OutputExceptionFailed<T>(expected, actual, expression, file, line);
            return false;
        }
        return true;
    }

private:
    string Name;

    template <typename T>
    void OutputExceptionFailed(const T expected, const T actual, const string& expression, const char* file, int line) const
    {
        cerr << file << ":" << line << ": Failure: expected " << expression << endl;
    }
};
