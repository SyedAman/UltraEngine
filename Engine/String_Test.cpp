// Copyright Syed Aman. All Rights Reserved.
#include "String.h"

#include "TestingFramework.h"

TEST(String, ShouldCreateEmptyString)
{
    const String str;
    constexpr std::size_t expected = 0;
    const std::size_t actual = str.Length();
    EXPECT_EQ(actual, expected);
}

TEST(String, ShouldCreateFromStringLiteral)
{
    const String str("hello");
    EXPECT_EQ(str, "hello");
}

TEST(String, ShouldReturnTheNumberOfCharactersInTheString)
{
    const String str1("hello");
    EXPECT_EQ(str1.Length(), 5);

    const String str2("a");
    EXPECT_EQ(str2.Length(), 1);

    const String str3("");
    EXPECT_EQ(str3.Length(), 0);
}   

TEST(String, ShouldReturnPointerToFirstCharacter) {
    const char* cstr = "Hello, World!";
    String str(cstr);
    
    EXPECT_EQ(str.Data()[0], cstr[0]);
}

TEST(String, ShouldCreateCopyOfInputDataWithoutMemoryInTheSameLocation)
{
    const char* cString = "hello";
    const String myString(cString);
    
    EXPECT_EQ(myString, cString);
    EXPECT_NE(myString.Data(), cString);

    // Has null terminator
    EXPECT_EQ(myString.Data()[myString.Length()], '\0');
}

TEST(String, ShouldHaveStringComparisons) {}
TEST(String, ShouldCreateFromStdString) {}
TEST(String, ShouldCreateFromStringObject) {}

TEST(String, ShouldAssignFromStringLiteral) {}
TEST(String, ShouldAssignFromStdString) {}
TEST(String, ShouldAssignFromStringObject) {}

TEST(String, ShouldAppendStringLiteral) {}
TEST(String, ShouldAppendStdString) {}
TEST(String, ShouldAppendStringObject) {}

TEST(String, ShouldEqualStringLiteral) {}
TEST(String, ShouldEqualStdString) {}
TEST(String, ShouldEqualStringObject) {}

TEST(String, ShouldHaveCorrectLength) {}
TEST(String, ShouldHaveCorrectCapacity) {}
TEST(String, ShouldResize) {}
TEST(String, ShouldReserve) {}

TEST(String, ShouldClearString) {}
TEST(String, ShouldInsertString) {}
TEST(String, ShouldEraseSubString) {}

TEST(String, ShouldFindSubstring) {}
TEST(String, ShouldFindCharacter) {}

TEST(String, ShouldConvertToStdString) {}
TEST(String, ShouldConvertToCString) {}

TEST(String, ShouldSupportStreamInsertionOperator) {}
TEST(String, ShouldSupportStreamExtractionOperator) {}
