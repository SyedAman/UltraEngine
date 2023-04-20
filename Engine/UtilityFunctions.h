// Copyright Syed Aman. All Rights Reserved.
#include "Pair.h"

template <typename T>
void Swap(T& Current, T& Parent)
{
    T Temp = Current;
    Current = Parent;
    Parent = Temp;
}

template <typename T>
struct Less
{
    bool operator()(const T& Left, const T& Right) const
    {
        return Left < Right;
    }
};


template<typename T1, typename T2>
struct Less<Pair<T1, T2>> {
    bool operator()(const Pair<T1, T2>& lhs, const Pair<T1, T2>& rhs) const {
        return lhs < rhs;
    }
};

struct IdentityFunctor
{
    template <typename T>
    T&& operator()(T&& Val) const
    {
        return (T&&)Val;
    }
};