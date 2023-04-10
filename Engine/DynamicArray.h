#pragma once
#include <gtest/internal/gtest-death-test-internal.h>

template <typename T>
class DynamicArray
{
    size_t Size_ = 0;
    T* Data_;
    size_t Capacity = 0;

    void DoubleCapacity();
    void DeallocateData() const;
    void AllocateData(int NewSize);

public:
    DynamicArray() : Data_(new T[Size_]) { }
    DynamicArray(int Size) : Size_(Size), Data_(new T[Size]) { }

    size_t Size() const;
    void PushBack(T Value);
    void Clear();
    
    T& operator[](int i) { return Data_[i]; }
};

template <typename T>
size_t DynamicArray<T>::Size() const
{
    return Size_;
}

template <typename T>
void DynamicArray<T>::DoubleCapacity()
{
    size_t NewCapacity = Capacity > 0 ? Capacity * 2 : 1;
    T* NewData = new T[NewCapacity];
    for (size_t i = 0; i < Size_; i++)
    {
        NewData[i] = Data_[i];
    }
    DeallocateData();
    Data_ = NewData;
    Capacity = NewCapacity;
}

template <typename T>
void DynamicArray<T>::PushBack(T Value)
{
    if (Size_ >= Capacity)
    {
            DoubleCapacity();
    }
    
    Data_[Size_++] = Value;
}

template <typename T>
void DynamicArray<T>::DeallocateData() const
{
    delete[] Data_;
}

template <typename T>
void DynamicArray<T>::AllocateData(int NewSize)
{
    Data_ = new T[NewSize];
    Size_ = NewSize;
}

template <typename T>
void DynamicArray<T>::Clear()
{
    DeallocateData();
    AllocateData(0);
}
