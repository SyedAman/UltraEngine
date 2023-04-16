#include "Entity.h"

#include <gtest/gtest.h>

TEST(Entity, ShouldCreateCreateWithPublicallyAccessibleID)
{
    const Entity entity1(0);
    ASSERT_EQ(entity1.EntityID, 0);

    const Entity entity2(1);
    ASSERT_EQ(entity2.EntityID, 1);
}

TEST(Entity, ShouldCompareEqualityByID)
{
    const Entity entity1(5);
    const Entity entity2(5);
    const Entity entity3(7);

    ASSERT_TRUE(entity1 == entity2);
    ASSERT_FALSE(entity1 == entity3);

    ASSERT_TRUE(entity1 != entity3);
    ASSERT_FALSE(entity1 != entity2);
}

TEST(Entity, ShouldCompareUsingCustomOperators) {
    Entity entity1(1);
    Entity entity2(2);
    Entity entity3(3);
    ASSERT_TRUE(entity1 < entity2);
    ASSERT_FALSE(entity1 > entity2);
    ASSERT_TRUE(entity2 <= entity3);
    ASSERT_TRUE(entity3 >= entity2);
}

TEST(Entity, ShouldCopyConstructWithSameID) {
    Entity entity1(1);
    Entity entity2(entity1);
    ASSERT_EQ(entity1.EntityID, entity2.EntityID);
}

TEST(Entity, ShouldAssignWithSameID) {
    Entity entity1(1);
    Entity entity2(3);
    entity2 = entity1;
    ASSERT_EQ(entity1.EntityID, entity2.EntityID);
}

TEST(Entity, ShouldCompareEqualityForConstAndNonConstEntities) {
    const Entity entity1(1);
    Entity entity2(1);
    const Entity entity3(2);

    ASSERT_TRUE(entity1 == entity2);
    ASSERT_FALSE(entity1 == entity3);

    ASSERT_TRUE(entity1 != entity3);
    ASSERT_FALSE(entity1 != entity2);
}
