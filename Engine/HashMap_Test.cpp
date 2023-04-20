// Copyright Syed Aman. All Rights Reserved.
#include "HashMap.h"
#include "String.h"
#include "Pair.h"

#include <gtest/gtest.h>

TEST(HashMap, ShouldCreateWithTemplateForKeyAndValue)
{
    HashMap<int, int> HashMap;
}

TEST(HashMap, ShouldInsertKeyValuePair)
{
    HashMap<int, int> HashMap1;
    HashMap1.Insert(1, 1);
    EXPECT_EQ(HashMap1[1], 1);

    HashMap1.Insert(0, 7);
    EXPECT_EQ(HashMap1[0], 7);

    HashMap<String, Pair<int, String>> HashMap2;
    HashMap2.Insert("Hello", Pair<int, String>(1, "World"));
    EXPECT_EQ(HashMap2["Hello"].First, 1);
}

TEST(HashMap, ShouldUpdateValueForKey) {}
TEST(HashMap, ShouldRemoveKeyValuePair) {}
TEST(HashMap, ShouldGetValueForKey) {}
TEST(HashMap, ShouldReturnIteratorToBegin) {}
TEST(HashMap, ShouldReturnIteratorToEnd) {}
TEST(HashMap, ShouldReturnConstIteratorToBegin) {}
TEST(HashMap, ShouldReturnConstIteratorToEnd) {}
TEST(HashMap, ShouldReturnSizeOfHashMap) {}
TEST(HashMap, ShouldBeEmptyWhenNoElementsArePresent) {}
TEST(HashMap, ShouldClearAllElements) {}
TEST(HashMap, ShouldHandleCollisions) {}
TEST(HashMap, ShouldResizeWhenLoadFactorExceedsThreshold) {}
TEST(HashMap, ShouldReturnIteratorToElementWithKey) {}
TEST(HashMap, ShouldReturnConstIteratorToElementWithKey) {}
TEST(HashMap, ShouldHandleCopyConstruction) {}
TEST(HashMap, ShouldHandleCopyAssignment) {}
TEST(HashMap, ShouldHandleMoveConstruction) {}
TEST(HashMap, ShouldHandleMoveAssignment) {}
TEST(HashMap, ShouldHandleEqualityComparison) {}
TEST(HashMap, ShouldHandleInequalityComparison) {}