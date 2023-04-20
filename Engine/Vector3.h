// Copyright Syed Aman. All Rights Reserved.
#pragma once

class Vector3
{
public:
    float X;
    float Y;
    float Z;
    
    Vector3(float X, float Y, float Z) : X(X), Y(Y), Z(Z) {}
    bool operator==(const Vector3& other) const;
    bool operator!=(const Vector3& other) const;
};
