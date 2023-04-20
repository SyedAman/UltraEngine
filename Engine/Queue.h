// Copyright Syed Aman. All Rights Reserved.
#pragma once


template <typename T>
class Queue
{
    size_t Size_ = 0;
    // TODO: Implement queue as a linked list because it offers constant enqueue and dequeue with the expense of memory.
    // TODO: Create the linked list class first before implementing this.

public:
    bool IsEmpty() const;
    size_t Size() const;
    void Enqueue(T value);
};

template <typename T>
bool Queue<T>::IsEmpty() const
{
    return Size_ == 0;
}

template <typename T>
size_t Queue<T>::Size() const
{
    return Size_;
}

template <typename T>
void Queue<T>::Enqueue(T value)
{
    Size_ += 1;
}
