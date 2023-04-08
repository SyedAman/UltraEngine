#pragma once
#include "DynamicArray.h"

template <typename T>
struct Less
{
    bool operator()(const T& Left, const T& Right) const
    {
        return Left < Right;
    }
};

template <typename T, typename Container = DynamicArray, typename Comparator = Less<T>>
class PriorityQueue
{
public:
    void push(T value);
    bool empty();
    void pop();
    T top();
};

template <typename T, typename Container, typename Comparator>
void PriorityQueue<T, Container, Comparator>::push(T value)
{
}

template <typename T, typename Container, typename Comparator>
bool PriorityQueue<T, Container, Comparator>::empty()
{
    return true;
}

template <typename T, typename Container, typename Comparator>
void PriorityQueue<T, Container, Comparator>::pop()
{
}

template <typename T, typename Container, typename Comparator>
T PriorityQueue<T, Container, Comparator>::top()
{
    return T();
}
