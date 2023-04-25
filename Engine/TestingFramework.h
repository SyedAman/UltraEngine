// Copyright Syed Aman. All rights reserved.
#pragma once
#include <iostream>

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
    static TestRegistry& Instance()
    {
        static TestRegistry registry;
        return registry;
    }

    void AddTest(ITest* test)
    {
        Tests_.emplace_back(test);
    }

    void RunAllTests() const
    {
        const size_t total = Tests_.size();
        int passed = 0;
        for (const auto& test : Tests_)
        {
            const string testName = test->GetName();
            OutputTestPreRun(testName);
            
            const bool bPassed = test->Run();

            OutputTestPostRun(bPassed, testName);

            if (bPassed)
            {
                passed++;
            }
        }

        OutputTestResults(total, passed);
    }
    
private:
    TestRegistry() = default;
    
    vector<ITest*> Tests_;

    const char* PluralEnding(const size_t total) const
    {
        return total != 1 ? "s" : "";
    }

    void OutputTestResults(const size_t total, const int passed) const
    {
        const int failed = total - passed;

        cout << endl << "[==========] " << total << " test" << PluralEnding(total) << " ran." << endl;
        cout << "[  PASSED  ] " << passed << " test" << PluralEnding(passed) << "." << endl;
        cout << "[  FAILED  ] " << failed << " test" << PluralEnding(failed) << "." << endl;
    }

    void OutputTestPreRun(const string testName) const
    {
        cout << "[  RUN  ] " << testName << endl;
    }

    void OutputTestPostRun(const bool bPassed, const string testName) const
    {
        cout << (bPassed ? "[  PASSED  ] " : "[  FAILED  ] ") << testName << endl;
    }
};



class TestBase : public ITest
{
public:
    TestBase(const string& name) : Name(name)
    {
        TestRegistry::Instance().AddTest(this);
    }
    
    string GetName() override
    {
        return Name;
    }
    
protected:
    bool ExpectTrue(const bool condition, const string& expression, const char* file, int line) const
    {
        if (!condition)
        {
            cerr << file << ":" << line << ": Failure: expected " << expression << " is false" << endl;
            return false;
        }
        return true;
    }
    bool ExpectFalse(const bool condition, const string& expression, const char* file, int line) const
    {
        if (condition)
        {
            cerr << file << ":" << line << ": Failure: expected " << expression << " is true" << endl;
            return false;
        }
        return true;
    }

    template <typename T>
    bool ExpectEqual(T expected, T actual, const string& expression, const char* file, int line) const
    {
        if (expected != actual)
        {
            cerr << file << ":" << line << ": Failure: expected " << expression << " (" << expected << " vs. " << actual << ")" << endl;
            return false;
        }
        return true;
    }

    template <typename T>
    bool ExpectNotEqual(const T expected, const T actual, const string& expression, const char* file, int line) const
    {
        if (expected == actual)
        {
            cerr << file << ":" << line << ": Failure: expected " << expression << " (" << expected << " vs. " << actual << ")" << endl;
            return false;
        }
        return true;
    }
private:
    string Name;
};
