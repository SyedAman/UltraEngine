#pragma once
#include <stdexcept>
#include <vector>
#include "UtilityFunctions.h"


template <typename T, typename Container = std::vector<T>, typename Comparator = Less<T>>
class PriorityQueue
{
    Container UnderlyingContainer;

    void SiftUp(int CurrentIndex);
    int GetHighestPriorityChildIndex(int CurrentIndex) const;
    void SiftDown(int CurrentIndex);

public:
    void push(T Value);
    bool empty();
    void pop();
    T top();
};

template <typename T, typename Container, typename Comparator>
void PriorityQueue<T, Container, Comparator>::SiftUp(int CurrentIndex)
{
    while (CurrentIndex > 0)
    {
        int ParentIndex = (CurrentIndex - 1) / 2;
        T& Current = UnderlyingContainer[CurrentIndex];
        T& Parent = UnderlyingContainer[ParentIndex];

        if (bool bSatisfiesHeapProperty = Comparator()(Current, Parent))
        {
            Swap(Current, Parent);

            CurrentIndex = ParentIndex;
        }
        else
        {
            break;
        }
    }
}

template <typename T, typename Container, typename Comparator>
int PriorityQueue<T, Container, Comparator>::GetHighestPriorityChildIndex(int CurrentIndex) const
{
    int LeftChildIndex = CurrentIndex * 2 + 1;
    int RightChildIndex = CurrentIndex * 2 + 2;
    int ContainerSize = UnderlyingContainer.size();

    if (LeftChildIndex >= ContainerSize) return -1; // No children, return -1.

    if (RightChildIndex < ContainerSize && Comparator()(UnderlyingContainer[RightChildIndex], UnderlyingContainer[LeftChildIndex]))
    {
        return RightChildIndex;
    }
    else
    {
        return LeftChildIndex;
    }
}

template <typename T, typename Container, typename Comparator>
void PriorityQueue<T, Container, Comparator>::SiftDown(int CurrentIndex)
{
    int HighestPriorityChildIndex = GetHighestPriorityChildIndex(CurrentIndex);

    bool bNoChildren = HighestPriorityChildIndex == -1;
    if (bNoChildren) return;

    T& Current = UnderlyingContainer[CurrentIndex];
    T& HighestPriorityChild = UnderlyingContainer[HighestPriorityChildIndex];

    bool bSatisfiesHeapProperty = Comparator()(HighestPriorityChild, Current);
    if (bSatisfiesHeapProperty)
    {
        Swap(Current, HighestPriorityChild);
        SiftDown(HighestPriorityChildIndex);
    }
}

template <typename T, typename Container, typename Comparator>
void PriorityQueue<T, Container, Comparator>::push(T Value)
{
    UnderlyingContainer.push_back(Value);
    SiftUp(UnderlyingContainer.size() - 1);
}

template <typename T, typename Container, typename Comparator>
bool PriorityQueue<T, Container, Comparator>::empty()
{
    return UnderlyingContainer.size() == 0;
}

template <typename T, typename Container, typename Comparator>
void PriorityQueue<T, Container, Comparator>::pop()
{
    if (UnderlyingContainer.size() > 0)
    {
        Swap(UnderlyingContainer[0], UnderlyingContainer[UnderlyingContainer.size() - 1]);
        UnderlyingContainer.pop_back();
        SiftDown(0);
    }
}

template <typename T, typename Container, typename Comparator>
T PriorityQueue<T, Container, Comparator>::top()
{
    if (UnderlyingContainer.empty())
        throw std::runtime_error("PriorityQueue is empty");

    return UnderlyingContainer.front();
}
