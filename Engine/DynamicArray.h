#pragma once

template <typename T>
class DynamicArray
{
    int Size_ = 0;
    T* Data_;

public:
    DynamicArray() : Data_(new T[Size_]) { }
    DynamicArray(int Size) : Size_(Size), Data_(new T[Size]) { }

    
    int Size() const;
    void push_back(T i);
    T& operator[](int i) { return Data_[i]; }
};

template <typename T>
int DynamicArray<T>::Size() const
{
    return Size_;
}

template <typename T>
void DynamicArray<T>::push_back(T i)
{
    Data_[Size_] = i;
}
