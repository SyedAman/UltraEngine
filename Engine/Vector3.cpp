// Copyright Syed Aman. All Rights Reserved.
#include "Vector3.h"

bool Vector3::operator==(const Vector3& other) const
{
    return X == other.X && Y == other.Y && Z == other.Z;
}

bool Vector3::operator!=(const Vector3& other) const
{
    return !(*this == other);
}
