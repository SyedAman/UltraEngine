#include "String.h"

#include <gtest/gtest.h>

TEST(String, ShouldCreateEmptyString)
{
    const String str;
    constexpr std::size_t expected = 0;
    const std::size_t actual = str.Length();
    ASSERT_EQ(actual, expected);
}
TEST(String, ShouldCreateFromStringLiteral)
{
    const String str("hello");
    ASSERT_EQ(str, "hello");
}
TEST(String, ShouldHaveStringComparisons)
{
    const String str("hello");
    // ASSERT_TRUE(str == "hello");
    // ASSERT_TRUE(str != "world");
//     ASSERT_TRUE(str < "world");
//     ASSERT_TRUE(str <= "world");
//     ASSERT_TRUE(str > "a");
//     ASSERT_TRUE(str >= "a");
}
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
