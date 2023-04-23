// Copyright Syed Aman. All rights reserved.
#pragma once
#include <functional>
#include <iostream>

#define TEST(test_case_name, test_name) \
    class test_case_name##_##test_name : public TestBase { \
    public: \
        test_case_name##_##test_name() { \
            TestRegistry::instance().AddTest(#test_case_name "." #test_name, std::bind(&test_case_name##_##test_name::Run, this)); \
        } \
        void Run() override; \
    } test_case_name##_##test_name##_instance; \
    void test_case_name##_##test_name::Run()

#define EXPECT_TRUE(condition) \
    ExpectTrue(condition, #condition, __FILE__, __LINE__)

#define EXPECT_FALSE(condition) \
    ExpectFalse(condition, #condition, __FILE__, __LINE__)

#define EXPECT_EQ(expected, actual) \
    ExpectEqual(expected, actual, #expected " == " #actual, __FILE__, __LINE__)

#define EXPECT_NE(expected, actual) \
    ExpectNotEqual(expected, actual, #expected " != " #actual, __FILE__, __LINE__)

class TestBase
{
public:
    virtual void Run() = 0;

    void ExpectTrue(bool condition, const std::string& expression, const char* file, int line)
    {
        if (!condition)
        {
            std::cerr << file << ":" << line << ": Failure: " << expression << " is false" << std::endl;
        }
    }
    void ExpectFalse(bool condition, const std::string& expression, const char* file, int line)
    {
        if (condition)
        {
            std::cerr << file << ":" << line << ": Failure: " << expression << " is true" << std::endl;
        }
    }
    void ExpectEqual(int expected, int actual, const std::string& expression, const char* file, int line)
    {
        if (expected != actual)
        {
            std::cerr << file << ":" << line << ": Failure: " << expression << " (" << expected << " vs. " << actual << ")" << std::endl;
        }
    }
    void ExpectNotEqual(const int expected, const int actual, const std::string& expression, const char* file, int line)
    {
        if (expected == actual)
        {
            std::cerr << file << ":" << line << ": Failure: " << expression << " (" << expected << " vs. " << actual << ")" << std::endl;
        }
    }
};

class TestRegistry
{
    TestRegistry() = default;
    std::vector<std::pair<std::string, std::function<void()>>> tests_;
    
public:
    static TestRegistry& instance()
    {
        static TestRegistry registry;
        return registry;
    }
    
    void AddTest(const std::string& test_name, const std::function<void()>& test_function)
    {
        tests_.emplace_back(test_name, test_function);
    }
    
    void RunAllTests()
    {
        int passed = 0;
        int total = tests_.size();
        for (const auto& test : tests_)
        {
            std::cout << "Running test: " << test.first << std::endl;
            test.second();
            passed++;
        }
        std::cout << "Passed " << passed << " out of " << total << " tests." << std::endl;
    }
};
