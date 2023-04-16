// Copyright Syed Aman. All Rights Reserved.

#pragma once
#include <compare>


struct Entity
{
    int EntityID;
    
    Entity(int EntityID);
    auto operator<=>(const Entity& entity) const = default;
};
