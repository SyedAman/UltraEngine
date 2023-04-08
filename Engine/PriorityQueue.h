#pragma once
#include <stdexcept>
#include <vector>

template <typename T>
struct Less
{
    bool operator()(const T& Left, const T& Right) const
    {
        return Left < Right;
    }
};

template <typename T, typename Container = std::vector<T>, typename Comparator = Less<T>>
class PriorityQueue
{
    Container UnderlyingContainer;

    void Swap(T& Current, T& Parent)
    {
        T Temp = Current;
        Current = Parent;
        Parent = Temp;
    }

    void SiftUp(int CurrentIndex)
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

    void SiftDown(int CurrentIndex)
    {
        int LeftChildIndex = CurrentIndex * 2 + 1;
        int RightChildIndex = CurrentIndex * 2 + 2;
        int ContainerSize = UnderlyingContainer.size();
        
        if (bool bNoChildren = LeftChildIndex >= ContainerSize) return;

        int HighestPriorityChildIndex = LeftChildIndex; // Assume the left child has the highest priority.

        if (RightChildIndex < ContainerSize && Comparator()(UnderlyingContainer[RightChildIndex], UnderlyingContainer[LeftChildIndex]))
        {
            HighestPriorityChildIndex = RightChildIndex;
        }

        T& Current = UnderlyingContainer[CurrentIndex];
        T& HighestPriorityChild = UnderlyingContainer[HighestPriorityChildIndex];
        if (bool bSatisfiesHeapProperty = Comparator()(HighestPriorityChild, Current))
        {
            Swap(Current, HighestPriorityChild);
            SiftDown(HighestPriorityChildIndex);
        }
    }

    
public:
    void push(T Value);
    bool empty();
    void pop();
    T top();
};

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
