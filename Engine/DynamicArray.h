#pragma once
#include <gtest/internal/gtest-death-test-internal.h>

#include "Pair.h"

template <typename T>
class DynamicArray
{
    size_t Size_;
    size_t Capacity_;
    T* Data_;

public:
    DynamicArray() : Size_(0), Capacity_(0), Data_(new T[Size_]) { }
    DynamicArray(int Capacity) : Size_(0), Capacity_(Capacity), Data_(new T[Capacity]) { }
    ~DynamicArray() { delete[] Data_; }

    size_t Size() const;
    void PushBack(T Value);
    void Clear();
    void PopBack();
    
    T& operator[](int i);
    const T& operator[](int i) const;
    T& Front();
    bool Empty() const;
    T* Begin();
    T* End();
};

template <typename T>
size_t DynamicArray<T>::Size() const
{
    return Size_;
}

template <typename T>
void DynamicArray<T>::PushBack(T Value)
{
    if (Size_ >= Capacity_)
    {
        Capacity_ = Capacity_ == 0 ? 1 : Capacity_ * 2;
        T* NewData = new T[Capacity_];
        for (int i = 0; i < Size_; ++i)
        {
            NewData[i] = Data_[i];
        }
        delete[] Data_;
        Data_ = NewData;
    }
    Data_[Size_++] = Value;
}

template <typename T>
void DynamicArray<T>::Clear()
{
    delete[] Data_;
    Size_ = 0;
    Capacity_ = 0;
    Data_ = new T[Capacity_];
}

template <typename T>
void DynamicArray<T>::PopBack()
{
    --Size_;
}

template <typename T>
T& DynamicArray<T>::operator[](int i)
{
    return Data_[i];
}

template <typename T>
const T& DynamicArray<T>::operator[](int i) const
{
    return Data_[i];
}

template <typename T>
T& DynamicArray<T>::Front()
{
    return Data_[0];
}

template <typename T>
bool DynamicArray<T>::Empty() const
{
    return Size_ == 0;
}

template <typename T>
T* DynamicArray<T>::Begin()
{
    return Data_;
}

template <typename T>
T* DynamicArray<T>::End()
{
    return Data_ + Size_;
}
