#include "TestingFramework.h"

TestRegistry& TestRegistry::Instance()
{
    static TestRegistry registry;
    return registry;
}

void TestRegistry::AddTest(ITest* test)
{
    Tests_.emplace_back(test);
}

void TestRegistry::RunAllTests() const
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

TestRegistry::TestRegistry() = default;

const char* TestRegistry::PluralEnding(const size_t total) const
{
    return total != 1 ? "s" : "";
}

void TestRegistry::OutputTestResults(const size_t total, const int passed) const
{
    const int failed = total - passed;

    cout << endl << "[==========] " << total << " test" << PluralEnding(total) << " ran." << endl;
    cout << "[  PASSED  ] " << passed << " test" << PluralEnding(passed) << "." << endl;
    cout << "[  FAILED  ] " << failed << " test" << PluralEnding(failed) << "." << endl;
}

void TestRegistry::OutputTestPreRun(const string testName) const
{
    cout << "[  RUN  ] " << testName << endl;
}

void TestRegistry::OutputTestPostRun(const bool bPassed, const string testName) const
{
    cout << (bPassed ? "[  PASSED  ] " : "[  FAILED  ] ") << testName << endl;
}

TestBase::TestBase(const string& name): Name(name)
{
    TestRegistry::Instance().AddTest(this);
}

string TestBase::GetName()
{
    return Name;
}

bool TestBase::ExpectTrue(const bool condition, const string& expression, const char* file, int line) const
{
    if (!condition)
    {
        cerr << file << ":" << line << ": Failure: expected " << expression << " is false" << endl;
        return false;
    }
    return true;
}

bool TestBase::ExpectFalse(const bool condition, const string& expression, const char* file, int line) const
{
    if (condition)
    {
        cerr << file << ":" << line << ": Failure: expected " << expression << " is true" << endl;
        return false;
    }
    return true;
}

