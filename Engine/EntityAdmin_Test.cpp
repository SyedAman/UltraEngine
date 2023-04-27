// Copyright Syed Aman. All Rights Reserved.
#include "EntityAdmin.h"
#include "TestingFramework.h"

TEST(EntityAdmin, ShouldCreate)
{
    EntityAdmin entityAdmin;
}

TEST(EntityAdmin, ShouldCreateWithEmptyComponentsArray)
{
    EntityAdmin entityAdmin;
    EXPECT_TRUE(entityAdmin.components.Empty());
}

TEST(EntityAdmin, ShouldAddComponentToEntity) {}
TEST(EntityAdmin, ShouldRemoveComponentFromEntity) {}
TEST(EntityAdmin, ShouldQueryEntityForComponent) {}
TEST(EntityAdmin, ShouldGetComponentFromEntity) {}
TEST(EntityAdmin, ShouldAddMultipleComponentsToEntity) {}
TEST(EntityAdmin, ShouldRemoveAllComponentsFromEntity) {}
TEST(EntityAdmin, ShouldGetAllEntitiesWithComponent) {}
TEST(EntityAdmin, ShouldGetAllComponentsOfType) {}
TEST(EntityAdmin, ShouldRemoveEntity) {}