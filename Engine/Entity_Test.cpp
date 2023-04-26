// Copyright Syed Aman. All Rights Reserved.
#include "Entity.h"

#include "TestingFramework.h"

TEST(Entity, ShouldCreateCreateWithPublicallyAccessibleID)
{
    const Entity entity1(0);
    EXPECT_EQ(entity1.EntityID, 0);

    const Entity entity2(1);
    EXPECT_EQ(entity2.EntityID, 1);
}

TEST(Entity, ShouldCompareEqualityByID)
{
    const Entity entity1(5);
    const Entity entity2(5);
    const Entity entity3(7);

    EXPECT_TRUE(entity1 == entity2);
    EXPECT_FALSE(entity1 == entity3);

    EXPECT_TRUE(entity1 != entity3);
    EXPECT_FALSE(entity1 != entity2);
}

TEST(Entity, ShouldCompareUsingCustomOperators) {
    Entity entity1(1);
    Entity entity2(2);
    Entity entity3(3);
    EXPECT_TRUE(entity1 < entity2);
    EXPECT_FALSE(entity1 > entity2);
    EXPECT_TRUE(entity2 <= entity3);
    EXPECT_TRUE(entity3 >= entity2);
}

TEST(Entity, ShouldCopyConstructWithSameID) {
    Entity entity1(1);
    Entity entity2(entity1);
    EXPECT_EQ(entity1.EntityID, entity2.EntityID);
}

TEST(Entity, ShouldAssignWithSameID) {
    Entity entity1(1);
    Entity entity2(3);
    entity2 = entity1;
    EXPECT_EQ(entity1.EntityID, entity2.EntityID);
}

TEST(Entity, ShouldCompareEqualityForConstAndNonConstEntities) {
    const Entity entity1(1);
    Entity entity2(1);
    const Entity entity3(2);

    EXPECT_TRUE(entity1 == entity2);
    EXPECT_FALSE(entity1 == entity3);

    EXPECT_TRUE(entity1 != entity3);
    EXPECT_FALSE(entity1 != entity2);
}
