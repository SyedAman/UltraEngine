#pragma once
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
    
public:
    void push(T Value);
    bool empty();
    void pop();
    T top();
};

template <typename T, typename Container, typename Comparator>
void PriorityQueue<T, Container, Comparator>::push(T Value)
{
    for (auto Iterator = UnderlyingContainer.begin(); Iterator != UnderlyingContainer.end(); ++Iterator)
    {
        if (Comparator()(Value, *Iterator))
        {
            UnderlyingContainer.insert(Iterator, Value);
            return;
        }
    }
    UnderlyingContainer.push_back(Value);
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
        UnderlyingContainer.erase(UnderlyingContainer.begin());
}

template <typename T, typename Container, typename Comparator>
T PriorityQueue<T, Container, Comparator>::top()
{
    return UnderlyingContainer.front();
}
