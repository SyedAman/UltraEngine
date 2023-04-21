// Copyright Syed Aman. All Rights Reserved.
#pragma once

class String
{
    size_t Size;
    char* Buffer;

public:
    size_t Length() const;
    const char* Data() const;

    String();
    String(const char* str);
    ~String();

    bool operator==(const String& other) const;
};
