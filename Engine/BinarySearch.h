// Copyright Syed Aman. All Rights Reserved.

#pragma once
#include "UtilityFunctions.h"


namespace Algo
{
    template <typename RangeValueType, typename SizeType, typename PredicateValueType, typename ProjectionType, typename SortPredicateType>
    size_t BinarySearch(RangeValueType* PointerToArray, const SizeType ArrCount, const PredicateValueType& Target, ProjectionType Projection = IdentityFunctor(), SortPredicateType SortPredicate = Less<PredicateValueType>())
    {
        SizeType LowerBound = 0;
        SizeType UpperBound = ArrCount;
        
        while (UpperBound > 0)
        {
            const SizeType LeftoverSize = UpperBound % 2;
            UpperBound = UpperBound / 2;
        
            const SizeType Mid = LowerBound + UpperBound;
            const SizeType LowerBoundIfLess = Mid + LeftoverSize;

            SizeType&& CheckValue = Projection(PointerToArray[Mid]);
            LowerBound = SortPredicate(CheckValue, Target) ? LowerBoundIfLess : LowerBound;
        }

        return LowerBound;
    }

    template <typename RangeValueType, typename SizeType, typename PredicateValueType>
    size_t BinarySearch(RangeValueType* PointerToArray, const SizeType ArrCount, const PredicateValueType& Target)
    {
        return BinarySearch(PointerToArray, ArrCount, Target, IdentityFunctor(), Less<PredicateValueType>());
    }
}
