#pragma once

template <typename T1, typename T2>
class Pair
{
public:
    T1 First;
    T2 Second;

    Pair() = default;
    Pair(T1 First, T2 Second) : First(First), Second(Second) { }

    bool operator==(const Pair<T1, T2>& pair) const;
    bool operator<(const Pair<T1, T2>& pair) const;
    bool operator>(const Pair<T1, T2>& pair) const;
};

template <typename T1, typename T2>
bool Pair<T1, T2>::operator==(const Pair<T1, T2>& pair) const
{
    return First == pair.First && Second == pair.Second;
}

template <typename T1, typename T2>
bool Pair<T1, T2>::operator<(const Pair<T1, T2>& pair) const
{
    return First < pair.First || (First == pair.First && Second < pair.Second);
}

template <typename T1, typename T2>
bool Pair<T1, T2>::operator>(const Pair<T1, T2>& pair) const
{
    return First > pair.First || (First == pair.First && Second > pair.Second);
}
