// Copyright Syed Aman. All Rights Reserved.
#pragma once
#include "UtilityFunctions.h"


namespace Algorithms
{
    template <typename RangeValueType, typename SizeType, typename PredicateValueType, typename ProjectionType, typename SortPredicateType>
    size_t BinarySearch(RangeValueType* pointerToArray, const SizeType arrCount, const PredicateValueType& target,
        ProjectionType projection = IdentityFunctor(), SortPredicateType sortPredicate = Less<PredicateValueType>())
    {
        SizeType LowerBound = 0;
        SizeType UpperBound = arrCount;
        
        while (UpperBound > 0)
        {
            const SizeType LeftoverSize = UpperBound % 2;
            UpperBound = UpperBound / 2;
        
            const SizeType Mid = LowerBound + UpperBound;
            const SizeType LowerBoundIfLess = Mid + LeftoverSize;

            SizeType&& CheckValue = projection(pointerToArray[Mid]);
            LowerBound = sortPredicate(CheckValue, target) ? LowerBoundIfLess : LowerBound;
        }

        return LowerBound;
    }

    template <typename RangeValueType, typename SizeType, typename PredicateValueType>
    size_t BinarySearch(RangeValueType* pointerToArray, const SizeType arrCount, const PredicateValueType& target)
    {
        return BinarySearch(pointerToArray, arrCount, target, IdentityFunctor(), Less<PredicateValueType>());
    }
}
