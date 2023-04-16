#include "HashMap.h"

#include <gtest/gtest.h>

TEST(HashMap, ShouldCreateWithTemplateForKeyAndValue)
{
    HashMap<int, int> hashMap;
}

TEST(HashMap, ShouldInsertKeyValuePair)
{
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