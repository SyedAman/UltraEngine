// Copyright Syed Aman. All Rights Reserved.
#pragma once

#include "DynamicArray.h"
#include "Pair.h"

template <typename KeyType, typename ValueType>
class HashMap
{
    DynamicArray<Pair<KeyType, ValueType>> Data = {};
    
public:
    void Insert(KeyType Key, ValueType Value);
    ValueType operator[](KeyType Key);
};

template <typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::Insert(KeyType Key, ValueType Value)
{
    Data.PushBack(Pair<KeyType, ValueType>(Key, Value));
}

template <typename KeyType, typename ValueType>
ValueType HashMap<KeyType, ValueType>::operator[](KeyType Key)
{
    // TODO: Currently O(n), make this O(1) with a hash table.
    for (auto Pair : Data)
    {
        if (Pair.First == Key)
        {
            return Pair.Second;
        }
    }
}
