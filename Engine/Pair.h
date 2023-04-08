#pragma once

template <typename T1, typename T2>
class Pair
{
public:
    T1 First;
    T2 Second;

    Pair() = default;
    
    Pair(T1 First, T2 Second) : First(First), Second(Second) { }
};