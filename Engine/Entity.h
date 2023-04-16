#pragma once
#include <compare>


struct Entity
{
    int EntityID;
    
    Entity(int EntityID);
    auto operator<=>(const Entity& entity) const = default;
};
