#pragma once
#include <compare>


struct Entity
{
    int Id;
    
    Entity(int Id);
    auto operator<=>(const Entity& entity) const = default;
};
