#pragma once
#include <compare>


struct Entity
{
    int Id;
    Entity(int Id) : Id(Id) {}
    auto operator<=>(const Entity& entity) const = default;
};
