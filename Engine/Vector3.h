#pragma once

class Vector3
{
public:
    Vector3(float X, float Y, float Z) : X(X), Y(Y), Z(Z) {}

    bool operator==(const Vector3& other) const
    {
        return X == other.X && Y == other.Y && Z == other.Z;
    }

    bool operator!=(const Vector3& other) const
    {
        return !(*this == other);
    }

    float X;
    float Y;
    float Z;
};
